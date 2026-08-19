// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// SEMC.h defines all the SEMC registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>
#include <type_traits>

#include "qindesign/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Size of Registers Arrays
constexpr size_t kSEMC_BR_count = 9;

// Structure type to access the Smart External Memory Controller (SEMC) registers.
//
// Comments are from BSD-3-licensed NXP SDK sources and the NXP reference
// manual.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_SEMC.h
// * https://github.com/nxp-mcuxpresso/mcux-soc-svd/blob/main/MIMXRT1062/MIMXRT1062.xml
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
// * i.MX RT1060 Processor Reference Manual, Rev. 4, chapter 25
struct SEMC_Layout {
  volatile uint32_t MCR;                               /**< Module Control Register, offset: 0x0 */
  volatile uint32_t IOCR;                              /**< IO MUX Control Register, offset: 0x4 */
  volatile uint32_t BMCR0;                             /**< Bus (AXI) Master Control Register 0, offset: 0x8 */
  volatile uint32_t BMCR1;                             /**< Bus (AXI) Master Control Register 1, offset: 0xC */
  volatile uint32_t BR[kSEMC_BR_count];                 /**< Base Register 0..Base Register 8, array offset: 0x10, array step: 0x4 */
  volatile uint32_t DLLCR;                             /**< DLL Control Register, offset: 0x34 */
  volatile uint32_t INTEN;                             /**< Interrupt Enable Register, offset: 0x38 */
  volatile uint32_t INTR;                              /**< Interrupt Register, offset: 0x3C */
  volatile uint32_t SDRAMCR0;                          /**< SDRAM Control Register 0, offset: 0x40 */
  volatile uint32_t SDRAMCR1;                          /**< SDRAM Control Register 1, offset: 0x44 */
  volatile uint32_t SDRAMCR2;                          /**< SDRAM Control Register 2, offset: 0x48 */
  volatile uint32_t SDRAMCR3;                          /**< SDRAM Control Register 3, offset: 0x4C */
  volatile uint32_t NANDCR0;                           /**< NAND Control Register 0, offset: 0x50 */
  volatile uint32_t NANDCR1;                           /**< NAND Control Register 1, offset: 0x54 */
  volatile uint32_t NANDCR2;                           /**< NAND Control Register 2, offset: 0x58 */
  volatile uint32_t NANDCR3;                           /**< NAND Control Register 3, offset: 0x5C */
  volatile uint32_t NORCR0;                            /**< NOR Control Register 0, offset: 0x60 */
  volatile uint32_t NORCR1;                            /**< NOR Control Register 1, offset: 0x64 */
  volatile uint32_t NORCR2;                            /**< NOR Control Register 2, offset: 0x68 */
  volatile uint32_t NORCR3;                            /**< NOR Control Register 3, offset: 0x6C */
  volatile uint32_t SRAMCR0;                           /**< SRAM Control Register 0, offset: 0x70 */
  volatile uint32_t SRAMCR1;                           /**< SRAM Control Register 1, offset: 0x74 */
  volatile uint32_t SRAMCR2;                           /**< SRAM Control Register 2, offset: 0x78 */
  uint32_t SRAMCR3;                                    /**< SRAM Control Register 3, offset: 0x7C */
  volatile uint32_t DBICR0;                            /**< DBI-B Control Register 0, offset: 0x80 */
  volatile uint32_t DBICR1;                            /**< DBI-B Control Register 1, offset: 0x84 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[2];
  volatile uint32_t IPCR0;                             /**< IP Command Control Register 0, offset: 0x90 */
  volatile uint32_t IPCR1;                             /**< IP Command Control Register 1, offset: 0x94 */
  volatile uint32_t IPCR2;                             /**< IP Command Control Register 2, offset: 0x98 */
  volatile uint32_t IPCMD;                             /**< IP Command Register, offset: 0x9C */
  volatile uint32_t IPTXDAT;                           /**< TX DATA Register, offset: 0xA0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  const volatile uint32_t IPRXDAT;                     /**< RX DATA Register, offset: 0xB0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  const volatile uint32_t STS0;                        /**< Status Register 0, offset: 0xC0 */
  uint32_t STS1;                                       /**< Status Register 1, offset: 0xC4 */
  const volatile uint32_t STS2;                        /**< Status Register 2, offset: 0xC8 */
  uint32_t STS3;                                       /**< Status Register 3, offset: 0xCC */
  uint32_t STS4;                                       /**< Status Register 4, offset: 0xD0 */
  uint32_t STS5;                                       /**< Status Register 5, offset: 0xD4 */
  uint32_t STS6;                                       /**< Status Register 6, offset: 0xD8 */
  uint32_t STS7;                                       /**< Status Register 7, offset: 0xDC */
  uint32_t STS8;                                       /**< Status Register 8, offset: 0xE0 */
  uint32_t STS9;                                       /**< Status Register 9, offset: 0xE4 */
  uint32_t STS10;                                      /**< Status Register 10, offset: 0xE8 */
  uint32_t STS11;                                      /**< Status Register 11, offset: 0xEC */
  const volatile uint32_t STS12;                       /**< Status Register 12, offset: 0xF0 */
  const volatile uint32_t STS13;                       /**< Status Register 13, offset: 0xF4 */
  uint32_t STS14;                                      /**< Status Register 14, offset: 0xF8 */
  uint32_t STS15;                                      /**< Status Register 15, offset: 0xFC */
};

constexpr size_t    kSEMC_size = 0x100;
constexpr uintptr_t kSEMC_base = 0x402F'0000;

namespace SEMC {

constexpr regs::RegGroup<SEMC_Layout, kSEMC_size, kSEMC_base> group;

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>(),
          auto AssignSet = 0, bool WriteOnly = false>
using SEMC_Reg = regs::Reg32<kSEMC_base, SEMC_Layout, Member, 0, Bits, Shift,
                             AssignMask, AssignSet, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>(),
          auto AssignSet = 0, bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kSEMC_BR_count)>>
using BR_Reg = regs::Reg32<kSEMC_base, SEMC_Layout, &SEMC_Layout::BR, Index,
                           Bits, Shift, AssignMask, AssignSet, WriteOnly>;

// Module Control Register
namespace MCR {
constexpr SEMC_Reg<&SEMC_Layout::MCR, 5, 24> BTO;    // Bus timeout cycles
    // The AXI bus timeout is 255 * 2^BTO clock cycles.
    // 0b00000..255*1
    // 0b00001..255*2
    // 0b11111..255*2^31
constexpr SEMC_Reg<&SEMC_Layout::MCR, 8, 16> CTO;    // Command Execution timeout cycles
    // Zero selects 256 * 1024 command-execution clock cycles; otherwise the timeout is CTO * 1024 clock cycles.
constexpr SEMC_Reg<&SEMC_Layout::MCR, 1,  7> WPOL1;  // R/B# polarity for NAND device
    // 0b0..R/B# polarity is not changed.
    // 0b1..R/B# polarity is inverted.
constexpr SEMC_Reg<&SEMC_Layout::MCR, 1,  6> WPOL0;  // WAIT/RDY polarity for SRAM/NOR
    // 0b0..WAIT/RDY polarity is not changed.
    // 0b1..WAIT/RDY polarity is inverted.
constexpr SEMC_Reg<&SEMC_Layout::MCR, 1,  2> DQSMD;  // DQS (read strobe) mode
    // 0b0..Dummy read strobe loopbacked internally
    // 0b1..Dummy read strobe loopbacked from DQS pad
constexpr SEMC_Reg<&SEMC_Layout::MCR, 1,  1> MDIS;   // Module Disable
    // 0b0..Module enabled
    // 0b1..Module disabled
constexpr SEMC_Reg<&SEMC_Layout::MCR, 1,  0> SWRST;  // Software Reset
    // 0b0..No reset
    // 0b1..Reset
}  // namespace MCR

// IO MUX Control Register
namespace IOCR {
constexpr SEMC_Reg<&SEMC_Layout::IOCR, 1, 25> MUX_CLKX1;  // SEMC_CLKX1 function selection
    // 0b0..NOR clock
    // 0b1..SRAM clock
constexpr SEMC_Reg<&SEMC_Layout::IOCR, 1, 24> MUX_CLKX0;  // SEMC_CLKX0 function selection
    // 0b0..NOR clock
    // 0b1..SRAM clock
constexpr SEMC_Reg<&SEMC_Layout::IOCR, 3, 15> MUX_RDY;    // SEMC_RDY function selection
    // 0b000..NAND R/B# input
    // 0b001..SDRAM CS1
    // 0b010..SDRAM CS2
    // 0b011..SDRAM CS3
    // 0b100..NOR CE#
    // 0b101..SRAM CE#
    // 0b110..DBI CSX
    // 0b111..Reserved
constexpr SEMC_Reg<&SEMC_Layout::IOCR, 3, 12> MUX_CSX3;   // SEMC_CSX3 output selection
    // 0b000..Reserved
    // 0b001..SDRAM CS1
    // 0b010..SDRAM CS2
    // 0b011..SDRAM CS3
    // 0b100..NAND CE#
    // 0b101..NOR CE#
    // 0b110..SRAM CE#
    // 0b111..DBI CSX
constexpr SEMC_Reg<&SEMC_Layout::IOCR, 3,  9> MUX_CSX2;   // SEMC_CSX2 output selection
    // 0b000..Reserved
    // 0b001..SDRAM CS1
    // 0b010..SDRAM CS2
    // 0b011..SDRAM CS3
    // 0b100..NAND CE#
    // 0b101..NOR CE#
    // 0b110..SRAM CE#
    // 0b111..DBI CSX
constexpr SEMC_Reg<&SEMC_Layout::IOCR, 3,  6> MUX_CSX1;   // SEMC_CSX1 output selection
    // 0b000..Reserved
    // 0b001..SDRAM CS1
    // 0b010..SDRAM CS2
    // 0b011..SDRAM CS3
    // 0b100..NAND CE#
    // 0b101..NOR CE#
    // 0b110..SRAM CE#
    // 0b111..DBI CSX
constexpr SEMC_Reg<&SEMC_Layout::IOCR, 3,  3> MUX_CSX0;   // SEMC_CSX0 output selection
    // 0b000..Reserved
    // 0b001..SDRAM CS1
    // 0b010..SDRAM CS2
    // 0b011..SDRAM CS3
    // 0b100..NAND CE#
    // 0b101..NOR CE#
    // 0b110..SRAM CE#
    // 0b111..DBI CSX
constexpr SEMC_Reg<&SEMC_Layout::IOCR, 3,  0> MUX_A8;     // SEMC_ADDR08 output selection
    // 0b000..SDRAM Address bit 8 (A8) or NOR/SRAM Address bit 24 (A24) in ADMUX 16bit mode
    // 0b001..NAND CE#
    // 0b010..NOR CE#
    // 0b011..SRAM CE#
    // 0b100..DBI CSX
    // 0b101-0b111..SDRAM Address bit 8 (A8) or NOR/SRAM Address bit 24 (A24) in ADMUX 16bit mode
}  // namespace IOCR

// Bus (AXI) Master Control Register 0
namespace BMCR0 {
constexpr SEMC_Reg<&SEMC_Layout::BMCR0, 8, 16> WRWS;  // Weight of slave hit with Read/Write Switch
constexpr SEMC_Reg<&SEMC_Layout::BMCR0, 8,  8> WSH;   // Weight of Slave Hit without read/write switch
constexpr SEMC_Reg<&SEMC_Layout::BMCR0, 4,  4> WAGE;  // Weight of AGE
constexpr SEMC_Reg<&SEMC_Layout::BMCR0, 4,  0> WQOS;  // Weight of QOS
}  // namespace BMCR0

// Bus (AXI) Master Control Register 1
namespace BMCR1 {
constexpr SEMC_Reg<&SEMC_Layout::BMCR1, 8, 24> WBR;   // Weight of Bank Rotation
constexpr SEMC_Reg<&SEMC_Layout::BMCR1, 8, 16> WRWS;  // Weight of slave hit without Read/Write Switch
constexpr SEMC_Reg<&SEMC_Layout::BMCR1, 8,  8> WPH;   // Weight of Page Hit
constexpr SEMC_Reg<&SEMC_Layout::BMCR1, 4,  4> WAGE;  // Weight of AGE
constexpr SEMC_Reg<&SEMC_Layout::BMCR1, 4,  0> WQOS;  // Weight of QOS
}  // namespace BMCR1

// Base Register 0..Base Register 8
namespace BR {
template <size_t Index>
constexpr BR_Reg<Index, 20, 12> BA;   // Base Address
template <size_t Index>
constexpr BR_Reg<Index,  5,  1> MS;   // Memory size
    // 0b00000..4KB
    // 0b00001..8KB
    // 0b00010..16KB
    // 0b00011..32KB
    // 0b00100..64KB
    // 0b00101..128KB
    // 0b00110..256KB
    // 0b00111..512KB
    // 0b01000..1MB
    // 0b01001..2MB
    // 0b01010..4MB
    // 0b01011..8MB
    // 0b01100..16MB
    // 0b01101..32MB
    // 0b01110..64MB
    // 0b01111..128MB
    // 0b10000..256MB
    // 0b10001..512MB
    // 0b10010..1GB
    // 0b10011..2GB
    // 0b10100-0b11111..4GB
template <size_t Index>
constexpr BR_Reg<Index,  1,  0> VLD;  // Valid
    // 0b0..The memory is invalid, can not be accessed.
    // 0b1..The memory is valid, can be accessed.

namespace vals {
constexpr regs::RegValue32<20, 12> BA;
constexpr regs::RegValue32< 5,  1> MS;
constexpr regs::RegValue32< 1,  0> VLD;
}  // namespace vals
}  // namespace BR

// DLL Control Register
namespace DLLCR {
constexpr SEMC_Reg<&SEMC_Layout::DLLCR, 6, 9> OVRDVAL;       // Override Value
constexpr SEMC_Reg<&SEMC_Layout::DLLCR, 1, 8> OVRDEN;        // Override Enable
    // 0b0..The delay cell number is not overridden.
    // 0b1..The delay cell number is overridden.
constexpr SEMC_Reg<&SEMC_Layout::DLLCR, 4, 3> SLVDLYTARGET;  // Delay Target for Slave
constexpr SEMC_Reg<&SEMC_Layout::DLLCR, 1, 1> DLLRESET;      // DLL Reset
    // 0b0..DLL is not reset.
    // 0b1..DLL is reset.
constexpr SEMC_Reg<&SEMC_Layout::DLLCR, 1, 0> DLLEN;         // DLL calibration enable
    // 0b0..DLL calibration is disabled.
    // 0b1..DLL calibration is enabled.
}  // namespace DLLCR

// Interrupt Enable Register
namespace INTEN {
constexpr SEMC_Reg<&SEMC_Layout::INTEN, 1, 5> NDNOPENDEN;   // NAND no pending AXI access interrupt enable
    // 0b0..Interrupt is disabled
    // 0b1..Interrupt is enabled
constexpr SEMC_Reg<&SEMC_Layout::INTEN, 1, 4> NDPAGEENDEN;  // NAND page end interrupt enable
    // 0b0..Interrupt is disabled
    // 0b1..Interrupt is enabled
constexpr SEMC_Reg<&SEMC_Layout::INTEN, 1, 3> AXIBUSERREN;  // AXI bus error interrupt enable
    // 0b0..Interrupt is disabled
    // 0b1..Interrupt is enabled
constexpr SEMC_Reg<&SEMC_Layout::INTEN, 1, 2> AXICMDERREN;  // AXI command error interrupt enable
    // 0b0..Interrupt is disabled
    // 0b1..Interrupt is enabled
constexpr SEMC_Reg<&SEMC_Layout::INTEN, 1, 1> IPCMDERREN;   // IP command error interrupt enable
    // 0b0..Interrupt is disabled
    // 0b1..Interrupt is enabled
constexpr SEMC_Reg<&SEMC_Layout::INTEN, 1, 0> IPCMDDONEEN;  // IP command done interrupt enable
    // 0b0..Interrupt is disabled
    // 0b1..Interrupt is enabled
}  // namespace INTEN

// Interrupt Register
namespace INTR {
constexpr SEMC_Reg<&SEMC_Layout::INTR, 1, 5, 0x0> NDNOPEND;   // NAND no pending AXI write transaction interrupt
    // Writing 1 clears this field.
    // 0b0..At least one NAND AXI write transaction is pending or no NAND write transaction is sent to the queue.
    // 0b1..All NAND AXI write pending transactions are finished.
constexpr SEMC_Reg<&SEMC_Layout::INTR, 1, 4, 0x0> NDPAGEEND;  // NAND page end interrupt
    // Writing 1 clears this field.
    // 0b0..The last address of main space in the NAND is not written by AXI command.
    // 0b1..The last address of main space in the NAND is written by AXI command.
constexpr SEMC_Reg<&SEMC_Layout::INTR, 1, 3, 0x0> AXIBUSERR;  // AXI bus error interrupt
    // Writing 1 clears this field.
    // 0b0..No AXI bus error.
    // 0b1..AXI bus error occurs.
constexpr SEMC_Reg<&SEMC_Layout::INTR, 1, 2, 0x0> AXICMDERR;  // AXI command error interrupt
    // Writing 1 clears this field.
    // 0b0..No AXI command error.
    // 0b1..AXI command error occurs.
constexpr SEMC_Reg<&SEMC_Layout::INTR, 1, 1, 0x0> IPCMDERR;   // IP command error done interrupt
    // Writing 1 clears this field.
    // 0b0..No IP command error.
    // 0b1..IP command error occurs.
constexpr SEMC_Reg<&SEMC_Layout::INTR, 1, 0, 0x0> IPCMDDONE;  // IP command normal done interrupt
    // Writing 1 clears this field.
    // 0b0..IP command is not done.
    // 0b1..IP command is done.
}  // namespace INTR

// SDRAM Control Register 0
namespace SDRAMCR0 {
constexpr SEMC_Reg<&SEMC_Layout::SDRAMCR0, 1, 14> BANK2;  // 2 Bank selection bit
    // 0b0..SDRAM device has 4 banks.
    // 0b1..SDRAM device has 2 banks.
constexpr SEMC_Reg<&SEMC_Layout::SDRAMCR0, 2, 10> CL;     // CAS Latency
    // 0b00..1
    // 0b01..1
    // 0b10..2
    // 0b11..3
constexpr SEMC_Reg<&SEMC_Layout::SDRAMCR0, 2,  8> COL;    // Column address bit number
    // 0b00..12
    // 0b01..11
    // 0b10..10
    // 0b11..9
constexpr SEMC_Reg<&SEMC_Layout::SDRAMCR0, 1,  7> COL8;   // Column 8 selection
    // 0b0..Column address bit number is decided by COL field.
    // 0b1..Column address bit number is 8. COL field is ignored.
constexpr SEMC_Reg<&SEMC_Layout::SDRAMCR0, 3,  4> BL;     // Burst Length
    // 0b000..1
    // 0b001..2
    // 0b010..4
    // 0b011..8
    // 0b100..8
    // 0b101..8
    // 0b110..8
    // 0b111..8
constexpr SEMC_Reg<&SEMC_Layout::SDRAMCR0, 1,  0> PS;     // Port Size
    // 0b0..8bit
    // 0b1..16bit
}  // namespace SDRAMCR0

// SDRAM Control Register 1
namespace SDRAMCR1 {
constexpr SEMC_Reg<&SEMC_Layout::SDRAMCR1, 4, 20> ACT2PRE;  // ACTIVE to PRECHARGE minimum time
constexpr SEMC_Reg<&SEMC_Layout::SDRAMCR1, 4, 16> CKEOFF;   // CKE off minimum time
constexpr SEMC_Reg<&SEMC_Layout::SDRAMCR1, 3, 13> WRC;      // WRITE recovery time
constexpr SEMC_Reg<&SEMC_Layout::SDRAMCR1, 5,  8> RFRC;     // REFRESH recovery time
constexpr SEMC_Reg<&SEMC_Layout::SDRAMCR1, 4,  4> ACT2RW;   // ACTIVE to READ/WRITE delay
constexpr SEMC_Reg<&SEMC_Layout::SDRAMCR1, 4,  0> PRE2ACT;  // PRECHARGE to ACTIVE/REFRESH command wait time
}  // namespace SDRAMCR1

// SDRAM Control Register 2
namespace SDRAMCR2 {
constexpr SEMC_Reg<&SEMC_Layout::SDRAMCR2, 8, 24> ITO;      // SDRAM idle timeout
    // 0b00000000..IDLE timeout period is 256*Prescale period.
    // 0b00000001-0b11111111..IDLE timeout period is ITO*Prescale period.
constexpr SEMC_Reg<&SEMC_Layout::SDRAMCR2, 8, 16> ACT2ACT;  // ACTIVE to ACTIVE delay
constexpr SEMC_Reg<&SEMC_Layout::SDRAMCR2, 8,  8> REF2REF;  // REFRESH to REFRESH delay
constexpr SEMC_Reg<&SEMC_Layout::SDRAMCR2, 8,  0> SRRC;     // SELF REFRESH recovery time
}  // namespace SDRAMCR2

// SDRAM Control Register 3
namespace SDRAMCR3 {
constexpr SEMC_Reg<&SEMC_Layout::SDRAMCR3, 8, 24> UT;        // Urgent refresh threshold
    // 0b00000000..256*(Prescaler period)
    // 0b00000001-0b11111111..UT*(Prescaler period)
constexpr SEMC_Reg<&SEMC_Layout::SDRAMCR3, 8, 16> RT;        // Refresh timer period
    // 0b00000000..(256+1)*(Prescaler period)
    // 0b00000001-0b11111111..(RT+1)*(Prescaler period)
constexpr SEMC_Reg<&SEMC_Layout::SDRAMCR3, 8,  8> PRESCALE;  // Prescaler period
    // 0b00000000..(256*16+1) clock cycles
    // 0b00000001-0b11111111..(PRESCALE*16+1) clock cycles
constexpr SEMC_Reg<&SEMC_Layout::SDRAMCR3, 3,  1> REBL;      // Refresh burst length
    // 0b000..1
    // 0b001..2
    // 0b010..3
    // 0b011..4
    // 0b100..5
    // 0b101..6
    // 0b110..7
    // 0b111..8
constexpr SEMC_Reg<&SEMC_Layout::SDRAMCR3, 1,  0> REN;       // Refresh enable
    // 0b0..The SEMC does not send AUTO REFRESH command automatically
    // 0b1..The SEMC sends AUTO REFRESH command automatically
}  // namespace SDRAMCR3

// NAND Control Register 0
namespace NANDCR0 {
constexpr SEMC_Reg<&SEMC_Layout::NANDCR0, 3, 8> COL;     // Column address bit number
    // 0b000..16
    // 0b001..15
    // 0b010..14
    // 0b011..13
    // 0b100..12
    // 0b101..11
    // 0b110..10
    // 0b111..9
constexpr SEMC_Reg<&SEMC_Layout::NANDCR0, 1, 7> EDO;     // EDO mode enabled
    // 0b0..EDO mode disabled
    // 0b1..EDO mode enabled
constexpr SEMC_Reg<&SEMC_Layout::NANDCR0, 3, 4> BL;      // Burst Length
    // 0b000..1
    // 0b001..2
    // 0b010..4
    // 0b011..8
    // 0b100..16
    // 0b101..32
    // 0b110..64
    // 0b111..64
constexpr SEMC_Reg<&SEMC_Layout::NANDCR0, 1, 1> SYNCEN;  // Synchronous Mode Enable
    // 0b0..Asynchronous mode is enabled.
    // 0b1..Synchronous mode is enabled.
constexpr SEMC_Reg<&SEMC_Layout::NANDCR0, 1, 0> PS;      // Port Size
    // 0b0..8bit
    // 0b1..16bit
}  // namespace NANDCR0

// NAND Control Register 1
namespace NANDCR1 {
constexpr SEMC_Reg<&SEMC_Layout::NANDCR1, 4, 28> CEITV;  // CE# interval time
constexpr SEMC_Reg<&SEMC_Layout::NANDCR1, 4, 24> TA;     // Turnaround time
constexpr SEMC_Reg<&SEMC_Layout::NANDCR1, 4, 20> REH;    // RE# high time
constexpr SEMC_Reg<&SEMC_Layout::NANDCR1, 4, 16> REL;    // RE# low time
constexpr SEMC_Reg<&SEMC_Layout::NANDCR1, 4, 12> WEH;    // WE# high time
constexpr SEMC_Reg<&SEMC_Layout::NANDCR1, 4,  8> WEL;    // WE# low time
constexpr SEMC_Reg<&SEMC_Layout::NANDCR1, 4,  4> CEH;    // CE# hold time
constexpr SEMC_Reg<&SEMC_Layout::NANDCR1, 4,  0> CES;    // CE# setup time
}  // namespace NANDCR1

// NAND Control Register 2
namespace NANDCR2 {
constexpr SEMC_Reg<&SEMC_Layout::NANDCR2, 6, 24> TWB;   // WE# high to busy time
constexpr SEMC_Reg<&SEMC_Layout::NANDCR2, 6, 18> TRR;   // Ready to RE# low time
constexpr SEMC_Reg<&SEMC_Layout::NANDCR2, 6, 12> TADL;  // Address cycle to data loading time
constexpr SEMC_Reg<&SEMC_Layout::NANDCR2, 6,  6> TRHW;  // RE# high to WE# low time
constexpr SEMC_Reg<&SEMC_Layout::NANDCR2, 6,  0> TWHR;  // WE# high to RE# low time
}  // namespace NANDCR2

// NAND Control Register 3
namespace NANDCR3 {
constexpr SEMC_Reg<&SEMC_Layout::NANDCR3, 4, 28> WDH;     // Write Data Hold time
constexpr SEMC_Reg<&SEMC_Layout::NANDCR3, 4, 24> WDS;     // Write Data Setup time
constexpr SEMC_Reg<&SEMC_Layout::NANDCR3, 4, 20> RDH;     // Read Data Hold time
constexpr SEMC_Reg<&SEMC_Layout::NANDCR3, 4, 16> RDS;     // Read Data Setup time
constexpr SEMC_Reg<&SEMC_Layout::NANDCR3, 1,  2> NDOPT3;  // NAND option bit 3
constexpr SEMC_Reg<&SEMC_Layout::NANDCR3, 1,  1> NDOPT2;  // NAND option bit 2
constexpr SEMC_Reg<&SEMC_Layout::NANDCR3, 1,  0> NDOPT1;  // NAND option bit 1
}  // namespace NANDCR3

// NOR Control Register 0
namespace NORCR0 {
constexpr SEMC_Reg<&SEMC_Layout::NORCR0, 4, 12> COL;     // Column Address bit width
    // 0b0000..12 Bits
    // 0b0001..11 Bits
    // 0b0010..10 Bits
    // 0b0011..9 Bits
    // 0b0100..8 Bits
    // 0b0101..7 Bits
    // 0b0110..6 Bits
    // 0b0111..5 Bits
    // 0b1000..4 Bits
    // 0b1001..3 Bits
    // 0b1010..2 Bits
    // 0b1011..12 Bits
    // 0b1100..12 Bits
    // 0b1101..12 Bits
    // 0b1110..12 Bits
    // 0b1111..12 Bits
constexpr SEMC_Reg<&SEMC_Layout::NORCR0, 1, 11> ADVH;    // ADV# level control during address hold state
    // 0b0..ADV# is high during address hold state.
    // 0b1..ADV# is low during address hold state.
constexpr SEMC_Reg<&SEMC_Layout::NORCR0, 1, 10> ADVP;    // ADV# Polarity
    // 0b0..ADV# is active low.
    // 0b1..ADV# is active high.
constexpr SEMC_Reg<&SEMC_Layout::NORCR0, 2,  8> AM;      // Address Mode
    // 0b00..Address/Data MUX mode (ADMUX)
    // 0b01..Advanced Address/Data MUX mode (AADM)
    // 0b10..Reserved
    // 0b11..Reserved
constexpr SEMC_Reg<&SEMC_Layout::NORCR0, 3,  4> BL;      // Burst Length
    // 0b000..1
    // 0b001..2
    // 0b010..4
    // 0b011..8
    // 0b100..16
    // 0b101..32
    // 0b110..64
    // 0b111..64
constexpr SEMC_Reg<&SEMC_Layout::NORCR0, 1,  1> SYNCEN;  // Synchronous Mode Enable
    // 0b0..Asynchronous mode is enabled.
    // 0b1..Synchronous mode is enabled. Only fixed latency mode is supported.
constexpr SEMC_Reg<&SEMC_Layout::NORCR0, 1,  0> PS;      // Port Size
    // 0b0..8bit
    // 0b1..16bit
}  // namespace NORCR0

// NOR Control Register 1
namespace NORCR1 {
constexpr SEMC_Reg<&SEMC_Layout::NORCR1, 4, 28> REH;  // RE high time
constexpr SEMC_Reg<&SEMC_Layout::NORCR1, 4, 24> REL;  // RE low time
constexpr SEMC_Reg<&SEMC_Layout::NORCR1, 4, 20> WEH;  // WE high time
constexpr SEMC_Reg<&SEMC_Layout::NORCR1, 4, 16> WEL;  // WE low time
constexpr SEMC_Reg<&SEMC_Layout::NORCR1, 4, 12> AH;   // Address hold time
constexpr SEMC_Reg<&SEMC_Layout::NORCR1, 4,  8> AS;   // Address setup time
constexpr SEMC_Reg<&SEMC_Layout::NORCR1, 4,  4> CEH;  // CE hold time
constexpr SEMC_Reg<&SEMC_Layout::NORCR1, 4,  0> CES;  // CE setup time
}  // namespace NORCR1

// NOR Control Register 2
namespace NORCR2 {
constexpr SEMC_Reg<&SEMC_Layout::NORCR2, 4, 28> RDH;    // Read hold time
constexpr SEMC_Reg<&SEMC_Layout::NORCR2, 4, 24> CEITV;  // CE# interval time
constexpr SEMC_Reg<&SEMC_Layout::NORCR2, 4, 20> RD;     // Read time
constexpr SEMC_Reg<&SEMC_Layout::NORCR2, 4, 16> LC;     // Latency count
constexpr SEMC_Reg<&SEMC_Layout::NORCR2, 4, 12> AWDH;   // Address to write data hold time
constexpr SEMC_Reg<&SEMC_Layout::NORCR2, 4,  8> TA;     // Turnaround time
}  // namespace NORCR2

// NOR Control Register 3
namespace NORCR3 {
constexpr SEMC_Reg<&SEMC_Layout::NORCR3, 4, 4> AHSR;  // Address hold time for SYNC read
constexpr SEMC_Reg<&SEMC_Layout::NORCR3, 4, 0> ASSR;  // Address setup time for SYNC read
}  // namespace NORCR3

// SRAM Control Register 0
namespace SRAMCR0 {
constexpr SEMC_Reg<&SEMC_Layout::SRAMCR0, 4, 12> COL;     // Column Address bit width
    // 0b0000..12 Bits
    // 0b0001..11 Bits
    // 0b0010..10 Bits
    // 0b0011..9 Bits
    // 0b0100..8 Bits
    // 0b0101..7 Bits
    // 0b0110..6 Bits
    // 0b0111..5 Bits
    // 0b1000..4 Bits
    // 0b1001..3 Bits
    // 0b1010..2 Bits
    // 0b1011..12 Bits
    // 0b1100..12 Bits
    // 0b1101..12 Bits
    // 0b1110..12 Bits
    // 0b1111..12 Bits
constexpr SEMC_Reg<&SEMC_Layout::SRAMCR0, 1, 11> ADVH;    // ADV# level control during address hold state
    // 0b0..ADV# is high during address hold state.
    // 0b1..ADV# is low during address hold state.
constexpr SEMC_Reg<&SEMC_Layout::SRAMCR0, 1, 10> ADVP;    // ADV# polarity
    // 0b0..ADV# is active low.
    // 0b1..ADV# is active high.
constexpr SEMC_Reg<&SEMC_Layout::SRAMCR0, 2,  8> AM;      // Address Mode
    // 0b00..Address/Data MUX mode (ADMUX)
    // 0b01..Advanced Address/Data MUX mode (AADM)
    // 0b10..Reserved
    // 0b11..Reserved
constexpr SEMC_Reg<&SEMC_Layout::SRAMCR0, 3,  4> BL;      // Burst Length
    // 0b000..1
    // 0b001..2
    // 0b010..4
    // 0b011..8
    // 0b100..16
    // 0b101..32
    // 0b110..64
    // 0b111..64
constexpr SEMC_Reg<&SEMC_Layout::SRAMCR0, 1,  1> SYNCEN;  // Synchronous Mode Enable
    // 0b0..Asynchronous mode is enabled.
    // 0b1..Synchronous mode is enabled. Only fixed latency mode is supported.
constexpr SEMC_Reg<&SEMC_Layout::SRAMCR0, 1,  0> PS;      // Port Size
    // 0b0..8bit
    // 0b1..16bit
}  // namespace SRAMCR0

// SRAM Control Register 1
namespace SRAMCR1 {
constexpr SEMC_Reg<&SEMC_Layout::SRAMCR1, 4, 28> REH;  // RE high time
constexpr SEMC_Reg<&SEMC_Layout::SRAMCR1, 4, 24> REL;  // RE low time
constexpr SEMC_Reg<&SEMC_Layout::SRAMCR1, 4, 20> WEH;  // WE high time
constexpr SEMC_Reg<&SEMC_Layout::SRAMCR1, 4, 16> WEL;  // WE low time
constexpr SEMC_Reg<&SEMC_Layout::SRAMCR1, 4, 12> AH;   // Address hold time
constexpr SEMC_Reg<&SEMC_Layout::SRAMCR1, 4,  8> AS;   // Address setup time
constexpr SEMC_Reg<&SEMC_Layout::SRAMCR1, 4,  4> CEH;  // CE hold time
constexpr SEMC_Reg<&SEMC_Layout::SRAMCR1, 4,  0> CES;  // CE setup time
}  // namespace SRAMCR1

// SRAM Control Register 2
namespace SRAMCR2 {
constexpr SEMC_Reg<&SEMC_Layout::SRAMCR2, 4, 28> RDH;    // Read hold time
constexpr SEMC_Reg<&SEMC_Layout::SRAMCR2, 4, 24> CEITV;  // CE# interval time
constexpr SEMC_Reg<&SEMC_Layout::SRAMCR2, 4, 20> RD;     // Read time
constexpr SEMC_Reg<&SEMC_Layout::SRAMCR2, 4, 16> LC;     // Latency count
constexpr SEMC_Reg<&SEMC_Layout::SRAMCR2, 4, 12> AWDH;   // Address to write data hold time
constexpr SEMC_Reg<&SEMC_Layout::SRAMCR2, 4,  8> TA;     // Turnaround time
constexpr SEMC_Reg<&SEMC_Layout::SRAMCR2, 4,  4> WDH;    // Write Data hold time
constexpr SEMC_Reg<&SEMC_Layout::SRAMCR2, 4,  0> WDS;    // Write Data setup time
}  // namespace SRAMCR2

// DBI-B Control Register 0
namespace DBICR0 {
constexpr SEMC_Reg<&SEMC_Layout::DBICR0, 4, 12> COL;  // Column Address bit width
    // 0b0000..12 Bits
    // 0b0001..11 Bits
    // 0b0010..10 Bits
    // 0b0011..9 Bits
    // 0b0100..8 Bits
    // 0b0101..7 Bits
    // 0b0110..6 Bits
    // 0b0111..5 Bits
    // 0b1000..4 Bits
    // 0b1001..3 Bits
    // 0b1010..2 Bits
    // 0b1011..12 Bits
    // 0b1100..12 Bits
    // 0b1101..12 Bits
    // 0b1110..12 Bits
    // 0b1111..12 Bits
constexpr SEMC_Reg<&SEMC_Layout::DBICR0, 3,  4> BL;   // Burst Length
    // 0b000..1
    // 0b001..2
    // 0b010..4
    // 0b011..8
    // 0b100..16
    // 0b101..32
    // 0b110..64
    // 0b111..64
constexpr SEMC_Reg<&SEMC_Layout::DBICR0, 1,  0> PS;   // Port Size
    // 0b0..8bit
    // 0b1..16bit
}  // namespace DBICR0

// DBI-B Control Register 1
namespace DBICR1 {
constexpr SEMC_Reg<&SEMC_Layout::DBICR1, 2, 30> REH2;   // RDX High Time bit [5:4]
constexpr SEMC_Reg<&SEMC_Layout::DBICR1, 2, 28> REL2;   // RDX Low Time bit [5:4]
constexpr SEMC_Reg<&SEMC_Layout::DBICR1, 4, 24> CEITV;  // CSX interval time
constexpr SEMC_Reg<&SEMC_Layout::DBICR1, 4, 20> REH;    // RDX High Time bit [3:0]
constexpr SEMC_Reg<&SEMC_Layout::DBICR1, 4, 16> REL;    // RDX Low Time bit [3:0]
constexpr SEMC_Reg<&SEMC_Layout::DBICR1, 4, 12> WEH;    // WRX High Time
constexpr SEMC_Reg<&SEMC_Layout::DBICR1, 4,  8> WEL;    // WRX Low Time
constexpr SEMC_Reg<&SEMC_Layout::DBICR1, 4,  4> CEH;    // CSX Hold Time
constexpr SEMC_Reg<&SEMC_Layout::DBICR1, 4,  0> CES;    // CSX Setup Time
}  // namespace DBICR1

// IP Command Control Register 0
namespace IPCR0 {
constexpr SEMC_Reg<&SEMC_Layout::IPCR0, 32, 0> SA;  // Slave address
}  // namespace IPCR0

// IP Command Control Register 1
namespace IPCR1 {
constexpr SEMC_Reg<&SEMC_Layout::IPCR1, 8, 8> NAND_EXT_ADDR;  // NAND Extended Address
constexpr SEMC_Reg<&SEMC_Layout::IPCR1, 3, 0> DATSZ;          // Data Size in Byte
    // 0b000..4
    // 0b001..1
    // 0b010..2
    // 0b011..3
    // 0b100..4
    // 0b101..4
    // 0b110..4
    // 0b111..4
}  // namespace IPCR1

// IP Command Control Register 2
namespace IPCR2 {
constexpr SEMC_Reg<&SEMC_Layout::IPCR2, 1, 3> BM3;  // Byte Mask for Byte 3 (IPTXDAT bit 31:24)
    // 0b0..Byte is unmasked
    // 0b1..Byte is masked
constexpr SEMC_Reg<&SEMC_Layout::IPCR2, 1, 2> BM2;  // Byte Mask for Byte 2 (IPTXDAT bit 23:16)
    // 0b0..Byte is unmasked
    // 0b1..Byte is masked
constexpr SEMC_Reg<&SEMC_Layout::IPCR2, 1, 1> BM1;  // Byte Mask for Byte 1 (IPTXDAT bit 15:8)
    // 0b0..Byte is unmasked
    // 0b1..Byte is masked
constexpr SEMC_Reg<&SEMC_Layout::IPCR2, 1, 0> BM0;  // Byte Mask for Byte 0 (IPTXDAT bit 7:0)
    // 0b0..Byte is unmasked
    // 0b1..Byte is masked
}  // namespace IPCR2

// IP Command Register
namespace IPCMD {
// TODO: Is this the correct way?
constexpr uint32_t kWO = regs::shiftedMask32<16, 16>();

constexpr uint32_t kKEY_All  = 0xA55A'0000;  // Key for all device types, including NAND
constexpr uint32_t kKEY_NAND = 0x5AA5'0000;  // Key for NAND only
    // The address is extended to 40-bit with the use of NAND_EXT_ADDR

constexpr SEMC_Reg<&SEMC_Layout::IPCMD, 16, 16, kWO, 0x0, true> KEY;  // This field should be written with 0xA55A when trigging an IP command for all device types
    // Note that writing this standalone will re-issue the current CMD
constexpr SEMC_Reg<regs::constify(&SEMC_Layout::IPCMD), 16,  0> CMD;  // SDRAM Commands

// Other commands:
//
// NOR Commands:
// * 0x2: Read
// * 0x3: Write
// * Others: Reserved
//
// SRAM Commands:
// * 0x2: Memory Array Read
// * 0x3: Memory Array Write
// * 0x4: Memory Register Read
// * 0x5: Memory Register Write
// * Others: Reserved
//
// DBI_B Commands:
// * 0x2: Read
// * 0x3: Write
// * Others: Reserved

// Versions where KEY also gets set
namespace keyed {
constexpr SEMC_Reg<&SEMC_Layout::IPCMD, 16, 0, 0x0, kKEY_all> CMD_all;    // SDRAM Commands:
    // 0x8: Read
    // 0x9: Write
    // 0xA: Mode Register Set
    // 0xB: Active
    // 0xC: Auto Refresh
    // 0xD: Self Refresh
    // 0xE: Precharge
    // 0xF: Precharge All
    // Others: Reserved
    //
    // Note: Self Refresh is sent to all SDRAM devices because they share the same SEMC_CLK pin
constexpr SEMC_Reg<&SEMC_Layout::IPCMD, 16, 0, 0x0, kKEY_NAND> CMD_NAND;  // NAND Commands:
    // Bit 15-8 (Command Code)
    //
    // Bit 7-4 (Address mode):
    // * 0x0: Colum and Row address(5 Byte-CA0/CA1/RA0/RA1/RA2)
    // * 0x1: Column address only (1 Byte-CA0)
    // * 0x2: Column address only (2 Byte-CA0/CA1)
    // * 0x3: Row address only (1 Byte-RA0)
    // * 0x4: Row address only (2 Byte-RA0/RA1)
    // * 0x5: Row address only (3 Byte-RA0/RA1/RA2)
    // * Others: Reserved
    //
    // Bit 3-0 (Command mode):
    // * 0x0: Command(0x05)-Address-Command-Read (Reserved for AXI Read)
    // * 0x1: Command(0x85)-Address-Write (Reserved for AXI Write)
    // * 0x2: Command
    // * 0x3: Command-Hold
    // * 0x4: Command-Address
    // * 0x5: Command-Address-Hold
    // * 0x6: Command-Address-Read
    // * 0x7: Command-Address-Write
    // * 0x8: Command-Read
    // * 0x9: Command-Write
    // * 0xA: Read
    // * 0xB: Write
    // * Others: Reserved
}  // namespace keyed
}  // namespace IPCMD

// TX DATA Register
namespace IPTXDAT {
constexpr SEMC_Reg<&SEMC_Layout::IPTXDAT, 32, 0> DAT;  // Data value to use for an IP write command
}  // namespace IPTXDAT

// RX DATA Register
namespace IPRXDAT {
constexpr SEMC_Reg<&SEMC_Layout::IPRXDAT, 32, 0> DAT;  // Data returned by device for an IP read command.
}  // namespace IPRXDAT

// Status Register 0
namespace STS0 {
constexpr SEMC_Reg<&SEMC_Layout::STS0, 1, 1> NARDY;  // Indicating NAND device Ready/WAIT# pin level.
    // 0b0..NAND device is not ready
    // 0b1..NAND device is ready
constexpr SEMC_Reg<&SEMC_Layout::STS0, 1, 0> IDLE;   // Indicating whether the SEMC is in idle state.
}  // namespace STS0

// Status Register 2
namespace STS2 {
constexpr SEMC_Reg<&SEMC_Layout::STS2, 1, 3> NDWRPEND;  // This field indicating whether there is pending AXI command (write) to NAND device.
    // 0b0..No pending
    // 0b1..Pending
}  // namespace STS2

// Status Register 12
namespace STS12 {
constexpr SEMC_Reg<&SEMC_Layout::STS12, 32, 0> NDADDR;  // This field indicating the last write address (AXI command) to NAND device (without base address in SEMC_BR4).
}  // namespace STS12

// Status Register 13
namespace STS13 {
constexpr SEMC_Reg<&SEMC_Layout::STS13, 6, 8> REFSEL;   // Sample clock reference delay line delay cell number selection.
constexpr SEMC_Reg<&SEMC_Layout::STS13, 6, 2> SLVSEL;   // Sample clock slave delay line delay cell number selection.
constexpr SEMC_Reg<&SEMC_Layout::STS13, 1, 1> REFLOCK;  // Sample clock reference delay line locked.
    // 0b0..Reference delay line is not locked.
    // 0b1..Reference delay line is locked.
constexpr SEMC_Reg<&SEMC_Layout::STS13, 1, 0> SLVLOCK;  // Sample clock slave delay line locked.
    // 0b0..Slave delay line is not locked.
    // 0b1..Slave delay line is locked.
}  // namespace STS13

}  // namespace SEMC

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
