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

#ifndef __ACAMERA_FPGA_CONFIG_H__
#define __ACAMERA_FPGA_CONFIG_H__


#include "system_sw_io.h"

#include "system_hw_io.h"

// ------------------------------------------------------------------------------ //
// Instance 'fpga' of module 'fpga_config_misc'
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_BASE_ADDR (0x220000L)
#define ACAMERA_FPGA_SIZE (0x1000)

// ------------------------------------------------------------------------------ //
// Group: FPGA
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Register: FPGA build date
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Build date, format (dec): YYMMDDHHMM
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_FPGA_BUILD_DATE_DEFAULT (0x0)
#define ACAMERA_FPGA_FPGA_FPGA_BUILD_DATE_DATASIZE (32)
#define ACAMERA_FPGA_FPGA_FPGA_BUILD_DATE_OFFSET (0x0)
#define ACAMERA_FPGA_FPGA_FPGA_BUILD_DATE_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_fpga_fpga_build_date_read(uintptr_t base) {
    return system_hw_read_32(0x220000L);
}
// ------------------------------------------------------------------------------ //
// Register: FPGA version
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Git hash, hex
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_FPGA_VERSION_DEFAULT (0x0)
#define ACAMERA_FPGA_FPGA_FPGA_VERSION_DATASIZE (32)
#define ACAMERA_FPGA_FPGA_FPGA_VERSION_OFFSET (0x10)
#define ACAMERA_FPGA_FPGA_FPGA_VERSION_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_fpga_fpga_version_read(uintptr_t base) {
    return system_hw_read_32(0x220010L);
}
// ------------------------------------------------------------------------------ //
// Register: ISP version
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// SVN revision, dec
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_ISP_VERSION_DEFAULT (0x0)
#define ACAMERA_FPGA_FPGA_ISP_VERSION_DATASIZE (32)
#define ACAMERA_FPGA_FPGA_ISP_VERSION_OFFSET (0x14)
#define ACAMERA_FPGA_FPGA_ISP_VERSION_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_fpga_isp_version_read(uintptr_t base) {
    return system_hw_read_32(0x220014L);
}
// ------------------------------------------------------------------------------ //
// Register: GDC version
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// SVN revision, dec
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_GDC_VERSION_DEFAULT (0x0)
#define ACAMERA_FPGA_FPGA_GDC_VERSION_DATASIZE (32)
#define ACAMERA_FPGA_FPGA_GDC_VERSION_OFFSET (0x18)
#define ACAMERA_FPGA_FPGA_GDC_VERSION_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_fpga_gdc_version_read(uintptr_t base) {
    return system_hw_read_32(0x220018L);
}
// ------------------------------------------------------------------------------ //
// Register: FPGA include ISP
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Is ISP included in this build: 0 - isn't included, 1 - included
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_FPGA_INCLUDE_ISP_DEFAULT (0x0)
#define ACAMERA_FPGA_FPGA_FPGA_INCLUDE_ISP_DATASIZE (1)
#define ACAMERA_FPGA_FPGA_FPGA_INCLUDE_ISP_OFFSET (0x30)
#define ACAMERA_FPGA_FPGA_FPGA_INCLUDE_ISP_MASK (0x1)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_fpga_fpga_include_isp_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220030L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: FPGA include GDC
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Is GDC included in this build: 0 - isn't included, 1 - included
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_FPGA_INCLUDE_GDC_DEFAULT (0x0)
#define ACAMERA_FPGA_FPGA_FPGA_INCLUDE_GDC_DATASIZE (1)
#define ACAMERA_FPGA_FPGA_FPGA_INCLUDE_GDC_OFFSET (0x30)
#define ACAMERA_FPGA_FPGA_FPGA_INCLUDE_GDC_MASK (0x2)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_fpga_fpga_include_gdc_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220030L) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: FPGA include CPU
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Is CPU included in this build: 0 - isn't included, 1 - included
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_FPGA_INCLUDE_CPU_DEFAULT (0x0)
#define ACAMERA_FPGA_FPGA_FPGA_INCLUDE_CPU_DATASIZE (1)
#define ACAMERA_FPGA_FPGA_FPGA_INCLUDE_CPU_OFFSET (0x30)
#define ACAMERA_FPGA_FPGA_FPGA_INCLUDE_CPU_MASK (0x4)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_fpga_fpga_include_cpu_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220030L) & 0x4) >> 2);
}
// ------------------------------------------------------------------------------ //
// Register: Sensor0 IMX290
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Is listed sensor type supported? 0 - no, 1 - yes
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_SENSOR0_IMX290_DEFAULT (0x0)
#define ACAMERA_FPGA_FPGA_SENSOR0_IMX290_DATASIZE (1)
#define ACAMERA_FPGA_FPGA_SENSOR0_IMX290_OFFSET (0x30)
#define ACAMERA_FPGA_FPGA_SENSOR0_IMX290_MASK (0x100)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_fpga_sensor0_imx290_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220030L) & 0x100) >> 8);
}
// ------------------------------------------------------------------------------ //
// Register: Sensor0 MIPI
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Is listed sensor type supported? 0 - no, 1 - yes
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_SENSOR0_MIPI_DEFAULT (0x0)
#define ACAMERA_FPGA_FPGA_SENSOR0_MIPI_DATASIZE (1)
#define ACAMERA_FPGA_FPGA_SENSOR0_MIPI_OFFSET (0x30)
#define ACAMERA_FPGA_FPGA_SENSOR0_MIPI_MASK (0x200)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_fpga_sensor0_mipi_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220030L) & 0x200) >> 9);
}
// ------------------------------------------------------------------------------ //
// Register: Sensor0 parallel
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Is listed sensor type supported? 0 - no, 1 - yes
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_SENSOR0_PARALLEL_DEFAULT (0x0)
#define ACAMERA_FPGA_FPGA_SENSOR0_PARALLEL_DATASIZE (1)
#define ACAMERA_FPGA_FPGA_SENSOR0_PARALLEL_OFFSET (0x30)
#define ACAMERA_FPGA_FPGA_SENSOR0_PARALLEL_MASK (0x400)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_fpga_sensor0_parallel_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220030L) & 0x400) >> 10);
}
// ------------------------------------------------------------------------------ //
// Register: Sensor1 MIPI
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Is listed sensor type supported? 0 - no, 1 - yes
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_SENSOR1_MIPI_DEFAULT (0x0)
#define ACAMERA_FPGA_FPGA_SENSOR1_MIPI_DATASIZE (1)
#define ACAMERA_FPGA_FPGA_SENSOR1_MIPI_OFFSET (0x30)
#define ACAMERA_FPGA_FPGA_SENSOR1_MIPI_MASK (0x800)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_fpga_sensor1_mipi_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220030L) & 0x800) >> 11);
}
// ------------------------------------------------------------------------------ //
// Register: Sensor1 parallel
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Is listed sensor type supported? 0 - no, 1 - yes
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_SENSOR1_PARALLEL_DEFAULT (0x0)
#define ACAMERA_FPGA_FPGA_SENSOR1_PARALLEL_DATASIZE (1)
#define ACAMERA_FPGA_FPGA_SENSOR1_PARALLEL_OFFSET (0x30)
#define ACAMERA_FPGA_FPGA_SENSOR1_PARALLEL_MASK (0x1000)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_fpga_sensor1_parallel_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220030L) & 0x1000) >> 12);
}
// ------------------------------------------------------------------------------ //
// Register: Lens control
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Is listed functionality type supported? 0 - no, 1 - yes
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_LENS_CONTROL_DEFAULT (0x0)
#define ACAMERA_FPGA_FPGA_LENS_CONTROL_DATASIZE (1)
#define ACAMERA_FPGA_FPGA_LENS_CONTROL_OFFSET (0x30)
#define ACAMERA_FPGA_FPGA_LENS_CONTROL_MASK (0x10000)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_fpga_lens_control_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220030L) & 0x10000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: wdr_frame_buffer1_dma_addr_39_32
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Higher part [39:32] of address bus of WDR Mux channel 1 out AXI
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_DMA_ADDR_39_32_DEFAULT (0x00)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_DMA_ADDR_39_32_DATASIZE (8)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_DMA_ADDR_39_32_OFFSET (0x40)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_DMA_ADDR_39_32_MASK (0xff)

// args: data (8-bit)
static __inline void acamera_fpga_isp_frame_stitch_frame_buffer_dma_addr_39_32_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220040L);
    system_hw_write_32(0x220040L, (((uint32_t) (data & 0xff)) << 0) | (curr & 0xffffff00));
}
static __inline uint8_t acamera_fpga_isp_frame_stitch_frame_buffer_dma_addr_39_32_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220040L) & 0xff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: capture1_dma_writer_waddr_39_32
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Higher part [39:32] of address bus write part of Video Capture DMA Writer 1 out AXI
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_CAPTURE1_DMA_WRITER_WADDR_39_32_DEFAULT (0x00)
#define ACAMERA_FPGA_FPGA_CAPTURE1_DMA_WRITER_WADDR_39_32_DATASIZE (8)
#define ACAMERA_FPGA_FPGA_CAPTURE1_DMA_WRITER_WADDR_39_32_OFFSET (0x40)
#define ACAMERA_FPGA_FPGA_CAPTURE1_DMA_WRITER_WADDR_39_32_MASK (0xff000000)

// args: data (8-bit)
static __inline void acamera_fpga_fpga_capture1_dma_writer_waddr_39_32_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220040L);
    system_hw_write_32(0x220040L, (((uint32_t) (data & 0xff)) << 24) | (curr & 0xffffff));
}
static __inline uint8_t acamera_fpga_fpga_capture1_dma_writer_waddr_39_32_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220040L) & 0xff000000) >> 24);
}
// ------------------------------------------------------------------------------ //
// Register: capture2_dma_writer_waddr_39_32
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Higher part [39:32] of address bus write part of Video Capture DMA Writer 2 out AXI
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_CAPTURE2_DMA_WRITER_WADDR_39_32_DEFAULT (0x00)
#define ACAMERA_FPGA_FPGA_CAPTURE2_DMA_WRITER_WADDR_39_32_DATASIZE (8)
#define ACAMERA_FPGA_FPGA_CAPTURE2_DMA_WRITER_WADDR_39_32_OFFSET (0x44)
#define ACAMERA_FPGA_FPGA_CAPTURE2_DMA_WRITER_WADDR_39_32_MASK (0xff)

// args: data (8-bit)
static __inline void acamera_fpga_fpga_capture2_dma_writer_waddr_39_32_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220044L);
    system_hw_write_32(0x220044L, (((uint32_t) (data & 0xff)) << 0) | (curr & 0xffffff00));
}
static __inline uint8_t acamera_fpga_fpga_capture2_dma_writer_waddr_39_32_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220044L) & 0xff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: capture3_dma_writer_waddr_39_32
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Higher part [39:32] of address bus write part of Video Capture DMA Writer 3 out AXI
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_CAPTURE3_DMA_WRITER_WADDR_39_32_DEFAULT (0x00)
#define ACAMERA_FPGA_FPGA_CAPTURE3_DMA_WRITER_WADDR_39_32_DATASIZE (8)
#define ACAMERA_FPGA_FPGA_CAPTURE3_DMA_WRITER_WADDR_39_32_OFFSET (0x44)
#define ACAMERA_FPGA_FPGA_CAPTURE3_DMA_WRITER_WADDR_39_32_MASK (0xff00)

// args: data (8-bit)
static __inline void acamera_fpga_fpga_capture3_dma_writer_waddr_39_32_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220044L);
    system_hw_write_32(0x220044L, (((uint32_t) (data & 0xff)) << 8) | (curr & 0xffff00ff));
}
static __inline uint8_t acamera_fpga_fpga_capture3_dma_writer_waddr_39_32_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220044L) & 0xff00) >> 8);
}
// ------------------------------------------------------------------------------ //
// Register: isp_dma_writer_fr_waddr_39_32
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Higher part [39:32] of address bus write part of ISP DMA Writer FR out AXI
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_ISP_DMA_WRITER_FR_WADDR_39_32_DEFAULT (0x00)
#define ACAMERA_FPGA_FPGA_ISP_DMA_WRITER_FR_WADDR_39_32_DATASIZE (8)
#define ACAMERA_FPGA_FPGA_ISP_DMA_WRITER_FR_WADDR_39_32_OFFSET (0x44)
#define ACAMERA_FPGA_FPGA_ISP_DMA_WRITER_FR_WADDR_39_32_MASK (0xff000000)

// args: data (8-bit)
static __inline void acamera_fpga_fpga_isp_dma_writer_fr_waddr_39_32_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220044L);
    system_hw_write_32(0x220044L, (((uint32_t) (data & 0xff)) << 24) | (curr & 0xffffff));
}
static __inline uint8_t acamera_fpga_fpga_isp_dma_writer_fr_waddr_39_32_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220044L) & 0xff000000) >> 24);
}
// ------------------------------------------------------------------------------ //
// Register: isp_dma_writer_ds_waddr_39_32
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Higher part [39:32] of address bus write part of ISP DMA Writer DS out AXI
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_ISP_DMA_WRITER_DS1_WADDR_39_32_DEFAULT (0x00)
#define ACAMERA_FPGA_FPGA_ISP_DMA_WRITER_DS1_WADDR_39_32_DATASIZE (8)
#define ACAMERA_FPGA_FPGA_ISP_DMA_WRITER_DS1_WADDR_39_32_OFFSET (0x48)
#define ACAMERA_FPGA_FPGA_ISP_DMA_WRITER_DS1_WADDR_39_32_MASK (0xff)

// args: data (8-bit)
static __inline void acamera_fpga_fpga_isp_dma_writer_ds1_waddr_39_32_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220048L);
    system_hw_write_32(0x220048L, (((uint32_t) (data & 0xff)) << 0) | (curr & 0xffffff00));
}
static __inline uint8_t acamera_fpga_fpga_isp_dma_writer_ds1_waddr_39_32_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220048L) & 0xff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: isp_dma_temper_addr_39_32
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Higher part [39:32] of address bus of ISP Temper in-out AXIs
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_ISP_DMA_TEMPER_ADDR_39_32_DEFAULT (0x00)
#define ACAMERA_FPGA_FPGA_ISP_DMA_TEMPER_ADDR_39_32_DATASIZE (8)
#define ACAMERA_FPGA_FPGA_ISP_DMA_TEMPER_ADDR_39_32_OFFSET (0x48)
#define ACAMERA_FPGA_FPGA_ISP_DMA_TEMPER_ADDR_39_32_MASK (0xff00)

// args: data (8-bit)
static __inline void acamera_fpga_fpga_isp_dma_temper_addr_39_32_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220048L);
    system_hw_write_32(0x220048L, (((uint32_t) (data & 0xff)) << 8) | (curr & 0xffff00ff));
}
static __inline uint8_t acamera_fpga_fpga_isp_dma_temper_addr_39_32_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220048L) & 0xff00) >> 8);
}
// ------------------------------------------------------------------------------ //
// Register: gdc_addr_39_32
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Higher part [39:32] of address bus of GDC AXI
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_GDC_ADDR_39_32_DEFAULT (0x00)
#define ACAMERA_FPGA_FPGA_GDC_ADDR_39_32_DATASIZE (8)
#define ACAMERA_FPGA_FPGA_GDC_ADDR_39_32_OFFSET (0x48)
#define ACAMERA_FPGA_FPGA_GDC_ADDR_39_32_MASK (0xff0000)

// args: data (8-bit)
static __inline void acamera_fpga_fpga_gdc_addr_39_32_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220048L);
    system_hw_write_32(0x220048L, (((uint32_t) (data & 0xff)) << 16) | (curr & 0xff00ffff));
}
static __inline uint8_t acamera_fpga_fpga_gdc_addr_39_32_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220048L) & 0xff0000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: hdmi_frame_reader_raddr_39_32
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Higher part [39:32] of address bus read part of HDMI Frame Reader AXI
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_HDMI_FRAME_READER_RADDR_39_32_DEFAULT (0x00)
#define ACAMERA_FPGA_FPGA_HDMI_FRAME_READER_RADDR_39_32_DATASIZE (8)
#define ACAMERA_FPGA_FPGA_HDMI_FRAME_READER_RADDR_39_32_OFFSET (0x48)
#define ACAMERA_FPGA_FPGA_HDMI_FRAME_READER_RADDR_39_32_MASK (0xff000000)

// args: data (8-bit)
static __inline void acamera_fpga_fpga_hdmi_frame_reader_raddr_39_32_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220048L);
    system_hw_write_32(0x220048L, (((uint32_t) (data & 0xff)) << 24) | (curr & 0xffffff));
}
static __inline uint8_t acamera_fpga_fpga_hdmi_frame_reader_raddr_39_32_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220048L) & 0xff000000) >> 24);
}
// ------------------------------------------------------------------------------ //
// Register: hdmi_frame_reader_uv_raddr_39_32
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Higher part [39:32] of address bus read part of HDMI Frame Reader AXI
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_HDMI_FRAME_READER_UV_RADDR_39_32_DEFAULT (0x00)
#define ACAMERA_FPGA_FPGA_HDMI_FRAME_READER_UV_RADDR_39_32_DATASIZE (8)
#define ACAMERA_FPGA_FPGA_HDMI_FRAME_READER_UV_RADDR_39_32_OFFSET (0x4c)
#define ACAMERA_FPGA_FPGA_HDMI_FRAME_READER_UV_RADDR_39_32_MASK (0xff)

// args: data (8-bit)
static __inline void acamera_fpga_fpga_hdmi_frame_reader_uv_raddr_39_32_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x22004cL);
    system_hw_write_32(0x22004cL, (((uint32_t) (data & 0xff)) << 0) | (curr & 0xffffff00));
}
static __inline uint8_t acamera_fpga_fpga_hdmi_frame_reader_uv_raddr_39_32_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x22004cL) & 0xff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: ISP max_addr_dly_line_fr
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// clogb2(MAX_FR_FRAME_W/2)+16
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_ISP_MAX_ADDR_DLY_LINE_FR_DEFAULT (975)
#define ACAMERA_FPGA_FPGA_ISP_MAX_ADDR_DLY_LINE_FR_DATASIZE (16)
#define ACAMERA_FPGA_FPGA_ISP_MAX_ADDR_DLY_LINE_FR_OFFSET (0x60)
#define ACAMERA_FPGA_FPGA_ISP_MAX_ADDR_DLY_LINE_FR_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_fpga_isp_max_addr_dly_line_fr_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220060L);
    system_hw_write_32(0x220060L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_fpga_isp_max_addr_dly_line_fr_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220060L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: ISP max_addr_dly_line_ds
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// clogb2(MAX_DS_FRAME_W/2)+16
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_ISP_MAX_ADDR_DLY_LINE_DS_DEFAULT (975)
#define ACAMERA_FPGA_FPGA_ISP_MAX_ADDR_DLY_LINE_DS_DATASIZE (16)
#define ACAMERA_FPGA_FPGA_ISP_MAX_ADDR_DLY_LINE_DS_OFFSET (0x64)
#define ACAMERA_FPGA_FPGA_ISP_MAX_ADDR_DLY_LINE_DS_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_fpga_isp_max_addr_dly_line_ds_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220064L);
    system_hw_write_32(0x220064L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_fpga_isp_max_addr_dly_line_ds_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220064L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Group: Interrupt controller
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Register: mask_vector
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Interrupt mask vector. 0: Interrupt is enabled, 1: interrupt is masked
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_MASK_VECTOR_DEFAULT (0xFFFFFFFF)
#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_MASK_VECTOR_DATASIZE (32)
#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_MASK_VECTOR_OFFSET (0x80)
#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_MASK_VECTOR_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_interrupt_controller_mask_vector_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x220080L, data);
}
static __inline uint32_t acamera_fpga_interrupt_controller_mask_vector_read(uintptr_t base) {
    return system_hw_read_32(0x220080L);
}
// ------------------------------------------------------------------------------ //
// Register: clear_vector
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Interrupt clear vector. its bitwise cleared. When a bit is set to 1. that interrupt bit in the status register is cleared
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_CLEAR_VECTOR_DEFAULT (0x00)
#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_CLEAR_VECTOR_DATASIZE (32)
#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_CLEAR_VECTOR_OFFSET (0x84)
#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_CLEAR_VECTOR_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_interrupt_controller_clear_vector_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x220084L, data);
}
static __inline uint32_t acamera_fpga_interrupt_controller_clear_vector_read(uintptr_t base) {
    return system_hw_read_32(0x220084L);
}
// ------------------------------------------------------------------------------ //
// Register: shadow_disable_vector
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Interrupt shadow disable vector. To disable shadow feature for the specific interrupt event by setting the related bit to 1
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_SHADOW_DISABLE_VECTOR_DEFAULT (0x00)
#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_SHADOW_DISABLE_VECTOR_DATASIZE (32)
#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_SHADOW_DISABLE_VECTOR_OFFSET (0x88)
#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_SHADOW_DISABLE_VECTOR_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_interrupt_controller_shadow_disable_vector_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x220088L, data);
}
static __inline uint32_t acamera_fpga_interrupt_controller_shadow_disable_vector_read(uintptr_t base) {
    return system_hw_read_32(0x220088L);
}
// ------------------------------------------------------------------------------ //
// Register: pulse_mode
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// When set to 1, the output interrupt will be a pulse. Otherwise it should be level
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_PULSE_MODE_DEFAULT (0)
#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_PULSE_MODE_DATASIZE (1)
#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_PULSE_MODE_OFFSET (0x8c)
#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_PULSE_MODE_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_interrupt_controller_pulse_mode_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x22008cL);
    system_hw_write_32(0x22008cL, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_interrupt_controller_pulse_mode_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x22008cL) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: clear
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Interrupt clear vector register qualifier. First the vector must be written. Then this bit must be set to 1 and then cleared
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_CLEAR_DEFAULT (0)
#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_CLEAR_DATASIZE (1)
#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_CLEAR_OFFSET (0x90)
#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_CLEAR_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_interrupt_controller_clear_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220090L);
    system_hw_write_32(0x220090L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_interrupt_controller_clear_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220090L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: status_vector
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// bit[0] : ISP
//                                                                                                             bit[1] : CDMA
//                                                                                                             bit[2] : GDC
//                                                                                                             bit[3]-bit[31] : Reserved
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_STATUS_VECTOR_DEFAULT (0x0)
#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_STATUS_VECTOR_DATASIZE (32)
#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_STATUS_VECTOR_OFFSET (0x94)
#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_STATUS_VECTOR_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_interrupt_controller_status_vector_read(uintptr_t base) {
    return system_hw_read_32(0x220094L);
}
// ------------------------------------------------------------------------------ //
// Register: bypass
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Bypass interrupt controller, mask_vector and status_vector are still active
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_BYPASS_DEFAULT (0)
#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_BYPASS_DATASIZE (1)
#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_BYPASS_OFFSET (0x9c)
#define ACAMERA_FPGA_INTERRUPT_CONTROLLER_BYPASS_MASK (0x80000000)

// args: data (1-bit)
static __inline void acamera_fpga_interrupt_controller_bypass_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x22009cL);
    system_hw_write_32(0x22009cL, (((uint32_t) (data & 0x1)) << 31) | (curr & 0x7fffffff));
}
static __inline uint8_t acamera_fpga_interrupt_controller_bypass_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x22009cL) & 0x80000000) >> 31);
}
// ------------------------------------------------------------------------------ //
// Group: Debug FPGA
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Register: FPGA probe 0 select
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Logical OR with others selected
//                                                                                                             bit[0]: ddr_axi_wvalid
//                                                                                                             bit[1]: ddr_axi_wready
//                                                                                                             bit[2]: ddr_axi_rvalid
//                                                                                                             bit[3]: ddr_axi_rready
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_DEBUG_FPGA_FPGA_PROBE_0_SELECT_DEFAULT (0x00)
#define ACAMERA_FPGA_DEBUG_FPGA_FPGA_PROBE_0_SELECT_DATASIZE (4)
#define ACAMERA_FPGA_DEBUG_FPGA_FPGA_PROBE_0_SELECT_OFFSET (0xa0)
#define ACAMERA_FPGA_DEBUG_FPGA_FPGA_PROBE_0_SELECT_MASK (0xf)

// args: data (4-bit)
static __inline void acamera_fpga_debug_fpga_fpga_probe_0_select_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2200a0L);
    system_hw_write_32(0x2200a0L, (((uint32_t) (data & 0xf)) << 0) | (curr & 0xfffffff0));
}
static __inline uint8_t acamera_fpga_debug_fpga_fpga_probe_0_select_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2200a0L) & 0xf) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: FPGA probe 1 select
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Logical OR with others selected
//                                                                                                             bit[0]: ddr_axi_wvalid
//                                                                                                             bit[1]: ddr_axi_wready
//                                                                                                             bit[2]: ddr_axi_rvalid
//                                                                                                             bit[3]: ddr_axi_rready
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_DEBUG_FPGA_FPGA_PROBE_1_SELECT_DEFAULT (0x00)
#define ACAMERA_FPGA_DEBUG_FPGA_FPGA_PROBE_1_SELECT_DATASIZE (4)
#define ACAMERA_FPGA_DEBUG_FPGA_FPGA_PROBE_1_SELECT_OFFSET (0xa0)
#define ACAMERA_FPGA_DEBUG_FPGA_FPGA_PROBE_1_SELECT_MASK (0xf0000)

// args: data (4-bit)
static __inline void acamera_fpga_debug_fpga_fpga_probe_1_select_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2200a0L);
    system_hw_write_32(0x2200a0L, (((uint32_t) (data & 0xf)) << 16) | (curr & 0xfff0ffff));
}
static __inline uint8_t acamera_fpga_debug_fpga_fpga_probe_1_select_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2200a0L) & 0xf0000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: FPGA probe 2 select
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Logical OR with others selected
//                                                                                                             bit[0]: ddr_axi_wvalid
//                                                                                                             bit[1]: ddr_axi_wready
//                                                                                                             bit[2]: ddr_axi_rvalid
//                                                                                                             bit[3]: ddr_axi_rready
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_DEBUG_FPGA_FPGA_PROBE_2_SELECT_DEFAULT (0x00)
#define ACAMERA_FPGA_DEBUG_FPGA_FPGA_PROBE_2_SELECT_DATASIZE (4)
#define ACAMERA_FPGA_DEBUG_FPGA_FPGA_PROBE_2_SELECT_OFFSET (0xa4)
#define ACAMERA_FPGA_DEBUG_FPGA_FPGA_PROBE_2_SELECT_MASK (0xf)

// args: data (4-bit)
static __inline void acamera_fpga_debug_fpga_fpga_probe_2_select_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2200a4L);
    system_hw_write_32(0x2200a4L, (((uint32_t) (data & 0xf)) << 0) | (curr & 0xfffffff0));
}
static __inline uint8_t acamera_fpga_debug_fpga_fpga_probe_2_select_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2200a4L) & 0xf) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: FPGA probe 3 select
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Logical OR with others selected
//                                                                                                             bit[0]: ddr_axi_wvalid
//                                                                                                             bit[1]: ddr_axi_wready
//                                                                                                             bit[2]: ddr_axi_rvalid
//                                                                                                             bit[3]: ddr_axi_rready
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_DEBUG_FPGA_FPGA_PROBE_3_SELECT_DEFAULT (0x00)
#define ACAMERA_FPGA_DEBUG_FPGA_FPGA_PROBE_3_SELECT_DATASIZE (4)
#define ACAMERA_FPGA_DEBUG_FPGA_FPGA_PROBE_3_SELECT_OFFSET (0xa4)
#define ACAMERA_FPGA_DEBUG_FPGA_FPGA_PROBE_3_SELECT_MASK (0xf0000)

// args: data (4-bit)
static __inline void acamera_fpga_debug_fpga_fpga_probe_3_select_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2200a4L);
    system_hw_write_32(0x2200a4L, (((uint32_t) (data & 0xf)) << 16) | (curr & 0xfff0ffff));
}
static __inline uint8_t acamera_fpga_debug_fpga_fpga_probe_3_select_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2200a4L) & 0xf0000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: Sensor probe 0 select
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Logical OR with others selected
//                                                                                                             bit[0]: diff lane
//                                                                                                             bit[1]: diff clk locked
//                                                                                                             bit[2]: diff clk aligned
//                                                                                                             bit[3]: ctrl bus
//                                                                                                             bit[4]: vsync
//                                                                                                             bit[5]: hsync 0
//                                                                                                             bit[6]: hsync 1
//                                                                                                             bit[7]: hsync 2
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_DEBUG_FPGA_SENSOR_PROBE_0_SELECT_DEFAULT (0x01)
#define ACAMERA_FPGA_DEBUG_FPGA_SENSOR_PROBE_0_SELECT_DATASIZE (8)
#define ACAMERA_FPGA_DEBUG_FPGA_SENSOR_PROBE_0_SELECT_OFFSET (0xa8)
#define ACAMERA_FPGA_DEBUG_FPGA_SENSOR_PROBE_0_SELECT_MASK (0xff)

// args: data (8-bit)
static __inline void acamera_fpga_debug_fpga_sensor_probe_0_select_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2200a8L);
    system_hw_write_32(0x2200a8L, (((uint32_t) (data & 0xff)) << 0) | (curr & 0xffffff00));
}
static __inline uint8_t acamera_fpga_debug_fpga_sensor_probe_0_select_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2200a8L) & 0xff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: Sensor probe 1 select
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Logical OR with others selected
//                                                                                                             bit[0]: diff lane
//                                                                                                             bit[1]: diff clk locked
//                                                                                                             bit[2]: diff clk aligned
//                                                                                                             bit[3]: ctrl bus
//                                                                                                             bit[4]: vsync
//                                                                                                             bit[5]: hsync 0
//                                                                                                             bit[6]: hsync 1
//                                                                                                             bit[7]: hsync 2
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_DEBUG_FPGA_SENSOR_PROBE_1_SELECT_DEFAULT (0x08)
#define ACAMERA_FPGA_DEBUG_FPGA_SENSOR_PROBE_1_SELECT_DATASIZE (8)
#define ACAMERA_FPGA_DEBUG_FPGA_SENSOR_PROBE_1_SELECT_OFFSET (0xa8)
#define ACAMERA_FPGA_DEBUG_FPGA_SENSOR_PROBE_1_SELECT_MASK (0xff0000)

// args: data (8-bit)
static __inline void acamera_fpga_debug_fpga_sensor_probe_1_select_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2200a8L);
    system_hw_write_32(0x2200a8L, (((uint32_t) (data & 0xff)) << 16) | (curr & 0xff00ffff));
}
static __inline uint8_t acamera_fpga_debug_fpga_sensor_probe_1_select_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2200a8L) & 0xff0000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: Sensor probe 2 select
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Logical OR with others selected
//                                                                                                             bit[0]: diff lane
//                                                                                                             bit[1]: diff clk locked
//                                                                                                             bit[2]: diff clk aligned
//                                                                                                             bit[3]: ctrl bus
//                                                                                                             bit[4]: vsync
//                                                                                                             bit[5]: hsync 0
//                                                                                                             bit[6]: hsync 1
//                                                                                                             bit[7]: hsync 2
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_DEBUG_FPGA_SENSOR_PROBE_2_SELECT_DEFAULT (0x00)
#define ACAMERA_FPGA_DEBUG_FPGA_SENSOR_PROBE_2_SELECT_DATASIZE (8)
#define ACAMERA_FPGA_DEBUG_FPGA_SENSOR_PROBE_2_SELECT_OFFSET (0xac)
#define ACAMERA_FPGA_DEBUG_FPGA_SENSOR_PROBE_2_SELECT_MASK (0xff)

// args: data (8-bit)
static __inline void acamera_fpga_debug_fpga_sensor_probe_2_select_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2200acL);
    system_hw_write_32(0x2200acL, (((uint32_t) (data & 0xff)) << 0) | (curr & 0xffffff00));
}
static __inline uint8_t acamera_fpga_debug_fpga_sensor_probe_2_select_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2200acL) & 0xff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: Sensor probe 3 select
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Logical OR with others selected
//                                                                                                             bit[0]: diff lane
//                                                                                                             bit[1]: diff clk locked
//                                                                                                             bit[2]: diff clk aligned
//                                                                                                             bit[3]: ctrl bus
//                                                                                                             bit[4]: vsync
//                                                                                                             bit[5]: hsync 0
//                                                                                                             bit[6]: hsync 1
//                                                                                                             bit[7]: hsync 2
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_DEBUG_FPGA_SENSOR_PROBE_3_SELECT_DEFAULT (0x00)
#define ACAMERA_FPGA_DEBUG_FPGA_SENSOR_PROBE_3_SELECT_DATASIZE (8)
#define ACAMERA_FPGA_DEBUG_FPGA_SENSOR_PROBE_3_SELECT_OFFSET (0xac)
#define ACAMERA_FPGA_DEBUG_FPGA_SENSOR_PROBE_3_SELECT_MASK (0xff0000)

// args: data (8-bit)
static __inline void acamera_fpga_debug_fpga_sensor_probe_3_select_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2200acL);
    system_hw_write_32(0x2200acL, (((uint32_t) (data & 0xff)) << 16) | (curr & 0xff00ffff));
}
static __inline uint8_t acamera_fpga_debug_fpga_sensor_probe_3_select_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2200acL) & 0xff0000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: ISP probe 0 select input
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Logical OR with others selected
//                                                                                                             bit[0]: input vsync
//                                                                                                             bit[1]: input hsync
//                                                                                                             bit[2]: output vsync
//                                                                                                             bit[3]: output hsync
//                                                                                                             bit[4]: cfg write
//                                                                                                             bit[5]: irq
//                                                                                                             bit[6]: fr_axi_wvalid
//                                                                                                             bit[7]: fr_axi_wready
//                                                                                                             bit[8]: ds_axi_wvalid
//                                                                                                             bit[9]: ds_axi_wready
//                                                                                                             bit[10]: temp_axi_wvalid
//                                                                                                             bit[11]: temp_axi_wready
//                                                                                                             bit[12]: temp_axi_rvalid
//                                                                                                             bit[13]: temp_axi_rready
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_DEBUG_FPGA_ISP_PROBE_0_SELECT_INPUT_DEFAULT (0x00)
#define ACAMERA_FPGA_DEBUG_FPGA_ISP_PROBE_0_SELECT_INPUT_DATASIZE (14)
#define ACAMERA_FPGA_DEBUG_FPGA_ISP_PROBE_0_SELECT_INPUT_OFFSET (0xb0)
#define ACAMERA_FPGA_DEBUG_FPGA_ISP_PROBE_0_SELECT_INPUT_MASK (0x3fff)

// args: data (14-bit)
static __inline void acamera_fpga_debug_fpga_isp_probe_0_select_input_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x2200b0L);
    system_hw_write_32(0x2200b0L, (((uint32_t) (data & 0x3fff)) << 0) | (curr & 0xffffc000));
}
static __inline uint16_t acamera_fpga_debug_fpga_isp_probe_0_select_input_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x2200b0L) & 0x3fff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: ISP probe 1 select input
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Logical OR with others selected
//                                                                                                             bit[0]: input vsync
//                                                                                                             bit[1]: input hsync
//                                                                                                             bit[2]: output vsync
//                                                                                                             bit[3]: output hsync
//                                                                                                             bit[4]: cfg write
//                                                                                                             bit[5]: irq
//                                                                                                             bit[6]: fr_axi_wvalid
//                                                                                                             bit[7]: fr_axi_wready
//                                                                                                             bit[8]: ds_axi_wvalid
//                                                                                                             bit[9]: ds_axi_wready
//                                                                                                             bit[10]: temp_axi_wvalid
//                                                                                                             bit[11]: temp_axi_wready
//                                                                                                             bit[12]: temp_axi_rvalid
//                                                                                                             bit[13]: temp_axi_rready
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_DEBUG_FPGA_ISP_PROBE_1_SELECT_INPUT_DEFAULT (0x00)
#define ACAMERA_FPGA_DEBUG_FPGA_ISP_PROBE_1_SELECT_INPUT_DATASIZE (14)
#define ACAMERA_FPGA_DEBUG_FPGA_ISP_PROBE_1_SELECT_INPUT_OFFSET (0xb0)
#define ACAMERA_FPGA_DEBUG_FPGA_ISP_PROBE_1_SELECT_INPUT_MASK (0x3fff0000)

// args: data (14-bit)
static __inline void acamera_fpga_debug_fpga_isp_probe_1_select_input_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x2200b0L);
    system_hw_write_32(0x2200b0L, (((uint32_t) (data & 0x3fff)) << 16) | (curr & 0xc000ffff));
}
static __inline uint16_t acamera_fpga_debug_fpga_isp_probe_1_select_input_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x2200b0L) & 0x3fff0000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: ISP probe 2 select input
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Logical OR with others selected
//                                                                                                             bit[0]: input vsync
//                                                                                                             bit[1]: input hsync
//                                                                                                             bit[2]: output vsync
//                                                                                                             bit[3]: output hsync
//                                                                                                             bit[4]: cfg write
//                                                                                                             bit[5]: irq
//                                                                                                             bit[6]: fr_axi_wvalid
//                                                                                                             bit[7]: fr_axi_wready
//                                                                                                             bit[8]: ds_axi_wvalid
//                                                                                                             bit[9]: ds_axi_wready
//                                                                                                             bit[10]: temp_axi_wvalid
//                                                                                                             bit[11]: temp_axi_wready
//                                                                                                             bit[12]: temp_axi_rvalid
//                                                                                                             bit[13]: temp_axi_rready
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_DEBUG_FPGA_ISP_PROBE_2_SELECT_INPUT_DEFAULT (0x00)
#define ACAMERA_FPGA_DEBUG_FPGA_ISP_PROBE_2_SELECT_INPUT_DATASIZE (14)
#define ACAMERA_FPGA_DEBUG_FPGA_ISP_PROBE_2_SELECT_INPUT_OFFSET (0xb4)
#define ACAMERA_FPGA_DEBUG_FPGA_ISP_PROBE_2_SELECT_INPUT_MASK (0x3fff)

// args: data (14-bit)
static __inline void acamera_fpga_debug_fpga_isp_probe_2_select_input_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x2200b4L);
    system_hw_write_32(0x2200b4L, (((uint32_t) (data & 0x3fff)) << 0) | (curr & 0xffffc000));
}
static __inline uint16_t acamera_fpga_debug_fpga_isp_probe_2_select_input_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x2200b4L) & 0x3fff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: ISP probe 3 select input
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Logical OR with others selected
//                                                                                                             bit[0]: input vsync
//                                                                                                             bit[1]: input hsync
//                                                                                                             bit[2]: output vsync
//                                                                                                             bit[3]: output hsync
//                                                                                                             bit[4]: cfg write
//                                                                                                             bit[5]: irq
//                                                                                                             bit[6]: fr_axi_wvalid
//                                                                                                             bit[7]: fr_axi_wready
//                                                                                                             bit[8]: ds_axi_wvalid
//                                                                                                             bit[9]: ds_axi_wready
//                                                                                                             bit[10]: temp_axi_wvalid
//                                                                                                             bit[11]: temp_axi_wready
//                                                                                                             bit[12]: temp_axi_rvalid
//                                                                                                             bit[13]: temp_axi_rready
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_DEBUG_FPGA_ISP_PROBE_3_SELECT_INPUT_DEFAULT (0x00)
#define ACAMERA_FPGA_DEBUG_FPGA_ISP_PROBE_3_SELECT_INPUT_DATASIZE (14)
#define ACAMERA_FPGA_DEBUG_FPGA_ISP_PROBE_3_SELECT_INPUT_OFFSET (0xb4)
#define ACAMERA_FPGA_DEBUG_FPGA_ISP_PROBE_3_SELECT_INPUT_MASK (0x3fff0000)

// args: data (14-bit)
static __inline void acamera_fpga_debug_fpga_isp_probe_3_select_input_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x2200b4L);
    system_hw_write_32(0x2200b4L, (((uint32_t) (data & 0x3fff)) << 16) | (curr & 0xc000ffff));
}
static __inline uint16_t acamera_fpga_debug_fpga_isp_probe_3_select_input_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x2200b4L) & 0x3fff0000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: Debug pulse width
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Pulse width extension (debug_clk periods)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_DEBUG_FPGA_DEBUG_PULSE_WIDTH_DEFAULT (500000)
#define ACAMERA_FPGA_DEBUG_FPGA_DEBUG_PULSE_WIDTH_DATASIZE (32)
#define ACAMERA_FPGA_DEBUG_FPGA_DEBUG_PULSE_WIDTH_OFFSET (0xb8)
#define ACAMERA_FPGA_DEBUG_FPGA_DEBUG_PULSE_WIDTH_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_debug_fpga_debug_pulse_width_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x2200b8L, data);
}
static __inline uint32_t acamera_fpga_debug_fpga_debug_pulse_width_read(uintptr_t base) {
    return system_hw_read_32(0x2200b8L);
}
// ------------------------------------------------------------------------------ //
// Register: Debug probes polarity
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Each bit: 0 - not inverted, 1 - inverted
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_DEBUG_FPGA_DEBUG_PROBES_POLARITY_DEFAULT (0x02)
#define ACAMERA_FPGA_DEBUG_FPGA_DEBUG_PROBES_POLARITY_DATASIZE (4)
#define ACAMERA_FPGA_DEBUG_FPGA_DEBUG_PROBES_POLARITY_OFFSET (0xbc)
#define ACAMERA_FPGA_DEBUG_FPGA_DEBUG_PROBES_POLARITY_MASK (0xf)

// args: data (4-bit)
static __inline void acamera_fpga_debug_fpga_debug_probes_polarity_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2200bcL);
    system_hw_write_32(0x2200bcL, (((uint32_t) (data & 0xf)) << 0) | (curr & 0xfffffff0));
}
static __inline uint8_t acamera_fpga_debug_fpga_debug_probes_polarity_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2200bcL) & 0xf) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: Debug outputs polarity
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Each bit: 0 - not inverted, 1 - inverted
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_DEBUG_FPGA_DEBUG_OUTPUTS_POLARITY_DEFAULT (0x00)
#define ACAMERA_FPGA_DEBUG_FPGA_DEBUG_OUTPUTS_POLARITY_DATASIZE (4)
#define ACAMERA_FPGA_DEBUG_FPGA_DEBUG_OUTPUTS_POLARITY_OFFSET (0xbc)
#define ACAMERA_FPGA_DEBUG_FPGA_DEBUG_OUTPUTS_POLARITY_MASK (0xf0000)

// args: data (4-bit)
static __inline void acamera_fpga_debug_fpga_debug_outputs_polarity_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2200bcL);
    system_hw_write_32(0x2200bcL, (((uint32_t) (data & 0xf)) << 16) | (curr & 0xfff0ffff));
}
static __inline uint8_t acamera_fpga_debug_fpga_debug_outputs_polarity_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2200bcL) & 0xf0000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Group: Sony IMX290 Decoder
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Register: Sensor Reset
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Sensor reset, active low
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_DECODER_SENSOR_RESET_DEFAULT (1)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_SENSOR_RESET_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_SENSOR_RESET_OFFSET (0x100)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_SENSOR_RESET_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_decoder_sensor_reset_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220100L);
    system_hw_write_32(0x220100L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_sony_imx290_decoder_sensor_reset_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220100L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: Enable 4 channel
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Use only ch0..3 of 8 input differential data lines
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_DECODER_ENABLE_4_CHANNEL_DEFAULT (1)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_ENABLE_4_CHANNEL_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_ENABLE_4_CHANNEL_OFFSET (0x100)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_ENABLE_4_CHANNEL_MASK (0x2)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_decoder_enable_4_channel_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220100L);
    system_hw_write_32(0x220100L, (((uint32_t) (data & 0x1)) << 1) | (curr & 0xfffffffd));
}
static __inline uint8_t acamera_fpga_sony_imx290_decoder_enable_4_channel_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220100L) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: Enable 10 bit
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 10 bit data, othervise 12 bits
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_DECODER_ENABLE_10_BIT_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_ENABLE_10_BIT_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_ENABLE_10_BIT_OFFSET (0x100)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_ENABLE_10_BIT_MASK (0x4)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_decoder_enable_10_bit_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220100L);
    system_hw_write_32(0x220100L, (((uint32_t) (data & 0x1)) << 2) | (curr & 0xfffffffb));
}
static __inline uint8_t acamera_fpga_sony_imx290_decoder_enable_10_bit_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220100L) & 0x4) >> 2);
}
// ------------------------------------------------------------------------------ //
// Register: FIFO watermark
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Watermark to start data out
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_DECODER_FIFO_WATERMARK_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_FIFO_WATERMARK_DATASIZE (10)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_FIFO_WATERMARK_OFFSET (0x100)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_FIFO_WATERMARK_MASK (0x3ff0000)

// args: data (10-bit)
static __inline void acamera_fpga_sony_imx290_decoder_fifo_watermark_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220100L);
    system_hw_write_32(0x220100L, (((uint32_t) (data & 0x3ff)) << 16) | (curr & 0xfc00ffff));
}
static __inline uint16_t acamera_fpga_sony_imx290_decoder_fifo_watermark_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220100L) & 0x3ff0000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: Clear stats
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Clear sensor statistics
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_DECODER_CLEAR_STATS_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_CLEAR_STATS_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_CLEAR_STATS_OFFSET (0x104)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_CLEAR_STATS_MASK (0x100)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_decoder_clear_stats_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220104L);
    system_hw_write_32(0x220104L, (((uint32_t) (data & 0x1)) << 8) | (curr & 0xfffffeff));
}
static __inline uint8_t acamera_fpga_sony_imx290_decoder_clear_stats_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220104L) & 0x100) >> 8);
}
// ------------------------------------------------------------------------------ //
// Register: DOL 0th present
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Video stream: 1 = present, 0 = not present
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_DECODER_DOL_0TH_PRESENT_DEFAULT (0x0)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_DOL_0TH_PRESENT_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_DOL_0TH_PRESENT_OFFSET (0x104)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_DOL_0TH_PRESENT_MASK (0x20000)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_sony_imx290_decoder_dol_0th_present_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220104L) & 0x20000) >> 17);
}
// ------------------------------------------------------------------------------ //
// Register: DOL 1th present
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Video stream: 1 = present, 0 = not present
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_DECODER_DOL_1TH_PRESENT_DEFAULT (0x0)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_DOL_1TH_PRESENT_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_DOL_1TH_PRESENT_OFFSET (0x104)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_DOL_1TH_PRESENT_MASK (0x40000)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_sony_imx290_decoder_dol_1th_present_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220104L) & 0x40000) >> 18);
}
// ------------------------------------------------------------------------------ //
// Register: DOL 2th present
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Video stream: 1 = present, 0 = not present
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_DECODER_DOL_2TH_PRESENT_DEFAULT (0x0)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_DOL_2TH_PRESENT_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_DOL_2TH_PRESENT_OFFSET (0x104)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_DOL_2TH_PRESENT_MASK (0x80000)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_sony_imx290_decoder_dol_2th_present_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220104L) & 0x80000) >> 19);
}
// ------------------------------------------------------------------------------ //
// Register: LVDS Realign
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Realign FPGA PLL to LVDS clock, active high
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_DECODER_LVDS_REALIGN_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_LVDS_REALIGN_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_LVDS_REALIGN_OFFSET (0x108)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_LVDS_REALIGN_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_decoder_lvds_realign_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220108L);
    system_hw_write_32(0x220108L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_sony_imx290_decoder_lvds_realign_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220108L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: LVDS Locked
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// FPGA PLL locked to sensor LVDS clock
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_DECODER_LVDS_LOCKED_DEFAULT (0x0)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_LVDS_LOCKED_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_LVDS_LOCKED_OFFSET (0x108)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_LVDS_LOCKED_MASK (0x100)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_sony_imx290_decoder_lvds_locked_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220108L) & 0x100) >> 8);
}
// ------------------------------------------------------------------------------ //
// Register: LVDS Aligned
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// FPGA PLL locked and aligned to sensor LVDS clock
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_DECODER_LVDS_ALIGNED_DEFAULT (0x0)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_LVDS_ALIGNED_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_LVDS_ALIGNED_OFFSET (0x108)
#define ACAMERA_FPGA_SONY_IMX290_DECODER_LVDS_ALIGNED_MASK (0x200)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_sony_imx290_decoder_lvds_aligned_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220108L) & 0x200) >> 9);
}
// ------------------------------------------------------------------------------ //
// Group: Sony IMX290 Input port
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Register: preset
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 
//        Allows selection of various input port presets for standard sensor inputs.  See ISP Guide for details of available presets.
//        0-14: Frequently used presets.  If using one of available presets, remaining bits in registers 0x100 and 0x104 are not used.
//        15:   Input port configured according to registers in 0x100 and 0x104.  Consult Apical support for special input port requirements.
//      
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_PRESET_DEFAULT (2)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_PRESET_DATASIZE (4)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_PRESET_OFFSET (0x140)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_PRESET_MASK (0xf)

// args: data (4-bit)
static __inline void acamera_fpga_sony_imx290_input_port_preset_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220140L);
    system_hw_write_32(0x220140L, (((uint32_t) (data & 0xf)) << 0) | (curr & 0xfffffff0));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_preset_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220140L) & 0xf) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: vs_use field
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VS_USE_FIELD_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VS_USE_FIELD_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VS_USE_FIELD_OFFSET (0x140)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VS_USE_FIELD_MASK (0x100)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VS_USE_FIELD_USE_VSYNC_I_PORT_FOR_VERTICAL_SYNC (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VS_USE_FIELD_USE_FIELD_I_PORT_FOR_VERTICAL_SYNC (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_vs_use_field_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220140L);
    system_hw_write_32(0x220140L, (((uint32_t) (data & 0x1)) << 8) | (curr & 0xfffffeff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_vs_use_field_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220140L) & 0x100) >> 8);
}
// ------------------------------------------------------------------------------ //
// Register: vs toggle
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VS_TOGGLE_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VS_TOGGLE_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VS_TOGGLE_OFFSET (0x140)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VS_TOGGLE_MASK (0x200)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VS_TOGGLE_VSYNC_IS_PULSETYPE (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VS_TOGGLE_VSYNC_IS_TOGGLETYPE_FIELD_SIGNAL (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_vs_toggle_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220140L);
    system_hw_write_32(0x220140L, (((uint32_t) (data & 0x1)) << 9) | (curr & 0xfffffdff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_vs_toggle_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220140L) & 0x200) >> 9);
}
// ------------------------------------------------------------------------------ //
// Register: vs polarity
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VS_POLARITY_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VS_POLARITY_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VS_POLARITY_OFFSET (0x140)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VS_POLARITY_MASK (0x400)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VS_POLARITY_HORIZONTAL_COUNTER_RESET_ON_RISING_EDGE (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VS_POLARITY_HORIZONTAL_COUNTER_RESET_ON_FALLING_EDGE (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_vs_polarity_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220140L);
    system_hw_write_32(0x220140L, (((uint32_t) (data & 0x1)) << 10) | (curr & 0xfffffbff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_vs_polarity_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220140L) & 0x400) >> 10);
}
// ------------------------------------------------------------------------------ //
// Register: vs_polarity acl
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VS_POLARITY_ACL_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VS_POLARITY_ACL_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VS_POLARITY_ACL_OFFSET (0x140)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VS_POLARITY_ACL_MASK (0x800)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VS_POLARITY_ACL_DONT_INVERT_POLARITY_FOR_ACL_GATE (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VS_POLARITY_ACL_INVERT_POLARITY_FOR_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_vs_polarity_acl_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220140L);
    system_hw_write_32(0x220140L, (((uint32_t) (data & 0x1)) << 11) | (curr & 0xfffff7ff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_vs_polarity_acl_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220140L) & 0x800) >> 11);
}
// ------------------------------------------------------------------------------ //
// Register: hs_use acl
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_USE_ACL_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_USE_ACL_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_USE_ACL_OFFSET (0x140)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_USE_ACL_MASK (0x1000)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_USE_ACL_USE_HSYNC_I_PORT_FOR_ACTIVELINE (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_USE_ACL_USE_ACL_I_PORT_FOR_ACTIVELINE (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_hs_use_acl_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220140L);
    system_hw_write_32(0x220140L, (((uint32_t) (data & 0x1)) << 12) | (curr & 0xffffefff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_hs_use_acl_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220140L) & 0x1000) >> 12);
}
// ------------------------------------------------------------------------------ //
// Register: vc_c select
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VC_C_SELECT_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VC_C_SELECT_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VC_C_SELECT_OFFSET (0x140)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VC_C_SELECT_MASK (0x4000)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VC_C_SELECT_VERTICAL_COUNTER_COUNTS_ON_HS (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VC_C_SELECT_VERTICAL_COUNTER_COUNTS_ON_HORIZONTAL_COUNTER_OVERFLOW_OR_RESET (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_vc_c_select_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220140L);
    system_hw_write_32(0x220140L, (((uint32_t) (data & 0x1)) << 14) | (curr & 0xffffbfff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_vc_c_select_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220140L) & 0x4000) >> 14);
}
// ------------------------------------------------------------------------------ //
// Register: vc_r select
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VC_R_SELECT_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VC_R_SELECT_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VC_R_SELECT_OFFSET (0x140)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VC_R_SELECT_MASK (0x8000)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VC_R_SELECT_VERTICAL_COUNTER_IS_RESET_ON_EDGE_OF_VS (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VC_R_SELECT_VERTICAL_COUNTER_IS_RESET_AFTER_TIMEOUT_ON_HS (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_vc_r_select_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220140L);
    system_hw_write_32(0x220140L, (((uint32_t) (data & 0x1)) << 15) | (curr & 0xffff7fff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_vc_r_select_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220140L) & 0x8000) >> 15);
}
// ------------------------------------------------------------------------------ //
// Register: hs_xor vs
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_XOR_VS_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_XOR_VS_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_XOR_VS_OFFSET (0x140)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_XOR_VS_MASK (0x10000)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_XOR_VS_NORMAL_MODE (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_XOR_VS_HVALID__HSYNC_XOR_VSYNC (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_hs_xor_vs_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220140L);
    system_hw_write_32(0x220140L, (((uint32_t) (data & 0x1)) << 16) | (curr & 0xfffeffff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_hs_xor_vs_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220140L) & 0x10000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: hs polarity
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_POLARITY_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_POLARITY_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_POLARITY_OFFSET (0x140)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_POLARITY_MASK (0x20000)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_POLARITY_DONT_INVERT_POLARITY_OF_HS_FOR_ACL_GATE (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_POLARITY_INVERT_POLARITY_OF_HS_FOR_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_hs_polarity_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220140L);
    system_hw_write_32(0x220140L, (((uint32_t) (data & 0x1)) << 17) | (curr & 0xfffdffff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_hs_polarity_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220140L) & 0x20000) >> 17);
}
// ------------------------------------------------------------------------------ //
// Register: hs_polarity acl
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_POLARITY_ACL_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_POLARITY_ACL_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_POLARITY_ACL_OFFSET (0x140)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_POLARITY_ACL_MASK (0x40000)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_POLARITY_ACL_DONT_INVERT_POLARITY_OF_HS_FOR_HS_GATE (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_POLARITY_ACL_INVERT_POLARITY_OF_HS_FOR_HS_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_hs_polarity_acl_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220140L);
    system_hw_write_32(0x220140L, (((uint32_t) (data & 0x1)) << 18) | (curr & 0xfffbffff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_hs_polarity_acl_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220140L) & 0x40000) >> 18);
}
// ------------------------------------------------------------------------------ //
// Register: hs_polarity hs
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_POLARITY_HS_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_POLARITY_HS_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_POLARITY_HS_OFFSET (0x140)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_POLARITY_HS_MASK (0x80000)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_POLARITY_HS_HORIZONTAL_COUNTER_IS_RESET_ON_RISING_EDGE_OF_HS (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_POLARITY_HS_HORIZONTAL_COUNTER_IS_RESET_ON_VSYNC_EG_WHEN_HSYNC_IS_NOT_AVAILABLE (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_hs_polarity_hs_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220140L);
    system_hw_write_32(0x220140L, (((uint32_t) (data & 0x1)) << 19) | (curr & 0xfff7ffff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_hs_polarity_hs_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220140L) & 0x80000) >> 19);
}
// ------------------------------------------------------------------------------ //
// Register: hs_polarity vc
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_POLARITY_VC_DEFAULT (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_POLARITY_VC_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_POLARITY_VC_OFFSET (0x140)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_POLARITY_VC_MASK (0x100000)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_POLARITY_VC_VERTICAL_COUNTER_INCREMENTS_ON_RISING_EDGE_OF_HS (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HS_POLARITY_VC_VERTICAL_COUNTER_INCREMENTS_ON_FALLING_EDGE_OF_HS (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_hs_polarity_vc_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220140L);
    system_hw_write_32(0x220140L, (((uint32_t) (data & 0x1)) << 20) | (curr & 0xffefffff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_hs_polarity_vc_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220140L) & 0x100000) >> 20);
}
// ------------------------------------------------------------------------------ //
// Register: hc_r select
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HC_R_SELECT_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HC_R_SELECT_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HC_R_SELECT_OFFSET (0x140)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HC_R_SELECT_MASK (0x800000)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HC_R_SELECT_VERTICAL_COUNTER_IS_RESET_ON_RISING_EDGE_OF_HS (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HC_R_SELECT_VERTICAL_COUNTER_IS_RESET_ON_RISING_EDGE_OF_VS (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_hc_r_select_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220140L);
    system_hw_write_32(0x220140L, (((uint32_t) (data & 0x1)) << 23) | (curr & 0xff7fffff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_hc_r_select_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220140L) & 0x800000) >> 23);
}
// ------------------------------------------------------------------------------ //
// Register: acl polarity
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACL_POLARITY_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACL_POLARITY_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACL_POLARITY_OFFSET (0x140)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACL_POLARITY_MASK (0x1000000)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACL_POLARITY_DONT_INVERT_ACL_I_FOR_ACL_GATE (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACL_POLARITY_INVERT_ACL_I_FOR_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_acl_polarity_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220140L);
    system_hw_write_32(0x220140L, (((uint32_t) (data & 0x1)) << 24) | (curr & 0xfeffffff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_acl_polarity_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220140L) & 0x1000000) >> 24);
}
// ------------------------------------------------------------------------------ //
// Register: field polarity
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELD_POLARITY_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELD_POLARITY_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELD_POLARITY_OFFSET (0x144)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELD_POLARITY_MASK (0x1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELD_POLARITY_DONT_INVERT_FIELD_I_FOR_FIELD_GATE (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELD_POLARITY_INVERT_FIELD_I_FOR_FIELD_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_field_polarity_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220144L);
    system_hw_write_32(0x220144L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_field_polarity_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220144L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: field toggle
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELD_TOGGLE_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELD_TOGGLE_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELD_TOGGLE_OFFSET (0x144)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELD_TOGGLE_MASK (0x2)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELD_TOGGLE_FIELD_IS_PULSETYPE (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELD_TOGGLE_FIELD_IS_TOGGLETYPE (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_field_toggle_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220144L);
    system_hw_write_32(0x220144L, (((uint32_t) (data & 0x1)) << 1) | (curr & 0xfffffffd));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_field_toggle_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220144L) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: aclg window0
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_WINDOW0_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_WINDOW0_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_WINDOW0_OFFSET (0x144)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_WINDOW0_MASK (0x100)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_WINDOW0_EXCLUDE_WINDOW0_SIGNAL_IN_ACL_GATE (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_WINDOW0_INCLUDE_WINDOW0_SIGNAL_IN_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_aclg_window0_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220144L);
    system_hw_write_32(0x220144L, (((uint32_t) (data & 0x1)) << 8) | (curr & 0xfffffeff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_aclg_window0_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220144L) & 0x100) >> 8);
}
// ------------------------------------------------------------------------------ //
// Register: aclg hsync
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_HSYNC_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_HSYNC_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_HSYNC_OFFSET (0x144)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_HSYNC_MASK (0x200)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_HSYNC_EXCLUDE_HSYNC_SIGNAL_IN_ACL_GATE (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_HSYNC_INCLUDE_HSYNC_SIGNAL_IN_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_aclg_hsync_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220144L);
    system_hw_write_32(0x220144L, (((uint32_t) (data & 0x1)) << 9) | (curr & 0xfffffdff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_aclg_hsync_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220144L) & 0x200) >> 9);
}
// ------------------------------------------------------------------------------ //
// Register: aclg window2
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_WINDOW2_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_WINDOW2_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_WINDOW2_OFFSET (0x144)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_WINDOW2_MASK (0x400)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_WINDOW2_EXCLUDE_WINDOW2_SIGNAL_IN_ACL_GATE (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_WINDOW2_INCLUDE_WINDOW2_SIGNAL_IN_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_aclg_window2_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220144L);
    system_hw_write_32(0x220144L, (((uint32_t) (data & 0x1)) << 10) | (curr & 0xfffffbff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_aclg_window2_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220144L) & 0x400) >> 10);
}
// ------------------------------------------------------------------------------ //
// Register: aclg acl
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_ACL_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_ACL_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_ACL_OFFSET (0x144)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_ACL_MASK (0x800)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_ACL_EXCLUDE_ACL_I_SIGNAL_IN_ACL_GATE (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_ACL_INCLUDE_ACL_I_SIGNAL_IN_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_aclg_acl_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220144L);
    system_hw_write_32(0x220144L, (((uint32_t) (data & 0x1)) << 11) | (curr & 0xfffff7ff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_aclg_acl_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220144L) & 0x800) >> 11);
}
// ------------------------------------------------------------------------------ //
// Register: aclg vsync
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_VSYNC_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_VSYNC_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_VSYNC_OFFSET (0x144)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_VSYNC_MASK (0x1000)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_VSYNC_EXCLUDE_VSYNC_SIGNAL_IN_ACL_GATE (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_ACLG_VSYNC_INCLUDE_VSYNC_SIGNAL_IN_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_aclg_vsync_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220144L);
    system_hw_write_32(0x220144L, (((uint32_t) (data & 0x1)) << 12) | (curr & 0xffffefff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_aclg_vsync_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220144L) & 0x1000) >> 12);
}
// ------------------------------------------------------------------------------ //
// Register: hsg window1
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HSG_WINDOW1_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HSG_WINDOW1_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HSG_WINDOW1_OFFSET (0x144)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HSG_WINDOW1_MASK (0x10000)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HSG_WINDOW1_EXCLUDE_WINDOW1_SIGNAL_IN_HS_GATE (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HSG_WINDOW1_INCLUDE_WINDOW1_SIGNAL_IN_HS_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_hsg_window1_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220144L);
    system_hw_write_32(0x220144L, (((uint32_t) (data & 0x1)) << 16) | (curr & 0xfffeffff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_hsg_window1_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220144L) & 0x10000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: hsg hsync
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HSG_HSYNC_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HSG_HSYNC_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HSG_HSYNC_OFFSET (0x144)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HSG_HSYNC_MASK (0x20000)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HSG_HSYNC_EXCLUDE_HSYNC_SIGNAL_IN_HS_GATE (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HSG_HSYNC_INCLUDE_HSYNC_SIGNAL_IN_HS_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_hsg_hsync_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220144L);
    system_hw_write_32(0x220144L, (((uint32_t) (data & 0x1)) << 17) | (curr & 0xfffdffff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_hsg_hsync_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220144L) & 0x20000) >> 17);
}
// ------------------------------------------------------------------------------ //
// Register: hsg vsync
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HSG_VSYNC_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HSG_VSYNC_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HSG_VSYNC_OFFSET (0x144)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HSG_VSYNC_MASK (0x40000)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HSG_VSYNC_EXCLUDE_VSYNC_SIGNAL_IN_HS_GATE (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HSG_VSYNC_INCLUDE_VSYNC_SIGNAL_IN_HS_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_hsg_vsync_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220144L);
    system_hw_write_32(0x220144L, (((uint32_t) (data & 0x1)) << 18) | (curr & 0xfffbffff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_hsg_vsync_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220144L) & 0x40000) >> 18);
}
// ------------------------------------------------------------------------------ //
// Register: hsg window2
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HSG_WINDOW2_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HSG_WINDOW2_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HSG_WINDOW2_OFFSET (0x144)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HSG_WINDOW2_MASK (0x80000)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HSG_WINDOW2_EXCLUDE_WINDOW2_SIGNAL_IN_HS_GATE (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HSG_WINDOW2_INCLUDE_WINDOW2_SIGNAL_IN_HS_GATE_MASK_OUT_SPURIOUS_HS_DURING_BLANK (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_hsg_window2_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220144L);
    system_hw_write_32(0x220144L, (((uint32_t) (data & 0x1)) << 19) | (curr & 0xfff7ffff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_hsg_window2_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220144L) & 0x80000) >> 19);
}
// ------------------------------------------------------------------------------ //
// Register: fieldg vsync
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELDG_VSYNC_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELDG_VSYNC_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELDG_VSYNC_OFFSET (0x144)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELDG_VSYNC_MASK (0x1000000)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELDG_VSYNC_EXCLUDE_VSYNC_SIGNAL_IN_FIELD_GATE (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELDG_VSYNC_INCLUDE_VSYNC_SIGNAL_IN_FIELD_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_fieldg_vsync_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220144L);
    system_hw_write_32(0x220144L, (((uint32_t) (data & 0x1)) << 24) | (curr & 0xfeffffff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_fieldg_vsync_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220144L) & 0x1000000) >> 24);
}
// ------------------------------------------------------------------------------ //
// Register: fieldg window2
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELDG_WINDOW2_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELDG_WINDOW2_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELDG_WINDOW2_OFFSET (0x144)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELDG_WINDOW2_MASK (0x2000000)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELDG_WINDOW2_EXCLUDE_WINDOW2_SIGNAL_IN_FIELD_GATE (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELDG_WINDOW2_INCLUDE_WINDOW2_SIGNAL_IN_FIELD_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_fieldg_window2_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220144L);
    system_hw_write_32(0x220144L, (((uint32_t) (data & 0x1)) << 25) | (curr & 0xfdffffff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_fieldg_window2_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220144L) & 0x2000000) >> 25);
}
// ------------------------------------------------------------------------------ //
// Register: fieldg field
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELDG_FIELD_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELDG_FIELD_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELDG_FIELD_OFFSET (0x144)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELDG_FIELD_MASK (0x4000000)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELDG_FIELD_EXCLUDE_FIELD_I_SIGNAL_IN_FIELD_GATE (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELDG_FIELD_INCLUDE_FIELD_I_SIGNAL_IN_FIELD_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_fieldg_field_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220144L);
    system_hw_write_32(0x220144L, (((uint32_t) (data & 0x1)) << 26) | (curr & 0xfbffffff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_fieldg_field_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220144L) & 0x4000000) >> 26);
}
// ------------------------------------------------------------------------------ //
// Register: field mode
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELD_MODE_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELD_MODE_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELD_MODE_OFFSET (0x144)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELD_MODE_MASK (0x8000000)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELD_MODE_PULSE_FIELD (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FIELD_MODE_TOGGLE_FIELD (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_field_mode_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220144L);
    system_hw_write_32(0x220144L, (((uint32_t) (data & 0x1)) << 27) | (curr & 0xf7ffffff));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_field_mode_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220144L) & 0x8000000) >> 27);
}
// ------------------------------------------------------------------------------ //
// Register: hc limit
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// horizontal counter limit value (counts: 0,1,...hc_limit-1,hc_limit,0,1,...)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HC_LIMIT_DEFAULT (0xFFFF)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HC_LIMIT_DATASIZE (16)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HC_LIMIT_OFFSET (0x148)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HC_LIMIT_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_sony_imx290_input_port_hc_limit_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220148L);
    system_hw_write_32(0x220148L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_sony_imx290_input_port_hc_limit_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220148L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: hc start0
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// window0 start for ACL gate.  See ISP guide for further details.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HC_START0_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HC_START0_DATASIZE (16)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HC_START0_OFFSET (0x14c)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HC_START0_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_sony_imx290_input_port_hc_start0_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x22014cL);
    system_hw_write_32(0x22014cL, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_sony_imx290_input_port_hc_start0_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x22014cL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: hc size0
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// window0 size for ACL gate.  See ISP guide for further details.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HC_SIZE0_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HC_SIZE0_DATASIZE (16)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HC_SIZE0_OFFSET (0x150)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HC_SIZE0_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_sony_imx290_input_port_hc_size0_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220150L);
    system_hw_write_32(0x220150L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_sony_imx290_input_port_hc_size0_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220150L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: hc start1
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// window1 start for HS gate.  See ISP guide for further details.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HC_START1_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HC_START1_DATASIZE (16)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HC_START1_OFFSET (0x154)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HC_START1_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_sony_imx290_input_port_hc_start1_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220154L);
    system_hw_write_32(0x220154L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_sony_imx290_input_port_hc_start1_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220154L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: hc size1
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// window1 size for HS gate.  See ISP guide for further details.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HC_SIZE1_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HC_SIZE1_DATASIZE (16)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HC_SIZE1_OFFSET (0x158)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_HC_SIZE1_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_sony_imx290_input_port_hc_size1_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220158L);
    system_hw_write_32(0x220158L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_sony_imx290_input_port_hc_size1_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220158L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: vc limit
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// vertical counter limit value (counts: 0,1,...vc_limit-1,vc_limit,0,1,...)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VC_LIMIT_DEFAULT (0xFFFF)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VC_LIMIT_DATASIZE (16)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VC_LIMIT_OFFSET (0x15c)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VC_LIMIT_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_sony_imx290_input_port_vc_limit_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x22015cL);
    system_hw_write_32(0x22015cL, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_sony_imx290_input_port_vc_limit_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x22015cL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: vc start
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// window2 start for ACL gate.  See ISP guide for further details.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VC_START_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VC_START_DATASIZE (16)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VC_START_OFFSET (0x160)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VC_START_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_sony_imx290_input_port_vc_start_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220160L);
    system_hw_write_32(0x220160L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_sony_imx290_input_port_vc_start_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220160L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: vc size
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// window2 size for ACL gate.  See ISP guide for further details.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VC_SIZE_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VC_SIZE_DATASIZE (16)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VC_SIZE_OFFSET (0x164)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_VC_SIZE_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_sony_imx290_input_port_vc_size_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220164L);
    system_hw_write_32(0x220164L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_sony_imx290_input_port_vc_size_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220164L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: frame width
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// detected frame width.  Read only value.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FRAME_WIDTH_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FRAME_WIDTH_DATASIZE (16)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FRAME_WIDTH_OFFSET (0x168)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FRAME_WIDTH_MASK (0xffff)

// args: data (16-bit)
static __inline uint16_t acamera_fpga_sony_imx290_input_port_frame_width_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220168L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: frame height
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// detected frame height.  Read only value.  
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FRAME_HEIGHT_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FRAME_HEIGHT_DATASIZE (16)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FRAME_HEIGHT_OFFSET (0x16c)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FRAME_HEIGHT_MASK (0xffff)

// args: data (16-bit)
static __inline uint16_t acamera_fpga_sony_imx290_input_port_frame_height_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x22016cL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: mode request
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Used to stop and start input port.  See ISP guide for further details. 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_MODE_REQUEST_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_MODE_REQUEST_DATASIZE (3)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_MODE_REQUEST_OFFSET (0x170)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_MODE_REQUEST_MASK (0x7)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_MODE_REQUEST_SAFE_STOP (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_MODE_REQUEST_SAFE_START (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_MODE_REQUEST_URGENT_STOP (2)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_MODE_REQUEST_URGENT_START (3)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_MODE_REQUEST_RESERVED4 (4)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_MODE_REQUEST_SAFER_START (5)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_MODE_REQUEST_RESERVED6 (6)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_MODE_REQUEST_RESERVED7 (7)

// args: data (3-bit)
static __inline void acamera_fpga_sony_imx290_input_port_mode_request_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220170L);
    system_hw_write_32(0x220170L, (((uint32_t) (data & 0x7)) << 0) | (curr & 0xfffffff8));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_mode_request_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220170L) & 0x7) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: freeze config
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Used to freeze input port configuration.  Used when multiple register writes are required to change input port configuration. 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FREEZE_CONFIG_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FREEZE_CONFIG_DATASIZE (1)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FREEZE_CONFIG_OFFSET (0x170)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FREEZE_CONFIG_MASK (0x80)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FREEZE_CONFIG_NORMAL_OPERATION (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_FREEZE_CONFIG_HOLD_PREVIOUS_INPUT_PORT_CONFIG_STATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_sony_imx290_input_port_freeze_config_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220170L);
    system_hw_write_32(0x220170L, (((uint32_t) (data & 0x1)) << 7) | (curr & 0xffffff7f));
}
static __inline uint8_t acamera_fpga_sony_imx290_input_port_freeze_config_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220170L) & 0x80) >> 7);
}
// ------------------------------------------------------------------------------ //
// Register: mode status
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 
//          Used to monitor input port status:
//          bit 0: 1=running, 0=stopped, bits 1,2-reserved
//        
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_MODE_STATUS_DEFAULT (0)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_MODE_STATUS_DATASIZE (3)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_MODE_STATUS_OFFSET (0x174)
#define ACAMERA_FPGA_SONY_IMX290_INPUT_PORT_MODE_STATUS_MASK (0x7)

// args: data (3-bit)
static __inline uint8_t acamera_fpga_sony_imx290_input_port_mode_status_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220174L) & 0x7) >> 0);
}
// ------------------------------------------------------------------------------ //
// Group: FPGA WDR multiplexor
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Register: Master Channel
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Master input channel
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_MASTER_CHANNEL_DEFAULT (0)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_MASTER_CHANNEL_DATASIZE (3)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_MASTER_CHANNEL_OFFSET (0x520)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_MASTER_CHANNEL_MASK (0x7)

// args: data (3-bit)
static __inline void acamera_fpga_fpga_wdr_multiplexor_master_channel_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220520L);
    system_hw_write_32(0x220520L, (((uint32_t) (data & 0x7)) << 0) | (curr & 0xfffffff8));
}
static __inline uint8_t acamera_fpga_fpga_wdr_multiplexor_master_channel_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220520L) & 0x7) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: Buffer1 Channel
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Input channel for buffer 1
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_BUFFER1_CHANNEL_DEFAULT (3)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_BUFFER1_CHANNEL_DATASIZE (3)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_BUFFER1_CHANNEL_OFFSET (0x520)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_BUFFER1_CHANNEL_MASK (0x700)

// args: data (3-bit)
static __inline void acamera_fpga_fpga_wdr_multiplexor_buffer1_channel_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220520L);
    system_hw_write_32(0x220520L, (((uint32_t) (data & 0x7)) << 8) | (curr & 0xfffff8ff));
}
static __inline uint8_t acamera_fpga_fpga_wdr_multiplexor_buffer1_channel_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220520L) & 0x700) >> 8);
}
// ------------------------------------------------------------------------------ //
// Register: Buffer2 Channel
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Input channel for buffer 2
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_BUFFER2_CHANNEL_DEFAULT (3)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_BUFFER2_CHANNEL_DATASIZE (3)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_BUFFER2_CHANNEL_OFFSET (0x520)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_BUFFER2_CHANNEL_MASK (0x70000)

// args: data (3-bit)
static __inline void acamera_fpga_fpga_wdr_multiplexor_buffer2_channel_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220520L);
    system_hw_write_32(0x220520L, (((uint32_t) (data & 0x7)) << 16) | (curr & 0xfff8ffff));
}
static __inline uint8_t acamera_fpga_fpga_wdr_multiplexor_buffer2_channel_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220520L) & 0x70000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: Buffer3 Channel
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Input channel for buffer 3
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_BUFFER3_CHANNEL_DEFAULT (3)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_BUFFER3_CHANNEL_DATASIZE (3)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_BUFFER3_CHANNEL_OFFSET (0x520)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_BUFFER3_CHANNEL_MASK (0x7000000)

// args: data (3-bit)
static __inline void acamera_fpga_fpga_wdr_multiplexor_buffer3_channel_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220520L);
    system_hw_write_32(0x220520L, (((uint32_t) (data & 0x7)) << 24) | (curr & 0xf8ffffff));
}
static __inline uint8_t acamera_fpga_fpga_wdr_multiplexor_buffer3_channel_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220520L) & 0x7000000) >> 24);
}
// ------------------------------------------------------------------------------ //
// Register: Current Channel
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Override input channel
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_CURRENT_CHANNEL_DEFAULT (0)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_CURRENT_CHANNEL_DATASIZE (3)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_CURRENT_CHANNEL_OFFSET (0x524)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_CURRENT_CHANNEL_MASK (0x7)

// args: data (3-bit)
static __inline void acamera_fpga_fpga_wdr_multiplexor_current_channel_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220524L);
    system_hw_write_32(0x220524L, (((uint32_t) (data & 0x7)) << 0) | (curr & 0xfffffff8));
}
static __inline uint8_t acamera_fpga_fpga_wdr_multiplexor_current_channel_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220524L) & 0x7) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: Current Channel out
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Override input channel
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_CURRENT_CHANNEL_OUT_DEFAULT (0x0)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_CURRENT_CHANNEL_OUT_DATASIZE (2)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_CURRENT_CHANNEL_OUT_OFFSET (0x524)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_CURRENT_CHANNEL_OUT_MASK (0x300)

// args: data (2-bit)
static __inline uint8_t acamera_fpga_fpga_wdr_multiplexor_current_channel_out_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220524L) & 0x300) >> 8);
}
// ------------------------------------------------------------------------------ //
// Register: Master Gain
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Output gain for channel, format uint8.8
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_MASTER_GAIN_DEFAULT (0x100)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_MASTER_GAIN_DATASIZE (16)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_MASTER_GAIN_OFFSET (0x528)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_MASTER_GAIN_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_fpga_wdr_multiplexor_master_gain_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220528L);
    system_hw_write_32(0x220528L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_fpga_wdr_multiplexor_master_gain_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220528L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: Buffer1 Gain
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Output gain for channel, format uint8.8
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_BUFFER1_GAIN_DEFAULT (0x100)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_BUFFER1_GAIN_DATASIZE (16)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_BUFFER1_GAIN_OFFSET (0x528)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_BUFFER1_GAIN_MASK (0xffff0000)

// args: data (16-bit)
static __inline void acamera_fpga_fpga_wdr_multiplexor_buffer1_gain_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220528L);
    system_hw_write_32(0x220528L, (((uint32_t) (data & 0xffff)) << 16) | (curr & 0xffff));
}
static __inline uint16_t acamera_fpga_fpga_wdr_multiplexor_buffer1_gain_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220528L) & 0xffff0000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: Buffer2 Gain
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Output gain for channel, format uint8.8
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_BUFFER2_GAIN_DEFAULT (0x100)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_BUFFER2_GAIN_DATASIZE (16)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_BUFFER2_GAIN_OFFSET (0x52c)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_BUFFER2_GAIN_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_fpga_wdr_multiplexor_buffer2_gain_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x22052cL);
    system_hw_write_32(0x22052cL, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_fpga_wdr_multiplexor_buffer2_gain_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x22052cL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: Buffer3 Gain
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Output gain for channel, format uint8.8
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_BUFFER3_GAIN_DEFAULT (0x100)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_BUFFER3_GAIN_DATASIZE (16)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_BUFFER3_GAIN_OFFSET (0x52c)
#define ACAMERA_FPGA_FPGA_WDR_MULTIPLEXOR_BUFFER3_GAIN_MASK (0xffff0000)

// args: data (16-bit)
static __inline void acamera_fpga_fpga_wdr_multiplexor_buffer3_gain_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x22052cL);
    system_hw_write_32(0x22052cL, (((uint32_t) (data & 0xffff)) << 16) | (curr & 0xffff));
}
static __inline uint16_t acamera_fpga_fpga_wdr_multiplexor_buffer3_gain_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x22052cL) & 0xffff0000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Group: FPGA WDR Frame Buffer1
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Register: Global FSM reset
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Global FSM reset, active high
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_GLOBAL_FSM_RESET_DEFAULT (0x0)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_GLOBAL_FSM_RESET_DATASIZE (1)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_GLOBAL_FSM_RESET_OFFSET (0x540)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_GLOBAL_FSM_RESET_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_isp_frame_stitch_frame_buffer_global_fsm_reset_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220540L);
    system_hw_write_32(0x220540L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_isp_frame_stitch_frame_buffer_global_fsm_reset_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220540L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: Active Width
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Active video width in pixels
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_ACTIVE_WIDTH_DEFAULT (0x780)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_ACTIVE_WIDTH_DATASIZE (16)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_ACTIVE_WIDTH_OFFSET (0x54c)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_ACTIVE_WIDTH_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_isp_frame_stitch_frame_buffer_active_width_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x22054cL);
    system_hw_write_32(0x22054cL, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_isp_frame_stitch_frame_buffer_active_width_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x22054cL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: Active Height
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Active video height in lines
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_ACTIVE_HEIGHT_DEFAULT (0x438)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_ACTIVE_HEIGHT_DATASIZE (16)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_ACTIVE_HEIGHT_OFFSET (0x54c)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_ACTIVE_HEIGHT_MASK (0xffff0000)

// args: data (16-bit)
static __inline void acamera_fpga_isp_frame_stitch_frame_buffer_active_height_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x22054cL);
    system_hw_write_32(0x22054cL, (((uint32_t) (data & 0xffff)) << 16) | (curr & 0xffff));
}
static __inline uint16_t acamera_fpga_isp_frame_stitch_frame_buffer_active_height_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x22054cL) & 0xffff0000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: axi_port_enable
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_AXI_PORT_ENABLE_DEFAULT (0x0)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_AXI_PORT_ENABLE_DATASIZE (1)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_AXI_PORT_ENABLE_OFFSET (0x550)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_AXI_PORT_ENABLE_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_isp_frame_stitch_frame_buffer_axi_port_enable_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220550L);
    system_hw_write_32(0x220550L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_isp_frame_stitch_frame_buffer_axi_port_enable_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220550L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: write_enable
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_WRITE_ENABLE_DEFAULT (0x1)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_WRITE_ENABLE_DATASIZE (1)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_WRITE_ENABLE_OFFSET (0x550)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_WRITE_ENABLE_MASK (0x2)

// args: data (1-bit)
static __inline void acamera_fpga_isp_frame_stitch_frame_buffer_write_enable_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220550L);
    system_hw_write_32(0x220550L, (((uint32_t) (data & 0x1)) << 1) | (curr & 0xfffffffd));
}
static __inline uint8_t acamera_fpga_isp_frame_stitch_frame_buffer_write_enable_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220550L) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: frame cancel
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_FRAME_CANCEL_DEFAULT (0x0)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_FRAME_CANCEL_DATASIZE (1)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_FRAME_CANCEL_OFFSET (0x550)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_FRAME_CANCEL_MASK (0x4)

// args: data (1-bit)
static __inline void acamera_fpga_isp_frame_stitch_frame_buffer_frame_cancel_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220550L);
    system_hw_write_32(0x220550L, (((uint32_t) (data & 0x1)) << 2) | (curr & 0xfffffffb));
}
static __inline uint8_t acamera_fpga_isp_frame_stitch_frame_buffer_frame_cancel_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220550L) & 0x4) >> 2);
}
// ------------------------------------------------------------------------------ //
// Register: config
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_CONFIG_DEFAULT (0x0000)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_CONFIG_DATASIZE (32)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_CONFIG_OFFSET (0x554)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_CONFIG_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_isp_frame_stitch_frame_buffer_config_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x220554L, data);
}
static __inline uint32_t acamera_fpga_isp_frame_stitch_frame_buffer_config_read(uintptr_t base) {
    return system_hw_read_32(0x220554L);
}
// ------------------------------------------------------------------------------ //
// Register: status
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_STATUS_DEFAULT (0x0)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_STATUS_DATASIZE (32)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_STATUS_OFFSET (0x558)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_STATUS_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_isp_frame_stitch_frame_buffer_status_read(uintptr_t base) {
    return system_hw_read_32(0x220558L);
}
// ------------------------------------------------------------------------------ //
// Register: bank0_base
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// bank 0 base address for frame buffer, should be word-aligned
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_BANK0_BASE_DEFAULT (0x0)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_BANK0_BASE_DATASIZE (32)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_BANK0_BASE_OFFSET (0x560)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_BANK0_BASE_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_isp_frame_stitch_frame_buffer_bank0_base_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x220560L, data);
}
static __inline uint32_t acamera_fpga_isp_frame_stitch_frame_buffer_bank0_base_read(uintptr_t base) {
    return system_hw_read_32(0x220560L);
}
// ------------------------------------------------------------------------------ //
// Register: bank1_base
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// bank 1 base address for frame buffer, should be word-aligned
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_BANK1_BASE_DEFAULT (0x0)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_BANK1_BASE_DATASIZE (32)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_BANK1_BASE_OFFSET (0x564)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_BANK1_BASE_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_isp_frame_stitch_frame_buffer_bank1_base_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x220564L, data);
}
static __inline uint32_t acamera_fpga_isp_frame_stitch_frame_buffer_bank1_base_read(uintptr_t base) {
    return system_hw_read_32(0x220564L);
}
// ------------------------------------------------------------------------------ //
// Register: bank2_base
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// bank 2 base address for frame buffer, should be word-aligned
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_BANK2_BASE_DEFAULT (0x0)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_BANK2_BASE_DATASIZE (32)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_BANK2_BASE_OFFSET (0x568)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_BANK2_BASE_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_isp_frame_stitch_frame_buffer_bank2_base_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x220568L, data);
}
static __inline uint32_t acamera_fpga_isp_frame_stitch_frame_buffer_bank2_base_read(uintptr_t base) {
    return system_hw_read_32(0x220568L);
}
// ------------------------------------------------------------------------------ //
// Register: Line_offset
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// distance between lines, should be word-aligned
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_LINE_OFFSET_DEFAULT (0x1000)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_LINE_OFFSET_DATASIZE (32)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_LINE_OFFSET_OFFSET (0x56c)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_LINE_OFFSET_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_isp_frame_stitch_frame_buffer_line_offset_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x22056cL, data);
}
static __inline uint32_t acamera_fpga_isp_frame_stitch_frame_buffer_line_offset_read(uintptr_t base) {
    return system_hw_read_32(0x22056cL);
}
// ------------------------------------------------------------------------------ //
// Register: Frame write on
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_FRAME_WRITE_ON_DEFAULT (0x0)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_FRAME_WRITE_ON_DATASIZE (1)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_FRAME_WRITE_ON_OFFSET (0x570)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_FRAME_WRITE_ON_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_isp_frame_stitch_frame_buffer_frame_write_on_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220570L);
    system_hw_write_32(0x220570L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_isp_frame_stitch_frame_buffer_frame_write_on_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220570L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: Frame read on
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_FRAME_READ_ON_DEFAULT (0x0)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_FRAME_READ_ON_DATASIZE (1)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_FRAME_READ_ON_OFFSET (0x570)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_FRAME_READ_ON_MASK (0x2)

// args: data (1-bit)
static __inline void acamera_fpga_isp_frame_stitch_frame_buffer_frame_read_on_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220570L);
    system_hw_write_32(0x220570L, (((uint32_t) (data & 0x1)) << 1) | (curr & 0xfffffffd));
}
static __inline uint8_t acamera_fpga_isp_frame_stitch_frame_buffer_frame_read_on_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220570L) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: Frame write cancel
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_FRAME_WRITE_CANCEL_DEFAULT (0x0)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_FRAME_WRITE_CANCEL_DATASIZE (1)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_FRAME_WRITE_CANCEL_OFFSET (0x570)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_FRAME_WRITE_CANCEL_MASK (0x10)

// args: data (1-bit)
static __inline void acamera_fpga_isp_frame_stitch_frame_buffer_frame_write_cancel_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220570L);
    system_hw_write_32(0x220570L, (((uint32_t) (data & 0x1)) << 4) | (curr & 0xffffffef));
}
static __inline uint8_t acamera_fpga_isp_frame_stitch_frame_buffer_frame_write_cancel_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220570L) & 0x10) >> 4);
}
// ------------------------------------------------------------------------------ //
// Register: Frame read cancel
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_FRAME_READ_CANCEL_DEFAULT (0x0)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_FRAME_READ_CANCEL_DATASIZE (1)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_FRAME_READ_CANCEL_OFFSET (0x570)
#define ACAMERA_FPGA_ISP_FRAME_STITCH_FRAME_BUFFER_FRAME_READ_CANCEL_MASK (0x20)

// args: data (1-bit)
static __inline void acamera_fpga_isp_frame_stitch_frame_buffer_frame_read_cancel_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220570L);
    system_hw_write_32(0x220570L, (((uint32_t) (data & 0x1)) << 5) | (curr & 0xffffffdf));
}
static __inline uint8_t acamera_fpga_isp_frame_stitch_frame_buffer_frame_read_cancel_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220570L) & 0x20) >> 5);
}
// ------------------------------------------------------------------------------ //
// Group: Video-Capture-1 Input port
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Controls video input port.  
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Register: preset
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 
//        Allows selection of various input port presets for standard sensor inputs.  See ISP Guide for details of available presets.
//        0-14: Frequently used presets.  If using one of available presets, remaining bits in registers 0x100 and 0x104 are not used.
//        15:   Input port configured according to registers in 0x100 and 0x104.  Consult Apical support for special input port requirements.
//      
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_PRESET_DEFAULT (2)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_PRESET_DATASIZE (4)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_PRESET_OFFSET (0x600)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_PRESET_MASK (0xf)

// args: data (4-bit)
static __inline void acamera_fpga_video_capture1_input_port_preset_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220600L);
    system_hw_write_32(0x220600L, (((uint32_t) (data & 0xf)) << 0) | (curr & 0xfffffff0));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_preset_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220600L) & 0xf) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: vs_use field
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VS_USE_FIELD_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VS_USE_FIELD_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VS_USE_FIELD_OFFSET (0x600)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VS_USE_FIELD_MASK (0x100)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VS_USE_FIELD_USE_VSYNC_I_PORT_FOR_VERTICAL_SYNC (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VS_USE_FIELD_USE_FIELD_I_PORT_FOR_VERTICAL_SYNC (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_vs_use_field_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220600L);
    system_hw_write_32(0x220600L, (((uint32_t) (data & 0x1)) << 8) | (curr & 0xfffffeff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_vs_use_field_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220600L) & 0x100) >> 8);
}
// ------------------------------------------------------------------------------ //
// Register: vs toggle
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VS_TOGGLE_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VS_TOGGLE_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VS_TOGGLE_OFFSET (0x600)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VS_TOGGLE_MASK (0x200)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VS_TOGGLE_VSYNC_IS_PULSETYPE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VS_TOGGLE_VSYNC_IS_TOGGLETYPE_FIELD_SIGNAL (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_vs_toggle_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220600L);
    system_hw_write_32(0x220600L, (((uint32_t) (data & 0x1)) << 9) | (curr & 0xfffffdff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_vs_toggle_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220600L) & 0x200) >> 9);
}
// ------------------------------------------------------------------------------ //
// Register: vs polarity
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VS_POLARITY_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VS_POLARITY_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VS_POLARITY_OFFSET (0x600)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VS_POLARITY_MASK (0x400)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VS_POLARITY_HORIZONTAL_COUNTER_RESET_ON_RISING_EDGE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VS_POLARITY_HORIZONTAL_COUNTER_RESET_ON_FALLING_EDGE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_vs_polarity_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220600L);
    system_hw_write_32(0x220600L, (((uint32_t) (data & 0x1)) << 10) | (curr & 0xfffffbff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_vs_polarity_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220600L) & 0x400) >> 10);
}
// ------------------------------------------------------------------------------ //
// Register: vs_polarity acl
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VS_POLARITY_ACL_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VS_POLARITY_ACL_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VS_POLARITY_ACL_OFFSET (0x600)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VS_POLARITY_ACL_MASK (0x800)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VS_POLARITY_ACL_DONT_INVERT_POLARITY_FOR_ACL_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VS_POLARITY_ACL_INVERT_POLARITY_FOR_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_vs_polarity_acl_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220600L);
    system_hw_write_32(0x220600L, (((uint32_t) (data & 0x1)) << 11) | (curr & 0xfffff7ff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_vs_polarity_acl_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220600L) & 0x800) >> 11);
}
// ------------------------------------------------------------------------------ //
// Register: hs_use acl
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_USE_ACL_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_USE_ACL_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_USE_ACL_OFFSET (0x600)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_USE_ACL_MASK (0x1000)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_USE_ACL_USE_HSYNC_I_PORT_FOR_ACTIVELINE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_USE_ACL_USE_ACL_I_PORT_FOR_ACTIVELINE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_hs_use_acl_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220600L);
    system_hw_write_32(0x220600L, (((uint32_t) (data & 0x1)) << 12) | (curr & 0xffffefff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_hs_use_acl_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220600L) & 0x1000) >> 12);
}
// ------------------------------------------------------------------------------ //
// Register: vc_c select
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VC_C_SELECT_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VC_C_SELECT_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VC_C_SELECT_OFFSET (0x600)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VC_C_SELECT_MASK (0x4000)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VC_C_SELECT_VERTICAL_COUNTER_COUNTS_ON_HS (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VC_C_SELECT_VERTICAL_COUNTER_COUNTS_ON_HORIZONTAL_COUNTER_OVERFLOW_OR_RESET (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_vc_c_select_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220600L);
    system_hw_write_32(0x220600L, (((uint32_t) (data & 0x1)) << 14) | (curr & 0xffffbfff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_vc_c_select_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220600L) & 0x4000) >> 14);
}
// ------------------------------------------------------------------------------ //
// Register: vc_r select
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VC_R_SELECT_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VC_R_SELECT_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VC_R_SELECT_OFFSET (0x600)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VC_R_SELECT_MASK (0x8000)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VC_R_SELECT_VERTICAL_COUNTER_IS_RESET_ON_EDGE_OF_VS (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VC_R_SELECT_VERTICAL_COUNTER_IS_RESET_AFTER_TIMEOUT_ON_HS (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_vc_r_select_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220600L);
    system_hw_write_32(0x220600L, (((uint32_t) (data & 0x1)) << 15) | (curr & 0xffff7fff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_vc_r_select_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220600L) & 0x8000) >> 15);
}
// ------------------------------------------------------------------------------ //
// Register: hs_xor vs
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_XOR_VS_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_XOR_VS_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_XOR_VS_OFFSET (0x600)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_XOR_VS_MASK (0x10000)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_XOR_VS_NORMAL_MODE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_XOR_VS_HVALID__HSYNC_XOR_VSYNC (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_hs_xor_vs_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220600L);
    system_hw_write_32(0x220600L, (((uint32_t) (data & 0x1)) << 16) | (curr & 0xfffeffff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_hs_xor_vs_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220600L) & 0x10000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: hs polarity
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_POLARITY_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_POLARITY_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_POLARITY_OFFSET (0x600)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_POLARITY_MASK (0x20000)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_POLARITY_DONT_INVERT_POLARITY_OF_HS_FOR_ACL_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_POLARITY_INVERT_POLARITY_OF_HS_FOR_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_hs_polarity_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220600L);
    system_hw_write_32(0x220600L, (((uint32_t) (data & 0x1)) << 17) | (curr & 0xfffdffff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_hs_polarity_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220600L) & 0x20000) >> 17);
}
// ------------------------------------------------------------------------------ //
// Register: hs_polarity acl
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_POLARITY_ACL_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_POLARITY_ACL_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_POLARITY_ACL_OFFSET (0x600)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_POLARITY_ACL_MASK (0x40000)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_POLARITY_ACL_DONT_INVERT_POLARITY_OF_HS_FOR_HS_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_POLARITY_ACL_INVERT_POLARITY_OF_HS_FOR_HS_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_hs_polarity_acl_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220600L);
    system_hw_write_32(0x220600L, (((uint32_t) (data & 0x1)) << 18) | (curr & 0xfffbffff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_hs_polarity_acl_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220600L) & 0x40000) >> 18);
}
// ------------------------------------------------------------------------------ //
// Register: hs_polarity hs
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_POLARITY_HS_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_POLARITY_HS_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_POLARITY_HS_OFFSET (0x600)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_POLARITY_HS_MASK (0x80000)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_POLARITY_HS_HORIZONTAL_COUNTER_IS_RESET_ON_RISING_EDGE_OF_HS (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_POLARITY_HS_HORIZONTAL_COUNTER_IS_RESET_ON_VSYNC_EG_WHEN_HSYNC_IS_NOT_AVAILABLE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_hs_polarity_hs_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220600L);
    system_hw_write_32(0x220600L, (((uint32_t) (data & 0x1)) << 19) | (curr & 0xfff7ffff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_hs_polarity_hs_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220600L) & 0x80000) >> 19);
}
// ------------------------------------------------------------------------------ //
// Register: hs_polarity vc
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_POLARITY_VC_DEFAULT (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_POLARITY_VC_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_POLARITY_VC_OFFSET (0x600)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_POLARITY_VC_MASK (0x100000)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_POLARITY_VC_VERTICAL_COUNTER_INCREMENTS_ON_RISING_EDGE_OF_HS (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HS_POLARITY_VC_VERTICAL_COUNTER_INCREMENTS_ON_FALLING_EDGE_OF_HS (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_hs_polarity_vc_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220600L);
    system_hw_write_32(0x220600L, (((uint32_t) (data & 0x1)) << 20) | (curr & 0xffefffff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_hs_polarity_vc_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220600L) & 0x100000) >> 20);
}
// ------------------------------------------------------------------------------ //
// Register: hc_r select
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HC_R_SELECT_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HC_R_SELECT_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HC_R_SELECT_OFFSET (0x600)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HC_R_SELECT_MASK (0x800000)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HC_R_SELECT_VERTICAL_COUNTER_IS_RESET_ON_RISING_EDGE_OF_HS (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HC_R_SELECT_VERTICAL_COUNTER_IS_RESET_ON_RISING_EDGE_OF_VS (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_hc_r_select_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220600L);
    system_hw_write_32(0x220600L, (((uint32_t) (data & 0x1)) << 23) | (curr & 0xff7fffff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_hc_r_select_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220600L) & 0x800000) >> 23);
}
// ------------------------------------------------------------------------------ //
// Register: acl polarity
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACL_POLARITY_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACL_POLARITY_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACL_POLARITY_OFFSET (0x600)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACL_POLARITY_MASK (0x1000000)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACL_POLARITY_DONT_INVERT_ACL_I_FOR_ACL_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACL_POLARITY_INVERT_ACL_I_FOR_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_acl_polarity_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220600L);
    system_hw_write_32(0x220600L, (((uint32_t) (data & 0x1)) << 24) | (curr & 0xfeffffff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_acl_polarity_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220600L) & 0x1000000) >> 24);
}
// ------------------------------------------------------------------------------ //
// Register: field polarity
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELD_POLARITY_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELD_POLARITY_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELD_POLARITY_OFFSET (0x604)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELD_POLARITY_MASK (0x1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELD_POLARITY_DONT_INVERT_FIELD_I_FOR_FIELD_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELD_POLARITY_INVERT_FIELD_I_FOR_FIELD_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_field_polarity_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220604L);
    system_hw_write_32(0x220604L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_field_polarity_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220604L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: field toggle
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELD_TOGGLE_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELD_TOGGLE_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELD_TOGGLE_OFFSET (0x604)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELD_TOGGLE_MASK (0x2)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELD_TOGGLE_FIELD_IS_PULSETYPE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELD_TOGGLE_FIELD_IS_TOGGLETYPE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_field_toggle_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220604L);
    system_hw_write_32(0x220604L, (((uint32_t) (data & 0x1)) << 1) | (curr & 0xfffffffd));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_field_toggle_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220604L) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: aclg window0
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_WINDOW0_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_WINDOW0_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_WINDOW0_OFFSET (0x604)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_WINDOW0_MASK (0x100)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_WINDOW0_EXCLUDE_WINDOW0_SIGNAL_IN_ACL_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_WINDOW0_INCLUDE_WINDOW0_SIGNAL_IN_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_aclg_window0_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220604L);
    system_hw_write_32(0x220604L, (((uint32_t) (data & 0x1)) << 8) | (curr & 0xfffffeff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_aclg_window0_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220604L) & 0x100) >> 8);
}
// ------------------------------------------------------------------------------ //
// Register: aclg hsync
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_HSYNC_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_HSYNC_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_HSYNC_OFFSET (0x604)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_HSYNC_MASK (0x200)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_HSYNC_EXCLUDE_HSYNC_SIGNAL_IN_ACL_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_HSYNC_INCLUDE_HSYNC_SIGNAL_IN_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_aclg_hsync_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220604L);
    system_hw_write_32(0x220604L, (((uint32_t) (data & 0x1)) << 9) | (curr & 0xfffffdff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_aclg_hsync_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220604L) & 0x200) >> 9);
}
// ------------------------------------------------------------------------------ //
// Register: aclg window2
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_WINDOW2_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_WINDOW2_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_WINDOW2_OFFSET (0x604)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_WINDOW2_MASK (0x400)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_WINDOW2_EXCLUDE_WINDOW2_SIGNAL_IN_ACL_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_WINDOW2_INCLUDE_WINDOW2_SIGNAL_IN_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_aclg_window2_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220604L);
    system_hw_write_32(0x220604L, (((uint32_t) (data & 0x1)) << 10) | (curr & 0xfffffbff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_aclg_window2_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220604L) & 0x400) >> 10);
}
// ------------------------------------------------------------------------------ //
// Register: aclg acl
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_ACL_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_ACL_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_ACL_OFFSET (0x604)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_ACL_MASK (0x800)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_ACL_EXCLUDE_ACL_I_SIGNAL_IN_ACL_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_ACL_INCLUDE_ACL_I_SIGNAL_IN_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_aclg_acl_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220604L);
    system_hw_write_32(0x220604L, (((uint32_t) (data & 0x1)) << 11) | (curr & 0xfffff7ff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_aclg_acl_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220604L) & 0x800) >> 11);
}
// ------------------------------------------------------------------------------ //
// Register: aclg vsync
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_VSYNC_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_VSYNC_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_VSYNC_OFFSET (0x604)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_VSYNC_MASK (0x1000)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_VSYNC_EXCLUDE_VSYNC_SIGNAL_IN_ACL_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_ACLG_VSYNC_INCLUDE_VSYNC_SIGNAL_IN_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_aclg_vsync_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220604L);
    system_hw_write_32(0x220604L, (((uint32_t) (data & 0x1)) << 12) | (curr & 0xffffefff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_aclg_vsync_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220604L) & 0x1000) >> 12);
}
// ------------------------------------------------------------------------------ //
// Register: hsg window1
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HSG_WINDOW1_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HSG_WINDOW1_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HSG_WINDOW1_OFFSET (0x604)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HSG_WINDOW1_MASK (0x10000)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HSG_WINDOW1_EXCLUDE_WINDOW1_SIGNAL_IN_HS_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HSG_WINDOW1_INCLUDE_WINDOW1_SIGNAL_IN_HS_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_hsg_window1_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220604L);
    system_hw_write_32(0x220604L, (((uint32_t) (data & 0x1)) << 16) | (curr & 0xfffeffff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_hsg_window1_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220604L) & 0x10000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: hsg hsync
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HSG_HSYNC_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HSG_HSYNC_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HSG_HSYNC_OFFSET (0x604)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HSG_HSYNC_MASK (0x20000)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HSG_HSYNC_EXCLUDE_HSYNC_SIGNAL_IN_HS_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HSG_HSYNC_INCLUDE_HSYNC_SIGNAL_IN_HS_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_hsg_hsync_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220604L);
    system_hw_write_32(0x220604L, (((uint32_t) (data & 0x1)) << 17) | (curr & 0xfffdffff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_hsg_hsync_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220604L) & 0x20000) >> 17);
}
// ------------------------------------------------------------------------------ //
// Register: hsg vsync
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HSG_VSYNC_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HSG_VSYNC_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HSG_VSYNC_OFFSET (0x604)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HSG_VSYNC_MASK (0x40000)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HSG_VSYNC_EXCLUDE_VSYNC_SIGNAL_IN_HS_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HSG_VSYNC_INCLUDE_VSYNC_SIGNAL_IN_HS_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_hsg_vsync_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220604L);
    system_hw_write_32(0x220604L, (((uint32_t) (data & 0x1)) << 18) | (curr & 0xfffbffff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_hsg_vsync_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220604L) & 0x40000) >> 18);
}
// ------------------------------------------------------------------------------ //
// Register: hsg window2
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HSG_WINDOW2_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HSG_WINDOW2_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HSG_WINDOW2_OFFSET (0x604)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HSG_WINDOW2_MASK (0x80000)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HSG_WINDOW2_EXCLUDE_WINDOW2_SIGNAL_IN_HS_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HSG_WINDOW2_INCLUDE_WINDOW2_SIGNAL_IN_HS_GATE_MASK_OUT_SPURIOUS_HS_DURING_BLANK (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_hsg_window2_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220604L);
    system_hw_write_32(0x220604L, (((uint32_t) (data & 0x1)) << 19) | (curr & 0xfff7ffff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_hsg_window2_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220604L) & 0x80000) >> 19);
}
// ------------------------------------------------------------------------------ //
// Register: fieldg vsync
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELDG_VSYNC_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELDG_VSYNC_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELDG_VSYNC_OFFSET (0x604)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELDG_VSYNC_MASK (0x1000000)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELDG_VSYNC_EXCLUDE_VSYNC_SIGNAL_IN_FIELD_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELDG_VSYNC_INCLUDE_VSYNC_SIGNAL_IN_FIELD_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_fieldg_vsync_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220604L);
    system_hw_write_32(0x220604L, (((uint32_t) (data & 0x1)) << 24) | (curr & 0xfeffffff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_fieldg_vsync_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220604L) & 0x1000000) >> 24);
}
// ------------------------------------------------------------------------------ //
// Register: fieldg window2
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELDG_WINDOW2_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELDG_WINDOW2_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELDG_WINDOW2_OFFSET (0x604)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELDG_WINDOW2_MASK (0x2000000)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELDG_WINDOW2_EXCLUDE_WINDOW2_SIGNAL_IN_FIELD_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELDG_WINDOW2_INCLUDE_WINDOW2_SIGNAL_IN_FIELD_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_fieldg_window2_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220604L);
    system_hw_write_32(0x220604L, (((uint32_t) (data & 0x1)) << 25) | (curr & 0xfdffffff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_fieldg_window2_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220604L) & 0x2000000) >> 25);
}
// ------------------------------------------------------------------------------ //
// Register: fieldg field
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELDG_FIELD_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELDG_FIELD_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELDG_FIELD_OFFSET (0x604)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELDG_FIELD_MASK (0x4000000)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELDG_FIELD_EXCLUDE_FIELD_I_SIGNAL_IN_FIELD_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELDG_FIELD_INCLUDE_FIELD_I_SIGNAL_IN_FIELD_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_fieldg_field_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220604L);
    system_hw_write_32(0x220604L, (((uint32_t) (data & 0x1)) << 26) | (curr & 0xfbffffff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_fieldg_field_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220604L) & 0x4000000) >> 26);
}
// ------------------------------------------------------------------------------ //
// Register: field mode
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELD_MODE_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELD_MODE_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELD_MODE_OFFSET (0x604)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELD_MODE_MASK (0x8000000)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELD_MODE_PULSE_FIELD (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FIELD_MODE_TOGGLE_FIELD (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_field_mode_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220604L);
    system_hw_write_32(0x220604L, (((uint32_t) (data & 0x1)) << 27) | (curr & 0xf7ffffff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_field_mode_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220604L) & 0x8000000) >> 27);
}
// ------------------------------------------------------------------------------ //
// Register: hc limit
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// horizontal counter limit value (counts: 0,1,...hc_limit-1,hc_limit,0,1,...)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HC_LIMIT_DEFAULT (0xFFFF)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HC_LIMIT_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HC_LIMIT_OFFSET (0x608)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HC_LIMIT_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture1_input_port_hc_limit_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220608L);
    system_hw_write_32(0x220608L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture1_input_port_hc_limit_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220608L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: hc start0
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// window0 start for ACL gate.  See ISP guide for further details.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HC_START0_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HC_START0_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HC_START0_OFFSET (0x60c)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HC_START0_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture1_input_port_hc_start0_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x22060cL);
    system_hw_write_32(0x22060cL, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture1_input_port_hc_start0_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x22060cL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: hc size0
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// window0 size for ACL gate.  See ISP guide for further details.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HC_SIZE0_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HC_SIZE0_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HC_SIZE0_OFFSET (0x610)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HC_SIZE0_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture1_input_port_hc_size0_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220610L);
    system_hw_write_32(0x220610L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture1_input_port_hc_size0_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220610L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: hc start1
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// window1 start for HS gate.  See ISP guide for further details.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HC_START1_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HC_START1_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HC_START1_OFFSET (0x614)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HC_START1_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture1_input_port_hc_start1_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220614L);
    system_hw_write_32(0x220614L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture1_input_port_hc_start1_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220614L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: hc size1
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// window1 size for HS gate.  See ISP guide for further details.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HC_SIZE1_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HC_SIZE1_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HC_SIZE1_OFFSET (0x618)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_HC_SIZE1_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture1_input_port_hc_size1_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220618L);
    system_hw_write_32(0x220618L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture1_input_port_hc_size1_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220618L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: vc limit
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// vertical counter limit value (counts: 0,1,...vc_limit-1,vc_limit,0,1,...)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VC_LIMIT_DEFAULT (0xFFFF)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VC_LIMIT_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VC_LIMIT_OFFSET (0x61c)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VC_LIMIT_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture1_input_port_vc_limit_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x22061cL);
    system_hw_write_32(0x22061cL, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture1_input_port_vc_limit_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x22061cL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: vc start
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// window2 start for ACL gate.  See ISP guide for further details.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VC_START_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VC_START_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VC_START_OFFSET (0x620)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VC_START_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture1_input_port_vc_start_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220620L);
    system_hw_write_32(0x220620L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture1_input_port_vc_start_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220620L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: vc size
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// window2 size for ACL gate.  See ISP guide for further details.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VC_SIZE_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VC_SIZE_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VC_SIZE_OFFSET (0x624)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_VC_SIZE_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture1_input_port_vc_size_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220624L);
    system_hw_write_32(0x220624L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture1_input_port_vc_size_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220624L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: frame width
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// detected frame width.  Read only value.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FRAME_WIDTH_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FRAME_WIDTH_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FRAME_WIDTH_OFFSET (0x628)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FRAME_WIDTH_MASK (0xffff)

// args: data (16-bit)
static __inline uint16_t acamera_fpga_video_capture1_input_port_frame_width_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220628L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: frame height
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// detected frame height.  Read only value.  
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FRAME_HEIGHT_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FRAME_HEIGHT_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FRAME_HEIGHT_OFFSET (0x62c)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FRAME_HEIGHT_MASK (0xffff)

// args: data (16-bit)
static __inline uint16_t acamera_fpga_video_capture1_input_port_frame_height_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x22062cL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: mode request
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Used to stop and start input port.  See ISP guide for further details. 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_MODE_REQUEST_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_MODE_REQUEST_DATASIZE (3)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_MODE_REQUEST_OFFSET (0x630)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_MODE_REQUEST_MASK (0x7)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_MODE_REQUEST_SAFE_STOP (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_MODE_REQUEST_SAFE_START (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_MODE_REQUEST_URGENT_STOP (2)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_MODE_REQUEST_URGENT_START (3)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_MODE_REQUEST_RESERVED4 (4)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_MODE_REQUEST_SAFER_START (5)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_MODE_REQUEST_RESERVED6 (6)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_MODE_REQUEST_RESERVED7 (7)

// args: data (3-bit)
static __inline void acamera_fpga_video_capture1_input_port_mode_request_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220630L);
    system_hw_write_32(0x220630L, (((uint32_t) (data & 0x7)) << 0) | (curr & 0xfffffff8));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_mode_request_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220630L) & 0x7) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: freeze config
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Used to freeze input port configuration.  Used when multiple register writes are required to change input port configuration. 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FREEZE_CONFIG_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FREEZE_CONFIG_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FREEZE_CONFIG_OFFSET (0x630)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FREEZE_CONFIG_MASK (0x80)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FREEZE_CONFIG_NORMAL_OPERATION (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_FREEZE_CONFIG_HOLD_PREVIOUS_INPUT_PORT_CONFIG_STATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_input_port_freeze_config_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220630L);
    system_hw_write_32(0x220630L, (((uint32_t) (data & 0x1)) << 7) | (curr & 0xffffff7f));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_freeze_config_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220630L) & 0x80) >> 7);
}
// ------------------------------------------------------------------------------ //
// Register: mode status
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 
//          Used to monitor input port status:
//          bit 0: 1=running, 0=stopped, bits 1,2-reserved
//        
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_MODE_STATUS_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_MODE_STATUS_DATASIZE (3)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_MODE_STATUS_OFFSET (0x634)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_MODE_STATUS_MASK (0x7)

// args: data (3-bit)
static __inline uint8_t acamera_fpga_video_capture1_input_port_mode_status_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220634L) & 0x7) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: source
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 
//          Select source for capture:
//          0=sensor, 1=ISP video input, 2=ISP FR video output, 3=ISP DS video output
//        
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_SOURCE_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_SOURCE_DATASIZE (2)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_SOURCE_OFFSET (0x634)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_INPUT_PORT_SOURCE_MASK (0x30000)

// args: data (2-bit)
static __inline void acamera_fpga_video_capture1_input_port_source_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220634L);
    system_hw_write_32(0x220634L, (((uint32_t) (data & 0x3)) << 16) | (curr & 0xfffcffff));
}
static __inline uint8_t acamera_fpga_video_capture1_input_port_source_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220634L) & 0x30000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Group: Video-Capture-1 Frame Stats
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Register: stats reset
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_STATS_RESET_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_STATS_RESET_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_STATS_RESET_OFFSET (0x680)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_STATS_RESET_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_frame_stats_stats_reset_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220680L);
    system_hw_write_32(0x220680L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_video_capture1_frame_stats_stats_reset_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220680L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: stats hold
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_STATS_HOLD_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_STATS_HOLD_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_STATS_HOLD_OFFSET (0x684)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_STATS_HOLD_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_frame_stats_stats_hold_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220684L);
    system_hw_write_32(0x220684L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_video_capture1_frame_stats_stats_hold_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220684L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: active width min
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_WIDTH_MIN_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_WIDTH_MIN_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_WIDTH_MIN_OFFSET (0x690)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_WIDTH_MIN_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture1_frame_stats_active_width_min_read(uintptr_t base) {
    return system_hw_read_32(0x220690L);
}
// ------------------------------------------------------------------------------ //
// Register: active width max
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_WIDTH_MAX_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_WIDTH_MAX_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_WIDTH_MAX_OFFSET (0x694)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_WIDTH_MAX_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture1_frame_stats_active_width_max_read(uintptr_t base) {
    return system_hw_read_32(0x220694L);
}
// ------------------------------------------------------------------------------ //
// Register: active width sum
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_WIDTH_SUM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_WIDTH_SUM_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_WIDTH_SUM_OFFSET (0x698)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_WIDTH_SUM_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture1_frame_stats_active_width_sum_read(uintptr_t base) {
    return system_hw_read_32(0x220698L);
}
// ------------------------------------------------------------------------------ //
// Register: active width num
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_WIDTH_NUM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_WIDTH_NUM_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_WIDTH_NUM_OFFSET (0x69c)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_WIDTH_NUM_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture1_frame_stats_active_width_num_read(uintptr_t base) {
    return system_hw_read_32(0x22069cL);
}
// ------------------------------------------------------------------------------ //
// Register: active height min
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_HEIGHT_MIN_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_HEIGHT_MIN_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_HEIGHT_MIN_OFFSET (0x6a0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_HEIGHT_MIN_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture1_frame_stats_active_height_min_read(uintptr_t base) {
    return system_hw_read_32(0x2206a0L);
}
// ------------------------------------------------------------------------------ //
// Register: active height max
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_HEIGHT_MAX_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_HEIGHT_MAX_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_HEIGHT_MAX_OFFSET (0x6a4)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_HEIGHT_MAX_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture1_frame_stats_active_height_max_read(uintptr_t base) {
    return system_hw_read_32(0x2206a4L);
}
// ------------------------------------------------------------------------------ //
// Register: active height sum
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_HEIGHT_SUM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_HEIGHT_SUM_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_HEIGHT_SUM_OFFSET (0x6a8)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_HEIGHT_SUM_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture1_frame_stats_active_height_sum_read(uintptr_t base) {
    return system_hw_read_32(0x2206a8L);
}
// ------------------------------------------------------------------------------ //
// Register: active height num
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_HEIGHT_NUM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_HEIGHT_NUM_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_HEIGHT_NUM_OFFSET (0x6ac)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_ACTIVE_HEIGHT_NUM_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture1_frame_stats_active_height_num_read(uintptr_t base) {
    return system_hw_read_32(0x2206acL);
}
// ------------------------------------------------------------------------------ //
// Register: hblank min
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_HBLANK_MIN_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_HBLANK_MIN_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_HBLANK_MIN_OFFSET (0x6b0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_HBLANK_MIN_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture1_frame_stats_hblank_min_read(uintptr_t base) {
    return system_hw_read_32(0x2206b0L);
}
// ------------------------------------------------------------------------------ //
// Register: hblank max
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_HBLANK_MAX_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_HBLANK_MAX_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_HBLANK_MAX_OFFSET (0x6b4)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_HBLANK_MAX_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture1_frame_stats_hblank_max_read(uintptr_t base) {
    return system_hw_read_32(0x2206b4L);
}
// ------------------------------------------------------------------------------ //
// Register: hblank sum
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_HBLANK_SUM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_HBLANK_SUM_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_HBLANK_SUM_OFFSET (0x6b8)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_HBLANK_SUM_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture1_frame_stats_hblank_sum_read(uintptr_t base) {
    return system_hw_read_32(0x2206b8L);
}
// ------------------------------------------------------------------------------ //
// Register: hblank num
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_HBLANK_NUM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_HBLANK_NUM_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_HBLANK_NUM_OFFSET (0x6bc)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_HBLANK_NUM_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture1_frame_stats_hblank_num_read(uintptr_t base) {
    return system_hw_read_32(0x2206bcL);
}
// ------------------------------------------------------------------------------ //
// Register: vblank min
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_VBLANK_MIN_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_VBLANK_MIN_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_VBLANK_MIN_OFFSET (0x6c0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_VBLANK_MIN_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture1_frame_stats_vblank_min_read(uintptr_t base) {
    return system_hw_read_32(0x2206c0L);
}
// ------------------------------------------------------------------------------ //
// Register: vblank max
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_VBLANK_MAX_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_VBLANK_MAX_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_VBLANK_MAX_OFFSET (0x6c4)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_VBLANK_MAX_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture1_frame_stats_vblank_max_read(uintptr_t base) {
    return system_hw_read_32(0x2206c4L);
}
// ------------------------------------------------------------------------------ //
// Register: vblank sum
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_VBLANK_SUM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_VBLANK_SUM_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_VBLANK_SUM_OFFSET (0x6c8)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_VBLANK_SUM_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture1_frame_stats_vblank_sum_read(uintptr_t base) {
    return system_hw_read_32(0x2206c8L);
}
// ------------------------------------------------------------------------------ //
// Register: vblank num
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_VBLANK_NUM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_VBLANK_NUM_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_VBLANK_NUM_OFFSET (0x6cc)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_FRAME_STATS_VBLANK_NUM_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture1_frame_stats_vblank_num_read(uintptr_t base) {
    return system_hw_read_32(0x2206ccL);
}
// ------------------------------------------------------------------------------ //
// Group: Video-Capture-1 video test gen
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Video test generator controls.  See ISP Guide for further details
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Register: test_pattern_off on
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Test pattern off-on: 0=off, 1=on
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_TEST_PATTERN_OFF_ON_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_TEST_PATTERN_OFF_ON_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_TEST_PATTERN_OFF_ON_OFFSET (0x700)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_TEST_PATTERN_OFF_ON_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_video_test_gen_test_pattern_off_on_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220700L);
    system_hw_write_32(0x220700L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_video_capture1_video_test_gen_test_pattern_off_on_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220700L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: bayer_rgb_i sel
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Bayer or rgb select for input video: 0=bayer, 1=rgb
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_BAYER_RGB_I_SEL_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_BAYER_RGB_I_SEL_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_BAYER_RGB_I_SEL_OFFSET (0x700)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_BAYER_RGB_I_SEL_MASK (0x2)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_video_test_gen_bayer_rgb_i_sel_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220700L);
    system_hw_write_32(0x220700L, (((uint32_t) (data & 0x1)) << 1) | (curr & 0xfffffffd));
}
static __inline uint8_t acamera_fpga_video_capture1_video_test_gen_bayer_rgb_i_sel_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220700L) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: bayer_rgb_o sel
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Bayer or rgb select for output video: 0=bayer, 1=rgb
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_BAYER_RGB_O_SEL_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_BAYER_RGB_O_SEL_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_BAYER_RGB_O_SEL_OFFSET (0x700)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_BAYER_RGB_O_SEL_MASK (0x4)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_video_test_gen_bayer_rgb_o_sel_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220700L);
    system_hw_write_32(0x220700L, (((uint32_t) (data & 0x1)) << 2) | (curr & 0xfffffffb));
}
static __inline uint8_t acamera_fpga_video_capture1_video_test_gen_bayer_rgb_o_sel_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220700L) & 0x4) >> 2);
}
// ------------------------------------------------------------------------------ //
// Register: pattern type
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Pattern type select: 0=Flat field,1=Horizontal gradient,2=Vertical Gradient,3=Vertical Bars,4=Rectangle,5-255=Default white frame on black
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_PATTERN_TYPE_DEFAULT (0x03)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_PATTERN_TYPE_DATASIZE (8)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_PATTERN_TYPE_OFFSET (0x704)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_PATTERN_TYPE_MASK (0xff)

// args: data (8-bit)
static __inline void acamera_fpga_video_capture1_video_test_gen_pattern_type_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220704L);
    system_hw_write_32(0x220704L, (((uint32_t) (data & 0xff)) << 0) | (curr & 0xffffff00));
}
static __inline uint8_t acamera_fpga_video_capture1_video_test_gen_pattern_type_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220704L) & 0xff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: r backgnd
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Red background  value 16bit, MSB aligned to used width 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_R_BACKGND_DEFAULT (0xFFFF)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_R_BACKGND_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_R_BACKGND_OFFSET (0x708)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_R_BACKGND_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture1_video_test_gen_r_backgnd_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220708L);
    system_hw_write_32(0x220708L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture1_video_test_gen_r_backgnd_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220708L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: g backgnd
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Green background value 16bit, MSB aligned to used width
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_G_BACKGND_DEFAULT (0xFFFF)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_G_BACKGND_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_G_BACKGND_OFFSET (0x70c)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_G_BACKGND_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture1_video_test_gen_g_backgnd_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x22070cL);
    system_hw_write_32(0x22070cL, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture1_video_test_gen_g_backgnd_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x22070cL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: b backgnd
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Blue background value 16bit, MSB aligned to used width
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_B_BACKGND_DEFAULT (0xFFFF)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_B_BACKGND_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_B_BACKGND_OFFSET (0x710)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_B_BACKGND_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture1_video_test_gen_b_backgnd_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220710L);
    system_hw_write_32(0x220710L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture1_video_test_gen_b_backgnd_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220710L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: r foregnd
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Red foreground  value 16bit, MSB aligned to used width 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_R_FOREGND_DEFAULT (0x8FFF)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_R_FOREGND_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_R_FOREGND_OFFSET (0x714)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_R_FOREGND_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture1_video_test_gen_r_foregnd_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220714L);
    system_hw_write_32(0x220714L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture1_video_test_gen_r_foregnd_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220714L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: g foregnd
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Green foreground value 16bit, MSB aligned to used width
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_G_FOREGND_DEFAULT (0x8FFF)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_G_FOREGND_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_G_FOREGND_OFFSET (0x718)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_G_FOREGND_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture1_video_test_gen_g_foregnd_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220718L);
    system_hw_write_32(0x220718L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture1_video_test_gen_g_foregnd_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220718L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: b foregnd
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Blue foreground value 16bit, MSB aligned to used width
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_B_FOREGND_DEFAULT (0x8FFF)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_B_FOREGND_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_B_FOREGND_OFFSET (0x71c)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_B_FOREGND_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture1_video_test_gen_b_foregnd_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x22071cL);
    system_hw_write_32(0x22071cL, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture1_video_test_gen_b_foregnd_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x22071cL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: rgb gradient
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// RGB gradient increment per pixel (0-15)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_RGB_GRADIENT_DEFAULT (0x3CAA)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_RGB_GRADIENT_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_RGB_GRADIENT_OFFSET (0x720)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_RGB_GRADIENT_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture1_video_test_gen_rgb_gradient_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220720L);
    system_hw_write_32(0x220720L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture1_video_test_gen_rgb_gradient_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220720L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: rgb_gradient start
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// RGB gradient start value 16bit, MSB aligned to used width
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_RGB_GRADIENT_START_DEFAULT (0x0000)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_RGB_GRADIENT_START_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_RGB_GRADIENT_START_OFFSET (0x724)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_RGB_GRADIENT_START_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture1_video_test_gen_rgb_gradient_start_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220724L);
    system_hw_write_32(0x220724L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture1_video_test_gen_rgb_gradient_start_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220724L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: rect top
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  Rectangle top line number 1-n
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_RECT_TOP_DEFAULT (0x0001)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_RECT_TOP_DATASIZE (14)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_RECT_TOP_OFFSET (0x728)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_RECT_TOP_MASK (0x3fff)

// args: data (14-bit)
static __inline void acamera_fpga_video_capture1_video_test_gen_rect_top_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220728L);
    system_hw_write_32(0x220728L, (((uint32_t) (data & 0x3fff)) << 0) | (curr & 0xffffc000));
}
static __inline uint16_t acamera_fpga_video_capture1_video_test_gen_rect_top_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220728L) & 0x3fff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: rect bot
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  Rectangle bottom line number 1-n
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_RECT_BOT_DEFAULT (0x0100)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_RECT_BOT_DATASIZE (14)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_RECT_BOT_OFFSET (0x72c)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_RECT_BOT_MASK (0x3fff)

// args: data (14-bit)
static __inline void acamera_fpga_video_capture1_video_test_gen_rect_bot_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x22072cL);
    system_hw_write_32(0x22072cL, (((uint32_t) (data & 0x3fff)) << 0) | (curr & 0xffffc000));
}
static __inline uint16_t acamera_fpga_video_capture1_video_test_gen_rect_bot_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x22072cL) & 0x3fff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: rect left
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  Rectangle left pixel number 1-n
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_RECT_LEFT_DEFAULT (0x0001)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_RECT_LEFT_DATASIZE (14)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_RECT_LEFT_OFFSET (0x730)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_RECT_LEFT_MASK (0x3fff)

// args: data (14-bit)
static __inline void acamera_fpga_video_capture1_video_test_gen_rect_left_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220730L);
    system_hw_write_32(0x220730L, (((uint32_t) (data & 0x3fff)) << 0) | (curr & 0xffffc000));
}
static __inline uint16_t acamera_fpga_video_capture1_video_test_gen_rect_left_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220730L) & 0x3fff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: rect right
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  Rectangle right pixel number 1-n
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_RECT_RIGHT_DEFAULT (0x0100)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_RECT_RIGHT_DATASIZE (14)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_RECT_RIGHT_OFFSET (0x738)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_VIDEO_TEST_GEN_RECT_RIGHT_MASK (0x3fff)

// args: data (14-bit)
static __inline void acamera_fpga_video_capture1_video_test_gen_rect_right_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220738L);
    system_hw_write_32(0x220738L, (((uint32_t) (data & 0x3fff)) << 0) | (curr & 0xffffc000));
}
static __inline uint16_t acamera_fpga_video_capture1_video_test_gen_rect_right_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220738L) & 0x3fff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Group: Video-Capture-1 DMA Writer
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Video-Capture DMA writer controls
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Register: Format
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Format
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_FORMAT_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_FORMAT_DATASIZE (8)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_FORMAT_OFFSET (0x780)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_FORMAT_MASK (0xff)

// args: data (8-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_format_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220780L);
    system_hw_write_32(0x220780L, (((uint32_t) (data & 0xff)) << 0) | (curr & 0xffffff00));
}
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_format_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220780L) & 0xff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: Base mode
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Base DMA packing mode for RGB/RAW/YUV etc (see ISP guide)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BASE_MODE_DEFAULT (0x0D)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BASE_MODE_DATASIZE (4)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BASE_MODE_OFFSET (0x780)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BASE_MODE_MASK (0xf)

// args: data (4-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_base_mode_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220780L);
    system_hw_write_32(0x220780L, (((uint32_t) (data & 0xf)) << 0) | (curr & 0xfffffff0));
}
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_base_mode_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220780L) & 0xf) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: Plane select
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Plane select for planar base modes.  Only used if planar outputs required.  Not used.  Should be set to 0
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_PLANE_SELECT_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_PLANE_SELECT_DATASIZE (2)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_PLANE_SELECT_OFFSET (0x780)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_PLANE_SELECT_MASK (0xc0)

// args: data (2-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_plane_select_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220780L);
    system_hw_write_32(0x220780L, (((uint32_t) (data & 0x3)) << 6) | (curr & 0xffffff3f));
}
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_plane_select_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220780L) & 0xc0) >> 6);
}
// ------------------------------------------------------------------------------ //
// Register: single frame
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 0 = All frames are written(after frame_write_on= 1), 1= only 1st frame written ( after frame_write_on =1)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_SINGLE_FRAME_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_SINGLE_FRAME_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_SINGLE_FRAME_OFFSET (0x784)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_SINGLE_FRAME_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_single_frame_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220784L);
    system_hw_write_32(0x220784L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_single_frame_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220784L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: frame write on
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 
//    0 = no frames written(when switched from 1, current frame completes writing before stopping),
//    1= write frame(s) (write single or continous frame(s) )
//    
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_FRAME_WRITE_ON_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_FRAME_WRITE_ON_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_FRAME_WRITE_ON_OFFSET (0x784)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_FRAME_WRITE_ON_MASK (0x2)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_frame_write_on_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220784L);
    system_hw_write_32(0x220784L, (((uint32_t) (data & 0x1)) << 1) | (curr & 0xfffffffd));
}
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_frame_write_on_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220784L) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: half irate
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 0 = normal operation , 1= write half(alternate) of input frames( only valid for continuous mode)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_HALF_IRATE_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_HALF_IRATE_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_HALF_IRATE_OFFSET (0x784)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_HALF_IRATE_MASK (0x4)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_half_irate_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220784L);
    system_hw_write_32(0x220784L, (((uint32_t) (data & 0x1)) << 2) | (curr & 0xfffffffb));
}
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_half_irate_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220784L) & 0x4) >> 2);
}
// ------------------------------------------------------------------------------ //
// Register: axi xact comp
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 0 = dont wait for axi transaction completion at end of frame(just all transfers accepted). 1 = wait for all transactions completed
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_XACT_COMP_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_XACT_COMP_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_XACT_COMP_OFFSET (0x784)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_XACT_COMP_MASK (0x8)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_axi_xact_comp_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220784L);
    system_hw_write_32(0x220784L, (((uint32_t) (data & 0x1)) << 3) | (curr & 0xfffffff7));
}
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_axi_xact_comp_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220784L) & 0x8) >> 3);
}
// ------------------------------------------------------------------------------ //
// Register: active width
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Active video width in pixels 128-8000
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_ACTIVE_WIDTH_DEFAULT (0x780)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_ACTIVE_WIDTH_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_ACTIVE_WIDTH_OFFSET (0x788)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_ACTIVE_WIDTH_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_active_width_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220788L);
    system_hw_write_32(0x220788L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture1_dma_writer_active_width_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220788L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: active height
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Active video height in lines 128-8000
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_ACTIVE_HEIGHT_DEFAULT (0x438)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_ACTIVE_HEIGHT_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_ACTIVE_HEIGHT_OFFSET (0x78c)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_ACTIVE_HEIGHT_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_active_height_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x22078cL);
    system_hw_write_32(0x22078cL, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture1_dma_writer_active_height_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x22078cL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: bank0_base
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// bank 0 base address for frame buffer, should be word-aligned
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BANK0_BASE_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BANK0_BASE_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BANK0_BASE_OFFSET (0x790)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BANK0_BASE_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_bank0_base_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x220790L, data);
}
static __inline uint32_t acamera_fpga_video_capture1_dma_writer_bank0_base_read(uintptr_t base) {
    return system_hw_read_32(0x220790L);
}
// ------------------------------------------------------------------------------ //
// Register: bank1_base
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// bank 1 base address for frame buffer, should be word-aligned
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BANK1_BASE_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BANK1_BASE_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BANK1_BASE_OFFSET (0x794)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BANK1_BASE_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_bank1_base_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x220794L, data);
}
static __inline uint32_t acamera_fpga_video_capture1_dma_writer_bank1_base_read(uintptr_t base) {
    return system_hw_read_32(0x220794L);
}
// ------------------------------------------------------------------------------ //
// Register: bank2_base
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// bank 2 base address for frame buffer, should be word-aligned
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BANK2_BASE_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BANK2_BASE_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BANK2_BASE_OFFSET (0x798)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BANK2_BASE_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_bank2_base_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x220798L, data);
}
static __inline uint32_t acamera_fpga_video_capture1_dma_writer_bank2_base_read(uintptr_t base) {
    return system_hw_read_32(0x220798L);
}
// ------------------------------------------------------------------------------ //
// Register: bank3_base
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// bank 3 base address for frame buffer, should be word-aligned
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BANK3_BASE_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BANK3_BASE_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BANK3_BASE_OFFSET (0x79c)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BANK3_BASE_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_bank3_base_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x22079cL, data);
}
static __inline uint32_t acamera_fpga_video_capture1_dma_writer_bank3_base_read(uintptr_t base) {
    return system_hw_read_32(0x22079cL);
}
// ------------------------------------------------------------------------------ //
// Register: bank4_base
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// bank 4 base address for frame buffer, should be word-aligned
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BANK4_BASE_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BANK4_BASE_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BANK4_BASE_OFFSET (0x7a0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BANK4_BASE_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_bank4_base_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x2207a0L, data);
}
static __inline uint32_t acamera_fpga_video_capture1_dma_writer_bank4_base_read(uintptr_t base) {
    return system_hw_read_32(0x2207a0L);
}
// ------------------------------------------------------------------------------ //
// Register: max bank
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// highest bank*_base to use for frame writes before recycling to bank0_base, only 0 to 4 are valid
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_MAX_BANK_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_MAX_BANK_DATASIZE (3)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_MAX_BANK_OFFSET (0x7a4)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_MAX_BANK_MASK (0x7)

// args: data (3-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_max_bank_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2207a4L);
    system_hw_write_32(0x2207a4L, (((uint32_t) (data & 0x7)) << 0) | (curr & 0xfffffff8));
}
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_max_bank_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2207a4L) & 0x7) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: bank0 restart
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 0 = normal operation, 1= restart bank counter to bank0 for next frame write
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BANK0_RESTART_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BANK0_RESTART_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BANK0_RESTART_OFFSET (0x7a4)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BANK0_RESTART_MASK (0x8)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_bank0_restart_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2207a4L);
    system_hw_write_32(0x2207a4L, (((uint32_t) (data & 0x1)) << 3) | (curr & 0xfffffff7));
}
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_bank0_restart_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2207a4L) & 0x8) >> 3);
}
// ------------------------------------------------------------------------------ //
// Register: Line_offset
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 
//    Indicates the offset in bytes from the start of one line to the next line.
//    This value should be equal to or larger than one line of image data and should be word-aligned
//    
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_LINE_OFFSET_DEFAULT (0x4000)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_LINE_OFFSET_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_LINE_OFFSET_OFFSET (0x7a8)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_LINE_OFFSET_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_line_offset_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x2207a8L, data);
}
static __inline uint32_t acamera_fpga_video_capture1_dma_writer_line_offset_read(uintptr_t base) {
    return system_hw_read_32(0x2207a8L);
}
// ------------------------------------------------------------------------------ //
// Register: frame write cancel
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 0 = normal operation, 1= cancel current/future frame write(s), any unstarted AXI bursts cancelled and fifo flushed
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_FRAME_WRITE_CANCEL_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_FRAME_WRITE_CANCEL_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_FRAME_WRITE_CANCEL_OFFSET (0x7ac)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_FRAME_WRITE_CANCEL_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_frame_write_cancel_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2207acL);
    system_hw_write_32(0x2207acL, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_frame_write_cancel_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2207acL) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: axi_port_enable
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// enables axi, active high, 1=enables axi write transfers, 0= reset axi domain( via reset synchroniser)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_PORT_ENABLE_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_PORT_ENABLE_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_PORT_ENABLE_OFFSET (0x7ac)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_PORT_ENABLE_MASK (0x2)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_axi_port_enable_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2207acL);
    system_hw_write_32(0x2207acL, (((uint32_t) (data & 0x1)) << 1) | (curr & 0xfffffffd));
}
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_axi_port_enable_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2207acL) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: wbank curr
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// write bank currently active. valid values =0-4. updated at start of frame write
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBANK_CURR_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBANK_CURR_DATASIZE (3)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBANK_CURR_OFFSET (0x7b0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBANK_CURR_MASK (0x7)

// args: data (3-bit)
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_wbank_curr_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2207b0L) & 0x7) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: wbank last
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// write bank last active. valid values = 0-4. updated at start of frame write
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBANK_LAST_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBANK_LAST_DATASIZE (3)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBANK_LAST_OFFSET (0x7b0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBANK_LAST_MASK (0x38)

// args: data (3-bit)
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_wbank_last_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2207b0L) & 0x38) >> 3);
}
// ------------------------------------------------------------------------------ //
// Register: wbank active
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 1 = wbank_curr is being written to. Goes high at start of writes, low at last write transfer/completion on axi. 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBANK_ACTIVE_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBANK_ACTIVE_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBANK_ACTIVE_OFFSET (0x7b4)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBANK_ACTIVE_MASK (0x1)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_wbank_active_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2207b4L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: wbank start
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 1 = High pulse at start of frame write to bank. 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBANK_START_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBANK_START_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBANK_START_OFFSET (0x7b4)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBANK_START_MASK (0x2)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_wbank_start_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2207b4L) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: wbank stop
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 1 = High pulse at end of frame write to bank. 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBANK_STOP_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBANK_STOP_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBANK_STOP_OFFSET (0x7b4)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBANK_STOP_MASK (0x4)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_wbank_stop_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2207b4L) & 0x4) >> 2);
}
// ------------------------------------------------------------------------------ //
// Register: wbase curr
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// currently active bank base addr - in bytes. updated at start of frame write
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBASE_CURR_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBASE_CURR_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBASE_CURR_OFFSET (0x7b8)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBASE_CURR_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture1_dma_writer_wbase_curr_read(uintptr_t base) {
    return system_hw_read_32(0x2207b8L);
}
// ------------------------------------------------------------------------------ //
// Register: wbase last
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// last active bank base addr - in bytes. Updated at start of frame write
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBASE_LAST_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBASE_LAST_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBASE_LAST_OFFSET (0x7bc)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WBASE_LAST_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture1_dma_writer_wbase_last_read(uintptr_t base) {
    return system_hw_read_32(0x2207bcL);
}
// ------------------------------------------------------------------------------ //
// Register: frame icount
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// count of incomming frames (starts) to vdma_writer on video input, non resetable, rolls over, updates at pixel 1 of new frame on video in
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_FRAME_ICOUNT_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_FRAME_ICOUNT_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_FRAME_ICOUNT_OFFSET (0x7c0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_FRAME_ICOUNT_MASK (0xffff)

// args: data (16-bit)
static __inline uint16_t acamera_fpga_video_capture1_dma_writer_frame_icount_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x2207c0L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: frame wcount
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// count of outgoing frame writes (starts) from vdma_writer sent to AXI output, non resetable, rolls over, updates at pixel 1 of new frame on video in
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_FRAME_WCOUNT_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_FRAME_WCOUNT_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_FRAME_WCOUNT_OFFSET (0x7c4)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_FRAME_WCOUNT_MASK (0xffff)

// args: data (16-bit)
static __inline uint16_t acamera_fpga_video_capture1_dma_writer_frame_wcount_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x2207c4L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: clear alarms
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 0>1 transition(synchronous detection) causes local axi/video alarm clear
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_CLEAR_ALARMS_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_CLEAR_ALARMS_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_CLEAR_ALARMS_OFFSET (0x7c8)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_CLEAR_ALARMS_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_clear_alarms_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2207c8L);
    system_hw_write_32(0x2207c8L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_clear_alarms_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2207c8L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: max_burst_length_is_8
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 1= Reduce default AXI max_burst_length from 16 to 8, 0= Dont reduce
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_MAX_BURST_LENGTH_IS_8_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_MAX_BURST_LENGTH_IS_8_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_MAX_BURST_LENGTH_IS_8_OFFSET (0x7c8)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_MAX_BURST_LENGTH_IS_8_MASK (0x2)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_max_burst_length_is_8_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2207c8L);
    system_hw_write_32(0x2207c8L, (((uint32_t) (data & 0x1)) << 1) | (curr & 0xfffffffd));
}
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_max_burst_length_is_8_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2207c8L) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: max_burst_length_is_4
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 1= Reduce default AXI max_burst_length from 16 to 4, 0= Dont reduce( has priority overmax_burst_length_is_8!)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_MAX_BURST_LENGTH_IS_4_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_MAX_BURST_LENGTH_IS_4_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_MAX_BURST_LENGTH_IS_4_OFFSET (0x7c8)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_MAX_BURST_LENGTH_IS_4_MASK (0x4)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_max_burst_length_is_4_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2207c8L);
    system_hw_write_32(0x2207c8L, (((uint32_t) (data & 0x1)) << 2) | (curr & 0xfffffffb));
}
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_max_burst_length_is_4_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2207c8L) & 0x4) >> 2);
}
// ------------------------------------------------------------------------------ //
// Register: write timeout disable
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 
//    At end of frame an optional timeout is applied to wait for AXI writes to completed/accepted befotre caneclling and flushing.
//    0= Timeout Enabled, timeout count can decrement.
//    1 = Disable timeout, timeout count can't decrement.
//    
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WRITE_TIMEOUT_DISABLE_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WRITE_TIMEOUT_DISABLE_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WRITE_TIMEOUT_DISABLE_OFFSET (0x7c8)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WRITE_TIMEOUT_DISABLE_MASK (0x8)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_write_timeout_disable_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2207c8L);
    system_hw_write_32(0x2207c8L, (((uint32_t) (data & 0x1)) << 3) | (curr & 0xfffffff7));
}
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_write_timeout_disable_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2207c8L) & 0x8) >> 3);
}
// ------------------------------------------------------------------------------ //
// Register: awmaxwait_limit
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// awvalid maxwait limit(cycles) to raise axi_fail_awmaxwait alarm . zero disables alarm raise.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AWMAXWAIT_LIMIT_DEFAULT (0x00)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AWMAXWAIT_LIMIT_DATASIZE (8)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AWMAXWAIT_LIMIT_OFFSET (0x7cc)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AWMAXWAIT_LIMIT_MASK (0xff)

// args: data (8-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_awmaxwait_limit_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2207ccL);
    system_hw_write_32(0x2207ccL, (((uint32_t) (data & 0xff)) << 0) | (curr & 0xffffff00));
}
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_awmaxwait_limit_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2207ccL) & 0xff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: wmaxwait_limit
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// wvalid maxwait limit(cycles) to raise axi_fail_wmaxwait alarm . zero disables alarm raise
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WMAXWAIT_LIMIT_DEFAULT (0x00)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WMAXWAIT_LIMIT_DATASIZE (8)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WMAXWAIT_LIMIT_OFFSET (0x7d0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WMAXWAIT_LIMIT_MASK (0xff)

// args: data (8-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_wmaxwait_limit_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2207d0L);
    system_hw_write_32(0x2207d0L, (((uint32_t) (data & 0xff)) << 0) | (curr & 0xffffff00));
}
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_wmaxwait_limit_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2207d0L) & 0xff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: wxact_ostand_limit
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// number oustsanding write transactions(bursts)(responses..1 per burst) limit to raise axi_fail_wxact_ostand. zero disables alarm raise
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WXACT_OSTAND_LIMIT_DEFAULT (0x00)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WXACT_OSTAND_LIMIT_DATASIZE (8)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WXACT_OSTAND_LIMIT_OFFSET (0x7d4)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_WXACT_OSTAND_LIMIT_MASK (0xff)

// args: data (8-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_wxact_ostand_limit_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2207d4L);
    system_hw_write_32(0x2207d4L, (((uint32_t) (data & 0xff)) << 0) | (curr & 0xffffff00));
}
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_wxact_ostand_limit_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2207d4L) & 0xff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: axi_fail_bresp
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  clearable alarm, high to indicate bad  bresp captured 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_FAIL_BRESP_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_FAIL_BRESP_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_FAIL_BRESP_OFFSET (0x7d8)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_FAIL_BRESP_MASK (0x1)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_axi_fail_bresp_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2207d8L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: axi_fail_awmaxwait
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  clearable alarm, high when awmaxwait_limit reached 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_FAIL_AWMAXWAIT_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_FAIL_AWMAXWAIT_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_FAIL_AWMAXWAIT_OFFSET (0x7d8)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_FAIL_AWMAXWAIT_MASK (0x2)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_axi_fail_awmaxwait_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2207d8L) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: axi_fail_wmaxwait
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  clearable alarm, high when wmaxwait_limit reached 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_FAIL_WMAXWAIT_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_FAIL_WMAXWAIT_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_FAIL_WMAXWAIT_OFFSET (0x7d8)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_FAIL_WMAXWAIT_MASK (0x4)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_axi_fail_wmaxwait_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2207d8L) & 0x4) >> 2);
}
// ------------------------------------------------------------------------------ //
// Register: axi_fail_wxact_ostand
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  clearable alarm, high when wxact_ostand_limit reached 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_FAIL_WXACT_OSTAND_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_FAIL_WXACT_OSTAND_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_FAIL_WXACT_OSTAND_OFFSET (0x7d8)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_FAIL_WXACT_OSTAND_MASK (0x8)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_axi_fail_wxact_ostand_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2207d8L) & 0x8) >> 3);
}
// ------------------------------------------------------------------------------ //
// Register: vi_fail_active_width
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  clearable alarm, high to indicate mismatched active_width detected 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_VI_FAIL_ACTIVE_WIDTH_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_VI_FAIL_ACTIVE_WIDTH_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_VI_FAIL_ACTIVE_WIDTH_OFFSET (0x7d8)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_VI_FAIL_ACTIVE_WIDTH_MASK (0x10)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_vi_fail_active_width_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2207d8L) & 0x10) >> 4);
}
// ------------------------------------------------------------------------------ //
// Register: vi_fail_active_height
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  clearable alarm, high to indicate mismatched active_height detected ( also raised on missing field!) 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_VI_FAIL_ACTIVE_HEIGHT_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_VI_FAIL_ACTIVE_HEIGHT_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_VI_FAIL_ACTIVE_HEIGHT_OFFSET (0x7d8)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_VI_FAIL_ACTIVE_HEIGHT_MASK (0x20)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_vi_fail_active_height_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2207d8L) & 0x20) >> 5);
}
// ------------------------------------------------------------------------------ //
// Register: vi_fail_interline_blanks
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  clearable alarm, high to indicate interline blanking below min 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_VI_FAIL_INTERLINE_BLANKS_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_VI_FAIL_INTERLINE_BLANKS_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_VI_FAIL_INTERLINE_BLANKS_OFFSET (0x7d8)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_VI_FAIL_INTERLINE_BLANKS_MASK (0x40)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_vi_fail_interline_blanks_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2207d8L) & 0x40) >> 6);
}
// ------------------------------------------------------------------------------ //
// Register: vi_fail_interframe_blanks
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  clearable alarm, high to indicate interframe blanking below min 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_VI_FAIL_INTERFRAME_BLANKS_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_VI_FAIL_INTERFRAME_BLANKS_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_VI_FAIL_INTERFRAME_BLANKS_OFFSET (0x7d8)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_VI_FAIL_INTERFRAME_BLANKS_MASK (0x80)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_vi_fail_interframe_blanks_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2207d8L) & 0x80) >> 7);
}
// ------------------------------------------------------------------------------ //
// Register: video_alarm
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  active high, problem found on video port(s) ( active width/height or interline/frame blanks failure) 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_VIDEO_ALARM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_VIDEO_ALARM_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_VIDEO_ALARM_OFFSET (0x7dc)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_VIDEO_ALARM_MASK (0x1)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_video_alarm_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2207dcL) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: axi_alarm
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  active high, problem found on axi port(s)( bresp or awmaxwait or wmaxwait or wxact_ostand failure ) 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_ALARM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_ALARM_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_ALARM_OFFSET (0x7dc)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_AXI_ALARM_MASK (0x2)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture1_dma_writer_axi_alarm_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2207dcL) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: blk_config
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// block configuration (reserved)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BLK_CONFIG_DEFAULT (0x0000)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BLK_CONFIG_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BLK_CONFIG_OFFSET (0x7e0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BLK_CONFIG_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_video_capture1_dma_writer_blk_config_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x2207e0L, data);
}
static __inline uint32_t acamera_fpga_video_capture1_dma_writer_blk_config_read(uintptr_t base) {
    return system_hw_read_32(0x2207e0L);
}
// ------------------------------------------------------------------------------ //
// Register: blk_status
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// block status output (reserved)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BLK_STATUS_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BLK_STATUS_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BLK_STATUS_OFFSET (0x7e4)
#define ACAMERA_FPGA_VIDEO_CAPTURE1_DMA_WRITER_BLK_STATUS_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture1_dma_writer_blk_status_read(uintptr_t base) {
    return system_hw_read_32(0x2207e4L);
}
// ------------------------------------------------------------------------------ //
// Group: Video-Capture-2 Input port
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Controls video input port.  
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Register: preset
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 
//        Allows selection of various input port presets for standard sensor inputs.  See ISP Guide for details of available presets.
//        0-14: Frequently used presets.  If using one of available presets, remaining bits in registers 0x100 and 0x104 are not used.
//        15:   Input port configured according to registers in 0x100 and 0x104.  Consult Apical support for special input port requirements.
//      
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_PRESET_DEFAULT (2)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_PRESET_DATASIZE (4)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_PRESET_OFFSET (0x800)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_PRESET_MASK (0xf)

// args: data (4-bit)
static __inline void acamera_fpga_video_capture2_input_port_preset_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220800L);
    system_hw_write_32(0x220800L, (((uint32_t) (data & 0xf)) << 0) | (curr & 0xfffffff0));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_preset_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220800L) & 0xf) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: vs_use field
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VS_USE_FIELD_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VS_USE_FIELD_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VS_USE_FIELD_OFFSET (0x800)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VS_USE_FIELD_MASK (0x100)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VS_USE_FIELD_USE_VSYNC_I_PORT_FOR_VERTICAL_SYNC (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VS_USE_FIELD_USE_FIELD_I_PORT_FOR_VERTICAL_SYNC (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_vs_use_field_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220800L);
    system_hw_write_32(0x220800L, (((uint32_t) (data & 0x1)) << 8) | (curr & 0xfffffeff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_vs_use_field_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220800L) & 0x100) >> 8);
}
// ------------------------------------------------------------------------------ //
// Register: vs toggle
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VS_TOGGLE_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VS_TOGGLE_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VS_TOGGLE_OFFSET (0x800)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VS_TOGGLE_MASK (0x200)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VS_TOGGLE_VSYNC_IS_PULSETYPE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VS_TOGGLE_VSYNC_IS_TOGGLETYPE_FIELD_SIGNAL (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_vs_toggle_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220800L);
    system_hw_write_32(0x220800L, (((uint32_t) (data & 0x1)) << 9) | (curr & 0xfffffdff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_vs_toggle_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220800L) & 0x200) >> 9);
}
// ------------------------------------------------------------------------------ //
// Register: vs polarity
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VS_POLARITY_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VS_POLARITY_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VS_POLARITY_OFFSET (0x800)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VS_POLARITY_MASK (0x400)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VS_POLARITY_HORIZONTAL_COUNTER_RESET_ON_RISING_EDGE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VS_POLARITY_HORIZONTAL_COUNTER_RESET_ON_FALLING_EDGE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_vs_polarity_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220800L);
    system_hw_write_32(0x220800L, (((uint32_t) (data & 0x1)) << 10) | (curr & 0xfffffbff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_vs_polarity_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220800L) & 0x400) >> 10);
}
// ------------------------------------------------------------------------------ //
// Register: vs_polarity acl
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VS_POLARITY_ACL_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VS_POLARITY_ACL_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VS_POLARITY_ACL_OFFSET (0x800)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VS_POLARITY_ACL_MASK (0x800)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VS_POLARITY_ACL_DONT_INVERT_POLARITY_FOR_ACL_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VS_POLARITY_ACL_INVERT_POLARITY_FOR_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_vs_polarity_acl_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220800L);
    system_hw_write_32(0x220800L, (((uint32_t) (data & 0x1)) << 11) | (curr & 0xfffff7ff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_vs_polarity_acl_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220800L) & 0x800) >> 11);
}
// ------------------------------------------------------------------------------ //
// Register: hs_use acl
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_USE_ACL_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_USE_ACL_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_USE_ACL_OFFSET (0x800)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_USE_ACL_MASK (0x1000)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_USE_ACL_USE_HSYNC_I_PORT_FOR_ACTIVELINE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_USE_ACL_USE_ACL_I_PORT_FOR_ACTIVELINE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_hs_use_acl_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220800L);
    system_hw_write_32(0x220800L, (((uint32_t) (data & 0x1)) << 12) | (curr & 0xffffefff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_hs_use_acl_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220800L) & 0x1000) >> 12);
}
// ------------------------------------------------------------------------------ //
// Register: vc_c select
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VC_C_SELECT_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VC_C_SELECT_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VC_C_SELECT_OFFSET (0x800)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VC_C_SELECT_MASK (0x4000)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VC_C_SELECT_VERTICAL_COUNTER_COUNTS_ON_HS (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VC_C_SELECT_VERTICAL_COUNTER_COUNTS_ON_HORIZONTAL_COUNTER_OVERFLOW_OR_RESET (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_vc_c_select_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220800L);
    system_hw_write_32(0x220800L, (((uint32_t) (data & 0x1)) << 14) | (curr & 0xffffbfff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_vc_c_select_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220800L) & 0x4000) >> 14);
}
// ------------------------------------------------------------------------------ //
// Register: vc_r select
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VC_R_SELECT_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VC_R_SELECT_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VC_R_SELECT_OFFSET (0x800)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VC_R_SELECT_MASK (0x8000)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VC_R_SELECT_VERTICAL_COUNTER_IS_RESET_ON_EDGE_OF_VS (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VC_R_SELECT_VERTICAL_COUNTER_IS_RESET_AFTER_TIMEOUT_ON_HS (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_vc_r_select_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220800L);
    system_hw_write_32(0x220800L, (((uint32_t) (data & 0x1)) << 15) | (curr & 0xffff7fff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_vc_r_select_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220800L) & 0x8000) >> 15);
}
// ------------------------------------------------------------------------------ //
// Register: hs_xor vs
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_XOR_VS_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_XOR_VS_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_XOR_VS_OFFSET (0x800)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_XOR_VS_MASK (0x10000)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_XOR_VS_NORMAL_MODE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_XOR_VS_HVALID__HSYNC_XOR_VSYNC (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_hs_xor_vs_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220800L);
    system_hw_write_32(0x220800L, (((uint32_t) (data & 0x1)) << 16) | (curr & 0xfffeffff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_hs_xor_vs_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220800L) & 0x10000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: hs polarity
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_POLARITY_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_POLARITY_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_POLARITY_OFFSET (0x800)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_POLARITY_MASK (0x20000)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_POLARITY_DONT_INVERT_POLARITY_OF_HS_FOR_ACL_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_POLARITY_INVERT_POLARITY_OF_HS_FOR_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_hs_polarity_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220800L);
    system_hw_write_32(0x220800L, (((uint32_t) (data & 0x1)) << 17) | (curr & 0xfffdffff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_hs_polarity_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220800L) & 0x20000) >> 17);
}
// ------------------------------------------------------------------------------ //
// Register: hs_polarity acl
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_POLARITY_ACL_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_POLARITY_ACL_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_POLARITY_ACL_OFFSET (0x800)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_POLARITY_ACL_MASK (0x40000)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_POLARITY_ACL_DONT_INVERT_POLARITY_OF_HS_FOR_HS_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_POLARITY_ACL_INVERT_POLARITY_OF_HS_FOR_HS_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_hs_polarity_acl_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220800L);
    system_hw_write_32(0x220800L, (((uint32_t) (data & 0x1)) << 18) | (curr & 0xfffbffff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_hs_polarity_acl_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220800L) & 0x40000) >> 18);
}
// ------------------------------------------------------------------------------ //
// Register: hs_polarity hs
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_POLARITY_HS_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_POLARITY_HS_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_POLARITY_HS_OFFSET (0x800)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_POLARITY_HS_MASK (0x80000)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_POLARITY_HS_HORIZONTAL_COUNTER_IS_RESET_ON_RISING_EDGE_OF_HS (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_POLARITY_HS_HORIZONTAL_COUNTER_IS_RESET_ON_VSYNC_EG_WHEN_HSYNC_IS_NOT_AVAILABLE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_hs_polarity_hs_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220800L);
    system_hw_write_32(0x220800L, (((uint32_t) (data & 0x1)) << 19) | (curr & 0xfff7ffff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_hs_polarity_hs_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220800L) & 0x80000) >> 19);
}
// ------------------------------------------------------------------------------ //
// Register: hs_polarity vc
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_POLARITY_VC_DEFAULT (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_POLARITY_VC_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_POLARITY_VC_OFFSET (0x800)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_POLARITY_VC_MASK (0x100000)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_POLARITY_VC_VERTICAL_COUNTER_INCREMENTS_ON_RISING_EDGE_OF_HS (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HS_POLARITY_VC_VERTICAL_COUNTER_INCREMENTS_ON_FALLING_EDGE_OF_HS (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_hs_polarity_vc_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220800L);
    system_hw_write_32(0x220800L, (((uint32_t) (data & 0x1)) << 20) | (curr & 0xffefffff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_hs_polarity_vc_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220800L) & 0x100000) >> 20);
}
// ------------------------------------------------------------------------------ //
// Register: hc_r select
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HC_R_SELECT_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HC_R_SELECT_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HC_R_SELECT_OFFSET (0x800)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HC_R_SELECT_MASK (0x800000)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HC_R_SELECT_VERTICAL_COUNTER_IS_RESET_ON_RISING_EDGE_OF_HS (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HC_R_SELECT_VERTICAL_COUNTER_IS_RESET_ON_RISING_EDGE_OF_VS (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_hc_r_select_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220800L);
    system_hw_write_32(0x220800L, (((uint32_t) (data & 0x1)) << 23) | (curr & 0xff7fffff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_hc_r_select_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220800L) & 0x800000) >> 23);
}
// ------------------------------------------------------------------------------ //
// Register: acl polarity
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACL_POLARITY_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACL_POLARITY_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACL_POLARITY_OFFSET (0x800)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACL_POLARITY_MASK (0x1000000)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACL_POLARITY_DONT_INVERT_ACL_I_FOR_ACL_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACL_POLARITY_INVERT_ACL_I_FOR_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_acl_polarity_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220800L);
    system_hw_write_32(0x220800L, (((uint32_t) (data & 0x1)) << 24) | (curr & 0xfeffffff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_acl_polarity_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220800L) & 0x1000000) >> 24);
}
// ------------------------------------------------------------------------------ //
// Register: field polarity
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELD_POLARITY_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELD_POLARITY_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELD_POLARITY_OFFSET (0x804)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELD_POLARITY_MASK (0x1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELD_POLARITY_DONT_INVERT_FIELD_I_FOR_FIELD_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELD_POLARITY_INVERT_FIELD_I_FOR_FIELD_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_field_polarity_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220804L);
    system_hw_write_32(0x220804L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_field_polarity_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220804L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: field toggle
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELD_TOGGLE_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELD_TOGGLE_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELD_TOGGLE_OFFSET (0x804)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELD_TOGGLE_MASK (0x2)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELD_TOGGLE_FIELD_IS_PULSETYPE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELD_TOGGLE_FIELD_IS_TOGGLETYPE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_field_toggle_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220804L);
    system_hw_write_32(0x220804L, (((uint32_t) (data & 0x1)) << 1) | (curr & 0xfffffffd));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_field_toggle_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220804L) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: aclg window0
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_WINDOW0_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_WINDOW0_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_WINDOW0_OFFSET (0x804)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_WINDOW0_MASK (0x100)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_WINDOW0_EXCLUDE_WINDOW0_SIGNAL_IN_ACL_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_WINDOW0_INCLUDE_WINDOW0_SIGNAL_IN_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_aclg_window0_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220804L);
    system_hw_write_32(0x220804L, (((uint32_t) (data & 0x1)) << 8) | (curr & 0xfffffeff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_aclg_window0_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220804L) & 0x100) >> 8);
}
// ------------------------------------------------------------------------------ //
// Register: aclg hsync
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_HSYNC_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_HSYNC_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_HSYNC_OFFSET (0x804)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_HSYNC_MASK (0x200)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_HSYNC_EXCLUDE_HSYNC_SIGNAL_IN_ACL_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_HSYNC_INCLUDE_HSYNC_SIGNAL_IN_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_aclg_hsync_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220804L);
    system_hw_write_32(0x220804L, (((uint32_t) (data & 0x1)) << 9) | (curr & 0xfffffdff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_aclg_hsync_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220804L) & 0x200) >> 9);
}
// ------------------------------------------------------------------------------ //
// Register: aclg window2
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_WINDOW2_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_WINDOW2_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_WINDOW2_OFFSET (0x804)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_WINDOW2_MASK (0x400)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_WINDOW2_EXCLUDE_WINDOW2_SIGNAL_IN_ACL_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_WINDOW2_INCLUDE_WINDOW2_SIGNAL_IN_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_aclg_window2_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220804L);
    system_hw_write_32(0x220804L, (((uint32_t) (data & 0x1)) << 10) | (curr & 0xfffffbff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_aclg_window2_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220804L) & 0x400) >> 10);
}
// ------------------------------------------------------------------------------ //
// Register: aclg acl
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_ACL_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_ACL_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_ACL_OFFSET (0x804)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_ACL_MASK (0x800)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_ACL_EXCLUDE_ACL_I_SIGNAL_IN_ACL_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_ACL_INCLUDE_ACL_I_SIGNAL_IN_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_aclg_acl_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220804L);
    system_hw_write_32(0x220804L, (((uint32_t) (data & 0x1)) << 11) | (curr & 0xfffff7ff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_aclg_acl_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220804L) & 0x800) >> 11);
}
// ------------------------------------------------------------------------------ //
// Register: aclg vsync
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_VSYNC_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_VSYNC_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_VSYNC_OFFSET (0x804)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_VSYNC_MASK (0x1000)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_VSYNC_EXCLUDE_VSYNC_SIGNAL_IN_ACL_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_ACLG_VSYNC_INCLUDE_VSYNC_SIGNAL_IN_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_aclg_vsync_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220804L);
    system_hw_write_32(0x220804L, (((uint32_t) (data & 0x1)) << 12) | (curr & 0xffffefff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_aclg_vsync_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220804L) & 0x1000) >> 12);
}
// ------------------------------------------------------------------------------ //
// Register: hsg window1
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HSG_WINDOW1_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HSG_WINDOW1_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HSG_WINDOW1_OFFSET (0x804)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HSG_WINDOW1_MASK (0x10000)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HSG_WINDOW1_EXCLUDE_WINDOW1_SIGNAL_IN_HS_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HSG_WINDOW1_INCLUDE_WINDOW1_SIGNAL_IN_HS_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_hsg_window1_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220804L);
    system_hw_write_32(0x220804L, (((uint32_t) (data & 0x1)) << 16) | (curr & 0xfffeffff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_hsg_window1_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220804L) & 0x10000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: hsg hsync
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HSG_HSYNC_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HSG_HSYNC_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HSG_HSYNC_OFFSET (0x804)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HSG_HSYNC_MASK (0x20000)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HSG_HSYNC_EXCLUDE_HSYNC_SIGNAL_IN_HS_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HSG_HSYNC_INCLUDE_HSYNC_SIGNAL_IN_HS_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_hsg_hsync_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220804L);
    system_hw_write_32(0x220804L, (((uint32_t) (data & 0x1)) << 17) | (curr & 0xfffdffff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_hsg_hsync_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220804L) & 0x20000) >> 17);
}
// ------------------------------------------------------------------------------ //
// Register: hsg vsync
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HSG_VSYNC_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HSG_VSYNC_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HSG_VSYNC_OFFSET (0x804)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HSG_VSYNC_MASK (0x40000)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HSG_VSYNC_EXCLUDE_VSYNC_SIGNAL_IN_HS_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HSG_VSYNC_INCLUDE_VSYNC_SIGNAL_IN_HS_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_hsg_vsync_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220804L);
    system_hw_write_32(0x220804L, (((uint32_t) (data & 0x1)) << 18) | (curr & 0xfffbffff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_hsg_vsync_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220804L) & 0x40000) >> 18);
}
// ------------------------------------------------------------------------------ //
// Register: hsg window2
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HSG_WINDOW2_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HSG_WINDOW2_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HSG_WINDOW2_OFFSET (0x804)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HSG_WINDOW2_MASK (0x80000)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HSG_WINDOW2_EXCLUDE_WINDOW2_SIGNAL_IN_HS_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HSG_WINDOW2_INCLUDE_WINDOW2_SIGNAL_IN_HS_GATE_MASK_OUT_SPURIOUS_HS_DURING_BLANK (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_hsg_window2_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220804L);
    system_hw_write_32(0x220804L, (((uint32_t) (data & 0x1)) << 19) | (curr & 0xfff7ffff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_hsg_window2_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220804L) & 0x80000) >> 19);
}
// ------------------------------------------------------------------------------ //
// Register: fieldg vsync
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELDG_VSYNC_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELDG_VSYNC_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELDG_VSYNC_OFFSET (0x804)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELDG_VSYNC_MASK (0x1000000)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELDG_VSYNC_EXCLUDE_VSYNC_SIGNAL_IN_FIELD_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELDG_VSYNC_INCLUDE_VSYNC_SIGNAL_IN_FIELD_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_fieldg_vsync_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220804L);
    system_hw_write_32(0x220804L, (((uint32_t) (data & 0x1)) << 24) | (curr & 0xfeffffff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_fieldg_vsync_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220804L) & 0x1000000) >> 24);
}
// ------------------------------------------------------------------------------ //
// Register: fieldg window2
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELDG_WINDOW2_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELDG_WINDOW2_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELDG_WINDOW2_OFFSET (0x804)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELDG_WINDOW2_MASK (0x2000000)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELDG_WINDOW2_EXCLUDE_WINDOW2_SIGNAL_IN_FIELD_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELDG_WINDOW2_INCLUDE_WINDOW2_SIGNAL_IN_FIELD_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_fieldg_window2_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220804L);
    system_hw_write_32(0x220804L, (((uint32_t) (data & 0x1)) << 25) | (curr & 0xfdffffff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_fieldg_window2_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220804L) & 0x2000000) >> 25);
}
// ------------------------------------------------------------------------------ //
// Register: fieldg field
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELDG_FIELD_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELDG_FIELD_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELDG_FIELD_OFFSET (0x804)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELDG_FIELD_MASK (0x4000000)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELDG_FIELD_EXCLUDE_FIELD_I_SIGNAL_IN_FIELD_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELDG_FIELD_INCLUDE_FIELD_I_SIGNAL_IN_FIELD_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_fieldg_field_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220804L);
    system_hw_write_32(0x220804L, (((uint32_t) (data & 0x1)) << 26) | (curr & 0xfbffffff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_fieldg_field_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220804L) & 0x4000000) >> 26);
}
// ------------------------------------------------------------------------------ //
// Register: field mode
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELD_MODE_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELD_MODE_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELD_MODE_OFFSET (0x804)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELD_MODE_MASK (0x8000000)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELD_MODE_PULSE_FIELD (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FIELD_MODE_TOGGLE_FIELD (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_field_mode_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220804L);
    system_hw_write_32(0x220804L, (((uint32_t) (data & 0x1)) << 27) | (curr & 0xf7ffffff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_field_mode_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220804L) & 0x8000000) >> 27);
}
// ------------------------------------------------------------------------------ //
// Register: hc limit
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// horizontal counter limit value (counts: 0,1,...hc_limit-1,hc_limit,0,1,...)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HC_LIMIT_DEFAULT (0xFFFF)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HC_LIMIT_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HC_LIMIT_OFFSET (0x808)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HC_LIMIT_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture2_input_port_hc_limit_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220808L);
    system_hw_write_32(0x220808L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture2_input_port_hc_limit_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220808L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: hc start0
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// window0 start for ACL gate.  See ISP guide for further details.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HC_START0_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HC_START0_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HC_START0_OFFSET (0x80c)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HC_START0_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture2_input_port_hc_start0_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x22080cL);
    system_hw_write_32(0x22080cL, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture2_input_port_hc_start0_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x22080cL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: hc size0
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// window0 size for ACL gate.  See ISP guide for further details.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HC_SIZE0_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HC_SIZE0_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HC_SIZE0_OFFSET (0x810)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HC_SIZE0_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture2_input_port_hc_size0_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220810L);
    system_hw_write_32(0x220810L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture2_input_port_hc_size0_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220810L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: hc start1
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// window1 start for HS gate.  See ISP guide for further details.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HC_START1_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HC_START1_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HC_START1_OFFSET (0x814)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HC_START1_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture2_input_port_hc_start1_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220814L);
    system_hw_write_32(0x220814L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture2_input_port_hc_start1_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220814L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: hc size1
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// window1 size for HS gate.  See ISP guide for further details.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HC_SIZE1_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HC_SIZE1_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HC_SIZE1_OFFSET (0x818)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_HC_SIZE1_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture2_input_port_hc_size1_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220818L);
    system_hw_write_32(0x220818L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture2_input_port_hc_size1_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220818L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: vc limit
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// vertical counter limit value (counts: 0,1,...vc_limit-1,vc_limit,0,1,...)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VC_LIMIT_DEFAULT (0xFFFF)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VC_LIMIT_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VC_LIMIT_OFFSET (0x81c)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VC_LIMIT_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture2_input_port_vc_limit_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x22081cL);
    system_hw_write_32(0x22081cL, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture2_input_port_vc_limit_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x22081cL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: vc start
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// window2 start for ACL gate.  See ISP guide for further details.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VC_START_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VC_START_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VC_START_OFFSET (0x820)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VC_START_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture2_input_port_vc_start_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220820L);
    system_hw_write_32(0x220820L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture2_input_port_vc_start_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220820L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: vc size
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// window2 size for ACL gate.  See ISP guide for further details.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VC_SIZE_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VC_SIZE_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VC_SIZE_OFFSET (0x824)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_VC_SIZE_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture2_input_port_vc_size_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220824L);
    system_hw_write_32(0x220824L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture2_input_port_vc_size_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220824L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: frame width
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// detected frame width.  Read only value.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FRAME_WIDTH_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FRAME_WIDTH_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FRAME_WIDTH_OFFSET (0x828)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FRAME_WIDTH_MASK (0xffff)

// args: data (16-bit)
static __inline uint16_t acamera_fpga_video_capture2_input_port_frame_width_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220828L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: frame height
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// detected frame height.  Read only value.  
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FRAME_HEIGHT_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FRAME_HEIGHT_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FRAME_HEIGHT_OFFSET (0x82c)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FRAME_HEIGHT_MASK (0xffff)

// args: data (16-bit)
static __inline uint16_t acamera_fpga_video_capture2_input_port_frame_height_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x22082cL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: mode request
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Used to stop and start input port.  See ISP guide for further details. 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_MODE_REQUEST_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_MODE_REQUEST_DATASIZE (3)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_MODE_REQUEST_OFFSET (0x830)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_MODE_REQUEST_MASK (0x7)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_MODE_REQUEST_SAFE_STOP (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_MODE_REQUEST_SAFE_START (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_MODE_REQUEST_URGENT_STOP (2)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_MODE_REQUEST_URGENT_START (3)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_MODE_REQUEST_RESERVED4 (4)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_MODE_REQUEST_SAFER_START (5)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_MODE_REQUEST_RESERVED6 (6)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_MODE_REQUEST_RESERVED7 (7)

// args: data (3-bit)
static __inline void acamera_fpga_video_capture2_input_port_mode_request_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220830L);
    system_hw_write_32(0x220830L, (((uint32_t) (data & 0x7)) << 0) | (curr & 0xfffffff8));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_mode_request_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220830L) & 0x7) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: freeze config
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Used to freeze input port configuration.  Used when multiple register writes are required to change input port configuration. 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FREEZE_CONFIG_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FREEZE_CONFIG_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FREEZE_CONFIG_OFFSET (0x830)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FREEZE_CONFIG_MASK (0x80)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FREEZE_CONFIG_NORMAL_OPERATION (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_FREEZE_CONFIG_HOLD_PREVIOUS_INPUT_PORT_CONFIG_STATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_input_port_freeze_config_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220830L);
    system_hw_write_32(0x220830L, (((uint32_t) (data & 0x1)) << 7) | (curr & 0xffffff7f));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_freeze_config_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220830L) & 0x80) >> 7);
}
// ------------------------------------------------------------------------------ //
// Register: mode status
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 
//          Used to monitor input port status:
//          bit 0: 1=running, 0=stopped, bits 1,2-reserved
//        
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_MODE_STATUS_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_MODE_STATUS_DATASIZE (3)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_MODE_STATUS_OFFSET (0x834)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_MODE_STATUS_MASK (0x7)

// args: data (3-bit)
static __inline uint8_t acamera_fpga_video_capture2_input_port_mode_status_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220834L) & 0x7) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: source
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 
//          Select source for capture:
//          0=sensor, 1=ISP video input, 2=ISP FR video output, 3=ISP DS video output
//        
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_SOURCE_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_SOURCE_DATASIZE (2)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_SOURCE_OFFSET (0x834)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_INPUT_PORT_SOURCE_MASK (0x30000)

// args: data (2-bit)
static __inline void acamera_fpga_video_capture2_input_port_source_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220834L);
    system_hw_write_32(0x220834L, (((uint32_t) (data & 0x3)) << 16) | (curr & 0xfffcffff));
}
static __inline uint8_t acamera_fpga_video_capture2_input_port_source_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220834L) & 0x30000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Group: Video-Capture-2 Frame Stats
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Register: stats reset
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_STATS_RESET_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_STATS_RESET_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_STATS_RESET_OFFSET (0x880)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_STATS_RESET_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_frame_stats_stats_reset_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220880L);
    system_hw_write_32(0x220880L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_video_capture2_frame_stats_stats_reset_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220880L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: stats hold
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_STATS_HOLD_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_STATS_HOLD_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_STATS_HOLD_OFFSET (0x884)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_STATS_HOLD_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_frame_stats_stats_hold_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220884L);
    system_hw_write_32(0x220884L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_video_capture2_frame_stats_stats_hold_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220884L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: active width min
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_WIDTH_MIN_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_WIDTH_MIN_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_WIDTH_MIN_OFFSET (0x890)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_WIDTH_MIN_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture2_frame_stats_active_width_min_read(uintptr_t base) {
    return system_hw_read_32(0x220890L);
}
// ------------------------------------------------------------------------------ //
// Register: active width max
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_WIDTH_MAX_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_WIDTH_MAX_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_WIDTH_MAX_OFFSET (0x894)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_WIDTH_MAX_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture2_frame_stats_active_width_max_read(uintptr_t base) {
    return system_hw_read_32(0x220894L);
}
// ------------------------------------------------------------------------------ //
// Register: active width sum
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_WIDTH_SUM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_WIDTH_SUM_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_WIDTH_SUM_OFFSET (0x898)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_WIDTH_SUM_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture2_frame_stats_active_width_sum_read(uintptr_t base) {
    return system_hw_read_32(0x220898L);
}
// ------------------------------------------------------------------------------ //
// Register: active width num
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_WIDTH_NUM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_WIDTH_NUM_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_WIDTH_NUM_OFFSET (0x89c)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_WIDTH_NUM_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture2_frame_stats_active_width_num_read(uintptr_t base) {
    return system_hw_read_32(0x22089cL);
}
// ------------------------------------------------------------------------------ //
// Register: active height min
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_HEIGHT_MIN_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_HEIGHT_MIN_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_HEIGHT_MIN_OFFSET (0x8a0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_HEIGHT_MIN_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture2_frame_stats_active_height_min_read(uintptr_t base) {
    return system_hw_read_32(0x2208a0L);
}
// ------------------------------------------------------------------------------ //
// Register: active height max
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_HEIGHT_MAX_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_HEIGHT_MAX_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_HEIGHT_MAX_OFFSET (0x8a4)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_HEIGHT_MAX_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture2_frame_stats_active_height_max_read(uintptr_t base) {
    return system_hw_read_32(0x2208a4L);
}
// ------------------------------------------------------------------------------ //
// Register: active height sum
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_HEIGHT_SUM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_HEIGHT_SUM_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_HEIGHT_SUM_OFFSET (0x8a8)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_HEIGHT_SUM_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture2_frame_stats_active_height_sum_read(uintptr_t base) {
    return system_hw_read_32(0x2208a8L);
}
// ------------------------------------------------------------------------------ //
// Register: active height num
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_HEIGHT_NUM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_HEIGHT_NUM_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_HEIGHT_NUM_OFFSET (0x8ac)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_ACTIVE_HEIGHT_NUM_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture2_frame_stats_active_height_num_read(uintptr_t base) {
    return system_hw_read_32(0x2208acL);
}
// ------------------------------------------------------------------------------ //
// Register: hblank min
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_HBLANK_MIN_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_HBLANK_MIN_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_HBLANK_MIN_OFFSET (0x8b0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_HBLANK_MIN_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture2_frame_stats_hblank_min_read(uintptr_t base) {
    return system_hw_read_32(0x2208b0L);
}
// ------------------------------------------------------------------------------ //
// Register: hblank max
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_HBLANK_MAX_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_HBLANK_MAX_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_HBLANK_MAX_OFFSET (0x8b4)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_HBLANK_MAX_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture2_frame_stats_hblank_max_read(uintptr_t base) {
    return system_hw_read_32(0x2208b4L);
}
// ------------------------------------------------------------------------------ //
// Register: hblank sum
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_HBLANK_SUM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_HBLANK_SUM_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_HBLANK_SUM_OFFSET (0x8b8)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_HBLANK_SUM_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture2_frame_stats_hblank_sum_read(uintptr_t base) {
    return system_hw_read_32(0x2208b8L);
}
// ------------------------------------------------------------------------------ //
// Register: hblank num
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_HBLANK_NUM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_HBLANK_NUM_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_HBLANK_NUM_OFFSET (0x8bc)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_HBLANK_NUM_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture2_frame_stats_hblank_num_read(uintptr_t base) {
    return system_hw_read_32(0x2208bcL);
}
// ------------------------------------------------------------------------------ //
// Register: vblank min
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_VBLANK_MIN_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_VBLANK_MIN_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_VBLANK_MIN_OFFSET (0x8c0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_VBLANK_MIN_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture2_frame_stats_vblank_min_read(uintptr_t base) {
    return system_hw_read_32(0x2208c0L);
}
// ------------------------------------------------------------------------------ //
// Register: vblank max
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_VBLANK_MAX_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_VBLANK_MAX_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_VBLANK_MAX_OFFSET (0x8c4)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_VBLANK_MAX_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture2_frame_stats_vblank_max_read(uintptr_t base) {
    return system_hw_read_32(0x2208c4L);
}
// ------------------------------------------------------------------------------ //
// Register: vblank sum
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_VBLANK_SUM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_VBLANK_SUM_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_VBLANK_SUM_OFFSET (0x8c8)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_VBLANK_SUM_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture2_frame_stats_vblank_sum_read(uintptr_t base) {
    return system_hw_read_32(0x2208c8L);
}
// ------------------------------------------------------------------------------ //
// Register: vblank num
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_VBLANK_NUM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_VBLANK_NUM_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_VBLANK_NUM_OFFSET (0x8cc)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_FRAME_STATS_VBLANK_NUM_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture2_frame_stats_vblank_num_read(uintptr_t base) {
    return system_hw_read_32(0x2208ccL);
}
// ------------------------------------------------------------------------------ //
// Group: Video-Capture-2 video test gen
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Video test generator controls.  See ISP Guide for further details
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Register: test_pattern_off on
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Test pattern off-on: 0=off, 1=on
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_TEST_PATTERN_OFF_ON_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_TEST_PATTERN_OFF_ON_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_TEST_PATTERN_OFF_ON_OFFSET (0x900)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_TEST_PATTERN_OFF_ON_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_video_test_gen_test_pattern_off_on_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220900L);
    system_hw_write_32(0x220900L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_video_capture2_video_test_gen_test_pattern_off_on_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220900L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: bayer_rgb_i sel
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Bayer or rgb select for input video: 0=bayer, 1=rgb
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_BAYER_RGB_I_SEL_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_BAYER_RGB_I_SEL_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_BAYER_RGB_I_SEL_OFFSET (0x900)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_BAYER_RGB_I_SEL_MASK (0x2)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_video_test_gen_bayer_rgb_i_sel_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220900L);
    system_hw_write_32(0x220900L, (((uint32_t) (data & 0x1)) << 1) | (curr & 0xfffffffd));
}
static __inline uint8_t acamera_fpga_video_capture2_video_test_gen_bayer_rgb_i_sel_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220900L) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: bayer_rgb_o sel
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Bayer or rgb select for output video: 0=bayer, 1=rgb
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_BAYER_RGB_O_SEL_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_BAYER_RGB_O_SEL_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_BAYER_RGB_O_SEL_OFFSET (0x900)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_BAYER_RGB_O_SEL_MASK (0x4)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_video_test_gen_bayer_rgb_o_sel_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220900L);
    system_hw_write_32(0x220900L, (((uint32_t) (data & 0x1)) << 2) | (curr & 0xfffffffb));
}
static __inline uint8_t acamera_fpga_video_capture2_video_test_gen_bayer_rgb_o_sel_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220900L) & 0x4) >> 2);
}
// ------------------------------------------------------------------------------ //
// Register: pattern type
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Pattern type select: 0=Flat field,1=Horizontal gradient,2=Vertical Gradient,3=Vertical Bars,4=Rectangle,5-255=Default white frame on black
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_PATTERN_TYPE_DEFAULT (0x03)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_PATTERN_TYPE_DATASIZE (8)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_PATTERN_TYPE_OFFSET (0x904)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_PATTERN_TYPE_MASK (0xff)

// args: data (8-bit)
static __inline void acamera_fpga_video_capture2_video_test_gen_pattern_type_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220904L);
    system_hw_write_32(0x220904L, (((uint32_t) (data & 0xff)) << 0) | (curr & 0xffffff00));
}
static __inline uint8_t acamera_fpga_video_capture2_video_test_gen_pattern_type_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220904L) & 0xff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: r backgnd
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Red background  value 16bit, MSB aligned to used width 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_R_BACKGND_DEFAULT (0xFFFF)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_R_BACKGND_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_R_BACKGND_OFFSET (0x908)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_R_BACKGND_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture2_video_test_gen_r_backgnd_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220908L);
    system_hw_write_32(0x220908L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture2_video_test_gen_r_backgnd_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220908L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: g backgnd
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Green background value 16bit, MSB aligned to used width
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_G_BACKGND_DEFAULT (0xFFFF)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_G_BACKGND_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_G_BACKGND_OFFSET (0x90c)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_G_BACKGND_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture2_video_test_gen_g_backgnd_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x22090cL);
    system_hw_write_32(0x22090cL, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture2_video_test_gen_g_backgnd_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x22090cL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: b backgnd
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Blue background value 16bit, MSB aligned to used width
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_B_BACKGND_DEFAULT (0xFFFF)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_B_BACKGND_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_B_BACKGND_OFFSET (0x910)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_B_BACKGND_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture2_video_test_gen_b_backgnd_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220910L);
    system_hw_write_32(0x220910L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture2_video_test_gen_b_backgnd_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220910L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: r foregnd
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Red foreground  value 16bit, MSB aligned to used width 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_R_FOREGND_DEFAULT (0x8FFF)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_R_FOREGND_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_R_FOREGND_OFFSET (0x914)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_R_FOREGND_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture2_video_test_gen_r_foregnd_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220914L);
    system_hw_write_32(0x220914L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture2_video_test_gen_r_foregnd_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220914L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: g foregnd
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Green foreground value 16bit, MSB aligned to used width
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_G_FOREGND_DEFAULT (0x8FFF)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_G_FOREGND_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_G_FOREGND_OFFSET (0x918)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_G_FOREGND_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture2_video_test_gen_g_foregnd_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220918L);
    system_hw_write_32(0x220918L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture2_video_test_gen_g_foregnd_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220918L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: b foregnd
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Blue foreground value 16bit, MSB aligned to used width
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_B_FOREGND_DEFAULT (0x8FFF)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_B_FOREGND_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_B_FOREGND_OFFSET (0x91c)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_B_FOREGND_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture2_video_test_gen_b_foregnd_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x22091cL);
    system_hw_write_32(0x22091cL, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture2_video_test_gen_b_foregnd_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x22091cL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: rgb gradient
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// RGB gradient increment per pixel (0-15)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_RGB_GRADIENT_DEFAULT (0x3CAA)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_RGB_GRADIENT_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_RGB_GRADIENT_OFFSET (0x920)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_RGB_GRADIENT_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture2_video_test_gen_rgb_gradient_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220920L);
    system_hw_write_32(0x220920L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture2_video_test_gen_rgb_gradient_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220920L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: rgb_gradient start
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// RGB gradient start value 16bit, MSB aligned to used width
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_RGB_GRADIENT_START_DEFAULT (0x0000)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_RGB_GRADIENT_START_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_RGB_GRADIENT_START_OFFSET (0x924)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_RGB_GRADIENT_START_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture2_video_test_gen_rgb_gradient_start_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220924L);
    system_hw_write_32(0x220924L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture2_video_test_gen_rgb_gradient_start_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220924L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: rect top
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  Rectangle top line number 1-n
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_RECT_TOP_DEFAULT (0x0001)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_RECT_TOP_DATASIZE (14)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_RECT_TOP_OFFSET (0x928)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_RECT_TOP_MASK (0x3fff)

// args: data (14-bit)
static __inline void acamera_fpga_video_capture2_video_test_gen_rect_top_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220928L);
    system_hw_write_32(0x220928L, (((uint32_t) (data & 0x3fff)) << 0) | (curr & 0xffffc000));
}
static __inline uint16_t acamera_fpga_video_capture2_video_test_gen_rect_top_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220928L) & 0x3fff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: rect bot
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  Rectangle bottom line number 1-n
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_RECT_BOT_DEFAULT (0x0100)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_RECT_BOT_DATASIZE (14)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_RECT_BOT_OFFSET (0x92c)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_RECT_BOT_MASK (0x3fff)

// args: data (14-bit)
static __inline void acamera_fpga_video_capture2_video_test_gen_rect_bot_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x22092cL);
    system_hw_write_32(0x22092cL, (((uint32_t) (data & 0x3fff)) << 0) | (curr & 0xffffc000));
}
static __inline uint16_t acamera_fpga_video_capture2_video_test_gen_rect_bot_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x22092cL) & 0x3fff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: rect left
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  Rectangle left pixel number 1-n
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_RECT_LEFT_DEFAULT (0x0001)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_RECT_LEFT_DATASIZE (14)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_RECT_LEFT_OFFSET (0x930)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_RECT_LEFT_MASK (0x3fff)

// args: data (14-bit)
static __inline void acamera_fpga_video_capture2_video_test_gen_rect_left_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220930L);
    system_hw_write_32(0x220930L, (((uint32_t) (data & 0x3fff)) << 0) | (curr & 0xffffc000));
}
static __inline uint16_t acamera_fpga_video_capture2_video_test_gen_rect_left_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220930L) & 0x3fff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: rect right
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  Rectangle right pixel number 1-n
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_RECT_RIGHT_DEFAULT (0x0100)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_RECT_RIGHT_DATASIZE (14)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_RECT_RIGHT_OFFSET (0x938)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_VIDEO_TEST_GEN_RECT_RIGHT_MASK (0x3fff)

// args: data (14-bit)
static __inline void acamera_fpga_video_capture2_video_test_gen_rect_right_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220938L);
    system_hw_write_32(0x220938L, (((uint32_t) (data & 0x3fff)) << 0) | (curr & 0xffffc000));
}
static __inline uint16_t acamera_fpga_video_capture2_video_test_gen_rect_right_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220938L) & 0x3fff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Group: Video-Capture-2 DMA Writer
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Video-Capture DMA writer controls
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Register: Format
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Format
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_FORMAT_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_FORMAT_DATASIZE (8)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_FORMAT_OFFSET (0x980)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_FORMAT_MASK (0xff)

// args: data (8-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_format_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220980L);
    system_hw_write_32(0x220980L, (((uint32_t) (data & 0xff)) << 0) | (curr & 0xffffff00));
}
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_format_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220980L) & 0xff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: Base mode
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Base DMA packing mode for RGB/RAW/YUV etc (see ISP guide)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BASE_MODE_DEFAULT (0x0D)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BASE_MODE_DATASIZE (4)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BASE_MODE_OFFSET (0x980)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BASE_MODE_MASK (0xf)

// args: data (4-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_base_mode_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220980L);
    system_hw_write_32(0x220980L, (((uint32_t) (data & 0xf)) << 0) | (curr & 0xfffffff0));
}
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_base_mode_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220980L) & 0xf) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: Plane select
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Plane select for planar base modes.  Only used if planar outputs required.  Not used.  Should be set to 0
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_PLANE_SELECT_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_PLANE_SELECT_DATASIZE (2)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_PLANE_SELECT_OFFSET (0x980)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_PLANE_SELECT_MASK (0xc0)

// args: data (2-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_plane_select_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220980L);
    system_hw_write_32(0x220980L, (((uint32_t) (data & 0x3)) << 6) | (curr & 0xffffff3f));
}
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_plane_select_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220980L) & 0xc0) >> 6);
}
// ------------------------------------------------------------------------------ //
// Register: single frame
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 0 = All frames are written(after frame_write_on= 1), 1= only 1st frame written ( after frame_write_on =1)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_SINGLE_FRAME_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_SINGLE_FRAME_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_SINGLE_FRAME_OFFSET (0x984)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_SINGLE_FRAME_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_single_frame_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220984L);
    system_hw_write_32(0x220984L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_single_frame_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220984L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: frame write on
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 
//    0 = no frames written(when switched from 1, current frame completes writing before stopping),
//    1= write frame(s) (write single or continous frame(s) )
//    
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_FRAME_WRITE_ON_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_FRAME_WRITE_ON_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_FRAME_WRITE_ON_OFFSET (0x984)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_FRAME_WRITE_ON_MASK (0x2)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_frame_write_on_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220984L);
    system_hw_write_32(0x220984L, (((uint32_t) (data & 0x1)) << 1) | (curr & 0xfffffffd));
}
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_frame_write_on_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220984L) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: half irate
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 0 = normal operation , 1= write half(alternate) of input frames( only valid for continuous mode)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_HALF_IRATE_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_HALF_IRATE_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_HALF_IRATE_OFFSET (0x984)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_HALF_IRATE_MASK (0x4)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_half_irate_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220984L);
    system_hw_write_32(0x220984L, (((uint32_t) (data & 0x1)) << 2) | (curr & 0xfffffffb));
}
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_half_irate_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220984L) & 0x4) >> 2);
}
// ------------------------------------------------------------------------------ //
// Register: axi xact comp
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 0 = dont wait for axi transaction completion at end of frame(just all transfers accepted). 1 = wait for all transactions completed
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_XACT_COMP_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_XACT_COMP_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_XACT_COMP_OFFSET (0x984)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_XACT_COMP_MASK (0x8)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_axi_xact_comp_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220984L);
    system_hw_write_32(0x220984L, (((uint32_t) (data & 0x1)) << 3) | (curr & 0xfffffff7));
}
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_axi_xact_comp_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220984L) & 0x8) >> 3);
}
// ------------------------------------------------------------------------------ //
// Register: active width
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Active video width in pixels 128-8000
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_ACTIVE_WIDTH_DEFAULT (0x780)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_ACTIVE_WIDTH_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_ACTIVE_WIDTH_OFFSET (0x988)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_ACTIVE_WIDTH_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_active_width_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220988L);
    system_hw_write_32(0x220988L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture2_dma_writer_active_width_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220988L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: active height
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Active video height in lines 128-8000
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_ACTIVE_HEIGHT_DEFAULT (0x438)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_ACTIVE_HEIGHT_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_ACTIVE_HEIGHT_OFFSET (0x98c)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_ACTIVE_HEIGHT_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_active_height_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x22098cL);
    system_hw_write_32(0x22098cL, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture2_dma_writer_active_height_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x22098cL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: bank0_base
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// bank 0 base address for frame buffer, should be word-aligned
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BANK0_BASE_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BANK0_BASE_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BANK0_BASE_OFFSET (0x990)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BANK0_BASE_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_bank0_base_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x220990L, data);
}
static __inline uint32_t acamera_fpga_video_capture2_dma_writer_bank0_base_read(uintptr_t base) {
    return system_hw_read_32(0x220990L);
}
// ------------------------------------------------------------------------------ //
// Register: bank1_base
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// bank 1 base address for frame buffer, should be word-aligned
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BANK1_BASE_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BANK1_BASE_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BANK1_BASE_OFFSET (0x994)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BANK1_BASE_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_bank1_base_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x220994L, data);
}
static __inline uint32_t acamera_fpga_video_capture2_dma_writer_bank1_base_read(uintptr_t base) {
    return system_hw_read_32(0x220994L);
}
// ------------------------------------------------------------------------------ //
// Register: bank2_base
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// bank 2 base address for frame buffer, should be word-aligned
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BANK2_BASE_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BANK2_BASE_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BANK2_BASE_OFFSET (0x998)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BANK2_BASE_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_bank2_base_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x220998L, data);
}
static __inline uint32_t acamera_fpga_video_capture2_dma_writer_bank2_base_read(uintptr_t base) {
    return system_hw_read_32(0x220998L);
}
// ------------------------------------------------------------------------------ //
// Register: bank3_base
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// bank 3 base address for frame buffer, should be word-aligned
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BANK3_BASE_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BANK3_BASE_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BANK3_BASE_OFFSET (0x99c)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BANK3_BASE_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_bank3_base_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x22099cL, data);
}
static __inline uint32_t acamera_fpga_video_capture2_dma_writer_bank3_base_read(uintptr_t base) {
    return system_hw_read_32(0x22099cL);
}
// ------------------------------------------------------------------------------ //
// Register: bank4_base
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// bank 4 base address for frame buffer, should be word-aligned
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BANK4_BASE_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BANK4_BASE_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BANK4_BASE_OFFSET (0x9a0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BANK4_BASE_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_bank4_base_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x2209a0L, data);
}
static __inline uint32_t acamera_fpga_video_capture2_dma_writer_bank4_base_read(uintptr_t base) {
    return system_hw_read_32(0x2209a0L);
}
// ------------------------------------------------------------------------------ //
// Register: max bank
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// highest bank*_base to use for frame writes before recycling to bank0_base, only 0 to 4 are valid
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_MAX_BANK_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_MAX_BANK_DATASIZE (3)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_MAX_BANK_OFFSET (0x9a4)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_MAX_BANK_MASK (0x7)

// args: data (3-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_max_bank_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2209a4L);
    system_hw_write_32(0x2209a4L, (((uint32_t) (data & 0x7)) << 0) | (curr & 0xfffffff8));
}
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_max_bank_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2209a4L) & 0x7) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: bank0 restart
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 0 = normal operation, 1= restart bank counter to bank0 for next frame write
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BANK0_RESTART_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BANK0_RESTART_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BANK0_RESTART_OFFSET (0x9a4)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BANK0_RESTART_MASK (0x8)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_bank0_restart_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2209a4L);
    system_hw_write_32(0x2209a4L, (((uint32_t) (data & 0x1)) << 3) | (curr & 0xfffffff7));
}
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_bank0_restart_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2209a4L) & 0x8) >> 3);
}
// ------------------------------------------------------------------------------ //
// Register: Line_offset
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 
//    Indicates the offset in bytes from the start of one line to the next line.
//    This value should be equal to or larger than one line of image data and should be word-aligned
//    
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_LINE_OFFSET_DEFAULT (0x4000)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_LINE_OFFSET_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_LINE_OFFSET_OFFSET (0x9a8)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_LINE_OFFSET_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_line_offset_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x2209a8L, data);
}
static __inline uint32_t acamera_fpga_video_capture2_dma_writer_line_offset_read(uintptr_t base) {
    return system_hw_read_32(0x2209a8L);
}
// ------------------------------------------------------------------------------ //
// Register: frame write cancel
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 0 = normal operation, 1= cancel current/future frame write(s), any unstarted AXI bursts cancelled and fifo flushed
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_FRAME_WRITE_CANCEL_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_FRAME_WRITE_CANCEL_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_FRAME_WRITE_CANCEL_OFFSET (0x9ac)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_FRAME_WRITE_CANCEL_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_frame_write_cancel_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2209acL);
    system_hw_write_32(0x2209acL, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_frame_write_cancel_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2209acL) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: axi_port_enable
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// enables axi, active high, 1=enables axi write transfers, 0= reset axi domain( via reset synchroniser)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_PORT_ENABLE_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_PORT_ENABLE_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_PORT_ENABLE_OFFSET (0x9ac)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_PORT_ENABLE_MASK (0x2)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_axi_port_enable_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2209acL);
    system_hw_write_32(0x2209acL, (((uint32_t) (data & 0x1)) << 1) | (curr & 0xfffffffd));
}
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_axi_port_enable_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2209acL) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: wbank curr
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// write bank currently active. valid values =0-4. updated at start of frame write
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBANK_CURR_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBANK_CURR_DATASIZE (3)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBANK_CURR_OFFSET (0x9b0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBANK_CURR_MASK (0x7)

// args: data (3-bit)
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_wbank_curr_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2209b0L) & 0x7) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: wbank last
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// write bank last active. valid values = 0-4. updated at start of frame write
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBANK_LAST_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBANK_LAST_DATASIZE (3)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBANK_LAST_OFFSET (0x9b0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBANK_LAST_MASK (0x38)

// args: data (3-bit)
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_wbank_last_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2209b0L) & 0x38) >> 3);
}
// ------------------------------------------------------------------------------ //
// Register: wbank active
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 1 = wbank_curr is being written to. Goes high at start of writes, low at last write transfer/completion on axi. 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBANK_ACTIVE_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBANK_ACTIVE_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBANK_ACTIVE_OFFSET (0x9b4)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBANK_ACTIVE_MASK (0x1)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_wbank_active_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2209b4L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: wbank start
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 1 = High pulse at start of frame write to bank. 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBANK_START_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBANK_START_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBANK_START_OFFSET (0x9b4)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBANK_START_MASK (0x2)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_wbank_start_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2209b4L) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: wbank stop
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 1 = High pulse at end of frame write to bank. 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBANK_STOP_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBANK_STOP_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBANK_STOP_OFFSET (0x9b4)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBANK_STOP_MASK (0x4)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_wbank_stop_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2209b4L) & 0x4) >> 2);
}
// ------------------------------------------------------------------------------ //
// Register: wbase curr
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// currently active bank base addr - in bytes. updated at start of frame write
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBASE_CURR_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBASE_CURR_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBASE_CURR_OFFSET (0x9b8)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBASE_CURR_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture2_dma_writer_wbase_curr_read(uintptr_t base) {
    return system_hw_read_32(0x2209b8L);
}
// ------------------------------------------------------------------------------ //
// Register: wbase last
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// last active bank base addr - in bytes. Updated at start of frame write
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBASE_LAST_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBASE_LAST_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBASE_LAST_OFFSET (0x9bc)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WBASE_LAST_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture2_dma_writer_wbase_last_read(uintptr_t base) {
    return system_hw_read_32(0x2209bcL);
}
// ------------------------------------------------------------------------------ //
// Register: frame icount
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// count of incomming frames (starts) to vdma_writer on video input, non resetable, rolls over, updates at pixel 1 of new frame on video in
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_FRAME_ICOUNT_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_FRAME_ICOUNT_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_FRAME_ICOUNT_OFFSET (0x9c0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_FRAME_ICOUNT_MASK (0xffff)

// args: data (16-bit)
static __inline uint16_t acamera_fpga_video_capture2_dma_writer_frame_icount_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x2209c0L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: frame wcount
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// count of outgoing frame writes (starts) from vdma_writer sent to AXI output, non resetable, rolls over, updates at pixel 1 of new frame on video in
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_FRAME_WCOUNT_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_FRAME_WCOUNT_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_FRAME_WCOUNT_OFFSET (0x9c4)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_FRAME_WCOUNT_MASK (0xffff)

// args: data (16-bit)
static __inline uint16_t acamera_fpga_video_capture2_dma_writer_frame_wcount_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x2209c4L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: clear alarms
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 0>1 transition(synchronous detection) causes local axi/video alarm clear
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_CLEAR_ALARMS_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_CLEAR_ALARMS_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_CLEAR_ALARMS_OFFSET (0x9c8)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_CLEAR_ALARMS_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_clear_alarms_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2209c8L);
    system_hw_write_32(0x2209c8L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_clear_alarms_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2209c8L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: max_burst_length_is_8
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 1= Reduce default AXI max_burst_length from 16 to 8, 0= Dont reduce
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_MAX_BURST_LENGTH_IS_8_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_MAX_BURST_LENGTH_IS_8_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_MAX_BURST_LENGTH_IS_8_OFFSET (0x9c8)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_MAX_BURST_LENGTH_IS_8_MASK (0x2)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_max_burst_length_is_8_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2209c8L);
    system_hw_write_32(0x2209c8L, (((uint32_t) (data & 0x1)) << 1) | (curr & 0xfffffffd));
}
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_max_burst_length_is_8_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2209c8L) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: max_burst_length_is_4
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 1= Reduce default AXI max_burst_length from 16 to 4, 0= Dont reduce( has priority overmax_burst_length_is_8!)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_MAX_BURST_LENGTH_IS_4_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_MAX_BURST_LENGTH_IS_4_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_MAX_BURST_LENGTH_IS_4_OFFSET (0x9c8)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_MAX_BURST_LENGTH_IS_4_MASK (0x4)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_max_burst_length_is_4_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2209c8L);
    system_hw_write_32(0x2209c8L, (((uint32_t) (data & 0x1)) << 2) | (curr & 0xfffffffb));
}
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_max_burst_length_is_4_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2209c8L) & 0x4) >> 2);
}
// ------------------------------------------------------------------------------ //
// Register: write timeout disable
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 
//    At end of frame an optional timeout is applied to wait for AXI writes to completed/accepted befotre caneclling and flushing.
//    0= Timeout Enabled, timeout count can decrement.
//    1 = Disable timeout, timeout count can't decrement.
//    
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WRITE_TIMEOUT_DISABLE_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WRITE_TIMEOUT_DISABLE_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WRITE_TIMEOUT_DISABLE_OFFSET (0x9c8)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WRITE_TIMEOUT_DISABLE_MASK (0x8)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_write_timeout_disable_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2209c8L);
    system_hw_write_32(0x2209c8L, (((uint32_t) (data & 0x1)) << 3) | (curr & 0xfffffff7));
}
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_write_timeout_disable_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2209c8L) & 0x8) >> 3);
}
// ------------------------------------------------------------------------------ //
// Register: awmaxwait_limit
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// awvalid maxwait limit(cycles) to raise axi_fail_awmaxwait alarm . zero disables alarm raise.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AWMAXWAIT_LIMIT_DEFAULT (0x00)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AWMAXWAIT_LIMIT_DATASIZE (8)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AWMAXWAIT_LIMIT_OFFSET (0x9cc)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AWMAXWAIT_LIMIT_MASK (0xff)

// args: data (8-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_awmaxwait_limit_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2209ccL);
    system_hw_write_32(0x2209ccL, (((uint32_t) (data & 0xff)) << 0) | (curr & 0xffffff00));
}
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_awmaxwait_limit_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2209ccL) & 0xff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: wmaxwait_limit
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// wvalid maxwait limit(cycles) to raise axi_fail_wmaxwait alarm . zero disables alarm raise
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WMAXWAIT_LIMIT_DEFAULT (0x00)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WMAXWAIT_LIMIT_DATASIZE (8)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WMAXWAIT_LIMIT_OFFSET (0x9d0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WMAXWAIT_LIMIT_MASK (0xff)

// args: data (8-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_wmaxwait_limit_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2209d0L);
    system_hw_write_32(0x2209d0L, (((uint32_t) (data & 0xff)) << 0) | (curr & 0xffffff00));
}
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_wmaxwait_limit_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2209d0L) & 0xff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: wxact_ostand_limit
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// number oustsanding write transactions(bursts)(responses..1 per burst) limit to raise axi_fail_wxact_ostand. zero disables alarm raise
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WXACT_OSTAND_LIMIT_DEFAULT (0x00)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WXACT_OSTAND_LIMIT_DATASIZE (8)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WXACT_OSTAND_LIMIT_OFFSET (0x9d4)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_WXACT_OSTAND_LIMIT_MASK (0xff)

// args: data (8-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_wxact_ostand_limit_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x2209d4L);
    system_hw_write_32(0x2209d4L, (((uint32_t) (data & 0xff)) << 0) | (curr & 0xffffff00));
}
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_wxact_ostand_limit_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2209d4L) & 0xff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: axi_fail_bresp
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  clearable alarm, high to indicate bad  bresp captured 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_FAIL_BRESP_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_FAIL_BRESP_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_FAIL_BRESP_OFFSET (0x9d8)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_FAIL_BRESP_MASK (0x1)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_axi_fail_bresp_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2209d8L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: axi_fail_awmaxwait
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  clearable alarm, high when awmaxwait_limit reached 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_FAIL_AWMAXWAIT_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_FAIL_AWMAXWAIT_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_FAIL_AWMAXWAIT_OFFSET (0x9d8)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_FAIL_AWMAXWAIT_MASK (0x2)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_axi_fail_awmaxwait_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2209d8L) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: axi_fail_wmaxwait
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  clearable alarm, high when wmaxwait_limit reached 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_FAIL_WMAXWAIT_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_FAIL_WMAXWAIT_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_FAIL_WMAXWAIT_OFFSET (0x9d8)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_FAIL_WMAXWAIT_MASK (0x4)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_axi_fail_wmaxwait_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2209d8L) & 0x4) >> 2);
}
// ------------------------------------------------------------------------------ //
// Register: axi_fail_wxact_ostand
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  clearable alarm, high when wxact_ostand_limit reached 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_FAIL_WXACT_OSTAND_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_FAIL_WXACT_OSTAND_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_FAIL_WXACT_OSTAND_OFFSET (0x9d8)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_FAIL_WXACT_OSTAND_MASK (0x8)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_axi_fail_wxact_ostand_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2209d8L) & 0x8) >> 3);
}
// ------------------------------------------------------------------------------ //
// Register: vi_fail_active_width
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  clearable alarm, high to indicate mismatched active_width detected 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_VI_FAIL_ACTIVE_WIDTH_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_VI_FAIL_ACTIVE_WIDTH_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_VI_FAIL_ACTIVE_WIDTH_OFFSET (0x9d8)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_VI_FAIL_ACTIVE_WIDTH_MASK (0x10)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_vi_fail_active_width_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2209d8L) & 0x10) >> 4);
}
// ------------------------------------------------------------------------------ //
// Register: vi_fail_active_height
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  clearable alarm, high to indicate mismatched active_height detected ( also raised on missing field!) 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_VI_FAIL_ACTIVE_HEIGHT_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_VI_FAIL_ACTIVE_HEIGHT_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_VI_FAIL_ACTIVE_HEIGHT_OFFSET (0x9d8)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_VI_FAIL_ACTIVE_HEIGHT_MASK (0x20)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_vi_fail_active_height_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2209d8L) & 0x20) >> 5);
}
// ------------------------------------------------------------------------------ //
// Register: vi_fail_interline_blanks
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  clearable alarm, high to indicate interline blanking below min 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_VI_FAIL_INTERLINE_BLANKS_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_VI_FAIL_INTERLINE_BLANKS_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_VI_FAIL_INTERLINE_BLANKS_OFFSET (0x9d8)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_VI_FAIL_INTERLINE_BLANKS_MASK (0x40)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_vi_fail_interline_blanks_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2209d8L) & 0x40) >> 6);
}
// ------------------------------------------------------------------------------ //
// Register: vi_fail_interframe_blanks
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  clearable alarm, high to indicate interframe blanking below min 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_VI_FAIL_INTERFRAME_BLANKS_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_VI_FAIL_INTERFRAME_BLANKS_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_VI_FAIL_INTERFRAME_BLANKS_OFFSET (0x9d8)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_VI_FAIL_INTERFRAME_BLANKS_MASK (0x80)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_vi_fail_interframe_blanks_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2209d8L) & 0x80) >> 7);
}
// ------------------------------------------------------------------------------ //
// Register: video_alarm
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  active high, problem found on video port(s) ( active width/height or interline/frame blanks failure) 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_VIDEO_ALARM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_VIDEO_ALARM_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_VIDEO_ALARM_OFFSET (0x9dc)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_VIDEO_ALARM_MASK (0x1)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_video_alarm_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2209dcL) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: axi_alarm
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  active high, problem found on axi port(s)( bresp or awmaxwait or wmaxwait or wxact_ostand failure ) 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_ALARM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_ALARM_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_ALARM_OFFSET (0x9dc)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_AXI_ALARM_MASK (0x2)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture2_dma_writer_axi_alarm_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x2209dcL) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: blk_config
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// block configuration (reserved)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BLK_CONFIG_DEFAULT (0x0000)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BLK_CONFIG_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BLK_CONFIG_OFFSET (0x9e0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BLK_CONFIG_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_video_capture2_dma_writer_blk_config_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x2209e0L, data);
}
static __inline uint32_t acamera_fpga_video_capture2_dma_writer_blk_config_read(uintptr_t base) {
    return system_hw_read_32(0x2209e0L);
}
// ------------------------------------------------------------------------------ //
// Register: blk_status
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// block status output (reserved)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BLK_STATUS_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BLK_STATUS_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BLK_STATUS_OFFSET (0x9e4)
#define ACAMERA_FPGA_VIDEO_CAPTURE2_DMA_WRITER_BLK_STATUS_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture2_dma_writer_blk_status_read(uintptr_t base) {
    return system_hw_read_32(0x2209e4L);
}
// ------------------------------------------------------------------------------ //
// Group: Video-Capture-3 Input port
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Controls video input port.  
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Register: preset
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 
//        Allows selection of various input port presets for standard sensor inputs.  See ISP Guide for details of available presets.
//        0-14: Frequently used presets.  If using one of available presets, remaining bits in registers 0x100 and 0x104 are not used.
//        15:   Input port configured according to registers in 0x100 and 0x104.  Consult Apical support for special input port requirements.
//      
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_PRESET_DEFAULT (2)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_PRESET_DATASIZE (4)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_PRESET_OFFSET (0xa00)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_PRESET_MASK (0xf)

// args: data (4-bit)
static __inline void acamera_fpga_video_capture3_input_port_preset_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a00L);
    system_hw_write_32(0x220a00L, (((uint32_t) (data & 0xf)) << 0) | (curr & 0xfffffff0));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_preset_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a00L) & 0xf) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: vs_use field
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VS_USE_FIELD_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VS_USE_FIELD_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VS_USE_FIELD_OFFSET (0xa00)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VS_USE_FIELD_MASK (0x100)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VS_USE_FIELD_USE_VSYNC_I_PORT_FOR_VERTICAL_SYNC (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VS_USE_FIELD_USE_FIELD_I_PORT_FOR_VERTICAL_SYNC (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_vs_use_field_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a00L);
    system_hw_write_32(0x220a00L, (((uint32_t) (data & 0x1)) << 8) | (curr & 0xfffffeff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_vs_use_field_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a00L) & 0x100) >> 8);
}
// ------------------------------------------------------------------------------ //
// Register: vs toggle
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VS_TOGGLE_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VS_TOGGLE_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VS_TOGGLE_OFFSET (0xa00)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VS_TOGGLE_MASK (0x200)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VS_TOGGLE_VSYNC_IS_PULSETYPE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VS_TOGGLE_VSYNC_IS_TOGGLETYPE_FIELD_SIGNAL (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_vs_toggle_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a00L);
    system_hw_write_32(0x220a00L, (((uint32_t) (data & 0x1)) << 9) | (curr & 0xfffffdff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_vs_toggle_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a00L) & 0x200) >> 9);
}
// ------------------------------------------------------------------------------ //
// Register: vs polarity
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VS_POLARITY_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VS_POLARITY_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VS_POLARITY_OFFSET (0xa00)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VS_POLARITY_MASK (0x400)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VS_POLARITY_HORIZONTAL_COUNTER_RESET_ON_RISING_EDGE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VS_POLARITY_HORIZONTAL_COUNTER_RESET_ON_FALLING_EDGE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_vs_polarity_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a00L);
    system_hw_write_32(0x220a00L, (((uint32_t) (data & 0x1)) << 10) | (curr & 0xfffffbff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_vs_polarity_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a00L) & 0x400) >> 10);
}
// ------------------------------------------------------------------------------ //
// Register: vs_polarity acl
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VS_POLARITY_ACL_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VS_POLARITY_ACL_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VS_POLARITY_ACL_OFFSET (0xa00)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VS_POLARITY_ACL_MASK (0x800)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VS_POLARITY_ACL_DONT_INVERT_POLARITY_FOR_ACL_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VS_POLARITY_ACL_INVERT_POLARITY_FOR_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_vs_polarity_acl_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a00L);
    system_hw_write_32(0x220a00L, (((uint32_t) (data & 0x1)) << 11) | (curr & 0xfffff7ff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_vs_polarity_acl_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a00L) & 0x800) >> 11);
}
// ------------------------------------------------------------------------------ //
// Register: hs_use acl
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_USE_ACL_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_USE_ACL_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_USE_ACL_OFFSET (0xa00)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_USE_ACL_MASK (0x1000)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_USE_ACL_USE_HSYNC_I_PORT_FOR_ACTIVELINE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_USE_ACL_USE_ACL_I_PORT_FOR_ACTIVELINE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_hs_use_acl_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a00L);
    system_hw_write_32(0x220a00L, (((uint32_t) (data & 0x1)) << 12) | (curr & 0xffffefff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_hs_use_acl_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a00L) & 0x1000) >> 12);
}
// ------------------------------------------------------------------------------ //
// Register: vc_c select
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VC_C_SELECT_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VC_C_SELECT_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VC_C_SELECT_OFFSET (0xa00)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VC_C_SELECT_MASK (0x4000)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VC_C_SELECT_VERTICAL_COUNTER_COUNTS_ON_HS (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VC_C_SELECT_VERTICAL_COUNTER_COUNTS_ON_HORIZONTAL_COUNTER_OVERFLOW_OR_RESET (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_vc_c_select_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a00L);
    system_hw_write_32(0x220a00L, (((uint32_t) (data & 0x1)) << 14) | (curr & 0xffffbfff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_vc_c_select_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a00L) & 0x4000) >> 14);
}
// ------------------------------------------------------------------------------ //
// Register: vc_r select
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VC_R_SELECT_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VC_R_SELECT_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VC_R_SELECT_OFFSET (0xa00)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VC_R_SELECT_MASK (0x8000)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VC_R_SELECT_VERTICAL_COUNTER_IS_RESET_ON_EDGE_OF_VS (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VC_R_SELECT_VERTICAL_COUNTER_IS_RESET_AFTER_TIMEOUT_ON_HS (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_vc_r_select_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a00L);
    system_hw_write_32(0x220a00L, (((uint32_t) (data & 0x1)) << 15) | (curr & 0xffff7fff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_vc_r_select_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a00L) & 0x8000) >> 15);
}
// ------------------------------------------------------------------------------ //
// Register: hs_xor vs
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_XOR_VS_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_XOR_VS_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_XOR_VS_OFFSET (0xa00)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_XOR_VS_MASK (0x10000)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_XOR_VS_NORMAL_MODE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_XOR_VS_HVALID__HSYNC_XOR_VSYNC (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_hs_xor_vs_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a00L);
    system_hw_write_32(0x220a00L, (((uint32_t) (data & 0x1)) << 16) | (curr & 0xfffeffff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_hs_xor_vs_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a00L) & 0x10000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: hs polarity
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_POLARITY_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_POLARITY_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_POLARITY_OFFSET (0xa00)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_POLARITY_MASK (0x20000)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_POLARITY_DONT_INVERT_POLARITY_OF_HS_FOR_ACL_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_POLARITY_INVERT_POLARITY_OF_HS_FOR_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_hs_polarity_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a00L);
    system_hw_write_32(0x220a00L, (((uint32_t) (data & 0x1)) << 17) | (curr & 0xfffdffff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_hs_polarity_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a00L) & 0x20000) >> 17);
}
// ------------------------------------------------------------------------------ //
// Register: hs_polarity acl
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_POLARITY_ACL_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_POLARITY_ACL_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_POLARITY_ACL_OFFSET (0xa00)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_POLARITY_ACL_MASK (0x40000)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_POLARITY_ACL_DONT_INVERT_POLARITY_OF_HS_FOR_HS_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_POLARITY_ACL_INVERT_POLARITY_OF_HS_FOR_HS_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_hs_polarity_acl_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a00L);
    system_hw_write_32(0x220a00L, (((uint32_t) (data & 0x1)) << 18) | (curr & 0xfffbffff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_hs_polarity_acl_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a00L) & 0x40000) >> 18);
}
// ------------------------------------------------------------------------------ //
// Register: hs_polarity hs
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_POLARITY_HS_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_POLARITY_HS_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_POLARITY_HS_OFFSET (0xa00)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_POLARITY_HS_MASK (0x80000)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_POLARITY_HS_HORIZONTAL_COUNTER_IS_RESET_ON_RISING_EDGE_OF_HS (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_POLARITY_HS_HORIZONTAL_COUNTER_IS_RESET_ON_VSYNC_EG_WHEN_HSYNC_IS_NOT_AVAILABLE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_hs_polarity_hs_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a00L);
    system_hw_write_32(0x220a00L, (((uint32_t) (data & 0x1)) << 19) | (curr & 0xfff7ffff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_hs_polarity_hs_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a00L) & 0x80000) >> 19);
}
// ------------------------------------------------------------------------------ //
// Register: hs_polarity vc
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_POLARITY_VC_DEFAULT (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_POLARITY_VC_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_POLARITY_VC_OFFSET (0xa00)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_POLARITY_VC_MASK (0x100000)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_POLARITY_VC_VERTICAL_COUNTER_INCREMENTS_ON_RISING_EDGE_OF_HS (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HS_POLARITY_VC_VERTICAL_COUNTER_INCREMENTS_ON_FALLING_EDGE_OF_HS (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_hs_polarity_vc_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a00L);
    system_hw_write_32(0x220a00L, (((uint32_t) (data & 0x1)) << 20) | (curr & 0xffefffff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_hs_polarity_vc_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a00L) & 0x100000) >> 20);
}
// ------------------------------------------------------------------------------ //
// Register: hc_r select
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HC_R_SELECT_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HC_R_SELECT_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HC_R_SELECT_OFFSET (0xa00)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HC_R_SELECT_MASK (0x800000)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HC_R_SELECT_VERTICAL_COUNTER_IS_RESET_ON_RISING_EDGE_OF_HS (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HC_R_SELECT_VERTICAL_COUNTER_IS_RESET_ON_RISING_EDGE_OF_VS (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_hc_r_select_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a00L);
    system_hw_write_32(0x220a00L, (((uint32_t) (data & 0x1)) << 23) | (curr & 0xff7fffff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_hc_r_select_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a00L) & 0x800000) >> 23);
}
// ------------------------------------------------------------------------------ //
// Register: acl polarity
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACL_POLARITY_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACL_POLARITY_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACL_POLARITY_OFFSET (0xa00)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACL_POLARITY_MASK (0x1000000)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACL_POLARITY_DONT_INVERT_ACL_I_FOR_ACL_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACL_POLARITY_INVERT_ACL_I_FOR_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_acl_polarity_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a00L);
    system_hw_write_32(0x220a00L, (((uint32_t) (data & 0x1)) << 24) | (curr & 0xfeffffff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_acl_polarity_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a00L) & 0x1000000) >> 24);
}
// ------------------------------------------------------------------------------ //
// Register: field polarity
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELD_POLARITY_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELD_POLARITY_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELD_POLARITY_OFFSET (0xa04)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELD_POLARITY_MASK (0x1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELD_POLARITY_DONT_INVERT_FIELD_I_FOR_FIELD_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELD_POLARITY_INVERT_FIELD_I_FOR_FIELD_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_field_polarity_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a04L);
    system_hw_write_32(0x220a04L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_field_polarity_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a04L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: field toggle
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELD_TOGGLE_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELD_TOGGLE_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELD_TOGGLE_OFFSET (0xa04)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELD_TOGGLE_MASK (0x2)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELD_TOGGLE_FIELD_IS_PULSETYPE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELD_TOGGLE_FIELD_IS_TOGGLETYPE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_field_toggle_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a04L);
    system_hw_write_32(0x220a04L, (((uint32_t) (data & 0x1)) << 1) | (curr & 0xfffffffd));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_field_toggle_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a04L) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: aclg window0
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_WINDOW0_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_WINDOW0_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_WINDOW0_OFFSET (0xa04)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_WINDOW0_MASK (0x100)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_WINDOW0_EXCLUDE_WINDOW0_SIGNAL_IN_ACL_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_WINDOW0_INCLUDE_WINDOW0_SIGNAL_IN_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_aclg_window0_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a04L);
    system_hw_write_32(0x220a04L, (((uint32_t) (data & 0x1)) << 8) | (curr & 0xfffffeff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_aclg_window0_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a04L) & 0x100) >> 8);
}
// ------------------------------------------------------------------------------ //
// Register: aclg hsync
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_HSYNC_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_HSYNC_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_HSYNC_OFFSET (0xa04)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_HSYNC_MASK (0x200)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_HSYNC_EXCLUDE_HSYNC_SIGNAL_IN_ACL_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_HSYNC_INCLUDE_HSYNC_SIGNAL_IN_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_aclg_hsync_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a04L);
    system_hw_write_32(0x220a04L, (((uint32_t) (data & 0x1)) << 9) | (curr & 0xfffffdff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_aclg_hsync_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a04L) & 0x200) >> 9);
}
// ------------------------------------------------------------------------------ //
// Register: aclg window2
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_WINDOW2_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_WINDOW2_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_WINDOW2_OFFSET (0xa04)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_WINDOW2_MASK (0x400)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_WINDOW2_EXCLUDE_WINDOW2_SIGNAL_IN_ACL_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_WINDOW2_INCLUDE_WINDOW2_SIGNAL_IN_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_aclg_window2_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a04L);
    system_hw_write_32(0x220a04L, (((uint32_t) (data & 0x1)) << 10) | (curr & 0xfffffbff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_aclg_window2_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a04L) & 0x400) >> 10);
}
// ------------------------------------------------------------------------------ //
// Register: aclg acl
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_ACL_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_ACL_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_ACL_OFFSET (0xa04)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_ACL_MASK (0x800)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_ACL_EXCLUDE_ACL_I_SIGNAL_IN_ACL_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_ACL_INCLUDE_ACL_I_SIGNAL_IN_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_aclg_acl_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a04L);
    system_hw_write_32(0x220a04L, (((uint32_t) (data & 0x1)) << 11) | (curr & 0xfffff7ff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_aclg_acl_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a04L) & 0x800) >> 11);
}
// ------------------------------------------------------------------------------ //
// Register: aclg vsync
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_VSYNC_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_VSYNC_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_VSYNC_OFFSET (0xa04)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_VSYNC_MASK (0x1000)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_VSYNC_EXCLUDE_VSYNC_SIGNAL_IN_ACL_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_ACLG_VSYNC_INCLUDE_VSYNC_SIGNAL_IN_ACL_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_aclg_vsync_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a04L);
    system_hw_write_32(0x220a04L, (((uint32_t) (data & 0x1)) << 12) | (curr & 0xffffefff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_aclg_vsync_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a04L) & 0x1000) >> 12);
}
// ------------------------------------------------------------------------------ //
// Register: hsg window1
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HSG_WINDOW1_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HSG_WINDOW1_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HSG_WINDOW1_OFFSET (0xa04)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HSG_WINDOW1_MASK (0x10000)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HSG_WINDOW1_EXCLUDE_WINDOW1_SIGNAL_IN_HS_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HSG_WINDOW1_INCLUDE_WINDOW1_SIGNAL_IN_HS_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_hsg_window1_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a04L);
    system_hw_write_32(0x220a04L, (((uint32_t) (data & 0x1)) << 16) | (curr & 0xfffeffff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_hsg_window1_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a04L) & 0x10000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: hsg hsync
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HSG_HSYNC_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HSG_HSYNC_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HSG_HSYNC_OFFSET (0xa04)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HSG_HSYNC_MASK (0x20000)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HSG_HSYNC_EXCLUDE_HSYNC_SIGNAL_IN_HS_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HSG_HSYNC_INCLUDE_HSYNC_SIGNAL_IN_HS_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_hsg_hsync_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a04L);
    system_hw_write_32(0x220a04L, (((uint32_t) (data & 0x1)) << 17) | (curr & 0xfffdffff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_hsg_hsync_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a04L) & 0x20000) >> 17);
}
// ------------------------------------------------------------------------------ //
// Register: hsg vsync
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HSG_VSYNC_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HSG_VSYNC_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HSG_VSYNC_OFFSET (0xa04)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HSG_VSYNC_MASK (0x40000)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HSG_VSYNC_EXCLUDE_VSYNC_SIGNAL_IN_HS_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HSG_VSYNC_INCLUDE_VSYNC_SIGNAL_IN_HS_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_hsg_vsync_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a04L);
    system_hw_write_32(0x220a04L, (((uint32_t) (data & 0x1)) << 18) | (curr & 0xfffbffff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_hsg_vsync_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a04L) & 0x40000) >> 18);
}
// ------------------------------------------------------------------------------ //
// Register: hsg window2
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HSG_WINDOW2_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HSG_WINDOW2_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HSG_WINDOW2_OFFSET (0xa04)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HSG_WINDOW2_MASK (0x80000)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HSG_WINDOW2_EXCLUDE_WINDOW2_SIGNAL_IN_HS_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HSG_WINDOW2_INCLUDE_WINDOW2_SIGNAL_IN_HS_GATE_MASK_OUT_SPURIOUS_HS_DURING_BLANK (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_hsg_window2_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a04L);
    system_hw_write_32(0x220a04L, (((uint32_t) (data & 0x1)) << 19) | (curr & 0xfff7ffff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_hsg_window2_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a04L) & 0x80000) >> 19);
}
// ------------------------------------------------------------------------------ //
// Register: fieldg vsync
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELDG_VSYNC_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELDG_VSYNC_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELDG_VSYNC_OFFSET (0xa04)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELDG_VSYNC_MASK (0x1000000)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELDG_VSYNC_EXCLUDE_VSYNC_SIGNAL_IN_FIELD_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELDG_VSYNC_INCLUDE_VSYNC_SIGNAL_IN_FIELD_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_fieldg_vsync_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a04L);
    system_hw_write_32(0x220a04L, (((uint32_t) (data & 0x1)) << 24) | (curr & 0xfeffffff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_fieldg_vsync_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a04L) & 0x1000000) >> 24);
}
// ------------------------------------------------------------------------------ //
// Register: fieldg window2
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELDG_WINDOW2_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELDG_WINDOW2_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELDG_WINDOW2_OFFSET (0xa04)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELDG_WINDOW2_MASK (0x2000000)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELDG_WINDOW2_EXCLUDE_WINDOW2_SIGNAL_IN_FIELD_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELDG_WINDOW2_INCLUDE_WINDOW2_SIGNAL_IN_FIELD_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_fieldg_window2_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a04L);
    system_hw_write_32(0x220a04L, (((uint32_t) (data & 0x1)) << 25) | (curr & 0xfdffffff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_fieldg_window2_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a04L) & 0x2000000) >> 25);
}
// ------------------------------------------------------------------------------ //
// Register: fieldg field
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELDG_FIELD_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELDG_FIELD_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELDG_FIELD_OFFSET (0xa04)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELDG_FIELD_MASK (0x4000000)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELDG_FIELD_EXCLUDE_FIELD_I_SIGNAL_IN_FIELD_GATE (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELDG_FIELD_INCLUDE_FIELD_I_SIGNAL_IN_FIELD_GATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_fieldg_field_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a04L);
    system_hw_write_32(0x220a04L, (((uint32_t) (data & 0x1)) << 26) | (curr & 0xfbffffff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_fieldg_field_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a04L) & 0x4000000) >> 26);
}
// ------------------------------------------------------------------------------ //
// Register: field mode
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELD_MODE_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELD_MODE_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELD_MODE_OFFSET (0xa04)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELD_MODE_MASK (0x8000000)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELD_MODE_PULSE_FIELD (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FIELD_MODE_TOGGLE_FIELD (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_field_mode_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a04L);
    system_hw_write_32(0x220a04L, (((uint32_t) (data & 0x1)) << 27) | (curr & 0xf7ffffff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_field_mode_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a04L) & 0x8000000) >> 27);
}
// ------------------------------------------------------------------------------ //
// Register: hc limit
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// horizontal counter limit value (counts: 0,1,...hc_limit-1,hc_limit,0,1,...)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HC_LIMIT_DEFAULT (0xFFFF)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HC_LIMIT_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HC_LIMIT_OFFSET (0xa08)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HC_LIMIT_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture3_input_port_hc_limit_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220a08L);
    system_hw_write_32(0x220a08L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture3_input_port_hc_limit_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220a08L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: hc start0
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// window0 start for ACL gate.  See ISP guide for further details.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HC_START0_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HC_START0_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HC_START0_OFFSET (0xa0c)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HC_START0_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture3_input_port_hc_start0_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220a0cL);
    system_hw_write_32(0x220a0cL, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture3_input_port_hc_start0_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220a0cL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: hc size0
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// window0 size for ACL gate.  See ISP guide for further details.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HC_SIZE0_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HC_SIZE0_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HC_SIZE0_OFFSET (0xa10)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HC_SIZE0_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture3_input_port_hc_size0_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220a10L);
    system_hw_write_32(0x220a10L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture3_input_port_hc_size0_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220a10L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: hc start1
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// window1 start for HS gate.  See ISP guide for further details.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HC_START1_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HC_START1_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HC_START1_OFFSET (0xa14)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HC_START1_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture3_input_port_hc_start1_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220a14L);
    system_hw_write_32(0x220a14L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture3_input_port_hc_start1_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220a14L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: hc size1
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// window1 size for HS gate.  See ISP guide for further details.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HC_SIZE1_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HC_SIZE1_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HC_SIZE1_OFFSET (0xa18)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_HC_SIZE1_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture3_input_port_hc_size1_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220a18L);
    system_hw_write_32(0x220a18L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture3_input_port_hc_size1_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220a18L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: vc limit
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// vertical counter limit value (counts: 0,1,...vc_limit-1,vc_limit,0,1,...)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VC_LIMIT_DEFAULT (0xFFFF)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VC_LIMIT_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VC_LIMIT_OFFSET (0xa1c)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VC_LIMIT_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture3_input_port_vc_limit_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220a1cL);
    system_hw_write_32(0x220a1cL, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture3_input_port_vc_limit_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220a1cL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: vc start
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// window2 start for ACL gate.  See ISP guide for further details.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VC_START_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VC_START_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VC_START_OFFSET (0xa20)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VC_START_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture3_input_port_vc_start_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220a20L);
    system_hw_write_32(0x220a20L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture3_input_port_vc_start_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220a20L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: vc size
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// window2 size for ACL gate.  See ISP guide for further details.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VC_SIZE_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VC_SIZE_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VC_SIZE_OFFSET (0xa24)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_VC_SIZE_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture3_input_port_vc_size_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220a24L);
    system_hw_write_32(0x220a24L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture3_input_port_vc_size_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220a24L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: frame width
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// detected frame width.  Read only value.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FRAME_WIDTH_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FRAME_WIDTH_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FRAME_WIDTH_OFFSET (0xa28)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FRAME_WIDTH_MASK (0xffff)

// args: data (16-bit)
static __inline uint16_t acamera_fpga_video_capture3_input_port_frame_width_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220a28L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: frame height
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// detected frame height.  Read only value.  
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FRAME_HEIGHT_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FRAME_HEIGHT_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FRAME_HEIGHT_OFFSET (0xa2c)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FRAME_HEIGHT_MASK (0xffff)

// args: data (16-bit)
static __inline uint16_t acamera_fpga_video_capture3_input_port_frame_height_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220a2cL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: mode request
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Used to stop and start input port.  See ISP guide for further details. 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_MODE_REQUEST_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_MODE_REQUEST_DATASIZE (3)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_MODE_REQUEST_OFFSET (0xa30)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_MODE_REQUEST_MASK (0x7)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_MODE_REQUEST_SAFE_STOP (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_MODE_REQUEST_SAFE_START (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_MODE_REQUEST_URGENT_STOP (2)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_MODE_REQUEST_URGENT_START (3)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_MODE_REQUEST_RESERVED4 (4)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_MODE_REQUEST_SAFER_START (5)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_MODE_REQUEST_RESERVED6 (6)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_MODE_REQUEST_RESERVED7 (7)

// args: data (3-bit)
static __inline void acamera_fpga_video_capture3_input_port_mode_request_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a30L);
    system_hw_write_32(0x220a30L, (((uint32_t) (data & 0x7)) << 0) | (curr & 0xfffffff8));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_mode_request_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a30L) & 0x7) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: freeze config
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Used to freeze input port configuration.  Used when multiple register writes are required to change input port configuration. 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FREEZE_CONFIG_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FREEZE_CONFIG_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FREEZE_CONFIG_OFFSET (0xa30)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FREEZE_CONFIG_MASK (0x80)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FREEZE_CONFIG_NORMAL_OPERATION (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_FREEZE_CONFIG_HOLD_PREVIOUS_INPUT_PORT_CONFIG_STATE (1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_input_port_freeze_config_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a30L);
    system_hw_write_32(0x220a30L, (((uint32_t) (data & 0x1)) << 7) | (curr & 0xffffff7f));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_freeze_config_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a30L) & 0x80) >> 7);
}
// ------------------------------------------------------------------------------ //
// Register: mode status
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 
//          Used to monitor input port status:
//          bit 0: 1=running, 0=stopped, bits 1,2-reserved
//        
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_MODE_STATUS_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_MODE_STATUS_DATASIZE (3)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_MODE_STATUS_OFFSET (0xa34)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_MODE_STATUS_MASK (0x7)

// args: data (3-bit)
static __inline uint8_t acamera_fpga_video_capture3_input_port_mode_status_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a34L) & 0x7) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: source
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 
//          Select source for capture:
//          0=sensor, 1=ISP video input, 2=ISP FR video output, 3=ISP DS video output
//        
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_SOURCE_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_SOURCE_DATASIZE (2)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_SOURCE_OFFSET (0xa34)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_INPUT_PORT_SOURCE_MASK (0x30000)

// args: data (2-bit)
static __inline void acamera_fpga_video_capture3_input_port_source_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a34L);
    system_hw_write_32(0x220a34L, (((uint32_t) (data & 0x3)) << 16) | (curr & 0xfffcffff));
}
static __inline uint8_t acamera_fpga_video_capture3_input_port_source_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a34L) & 0x30000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Group: Video-Capture-3 Frame Stats
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Register: stats reset
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_STATS_RESET_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_STATS_RESET_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_STATS_RESET_OFFSET (0xa80)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_STATS_RESET_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_frame_stats_stats_reset_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a80L);
    system_hw_write_32(0x220a80L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_video_capture3_frame_stats_stats_reset_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a80L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: stats hold
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_STATS_HOLD_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_STATS_HOLD_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_STATS_HOLD_OFFSET (0xa84)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_STATS_HOLD_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_frame_stats_stats_hold_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220a84L);
    system_hw_write_32(0x220a84L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_video_capture3_frame_stats_stats_hold_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220a84L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: active width min
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_WIDTH_MIN_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_WIDTH_MIN_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_WIDTH_MIN_OFFSET (0xa90)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_WIDTH_MIN_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture3_frame_stats_active_width_min_read(uintptr_t base) {
    return system_hw_read_32(0x220a90L);
}
// ------------------------------------------------------------------------------ //
// Register: active width max
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_WIDTH_MAX_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_WIDTH_MAX_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_WIDTH_MAX_OFFSET (0xa94)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_WIDTH_MAX_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture3_frame_stats_active_width_max_read(uintptr_t base) {
    return system_hw_read_32(0x220a94L);
}
// ------------------------------------------------------------------------------ //
// Register: active width sum
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_WIDTH_SUM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_WIDTH_SUM_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_WIDTH_SUM_OFFSET (0xa98)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_WIDTH_SUM_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture3_frame_stats_active_width_sum_read(uintptr_t base) {
    return system_hw_read_32(0x220a98L);
}
// ------------------------------------------------------------------------------ //
// Register: active width num
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_WIDTH_NUM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_WIDTH_NUM_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_WIDTH_NUM_OFFSET (0xa9c)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_WIDTH_NUM_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture3_frame_stats_active_width_num_read(uintptr_t base) {
    return system_hw_read_32(0x220a9cL);
}
// ------------------------------------------------------------------------------ //
// Register: active height min
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_HEIGHT_MIN_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_HEIGHT_MIN_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_HEIGHT_MIN_OFFSET (0xaa0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_HEIGHT_MIN_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture3_frame_stats_active_height_min_read(uintptr_t base) {
    return system_hw_read_32(0x220aa0L);
}
// ------------------------------------------------------------------------------ //
// Register: active height max
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_HEIGHT_MAX_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_HEIGHT_MAX_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_HEIGHT_MAX_OFFSET (0xaa4)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_HEIGHT_MAX_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture3_frame_stats_active_height_max_read(uintptr_t base) {
    return system_hw_read_32(0x220aa4L);
}
// ------------------------------------------------------------------------------ //
// Register: active height sum
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_HEIGHT_SUM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_HEIGHT_SUM_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_HEIGHT_SUM_OFFSET (0xaa8)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_HEIGHT_SUM_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture3_frame_stats_active_height_sum_read(uintptr_t base) {
    return system_hw_read_32(0x220aa8L);
}
// ------------------------------------------------------------------------------ //
// Register: active height num
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_HEIGHT_NUM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_HEIGHT_NUM_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_HEIGHT_NUM_OFFSET (0xaac)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_ACTIVE_HEIGHT_NUM_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture3_frame_stats_active_height_num_read(uintptr_t base) {
    return system_hw_read_32(0x220aacL);
}
// ------------------------------------------------------------------------------ //
// Register: hblank min
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_HBLANK_MIN_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_HBLANK_MIN_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_HBLANK_MIN_OFFSET (0xab0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_HBLANK_MIN_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture3_frame_stats_hblank_min_read(uintptr_t base) {
    return system_hw_read_32(0x220ab0L);
}
// ------------------------------------------------------------------------------ //
// Register: hblank max
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_HBLANK_MAX_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_HBLANK_MAX_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_HBLANK_MAX_OFFSET (0xab4)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_HBLANK_MAX_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture3_frame_stats_hblank_max_read(uintptr_t base) {
    return system_hw_read_32(0x220ab4L);
}
// ------------------------------------------------------------------------------ //
// Register: hblank sum
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_HBLANK_SUM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_HBLANK_SUM_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_HBLANK_SUM_OFFSET (0xab8)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_HBLANK_SUM_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture3_frame_stats_hblank_sum_read(uintptr_t base) {
    return system_hw_read_32(0x220ab8L);
}
// ------------------------------------------------------------------------------ //
// Register: hblank num
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_HBLANK_NUM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_HBLANK_NUM_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_HBLANK_NUM_OFFSET (0xabc)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_HBLANK_NUM_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture3_frame_stats_hblank_num_read(uintptr_t base) {
    return system_hw_read_32(0x220abcL);
}
// ------------------------------------------------------------------------------ //
// Register: vblank min
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_VBLANK_MIN_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_VBLANK_MIN_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_VBLANK_MIN_OFFSET (0xac0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_VBLANK_MIN_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture3_frame_stats_vblank_min_read(uintptr_t base) {
    return system_hw_read_32(0x220ac0L);
}
// ------------------------------------------------------------------------------ //
// Register: vblank max
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_VBLANK_MAX_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_VBLANK_MAX_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_VBLANK_MAX_OFFSET (0xac4)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_VBLANK_MAX_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture3_frame_stats_vblank_max_read(uintptr_t base) {
    return system_hw_read_32(0x220ac4L);
}
// ------------------------------------------------------------------------------ //
// Register: vblank sum
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_VBLANK_SUM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_VBLANK_SUM_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_VBLANK_SUM_OFFSET (0xac8)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_VBLANK_SUM_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture3_frame_stats_vblank_sum_read(uintptr_t base) {
    return system_hw_read_32(0x220ac8L);
}
// ------------------------------------------------------------------------------ //
// Register: vblank num
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_VBLANK_NUM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_VBLANK_NUM_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_VBLANK_NUM_OFFSET (0xacc)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_FRAME_STATS_VBLANK_NUM_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture3_frame_stats_vblank_num_read(uintptr_t base) {
    return system_hw_read_32(0x220accL);
}
// ------------------------------------------------------------------------------ //
// Group: Video-Capture-3 video test gen
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Video test generator controls.  See ISP Guide for further details
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Register: test_pattern_off on
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Test pattern off-on: 0=off, 1=on
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_TEST_PATTERN_OFF_ON_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_TEST_PATTERN_OFF_ON_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_TEST_PATTERN_OFF_ON_OFFSET (0xb00)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_TEST_PATTERN_OFF_ON_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_video_test_gen_test_pattern_off_on_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220b00L);
    system_hw_write_32(0x220b00L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_video_capture3_video_test_gen_test_pattern_off_on_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220b00L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: bayer_rgb_i sel
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Bayer or rgb select for input video: 0=bayer, 1=rgb
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_BAYER_RGB_I_SEL_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_BAYER_RGB_I_SEL_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_BAYER_RGB_I_SEL_OFFSET (0xb00)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_BAYER_RGB_I_SEL_MASK (0x2)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_video_test_gen_bayer_rgb_i_sel_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220b00L);
    system_hw_write_32(0x220b00L, (((uint32_t) (data & 0x1)) << 1) | (curr & 0xfffffffd));
}
static __inline uint8_t acamera_fpga_video_capture3_video_test_gen_bayer_rgb_i_sel_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220b00L) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: bayer_rgb_o sel
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Bayer or rgb select for output video: 0=bayer, 1=rgb
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_BAYER_RGB_O_SEL_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_BAYER_RGB_O_SEL_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_BAYER_RGB_O_SEL_OFFSET (0xb00)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_BAYER_RGB_O_SEL_MASK (0x4)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_video_test_gen_bayer_rgb_o_sel_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220b00L);
    system_hw_write_32(0x220b00L, (((uint32_t) (data & 0x1)) << 2) | (curr & 0xfffffffb));
}
static __inline uint8_t acamera_fpga_video_capture3_video_test_gen_bayer_rgb_o_sel_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220b00L) & 0x4) >> 2);
}
// ------------------------------------------------------------------------------ //
// Register: pattern type
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Pattern type select: 0=Flat field,1=Horizontal gradient,2=Vertical Gradient,3=Vertical Bars,4=Rectangle,5-255=Default white frame on black
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_PATTERN_TYPE_DEFAULT (0x03)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_PATTERN_TYPE_DATASIZE (8)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_PATTERN_TYPE_OFFSET (0xb04)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_PATTERN_TYPE_MASK (0xff)

// args: data (8-bit)
static __inline void acamera_fpga_video_capture3_video_test_gen_pattern_type_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220b04L);
    system_hw_write_32(0x220b04L, (((uint32_t) (data & 0xff)) << 0) | (curr & 0xffffff00));
}
static __inline uint8_t acamera_fpga_video_capture3_video_test_gen_pattern_type_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220b04L) & 0xff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: r backgnd
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Red background  value 16bit, MSB aligned to used width 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_R_BACKGND_DEFAULT (0xFFFF)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_R_BACKGND_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_R_BACKGND_OFFSET (0xb08)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_R_BACKGND_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture3_video_test_gen_r_backgnd_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220b08L);
    system_hw_write_32(0x220b08L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture3_video_test_gen_r_backgnd_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220b08L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: g backgnd
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Green background value 16bit, MSB aligned to used width
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_G_BACKGND_DEFAULT (0xFFFF)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_G_BACKGND_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_G_BACKGND_OFFSET (0xb0c)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_G_BACKGND_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture3_video_test_gen_g_backgnd_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220b0cL);
    system_hw_write_32(0x220b0cL, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture3_video_test_gen_g_backgnd_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220b0cL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: b backgnd
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Blue background value 16bit, MSB aligned to used width
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_B_BACKGND_DEFAULT (0xFFFF)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_B_BACKGND_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_B_BACKGND_OFFSET (0xb10)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_B_BACKGND_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture3_video_test_gen_b_backgnd_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220b10L);
    system_hw_write_32(0x220b10L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture3_video_test_gen_b_backgnd_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220b10L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: r foregnd
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Red foreground  value 16bit, MSB aligned to used width 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_R_FOREGND_DEFAULT (0x8FFF)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_R_FOREGND_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_R_FOREGND_OFFSET (0xb14)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_R_FOREGND_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture3_video_test_gen_r_foregnd_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220b14L);
    system_hw_write_32(0x220b14L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture3_video_test_gen_r_foregnd_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220b14L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: g foregnd
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Green foreground value 16bit, MSB aligned to used width
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_G_FOREGND_DEFAULT (0x8FFF)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_G_FOREGND_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_G_FOREGND_OFFSET (0xb18)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_G_FOREGND_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture3_video_test_gen_g_foregnd_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220b18L);
    system_hw_write_32(0x220b18L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture3_video_test_gen_g_foregnd_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220b18L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: b foregnd
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Blue foreground value 16bit, MSB aligned to used width
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_B_FOREGND_DEFAULT (0x8FFF)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_B_FOREGND_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_B_FOREGND_OFFSET (0xb1c)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_B_FOREGND_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture3_video_test_gen_b_foregnd_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220b1cL);
    system_hw_write_32(0x220b1cL, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture3_video_test_gen_b_foregnd_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220b1cL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: rgb gradient
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// RGB gradient increment per pixel (0-15)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_RGB_GRADIENT_DEFAULT (0x3CAA)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_RGB_GRADIENT_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_RGB_GRADIENT_OFFSET (0xb20)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_RGB_GRADIENT_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture3_video_test_gen_rgb_gradient_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220b20L);
    system_hw_write_32(0x220b20L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture3_video_test_gen_rgb_gradient_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220b20L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: rgb_gradient start
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// RGB gradient start value 16bit, MSB aligned to used width
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_RGB_GRADIENT_START_DEFAULT (0x0000)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_RGB_GRADIENT_START_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_RGB_GRADIENT_START_OFFSET (0xb24)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_RGB_GRADIENT_START_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture3_video_test_gen_rgb_gradient_start_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220b24L);
    system_hw_write_32(0x220b24L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture3_video_test_gen_rgb_gradient_start_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220b24L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: rect top
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  Rectangle top line number 1-n
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_RECT_TOP_DEFAULT (0x0001)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_RECT_TOP_DATASIZE (14)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_RECT_TOP_OFFSET (0xb28)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_RECT_TOP_MASK (0x3fff)

// args: data (14-bit)
static __inline void acamera_fpga_video_capture3_video_test_gen_rect_top_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220b28L);
    system_hw_write_32(0x220b28L, (((uint32_t) (data & 0x3fff)) << 0) | (curr & 0xffffc000));
}
static __inline uint16_t acamera_fpga_video_capture3_video_test_gen_rect_top_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220b28L) & 0x3fff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: rect bot
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  Rectangle bottom line number 1-n
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_RECT_BOT_DEFAULT (0x0100)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_RECT_BOT_DATASIZE (14)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_RECT_BOT_OFFSET (0xb2c)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_RECT_BOT_MASK (0x3fff)

// args: data (14-bit)
static __inline void acamera_fpga_video_capture3_video_test_gen_rect_bot_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220b2cL);
    system_hw_write_32(0x220b2cL, (((uint32_t) (data & 0x3fff)) << 0) | (curr & 0xffffc000));
}
static __inline uint16_t acamera_fpga_video_capture3_video_test_gen_rect_bot_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220b2cL) & 0x3fff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: rect left
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  Rectangle left pixel number 1-n
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_RECT_LEFT_DEFAULT (0x0001)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_RECT_LEFT_DATASIZE (14)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_RECT_LEFT_OFFSET (0xb30)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_RECT_LEFT_MASK (0x3fff)

// args: data (14-bit)
static __inline void acamera_fpga_video_capture3_video_test_gen_rect_left_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220b30L);
    system_hw_write_32(0x220b30L, (((uint32_t) (data & 0x3fff)) << 0) | (curr & 0xffffc000));
}
static __inline uint16_t acamera_fpga_video_capture3_video_test_gen_rect_left_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220b30L) & 0x3fff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: rect right
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  Rectangle right pixel number 1-n
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_RECT_RIGHT_DEFAULT (0x0100)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_RECT_RIGHT_DATASIZE (14)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_RECT_RIGHT_OFFSET (0xb38)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_VIDEO_TEST_GEN_RECT_RIGHT_MASK (0x3fff)

// args: data (14-bit)
static __inline void acamera_fpga_video_capture3_video_test_gen_rect_right_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220b38L);
    system_hw_write_32(0x220b38L, (((uint32_t) (data & 0x3fff)) << 0) | (curr & 0xffffc000));
}
static __inline uint16_t acamera_fpga_video_capture3_video_test_gen_rect_right_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220b38L) & 0x3fff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Group: Video-Capture-3 DMA Writer
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Video-Capture DMA writer controls
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Register: Format
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Format
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_FORMAT_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_FORMAT_DATASIZE (8)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_FORMAT_OFFSET (0xb80)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_FORMAT_MASK (0xff)

// args: data (8-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_format_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220b80L);
    system_hw_write_32(0x220b80L, (((uint32_t) (data & 0xff)) << 0) | (curr & 0xffffff00));
}
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_format_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220b80L) & 0xff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: Base mode
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Base DMA packing mode for RGB/RAW/YUV etc (see ISP guide)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BASE_MODE_DEFAULT (0x0D)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BASE_MODE_DATASIZE (4)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BASE_MODE_OFFSET (0xb80)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BASE_MODE_MASK (0xf)

// args: data (4-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_base_mode_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220b80L);
    system_hw_write_32(0x220b80L, (((uint32_t) (data & 0xf)) << 0) | (curr & 0xfffffff0));
}
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_base_mode_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220b80L) & 0xf) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: Plane select
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Plane select for planar base modes.  Only used if planar outputs required.  Not used.  Should be set to 0
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_PLANE_SELECT_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_PLANE_SELECT_DATASIZE (2)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_PLANE_SELECT_OFFSET (0xb80)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_PLANE_SELECT_MASK (0xc0)

// args: data (2-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_plane_select_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220b80L);
    system_hw_write_32(0x220b80L, (((uint32_t) (data & 0x3)) << 6) | (curr & 0xffffff3f));
}
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_plane_select_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220b80L) & 0xc0) >> 6);
}
// ------------------------------------------------------------------------------ //
// Register: single frame
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 0 = All frames are written(after frame_write_on= 1), 1= only 1st frame written ( after frame_write_on =1)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_SINGLE_FRAME_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_SINGLE_FRAME_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_SINGLE_FRAME_OFFSET (0xb84)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_SINGLE_FRAME_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_single_frame_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220b84L);
    system_hw_write_32(0x220b84L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_single_frame_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220b84L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: frame write on
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 
//    0 = no frames written(when switched from 1, current frame completes writing before stopping),
//    1= write frame(s) (write single or continous frame(s) )
//    
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_FRAME_WRITE_ON_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_FRAME_WRITE_ON_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_FRAME_WRITE_ON_OFFSET (0xb84)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_FRAME_WRITE_ON_MASK (0x2)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_frame_write_on_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220b84L);
    system_hw_write_32(0x220b84L, (((uint32_t) (data & 0x1)) << 1) | (curr & 0xfffffffd));
}
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_frame_write_on_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220b84L) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: half irate
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 0 = normal operation , 1= write half(alternate) of input frames( only valid for continuous mode)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_HALF_IRATE_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_HALF_IRATE_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_HALF_IRATE_OFFSET (0xb84)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_HALF_IRATE_MASK (0x4)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_half_irate_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220b84L);
    system_hw_write_32(0x220b84L, (((uint32_t) (data & 0x1)) << 2) | (curr & 0xfffffffb));
}
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_half_irate_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220b84L) & 0x4) >> 2);
}
// ------------------------------------------------------------------------------ //
// Register: axi xact comp
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 0 = dont wait for axi transaction completion at end of frame(just all transfers accepted). 1 = wait for all transactions completed
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_XACT_COMP_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_XACT_COMP_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_XACT_COMP_OFFSET (0xb84)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_XACT_COMP_MASK (0x8)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_axi_xact_comp_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220b84L);
    system_hw_write_32(0x220b84L, (((uint32_t) (data & 0x1)) << 3) | (curr & 0xfffffff7));
}
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_axi_xact_comp_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220b84L) & 0x8) >> 3);
}
// ------------------------------------------------------------------------------ //
// Register: active width
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Active video width in pixels 128-8000
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_ACTIVE_WIDTH_DEFAULT (0x780)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_ACTIVE_WIDTH_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_ACTIVE_WIDTH_OFFSET (0xb88)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_ACTIVE_WIDTH_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_active_width_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220b88L);
    system_hw_write_32(0x220b88L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture3_dma_writer_active_width_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220b88L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: active height
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Active video height in lines 128-8000
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_ACTIVE_HEIGHT_DEFAULT (0x438)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_ACTIVE_HEIGHT_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_ACTIVE_HEIGHT_OFFSET (0xb8c)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_ACTIVE_HEIGHT_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_active_height_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220b8cL);
    system_hw_write_32(0x220b8cL, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_video_capture3_dma_writer_active_height_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220b8cL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: bank0_base
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// bank 0 base address for frame buffer, should be word-aligned
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BANK0_BASE_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BANK0_BASE_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BANK0_BASE_OFFSET (0xb90)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BANK0_BASE_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_bank0_base_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x220b90L, data);
}
static __inline uint32_t acamera_fpga_video_capture3_dma_writer_bank0_base_read(uintptr_t base) {
    return system_hw_read_32(0x220b90L);
}
// ------------------------------------------------------------------------------ //
// Register: bank1_base
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// bank 1 base address for frame buffer, should be word-aligned
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BANK1_BASE_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BANK1_BASE_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BANK1_BASE_OFFSET (0xb94)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BANK1_BASE_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_bank1_base_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x220b94L, data);
}
static __inline uint32_t acamera_fpga_video_capture3_dma_writer_bank1_base_read(uintptr_t base) {
    return system_hw_read_32(0x220b94L);
}
// ------------------------------------------------------------------------------ //
// Register: bank2_base
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// bank 2 base address for frame buffer, should be word-aligned
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BANK2_BASE_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BANK2_BASE_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BANK2_BASE_OFFSET (0xb98)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BANK2_BASE_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_bank2_base_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x220b98L, data);
}
static __inline uint32_t acamera_fpga_video_capture3_dma_writer_bank2_base_read(uintptr_t base) {
    return system_hw_read_32(0x220b98L);
}
// ------------------------------------------------------------------------------ //
// Register: bank3_base
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// bank 3 base address for frame buffer, should be word-aligned
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BANK3_BASE_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BANK3_BASE_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BANK3_BASE_OFFSET (0xb9c)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BANK3_BASE_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_bank3_base_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x220b9cL, data);
}
static __inline uint32_t acamera_fpga_video_capture3_dma_writer_bank3_base_read(uintptr_t base) {
    return system_hw_read_32(0x220b9cL);
}
// ------------------------------------------------------------------------------ //
// Register: bank4_base
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// bank 4 base address for frame buffer, should be word-aligned
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BANK4_BASE_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BANK4_BASE_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BANK4_BASE_OFFSET (0xba0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BANK4_BASE_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_bank4_base_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x220ba0L, data);
}
static __inline uint32_t acamera_fpga_video_capture3_dma_writer_bank4_base_read(uintptr_t base) {
    return system_hw_read_32(0x220ba0L);
}
// ------------------------------------------------------------------------------ //
// Register: max bank
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// highest bank*_base to use for frame writes before recycling to bank0_base, only 0 to 4 are valid
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_MAX_BANK_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_MAX_BANK_DATASIZE (3)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_MAX_BANK_OFFSET (0xba4)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_MAX_BANK_MASK (0x7)

// args: data (3-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_max_bank_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220ba4L);
    system_hw_write_32(0x220ba4L, (((uint32_t) (data & 0x7)) << 0) | (curr & 0xfffffff8));
}
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_max_bank_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220ba4L) & 0x7) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: bank0 restart
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 0 = normal operation, 1= restart bank counter to bank0 for next frame write
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BANK0_RESTART_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BANK0_RESTART_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BANK0_RESTART_OFFSET (0xba4)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BANK0_RESTART_MASK (0x8)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_bank0_restart_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220ba4L);
    system_hw_write_32(0x220ba4L, (((uint32_t) (data & 0x1)) << 3) | (curr & 0xfffffff7));
}
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_bank0_restart_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220ba4L) & 0x8) >> 3);
}
// ------------------------------------------------------------------------------ //
// Register: Line_offset
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 
//    Indicates the offset in bytes from the start of one line to the next line.
//    This value should be equal to or larger than one line of image data and should be word-aligned
//    
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_LINE_OFFSET_DEFAULT (0x4000)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_LINE_OFFSET_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_LINE_OFFSET_OFFSET (0xba8)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_LINE_OFFSET_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_line_offset_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x220ba8L, data);
}
static __inline uint32_t acamera_fpga_video_capture3_dma_writer_line_offset_read(uintptr_t base) {
    return system_hw_read_32(0x220ba8L);
}
// ------------------------------------------------------------------------------ //
// Register: frame write cancel
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 0 = normal operation, 1= cancel current/future frame write(s), any unstarted AXI bursts cancelled and fifo flushed
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_FRAME_WRITE_CANCEL_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_FRAME_WRITE_CANCEL_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_FRAME_WRITE_CANCEL_OFFSET (0xbac)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_FRAME_WRITE_CANCEL_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_frame_write_cancel_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220bacL);
    system_hw_write_32(0x220bacL, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_frame_write_cancel_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220bacL) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: axi_port_enable
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// enables axi, active high, 1=enables axi write transfers, 0= reset axi domain( via reset synchroniser)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_PORT_ENABLE_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_PORT_ENABLE_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_PORT_ENABLE_OFFSET (0xbac)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_PORT_ENABLE_MASK (0x2)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_axi_port_enable_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220bacL);
    system_hw_write_32(0x220bacL, (((uint32_t) (data & 0x1)) << 1) | (curr & 0xfffffffd));
}
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_axi_port_enable_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220bacL) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: wbank curr
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// write bank currently active. valid values =0-4. updated at start of frame write
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBANK_CURR_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBANK_CURR_DATASIZE (3)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBANK_CURR_OFFSET (0xbb0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBANK_CURR_MASK (0x7)

// args: data (3-bit)
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_wbank_curr_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220bb0L) & 0x7) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: wbank last
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// write bank last active. valid values = 0-4. updated at start of frame write
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBANK_LAST_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBANK_LAST_DATASIZE (3)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBANK_LAST_OFFSET (0xbb0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBANK_LAST_MASK (0x38)

// args: data (3-bit)
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_wbank_last_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220bb0L) & 0x38) >> 3);
}
// ------------------------------------------------------------------------------ //
// Register: wbank active
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 1 = wbank_curr is being written to. Goes high at start of writes, low at last write transfer/completion on axi. 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBANK_ACTIVE_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBANK_ACTIVE_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBANK_ACTIVE_OFFSET (0xbb4)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBANK_ACTIVE_MASK (0x1)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_wbank_active_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220bb4L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: wbank start
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 1 = High pulse at start of frame write to bank. 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBANK_START_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBANK_START_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBANK_START_OFFSET (0xbb4)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBANK_START_MASK (0x2)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_wbank_start_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220bb4L) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: wbank stop
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 1 = High pulse at end of frame write to bank. 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBANK_STOP_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBANK_STOP_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBANK_STOP_OFFSET (0xbb4)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBANK_STOP_MASK (0x4)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_wbank_stop_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220bb4L) & 0x4) >> 2);
}
// ------------------------------------------------------------------------------ //
// Register: wbase curr
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// currently active bank base addr - in bytes. updated at start of frame write
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBASE_CURR_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBASE_CURR_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBASE_CURR_OFFSET (0xbb8)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBASE_CURR_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture3_dma_writer_wbase_curr_read(uintptr_t base) {
    return system_hw_read_32(0x220bb8L);
}
// ------------------------------------------------------------------------------ //
// Register: wbase last
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// last active bank base addr - in bytes. Updated at start of frame write
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBASE_LAST_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBASE_LAST_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBASE_LAST_OFFSET (0xbbc)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WBASE_LAST_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture3_dma_writer_wbase_last_read(uintptr_t base) {
    return system_hw_read_32(0x220bbcL);
}
// ------------------------------------------------------------------------------ //
// Register: frame icount
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// count of incomming frames (starts) to vdma_writer on video input, non resetable, rolls over, updates at pixel 1 of new frame on video in
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_FRAME_ICOUNT_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_FRAME_ICOUNT_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_FRAME_ICOUNT_OFFSET (0xbc0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_FRAME_ICOUNT_MASK (0xffff)

// args: data (16-bit)
static __inline uint16_t acamera_fpga_video_capture3_dma_writer_frame_icount_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220bc0L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: frame wcount
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// count of outgoing frame writes (starts) from vdma_writer sent to AXI output, non resetable, rolls over, updates at pixel 1 of new frame on video in
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_FRAME_WCOUNT_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_FRAME_WCOUNT_DATASIZE (16)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_FRAME_WCOUNT_OFFSET (0xbc4)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_FRAME_WCOUNT_MASK (0xffff)

// args: data (16-bit)
static __inline uint16_t acamera_fpga_video_capture3_dma_writer_frame_wcount_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220bc4L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: clear alarms
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 0>1 transition(synchronous detection) causes local axi/video alarm clear
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_CLEAR_ALARMS_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_CLEAR_ALARMS_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_CLEAR_ALARMS_OFFSET (0xbc8)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_CLEAR_ALARMS_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_clear_alarms_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220bc8L);
    system_hw_write_32(0x220bc8L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_clear_alarms_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220bc8L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: max_burst_length_is_8
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 1= Reduce default AXI max_burst_length from 16 to 8, 0= Dont reduce
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_MAX_BURST_LENGTH_IS_8_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_MAX_BURST_LENGTH_IS_8_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_MAX_BURST_LENGTH_IS_8_OFFSET (0xbc8)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_MAX_BURST_LENGTH_IS_8_MASK (0x2)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_max_burst_length_is_8_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220bc8L);
    system_hw_write_32(0x220bc8L, (((uint32_t) (data & 0x1)) << 1) | (curr & 0xfffffffd));
}
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_max_burst_length_is_8_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220bc8L) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: max_burst_length_is_4
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 1= Reduce default AXI max_burst_length from 16 to 4, 0= Dont reduce( has priority overmax_burst_length_is_8!)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_MAX_BURST_LENGTH_IS_4_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_MAX_BURST_LENGTH_IS_4_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_MAX_BURST_LENGTH_IS_4_OFFSET (0xbc8)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_MAX_BURST_LENGTH_IS_4_MASK (0x4)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_max_burst_length_is_4_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220bc8L);
    system_hw_write_32(0x220bc8L, (((uint32_t) (data & 0x1)) << 2) | (curr & 0xfffffffb));
}
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_max_burst_length_is_4_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220bc8L) & 0x4) >> 2);
}
// ------------------------------------------------------------------------------ //
// Register: write timeout disable
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 
//    At end of frame an optional timeout is applied to wait for AXI writes to completed/accepted befotre caneclling and flushing.
//    0= Timeout Enabled, timeout count can decrement.
//    1 = Disable timeout, timeout count can't decrement.
//    
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WRITE_TIMEOUT_DISABLE_DEFAULT (0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WRITE_TIMEOUT_DISABLE_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WRITE_TIMEOUT_DISABLE_OFFSET (0xbc8)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WRITE_TIMEOUT_DISABLE_MASK (0x8)

// args: data (1-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_write_timeout_disable_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220bc8L);
    system_hw_write_32(0x220bc8L, (((uint32_t) (data & 0x1)) << 3) | (curr & 0xfffffff7));
}
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_write_timeout_disable_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220bc8L) & 0x8) >> 3);
}
// ------------------------------------------------------------------------------ //
// Register: awmaxwait_limit
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// awvalid maxwait limit(cycles) to raise axi_fail_awmaxwait alarm . zero disables alarm raise.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AWMAXWAIT_LIMIT_DEFAULT (0x00)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AWMAXWAIT_LIMIT_DATASIZE (8)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AWMAXWAIT_LIMIT_OFFSET (0xbcc)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AWMAXWAIT_LIMIT_MASK (0xff)

// args: data (8-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_awmaxwait_limit_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220bccL);
    system_hw_write_32(0x220bccL, (((uint32_t) (data & 0xff)) << 0) | (curr & 0xffffff00));
}
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_awmaxwait_limit_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220bccL) & 0xff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: wmaxwait_limit
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// wvalid maxwait limit(cycles) to raise axi_fail_wmaxwait alarm . zero disables alarm raise
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WMAXWAIT_LIMIT_DEFAULT (0x00)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WMAXWAIT_LIMIT_DATASIZE (8)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WMAXWAIT_LIMIT_OFFSET (0xbd0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WMAXWAIT_LIMIT_MASK (0xff)

// args: data (8-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_wmaxwait_limit_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220bd0L);
    system_hw_write_32(0x220bd0L, (((uint32_t) (data & 0xff)) << 0) | (curr & 0xffffff00));
}
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_wmaxwait_limit_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220bd0L) & 0xff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: wxact_ostand_limit
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// number oustsanding write transactions(bursts)(responses..1 per burst) limit to raise axi_fail_wxact_ostand. zero disables alarm raise
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WXACT_OSTAND_LIMIT_DEFAULT (0x00)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WXACT_OSTAND_LIMIT_DATASIZE (8)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WXACT_OSTAND_LIMIT_OFFSET (0xbd4)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_WXACT_OSTAND_LIMIT_MASK (0xff)

// args: data (8-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_wxact_ostand_limit_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220bd4L);
    system_hw_write_32(0x220bd4L, (((uint32_t) (data & 0xff)) << 0) | (curr & 0xffffff00));
}
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_wxact_ostand_limit_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220bd4L) & 0xff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: axi_fail_bresp
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  clearable alarm, high to indicate bad  bresp captured 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_FAIL_BRESP_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_FAIL_BRESP_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_FAIL_BRESP_OFFSET (0xbd8)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_FAIL_BRESP_MASK (0x1)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_axi_fail_bresp_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220bd8L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: axi_fail_awmaxwait
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  clearable alarm, high when awmaxwait_limit reached 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_FAIL_AWMAXWAIT_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_FAIL_AWMAXWAIT_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_FAIL_AWMAXWAIT_OFFSET (0xbd8)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_FAIL_AWMAXWAIT_MASK (0x2)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_axi_fail_awmaxwait_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220bd8L) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: axi_fail_wmaxwait
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  clearable alarm, high when wmaxwait_limit reached 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_FAIL_WMAXWAIT_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_FAIL_WMAXWAIT_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_FAIL_WMAXWAIT_OFFSET (0xbd8)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_FAIL_WMAXWAIT_MASK (0x4)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_axi_fail_wmaxwait_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220bd8L) & 0x4) >> 2);
}
// ------------------------------------------------------------------------------ //
// Register: axi_fail_wxact_ostand
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  clearable alarm, high when wxact_ostand_limit reached 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_FAIL_WXACT_OSTAND_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_FAIL_WXACT_OSTAND_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_FAIL_WXACT_OSTAND_OFFSET (0xbd8)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_FAIL_WXACT_OSTAND_MASK (0x8)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_axi_fail_wxact_ostand_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220bd8L) & 0x8) >> 3);
}
// ------------------------------------------------------------------------------ //
// Register: vi_fail_active_width
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  clearable alarm, high to indicate mismatched active_width detected 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_VI_FAIL_ACTIVE_WIDTH_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_VI_FAIL_ACTIVE_WIDTH_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_VI_FAIL_ACTIVE_WIDTH_OFFSET (0xbd8)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_VI_FAIL_ACTIVE_WIDTH_MASK (0x10)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_vi_fail_active_width_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220bd8L) & 0x10) >> 4);
}
// ------------------------------------------------------------------------------ //
// Register: vi_fail_active_height
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  clearable alarm, high to indicate mismatched active_height detected ( also raised on missing field!) 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_VI_FAIL_ACTIVE_HEIGHT_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_VI_FAIL_ACTIVE_HEIGHT_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_VI_FAIL_ACTIVE_HEIGHT_OFFSET (0xbd8)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_VI_FAIL_ACTIVE_HEIGHT_MASK (0x20)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_vi_fail_active_height_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220bd8L) & 0x20) >> 5);
}
// ------------------------------------------------------------------------------ //
// Register: vi_fail_interline_blanks
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  clearable alarm, high to indicate interline blanking below min 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_VI_FAIL_INTERLINE_BLANKS_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_VI_FAIL_INTERLINE_BLANKS_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_VI_FAIL_INTERLINE_BLANKS_OFFSET (0xbd8)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_VI_FAIL_INTERLINE_BLANKS_MASK (0x40)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_vi_fail_interline_blanks_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220bd8L) & 0x40) >> 6);
}
// ------------------------------------------------------------------------------ //
// Register: vi_fail_interframe_blanks
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  clearable alarm, high to indicate interframe blanking below min 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_VI_FAIL_INTERFRAME_BLANKS_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_VI_FAIL_INTERFRAME_BLANKS_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_VI_FAIL_INTERFRAME_BLANKS_OFFSET (0xbd8)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_VI_FAIL_INTERFRAME_BLANKS_MASK (0x80)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_vi_fail_interframe_blanks_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220bd8L) & 0x80) >> 7);
}
// ------------------------------------------------------------------------------ //
// Register: video_alarm
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  active high, problem found on video port(s) ( active width/height or interline/frame blanks failure) 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_VIDEO_ALARM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_VIDEO_ALARM_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_VIDEO_ALARM_OFFSET (0xbdc)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_VIDEO_ALARM_MASK (0x1)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_video_alarm_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220bdcL) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: axi_alarm
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
//  active high, problem found on axi port(s)( bresp or awmaxwait or wmaxwait or wxact_ostand failure ) 
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_ALARM_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_ALARM_DATASIZE (1)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_ALARM_OFFSET (0xbdc)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_AXI_ALARM_MASK (0x2)

// args: data (1-bit)
static __inline uint8_t acamera_fpga_video_capture3_dma_writer_axi_alarm_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220bdcL) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: blk_config
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// block configuration (reserved)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BLK_CONFIG_DEFAULT (0x0000)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BLK_CONFIG_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BLK_CONFIG_OFFSET (0xbe0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BLK_CONFIG_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_video_capture3_dma_writer_blk_config_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x220be0L, data);
}
static __inline uint32_t acamera_fpga_video_capture3_dma_writer_blk_config_read(uintptr_t base) {
    return system_hw_read_32(0x220be0L);
}
// ------------------------------------------------------------------------------ //
// Register: blk_status
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// block status output (reserved)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BLK_STATUS_DEFAULT (0x0)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BLK_STATUS_DATASIZE (32)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BLK_STATUS_OFFSET (0xbe4)
#define ACAMERA_FPGA_VIDEO_CAPTURE3_DMA_WRITER_BLK_STATUS_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_video_capture3_dma_writer_blk_status_read(uintptr_t base) {
    return system_hw_read_32(0x220be4L);
}
// ------------------------------------------------------------------------------ //
// Group: HDMI top
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Register: Source
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Source: 0-RGB/RAW, 1-YUV
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_TOP_SOURCE_DEFAULT (0)
#define ACAMERA_FPGA_HDMI_TOP_SOURCE_DATASIZE (1)
#define ACAMERA_FPGA_HDMI_TOP_SOURCE_OFFSET (0xe00)
#define ACAMERA_FPGA_HDMI_TOP_SOURCE_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_hdmi_top_source_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220e00L);
    system_hw_write_32(0x220e00L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_hdmi_top_source_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220e00L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Group: HDMI sync
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Register: Offset X
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Offset in pixels from v-sync reference to start of active video
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_SYNC_OFFSET_X_DEFAULT (0)
#define ACAMERA_FPGA_HDMI_SYNC_OFFSET_X_DATASIZE (13)
#define ACAMERA_FPGA_HDMI_SYNC_OFFSET_X_OFFSET (0xe10)
#define ACAMERA_FPGA_HDMI_SYNC_OFFSET_X_MASK (0x1fff)

// args: data (13-bit)
static __inline void acamera_fpga_hdmi_sync_offset_x_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220e10L);
    system_hw_write_32(0x220e10L, (((uint32_t) (data & 0x1fff)) << 0) | (curr & 0xffffe000));
}
static __inline uint16_t acamera_fpga_hdmi_sync_offset_x_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220e10L) & 0x1fff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: Offset Y
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Offset in lines from v-sync reference to start of active video
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_SYNC_OFFSET_Y_DEFAULT (0)
#define ACAMERA_FPGA_HDMI_SYNC_OFFSET_Y_DATASIZE (13)
#define ACAMERA_FPGA_HDMI_SYNC_OFFSET_Y_OFFSET (0xe10)
#define ACAMERA_FPGA_HDMI_SYNC_OFFSET_Y_MASK (0x1fff0000)

// args: data (13-bit)
static __inline void acamera_fpga_hdmi_sync_offset_y_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220e10L);
    system_hw_write_32(0x220e10L, (((uint32_t) (data & 0x1fff)) << 16) | (curr & 0xe000ffff));
}
static __inline uint16_t acamera_fpga_hdmi_sync_offset_y_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220e10L) & 0x1fff0000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: Total Width
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Total frame width including horizontal blanking
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_SYNC_TOTAL_WIDTH_DEFAULT (2200)
#define ACAMERA_FPGA_HDMI_SYNC_TOTAL_WIDTH_DATASIZE (13)
#define ACAMERA_FPGA_HDMI_SYNC_TOTAL_WIDTH_OFFSET (0xe14)
#define ACAMERA_FPGA_HDMI_SYNC_TOTAL_WIDTH_MASK (0x1fff)

// args: data (13-bit)
static __inline void acamera_fpga_hdmi_sync_total_width_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220e14L);
    system_hw_write_32(0x220e14L, (((uint32_t) (data & 0x1fff)) << 0) | (curr & 0xffffe000));
}
static __inline uint16_t acamera_fpga_hdmi_sync_total_width_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220e14L) & 0x1fff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: Total Height
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Total frame height including vertical blanking
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_SYNC_TOTAL_HEIGHT_DEFAULT (1125)
#define ACAMERA_FPGA_HDMI_SYNC_TOTAL_HEIGHT_DATASIZE (13)
#define ACAMERA_FPGA_HDMI_SYNC_TOTAL_HEIGHT_OFFSET (0xe14)
#define ACAMERA_FPGA_HDMI_SYNC_TOTAL_HEIGHT_MASK (0x1fff0000)

// args: data (13-bit)
static __inline void acamera_fpga_hdmi_sync_total_height_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220e14L);
    system_hw_write_32(0x220e14L, (((uint32_t) (data & 0x1fff)) << 16) | (curr & 0xe000ffff));
}
static __inline uint16_t acamera_fpga_hdmi_sync_total_height_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220e14L) & 0x1fff0000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: Active Width
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Active video width in pixels
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_SYNC_ACTIVE_WIDTH_DEFAULT (1920)
#define ACAMERA_FPGA_HDMI_SYNC_ACTIVE_WIDTH_DATASIZE (13)
#define ACAMERA_FPGA_HDMI_SYNC_ACTIVE_WIDTH_OFFSET (0xe18)
#define ACAMERA_FPGA_HDMI_SYNC_ACTIVE_WIDTH_MASK (0x1fff)

// args: data (13-bit)
static __inline void acamera_fpga_hdmi_sync_active_width_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220e18L);
    system_hw_write_32(0x220e18L, (((uint32_t) (data & 0x1fff)) << 0) | (curr & 0xffffe000));
}
static __inline uint16_t acamera_fpga_hdmi_sync_active_width_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220e18L) & 0x1fff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: Active Height
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Active video height in lines
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_SYNC_ACTIVE_HEIGHT_DEFAULT (1080)
#define ACAMERA_FPGA_HDMI_SYNC_ACTIVE_HEIGHT_DATASIZE (13)
#define ACAMERA_FPGA_HDMI_SYNC_ACTIVE_HEIGHT_OFFSET (0xe18)
#define ACAMERA_FPGA_HDMI_SYNC_ACTIVE_HEIGHT_MASK (0x1fff0000)

// args: data (13-bit)
static __inline void acamera_fpga_hdmi_sync_active_height_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220e18L);
    system_hw_write_32(0x220e18L, (((uint32_t) (data & 0x1fff)) << 16) | (curr & 0xe000ffff));
}
static __inline uint16_t acamera_fpga_hdmi_sync_active_height_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220e18L) & 0x1fff0000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: H Front Porch
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Horizontal sync front porch (for DVI out)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_SYNC_H_FRONT_PORCH_DEFAULT (87)
#define ACAMERA_FPGA_HDMI_SYNC_H_FRONT_PORCH_DATASIZE (13)
#define ACAMERA_FPGA_HDMI_SYNC_H_FRONT_PORCH_OFFSET (0xe1c)
#define ACAMERA_FPGA_HDMI_SYNC_H_FRONT_PORCH_MASK (0x1fff)

// args: data (13-bit)
static __inline void acamera_fpga_hdmi_sync_h_front_porch_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220e1cL);
    system_hw_write_32(0x220e1cL, (((uint32_t) (data & 0x1fff)) << 0) | (curr & 0xffffe000));
}
static __inline uint16_t acamera_fpga_hdmi_sync_h_front_porch_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220e1cL) & 0x1fff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: V Front Porch
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Vertical sync front porch (for DVI out)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_SYNC_V_FRONT_PORCH_DEFAULT (3)
#define ACAMERA_FPGA_HDMI_SYNC_V_FRONT_PORCH_DATASIZE (13)
#define ACAMERA_FPGA_HDMI_SYNC_V_FRONT_PORCH_OFFSET (0xe1c)
#define ACAMERA_FPGA_HDMI_SYNC_V_FRONT_PORCH_MASK (0x1fff0000)

// args: data (13-bit)
static __inline void acamera_fpga_hdmi_sync_v_front_porch_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220e1cL);
    system_hw_write_32(0x220e1cL, (((uint32_t) (data & 0x1fff)) << 16) | (curr & 0xe000ffff));
}
static __inline uint16_t acamera_fpga_hdmi_sync_v_front_porch_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220e1cL) & 0x1fff0000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: H-Sync Width
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Horizontal sync width (for DVI out)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_SYNC_H_SYNC_WIDTH_DEFAULT (44)
#define ACAMERA_FPGA_HDMI_SYNC_H_SYNC_WIDTH_DATASIZE (13)
#define ACAMERA_FPGA_HDMI_SYNC_H_SYNC_WIDTH_OFFSET (0xe20)
#define ACAMERA_FPGA_HDMI_SYNC_H_SYNC_WIDTH_MASK (0x1fff)

// args: data (13-bit)
static __inline void acamera_fpga_hdmi_sync_h_sync_width_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220e20L);
    system_hw_write_32(0x220e20L, (((uint32_t) (data & 0x1fff)) << 0) | (curr & 0xffffe000));
}
static __inline uint16_t acamera_fpga_hdmi_sync_h_sync_width_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220e20L) & 0x1fff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: V-Sync Width
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Vertical sync width (for DVI out)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_SYNC_V_SYNC_WIDTH_DEFAULT (5)
#define ACAMERA_FPGA_HDMI_SYNC_V_SYNC_WIDTH_DATASIZE (13)
#define ACAMERA_FPGA_HDMI_SYNC_V_SYNC_WIDTH_OFFSET (0xe20)
#define ACAMERA_FPGA_HDMI_SYNC_V_SYNC_WIDTH_MASK (0x1fff0000)

// args: data (13-bit)
static __inline void acamera_fpga_hdmi_sync_v_sync_width_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220e20L);
    system_hw_write_32(0x220e20L, (((uint32_t) (data & 0x1fff)) << 16) | (curr & 0xe000ffff));
}
static __inline uint16_t acamera_fpga_hdmi_sync_v_sync_width_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220e20L) & 0x1fff0000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: H Sync Pol
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Horizontal sync out polarity (for DVI out)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_SYNC_H_SYNC_POL_DEFAULT (1)
#define ACAMERA_FPGA_HDMI_SYNC_H_SYNC_POL_DATASIZE (1)
#define ACAMERA_FPGA_HDMI_SYNC_H_SYNC_POL_OFFSET (0xe24)
#define ACAMERA_FPGA_HDMI_SYNC_H_SYNC_POL_MASK (0x4)

// args: data (1-bit)
static __inline void acamera_fpga_hdmi_sync_h_sync_pol_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220e24L);
    system_hw_write_32(0x220e24L, (((uint32_t) (data & 0x1)) << 2) | (curr & 0xfffffffb));
}
static __inline uint8_t acamera_fpga_hdmi_sync_h_sync_pol_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220e24L) & 0x4) >> 2);
}
// ------------------------------------------------------------------------------ //
// Register: V Sync Pol
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Vertical sync out polarity (for DVI out)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_SYNC_V_SYNC_POL_DEFAULT (1)
#define ACAMERA_FPGA_HDMI_SYNC_V_SYNC_POL_DATASIZE (1)
#define ACAMERA_FPGA_HDMI_SYNC_V_SYNC_POL_OFFSET (0xe24)
#define ACAMERA_FPGA_HDMI_SYNC_V_SYNC_POL_MASK (0x8)

// args: data (1-bit)
static __inline void acamera_fpga_hdmi_sync_v_sync_pol_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220e24L);
    system_hw_write_32(0x220e24L, (((uint32_t) (data & 0x1)) << 3) | (curr & 0xfffffff7));
}
static __inline uint8_t acamera_fpga_hdmi_sync_v_sync_pol_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220e24L) & 0x8) >> 3);
}
// ------------------------------------------------------------------------------ //
// Group: Frame Reader
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Register: format
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FRAME_READER_FORMAT_DEFAULT (0)
#define ACAMERA_FPGA_FRAME_READER_FORMAT_DATASIZE (8)
#define ACAMERA_FPGA_FRAME_READER_FORMAT_OFFSET (0xe80)
#define ACAMERA_FPGA_FRAME_READER_FORMAT_MASK (0xff)

// args: data (8-bit)
static __inline void acamera_fpga_frame_reader_format_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220e80L);
    system_hw_write_32(0x220e80L, (((uint32_t) (data & 0xff)) << 0) | (curr & 0xffffff00));
}
static __inline uint8_t acamera_fpga_frame_reader_format_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220e80L) & 0xff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: rbase load
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FRAME_READER_RBASE_LOAD_DEFAULT (0x0)
#define ACAMERA_FPGA_FRAME_READER_RBASE_LOAD_DATASIZE (1)
#define ACAMERA_FPGA_FRAME_READER_RBASE_LOAD_OFFSET (0xe8c)
#define ACAMERA_FPGA_FRAME_READER_RBASE_LOAD_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_frame_reader_rbase_load_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220e8cL);
    system_hw_write_32(0x220e8cL, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_frame_reader_rbase_load_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220e8cL) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: rbase load sel
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Selector for rbase_load strobe: 0-field, 1-configuration bit rbase_load
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FRAME_READER_RBASE_LOAD_SEL_DEFAULT (0x0)
#define ACAMERA_FPGA_FRAME_READER_RBASE_LOAD_SEL_DATASIZE (1)
#define ACAMERA_FPGA_FRAME_READER_RBASE_LOAD_SEL_OFFSET (0xe8c)
#define ACAMERA_FPGA_FRAME_READER_RBASE_LOAD_SEL_MASK (0x10)

// args: data (1-bit)
static __inline void acamera_fpga_frame_reader_rbase_load_sel_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220e8cL);
    system_hw_write_32(0x220e8cL, (((uint32_t) (data & 0x1)) << 4) | (curr & 0xffffffef));
}
static __inline uint8_t acamera_fpga_frame_reader_rbase_load_sel_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220e8cL) & 0x10) >> 4);
}
// ------------------------------------------------------------------------------ //
// Register: rbase
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Base address for frame buffer, should be word-aligned
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FRAME_READER_RBASE_DEFAULT (0x0)
#define ACAMERA_FPGA_FRAME_READER_RBASE_DATASIZE (32)
#define ACAMERA_FPGA_FRAME_READER_RBASE_OFFSET (0xe90)
#define ACAMERA_FPGA_FRAME_READER_RBASE_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_frame_reader_rbase_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x220e90L, data);
}
static __inline uint32_t acamera_fpga_frame_reader_rbase_read(uintptr_t base) {
    return system_hw_read_32(0x220e90L);
}
// ------------------------------------------------------------------------------ //
// Register: Line_offset
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Indicates offset in bytes from the start of one line to the next line. Should be word-aligned
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FRAME_READER_LINE_OFFSET_DEFAULT (0x1000)
#define ACAMERA_FPGA_FRAME_READER_LINE_OFFSET_DATASIZE (32)
#define ACAMERA_FPGA_FRAME_READER_LINE_OFFSET_OFFSET (0xe94)
#define ACAMERA_FPGA_FRAME_READER_LINE_OFFSET_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_frame_reader_line_offset_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x220e94L, data);
}
static __inline uint32_t acamera_fpga_frame_reader_line_offset_read(uintptr_t base) {
    return system_hw_read_32(0x220e94L);
}
// ------------------------------------------------------------------------------ //
// Register: axi_port_enable
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FRAME_READER_AXI_PORT_ENABLE_DEFAULT (0x0)
#define ACAMERA_FPGA_FRAME_READER_AXI_PORT_ENABLE_DATASIZE (1)
#define ACAMERA_FPGA_FRAME_READER_AXI_PORT_ENABLE_OFFSET (0xe98)
#define ACAMERA_FPGA_FRAME_READER_AXI_PORT_ENABLE_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_frame_reader_axi_port_enable_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220e98L);
    system_hw_write_32(0x220e98L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_frame_reader_axi_port_enable_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220e98L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: config
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FRAME_READER_CONFIG_DEFAULT (0x0000)
#define ACAMERA_FPGA_FRAME_READER_CONFIG_DATASIZE (32)
#define ACAMERA_FPGA_FRAME_READER_CONFIG_OFFSET (0xea0)
#define ACAMERA_FPGA_FRAME_READER_CONFIG_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_frame_reader_config_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x220ea0L, data);
}
static __inline uint32_t acamera_fpga_frame_reader_config_read(uintptr_t base) {
    return system_hw_read_32(0x220ea0L);
}
// ------------------------------------------------------------------------------ //
// Register: status
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FRAME_READER_STATUS_DEFAULT (0x0)
#define ACAMERA_FPGA_FRAME_READER_STATUS_DATASIZE (32)
#define ACAMERA_FPGA_FRAME_READER_STATUS_OFFSET (0xea4)
#define ACAMERA_FPGA_FRAME_READER_STATUS_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_frame_reader_status_read(uintptr_t base) {
    return system_hw_read_32(0x220ea4L);
}
// ------------------------------------------------------------------------------ //
// Register: active_width
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FRAME_READER_ACTIVE_WIDTH_DEFAULT (0x0780)
#define ACAMERA_FPGA_FRAME_READER_ACTIVE_WIDTH_DATASIZE (16)
#define ACAMERA_FPGA_FRAME_READER_ACTIVE_WIDTH_OFFSET (0xea8)
#define ACAMERA_FPGA_FRAME_READER_ACTIVE_WIDTH_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_frame_reader_active_width_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220ea8L);
    system_hw_write_32(0x220ea8L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_frame_reader_active_width_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220ea8L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: active_height
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FRAME_READER_ACTIVE_HEIGHT_DEFAULT (0x0438)
#define ACAMERA_FPGA_FRAME_READER_ACTIVE_HEIGHT_DATASIZE (16)
#define ACAMERA_FPGA_FRAME_READER_ACTIVE_HEIGHT_OFFSET (0xeac)
#define ACAMERA_FPGA_FRAME_READER_ACTIVE_HEIGHT_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_frame_reader_active_height_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220eacL);
    system_hw_write_32(0x220eacL, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_frame_reader_active_height_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220eacL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Group: Frame Reader UV
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Register: format
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FRAME_READER_UV_FORMAT_DEFAULT (0)
#define ACAMERA_FPGA_FRAME_READER_UV_FORMAT_DATASIZE (8)
#define ACAMERA_FPGA_FRAME_READER_UV_FORMAT_OFFSET (0xec0)
#define ACAMERA_FPGA_FRAME_READER_UV_FORMAT_MASK (0xff)

// args: data (8-bit)
static __inline void acamera_fpga_frame_reader_uv_format_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220ec0L);
    system_hw_write_32(0x220ec0L, (((uint32_t) (data & 0xff)) << 0) | (curr & 0xffffff00));
}
static __inline uint8_t acamera_fpga_frame_reader_uv_format_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220ec0L) & 0xff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: repeat_downsampled_lines
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 1=U/V values for unsampled 4:2:0 lines repeated from previous line(double axi line reads) on output video, 0=default values inserted for 4:2:0 unsampled lines
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FRAME_READER_UV_REPEAT_DOWNSAMPLED_LINES_DEFAULT (0)
#define ACAMERA_FPGA_FRAME_READER_UV_REPEAT_DOWNSAMPLED_LINES_DATASIZE (1)
#define ACAMERA_FPGA_FRAME_READER_UV_REPEAT_DOWNSAMPLED_LINES_OFFSET (0xec4)
#define ACAMERA_FPGA_FRAME_READER_UV_REPEAT_DOWNSAMPLED_LINES_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_frame_reader_uv_repeat_downsampled_lines_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220ec4L);
    system_hw_write_32(0x220ec4L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_frame_reader_uv_repeat_downsampled_lines_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220ec4L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: repeat_downsampled_pixels
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 1=U/V values for unsampled 4:2:0 pixels repeated from previous pixel(within a line) on output video, 0=default values inserted for 4:2:0 unsampled pixels
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FRAME_READER_UV_REPEAT_DOWNSAMPLED_PIXELS_DEFAULT (0)
#define ACAMERA_FPGA_FRAME_READER_UV_REPEAT_DOWNSAMPLED_PIXELS_DATASIZE (1)
#define ACAMERA_FPGA_FRAME_READER_UV_REPEAT_DOWNSAMPLED_PIXELS_OFFSET (0xec4)
#define ACAMERA_FPGA_FRAME_READER_UV_REPEAT_DOWNSAMPLED_PIXELS_MASK (0x2)

// args: data (1-bit)
static __inline void acamera_fpga_frame_reader_uv_repeat_downsampled_pixels_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220ec4L);
    system_hw_write_32(0x220ec4L, (((uint32_t) (data & 0x1)) << 1) | (curr & 0xfffffffd));
}
static __inline uint8_t acamera_fpga_frame_reader_uv_repeat_downsampled_pixels_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220ec4L) & 0x2) >> 1);
}
// ------------------------------------------------------------------------------ //
// Register: rbase load
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FRAME_READER_UV_RBASE_LOAD_DEFAULT (0x0)
#define ACAMERA_FPGA_FRAME_READER_UV_RBASE_LOAD_DATASIZE (1)
#define ACAMERA_FPGA_FRAME_READER_UV_RBASE_LOAD_OFFSET (0xecc)
#define ACAMERA_FPGA_FRAME_READER_UV_RBASE_LOAD_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_frame_reader_uv_rbase_load_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220eccL);
    system_hw_write_32(0x220eccL, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_frame_reader_uv_rbase_load_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220eccL) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: rbase load sel
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Selector for rbase_load strobe: 0-field, 1-configuration bit rbase_load
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FRAME_READER_UV_RBASE_LOAD_SEL_DEFAULT (0x0)
#define ACAMERA_FPGA_FRAME_READER_UV_RBASE_LOAD_SEL_DATASIZE (1)
#define ACAMERA_FPGA_FRAME_READER_UV_RBASE_LOAD_SEL_OFFSET (0xecc)
#define ACAMERA_FPGA_FRAME_READER_UV_RBASE_LOAD_SEL_MASK (0x10)

// args: data (1-bit)
static __inline void acamera_fpga_frame_reader_uv_rbase_load_sel_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220eccL);
    system_hw_write_32(0x220eccL, (((uint32_t) (data & 0x1)) << 4) | (curr & 0xffffffef));
}
static __inline uint8_t acamera_fpga_frame_reader_uv_rbase_load_sel_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220eccL) & 0x10) >> 4);
}
// ------------------------------------------------------------------------------ //
// Register: rbase
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Base address for frame buffer, should be word-aligned
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FRAME_READER_UV_RBASE_DEFAULT (0x0)
#define ACAMERA_FPGA_FRAME_READER_UV_RBASE_DATASIZE (32)
#define ACAMERA_FPGA_FRAME_READER_UV_RBASE_OFFSET (0xed0)
#define ACAMERA_FPGA_FRAME_READER_UV_RBASE_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_frame_reader_uv_rbase_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x220ed0L, data);
}
static __inline uint32_t acamera_fpga_frame_reader_uv_rbase_read(uintptr_t base) {
    return system_hw_read_32(0x220ed0L);
}
// ------------------------------------------------------------------------------ //
// Register: Line_offset
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Indicates offset in bytes from the start of one line to the next line. Should be word-aligned
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FRAME_READER_UV_LINE_OFFSET_DEFAULT (0x1000)
#define ACAMERA_FPGA_FRAME_READER_UV_LINE_OFFSET_DATASIZE (32)
#define ACAMERA_FPGA_FRAME_READER_UV_LINE_OFFSET_OFFSET (0xed4)
#define ACAMERA_FPGA_FRAME_READER_UV_LINE_OFFSET_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_frame_reader_uv_line_offset_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x220ed4L, data);
}
static __inline uint32_t acamera_fpga_frame_reader_uv_line_offset_read(uintptr_t base) {
    return system_hw_read_32(0x220ed4L);
}
// ------------------------------------------------------------------------------ //
// Register: axi_port_enable
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FRAME_READER_UV_AXI_PORT_ENABLE_DEFAULT (0x0)
#define ACAMERA_FPGA_FRAME_READER_UV_AXI_PORT_ENABLE_DATASIZE (1)
#define ACAMERA_FPGA_FRAME_READER_UV_AXI_PORT_ENABLE_OFFSET (0xed8)
#define ACAMERA_FPGA_FRAME_READER_UV_AXI_PORT_ENABLE_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_frame_reader_uv_axi_port_enable_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220ed8L);
    system_hw_write_32(0x220ed8L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_frame_reader_uv_axi_port_enable_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220ed8L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: config
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FRAME_READER_UV_CONFIG_DEFAULT (0x0000)
#define ACAMERA_FPGA_FRAME_READER_UV_CONFIG_DATASIZE (32)
#define ACAMERA_FPGA_FRAME_READER_UV_CONFIG_OFFSET (0xee0)
#define ACAMERA_FPGA_FRAME_READER_UV_CONFIG_MASK (0xffffffff)

// args: data (32-bit)
static __inline void acamera_fpga_frame_reader_uv_config_write(uintptr_t base, uint32_t data) {
    system_hw_write_32(0x220ee0L, data);
}
static __inline uint32_t acamera_fpga_frame_reader_uv_config_read(uintptr_t base) {
    return system_hw_read_32(0x220ee0L);
}
// ------------------------------------------------------------------------------ //
// Register: status
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FRAME_READER_UV_STATUS_DEFAULT (0x0)
#define ACAMERA_FPGA_FRAME_READER_UV_STATUS_DATASIZE (32)
#define ACAMERA_FPGA_FRAME_READER_UV_STATUS_OFFSET (0xee4)
#define ACAMERA_FPGA_FRAME_READER_UV_STATUS_MASK (0xffffffff)

// args: data (32-bit)
static __inline uint32_t acamera_fpga_frame_reader_uv_status_read(uintptr_t base) {
    return system_hw_read_32(0x220ee4L);
}
// ------------------------------------------------------------------------------ //
// Register: active_width
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FRAME_READER_UV_ACTIVE_WIDTH_DEFAULT (0x0780)
#define ACAMERA_FPGA_FRAME_READER_UV_ACTIVE_WIDTH_DATASIZE (16)
#define ACAMERA_FPGA_FRAME_READER_UV_ACTIVE_WIDTH_OFFSET (0xee8)
#define ACAMERA_FPGA_FRAME_READER_UV_ACTIVE_WIDTH_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_frame_reader_uv_active_width_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220ee8L);
    system_hw_write_32(0x220ee8L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_frame_reader_uv_active_width_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220ee8L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: active_height
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_FRAME_READER_UV_ACTIVE_HEIGHT_DEFAULT (0x0438)
#define ACAMERA_FPGA_FRAME_READER_UV_ACTIVE_HEIGHT_DATASIZE (16)
#define ACAMERA_FPGA_FRAME_READER_UV_ACTIVE_HEIGHT_OFFSET (0xeec)
#define ACAMERA_FPGA_FRAME_READER_UV_ACTIVE_HEIGHT_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_frame_reader_uv_active_height_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220eecL);
    system_hw_write_32(0x220eecL, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_frame_reader_uv_active_height_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220eecL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Group: HDMI YUV Downsampler
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Register: enable_horiz_downsample
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// enable_horizontal_downsample, active high, downsamples YUV444 to YUV422
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_ENABLE_HORIZ_DOWNSAMPLE_DEFAULT (0)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_ENABLE_HORIZ_DOWNSAMPLE_DATASIZE (1)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_ENABLE_HORIZ_DOWNSAMPLE_OFFSET (0xf00)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_ENABLE_HORIZ_DOWNSAMPLE_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_enable_horiz_downsample_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220f00L);
    system_hw_write_32(0x220f00L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_hdmi_yuv_downsampler_enable_horiz_downsample_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220f00L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: enable_vert_downsample
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// enable_vertical_downsample, active high, downsamples YUV422 to YUV420 ( requires enable_horiz_downsample = '1')
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_ENABLE_VERT_DOWNSAMPLE_DEFAULT (0)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_ENABLE_VERT_DOWNSAMPLE_DATASIZE (1)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_ENABLE_VERT_DOWNSAMPLE_OFFSET (0xf00)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_ENABLE_VERT_DOWNSAMPLE_MASK (0x100)

// args: data (1-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_enable_vert_downsample_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220f00L);
    system_hw_write_32(0x220f00L, (((uint32_t) (data & 0x1)) << 8) | (curr & 0xfffffeff));
}
static __inline uint8_t acamera_fpga_hdmi_yuv_downsampler_enable_vert_downsample_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220f00L) & 0x100) >> 8);
}
// ------------------------------------------------------------------------------ //
// Register: enable_horiz_filter
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// enable_filter, active high, turns on horizontal 7 tap lanczos filter
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_ENABLE_HORIZ_FILTER_DEFAULT (0)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_ENABLE_HORIZ_FILTER_DATASIZE (1)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_ENABLE_HORIZ_FILTER_OFFSET (0xf00)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_ENABLE_HORIZ_FILTER_MASK (0x10000)

// args: data (1-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_enable_horiz_filter_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220f00L);
    system_hw_write_32(0x220f00L, (((uint32_t) (data & 0x1)) << 16) | (curr & 0xfffeffff));
}
static __inline uint8_t acamera_fpga_hdmi_yuv_downsampler_enable_horiz_filter_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220f00L) & 0x10000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: enable_matrix
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// active high, turn on colour space conversion matrix ( eg for RGB to YUV conversion)
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_ENABLE_MATRIX_DEFAULT (0)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_ENABLE_MATRIX_DATASIZE (1)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_ENABLE_MATRIX_OFFSET (0xf00)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_ENABLE_MATRIX_MASK (0x1000000)

// args: data (1-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_enable_matrix_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220f00L);
    system_hw_write_32(0x220f00L, (((uint32_t) (data & 0x1)) << 24) | (curr & 0xfeffffff));
}
static __inline uint8_t acamera_fpga_hdmi_yuv_downsampler_enable_matrix_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220f00L) & 0x1000000) >> 24);
}
// ------------------------------------------------------------------------------ //
// Register: matrix_11
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// coefft_11 sign|2bit|8bit precision
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_11_DEFAULT (0x012A)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_11_DATASIZE (16)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_11_OFFSET (0xf10)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_11_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_matrix_11_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220f10L);
    system_hw_write_32(0x220f10L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_hdmi_yuv_downsampler_matrix_11_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220f10L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: matrix_12
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// coefft_12 sign|2bit|8bit precision
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_12_DEFAULT (0x0000)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_12_DATASIZE (16)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_12_OFFSET (0xf14)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_12_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_matrix_12_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220f14L);
    system_hw_write_32(0x220f14L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_hdmi_yuv_downsampler_matrix_12_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220f14L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: matrix_13
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// coefft_13 sign|2bit|8bit precision
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_13_DEFAULT (0x0199)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_13_DATASIZE (16)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_13_OFFSET (0xf18)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_13_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_matrix_13_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220f18L);
    system_hw_write_32(0x220f18L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_hdmi_yuv_downsampler_matrix_13_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220f18L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: matrix_21
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// coefft_21 sign|2bit|8bit precision
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_21_DEFAULT (0x012A)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_21_DATASIZE (16)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_21_OFFSET (0xf1c)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_21_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_matrix_21_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220f1cL);
    system_hw_write_32(0x220f1cL, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_hdmi_yuv_downsampler_matrix_21_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220f1cL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: matrix_22
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// coefft_22 sign|2bit|8bit precision
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_22_DEFAULT (0xF064)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_22_DATASIZE (16)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_22_OFFSET (0xf20)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_22_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_matrix_22_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220f20L);
    system_hw_write_32(0x220f20L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_hdmi_yuv_downsampler_matrix_22_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220f20L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: matrix_23
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// coefft_23 sign|2bit|8bit precision
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_23_DEFAULT (0xF0D0)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_23_DATASIZE (16)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_23_OFFSET (0xf24)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_23_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_matrix_23_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220f24L);
    system_hw_write_32(0x220f24L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_hdmi_yuv_downsampler_matrix_23_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220f24L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: matrix_31
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// coefft_31 sign|2bit|8bit precision
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_31_DEFAULT (0x012A)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_31_DATASIZE (16)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_31_OFFSET (0xf28)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_31_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_matrix_31_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220f28L);
    system_hw_write_32(0x220f28L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_hdmi_yuv_downsampler_matrix_31_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220f28L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: matrix_32
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// coefft_32 sign|2bit|8bit precision
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_32_DEFAULT (0x0205)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_32_DATASIZE (16)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_32_OFFSET (0xf2c)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_32_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_matrix_32_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220f2cL);
    system_hw_write_32(0x220f2cL, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_hdmi_yuv_downsampler_matrix_32_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220f2cL) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: matrix_33
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// coefft_33 sign|2bit|8bit precision
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_33_DEFAULT (0x0000)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_33_DATASIZE (16)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_33_OFFSET (0xf30)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_33_MASK (0xffff)

// args: data (16-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_matrix_33_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220f30L);
    system_hw_write_32(0x220f30L, (((uint32_t) (data & 0xffff)) << 0) | (curr & 0xffff0000));
}
static __inline uint16_t acamera_fpga_hdmi_yuv_downsampler_matrix_33_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220f30L) & 0xffff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: matrix_o1
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// coefft_o1 complementary format, extra bit for sign
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_O1_DEFAULT (0x485)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_O1_DATASIZE (11)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_O1_OFFSET (0xf38)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_O1_MASK (0x7ff)

// args: data (11-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_matrix_o1_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220f38L);
    system_hw_write_32(0x220f38L, (((uint32_t) (data & 0x7ff)) << 0) | (curr & 0xfffff800));
}
static __inline uint16_t acamera_fpga_hdmi_yuv_downsampler_matrix_o1_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220f38L) & 0x7ff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: matrix_o2
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// coefft_o2 complementary format
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_O2_DEFAULT (0x21E)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_O2_DATASIZE (11)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_O2_OFFSET (0xf40)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_O2_MASK (0x7ff)

// args: data (11-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_matrix_o2_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220f40L);
    system_hw_write_32(0x220f40L, (((uint32_t) (data & 0x7ff)) << 0) | (curr & 0xfffff800));
}
static __inline uint16_t acamera_fpga_hdmi_yuv_downsampler_matrix_o2_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220f40L) & 0x7ff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: matrix_o3
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// coefft_o3 complementary format
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_O3_DEFAULT (0x400)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_O3_DATASIZE (11)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_O3_OFFSET (0xf48)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_MATRIX_O3_MASK (0x7ff)

// args: data (11-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_matrix_o3_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220f48L);
    system_hw_write_32(0x220f48L, (((uint32_t) (data & 0x7ff)) << 0) | (curr & 0xfffff800));
}
static __inline uint16_t acamera_fpga_hdmi_yuv_downsampler_matrix_o3_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220f48L) & 0x7ff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: enable_dither
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 0= disable dithering module
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_ENABLE_DITHER_DEFAULT (0)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_ENABLE_DITHER_DATASIZE (1)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_ENABLE_DITHER_OFFSET (0xf50)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_ENABLE_DITHER_MASK (0x1)

// args: data (1-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_enable_dither_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220f50L);
    system_hw_write_32(0x220f50L, (((uint32_t) (data & 0x1)) << 0) | (curr & 0xfffffffe));
}
static __inline uint8_t acamera_fpga_hdmi_yuv_downsampler_enable_dither_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220f50L) & 0x1) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: dither_amount
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 00= dither 1 bit 01=dither 2 bits, 10= dither 3 bits 11=dither 4 bits
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_DITHER_AMOUNT_DEFAULT (0)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_DITHER_AMOUNT_DATASIZE (2)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_DITHER_AMOUNT_OFFSET (0xf50)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_DITHER_AMOUNT_MASK (0x300)

// args: data (2-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_dither_amount_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220f50L);
    system_hw_write_32(0x220f50L, (((uint32_t) (data & 0x3)) << 8) | (curr & 0xfffffcff));
}
static __inline uint8_t acamera_fpga_hdmi_yuv_downsampler_dither_amount_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220f50L) & 0x300) >> 8);
}
// ------------------------------------------------------------------------------ //
// Register: shift_mode
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// 0= out is MSB aligned ; 1=out is LSB aligned
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_SHIFT_MODE_DEFAULT (0)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_SHIFT_MODE_DATASIZE (1)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_SHIFT_MODE_OFFSET (0xf50)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_SHIFT_MODE_MASK (0x10000)

// args: data (1-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_shift_mode_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220f50L);
    system_hw_write_32(0x220f50L, (((uint32_t) (data & 0x1)) << 16) | (curr & 0xfffeffff));
}
static __inline uint8_t acamera_fpga_hdmi_yuv_downsampler_shift_mode_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220f50L) & 0x10000) >> 16);
}
// ------------------------------------------------------------------------------ //
// Register: clip_max_y
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// max value(unsigned number) of data1 on y_o1/y_o2
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_CLIP_MAX_Y_DEFAULT (0x3FF)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_CLIP_MAX_Y_DATASIZE (10)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_CLIP_MAX_Y_OFFSET (0xf60)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_CLIP_MAX_Y_MASK (0x3ff)

// args: data (10-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_clip_max_y_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220f60L);
    system_hw_write_32(0x220f60L, (((uint32_t) (data & 0x3ff)) << 0) | (curr & 0xfffffc00));
}
static __inline uint16_t acamera_fpga_hdmi_yuv_downsampler_clip_max_y_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220f60L) & 0x3ff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: clip_min_y
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// min value(unsigned number) of data1 on y_o1/y_o2
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_CLIP_MIN_Y_DEFAULT (0)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_CLIP_MIN_Y_DATASIZE (10)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_CLIP_MIN_Y_OFFSET (0xf64)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_CLIP_MIN_Y_MASK (0x3ff)

// args: data (10-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_clip_min_y_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220f64L);
    system_hw_write_32(0x220f64L, (((uint32_t) (data & 0x3ff)) << 0) | (curr & 0xfffffc00));
}
static __inline uint16_t acamera_fpga_hdmi_yuv_downsampler_clip_min_y_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220f64L) & 0x3ff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: clip_max_uv
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// max value(unsigned number) of data2/3 on u_01/v_o1/u_o1/u_o2
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_CLIP_MAX_UV_DEFAULT (0x3FF)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_CLIP_MAX_UV_DATASIZE (10)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_CLIP_MAX_UV_OFFSET (0xf68)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_CLIP_MAX_UV_MASK (0x3ff)

// args: data (10-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_clip_max_uv_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220f68L);
    system_hw_write_32(0x220f68L, (((uint32_t) (data & 0x3ff)) << 0) | (curr & 0xfffffc00));
}
static __inline uint16_t acamera_fpga_hdmi_yuv_downsampler_clip_max_uv_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220f68L) & 0x3ff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: clip_min_uv
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// min value(unsigned number) of data2/3 on u_01/v_o1/u_o1/u_o2
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_CLIP_MIN_UV_DEFAULT (0)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_CLIP_MIN_UV_DATASIZE (10)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_CLIP_MIN_UV_OFFSET (0xf6c)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_CLIP_MIN_UV_MASK (0x3ff)

// args: data (10-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_clip_min_uv_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220f6cL);
    system_hw_write_32(0x220f6cL, (((uint32_t) (data & 0x3ff)) << 0) | (curr & 0xfffffc00));
}
static __inline uint16_t acamera_fpga_hdmi_yuv_downsampler_clip_min_uv_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220f6cL) & 0x3ff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: data_mask_ry
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// mask for data1 outputs on y_o1/y_o2. Internal values are bitwise AND'd with mask before output.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_DATA_MASK_RY_DEFAULT (0x3FF)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_DATA_MASK_RY_DATASIZE (10)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_DATA_MASK_RY_OFFSET (0xf70)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_DATA_MASK_RY_MASK (0x3ff)

// args: data (10-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_data_mask_ry_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220f70L);
    system_hw_write_32(0x220f70L, (((uint32_t) (data & 0x3ff)) << 0) | (curr & 0xfffffc00));
}
static __inline uint16_t acamera_fpga_hdmi_yuv_downsampler_data_mask_ry_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220f70L) & 0x3ff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: data_mask_gu
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// mask for data2 outputs on u_o1/u_o2. Internal values are bitwise AND'd with mask before output.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_DATA_MASK_GU_DEFAULT (0x3FF)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_DATA_MASK_GU_DATASIZE (10)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_DATA_MASK_GU_OFFSET (0xf74)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_DATA_MASK_GU_MASK (0x3ff)

// args: data (10-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_data_mask_gu_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220f74L);
    system_hw_write_32(0x220f74L, (((uint32_t) (data & 0x3ff)) << 0) | (curr & 0xfffffc00));
}
static __inline uint16_t acamera_fpga_hdmi_yuv_downsampler_data_mask_gu_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220f74L) & 0x3ff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: data_mask_bv
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// mask for data3 outputs on v_o1/v_o2. Internal values are bitwise AND'd with mask before output.
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_DATA_MASK_BV_DEFAULT (0x3FF)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_DATA_MASK_BV_DATASIZE (10)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_DATA_MASK_BV_OFFSET (0xf78)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_DATA_MASK_BV_MASK (0x3ff)

// args: data (10-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_data_mask_bv_write(uintptr_t base, uint16_t data) {
    uint32_t curr = system_hw_read_32(0x220f78L);
    system_hw_write_32(0x220f78L, (((uint32_t) (data & 0x3ff)) << 0) | (curr & 0xfffffc00));
}
static __inline uint16_t acamera_fpga_hdmi_yuv_downsampler_data_mask_bv_read(uintptr_t base) {
    return (uint16_t)((system_hw_read_32(0x220f78L) & 0x3ff) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: global_fsm_reset
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// active high, sync reset, not qualified by vcke, used for some functions
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_GLOBAL_FSM_RESET_DEFAULT (0)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_GLOBAL_FSM_RESET_DATASIZE (1)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_GLOBAL_FSM_RESET_OFFSET (0xf7c)
#define ACAMERA_FPGA_HDMI_YUV_DOWNSAMPLER_GLOBAL_FSM_RESET_MASK (0x1000000)

// args: data (1-bit)
static __inline void acamera_fpga_hdmi_yuv_downsampler_global_fsm_reset_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220f7cL);
    system_hw_write_32(0x220f7cL, (((uint32_t) (data & 0x1)) << 24) | (curr & 0xfeffffff));
}
static __inline uint8_t acamera_fpga_hdmi_yuv_downsampler_global_fsm_reset_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220f7cL) & 0x1000000) >> 24);
}
// ------------------------------------------------------------------------------ //
// Group: HDMI Horizontal Shift
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Register: Offset
// ------------------------------------------------------------------------------ //

// ------------------------------------------------------------------------------ //
// Pixel resolution shift offset
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_HORIZONTAL_SHIFT_OFFSET_DEFAULT (0x0)
#define ACAMERA_FPGA_HDMI_HORIZONTAL_SHIFT_OFFSET_DATASIZE (5)
#define ACAMERA_FPGA_HDMI_HORIZONTAL_SHIFT_OFFSET_OFFSET (0xf80)
#define ACAMERA_FPGA_HDMI_HORIZONTAL_SHIFT_OFFSET_MASK (0x1f)

// args: data (5-bit)
static __inline void acamera_fpga_hdmi_horizontal_shift_offset_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220f80L);
    system_hw_write_32(0x220f80L, (((uint32_t) (data & 0x1f)) << 0) | (curr & 0xffffffe0));
}
static __inline uint8_t acamera_fpga_hdmi_horizontal_shift_offset_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220f80L) & 0x1f) >> 0);
}
// ------------------------------------------------------------------------------ //
// Register: Enable
// ------------------------------------------------------------------------------ //

#define ACAMERA_FPGA_HDMI_HORIZONTAL_SHIFT_ENABLE_DEFAULT (0x0)
#define ACAMERA_FPGA_HDMI_HORIZONTAL_SHIFT_ENABLE_DATASIZE (1)
#define ACAMERA_FPGA_HDMI_HORIZONTAL_SHIFT_ENABLE_OFFSET (0xf80)
#define ACAMERA_FPGA_HDMI_HORIZONTAL_SHIFT_ENABLE_MASK (0x10000)

// args: data (1-bit)
static __inline void acamera_fpga_hdmi_horizontal_shift_enable_write(uintptr_t base, uint8_t data) {
    uint32_t curr = system_hw_read_32(0x220f80L);
    system_hw_write_32(0x220f80L, (((uint32_t) (data & 0x1)) << 16) | (curr & 0xfffeffff));
}
static __inline uint8_t acamera_fpga_hdmi_horizontal_shift_enable_read(uintptr_t base) {
    return (uint8_t)((system_hw_read_32(0x220f80L) & 0x10000) >> 16);
}
// ------------------------------------------------------------------------------ //
#endif //__ACAMERA_FPGA_CONFIG_H__
