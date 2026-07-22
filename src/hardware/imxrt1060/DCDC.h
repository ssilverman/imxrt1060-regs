// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// DCDC.h defines all the DCDC registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// DCDC layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_DCDC.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct DCDC_Layout {
  volatile uint32_t REG0;                              /**< DCDC Register 0, offset: 0x0 */
  volatile uint32_t REG1;                              /**< DCDC Register 1, offset: 0x4 */
  volatile uint32_t REG2;                              /**< DCDC Register 2, offset: 0x8 */
  volatile uint32_t REG3;                              /**< DCDC Register 3, offset: 0xC */
};

constexpr size_t    kDCDC_size = 0x10;
constexpr uintptr_t kDCDC_base = 0x40080000;

namespace DCDC {
constexpr regs::RegGroup<DCDC_Layout, kDCDC_size, kDCDC_base> group;
}  // namespace DCDC

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using DCDC_Reg =
    regs::Reg32<kDCDC_base, DCDC_Layout, Member, 0, Bits, Shift, DirectAssign>;

namespace DCDC {

// DCDC Register 0
namespace REG0 {
constexpr DCDC_Reg<regs::constify(&DCDC_Layout::REG0), 1, 31> STS_DC_OK;  // DCDC Output OK
    // 0b0..DCDC is settling
    // 0b1..DCDC already settled
constexpr DCDC_Reg<&DCDC_Layout::REG0, 1, 29> XTAL_24M_OK;  // 24M XTAL OK
    // 0b0..DCDC uses internal ring OSC
    // 0b1..DCDC uses xtal 24M
constexpr DCDC_Reg<&DCDC_Layout::REG0, 1, 28> CURRENT_ALERT_RESET;  // Reset Current Alert Signal
    // 0b0..Current Alert Signal not reset
    // 0b1..Current Alert Signal reset
constexpr DCDC_Reg<&DCDC_Layout::REG0, 1, 27> XTALOK_DISABLE;  // Disable xtalok detection circuit
    // 0b0..Enable xtalok detection circuit
    // 0b1..Disable xtalok detection circuit and always outputs OK signal "1"
constexpr DCDC_Reg<&DCDC_Layout::REG0, 1, 26> PWD_CMP_OFFSET;  // Power down output range comparator
    // 0b0..Output range comparator powered up
    // 0b1..Output range comparator powered down
constexpr DCDC_Reg<&DCDC_Layout::REG0, 1, 21> LP_HIGH_HYS;  // Low Power High Hysteric Value
    // 0b0..Adjust hysteretic value in low power to 12.5mV
    // 0b1..Adjust hysteretic value in low power to 25mV
constexpr DCDC_Reg<&DCDC_Layout::REG0, 1, 20> LP_OVERLOAD_FREQ_SEL;  // Low Power Overload Frequency Select
    // 0b0..eight 32k cycle
    // 0b1..sixteen 32k cycle
constexpr DCDC_Reg<&DCDC_Layout::REG0, 2, 18> LP_OVERLOAD_THRSH;  // Low Power Overload Threshold
    // 0b00..32
    // 0b01..64
    // 0b10..16
    // 0b11..8
constexpr DCDC_Reg<&DCDC_Layout::REG0, 1, 17> PWD_HIGH_VOLT_DET;  // Power Down High Voltage Detection
    // 0b0..Overvoltage detection comparator is enabled
    // 0b1..Overvoltage detection comparator is disabled
constexpr DCDC_Reg<&DCDC_Layout::REG0, 1, 16> EN_LP_OVERLOAD_SNS;  // Low Power Overload Sense Enable
    // 0b0..Overload Detection in power save mode disabled
    // 0b1..Overload Detection in power save mode enabled
constexpr DCDC_Reg<&DCDC_Layout::REG0, 1, 11> PWD_CMP_BATT_DET;  // Power Down Battery Detection Comparator
    // 0b0..Low voltage detection comparator is enabled
    // 0b1..Low voltage detection comparator is disabled
constexpr DCDC_Reg<&DCDC_Layout::REG0, 2,  9> OVERCUR_TRIG_ADJ;  // Overcurrent Trigger Adjust
    // 0b00..In Run Mode, 1 A. In Power Save Mode, 0.25 A
    // 0b01..In Run Mode, 2 A. In Power Save Mode, 0.25 A
    // 0b10..In Run Mode, 1 A. In Power Save Mode, 0.2 A
    // 0b11..In Run Mode, 2 A. In Power Save Mode, 0.2 A
constexpr DCDC_Reg<&DCDC_Layout::REG0, 1,  8> PWD_OVERCUR_DET;  // Power down overcurrent detection comparator
    // 0b0..Overcurrent detection comparator is enabled
    // 0b1..Overcurrent detection comparator is disabled
constexpr DCDC_Reg<&DCDC_Layout::REG0, 3,  5> CUR_SNS_THRSH;  // Current Sense (detector) Threshold
    // 0b000..150 mA
    // 0b001..250 mA
    // 0b010..350 mA
    // 0b011..450 mA
    // 0b100..550 mA
    // 0b101..650 mA
constexpr DCDC_Reg<&DCDC_Layout::REG0, 1,  4> PWD_CUR_SNS_CMP;  // Power down signal of the current detector.
    // 0b0..Current Detector powered up
    // 0b1..Current Detector powered down
constexpr DCDC_Reg<&DCDC_Layout::REG0, 1,  3> PWD_OSC_INT;  // Power down internal osc
    // 0b0..Internal oscillator powered up
    // 0b1..Internal oscillator powered down
constexpr DCDC_Reg<&DCDC_Layout::REG0, 1,  2> SEL_CLK;  // Select Clock
    // 0b0..DCDC uses internal ring oscillator
    // 0b1..DCDC uses 24M xtal
constexpr DCDC_Reg<&DCDC_Layout::REG0, 1,  1> DISABLE_AUTO_CLK_SWITCH;  // Disable Auto Clock Switch
    // 0b0..If DISABLE_AUTO_CLK_SWITCH is set to 0 and 24M xtal is OK, the clock source will switch from internal ring OSC to 24M xtal automatically
    // 0b1..If DISABLE_AUTO_CLK_SWITCH is set to 1, SEL_CLK will determine which clock source the DCDC uses
constexpr DCDC_Reg<&DCDC_Layout::REG0, 1,  0> PWD_ZCD;  // Power Down Zero Cross Detection
    // 0b0..Zero cross detetion function powered up
    // 0b1..Zero cross detetion function powered down
}  // namespace REG0

// DCDC Register 1
namespace REG1 {
constexpr DCDC_Reg<&DCDC_Layout::REG1, 5, 24> VBG_TRIM;  // Trim Bandgap Voltage
constexpr DCDC_Reg<&DCDC_Layout::REG1, 1, 23> LOOPCTRL_EN_HYST;  // Enable Hysteresis
    // 0b0..Disable hysteresis in switching converter common mode analog comparators
    // 0b1..Enable hysteresis in switching converter common mode analog comparators
constexpr DCDC_Reg<&DCDC_Layout::REG1, 1, 21> LOOPCTRL_HST_THRESH;  // Increase Threshold Detection
    // 0b0..Lower hysteresis threshold (about 2.5mV in typical, but this value can vary with PVT corners
    // 0b1..Higher hysteresis threshold (about 5mV in typical)
constexpr DCDC_Reg<&DCDC_Layout::REG1, 2, 12> LP_CMP_ISRC_SEL;  // Low Power Comparator Current Bias
    // 0b00..50 nA
    // 0b01..100 nA
    // 0b10..200 nA
    // 0b11..400 nA
constexpr DCDC_Reg<&DCDC_Layout::REG1, 1,  9> REG_RLOAD_SW;
    // 0b0..Load resistor disconnected
    // 0b1..Load resistor connected
constexpr DCDC_Reg<&DCDC_Layout::REG1, 2,  7> REG_FBK_SEL;
    // 0b00..The regulator outputs 1.0V with 1.2V reference voltage
    // 0b01..The regulator outputs 1.1V with 1.2V reference voltage
    // 0b10..The regulator outputs 1.0V with 1.3V reference voltage
    // 0b11..The regulator outputs 1.1V with 1.3V reference voltage
}  // namespace REG1

// DCDC Register 2
namespace REG2 {
constexpr DCDC_Reg<&DCDC_Layout::REG2, 1, 28> DCM_SET_CTRL;  // DCM Set Control
constexpr DCDC_Reg<&DCDC_Layout::REG2, 1, 27> DISABLE_PULSE_SKIP;  // Disable Pulse Skip
    // 0b0..DCDC will be idle to save current dissipation when the duty cycle get to the low limit which is set by NEGLIMIT_IN.
    // 0b1..DCDC will keep working with the low limited duty cycle NEGLIMIT_IN.
constexpr DCDC_Reg<&DCDC_Layout::REG2, 1, 13> LOOPCTRL_HYST_SIGN;
    // 0b0..Do not invert sign of the hysteresis
    // 0b1..Invert sign of the hysteresis
constexpr DCDC_Reg<&DCDC_Layout::REG2, 1, 12> LOOPCTRL_RCSCALE_THRSH;
    // 0b0..Do not increase the threshold detection for RC scale circuit.
    // 0b1..Increase the threshold detection for RC scale circuit.
constexpr DCDC_Reg<&DCDC_Layout::REG2, 3,  9> LOOPCTRL_EN_RCSCALE;  // Enable RC Scale
constexpr DCDC_Reg<&DCDC_Layout::REG2, 3,  6> LOOPCTRL_DC_FF;
}  // namespace REG2

// DCDC Register 3
namespace REG3 {
constexpr DCDC_Reg<&DCDC_Layout::REG3, 1, 30> DISABLE_STEP;  // Disable Step
    // 0b0..Enable stepping for the output of VDD_SOC of DCDC
    // 0b1..Disable stepping for the output of VDD_SOC of DCDC
constexpr DCDC_Reg<&DCDC_Layout::REG3, 1, 24> MINPWR_DC_HALFCLK;
    // 0b0..DCDC clock remains at full frequency for continuous mode
    // 0b1..DCDC clock set to half frequency for continuous mode
constexpr DCDC_Reg<&DCDC_Layout::REG3, 3,  8> TARGET_LP;  // Low Power Target Value
    // 0b000..0.9 V
    // 0b001..0.925 V
    // 0b010..0.95 V
    // 0b011..0.975 V
    // 0b100..1.0 V
constexpr DCDC_Reg<&DCDC_Layout::REG3, 5,  0> TRG;  // Target value of VDD_SOC
}  // namespace REG3

}  // namespace DCDC

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
