// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// LCDIF.h defines all the LCDIF registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>
#include <type_traits>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Size of Registers Arrays
constexpr size_t kLCDIF_PIGEON_count = 12;

// Structure type to access the Enhanced LCD Interface (eLCDIF) registers.
//
// Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_LCDIF.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct LCDIF_Layout {
  volatile uint32_t CTRL;                              /**< LCDIF General Control Register, offset: 0x0 */
  volatile uint32_t CTRL_SET;                          /**< LCDIF General Control Register, offset: 0x4 */
  volatile uint32_t CTRL_CLR;                          /**< LCDIF General Control Register, offset: 0x8 */
  volatile uint32_t CTRL_TOG;                          /**< LCDIF General Control Register, offset: 0xC */
  volatile uint32_t CTRL1;                             /**< LCDIF General Control1 Register, offset: 0x10 */
  volatile uint32_t CTRL1_SET;                         /**< LCDIF General Control1 Register, offset: 0x14 */
  volatile uint32_t CTRL1_CLR;                         /**< LCDIF General Control1 Register, offset: 0x18 */
  volatile uint32_t CTRL1_TOG;                         /**< LCDIF General Control1 Register, offset: 0x1C */
  volatile uint32_t CTRL2;                             /**< LCDIF General Control2 Register, offset: 0x20 */
  volatile uint32_t CTRL2_SET;                         /**< LCDIF General Control2 Register, offset: 0x24 */
  volatile uint32_t CTRL2_CLR;                         /**< LCDIF General Control2 Register, offset: 0x28 */
  volatile uint32_t CTRL2_TOG;                         /**< LCDIF General Control2 Register, offset: 0x2C */
  volatile uint32_t TRANSFER_COUNT;                    /**< LCDIF Horizontal and Vertical Valid Data Count Register, offset: 0x30 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CUR_BUF;                           /**< LCD Interface Current Buffer Address Register, offset: 0x40 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t NEXT_BUF;                          /**< LCD Interface Next Buffer Address Register, offset: 0x50 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[7];
  volatile uint32_t VDCTRL0;                           /**< LCDIF VSYNC Mode and Dotclk Mode Control Register0, offset: 0x70 */
  volatile uint32_t VDCTRL0_SET;                       /**< LCDIF VSYNC Mode and Dotclk Mode Control Register0, offset: 0x74 */
  volatile uint32_t VDCTRL0_CLR;                       /**< LCDIF VSYNC Mode and Dotclk Mode Control Register0, offset: 0x78 */
  volatile uint32_t VDCTRL0_TOG;                       /**< LCDIF VSYNC Mode and Dotclk Mode Control Register0, offset: 0x7C */
  volatile uint32_t VDCTRL1;                           /**< LCDIF VSYNC Mode and Dotclk Mode Control Register1, offset: 0x80 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t VDCTRL2;                           /**< LCDIF VSYNC Mode and Dotclk Mode Control Register2, offset: 0x90 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t VDCTRL3;                           /**< LCDIF VSYNC Mode and Dotclk Mode Control Register3, offset: 0xA0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t VDCTRL4;                           /**< LCDIF VSYNC Mode and Dotclk Mode Control Register4, offset: 0xB0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[55];
  volatile uint32_t BM_ERROR_STAT;                     /**< Bus Master Error Status Register, offset: 0x190 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CRC_STAT;                          /**< CRC Status Register, offset: 0x1A0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  const volatile uint32_t STAT;                        /**< LCD Interface Status Register, offset: 0x1B0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[115];
  volatile uint32_t PIGEONCTRL0;                       /**< LCDIF Pigeon Mode Control0 Register, offset: 0x380 */
  volatile uint32_t PIGEONCTRL0_SET;                   /**< LCDIF Pigeon Mode Control0 Register, offset: 0x384 */
  volatile uint32_t PIGEONCTRL0_CLR;                   /**< LCDIF Pigeon Mode Control0 Register, offset: 0x388 */
  volatile uint32_t PIGEONCTRL0_TOG;                   /**< LCDIF Pigeon Mode Control0 Register, offset: 0x38C */
  volatile uint32_t PIGEONCTRL1;                       /**< LCDIF Pigeon Mode Control1 Register, offset: 0x390 */
  volatile uint32_t PIGEONCTRL1_SET;                   /**< LCDIF Pigeon Mode Control1 Register, offset: 0x394 */
  volatile uint32_t PIGEONCTRL1_CLR;                   /**< LCDIF Pigeon Mode Control1 Register, offset: 0x398 */
  volatile uint32_t PIGEONCTRL1_TOG;                   /**< LCDIF Pigeon Mode Control1 Register, offset: 0x39C */
  volatile uint32_t PIGEONCTRL2;                       /**< LCDIF Pigeon Mode Control2 Register, offset: 0x3A0 */
  volatile uint32_t PIGEONCTRL2_SET;                   /**< LCDIF Pigeon Mode Control2 Register, offset: 0x3A4 */
  volatile uint32_t PIGEONCTRL2_CLR;                   /**< LCDIF Pigeon Mode Control2 Register, offset: 0x3A8 */
  volatile uint32_t PIGEONCTRL2_TOG;                   /**< LCDIF Pigeon Mode Control2 Register, offset: 0x3AC */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[276];
  struct PIGEON_Layout {                               /* offset: 0x800, array step: 0x40 */
    volatile uint32_t PIGEON_0;                        /**< Panel Interface Signal Generator Register, array offset: 0x800, array step: 0x40 */
    uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
    volatile uint32_t PIGEON_1;                        /**< Panel Interface Signal Generator Register, array offset: 0x810, array step: 0x40 */
    uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
    volatile uint32_t PIGEON_2;                        /**< Panel Interface Signal Generator Register, array offset: 0x820, array step: 0x40 */
    uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[7];
  } PIGEON[kLCDIF_PIGEON_count];
  volatile uint32_t LUT_CTRL;                          /**< Look Up Table Control Register, offset: 0xB00 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t LUT0_ADDR;                         /**< Lookup Table 0 Index Register, offset: 0xB10 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t LUT0_DATA;                         /**< Lookup Table 0 Data Register, offset: 0xB20 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t LUT1_ADDR;                         /**< Lookup Table 1 Index Register, offset: 0xB30 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t LUT1_DATA;                         /**< Lookup Table 1 Data Register, offset: 0xB40 */
};

constexpr size_t    kLCDIF_size = 0xB44;
constexpr uintptr_t kLCDIF_base = 0x402B8000;

namespace LCDIF {
constexpr regs::RegGroup<LCDIF_Layout, kLCDIF_size, kLCDIF_base> group;
}  // namespace LCDIF

namespace LCDIF {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false>
using LCDIF_Reg =
    regs::Reg32<kLCDIF_base, LCDIF_Layout, Member, 0, Bits, Shift,
                AssignMask, WriteOnly>;

// LCDIF General Control Register
namespace CTRL {
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL, 1, 31> SFTRST;              // This bit must be set to zero to enable normal operation of the LCDIF
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL, 1, 30> CLKGATE;             // This bit must be set to zero for normal operation
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL, 1, 26> DATA_SHIFT_DIR;      // Use this bit to determine the direction of shift of transmit data.
    // 0b0..Data to be transmitted is shifted LEFT by SHIFT_NUM_BITS bits.
    // 0b1..Data to be transmitted is shifted RIGHT by SHIFT_NUM_BITS bits.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL, 5, 21> SHIFT_NUM_BITS;
    // The data to be transmitted is shifted left or right by this number of bits.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL, 1, 19> BYPASS_COUNT;
    // When this bit is 0, it means that LCDIF will stop the block operation and turn off the RUN bit after the
    //     amount of data indicated by the LCDIF_TRANSFER_COUNT register has been transferred out
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL, 1, 17> DOTCLK_MODE;
    // Set this bit to 1 to make the hardware go into the DOTCLK mode, i.e. VSYNC/HSYNC/DOTCLK/ENABLE interface
    //     mode. ENABLE is optional, selected by the ENABLE_PRESENT bit. Toggle this bit from 1 to 0 to make the
    //     hardware go out of DOTCLK mode after completing all data transfer and deasserting the RUN bit.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL, 2, 14> INPUT_DATA_SWIZZLE;  // This field specifies how to swap the bytes fetched by the bus master interface
    // 0b00..Little Endian byte ordering (same as NO_SWAP).
    // 0b00..No byte swapping.(Little endian)
    // 0b01..Big Endian swap (swap bytes 0,3 and 1,2).
    // 0b01..Swizzle all bytes, swap bytes 0,3 and 1,2 (aka Big Endian).
    // 0b10..Swap half-words.
    // 0b11..Swap bytes within each half-word.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL, 2, 12> CSC_DATA_SWIZZLE;
    // This field specifies how to swap the bytes after the data has been converted into an internal representation
    //     of 24 bits per pixel and before it is transmitted over the LCD interface bus
    // 0b00..Little Endian byte ordering (same as NO_SWAP).
    // 0b00..No byte swapping.(Little endian)
    // 0b01..Big Endian swap (swap bytes 0,3 and 1,2).
    // 0b01..Swizzle all bytes, swap bytes 0,3 and 1,2 (aka Big Endian).
    // 0b10..Swap half-words.
    // 0b11..Swap bytes within each half-word.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL, 2, 10> LCD_DATABUS_WIDTH;   // LCD Data bus transfer width.
    // When LUT enabled, this field should be set to 0x01.
    // 0b00..16-bit data bus mode.
    // 0b01..8-bit data bus mode.
    // 0b10..18-bit data bus mode.
    // 0b11..24-bit data bus mode.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL, 2,  8> WORD_LENGTH;  // Input data format.
    // 0b00..Input data is 16 bits per pixel.
    // 0b01..Input data is 8 bits wide.
    // 0b10..Input data is 18 bits per pixel.
    // 0b11..Input data is 24 bits per pixel.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL, 1,  6> ENABLE_PXP_HANDSHAKE;
    // If this bit is set and LCDIF_MASTER bit is set, the LCDIF will act as bus master and the handshake mechanism
    //     between LCDIF and PXP will be turned on
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL, 1,  5> MASTER;              // Set this bit to make the LCDIF act as a bus master
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL, 1,  3> DATA_FORMAT_16_BIT;
    // When this bit is 1 and WORD_LENGTH = 0, it implies that the 16-bit data is in ARGB555 format
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL, 1,  2> DATA_FORMAT_18_BIT;  // Used only when WORD_LENGTH = 2, i.e. 18-bit.
    // 0b0..Data input to the block is in 18 bpp format, such that lower 18 bits contain RGB 666 and upper 14 bits
    //     do not contain any useful data.
    // 0b1..Data input to the block is in 18 bpp format, such that upper 18 bits contain RGB 666 and lower 14 bits
    //     do not contain any useful data.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL, 1,  1> DATA_FORMAT_24_BIT;
    // Used only when WORD_LENGTH = 3, i.e. 24-bit. Note that this applies to both packed and unpacked 24-bit data.
    // 0b0..Data input to the block is in 24 bpp format, such that all RGB 888 data is contained in 24 bits.
    // 0b1..Data input to the block is actually RGB 18 bpp, but there is 1 color per byte, hence the upper 2 bits in
    //     each byte do not contain any useful data, and should be dropped.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL, 1,  0> RUN;
    // When this bit is set by software, the LCDIF will begin transferring data between the SoC and the display
}  // namespace CTRL

// LCDIF General Control Register
namespace CTRL_SET {
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_SET, 1, 31, 0x0> SFTRST;               // This bit must be set to zero to enable normal operation of the LCDIF
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_SET, 1, 30, 0x0> CLKGATE;              // This bit must be set to zero for normal operation
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_SET, 1, 26, 0x0> DATA_SHIFT_DIR;       // Use this bit to determine the direction of shift of transmit data.
    // 0b0..Data to be transmitted is shifted LEFT by SHIFT_NUM_BITS bits.
    // 0b1..Data to be transmitted is shifted RIGHT by SHIFT_NUM_BITS bits.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_SET, 5, 21, 0x0> SHIFT_NUM_BITS;
    // The data to be transmitted is shifted left or right by this number of bits.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_SET, 1, 19, 0x0> BYPASS_COUNT;
    // When this bit is 0, it means that LCDIF will stop the block operation and turn off the RUN bit after the
    //     amount of data indicated by the LCDIF_TRANSFER_COUNT register has been transferred out
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_SET, 1, 17, 0x0> DOTCLK_MODE;
    // Set this bit to 1 to make the hardware go into the DOTCLK mode, i.e. VSYNC/HSYNC/DOTCLK/ENABLE interface
    //     mode. ENABLE is optional, selected by the ENABLE_PRESENT bit. Toggle this bit from 1 to 0 to make the
    //     hardware go out of DOTCLK mode after completing all data transfer and deasserting the RUN bit.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_SET, 2, 14, 0x0> INPUT_DATA_SWIZZLE;  // This field specifies how to swap the bytes fetched by the bus master interface
    // 0b00..Little Endian byte ordering (same as NO_SWAP).
    // 0b00..No byte swapping.(Little endian)
    // 0b01..Big Endian swap (swap bytes 0,3 and 1,2).
    // 0b01..Swizzle all bytes, swap bytes 0,3 and 1,2 (aka Big Endian).
    // 0b10..Swap half-words.
    // 0b11..Swap bytes within each half-word.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_SET, 2, 12, 0x0> CSC_DATA_SWIZZLE;
    // This field specifies how to swap the bytes after the data has been converted into an internal representation
    //     of 24 bits per pixel and before it is transmitted over the LCD interface bus
    // 0b00..Little Endian byte ordering (same as NO_SWAP).
    // 0b00..No byte swapping.(Little endian)
    // 0b01..Big Endian swap (swap bytes 0,3 and 1,2).
    // 0b01..Swizzle all bytes, swap bytes 0,3 and 1,2 (aka Big Endian).
    // 0b10..Swap half-words.
    // 0b11..Swap bytes within each half-word.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_SET, 2, 10, 0x0> LCD_DATABUS_WIDTH;   // LCD Data bus transfer width.
    // When LUT enabled, this field should be set to 0x01.
    // 0b00..16-bit data bus mode.
    // 0b01..8-bit data bus mode.
    // 0b10..18-bit data bus mode.
    // 0b11..24-bit data bus mode.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_SET, 2,  8, 0x0> WORD_LENGTH;         // Input data format.
    // 0b00..Input data is 16 bits per pixel.
    // 0b01..Input data is 8 bits wide.
    // 0b10..Input data is 18 bits per pixel.
    // 0b11..Input data is 24 bits per pixel.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_SET, 1,  6, 0x0> ENABLE_PXP_HANDSHAKE;
    // If this bit is set and LCDIF_MASTER bit is set, the LCDIF will act as bus master and the handshake mechanism
    //     between LCDIF and PXP will be turned on
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_SET, 1,  5, 0x0> MASTER;              // Set this bit to make the LCDIF act as a bus master
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_SET, 1,  3, 0x0> DATA_FORMAT_16_BIT;
    // When this bit is 1 and WORD_LENGTH = 0, it implies that the 16-bit data is in ARGB555 format
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_SET, 1,  2, 0x0> DATA_FORMAT_18_BIT;
    // Used only when WORD_LENGTH = 2, i.e. 18-bit.
    // 0b0..Data input to the block is in 18 bpp format, such that lower 18 bits contain RGB 666 and upper 14 bits
    //     do not contain any useful data.
    // 0b1..Data input to the block is in 18 bpp format, such that upper 18 bits contain RGB 666 and lower 14 bits
    //     do not contain any useful data.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_SET, 1,  1, 0x0> DATA_FORMAT_24_BIT;
    // Used only when WORD_LENGTH = 3, i.e. 24-bit. Note that this applies to both packed and unpacked 24-bit data.
    // 0b0..Data input to the block is in 24 bpp format, such that all RGB 888 data is contained in 24 bits.
    // 0b1..Data input to the block is actually RGB 18 bpp, but there is 1 color per byte, hence the upper 2 bits in
    //     each byte do not contain any useful data, and should be dropped.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_SET, 1,  0, 0x0> RUN;
    // When this bit is set by software, the LCDIF will begin transferring data between the SoC and the display
}  // namespace CTRL_SET

// LCDIF General Control Register
namespace CTRL_CLR {
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_CLR, 1, 31, 0x0> SFTRST;
    // This bit must be set to zero to enable normal operation of the LCDIF
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_CLR, 1, 30, 0x0> CLKGATE;
    // This bit must be set to zero for normal operation
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_CLR, 1, 26, 0x0> DATA_SHIFT_DIR;
    // Use this bit to determine the direction of shift of transmit data.
    // 0b0..Data to be transmitted is shifted LEFT by SHIFT_NUM_BITS bits.
    // 0b1..Data to be transmitted is shifted RIGHT by SHIFT_NUM_BITS bits.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_CLR, 5, 21, 0x0> SHIFT_NUM_BITS;
    // The data to be transmitted is shifted left or right by this number of bits.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_CLR, 1, 19, 0x0> BYPASS_COUNT;
    // When this bit is 0, it means that LCDIF will stop the block operation and turn off the RUN bit after the
    //     amount of data indicated by the LCDIF_TRANSFER_COUNT register has been transferred out
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_CLR, 1, 17, 0x0> DOTCLK_MODE;
    // Set this bit to 1 to make the hardware go into the DOTCLK mode, i.e. VSYNC/HSYNC/DOTCLK/ENABLE interface
    //     mode. ENABLE is optional, selected by the ENABLE_PRESENT bit. Toggle this bit from 1 to 0 to make the
    //     hardware go out of DOTCLK mode after completing all data transfer and deasserting the RUN bit.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_CLR, 2, 14, 0x0> INPUT_DATA_SWIZZLE;
    // This field specifies how to swap the bytes fetched by the bus master interface
    // 0b00..Little Endian byte ordering (same as NO_SWAP).
    // 0b00..No byte swapping.(Little endian)
    // 0b01..Big Endian swap (swap bytes 0,3 and 1,2).
    // 0b01..Swizzle all bytes, swap bytes 0,3 and 1,2 (aka Big Endian).
    // 0b10..Swap half-words.
    // 0b11..Swap bytes within each half-word.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_CLR, 2, 12, 0x0> CSC_DATA_SWIZZLE;
    // This field specifies how to swap the bytes after the data has been converted into an internal representation
    //     of 24 bits per pixel and before it is transmitted over the LCD interface bus
    // 0b00..Little Endian byte ordering (same as NO_SWAP).
    // 0b00..No byte swapping.(Little endian)
    // 0b01..Big Endian swap (swap bytes 0,3 and 1,2).
    // 0b01..Swizzle all bytes, swap bytes 0,3 and 1,2 (aka Big Endian).
    // 0b10..Swap half-words.
    // 0b11..Swap bytes within each half-word.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_CLR, 2, 10, 0x0> LCD_DATABUS_WIDTH;
    // LCD Data bus transfer width. When LUT enabled, this field should be set to 0x01.
    // 0b00..16-bit data bus mode.
    // 0b01..8-bit data bus mode.
    // 0b10..18-bit data bus mode.
    // 0b11..24-bit data bus mode.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_CLR, 2,  8, 0x0> WORD_LENGTH;  // Input data format.
    // 0b00..Input data is 16 bits per pixel.
    // 0b01..Input data is 8 bits wide.
    // 0b10..Input data is 18 bits per pixel.
    // 0b11..Input data is 24 bits per pixel.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_CLR, 1,  6, 0x0> ENABLE_PXP_HANDSHAKE;
    // If this bit is set and LCDIF_MASTER bit is set, the LCDIF will act as bus master and the handshake mechanism
    //     between LCDIF and PXP will be turned on
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_CLR, 1,  5, 0x0> MASTER;
    // Set this bit to make the LCDIF act as a bus master
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_CLR, 1,  3, 0x0> DATA_FORMAT_16_BIT;
    // When this bit is 1 and WORD_LENGTH = 0, it implies that the 16-bit data is in ARGB555 format
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_CLR, 1,  2, 0x0> DATA_FORMAT_18_BIT;
    // Used only when WORD_LENGTH = 2, i.e. 18-bit.
    // 0b0..Data input to the block is in 18 bpp format, such that lower 18 bits contain RGB 666 and upper 14 bits
    //     do not contain any useful data.
    // 0b1..Data input to the block is in 18 bpp format, such that upper 18 bits contain RGB 666 and lower 14 bits
    //     do not contain any useful data.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_CLR, 1,  1, 0x0> DATA_FORMAT_24_BIT;
    // Used only when WORD_LENGTH = 3, i.e. 24-bit. Note that this applies to both packed and unpacked 24-bit data.
    // 0b0..Data input to the block is in 24 bpp format, such that all RGB 888 data is contained in 24 bits.
    // 0b1..Data input to the block is actually RGB 18 bpp, but there is 1 color per byte, hence the upper 2 bits in
    //     each byte do not contain any useful data, and should be dropped.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_CLR, 1,  0, 0x0> RUN;
    // When this bit is set by software, the LCDIF will begin transferring data between the SoC and the display
}  // namespace CTRL_CLR

// LCDIF General Control Register
namespace CTRL_TOG {
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_TOG, 1, 31, 0x0> SFTRST;
    // This bit must be set to zero to enable normal operation of the LCDIF
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_TOG, 1, 30, 0x0> CLKGATE;
    // This bit must be set to zero for normal operation
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_TOG, 1, 26, 0x0> DATA_SHIFT_DIR;
    // Use this bit to determine the direction of shift of transmit data.
    // 0b0..Data to be transmitted is shifted LEFT by SHIFT_NUM_BITS bits.
    // 0b1..Data to be transmitted is shifted RIGHT by SHIFT_NUM_BITS bits.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_TOG, 5, 21, 0x0> SHIFT_NUM_BITS;
    // The data to be transmitted is shifted left or right by this number of bits.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_TOG, 1, 19, 0x0> BYPASS_COUNT;
    // When this bit is 0, it means that LCDIF will stop the block operation and turn off the RUN bit after the
    //     amount of data indicated by the LCDIF_TRANSFER_COUNT register has been transferred out
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_TOG, 1, 17, 0x0> DOTCLK_MODE;
    // Set this bit to 1 to make the hardware go into the DOTCLK mode, i.e. VSYNC/HSYNC/DOTCLK/ENABLE interface
    //     mode. ENABLE is optional, selected by the ENABLE_PRESENT bit. Toggle this bit from 1 to 0 to make the
    //     hardware go out of DOTCLK mode after completing all data transfer and deasserting the RUN bit.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_TOG, 2, 14, 0x0> INPUT_DATA_SWIZZLE;
    // This field specifies how to swap the bytes fetched by the bus master interface
    // 0b00..Little Endian byte ordering (same as NO_SWAP).
    // 0b00..No byte swapping.(Little endian)
    // 0b01..Big Endian swap (swap bytes 0,3 and 1,2).
    // 0b01..Swizzle all bytes, swap bytes 0,3 and 1,2 (aka Big Endian).
    // 0b10..Swap half-words.
    // 0b11..Swap bytes within each half-word.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_TOG, 2, 12, 0x0> CSC_DATA_SWIZZLE;
    // This field specifies how to swap the bytes after the data has been converted into an internal representation
    //     of 24 bits per pixel and before it is transmitted over the LCD interface bus
    // 0b00..Little Endian byte ordering (same as NO_SWAP).
    // 0b00..No byte swapping.(Little endian)
    // 0b01..Big Endian swap (swap bytes 0,3 and 1,2).
    // 0b01..Swizzle all bytes, swap bytes 0,3 and 1,2 (aka Big Endian).
    // 0b10..Swap half-words.
    // 0b11..Swap bytes within each half-word.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_TOG, 2, 10, 0x0> LCD_DATABUS_WIDTH;
    // LCD Data bus transfer width. When LUT enabled, this field should be set to 0x01.
    // 0b00..16-bit data bus mode.
    // 0b01..8-bit data bus mode.
    // 0b10..18-bit data bus mode.
    // 0b11..24-bit data bus mode.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_TOG, 2,  8, 0x0> WORD_LENGTH;  // Input data format.
    // 0b00..Input data is 16 bits per pixel.
    // 0b01..Input data is 8 bits wide.
    // 0b10..Input data is 18 bits per pixel.
    // 0b11..Input data is 24 bits per pixel.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_TOG, 1,  6, 0x0> ENABLE_PXP_HANDSHAKE;
    // If this bit is set and LCDIF_MASTER bit is set, the LCDIF will act as bus master and the handshake mechanism
    //     between LCDIF and PXP will be turned on
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_TOG, 1,  5, 0x0> MASTER;
    // Set this bit to make the LCDIF act as a bus master
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_TOG, 1,  3, 0x0> DATA_FORMAT_16_BIT;
    // When this bit is 1 and WORD_LENGTH = 0, it implies that the 16-bit data is in ARGB555 format
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_TOG, 1,  2, 0x0> DATA_FORMAT_18_BIT;
    // Used only when WORD_LENGTH = 2, i.e. 18-bit.
    // 0b0..Data input to the block is in 18 bpp format, such that lower 18 bits contain RGB 666 and upper 14 bits
    //     do not contain any useful data.
    // 0b1..Data input to the block is in 18 bpp format, such that upper 18 bits contain RGB 666 and lower 14 bits
    //     do not contain any useful data.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_TOG, 1,  1, 0x0> DATA_FORMAT_24_BIT;
    // Used only when WORD_LENGTH = 3, i.e. 24-bit. Note that this applies to both packed and unpacked 24-bit data.
    // 0b0..Data input to the block is in 24 bpp format, such that all RGB 888 data is contained in 24 bits.
    // 0b1..Data input to the block is actually RGB 18 bpp, but there is 1 color per byte, hence the upper 2 bits in
    //     each byte do not contain any useful data, and should be dropped.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL_TOG, 1,  0, 0x0> RUN;
    // When this bit is set by software, the LCDIF will begin transferring data between the SoC and the display
}  // namespace CTRL_TOG

// LCDIF General Control1 Register
namespace CTRL1 {
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1, 1, 31> IMAGE_DATA_SELECT;                   // Command Mode MIPI image data select bit
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1, 1, 30> CS_OUT_SELECT;                       // This bit is CS0/CS1 valid select signals
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1, 1, 26> BM_ERROR_IRQ_EN;                     // This bit is set to enable bus master error interrupt in the LCDIF master mode.
constexpr LCDIF_Reg<regs::constify(&LCDIF_Layout::CTRL1), 1, 25> BM_ERROR_IRQ;        // This bit is set to indicate that an interrupt is requested by the LCDIF block
    // 0b0..No Interrupt Request Pending.
    // 0b1..Interrupt Request Pending.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1, 1, 24> RECOVER_ON_UNDERFLOW;
    // Set this bit to enable the LCDIF block to recover in the next field/frame if there was an underflow in the
    //     current field/frame
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1, 1, 23> INTERLACE_FIELDS;                    // Set this bit if it is required that the LCDIF block fetches odd lines in one field and even lines in the
    //     other field
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1, 1, 22> START_INTERLACE_FROM_SECOND_FIELD;
    // The default is to grab the odd lines first and then the even lines
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1, 1, 21> FIFO_CLEAR;                          // Set this bit to clear all the data in the latency FIFO (LFIFO), TXFIFO and the RXFIFO.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1, 1, 20> IRQ_ON_ALTERNATE_FIELDS;
    // If this bit is set, the LCDIF block will assert the cur_frame_done interrupt only on alternate fields,
    //     otherwise it will issue the interrupt on both odd and even field
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1, 4, 16> BYTE_PACKING_FORMAT;                 // This bitfield is used to show which data bytes in a 32-bit word are valid
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1, 1, 15> OVERFLOW_IRQ_EN;                     // This bit is set to enable an overflow interrupt in the TXFIFO in the write mode.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1, 1, 14> UNDERFLOW_IRQ_EN;                    // This bit is set to enable an underflow interrupt in the TXFIFO in the write mode.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1, 1, 13> CUR_FRAME_DONE_IRQ_EN;
    // This bit is set to 1 enable an interrupt every time the hardware enters in the vertical blanking state
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1, 1, 12> VSYNC_EDGE_IRQ_EN;
    // This bit is set to enable an interrupt every time the hardware encounters the leading VSYNC edge in the VSYNC
    //     and DOTCLK modes, or the beginning of every field in DVI mode
constexpr LCDIF_Reg<regs::constify(&LCDIF_Layout::CTRL1), 1, 11> OVERFLOW_IRQ;        // This bit is set to indicate that an interrupt is requested by the LCDIF block
    // 0b0..No Interrupt Request Pending.
    // 0b1..Interrupt Request Pending.
constexpr LCDIF_Reg<regs::constify(&LCDIF_Layout::CTRL1), 1, 10> UNDERFLOW_IRQ;       // This bit is set to indicate that an interrupt is requested by the LCDIF block
    // 0b0..No Interrupt Request Pending.
    // 0b1..Interrupt Request Pending.
constexpr LCDIF_Reg<regs::constify(&LCDIF_Layout::CTRL1), 1,  9> CUR_FRAME_DONE_IRQ;  // This bit is set to indicate that an interrupt is requested by the LCDIF block
    // 0b0..No Interrupt Request Pending.
    // 0b1..Interrupt Request Pending.
constexpr LCDIF_Reg<regs::constify(&LCDIF_Layout::CTRL1), 1,  8> VSYNC_EDGE_IRQ;      // This bit is set to indicate that an interrupt is requested by the LCDIF block
    // 0b0..No Interrupt Request Pending.
    // 0b1..Interrupt Request Pending.
}  // namespace CTRL1

// LCDIF General Control1 Register
namespace CTRL1_SET {
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_SET, 1, 31, 0x0> IMAGE_DATA_SELECT;                   // Command Mode MIPI image data select bit
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_SET, 1, 30, 0x0> CS_OUT_SELECT;                       // This bit is CS0/CS1 valid select signals
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_SET, 1, 26, 0x0> BM_ERROR_IRQ_EN;                     // This bit is set to enable bus master error interrupt in the LCDIF master mode.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_SET, 1, 25, 0x0> BM_ERROR_IRQ;                        // This bit is set to indicate that an interrupt is requested by the LCDIF block
    // 0b0..No Interrupt Request Pending.
    // 0b1..Interrupt Request Pending.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_SET, 1, 24, 0x0> RECOVER_ON_UNDERFLOW;
    // Set this bit to enable the LCDIF block to recover in the next field/frame if there was an underflow in the
    //     current field/frame
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_SET, 1, 23, 0x0> INTERLACE_FIELDS;
    // Set this bit if it is required that the LCDIF block fetches odd lines in one field and even lines in the
    //     other field
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_SET, 1, 22, 0x0> START_INTERLACE_FROM_SECOND_FIELD;
    // The default is to grab the odd lines first and then the even lines
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_SET, 1, 21, 0x0> FIFO_CLEAR;                          // Set this bit to clear all the data in the latency FIFO (LFIFO), TXFIFO and the RXFIFO.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_SET, 1, 20, 0x0> IRQ_ON_ALTERNATE_FIELDS;
    // If this bit is set, the LCDIF block will assert the cur_frame_done interrupt only on alternate fields,
    //     otherwise it will issue the interrupt on both odd and even field
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_SET, 4, 16, 0x0> BYTE_PACKING_FORMAT;                 // This bitfield is used to show which data bytes in a 32-bit word are valid
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_SET, 1, 15, 0x0> OVERFLOW_IRQ_EN;                     // This bit is set to enable an overflow interrupt in the TXFIFO in the write mode.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_SET, 1, 14, 0x0> UNDERFLOW_IRQ_EN;                    // This bit is set to enable an underflow interrupt in the TXFIFO in the write mode.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_SET, 1, 13, 0x0> CUR_FRAME_DONE_IRQ_EN;
    // This bit is set to 1 enable an interrupt every time the hardware enters in the vertical blanking state
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_SET, 1, 12, 0x0> VSYNC_EDGE_IRQ_EN;
    // This bit is set to enable an interrupt every time the hardware encounters the leading VSYNC edge in the VSYNC
    //     and DOTCLK modes, or the beginning of every field in DVI mode
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_SET, 1, 11, 0x0> OVERFLOW_IRQ;                        // This bit is set to indicate that an interrupt is requested by the LCDIF block
    // 0b0..No Interrupt Request Pending.
    // 0b1..Interrupt Request Pending.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_SET, 1, 10, 0x0> UNDERFLOW_IRQ;                       // This bit is set to indicate that an interrupt is requested by the LCDIF block
    // 0b0..No Interrupt Request Pending.
    // 0b1..Interrupt Request Pending.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_SET, 1,  9, 0x0> CUR_FRAME_DONE_IRQ;                  // This bit is set to indicate that an interrupt is requested by the LCDIF block
    // 0b0..No Interrupt Request Pending.
    // 0b1..Interrupt Request Pending.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_SET, 1,  8, 0x0> VSYNC_EDGE_IRQ;                      // This bit is set to indicate that an interrupt is requested by the LCDIF block
    // 0b0..No Interrupt Request Pending.
    // 0b1..Interrupt Request Pending.
}  // namespace CTRL1_SET

// LCDIF General Control1 Register
namespace CTRL1_CLR {
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_CLR, 1, 31, 0x0> IMAGE_DATA_SELECT;                   // Command Mode MIPI image data select bit
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_CLR, 1, 30, 0x0> CS_OUT_SELECT;                       // This bit is CS0/CS1 valid select signals
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_CLR, 1, 26, 0x0> BM_ERROR_IRQ_EN;                     // This bit is set to enable bus master error interrupt in the LCDIF master mode.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_CLR, 1, 25, 0x0> BM_ERROR_IRQ;                        // This bit is set to indicate that an interrupt is requested by the LCDIF block
    // 0b0..No Interrupt Request Pending.
    // 0b1..Interrupt Request Pending.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_CLR, 1, 24, 0x0> RECOVER_ON_UNDERFLOW;
    // Set this bit to enable the LCDIF block to recover in the next field/frame if there was an underflow in the
    //     current field/frame
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_CLR, 1, 23, 0x0> INTERLACE_FIELDS;
    // Set this bit if it is required that the LCDIF block fetches odd lines in one field and even lines in the
    //     other field
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_CLR, 1, 22, 0x0> START_INTERLACE_FROM_SECOND_FIELD;
    // The default is to grab the odd lines first and then the even lines
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_CLR, 1, 21, 0x0> FIFO_CLEAR;                          // Set this bit to clear all the data in the latency FIFO (LFIFO), TXFIFO and the RXFIFO.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_CLR, 1, 20, 0x0> IRQ_ON_ALTERNATE_FIELDS;
    // If this bit is set, the LCDIF block will assert the cur_frame_done interrupt only on alternate fields,
    //     otherwise it will issue the interrupt on both odd and even field
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_CLR, 4, 16, 0x0> BYTE_PACKING_FORMAT;                 // This bitfield is used to show which data bytes in a 32-bit word are valid
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_CLR, 1, 15, 0x0> OVERFLOW_IRQ_EN;                     // This bit is set to enable an overflow interrupt in the TXFIFO in the write mode.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_CLR, 1, 14, 0x0> UNDERFLOW_IRQ_EN;                    // This bit is set to enable an underflow interrupt in the TXFIFO in the write mode.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_CLR, 1, 13, 0x0> CUR_FRAME_DONE_IRQ_EN;
    // This bit is set to 1 enable an interrupt every time the hardware enters in the vertical blanking state
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_CLR, 1, 12, 0x0> VSYNC_EDGE_IRQ_EN;
    // This bit is set to enable an interrupt every time the hardware encounters the leading VSYNC edge in the VSYNC
    //     and DOTCLK modes, or the beginning of every field in DVI mode
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_CLR, 1, 11, 0x0> OVERFLOW_IRQ;                        // This bit is set to indicate that an interrupt is requested by the LCDIF block
    // 0b0..No Interrupt Request Pending.
    // 0b1..Interrupt Request Pending.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_CLR, 1, 10, 0x0> UNDERFLOW_IRQ;                       // This bit is set to indicate that an interrupt is requested by the LCDIF block
    // 0b0..No Interrupt Request Pending.
    // 0b1..Interrupt Request Pending.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_CLR, 1,  9, 0x0> CUR_FRAME_DONE_IRQ;                  // This bit is set to indicate that an interrupt is requested by the LCDIF block
    // 0b0..No Interrupt Request Pending.
    // 0b1..Interrupt Request Pending.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_CLR, 1,  8, 0x0> VSYNC_EDGE_IRQ;                      // This bit is set to indicate that an interrupt is requested by the LCDIF block
    // 0b0..No Interrupt Request Pending.
    // 0b1..Interrupt Request Pending.
}  // namespace CTRL1_CLR

// LCDIF General Control1 Register
namespace CTRL1_TOG {
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_TOG, 1, 31, 0x0> IMAGE_DATA_SELECT;                   // Command Mode MIPI image data select bit
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_TOG, 1, 30, 0x0> CS_OUT_SELECT;                       // This bit is CS0/CS1 valid select signals
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_TOG, 1, 26, 0x0> BM_ERROR_IRQ_EN;                     // This bit is set to enable bus master error interrupt in the LCDIF master mode.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_TOG, 1, 25, 0x0> BM_ERROR_IRQ;                        // This bit is set to indicate that an interrupt is requested by the LCDIF block
    // 0b0..No Interrupt Request Pending.
    // 0b1..Interrupt Request Pending.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_TOG, 1, 24, 0x0> RECOVER_ON_UNDERFLOW;
    // Set this bit to enable the LCDIF block to recover in the next field/frame if there was an underflow in the
    //     current field/frame
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_TOG, 1, 23, 0x0> INTERLACE_FIELDS;
    // Set this bit if it is required that the LCDIF block fetches odd lines in one field and even lines in the
    //     other field
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_TOG, 1, 22, 0x0> START_INTERLACE_FROM_SECOND_FIELD;
    // The default is to grab the odd lines first and then the even lines
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_TOG, 1, 21, 0x0> FIFO_CLEAR;                          // Set this bit to clear all the data in the latency FIFO (LFIFO), TXFIFO and the RXFIFO.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_TOG, 1, 20, 0x0> IRQ_ON_ALTERNATE_FIELDS;
    // If this bit is set, the LCDIF block will assert the cur_frame_done interrupt only on alternate fields,
    //     otherwise it will issue the interrupt on both odd and even field
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_TOG, 4, 16, 0x0> BYTE_PACKING_FORMAT;                 // This bitfield is used to show which data bytes in a 32-bit word are valid
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_TOG, 1, 15, 0x0> OVERFLOW_IRQ_EN;                     // This bit is set to enable an overflow interrupt in the TXFIFO in the write mode.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_TOG, 1, 14, 0x0> UNDERFLOW_IRQ_EN;                    // This bit is set to enable an underflow interrupt in the TXFIFO in the write mode.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_TOG, 1, 13, 0x0> CUR_FRAME_DONE_IRQ_EN;
    // This bit is set to 1 enable an interrupt every time the hardware enters in the vertical blanking state
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_TOG, 1, 12, 0x0> VSYNC_EDGE_IRQ_EN;
    // This bit is set to enable an interrupt every time the hardware encounters the leading VSYNC edge in the VSYNC
    //     and DOTCLK modes, or the beginning of every field in DVI mode
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_TOG, 1, 11, 0x0> OVERFLOW_IRQ;                        // This bit is set to indicate that an interrupt is requested by the LCDIF block
    // 0b0..No Interrupt Request Pending.
    // 0b1..Interrupt Request Pending.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_TOG, 1, 10, 0x0> UNDERFLOW_IRQ;                       // This bit is set to indicate that an interrupt is requested by the LCDIF block
    // 0b0..No Interrupt Request Pending.
    // 0b1..Interrupt Request Pending.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_TOG, 1,  9, 0x0> CUR_FRAME_DONE_IRQ;                  // This bit is set to indicate that an interrupt is requested by the LCDIF block
    // 0b0..No Interrupt Request Pending.
    // 0b1..Interrupt Request Pending.
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL1_TOG, 1,  8, 0x0> VSYNC_EDGE_IRQ;                      // This bit is set to indicate that an interrupt is requested by the LCDIF block
    // 0b0..No Interrupt Request Pending.
    // 0b1..Interrupt Request Pending.
}  // namespace CTRL1_TOG

// LCDIF General Control2 Register
namespace CTRL2 {
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL2, 3, 21> OUTSTANDING_REQS;
    // This bitfield indicates the maximum number of outstanding transactions that LCDIF should request when it is
    //     acting as a bus master
    // 0b000..REQ_1
    // 0b001..REQ_2
    // 0b010..REQ_4
    // 0b011..REQ_8
    // 0b100..REQ_16
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL2, 1, 20> BURST_LEN_8;
    // By default, when the LCDIF is in the bus master mode, it will issue AXI bursts of length 16 (except when in
    //     packed 24 bpp mode, it will issue bursts of length 15)
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL2, 3, 16> ODD_LINE_PATTERN;   // This field determines the order of the RGB components of each pixel in ODD lines (line numbers 1,3,5,
    // 0b000..RGB
    // 0b001..RBG
    // 0b010..GBR
    // 0b011..GRB
    // 0b100..BRG
    // 0b101..BGR
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL2, 3, 12> EVEN_LINE_PATTERN;  // This field determines the order of the RGB components of each pixel in EVEN lines (line numbers 2,4,6,
    // 0b000..RGB
    // 0b001..RBG
    // 0b010..GBR
    // 0b011..GRB
    // 0b100..BRG
    // 0b101..BGR
}  // namespace CTRL2

// LCDIF General Control2 Register
namespace CTRL2_SET {
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL2_SET, 3, 21, 0x0> OUTSTANDING_REQS;
    // This bitfield indicates the maximum number of outstanding transactions that LCDIF should request when it is
    //     acting as a bus master
    // 0b000..REQ_1
    // 0b001..REQ_2
    // 0b010..REQ_4
    // 0b011..REQ_8
    // 0b100..REQ_16
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL2_SET, 1, 20, 0x0> BURST_LEN_8;
    // By default, when the LCDIF is in the bus master mode, it will issue AXI bursts of length 16 (except when in
    //     packed 24 bpp mode, it will issue bursts of length 15)
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL2_SET, 3, 16, 0x0> ODD_LINE_PATTERN;   // This field determines the order of the RGB components of each pixel in ODD lines (line numbers 1,3,5,
    // 0b000..RGB
    // 0b001..RBG
    // 0b010..GBR
    // 0b011..GRB
    // 0b100..BRG
    // 0b101..BGR
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL2_SET, 3, 12, 0x0> EVEN_LINE_PATTERN;  // This field determines the order of the RGB components of each pixel in EVEN lines (line numbers 2,4,6,
    // 0b000..RGB
    // 0b001..RBG
    // 0b010..GBR
    // 0b011..GRB
    // 0b100..BRG
    // 0b101..BGR
}  // namespace CTRL2_SET

// LCDIF General Control2 Register
namespace CTRL2_CLR {
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL2_CLR, 3, 21, 0x0> OUTSTANDING_REQS;
    // This bitfield indicates the maximum number of outstanding transactions that LCDIF should request when it is
    //     acting as a bus master
    // 0b000..REQ_1
    // 0b001..REQ_2
    // 0b010..REQ_4
    // 0b011..REQ_8
    // 0b100..REQ_16
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL2_CLR, 1, 20, 0x0> BURST_LEN_8;
    // By default, when the LCDIF is in the bus master mode, it will issue AXI bursts of length 16 (except when in
    //     packed 24 bpp mode, it will issue bursts of length 15)
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL2_CLR, 3, 16, 0x0> ODD_LINE_PATTERN;   // This field determines the order of the RGB components of each pixel in ODD lines (line numbers 1,3,5,
    // 0b000..RGB
    // 0b001..RBG
    // 0b010..GBR
    // 0b011..GRB
    // 0b100..BRG
    // 0b101..BGR
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL2_CLR, 3, 12, 0x0> EVEN_LINE_PATTERN;  // This field determines the order of the RGB components of each pixel in EVEN lines (line numbers 2,4,6,
    // 0b000..RGB
    // 0b001..RBG
    // 0b010..GBR
    // 0b011..GRB
    // 0b100..BRG
    // 0b101..BGR
}  // namespace CTRL2_CLR

// LCDIF General Control2 Register
namespace CTRL2_TOG {
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL2_TOG, 3, 21, 0x0> OUTSTANDING_REQS;
    // This bitfield indicates the maximum number of outstanding transactions that LCDIF should request when it is
    //     acting as a bus master
    // 0b000..REQ_1
    // 0b001..REQ_2
    // 0b010..REQ_4
    // 0b011..REQ_8
    // 0b100..REQ_16
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL2_TOG, 1, 20, 0x0> BURST_LEN_8;
    // By default, when the LCDIF is in the bus master mode, it will issue AXI bursts of length 16 (except when in
    //     packed 24 bpp mode, it will issue bursts of length 15)
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL2_TOG, 3, 16, 0x0> ODD_LINE_PATTERN;   // This field determines the order of the RGB components of each pixel in ODD lines (line numbers 1,3,5,
    // 0b000..RGB
    // 0b001..RBG
    // 0b010..GBR
    // 0b011..GRB
    // 0b100..BRG
    // 0b101..BGR
constexpr LCDIF_Reg<&LCDIF_Layout::CTRL2_TOG, 3, 12, 0x0> EVEN_LINE_PATTERN;  // This field determines the order of the RGB components of each pixel in EVEN lines (line numbers 2,4,6,
    // 0b000..RGB
    // 0b001..RBG
    // 0b010..GBR
    // 0b011..GRB
    // 0b100..BRG
    // 0b101..BGR
}  // namespace CTRL2_TOG

// LCDIF Horizontal and Vertical Valid Data Count Register
namespace TRANSFER_COUNT {
constexpr LCDIF_Reg<&LCDIF_Layout::TRANSFER_COUNT, 16, 16> V_COUNT;  // Number of horizontal lines per frame which contain valid data
constexpr LCDIF_Reg<&LCDIF_Layout::TRANSFER_COUNT, 16,  0> H_COUNT;  // Total valid data (pixels) in each horizontal line
}  // namespace TRANSFER_COUNT

// LCD Interface Current Buffer Address Register
namespace CUR_BUF {
constexpr LCDIF_Reg<&LCDIF_Layout::CUR_BUF, 32, 0> ADDR;  // Address of the current frame being transmitted by LCDIF.
}  // namespace CUR_BUF

// LCD Interface Next Buffer Address Register
namespace NEXT_BUF {
constexpr LCDIF_Reg<&LCDIF_Layout::NEXT_BUF, 32, 0> ADDR;  // Address of the next frame that will be transmitted by LCDIF.
}  // namespace NEXT_BUF

// LCDIF VSYNC Mode and Dotclk Mode Control Register0
namespace VDCTRL0 {
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0,  1, 28> ENABLE_PRESENT;
    // Setting this bit to 1 will make the hardware generate the ENABLE signal in the DOTCLK mode, thereby making it
    //     the true RGB interface along with the remaining three signals VSYNC, HSYNC and DOTCLK
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0,  1, 27> VSYNC_POL;
    // Default 0 active low during VSYNC_PULSE_WIDTH time and will be high during the rest of the VSYNC period
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0,  1, 26> HSYNC_POL;
    // Default 0 active low during HSYNC_PULSE_WIDTH time and will be high during the rest of the HSYNC period
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0,  1, 25> DOTCLK_POL;
    // Default is data launched at negative edge of DOTCLK and captured at positive edge
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0,  1, 24> ENABLE_POL;
    // Default 0 active low during valid data transfer on each horizontal line.
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0,  1, 21> VSYNC_PERIOD_UNIT;
    // Default 0 for counting VSYNC_PERIOD in terms of DISPLAY CLOCK (pix_clk) cycles
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0,  1, 20> VSYNC_PULSE_WIDTH_UNIT;
    // Default 0 for counting VSYNC_PULSE_WIDTH in terms of DISPLAY CLOCK (pix_clk) cycles
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0,  1, 19> HALF_LINE;
    // Setting this bit to 1 will make the total VSYNC period equal to the VSYNC_PERIOD field plus half the
    //     HORIZONTAL_PERIOD field (i
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0,  1, 18> HALF_LINE_MODE;
    // When this bit is 0, the first field (VSYNC period) will end in half a horizontal line and the second field
    //     will begin with half a horizontal line
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0, 18,  0> VSYNC_PULSE_WIDTH;  // Number of units for which VSYNC signal is active
}  // namespace VDCTRL0

// LCDIF VSYNC Mode and Dotclk Mode Control Register0
namespace VDCTRL0_SET {
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_SET,  1, 28, 0x0> ENABLE_PRESENT;
    // Setting this bit to 1 will make the hardware generate the ENABLE signal in the DOTCLK mode, thereby making it
    //     the true RGB interface along with the remaining three signals VSYNC, HSYNC and DOTCLK
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_SET,  1, 27, 0x0> VSYNC_POL;
    // Default 0 active low during VSYNC_PULSE_WIDTH time and will be high during the rest of the VSYNC period
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_SET,  1, 26, 0x0> HSYNC_POL;
    // Default 0 active low during HSYNC_PULSE_WIDTH time and will be high during the rest of the HSYNC period
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_SET,  1, 25, 0x0> DOTCLK_POL;
    // Default is data launched at negative edge of DOTCLK and captured at positive edge
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_SET,  1, 24, 0x0> ENABLE_POL;
    // Default 0 active low during valid data transfer on each horizontal line.
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_SET,  1, 21, 0x0> VSYNC_PERIOD_UNIT;
    // Default 0 for counting VSYNC_PERIOD in terms of DISPLAY CLOCK (pix_clk) cycles
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_SET,  1, 20, 0x0> VSYNC_PULSE_WIDTH_UNIT;
    // Default 0 for counting VSYNC_PULSE_WIDTH in terms of DISPLAY CLOCK (pix_clk) cycles
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_SET,  1, 19, 0x0> HALF_LINE;
    // Setting this bit to 1 will make the total VSYNC period equal to the VSYNC_PERIOD field plus half the
    //     HORIZONTAL_PERIOD field (i
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_SET,  1, 18, 0x0> HALF_LINE_MODE;
    // When this bit is 0, the first field (VSYNC period) will end in half a horizontal line and the second field
    //     will begin with half a horizontal line
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_SET, 18,  0, 0x0> VSYNC_PULSE_WIDTH;  // Number of units for which VSYNC signal is active
}  // namespace VDCTRL0_SET

// LCDIF VSYNC Mode and Dotclk Mode Control Register0
namespace VDCTRL0_CLR {
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_CLR,  1, 28, 0x0> ENABLE_PRESENT;
    // Setting this bit to 1 will make the hardware generate the ENABLE signal in the DOTCLK mode, thereby making it
    //     the true RGB interface along with the remaining three signals VSYNC, HSYNC and DOTCLK
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_CLR,  1, 27, 0x0> VSYNC_POL;
    // Default 0 active low during VSYNC_PULSE_WIDTH time and will be high during the rest of the VSYNC period
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_CLR,  1, 26, 0x0> HSYNC_POL;
    // Default 0 active low during HSYNC_PULSE_WIDTH time and will be high during the rest of the HSYNC period
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_CLR,  1, 25, 0x0> DOTCLK_POL;
    // Default is data launched at negative edge of DOTCLK and captured at positive edge
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_CLR,  1, 24, 0x0> ENABLE_POL;
    // Default 0 active low during valid data transfer on each horizontal line.
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_CLR,  1, 21, 0x0> VSYNC_PERIOD_UNIT;
    // Default 0 for counting VSYNC_PERIOD in terms of DISPLAY CLOCK (pix_clk) cycles
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_CLR,  1, 20, 0x0> VSYNC_PULSE_WIDTH_UNIT;
    // Default 0 for counting VSYNC_PULSE_WIDTH in terms of DISPLAY CLOCK (pix_clk) cycles
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_CLR,  1, 19, 0x0> HALF_LINE;
    // Setting this bit to 1 will make the total VSYNC period equal to the VSYNC_PERIOD field plus half the
    //     HORIZONTAL_PERIOD field (i
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_CLR,  1, 18, 0x0> HALF_LINE_MODE;
    // When this bit is 0, the first field (VSYNC period) will end in half a horizontal line and the second field
    //     will begin with half a horizontal line
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_CLR, 18,  0, 0x0> VSYNC_PULSE_WIDTH;  // Number of units for which VSYNC signal is active
}  // namespace VDCTRL0_CLR

// LCDIF VSYNC Mode and Dotclk Mode Control Register0
namespace VDCTRL0_TOG {
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_TOG,  1, 28, 0x0> ENABLE_PRESENT;
    // Setting this bit to 1 will make the hardware generate the ENABLE signal in the DOTCLK mode, thereby making it
    //     the true RGB interface along with the remaining three signals VSYNC, HSYNC and DOTCLK
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_TOG,  1, 27, 0x0> VSYNC_POL;
    // Default 0 active low during VSYNC_PULSE_WIDTH time and will be high during the rest of the VSYNC period
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_TOG,  1, 26, 0x0> HSYNC_POL;
    // Default 0 active low during HSYNC_PULSE_WIDTH time and will be high during the rest of the HSYNC period
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_TOG,  1, 25, 0x0> DOTCLK_POL;
    // Default is data launched at negative edge of DOTCLK and captured at positive edge
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_TOG,  1, 24, 0x0> ENABLE_POL;
    // Default 0 active low during valid data transfer on each horizontal line.
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_TOG,  1, 21, 0x0> VSYNC_PERIOD_UNIT;
    // Default 0 for counting VSYNC_PERIOD in terms of DISPLAY CLOCK (pix_clk) cycles
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_TOG,  1, 20, 0x0> VSYNC_PULSE_WIDTH_UNIT;
    // Default 0 for counting VSYNC_PULSE_WIDTH in terms of DISPLAY CLOCK (pix_clk) cycles
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_TOG,  1, 19, 0x0> HALF_LINE;
    // Setting this bit to 1 will make the total VSYNC period equal to the VSYNC_PERIOD field plus half the
    //     HORIZONTAL_PERIOD field (i
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_TOG,  1, 18, 0x0> HALF_LINE_MODE;
    // When this bit is 0, the first field (VSYNC period) will end in half a horizontal line and the second field
    //     will begin with half a horizontal line
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL0_TOG, 18,  0, 0x0> VSYNC_PULSE_WIDTH;  // Number of units for which VSYNC signal is active
}  // namespace VDCTRL0_TOG

// LCDIF VSYNC Mode and Dotclk Mode Control Register1
namespace VDCTRL1 {
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL1, 32, 0> VSYNC_PERIOD;  // Total number of units between two positive or two negative edges of the VSYNC signal
}  // namespace VDCTRL1

// LCDIF VSYNC Mode and Dotclk Mode Control Register2
namespace VDCTRL2 {
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL2, 14, 18> HSYNC_PULSE_WIDTH;  // Number of DISPLAY CLOCK (pix_clk) cycles for which HSYNC signal is active.
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL2, 18,  0> HSYNC_PERIOD;       // Total number of DISPLAY CLOCK (pix_clk) cycles between two positive or two negative edges of the HSYNC signal
}  // namespace VDCTRL2

// LCDIF VSYNC Mode and Dotclk Mode Control Register3
namespace VDCTRL3 {
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL3,  1, 29> MUX_SYNC_SIGNALS;
    // When this bit is set, the LCDIF block will internally mux HSYNC with LCD_D14, DOTCLK with LCD_D13 and ENABLE
    //     with LCD_D12, otherwise these signals will go out on separate pins
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL3,  1, 28> VSYNC_ONLY;
    // This bit must be set to 1 in the VSYNC mode of operation, and 0 in the DOTCLK mode of operation.
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL3, 12, 16> HORIZONTAL_WAIT_CNT;
    // In the DOTCLK mode, wait for this number of clocks from falling edge (or rising if HSYNC_POL is 1) of HSYNC
    //     signal to account for horizontal back porch plus the number of DOTCLKs before the moving picture
    //     information begins
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL3, 16,  0> VERTICAL_WAIT_CNT;
    // In the VSYNC interface mode, wait for this number of DISPLAY CLOCK (pix_clk) cycles from the falling VSYNC
    //     edge (or rising if VSYNC_POL is 1) before starting LCD transactions and is applicable only if
    //     WAIT_FOR_VSYNC_EDGE is set
}  // namespace VDCTRL3

// LCDIF VSYNC Mode and Dotclk Mode Control Register4
namespace VDCTRL4 {
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL4,  3, 29> DOTCLK_DLY_SEL;
    // This bitfield selects the amount of time by which the DOTCLK signal should be delayed before coming out of
    //     the LCD_DOTCK pin
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL4,  1, 18> SYNC_SIGNALS_ON;
    // Set this field to 1 if the LCD controller requires that the VSYNC or VSYNC/HSYNC/DOTCLK control signals
    //     should be active at least one frame before the data transfers actually start and remain active at least
    //     one frame after the data transfers end
constexpr LCDIF_Reg<&LCDIF_Layout::VDCTRL4, 18,  0> DOTCLK_H_VALID_DATA_CNT;  // Total number of DISPLAY CLOCK (pix_clk) cycles on each horizontal line that carry valid data in DOTCLK mode
}  // namespace VDCTRL4

// Bus Master Error Status Register
namespace BM_ERROR_STAT {
constexpr LCDIF_Reg<&LCDIF_Layout::BM_ERROR_STAT, 32, 0> ADDR;  // Virtual address at which bus master error occurred.
}  // namespace BM_ERROR_STAT

// CRC Status Register
namespace CRC_STAT {
constexpr LCDIF_Reg<&LCDIF_Layout::CRC_STAT, 32, 0> CRC_VALUE;  // Calculated CRC value
}  // namespace CRC_STAT

// LCD Interface Status Register
namespace STAT {
constexpr LCDIF_Reg<&LCDIF_Layout::STAT, 1, 31> PRESENT;
    // 0: LCDIF not present on this product 1: LCDIF is present.
constexpr LCDIF_Reg<&LCDIF_Layout::STAT, 1, 30> DMA_REQ;       // Reflects the current state of the DMA Request line for the LCDIF
constexpr LCDIF_Reg<&LCDIF_Layout::STAT, 1, 29> LFIFO_FULL;    // Read only view of the signals that indicates LCD LFIFO is full.
constexpr LCDIF_Reg<&LCDIF_Layout::STAT, 1, 28> LFIFO_EMPTY;   // Read only view of the signals that indicates LCD LFIFO is empty.
constexpr LCDIF_Reg<&LCDIF_Layout::STAT, 1, 27> TXFIFO_FULL;   // Read only view of the signals that indicates LCD TXFIFO is full.
constexpr LCDIF_Reg<&LCDIF_Layout::STAT, 1, 26> TXFIFO_EMPTY;  // Read only view of the signals that indicates LCD TXFIFO is empty.
constexpr LCDIF_Reg<&LCDIF_Layout::STAT, 9,  0> LFIFO_COUNT;   // Read only view of the current count in Latency buffer (LFIFO).
}  // namespace STAT

// LCDIF Pigeon Mode Control0 Register
namespace PIGEONCTRL0 {
constexpr LCDIF_Reg<&LCDIF_Layout::PIGEONCTRL0, 12, 16> LD_PERIOD;  // Period of pclk counter during LD phase
constexpr LCDIF_Reg<&LCDIF_Layout::PIGEONCTRL0, 12,  0> FD_PERIOD;  // Period of line counter during FD phase
}  // namespace PIGEONCTRL0

// LCDIF Pigeon Mode Control0 Register
namespace PIGEONCTRL0_SET {
constexpr LCDIF_Reg<&LCDIF_Layout::PIGEONCTRL0_SET, 12, 16, 0x0> LD_PERIOD;  // Period of pclk counter during LD phase
constexpr LCDIF_Reg<&LCDIF_Layout::PIGEONCTRL0_SET, 12,  0, 0x0> FD_PERIOD;  // Period of line counter during FD phase
}  // namespace PIGEONCTRL0_SET

// LCDIF Pigeon Mode Control0 Register
namespace PIGEONCTRL0_CLR {
constexpr LCDIF_Reg<&LCDIF_Layout::PIGEONCTRL0_CLR, 12, 16, 0x0> LD_PERIOD;  // Period of pclk counter during LD phase
constexpr LCDIF_Reg<&LCDIF_Layout::PIGEONCTRL0_CLR, 12,  0, 0x0> FD_PERIOD;  // Period of line counter during FD phase
}  // namespace PIGEONCTRL0_CLR

// LCDIF Pigeon Mode Control0 Register
namespace PIGEONCTRL0_TOG {
constexpr LCDIF_Reg<&LCDIF_Layout::PIGEONCTRL0_TOG, 12, 16, 0x0> LD_PERIOD;  // Period of pclk counter during LD phase
constexpr LCDIF_Reg<&LCDIF_Layout::PIGEONCTRL0_TOG, 12,  0, 0x0> FD_PERIOD;  // Period of line counter during FD phase
}  // namespace PIGEONCTRL0_TOG

// LCDIF Pigeon Mode Control1 Register
namespace PIGEONCTRL1 {
constexpr LCDIF_Reg<&LCDIF_Layout::PIGEONCTRL1, 12, 16> FRAME_CNT_CYCLES;  // Max cycles of frame counter
constexpr LCDIF_Reg<&LCDIF_Layout::PIGEONCTRL1, 12,  0> FRAME_CNT_PERIOD;  // Period of frame counter
}  // namespace PIGEONCTRL1

// LCDIF Pigeon Mode Control1 Register
namespace PIGEONCTRL1_SET {
constexpr LCDIF_Reg<&LCDIF_Layout::PIGEONCTRL1_SET, 12, 16, 0x0> FRAME_CNT_CYCLES;  // Max cycles of frame counter
constexpr LCDIF_Reg<&LCDIF_Layout::PIGEONCTRL1_SET, 12,  0, 0x0> FRAME_CNT_PERIOD;  // Period of frame counter
}  // namespace PIGEONCTRL1_SET

// LCDIF Pigeon Mode Control1 Register
namespace PIGEONCTRL1_CLR {
constexpr LCDIF_Reg<&LCDIF_Layout::PIGEONCTRL1_CLR, 12, 16, 0x0> FRAME_CNT_CYCLES;  // Max cycles of frame counter
constexpr LCDIF_Reg<&LCDIF_Layout::PIGEONCTRL1_CLR, 12,  0, 0x0> FRAME_CNT_PERIOD;  // Period of frame counter
}  // namespace PIGEONCTRL1_CLR

// LCDIF Pigeon Mode Control1 Register
namespace PIGEONCTRL1_TOG {
constexpr LCDIF_Reg<&LCDIF_Layout::PIGEONCTRL1_TOG, 12, 16, 0x0> FRAME_CNT_CYCLES;  // Max cycles of frame counter
constexpr LCDIF_Reg<&LCDIF_Layout::PIGEONCTRL1_TOG, 12,  0, 0x0> FRAME_CNT_PERIOD;  // Period of frame counter
}  // namespace PIGEONCTRL1_TOG

// LCDIF Pigeon Mode Control2 Register
namespace PIGEONCTRL2 {
constexpr LCDIF_Reg<&LCDIF_Layout::PIGEONCTRL2, 1, 1> PIGEON_CLK_GATE;  // Pigeon mode dot clock gate enable
constexpr LCDIF_Reg<&LCDIF_Layout::PIGEONCTRL2, 1, 0> PIGEON_DATA_EN;   // Pigeon mode data enable
}  // namespace PIGEONCTRL2

// LCDIF Pigeon Mode Control2 Register
namespace PIGEONCTRL2_SET {
constexpr LCDIF_Reg<&LCDIF_Layout::PIGEONCTRL2_SET, 1, 1, 0x0> PIGEON_CLK_GATE;  // Pigeon mode dot clock gate enable
constexpr LCDIF_Reg<&LCDIF_Layout::PIGEONCTRL2_SET, 1, 0, 0x0> PIGEON_DATA_EN;   // Pigeon mode data enable
}  // namespace PIGEONCTRL2_SET

// LCDIF Pigeon Mode Control2 Register
namespace PIGEONCTRL2_CLR {
constexpr LCDIF_Reg<&LCDIF_Layout::PIGEONCTRL2_CLR, 1, 1, 0x0> PIGEON_CLK_GATE;  // Pigeon mode dot clock gate enable
constexpr LCDIF_Reg<&LCDIF_Layout::PIGEONCTRL2_CLR, 1, 0, 0x0> PIGEON_DATA_EN;   // Pigeon mode data enable
}  // namespace PIGEONCTRL2_CLR

// LCDIF Pigeon Mode Control2 Register
namespace PIGEONCTRL2_TOG {
constexpr LCDIF_Reg<&LCDIF_Layout::PIGEONCTRL2_TOG, 1, 1, 0x0> PIGEON_CLK_GATE;  // Pigeon mode dot clock gate enable
constexpr LCDIF_Reg<&LCDIF_Layout::PIGEONCTRL2_TOG, 1, 0, 0x0> PIGEON_DATA_EN;   // Pigeon mode data enable
}  // namespace PIGEONCTRL2_TOG

// Look Up Table Control Register
namespace LUT_CTRL {
constexpr LCDIF_Reg<&LCDIF_Layout::LUT_CTRL, 1, 0> LUT_BYPASS;  // Setting this bit will bypass the LUT memory resource completely
}  // namespace LUT_CTRL

// Lookup Table 0 Index Register
namespace LUT0_ADDR {
constexpr LCDIF_Reg<&LCDIF_Layout::LUT0_ADDR, 8, 0> ADDR;  // LUT indexed address pointer
}  // namespace LUT0_ADDR

// Lookup Table 0 Data Register
namespace LUT0_DATA {
constexpr LCDIF_Reg<&LCDIF_Layout::LUT0_DATA, 32, 0> DATA;
    // Writing this field will load 4 bytes, aligned to four byte boundaries, of
    // data indexed by the ADDR field of the REG_LUT_CTRL register
}  // namespace LUT0_DATA

// Lookup Table 1 Index Register
namespace LUT1_ADDR {
constexpr LCDIF_Reg<&LCDIF_Layout::LUT1_ADDR, 8, 0> ADDR;  // LUT indexed address pointer
}  // namespace LUT1_ADDR

// Lookup Table 1 Data Register
namespace LUT1_DATA {
constexpr LCDIF_Reg<&LCDIF_Layout::LUT1_DATA, 32, 0> DATA;
    // Writing this field will load 4 bytes, aligned to four byte boundaries, of
    // data indexed by the ADDR field of the REG_LUT_CTRL register
}  // namespace LUT1_DATA

template <size_t Index,
          typename = std::enable_if_t<(Index < kLCDIF_PIGEON_count)>>
constexpr uintptr_t PigeonBase() {
  return kLCDIF_base + offsetof(LCDIF_Layout, PIGEON) +
         Index*sizeof(LCDIF_Layout::PIGEON_Layout);
}

template <size_t Index, auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false>
using PIGEON_Reg =
    regs::Reg32<PigeonBase<Index>(), LCDIF_Layout::PIGEON_Layout,
                Member, 0, Bits, Shift, AssignMask, WriteOnly>;

namespace PIGEON {

// Panel Interface Signal Generator Register
namespace PIGEON_0 {
template <size_t Index>
constexpr PIGEON_Reg<Index, &LCDIF_Layout::PIGEON_Layout::PIGEON_0,  8, 24> STATE_MASK;
    // state_mask = (FS|FB|FD|FE) and (LS|LB|LD|LE) , select any combination of scan states as reference point for
    //     local counter to start ticking
    // 0b00000001..FRAME SYNC
    // 0b00000010..FRAME BEGIN
    // 0b00000100..FRAME DATA
    // 0b00001000..FRAME END
    // 0b00010000..LINE SYNC
    // 0b00100000..LINE BEGIN
    // 0b01000000..LINE DATA
    // 0b10000000..LINE END
template <size_t Index>
constexpr PIGEON_Reg<Index, &LCDIF_Layout::PIGEON_Layout::PIGEON_0, 12, 12> MASK_CNT;
    // When the global counter selected through MASK_CNT_SEL matches value in this reg, pigeon local counter start
    //     ticking
template <size_t Index>
constexpr PIGEON_Reg<Index, &LCDIF_Layout::PIGEON_Layout::PIGEON_0,  4,  8> MASK_CNT_SEL;  // select global counters as mask condition, use together with MASK_CNT
    // 0b0000..pclk counter within one hscan state
    // 0b0001..pclk cycle within one hscan state
    // 0b0010..line counter within one vscan state
    // 0b0011..line cycle within one vscan state
    // 0b0100..frame counter
    // 0b0101..frame cycle
    // 0b0110..horizontal counter (pclk counter within one line )
    // 0b0111..vertical counter (line counter within one frame)
template <size_t Index>
constexpr PIGEON_Reg<Index, &LCDIF_Layout::PIGEON_Layout::PIGEON_0,  4,  4> OFFSET;        // offset on pclk unit
template <size_t Index>
constexpr PIGEON_Reg<Index, &LCDIF_Layout::PIGEON_Layout::PIGEON_0,  2,  2> INC_SEL;       // Event to incrment local counter
    // 0b00..pclk
    // 0b01..Line start pulse
    // 0b10..Frame start pulse
    // 0b11..Use another signal as tick event
template <size_t Index>
constexpr PIGEON_Reg<Index, &LCDIF_Layout::PIGEON_Layout::PIGEON_0,  1,  1> POL;           // Polarity of signal output
    // 0b0..Normal Signal (Active high)
    // 0b1..Inverted signal (Active low)
template <size_t Index>
constexpr PIGEON_Reg<Index, &LCDIF_Layout::PIGEON_Layout::PIGEON_0,  1,  0> EN;            // Enable pigeon Mode on this signal
}  // namespace PIGEON_0

// Panel Interface Signal Generator Register
namespace PIGEON_1 {
template <size_t Index>
constexpr PIGEON_Reg<Index, &LCDIF_Layout::PIGEON_Layout::PIGEON_1, 16, 16> CLR_CNT;  // Deassert signal output when counter match this value
    // 0b0000000000000000..Keep active until mask off
template <size_t Index>
constexpr PIGEON_Reg<Index, &LCDIF_Layout::PIGEON_Layout::PIGEON_1, 16,  0> SET_CNT;  // Assert signal output when counter match this value
    // 0b0000000000000000..Start as active
}  // namespace PIGEON_1

// Panel Interface Signal Generator Register
namespace PIGEON_2 {
template <size_t Index>
constexpr PIGEON_Reg<Index, &LCDIF_Layout::PIGEON_Layout::PIGEON_2, 5, 4> SIG_ANOTHER;  // Select another signal for logic operation or as mask or counter tick event
    // 0b00000..Keep active until mask off
template <size_t Index>
constexpr PIGEON_Reg<Index, &LCDIF_Layout::PIGEON_Layout::PIGEON_2, 4, 0> SIG_LOGIC;    // Logic operation with another signal: DIS/AND/OR/COND
    // 0b0000..No logic operation
    // 0b0001..sigout = sig_another AND this_sig
    // 0b0010..sigout = sig_another OR this_sig
    // 0b0011..mask = sig_another AND other_masks
}  // namespace PIGEON_2

}  // namespace PIGEON

}  // namespace LCDIF

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
