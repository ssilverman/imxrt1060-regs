// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// CM7_MCM.h defines all the CM7_MCM registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "qindesign/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the ARM Cortex-M7 Miscellaneous Control Module
// (CM7_MCM) registers.
//
// Comments are from BSD-3-licensed NXP SDK sources and the NXP reference
// manual.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_CM7_MCM.h
// * https://github.com/nxp-mcuxpresso/mcux-soc-svd/blob/main/MIMXRT1062/MIMXRT1062.xml
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
// * i.MX RT1060 Processor Reference Manual, Rev. 4, chapter 28
struct CM7_MCM_Layout {
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[4];
  volatile uint32_t ISCR;                              /**< Interrupt Status and Control Register, offset: 0x10 */
};

constexpr size_t    kCM7_MCM_size = 0x14;
constexpr uintptr_t kCM7_MCM_base = 0xE008'0000;

namespace CM7_MCM {

constexpr regs::RegGroup<CM7_MCM_Layout, kCM7_MCM_size, kCM7_MCM_base> group;

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using CM7_MCM_Reg = regs::Reg32<kCM7_MCM_base, CM7_MCM_Layout, Member, 0, Bits,
                                Shift, AssignMask>;

// Interrupt Status and Control Register
namespace ISCR {
constexpr uint32_t kW1C = 0x0000'0020;

constexpr CM7_MCM_Reg<&CM7_MCM_Layout::ISCR, 1, 31, regs::shiftedMask32<1, 31>() | kW1C> FIDCE;  // FPU Input Denormal Interrupt Enable
    // 0b0..Disable interrupt.
    // 0b1..Enable interrupt.
constexpr CM7_MCM_Reg<&CM7_MCM_Layout::ISCR, 1, 28, regs::shiftedMask32<1, 28>() | kW1C> FIXCE;  // FPU Inexact Interrupt Enable
    // 0b0..Disable interrupt.
    // 0b1..Enable interrupt.
constexpr CM7_MCM_Reg<&CM7_MCM_Layout::ISCR, 1, 27, regs::shiftedMask32<1, 27>() | kW1C> FUFCE;  // FPU Underflow Interrupt Enable
    // 0b0..Disable interrupt.
    // 0b1..Enable interrupt.
constexpr CM7_MCM_Reg<&CM7_MCM_Layout::ISCR, 1, 26, regs::shiftedMask32<1, 26>() | kW1C> FOFCE;  // FPU Overflow Interrupt Enable
    // 0b0..Disable interrupt.
    // 0b1..Enable interrupt.
constexpr CM7_MCM_Reg<&CM7_MCM_Layout::ISCR, 1, 25, regs::shiftedMask32<1, 25>() | kW1C> FDZCE;  // FPU Divide-by-Zero Interrupt Enable
    // 0b0..Disable interrupt.
    // 0b1..Enable interrupt.
constexpr CM7_MCM_Reg<&CM7_MCM_Layout::ISCR, 1, 24, regs::shiftedMask32<1, 24>() | kW1C> FIOCE;  // FPU Invalid Operation Interrupt Enable
    // 0b0..Disable interrupt.
    // 0b1..Enable interrupt.
constexpr CM7_MCM_Reg<&CM7_MCM_Layout::ISCR, 1, 21, regs::shiftedMask32<1, 21>() | kW1C> WABE;   // TCM Write Abort Interrupt Enable
    // 0b0..Disable interrupt.
    // 0b1..Enable interrupt.
constexpr CM7_MCM_Reg<regs::constify(&CM7_MCM_Layout::ISCR), 1, 15> FIDC;                        // FPU Input Denormal Interrupt Status
    // This read-only field mirrors FPSCR[IDC] and remains set until software clears that FPSCR bit.
    // 0b0..No interrupt.
    // 0b1..Interrupt occurred.
constexpr CM7_MCM_Reg<regs::constify(&CM7_MCM_Layout::ISCR), 1, 12> FIXC;                        // FPU Inexact Interrupt Status
    // This read-only field mirrors FPSCR[IXC] and remains set until software clears that FPSCR bit.
    // 0b0..No interrupt.
    // 0b1..Interrupt occurred.
constexpr CM7_MCM_Reg<regs::constify(&CM7_MCM_Layout::ISCR), 1, 11> FUFC;                        // FPU Underflow Interrupt Status
    // This read-only field mirrors FPSCR[UFC] and remains set until software clears that FPSCR bit.
    // 0b0..No interrupt.
    // 0b1..Interrupt occurred.
constexpr CM7_MCM_Reg<regs::constify(&CM7_MCM_Layout::ISCR), 1, 10> FOFC;                        // FPU Overflow Interrupt Status
    // This read-only field mirrors FPSCR[OFC] and remains set until software clears that FPSCR bit.
    // 0b0..No interrupt.
    // 0b1..Interrupt occurred.
constexpr CM7_MCM_Reg<regs::constify(&CM7_MCM_Layout::ISCR), 1,  9> FDZC;                        // FPU Divide-by-Zero Interrupt Status
    // This read-only field mirrors FPSCR[DZC] and remains set until software clears that FPSCR bit.
    // 0b0..No interrupt.
    // 0b1..Interrupt occurred.
constexpr CM7_MCM_Reg<regs::constify(&CM7_MCM_Layout::ISCR), 1,  8> FIOC;                        // FPU Invalid Operation Interrupt Status
    // This read-only field mirrors FPSCR[IOC] and remains set until software clears that FPSCR bit.
    // 0b0..No interrupt.
    // 0b1..Interrupt occurred.
constexpr CM7_MCM_Reg<regs::constify(&CM7_MCM_Layout::ISCR), 1,  6> WABSO;                       // Write Abort on Slave Overrun
    // This read-only field indicates another write abort occurred before software retrieved the original event information.
    // Clearing WABS also clears this field.
    // 0b0..No write abort overrun.
    // 0b1..Write abort overrun occurred.
constexpr CM7_MCM_Reg<&CM7_MCM_Layout::ISCR, 1,  5, kW1C> WABS;                                  // Write Abort on Slave
    // This field indicates that a write abort occurred on the AHBS interface.
    // Write 1 to clear WABS and WABSO.
    // 0b0..No abort.
    // 0b1..Abort.
}  // namespace ISCR

}  // namespace CM7_MCM

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
