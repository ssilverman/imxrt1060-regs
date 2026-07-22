// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// CSI.h defines all the CSI registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// CSI layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_CSI.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct CSI_Layout {
  volatile uint32_t CR1;                               /**< CSI Control Register 1, offset: 0x0 */
  volatile uint32_t CR2;                               /**< CSI Control Register 2, offset: 0x4 */
  volatile uint32_t CR3;                               /**< CSI Control Register 3, offset: 0x8 */
  const volatile uint32_t STATFIFO;                    /**< CSI Statistic FIFO Register, offset: 0xC */
  const volatile uint32_t RFIFO;                       /**< CSI RX FIFO Register, offset: 0x10 */
  volatile uint32_t RXCNT;                             /**< CSI RX Count Register, offset: 0x14 */
  volatile uint32_t SR;                                /**< CSI Status Register, offset: 0x18 */
  uint8_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[4];
  volatile uint32_t DMASA_STATFIFO;                    /**< CSI DMA Start Address Register - for STATFIFO, offset: 0x20 */
  volatile uint32_t DMATS_STATFIFO;                    /**< CSI DMA Transfer Size Register - for STATFIFO, offset: 0x24 */
  volatile uint32_t DMASA_FB1;                         /**< CSI DMA Start Address Register - for Frame Buffer1, offset: 0x28 */
  volatile uint32_t DMASA_FB2;                         /**< CSI DMA Transfer Size Register - for Frame Buffer2, offset: 0x2C */
  volatile uint32_t FBUF_PARA;                         /**< CSI Frame Buffer Parameter Register, offset: 0x30 */
  volatile uint32_t IMAG_PARA;                         /**< CSI Image Parameter Register, offset: 0x34 */
  uint8_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[16];
  volatile uint32_t CR18;                              /**< CSI Control Register 18, offset: 0x48 */
  volatile uint32_t CR19;                              /**< CSI Control Register 19, offset: 0x4C */
};

constexpr size_t    kCSI_size = 0x50;
constexpr uintptr_t kCSI_base = 0x402BC000;

namespace CSI {
constexpr regs::RegGroup<CSI_Layout, kCSI_size, kCSI_base> group;
}  // namespace CSI

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using CSI_Reg =
    regs::Reg32<kCSI_base, CSI_Layout, Member, 0, Bits, Shift, DirectAssign>;

namespace CSI {

// Control Register 1
namespace CR1 {
constexpr CSI_Reg<&CSI_Layout::CR1, 1, 31> SWAP16_EN;
    // 0b0..Disable swapping
    // 0b1..Enable swapping
constexpr CSI_Reg<&CSI_Layout::CR1, 1, 30> EXT_VSYNC;
    // 0b0..Internal VSYNC mode
    // 0b1..External VSYNC mode
constexpr CSI_Reg<&CSI_Layout::CR1, 1, 29> EOF_INT_EN;
    // 0b0..EOF interrupt is disabled.
    // 0b1..EOF interrupt is generated when RX count value is reached.
constexpr CSI_Reg<&CSI_Layout::CR1, 1, 28> PrP_IF_EN;
    // 0b0..CSI to PrP bus is disabled
    // 0b1..CSI to PrP bus is enabled
constexpr CSI_Reg<&CSI_Layout::CR1, 1, 27> CCIR_MODE;
    // 0b0..Progressive mode is selected
    // 0b1..Interlace mode is selected
constexpr CSI_Reg<&CSI_Layout::CR1, 1, 26> COF_INT_EN;
    // 0b0..COF interrupt is disabled
    // 0b1..COF interrupt is enabled
constexpr CSI_Reg<&CSI_Layout::CR1, 1, 25> SF_OR_INTEN;
    // 0b0..STATFIFO overrun interrupt is disabled
    // 0b1..STATFIFO overrun interrupt is enabled
constexpr CSI_Reg<&CSI_Layout::CR1, 1, 24> RF_OR_INTEN;
    // 0b0..RxFIFO overrun interrupt is disabled
    // 0b1..RxFIFO overrun interrupt is enabled
constexpr CSI_Reg<&CSI_Layout::CR1, 1, 22> SFF_DMA_DONE_INTEN;
    // 0b0..STATFIFO DMA Transfer Done interrupt disable
    // 0b1..STATFIFO DMA Transfer Done interrupt enable
constexpr CSI_Reg<&CSI_Layout::CR1, 1, 21> STATFF_INTEN;
    // 0b0..STATFIFO full interrupt disable
    // 0b1..STATFIFO full interrupt enable
constexpr CSI_Reg<&CSI_Layout::CR1, 1, 20> FB2_DMA_DONE_INTEN;
    // 0b0..Frame Buffer2 DMA Transfer Done interrupt disable
    // 0b1..Frame Buffer2 DMA Transfer Done interrupt enable
constexpr CSI_Reg<&CSI_Layout::CR1, 1, 19> FB1_DMA_DONE_INTEN;
    // 0b0..Frame Buffer1 DMA Transfer Done interrupt disable
    // 0b1..Frame Buffer1 DMA Transfer Done interrupt enable
constexpr CSI_Reg<&CSI_Layout::CR1, 1, 18> RXFF_INTEN;
    // 0b0..RxFIFO full interrupt disable
    // 0b1..RxFIFO full interrupt enable
constexpr CSI_Reg<&CSI_Layout::CR1, 1, 17> SOF_POL;
    // 0b0..SOF interrupt is generated on SOF falling edge
    // 0b1..SOF interrupt is generated on SOF rising edge
constexpr CSI_Reg<&CSI_Layout::CR1, 1, 16> SOF_INTEN;
    // 0b0..SOF interrupt disable
    // 0b1..SOF interrupt enable
constexpr CSI_Reg<&CSI_Layout::CR1, 1, 11> HSYNC_POL;
    // 0b0..HSYNC is active low
    // 0b1..HSYNC is active high
constexpr CSI_Reg<&CSI_Layout::CR1, 1, 10> CCIR_EN;
    // 0b0..Traditional interface is selected.
    // 0b1..BT.656 interface is selected.
constexpr CSI_Reg<&CSI_Layout::CR1, 1,  8> FCC;
    // 0b0..Asynchronous FIFO clear is selected.
    // 0b1..Synchronous FIFO clear is selected.
constexpr CSI_Reg<&CSI_Layout::CR1, 1,  7> PACK_DIR;
    // 0b0..Pack from LSB first. For image data, 0x11, 0x22, 0x33, 0x44, it will appear as 0x44332211 in RX FIFO. For
    //      stat data, 0xAAAA, 0xBBBB, it will appear as 0xBBBBAAAA in STAT FIFO.
    // 0b1..Pack from MSB first. For image data, 0x11, 0x22, 0x33, 0x44, it will appear as 0x11223344 in RX FIFO. For
    //      stat data, 0xAAAA, 0xBBBB, it will appear as 0xAAAABBBB in STAT FIFO.
constexpr CSI_Reg<&CSI_Layout::CR1, 1,  6> CLR_STATFIFO;
constexpr CSI_Reg<&CSI_Layout::CR1, 1,  5> CLR_RXFIFO;
constexpr CSI_Reg<&CSI_Layout::CR1, 1,  4> GCLK_MODE;
    // 0b0..Non-gated clock mode. All incoming pixel clocks are valid. HSYNC is ignored.
    // 0b1..Gated clock mode. Pixel clock signal is valid only when HSYNC is active.
constexpr CSI_Reg<&CSI_Layout::CR1, 1,  3> INV_DATA;
    // 0b0..CSI_D[7:0] data lines are directly applied to internal circuitry
    // 0b1..CSI_D[7:0] data lines are inverted before applied to internal circuitry
constexpr CSI_Reg<&CSI_Layout::CR1, 1,  2> INV_PCLK;
    // 0b0..CSI_PIXCLK is directly applied to internal circuitry
    // 0b1..CSI_PIXCLK is inverted before applied to internal circuitry
constexpr CSI_Reg<&CSI_Layout::CR1, 1,  1> REDGE;
    // 0b0..Pixel data is latched at the falling edge of CSI_PIXCLK
    // 0b1..Pixel data is latched at the rising edge of CSI_PIXCLK
constexpr CSI_Reg<&CSI_Layout::CR1, 1,  0> PIXEL_BIT;
    // 0b0..8-bit data for each pixel
    // 0b1..10-bit data for each pixel
}  // namespace CR1

// Control Register 2
namespace CR2 {
constexpr CSI_Reg<&CSI_Layout::CR2, 2, 30> DMA_BURST_TYPE_RFF;
    // 0b01..INCR4
    // 0b11..INCR16
    // 0bx0..INCR8
constexpr CSI_Reg<&CSI_Layout::CR2, 2, 28> DMA_BURST_TYPE_SFF;
    // 0b01..INCR4
    // 0b11..INCR16
    // 0bx0..INCR8
constexpr CSI_Reg<&CSI_Layout::CR2, 1, 26> DRM;
    // 0b0..Stats grid of 8 x 6
    // 0b1..Stats grid of 8 x 12
constexpr CSI_Reg<&CSI_Layout::CR2, 2, 24> AFS;
    // 0b00..Abs Diff on consecutive green pixels
    // 0b01..Abs Diff on every third green pixels
    // 0b1x..Abs Diff on every four green pixels
constexpr CSI_Reg<&CSI_Layout::CR2, 1, 23> SCE;
    // 0b0..Skip count disable
    // 0b1..Skip count enable
constexpr CSI_Reg<&CSI_Layout::CR2, 2, 19> BTS;
    // 0b00..GR
    // 0b01..RG
    // 0b10..BG
    // 0b11..GB
constexpr CSI_Reg<&CSI_Layout::CR2, 3, 16> LVRM;
    // 0b000..512 x 384
    // 0b001..448 x 336
    // 0b010..384 x 288
    // 0b011..384 x 256
    // 0b100..320 x 240
    // 0b101..288 x 216
    // 0b110..400 x 300
constexpr CSI_Reg<&CSI_Layout::CR2, 8,  8> VSC;
    // 0b00000000-0b11111111..Number of rows to skip minus 1
constexpr CSI_Reg<&CSI_Layout::CR2, 8,  0> HSC;
    // 0b00000000-0b11111111..Number of pixels to skip minus 1
}  // namespace CR2

// Control Register 3
namespace CR3 {
constexpr CSI_Reg<&CSI_Layout::CR3, 16, 16> FRMCNT;
constexpr CSI_Reg<&CSI_Layout::CR3,  1, 15> FRMCNT_RST;
    // 0b0..Do not reset
    // 0b1..Reset frame counter immediately
constexpr CSI_Reg<&CSI_Layout::CR3,  1, 14> DMA_REFLASH_RFF;
    // 0b0..No reflashing
    // 0b1..Reflash the embedded DMA controller
constexpr CSI_Reg<&CSI_Layout::CR3,  1, 13> DMA_REFLASH_SFF;
    // 0b0..No reflashing
    // 0b1..Reflash the embedded DMA controller
constexpr CSI_Reg<&CSI_Layout::CR3,  1, 12> DMA_REQ_EN_RFF;
    // 0b0..Disable the dma request
    // 0b1..Enable the dma request
constexpr CSI_Reg<&CSI_Layout::CR3,  1, 11> DMA_REQ_EN_SFF;
    // 0b0..Disable the dma request
    // 0b1..Enable the dma request
constexpr CSI_Reg<&CSI_Layout::CR3,  3,  8> STATFF_LEVEL;
    // 0b000..4 Double words
    // 0b001..8 Double words
    // 0b010..12 Double words
    // 0b011..16 Double words
    // 0b100..24 Double words
    // 0b101..32 Double words
    // 0b110..48 Double words
    // 0b111..64 Double words
constexpr CSI_Reg<&CSI_Layout::CR3,  1,  7> HRESP_ERR_EN;
    // 0b0..Disable hresponse error interrupt
    // 0b1..Enable hresponse error interrupt
constexpr CSI_Reg<&CSI_Layout::CR3,  3,  4> RxFF_LEVEL;
    // 0b000..4 Double words
    // 0b001..8 Double words
    // 0b010..16 Double words
    // 0b011..24 Double words
    // 0b100..32 Double words
    // 0b101..48 Double words
    // 0b110..64 Double words
    // 0b111..96 Double words
constexpr CSI_Reg<&CSI_Layout::CR3,  1,  3> SENSOR_16BITS;
    // 0b0..Only one 8-bit sensor is connected.
    // 0b1..One 16-bit sensor is connected.
constexpr CSI_Reg<&CSI_Layout::CR3,  1,  2> ZERO_PACK_EN;
    // 0b0..Zero packing disabled
    // 0b1..Zero packing enabled
constexpr CSI_Reg<&CSI_Layout::CR3,  1,  1> ECC_INT_EN;
    // 0b0..No interrupt is generated when error is detected. Only the status bit ECC_INT is set.
    // 0b1..Interrupt is generated when error is detected.
constexpr CSI_Reg<&CSI_Layout::CR3,  1,  0> ECC_AUTO_EN;
    // 0b0..Auto Error correction is disabled.
    // 0b1..Auto Error correction is enabled.
}  // namespace CR3

// RX Count Register
namespace RXCNT {
constexpr CSI_Reg<&CSI_Layout::RXCNT, 22,  0> RXCNT;
}  // namespace RXCNT

// Status Register
namespace SR {
constexpr CSI_Reg<&CSI_Layout::SR, 1, 28> BASEADDR_CHHANGE_ERROR;
constexpr CSI_Reg<&CSI_Layout::SR, 1, 27> DMA_FIELD0_DONE;
constexpr CSI_Reg<&CSI_Layout::SR, 1, 26> DMA_FIELD1_DONE;
constexpr CSI_Reg<&CSI_Layout::SR, 1, 25> SF_OR_INT;
    // 0b0..STATFIFO has not overflowed.
    // 0b1..STATFIFO has overflowed.
constexpr CSI_Reg<&CSI_Layout::SR, 1, 24> RF_OR_INT;
    // 0b0..RXFIFO has not overflowed.
    // 0b1..RXFIFO has overflowed.
constexpr CSI_Reg<&CSI_Layout::SR, 1, 22> DMA_TSF_DONE_SFF;
    // 0b0..DMA transfer is not completed.
    // 0b1..DMA transfer is completed.
constexpr CSI_Reg<&CSI_Layout::SR, 1, 21> STATFF_INT;
    // 0b0..STATFIFO is not full.
    // 0b1..STATFIFO is full.
constexpr CSI_Reg<&CSI_Layout::SR, 1, 20> DMA_TSF_DONE_FB2;
    // 0b0..DMA transfer is not completed.
    // 0b1..DMA transfer is completed.
constexpr CSI_Reg<&CSI_Layout::SR, 1, 19> DMA_TSF_DONE_FB1;
    // 0b0..DMA transfer is not completed.
    // 0b1..DMA transfer is completed.
constexpr CSI_Reg<&CSI_Layout::SR, 1, 18> RxFF_INT;
    // 0b0..RxFIFO is not full.
    // 0b1..RxFIFO is full.
constexpr CSI_Reg<&CSI_Layout::SR, 1, 17> EOF_INT;
    // 0b0..EOF is not detected.
    // 0b1..EOF is detected.
constexpr CSI_Reg<&CSI_Layout::SR, 1, 16> SOF_INT;
    // 0b0..SOF is not detected.
    // 0b1..SOF is detected.
constexpr CSI_Reg<&CSI_Layout::SR, 1, 15> F2_INT;
    // 0b0..Field 2 of video is not detected
    // 0b1..Field 2 of video is about to start
constexpr CSI_Reg<&CSI_Layout::SR, 1, 14> F1_INT;
    // 0b0..Field 1 of video is not detected.
    // 0b1..Field 1 of video is about to start.
constexpr CSI_Reg<&CSI_Layout::SR, 1, 13> COF_INT;
    // 0b0..Video field has no change.
    // 0b1..Change of video field is detected.
constexpr CSI_Reg<&CSI_Layout::SR, 1,  7> HRESP_ERR_INT;
    // 0b0..No hresponse error.
    // 0b1..Hresponse error is detected.
constexpr CSI_Reg<&CSI_Layout::SR, 1,  1> ECC_INT;
    // 0b0..No error detected
    // 0b1..Error is detected in BT.656 coding
constexpr CSI_Reg<&CSI_Layout::SR, 1,  0> DRDY;
    // 0b0..No data (word) is ready
    // 0b1..At least 1 datum (word) is ready in RXFIFO.
}  // namespace SR

// DMA Start Address Register - for STATFIFO
namespace DMASA_STATFIFO {
constexpr CSI_Reg<&CSI_Layout::DMASA_STATFIFO, 30, 2> DMA_START_ADDR_SFF;
}  // namespace DMASA_STATFIFO

// DMA Start Address Register - for Frame Buffer1
namespace DMASA_FB1 {
constexpr CSI_Reg<&CSI_Layout::DMASA_FB1, 30, 2> DMA_START_ADDR_FB1;
}  // namespace DMASA_FB1

// DMA Transfer Size Register - for Frame Buffer2
namespace DMASA_FB2 {
constexpr CSI_Reg<&CSI_Layout::DMASA_FB2, 30, 2> DMA_START_ADDR_FB2;
}  // namespace DMASA_FB2

// Frame Buffer Parameter Register
namespace FBUF_PARA {
constexpr CSI_Reg<&CSI_Layout::FBUF_PARA, 16, 16> DEINTERLACE_STRIDE;
constexpr CSI_Reg<&CSI_Layout::FBUF_PARA, 16,  0> FBUF_STRIDE;
}  // namespace FBUF_PARA

// Image Parameter Register
namespace IMAG_PARA {
constexpr CSI_Reg<&CSI_Layout::IMAG_PARA, 16, 16> IMAGE_WIDTH;
constexpr CSI_Reg<&CSI_Layout::IMAG_PARA, 16,  0> IMAGE_HEIGHT;
}  // namespace IMAG_PARA

// Control Register 18
namespace CR18 {
constexpr CSI_Reg<&CSI_Layout::CR18, 1, 31> CSI_ENABLE;
constexpr CSI_Reg<&CSI_Layout::CR18, 2, 18> MASK_OPTION;
    // 0b00..Writing to memory (OCRAM or external DDR) from first completely frame, when using this option, the CSI_ENABLE should be 1.
    // 0b01..Writing to memory when CSI_ENABLE is 1.
    // 0b10..Writing to memory from second completely frame, when using this option, the CSI_ENABLE should be 1.
    // 0b11..Writing to memory when data comes in, not matter the CSI_ENABLE is 1 or 0.
constexpr CSI_Reg<&CSI_Layout::CR18, 4, 12> AHB_HPROT;
constexpr CSI_Reg<&CSI_Layout::CR18, 1, 10> RGB888A_FORMAT_SEL;
    // 0b0..{8'h0, data[23:0]}
    // 0b1..{data[23:0], 8'h0}
constexpr CSI_Reg<&CSI_Layout::CR18, 1,  9> BASEADDR_CHANGE_ERROR_IE;
    // 0b0..Interrupt disabled
    // 0b1..Interrupt enabled
constexpr CSI_Reg<&CSI_Layout::CR18, 1,  8> LAST_DMA_REQ_SEL;
    // 0b0..fifo_full_level
    // 0b1..hburst_length
constexpr CSI_Reg<&CSI_Layout::CR18, 1,  7> DMA_FIELD1_DONE_IE;
    // 0b0..Interrupt disabled
    // 0b1..Interrupt enabled
constexpr CSI_Reg<&CSI_Layout::CR18, 1,  6> FIELD0_DONE_IE;
    // 0b0..Interrupt disabled
    // 0b1..Interrupt enabled
constexpr CSI_Reg<&CSI_Layout::CR18, 1,  5> BASEADDR_SWITCH_SEL;
    // 0b0..Switching base address at the edge of the vsync
    // 0b1..Switching base address at the edge of the first data of each frame
constexpr CSI_Reg<&CSI_Layout::CR18, 1,  4> BASEADDR_SWITCH_EN;
constexpr CSI_Reg<&CSI_Layout::CR18, 1,  3> PARALLEL24_EN;
    // 0b0..Input is disabled
    // 0b1..Input is enabled
constexpr CSI_Reg<&CSI_Layout::CR18, 1,  2> DEINTERLACE_EN;
    // 0b0..Deinterlace disabled
    // 0b1..Deinterlace enabled
}  // namespace CR18

// Control Register 19
namespace CR19 {
constexpr CSI_Reg<&CSI_Layout::CR19, 8, 0> DMA_RFIFO_HIGHEST_FIFO_LEVEL;
}  // namespace CR19

}  // namespace CSI

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
