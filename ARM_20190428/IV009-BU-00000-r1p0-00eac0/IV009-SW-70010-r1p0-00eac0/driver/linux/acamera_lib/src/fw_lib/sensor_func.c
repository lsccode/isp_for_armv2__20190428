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

#include "acamera_fw.h"
#include "acamera_math.h"
#include "acamera_math.h"
#include "acamera_isp_config.h"
#include "system_timer.h"

#include "acamera_logger.h"
#include "sensor_fsm.h"

#include "acamera.h"

#if USER_MODULE
#include "sbuf.h"
#endif

typedef struct {
    uint16_t active_width;
    uint16_t active_height;
    uint16_t total_width;
    uint16_t total_height;
    uint16_t offset_x;
    uint16_t offset_y;
    uint16_t h_front_porch;
    uint16_t v_front_porch;
    uint16_t h_sync_width;
    uint16_t v_sync_width;
} dvi_sync_param_t;


#ifdef LOG_MODULE
#undef LOG_MODULE
#define LOG_MODULE LOG_MODULE_SENSOR
#endif

void sensor_init_output( sensor_fsm_ptr_t p_fsm, int mode )
{
    const sensor_param_t *param = p_fsm->ctrl.get_parameters( p_fsm->sensor_ctx );
    if ( ( mode != 720 ) && ( mode != 1080 ) ) {
        if ( param->active.height >= 1080 ) {
            mode = 1080;
        } else {
            mode = 720;
        }
    }

    // decrease output mode to 720p if active_height < mode
    if ( mode > param->active.height )
        mode = 720;

    p_fsm->isp_output_mode = mode;
}

///////////////////////////////////////////////////////////////////////////////

uint32_t sensor_boot_init( sensor_fsm_ptr_t p_fsm )
{
    ACAMERA_FSM2CTX_PTR( p_fsm )
        ->settings.sensor_init( &p_fsm->sensor_ctx, &p_fsm->ctrl );


#if USER_MODULE
    uint32_t idx = 0;
    sensor_param_t *param = (sensor_param_t *)p_fsm->ctrl.get_parameters( p_fsm->sensor_ctx );
    struct sensor_info ksensor_info;
    acamera_fsm_mgr_get_param( p_fsm->cmn.p_fsm_mgr, FSM_PARAM_GET_KSENSOR_INFO, NULL, 0, &ksensor_info, sizeof( ksensor_info ) );

    param->modes_num = ksensor_info.modes_num;
    if ( param->modes_num > ISP_MAX_SENSOR_MODES ) {
        param->modes_num = ISP_MAX_SENSOR_MODES;
    }

    for ( idx = 0; idx < param->modes_num; idx++ ) {
        param->modes_table[idx] = ksensor_info.modes[idx];

        LOG( LOG_INFO, "Sensor_mode[%d]: wdr_mode: %d, exp: %d.", idx,
             param->modes_table[idx].wdr_mode,
             param->modes_table[idx].exposures );
    }
#endif

    return 0;
}

void sensor_hw_init( sensor_fsm_ptr_t p_fsm )
{

#if FW_DO_INITIALIZATION
    acamera_isp_input_port_mode_request_write( p_fsm->cmn.isp_base, ACAMERA_ISP_INPUT_PORT_MODE_REQUEST_SAFE_STOP ); // urgent stop
#endif                                                                                                               //FW_DO_INITIALIZATION

    // 1): set sensor to preset_mode as required.
    p_fsm->ctrl.set_mode( p_fsm->sensor_ctx, p_fsm->preset_mode );
    p_fsm->ctrl.disable_sensor_isp( p_fsm->sensor_ctx );

    // 2): set to wdr_mode through general router (wdr_mode changed in sensor param in 1st step).
    const sensor_param_t *param = p_fsm->ctrl.get_parameters( p_fsm->sensor_ctx );

    fsm_param_set_wdr_param_t set_wdr_param;
    set_wdr_param.wdr_mode = param->modes_table[param->mode].wdr_mode;
    set_wdr_param.exp_number = param->modes_table[param->mode].exposures;
    acamera_fsm_mgr_set_param( p_fsm->cmn.p_fsm_mgr, FSM_PARAM_SET_WDR_MODE, &set_wdr_param, sizeof( set_wdr_param ) );

    // 3): Init or update the calibration data.
    acamera_init_calibrations( ACAMERA_FSM2CTX_PTR( p_fsm ) );

    // 4). update new settings to ISP if necessary
    acamera_update_cur_settings_to_isp( p_fsm->cmn.ctx_id );
}

void sensor_sw_init( sensor_fsm_ptr_t p_fsm )
{
    const sensor_param_t *param = p_fsm->ctrl.get_parameters( p_fsm->sensor_ctx );

#if FW_DO_INITIALIZATION
    /* sensor resolution */
    acamera_isp_top_active_width_write( p_fsm->cmn.isp_base, param->active.width );
    acamera_isp_top_active_height_write( p_fsm->cmn.isp_base, param->active.height );

    acamera_isp_metering_af_active_width_write( p_fsm->cmn.isp_base, param->active.width );
    acamera_isp_metering_af_active_height_write( p_fsm->cmn.isp_base, param->active.height );

    acamera_isp_lumvar_active_width_write( p_fsm->cmn.isp_base, param->active.width );
    acamera_isp_lumvar_active_height_write( p_fsm->cmn.isp_base, param->active.height );

    acamera_isp_input_port_hc_size0_write( p_fsm->cmn.isp_base, param->active.width );
    acamera_isp_input_port_hc_size1_write( p_fsm->cmn.isp_base, param->active.width );
    acamera_isp_input_port_vc_size_write( p_fsm->cmn.isp_base, param->active.height );

    sensor_init_output( p_fsm, p_fsm->isp_output_mode );
#endif //FW_DO_INITIALIZATION

    acamera_isp_input_port_mode_request_write( p_fsm->cmn.isp_base, ACAMERA_ISP_INPUT_PORT_MODE_REQUEST_SAFE_START );

    sensor_update_black( p_fsm );

    LOG( LOG_NOTICE, "Sensor initialization is complete, ID 0x%04X resolution %dx%d", p_fsm->ctrl.get_id( p_fsm->sensor_ctx ), param->active.width, param->active.height );
}

void sensor_update_black( sensor_fsm_ptr_t p_fsm )
{
    int32_t stub = 0;
    exposure_set_t exp;

    acamera_fsm_mgr_get_param( p_fsm->cmn.p_fsm_mgr, FSM_PARAM_GET_FRAME_EXPOSURE_SET, &stub, sizeof( stub ), &exp, sizeof( exp ) );

    uint16_t again_log2 = ( uint16_t )( exp.info.again_log2 >> ( LOG2_GAIN_SHIFT - 5 ) ); // makes again in format log2(gain)*32
    uint32_t wdr_mode = 0;

    acamera_fsm_mgr_get_param( p_fsm->cmn.p_fsm_mgr, FSM_PARAM_GET_WDR_MODE, NULL, 0, &wdr_mode, sizeof( wdr_mode ) );
    uint32_t idx_r = CALIBRATION_BLACK_LEVEL_R;
    uint32_t idx_b = CALIBRATION_BLACK_LEVEL_B;
    uint32_t idx_gr = CALIBRATION_BLACK_LEVEL_GR;
    uint32_t idx_gb = CALIBRATION_BLACK_LEVEL_GB;
    uint32_t r = acamera_calc_modulation_u16( again_log2, _GET_MOD_ENTRY16_PTR( ACAMERA_FSM2CTX_PTR( p_fsm ), idx_r ), _GET_ROWS( ACAMERA_FSM2CTX_PTR( p_fsm ), idx_r ) );
    uint32_t b = acamera_calc_modulation_u16( again_log2, _GET_MOD_ENTRY16_PTR( ACAMERA_FSM2CTX_PTR( p_fsm ), idx_b ), _GET_ROWS( ACAMERA_FSM2CTX_PTR( p_fsm ), idx_b ) );
    uint32_t gr = acamera_calc_modulation_u16( again_log2, _GET_MOD_ENTRY16_PTR( ACAMERA_FSM2CTX_PTR( p_fsm ), idx_gr ), _GET_ROWS( ACAMERA_FSM2CTX_PTR( p_fsm ), idx_gr ) );
    uint32_t gb = acamera_calc_modulation_u16( again_log2, _GET_MOD_ENTRY16_PTR( ACAMERA_FSM2CTX_PTR( p_fsm ), idx_gb ), _GET_ROWS( ACAMERA_FSM2CTX_PTR( p_fsm ), idx_gb ) );

    p_fsm->black_level = r;

    if ( wdr_mode == WDR_MODE_FS_LIN ) {
        if ( ACAMERA_FSM2CTX_PTR( p_fsm )->stab.global_manual_frame_stitch == 0 ) {
            acamera_isp_frame_stitch_black_level_long_write( p_fsm->cmn.isp_base, p_fsm->black_level );
            acamera_isp_frame_stitch_black_level_medium_write( p_fsm->cmn.isp_base, p_fsm->black_level );
            acamera_isp_frame_stitch_black_level_short_write( p_fsm->cmn.isp_base, p_fsm->black_level );
            acamera_isp_frame_stitch_black_level_very_short_write( p_fsm->cmn.isp_base, p_fsm->black_level );
            acamera_isp_frame_stitch_black_level_out_write( p_fsm->cmn.isp_base, p_fsm->black_level << BLACK_LEVEL_SHIFT_DG );
        }

        if ( ACAMERA_FSM2CTX_PTR( p_fsm )->stab.global_manual_black_level == 0 ) {
            acamera_isp_sensor_offset_pre_shading_offset_00_write( p_fsm->cmn.isp_base, (uint32_t)_GET_MOD_ENTRY16_PTR( ACAMERA_FSM2CTX_PTR( p_fsm ), idx_r )->y << BLACK_LEVEL_SHIFT_WB );
            acamera_isp_sensor_offset_pre_shading_offset_01_write( p_fsm->cmn.isp_base, (uint32_t)_GET_MOD_ENTRY16_PTR( ACAMERA_FSM2CTX_PTR( p_fsm ), idx_gr )->y << BLACK_LEVEL_SHIFT_WB );
            acamera_isp_sensor_offset_pre_shading_offset_10_write( p_fsm->cmn.isp_base, (uint32_t)_GET_MOD_ENTRY16_PTR( ACAMERA_FSM2CTX_PTR( p_fsm ), idx_gb )->y << BLACK_LEVEL_SHIFT_WB );
            acamera_isp_sensor_offset_pre_shading_offset_11_write( p_fsm->cmn.isp_base, (uint32_t)_GET_MOD_ENTRY16_PTR( ACAMERA_FSM2CTX_PTR( p_fsm ), idx_b )->y << BLACK_LEVEL_SHIFT_WB );
        }

        acamera_isp_digital_gain_offset_write( p_fsm->cmn.isp_base, (uint32_t)_GET_MOD_ENTRY16_PTR( ACAMERA_FSM2CTX_PTR( p_fsm ), idx_gr )->y << BLACK_LEVEL_SHIFT_DG );
    } else {
        if ( ACAMERA_FSM2CTX_PTR( p_fsm )->stab.global_manual_black_level == 0 ) {
            acamera_isp_sensor_offset_pre_shading_offset_00_write( p_fsm->cmn.isp_base, r << BLACK_LEVEL_SHIFT_WB );
            acamera_isp_sensor_offset_pre_shading_offset_01_write( p_fsm->cmn.isp_base, gr << BLACK_LEVEL_SHIFT_WB );
            acamera_isp_sensor_offset_pre_shading_offset_10_write( p_fsm->cmn.isp_base, gb << BLACK_LEVEL_SHIFT_WB );
            acamera_isp_sensor_offset_pre_shading_offset_11_write( p_fsm->cmn.isp_base, b << BLACK_LEVEL_SHIFT_WB );
        }

        acamera_isp_digital_gain_offset_write( p_fsm->cmn.isp_base, (uint32_t)p_fsm->black_level << BLACK_LEVEL_SHIFT_DG );
    }
}

uint32_t sensor_get_lines_second( sensor_fsm_ptr_t p_fsm )
{
    const sensor_param_t *param = p_fsm->ctrl.get_parameters( p_fsm->sensor_ctx );
    return param->lines_per_second;
}

void sensor_deinit( sensor_fsm_ptr_t p_fsm )
{
    ACAMERA_FSM2CTX_PTR( p_fsm )
        ->settings.sensor_deinit( p_fsm->sensor_ctx );
}
