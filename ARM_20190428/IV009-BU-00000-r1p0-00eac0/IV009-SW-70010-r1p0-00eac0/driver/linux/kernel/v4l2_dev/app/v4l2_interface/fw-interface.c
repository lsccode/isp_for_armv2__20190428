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

#include <linux/device.h>
#include <linux/slab.h>
#include <linux/random.h>
#include <asm/div64.h>
#include <linux/sched.h>
#include <linux/videodev2.h>
#include <media/videobuf2-core.h>
#include <media/videobuf2-vmalloc.h>

#include "acamera_command_api.h"
#include "acamera_firmware_settings.h"
#include "acamera_logger.h"
#include "isp-v4l2-common.h"
#include "fw-interface.h"

//use main_firmware.c routines to initialize fw
extern int isp_fw_init( uint32_t hw_isp_addr );
extern void isp_fw_exit( void );

static int isp_started = 0;


/* ----------------------------------------------------------------
 * fw_interface control interface
 */

/* fw-interface isp control interface */
int fw_intf_isp_init( uint32_t hw_isp_addr )
{

    LOG( LOG_INFO, "Initializing fw ..." );
    int rc = 0;
    /* flag variable update */

    rc = isp_fw_init( hw_isp_addr );

    if ( rc == 0 )
        isp_started = 1;

    return rc;
}

int fw_intf_is_isp_started( void )
{
    return isp_started;
}

void fw_intf_isp_deinit( void )
{
    LOG( LOG_INFO, "Deinitializing fw interface ..." );

    /* flag variable update */
    isp_started = 0;

    isp_fw_exit();
}

uint32_t fw_calibration_update( uint32_t ctx_id )
{
    uint32_t retval = 0;
    acamera_command( ctx_id, TSYSTEM, CALIBRATION_UPDATE, UPDATE, COMMAND_SET, &retval );
    return retval;
}

int fw_intf_isp_start( void )
{
    LOG( LOG_DEBUG, "Starting context" );


    return 0;
}

void fw_intf_isp_stop( void )
{
    LOG( LOG_DEBUG, "Enter" );
}

int fw_intf_isp_get_current_ctx_id( uint32_t ctx_id )
{
    int active_ctx_id = -1;

    if ( !isp_started ) {
        LOG( LOG_ERR, "ISP FW not inited yet" );
        return -EBUSY;
    }

#if defined( TGENERAL ) && defined( ACTIVE_CONTEXT )
    acamera_command( ctx_id, TGENERAL, ACTIVE_CONTEXT, 0, COMMAND_GET, &active_ctx_id );
#endif

    return active_ctx_id;
}

int fw_intf_isp_get_sensor_info( uint32_t ctx_id, isp_v4l2_sensor_info *sensor_info )
{
    if ( !isp_started ) {
        LOG( LOG_ERR, "ISP FW not inited yet" );
        return -EBUSY;
    }

#if defined( TSENSOR ) && defined( SENSOR_SUPPORTED_PRESETS ) && defined( SENSOR_INFO_PRESET ) && \
    defined( SENSOR_INFO_FPS ) && defined( SENSOR_INFO_WIDTH ) && defined( SENSOR_INFO_HEIGHT )
    LOG( LOG_INFO, "API found, initializing sensor_info from API." );
    int i, j;
    uint32_t ret_val = 0;
    uint32_t preset_num = 0;

    /* reset buffer */
    memset( sensor_info, 0x0, sizeof( isp_v4l2_sensor_info ) );

    /* get preset size */
    acamera_command( ctx_id, TSENSOR, SENSOR_SUPPORTED_PRESETS, 0, COMMAND_GET, &preset_num );
    if ( preset_num > MAX_SENSOR_PRESET_SIZE ) {
        LOG( LOG_ERR, "MAX_SENSOR_PRESET_SIZE is too small ! (preset_num = %d)", preset_num );
        preset_num = MAX_SENSOR_PRESET_SIZE;
    }

    /* fill preset values */
    for ( i = 0; i < preset_num; i++ ) {
        uint32_t width = 0, height = 0, fps = 0, exposures = 1;

        /* get next preset */
        acamera_command( ctx_id, TSENSOR, SENSOR_INFO_PRESET, i, COMMAND_SET, &ret_val );
        acamera_command( ctx_id, TSENSOR, SENSOR_INFO_FPS, i, COMMAND_GET, &fps );
        acamera_command( ctx_id, TSENSOR, SENSOR_INFO_WIDTH, i, COMMAND_GET, &width );
        acamera_command( ctx_id, TSENSOR, SENSOR_INFO_HEIGHT, i, COMMAND_GET, &height );
#if defined( SENSOR_INFO_EXPOSURES )
        acamera_command( ctx_id, TSENSOR, SENSOR_INFO_EXPOSURES, i, COMMAND_GET, &exposures );
#endif

        /* find proper index from sensor_info */
        for ( j = 0; j < sensor_info->preset_num; j++ ) {
            if ( sensor_info->preset[j].width == width &&
                 sensor_info->preset[j].height == height )
                break;
        }

        /* store preset */
        if ( sensor_info->preset[j].fps_num < MAX_SENSOR_FPS_SIZE ) {
            sensor_info->preset[j].width = width;
            sensor_info->preset[j].height = height;
            sensor_info->preset[j].exposures[sensor_info->preset[j].fps_num] = exposures;
            sensor_info->preset[j].fps[sensor_info->preset[j].fps_num] = fps;
            sensor_info->preset[j].idx[sensor_info->preset[j].fps_num] = i;
            sensor_info->preset[j].fps_num++;
            if ( sensor_info->preset_num <= j )
                sensor_info->preset_num++;
        } else {
            LOG( LOG_ERR, "FPS number overflowed ! (preset#%d / index#%d)", i, j );
        }
    }
    uint32_t spreset = 0, swidth = 0, sheight = 0;
    acamera_command( ctx_id, TSENSOR, SENSOR_PRESET, 0, COMMAND_GET, &spreset );
    acamera_command( ctx_id, TSENSOR, SENSOR_WIDTH, 0, COMMAND_GET, &swidth );
    acamera_command( ctx_id, TSENSOR, SENSOR_HEIGHT, 0, COMMAND_GET, &sheight );

    for ( i = 0; i < sensor_info->preset_num; i++ ) {
        if ( swidth == sensor_info->preset[i].width && sheight == sensor_info->preset[i].height ) {
            sensor_info->preset_cur = i;
            break;
        }
    }

    if ( i < MAX_SENSOR_PRESET_SIZE ) {
        for ( j = 0; j < sensor_info->preset[i].fps_num; j++ ) {
            if ( sensor_info->preset[i].idx[j] == spreset ) {
                sensor_info->preset[i].fps_cur = spreset;
                break;
            }
        }
    }

    LOG( LOG_INFO, "Sensor info current preset:%d v4l2 preset:%d", sensor_info->preset[i].fps_cur, sensor_info->preset_cur );

    //check current sensor settings

    LOG( LOG_INFO, "/* dump sensor info -----------------" );
    for ( i = 0; i < sensor_info->preset_num; i++ ) {
        LOG( LOG_INFO, "   Idx#%02d - W:%04d H:%04d",
             i, sensor_info->preset[i].width, sensor_info->preset[i].height );
        for ( j = 0; j < sensor_info->preset[i].fps_num; j++ )
            LOG( LOG_INFO, "            FPS#%d: %d (preset index = %d) exposures:%d",
                 j, sensor_info->preset[i].fps[j] / 256, sensor_info->preset[i].idx[j], sensor_info->preset[i].exposures[j] );
    }

    LOG( LOG_INFO, "-----------------------------------*/" );

#else
    /* returning default setting (1080p) */
    LOG( LOG_ERR, "API not found, initializing sensor_info to default." );
    sensor_info->preset_num = 1;
    sensor_info->preset[0].fps = 30 * 256;
    sensor_info->preset[0].width = 1920;
    sensor_info->preset[0].height = 1080;
#endif

    return 0;
}

int fw_intf_isp_get_sensor_preset( uint32_t ctx_id )
{
    int value = -1;

    if ( !isp_started ) {
        LOG( LOG_ERR, "ISP FW not inited yet" );
        return -EBUSY;
    }

#if defined( TSENSOR ) && defined( SENSOR_PRESET )
    acamera_command( ctx_id, TSENSOR, SENSOR_PRESET, 0, COMMAND_GET, &value );
#endif

    return value;
}

int fw_intf_isp_set_sensor_preset( uint32_t ctx_id, uint32_t preset )
{
    int value = -1;

    if ( !isp_started ) {
        LOG( LOG_ERR, "ISP FW not inited yet" );
        return -EBUSY;
    }

#if defined( TSENSOR ) && defined( SENSOR_PRESET )
    LOG( LOG_INFO, "V4L2 setting sensor preset to %d\n", preset );
    acamera_command( ctx_id, TSENSOR, SENSOR_PRESET, preset, COMMAND_SET, &value );
#endif

    return value;
}

/*
 * fw-interface per-stream control interface
 */
int fw_intf_stream_start( uint32_t ctx_id, isp_v4l2_stream_type_t streamType )
{
    LOG( LOG_DEBUG, "Starting stream type %d", streamType );

    /*
     * There is no need to explicitly start any stream in FW
     * as the dma writers are polling for V4l2 buffers
     * so when the the stream is on it will get buffers.
     */

    return 0;
}

void fw_intf_stream_stop( uint32_t ctx_id, isp_v4l2_stream_type_t streamType )
{
    LOG( LOG_DEBUG, "Stopping stream type %d", streamType );
}

/* fw-interface sensor hw stream control interface */
int fw_intf_sensor_pause( uint32_t ctx_id )
{
    uint32_t rc = 0;

    if ( !isp_started ) {
        LOG( LOG_ERR, "ISP FW not inited yet" );
        return -EBUSY;
    }

    acamera_command( ctx_id, TSENSOR, SENSOR_STREAMING, OFF, COMMAND_SET, &rc );

    return rc;
}

int fw_intf_sensor_resume( uint32_t ctx_id )
{
    uint32_t rc = 0;

    if ( !isp_started ) {
        LOG( LOG_ERR, "ISP FW not inited yet" );
        return -EBUSY;
    }

    acamera_command( ctx_id, TSENSOR, SENSOR_STREAMING, ON, COMMAND_SET, &rc );

    return rc;
}


/* fw-interface per-stream config interface */
int fw_intf_stream_set_resolution( uint32_t ctx_id, const isp_v4l2_sensor_info *sensor_info,
                                   isp_v4l2_stream_type_t streamType, uint32_t *width, uint32_t *height )
{
    /*
     * StreamType
     *   - FR : directly update sensor resolution since FR doesn't have down-scaler.
     *   - DS : need to be implemented.
     *   - RAW: can't be configured separately from FR.
     */
    if ( !isp_started ) {
        LOG( LOG_ERR, "ISP FW not inited yet" );
        return -EBUSY;
    }

    LOG( LOG_DEBUG, "streamtype:%d, w:%d h:%d\n", streamType, *width, *height );
    if ( streamType == V4L2_STREAM_TYPE_FR ) {
#if defined( TSENSOR ) && defined( SENSOR_PRESET )
        int result;
        uint32_t ret_val = 0;
        uint32_t idx = 0x0;
        uint32_t fps = 0x0;
        uint32_t w, h;
        uint32_t i, j;


        w = *width;
        h = *height;

        uint32_t width_cur = 0, height_cur = 0;
        //check if we need to change sensor preset
        acamera_command( ctx_id, TSENSOR, SENSOR_WIDTH, 0, COMMAND_GET, &width_cur );
        acamera_command( ctx_id, TSENSOR, SENSOR_HEIGHT, 0, COMMAND_GET, &height_cur );
        LOG( LOG_INFO, "target (width = %d, height = %d) current (w=%d h=%d)", w, h, width_cur, height_cur );
        if ( width_cur != w || height_cur != h ) {
            /* search resolution from preset table
             *   for now, use the highest fps.
             *   this should be changed properly in the future to pick fps from application
             */
            for ( i = 0; i < sensor_info->preset_num; i++ ) {
                if ( sensor_info->preset[i].width == w && sensor_info->preset[i].height == h ) {
                    *( (char *)&sensor_info->preset[i].fps_cur ) = 0;
                    for ( j = 0; j < sensor_info->preset[i].fps_num; j++ ) {
                        if ( sensor_info->preset[i].fps[j] > fps ) {
                            fps = sensor_info->preset[i].fps[j];
                            idx = sensor_info->preset[i].idx[j];
                            *( (char *)&sensor_info->preset[i].fps_cur ) = j;
                        }
                    }

                    break;
                }
            }
            if ( i >= sensor_info->preset_num ) {
                LOG( LOG_ERR, "invalid resolution (width = %d, height = %d) reverting to current %dx%d", w, h, width_cur, height_cur );
                *width = width_cur;
                *height = height_cur;
                return 0;
            }

            /* set sensor resolution preset */
            LOG( LOG_NOTICE, "Setting new resolution : width = %d, height = %d (preset idx = %d, fps = %d)", w, h, idx, fps / 256 );
            result = acamera_command( ctx_id, TSENSOR, SENSOR_PRESET, idx, COMMAND_SET, &ret_val );
            *( (char *)&sensor_info->preset_cur ) = idx;
            if ( result ) {
                LOG( LOG_ERR, "Failed to set preset to %u, ret_value: %d.", idx, result );
                return result;
            }
        } else {
            acamera_command( ctx_id, TSENSOR, SENSOR_PRESET, 0, COMMAND_GET, &idx );
            LOG( LOG_INFO, "Leaving same sensor settings resolution : width = %d, height = %d (preset idx = %d)", w, h, idx );
        }
#endif
    }
#if ISP_HAS_DS1
    else if ( streamType == V4L2_STREAM_TYPE_DS1 ) {

        int result;
        uint32_t ret_val;
        uint32_t w, h;

        w = *width;
        h = *height;

        uint32_t width_cur = 0, height_cur = 0;
        //check if we need to change sensor preset
        acamera_command( ctx_id, TSENSOR, SENSOR_WIDTH, 0, COMMAND_GET, &width_cur );
        acamera_command( ctx_id, TSENSOR, SENSOR_HEIGHT, 0, COMMAND_GET, &height_cur );
        LOG( LOG_INFO, "target (width = %d, height = %d) current (w=%d h=%d)", w, h, width_cur, height_cur );
        if ( w > width_cur || h > height_cur ) {
            LOG( LOG_ERR, "Invalid target size: (width = %d, height = %d), current (w=%d h=%d)", w, h, width_cur, height_cur );
            return -EINVAL;
        }

#if defined( TIMAGE ) && defined( IMAGE_RESIZE_TYPE_ID ) && defined( IMAGE_RESIZE_WIDTH_ID )
        {
            result = acamera_command( ctx_id, TIMAGE, IMAGE_RESIZE_WIDTH_ID, w, COMMAND_SET, &ret_val );
            if ( result ) {
                LOG( LOG_ERR, "Failed to set resize_width, ret_value: %d.", result );
                return result;
            }
            acamera_command( ctx_id, TIMAGE, IMAGE_RESIZE_HEIGHT_ID, h, COMMAND_SET, &ret_val );
            if ( result ) {
                LOG( LOG_ERR, "Failed to set resize_height, ret_value: %d.", result );
                return result;
            }
            acamera_command( ctx_id, TIMAGE, IMAGE_RESIZE_TYPE_ID, SCALER, COMMAND_SET, &ret_val );
            if ( result ) {
                LOG( LOG_ERR, "Failed to set resize_type, ret_value: %d.", result );
                return result;
            }
            acamera_command( ctx_id, TIMAGE, IMAGE_RESIZE_ENABLE_ID, RUN, COMMAND_SET, &ret_val );
            if ( result ) {
                LOG( LOG_ERR, "Failed to set resize_enable, ret_value: %d.", result );
                return result;
            }
        }
#endif
    }
#endif

    return 0;
}

int fw_intf_stream_set_output_format( uint32_t ctx_id, isp_v4l2_stream_type_t streamType, uint32_t format )
{

#if defined( TIMAGE ) && defined( FR_FORMAT_BASE_PLANE_ID )
    uint32_t value;

    if ( !isp_started ) {
        LOG( LOG_ERR, "ISP FW not inited yet" );
        return -EBUSY;
    }

    switch ( format ) {
#ifdef DMA_FORMAT_RGB32
    case V4L2_PIX_FMT_RGB32:
        value = RGB32;
        break;
#endif
#if defined( DMA_FORMAT_NV12_Y )
    case V4L2_PIX_FMT_NV12:
        value = NV12_YUV;
        break;
#endif
#ifdef DMA_FORMAT_A2R10G10B10
    case ISP_V4L2_PIX_FMT_ARGB2101010:
        value = A2R10G10B10;
        break;
#endif
#ifdef DMA_FORMAT_RAW16
    case V4L2_PIX_FMT_SBGGR16:
        value = RAW16;
        break;
#endif
#ifdef DMA_FORMAT_DISABLE
    case ISP_V4L2_PIX_FMT_NULL:
        value = DMA_DISABLE;
        break;
#endif
    case ISP_V4L2_PIX_FMT_META:
        LOG( LOG_INFO, "Meta format 0x%x doesn't need to be set to firmware", format );
        return 0;
        break;
    default:
        LOG( LOG_ERR, "Requested format 0x%x is not supported by firmware !", format );
        return -1;
        break;
    }

    if ( streamType == V4L2_STREAM_TYPE_FR ) {

        uint8_t result;
        uint32_t ret_val = 0;

        result = acamera_command( ctx_id, TIMAGE, FR_FORMAT_BASE_PLANE_ID, value, COMMAND_SET, &ret_val );
        LOG( LOG_INFO, "set format for stream %d to %d (0x%x)", streamType, value, format );
        if ( result ) {
            LOG( LOG_ERR, "TIMAGE - FR_FORMAT_BASE_PLANE_ID failed (value = 0x%x, result = %d)", value, result );
        }
    }
#if ISP_HAS_DS1
    else if ( streamType == V4L2_STREAM_TYPE_DS1 ) {

        uint8_t result;
        uint32_t ret_val = 0;

        result = acamera_command( ctx_id, TIMAGE, DS1_FORMAT_BASE_PLANE_ID, value, COMMAND_SET, &ret_val );
        LOG( LOG_INFO, "set format for stream %d to %d (0x%x)", streamType, value, format );
        if ( result ) {
            LOG( LOG_ERR, "TIMAGE - DS1_FORMAT_BASE_PLANE_ID failed (value = 0x%x, result = %d)", value, result );
        }
    }
#endif

#else
    LOG( LOG_ERR, "cannot find proper API for fr base mode ID" );
#endif


    return 0;
}


/* ----------------------------------------------------------------
 * Internal handler for control interface functions
 */
static bool isp_fw_do_validate_control( uint32_t id )
{
    return 1;
}

static int isp_fw_do_set_test_pattern( uint32_t ctx_id, int enable )
{
#if defined( TSYSTEM ) && defined( TEST_PATTERN_ENABLE_ID )
    int result;
    uint32_t ret_val = 0;

    LOG( LOG_INFO, "test_pattern: %d.", enable );

    if ( enable < 0 )
        return -EIO;

    if ( !isp_started ) {
        LOG( LOG_NOTICE, "ISP FW not inited yet" );
        return -EBUSY;
    }

    result = acamera_command( ctx_id, TSYSTEM, TEST_PATTERN_ENABLE_ID, enable ? ON : OFF, COMMAND_SET, &ret_val );
    if ( result ) {
        LOG( LOG_ERR, "Failed to set TEST_PATTERN_ENABLE_ID to %u, ret_value: %d.", enable, result );
        return result;
    }
#endif

    return 0;
}

static int isp_fw_do_set_test_pattern_type( uint32_t ctx_id, int pattern_type )
{
#if defined( TSYSTEM ) && defined( TEST_PATTERN_MODE_ID )
    int result;
    uint32_t ret_val = 0;

    LOG( LOG_INFO, "test_pattern_type: %d.", pattern_type );

    if ( !isp_started ) {
        LOG( LOG_ERR, "ISP FW not inited yet" );
        return -EBUSY;
    }

    result = acamera_command( ctx_id, TSYSTEM, TEST_PATTERN_MODE_ID, pattern_type, COMMAND_SET, &ret_val );
    if ( result ) {
        LOG( LOG_ERR, "Failed to set TEST_PATTERN_MODE_ID to %d, ret_value: %d.", pattern_type, result );
        return result;
    }
#endif

    return 0;
}


static int isp_fw_do_set_af_refocus( uint32_t ctx_id, int val )
{
#if defined( TALGORITHMS ) && defined( AF_MODE_ID )
    int result;
    u32 ret_val = 0;

    result = acamera_command( ctx_id, TALGORITHMS, AF_MODE_ID, AF_AUTO_SINGLE, COMMAND_SET, &ret_val );
    if ( result ) {
        LOG( LOG_ERR, "Failed to set AF_MODE_ID to AF_AUTO_SINGLE, ret_value: %u.", ret_val );
        return result;
    }
#endif

    return 0;
}

static int isp_fw_do_set_af_roi( uint32_t ctx_id, int val )
{
#if defined( TALGORITHMS ) && defined( AF_ROI_ID )
    int result;
    u32 ret_val = 0;
    // map [0,127] to [0, 254] due to limitaton of V4L2_CTRL_TYPE_INTEGER.
    uint32_t roi = val << 1;

    result = acamera_command( ctx_id, TALGORITHMS, AF_ROI_ID, roi, COMMAND_SET, &ret_val );
    if ( result ) {
        LOG( LOG_ERR, "Failed to set AF_MODE_ID to AF_AUTO_SINGLE, ret_value: %u.", ret_val );
        return result;
    }
#endif

    return 0;
}

static int isp_fw_do_set_brightness( uint32_t ctx_id, int brightness )
{
#if defined( TSCENE_MODES ) && defined( BRIGHTNESS_STRENGTH_ID )
    int result;
    uint32_t ret_val = 0;

    LOG( LOG_INFO, "brightness: %d.", brightness );

    /* some controls(such brightness) will call acamera_command()
     * before isp_fw initialed, so we need to check.
     */
    if ( !isp_started ) {
        LOG( LOG_ERR, "ISP FW not inited yet" );
        return -EBUSY;
    }

    result = acamera_command( ctx_id, TSCENE_MODES, BRIGHTNESS_STRENGTH_ID, brightness, COMMAND_SET, &ret_val );
    if ( result ) {
        LOG( LOG_ERR, "Failed to set BRIGHTNESS_STRENGTH_ID to %d, ret_value: %d.", brightness, result );
        return result;
    }
#endif

    return 0;
}

static int isp_fw_do_set_contrast( uint32_t ctx_id, int contrast )
{
#if defined( TSCENE_MODES ) && defined( CONTRAST_STRENGTH_ID )
    int result;
    uint32_t ret_val = 0;

    LOG( LOG_INFO, "contrast: %d.", contrast );

    /* some controls(such brightness) will call acamera_command()
     * before isp_fw initialed, so we need to check.
     */
    if ( !isp_started ) {
        LOG( LOG_ERR, "ISP FW not inited yet" );
        return -EBUSY;
    }

    result = acamera_command( ctx_id, TSCENE_MODES, CONTRAST_STRENGTH_ID, contrast, COMMAND_SET, &ret_val );
    if ( result ) {
        LOG( LOG_ERR, "Failed to set CONTRAST_STRENGTH_ID to %d, ret_value: %d.", contrast, result );
        return result;
    }
#endif

    return 0;
}

static int isp_fw_do_set_saturation( uint32_t ctx_id, int saturation )
{
#if defined( TSCENE_MODES ) && defined( SATURATION_STRENGTH_ID )
    int result;
    uint32_t ret_val = 0;

    LOG( LOG_INFO, "saturation: %d.", saturation );

    /* some controls(such brightness) will call acamera_command()
     * before isp_fw initialed, so we need to check.
     */
    if ( !isp_started ) {
        LOG( LOG_ERR, "ISP FW not inited yet" );
        return -EBUSY;
    }

    result = acamera_command( ctx_id, TSCENE_MODES, SATURATION_STRENGTH_ID, saturation, COMMAND_SET, &ret_val );
    if ( result ) {
        LOG( LOG_ERR, "Failed to set SATURATION_STRENGTH_ID to %d, ret_value: %d.", saturation, result );
        return result;
    }
#endif

    return 0;
}

static int isp_fw_do_set_hue( uint32_t ctx_id, int hue )
{
#if defined( TSCENE_MODES ) && defined( HUE_THETA_ID )
    int result;
    uint32_t ret_val = 0;

    LOG( LOG_INFO, "hue: %d.", hue );

    /* some controls(such brightness) will call acamera_command()
     * before isp_fw initialed, so we need to check.
     */
    if ( !isp_started ) {
        LOG( LOG_ERR, "ISP FW not inited yet" );
        return -EBUSY;
    }

    result = acamera_command( ctx_id, TSCENE_MODES, HUE_THETA_ID, hue, COMMAND_SET, &ret_val );
    if ( result ) {
        LOG( LOG_ERR, "Failed to set HUE_THETA_ID to %d, ret_value: %d.", hue, result );
        return result;
    }
#endif

    return 0;
}

static int isp_fw_do_set_sharpness( uint32_t ctx_id, int sharpness )
{
#if defined( TSCENE_MODES ) && defined( SHARPENING_STRENGTH_ID )
    int result;
    uint32_t ret_val = 0;

    LOG( LOG_INFO, "sharpness: %d.", sharpness );

    /* some controls(such brightness) will call acamera_command()
     * before isp_fw initialed, so we need to check.
     */
    if ( !isp_started ) {
        LOG( LOG_ERR, "ISP FW not inited yet" );
        return -EBUSY;
    }

    result = acamera_command( ctx_id, TSCENE_MODES, SHARPENING_STRENGTH_ID, sharpness, COMMAND_SET, &ret_val );
    if ( result ) {
        LOG( LOG_ERR, "Failed to set SHARPENING_STRENGTH_ID to %d, ret_value: %d.", sharpness, result );
        return result;
    }
#endif

    return 0;
}

static int isp_fw_do_set_color_fx( uint32_t ctx_id, int idx )
{
#if defined( TSCENE_MODES ) && defined( COLOR_MODE_ID )
    int result;
    uint32_t ret_val = 0;
    int color_idx;

    LOG( LOG_INFO, "idx: %d.", idx );

    switch ( idx ) {
    case V4L2_COLORFX_NONE:
        color_idx = NORMAL;
        break;
    case V4L2_COLORFX_BW:
        color_idx = BLACK_AND_WHITE;
        break;
    case V4L2_COLORFX_SEPIA:
        color_idx = SEPIA;
        break;
    case V4L2_COLORFX_NEGATIVE:
        color_idx = NEGATIVE;
        break;
    case V4L2_COLORFX_VIVID:
        color_idx = VIVID;
        break;
    default:
        return -EINVAL;
        break;
    }

    /* some controls(such brightness) will call acamera_command()
     * before isp_fw initialed, so we need to check.
     */
    if ( !isp_started ) {
        LOG( LOG_ERR, "ISP FW not inited yet" );
        return -EBUSY;
    }

    result = acamera_command( ctx_id, TSCENE_MODES, COLOR_MODE_ID, color_idx, COMMAND_SET, &ret_val );
    if ( result ) {
        LOG( LOG_ERR, "Failed to set COLOR_MODE_ID to %d, ret_value: %d.", color_idx, result );
        return result;
    }
#endif

    return 0;
}

static int isp_fw_do_set_hflip( uint32_t ctx_id, bool enable )
{
#if defined( TIMAGE ) && defined( ORIENTATION_HFLIP_ID )
    int result;
    uint32_t ret_val = 0;

    LOG( LOG_INFO, "hflip enable: %d.", enable );

    /* some controls(such brightness) will call acamera_command()
     * before isp_fw initialed, so we need to check.
     */
    if ( !isp_started ) {
        LOG( LOG_ERR, "ISP FW not inited yet" );
        return -EBUSY;
    }

    result = acamera_command( ctx_id, TIMAGE, ORIENTATION_HFLIP_ID, enable ? ENABLE : DISABLE, COMMAND_SET, &ret_val );
    if ( result ) {
        LOG( LOG_ERR, "Failed to set ORIENTATION_HFLIP_ID to %d, ret_value: %d.", enable, result );
        return result;
    }
#endif

    return 0;
}

static int isp_fw_do_set_vflip( uint32_t ctx_id, bool enable )
{
#if defined( TIMAGE ) && defined( ORIENTATION_VFLIP_ID )
    int result;
    uint32_t ret_val = 0;

    LOG( LOG_INFO, "vflip enable: %d.", enable );

    /* some controls(such brightness) will call acamera_command()
     * before isp_fw initialed, so we need to check.
     */
    if ( !isp_started ) {
        LOG( LOG_ERR, "ISP FW not inited yet" );
        return -EBUSY;
    }

    result = acamera_command( ctx_id, TIMAGE, ORIENTATION_VFLIP_ID, enable ? ENABLE : DISABLE, COMMAND_SET, &ret_val );
    if ( result ) {
        LOG( LOG_ERR, "Failed to set ORIENTATION_VFLIP_ID to %d, ret_value: %d.", enable, result );
        return result;
    }
#endif

    return 0;
}

static int isp_fw_do_set_manual_gain( uint32_t ctx_id, bool enable )
{
#if defined( TALGORITHMS ) && defined( AE_MODE_ID )
    int result;
    uint32_t mode = 0;
    uint32_t ret_val = 0;

    LOG( LOG_INFO, "manual_gain enable: %d.", enable );

    /* some controls(such brightness) will call acamera_command()
     * before isp_fw initialed, so we need to check.
     */
    if ( !isp_started ) {
        LOG( LOG_ERR, "ISP FW not inited yet" );
        return -EBUSY;
    }

    result = acamera_command( ctx_id, TALGORITHMS, AE_MODE_ID, 0, COMMAND_GET, &ret_val );
    LOG( LOG_INFO, "AE_MODE_ID = %d", ret_val );
    if ( enable ) {
        if ( ret_val == AE_AUTO ) {
            mode = AE_MANUAL_GAIN;
        } else if ( ret_val == AE_MANUAL_EXPOSURE_TIME ) {
            mode = AE_FULL_MANUAL;
        } else {
            LOG( LOG_INFO, "Manual gain is already enabled." );
            return 0;
        }
    } else {
        if ( ret_val == AE_MANUAL_GAIN ) {
            mode = AE_AUTO;
        } else if ( ret_val == AE_FULL_MANUAL ) {
            mode = AE_MANUAL_EXPOSURE_TIME;
        } else {
            LOG( LOG_INFO, "Manual gain is already disabled." );
            return 0;
        }
    }

    result = acamera_command( ctx_id, TALGORITHMS, AE_MODE_ID, mode, COMMAND_SET, &ret_val );
    if ( result ) {
        LOG( LOG_ERR, "Failed to set AE_MODE_ID to %u, ret_value: %d.", mode, result );
        return result;
    }
#endif

    return 0;
}

static int isp_fw_do_set_gain( uint32_t ctx_id, int gain )
{
#if defined( TALGORITHMS ) && defined( AE_GAIN_ID )
    int result;
    int gain_frac;
    uint32_t ret_val = 0;

    LOG( LOG_INFO, "gain: %d.", gain );

    /* some controls(such brightness) will call acamera_command()
     * before isp_fw initialed, so we need to check.
     */
    if ( !isp_started ) {
        LOG( LOG_ERR, "ISP FW not inited yet" );
        return -EBUSY;
    }

    result = acamera_command( ctx_id, TALGORITHMS, AE_MODE_ID, 0, COMMAND_GET, &ret_val );
    LOG( LOG_INFO, "AE_MODE_ID = %d", ret_val );
    if ( ret_val != AE_FULL_MANUAL && ret_val != AE_MANUAL_GAIN ) {
        LOG( LOG_ERR, "Cannot set gain while AE_MODE is %d", ret_val );
        return 0;
    }

    gain_frac = ( ( gain % 100 ) * 256 ) / 100; // fraction part
    gain_frac |= ( gain / 100 ) << 8;           // integer part

    result = acamera_command( ctx_id, TALGORITHMS, AE_GAIN_ID, gain_frac, COMMAND_SET, &ret_val );
    if ( result ) {
        LOG( LOG_ERR, "Failed to set AE_GAIN_ID to %d, ret_value: %d.", gain, result );
        return result;
    }
#endif

    return 0;
}

// Note: The reason of original designer treat exposure_auto as
//       exp_manual enable/disable should be based on below definition.
//          enum v4l2_exposure_auto_type {
//                      V4L2_EXPOSURE_AUTO = 0,
//                      V4L2_EXPOSURE_MANUAL = 1,
static int isp_fw_do_set_exposure_auto( uint32_t ctx_id, int enable )
{
#if defined( TALGORITHMS ) && defined( AE_MODE_ID )
    int result;
    uint32_t mode = 0;
    uint32_t ret_val = 0;

    LOG( LOG_INFO, "manual_exposure enable: %d.", enable );

    /* some controls(such brightness) will call acamera_command()
     * before isp_fw initialed, so we need to check.
     */
    if ( !isp_started ) {
        LOG( LOG_ERR, "ISP FW not inited yet" );
        return -EBUSY;
    }

    result = acamera_command( ctx_id, TALGORITHMS, AE_MODE_ID, 0, COMMAND_GET, &ret_val );
    LOG( LOG_INFO, "AE_MODE_ID = %d", ret_val );
    switch ( enable ) {
    case true:
        if ( ret_val == AE_AUTO ) {
            mode = AE_MANUAL_EXPOSURE_TIME;
        } else if ( ret_val == AE_MANUAL_GAIN ) {
            mode = AE_FULL_MANUAL;
        } else {
            LOG( LOG_INFO, "Manual exposure is already enabled." );
            return 0;
        }
        break;
    case false:
        if ( ret_val == AE_MANUAL_EXPOSURE_TIME ) {
            mode = AE_AUTO;
        } else if ( ret_val == AE_FULL_MANUAL ) {
            mode = AE_MANUAL_GAIN;
        } else {
            LOG( LOG_INFO, "Manual exposure is already disabled." );
            return 0;
        }
        break;
    }

    result = acamera_command( ctx_id, TALGORITHMS, AE_MODE_ID, mode, COMMAND_SET, &ret_val );
    if ( result ) {
        LOG( LOG_ERR, "Failed to set AE_MODE_ID to %u, ret_value: %d.", mode, result );
        return result;
    }
#endif

    return 0;
}

/* set exposure in us unit */
static int isp_fw_do_set_exposure( uint32_t ctx_id, int exp )
{
#if defined( TALGORITHMS ) && defined( AE_EXPOSURE_ID )
    int result;
    uint32_t ret_val = 0;

    // V4L2_CID_EXPOSURE_ABSOLUTE   integer
    //    Determines the exposure time of the camera sensor.
    //    Drivers should interpret the values as 100 µs units,
    //    where the value 1 stands for 1/10000th of a second,
    //    10000 for 1 second and 100000 for 10 seconds.
    LOG( LOG_INFO, "exp in us: %d.", exp * 100 );

    /* some controls(such brightness) will call acamera_command()
     * before isp_fw initialed, so we need to check.
     */
    if ( !isp_started ) {
        LOG( LOG_ERR, "ISP FW not inited yet" );
        return -EBUSY;
    }

    // The exposure unit in driver is us.
    result = acamera_command( ctx_id, TALGORITHMS, AE_EXPOSURE_ID, exp * 100, COMMAND_SET, &ret_val );
    if ( result ) {
        LOG( LOG_ERR, "Failed to set AE_EXPOSURE_ID to %d, ret_value: %d.", exp, result );
        return result;
    }
#endif
    return 0;
}

static int isp_fw_do_set_variable_frame_rate( uint32_t ctx_id, int enable )
{
    // Not supported
    return 0;
}

static int isp_fw_do_set_white_balance_mode( uint32_t ctx_id, int wb_mode )
{
#if defined( TALGORITHMS ) && defined( AWB_MODE_ID )
#if defined( ISP_HAS_AWB_MESH_FSM ) || defined( ISP_HAS_AWB_MESH_NBP_FSM ) || defined( ISP_HAS_AWB_MANUAL_FSM ) || defined( ISP_HAS_AWB_ACAMERA_FSM )
    static int32_t last_wb_request = AWB_DAY_LIGHT;
#else
    static int32_t last_wb_request = AWB_MANUAL;
#endif
    int result;
    uint32_t mode = 0;
    uint32_t ret_val = 0;

    LOG( LOG_INFO, "new white balance request: %d.", wb_mode );

    /* some controls(such brightness) will call acamera_command()
     * before isp_fw initialed, so we need to check.
     */
    if ( !isp_started ) {
        LOG( LOG_ERR, "ISP FW not inited yet" );
        return -EBUSY;
    }

    result = acamera_command( ctx_id, TALGORITHMS, AWB_MODE_ID, 0, COMMAND_GET, &ret_val );
    LOG( LOG_INFO, "AWB_MODE_ID = %d", ret_val );
    switch ( wb_mode ) {
    case AWB_MANUAL:
        /* we set the last mode instead of MANUAL */
        mode = last_wb_request;
        break;
    case AWB_AUTO:
        /* we set the last mode instead of MANUAL */
        if ( ret_val != AWB_AUTO ) {
            mode = wb_mode;
        } else {
            LOG( LOG_INFO, "Auto WB is already enabled." );
            return 0;
        }
        break;
#if defined( ISP_HAS_AWB_MESH_FSM ) || defined( ISP_HAS_AWB_MESH_NBP_FSM ) || defined( ISP_HAS_AWB_MANUAL_FSM ) || defined( ISP_HAS_AWB_ACAMERA_FSM )
    case AWB_DAY_LIGHT:
    case AWB_CLOUDY:
    case AWB_INCANDESCENT:
    case AWB_FLOURESCENT:
    case AWB_TWILIGHT:
    case AWB_SHADE:
    case AWB_WARM_FLOURESCENT:
        if ( ret_val != AWB_AUTO ) {
            mode = wb_mode;
        } else {
            /* wb mode is not updated when it's in auto mode */
            LOG( LOG_INFO, "Auto WB is enabled, remembering mode." );
            last_wb_request = wb_mode;
            return 0;
        }
        break;
#endif
    default:
        return -EINVAL;
    }

    result = acamera_command( ctx_id, TALGORITHMS, AWB_MODE_ID, mode, COMMAND_SET, &ret_val );
    if ( result ) {
        LOG( LOG_ERR, "Failed to set AWB_MODE_ID to %u, ret_value: %d.", mode, result );
        return result;
    }
#endif
    return 0;
}

static int isp_fw_do_set_focus_auto( uint32_t ctx_id, int enable )
{
#if defined( TALGORITHMS ) && defined( AF_MODE_ID )
    int result;
    uint32_t mode = 0;
    uint32_t ret_val = 0;

    LOG( LOG_INFO, "new auto focus request: %d.", enable );

    /* some controls(such brightness) will call acamera_command()
     * before isp_fw initialed, so we need to check.
     */
    if ( !isp_started ) {
        LOG( LOG_ERR, "ISP FW not inited yet" );
        return -EBUSY;
    }

    result = acamera_command( ctx_id, TALGORITHMS, AF_MODE_ID, 0, COMMAND_GET, &ret_val );
    LOG( LOG_INFO, "AF_MODE_ID = %d", ret_val );
    switch ( enable ) {
    case 1:
        /* we set the last mode instead of MANUAL */
        if ( ret_val != AF_AUTO_CONTINUOUS ) {
            mode = AF_AUTO_CONTINUOUS;
        } else {
            LOG( LOG_INFO, "Auto focus is already enabled." );
            return 0;
        }
        break;
    case 0:
        if ( ret_val != AF_MANUAL ) {
            mode = AF_MANUAL;
        } else {
            /* wb mode is not updated when it's in auto mode */
            LOG( LOG_INFO, "Auto WB is enabled, remembering mode." );
            return 0;
        }
        break;
    default:
        return -EINVAL;
    }

    result = acamera_command( ctx_id, TALGORITHMS, AF_MODE_ID, mode, COMMAND_SET, &ret_val );
    if ( result ) {
        LOG( LOG_ERR, "Failed to set AF_MODE_ID to %u, ret_value: %d.", mode, result );
        return result;
    }
#endif

    return 0;
}

static int isp_fw_do_set_focus( uint32_t ctx_id, int focus )
{
#if defined( TALGORITHMS ) && defined( AF_MANUAL_CONTROL_ID )
    int result;
    uint32_t ret_val = 0;

    LOG( LOG_INFO, "focus: %d.", focus );

    /* some controls(such brightness) will call acamera_command()
     * before isp_fw initialed, so we need to check.
     */
    if ( !isp_started ) {
        LOG( LOG_ERR, "ISP FW not inited yet" );
        return -EBUSY;
    }

    result = acamera_command( ctx_id, TALGORITHMS, AF_MANUAL_CONTROL_ID, focus, COMMAND_SET, &ret_val );
    if ( result ) {
        LOG( LOG_ERR, "Failed to set AF_MANUAL_CONTROL_ID to %d, ret_value: %d.", focus, result );
        return result;
    }
#endif
    return 0;
}

static int isp_fw_do_set_cmd( uint32_t ctx_id, uint8_t command_type, uint8_t command, uint32_t value )
{
    int rc = 0;
    uint32_t ret_val = 0;

    if ( !isp_started ) {
        LOG( LOG_ERR, "ISP FW not inited yet" );
        return -EBUSY;
    }

    rc = acamera_command( ctx_id, command_type, command, value, COMMAND_SET, &ret_val );
    return rc;
}

static int isp_fw_do_get_cmd( uint32_t ctx_id, uint8_t command_type, uint8_t command, uint32_t *ret_val )
{
    int rc = 0;

    if ( !isp_started ) {
        LOG( LOG_ERR, "ISP FW not inited yet" );
        return -EBUSY;
    }

    rc = acamera_command( ctx_id, command_type, command, 0, COMMAND_GET, ret_val );
    return rc;
}

/* ----------------------------------------------------------------
 * fw_interface config interface
 */
bool fw_intf_validate_control( uint32_t id )
{
    return isp_fw_do_validate_control( id );
}

int fw_intf_set_test_pattern( uint32_t ctx_id, int val )
{
    return isp_fw_do_set_test_pattern( ctx_id, val );
}

int fw_intf_set_test_pattern_type( uint32_t ctx_id, int val )
{
    return isp_fw_do_set_test_pattern_type( ctx_id, val );
}

int fw_intf_set_af_refocus( uint32_t ctx_id, int val )
{
    return isp_fw_do_set_af_refocus( ctx_id, val );
}

int fw_intf_set_af_roi( uint32_t ctx_id, int val )
{
    return isp_fw_do_set_af_roi( ctx_id, val );
}

int fw_intf_set_brightness( uint32_t ctx_id, int val )
{
    return isp_fw_do_set_brightness( ctx_id, val );
}

int fw_intf_set_contrast( uint32_t ctx_id, int val )
{
    return isp_fw_do_set_contrast( ctx_id, val );
}

int fw_intf_set_saturation( uint32_t ctx_id, int val )
{
    return isp_fw_do_set_saturation( ctx_id, val );
}

int fw_intf_set_hue( uint32_t ctx_id, int val )
{
    return isp_fw_do_set_hue( ctx_id, val );
}

int fw_intf_set_sharpness( uint32_t ctx_id, int val )
{
    return isp_fw_do_set_sharpness( ctx_id, val );
}

int fw_intf_set_color_fx( uint32_t ctx_id, int val )
{
    return isp_fw_do_set_color_fx( ctx_id, val );
}

int fw_intf_set_hflip( uint32_t ctx_id, int val )
{
    return isp_fw_do_set_hflip( ctx_id, val ? 1 : 0 );
}

int fw_intf_set_vflip( uint32_t ctx_id, int val )
{
    return isp_fw_do_set_vflip( ctx_id, val ? 1 : 0 );
}

int fw_intf_set_autogain( uint32_t ctx_id, int val )
{
    /* autogain enable: disable manual gain.
     * autogain disable: enable manual gain.
     */
    return isp_fw_do_set_manual_gain( ctx_id, val ? 0 : 1 );
}

int fw_intf_set_gain( uint32_t ctx_id, int val )
{
    return isp_fw_do_set_gain( ctx_id, val );
}

int fw_intf_set_exposure_auto( uint32_t ctx_id, int val )
{
    return isp_fw_do_set_exposure_auto( ctx_id, val );
}

int fw_intf_set_exposure( uint32_t ctx_id, int val )
{
    return isp_fw_do_set_exposure( ctx_id, val );
}

int fw_intf_set_variable_frame_rate( uint32_t ctx_id, int val )
{
    return isp_fw_do_set_variable_frame_rate( ctx_id, val );
}

int fw_intf_set_white_balance_auto( uint32_t ctx_id, int val )
{
#ifdef AWB_MODE_ID
    int mode;

    if ( val == true )
        mode = AWB_AUTO;
    else
        mode = AWB_MANUAL;

    return isp_fw_do_set_white_balance_mode( ctx_id, mode );
#endif

    // return SUCCESS for compatibility verfication issue
    return 0;
}

int fw_intf_set_white_balance( uint32_t ctx_id, int val )
{
    int mode = 0;

    switch ( val ) {
#ifdef AWB_MODE_ID
#if defined( ISP_HAS_AWB_MESH_FSM ) || defined( ISP_HAS_AWB_MESH_NBP_FSM ) || defined( ISP_HAS_AWB_MANUAL_FSM ) || defined( ISP_HAS_AWB_ACAMERA_FSM )
    case 8000:
        mode = AWB_SHADE;
        break;
    case 7000:
        mode = AWB_CLOUDY;
        break;
    case 6000:
    case 5000:
        mode = AWB_DAY_LIGHT;
        break;
    case 4000:
        mode = AWB_FLOURESCENT;
        break;
    case 3000:
        mode = AWB_WARM_FLOURESCENT;
        break;
    case 2000:
        mode = AWB_INCANDESCENT;
        break;
#endif
#endif
    default:
        // return SUCCESS for compatibility verfication issue
        return 0;
    }

    return isp_fw_do_set_white_balance_mode( ctx_id, mode );
}

int fw_intf_set_focus_auto( uint32_t ctx_id, int val )
{
    return isp_fw_do_set_focus_auto( ctx_id, val );
}

int fw_intf_set_focus( uint32_t ctx_id, int val )
{
    return isp_fw_do_set_focus( ctx_id, val );
}

int fw_intf_set_output_fr_on_off( uint32_t ctx_id, uint32_t ctrl_val )
{
    return fw_intf_stream_set_output_format( ctx_id, V4L2_STREAM_TYPE_FR, ctrl_val );
}

int fw_intf_set_output_ds1_on_off( uint32_t ctx_id, uint32_t ctrl_val )
{
#if ISP_HAS_DS1
    return fw_intf_stream_set_output_format( ctx_id, V4L2_STREAM_TYPE_DS1, ctrl_val );
#else
    return 0;
#endif
}

int fw_intf_set_temper3_mode( uint32_t ctx_id, int enable_temper3_mode )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( TEMPER_MODE_ID )
    uint32_t cmd_value = enable_temper3_mode ? TEMPER3_MODE : TEMPER2_MODE;
    rc = isp_fw_do_set_cmd( ctx_id, TSYSTEM, TEMPER_MODE_ID, cmd_value );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set enable_temper3_mode to %d, rc: %d.", enable_temper3_mode, rc );
    }
#endif

    return rc;
}

int fw_intf_set_system_freeze_firmware( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_FREEZE_FIRMWARE )
    rc = isp_fw_do_set_cmd( ctx_id, TSYSTEM, SYSTEM_FREEZE_FIRMWARE, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set SYSTEM_FREEZE_FIRMWARE to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_system_manual_exposure( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MANUAL_EXPOSURE )
    rc = isp_fw_do_set_cmd( ctx_id, TSYSTEM, SYSTEM_MANUAL_EXPOSURE, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set SYSTEM_MANUAL_EXPOSURE to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_system_manual_integration_time( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MANUAL_INTEGRATION_TIME )
    rc = isp_fw_do_set_cmd( ctx_id, TSYSTEM, SYSTEM_MANUAL_INTEGRATION_TIME, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set SYSTEM_MANUAL_INTEGRATION_TIME to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_system_manual_max_integration_time( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MANUAL_MAX_INTEGRATION_TIME )
    rc = isp_fw_do_set_cmd( ctx_id, TSYSTEM, SYSTEM_MANUAL_MAX_INTEGRATION_TIME, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set SYSTEM_MANUAL_MAX_INTEGRATION_TIME to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_system_manual_sensor_analog_gain( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MANUAL_SENSOR_ANALOG_GAIN )
    rc = isp_fw_do_set_cmd( ctx_id, TSYSTEM, SYSTEM_MANUAL_SENSOR_ANALOG_GAIN, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set SYSTEM_MANUAL_SENSOR_ANALOG_GAIN to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_system_manual_sensor_digital_gain( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MANUAL_SENSOR_DIGITAL_GAIN )
    rc = isp_fw_do_set_cmd( ctx_id, TSYSTEM, SYSTEM_MANUAL_SENSOR_DIGITAL_GAIN, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set SYSTEM_MANUAL_SENSOR_DIGITAL_GAIN to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_system_manual_isp_digital_gain( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MANUAL_ISP_DIGITAL_GAIN )
    rc = isp_fw_do_set_cmd( ctx_id, TSYSTEM, SYSTEM_MANUAL_ISP_DIGITAL_GAIN, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set SYSTEM_MANUAL_ISP_DIGITAL_GAIN to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_system_manual_exposure_ratio( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MANUAL_EXPOSURE_RATIO )
    rc = isp_fw_do_set_cmd( ctx_id, TSYSTEM, SYSTEM_MANUAL_EXPOSURE_RATIO, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set SYSTEM_MANUAL_EXPOSURE_RATIO to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_system_manual_awb( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MANUAL_AWB )
    rc = isp_fw_do_set_cmd( ctx_id, TSYSTEM, SYSTEM_MANUAL_AWB, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set SYSTEM_MANUAL_AWB to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_system_manual_saturation( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MANUAL_SATURATION )
    rc = isp_fw_do_set_cmd( ctx_id, TSYSTEM, SYSTEM_MANUAL_SATURATION, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set SYSTEM_MANUAL_SATURATION to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_system_max_exposure_ratio( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MAX_EXPOSURE_RATIO )
    rc = isp_fw_do_set_cmd( ctx_id, TSYSTEM, SYSTEM_MAX_EXPOSURE_RATIO, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set SYSTEM_MAX_EXPOSURE_RATIO to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_system_exposure( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_EXPOSURE )
    rc = isp_fw_do_set_cmd( ctx_id, TSYSTEM, SYSTEM_EXPOSURE, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set SYSTEM_EXPOSURE to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_system_integration_time( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_INTEGRATION_TIME )
    rc = isp_fw_do_set_cmd( ctx_id, TSYSTEM, SYSTEM_INTEGRATION_TIME, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set SYSTEM_INTEGRATION_TIME to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_system_exposure_ratio( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_EXPOSURE_RATIO )
    rc = isp_fw_do_set_cmd( ctx_id, TSYSTEM, SYSTEM_EXPOSURE_RATIO, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set SYSTEM_EXPOSURE_RATIO to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_system_max_integration_time( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MAX_INTEGRATION_TIME )
    rc = isp_fw_do_set_cmd( ctx_id, TSYSTEM, SYSTEM_MAX_INTEGRATION_TIME, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set SYSTEM_MAX_INTEGRATION_TIME to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_system_sensor_analog_gain( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_SENSOR_ANALOG_GAIN )
    rc = isp_fw_do_set_cmd( ctx_id, TSYSTEM, SYSTEM_SENSOR_ANALOG_GAIN, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set SYSTEM_SENSOR_ANALOG_GAIN to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_system_max_sensor_analog_gain( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MAX_SENSOR_ANALOG_GAIN )
    rc = isp_fw_do_set_cmd( ctx_id, TSYSTEM, SYSTEM_MAX_SENSOR_ANALOG_GAIN, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set SYSTEM_MAX_SENSOR_ANALOG_GAIN to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_system_sensor_digital_gain( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_SENSOR_DIGITAL_GAIN )
    rc = isp_fw_do_set_cmd( ctx_id, TSYSTEM, SYSTEM_SENSOR_DIGITAL_GAIN, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set SYSTEM_SENSOR_DIGITAL_GAIN to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_system_max_sensor_digital_gain( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MAX_SENSOR_DIGITAL_GAIN )
    rc = isp_fw_do_set_cmd( ctx_id, TSYSTEM, SYSTEM_MAX_SENSOR_DIGITAL_GAIN, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set SYSTEM_MAX_SENSOR_DIGITAL_GAIN to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_system_isp_digital_gain( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_ISP_DIGITAL_GAIN )
    rc = isp_fw_do_set_cmd( ctx_id, TSYSTEM, SYSTEM_ISP_DIGITAL_GAIN, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set SYSTEM_ISP_DIGITAL_GAIN to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_system_max_isp_digital_gain( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MAX_ISP_DIGITAL_GAIN )
    rc = isp_fw_do_set_cmd( ctx_id, TSYSTEM, SYSTEM_MAX_ISP_DIGITAL_GAIN, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set SYSTEM_MAX_ISP_DIGITAL_GAIN to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_system_awb_red_gain( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_AWB_RED_GAIN )
    rc = isp_fw_do_set_cmd( ctx_id, TSYSTEM, SYSTEM_AWB_RED_GAIN, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set SYSTEM_AWB_RED_GAIN to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_system_awb_blue_gain( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_AWB_BLUE_GAIN )
    rc = isp_fw_do_set_cmd( ctx_id, TSYSTEM, SYSTEM_AWB_BLUE_GAIN, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set SYSTEM_AWB_BLUE_GAIN to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_isp_modules_manual_iridix( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TISP_MODULES ) && defined( ISP_MODULES_MANUAL_IRIDIX )
    rc = isp_fw_do_set_cmd( ctx_id, TISP_MODULES, ISP_MODULES_MANUAL_IRIDIX, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set ISP_MODULES_MANUAL_IRIDIX to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_isp_modules_manual_sinter( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TISP_MODULES ) && defined( ISP_MODULES_MANUAL_SINTER )
    rc = isp_fw_do_set_cmd( ctx_id, TISP_MODULES, ISP_MODULES_MANUAL_SINTER, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set ISP_MODULES_MANUAL_SINTER to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_isp_modules_manual_temper( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TISP_MODULES ) && defined( ISP_MODULES_MANUAL_TEMPER )
    rc = isp_fw_do_set_cmd( ctx_id, TISP_MODULES, ISP_MODULES_MANUAL_TEMPER, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set ISP_MODULES_MANUAL_TEMPER to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_isp_modules_manual_auto_level( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TISP_MODULES ) && defined( ISP_MODULES_MANUAL_AUTO_LEVEL )
    rc = isp_fw_do_set_cmd( ctx_id, TISP_MODULES, ISP_MODULES_MANUAL_AUTO_LEVEL, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set ISP_MODULES_MANUAL_AUTO_LEVEL to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_isp_modules_manual_frame_stitch( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TISP_MODULES ) && defined( ISP_MODULES_MANUAL_FRAME_STITCH )
    rc = isp_fw_do_set_cmd( ctx_id, TISP_MODULES, ISP_MODULES_MANUAL_FRAME_STITCH, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set ISP_MODULES_MANUAL_FRAME_STITCH to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_isp_modules_manual_raw_frontend( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TISP_MODULES ) && defined( ISP_MODULES_MANUAL_RAW_FRONTEND )
    rc = isp_fw_do_set_cmd( ctx_id, TISP_MODULES, ISP_MODULES_MANUAL_RAW_FRONTEND, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set ISP_MODULES_MANUAL_RAW_FRONTEND to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_isp_modules_manual_black_level( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TISP_MODULES ) && defined( ISP_MODULES_MANUAL_BLACK_LEVEL )
    rc = isp_fw_do_set_cmd( ctx_id, TISP_MODULES, ISP_MODULES_MANUAL_BLACK_LEVEL, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set ISP_MODULES_MANUAL_BLACK_LEVEL to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_isp_modules_manual_shading( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TISP_MODULES ) && defined( ISP_MODULES_MANUAL_SHADING )
    rc = isp_fw_do_set_cmd( ctx_id, TISP_MODULES, ISP_MODULES_MANUAL_SHADING, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set ISP_MODULES_MANUAL_SHADING to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_isp_modules_manual_demosaic( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TISP_MODULES ) && defined( ISP_MODULES_MANUAL_DEMOSAIC )
    rc = isp_fw_do_set_cmd( ctx_id, TISP_MODULES, ISP_MODULES_MANUAL_DEMOSAIC, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set ISP_MODULES_MANUAL_DEMOSAIC to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_isp_modules_manual_cnr( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TISP_MODULES ) && defined( ISP_MODULES_MANUAL_CNR )
    rc = isp_fw_do_set_cmd( ctx_id, TISP_MODULES, ISP_MODULES_MANUAL_CNR, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set ISP_MODULES_MANUAL_CNR to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_isp_modules_manual_sharpen( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TISP_MODULES ) && defined( ISP_MODULES_MANUAL_SHARPEN )
    rc = isp_fw_do_set_cmd( ctx_id, TISP_MODULES, ISP_MODULES_MANUAL_SHARPEN, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set ISP_MODULES_MANUAL_SHARPEN to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_image_resize_enable( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TIMAGE ) && defined( IMAGE_RESIZE_ENABLE_ID )
    rc = 0;
    uint32_t run = val ? RUN : 0;
    if ( run ) { // no need to set DONE, otherwise, rc will be failed.
        rc = isp_fw_do_set_cmd( ctx_id, TIMAGE, IMAGE_RESIZE_ENABLE_ID, run );
        if ( rc ) {
            LOG( LOG_ERR, "Failed to set IMAGE_RESIZE_ENABLE_ID to %d, rc: %d.", val, rc );
        }
    }
#endif

    return rc;
}

int fw_intf_set_image_resize_type( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TIMAGE ) && defined( IMAGE_RESIZE_TYPE_ID )
    uint32_t type;
    switch ( val ) {
    case V4L2_RESIZE_TYPE_CROP_FR:
        type = CROP_FR;
        break;
#if ISP_HAS_DS1
    case V4L2_RESIZE_TYPE_CROP_DS1:
        type = CROP_DS;
        break;
    case V4L2_RESIZE_TYPE_SCALER_DS1:
        type = SCALER;
        break;
#endif
    default:
        LOG( LOG_ERR, "Not supported IMAGE_RESIZE_TYPE_ID: %d.", val );
        return -2;
    }

    rc = isp_fw_do_set_cmd( ctx_id, TIMAGE, IMAGE_RESIZE_TYPE_ID, type );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set IMAGE_RESIZE_TYPE_ID to %d, rc: %d.", type, rc );
    }
#endif

    return rc;
}

int fw_intf_set_image_crop_xoffset( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TIMAGE ) && defined( IMAGE_CROP_XOFFSET_ID )
    rc = isp_fw_do_set_cmd( ctx_id, TIMAGE, IMAGE_CROP_XOFFSET_ID, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set IMAGE_CROP_XOFFSET_ID to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_image_crop_yoffset( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TIMAGE ) && defined( IMAGE_CROP_YOFFSET_ID )
    rc = isp_fw_do_set_cmd( ctx_id, TIMAGE, IMAGE_CROP_YOFFSET_ID, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set IMAGE_CROP_YOFFSET_ID to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_image_resize_width( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TIMAGE ) && defined( IMAGE_RESIZE_WIDTH_ID )
    rc = isp_fw_do_set_cmd( ctx_id, TIMAGE, IMAGE_RESIZE_WIDTH_ID, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set IMAGE_RESIZE_WIDTH_ID to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_image_resize_height( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TIMAGE ) && defined( IMAGE_RESIZE_HEIGHT_ID )
    rc = isp_fw_do_set_cmd( ctx_id, TIMAGE, IMAGE_RESIZE_HEIGHT_ID, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set IMAGE_RESIZE_HEIGHT_ID to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_ae_compensation( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TALGORITHMS ) && defined( AE_COMPENSATION_ID )
    rc = isp_fw_do_set_cmd( ctx_id, TALGORITHMS, AE_COMPENSATION_ID, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set AE_COMPENSATION_ID to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_set_system_dynamic_gamma_enable( uint32_t ctx_id, int val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_DYNAMIC_GAMMA_ENABLE )
    rc = isp_fw_do_set_cmd( ctx_id, TSYSTEM, SYSTEM_DYNAMIC_GAMMA_ENABLE, (uint32_t)val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to set SYSTEM_DYNAMIC_GAMMA_ENABLE to %d, rc: %d.", val, rc );
    }
#endif

    return rc;
}

int fw_intf_get_test_pattern( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( TEST_PATTERN_ENABLE_ID )
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, TEST_PATTERN_ENABLE_ID, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get TEST_PATTERN_ENABLE_ID, rc: %d.", rc );
    } else {
        *ret_val = ( *ret_val == ON ) ? 1 : 0;
    }
#endif

    return rc;
}

int fw_intf_get_test_pattern_type( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( TEST_PATTERN_MODE_ID )
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, TEST_PATTERN_MODE_ID, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get TEST_PATTERN_MODE_ID, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_sensor_preset( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSENSOR ) && defined( SENSOR_PRESET )
    rc = isp_fw_do_get_cmd( ctx_id, TSENSOR, SENSOR_PRESET, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get SENSOR_PRESET, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_af_roi( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TALGORITHMS ) && defined( AF_ROI_ID )
    uint32_t roi = 0;
    rc = isp_fw_do_get_cmd( ctx_id, TALGORITHMS, AF_ROI_ID, &roi );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get AF_ROI_ID, rc: %d.", rc );
    } else {
        // map [0, 254] to [0,127] due to limitaton of V4L2_CTRL_TYPE_INTEGER.
        *ret_val = roi >> 1;
    }
#endif

    return rc;
}

int fw_intf_get_output_fr_on_off( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TIMAGE ) && defined( FR_FORMAT_BASE_PLANE_ID )
    uint32_t format = 0;
    rc = isp_fw_do_get_cmd( ctx_id, TIMAGE, FR_FORMAT_BASE_PLANE_ID, &format );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get FR_FORMAT_BASE_PLANE_ID, rc: %d.", rc );
    } else {
        *ret_val = ( format != DMA_DISABLE ) ? 1 : 0;
    }
#endif

    return rc;
}

int fw_intf_get_output_ds1_on_off( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if ISP_HAS_DS1 && defined( TIMAGE ) && defined( DS1_FORMAT_BASE_PLANE_ID )
    uint32_t format = 0;
    rc = isp_fw_do_get_cmd( ctx_id, TIMAGE, DS1_FORMAT_BASE_PLANE_ID, &format );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get DS1_FORMAT_BASE_PLANE_ID, rc: %d.", rc );
    } else {
        *ret_val = ( format != DMA_DISABLE ) ? 1 : 0;
    }
#endif

    return rc;
}

int fw_intf_get_temper3_mode( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( TEMPER_MODE_ID )
    uint32_t mode = 0;
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, TEMPER_MODE_ID, &mode );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get TEMPER_MODE_ID, rc: %d.", rc );
    } else {
        *ret_val = ( mode == TEMPER3_MODE ) ? 1 : 0;
    }
#endif

    return rc;
}

int fw_intf_get_system_freeze_firmware( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_FREEZE_FIRMWARE )
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, SYSTEM_FREEZE_FIRMWARE, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get SYSTEM_FREEZE_FIRMWARE, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_system_manual_exposure( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MANUAL_EXPOSURE )
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, SYSTEM_MANUAL_EXPOSURE, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get SYSTEM_MANUAL_EXPOSURE, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_system_manual_integration_time( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MANUAL_INTEGRATION_TIME )
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, SYSTEM_MANUAL_INTEGRATION_TIME, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get SYSTEM_MANUAL_INTEGRATION_TIME, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_system_manual_max_integration_time( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MANUAL_MAX_INTEGRATION_TIME )
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, SYSTEM_MANUAL_MAX_INTEGRATION_TIME, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get SYSTEM_MANUAL_MAX_INTEGRATION_TIME, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_system_manual_sensor_analog_gain( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MANUAL_SENSOR_ANALOG_GAIN )
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, SYSTEM_MANUAL_SENSOR_ANALOG_GAIN, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get SYSTEM_MANUAL_SENSOR_ANALOG_GAIN, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_system_manual_sensor_digital_gain( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MANUAL_SENSOR_DIGITAL_GAIN )
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, SYSTEM_MANUAL_SENSOR_DIGITAL_GAIN, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get SYSTEM_MANUAL_SENSOR_DIGITAL_GAIN, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_system_manual_isp_digital_gain( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MANUAL_ISP_DIGITAL_GAIN )
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, SYSTEM_MANUAL_ISP_DIGITAL_GAIN, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get SYSTEM_MANUAL_ISP_DIGITAL_GAIN, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_system_manual_exposure_ratio( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MANUAL_EXPOSURE_RATIO )
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, SYSTEM_MANUAL_EXPOSURE_RATIO, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get SYSTEM_MANUAL_EXPOSURE_RATIO, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_system_manual_awb( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MANUAL_AWB )
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, SYSTEM_MANUAL_AWB, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get SYSTEM_MANUAL_AWB, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_system_manual_saturation( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MANUAL_SATURATION )
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, SYSTEM_MANUAL_SATURATION, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get SYSTEM_MANUAL_SATURATION, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_system_max_exposure_ratio( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MAX_EXPOSURE_RATIO )
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, SYSTEM_MAX_EXPOSURE_RATIO, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get SYSTEM_MAX_EXPOSURE_RATIO, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_system_max_integration_time( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MAX_INTEGRATION_TIME )
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, SYSTEM_MAX_INTEGRATION_TIME, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get SYSTEM_MAX_INTEGRATION_TIME, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_system_max_sensor_analog_gain( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MAX_SENSOR_ANALOG_GAIN )
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, SYSTEM_MAX_SENSOR_ANALOG_GAIN, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get SYSTEM_MAX_SENSOR_ANALOG_GAIN, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_system_max_sensor_digital_gain( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MAX_SENSOR_DIGITAL_GAIN )
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, SYSTEM_MAX_SENSOR_DIGITAL_GAIN, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get SYSTEM_MAX_SENSOR_DIGITAL_GAIN, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_system_max_isp_digital_gain( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_MAX_ISP_DIGITAL_GAIN )
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, SYSTEM_MAX_ISP_DIGITAL_GAIN, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get SYSTEM_MAX_ISP_DIGITAL_GAIN, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_isp_modules_manual_iridix( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TISP_MODULES ) && defined( ISP_MODULES_MANUAL_IRIDIX )
    rc = isp_fw_do_get_cmd( ctx_id, TISP_MODULES, ISP_MODULES_MANUAL_IRIDIX, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get ISP_MODULES_MANUAL_IRIDIX, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_isp_modules_manual_sinter( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TISP_MODULES ) && defined( ISP_MODULES_MANUAL_SINTER )
    rc = isp_fw_do_get_cmd( ctx_id, TISP_MODULES, ISP_MODULES_MANUAL_SINTER, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get ISP_MODULES_MANUAL_SINTER, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_isp_modules_manual_temper( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TISP_MODULES ) && defined( ISP_MODULES_MANUAL_TEMPER )
    rc = isp_fw_do_get_cmd( ctx_id, TISP_MODULES, ISP_MODULES_MANUAL_TEMPER, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get ISP_MODULES_MANUAL_TEMPER, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_isp_modules_manual_auto_level( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TISP_MODULES ) && defined( ISP_MODULES_MANUAL_AUTO_LEVEL )
    rc = isp_fw_do_get_cmd( ctx_id, TISP_MODULES, ISP_MODULES_MANUAL_AUTO_LEVEL, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get ISP_MODULES_MANUAL_AUTO_LEVEL, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_isp_modules_manual_frame_stitch( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TISP_MODULES ) && defined( ISP_MODULES_MANUAL_FRAME_STITCH )
    rc = isp_fw_do_get_cmd( ctx_id, TISP_MODULES, ISP_MODULES_MANUAL_FRAME_STITCH, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get ISP_MODULES_MANUAL_FRAME_STITCH, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_isp_modules_manual_raw_frontend( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TISP_MODULES ) && defined( ISP_MODULES_MANUAL_RAW_FRONTEND )
    rc = isp_fw_do_get_cmd( ctx_id, TISP_MODULES, ISP_MODULES_MANUAL_RAW_FRONTEND, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get ISP_MODULES_MANUAL_RAW_FRONTEND, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_isp_modules_manual_black_level( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TISP_MODULES ) && defined( ISP_MODULES_MANUAL_BLACK_LEVEL )
    rc = isp_fw_do_get_cmd( ctx_id, TISP_MODULES, ISP_MODULES_MANUAL_BLACK_LEVEL, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get ISP_MODULES_MANUAL_BLACK_LEVEL, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_isp_modules_manual_shading( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TISP_MODULES ) && defined( ISP_MODULES_MANUAL_SHADING )
    rc = isp_fw_do_get_cmd( ctx_id, TISP_MODULES, ISP_MODULES_MANUAL_SHADING, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get ISP_MODULES_MANUAL_SHADING, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_isp_modules_manual_demosaic( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TISP_MODULES ) && defined( ISP_MODULES_MANUAL_DEMOSAIC )
    rc = isp_fw_do_get_cmd( ctx_id, TISP_MODULES, ISP_MODULES_MANUAL_DEMOSAIC, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get ISP_MODULES_MANUAL_DEMOSAIC, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_isp_modules_manual_cnr( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TISP_MODULES ) && defined( ISP_MODULES_MANUAL_CNR )
    rc = isp_fw_do_get_cmd( ctx_id, TISP_MODULES, ISP_MODULES_MANUAL_CNR, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get ISP_MODULES_MANUAL_CNR, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_isp_modules_manual_sharpen( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TISP_MODULES ) && defined( ISP_MODULES_MANUAL_SHARPEN )
    rc = isp_fw_do_get_cmd( ctx_id, TISP_MODULES, ISP_MODULES_MANUAL_SHARPEN, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get ISP_MODULES_MANUAL_SHARPEN, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_image_resize_enable( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TIMAGE ) && defined( IMAGE_RESIZE_ENABLE_ID )
    uint32_t status = 0;
    rc = isp_fw_do_get_cmd( ctx_id, TIMAGE, IMAGE_RESIZE_ENABLE_ID, &status );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get IMAGE_RESIZE_ENABLE_ID, rc: %d.", rc );
    } else {
        *ret_val = ( status == RUN ) ? 1 : 0;
    }
#endif

    return rc;
}

int fw_intf_get_image_resize_type( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TIMAGE ) && defined( IMAGE_RESIZE_TYPE_ID )
    uint32_t type = 0;
    rc = isp_fw_do_get_cmd( ctx_id, TIMAGE, IMAGE_RESIZE_TYPE_ID, &type );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get IMAGE_RESIZE_TYPE_ID, rc: %d.", rc );
    } else {
        switch ( type ) {
        case CROP_FR:
            *ret_val = V4L2_RESIZE_TYPE_CROP_FR;
            break;
#if ISP_HAS_DS1
        case CROP_DS:
            *ret_val = V4L2_RESIZE_TYPE_CROP_DS1;
            break;
        case SCALER:
            *ret_val = V4L2_RESIZE_TYPE_SCALER_DS1;
            break;
#endif
        default:
            LOG( LOG_ERR, "Not supported IMAGE_RESIZE_TYPE_ID: %d.", type );
            rc = -2;
        }
    }
#endif

    return rc;
}

int fw_intf_get_image_crop_xoffset( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TIMAGE ) && defined( IMAGE_CROP_XOFFSET_ID )
    rc = isp_fw_do_get_cmd( ctx_id, TIMAGE, IMAGE_CROP_XOFFSET_ID, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get IMAGE_CROP_XOFFSET_ID, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_image_crop_yoffset( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TIMAGE ) && defined( IMAGE_CROP_YOFFSET_ID )
    rc = isp_fw_do_get_cmd( ctx_id, TIMAGE, IMAGE_CROP_YOFFSET_ID, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get IMAGE_CROP_YOFFSET_ID, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_image_resize_width( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TIMAGE ) && defined( IMAGE_RESIZE_WIDTH_ID )
    rc = isp_fw_do_get_cmd( ctx_id, TIMAGE, IMAGE_RESIZE_WIDTH_ID, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get IMAGE_RESIZE_WIDTH_ID, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_image_resize_height( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TIMAGE ) && defined( IMAGE_RESIZE_HEIGHT_ID )
    rc = isp_fw_do_get_cmd( ctx_id, TIMAGE, IMAGE_RESIZE_HEIGHT_ID, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get IMAGE_RESIZE_HEIGHT_ID, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_system_exposure( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_EXPOSURE )
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, SYSTEM_EXPOSURE, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get SYSTEM_EXPOSURE, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_system_integration_time( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_INTEGRATION_TIME )
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, SYSTEM_INTEGRATION_TIME, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get SYSTEM_INTEGRATION_TIME, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_system_exposure_ratio( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_EXPOSURE_RATIO )
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, SYSTEM_EXPOSURE_RATIO, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get SYSTEM_EXPOSURE_RATIO, rc: %d.", rc );
    }
#endif

    return rc;
}


int fw_intf_get_system_sensor_analog_gain( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_SENSOR_ANALOG_GAIN )
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, SYSTEM_SENSOR_ANALOG_GAIN, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get SYSTEM_SENSOR_ANALOG_GAIN, rc: %d.", rc );
    }
#endif

    return rc;
}


int fw_intf_get_system_sensor_digital_gain( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_SENSOR_DIGITAL_GAIN )
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, SYSTEM_SENSOR_DIGITAL_GAIN, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get SYSTEM_SENSOR_DIGITAL_GAIN, rc: %d.", rc );
    }
#endif

    return rc;
}


int fw_intf_get_system_isp_digital_gain( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_ISP_DIGITAL_GAIN )
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, SYSTEM_ISP_DIGITAL_GAIN, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get SYSTEM_ISP_DIGITAL_GAIN, rc: %d.", rc );
    }
#endif

    return rc;
}


int fw_intf_get_system_awb_red_gain( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_AWB_RED_GAIN )
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, SYSTEM_AWB_RED_GAIN, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get SYSTEM_AWB_RED_GAIN, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_system_awb_blue_gain( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_AWB_BLUE_GAIN )
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, SYSTEM_AWB_BLUE_GAIN, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get SYSTEM_AWB_BLUE_GAIN, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_status_info_exposure_log2( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSTATUS ) && defined( STATUS_INFO_EXPOSURE_LOG2_ID )
    rc = isp_fw_do_get_cmd( ctx_id, TSTATUS, STATUS_INFO_EXPOSURE_LOG2_ID, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get STATUS_INFO_EXPOSURE_LOG2_ID, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_status_info_gain_log2( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSTATUS ) && defined( STATUS_INFO_GAIN_LOG2_ID )
    rc = isp_fw_do_get_cmd( ctx_id, TSTATUS, STATUS_INFO_GAIN_LOG2_ID, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get STATUS_INFO_GAIN_LOG2_ID, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_status_info_gain_ones( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSTATUS ) && defined( STATUS_INFO_GAIN_ONES_ID )
    rc = isp_fw_do_get_cmd( ctx_id, TSTATUS, STATUS_INFO_GAIN_ONES_ID, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get STATUS_INFO_GAIN_ONES_ID, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_status_info_awb_mix_light_contrast( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSTATUS ) && defined( STATUS_INFO_AWB_MIX_LIGHT_CONTRAST )
    rc = isp_fw_do_get_cmd( ctx_id, TSTATUS, STATUS_INFO_AWB_MIX_LIGHT_CONTRAST, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get STATUS_INFO_AWB_MIX_LIGHT_CONTRAST, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_status_info_af_lens_pos( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSTATUS ) && defined( STATUS_INFO_AF_LENS_POS )
    rc = isp_fw_do_get_cmd( ctx_id, TSTATUS, STATUS_INFO_AF_LENS_POS, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get STATUS_INFO_AF_LENS_POS, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_status_info_af_focus_value( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSTATUS ) && defined( STATUS_INFO_AF_FOCUS_VALUE )
    rc = isp_fw_do_get_cmd( ctx_id, TSTATUS, STATUS_INFO_AF_FOCUS_VALUE, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get STATUS_INFO_AF_FOCUS_VALUE, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_info_fw_revision( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSELFTEST ) && defined( FW_REVISION )
    rc = isp_fw_do_get_cmd( ctx_id, TSELFTEST, FW_REVISION, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get FW_REVISION, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_ae_compensation( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TALGORITHMS ) && defined( AE_COMPENSATION_ID )
    rc = isp_fw_do_get_cmd( ctx_id, TALGORITHMS, AE_COMPENSATION_ID, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get AE_COMPENSATION_ID, rc: %d.", rc );
    }
#endif

    return rc;
}

int fw_intf_get_system_dynamic_gamma_enable( uint32_t ctx_id, int *ret_val )
{
    int rc = -1;

#if defined( TSYSTEM ) && defined( SYSTEM_DYNAMIC_GAMMA_ENABLE )
    rc = isp_fw_do_get_cmd( ctx_id, TSYSTEM, SYSTEM_DYNAMIC_GAMMA_ENABLE, ret_val );
    if ( rc ) {
        LOG( LOG_ERR, "Failed to get SYSTEM_DYNAMIC_GAMMA_ENABLE, rc: %d.", rc );
    }
#endif

    return rc;
}
