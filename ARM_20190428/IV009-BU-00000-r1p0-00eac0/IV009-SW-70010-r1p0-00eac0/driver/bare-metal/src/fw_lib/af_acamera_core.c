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
#include "af_standard_api.h"
#include "af_acamera_core.h"

#define AF_ZONES_COUNT_MAX ( 33 * 33 )

enum {
    AF_MODE_AF = 0,
    AF_MODE_CAF = 1,
    AF_MODE_MANUAL = 2,
    AF_MODE_CALIBRATION = 3,
};

typedef struct _af_acamera_core_obj_ {
    af_status_t af_status;
    af_fast_search_param_t fs;
    af_track_position_param_t tp;

    uint32_t pos_min;
    uint32_t pos_inf;
    uint32_t pos_macro;
    uint32_t pos_max;
    uint32_t def_pos_min;
    uint32_t def_pos_inf;
    uint32_t def_pos_macro;
    uint32_t def_pos_max;
    uint32_t def_pos_min_up;
    uint32_t def_pos_inf_up;
    uint32_t def_pos_macro_up;
    uint32_t def_pos_max_up;
    uint32_t def_pos_min_down;
    uint32_t def_pos_inf_down;
    uint32_t def_pos_macro_down;
    uint32_t def_pos_max_down;

    uint32_t last_position;
    int32_t last_sharp;
    uint32_t frame_number_from_start;
    uint8_t skip_frame;
    uint8_t frame_num;
    uint8_t zone_weight[AF_ZONES_COUNT_MAX];
    uint64_t zone_process_statistic[AF_ZONES_COUNT_MAX];
    uint32_t zone_process_reliablility[AF_ZONES_COUNT_MAX];
} af_acamera_core_obj_t;


af_acamera_core_obj_t af_core_objs[FIRMWARE_CONTEXT_NUMBER];


#ifdef LOG_MODULE
#undef LOG_MODULE
#define LOG_MODULE LOG_MODULE_AF_ACAMERA
#endif


void af_acamera_core_init_fast_search( af_acamera_core_obj_t *p_af_core_obj, af_acamera_input_t *p_af_acamera_input )
{
    af_misc_info_t *p_af_misc_info = &p_af_acamera_input->misc_info;
    af_lms_param_t *param = p_af_acamera_input->cali_data.af_param;

    // init default positions
    if ( 0 == p_af_core_obj->def_pos_min ) {
        p_af_core_obj->pos_min = p_af_core_obj->def_pos_min = param->pos_min;
        p_af_core_obj->pos_inf = p_af_core_obj->def_pos_inf = param->pos_inf;
        p_af_core_obj->pos_macro = p_af_core_obj->def_pos_macro = param->pos_macro;
        p_af_core_obj->pos_max = p_af_core_obj->def_pos_max = param->pos_max;
        p_af_core_obj->def_pos_min_down = param->pos_min_down;
        p_af_core_obj->def_pos_inf_down = param->pos_inf_down;
        p_af_core_obj->def_pos_macro_down = param->pos_macro_down;
        p_af_core_obj->def_pos_max_down = param->pos_max_down;
        p_af_core_obj->def_pos_min_up = param->pos_min_up;
        p_af_core_obj->def_pos_inf_up = param->pos_inf_up;
        p_af_core_obj->def_pos_macro_up = param->pos_macro_up;
        p_af_core_obj->def_pos_max_up = param->pos_max_up;
    }

    if ( p_af_misc_info->accel_angle ) {
        if ( p_af_misc_info->accel_angle > 0 ) { // Facing up
            p_af_core_obj->pos_min = p_af_core_obj->def_pos_min + ( ( p_af_core_obj->def_pos_min_up - p_af_core_obj->def_pos_min ) * p_af_misc_info->accel_angle >> 8 );
            p_af_core_obj->pos_inf = p_af_core_obj->def_pos_inf + ( ( p_af_core_obj->def_pos_inf_up - p_af_core_obj->def_pos_inf ) * p_af_misc_info->accel_angle >> 8 );
            p_af_core_obj->pos_macro = p_af_core_obj->def_pos_macro + ( ( p_af_core_obj->def_pos_macro - p_af_core_obj->def_pos_macro ) * p_af_misc_info->accel_angle >> 8 );
            p_af_core_obj->pos_max = p_af_core_obj->def_pos_max + ( ( p_af_core_obj->def_pos_max_up - p_af_core_obj->def_pos_max ) * p_af_misc_info->accel_angle >> 8 );
        } else { // Facing down
            p_af_core_obj->pos_min = p_af_core_obj->def_pos_min + ( ( p_af_core_obj->def_pos_min - p_af_core_obj->def_pos_min_down ) * p_af_misc_info->accel_angle >> 8 );
            p_af_core_obj->pos_inf = p_af_core_obj->def_pos_inf + ( ( p_af_core_obj->def_pos_inf - p_af_core_obj->def_pos_inf_down ) * p_af_misc_info->accel_angle >> 8 );
            p_af_core_obj->pos_macro = p_af_core_obj->def_pos_macro + ( ( p_af_core_obj->def_pos_macro - p_af_core_obj->def_pos_macro_down ) * p_af_misc_info->accel_angle >> 8 );
            p_af_core_obj->pos_max = p_af_core_obj->def_pos_max + ( ( p_af_core_obj->def_pos_max - p_af_core_obj->def_pos_max_down ) * p_af_misc_info->accel_angle >> 8 );
        }

        LOG( LOG_INFO, "Acceleromater data  %d\n", p_af_misc_info->accel_angle );
        LOG( LOG_INFO, "Defaul: min %d, inf %d macro %d, max %d, Recalculated min %d, inf %d, macro %d, max %d\n",
             p_af_core_obj->def_pos_min, p_af_core_obj->def_pos_inf, p_af_core_obj->def_pos_macro, p_af_core_obj->def_pos_max,
             p_af_core_obj->pos_min, p_af_core_obj->pos_inf, p_af_core_obj->pos_macro, p_af_core_obj->pos_max );
    }

    af_fast_search_param_t *fs = &p_af_core_obj->fs;

    uint16_t *ptr_af_zone_whgh_h = p_af_acamera_input->cali_data.af_zone_whgh_h;
    uint16_t *ptr_af_zone_whgh_v = p_af_acamera_input->cali_data.af_zone_whgh_v;

    uint8_t x, y;
    uint8_t zones_horiz = p_af_acamera_input->af_info.zones_horiz;
    uint8_t zones_vert = p_af_acamera_input->af_info.zones_vert;
    uint32_t roi = p_af_acamera_input->af_info.roi;


    uint8_t x_start = ( uint8_t )( ( ( ( roi >> 24 ) & 0xFF ) * zones_horiz + 128 ) >> 8 );
    uint8_t x_end = ( uint8_t )( ( ( ( roi >> 8 ) & 0xFF ) * zones_horiz + 128 ) >> 8 );
    uint8_t y_start = ( uint8_t )( ( ( ( roi >> 16 ) & 0xFF ) * zones_vert + 128 ) >> 8 );
    uint8_t y_end = ( uint8_t )( ( ( ( roi >> 0 ) & 0xFF ) * zones_vert + 128 ) >> 8 );

    LOG( LOG_INFO, "ROI: X from %d to %d out of %d, Y from %d to %d out of %d\n", x_start, x_end, zones_horiz, y_start, y_end, zones_vert );

    uint8_t zone_size_x = x_end - x_start;
    uint8_t zone_size_y = y_end - y_start;
    uint32_t middle_x = zone_size_x * 256 / 2;
    uint32_t middle_y = zone_size_y * 256 / 2;
    uint16_t gaus_center_x = ( p_af_acamera_input->cali_data.af_zone_whgh_h_len * 256 / 2 );
    uint16_t gaus_center_y = ( p_af_acamera_input->cali_data.af_zone_whgh_v_len * 256 / 2 );

    for ( y = 0; y < zones_vert; y++ ) {
        uint32_t inx = (uint32_t)y * zones_horiz;
        for ( x = 0; x < zones_horiz; x++ ) {
            if ( y >= y_start && y <= y_end &&
                 x >= x_start && x <= x_end ) {

                uint8_t index_y = ( y - y_start );
                uint8_t index_x = ( x - x_start );
                int32_t distance_x = ( index_x * 256 + 128 ) - middle_x;
                int32_t distance_y = ( index_y * 256 + 128 ) - middle_y;
                uint32_t coeff_x;
                uint32_t coeff_y;

                if ( ( x == x_end && x_start != x_end ) ||
                     ( y == y_end && y_start != y_end ) ) {
                    p_af_core_obj->zone_weight[inx + x] = 1;
                } else {
                    coeff_x = ( gaus_center_x + distance_x ) / 256;
                    if ( distance_x > 0 && ( distance_x & 0x80 ) )
                        coeff_x--;
                    coeff_y = ( gaus_center_y + distance_y ) / 256;
                    if ( distance_y > 0 && ( distance_y & 0x80 ) )
                        coeff_y--;

                    coeff_x = ptr_af_zone_whgh_h[coeff_x];
                    coeff_y = ptr_af_zone_whgh_v[coeff_y];

                    p_af_core_obj->zone_weight[inx + x] = ( coeff_x * coeff_y ) >> 4;
                    if ( !p_af_core_obj->zone_weight[inx + x] )
                        p_af_core_obj->zone_weight[inx + x] = 1;
                }
            } else {
                p_af_core_obj->zone_weight[inx + x] = 1;
            }
        }
    }

    uint16_t lens_min_step = p_af_acamera_input->misc_info.lens_min_step;

    fs->step = 0;
    if ( p_af_acamera_input->af_info.af_mode == AF_MODE_CALIBRATION ) {
        fs->position = AF_CALIBRATION_BOUNDARIES * lens_min_step;
        fs->step_number = ( uint16_t )( 0x10000 / lens_min_step - 2 * AF_CALIBRATION_BOUNDARIES + 1 );
    } else {
        fs->position = p_af_core_obj->pos_min;
        fs->step_number = param->fast_search_positions;
    }
    fs->prev_position = fs->position;
    fs->spot_zone_step_x = ISP_DEFAULT_AF_ZONES_HOR / AF_SPOT_COUNT_X;
    fs->spot_zone_step_y = ISP_DEFAULT_AF_ZONES_VERT / AF_SPOT_COUNT_Y;
    fs->spot_zone_size_x = fs->spot_zone_step_x;
    fs->spot_zone_size_y = fs->spot_zone_step_y;
    fs->finished_valid_spot_count = 0;

    LOG( LOG_INFO, "Zone X size %d, step %d, Y size %d, step %d\n", fs->spot_zone_size_x, fs->spot_zone_step_x, fs->spot_zone_size_y, fs->spot_zone_step_y );

    for ( y = 0; y < AF_SPOT_COUNT_Y; y++ ) {
        for ( x = 0; x < AF_SPOT_COUNT_X; x++ ) {
            fs->spots[y][x].min_value = 0x7FFFFFFF;
            fs->spots[y][x].max_value = 0x80000000;
            fs->spots[y][x].max_position = p_af_core_obj->pos_inf;
            fs->spots[y][x].before_max_value = 0x80000000;
            fs->spots[y][x].before_max_position = p_af_core_obj->pos_inf;
            fs->spots[y][x].after_max_value = 0x80000000;
            fs->spots[y][x].after_max_position = p_af_core_obj->pos_inf;
            fs->spots[y][x].previous_value = 0x80000000;
            fs->spots[y][x].status = AF_SPOT_STATUS_NOT_FINISHED;
            fs->spots[y][x].optimal_position = p_af_core_obj->pos_inf;
            fs->spots[y][x].dynamic_range = 1024; // max dynamic range is 1024
        }
    }
    p_af_core_obj->skip_frame = param->skip_frames_init; // first edge is big jump in position, so give it more time for stability

    p_af_core_obj->last_position = fs->position;
    p_af_core_obj->frame_number_from_start = 0;

    p_af_core_obj->af_status = AF_STATUS_FAST_SEARCH;
}


static void af_acamera_core_init_track_position( af_acamera_core_obj_t *p_af_core_obj, af_acamera_input_t *p_af_acamera_input )
{
    af_fast_search_param_t *fs = &p_af_core_obj->fs;
    af_track_position_param_t *tp = &p_af_core_obj->tp;
    af_lms_param_t *param = p_af_acamera_input->cali_data.af_param;
    p_af_core_obj->skip_frame = param->skip_frames_init;

    memset( fs, 0, sizeof( af_fast_search_param_t ) );
    tp->frames_in_tracking = array_size( tp->values ) + 2;
    tp->scene_is_changed = 0;
    tp->diff0_cnt = 0;

    LOG( LOG_INFO, "Position Track Started from position %d\n", fs->position );
}

static int32_t af_acamera_core_proc_statistic( af_acamera_core_obj_t *p_af_core_obj, af_stats_data_t *stats, af_acamera_input_t *p_af_acamera_input )
{
    uint8_t x, y;
    uint8_t zones_horiz = p_af_acamera_input->af_info.zones_horiz;
    uint8_t zones_vert = p_af_acamera_input->af_info.zones_vert;

    uint32_t( *p_stats )[2] = (uint32_t( * )[2])stats->zones_stats;
    uint8_t *weight = p_af_core_obj->zone_weight;
    uint64_t total = 0;
    uint32_t total_weight = 0;
    uint32_t max_I2_order = 0;

    for ( y = 0; y < zones_vert; y++ ) {
        uint32_t inx = (uint32_t)y * zones_horiz;
        for ( x = 0; x < zones_horiz; x++ ) {
            if ( weight[inx + x] ) {
                uint32_t af_word2 = p_stats[inx + x][1];
                uint32_t e_I2 = ( af_word2 >> 16 ) & 0x1F;
                if ( e_I2 > max_I2_order ) {
                    max_I2_order = e_I2;
                }
            }
        }
    }

    for ( y = 0; y < zones_vert; y++ ) {
        uint32_t inx = (uint32_t)y * zones_horiz;
        for ( x = 0; x < zones_horiz; x++ ) {
            //-----------------------------------------------------
            //
            //              AF2 statistics data format
            //
            //                  --- WORD 1 ---
            //  ____________________________________________
            //  |_________m_I4 _______|_________m_I2________|
            // 32                    16                     0
            //
            //                  --- WORD 2 ---
            //  ____________________________________________
            //  |_|e_E4_|_e_I4 _|_e_I2_|___________m_E4______|
            //   31    26      21     16                     0
            //
            //  where
            //          m_I2 - mantissa for I^2 (16 bits)
            //          m_I4 - mantissa for I^4 (16 bits)
            //          m_E4 - mantissa for E^4 (16 bits)
            //          e_I2 - exponenta for I^2 (5 bits)
            //          e_I4 - exponenta for I^4 (5+1 bits) -- MSB is 31st bit in word2
            //          e_E4 - exponenta for E^4 (5 bits)
            //
            //----------------------------------------------------
            /*
            Stats:Works on Bayer Domain
            R11G12R13
            G21B22G23
            R31G32R33
            N is the Number of Pixels/Zone.
            I2=N*(SUM_OF(PIXLES^2) in zone).
            I4=N*(SUM_OF(PIXLES^4) in zone) = (I2>>4)>^2
            E4=SUM_OF( Sum of (Diff of adj neighbours).^4)
            For B22 (R13-R31)^4+(R11-R33)^4+(G12-G32)^4+(G21-G23)^4)
            Q Format for m_E4 and m_I4 are matched.
            m_I4 is actually Left shifted by 8.*/

            uint32_t af_word1 = p_stats[inx + x][0];
            uint32_t af_word2 = p_stats[inx + x][1];
            uint32_t m_I4 = af_word1 >> 16;
            uint32_t m_E4 = af_word2 & 0x0000FFFF;
            uint32_t e_I2 = ( af_word2 >> 16 ) & 0x1F;
            uint32_t e_I4 = ( ( af_word2 >> 21 ) & 0x1F ) | ( ( af_word2 >> 31 ) << 5 );
            uint32_t e_E4 = ( af_word2 >> 26 ) & 0x1F;

            if ( e_I4 == 0x1F && m_I4 == 0xFFFF ) { // saturation
                LOG( LOG_WARNING, "AF2 saturation" );
            } else {

                if ( e_I4 ) {
                    m_I4 = m_I4 | 0x10000;
                    e_I4 = e_I4 - 1;
                }
                if ( e_E4 ) {
                    m_E4 = m_E4 | 0x10000;
                    e_E4 = e_E4 - 1;
                }

                uint64_t res = 0;
                if ( m_I4 ) {
                    res = ( (uint64_t)m_E4 << ( 32 + e_E4 - e_I4 ) ) / m_I4;
                }
                total += res * weight[inx + x];
                total_weight += weight[inx + x];
                p_af_core_obj->zone_process_statistic[inx + x] = res * weight[inx + x];
                p_af_core_obj->zone_process_reliablility[inx + x] = max_I2_order - e_I2;
            }
        }
    }
    if ( total_weight )
        total /= total_weight;
    if ( total > 0xFFFFFFFF ) {
        LOG( LOG_WARNING, "Total saturation" );
    }
    return acamera_log2_fixed_to_fixed_64( total, 0, LOG2_GAIN_SHIFT );
}

static uint16_t calculate_position( uint16_t x1, uint16_t x2, uint16_t x3, int32_t y1, int32_t y2, int32_t y3 )
{
    int64_t nominator, denominator;
    nominator = (int64_t)y1 * ( ( int32_t )( (uint32_t)x2 * x2 - (uint32_t)x3 * x3 ) );
    nominator += (int64_t)y2 * ( ( int32_t )( (uint32_t)x3 * x3 - (uint32_t)x1 * x1 ) );
    nominator += (int64_t)y3 * ( ( int32_t )( (uint32_t)x1 * x1 - (uint32_t)x2 * x2 ) );
    denominator = (int64_t)y1 * ( (int32_t)x2 - (int32_t)x3 );
    denominator += (int64_t)y2 * ( (int32_t)x3 - (int32_t)x1 );
    denominator += (int64_t)y3 * ( (int32_t)x1 - (int32_t)x2 );
    if ( denominator )
        return ( uint16_t )( nominator / denominator / 2 );
    else
        return x2;
}


static uint8_t is_frame_need_to_skip( af_acamera_core_obj_t *p_af_core_obj )
{
    uint8_t skip = 0;

    if ( p_af_core_obj->skip_frame ) {
        skip = 1;
        p_af_core_obj->skip_frame--;
    }

    return skip;
}

static void af_acamera_core_proc_fast_search_step( af_acamera_core_obj_t *p_af_core_obj, af_stats_data_t *stats, af_acamera_input_t *p_af_acamera_input )
{
    uint8_t x, y;
    uint16_t i, j;
    int32_t middle_spot = 0;

    uint8_t af_mode = p_af_acamera_input->af_info.af_mode;
    af_fast_search_param_t *fs = &p_af_core_obj->fs;
    af_lms_param_t *param = p_af_acamera_input->cali_data.af_param;
    uint8_t zones_horiz = p_af_acamera_input->af_info.zones_horiz;
    uint16_t lens_min_step = p_af_acamera_input->misc_info.lens_min_step;

    int32_t stat = af_acamera_core_proc_statistic( p_af_core_obj, stats, p_af_acamera_input );
    uint16_t pos = fs->position;

    uint8_t increasing = 0;
    uint8_t rising = 0;
    uint8_t falling = 0;

    for ( y = AF_SPOT_IGNORE_NUM; y < AF_SPOT_COUNT_Y - AF_SPOT_IGNORE_NUM; y++ ) {
        uint16_t y_off = fs->spot_zone_step_y * y;
        for ( x = AF_SPOT_IGNORE_NUM; x < AF_SPOT_COUNT_X - AF_SPOT_IGNORE_NUM; x++ ) {
            uint16_t x_off = fs->spot_zone_step_x * x;
            int32_t spot_stat = 0;
            uint32_t spot_reliable = 0;
            af_spot_param_t *spot = &fs->spots[y][x];
            if ( AF_SPOT_STATUS_NOT_FINISHED == spot->status ) {
                uint64_t spot_acc = 0;
                for ( j = y_off; j < y_off + fs->spot_zone_size_y; j++ ) {
                    uint16_t inx = j * zones_horiz;
                    for ( i = x_off; i < x_off + fs->spot_zone_size_x; i++ ) {
                        spot_acc += p_af_core_obj->zone_process_statistic[inx + i];
                        spot_reliable += p_af_core_obj->zone_process_reliablility[inx + i];
                    }
                }
                spot_stat = acamera_log2_fixed_to_fixed_64( spot_acc, 0, LOG2_GAIN_SHIFT );

                if ( x == AF_SPOT_COUNT_X / 2 && y == AF_SPOT_COUNT_Y / 2 ) {
                    middle_spot = spot_stat;
                }

                if ( spot_stat > spot->previous_value ) {
                    rising++;
                } else {
                    // for falling spot we use exit_threshold to check.
                    if ( ( spot->previous_value - spot_stat ) > param->exit_th )
                        falling++;
                }

                if ( spot_stat > spot->max_value ) {
                    spot->before_max_value = spot->previous_value;
                    spot->before_max_position = fs->prev_position;
                    spot->max_value = spot_stat;
                    spot->max_position = fs->position;
                    spot->after_max_value = 0x80000000;
                } else if ( spot->max_position == fs->prev_position ) { // maximum was found on the previous step
                    spot->after_max_value = spot_stat;
                    spot->after_max_position = fs->position;
                }
                if ( spot_stat < spot->min_value ) {
                    spot->min_value = spot_stat;
                }

                if ( af_mode != AF_MODE_CALIBRATION &&
                     ( ( spot->max_value > spot_stat + param->exit_th ) || ( fs->step == fs->step_number + 1 ) ) ) {

                    spot->status = AF_SPOT_STATUS_FINISHED_VALID;
                    fs->finished_valid_spot_count++;

                    if ( spot->before_max_value == 0x80000000 || spot->after_max_value == 0x80000000 ) { // never increase or never decrease - set maximum position
                        spot->optimal_position = spot->max_position;
                    } else { // central point calculation
                        spot->optimal_position = calculate_position( spot->after_max_position, spot->max_position, spot->before_max_position, spot->after_max_value, spot->max_value, spot->before_max_value );
                    }

                    if ( spot->optimal_position < p_af_core_obj->pos_inf ) {
                        spot->optimal_position = p_af_core_obj->pos_inf;
                    } else if ( spot->optimal_position > p_af_core_obj->pos_macro ) {
                        spot->optimal_position = p_af_core_obj->pos_macro;
                    }

                    LOG( LOG_INFO, "spot %dx%d finished with position %d, max_value %ld\n", x, y, spot->optimal_position / lens_min_step, spot->max_value );

                } else {
                    increasing = 1;
                }
                spot->previous_value = spot_stat;
                spot->reliable = spot_reliable;

                if ( param->print_debug )
                    LOG( LOG_NOTICE, "spot %d x %d, dynamic_range: %u, stat: %d, reliable: %d, max: %d, min: %d.",
                         x,
                         y,
                         spot->dynamic_range,
                         spot_stat,
                         spot_reliable,
                         spot->max_value,
                         spot->min_value );
            }
        }
    }

    // Only check invalid spot when we found at least 1 valid spot.
    if ( af_mode != AF_MODE_CALIBRATION && fs->finished_valid_spot_count ) {
        for ( y = AF_SPOT_IGNORE_NUM; y < AF_SPOT_COUNT_Y - AF_SPOT_IGNORE_NUM; y++ ) {
            for ( x = AF_SPOT_IGNORE_NUM; x < AF_SPOT_COUNT_X - AF_SPOT_IGNORE_NUM; x++ ) {
                af_spot_param_t *spot = &fs->spots[y][x];

                // start calc dynamic range from step 3.
                if ( fs->step >= 2 ) {
                    if ( spot->max_value != 0 ) {
                        spot->dynamic_range = ( ( spot->max_value - spot->min_value ) << 10 ) / spot->max_value;
                    } else {
                        LOG( LOG_ERR, "spot->max_value is 0, avoided divide by 0. " );
                    }

                    if ( spot->dynamic_range < param->dynamic_range_th ) {
                        // mark low contrast spot as invalid spot
                        spot->status = AF_SPOT_STATUS_FINISHED_INVALID;
                    }
                }
            }
        }
    }

    if ( af_mode == AF_MODE_CALIBRATION ) {
        p_af_core_obj->last_sharp = middle_spot;
    }

    if ( rising >= falling ) {
        increasing = 1;
    } else {
        increasing = 0;
    }

    if ( param->print_debug )
        LOG( LOG_NOTICE, "increasing: %d (^%d vs v%d), finished_valid_spot_count: %d, step: %d, step_number: %d.", increasing, rising, falling, fs->finished_valid_spot_count, fs->step, fs->step_number );

    p_af_core_obj->frame_number_from_start++;
    if ( ( af_mode != AF_MODE_CALIBRATION && !increasing ) || fs->step == fs->step_number + 1 ) {
        uint16_t best_position = 0;
        uint32_t best_reliable = 0xFFFFFF00;

        if ( param->print_debug )
            LOG( LOG_NOTICE, "Final position calc." );

        for ( y = AF_SPOT_IGNORE_NUM; y < AF_SPOT_COUNT_Y - AF_SPOT_IGNORE_NUM; y++ ) {
            for ( x = AF_SPOT_IGNORE_NUM; x < AF_SPOT_COUNT_X - AF_SPOT_IGNORE_NUM; x++ ) {
                af_spot_param_t *spot = &fs->spots[y][x];

                if ( x != AF_SPOT_COUNT_X / 2 && y != AF_SPOT_COUNT_Y / 2 )
                    continue;

                if ( spot->status != AF_SPOT_STATUS_FINISHED_VALID )
                    continue;

                if ( ( spot->max_value - spot->min_value ) > ( param->spot_tolerance ) ) {
                    if ( best_position < spot->optimal_position ) {
                        best_position = spot->optimal_position;
                        best_reliable = MIN( spot->reliable, best_reliable );

                        if ( param->print_debug )
                            LOG( LOG_NOTICE, "Best position: %d, for spot: %dx%d, reliable %u.", best_position / lens_min_step, x, y, spot->reliable );
                    }

                } else {
                    LOG( LOG_DEBUG, "Skip low contrast spot %dx%d, diff %ld, reliable %ld\n", x, y, spot->max_value - spot->min_value, spot->reliable );
                }
            }
        }
        if ( !best_position ) { // all spots are low contrast. Choose middle one.
            best_position = fs->spots[AF_SPOT_COUNT_Y / 2][AF_SPOT_COUNT_X / 2].optimal_position;

            if ( param->print_debug )
                LOG( LOG_NOTICE, "All spot are low contrast. Choose position from central spot: %d.", best_position / lens_min_step );
        }

        fs->position = best_position;

        if ( param->print_debug )
            LOG( LOG_NOTICE, "Position: %d, value: %d.", pos / lens_min_step, stat );

        p_af_core_obj->last_position = fs->position;
        if ( param->print_debug )
            LOG( LOG_NOTICE, "fast_search_finished, last_position: %d.", p_af_core_obj->last_position >> 6 );

        if ( af_mode == AF_MODE_CAF ) {
            p_af_core_obj->af_status = AF_STATUS_TRACKING;
            af_acamera_core_init_track_position( p_af_core_obj, p_af_acamera_input );
        } else {
            p_af_core_obj->af_status = AF_STATUS_CONVERGED;
        }

        LOG( LOG_INFO, "Found optimal position: %d\n", fs->position / lens_min_step );

        if ( param->print_debug ) {
            LOG( LOG_NOTICE, "### N: %d FS P: %d.", p_af_core_obj->frame_number_from_start, fs->position >> 6 );
        }

        return;
    } else {
        if ( param->print_debug )
            LOG( LOG_NOTICE, "Move to next step." );

        fs->step++;
        fs->prev_position = fs->position;
        if ( af_mode == AF_MODE_CALIBRATION ) {
            fs->position = ( AF_CALIBRATION_BOUNDARIES + fs->step ) * lens_min_step;
        } else {
            if ( fs->step <= fs->step_number ) {
                fs->position = p_af_core_obj->pos_inf + ( uint16_t )( ( uint32_t )( p_af_core_obj->pos_macro - p_af_core_obj->pos_inf ) * ( fs->step - 1 ) / ( fs->step_number - 1 ) );
            } else {
                fs->position = param->pos_max;
            }
        }

        if ( af_mode == AF_MODE_CALIBRATION ) {
            p_af_core_obj->last_position = fs->position;
            if ( param->print_debug )
                LOG( LOG_NOTICE, "calibration_mode, last_position: %d.", p_af_core_obj->last_position >> 6 );
            p_af_core_obj->skip_frame = param->skip_frames_move; // skip next frames
        } else {

            af_fast_search_param_t *fs = &p_af_core_obj->fs;
            uint8_t step = fs->step;
            uint16_t position;
            if ( step <= fs->step_number ) {
                position = p_af_core_obj->pos_inf + ( uint16_t )( ( uint32_t )( p_af_core_obj->pos_macro - p_af_core_obj->pos_inf ) * ( step - 1 ) / ( fs->step_number - 1 ) );
            } else {
                position = p_af_core_obj->pos_max;
            }

            p_af_core_obj->last_position = position;
            if ( param->print_debug )
                LOG( LOG_NOTICE, "last_position: %d, lens: %d.", p_af_core_obj->last_position, p_af_core_obj->last_position >> 6 );

            p_af_core_obj->skip_frame = param->skip_frames_move; // skip next frames
        }

        LOG( LOG_DEBUG, "Position: %d, value: %ld\n", pos / lens_min_step, stat );
    }

    if ( param->print_debug )
        LOG( LOG_NOTICE, "### N: %d FS P: %d, lens: %d.", p_af_core_obj->frame_number_from_start, fs->position, fs->position >> 6 );
}


static void af_acamera_core_proc_track_position_step( af_acamera_core_obj_t *p_af_core_obj, af_stats_data_t *stats, af_acamera_input_t *p_af_acamera_input )
{
    af_lms_param_t *param = p_af_acamera_input->cali_data.af_param;

    int32_t threshold_low = param->caf_stable_th;
    int32_t threshold_high = param->caf_trigger_th;

    af_track_position_param_t *tp = &p_af_core_obj->tp;
    if ( ++tp->values_inx >= array_size( tp->values ) )
        tp->values_inx = 0;
    tp->values[tp->values_inx] = af_acamera_core_proc_statistic( p_af_core_obj, stats, p_af_acamera_input );
    p_af_core_obj->skip_frame = 1;

    if ( tp->frames_in_tracking )
        tp->frames_in_tracking--;
    else {
        int i;
        int32_t stat_min = 0x7FFFFFFF;
        int32_t stat_max = -0x7FFFFFFF;
        for ( i = 0; i < array_size( tp->values ); i++ ) {
            if ( stat_min > tp->values[i] )
                stat_min = tp->values[i];
            if ( stat_max < tp->values[i] )
                stat_max = tp->values[i];
        }

        if ( param->print_debug ) {
            if ( 0 == ( ( stat_max - stat_min ) >> ( LOG2_GAIN_SHIFT - 4 ) ) ) {
                tp->diff0_cnt++;
            } else {
                LOG( LOG_INFO, "diff0_cnt: %d, low: %d, high: %d, min %d max %d diff %d.",
                     tp->diff0_cnt,
                     threshold_low >> ( LOG2_GAIN_SHIFT - 4 ),
                     threshold_high >> ( LOG2_GAIN_SHIFT - 4 ),
                     stat_min >> ( LOG2_GAIN_SHIFT - 4 ),
                     stat_max >> ( LOG2_GAIN_SHIFT - 4 ),
                     ( stat_max - stat_min ) >> ( LOG2_GAIN_SHIFT - 4 ) );

                tp->diff0_cnt = 0;
            }
        }


        LOG( LOG_INFO, "min %ld max %ld diff %ld\n", stat_min, stat_max, ( stat_max - stat_min ) >> ( LOG2_GAIN_SHIFT - 4 ) );

        if ( !tp->scene_is_changed ) {
            if ( stat_max - stat_min > threshold_high ) {
                tp->scene_is_changed = 1;

                if ( param->print_debug ) {
                    LOG( LOG_NOTICE, "Scene is changed - wait for stabilization." );
                }
            }
        } else if ( stat_max - stat_min < threshold_low ) {
            if ( param->print_debug ) {
                LOG( LOG_NOTICE, "Scene is stable - full refocus." );
            }

            af_acamera_core_init_fast_search( p_af_core_obj, p_af_acamera_input );
            return;
        }
    }
}

static void af_acamera_core_calc_sharp_lens_pos( af_acamera_core_obj_t *p_af_core_obj, af_stats_data_t *stats, af_acamera_input_t *p_af_acamera_input )
{
    // ignore first frames to wait for image stable
    if ( p_af_core_obj->frame_num > 0 ) {
        p_af_core_obj->frame_num--;
        return;
    }

    // skip frames after lens move
    if ( is_frame_need_to_skip( p_af_core_obj ) ) {
        return;
    }

    if ( AF_STATUS_FAST_SEARCH == p_af_core_obj->af_status ) {
        af_acamera_core_proc_fast_search_step( p_af_core_obj, stats, p_af_acamera_input );
    } else if ( AF_STATUS_TRACKING == p_af_core_obj->af_status ) {
        af_acamera_core_proc_track_position_step( p_af_core_obj, stats, p_af_acamera_input );
    }
}

static void af_acamera_core_calc_manual_lens_pos( af_acamera_core_obj_t *p_af_core_obj, af_acamera_input_t *p_af_acamera_input )
{
    uint16_t pos = p_af_core_obj->pos_min + ( uint16_t )( ( uint32_t )( p_af_core_obj->pos_max - p_af_core_obj->pos_min ) * p_af_acamera_input->af_info.af_pos_manual >> 8 );

    p_af_core_obj->last_position = pos;
    p_af_core_obj->af_status = AF_STATUS_CONVERGED;

    LOG( LOG_DEBUG, "Set Manual Position to %d.", pos / p_af_acamera_input->misc_info.lens_min_step );
}


void *af_acamera_core_init( uint32_t ctx_id )
{
    af_acamera_core_obj_t *p_af_core_obj = NULL;

    if ( ctx_id >= FIRMWARE_CONTEXT_NUMBER ) {
        LOG( LOG_CRIT, "Invalid ctx_id: %d, greater than max: %d.", ctx_id, FIRMWARE_CONTEXT_NUMBER - 1 );
        return NULL;
    }

    p_af_core_obj = &af_core_objs[ctx_id];
    memset( p_af_core_obj, 0, sizeof( *p_af_core_obj ) );

    p_af_core_obj->af_status = AF_STATUS_INVALID;
    p_af_core_obj->frame_num = 60;

    return p_af_core_obj;
}

int32_t af_acamera_core_deinit( void *af_ctx )
{
    return 0;
}

int32_t af_acamera_core_proc( void *af_ctx, af_stats_data_t *stats, af_input_data_t *input, af_output_data_t *output )
{
    if ( !af_ctx || !stats || !input || !input->acamera_input || !output || !output->acamera_output ) {
        LOG( LOG_ERR, "Invalid parameter: %p-%p-%p-%p-%p-%p.", af_ctx, stats, input, input ? input->acamera_input : NULL, output, output ? output->acamera_output : NULL );
        return -1;
    }

    af_acamera_core_obj_t *p_af_core_obj = (af_acamera_core_obj_t *)af_ctx;
    af_acamera_output_t *p_af_acamera_output = (af_acamera_output_t *)output->acamera_output;
    af_acamera_input_t *p_af_acamera_input = (af_acamera_input_t *)input->acamera_input;

    if ( stats->zones_size > AF_ZONES_COUNT_MAX ) {
        LOG( LOG_ERR, "Not supported AF zones, current size: %d, max: %d.", stats->zones_size, AF_ZONES_COUNT_MAX );
        return -2;
    }

    if ( p_af_acamera_input->af_info.refocus_required && p_af_core_obj->af_status != AF_STATUS_FAST_SEARCH ) {
        af_acamera_core_init_fast_search( p_af_core_obj, p_af_acamera_input );
    }

    if ( p_af_acamera_input->af_info.af_mode == AF_MODE_MANUAL ) {
        af_acamera_core_calc_manual_lens_pos( p_af_core_obj, p_af_acamera_input );
    } else {
        af_acamera_core_calc_sharp_lens_pos( p_af_core_obj, stats, p_af_acamera_input );
    }

    p_af_acamera_output->af_lens_pos = p_af_core_obj->last_position;
    p_af_acamera_output->af_sharp_val = p_af_core_obj->last_sharp;

    return 0;
}
