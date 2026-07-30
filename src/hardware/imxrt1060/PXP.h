// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// PXP.h defines all the PXP registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>
#include <type_traits>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the Pixel Pipeline (PXP) registers.
//
// Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_PXP.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct PXP_Layout {
  volatile uint32_t CTRL;                              /**< Control Register 0, offset: 0x0 */
  volatile uint32_t CTRL_SET;                          /**< Control Register 0, offset: 0x4 */
  volatile uint32_t CTRL_CLR;                          /**< Control Register 0, offset: 0x8 */
  volatile uint32_t CTRL_TOG;                          /**< Control Register 0, offset: 0xC */
  volatile uint32_t STAT;                              /**< Status Register, offset: 0x10 */
  volatile uint32_t STAT_SET;                          /**< Status Register, offset: 0x14 */
  volatile uint32_t STAT_CLR;                          /**< Status Register, offset: 0x18 */
  volatile uint32_t STAT_TOG;                          /**< Status Register, offset: 0x1C */
  volatile uint32_t OUT_CTRL;                          /**< Output Buffer Control Register, offset: 0x20 */
  volatile uint32_t OUT_CTRL_SET;                      /**< Output Buffer Control Register, offset: 0x24 */
  volatile uint32_t OUT_CTRL_CLR;                      /**< Output Buffer Control Register, offset: 0x28 */
  volatile uint32_t OUT_CTRL_TOG;                      /**< Output Buffer Control Register, offset: 0x2C */
  volatile uint32_t OUT_BUF;                           /**< Output Frame Buffer Pointer, offset: 0x30 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t OUT_BUF2;                          /**< Output Frame Buffer Pointer #2, offset: 0x40 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t OUT_PITCH;                         /**< Output Buffer Pitch, offset: 0x50 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t OUT_LRC;                           /**< Output Surface Lower Right Coordinate, offset: 0x60 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t OUT_PS_ULC;                        /**< Processed Surface Upper Left Coordinate, offset: 0x70 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t OUT_PS_LRC;                        /**< Processed Surface Lower Right Coordinate, offset: 0x80 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t OUT_AS_ULC;                        /**< Alpha Surface Upper Left Coordinate, offset: 0x90 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t OUT_AS_LRC;                        /**< Alpha Surface Lower Right Coordinate, offset: 0xA0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PS_CTRL;                           /**< Processed Surface (PS) Control Register, offset: 0xB0 */
  volatile uint32_t PS_CTRL_SET;                       /**< Processed Surface (PS) Control Register, offset: 0xB4 */
  volatile uint32_t PS_CTRL_CLR;                       /**< Processed Surface (PS) Control Register, offset: 0xB8 */
  volatile uint32_t PS_CTRL_TOG;                       /**< Processed Surface (PS) Control Register, offset: 0xBC */
  volatile uint32_t PS_BUF;                            /**< PS Input Buffer Address, offset: 0xC0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PS_UBUF;                           /**< PS U/Cb or 2 Plane UV Input Buffer Address, offset: 0xD0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PS_VBUF;                           /**< PS V/Cr Input Buffer Address, offset: 0xE0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PS_PITCH;                          /**< Processed Surface Pitch, offset: 0xF0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PS_BACKGROUND;                     /**< PS Background Color, offset: 0x100 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PS_SCALE;                          /**< PS Scale Factor Register, offset: 0x110 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PS_OFFSET;                         /**< PS Scale Offset Register, offset: 0x120 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PS_CLRKEYLOW;                      /**< PS Color Key Low, offset: 0x130 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PS_CLRKEYHIGH;                     /**< PS Color Key High, offset: 0x140 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t AS_CTRL;                           /**< Alpha Surface Control, offset: 0x150 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t AS_BUF;                            /**< Alpha Surface Buffer Pointer, offset: 0x160 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t AS_PITCH;                          /**< Alpha Surface Pitch, offset: 0x170 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t AS_CLRKEYLOW;                      /**< Overlay Color Key Low, offset: 0x180 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t AS_CLRKEYHIGH;                     /**< Overlay Color Key High, offset: 0x190 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CSC1_COEF0;                        /**< Color Space Conversion Coefficient Register 0, offset: 0x1A0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CSC1_COEF1;                        /**< Color Space Conversion Coefficient Register 1, offset: 0x1B0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CSC1_COEF2;                        /**< Color Space Conversion Coefficient Register 2, offset: 0x1C0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[87];
  volatile uint32_t POWER;                             /**< PXP Power Control Register, offset: 0x320 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[55];
  volatile uint32_t NEXT;                              /**< Next Frame Pointer, offset: 0x400 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[15];
  volatile uint32_t PORTER_DUFF_CTRL;                  /**< PXP Alpha Engine A Control Register., offset: 0x440 */
};

constexpr size_t    kPXP_size = 0x444;
constexpr uintptr_t kPXP_base = 0x402B4000;

namespace PXP {
constexpr regs::RegGroup<PXP_Layout, kPXP_size, kPXP_base> group;
}  // namespace PXP

namespace PXP {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false>
using PXP_Reg = regs::Reg32<kPXP_base, PXP_Layout, Member, 0, Bits, Shift,
                            AssignMask, WriteOnly>;

// Control Register 0
namespace CTRL {
constexpr PXP_Reg<&PXP_Layout::CTRL, 1, 31> SFTRST;                // This bit can be turned on and then off to reset the PXP block to its default state.
    // 0b0..Normal PXP operation is enabled
    // 0b1..Clocking with PXP is disabled and held in its reset (lowest power) state. This is the default value.
constexpr PXP_Reg<&PXP_Layout::CTRL, 1, 30> CLKGATE;               // This bit must be set to zero for normal operation
    // 0b0..Normal operation
    // 0b1..All clocks to PXP is gated-off
constexpr PXP_Reg<&PXP_Layout::CTRL, 1, 28> EN_REPEAT;             // Enable the PXP to run continuously
    // 0b0..PXP will complete the process and enter the idle state ready to accept the next frame to be processed
    // 0b1..PXP will repeat based on the current configuration register settings
constexpr PXP_Reg<&PXP_Layout::CTRL, 1, 23> BLOCK_SIZE;            // Select the block size to process.
    // 0b0..Process 8x8 pixel blocks.
    // 0b1..Process 16x16 pixel blocks.
constexpr PXP_Reg<&PXP_Layout::CTRL, 1, 22> ROT_POS;               // This bit controls where rotation will occur in the PXP datapath
constexpr PXP_Reg<&PXP_Layout::CTRL, 1, 11> VFLIP;                 // Indicates that the output buffer should be flipped vertically (effect applied before rotation).
    // 0b0..Vertical Flip is disabled
    // 0b1..Vertical Flip is enabled
constexpr PXP_Reg<&PXP_Layout::CTRL, 1, 10> HFLIP;                 // Indicates that the output buffer should be flipped horizontally (effect applied before rotation).
    // 0b0..Horizontal Flip is disabled
    // 0b1..Horizontal Flip is enabled
constexpr PXP_Reg<&PXP_Layout::CTRL, 2,  8> ROTATE;                // Indicates the clockwise rotation to be applied at the output buffer
    // 0b00..ROT_0
    // 0b01..ROT_90
    // 0b10..ROT_180
    // 0b11..ROT_270
constexpr PXP_Reg<&PXP_Layout::CTRL, 1,  4> ENABLE_LCD_HANDSHAKE;  // Enable handshake with LCD controller
constexpr PXP_Reg<&PXP_Layout::CTRL, 1,  2> NEXT_IRQ_ENABLE;       // Next command interrupt enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr PXP_Reg<&PXP_Layout::CTRL, 1,  1> IRQ_ENABLE;            // Interrupt enable
    // When using the PXP_NEXT functionality to reprogram the PXP, the new value of this bit will be used and may therefore enable or disable an interrupt unintentionally
    // 0b0..PXP interrupt is disabled
    // 0b1..PXP interrupt is enabled
constexpr PXP_Reg<&PXP_Layout::CTRL, 1,  0> ENABLE;                // Enables PXP operation with specified parameters
    // 0b0..PXP is disabled
    // 0b1..PXP is enabled
}  // namespace CTRL

// Control Register 0
namespace CTRL_SET {
constexpr PXP_Reg<&PXP_Layout::CTRL_SET, 1, 31, 0x0> SFTRST;                // This bit can be turned on and then off to reset the PXP block to its default state.
    // 0b0..Normal PXP operation is enabled
    // 0b1..Clocking with PXP is disabled and held in its reset (lowest power) state. This is the default value.
constexpr PXP_Reg<&PXP_Layout::CTRL_SET, 1, 30, 0x0> CLKGATE;               // This bit must be set to zero for normal operation
    // 0b0..Normal operation
    // 0b1..All clocks to PXP is gated-off
constexpr PXP_Reg<&PXP_Layout::CTRL_SET, 1, 28, 0x0> EN_REPEAT;             // Enable the PXP to run continuously
    // 0b0..PXP will complete the process and enter the idle state ready to accept the next frame to be processed
    // 0b1..PXP will repeat based on the current configuration register settings
constexpr PXP_Reg<&PXP_Layout::CTRL_SET, 1, 23, 0x0> BLOCK_SIZE;            // Select the block size to process.
    // 0b0..Process 8x8 pixel blocks.
    // 0b1..Process 16x16 pixel blocks.
constexpr PXP_Reg<&PXP_Layout::CTRL_SET, 1, 22, 0x0> ROT_POS;               // This bit controls where rotation will occur in the PXP datapath
constexpr PXP_Reg<&PXP_Layout::CTRL_SET, 1, 11, 0x0> VFLIP;                 // Indicates that the output buffer should be flipped vertically (effect applied before rotation).
    // 0b0..Vertical Flip is disabled
    // 0b1..Vertical Flip is enabled
constexpr PXP_Reg<&PXP_Layout::CTRL_SET, 1, 10, 0x0> HFLIP;                 // Indicates that the output buffer should be flipped horizontally (effect applied before rotation).
    // 0b0..Horizontal Flip is disabled
    // 0b1..Horizontal Flip is enabled
constexpr PXP_Reg<&PXP_Layout::CTRL_SET, 2,  8, 0x0> ROTATE;                // Indicates the clockwise rotation to be applied at the output buffer
    // 0b00..ROT_0
    // 0b01..ROT_90
    // 0b10..ROT_180
    // 0b11..ROT_270
constexpr PXP_Reg<&PXP_Layout::CTRL_SET, 1,  4, 0x0> ENABLE_LCD_HANDSHAKE;  // Enable handshake with LCD controller
constexpr PXP_Reg<&PXP_Layout::CTRL_SET, 1,  2, 0x0> NEXT_IRQ_ENABLE;       // Next command interrupt enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr PXP_Reg<&PXP_Layout::CTRL_SET, 1,  1, 0x0> IRQ_ENABLE;            // Interrupt enable
    // When using the PXP_NEXT functionality to reprogram the PXP, the new value of this bit will be used and may therefore enable or disable an interrupt unintentionally
    // 0b0..PXP interrupt is disabled
    // 0b1..PXP interrupt is enabled
constexpr PXP_Reg<&PXP_Layout::CTRL_SET, 1,  0, 0x0> ENABLE;                // Enables PXP operation with specified parameters
    // 0b0..PXP is disabled
    // 0b1..PXP is enabled
}  // namespace CTRL_SET

// Control Register 0
namespace CTRL_CLR {
constexpr PXP_Reg<&PXP_Layout::CTRL_CLR, 1, 31, 0x0> SFTRST;                // This bit can be turned on and then off to reset the PXP block to its default state.
    // 0b0..Normal PXP operation is enabled
    // 0b1..Clocking with PXP is disabled and held in its reset (lowest power) state. This is the default value.
constexpr PXP_Reg<&PXP_Layout::CTRL_CLR, 1, 30, 0x0> CLKGATE;               // This bit must be set to zero for normal operation
    // 0b0..Normal operation
    // 0b1..All clocks to PXP is gated-off
constexpr PXP_Reg<&PXP_Layout::CTRL_CLR, 1, 28, 0x0> EN_REPEAT;             // Enable the PXP to run continuously
    // 0b0..PXP will complete the process and enter the idle state ready to accept the next frame to be processed
    // 0b1..PXP will repeat based on the current configuration register settings
constexpr PXP_Reg<&PXP_Layout::CTRL_CLR, 1, 23, 0x0> BLOCK_SIZE;            // Select the block size to process.
    // 0b0..Process 8x8 pixel blocks.
    // 0b1..Process 16x16 pixel blocks.
constexpr PXP_Reg<&PXP_Layout::CTRL_CLR, 1, 22, 0x0> ROT_POS;               // This bit controls where rotation will occur in the PXP datapath
constexpr PXP_Reg<&PXP_Layout::CTRL_CLR, 1, 11, 0x0> VFLIP;                 // Indicates that the output buffer should be flipped vertically (effect applied before rotation).
    // 0b0..Vertical Flip is disabled
    // 0b1..Vertical Flip is enabled
constexpr PXP_Reg<&PXP_Layout::CTRL_CLR, 1, 10, 0x0> HFLIP;                 // Indicates that the output buffer should be flipped horizontally (effect applied before rotation).
    // 0b0..Horizontal Flip is disabled
    // 0b1..Horizontal Flip is enabled
constexpr PXP_Reg<&PXP_Layout::CTRL_CLR, 2,  8, 0x0> ROTATE;                // Indicates the clockwise rotation to be applied at the output buffer
    // 0b00..ROT_0
    // 0b01..ROT_90
    // 0b10..ROT_180
    // 0b11..ROT_270
constexpr PXP_Reg<&PXP_Layout::CTRL_CLR, 1,  4, 0x0> ENABLE_LCD_HANDSHAKE;  // Enable handshake with LCD controller
constexpr PXP_Reg<&PXP_Layout::CTRL_CLR, 1,  2, 0x0> NEXT_IRQ_ENABLE;       // Next command interrupt enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr PXP_Reg<&PXP_Layout::CTRL_CLR, 1,  1, 0x0> IRQ_ENABLE;            // Interrupt enable
    // When using the PXP_NEXT functionality to reprogram the PXP, the new value of this bit will be used and may therefore enable or disable an interrupt unintentionally
    // 0b0..PXP interrupt is disabled
    // 0b1..PXP interrupt is enabled
constexpr PXP_Reg<&PXP_Layout::CTRL_CLR, 1,  0, 0x0> ENABLE;                // Enables PXP operation with specified parameters
    // 0b0..PXP is disabled
    // 0b1..PXP is enabled
}  // namespace CTRL_CLR

// Control Register 0
namespace CTRL_TOG {
constexpr PXP_Reg<&PXP_Layout::CTRL_TOG, 1, 31, 0x0> SFTRST;                // This bit can be turned on and then off to reset the PXP block to its default state.
    // 0b0..Normal PXP operation is enabled
    // 0b1..Clocking with PXP is disabled and held in its reset (lowest power) state. This is the default value.
constexpr PXP_Reg<&PXP_Layout::CTRL_TOG, 1, 30, 0x0> CLKGATE;               // This bit must be set to zero for normal operation
    // 0b0..Normal operation
    // 0b1..All clocks to PXP is gated-off
constexpr PXP_Reg<&PXP_Layout::CTRL_TOG, 1, 28, 0x0> EN_REPEAT;             // Enable the PXP to run continuously
    // 0b0..PXP will complete the process and enter the idle state ready to accept the next frame to be processed
    // 0b1..PXP will repeat based on the current configuration register settings
constexpr PXP_Reg<&PXP_Layout::CTRL_TOG, 1, 23, 0x0> BLOCK_SIZE;            // Select the block size to process.
    // 0b0..Process 8x8 pixel blocks.
    // 0b1..Process 16x16 pixel blocks.
constexpr PXP_Reg<&PXP_Layout::CTRL_TOG, 1, 22, 0x0> ROT_POS;               // This bit controls where rotation will occur in the PXP datapath
constexpr PXP_Reg<&PXP_Layout::CTRL_TOG, 1, 11, 0x0> VFLIP;                 // Indicates that the output buffer should be flipped vertically (effect applied before rotation).
    // 0b0..Vertical Flip is disabled
    // 0b1..Vertical Flip is enabled
constexpr PXP_Reg<&PXP_Layout::CTRL_TOG, 1, 10, 0x0> HFLIP;                 // Indicates that the output buffer should be flipped horizontally (effect applied before rotation).
    // 0b0..Horizontal Flip is disabled
    // 0b1..Horizontal Flip is enabled
constexpr PXP_Reg<&PXP_Layout::CTRL_TOG, 2,  8, 0x0> ROTATE;                // Indicates the clockwise rotation to be applied at the output buffer
    // 0b00..ROT_0
    // 0b01..ROT_90
    // 0b10..ROT_180
    // 0b11..ROT_270
constexpr PXP_Reg<&PXP_Layout::CTRL_TOG, 1,  4, 0x0> ENABLE_LCD_HANDSHAKE;  // Enable handshake with LCD controller
constexpr PXP_Reg<&PXP_Layout::CTRL_TOG, 1,  2, 0x0> NEXT_IRQ_ENABLE;       // Next command interrupt enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr PXP_Reg<&PXP_Layout::CTRL_TOG, 1,  1, 0x0> IRQ_ENABLE;            // Interrupt enable
    // When using the PXP_NEXT functionality to reprogram the PXP, the new value of this bit will be used and may therefore enable or disable an interrupt unintentionally
    // 0b0..PXP interrupt is disabled
    // 0b1..PXP interrupt is enabled
constexpr PXP_Reg<&PXP_Layout::CTRL_TOG, 1,  0, 0x0> ENABLE;                // Enables PXP operation with specified parameters
    // 0b0..PXP is disabled
    // 0b1..PXP is enabled
}  // namespace CTRL_TOG

// Status Register
namespace STAT {
constexpr PXP_Reg<regs::constify(&PXP_Layout::STAT), 8, 24> BLOCKX;        // Indicates the X coordinate of the block currently being rendered.
constexpr PXP_Reg<regs::constify(&PXP_Layout::STAT), 8, 16> BLOCKY;        // Indicates the Y coordinate of the block currently being rendered.
constexpr PXP_Reg<&PXP_Layout::STAT, 1,  8> LUT_DMA_LOAD_DONE_IRQ;         // Indicates that the LUT DMA transfer has completed.
    // 0b0..LUT DMA LOAD transfer is active
    // 0b1..LUT DMA LOAD transfer is complete
constexpr PXP_Reg<regs::constify(&PXP_Layout::STAT), 4,  4> AXI_ERROR_ID;  // Indicates the AXI ID of the failing bus operation.
constexpr PXP_Reg<&PXP_Layout::STAT, 1,  3> NEXT_IRQ;                      // Indicates that a command issued with the "Next Command" functionality has been issued and that a new command may be initiated with a write to the PXP_NEXT register
constexpr PXP_Reg<&PXP_Layout::STAT, 1,  2> AXI_READ_ERROR;                // Indicates PXP encountered an AXI read error and processing has been terminated.
    // 0b0..AXI read is normal
    // 0b1..AXI read error has occurred
constexpr PXP_Reg<&PXP_Layout::STAT, 1,  1> AXI_WRITE_ERROR;               // Indicates PXP encountered an AXI write error and processing has been terminated.
    // 0b0..AXI write is normal
    // 0b1..AXI write error has occurred
constexpr PXP_Reg<&PXP_Layout::STAT, 1,  0> IRQ;                           // Indicates current PXP interrupt status
    // 0b0..No interrupt
    // 0b1..Interrupt generated
}  // namespace STAT

// Status Register
namespace STAT_SET {
constexpr PXP_Reg<regs::constify(&PXP_Layout::STAT_SET), 8, 24, 0x0> BLOCKX;        // Indicates the X coordinate of the block currently being rendered.
constexpr PXP_Reg<regs::constify(&PXP_Layout::STAT_SET), 8, 16, 0x0> BLOCKY;        // Indicates the Y coordinate of the block currently being rendered.
constexpr PXP_Reg<&PXP_Layout::STAT_SET, 1,  8, 0x0> LUT_DMA_LOAD_DONE_IRQ;         // Indicates that the LUT DMA transfer has completed.
    // 0b0..LUT DMA LOAD transfer is active
    // 0b1..LUT DMA LOAD transfer is complete
constexpr PXP_Reg<regs::constify(&PXP_Layout::STAT_SET), 4,  4, 0x0> AXI_ERROR_ID;  // Indicates the AXI ID of the failing bus operation.
constexpr PXP_Reg<&PXP_Layout::STAT_SET, 1,  3, 0x0> NEXT_IRQ;                      // Indicates that a command issued with the "Next Command" functionality has been issued and that a new command may be initiated with a write to the PXP_NEXT register
constexpr PXP_Reg<&PXP_Layout::STAT_SET, 1,  2, 0x0> AXI_READ_ERROR;                // Indicates PXP encountered an AXI read error and processing has been terminated.
    // 0b0..AXI read is normal
    // 0b1..AXI read error has occurred
constexpr PXP_Reg<&PXP_Layout::STAT_SET, 1,  1, 0x0> AXI_WRITE_ERROR;               // Indicates PXP encountered an AXI write error and processing has been terminated.
    // 0b0..AXI write is normal
    // 0b1..AXI write error has occurred
constexpr PXP_Reg<&PXP_Layout::STAT_SET, 1,  0, 0x0> IRQ;                           // Indicates current PXP interrupt status
    // 0b0..No interrupt
    // 0b1..Interrupt generated
}  // namespace STAT_SET

// Status Register
namespace STAT_CLR {
constexpr PXP_Reg<regs::constify(&PXP_Layout::STAT_CLR), 8, 24, 0x0> BLOCKX;        // Indicates the X coordinate of the block currently being rendered.
constexpr PXP_Reg<regs::constify(&PXP_Layout::STAT_CLR), 8, 16, 0x0> BLOCKY;        // Indicates the Y coordinate of the block currently being rendered.
constexpr PXP_Reg<&PXP_Layout::STAT_CLR, 1,  8, 0x0> LUT_DMA_LOAD_DONE_IRQ;         // Indicates that the LUT DMA transfer has completed.
    // 0b0..LUT DMA LOAD transfer is active
    // 0b1..LUT DMA LOAD transfer is complete
constexpr PXP_Reg<regs::constify(&PXP_Layout::STAT_CLR), 4,  4, 0x0> AXI_ERROR_ID;  // Indicates the AXI ID of the failing bus operation.
constexpr PXP_Reg<&PXP_Layout::STAT_CLR, 1,  3, 0x0> NEXT_IRQ;                      // Indicates that a command issued with the "Next Command" functionality has been issued and that a new command may be initiated with a write to the PXP_NEXT register
constexpr PXP_Reg<&PXP_Layout::STAT_CLR, 1,  2, 0x0> AXI_READ_ERROR;                // Indicates PXP encountered an AXI read error and processing has been terminated.
    // 0b0..AXI read is normal
    // 0b1..AXI read error has occurred
constexpr PXP_Reg<&PXP_Layout::STAT_CLR, 1,  1, 0x0> AXI_WRITE_ERROR;               // Indicates PXP encountered an AXI write error and processing has been terminated.
    // 0b0..AXI write is normal
    // 0b1..AXI write error has occurred
constexpr PXP_Reg<&PXP_Layout::STAT_CLR, 1,  0, 0x0> IRQ;                           // Indicates current PXP interrupt status
    // 0b0..No interrupt
    // 0b1..Interrupt generated
}  // namespace STAT_CLR

// Status Register
namespace STAT_TOG {
constexpr PXP_Reg<regs::constify(&PXP_Layout::STAT_TOG), 8, 24, 0x0> BLOCKX;        // Indicates the X coordinate of the block currently being rendered.
constexpr PXP_Reg<regs::constify(&PXP_Layout::STAT_TOG), 8, 16, 0x0> BLOCKY;        // Indicates the Y coordinate of the block currently being rendered.
constexpr PXP_Reg<&PXP_Layout::STAT_TOG, 1,  8, 0x0> LUT_DMA_LOAD_DONE_IRQ;         // Indicates that the LUT DMA transfer has completed.
    // 0b0..LUT DMA LOAD transfer is active
    // 0b1..LUT DMA LOAD transfer is complete
constexpr PXP_Reg<regs::constify(&PXP_Layout::STAT_TOG), 4,  4, 0x0> AXI_ERROR_ID;  // Indicates the AXI ID of the failing bus operation.
constexpr PXP_Reg<&PXP_Layout::STAT_TOG, 1,  3, 0x0> NEXT_IRQ;                      // Indicates that a command issued with the "Next Command" functionality has been issued and that a new command may be initiated with a write to the PXP_NEXT register
constexpr PXP_Reg<&PXP_Layout::STAT_TOG, 1,  2, 0x0> AXI_READ_ERROR;                // Indicates PXP encountered an AXI read error and processing has been terminated.
    // 0b0..AXI read is normal
    // 0b1..AXI read error has occurred
constexpr PXP_Reg<&PXP_Layout::STAT_TOG, 1,  1, 0x0> AXI_WRITE_ERROR;               // Indicates PXP encountered an AXI write error and processing has been terminated.
    // 0b0..AXI write is normal
    // 0b1..AXI write error has occurred
constexpr PXP_Reg<&PXP_Layout::STAT_TOG, 1,  0, 0x0> IRQ;                           // Indicates current PXP interrupt status
    // 0b0..No interrupt
    // 0b1..Interrupt generated
}  // namespace STAT_TOG

// Output Buffer Control Register
namespace OUT_CTRL {
constexpr PXP_Reg<&PXP_Layout::OUT_CTRL, 8, 24> ALPHA;              // When generating an output buffer with an alpha component, the value in this field will be used when enabled to override the alpha passed through the pixel data pipeline
constexpr PXP_Reg<&PXP_Layout::OUT_CTRL, 1, 23> ALPHA_OUTPUT;       // Indicates that alpha component in output buffer pixels should be overwritten by PXP_OUT_CTRL[ALPHA]
    // 0b0..Retain
    // 0b1..Overwritten
constexpr PXP_Reg<&PXP_Layout::OUT_CTRL, 2,  8> INTERLACED_OUTPUT;  // Determines how the PXP writes it's output data
    // 0b00..All data written in progressive format to the OUTBUF Pointer.
    // 0b01..Interlaced output: only data for field 0 is written to the OUTBUF Pointer.
    // 0b10..Interlaced output: only data for field 1 is written to the OUTBUF2 Pointer.
    // 0b11..Interlaced output: data for field 0 is written to OUTBUF and data for field 1 is written to OUTBUF2.
constexpr PXP_Reg<&PXP_Layout::OUT_CTRL, 5,  0> FORMAT;             // Output framebuffer format
    // 0b00000..32-bit pixels
    // 0b00100..32-bit pixels (unpacked 24-bit pixel in 32 bit DWORD.)
    // 0b00101..24-bit pixels (packed 24-bit format)
    // 0b01000..16-bit pixels
    // 0b01001..16-bit pixels
    // 0b01100..16-bit pixels
    // 0b01101..16-bit pixels
    // 0b01110..16-bit pixels
    // 0b10000..32-bit pixels (1-plane XYUV unpacked)
    // 0b10010..16-bit pixels (1-plane U0,Y0,V0,Y1 interleaved bytes)
    // 0b10011..16-bit pixels (1-plane V0,Y0,U0,Y1 interleaved bytes)
    // 0b10100..8-bit monochrome pixels (1-plane Y luma output)
    // 0b10101..4-bit monochrome pixels (1-plane Y luma, 4 bit truncation)
    // 0b11000..16-bit pixels (2-plane UV interleaved bytes)
    // 0b11001..16-bit pixels (2-plane UV)
    // 0b11010..16-bit pixels (2-plane VU interleaved bytes)
    // 0b11011..16-bit pixels (2-plane VU)
}  // namespace OUT_CTRL

// Output Buffer Control Register
namespace OUT_CTRL_SET {
constexpr PXP_Reg<&PXP_Layout::OUT_CTRL_SET, 8, 24, 0x0> ALPHA;              // When generating an output buffer with an alpha component, the value in this field will be used when enabled to override the alpha passed through the pixel data pipeline
constexpr PXP_Reg<&PXP_Layout::OUT_CTRL_SET, 1, 23, 0x0> ALPHA_OUTPUT;       // Indicates that alpha component in output buffer pixels should be overwritten by PXP_OUT_CTRL[ALPHA]
    // 0b0..Retain
    // 0b1..Overwritten
constexpr PXP_Reg<&PXP_Layout::OUT_CTRL_SET, 2,  8, 0x0> INTERLACED_OUTPUT;  // Determines how the PXP writes it's output data
    // 0b00..All data written in progressive format to the OUTBUF Pointer.
    // 0b01..Interlaced output: only data for field 0 is written to the OUTBUF Pointer.
    // 0b10..Interlaced output: only data for field 1 is written to the OUTBUF2 Pointer.
    // 0b11..Interlaced output: data for field 0 is written to OUTBUF and data for field 1 is written to OUTBUF2.
constexpr PXP_Reg<&PXP_Layout::OUT_CTRL_SET, 5,  0, 0x0> FORMAT;             // Output framebuffer format
    // 0b00000..32-bit pixels
    // 0b00100..32-bit pixels (unpacked 24-bit pixel in 32 bit DWORD.)
    // 0b00101..24-bit pixels (packed 24-bit format)
    // 0b01000..16-bit pixels
    // 0b01001..16-bit pixels
    // 0b01100..16-bit pixels
    // 0b01101..16-bit pixels
    // 0b01110..16-bit pixels
    // 0b10000..32-bit pixels (1-plane XYUV unpacked)
    // 0b10010..16-bit pixels (1-plane U0,Y0,V0,Y1 interleaved bytes)
    // 0b10011..16-bit pixels (1-plane V0,Y0,U0,Y1 interleaved bytes)
    // 0b10100..8-bit monochrome pixels (1-plane Y luma output)
    // 0b10101..4-bit monochrome pixels (1-plane Y luma, 4 bit truncation)
    // 0b11000..16-bit pixels (2-plane UV interleaved bytes)
    // 0b11001..16-bit pixels (2-plane UV)
    // 0b11010..16-bit pixels (2-plane VU interleaved bytes)
    // 0b11011..16-bit pixels (2-plane VU)
}  // namespace OUT_CTRL_SET

// Output Buffer Control Register
namespace OUT_CTRL_CLR {
constexpr PXP_Reg<&PXP_Layout::OUT_CTRL_CLR, 8, 24, 0x0> ALPHA;              // When generating an output buffer with an alpha component, the value in this field will be used when enabled to override the alpha passed through the pixel data pipeline
constexpr PXP_Reg<&PXP_Layout::OUT_CTRL_CLR, 1, 23, 0x0> ALPHA_OUTPUT;       // Indicates that alpha component in output buffer pixels should be overwritten by PXP_OUT_CTRL[ALPHA]
    // 0b0..Retain
    // 0b1..Overwritten
constexpr PXP_Reg<&PXP_Layout::OUT_CTRL_CLR, 2,  8, 0x0> INTERLACED_OUTPUT;  // Determines how the PXP writes it's output data
    // 0b00..All data written in progressive format to the OUTBUF Pointer.
    // 0b01..Interlaced output: only data for field 0 is written to the OUTBUF Pointer.
    // 0b10..Interlaced output: only data for field 1 is written to the OUTBUF2 Pointer.
    // 0b11..Interlaced output: data for field 0 is written to OUTBUF and data for field 1 is written to OUTBUF2.
constexpr PXP_Reg<&PXP_Layout::OUT_CTRL_CLR, 5,  0, 0x0> FORMAT;             // Output framebuffer format
    // 0b00000..32-bit pixels
    // 0b00100..32-bit pixels (unpacked 24-bit pixel in 32 bit DWORD.)
    // 0b00101..24-bit pixels (packed 24-bit format)
    // 0b01000..16-bit pixels
    // 0b01001..16-bit pixels
    // 0b01100..16-bit pixels
    // 0b01101..16-bit pixels
    // 0b01110..16-bit pixels
    // 0b10000..32-bit pixels (1-plane XYUV unpacked)
    // 0b10010..16-bit pixels (1-plane U0,Y0,V0,Y1 interleaved bytes)
    // 0b10011..16-bit pixels (1-plane V0,Y0,U0,Y1 interleaved bytes)
    // 0b10100..8-bit monochrome pixels (1-plane Y luma output)
    // 0b10101..4-bit monochrome pixels (1-plane Y luma, 4 bit truncation)
    // 0b11000..16-bit pixels (2-plane UV interleaved bytes)
    // 0b11001..16-bit pixels (2-plane UV)
    // 0b11010..16-bit pixels (2-plane VU interleaved bytes)
    // 0b11011..16-bit pixels (2-plane VU)
}  // namespace OUT_CTRL_CLR

// Output Buffer Control Register
namespace OUT_CTRL_TOG {
constexpr PXP_Reg<&PXP_Layout::OUT_CTRL_TOG, 8, 24, 0x0> ALPHA;              // When generating an output buffer with an alpha component, the value in this field will be used when enabled to override the alpha passed through the pixel data pipeline
constexpr PXP_Reg<&PXP_Layout::OUT_CTRL_TOG, 1, 23, 0x0> ALPHA_OUTPUT;       // Indicates that alpha component in output buffer pixels should be overwritten by PXP_OUT_CTRL[ALPHA]
    // 0b0..Retain
    // 0b1..Overwritten
constexpr PXP_Reg<&PXP_Layout::OUT_CTRL_TOG, 2,  8, 0x0> INTERLACED_OUTPUT;  // Determines how the PXP writes it's output data
    // 0b00..All data written in progressive format to the OUTBUF Pointer.
    // 0b01..Interlaced output: only data for field 0 is written to the OUTBUF Pointer.
    // 0b10..Interlaced output: only data for field 1 is written to the OUTBUF2 Pointer.
    // 0b11..Interlaced output: data for field 0 is written to OUTBUF and data for field 1 is written to OUTBUF2.
constexpr PXP_Reg<&PXP_Layout::OUT_CTRL_TOG, 5,  0, 0x0> FORMAT;             // Output framebuffer format
    // 0b00000..32-bit pixels
    // 0b00100..32-bit pixels (unpacked 24-bit pixel in 32 bit DWORD.)
    // 0b00101..24-bit pixels (packed 24-bit format)
    // 0b01000..16-bit pixels
    // 0b01001..16-bit pixels
    // 0b01100..16-bit pixels
    // 0b01101..16-bit pixels
    // 0b01110..16-bit pixels
    // 0b10000..32-bit pixels (1-plane XYUV unpacked)
    // 0b10010..16-bit pixels (1-plane U0,Y0,V0,Y1 interleaved bytes)
    // 0b10011..16-bit pixels (1-plane V0,Y0,U0,Y1 interleaved bytes)
    // 0b10100..8-bit monochrome pixels (1-plane Y luma output)
    // 0b10101..4-bit monochrome pixels (1-plane Y luma, 4 bit truncation)
    // 0b11000..16-bit pixels (2-plane UV interleaved bytes)
    // 0b11001..16-bit pixels (2-plane UV)
    // 0b11010..16-bit pixels (2-plane VU interleaved bytes)
    // 0b11011..16-bit pixels (2-plane VU)
}  // namespace OUT_CTRL_TOG

// Output Frame Buffer Pointer
namespace OUT_BUF {
constexpr PXP_Reg<&PXP_Layout::OUT_BUF, 32, 0> ADDR;  // Current address pointer for the output frame buffer
}  // namespace OUT_BUF

// Output Frame Buffer Pointer #2
namespace OUT_BUF2 {
constexpr PXP_Reg<&PXP_Layout::OUT_BUF2, 32, 0> ADDR;  // Current address pointer for the output frame buffer
}  // namespace OUT_BUF2

// Output Buffer Pitch
namespace OUT_PITCH {
constexpr PXP_Reg<&PXP_Layout::OUT_PITCH, 16, 0> PITCH;  // Indicates the number of bytes in memory between two vertically adjacent pixels.
}  // namespace OUT_PITCH

// Output Surface Lower Right Coordinate
namespace OUT_LRC {
constexpr PXP_Reg<&PXP_Layout::OUT_LRC, 14, 16> X;  // Indicates number of horizontal PIXELS in the output surface (non-rotated)
constexpr PXP_Reg<&PXP_Layout::OUT_LRC, 14,  0> Y;  // Indicates the number of vertical PIXELS in the output surface (non-rotated)
}  // namespace OUT_LRC

// Processed Surface Upper Left Coordinate
namespace OUT_PS_ULC {
constexpr PXP_Reg<&PXP_Layout::OUT_PS_ULC, 14, 16> X;  // This field indicates the upper left X-coordinate (in pixels) of the processed surface (PS) in the output buffer
constexpr PXP_Reg<&PXP_Layout::OUT_PS_ULC, 14,  0> Y;  // This field indicates the upper left Y-coordinate (in pixels) of the processed surface in the output buffer
}  // namespace OUT_PS_ULC

// Processed Surface Lower Right Coordinate
namespace OUT_PS_LRC {
constexpr PXP_Reg<&PXP_Layout::OUT_PS_LRC, 14, 16> X;  // This field indicates the lower right X-coordinate (in pixels) of the processed surface (PS) in the output frame buffer
constexpr PXP_Reg<&PXP_Layout::OUT_PS_LRC, 14,  0> Y;  // This field indicates the lower right Y-coordinate (in pixels) of the processed surface in the output frame buffer
}  // namespace OUT_PS_LRC

// Alpha Surface Upper Left Coordinate
namespace OUT_AS_ULC {
constexpr PXP_Reg<&PXP_Layout::OUT_AS_ULC, 14, 16> X;  // This field indicates the upper left X-coordinate (in pixels) of the alpha surface (AS) in the output frame buffer
constexpr PXP_Reg<&PXP_Layout::OUT_AS_ULC, 14,  0> Y;  // This field indicates the upper left Y-coordinate (in pixels) of the alpha surface in the output frame buffer
}  // namespace OUT_AS_ULC

// Alpha Surface Lower Right Coordinate
namespace OUT_AS_LRC {
constexpr PXP_Reg<&PXP_Layout::OUT_AS_LRC, 14, 16> X;  // This field indicates the lower right X-coordinate (in pixels) of the alpha surface (AS) in the output frame buffer
constexpr PXP_Reg<&PXP_Layout::OUT_AS_LRC, 14,  0> Y;  // This field indicates the lower right Y-coordinate (in pixels) of the alpha surface in the output frame buffer
}  // namespace OUT_AS_LRC

// Processed Surface (PS) Control Register
namespace PS_CTRL {
constexpr PXP_Reg<&PXP_Layout::PS_CTRL, 2, 10> DECX;     // Horizontal pre decimation filter control.
    // 0b00..Disable pre-decimation filter.
    // 0b01..Decimate PS by 2.
    // 0b10..Decimate PS by 4.
    // 0b11..Decimate PS by 8.
constexpr PXP_Reg<&PXP_Layout::PS_CTRL, 2,  8> DECY;     // Verticle pre decimation filter control.
    // 0b00..Disable pre-decimation filter.
    // 0b01..Decimate PS by 2.
    // 0b10..Decimate PS by 4.
    // 0b11..Decimate PS by 8.
constexpr PXP_Reg<&PXP_Layout::PS_CTRL, 1,  6> WB_SWAP;  // Swap bytes in words.
    // For each 16 bit word, the two bytes will be swapped.
    // 0b0..Byte swap is disabled
    // 0b1..Byte swap is enabled
constexpr PXP_Reg<&PXP_Layout::PS_CTRL, 6,  0> FORMAT;   // PS buffer format.
    // To select between YUV and YCbCr formats, see bit 31 of the CSC1_COEF0 register.
    // 0b000100..32-bit pixels (unpacked 24-bit format with/without alpha at high 8bits)
    // 0b001100..16-bit pixels with/without alpha at high 1bit
    // 0b001101..16-bit pixels with/without alpha at high 4 bits
    // 0b001110..16-bit pixels
    // 0b010000..32-bit pixels (1-plane XYUV unpacked)
    // 0b010010..16-bit pixels (1-plane U0,Y0,V0,Y1 interleaved bytes)
    // 0b010011..16-bit pixels (1-plane V0,Y0,U0,Y1 interleaved bytes)
    // 0b010100..8-bit monochrome pixels (1-plane Y luma output)
    // 0b010101..4-bit monochrome pixels (1-plane Y luma, 4 bit truncation)
    // 0b011000..16-bit pixels (2-plane UV interleaved bytes)
    // 0b011001..16-bit pixels (2-plane UV)
    // 0b011010..16-bit pixels (2-plane VU interleaved bytes)
    // 0b011011..16-bit pixels (2-plane VU)
    // 0b011110..16-bit pixels (3-plane format)
    // 0b011111..16-bit pixels (3-plane format)
    // 0b100100..2-bit pixels with alpha at the low 8 bits
    // 0b101100..16-bit pixels with alpha at the low 1bits
    // 0b101101..16-bit pixels with alpha at the low 4 bits
}  // namespace PS_CTRL

// Processed Surface (PS) Control Register
namespace PS_CTRL_SET {
constexpr PXP_Reg<&PXP_Layout::PS_CTRL_SET, 2, 10, 0x0> DECX;     // Horizontal pre decimation filter control.
    // 0b00..Disable pre-decimation filter.
    // 0b01..Decimate PS by 2.
    // 0b10..Decimate PS by 4.
    // 0b11..Decimate PS by 8.
constexpr PXP_Reg<&PXP_Layout::PS_CTRL_SET, 2,  8, 0x0> DECY;     // Verticle pre decimation filter control.
    // 0b00..Disable pre-decimation filter.
    // 0b01..Decimate PS by 2.
    // 0b10..Decimate PS by 4.
    // 0b11..Decimate PS by 8.
constexpr PXP_Reg<&PXP_Layout::PS_CTRL_SET, 1,  6, 0x0> WB_SWAP;  // Swap bytes in words.
    // For each 16 bit word, the two bytes will be swapped.
    // 0b0..Byte swap is disabled
    // 0b1..Byte swap is enabled
constexpr PXP_Reg<&PXP_Layout::PS_CTRL_SET, 6,  0, 0x0> FORMAT;   // PS buffer format.
    // To select between YUV and YCbCr formats, see bit 31 of the CSC1_COEF0 register.
    // 0b000100..32-bit pixels (unpacked 24-bit format with/without alpha at high 8bits)
    // 0b001100..16-bit pixels with/without alpha at high 1bit
    // 0b001101..16-bit pixels with/without alpha at high 4 bits
    // 0b001110..16-bit pixels
    // 0b010000..32-bit pixels (1-plane XYUV unpacked)
    // 0b010010..16-bit pixels (1-plane U0,Y0,V0,Y1 interleaved bytes)
    // 0b010011..16-bit pixels (1-plane V0,Y0,U0,Y1 interleaved bytes)
    // 0b010100..8-bit monochrome pixels (1-plane Y luma output)
    // 0b010101..4-bit monochrome pixels (1-plane Y luma, 4 bit truncation)
    // 0b011000..16-bit pixels (2-plane UV interleaved bytes)
    // 0b011001..16-bit pixels (2-plane UV)
    // 0b011010..16-bit pixels (2-plane VU interleaved bytes)
    // 0b011011..16-bit pixels (2-plane VU)
    // 0b011110..16-bit pixels (3-plane format)
    // 0b011111..16-bit pixels (3-plane format)
    // 0b100100..2-bit pixels with alpha at the low 8 bits
    // 0b101100..16-bit pixels with alpha at the low 1bits
    // 0b101101..16-bit pixels with alpha at the low 4 bits
}  // namespace PS_CTRL_SET

// Processed Surface (PS) Control Register
namespace PS_CTRL_CLR {
constexpr PXP_Reg<&PXP_Layout::PS_CTRL_CLR, 2, 10, 0x0> DECX;     // Horizontal pre decimation filter control.
    // 0b00..Disable pre-decimation filter.
    // 0b01..Decimate PS by 2.
    // 0b10..Decimate PS by 4.
    // 0b11..Decimate PS by 8.
constexpr PXP_Reg<&PXP_Layout::PS_CTRL_CLR, 2,  8, 0x0> DECY;     // Verticle pre decimation filter control.
    // 0b00..Disable pre-decimation filter.
    // 0b01..Decimate PS by 2.
    // 0b10..Decimate PS by 4.
    // 0b11..Decimate PS by 8.
constexpr PXP_Reg<&PXP_Layout::PS_CTRL_CLR, 1,  6, 0x0> WB_SWAP;  // Swap bytes in words.
    // For each 16 bit word, the two bytes will be swapped.
    // 0b0..Byte swap is disabled
    // 0b1..Byte swap is enabled
constexpr PXP_Reg<&PXP_Layout::PS_CTRL_CLR, 6,  0, 0x0> FORMAT;   // PS buffer format.
    // To select between YUV and YCbCr formats, see bit 31 of the CSC1_COEF0 register.
    // 0b000100..32-bit pixels (unpacked 24-bit format with/without alpha at high 8bits)
    // 0b001100..16-bit pixels with/without alpha at high 1bit
    // 0b001101..16-bit pixels with/without alpha at high 4 bits
    // 0b001110..16-bit pixels
    // 0b010000..32-bit pixels (1-plane XYUV unpacked)
    // 0b010010..16-bit pixels (1-plane U0,Y0,V0,Y1 interleaved bytes)
    // 0b010011..16-bit pixels (1-plane V0,Y0,U0,Y1 interleaved bytes)
    // 0b010100..8-bit monochrome pixels (1-plane Y luma output)
    // 0b010101..4-bit monochrome pixels (1-plane Y luma, 4 bit truncation)
    // 0b011000..16-bit pixels (2-plane UV interleaved bytes)
    // 0b011001..16-bit pixels (2-plane UV)
    // 0b011010..16-bit pixels (2-plane VU interleaved bytes)
    // 0b011011..16-bit pixels (2-plane VU)
    // 0b011110..16-bit pixels (3-plane format)
    // 0b011111..16-bit pixels (3-plane format)
    // 0b100100..2-bit pixels with alpha at the low 8 bits
    // 0b101100..16-bit pixels with alpha at the low 1bits
    // 0b101101..16-bit pixels with alpha at the low 4 bits
}  // namespace PS_CTRL_CLR

// Processed Surface (PS) Control Register
namespace PS_CTRL_TOG {
constexpr PXP_Reg<&PXP_Layout::PS_CTRL_TOG, 2, 10, 0x0> DECX;     // Horizontal pre decimation filter control.
    // 0b00..Disable pre-decimation filter.
    // 0b01..Decimate PS by 2.
    // 0b10..Decimate PS by 4.
    // 0b11..Decimate PS by 8.
constexpr PXP_Reg<&PXP_Layout::PS_CTRL_TOG, 2,  8, 0x0> DECY;     // Verticle pre decimation filter control.
    // 0b00..Disable pre-decimation filter.
    // 0b01..Decimate PS by 2.
    // 0b10..Decimate PS by 4.
    // 0b11..Decimate PS by 8.
constexpr PXP_Reg<&PXP_Layout::PS_CTRL_TOG, 1,  6, 0x0> WB_SWAP;  // Swap bytes in words.
    // For each 16 bit word, the two bytes will be swapped.
    // 0b0..Byte swap is disabled
    // 0b1..Byte swap is enabled
constexpr PXP_Reg<&PXP_Layout::PS_CTRL_TOG, 6,  0, 0x0> FORMAT;   // PS buffer format.
    // To select between YUV and YCbCr formats, see bit 31 of the CSC1_COEF0 register.
    // 0b000100..32-bit pixels (unpacked 24-bit format with/without alpha at high 8bits)
    // 0b001100..16-bit pixels with/without alpha at high 1bit
    // 0b001101..16-bit pixels with/without alpha at high 4 bits
    // 0b001110..16-bit pixels
    // 0b010000..32-bit pixels (1-plane XYUV unpacked)
    // 0b010010..16-bit pixels (1-plane U0,Y0,V0,Y1 interleaved bytes)
    // 0b010011..16-bit pixels (1-plane V0,Y0,U0,Y1 interleaved bytes)
    // 0b010100..8-bit monochrome pixels (1-plane Y luma output)
    // 0b010101..4-bit monochrome pixels (1-plane Y luma, 4 bit truncation)
    // 0b011000..16-bit pixels (2-plane UV interleaved bytes)
    // 0b011001..16-bit pixels (2-plane UV)
    // 0b011010..16-bit pixels (2-plane VU interleaved bytes)
    // 0b011011..16-bit pixels (2-plane VU)
    // 0b011110..16-bit pixels (3-plane format)
    // 0b011111..16-bit pixels (3-plane format)
    // 0b100100..2-bit pixels with alpha at the low 8 bits
    // 0b101100..16-bit pixels with alpha at the low 1bits
    // 0b101101..16-bit pixels with alpha at the low 4 bits
}  // namespace PS_CTRL_TOG

// PS Input Buffer Address
namespace PS_BUF {
constexpr PXP_Reg<&PXP_Layout::PS_BUF, 32, 0> ADDR;  // Address pointer for the PS RGB or Y (luma) input buffer.
}  // namespace PS_BUF

// PS U/Cb or 2 Plane UV Input Buffer Address
namespace PS_UBUF {
constexpr PXP_Reg<&PXP_Layout::PS_UBUF, 32, 0> ADDR;  // Address pointer for the PS U/Cb or 2 plane UV Chroma input buffer.
}  // namespace PS_UBUF

// PS V/Cr Input Buffer Address
namespace PS_VBUF {
constexpr PXP_Reg<&PXP_Layout::PS_VBUF, 32, 0> ADDR;  // Address pointer for the PS V/Cr Chroma input buffer.
}  // namespace PS_VBUF

// Processed Surface Pitch
namespace PS_PITCH {
constexpr PXP_Reg<&PXP_Layout::PS_PITCH, 16, 0> PITCH;  // Indicates the number of bytes in memory between two vertically adjacent pixels.
}  // namespace PS_PITCH

// PS Background Color
namespace PS_BACKGROUND {
constexpr PXP_Reg<&PXP_Layout::PS_BACKGROUND, 24, 0> COLOR;  // Background color (in 24bpp format) for any pixels not within the buffer range specified by the PS ULC/LRC
}  // namespace PS_BACKGROUND

// PS Scale Factor Register
namespace PS_SCALE {
constexpr PXP_Reg<&PXP_Layout::PS_SCALE, 15, 16> YSCALE;  // This is a two bit integer and 12 bit fractional representation
constexpr PXP_Reg<&PXP_Layout::PS_SCALE, 15,  0> XSCALE;  // This is a two bit integer and 12 bit fractional representation
}  // namespace PS_SCALE

// PS Scale Offset Register
namespace PS_OFFSET {
constexpr PXP_Reg<&PXP_Layout::PS_OFFSET, 12, 16> YOFFSET;  // This is a 12 bit fractional representation
constexpr PXP_Reg<&PXP_Layout::PS_OFFSET, 12,  0> XOFFSET;  // This is a 12 bit fractional representation
}  // namespace PS_OFFSET

// PS Color Key Low
namespace PS_CLRKEYLOW {
constexpr PXP_Reg<&PXP_Layout::PS_CLRKEYLOW, 24, 0> PIXEL;  // Low range of color key applied to PS buffer
}  // namespace PS_CLRKEYLOW

// PS Color Key High
namespace PS_CLRKEYHIGH {
constexpr PXP_Reg<&PXP_Layout::PS_CLRKEYHIGH, 24, 0> PIXEL;  // High range of color key applied to PS buffer
}  // namespace PS_CLRKEYHIGH

// Alpha Surface Control
namespace AS_CTRL {
constexpr PXP_Reg<&PXP_Layout::AS_CTRL, 1, 20> ALPHA_INVERT;     // Setting this bit to logic 0 will not alter the alpha value
    // 0b0..Not inverted
    // 0b1..Inverted
constexpr PXP_Reg<&PXP_Layout::AS_CTRL, 4, 16> ROP;              // Indicates a raster operation to perform when enabled
    // 0b0000..AS AND PS
    // 0b0001..nAS AND PS
    // 0b0010..AS AND nPS
    // 0b0011..AS OR PS
    // 0b0100..nAS OR PS
    // 0b0101..AS OR nPS
    // 0b0110..nAS
    // 0b0111..nPS
    // 0b1000..AS NAND PS
    // 0b1001..AS NOR PS
    // 0b1010..AS XOR PS
    // 0b1011..AS XNOR PS
constexpr PXP_Reg<&PXP_Layout::AS_CTRL, 8,  8> ALPHA;            // Alpha modifier used when the ALPHA_MULTIPLY or ALPHA_OVERRIDE values are programmed in PXP_AS_CTRL[ALPHA_CTRL]
constexpr PXP_Reg<&PXP_Layout::AS_CTRL, 4,  4> FORMAT;           // Indicates the input buffer format for AS.
    // 0b0000..32-bit pixels with alpha
    // 0b0001..2-bit pixel with alpha at low 8 bits
    // 0b0100..32-bit pixels without alpha (unpacked 24-bit format)
    // 0b1000..16-bit pixels with alpha
    // 0b1001..16-bit pixels with alpha
    // 0b1010..16-bit pixel with alpha at low 1 bit
    // 0b1011..16-bit pixel with alpha at low 4 bits
    // 0b1100..16-bit pixels without alpha
    // 0b1101..16-bit pixels without alpha
    // 0b1110..16-bit pixels without alpha
constexpr PXP_Reg<&PXP_Layout::AS_CTRL, 1,  3> ENABLE_COLORKEY;  // Indicates that colorkey functionality is enabled for this alpha surface
    // 0b0..Disabled
    // 0b1..Enabled
constexpr PXP_Reg<&PXP_Layout::AS_CTRL, 2,  1> ALPHA_CTRL;       // Determines how the alpha value is constructed for this alpha surface
    // 0b00..Indicates that the AS pixel alpha value will be used to blend the AS with PS. The ALPHA field is
    //     ignored.
    // 0b01..Indicates that the value in the ALPHA field should be used instead of the alpha values present in the
    //     input pixels.
    // 0b10..Indicates that the value in the ALPHA field should be used to scale all pixel alpha values. Each pixel
    //     alpha is multiplied by the value in the ALPHA field.
    // 0b11..Enable ROPs. The ROP field indicates an operation to be performed on the alpha surface and PS pixels.
}  // namespace AS_CTRL

// Alpha Surface Buffer Pointer
namespace AS_BUF {
constexpr PXP_Reg<&PXP_Layout::AS_BUF, 32, 0> ADDR;  // Address pointer for the alpha surface 0 buffer.
}  // namespace AS_BUF

// Alpha Surface Pitch
namespace AS_PITCH {
constexpr PXP_Reg<&PXP_Layout::AS_PITCH, 16, 0> PITCH;  // Indicates the number of bytes in memory between two vertically adjacent pixels.
}  // namespace AS_PITCH

// Overlay Color Key Low
namespace AS_CLRKEYLOW {
constexpr PXP_Reg<&PXP_Layout::AS_CLRKEYLOW, 24, 0> PIXEL;  // Low range of RGB color key applied to AS buffer.
    // Each overlay has an independent colorkey enable.
}  // namespace AS_CLRKEYLOW

// Overlay Color Key High
namespace AS_CLRKEYHIGH {
constexpr PXP_Reg<&PXP_Layout::AS_CLRKEYHIGH, 24, 0> PIXEL;  // High range of RGB color key applied to AS buffer.
    // Each overlay has an independent colorkey enable.
}  // namespace AS_CLRKEYHIGH

// Color Space Conversion Coefficient Register 0
namespace CSC1_COEF0 {
constexpr PXP_Reg<&PXP_Layout::CSC1_COEF0,  1, 31> YCBCR_MODE;  // Set to 1 when performing YCbCr conversion to RGB
    // 0b0..YUV to RGB
    // 0b1..YCbCr to RGB
constexpr PXP_Reg<&PXP_Layout::CSC1_COEF0,  1, 30> BYPASS;      // Bypass the CSC unit in the scaling engine
constexpr PXP_Reg<&PXP_Layout::CSC1_COEF0, 11, 18> C0;          // Two's compliment Y multiplier coefficient.
    // YUV=0x100 (1.000) YCbCr=0x12A (1.164)
constexpr PXP_Reg<&PXP_Layout::CSC1_COEF0,  9,  9> UV_OFFSET;   // Two's compliment phase offset implicit for CbCr data
constexpr PXP_Reg<&PXP_Layout::CSC1_COEF0,  9,  0> Y_OFFSET;    // Two's compliment amplitude offset implicit in the Y data
}  // namespace CSC1_COEF0

// Color Space Conversion Coefficient Register 1
namespace CSC1_COEF1 {
constexpr PXP_Reg<&PXP_Layout::CSC1_COEF1, 11, 16> C1;  // Two's compliment Red V/Cr multiplier coefficient.
    // YUV=0x123 (1.140) YCbCr=0x198 (1.596)
constexpr PXP_Reg<&PXP_Layout::CSC1_COEF1, 11,  0> C4;  // Two's compliment Blue U/Cb multiplier coefficient.
    // YUV=0x208 (2.032) YCbCr=0x204 (2.017)
}  // namespace CSC1_COEF1

// Color Space Conversion Coefficient Register 2
namespace CSC1_COEF2 {
constexpr PXP_Reg<&PXP_Layout::CSC1_COEF2, 11, 16> C2;  // Two's complement Green V/Cr multiplier coefficient.
    // YUV=0x76B (-0.581) YCbCr=0x730 (-0.813)
constexpr PXP_Reg<&PXP_Layout::CSC1_COEF2, 11,  0> C3;  // Two's complement Green U/Cb multiplier coefficient.
    // YUV=0x79C (-0.394) YCbCr=0x79C (-0.392)
}  // namespace CSC1_COEF2

// PXP Power Control Register
namespace POWER {
constexpr PXP_Reg<&PXP_Layout::POWER, 20, 12> CTRL;              // Power control for the PXP.
constexpr PXP_Reg<&PXP_Layout::POWER,  3,  9> ROT_MEM_LP_STATE;  // Select the low power state of the Rotation (ROT) memory.
    // 0b000..Memory is not in low power state.
    // 0b001..Light Sleep Mode. Low leakage mode, maintain memory contents.
    // 0b010..Deep Sleep Mode. Low leakage mode, maintain memory contents.
    // 0b100..Shut Down Mode. Shut Down periphery and core, no memory retention.
}  // namespace POWER

// Next Frame Pointer
namespace NEXT {
constexpr PXP_Reg<&PXP_Layout::NEXT, 30, 2> POINTER;                  // A pointer to a data structure containing register values to be used when processing the next frame
constexpr PXP_Reg<regs::constify(&PXP_Layout::NEXT),  1, 0> ENABLED;  // Indicates that the "next frame" functionality has been enabled
}  // namespace NEXT

// PXP Alpha Engine A Control Register.
namespace PORTER_DUFF_CTRL {
constexpr PXP_Reg<&PXP_Layout::PORTER_DUFF_CTRL, 8, 24> S1_GLOBAL_ALPHA;       // s1 global alpha
constexpr PXP_Reg<&PXP_Layout::PORTER_DUFF_CTRL, 8, 16> S0_GLOBAL_ALPHA;       // s0 global alpha
constexpr PXP_Reg<&PXP_Layout::PORTER_DUFF_CTRL, 1, 13> S1_COLOR_MODE;         // s1 color mode
    // 0b0..Original pixel
    // 0b1..Scaled pixel
constexpr PXP_Reg<&PXP_Layout::PORTER_DUFF_CTRL, 1, 12> S1_ALPHA_MODE;         // s1 alpha mode (Porter-Duff Alpha mode)
    // 0b0..Straight mode
    // 0b1..Inverted mode
constexpr PXP_Reg<&PXP_Layout::PORTER_DUFF_CTRL, 2, 10> S1_GLOBAL_ALPHA_MODE;  // s1 global alpha mode (Porter-Duff Global Alpha mode)
    // 0b00..Global alpha
    // 0b01..Local alpha
    // 0b10..Scaled alpha
    // 0b11..Scaled alpha
constexpr PXP_Reg<&PXP_Layout::PORTER_DUFF_CTRL, 2,  8> S1_S0_FACTOR_MODE;     // s1 to s0 factor mode (Porter-Duff factor mode)
    // 0b00..1
    // 0b01..0
    // 0b10..Straight alpha
    // 0b11..Inverse alpha
constexpr PXP_Reg<&PXP_Layout::PORTER_DUFF_CTRL, 1,  6> S0_COLOR_MODE;         // s0 color mode (Porter-Duff color mode)
    // 0b0..Original pixel
    // 0b1..Scaled pixel
constexpr PXP_Reg<&PXP_Layout::PORTER_DUFF_CTRL, 1,  5> S0_ALPHA_MODE;         // s0 alpha mode (Porter-Duff alpha mode)
    // 0b0..Straight mode
    // 0b1..Inverted mode
constexpr PXP_Reg<&PXP_Layout::PORTER_DUFF_CTRL, 2,  3> S0_GLOBAL_ALPHA_MODE;  // s0 global alpha mode
    // 0b00..Global alpha
    // 0b01..Local alpha
    // 0b10..Scaled alpha
    // 0b11..Scaled alpha
constexpr PXP_Reg<&PXP_Layout::PORTER_DUFF_CTRL, 2,  1> S0_S1_FACTOR_MODE;     // s0 to s1 factor mode
    // 0b00..1
    // 0b01..0
    // 0b10..Straight alpha
    // 0b11..Inverse alpha
constexpr PXP_Reg<&PXP_Layout::PORTER_DUFF_CTRL, 1,  0> PORTER_DUFF_ENABLE;    // Porter-Duff Enable
    // 0b0..Disabled
    // 0b1..Enabled
}  // namespace PORTER_DUFF_CTRL

}  // namespace PXP

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
