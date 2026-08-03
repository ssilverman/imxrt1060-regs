// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// XTALOSC24M.h defines all the XTALOSC24M registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "qindesign/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the 24 MHz crystal oscillator (XTALOSC24M)
// registers.
//
// Comments are from BSD-3-licensed NXP SDK sources and the NXP reference
// manual.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_XTALOSC24M.h
// * https://github.com/nxp-mcuxpresso/mcux-soc-svd/blob/main/MIMXRT1062/MIMXRT1062.xml
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
// * i.MX RT1060 Processor Reference Manual, Rev. 4, chapter 15
struct XTALOSC24M_Layout {
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[84];
  volatile uint32_t MISC0;                             /**< Miscellaneous Register 0, offset: 0x150 */
  volatile uint32_t MISC0_SET;                         /**< Miscellaneous Register 0, offset: 0x154 */
  volatile uint32_t MISC0_CLR;                         /**< Miscellaneous Register 0, offset: 0x158 */
  volatile uint32_t MISC0_TOG;                         /**< Miscellaneous Register 0, offset: 0x15C */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[68];
  volatile uint32_t LOWPWR_CTRL;                       /**< XTAL OSC (LP) Control Register, offset: 0x270 */
  volatile uint32_t LOWPWR_CTRL_SET;                   /**< XTAL OSC (LP) Control Register, offset: 0x274 */
  volatile uint32_t LOWPWR_CTRL_CLR;                   /**< XTAL OSC (LP) Control Register, offset: 0x278 */
  volatile uint32_t LOWPWR_CTRL_TOG;                   /**< XTAL OSC (LP) Control Register, offset: 0x27C */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[8];
  volatile uint32_t OSC_CONFIG0;                       /**< XTAL OSC Configuration 0 Register, offset: 0x2A0 */
  volatile uint32_t OSC_CONFIG0_SET;                   /**< XTAL OSC Configuration 0 Register, offset: 0x2A4 */
  volatile uint32_t OSC_CONFIG0_CLR;                   /**< XTAL OSC Configuration 0 Register, offset: 0x2A8 */
  volatile uint32_t OSC_CONFIG0_TOG;                   /**< XTAL OSC Configuration 0 Register, offset: 0x2AC */
  volatile uint32_t OSC_CONFIG1;                       /**< XTAL OSC Configuration 1 Register, offset: 0x2B0 */
  volatile uint32_t OSC_CONFIG1_SET;                   /**< XTAL OSC Configuration 1 Register, offset: 0x2B4 */
  volatile uint32_t OSC_CONFIG1_CLR;                   /**< XTAL OSC Configuration 1 Register, offset: 0x2B8 */
  volatile uint32_t OSC_CONFIG1_TOG;                   /**< XTAL OSC Configuration 1 Register, offset: 0x2BC */
  volatile uint32_t OSC_CONFIG2;                       /**< XTAL OSC Configuration 2 Register, offset: 0x2C0 */
  volatile uint32_t OSC_CONFIG2_SET;                   /**< XTAL OSC Configuration 2 Register, offset: 0x2C4 */
  volatile uint32_t OSC_CONFIG2_CLR;                   /**< XTAL OSC Configuration 2 Register, offset: 0x2C8 */
  volatile uint32_t OSC_CONFIG2_TOG;                   /**< XTAL OSC Configuration 2 Register, offset: 0x2CC */
};

constexpr size_t    kXTALOSC24M_size = 0x2D0;
constexpr uintptr_t kXTALOSC24M_base = 0x400D'8000;

namespace XTALOSC24M {

constexpr regs::RegGroup<XTALOSC24M_Layout, kXTALOSC24M_size, kXTALOSC24M_base>
    group;

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using XTALOSC24M_Reg = regs::Reg32<kXTALOSC24M_base, XTALOSC24M_Layout, Member,
                                   0, Bits, Shift, AssignMask>;

// Miscellaneous Register 0
namespace MISC0 {
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0, 1, 31> VID_PLL_PREDIV;                   // Predivider for the source clock of the PLL's.
    // Not related to oscillator.
    // 0b0..Divide by 1
    // 0b1..Divide by 2
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0, 1, 30> XTAL_24M_PWD;                     // This field powers down the 24M crystal oscillator if set true.
constexpr XTALOSC24M_Reg<regs::constify(&XTALOSC24M_Layout::MISC0), 1, 29> RTC_XTAL_SOURCE;  // This field indicates which chip source is being used for the rtc clock.
    // 0b0..Internal ring oscillator
    // 0b1..RTC_XTAL
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0, 3, 26> CLKGATE_DELAY;                    // This field specifies the delay between powering up the XTAL 24MHz clock and releasing the clock to the digital logic inside the analog block
    // Do not change this field during a low-power event; normally, software does not need to modify it.
    // 0b000..0.5 ms
    // 0b001..1.0 ms
    // 0b010..2.0 ms
    // 0b011..3.0 ms
    // 0b100..4.0 ms
    // 0b101..5.0 ms
    // 0b110..6.0 ms
    // 0b111..7.0 ms
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0, 1, 25> CLKGATE_CTRL;                     // This bit allows disabling the clock gate (always ungated) for the xtal 24MHz clock that clocks the digital logic in the analog block
    // Do not change this field during a low-power event; normally, software does not need to modify it.
    // 0b0..Allow the logic to automatically gate the clock when the XTAL is powered down.
    // 0b1..Prevent the logic from ever gating off the clock.
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0, 1, 16> OSC_XTALOK_EN;                    // This bit enables the detector that signals when the 24MHz crystal oscillator is stable.
constexpr XTALOSC24M_Reg<regs::constify(&XTALOSC24M_Layout::MISC0),  1, 15> OSC_XTALOK;      // Status bit that signals that the output of the 24-MHz crystal oscillator is stable
    // This status is generated by a timer and active frequency detection.
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0, 2, 13> OSC_I;                            // This field determines the bias current in the 24MHz oscillator
    // Use the highest bias during startup; software can reduce the bias after the oscillator starts.
    // 0b00..Nominal
    // 0b01..Decrease current by 12.5%
    // 0b10..Decrease current by 25.0%
    // 0b11..Decrease current by 37.5%
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0, 1, 12> DISCON_HIGH_SNVS;                 // This bit controls a switch from VDD_HIGH_IN to VDD_SNVS_IN.
    // 0b0..Turn on the switch
    // 0b1..Turn off the switch
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0, 2, 10> STOP_MODE_CONFIG;                 // Configure the analog behavior in stop mode.
    // Not related to oscillator.
    // 0b00..All analog except RTC powered down on stop mode assertion. Crystal oscillator on, RC oscillator off.
    // 0b01..Certain analog functions such as certain regulators left up. Crystal oscillator on, RC oscillator off.
    // 0b10..Crystal oscillator off, RC oscillator on, normal-power bandgap on, low-power bandgap off.
    // 0b11..Crystal oscillator off, RC oscillator on, normal-power bandgap off, low-power bandgap on.
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0, 1,  7> REFTOP_VBGUP;                     // Status bit that signals the analog bandgap voltage is up and stable
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0, 3,  4> REFTOP_VBGADJ;                    // Not related to oscillator.
    // 0b000..Nominal VBG
    // 0b001..VBG+0.78%
    // 0b010..VBG+1.56%
    // 0b011..VBG+2.34%
    // 0b100..VBG-0.78%
    // 0b101..VBG-1.56%
    // 0b110..VBG-2.34%
    // 0b111..VBG-3.12%
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0, 1,  3> REFTOP_SELFBIASOFF;               // Control bit to disable the self-bias circuit in the analog bandgap
    // Set this field after the bandgap stabilizes for best noise performance.
    // Clear it before removing VDD_HIGH_IN or asserting REFTOP_PWD.
    // 0b0..Uses coarse bias currents for startup
    // 0b1..Uses bandgap-based bias currents for best performance.
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0, 1,  0> REFTOP_PWD;                       // Control bit to power-down the analog bandgap reference circuitry
    // The bandgap is required for correct operation of most LDO, PLL, and analog functions.
}  // namespace MISC0

// Miscellaneous Register 0
namespace MISC0_SET {
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_SET, 1, 31, 0x0> VID_PLL_PREDIV;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_SET, 1, 30, 0x0> XTAL_24M_PWD;
constexpr XTALOSC24M_Reg<regs::constify(&XTALOSC24M_Layout::MISC0_SET),  1, 29> RTC_XTAL_SOURCE;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_SET, 3, 26, 0x0> CLKGATE_DELAY;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_SET, 1, 25, 0x0> CLKGATE_CTRL;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_SET, 1, 16, 0x0> OSC_XTALOK_EN;
constexpr XTALOSC24M_Reg<regs::constify(&XTALOSC24M_Layout::MISC0_SET),  1, 15> OSC_XTALOK;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_SET, 2, 13, 0x0> OSC_I;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_SET, 1, 12, 0x0> DISCON_HIGH_SNVS;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_SET, 2, 10, 0x0> STOP_MODE_CONFIG;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_SET, 1,  7, 0x0> REFTOP_VBGUP;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_SET, 3,  4, 0x0> REFTOP_VBGADJ;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_SET, 1,  3, 0x0> REFTOP_SELFBIASOFF;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_SET, 1,  0, 0x0> REFTOP_PWD;
}  // namespace MISC0_SET

// Miscellaneous Register 0
namespace MISC0_CLR {
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_CLR, 1, 31, 0x0> VID_PLL_PREDIV;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_CLR, 1, 30, 0x0> XTAL_24M_PWD;
constexpr XTALOSC24M_Reg<regs::constify(&XTALOSC24M_Layout::MISC0_CLR),  1, 29> RTC_XTAL_SOURCE;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_CLR, 3, 26, 0x0> CLKGATE_DELAY;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_CLR, 1, 25, 0x0> CLKGATE_CTRL;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_CLR, 1, 16, 0x0> OSC_XTALOK_EN;
constexpr XTALOSC24M_Reg<regs::constify(&XTALOSC24M_Layout::MISC0_CLR),  1, 15> OSC_XTALOK;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_CLR, 2, 13, 0x0> OSC_I;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_CLR, 1, 12, 0x0> DISCON_HIGH_SNVS;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_CLR, 2, 10, 0x0> STOP_MODE_CONFIG;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_CLR, 1,  7, 0x0> REFTOP_VBGUP;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_CLR, 3,  4, 0x0> REFTOP_VBGADJ;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_CLR, 1,  3, 0x0> REFTOP_SELFBIASOFF;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_CLR, 1,  0, 0x0> REFTOP_PWD;
}  // namespace MISC0_CLR

// Miscellaneous Register 0
namespace MISC0_TOG {
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_TOG, 1, 31, 0x0> VID_PLL_PREDIV;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_TOG, 1, 30, 0x0> XTAL_24M_PWD;
constexpr XTALOSC24M_Reg<regs::constify(&XTALOSC24M_Layout::MISC0_TOG),  1, 29> RTC_XTAL_SOURCE;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_TOG, 3, 26, 0x0> CLKGATE_DELAY;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_TOG, 1, 25, 0x0> CLKGATE_CTRL;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_TOG, 1, 16, 0x0> OSC_XTALOK_EN;
constexpr XTALOSC24M_Reg<regs::constify(&XTALOSC24M_Layout::MISC0_TOG),  1, 15> OSC_XTALOK;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_TOG, 2, 13, 0x0> OSC_I;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_TOG, 1, 12, 0x0> DISCON_HIGH_SNVS;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_TOG, 2, 10, 0x0> STOP_MODE_CONFIG;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_TOG, 1,  7, 0x0> REFTOP_VBGUP;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_TOG, 3,  4, 0x0> REFTOP_VBGADJ;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_TOG, 1,  3, 0x0> REFTOP_SELFBIASOFF;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::MISC0_TOG, 1,  0, 0x0> REFTOP_PWD;
}  // namespace MISC0_TOG

// XTAL OSC (LP) Control Register
namespace LOWPWR_CTRL {
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL, 1, 18> GPU_PWRGATE;                         // GPU power gate control.
    // Used as software mask. Set to zero to force ungated.
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL, 1, 17> MIX_PWRGATE;                         // Display power gate control.
    // Used as software mask. Set to zero to force ungated.
constexpr XTALOSC24M_Reg<regs::constify(&XTALOSC24M_Layout::LOWPWR_CTRL), 1, 16> XTALOSC_PWRUP_STAT;  // Status of the 24MHz xtal oscillator.
    // 0b0..Not stable
    // 0b1..Stable and ready to use
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL, 2, 14> XTALOSC_PWRUP_DELAY;                 // Specifies the time delay between when the 24MHz xtal is powered up until it is stable and ready to use
    // 0b00..0.25 ms
    // 0b01..0.5 ms
    // 0b10..1 ms
    // 0b11..2 ms
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL, 1, 13> RCOSC_CG_OVERRIDE;                   // For debug purposes only
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL, 1, 11> DISPLAY_PWRGATE;                     // Display logic power gate control.
    // Used as software override. Not related to oscillator.
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL, 1, 10> CPU_PWRGATE;                         // CPU power gate control.
    // Used as software override. Test purpose only Not related to oscillator.
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL, 1,  9> L2_PWRGATE;                          // L2 power gate control.
    // Used as software override. Not related to oscillator.
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL, 1,  8> L1_PWRGATE;                          // L1 power gate control.
    // Used as software override. Not related to oscillator.
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL, 1,  7> REFTOP_IBIAS_OFF;                    // Low power reftop ibias disable.
    // Not related to oscillator.
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL, 1,  6> LPBG_TEST;                           // Low power bandgap test bit.
    // Not related to oscillator.
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL, 1,  5> LPBG_SEL;                            // Bandgap select.
    // Not related to oscillator.
    // 0b0..Normal power bandgap
    // 0b1..Low power bandgap
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL, 1,  4> OSC_SEL;                             // Select the source for the 24MHz clock.
    // 0b0..Crystal oscillator
    // 0b1..RC oscillator
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL, 1,  0> RC_OSC_EN;                           // RC Osc. enable control.
    // 0b0..Use crystal oscillator to source the 24 MHz clock
    // 0b1..Use RC oscillator
}  // namespace LOWPWR_CTRL

// XTAL OSC (LP) Control Register
namespace LOWPWR_CTRL_SET {
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_SET, 1, 18, 0x0> GPU_PWRGATE;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_SET, 1, 17, 0x0> MIX_PWRGATE;
constexpr XTALOSC24M_Reg<regs::constify(&XTALOSC24M_Layout::LOWPWR_CTRL_SET), 1, 16> XTALOSC_PWRUP_STAT;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_SET, 2, 14, 0x0> XTALOSC_PWRUP_DELAY;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_SET, 1, 13, 0x0> RCOSC_CG_OVERRIDE;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_SET, 1, 11, 0x0> DISPLAY_PWRGATE;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_SET, 1, 10, 0x0> CPU_PWRGATE;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_SET, 1,  9, 0x0> L2_PWRGATE;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_SET, 1,  8, 0x0> L1_PWRGATE;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_SET, 1,  7, 0x0> REFTOP_IBIAS_OFF;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_SET, 1,  6, 0x0> LPBG_TEST;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_SET, 1,  5, 0x0> LPBG_SEL;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_SET, 1,  4, 0x0> OSC_SEL;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_SET, 1,  0, 0x0> RC_OSC_EN;
}  // namespace LOWPWR_CTRL_SET

// XTAL OSC (LP) Control Register
namespace LOWPWR_CTRL_CLR {
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_CLR, 1, 18, 0x0> GPU_PWRGATE;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_CLR, 1, 17, 0x0> MIX_PWRGATE;
constexpr XTALOSC24M_Reg<regs::constify(&XTALOSC24M_Layout::LOWPWR_CTRL_CLR), 1, 16> XTALOSC_PWRUP_STAT;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_CLR, 2, 14, 0x0> XTALOSC_PWRUP_DELAY;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_CLR, 1, 13, 0x0> RCOSC_CG_OVERRIDE;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_CLR, 1, 11, 0x0> DISPLAY_PWRGATE;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_CLR, 1, 10, 0x0> CPU_PWRGATE;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_CLR, 1,  9, 0x0> L2_PWRGATE;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_CLR, 1,  8, 0x0> L1_PWRGATE;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_CLR, 1,  7, 0x0> REFTOP_IBIAS_OFF;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_CLR, 1,  6, 0x0> LPBG_TEST;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_CLR, 1,  5, 0x0> LPBG_SEL;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_CLR, 1,  4, 0x0> OSC_SEL;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_CLR, 1,  0, 0x0> RC_OSC_EN;
}  // namespace LOWPWR_CTRL_CLR

// XTAL OSC (LP) Control Register
namespace LOWPWR_CTRL_TOG {
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_TOG, 1, 18, 0x0> GPU_PWRGATE;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_TOG, 1, 17, 0x0> MIX_PWRGATE;
constexpr XTALOSC24M_Reg<regs::constify(&XTALOSC24M_Layout::LOWPWR_CTRL_TOG), 1, 16> XTALOSC_PWRUP_STAT;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_TOG, 2, 14, 0x0> XTALOSC_PWRUP_DELAY;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_TOG, 1, 13, 0x0> RCOSC_CG_OVERRIDE;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_TOG, 1, 11, 0x0> DISPLAY_PWRGATE;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_TOG, 1, 10, 0x0> CPU_PWRGATE;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_TOG, 1,  9, 0x0> L2_PWRGATE;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_TOG, 1,  8, 0x0> L1_PWRGATE;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_TOG, 1,  7, 0x0> REFTOP_IBIAS_OFF;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_TOG, 1,  6, 0x0> LPBG_TEST;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_TOG, 1,  5, 0x0> LPBG_SEL;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_TOG, 1,  4, 0x0> OSC_SEL;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::LOWPWR_CTRL_TOG, 1,  0, 0x0> RC_OSC_EN;
}  // namespace LOWPWR_CTRL_TOG

// XTAL OSC Configuration 0 Register
namespace OSC_CONFIG0 {
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0, 8, 24> RC_OSC_PROG_CUR;  // The current tuning value in use.
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0, 4, 16> HYST_MINUS;       // Negative hysteresis value
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0, 4, 12> HYST_PLUS;        // Positive hysteresis value
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0, 8,  4> RC_OSC_PROG;      // RC osc. tuning values.
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0, 1,  3> INVERT;           // Invert the stepping of the calculated RC tuning value.
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0, 1,  2> BYPASS;           // Bypasses any calculated RC tuning value and uses the programmed register value.
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0, 1,  1> ENABLE;           // Enables the tuning logic to calculate new RC tuning values
    // Disabling tuning freezes the calculation state.
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0, 1,  0> START;            // Start/stop bit for the RC tuning calculation logic.
    // If stopped the tuning logic is reset.
}  // namespace OSC_CONFIG0

// XTAL OSC Configuration 0 Register
namespace OSC_CONFIG0_SET {
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0_SET, 8, 24, 0x0> RC_OSC_PROG_CUR;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0_SET, 4, 16, 0x0> HYST_MINUS;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0_SET, 4, 12, 0x0> HYST_PLUS;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0_SET, 8,  4, 0x0> RC_OSC_PROG;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0_SET, 1,  3, 0x0> INVERT;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0_SET, 1,  2, 0x0> BYPASS;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0_SET, 1,  1, 0x0> ENABLE;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0_SET, 1,  0, 0x0> START;
}  // namespace OSC_CONFIG0_SET

// XTAL OSC Configuration 0 Register
namespace OSC_CONFIG0_CLR {
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0_CLR, 8, 24, 0x0> RC_OSC_PROG_CUR;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0_CLR, 4, 16, 0x0> HYST_MINUS;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0_CLR, 4, 12, 0x0> HYST_PLUS;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0_CLR, 8,  4, 0x0> RC_OSC_PROG;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0_CLR, 1,  3, 0x0> INVERT;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0_CLR, 1,  2, 0x0> BYPASS;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0_CLR, 1,  1, 0x0> ENABLE;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0_CLR, 1,  0, 0x0> START;
}  // namespace OSC_CONFIG0_CLR

// XTAL OSC Configuration 0 Register
namespace OSC_CONFIG0_TOG {
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0_TOG, 8, 24, 0x0> RC_OSC_PROG_CUR;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0_TOG, 4, 16, 0x0> HYST_MINUS;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0_TOG, 4, 12, 0x0> HYST_PLUS;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0_TOG, 8,  4, 0x0> RC_OSC_PROG;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0_TOG, 1,  3, 0x0> INVERT;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0_TOG, 1,  2, 0x0> BYPASS;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0_TOG, 1,  1, 0x0> ENABLE;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG0_TOG, 1,  0, 0x0> START;
}  // namespace OSC_CONFIG0_TOG

// XTAL OSC Configuration 1 Register
namespace OSC_CONFIG1 {
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG1, 12, 20> COUNT_RC_CUR;  // The current tuning value in use.
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG1, 12,  0> COUNT_RC_TRG;  // The target count used to tune the RC OSC frequency
    // This value is the desired number of RC oscillator cycles in one 32 kHz clock cycle.
}  // namespace OSC_CONFIG1

// XTAL OSC Configuration 1 Register
namespace OSC_CONFIG1_SET {
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG1_SET, 12, 20, 0x0> COUNT_RC_CUR;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG1_SET, 12,  0, 0x0> COUNT_RC_TRG;
}  // namespace OSC_CONFIG1_SET

// XTAL OSC Configuration 1 Register
namespace OSC_CONFIG1_CLR {
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG1_CLR, 12, 20, 0x0> COUNT_RC_CUR;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG1_CLR, 12,  0, 0x0> COUNT_RC_TRG;
}  // namespace OSC_CONFIG1_CLR

// XTAL OSC Configuration 1 Register
namespace OSC_CONFIG1_TOG {
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG1_TOG, 12, 20, 0x0> COUNT_RC_CUR;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG1_TOG, 12,  0, 0x0> COUNT_RC_TRG;
}  // namespace OSC_CONFIG1_TOG

// XTAL OSC Configuration 2 Register
namespace OSC_CONFIG2 {
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG2,  1, 31> CLK_1M_ERR_FL;  // Flag indicates that the count_1m count wasn't reached within 1 32kHz period
    // The target count was not reached within one 32 kHz clock period, indicating that the target is too high.
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG2,  1, 17> MUX_1M;         // Mux the corrected or uncorrected 1MHz clock to the output
    // 0b0..Output the free-running 1 MHz clock.
    // 0b1..Output the locked 1 MHz clock.
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG2,  1, 16> ENABLE_1M;      // Enable the 1MHz clock output. 0 - disabled; 1 - enabled.
    // 0b0..Disable the 1 MHz clock output.
    // 0b1..Enable the 1 MHz clock output.
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG2, 12,  0> COUNT_1M_TRG;   // The target count used to tune the 1MHz clock frequency
}  // namespace OSC_CONFIG2

// XTAL OSC Configuration 2 Register
namespace OSC_CONFIG2_SET {
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG2_SET,  1, 31, 0x0> CLK_1M_ERR_FL;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG2_SET,  1, 17, 0x0> MUX_1M;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG2_SET,  1, 16, 0x0> ENABLE_1M;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG2_SET, 12,  0, 0x0> COUNT_1M_TRG;
}  // namespace OSC_CONFIG2_SET

// XTAL OSC Configuration 2 Register
namespace OSC_CONFIG2_CLR {
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG2_CLR,  1, 31, 0x0> CLK_1M_ERR_FL;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG2_CLR,  1, 17, 0x0> MUX_1M;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG2_CLR,  1, 16, 0x0> ENABLE_1M;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG2_CLR, 12,  0, 0x0> COUNT_1M_TRG;
}  // namespace OSC_CONFIG2_CLR

// XTAL OSC Configuration 2 Register
namespace OSC_CONFIG2_TOG {
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG2_TOG,  1, 31, 0x0> CLK_1M_ERR_FL;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG2_TOG,  1, 17, 0x0> MUX_1M;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG2_TOG,  1, 16, 0x0> ENABLE_1M;
constexpr XTALOSC24M_Reg<&XTALOSC24M_Layout::OSC_CONFIG2_TOG, 12,  0, 0x0> COUNT_1M_TRG;
}  // namespace OSC_CONFIG2_TOG

}  // namespace XTALOSC24M

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
