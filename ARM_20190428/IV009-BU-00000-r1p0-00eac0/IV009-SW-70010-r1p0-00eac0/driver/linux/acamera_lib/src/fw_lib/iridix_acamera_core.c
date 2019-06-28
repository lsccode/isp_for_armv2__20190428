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

#include "acamera_math.h"
#include "acamera_logger.h"
#include "iridix_acamera_core.h"


typedef struct _iridix_acamera_core_obj_ {
    uint16_t strength_target;

    uint16_t dark_enh;
    uint32_t dark_enh_avg;
    uint32_t iridix_global_DG_avg;

    uint32_t iridix_contrast;
    uint16_t iridix_global_DG;

    uint16_t mp_iridix_strength;
} iridix_acamera_core_obj_t;

iridix_acamera_core_obj_t iridix_core_objs[FIRMWARE_CONTEXT_NUMBER];

#ifdef LOG_MODULE
#undef LOG_MODULE
#define LOG_MODULE LOG_MODULE_IRIDIX_ACAMERA
#endif


static uint16_t iridix_control_strength_clip_calculate( iridix_acamera_core_obj_t *p_iridix_core_obj, iridix_acamera_input_t *p_input )
{
    // Calculate iridix strength based on the histogram of the current image
    int16_t ir_str;
    int32_t max_str, max_drk;
    int32_t cur_exposure_log2 = p_input->misc_info.cur_exposure_log2;

    ir_str = p_iridix_core_obj->mp_iridix_strength;

    uint32_t ev_lim_no_str = p_input->cali_data.cali_iridix_ev_lim_no_str[0];
    if ( cur_exposure_log2 < p_input->cali_data.cali_iridix_ev_lim_full_str[0] ) {
        max_str = 100;
    } else if ( ev_lim_no_str < cur_exposure_log2 ) {
        max_str = 0;
    } else {
        int tmp_ev_lim = ( ev_lim_no_str - p_input->cali_data.cali_iridix_ev_lim_full_str[0] );
        if ( tmp_ev_lim == 0 ) {
            tmp_ev_lim = 1;
        }
        max_str = 100 - ( 100 * ( cur_exposure_log2 - p_input->cali_data.cali_iridix_ev_lim_full_str[0] ) ) / tmp_ev_lim;
    }

    if ( max_str < p_input->cali_data.cali_iridix_min_max_str[0] && cur_exposure_log2 < p_input->cali_data.cali_iridix_ev_lim_full_str[0] )
        max_str = p_input->cali_data.cali_iridix_min_max_str[0];

    if ( max_str < 0 )
        max_str = 0;

    if ( ir_str > max_str ) {
        ir_str = max_str;
    }
    //////////////////////////// clip dk according to ev
    uint32_t ev_lim_no_drk = p_input->cali_data.cali_iridix_ev_lim_no_str[1];

    if ( cur_exposure_log2 < p_input->cali_data.cali_iridix_ev_lim_full_str[0] ) {
        max_drk = 100;
    } else if ( ev_lim_no_drk < cur_exposure_log2 ) {
        max_drk = 0;
    } else {
        int tmp_drk = ( ev_lim_no_drk - p_input->cali_data.cali_iridix_ev_lim_full_str[0] );
        if ( tmp_drk == 0 ) {
            tmp_drk = 1;
        }
        max_drk = 100 - ( 100 * ( cur_exposure_log2 - p_input->cali_data.cali_iridix_ev_lim_full_str[0] ) ) / tmp_drk;
    }

    if ( max_drk < 0 ) max_drk = 0;

    //Clip dark enh
    int32_t min_dk = p_input->cali_data.cali_iridix_strength_dk_enh_ctrl[2];
    int32_t max_dk = p_input->cali_data.cali_iridix_strength_dk_enh_ctrl[3];
    int32_t m = ( ( min_dk - max_dk ) ) / ( 0 - 100 );
    uint32_t dk_enh_clip = min_dk + m * ( max_drk - 0 );
    if ( cur_exposure_log2 > p_input->cali_data.cali_iridix_ev_lim_full_str[0] ) {
        p_iridix_core_obj->dark_enh = p_iridix_core_obj->dark_enh > dk_enh_clip ? dk_enh_clip : p_iridix_core_obj->dark_enh;
    }
    p_iridix_core_obj->dark_enh = p_iridix_core_obj->dark_enh > dk_enh_clip ? dk_enh_clip : p_iridix_core_obj->dark_enh;

    uint32_t smin = p_input->misc_info.global_minimum_iridix_strength;
    uint32_t smax = p_input->misc_info.global_maximum_iridix_strength;
    uint32_t strength = 256 * smin + ( 256 * ( smax - smin ) * ir_str ) / 100;

    return ( (uint16_t)strength );
}

static uint16_t iridix_control_dark_enhancement_and_strength_calculate( iridix_acamera_core_obj_t *p_iridix_core_obj, iridix_stats_data_t *p_stats, iridix_acamera_input_t *p_input )
{
    // Calculate iridix strength based on the histogram of the current image
    int32_t i;
    int32_t pD;
    int32_t pH;
    int32_t chist;
    int32_t m;
    int32_t pD_cut = 0;
    int32_t pH_cut = 0;
    int32_t dk_enh = 0;
    int32_t ir_strength_max_ratio = 100;
    int32_t ir_strength;
    int32_t contrast;
    int32_t dk_target;
    int32_t ir_gain;


    int32_t dark_prc = p_input->cali_data.cali_iridix_strength_dk_enh_ctrl[0];
    int32_t bright_prc = p_input->cali_data.cali_iridix_strength_dk_enh_ctrl[1];
    //dark enhancement parameters
    int32_t min_dk = p_input->cali_data.cali_iridix_strength_dk_enh_ctrl[2];
    int32_t max_dk = p_input->cali_data.cali_iridix_strength_dk_enh_ctrl[3];
    int32_t pD_cut_min = p_input->cali_data.cali_iridix_strength_dk_enh_ctrl[4];
    int32_t pD_cut_max = p_input->cali_data.cali_iridix_strength_dk_enh_ctrl[5];
    int32_t dark_contrast_min = p_input->cali_data.cali_iridix_strength_dk_enh_ctrl[6];
    int32_t dark_contrast_max = p_input->cali_data.cali_iridix_strength_dk_enh_ctrl[7];
    int32_t median = 0;
    //Iridix strength parameters
    int32_t min_str = p_input->cali_data.cali_iridix_strength_dk_enh_ctrl[8];
    int32_t max_str = p_input->cali_data.cali_iridix_strength_dk_enh_ctrl[9];
    int32_t dark_prc_gain_target = p_input->cali_data.cali_iridix_strength_dk_enh_ctrl[10];
    int32_t contrast_min = p_input->cali_data.cali_iridix_strength_dk_enh_ctrl[11];    //U24.8 tuning parameter
    int32_t contrast_max = p_input->cali_data.cali_iridix_strength_dk_enh_ctrl[12];    //U24.8 tuning parameter
    int32_t iridix_max_gain = p_input->cali_data.cali_iridix_strength_dk_enh_ctrl[13]; //U24.8 tuning parameter

    int32_t target_LDR = p_input->cali_data.cali_ae_ctrl[1]; // This should correspond to 0.48 point in RAW histogram so that mean intensity value after gamma correction is 18% grey (122 in 0:255 histogram)

    //pH, and pD are the percentage of pixels for dark and highlight
    pD = ( (uint64_t)p_stats->fullhist_sum * dark_prc ) / 100;
    pH = ( (uint64_t)p_stats->fullhist_sum * bright_prc ) / 100;


    int32_t tpixels_median = p_stats->fullhist_sum / 2; // mid point of histogram

    //calculate median of histogram
    chist = 0;
    for ( i = 0; i < p_stats->fullhist_size; i++ ) {
        chist += p_stats->fullhist[i];
        if ( tpixels_median < chist ) {
            median = i;
            break;
        }
    }
    //calculate pH_cut - intensity cut for highlight pixels
    chist = 0;
    for ( i = 0; i < p_stats->fullhist_size; i++ ) {
        chist += p_stats->fullhist[i];
        if ( pH <= chist ) {
            pH_cut = i;
            break;
        }
    }

    //calculate pD - - intensity cut for dark pixels
    chist = 0;
    for ( i = 0; i < p_stats->fullhist_size; i++ ) {
        chist += p_stats->fullhist[i];
        if ( pD <= chist ) {
            pD_cut = i;
            break;
        }
    }
    pH_cut = ( pH_cut <= 0 ) ? 1 : pH_cut;
    pD_cut = ( pD_cut <= 0 ) ? 1 : pD_cut;

    // Compensate for iridix global digital gain
    pD_cut = ( pD_cut * p_iridix_core_obj->iridix_global_DG ) >> 8;
    pH_cut = ( pH_cut * p_iridix_core_obj->iridix_global_DG ) >> 8;
    pH_cut = ( pH_cut <= 0 ) ? 1 : pH_cut;
    pD_cut = ( pD_cut <= 0 ) ? 1 : pD_cut;
    median = ( median * p_iridix_core_obj->iridix_global_DG ) >> 8;


    /*
        Calculate dark enhancement as a function of intensity cut of dark pixels
                            f(pD_cut)
            max_dk     ___
                    |    \
                    |    .
                    |     \
                    |      .
                    |        \_____________
            min_dk    |
                    |--|----|-------------
                    pD_cut_min   pD_cut_max
    */


    m = 0;
    m = ( ( max_dk << 8 ) - ( min_dk << 8 ) ) / ( ( pD_cut_min != pD_cut_max ) ? pD_cut_min - pD_cut_max : 1 );
    int32_t dk_enh_Icut = ( ( m * ( median - pD_cut_min ) ) + ( max_dk << 8 ) ) >> 8;

    contrast = ( ( pH_cut << 8 ) / pD_cut ); //U24.8
    m = 0;

    if ( median <= 2 ) {
        min_dk = ( max_dk + 4096 ) / 2;
    }
    m = ( ( max_dk - min_dk ) << 8 ) / ( ( dark_contrast_max != dark_contrast_min ) ? dark_contrast_max - dark_contrast_min : 1 ); //U24.8
    dk_enh = ( ( m * ( contrast - dark_contrast_max ) ) + ( max_dk << 8 ) ) >> 8;                                                  //U32.0
    dk_enh = dk_enh_Icut > dk_enh ? dk_enh : dk_enh_Icut;
    if ( dk_enh < min_dk ) {
        dk_enh = min_dk;
    } else if ( dk_enh > max_dk ) {
        dk_enh = max_dk;
    }

    // time filter for iridix dark enhancement
    uint16_t dark_enh_coeff = p_input->cali_data.cali_iridix_avg_coef[0] * 2;

    if ( dark_enh_coeff > 1 ) {
        p_iridix_core_obj->dark_enh_avg += dk_enh - p_iridix_core_obj->dark_enh_avg / dark_enh_coeff; // division by zero is checked
        dk_enh = ( uint16_t )( p_iridix_core_obj->dark_enh_avg / dark_enh_coeff );                    // division by zero is checked
    }

    //Iridix strength is caclulated as: min(f(pD_cut),f(contrast))
    //------ f(pD_cut)

    dk_target = p_stats->fullhist_size * dark_prc_gain_target / 100;
    ir_gain = ( ( dk_target << 8 ) / pD_cut ) >> 8; //U32.0

    ir_strength = 100 * ( ir_gain - 1 ) / ( iridix_max_gain - 1 );

    ir_strength = ir_strength > 100 ? 100 : ir_strength;
    ir_strength = ir_strength < 0 ? 0 : ir_strength;

    /*
                        f(contrast)
        max str |                --------
                |             /
                |           -
                |         /
                |      -
                |    /
                |....
        min str    |---|----------|--------
                contrast_min   contrast_max
        */

    //clip strength according to f(contrast)
    if ( contrast <= contrast_min ) {
        ir_strength_max_ratio = min_str;
        if ( median <= target_LDR ) {
            m = 0;
            m = ( ( max_str - min_str ) << 8 ) / ( target_LDR ? -target_LDR : 1 );      //U24.16
            ir_strength_max_ratio = ( ( m * ( median - 0 ) ) + ( max_str << 8 ) ) >> 8; //U32.0
                                                                                        // LOG(LOG_DEBUG,"a %d \n", (int)ir_strength_max_ratio);
        }

    } else if ( contrast >= contrast_max ) {
        ir_strength_max_ratio = max_str;
        // LOG(LOG_DEBUG,"c %d \n", (int)ir_strength_max_ratio);

    } else {
        if ( pH_cut < target_LDR ) {
            m = 0;
            m = ( ( max_str - min_str ) << 8 ) / ( ( 0 - target_LDR ) );                //U24.16
            ir_strength_max_ratio = ( ( m * ( median - 0 ) ) + ( max_str << 8 ) ) >> 8; //U32.0
                                                                                        // LOG(LOG_DEBUG,"b1 %d \n", (int)ir_strength_max_ratio);

        } else if ( median <= target_LDR ) {
            m = 0;
            m = ( ( max_str - min_str ) << 8 ) / ( target_LDR ? -target_LDR : 1 );      //U24.16
            ir_strength_max_ratio = ( ( m * ( median - 0 ) ) + ( max_str << 8 ) ) >> 8; //U32.0
                                                                                        // LOG(LOG_DEBUG,"b2 %d \n", (int)ir_strength_max_ratio);
        } else {
            m = 0;
            m = ( ( max_str - min_str ) << 8 ) / ( ( contrast_max - contrast_min ) ? ( contrast_max - contrast_min ) : 1 ); //U24.16
            ir_strength_max_ratio = ( ( m * ( contrast - contrast_min ) ) + ( min_str << 8 ) ) >> 8;                        //U32.0
                                                                                                                            // LOG(LOG_DEBUG,"b3 %d \n", (int)ir_strength_max_ratio);
        }
    }

    ir_strength = ir_strength > ir_strength_max_ratio ? ir_strength_max_ratio : ir_strength;

    ir_strength = ir_strength < min_str ? min_str : ir_strength;
    p_iridix_core_obj->iridix_contrast = contrast;


    p_iridix_core_obj->mp_iridix_strength = (uint16_t)ir_strength;

    // LOG( LOG_NOTICE, "median %d pD_cut = %d pH_cut = %d contrast = %d irxDG = %d ir_strength_max_ratio %d ir_strength %d dk_enh %d\n",
    //                 (int)median, (int)pD_cut, (int)pH_cut, (int)contrast >> 8, (int)p_iridix_core_obj->iridix_global_DG, (int)ir_strength_max_ratio, (int)ir_strength, (int)dk_enh );

    return ( (uint16_t)dk_enh );
}

static uint16_t iridix_control_global_DG_calculate( iridix_acamera_core_obj_t *p_iridix_core_obj, iridix_stats_data_t *p_stats, iridix_acamera_input_t *p_input )
{

    /*
    Function Description:
    This function calculates the required digital gain, (independant from AE) so that iridix does not need to be used as a global gain.
    This gain will be set in accordance to contrast of the scene.
    */

    uint64_t chist = 0;
    uint64_t acc = 0;
    uint32_t hist_mean;

    int32_t gain;
    uint32_t i;
    int32_t ir_gdg_enable;
    int32_t pH;        // No. of pixels in cummulative histogram that is less than the intensity cut for highlight pixels. This percentage corresponds to bright_prc
    int32_t pClip_cut; // Intensity cut for highlight/clipped pixels. if clipping should be avoided bright_prc should be set to 100% of pixels
    int32_t max_gain_clipping;
    // ------- Tuning parameters --------- //
    int32_t target_LDR;    // This should correspond to 0.48 point in RAW histogram so that mean intensity value after gamma correction is 18% grey (122 in 0:255 histogram)
    int32_t bright_prc;    //  No of pixels that should be below hi_target_prc
    int32_t hi_target_prc; // Target for the bright_prc pixels to avoide/controll clipping


    //get values from calibration parameters
    target_LDR = p_input->cali_data.cali_ae_ctrl[1];
    bright_prc = p_input->cali_data.cali_ae_ctrl[5];
    hi_target_prc = p_input->cali_data.cali_ae_ctrl[6];
    ir_gdg_enable = p_input->cali_data.cali_ae_ctrl[7];
    // max clipped gain will make sure there that only 1% of pixels is avobe 75% of histogram
    pH = ( (uint64_t)p_stats->fullhist_sum * bright_prc ) / 100;

    chist = 0;
    // init to -1 to prepare for the loop
    pClip_cut = -1;

    // calculate mean value and find the clip point
    for ( i = 0; i < p_stats->fullhist_size; i++ ) {
        acc += ( 2 * i + 1ull ) * p_stats->fullhist[i];

        // if clip point >= 0: we already found it, don't need to continue
        if ( pClip_cut < 0 ) {
            chist += p_stats->fullhist[i];
            if ( pH <= chist ) {
                pClip_cut = i;
            }
        }
    }
    hist_mean = ( uint32_t )( div64_u64( acc, 2 * p_stats->fullhist_sum ) );


    pClip_cut = ( pClip_cut <= 0 ) ? 1 : pClip_cut;
    max_gain_clipping = ( ( p_stats->fullhist_size * hi_target_prc / 100 ) << 8 ) / pClip_cut; //U24.8

    //Try to always have a balance target as if it was a low dynamic range scene.
    gain = ( ( target_LDR << 8 ) / ( hist_mean ? hist_mean : 1 ) ); //U24.8

    // pH pixels should be below hi_target_prc of histogram to avoide clipping
    gain = gain <= max_gain_clipping ? gain : max_gain_clipping;
    gain = gain > 256 ? gain : 256;

    gain = gain > 4095 ? 4095 : gain; //12 bits gain U4.8

    if ( ir_gdg_enable == 0 ) {
        gain = 256;
    }

    // time filter for iridix global DG
    uint8_t iridix_avg_coeff = p_input->cali_data.cali_iridix_avg_coef[0];
    if ( iridix_avg_coeff > 1 ) {
        // iridix_avg_coeff = iridix_avg_coeff;
        p_iridix_core_obj->iridix_global_DG_avg += gain - p_iridix_core_obj->iridix_global_DG_avg / iridix_avg_coeff; // division by zero is checked
        gain = ( uint16_t )( p_iridix_core_obj->iridix_global_DG_avg / iridix_avg_coeff );                            // division by zero is checked
    }

    return ( (uint16_t)gain );
}


void *iridix_acamera_core_init( uint32_t ctx_id )
{
    iridix_acamera_core_obj_t *p_iridix_core_obj = NULL;

    if ( ctx_id >= FIRMWARE_CONTEXT_NUMBER ) {
        LOG( LOG_CRIT, "Invalid ctx_id: %d, greater than max: %d.", ctx_id, FIRMWARE_CONTEXT_NUMBER - 1 );
        return NULL;
    }

    p_iridix_core_obj = &iridix_core_objs[ctx_id];
    memset( p_iridix_core_obj, 0, sizeof( *p_iridix_core_obj ) );

    p_iridix_core_obj->dark_enh_avg = IRIDIX_STRENGTH_TARGET * CALIBRATION_IRIDIX_AVG_COEF_INIT * 2;
    p_iridix_core_obj->iridix_global_DG_avg = IRIDIX_STRENGTH_TARGET * CALIBRATION_IRIDIX_AVG_COEF_INIT * 2;
    p_iridix_core_obj->iridix_contrast = 256;
    p_iridix_core_obj->iridix_global_DG = 256;
    p_iridix_core_obj->dark_enh = 15000;
    p_iridix_core_obj->strength_target = IRIDIX_STRENGTH_TARGET;

    return p_iridix_core_obj;
}

int32_t iridix_acamera_core_deinit( void *iridix_ctx )
{
    return 0;
}

int32_t iridix_acamera_core_proc( void *iridix_ctx, iridix_stats_data_t *stats, iridix_input_data_t *input, iridix_output_data_t *output )
{
    if ( !iridix_ctx || !stats || !input || !input->acamera_input || !output || !output->acamera_output ) {
        LOG( LOG_ERR, "Invalid NULL pointer, %p-%p-%p-%p-%p-%p.", iridix_ctx, stats, input, input ? input->acamera_input : NULL, output, output ? output->acamera_output : NULL );
        return -1;
    }

    iridix_acamera_core_obj_t *p_iridix_core_obj = (iridix_acamera_core_obj_t *)iridix_ctx;
    iridix_acamera_input_t *p_acamera_input = (iridix_acamera_input_t *)input->acamera_input;
    iridix_acamera_output_t *p_acamera_output = (iridix_acamera_output_t *)output->acamera_output;

    uint16_t tmp_strength_target;

    if ( p_acamera_input->misc_info.global_manual_iridix == 0 ) {
        p_iridix_core_obj->iridix_global_DG = iridix_control_global_DG_calculate( p_iridix_core_obj, stats, p_acamera_input );
        p_iridix_core_obj->dark_enh = iridix_control_dark_enhancement_and_strength_calculate( p_iridix_core_obj, stats, p_acamera_input );
        tmp_strength_target = iridix_control_strength_clip_calculate( p_iridix_core_obj, p_acamera_input );
    } else {
        tmp_strength_target = p_acamera_input->misc_info.global_iridix_strength_target << 8;
    }

    uint16_t smin = (uint16_t)p_acamera_input->misc_info.global_minimum_iridix_strength * 256;
    uint16_t smax = (uint16_t)p_acamera_input->misc_info.global_maximum_iridix_strength * 256;
    if ( tmp_strength_target < smin ) {
        tmp_strength_target = smin;
    }

    if ( tmp_strength_target > smax ) {
        tmp_strength_target = smax;
    }

    p_iridix_core_obj->strength_target = tmp_strength_target;

    // output values
    p_acamera_output->strength_target = tmp_strength_target;
    p_acamera_output->dark_enh = p_iridix_core_obj->dark_enh;
    p_acamera_output->iridix_global_DG = p_iridix_core_obj->iridix_global_DG;
    p_acamera_output->iridix_contrast = p_iridix_core_obj->iridix_contrast;

    return 0;
}
