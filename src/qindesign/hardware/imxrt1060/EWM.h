// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// EWM.h defines all the EWM registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "qindesign/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the External Watchdog Monitor (EWM) registers.
// EWM only supports 8-bit register accesses.
//
// Comments are from BSD-3-licensed NXP SDK sources and the NXP reference
// manual.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_EWM.h
// * https://github.com/nxp-mcuxpresso/mcux-soc-svd/blob/main/MIMXRT1062/MIMXRT1062.xml
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
// * i.MX RT1060 Processor Reference Manual, Rev. 4, chapter 59
struct EWM_Layout {
  volatile uint8_t CTRL;                               /**< Control Register, offset: 0x0 */
  volatile uint8_t SERV;                               /**< WORZ, Service Register, offset: 0x1 */
  volatile uint8_t CMPL;                               /**< RWONCE, Compare Low Register, offset: 0x2 */
  volatile uint8_t CMPH;                               /**< RWONCE, Compare High Register, offset: 0x3 */
  volatile uint8_t CLKCTRL;                            /**< RWONCE, Clock Control Register, offset: 0x4 */
  volatile uint8_t CLKPRESCALER;                       /**< RWONCE, Clock Prescaler Register, offset: 0x5 */
};

constexpr size_t    kEWM_size = 0x6;
constexpr uintptr_t kEWM_base = 0x400B'4000;

namespace EWM {

constexpr regs::RegGroup<EWM_Layout, kEWM_size, kEWM_base> group;

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask8<Bits, Shift>()>
using EWM_Reg =
    regs::Reg8<kEWM_base, EWM_Layout, Member, 0, Bits, Shift, AssignMask>;

// Control Register
// INEN, ASSIN, and EWMEN should be written as a group because of their
// write-once behaviour.
namespace CTRL {
constexpr EWM_Reg<&EWM_Layout::CTRL, 1, 3> INTEN;  // Interrupt Enable.
    // 0b0..Deasserts the interrupt request.
    // 0b1..Generates an interrupt request, when EWM_OUT_b is asserted.
constexpr EWM_Reg<&EWM_Layout::CTRL, 1, 2> INEN;   // Input Enable.
    // RWONCE
    // This field may be written only once after a CPU reset. Further modification causes a bus transfer error.
    // 0b0..EWM_in port is disabled.
    // 0b1..EWM_in port is enabled.
constexpr EWM_Reg<&EWM_Layout::CTRL, 1, 1> ASSIN;  // EWM_in's Assertion State Select.
    // RWONCE
    // This field may be written only once after a CPU reset. Further modification causes a bus transfer error.
    // 0b0..Default assert state of the EWM_in signal.
    // 0b1..Inverts the assert state of EWM_in signal.
constexpr EWM_Reg<&EWM_Layout::CTRL, 1, 0> EWMEN;  // EWM enable.
    // RWONCE
    // This field may be written only once after a CPU reset. Further modification causes a bus transfer error.
    // 0b0..EWM module is disabled.
    // 0b1..EWM module is enabled.
}  // namespace CTRL

// Service Register
namespace SERV {
constexpr EWM_Reg<&EWM_Layout::SERV, 8, 0> SERVICE;  // EWM Service Byte
    // Refresh the EWM by writing 0xB4 followed by 0x2C.
    // The second byte must be written within 63 peripheral bus clock cycles of the first.
}  // namespace SERV

// Compare Low Register
namespace CMPL {
constexpr EWM_Reg<&EWM_Layout::CMPL, 8, 0> COMPAREL;  // Low Comparison Value for the Refresh Window
    // This field may be written only once after a CPU reset. A second write causes a bus transfer error.
    // Software should write this field after reset even when the default minimum refresh time is required.
}  // namespace CMPL

// Compare High Register
namespace CMPH {
constexpr EWM_Reg<&EWM_Layout::CMPH, 8, 0> COMPAREH;  // High Comparison Value for the Refresh Window
    // This field may be written only once after a CPU reset. A second write causes a bus transfer error.
    // Values through 0xFE are valid. The EWM counter never expires when this field is 0xFF.
}  // namespace CMPH

// Clock Control Register
namespace CLKCTRL {
constexpr EWM_Reg<&EWM_Layout::CLKCTRL, 2, 0, 0x0> CLKSEL;  // Low-Power Clock Source Select
    // Direct-assign because there's only one writable field
    // This field may be written only once after a CPU reset. A second write causes a bus transfer error.
    // Select the required clock before enabling EWM.
    // 0b00: lpo_clk[0]
    // 0b01: lpo_clk[1]
    // 0b10: lpo_clk[2]
    // 0b11: lpo_clk[3]
}  // namespace CLKCTRL

// Clock Prescaler Register
namespace CLKPRESCALER {
constexpr EWM_Reg<&EWM_Layout::CLKPRESCALER, 8, 0> CLK_DIV;  // Low-Power Clock Prescaler Divisor
    // This field may be written only once after a CPU reset. A second write causes a bus transfer error.
    // Write the required prescaler before enabling EWM.
    // Prescaled clock frequency = selected low-power clock frequency / (1 + CLK_DIV).
    // The prescaled EWM clock must not exceed half the peripheral bus clock frequency.
}  // namespace CLKPRESCALER

}  // namespace EWM

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
