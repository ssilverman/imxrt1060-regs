// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// WDOG.h defines all the WDOG registers.
// This file is part of the TeensyRegs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace teensy4 {

// WDOG layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_WDOG.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct WDOG_Layout {
  volatile uint16_t WCR;                               /**< Watchdog Control Register, offset: 0x0 */
  volatile uint16_t WSR;                               /**< Watchdog Service Register, offset: 0x2 */
  const volatile uint16_t WRSR;                        /**< Watchdog Reset Status Register, offset: 0x4 */
  volatile uint16_t WICR;                              /**< Watchdog Interrupt Control Register, offset: 0x6 */
  volatile uint16_t WMCR;                              /**< Watchdog Miscellaneous Control Register, offset: 0x8 */
};

constexpr size_t    kWDOG_size  = 0xA;
constexpr uintptr_t kWDOG1_base = 0x400B8000;
constexpr uintptr_t kWDOG2_base = 0x400D0000;

namespace WDOG1 {
constexpr regs::RegGroup<WDOG_Layout, kWDOG_size, kWDOG1_base> group;
}  // namespace WDOG1

namespace WDOG2 {
constexpr regs::RegGroup<WDOG_Layout, kWDOG_size, kWDOG2_base> group;
}  // namespace WDOG2

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using WDOG1_Reg =
    regs::Reg16<kWDOG1_base, WDOG_Layout, Member, 0, Bits, Shift, DirectAssign>;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using WDOG2_Reg =
    regs::Reg16<kWDOG2_base, WDOG_Layout, Member, 0, Bits, Shift, DirectAssign>;

namespace WDOG1 {

// Watchdog Control Register
namespace WCR {
constexpr WDOG1_Reg<&WDOG_Layout::WCR, 8, 8> WT;
    // 0b00000000..- 0.5 Seconds (Default).
    // 0b00000001..- 1.0 Seconds.
    // 0b00000010..- 1.5 Seconds.
    // 0b00000011..- 2.0 Seconds.
    // 0b11111111..- 128 Seconds.
constexpr WDOG1_Reg<&WDOG_Layout::WCR, 1, 7> WDW;
    // 0b0..Continue WDOG timer operation (Default).
    // 0b1..Suspend WDOG timer operation.
constexpr WDOG1_Reg<&WDOG_Layout::WCR, 1, 6> SRE;  // Software Reset Extension, an optional way to generate software reset
    // 0b0..using original way to generate software reset (default)
    // 0b1..using new way to generate software reset.
constexpr WDOG1_Reg<&WDOG_Layout::WCR, 1, 5> WDA;
    // 0b0..Assert WDOG_B output.
    // 0b1..No effect on system (Default).
constexpr WDOG1_Reg<&WDOG_Layout::WCR, 1, 4> SRS;
    // 0b0..Assert system reset signal.
    // 0b1..No effect on the system (Default).
constexpr WDOG1_Reg<&WDOG_Layout::WCR, 1, 3> WDT;
    // 0b0..No effect on WDOG_B (Default).
    // 0b1..Assert WDOG_B upon a Watchdog Time-out event.
constexpr WDOG1_Reg<&WDOG_Layout::WCR, 1, 2> WDE;
    // 0b0..Disable the Watchdog (Default).
    // 0b1..Enable the Watchdog.
constexpr WDOG1_Reg<&WDOG_Layout::WCR, 1, 1> WDBG;
    // 0b0..Continue WDOG timer operation (Default).
    // 0b1..Suspend the watchdog timer.
constexpr WDOG1_Reg<&WDOG_Layout::WCR, 1, 0> WDZST;
    // 0b0..Continue timer operation (Default).
    // 0b1..Suspend the watchdog timer.
}  // namespace WCR

// Watchdog Service Register
namespace WSR {
constexpr WDOG1_Reg<&WDOG_Layout::WSR, 16, 0, true> WSR;
    // 0b0101010101010101..Write to the Watchdog Service Register (WDOG_WSR).
    // 0b1010101010101010..Write to the Watchdog Service Register (WDOG_WSR).
}  // namespace WSR

// Watchdog Reset Status Register
namespace WRSR {
constexpr WDOG1_Reg<&WDOG_Layout::WRSR, 1, 4> POR;
    // 0b0..Reset is not the result of a power on reset.
    // 0b1..Reset is the result of a power on reset.
constexpr WDOG1_Reg<&WDOG_Layout::WRSR, 1, 1> TOUT;
    // 0b0..Reset is not the result of a WDOG timeout.
    // 0b1..Reset is the result of a WDOG timeout.
constexpr WDOG1_Reg<&WDOG_Layout::WRSR, 1, 0> SFTW;
    // 0b0..Reset is not the result of a software reset.
    // 0b1..Reset is the result of a software reset.
}  // namespace WRSR

// Watchdog Interrupt Control Register
namespace WICR {
constexpr WDOG1_Reg<&WDOG_Layout::WICR, 1, 15> WIE;
    // 0b0..Disable Interrupt (Default).
    // 0b1..Enable Interrupt.
constexpr WDOG1_Reg<&WDOG_Layout::WICR, 1, 14> WTIS;
    // 0b0..No interrupt has occurred (Default).
    // 0b1..Interrupt has occurred
constexpr WDOG1_Reg<&WDOG_Layout::WICR, 8,  0> WICT;
    // 0b00000000..WICT[7:0] = Time duration between interrupt and time-out is 0 seconds.
    // 0b00000001..WICT[7:0] = Time duration between interrupt and time-out is 0.5 seconds.
    // 0b00000100..WICT[7:0] = Time duration between interrupt and time-out is 2 seconds (Default).
    // 0b11111111..WICT[7:0] = Time duration between interrupt and time-out is 127.5 seconds.
}  // namespace WICR

// Watchdog Miscellaneous Control Register
namespace WMCR {
constexpr WDOG1_Reg<&WDOG_Layout::WMCR, 1, 0> PDE;
    // 0b0..Power Down Counter of WDOG is disabled.
    // 0b1..Power Down Counter of WDOG is enabled (Default).
}  // namespace WMCR

}  // namespace WDOG1

namespace WDOG2 {

// WDOG2 Watchdog Control Register
namespace WCR {
constexpr WDOG2_Reg<&WDOG_Layout::WCR, 8, 8> WT;
constexpr WDOG2_Reg<&WDOG_Layout::WCR, 1, 7> WDW;
constexpr WDOG2_Reg<&WDOG_Layout::WCR, 1, 6> SRE;
constexpr WDOG2_Reg<&WDOG_Layout::WCR, 1, 5> WDA;
constexpr WDOG2_Reg<&WDOG_Layout::WCR, 1, 4> SRS;
constexpr WDOG2_Reg<&WDOG_Layout::WCR, 1, 3> WDT;
constexpr WDOG2_Reg<&WDOG_Layout::WCR, 1, 2> WDE;
constexpr WDOG2_Reg<&WDOG_Layout::WCR, 1, 1> WDBG;
constexpr WDOG2_Reg<&WDOG_Layout::WCR, 1, 0> WDZST;
}  // namespace WCR

// WDOG2 Watchdog Service Register
namespace WSR {
constexpr WDOG2_Reg<&WDOG_Layout::WSR, 16, 0, true> WSR;
}  // namespace WSR

// WDOG2 Watchdog Reset Status Register
namespace WRSR {
constexpr WDOG2_Reg<&WDOG_Layout::WRSR, 1, 4> POR;
constexpr WDOG2_Reg<&WDOG_Layout::WRSR, 1, 1> TOUT;
constexpr WDOG2_Reg<&WDOG_Layout::WRSR, 1, 0> SFTW;
}  // namespace WRSR

// WDOG2 Watchdog Interrupt Control Register
namespace WICR {
constexpr WDOG2_Reg<&WDOG_Layout::WICR, 1, 15> WIE;
constexpr WDOG2_Reg<&WDOG_Layout::WICR, 1, 14> WTIS;
constexpr WDOG2_Reg<&WDOG_Layout::WICR, 8,  0> WICT;
}  // namespace WICR

// WDOG2 Watchdog Miscellaneous Control Register
namespace WMCR {
constexpr WDOG2_Reg<&WDOG_Layout::WMCR, 1, 0> PDE;
}  // namespace WMCR

}  // namespace WDOG2

}  // namespace teensy4
}  // namespace hardware
}  // namespace qindesign
