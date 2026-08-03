// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// RTWDOG.h defines all the RTWDOG registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "qindesign/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the RTWDOG (WDOG3) registers.
//
// Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_RTWDOG.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct RTWDOG_Layout {
  volatile uint32_t CS;                                /**< Watchdog Control and Status Register, offset: 0x0 */
  volatile uint32_t CNT;                               /**< Watchdog Counter Register, offset: 0x4 */
  volatile uint32_t TOVAL;                             /**< Watchdog Timeout Value Register, offset: 0x8 */
  volatile uint32_t WIN;                               /**< Watchdog Window Register, offset: 0xC */
};

constexpr size_t    kRTWDOG_size = 0x10;
constexpr uintptr_t kRTWDOG_base = 0x400B'C000;

namespace RTWDOG {

constexpr regs::RegGroup<RTWDOG_Layout, kRTWDOG_size, kRTWDOG_base> group;

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using RTWDOG_Reg = regs::Reg32<kRTWDOG_base, RTWDOG_Layout, Member, 0, Bits,
                               Shift, AssignMask>;

// Watchdog Control and Status Register
namespace CS {
constexpr uint32_t kW1C = 0x0000'4000;

constexpr RTWDOG_Reg<&RTWDOG_Layout::CS, 1, 15, regs::shiftedMask32<1, 15>() | kW1C> WIN;      // Watchdog Window
    // 0b0..Window mode disabled.
    // 0b1..Window mode enabled.
constexpr RTWDOG_Reg<&RTWDOG_Layout::CS, 1, 14, kW1C> FLG;                                     // Watchdog Interrupt Flag
    // 0b0..No interrupt occurred.
    // 0b1..An interrupt occurred.
constexpr RTWDOG_Reg<&RTWDOG_Layout::CS, 1, 13, regs::shiftedMask32<1, 13>() | kW1C> CMD32EN;  // Enables or disables WDOG support for 32-bit (otherwise 16-bit or 8-bit) refresh/unlock command write words
    // 0b0..Disables support for 32-bit refresh/unlock command write words. Only 16-bit or 8-bit is supported.
    // 0b1..Enables support for 32-bit refresh/unlock command write words. 16-bit or 8-bit is NOT supported.
constexpr RTWDOG_Reg<&RTWDOG_Layout::CS, 1, 12, regs::shiftedMask32<1, 12>() | kW1C> PRES;     // Watchdog prescaler
    // 0b0..256 prescaler disabled.
    // 0b1..256 prescaler enabled.
constexpr RTWDOG_Reg<regs::constify(&RTWDOG_Layout::CS), 1, 11> ULK;                           // Unlock status
    // 0b0..WDOG is locked.
    // 0b1..WDOG is unlocked.
constexpr RTWDOG_Reg<regs::constify(&RTWDOG_Layout::CS), 1, 10> RCS;                           // Reconfiguration Success
    // 0b0..Reconfiguring WDOG.
    // 0b1..Reconfiguration is successful.
constexpr RTWDOG_Reg<&RTWDOG_Layout::CS, 2,  8, regs::shiftedMask32<2,  8>() | kW1C> CLK;      // Watchdog Clock
constexpr RTWDOG_Reg<&RTWDOG_Layout::CS, 1,  7, regs::shiftedMask32<1,  7>() | kW1C> EN;       // Watchdog Enable
    // 0b0..Watchdog disabled.
    // 0b1..Watchdog enabled.
constexpr RTWDOG_Reg<&RTWDOG_Layout::CS, 1,  6, regs::shiftedMask32<1,  6>() | kW1C> INT;      // Watchdog Interrupt
    // 0b0..Watchdog interrupts are disabled. Watchdog resets are not delayed.
    // 0b1..Watchdog interrupts are enabled. Watchdog resets are delayed by 128 bus clocks from the interrupt vector fetch.
constexpr RTWDOG_Reg<&RTWDOG_Layout::CS, 1,  5, regs::shiftedMask32<1,  5>() | kW1C> UPDATE;   // Allow updates
    // 0b0..Updates not allowed. After the initial configuration, the watchdog cannot be later modified without forcing a reset.
    // 0b1..Updates allowed. Software can modify the watchdog configuration registers within 128 bus clocks after performing the unlock write sequence.
constexpr RTWDOG_Reg<&RTWDOG_Layout::CS, 2,  3, regs::shiftedMask32<2,  3>() | kW1C> TST;      // Watchdog Test
    // 0b00..Watchdog test mode disabled.
    // 0b01..Watchdog user mode enabled. (Watchdog test mode disabled.) After testing the watchdog, software should
    //       use this setting to indicate that the watchdog is functioning normally in user mode.
    // 0b10..Watchdog test mode enabled, only the low byte is used. CNT[CNTLOW] is compared with TOVAL[TOVALLOW].
    // 0b11..Watchdog test mode enabled, only the high byte is used. CNT[CNTHIGH] is compared with TOVAL[TOVALHIGH].
constexpr RTWDOG_Reg<&RTWDOG_Layout::CS, 1,  2, regs::shiftedMask32<1,  2>() | kW1C> DBG;      // Debug Enable
    // 0b0..Watchdog disabled in chip debug mode.
    // 0b1..Watchdog enabled in chip debug mode.
constexpr RTWDOG_Reg<&RTWDOG_Layout::CS, 1,  1, regs::shiftedMask32<1,  1>() | kW1C> WAIT;     // Wait Enable
    // 0b0..Watchdog disabled in chip wait mode.
    // 0b1..Watchdog enabled in chip wait mode.
constexpr RTWDOG_Reg<&RTWDOG_Layout::CS, 1,  0, regs::shiftedMask32<1,  0>() | kW1C> STOP;     // Stop Enable
    // 0b0..Watchdog disabled in chip stop mode.
    // 0b1..Watchdog enabled in chip stop mode.
}  // namespace CS

// Watchdog Counter Register
namespace CNT {
constexpr RTWDOG_Reg<&RTWDOG_Layout::CNT, 8, 8> CNTHIGH;  // High byte of the Watchdog Counter
constexpr RTWDOG_Reg<&RTWDOG_Layout::CNT, 8, 0> CNTLOW;   // Low byte of the Watchdog Counter
}  // namespace CNT

// Watchdog Timeout Value Register
namespace TOVAL {
constexpr RTWDOG_Reg<&RTWDOG_Layout::TOVAL, 8, 8> TOVALHIGH;  // High byte of the timeout value
constexpr RTWDOG_Reg<&RTWDOG_Layout::TOVAL, 8, 0> TOVALLOW;   // Low byte of the timeout value
}  // namespace TOVAL

// Watchdog Window Register
namespace WIN {
constexpr RTWDOG_Reg<&RTWDOG_Layout::WIN, 8, 8> WINHIGH;  // High byte of Watchdog Window
constexpr RTWDOG_Reg<&RTWDOG_Layout::WIN, 8, 0> WINLOW;   // Low byte of Watchdog Window
}  // namespace WIN

}  // namespace RTWDOG

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
