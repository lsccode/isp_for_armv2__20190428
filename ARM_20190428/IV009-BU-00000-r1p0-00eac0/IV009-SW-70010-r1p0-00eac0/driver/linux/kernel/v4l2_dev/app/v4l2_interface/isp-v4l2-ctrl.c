/*
*
* SPDX-License-Identifier: GPL-2.0
*
* Copyright (C) 2011-2018 ARM or its affiliates
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; version 2.
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
* You should have received a copy of the GNU General Public License along
* with this program; if not, write to the Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*
*/

#include <media/v4l2-device.h>
#include <media/v4l2-ctrls.h>

#include "acamera_logger.h"

#include "isp-v4l2-common.h"
#include "isp-v4l2-ctrl.h"
#include "fw-interface.h"

static int isp_v4l2_ctrl_check_valid( struct v4l2_ctrl *ctrl )
{
    if ( ctrl->is_int == 1 ) {
        if ( ctrl->val < ctrl->minimum || ctrl->val > ctrl->maximum )
            return -EINVAL;
    }

    return 0;
}

static int isp_v4l2_ctrl_s_ctrl_standard( struct v4l2_ctrl *ctrl )
{
    int ret = 0;
    struct v4l2_ctrl_handler *hdl = ctrl->handler;

    isp_v4l2_ctrl_t *isp_ctrl = std_hdl_to_isp_ctrl( hdl );
    int ctx_id = isp_ctrl->ctx_id;

    LOG( LOG_INFO, "Control - id:0x%x, val:%d, is_int:%d, min:%d, max:%d.\n",
         ctrl->id, ctrl->val, ctrl->is_int, ctrl->minimum, ctrl->maximum );

    if ( isp_v4l2_ctrl_check_valid( ctrl ) < 0 ) {
        return -EINVAL;
    }

    switch ( ctrl->id ) {
    case V4L2_CID_BRIGHTNESS:
        ret = fw_intf_set_brightness( ctx_id, ctrl->val );
        break;
    case V4L2_CID_CONTRAST:
        ret = fw_intf_set_contrast( ctx_id, ctrl->val );
        break;
    case V4L2_CID_SATURATION:
        ret = fw_intf_set_saturation( ctx_id, ctrl->val );
        break;
    case V4L2_CID_HUE:
        ret = fw_intf_set_hue( ctx_id, ctrl->val );
        break;
    case V4L2_CID_SHARPNESS:
        ret = fw_intf_set_sharpness( ctx_id, ctrl->val );
        break;
    case V4L2_CID_COLORFX:
        ret = fw_intf_set_color_fx( ctx_id, ctrl->val );
        break;
    case V4L2_CID_HFLIP:
        ret = fw_intf_set_hflip( ctx_id, ctrl->val );
        break;
    case V4L2_CID_VFLIP:
        ret = fw_intf_set_vflip( ctx_id, ctrl->val );
        break;
    case V4L2_CID_AUTOGAIN:
        ret = fw_intf_set_autogain( ctx_id, ctrl->val );
        break;
    case V4L2_CID_GAIN:
        ret = fw_intf_set_gain( ctx_id, ctrl->val );
        break;
    case V4L2_CID_EXPOSURE_AUTO:
        ret = fw_intf_set_exposure_auto( ctx_id, ctrl->val );
        break;
    case V4L2_CID_EXPOSURE_ABSOLUTE:
        ret = fw_intf_set_exposure( ctx_id, ctrl->val );
        break;
    case V4L2_CID_EXPOSURE_AUTO_PRIORITY:
        ret = fw_intf_set_variable_frame_rate( ctx_id, ctrl->val );
        break;
    case V4L2_CID_AUTO_WHITE_BALANCE:
        ret = fw_intf_set_white_balance_auto( ctx_id, ctrl->val );
        break;
    case V4L2_CID_WHITE_BALANCE_TEMPERATURE:
        ret = fw_intf_set_white_balance( ctx_id, ctrl->val );
        break;
    case V4L2_CID_FOCUS_AUTO:
        ret = fw_intf_set_focus_auto( ctx_id, ctrl->val );
        break;
    case V4L2_CID_FOCUS_ABSOLUTE:
        ret = fw_intf_set_focus( ctx_id, ctrl->val );
        break;
    }

    return ret;
}

static int isp_v4l2_ctrl_g_ctrl_custom( struct v4l2_ctrl *ctrl )
{
    int ret = -EINVAL;

    struct v4l2_ctrl_handler *hdl = ctrl->handler;

    isp_v4l2_ctrl_t *isp_ctrl = cst_hdl_to_isp_ctrl( hdl );
    int ctx_id = isp_ctrl->ctx_id;

    LOG( LOG_INFO, "Control - id:0x%x, val:%d, is_int:%d, min:%d, max:%d.\n",
         ctrl->id, ctrl->val, ctrl->is_int, ctrl->minimum, ctrl->maximum );

    if ( isp_v4l2_ctrl_check_valid( ctrl ) < 0 ) {
        LOG( LOG_ERR, "Invalid param: id:0x%x, val:0x%x, is_int:%d, min:0x%x, max:0x%x.\n",
             ctrl->id, ctrl->val, ctrl->is_int, ctrl->minimum, ctrl->maximum );

        return -EINVAL;
    }

    switch ( ctrl->id ) {
    case ISP_V4L2_CID_TEST_PATTERN:
        ret = fw_intf_get_test_pattern( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get test_pattern: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_TEST_PATTERN_TYPE:
        ret = fw_intf_get_test_pattern_type( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get test_pattern_type: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_SENSOR_PRESET:
        ret = fw_intf_get_sensor_preset( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get sensor preset: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_AF_ROI:
        // map [0,127] to [0, 254] due to limitaton of V4L2_CTRL_TYPE_INTEGER.
        ret = fw_intf_get_af_roi( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get af roi: 0x%x.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_OUTPUT_FR_ON_OFF:
        ret = fw_intf_get_output_fr_on_off( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get FR on/off: 0x%x.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_OUTPUT_DS1_ON_OFF:
        ret = fw_intf_get_output_ds1_on_off( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get DS1 on/off: 0x%x.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_TEMPER3_MODE:
        ret = fw_intf_get_temper3_mode( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get temper3_mode: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_FREEZE_FIRMWARE:
        ret = fw_intf_get_system_freeze_firmware( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get system_freeze_firmware: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_MANUAL_EXPOSURE:
        ret = fw_intf_get_system_manual_exposure( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get system_manual_exposure: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_MANUAL_INTEGRATION_TIME:
        ret = fw_intf_get_system_manual_integration_time( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get system_manual_integration_time: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_MANUAL_MAX_INTEGRATION_TIME:
        ret = fw_intf_get_system_manual_max_integration_time( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get system_manual_max_integration_time: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_MANUAL_SENSOR_ANALOG_GAIN:
        ret = fw_intf_get_system_manual_sensor_analog_gain( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get system_manual_sensor_analog_gain: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_MANUAL_SENSOR_DIGITAL_GAIN:
        ret = fw_intf_get_system_manual_sensor_digital_gain( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get system_manual_sensor_digital_gain: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_MANUAL_ISP_DIGITAL_GAIN:
        ret = fw_intf_get_system_manual_isp_digital_gain( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get system_manual_isp_digital_gain: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_MANUAL_EXPOSURE_RATIO:
        ret = fw_intf_get_system_manual_exposure_ratio( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get system_manual_exposure_ratio: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_MANUAL_AWB:
        ret = fw_intf_get_system_manual_awb( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get system_manual_awb: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_MANUAL_SATURATION:
        ret = fw_intf_get_system_manual_saturation( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get system_manual_saturation: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_MAX_EXPOSURE_RATIO:
        ret = fw_intf_get_system_max_exposure_ratio( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get system_max_exposure_ratio: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_EXPOSURE:
        ret = fw_intf_get_system_exposure( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get system_exposure: %d, rc: %d.\n", ctrl->val, ret );
        break;
    case ISP_V4L2_CID_SYSTEM_INTEGRATION_TIME:
        ret = fw_intf_get_system_integration_time( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get system_integration_time: %d, rc: %d.\n", ctrl->val, ret );
        break;
    case ISP_V4L2_CID_SYSTEM_MAX_INTEGRATION_TIME:
        ret = fw_intf_get_system_max_integration_time( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get system_max_integration_time: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_EXPOSURE_RATIO:
        ret = fw_intf_get_system_exposure_ratio( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get system_exposure_ratio: %d, rc: %d.\n", ctrl->val, ret );
        break;
    case ISP_V4L2_CID_SYSTEM_SENSOR_ANALOG_GAIN:
        ret = fw_intf_get_system_sensor_analog_gain( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get system_sensor_analog_gain: %d, rc: %d.\n", ctrl->val, ret );
        break;
    case ISP_V4L2_CID_SYSTEM_MAX_SENSOR_ANALOG_GAIN:
        ret = fw_intf_get_system_max_sensor_analog_gain( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get system_max_sensor_analog_gain: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_SENSOR_DIGITAL_GAIN:
        ret = fw_intf_get_system_sensor_digital_gain( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get system_sensor_digital_gain: %d, rc: %d.\n", ctrl->val, ret );
        break;
    case ISP_V4L2_CID_SYSTEM_MAX_SENSOR_DIGITAL_GAIN:
        ret = fw_intf_get_system_max_sensor_digital_gain( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get system_max_sensor_digital_gain: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_ISP_DIGITAL_GAIN:
        ret = fw_intf_get_system_isp_digital_gain( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get system_isp_digital_gain: %d, rc: %d.\n", ctrl->val, ret );
        break;
    case ISP_V4L2_CID_SYSTEM_MAX_ISP_DIGITAL_GAIN:
        ret = fw_intf_get_system_max_isp_digital_gain( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get system_max_isp_digital_gain: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_AWB_RED_GAIN:
        ret = fw_intf_get_system_awb_red_gain( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get system_awb_red_gain: %d, rc: %d.\n", ctrl->val, ret );
        break;
    case ISP_V4L2_CID_SYSTEM_AWB_BLUE_GAIN:
        ret = fw_intf_get_system_awb_blue_gain( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get system_awb_blue_gain: %d, rc: %d.\n", ctrl->val, ret );
        break;
    case ISP_V4L2_CID_ISP_MODULES_MANUAL_IRIDIX:
        ret = fw_intf_get_isp_modules_manual_iridix( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get isp_modules_manual_iridix: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_ISP_MODULES_MANUAL_SINTER:
        ret = fw_intf_get_isp_modules_manual_sinter( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get isp_modules_manual_sinter: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_ISP_MODULES_MANUAL_TEMPER:
        ret = fw_intf_get_isp_modules_manual_temper( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get isp_modules_manual_temper: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_ISP_MODULES_MANUAL_AUTO_LEVEL:
        ret = fw_intf_get_isp_modules_manual_auto_level( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get isp_modules_manual_auto_level: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_ISP_MODULES_MANUAL_FRAME_STITCH:
        ret = fw_intf_get_isp_modules_manual_frame_stitch( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get isp_modules_manual_frame_stitch: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_ISP_MODULES_MANUAL_RAW_FRONTEND:
        ret = fw_intf_get_isp_modules_manual_raw_frontend( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get isp_modules_manual_raw_frontend: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_ISP_MODULES_MANUAL_BLACK_LEVEL:
        ret = fw_intf_get_isp_modules_manual_black_level( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get isp_modules_manual_black_level: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_ISP_MODULES_MANUAL_SHADING:
        ret = fw_intf_get_isp_modules_manual_shading( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get isp_modules_manual_shading: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_ISP_MODULES_MANUAL_DEMOSAIC:
        ret = fw_intf_get_isp_modules_manual_demosaic( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get isp_modules_manual_demosaic: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_ISP_MODULES_MANUAL_CNR:
        ret = fw_intf_get_isp_modules_manual_cnr( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get isp_modules_manual_cnr: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_ISP_MODULES_MANUAL_SHARPEN:
        ret = fw_intf_get_isp_modules_manual_sharpen( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get isp_modules_manual_sharpen: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_IMAGE_RESIZE_ENABLE_ID:
        ret = fw_intf_get_image_resize_enable( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get image_resize_enable: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_IMAGE_RESIZE_TYPE_ID:
        ret = fw_intf_get_image_resize_type( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get image_resize_type: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_IMAGE_CROP_XOFFSET_ID:
        ret = fw_intf_get_image_crop_xoffset( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get image_crop_xoffset: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_IMAGE_CROP_YOFFSET_ID:
        ret = fw_intf_get_image_crop_yoffset( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get image_crop_yoffset: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_IMAGE_RESIZE_WIDTH_ID:
        ret = fw_intf_get_image_resize_width( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get image_resize_width: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_IMAGE_RESIZE_HEIGHT_ID:
        ret = fw_intf_get_image_resize_height( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get image_resize_height: %d.\n", ctrl->val );
        break;
    case ISP_V4L2_CID_STATUS_INFO_EXPOSURE_LOG2:
        ret = fw_intf_get_status_info_exposure_log2( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get status_info_exposure_log2: %d, rc: %d.\n", ctrl->val, ret );
        break;
    case ISP_V4L2_CID_STATUS_INFO_GAIN_LOG2:
        ret = fw_intf_get_status_info_gain_log2( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get status_info_gain_log2: %d, rc: %d.\n", ctrl->val, ret );
        break;
    case ISP_V4L2_CID_STATUS_INFO_GAIN_ONES:
        ret = fw_intf_get_status_info_gain_ones( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get status_info_gain_ones: %d, rc: %d.\n", ctrl->val, ret );
        break;
    case ISP_V4L2_CID_STATUS_INFO_AWB_MIX_LIGHT_CONTRAST:
        ret = fw_intf_get_status_info_awb_mix_light_contrast( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get status_info_awb_mix_light_contrast: %d, rc: %d.\n", ctrl->val, ret );
        break;
    case ISP_V4L2_CID_STATUS_INFO_AF_LENS_POS:
        ret = fw_intf_get_status_info_af_lens_pos( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get status_info_af_lens_pos: %d, rc: %d.\n", ctrl->val, ret );
        break;
    case ISP_V4L2_CID_STATUS_INFO_AF_FOCUS_VALUE:
        ret = fw_intf_get_status_info_af_focus_value( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get status_info_af_focus_value: %d, rc: %d.\n", ctrl->val, ret );
        break;
    case ISP_V4L2_CID_INFO_FW_REVISION:
        ret = fw_intf_get_info_fw_revision( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "get info_fw_revision: %d, rc: %d.\n", ctrl->val, ret );
        break;
    case ISP_V4L2_CID_SENSOR_LINES_PER_SECOND:
        ret = -1;
        break;
    case ISP_V4L2_CID_AE_COMPENSATION:
        ret = fw_intf_get_ae_compensation( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "fw_intf_get_ae_compensation: %d, rc: %d.\n", ctrl->val, ret );
        break;
    case ISP_V4L2_CID_SYSTEM_DYNAMIC_GAMMA_ENABLE:
        ret = fw_intf_get_system_dynamic_gamma_enable( ctx_id, &ctrl->val );
        LOG( LOG_INFO, "fw_intf_get_system_dynamic_gamma_enable: %d, rc: %d.\n", ctrl->val, ret );
        break;
    }

    return ret;
}

static int isp_v4l2_ctrl_s_ctrl_custom( struct v4l2_ctrl *ctrl )
{
    int ret = -EINVAL;

    struct v4l2_ctrl_handler *hdl = ctrl->handler;

    isp_v4l2_ctrl_t *isp_ctrl = cst_hdl_to_isp_ctrl( hdl );
    int ctx_id = isp_ctrl->ctx_id;

    LOG( LOG_INFO, "Control - id:0x%x, val:%d, is_int:%d, min:%d, max:%d.\n",
         ctrl->id, ctrl->val, ctrl->is_int, ctrl->minimum, ctrl->maximum );

    if ( isp_v4l2_ctrl_check_valid( ctrl ) < 0 ) {
        LOG( LOG_ERR, "Invalid param: id:0x%x, val:0x%x, is_int:%d, min:0x%x, max:0x%x.\n",
             ctrl->id, ctrl->val, ctrl->is_int, ctrl->minimum, ctrl->maximum );

        return -EINVAL;
    }

    switch ( ctrl->id ) {
    case ISP_V4L2_CID_TEST_PATTERN:
        LOG( LOG_INFO, "new test_pattern: %d.\n", ctrl->val );
        ret = fw_intf_set_test_pattern( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_TEST_PATTERN_TYPE:
        LOG( LOG_INFO, "new test_pattern_type: %d.\n", ctrl->val );
        ret = fw_intf_set_test_pattern_type( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_AF_REFOCUS:
        LOG( LOG_INFO, "new focus: %d.\n", ctrl->val );
        ret = fw_intf_set_af_refocus( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_SENSOR_PRESET:
        LOG( LOG_INFO, "new sensor preset: %d.\n", ctrl->val );
        ret = fw_intf_isp_set_sensor_preset( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_AF_ROI:
        LOG( LOG_INFO, "new af roi: 0x%x.\n", ctrl->val );
        ret = fw_intf_set_af_roi( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_OUTPUT_FR_ON_OFF:
        LOG( LOG_INFO, "output FR on/off: 0x%x.\n", ctrl->val );
        ret = fw_intf_set_output_fr_on_off( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_OUTPUT_DS1_ON_OFF:
        LOG( LOG_INFO, "output DS1 on/off: 0x%x.\n", ctrl->val );
        ret = fw_intf_set_output_ds1_on_off( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_TEMPER3_MODE:
        LOG( LOG_INFO, "new temper3_mode: %d.\n", ctrl->val );
        ret = fw_intf_set_temper3_mode( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_FREEZE_FIRMWARE:
        LOG( LOG_INFO, "new system_freeze_firmware: %d.\n", ctrl->val );
        ret = fw_intf_set_system_freeze_firmware( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_MANUAL_EXPOSURE:
        LOG( LOG_INFO, "new system_manual_exposure: %d.\n", ctrl->val );
        ret = fw_intf_set_system_manual_exposure( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_MANUAL_INTEGRATION_TIME:
        LOG( LOG_INFO, "new system_manual_integration_time: %d.\n", ctrl->val );
        ret = fw_intf_set_system_manual_integration_time( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_MANUAL_MAX_INTEGRATION_TIME:
        LOG( LOG_INFO, "new system_manual_max_integration_time: %d.\n", ctrl->val );
        ret = fw_intf_set_system_manual_max_integration_time( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_MANUAL_SENSOR_ANALOG_GAIN:
        LOG( LOG_INFO, "new system_manual_sensor_analog_gain: %d.\n", ctrl->val );
        ret = fw_intf_set_system_manual_sensor_analog_gain( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_MANUAL_SENSOR_DIGITAL_GAIN:
        LOG( LOG_INFO, "new system_manual_sensor_digital_gain: %d.\n", ctrl->val );
        ret = fw_intf_set_system_manual_sensor_digital_gain( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_MANUAL_ISP_DIGITAL_GAIN:
        LOG( LOG_INFO, "new system_manual_isp_digital_gain: %d.\n", ctrl->val );
        ret = fw_intf_set_system_manual_isp_digital_gain( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_MANUAL_EXPOSURE_RATIO:
        LOG( LOG_INFO, "new system_manual_exposure_ratio: %d.\n", ctrl->val );
        ret = fw_intf_set_system_manual_exposure_ratio( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_MANUAL_AWB:
        LOG( LOG_INFO, "new system_manual_awb: %d.\n", ctrl->val );
        ret = fw_intf_set_system_manual_awb( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_MANUAL_SATURATION:
        LOG( LOG_INFO, "new system_manual_saturation: %d.\n", ctrl->val );
        ret = fw_intf_set_system_manual_saturation( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_MAX_EXPOSURE_RATIO:
        LOG( LOG_INFO, "new system_max_exposure_ratio: %d.\n", ctrl->val );
        ret = fw_intf_set_system_max_exposure_ratio( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_EXPOSURE:
        LOG( LOG_INFO, "new system_exposure: %d.\n", ctrl->val );
        ret = fw_intf_set_system_exposure( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_INTEGRATION_TIME:
        LOG( LOG_INFO, "new system_integration_time: %d.\n", ctrl->val );
        ret = fw_intf_set_system_integration_time( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_EXPOSURE_RATIO:
        LOG( LOG_INFO, "new system_exposure_ratio: %d.\n", ctrl->val );
        ret = fw_intf_set_system_exposure_ratio( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_MAX_INTEGRATION_TIME:
        LOG( LOG_INFO, "new system_max_integration_time: %d.\n", ctrl->val );
        ret = fw_intf_set_system_max_integration_time( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_SENSOR_ANALOG_GAIN:
        LOG( LOG_INFO, "new system_sensor_analog_gain: %d.\n", ctrl->val );
        ret = fw_intf_set_system_sensor_analog_gain( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_MAX_SENSOR_ANALOG_GAIN:
        LOG( LOG_INFO, "new system_max_sensor_analog_gain: %d.\n", ctrl->val );
        ret = fw_intf_set_system_max_sensor_analog_gain( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_SENSOR_DIGITAL_GAIN:
        LOG( LOG_INFO, "new system_sensor_digital_gain: %d.\n", ctrl->val );
        ret = fw_intf_set_system_sensor_digital_gain( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_MAX_SENSOR_DIGITAL_GAIN:
        LOG( LOG_INFO, "new system_max_sensor_digital_gain: %d.\n", ctrl->val );
        ret = fw_intf_set_system_max_sensor_digital_gain( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_ISP_DIGITAL_GAIN:
        LOG( LOG_INFO, "new system_isp_digital_gain: %d.\n", ctrl->val );
        ret = fw_intf_set_system_isp_digital_gain( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_MAX_ISP_DIGITAL_GAIN:
        LOG( LOG_INFO, "new system_max_isp_digital_gain: %d.\n", ctrl->val );
        ret = fw_intf_set_system_max_isp_digital_gain( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_AWB_RED_GAIN:
        LOG( LOG_INFO, "new system_awb_red_gain: %d.\n", ctrl->val );
        ret = fw_intf_set_system_awb_red_gain( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_AWB_BLUE_GAIN:
        LOG( LOG_INFO, "new system_awb_blue_gain: %d.\n", ctrl->val );
        ret = fw_intf_set_system_awb_blue_gain( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_ISP_MODULES_MANUAL_IRIDIX:
        LOG( LOG_INFO, "new isp_modules_manual_iridix: %d.\n", ctrl->val );
        ret = fw_intf_set_isp_modules_manual_iridix( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_ISP_MODULES_MANUAL_SINTER:
        LOG( LOG_INFO, "new isp_modules_manual_sinter: %d.\n", ctrl->val );
        ret = fw_intf_set_isp_modules_manual_sinter( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_ISP_MODULES_MANUAL_TEMPER:
        LOG( LOG_INFO, "new isp_modules_manual_temper: %d.\n", ctrl->val );
        ret = fw_intf_set_isp_modules_manual_temper( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_ISP_MODULES_MANUAL_AUTO_LEVEL:
        LOG( LOG_INFO, "new isp_modules_manual_auto_level: %d.\n", ctrl->val );
        ret = fw_intf_set_isp_modules_manual_auto_level( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_ISP_MODULES_MANUAL_FRAME_STITCH:
        LOG( LOG_INFO, "new isp_modules_manual_frame_stitch: %d.\n", ctrl->val );
        ret = fw_intf_set_isp_modules_manual_frame_stitch( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_ISP_MODULES_MANUAL_RAW_FRONTEND:
        LOG( LOG_INFO, "new isp_modules_manual_raw_frontend: %d.\n", ctrl->val );
        ret = fw_intf_set_isp_modules_manual_raw_frontend( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_ISP_MODULES_MANUAL_BLACK_LEVEL:
        LOG( LOG_INFO, "new isp_modules_manual_black_level: %d.\n", ctrl->val );
        ret = fw_intf_set_isp_modules_manual_black_level( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_ISP_MODULES_MANUAL_SHADING:
        LOG( LOG_INFO, "new isp_modules_manual_shading: %d.\n", ctrl->val );
        ret = fw_intf_set_isp_modules_manual_shading( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_ISP_MODULES_MANUAL_DEMOSAIC:
        LOG( LOG_INFO, "new isp_modules_manual_demosaic: %d.\n", ctrl->val );
        ret = fw_intf_set_isp_modules_manual_demosaic( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_ISP_MODULES_MANUAL_CNR:
        LOG( LOG_INFO, "new isp_modules_manual_cnr: %d.\n", ctrl->val );
        ret = fw_intf_set_isp_modules_manual_cnr( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_ISP_MODULES_MANUAL_SHARPEN:
        LOG( LOG_INFO, "new isp_modules_manual_sharpen: %d.\n", ctrl->val );
        ret = fw_intf_set_isp_modules_manual_sharpen( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_IMAGE_RESIZE_ENABLE_ID:
        LOG( LOG_INFO, "new image_resize_enable: %d.\n", ctrl->val );
        ret = fw_intf_set_image_resize_enable( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_IMAGE_RESIZE_TYPE_ID:
        LOG( LOG_INFO, "new image_resize_type: %d.\n", ctrl->val );
        ret = fw_intf_set_image_resize_type( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_IMAGE_CROP_XOFFSET_ID:
        LOG( LOG_INFO, "new image_crop_xoffset: %d.\n", ctrl->val );
        ret = fw_intf_set_image_crop_xoffset( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_IMAGE_CROP_YOFFSET_ID:
        LOG( LOG_INFO, "new image_crop_yoffset: %d.\n", ctrl->val );
        ret = fw_intf_set_image_crop_yoffset( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_IMAGE_RESIZE_WIDTH_ID:
        LOG( LOG_INFO, "new image_resize_width: %d.\n", ctrl->val );
        ret = fw_intf_set_image_resize_width( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_IMAGE_RESIZE_HEIGHT_ID:
        LOG( LOG_INFO, "new image_resize_height: %d.\n", ctrl->val );
        ret = fw_intf_set_image_resize_height( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_AE_COMPENSATION:
        LOG( LOG_INFO, "new ae_compensation: %d.\n", ctrl->val );
        ret = fw_intf_set_ae_compensation( ctx_id, ctrl->val );
        break;
    case ISP_V4L2_CID_SYSTEM_DYNAMIC_GAMMA_ENABLE:
        LOG( LOG_INFO, "new system_dynamic_gamma_enable: %d, rc: %d.\n", ctrl->val, ret );
        ret = fw_intf_set_system_dynamic_gamma_enable( ctx_id, ctrl->val );
        break;
    }

    return ret;
}

static const struct v4l2_ctrl_ops isp_v4l2_ctrl_ops_custom = {
    .s_ctrl = isp_v4l2_ctrl_s_ctrl_custom,
    .g_volatile_ctrl = isp_v4l2_ctrl_g_ctrl_custom,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_test_pattern = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_TEST_PATTERN,
    .name = "ISP Test Pattern",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 1,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_test_pattern_type = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_TEST_PATTERN_TYPE,
    .name = "ISP Test Pattern Type",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 3,
    .step = 1,
    .def = 3,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_af_refocus = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_AF_REFOCUS,
    .name = "ISP AF Refocus",
    .type = V4L2_CTRL_TYPE_BUTTON,
    .min = 0,
    .max = 0,
    .step = 0,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_sensor_preset = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_SENSOR_PRESET,
    .name = "ISP Sensor Preset",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 16,
    .step = 1,
    .def = 0,
};


static const struct v4l2_ctrl_config isp_v4l2_ctrl_af_roi = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_AF_ROI,
    .name = "ISP AF ROI",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 0x7F7F7F7F,
    .step = 1,
    .def = 0x20206060,
};


static const struct v4l2_ctrl_config isp_v4l2_ctrl_output_fr_on_off = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_OUTPUT_FR_ON_OFF,
    .name = "ISP FR ON/OFF",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 0x7FFFFFFF,
    .step = 1,
    .def = 0,
};


static const struct v4l2_ctrl_config isp_v4l2_ctrl_output_ds1_on_off = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_OUTPUT_DS1_ON_OFF,
    .name = "ISP DS1 ON/OFF",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 0x7FFFFFFF,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_temper3_mode = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_TEMPER3_MODE,
    .name = "ISP temper3 mode or temper2 mode",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 1,
    .step = 1,
    .def = 1,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_system_freeze_firmware = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_SYSTEM_FREEZE_FIRMWARE,
    .name = "Freeze ISP firmware",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 1,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_system_manual_exposure = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_SYSTEM_MANUAL_EXPOSURE,
    .name = "Enable manual exposure",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 1,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_system_manual_integration_time = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_SYSTEM_MANUAL_INTEGRATION_TIME,
    .name = "Enable manual integration time",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 1,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_system_manual_max_integration_time = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_SYSTEM_MANUAL_MAX_INTEGRATION_TIME,
    .name = "Enable manual max integration time",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 1,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_system_manual_sensor_analog_gain = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_SYSTEM_MANUAL_SENSOR_ANALOG_GAIN,
    .name = "Enable manual sensor analog gain",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 1,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_system_manual_sensor_digital_gain = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_SYSTEM_MANUAL_SENSOR_DIGITAL_GAIN,
    .name = "Enable manual sensor digital gain",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 1,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_system_manual_isp_digital_gain = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_SYSTEM_MANUAL_ISP_DIGITAL_GAIN,
    .name = "Enable manual ISP digital gain",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 1,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_system_manual_exposure_ratio = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_SYSTEM_MANUAL_EXPOSURE_RATIO,
    .name = "Enable manual exposure ratio",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 1,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_system_manual_awb = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_SYSTEM_MANUAL_AWB,
    .name = "Enable manual AWB",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 1,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_system_manual_saturation = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_SYSTEM_MANUAL_SATURATION,
    .name = "Enable manual saturation",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 1,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_system_max_exposure_ratio = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_SYSTEM_MAX_EXPOSURE_RATIO,
    .name = "Set maximum exposure ratio",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 1,
    .max = 16777216, // 64^4
    .step = 1,
    .def = 1,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_system_exposure = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_SYSTEM_EXPOSURE,
    .name = "Set current exposure",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 0x7FFFFFFF,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_system_integration_time = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_SYSTEM_INTEGRATION_TIME,
    .name = "Set current integration time",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 0x7FFFFFFF,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_system_exposure_ratio = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_SYSTEM_EXPOSURE_RATIO,
    .name = "Set current exposure ratio",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 0x7FFFFFFF,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_system_max_integration_time = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_SYSTEM_MAX_INTEGRATION_TIME,
    .name = "Set max integration time",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 0x7FFFFFFF,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_system_sensor_analog_gain = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_SYSTEM_SENSOR_ANALOG_GAIN,
    .name = "Set sensor analog gain",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 255,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_system_max_sensor_analog_gain = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_SYSTEM_MAX_SENSOR_ANALOG_GAIN,
    .name = "Set max sensor analog gain",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 255,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_system_sensor_digital_gain = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_SYSTEM_SENSOR_DIGITAL_GAIN,
    .name = "Set sensor digital gain",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 255,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_system_max_sensor_digital_gain = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_SYSTEM_MAX_SENSOR_DIGITAL_GAIN,
    .name = "Set max sensor digital gain",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 255,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_system_isp_digital_gain = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_SYSTEM_ISP_DIGITAL_GAIN,
    .name = "Set isp digital gain",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 255,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_system_max_isp_digital_gain = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_SYSTEM_MAX_ISP_DIGITAL_GAIN,
    .name = "Set max isp digital gain",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 255,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_system_awb_red_gain = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_SYSTEM_AWB_RED_GAIN,
    .name = "Set awb red gain",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 65535,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_system_awb_blue_gain = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_SYSTEM_AWB_BLUE_GAIN,
    .name = "Set awb blue gain",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 65535,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_isp_modules_manual_iridix = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_ISP_MODULES_MANUAL_IRIDIX,
    .name = "Enable manual iridix",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 1,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_isp_modules_manual_sinter = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_ISP_MODULES_MANUAL_SINTER,
    .name = "Enable manual sinter",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 1,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_isp_modules_manual_temper = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_ISP_MODULES_MANUAL_TEMPER,
    .name = "Enable manual temper",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 1,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_isp_modules_manual_auto_level = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_ISP_MODULES_MANUAL_AUTO_LEVEL,
    .name = "Enable manual auto level",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 1,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_isp_modules_manual_frame_stitch = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_ISP_MODULES_MANUAL_FRAME_STITCH,
    .name = "Enable manual frame stitch",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 1,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_isp_modules_manual_raw_frontend = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_ISP_MODULES_MANUAL_RAW_FRONTEND,
    .name = "Enable manual raw frontend",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 1,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_isp_modules_manual_black_level = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_ISP_MODULES_MANUAL_BLACK_LEVEL,
    .name = "Enable manual black level",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 1,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_isp_modules_manual_shading = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_ISP_MODULES_MANUAL_SHADING,
    .name = "Enable manual shading",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 1,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_isp_modules_manual_demosaic = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_ISP_MODULES_MANUAL_DEMOSAIC,
    .name = "Enable manual demosaic",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 1,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_isp_modules_manual_cnr = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_ISP_MODULES_MANUAL_CNR,
    .name = "Enable manual CNR",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 1,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_isp_modules_manual_sharpen = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_ISP_MODULES_MANUAL_SHARPEN,
    .name = "Enable manual sharpen",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 1,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_image_resize_enable = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_IMAGE_RESIZE_ENABLE_ID,
    .name = "Enable resize",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 1,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_image_resize_type = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_IMAGE_RESIZE_TYPE_ID,
    .name = "Image resize_type",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 2,
    .step = 1,
    .def = 2,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_image_crop_xoffset = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_IMAGE_CROP_XOFFSET_ID,
    .name = "Image crop xoffset",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 4000,
    .step = 1,
    .def = 1,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_image_crop_yoffset = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_IMAGE_CROP_YOFFSET_ID,
    .name = "Image crop yoffset",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 4000,
    .step = 1,
    .def = 1,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_image_resize_width = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_IMAGE_RESIZE_WIDTH_ID,
    .name = "Image resize width",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 5000,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_image_resize_height = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_IMAGE_RESIZE_HEIGHT_ID,
    .name = "Image resize height",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 5000,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_status_info_exposure_log2 = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_STATUS_INFO_EXPOSURE_LOG2,
    .name = "Get expososure log2",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 0xffffffff,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_status_info_gain_log2 = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_STATUS_INFO_GAIN_LOG2,
    .name = "Get gain log2",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 0xffffffff,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_status_info_gain_ones = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_STATUS_INFO_GAIN_ONES,
    .name = "Get gain ones",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 0xffffffff,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_status_info_awb_mix_light_contrast = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_STATUS_INFO_AWB_MIX_LIGHT_CONTRAST,
    .name = "Get AWB mix light contrast",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 0xffffffff,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_status_info_af_lens_pos = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_STATUS_INFO_AF_LENS_POS,
    .name = "Get AF lens position",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 0xffffffff,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_status_info_af_focus_value = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_STATUS_INFO_AF_FOCUS_VALUE,
    .name = "Get AF focus value",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 0xffffffff,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_info_fw_revision = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_INFO_FW_REVISION,
    .name = "Get firmware revision",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 0xffffffff,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_sensor_lines_per_second = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_SENSOR_LINES_PER_SECOND,
    .name = "Get Sensor Lines per second",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 0xffffffff,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_ae_compensation = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_AE_COMPENSATION,
    .name = "Set/Get AE Compensation",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 0xffffffff,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_system_dynamic_gamma_enable = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .id = ISP_V4L2_CID_SYSTEM_DYNAMIC_GAMMA_ENABLE,
    .name = "Enable/Disable Dynamic Gamma",
    .type = V4L2_CTRL_TYPE_INTEGER,
    .min = 0,
    .max = 1,
    .step = 1,
    .def = 0,
};

static const struct v4l2_ctrl_ops isp_v4l2_ctrl_ops = {
    .s_ctrl = isp_v4l2_ctrl_s_ctrl_standard,
};

static const struct v4l2_ctrl_config isp_v4l2_ctrl_class = {
    .ops = &isp_v4l2_ctrl_ops_custom,
    .flags = V4L2_CTRL_FLAG_READ_ONLY | V4L2_CTRL_FLAG_WRITE_ONLY,
    .id = ISP_V4L2_CID_ISP_V4L2_CLASS,
    .name = "ARM ISP Controls",
    .type = V4L2_CTRL_TYPE_CTRL_CLASS,
};

#define ADD_CTRL_STD( id, min, max, step, def )                  \
    {                                                            \
        if ( fw_intf_validate_control( id ) ) {                  \
            v4l2_ctrl_new_std( hdl_std_ctrl, &isp_v4l2_ctrl_ops, \
                               id, min, max, step, def );        \
        }                                                        \
    }

#define ADD_CTRL_STD_MENU( id, max, skipmask, def )                   \
    {                                                                 \
        if ( fw_intf_validate_control( id ) ) {                       \
            v4l2_ctrl_new_std_menu( hdl_std_ctrl, &isp_v4l2_ctrl_ops, \
                                    id, max, skipmask, def );         \
        }                                                             \
    }


#if ( LINUX_VERSION_CODE >= KERNEL_VERSION( 4, 1, 1 ) )
#define ADD_CTRL_CST_VOLATILE( id, cfg, priv )                          \
    {                                                                   \
        if ( fw_intf_validate_control( id ) ) {                         \
            tmp_ctrl = v4l2_ctrl_new_custom( hdl_cst_ctrl, cfg, priv ); \
            if ( tmp_ctrl )                                             \
                tmp_ctrl->flags |= ( V4L2_CTRL_FLAG_VOLATILE |          \
                                     V4L2_CTRL_FLAG_EXECUTE_ON_WRITE ); \
        }                                                               \
    }

#else
#define ADD_CTRL_CST_VOLATILE( id, cfg, priv )                          \
    {                                                                   \
        if ( fw_intf_validate_control( id ) ) {                         \
            tmp_ctrl = v4l2_ctrl_new_custom( hdl_cst_ctrl, cfg, priv ); \
            if ( tmp_ctrl )                                             \
                tmp_ctrl->flags |= V4L2_CTRL_FLAG_VOLATILE;             \
        }                                                               \
    }

#endif

#define ADD_CTRL_CST( id, cfg, priv )                        \
    {                                                        \
        if ( fw_intf_validate_control( id ) ) {              \
            v4l2_ctrl_new_custom( hdl_cst_ctrl, cfg, priv ); \
        }                                                    \
    }

int isp_v4l2_ctrl_init( uint32_t ctx_id, isp_v4l2_ctrl_t *ctrl )
{
    struct v4l2_ctrl_handler *hdl_std_ctrl = &ctrl->ctrl_hdl_std_ctrl;
    struct v4l2_ctrl_handler *hdl_cst_ctrl = &ctrl->ctrl_hdl_cst_ctrl;
    struct v4l2_ctrl *tmp_ctrl;

    ctrl->ctx_id = ctx_id;

    LOG( LOG_INFO, "[ctrl] ctx_id#%d: ctrl: %p, hdl_std_ctrl: %p, ctrl_hdl_cst_ctrl: %p.",
         ctx_id, ctrl, hdl_std_ctrl, hdl_cst_ctrl );

    /* Init and add standard controls */
    v4l2_ctrl_handler_init( hdl_std_ctrl, 10 );
    v4l2_ctrl_new_custom( hdl_std_ctrl, &isp_v4l2_ctrl_class, NULL );

    /* general */
    ADD_CTRL_STD( V4L2_CID_BRIGHTNESS, 0, 255, 1, 128 );
    ADD_CTRL_STD( V4L2_CID_CONTRAST, 0, 255, 1, 128 );
    ADD_CTRL_STD( V4L2_CID_SATURATION, 0, 255, 1, 128 );
    ADD_CTRL_STD( V4L2_CID_HUE, 0, 360, 1, 180 );
    ADD_CTRL_STD( V4L2_CID_SHARPNESS, 0, 255, 1, 128 );
    ADD_CTRL_STD_MENU( V4L2_CID_COLORFX, 9, 0x1F0, 0 );
    /* orientation */
    ADD_CTRL_STD( V4L2_CID_HFLIP, 0, 1, 1, 0 );
    ADD_CTRL_STD( V4L2_CID_VFLIP, 0, 1, 1, 0 );
    /* exposure */
    ADD_CTRL_STD( V4L2_CID_AUTOGAIN, 0, 1, 1, 1 );
    ADD_CTRL_STD( V4L2_CID_GAIN, 100, 3200, 1, 100 );
    ADD_CTRL_STD_MENU( V4L2_CID_EXPOSURE_AUTO, 1, 0x0, 0 );
    ADD_CTRL_STD( V4L2_CID_EXPOSURE_ABSOLUTE, 1, 1000, 1, 33 );
    ADD_CTRL_STD( V4L2_CID_EXPOSURE_AUTO_PRIORITY, 0, 1, 1, 0 );
    /* white balance */
    ADD_CTRL_STD( V4L2_CID_AUTO_WHITE_BALANCE, 0, 1, 1, 1 );
    ADD_CTRL_STD( V4L2_CID_WHITE_BALANCE_TEMPERATURE, 2000, 8000, 1000, 5000 );
    /* focus */
    ADD_CTRL_STD( V4L2_CID_FOCUS_AUTO, 0, 1, 1, 1 );
    ADD_CTRL_STD( V4L2_CID_FOCUS_ABSOLUTE, 0, 255, 1, 0 );

    /* Init and add custom controls */
    v4l2_ctrl_handler_init( hdl_cst_ctrl, 64 );
    v4l2_ctrl_new_custom( hdl_cst_ctrl, &isp_v4l2_ctrl_class, NULL );

    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_TEST_PATTERN, &isp_v4l2_ctrl_test_pattern, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_TEST_PATTERN_TYPE, &isp_v4l2_ctrl_test_pattern_type, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_AF_REFOCUS, &isp_v4l2_ctrl_af_refocus, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_SENSOR_PRESET, &isp_v4l2_ctrl_sensor_preset, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_AF_ROI, &isp_v4l2_ctrl_af_roi, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_OUTPUT_FR_ON_OFF, &isp_v4l2_ctrl_output_fr_on_off, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_OUTPUT_DS1_ON_OFF, &isp_v4l2_ctrl_output_ds1_on_off, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_TEMPER3_MODE, &isp_v4l2_ctrl_temper3_mode, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_SYSTEM_FREEZE_FIRMWARE, &isp_v4l2_ctrl_system_freeze_firmware, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_SYSTEM_MANUAL_EXPOSURE, &isp_v4l2_ctrl_system_manual_exposure, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_SYSTEM_MANUAL_INTEGRATION_TIME, &isp_v4l2_ctrl_system_manual_integration_time, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_SYSTEM_MANUAL_MAX_INTEGRATION_TIME, &isp_v4l2_ctrl_system_manual_max_integration_time, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_SYSTEM_MANUAL_SENSOR_ANALOG_GAIN, &isp_v4l2_ctrl_system_manual_sensor_analog_gain, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_SYSTEM_MANUAL_SENSOR_DIGITAL_GAIN, &isp_v4l2_ctrl_system_manual_sensor_digital_gain, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_SYSTEM_MANUAL_ISP_DIGITAL_GAIN, &isp_v4l2_ctrl_system_manual_isp_digital_gain, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_SYSTEM_MANUAL_EXPOSURE_RATIO, &isp_v4l2_ctrl_system_manual_exposure_ratio, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_SYSTEM_MANUAL_AWB, &isp_v4l2_ctrl_system_manual_awb, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_SYSTEM_MANUAL_SATURATION, &isp_v4l2_ctrl_system_manual_saturation, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_SYSTEM_MAX_EXPOSURE_RATIO, &isp_v4l2_ctrl_system_max_exposure_ratio, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_SYSTEM_EXPOSURE, &isp_v4l2_ctrl_system_exposure, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_SYSTEM_INTEGRATION_TIME, &isp_v4l2_ctrl_system_integration_time, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_SYSTEM_EXPOSURE_RATIO, &isp_v4l2_ctrl_system_exposure_ratio, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_SYSTEM_MAX_INTEGRATION_TIME, &isp_v4l2_ctrl_system_max_integration_time, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_SYSTEM_SENSOR_ANALOG_GAIN, &isp_v4l2_ctrl_system_sensor_analog_gain, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_SYSTEM_MAX_SENSOR_ANALOG_GAIN, &isp_v4l2_ctrl_system_max_sensor_analog_gain, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_SYSTEM_SENSOR_DIGITAL_GAIN, &isp_v4l2_ctrl_system_sensor_digital_gain, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_SYSTEM_MAX_SENSOR_DIGITAL_GAIN, &isp_v4l2_ctrl_system_max_sensor_digital_gain, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_SYSTEM_ISP_DIGITAL_GAIN, &isp_v4l2_ctrl_system_isp_digital_gain, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_SYSTEM_MAX_ISP_DIGITAL_GAIN, &isp_v4l2_ctrl_system_max_isp_digital_gain, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_SYSTEM_AWB_RED_GAIN, &isp_v4l2_ctrl_system_awb_red_gain, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_SYSTEM_AWB_BLUE_GAIN, &isp_v4l2_ctrl_system_awb_blue_gain, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_ISP_MODULES_MANUAL_IRIDIX, &isp_v4l2_ctrl_isp_modules_manual_iridix, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_ISP_MODULES_MANUAL_SINTER, &isp_v4l2_ctrl_isp_modules_manual_sinter, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_ISP_MODULES_MANUAL_TEMPER, &isp_v4l2_ctrl_isp_modules_manual_temper, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_ISP_MODULES_MANUAL_AUTO_LEVEL, &isp_v4l2_ctrl_isp_modules_manual_auto_level, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_ISP_MODULES_MANUAL_FRAME_STITCH, &isp_v4l2_ctrl_isp_modules_manual_frame_stitch, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_ISP_MODULES_MANUAL_RAW_FRONTEND, &isp_v4l2_ctrl_isp_modules_manual_raw_frontend, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_ISP_MODULES_MANUAL_BLACK_LEVEL, &isp_v4l2_ctrl_isp_modules_manual_black_level, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_ISP_MODULES_MANUAL_SHADING, &isp_v4l2_ctrl_isp_modules_manual_shading, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_ISP_MODULES_MANUAL_DEMOSAIC, &isp_v4l2_ctrl_isp_modules_manual_demosaic, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_ISP_MODULES_MANUAL_CNR, &isp_v4l2_ctrl_isp_modules_manual_cnr, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_ISP_MODULES_MANUAL_SHARPEN, &isp_v4l2_ctrl_isp_modules_manual_sharpen, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_IMAGE_RESIZE_ENABLE_ID, &isp_v4l2_ctrl_image_resize_enable, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_IMAGE_RESIZE_TYPE_ID, &isp_v4l2_ctrl_image_resize_type, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_IMAGE_CROP_XOFFSET_ID, &isp_v4l2_ctrl_image_crop_xoffset, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_IMAGE_CROP_YOFFSET_ID, &isp_v4l2_ctrl_image_crop_yoffset, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_IMAGE_RESIZE_WIDTH_ID, &isp_v4l2_ctrl_image_resize_width, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_IMAGE_RESIZE_HEIGHT_ID, &isp_v4l2_ctrl_image_resize_height, NULL );


    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_STATUS_INFO_EXPOSURE_LOG2, &isp_v4l2_ctrl_status_info_exposure_log2, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_STATUS_INFO_GAIN_LOG2, &isp_v4l2_ctrl_status_info_gain_log2, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_STATUS_INFO_GAIN_ONES, &isp_v4l2_ctrl_status_info_gain_ones, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_STATUS_INFO_AWB_MIX_LIGHT_CONTRAST, &isp_v4l2_ctrl_status_info_awb_mix_light_contrast, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_STATUS_INFO_AF_LENS_POS, &isp_v4l2_ctrl_status_info_af_lens_pos, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_STATUS_INFO_AF_FOCUS_VALUE, &isp_v4l2_ctrl_status_info_af_focus_value, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_INFO_FW_REVISION, &isp_v4l2_ctrl_info_fw_revision, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_SENSOR_LINES_PER_SECOND, &isp_v4l2_ctrl_sensor_lines_per_second, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_AE_COMPENSATION, &isp_v4l2_ctrl_ae_compensation, NULL );
    ADD_CTRL_CST_VOLATILE( ISP_V4L2_CID_SYSTEM_DYNAMIC_GAMMA_ENABLE, &isp_v4l2_ctrl_system_dynamic_gamma_enable, NULL );

    /* Add control handler to v4l2 device */
    v4l2_ctrl_add_handler( hdl_std_ctrl, hdl_cst_ctrl, NULL );
    ctrl->video_dev->ctrl_handler = hdl_std_ctrl;

    v4l2_ctrl_handler_setup( hdl_std_ctrl );
    v4l2_ctrl_handler_setup( hdl_cst_ctrl );

    return 0;
}

void isp_v4l2_ctrl_deinit( isp_v4l2_ctrl_t *ctrl )
{
    v4l2_ctrl_handler_free( &ctrl->ctrl_hdl_std_ctrl );
    v4l2_ctrl_handler_free( &ctrl->ctrl_hdl_cst_ctrl );
}
