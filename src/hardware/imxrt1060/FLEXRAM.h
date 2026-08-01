// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// FLEXRAM.h defines all the FLEXRAM registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the FlexRAM (FLEXRAM) registers.
//
// Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_FLEXRAM.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct FLEXRAM_Layout {
  volatile uint32_t TCM_CTRL;                          /**< TCM CRTL Register, offset: 0x0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t INT_STATUS;                        /**< Interrupt Status Register, offset: 0x10 */
  volatile uint32_t INT_STAT_EN;                       /**< Interrupt Status Enable Register, offset: 0x14 */
  volatile uint32_t INT_SIG_EN;                        /**< Interrupt Enable Register, offset: 0x18 */
};

constexpr size_t    kFLEXRAM_size = 0x1C;
constexpr uintptr_t kFLEXRAM_base = 0x400B0000;

namespace FLEXRAM {
constexpr regs::RegGroup<FLEXRAM_Layout, kFLEXRAM_size, kFLEXRAM_base> group;
}  // namespace FLEXRAM

namespace FLEXRAM {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>()>
using FLEXRAM_Reg =
    regs::Reg32<kFLEXRAM_base, FLEXRAM_Layout, Member, 0, Bits, Shift,
                AssignMask>;

// TCM CRTL Register
namespace TCM_CTRL {
constexpr FLEXRAM_Reg<&FLEXRAM_Layout::TCM_CTRL, 1, 2> FORCE_CLK_ON;  // Force RAM Clock Always On
constexpr FLEXRAM_Reg<&FLEXRAM_Layout::TCM_CTRL, 1, 1> TCM_RWAIT_EN;  // TCM Read Wait Mode Enable
    // 0b0..TCM read fast mode: Read RAM accesses are expected to be finished in 1-cycle.
    // 0b1..TCM read wait mode: Read RAM accesses are expected to be finished in 2-cycles.
constexpr FLEXRAM_Reg<&FLEXRAM_Layout::TCM_CTRL, 1, 0> TCM_WWAIT_EN;  // TCM Write Wait Mode Enable
    // 0b0..TCM write fast mode: Write RAM accesses are expected to be finished in 1-cycle.
    // 0b1..TCM write wait mode: Write RAM accesses are expected to be finished in 2-cycles.
}  // namespace TCM_CTRL

// Interrupt Status Register
namespace INT_STATUS {
constexpr FLEXRAM_Reg<&FLEXRAM_Layout::INT_STATUS, 1, 5, 0x0> OCRAM_ERR_STATUS;  // OCRAM Access Error Status
    // 0b0..OCRAM access error does not happen
    // 0b1..OCRAM access error happens.
constexpr FLEXRAM_Reg<&FLEXRAM_Layout::INT_STATUS, 1, 4, 0x0> DTCM_ERR_STATUS;   // DTCM Access Error Status
    // 0b0..DTCM access error does not happen
    // 0b1..DTCM access error happens.
constexpr FLEXRAM_Reg<&FLEXRAM_Layout::INT_STATUS, 1, 3, 0x0> ITCM_ERR_STATUS;   // ITCM Access Error Status
    // 0b0..ITCM access error does not happen
    // 0b1..ITCM access error happens.
}  // namespace INT_STATUS

// Interrupt Status Enable Register
namespace INT_STAT_EN {
constexpr FLEXRAM_Reg<&FLEXRAM_Layout::INT_STAT_EN, 1, 5> OCRAM_ERR_STAT_EN;  // OCRAM Access Error Status Enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr FLEXRAM_Reg<&FLEXRAM_Layout::INT_STAT_EN, 1, 4> DTCM_ERR_STAT_EN;   // DTCM Access Error Status Enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr FLEXRAM_Reg<&FLEXRAM_Layout::INT_STAT_EN, 1, 3> ITCM_ERR_STAT_EN;   // ITCM Access Error Status Enable
    // 0b0..Masked
    // 0b1..Enabled
}  // namespace INT_STAT_EN

// Interrupt Enable Register
namespace INT_SIG_EN {
constexpr FLEXRAM_Reg<&FLEXRAM_Layout::INT_SIG_EN, 1, 5> OCRAM_ERR_SIG_EN;  // OCRAM Access Error Interrupt Enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr FLEXRAM_Reg<&FLEXRAM_Layout::INT_SIG_EN, 1, 4> DTCM_ERR_SIG_EN;   // DTCM Access Error Interrupt Enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr FLEXRAM_Reg<&FLEXRAM_Layout::INT_SIG_EN, 1, 3> ITCM_ERR_SIG_EN;   // ITCM Access Error Interrupt Enable
    // 0b0..Masked
    // 0b1..Enabled
}  // namespace INT_SIG_EN

}  // namespace FLEXRAM

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
