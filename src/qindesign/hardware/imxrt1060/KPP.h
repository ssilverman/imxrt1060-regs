// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// KPP.h defines all the KPP registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "qindesign/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the Keypad Port (KPP) registers.
//
// Comments are from BSD-3-licensed NXP SDK and the NXP reference manual.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_KPP.h
// * https://github.com/nxp-mcuxpresso/mcux-soc-svd/blob/main/MIMXRT1062/MIMXRT1062.xml
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
// * i.MX RT1060 Processor Reference Manual, Rev. 4, chapter 46
struct KPP_Layout {
  volatile uint16_t KPCR;                              /**< Keypad Control Register, offset: 0x0 */
  volatile uint16_t KPSR;                              /**< Keypad Status Register, offset: 0x2 */
  volatile uint16_t KDDR;                              /**< Keypad Data Direction Register, offset: 0x4 */
  volatile uint16_t KPDR;                              /**< Keypad Data Register, offset: 0x6 */
};

constexpr size_t    kKPP_size = 0x8;
constexpr uintptr_t kKPP_base = 0x401F'C000;

namespace KPP {

constexpr regs::RegGroup<KPP_Layout, kKPP_size, kKPP_base> group;

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask16<Bits, Shift>()>
using KPP_Reg =
    regs::Reg16<kKPP_base, KPP_Layout, Member, 0, Bits, Shift, AssignMask>;

// Keypad Control Register
namespace KPCR {
constexpr KPP_Reg<&KPP_Layout::KPCR, 8, 8> KCO;  // Keypad Column Strobe Open-Drain Enable
    // 0b00000000..Column strobe output is totem pole drive.
    // 0b00000001..Column strobe output is open drain.
constexpr KPP_Reg<&KPP_Layout::KPCR, 8, 0> KRE;  // Keypad Row Enable
    // 0b00000000..Row is not included in the keypad key press detect.
    // 0b00000001..Row is included in the keypad key press detect.
}  // namespace KPCR

// Keypad Status Register
namespace KPSR {
constexpr uint16_t kW1C = 0x0003;

constexpr KPP_Reg<&KPP_Layout::KPSR, 1, 9, regs::shiftedMask16<1, 9>() | kW1C> KRIE;  // Keypad Release Interrupt Enable
    // 0b0..No interrupt request is generated when KPKR is set.
    // 0b1..An interrupt request is generated when KPKR is set.
constexpr KPP_Reg<&KPP_Layout::KPSR, 1, 8, regs::shiftedMask16<1, 8>() | kW1C> KDIE;  // Keypad Key Depress Interrupt Enable
    // 0b0..No interrupt request is generated when KPKD is set.
    // 0b1..An interrupt request is generated when KPKD is set.
constexpr KPP_Reg<&KPP_Layout::KPSR, 1, 3, regs::shiftedMask16<1, 3>() | kW1C> KRSS;  // Key Release Synchronizer Set
    // Writing 1 sets the key-release synchronizer chain; reads return 0.
    // 0b0..No effect
    // 0b1..Set bits which sets keypad release synchronizer chain
constexpr KPP_Reg<&KPP_Layout::KPSR, 1, 2, regs::shiftedMask16<1, 2>() | kW1C> KDSC;  // Key Depress Synchronizer Clear
    // Writing 1 clears the key-depress synchronizer chain; reads return 0.
    // 0b0..No effect
    // 0b1..Set bits that clear the keypad depress synchronizer chain
constexpr KPP_Reg<&KPP_Layout::KPSR, 1, 1, kW1C> KPKR;                                // Keypad Key Release
    // Writing 1 clears this status flag.
    // 0b0..No key release detected
    // 0b1..All keys have been released
constexpr KPP_Reg<&KPP_Layout::KPSR, 1, 0, kW1C> KPKD;                                // Keypad Key Depress
    // Writing 1 clears this status flag.
    // 0b0..No key presses detected
    // 0b1..A key has been depressed
}  // namespace KPSR

// Keypad Data Direction Register
namespace KDDR {
constexpr KPP_Reg<&KPP_Layout::KDDR, 8, 8> KCDD;  // Keypad Column Data Direction
    // 0b00000000..COLn pin is configured as an input.
    // 0b00000001..COLn pin is configured as an output.
constexpr KPP_Reg<&KPP_Layout::KDDR, 8, 0> KRDD;  // Keypad Row Data Direction
    // 0b00000000..ROWn pin configured as an input.
    // 0b00000001..ROWn pin configured as an output.
}  // namespace KDDR

// Keypad Data Register
namespace KPDR {
constexpr KPP_Reg<&KPP_Layout::KPDR, 8, 8> KCD;  // Keypad Column Data
constexpr KPP_Reg<&KPP_Layout::KPDR, 8, 0> KRD;  // Keypad Row Data
}  // namespace KPDR

}  // namespace KPP

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
