//----------------------------------------------------------------------------
//   The confidential and proprietary information contained in this file may
//   only be used by a person authorised under and to the extent permitted
//   by a subsisting licensing agreement from ARM Limited or its affiliates.
//
//          (C) COPYRIGHT [2018] ARM Limited or its affiliates.
//              ALL RIGHTS RESERVED
//
//   This entire notice must be reproduced on all copies of this file
//   and copies of this file may only be made by a person if such person is
//   permitted to do so under the terms of a subsisting license agreement
//   from ARM Limited or its affiliates.
//----------------------------------------------------------------------------

#include "acamera_firmware_config.h"
#include "acamera_math.h"
#include "acamera_logger.h"
#include "ae_standard_api.h"
#include "ae_acamera_core.h"

#ifdef LOG_MODULE
#undef LOG_MODULE
#define LOG_MODULE LOG_MODULE_AE_ACAMERA
#endif

enum { AE_CLIPPING_ANTIFLICKER_N = 5 };

typedef struct _ae_acamera_core_obj_ {
    uint64_t WSNR_cumsum[ISP_FULL_HISTOGRAM_SIZE];
    int32_t targets_history[AE_CLIPPING_ANTIFLICKER_N];
    uint32_t next_hist_idx;
    int32_t max_target;

    int32_t exposure_log2;
    int32_t ae_hist_mean;
    int32_t error_log2;
    uint32_t exposure_ratio_avg;
    int64_t integrator;
} ae_acamera_core_obj_t;

ae_acamera_core_obj_t ae_core_objs[FIRMWARE_CONTEXT_NUMBER];


static const uint8_t AE_FXPOINT_QBITS = 6;
static const int32_t AE_CLIPPING_HISTORY_INIT_VALUE = 0; // Empty history

static uint8_t linear_interpolation_u8( int32_t x0, uint8_t y0, int32_t x1, uint8_t y1, int32_t x )
{
    if ( x1 != x0 )
        return y0 + ( y1 - y0 ) * ( x - x0 ) / ( x1 - x0 ); // division by zero is checked
    LOG( LOG_INFO, "AVOIDED DIVISION BY ZERO" );
    return y0;
}

static uint16_t get_exposure_correction( ae_acamera_core_obj_t *p_ae_core_obj, ae_acamera_input_t *p_ae_acamera_input )
{
    int32_t exp = acamera_math_exp2( p_ae_core_obj->exposure_log2, LOG2_GAIN_SHIFT, 6 );
    uint16_t correction = 0;
    const uint8_t *lut = p_ae_acamera_input->cali_data.ae_corr_lut; //_GET_UCHAR_PTR( ACAMERA_FSM2CTX_PTR( p_fsm ), CALIBRATION_AE_CORRECTION );

    if ( exp <= p_ae_acamera_input->cali_data.ae_exp_corr_lut[0] )
        correction = lut[0];
    else if ( exp >= p_ae_acamera_input->cali_data.ae_exp_corr_lut[p_ae_acamera_input->cali_data.ae_exp_corr_lut_len - 1] )
        correction = lut[p_ae_acamera_input->cali_data.ae_exp_corr_lut_len - 1];
    else {
        int i;
        for ( i = 1; i < p_ae_acamera_input->cali_data.ae_exp_corr_lut_len; i++ ) {
            if ( exp < p_ae_acamera_input->cali_data.ae_exp_corr_lut[i] ) {
                correction = linear_interpolation_u8( p_ae_acamera_input->cali_data.ae_exp_corr_lut[i - 1],
                                                      lut[i - 1],
                                                      p_ae_acamera_input->cali_data.ae_exp_corr_lut[i],
                                                      lut[i],
                                                      exp );
                break;
            }
        }
    }
    return correction;
}

static inline uint32_t adjacent_ratio_to_full( int32_t sensor_exp_number, uint32_t ratio )
{
    switch ( sensor_exp_number ) {
    case 4:
        return ( ratio * ratio * ratio ) << 6;
        break;
    case 3:
        return ( ratio * ratio ) << 6;
        break;
    default:
    case 2:
        return ratio << 6;
        break;
    }
}

uint32_t ae_calculate_exposure_ratio( ae_acamera_core_obj_t *p_ae_core_obj, ae_stats_data_t *stats, ae_input_data_t *ae_input )
{
    ae_acamera_input_t *p_ae_acamera_input = (ae_acamera_input_t *)( ae_input->acamera_input );
    ae_balanced_param_t *param = p_ae_acamera_input->ae_ctrl;
    uint32_t exp_ratio = 64;
    uint32_t max_clip_exp_ratio = 64;

    const uint32_t max_exposure_ratio = adjacent_ratio_to_full( p_ae_acamera_input->misc_info.sensor_exp_number,
                                        p_ae_acamera_input->misc_info.global_max_exposure_ratio );

    if ( p_ae_acamera_input->misc_info.global_manual_exposure_ratio ) {
        exp_ratio = adjacent_ratio_to_full( p_ae_acamera_input->misc_info.sensor_exp_number,
                                            p_ae_acamera_input->misc_info.global_exposure_ratio );
    } else {

#if defined( CALIBRATION_EXPOSURE_RATIO_ADJUSTMENT ) && ( defined( ISP_HAS_IRIDIX8_FSM ) || defined( ISP_HAS_IRIDIX8_MANUAL_FSM ) || defined( ISP_HAS_IRIDIX_ACAMERA_FSM ) )
        //Modulation of clipped pixels according to contrast of scene
        uint32_t er_contrast_adj = acamera_calc_modulation_u16( p_ae_acamera_input->misc_info.iridix_contrast, p_ae_acamera_input->cali_data.ae_exp_ratio_adjustment, p_ae_acamera_input->cali_data.ae_exp_ratio_adjustment_len );

        //uint32_t max_clipped_amount = (uint32_t)((uint64_t)stats->fullhist_sum*param->long_clip>>8); //without modulation
        uint32_t long_clip = ( uint32_t )( param->long_clip * er_contrast_adj ) >> 8;
        uint32_t max_clipped_amount = ( uint32_t )( (uint64_t)stats->fullhist_sum * long_clip >> 8 ); //without modulation
                                                                                                      // LOG( LOG_CRIT, " iridix_contrast %d", (int)iridix_contrast);
#else
        uint32_t max_clipped_amount = ( uint32_t )( (uint64_t)stats->fullhist_sum * param->long_clip >> 8 );
#endif

        uint32_t inx = ISP_FULL_HISTOGRAM_SIZE - 1;
        uint32_t clipped_amount = stats->fullhist[inx];

        while ( clipped_amount <= max_clipped_amount && inx > 0 ) { //kernel ooops
            inx--;
            clipped_amount += stats->fullhist[inx];
        }
        exp_ratio = ( ( uint32_t )( ISP_FULL_HISTOGRAM_SIZE - 1 ) << 7 ) / ( 2 * inx + 1 );
        max_clip_exp_ratio = exp_ratio;
        //LOG( LOG_ERR, " exp_ratio CLIP %d", exp_ratio );
        if ( p_ae_acamera_input->misc_info.sensor_exp_number > 1 ) {
            const uint32_t *hist = stats->fullhist;

            // Compute partial sums
            {
                p_ae_core_obj->WSNR_cumsum[0] = hist[0] * acamera_sqrt32( 64 );
                uint32_t i = 1;
                for ( ; i < ISP_FULL_HISTOGRAM_SIZE; ++i ) {
                    p_ae_core_obj->WSNR_cumsum[i] = p_ae_core_obj->WSNR_cumsum[i - 1] + hist[i] * acamera_sqrt32( 64 * ( i + 1 ) );
                }
            }

            uint32_t ER_best = ( 1 << AE_FXPOINT_QBITS );
            uint64_t WSNR_best = p_ae_core_obj->WSNR_cumsum[ISP_FULL_HISTOGRAM_SIZE - 1];

            switch ( p_ae_acamera_input->misc_info.sensor_exp_number ) {
            case 2: {
                int32_t er_cand = 1;
                for ( ; er_cand < 16; ++er_cand ) {
                    const int32_t ER_candidate_sqr = ( er_cand << AE_FXPOINT_QBITS );

                    uint32_t clip_medium = ( ISP_FULL_HISTOGRAM_SIZE ) / er_cand;
                    clip_medium = MAX( 1, clip_medium );
                    clip_medium = MIN( clip_medium, ISP_FULL_HISTOGRAM_SIZE - 1 );

                    // Unsigned because cumsums are monotonic
                    uint64_t current_WSNR = ( ( p_ae_core_obj->WSNR_cumsum[ISP_FULL_HISTOGRAM_SIZE - 1] -
                                                p_ae_core_obj->WSNR_cumsum[clip_medium] ) << AE_FXPOINT_QBITS ) +
                                            ( p_ae_core_obj->WSNR_cumsum[clip_medium] * ER_candidate_sqr );

                    if ( current_WSNR > WSNR_best ) {
                        WSNR_best = current_WSNR;
                        ER_best = ( ER_candidate_sqr * ER_candidate_sqr ) >> AE_FXPOINT_QBITS;
                    }
                }
                exp_ratio = ER_best;
            } break;

            case 3: {
                int32_t er_cand = 1;
                for ( ; er_cand < 16; ++er_cand ) {
                    const int32_t ER_candidate_sqr = ( er_cand << AE_FXPOINT_QBITS );

                    uint32_t clip_medium = ( ISP_FULL_HISTOGRAM_SIZE ) / er_cand;
                    uint32_t clip_long = clip_medium / er_cand;

                    clip_long = MAX( 1, clip_long );
                    clip_long = MIN( clip_long, ISP_FULL_HISTOGRAM_SIZE - 2 );

                    clip_medium = MAX( clip_long + 1, clip_medium );
                    clip_medium = MIN( clip_medium, ISP_FULL_HISTOGRAM_SIZE - 1 );

                    // Unsigned because cumsums are monotonic
                    uint64_t current_WSNR = ( ( p_ae_core_obj->WSNR_cumsum[ISP_FULL_HISTOGRAM_SIZE - 1] - p_ae_core_obj->WSNR_cumsum[clip_medium] ) << AE_FXPOINT_QBITS ) +
                                            ( acamera_sqrt32( ER_candidate_sqr << AE_FXPOINT_QBITS ) * ( p_ae_core_obj->WSNR_cumsum[clip_medium] - p_ae_core_obj->WSNR_cumsum[clip_long] ) ) +
                                            ( p_ae_core_obj->WSNR_cumsum[clip_long] * ER_candidate_sqr );

                    if ( current_WSNR > WSNR_best ) {
                        WSNR_best = current_WSNR;
                        ER_best = ( ER_candidate_sqr * ER_candidate_sqr ) >> AE_FXPOINT_QBITS;
                    }
                }
                exp_ratio = ER_best;
            } break;

            case 4: {
                int32_t er_cand = 1;
                for ( ; er_cand < 16; ++er_cand ) {
                    const int32_t ER_candidate_sqr = ( er_cand << AE_FXPOINT_QBITS );

                    uint32_t clip_medium = ( ISP_FULL_HISTOGRAM_SIZE ) / ( er_cand );
                    uint32_t clip_medium2 = clip_medium / er_cand;
                    uint32_t clip_long = clip_medium2 / er_cand;

                    clip_long = MAX( 1, clip_long );
                    clip_long = MIN( clip_long, ISP_FULL_HISTOGRAM_SIZE - 3 );

                    clip_medium2 = MAX( clip_long + 1, clip_medium2 );
                    clip_medium2 = MIN( clip_medium2, ISP_FULL_HISTOGRAM_SIZE - 2 );

                    clip_medium = MAX( clip_medium2 + 1, clip_medium );
                    clip_medium = MIN( clip_medium, ISP_FULL_HISTOGRAM_SIZE - 1 );

                    const uint32_t canditade_sqr_root = acamera_sqrt32( ER_candidate_sqr << AE_FXPOINT_QBITS );
                    const uint32_t canditade_cube_root = acamera_math_exp2( acamera_log2_fixed_to_fixed( ER_candidate_sqr, AE_FXPOINT_QBITS, AE_FXPOINT_QBITS ) / 3, AE_FXPOINT_QBITS, AE_FXPOINT_QBITS );

                    // Unsigned because cumsums are monotonic
                    uint64_t current_WSNR = ( ( p_ae_core_obj->WSNR_cumsum[ISP_FULL_HISTOGRAM_SIZE - 1] - p_ae_core_obj->WSNR_cumsum[clip_medium] ) << AE_FXPOINT_QBITS ) +
                                            ( canditade_cube_root * ( p_ae_core_obj->WSNR_cumsum[clip_medium] - p_ae_core_obj->WSNR_cumsum[clip_medium2] ) ) +
                                            ( canditade_sqr_root * ( p_ae_core_obj->WSNR_cumsum[clip_medium2] - p_ae_core_obj->WSNR_cumsum[clip_long] ) ) +
                                            ( ER_candidate_sqr * p_ae_core_obj->WSNR_cumsum[clip_long] );

                    if ( current_WSNR > WSNR_best ) {
                        WSNR_best = current_WSNR;
                        ER_best = ( ER_candidate_sqr * ER_candidate_sqr ) >> AE_FXPOINT_QBITS;
                    }
                }
                exp_ratio = ER_best;
            } break;

            default: {
                LOG( LOG_ERR, "Unsupported exposures number!" );
            } break;
            }

            exp_ratio = exp_ratio > max_clip_exp_ratio ? max_clip_exp_ratio : exp_ratio;
            //LOG( LOG_ERR, " ER_best %d max %d ER %d", ER_best>>6, max_clip_exp_ratio>>6, exp_ratio>>6 );
        }
    }
    if ( exp_ratio < 64 ) {
        exp_ratio = 64;
    }
    if ( exp_ratio > max_exposure_ratio ) {
        exp_ratio = max_exposure_ratio;
    }
    if ( param->er_avg_coeff > 0 ) {
        p_ae_core_obj->exposure_ratio_avg += exp_ratio - ( p_ae_core_obj->exposure_ratio_avg / param->er_avg_coeff ); // division by zero is checked
        exp_ratio = p_ae_core_obj->exposure_ratio_avg / param->er_avg_coeff;                                          // division by zero is checked
    }

    return exp_ratio;
}

static void ae_calculate_target( ae_acamera_core_obj_t *p_ae_core_obj, ae_stats_data_t *stats, ae_input_data_t *ae_input )
{
    if ( stats->fullhist_sum == 0 ) {
        LOG( LOG_WARNING, "FULL HISTOGRAM SUM IS ZERO" );
        return;
    }

    ae_acamera_input_t *p_ae_acamera_input = (ae_acamera_input_t *)( ae_input->acamera_input );
    ae_balanced_param_t *param = p_ae_acamera_input->ae_ctrl;

    uint8_t ae_comp = p_ae_acamera_input->misc_info.global_ae_compensation; // ACAMERA_FSM2CTX_PTR( p_fsm )->stab.global_ae_compensation;

    // calculate mean value
    uint32_t cnt;
    uint64_t acc = 0;
    uint32_t n = param->tail_weight;
    uint32_t m1;

    for ( cnt = 0; cnt < ISP_FULL_HISTOGRAM_SIZE - n; cnt++ ) {
        acc += ( 2 * cnt + 1ull ) * stats->fullhist[cnt];
    }
    for ( ; cnt < ISP_FULL_HISTOGRAM_SIZE; cnt++ ) {
        acc += ( cnt - ( ISP_FULL_HISTOGRAM_SIZE - n ) + 2 ) / 2 * ( 2 * cnt + 1ull ) * stats->fullhist[cnt];
    }
    m1 = ( uint32_t )( div64_u64( acc, 2 * stats->fullhist_sum ) );

    p_ae_core_obj->ae_hist_mean = m1;

    uint16_t log2_gain = p_ae_acamera_input->misc_info.total_gain >> ( LOG2_GAIN_SHIFT - 8 );

    const int32_t ldr_target = param->target_point;
    const int32_t hdr_target =
        acamera_calc_modulation_u16( log2_gain,
                                     p_ae_acamera_input->cali_data.ae_hdr_target,
                                     p_ae_acamera_input->cali_data.ae_hdr_target_len );

    LOG( LOG_DEBUG, "hdr_target %d log2_gain %d", hdr_target, log2_gain );

    const uint32_t hi_target_prc = MIN( param->hi_target_prc, 100 );
    const uint32_t hi_target_p = MIN( param->hi_target_p, 100 );
    const uint32_t clip_target = ( hi_target_prc * (uint64_t)stats->fullhist_sum ) / 100;
    const uint32_t unclipped_point = ( hi_target_p * ISP_FULL_HISTOGRAM_SIZE ) / 100;

    // Find a clip point satisfying clipping thresholds
    uint32_t target_pc_point = 0;
    {
        uint32_t pc_counted = 0;
        for ( ; ( target_pc_point < ISP_FULL_HISTOGRAM_SIZE ) && ( pc_counted < clip_target ); ++target_pc_point ) {
            pc_counted += stats->fullhist[target_pc_point];
        }
        target_pc_point = MAX( 1, target_pc_point ); // target_pc_point >= 1
    }

    const int is_unknown_target = ( target_pc_point >= ISP_FULL_HISTOGRAM_SIZE - 1 ) ? 1 : 0; // bool
    if ( is_unknown_target ) {
        p_ae_core_obj->targets_history[p_ae_core_obj->next_hist_idx++] = 0;
        if ( p_ae_core_obj->next_hist_idx >= AE_CLIPPING_ANTIFLICKER_N ) {
            p_ae_core_obj->next_hist_idx = 0;
        }

        uint32_t old_target = hdr_target;
        int32_t i = 0;
        int32_t rIdx = p_ae_core_obj->next_hist_idx;
        for ( ; i < AE_CLIPPING_ANTIFLICKER_N; ++i ) {
            rIdx = ( rIdx > 0 ) ? rIdx - 1 : AE_CLIPPING_ANTIFLICKER_N - 1;
            if ( p_ae_core_obj->targets_history[rIdx] > 0 ) {
                old_target = p_ae_core_obj->targets_history[rIdx];
                break;
            }
        }
        // Not using formula X + a * (Y - X) because of unsigned arguments
        // max_target = max_target * 0.8 + max_target_n * 0.2;
        p_ae_core_obj->max_target = ( 819 * p_ae_core_obj->max_target + 205 * old_target ) >> 10;
    } else {
        const uint32_t mean = ( m1 > 0 ? m1 : 1 );
        const uint32_t target_candidate =
            ( ( 973 * mean * unclipped_point ) / target_pc_point ) >> 10;
        // division by zero is checked
        // 0.95 * 1024 = 973
        p_ae_core_obj->targets_history[p_ae_core_obj->next_hist_idx++] = target_candidate;
        if ( p_ae_core_obj->next_hist_idx >= AE_CLIPPING_ANTIFLICKER_N ) {
            p_ae_core_obj->next_hist_idx = 0;
        }

        p_ae_core_obj->max_target = target_candidate;
    }
    // clamp
    p_ae_core_obj->max_target = MAX( p_ae_core_obj->max_target, hdr_target );
    p_ae_core_obj->max_target = MIN( p_ae_core_obj->max_target, ldr_target );
    const int32_t new_target = p_ae_core_obj->max_target;
    uint16_t exp_correction = get_exposure_correction( p_ae_core_obj, p_ae_acamera_input );

    p_ae_core_obj->error_log2 = acamera_log2_fixed_to_fixed( new_target, 0, LOG2_GAIN_SHIFT ) -
                                acamera_log2_fixed_to_fixed( m1, 0, LOG2_GAIN_SHIFT ) +
                                ( ( ( int32_t )(ae_comp)-0x80 ) << ( LOG2_GAIN_SHIFT - 6 + 1 ) ) +
                                ( ( (int32_t)exp_correction - 0x80 ) << ( LOG2_GAIN_SHIFT - 6 + 1 ) );

    int32_t p_para = 0, n_para = 0;
    if ( param->AE_tol != 0 ) {
        p_para = acamera_log2_fixed_to_fixed( new_target, 0, LOG2_GAIN_SHIFT ) - acamera_log2_fixed_to_fixed( new_target - param->AE_tol, 0, LOG2_GAIN_SHIFT );
        n_para = acamera_log2_fixed_to_fixed( new_target, 0, LOG2_GAIN_SHIFT ) - acamera_log2_fixed_to_fixed( new_target + param->AE_tol, 0, LOG2_GAIN_SHIFT );
        if ( ( p_ae_core_obj->error_log2 <= p_para ) && ( p_ae_core_obj->error_log2 >= n_para ) ) {
            p_ae_core_obj->error_log2 = 0;
        }
        //LOG( LOG_ERR, "AE_tol  %d p_ %d n_ %d new_target %d p_ae_core_obj->error_log2 %d", param->AE_tol, p_para, n_para, new_target, p_ae_core_obj->error_log2 );
        //LOG( LOG_ERR, "%ld,%d,%ld,%ld,%d,%d\n", m1, new_target, ldr_target, p_ae_core_obj->error_log2, ae_comp, exp_correction );
    }
}

static void ae_calculate_exposure( ae_acamera_core_obj_t *p_ae_core_obj, ae_stats_data_t *stats, ae_input_data_t *ae_input, ae_acamera_output_t *p_ae_acamera_output )
{
    ae_acamera_input_t *p_ae_acamera_input = (ae_acamera_input_t *)( ae_input->acamera_input );

    int32_t exposure_log2 = 0;

    if ( sizeof( ae_output_data_t ) < sizeof( ae_acamera_output_t ) ) {
        LOG( LOG_CRIT, "Invalid param, output size is not enough, expect: %d, actual: %d.", sizeof( ae_acamera_output_t ), sizeof( ae_output_data_t ) );
        return;
    }

    if ( p_ae_acamera_input->misc_info.global_manual_exposure ) {
        exposure_log2 = acamera_log2_fixed_to_fixed( p_ae_acamera_input->misc_info.global_exposure, 6, LOG2_GAIN_SHIFT );
        if ( exposure_log2 < 0 )
            exposure_log2 = 0;
    } else {
        ae_balanced_param_t *param = p_ae_acamera_input->ae_ctrl;
        int32_t coeff = param->pi_coeff;
        int64_t max_exposure;
        int32_t max_exposure_log2 = p_ae_acamera_input->misc_info.max_exposure_log2;

        max_exposure = (int64_t)coeff * max_exposure_log2;
        p_ae_core_obj->integrator += p_ae_core_obj->error_log2;

        if ( p_ae_core_obj->integrator < 0 )
            p_ae_core_obj->integrator = 0;
        if ( p_ae_core_obj->integrator > max_exposure )
            p_ae_core_obj->integrator = max_exposure;

        exposure_log2 = (int32_t)div64_s64( p_ae_core_obj->error_log2 + p_ae_core_obj->integrator, coeff );

        LOG( LOG_DEBUG, "exp: %d, err_log2: %d, integrator: %d, coeff: %d\n", (int)exposure_log2, (int)p_ae_core_obj->error_log2, (int)p_ae_core_obj->integrator, (int)coeff );
        if ( exposure_log2 < 0 )
            exposure_log2 = 0;
        LOG( LOG_DEBUG, "max_exposure_log2: %d, max_exposure: %d, exposure_log2: %d\n", (int)max_exposure_log2, (int)max_exposure, (int)exposure_log2 );
    }

    p_ae_acamera_output->exposure_log2 = exposure_log2;
    p_ae_core_obj->exposure_log2 = exposure_log2;
    p_ae_acamera_output->exposure_ratio = ae_calculate_exposure_ratio( p_ae_core_obj, stats, ae_input );

    LOG( LOG_DEBUG, "ae exposure_log2: %d, ratio: %d.", (int)exposure_log2, p_ae_acamera_output->exposure_ratio );
}

void *ae_acamera_core_init( uint32_t ctx_id )
{
    uint32_t i;
    ae_acamera_core_obj_t *p_ae_core_obj = NULL;

    if ( ctx_id >= FIRMWARE_CONTEXT_NUMBER ) {
        LOG( LOG_CRIT, "Invalid ctx_id: %d, greater than max: %d.", ctx_id, FIRMWARE_CONTEXT_NUMBER - 1 );
        return NULL;
    }

    p_ae_core_obj = &ae_core_objs[ctx_id];
    memset( p_ae_core_obj, 0, sizeof( *p_ae_core_obj ) );

    for ( i = 0; i < AE_CLIPPING_ANTIFLICKER_N; ++i ) {
        p_ae_core_obj->targets_history[i] = AE_CLIPPING_HISTORY_INIT_VALUE;
    }

    p_ae_core_obj->exposure_ratio_avg = 64;

    return p_ae_core_obj;
}

int32_t ae_acamera_core_deinit( void *ae_ctx )
{
    return 0;
}

int32_t ae_acamera_core_proc( void *ae_ctx, ae_stats_data_t *stats, ae_input_data_t *input, ae_output_data_t *output )
{
    if ( !ae_ctx || !stats || !input || !input->acamera_input || !output || !output->acamera_output ) {
        LOG( LOG_ERR, "Invalid parameter: %p-%p-%p-%p-%p-%p.", ae_ctx, stats, input, input ? input->acamera_input : NULL, output, output ? output->acamera_output : NULL );
        return -1;
    }

    ae_acamera_core_obj_t *p_ae_core_obj = (ae_acamera_core_obj_t *)ae_ctx;
    ae_acamera_output_t *p_ae_acamera_output = (ae_acamera_output_t *)output->acamera_output;

    ae_calculate_target( p_ae_core_obj, stats, input );

    ae_calculate_exposure( p_ae_core_obj, stats, input, p_ae_acamera_output );

    return 0;
}
