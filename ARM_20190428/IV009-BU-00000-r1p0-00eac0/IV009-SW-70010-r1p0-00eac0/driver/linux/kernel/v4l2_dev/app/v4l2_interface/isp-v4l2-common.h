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

#ifndef _ISP_V4L2_COMMON_H_
#define _ISP_V4L2_COMMON_H_

#include "acamera_firmware_config.h"

/* Sensor data types */
#define MAX_SENSOR_PRESET_SIZE 10
#define MAX_SENSOR_FPS_SIZE 10
typedef struct _isp_v4l2_sensor_preset {
    uint32_t width;
    uint32_t height;
    uint32_t fps[MAX_SENSOR_FPS_SIZE];
    uint32_t idx[MAX_SENSOR_FPS_SIZE];
    uint8_t fps_num;
    uint8_t fps_cur;
    uint8_t exposures[MAX_SENSOR_FPS_SIZE];
} isp_v4l2_sensor_preset;

typedef struct _isp_v4l2_sensor_info {
    /* resolution preset */
    isp_v4l2_sensor_preset preset[MAX_SENSOR_PRESET_SIZE];
    uint8_t preset_num;
    uint8_t preset_cur;
} isp_v4l2_sensor_info;

#define V4L2_CAN_UPDATE_SENSOR 0
#define V4L2_RESTORE_FR_BASE0 1

/* custom v4l2 formats */
#define ISP_V4L2_PIX_FMT_META v4l2_fourcc( 'M', 'E', 'T', 'A' )        /* META */
#define ISP_V4L2_PIX_FMT_ARGB2101010 v4l2_fourcc( 'B', 'A', '3', '0' ) /* ARGB2101010 */
#define ISP_V4L2_PIX_FMT_NULL v4l2_fourcc( 'N', 'U', 'L', 'L' )        /* format NULL to disable */

/* custom v4l2 events */
#define V4L2_EVENT_ACAMERA_CLASS ( V4L2_EVENT_PRIVATE_START + 0xA * 1000 )
#define V4L2_EVENT_ACAMERA_FRAME_READY ( V4L2_EVENT_ACAMERA_CLASS + 0x1 )
#define V4L2_EVENT_ACAMERA_STREAM_OFF ( V4L2_EVENT_ACAMERA_CLASS + 0x2 )

/* custom v4l2 controls */
#define ISP_V4L2_CID_ISP_V4L2_CLASS ( 0x00f00000 | 1 )
#define ISP_V4L2_CID_BASE ( 0x00f00000 | 0xf000 )
#define ISP_V4L2_CID_TEST_PATTERN ( ISP_V4L2_CID_BASE + 0 )
#define ISP_V4L2_CID_TEST_PATTERN_TYPE ( ISP_V4L2_CID_BASE + 1 )
#define ISP_V4L2_CID_AF_REFOCUS ( ISP_V4L2_CID_BASE + 2 )
#define ISP_V4L2_CID_SENSOR_PRESET ( ISP_V4L2_CID_BASE + 3 )
#define ISP_V4L2_CID_AF_ROI ( ISP_V4L2_CID_BASE + 4 )
#define ISP_V4L2_CID_OUTPUT_FR_ON_OFF ( ISP_V4L2_CID_BASE + 5 )
#define ISP_V4L2_CID_OUTPUT_DS1_ON_OFF ( ISP_V4L2_CID_BASE + 6 )
#define ISP_V4L2_CID_TEMPER3_MODE ( ISP_V4L2_CID_BASE + 7 )
#define ISP_V4L2_CID_SYSTEM_FREEZE_FIRMWARE ( ISP_V4L2_CID_BASE + 8 )
#define ISP_V4L2_CID_SYSTEM_MANUAL_EXPOSURE ( ISP_V4L2_CID_BASE + 9 )
#define ISP_V4L2_CID_SYSTEM_MANUAL_INTEGRATION_TIME ( ISP_V4L2_CID_BASE + 10 )
#define ISP_V4L2_CID_SYSTEM_MANUAL_MAX_INTEGRATION_TIME ( ISP_V4L2_CID_BASE + 11 )
#define ISP_V4L2_CID_SYSTEM_MANUAL_SENSOR_ANALOG_GAIN ( ISP_V4L2_CID_BASE + 12 )
#define ISP_V4L2_CID_SYSTEM_MANUAL_SENSOR_DIGITAL_GAIN ( ISP_V4L2_CID_BASE + 13 )
#define ISP_V4L2_CID_SYSTEM_MANUAL_ISP_DIGITAL_GAIN ( ISP_V4L2_CID_BASE + 14 )
#define ISP_V4L2_CID_SYSTEM_MANUAL_EXPOSURE_RATIO ( ISP_V4L2_CID_BASE + 15 )
#define ISP_V4L2_CID_SYSTEM_MANUAL_AWB ( ISP_V4L2_CID_BASE + 16 )
#define ISP_V4L2_CID_SYSTEM_MANUAL_SATURATION ( ISP_V4L2_CID_BASE + 17 )
#define ISP_V4L2_CID_SYSTEM_MAX_EXPOSURE_RATIO ( ISP_V4L2_CID_BASE + 18 )
#define ISP_V4L2_CID_SYSTEM_EXPOSURE ( ISP_V4L2_CID_BASE + 19 )
#define ISP_V4L2_CID_SYSTEM_INTEGRATION_TIME ( ISP_V4L2_CID_BASE + 20 )
#define ISP_V4L2_CID_SYSTEM_EXPOSURE_RATIO ( ISP_V4L2_CID_BASE + 21 )
#define ISP_V4L2_CID_SYSTEM_MAX_INTEGRATION_TIME ( ISP_V4L2_CID_BASE + 22 )
#define ISP_V4L2_CID_SYSTEM_SENSOR_ANALOG_GAIN ( ISP_V4L2_CID_BASE + 23 )
#define ISP_V4L2_CID_SYSTEM_MAX_SENSOR_ANALOG_GAIN ( ISP_V4L2_CID_BASE + 24 )
#define ISP_V4L2_CID_SYSTEM_SENSOR_DIGITAL_GAIN ( ISP_V4L2_CID_BASE + 25 )
#define ISP_V4L2_CID_SYSTEM_MAX_SENSOR_DIGITAL_GAIN ( ISP_V4L2_CID_BASE + 26 )
#define ISP_V4L2_CID_SYSTEM_ISP_DIGITAL_GAIN ( ISP_V4L2_CID_BASE + 27 )
#define ISP_V4L2_CID_SYSTEM_MAX_ISP_DIGITAL_GAIN ( ISP_V4L2_CID_BASE + 28 )
#define ISP_V4L2_CID_SYSTEM_AWB_RED_GAIN ( ISP_V4L2_CID_BASE + 29 )
#define ISP_V4L2_CID_SYSTEM_AWB_BLUE_GAIN ( ISP_V4L2_CID_BASE + 30 )

// ISP_MODULES
#define ISP_V4L2_CID_ISP_MODULES_MANUAL_IRIDIX ( ISP_V4L2_CID_BASE + 31 )
#define ISP_V4L2_CID_ISP_MODULES_MANUAL_SINTER ( ISP_V4L2_CID_BASE + 32 )
#define ISP_V4L2_CID_ISP_MODULES_MANUAL_TEMPER ( ISP_V4L2_CID_BASE + 33 )
#define ISP_V4L2_CID_ISP_MODULES_MANUAL_AUTO_LEVEL ( ISP_V4L2_CID_BASE + 34 )
#define ISP_V4L2_CID_ISP_MODULES_MANUAL_FRAME_STITCH ( ISP_V4L2_CID_BASE + 35 )
#define ISP_V4L2_CID_ISP_MODULES_MANUAL_RAW_FRONTEND ( ISP_V4L2_CID_BASE + 36 )
#define ISP_V4L2_CID_ISP_MODULES_MANUAL_BLACK_LEVEL ( ISP_V4L2_CID_BASE + 37 )
#define ISP_V4L2_CID_ISP_MODULES_MANUAL_SHADING ( ISP_V4L2_CID_BASE + 38 )
#define ISP_V4L2_CID_ISP_MODULES_MANUAL_DEMOSAIC ( ISP_V4L2_CID_BASE + 39 )
#define ISP_V4L2_CID_ISP_MODULES_MANUAL_CNR ( ISP_V4L2_CID_BASE + 40 )
#define ISP_V4L2_CID_ISP_MODULES_MANUAL_SHARPEN ( ISP_V4L2_CID_BASE + 41 )

// TIMAGE
#define ISP_V4L2_CID_IMAGE_RESIZE_ENABLE_ID ( ISP_V4L2_CID_BASE + 42 )
#define ISP_V4L2_CID_IMAGE_RESIZE_TYPE_ID ( ISP_V4L2_CID_BASE + 43 )
#define ISP_V4L2_CID_IMAGE_CROP_XOFFSET_ID ( ISP_V4L2_CID_BASE + 44 )
#define ISP_V4L2_CID_IMAGE_CROP_YOFFSET_ID ( ISP_V4L2_CID_BASE + 45 )
#define ISP_V4L2_CID_IMAGE_RESIZE_WIDTH_ID ( ISP_V4L2_CID_BASE + 46 )
#define ISP_V4L2_CID_IMAGE_RESIZE_HEIGHT_ID ( ISP_V4L2_CID_BASE + 47 )

#define ISP_V4L2_CID_STATUS_INFO_EXPOSURE_LOG2 ( ISP_V4L2_CID_BASE + 48 )
#define ISP_V4L2_CID_STATUS_INFO_GAIN_LOG2 ( ISP_V4L2_CID_BASE + 49 )
#define ISP_V4L2_CID_STATUS_INFO_GAIN_ONES ( ISP_V4L2_CID_BASE + 50 )
#define ISP_V4L2_CID_STATUS_INFO_AWB_MIX_LIGHT_CONTRAST ( ISP_V4L2_CID_BASE + 51 )
#define ISP_V4L2_CID_STATUS_INFO_AF_LENS_POS ( ISP_V4L2_CID_BASE + 52 )
#define ISP_V4L2_CID_STATUS_INFO_AF_FOCUS_VALUE ( ISP_V4L2_CID_BASE + 53 )
#define ISP_V4L2_CID_INFO_FW_REVISION ( ISP_V4L2_CID_BASE + 54 )

#define ISP_V4L2_CID_SENSOR_LINES_PER_SECOND ( ISP_V4L2_CID_BASE + 55 )
#define ISP_V4L2_CID_AE_COMPENSATION ( ISP_V4L2_CID_BASE + 56 )
#define ISP_V4L2_CID_SYSTEM_DYNAMIC_GAMMA_ENABLE ( ISP_V4L2_CID_BASE + 57 )

/* type of stream */
typedef enum {
    V4L2_RESIZE_TYPE_CROP_FR = 0,
    V4L2_RESIZE_TYPE_CROP_DS1 = 1,
    V4L2_RESIZE_TYPE_SCALER_DS1 = 2,
} isp_v4l2_resize_type_t;

/* type of stream */
typedef enum {
    V4L2_STREAM_TYPE_FR = 0,
#if ISP_HAS_META_CB
    V4L2_STREAM_TYPE_META,
#endif
#if ISP_HAS_DS1
    V4L2_STREAM_TYPE_DS1,
#endif
#if ISP_HAS_RAW_CB
    V4L2_STREAM_TYPE_RAW,
#endif
    V4L2_STREAM_TYPE_MAX
} isp_v4l2_stream_type_t;

#endif