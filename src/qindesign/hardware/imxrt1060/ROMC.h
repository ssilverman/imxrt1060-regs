// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// ROMC.h defines all the ROMC registers.
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
constexpr size_t kROMC_ROMPATCHD_count = 8;
constexpr size_t kROMC_ROMPATCHA_count = 16;

// Structure type to access the ROM Controller (ROMC) registers.
//
// Comments are from BSD-3-licensed NXP SDK sources.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_ROMC.h
// * https://github.com/nxp-mcuxpresso/mcux-soc-svd/blob/main/MIMXRT1062/MIMXRT1062.xml
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct ROMC_Layout {
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[53];
  volatile uint32_t ROMPATCHD[kROMC_ROMPATCHD_count];  /**< ROMC Data Registers, array offset: 0xD4, array step: 0x4 */
  volatile uint32_t ROMPATCHCNTL;                      /**< ROMC Control Register, offset: 0xF4 */
  uint32_t ROMPATCHENH;                                /**< ROMC Enable Register High, offset: 0xF8 */
  volatile uint32_t ROMPATCHENL;                       /**< ROMC Enable Register Low, offset: 0xFC */
  volatile uint32_t ROMPATCHA[kROMC_ROMPATCHA_count];  /**< ROMC Address Registers, array offset: 0x100, array step: 0x4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[50];
  volatile uint32_t ROMPATCHSR;                        /**< ROMC Status Register, offset: 0x208 */
};

constexpr size_t    kROMC_size = 0x20C;
constexpr uintptr_t kROMC_base = 0x4018'0000;

namespace ROMC {

constexpr regs::RegGroup<ROMC_Layout, kROMC_size, kROMC_base> group;

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>(),
          auto AssignSet = 0, bool WriteOnly = false>
using ROMC_Reg = regs::Reg32<kROMC_base, ROMC_Layout, Member, 0, Bits, Shift,
                             AssignMask, AssignSet, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>(),
          auto AssignSet = 0, bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kROMC_ROMPATCHD_count)>>
using ROMPATCHD_Reg =
    regs::Reg32<kROMC_base, ROMC_Layout, &ROMC_Layout::ROMPATCHD, Index, Bits,
                Shift, AssignMask, AssignSet, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>(),
          auto AssignSet = 0, bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kROMC_ROMPATCHA_count)>>
using ROMPATCHA_Reg =
    regs::Reg32<kROMC_base, ROMC_Layout, &ROMC_Layout::ROMPATCHA, Index, Bits,
                Shift, AssignMask, AssignSet, WriteOnly>;

// ROMC Data Registers
namespace ROMPATCHD {
template <size_t Index>
constexpr ROMPATCHD_Reg<Index, 32, 0> DATAX;  // Data Fix Registers - Stores the data used for 1-word data fix operations
}  // namespace ROMPATCHD

// ROMC Control Register
namespace ROMPATCHCNTL {
constexpr ROMC_Reg<&ROMC_Layout::ROMPATCHCNTL, 1, 29> DIS;      // ROMC Disable -- This bit, when set, disables all ROMC operations
    // 0b0..Does not affect any ROMC functions (default)
    // 0b1..Disable all ROMC functions: data fixing, and opcode patching
constexpr ROMC_Reg<&ROMC_Layout::ROMPATCHCNTL, 8,  0> DATAFIX;  // Data Fix Enable - Controls the use of the first 8 address comparators for 1-word data fix or for code patch routine
    // 0b00000000..Address comparator triggers a opcode patch
    // 0b00000001..Address comparator triggers a data fix
}  // namespace ROMPATCHCNTL

// ROMC Enable Register Low
namespace ROMPATCHENL {
constexpr ROMC_Reg<&ROMC_Layout::ROMPATCHENL, 16, 0> ENABLE;  // Enable Address Comparator - This bit enables the corresponding address comparator to trigger an event
    // 0b0000000000000000..Address comparator disabled
    // 0b0000000000000001..Address comparator enabled, ROMC will trigger a opcode patch or data fix event upon matching of the associated address
}  // namespace ROMPATCHENL

// ROMC Address Registers
namespace ROMPATCHA {
template <size_t Index>
constexpr ROMPATCHA_Reg<Index, 22, 1> ADDRX;   // Address Comparator Registers - Indicates the memory address to be watched
template <size_t Index>
constexpr ROMPATCHA_Reg<Index,  1, 0> THUMBX;  // THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an Arm opcode patch
    // 0b0..Arm patch
    // 0b1..THUMB patch (ignore if data fix)
}  // namespace ROMPATCHA

// ROMC Status Register
namespace ROMPATCHSR {
constexpr ROMC_Reg<&ROMC_Layout::ROMPATCHSR, 1, 17, 0x0> SW;                 // ROMC AHB Multiple Address Comparator matches Indicator - Indicates that multiple address comparator matches occurred
    // Writing 1 clears this field.
    // 0b0..no event or comparator collisions
    // 0b1..a collision has occurred
constexpr ROMC_Reg<regs::constify(&ROMC_Layout::ROMPATCHSR), 6,  0> SOURCE;  // ROMC Source Number - Binary encoding of the number of the address comparator which has an address match in the most recent patch event on ROMC AHB
    // 0b000000..Address Comparator 0 matched
    // 0b000001..Address Comparator 1 matched
    // 0b001111..Address Comparator 15 matched
}  // namespace ROMPATCHSR

}  // namespace ROMC

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
