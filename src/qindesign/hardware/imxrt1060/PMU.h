// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// PMU.h defines all the PMU registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "qindesign/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the Power Management Unit (PMU) registers.
//
// Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_PMU.h
// * https://github.com/nxp-mcuxpresso/mcux-soc-svd/blob/main/MIMXRT1062/MIMXRT1062.xml
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct PMU_Layout {
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[68];
  volatile uint32_t REG_1P1;                           /**< Regulator 1P1 Register, offset: 0x110 */
  volatile uint32_t REG_1P1_SET;                       /**< Regulator 1P1 Register, offset: 0x114 */
  volatile uint32_t REG_1P1_CLR;                       /**< Regulator 1P1 Register, offset: 0x118 */
  volatile uint32_t REG_1P1_TOG;                       /**< Regulator 1P1 Register, offset: 0x11C */
  volatile uint32_t REG_3P0;                           /**< Regulator 3P0 Register, offset: 0x120 */
  volatile uint32_t REG_3P0_SET;                       /**< Regulator 3P0 Register, offset: 0x124 */
  volatile uint32_t REG_3P0_CLR;                       /**< Regulator 3P0 Register, offset: 0x128 */
  volatile uint32_t REG_3P0_TOG;                       /**< Regulator 3P0 Register, offset: 0x12C */
  volatile uint32_t REG_2P5;                           /**< Regulator 2P5 Register, offset: 0x130 */
  volatile uint32_t REG_2P5_SET;                       /**< Regulator 2P5 Register, offset: 0x134 */
  volatile uint32_t REG_2P5_CLR;                       /**< Regulator 2P5 Register, offset: 0x138 */
  volatile uint32_t REG_2P5_TOG;                       /**< Regulator 2P5 Register, offset: 0x13C */
  volatile uint32_t REG_CORE;                          /**< Digital Regulator Core Register, offset: 0x140 */
  volatile uint32_t REG_CORE_SET;                      /**< Digital Regulator Core Register, offset: 0x144 */
  volatile uint32_t REG_CORE_CLR;                      /**< Digital Regulator Core Register, offset: 0x148 */
  volatile uint32_t REG_CORE_TOG;                      /**< Digital Regulator Core Register, offset: 0x14C */
  volatile uint32_t MISC0;                             /**< Miscellaneous Register 0, offset: 0x150 */
  volatile uint32_t MISC0_SET;                         /**< Miscellaneous Register 0, offset: 0x154 */
  volatile uint32_t MISC0_CLR;                         /**< Miscellaneous Register 0, offset: 0x158 */
  volatile uint32_t MISC0_TOG;                         /**< Miscellaneous Register 0, offset: 0x15C */
  volatile uint32_t MISC1;                             /**< Miscellaneous Register 1, offset: 0x160 */
  volatile uint32_t MISC1_SET;                         /**< Miscellaneous Register 1, offset: 0x164 */
  volatile uint32_t MISC1_CLR;                         /**< Miscellaneous Register 1, offset: 0x168 */
  volatile uint32_t MISC1_TOG;                         /**< Miscellaneous Register 1, offset: 0x16C */
  volatile uint32_t MISC2;                             /**< Miscellaneous Control Register, offset: 0x170 */
  volatile uint32_t MISC2_SET;                         /**< Miscellaneous Control Register, offset: 0x174 */
  volatile uint32_t MISC2_CLR;                         /**< Miscellaneous Control Register, offset: 0x178 */
  volatile uint32_t MISC2_TOG;                         /**< Miscellaneous Control Register, offset: 0x17C */
};

constexpr size_t    kPMU_size = 0x180;
constexpr uintptr_t kPMU_base = 0x400D'8000;

namespace PMU {

constexpr regs::RegGroup<PMU_Layout, kPMU_size, kPMU_base> group;

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using PMU_Reg =
    regs::Reg32<kPMU_base, PMU_Layout, Member, 0, Bits, Shift, AssignMask>;

namespace PMU {

// Regulator 1P1 Register
namespace REG_1P1 {
constexpr PMU_Reg<&PMU_Layout::REG_1P1, 1, 19> SELREF_WEAK_LINREG;         // Selects the source for the reference voltage of the weak 1p1 regulator.
    // 0b0..Weak-linreg output tracks low-power-bandgap voltage
    // 0b1..Weak-linreg output tracks VDD_SOC_IN voltage
constexpr PMU_Reg<&PMU_Layout::REG_1P1, 1, 18> ENABLE_WEAK_LINREG;         // Enables the weak 1p1 regulator
constexpr PMU_Reg<regs::constify(&PMU_Layout::REG_1P1), 1, 17> OK_VDD1P1;  // Status bit that signals when the regulator output is ok.
    // 1 = regulator output > brownout target
constexpr PMU_Reg<regs::constify(&PMU_Layout::REG_1P1), 1, 16> BO_VDD1P1;  // Status bit that signals when a brownout is detected on the regulator output.
constexpr PMU_Reg<&PMU_Layout::REG_1P1, 5,  8> OUTPUT_TRG;                 // Control bits to adjust the regulator output voltage
    // 0b000x1..1.375V
    // 0b00100..0.8V
    // 0b10000..1.1V
constexpr PMU_Reg<&PMU_Layout::REG_1P1, 3,  4> BO_OFFSET;                  // Control bits to adjust the regulator brownout offset voltage in 25mV steps
constexpr PMU_Reg<&PMU_Layout::REG_1P1, 1,  3> ENABLE_PULLDOWN;            // Control bit to enable the pull-down circuitry in the regulator
constexpr PMU_Reg<&PMU_Layout::REG_1P1, 1,  2> ENABLE_ILIMIT;              // Control bit to enable the current-limit circuitry in the regulator.
constexpr PMU_Reg<&PMU_Layout::REG_1P1, 1,  1> ENABLE_BO;                  // Control bit to enable the brownout circuitry in the regulator.
constexpr PMU_Reg<&PMU_Layout::REG_1P1, 1,  0> ENABLE_LINREG;              // Control bit to enable the regulator output.
}  // namespace REG_1P1

// Regulator 1P1 Register
namespace REG_1P1_SET {
constexpr PMU_Reg<&PMU_Layout::REG_1P1_SET, 1, 19, 0x0> SELREF_WEAK_LINREG;    // Selects the source for the reference voltage of the weak 1p1 regulator.
    // 0b0..Weak-linreg output tracks low-power-bandgap voltage
    // 0b1..Weak-linreg output tracks VDD_SOC_IN voltage
constexpr PMU_Reg<&PMU_Layout::REG_1P1_SET, 1, 18, 0x0> ENABLE_WEAK_LINREG;    // Enables the weak 1p1 regulator
constexpr PMU_Reg<regs::constify(&PMU_Layout::REG_1P1_SET), 1, 17> OK_VDD1P1;  // Status bit that signals when the regulator output is ok.
    // 1 = regulator output > brownout target
constexpr PMU_Reg<regs::constify(&PMU_Layout::REG_1P1_SET), 1, 16> BO_VDD1P1;  // Status bit that signals when a brownout is detected on the regulator output.
constexpr PMU_Reg<&PMU_Layout::REG_1P1_SET, 5,  8, 0x0> OUTPUT_TRG;            // Control bits to adjust the regulator output voltage
    // 0b000x1..1.375V
    // 0b00100..0.8V
    // 0b10000..1.1V
constexpr PMU_Reg<&PMU_Layout::REG_1P1_SET, 3,  4, 0x0> BO_OFFSET;             // Control bits to adjust the regulator brownout offset voltage in 25mV steps
constexpr PMU_Reg<&PMU_Layout::REG_1P1_SET, 1,  3, 0x0> ENABLE_PULLDOWN;       // Control bit to enable the pull-down circuitry in the regulator
constexpr PMU_Reg<&PMU_Layout::REG_1P1_SET, 1,  2, 0x0> ENABLE_ILIMIT;         // Control bit to enable the current-limit circuitry in the regulator.
constexpr PMU_Reg<&PMU_Layout::REG_1P1_SET, 1,  1, 0x0> ENABLE_BO;             // Control bit to enable the brownout circuitry in the regulator.
constexpr PMU_Reg<&PMU_Layout::REG_1P1_SET, 1,  0, 0x0> ENABLE_LINREG;         // Control bit to enable the regulator output.
}  // namespace REG_1P1_SET

// Regulator 1P1 Register
namespace REG_1P1_CLR {
constexpr PMU_Reg<&PMU_Layout::REG_1P1_CLR, 1, 19, 0x0> SELREF_WEAK_LINREG;    // Selects the source for the reference voltage of the weak 1p1 regulator.
    // 0b0..Weak-linreg output tracks low-power-bandgap voltage
    // 0b1..Weak-linreg output tracks VDD_SOC_IN voltage
constexpr PMU_Reg<&PMU_Layout::REG_1P1_CLR, 1, 18, 0x0> ENABLE_WEAK_LINREG;    // Enables the weak 1p1 regulator
constexpr PMU_Reg<regs::constify(&PMU_Layout::REG_1P1_CLR), 1, 17> OK_VDD1P1;  // Status bit that signals when the regulator output is ok.
    // 1 = regulator output > brownout target
constexpr PMU_Reg<regs::constify(&PMU_Layout::REG_1P1_CLR), 1, 16> BO_VDD1P1;  // Status bit that signals when a brownout is detected on the regulator output.
constexpr PMU_Reg<&PMU_Layout::REG_1P1_CLR, 5,  8, 0x0> OUTPUT_TRG;            // Control bits to adjust the regulator output voltage
    // 0b000x1..1.375V
    // 0b00100..0.8V
    // 0b10000..1.1V
constexpr PMU_Reg<&PMU_Layout::REG_1P1_CLR, 3,  4, 0x0> BO_OFFSET;             // Control bits to adjust the regulator brownout offset voltage in 25mV steps
constexpr PMU_Reg<&PMU_Layout::REG_1P1_CLR, 1,  3, 0x0> ENABLE_PULLDOWN;       // Control bit to enable the pull-down circuitry in the regulator
constexpr PMU_Reg<&PMU_Layout::REG_1P1_CLR, 1,  2, 0x0> ENABLE_ILIMIT;         // Control bit to enable the current-limit circuitry in the regulator.
constexpr PMU_Reg<&PMU_Layout::REG_1P1_CLR, 1,  1, 0x0> ENABLE_BO;             // Control bit to enable the brownout circuitry in the regulator.
constexpr PMU_Reg<&PMU_Layout::REG_1P1_CLR, 1,  0, 0x0> ENABLE_LINREG;         // Control bit to enable the regulator output.
}  // namespace REG_1P1_CLR

// Regulator 1P1 Register
namespace REG_1P1_TOG {
constexpr PMU_Reg<&PMU_Layout::REG_1P1_TOG, 1, 19, 0x0> SELREF_WEAK_LINREG;    // Selects the source for the reference voltage of the weak 1p1 regulator.
    // 0b0..Weak-linreg output tracks low-power-bandgap voltage
    // 0b1..Weak-linreg output tracks VDD_SOC_IN voltage
constexpr PMU_Reg<&PMU_Layout::REG_1P1_TOG, 1, 18, 0x0> ENABLE_WEAK_LINREG;    // Enables the weak 1p1 regulator
constexpr PMU_Reg<regs::constify(&PMU_Layout::REG_1P1_TOG), 1, 17> OK_VDD1P1;  // Status bit that signals when the regulator output is ok.
    // 1 = regulator output > brownout target
constexpr PMU_Reg<regs::constify(&PMU_Layout::REG_1P1_TOG), 1, 16> BO_VDD1P1;  // Status bit that signals when a brownout is detected on the regulator output.
constexpr PMU_Reg<&PMU_Layout::REG_1P1_TOG, 5,  8, 0x0> OUTPUT_TRG;            // Control bits to adjust the regulator output voltage
    // 0b000x1..1.375V
    // 0b00100..0.8V
    // 0b10000..1.1V
constexpr PMU_Reg<&PMU_Layout::REG_1P1_TOG, 3,  4, 0x0> BO_OFFSET;             // Control bits to adjust the regulator brownout offset voltage in 25mV steps
constexpr PMU_Reg<&PMU_Layout::REG_1P1_TOG, 1,  3, 0x0> ENABLE_PULLDOWN;       // Control bit to enable the pull-down circuitry in the regulator
constexpr PMU_Reg<&PMU_Layout::REG_1P1_TOG, 1,  2, 0x0> ENABLE_ILIMIT;         // Control bit to enable the current-limit circuitry in the regulator.
constexpr PMU_Reg<&PMU_Layout::REG_1P1_TOG, 1,  1, 0x0> ENABLE_BO;             // Control bit to enable the brownout circuitry in the regulator.
constexpr PMU_Reg<&PMU_Layout::REG_1P1_TOG, 1,  0, 0x0> ENABLE_LINREG;         // Control bit to enable the regulator output.
}  // namespace REG_1P1_TOG

// Regulator 3P0 Register
namespace REG_3P0 {
constexpr PMU_Reg<regs::constify(&PMU_Layout::REG_3P0), 1, 17> OK_VDD3P0;  // Status bit that signals when the regulator output is ok.
    // 1 = regulator output > brownout target
constexpr PMU_Reg<regs::constify(&PMU_Layout::REG_3P0), 1, 16> BO_VDD3P0;  // Status bit that signals when a brownout is detected on the regulator output.
constexpr PMU_Reg<&PMU_Layout::REG_3P0, 5,  8> OUTPUT_TRG;                 // Control bits to adjust the regulator output voltage
    // 0b00000..2.625V
    // 0b01111..3.000V
    // 0b11111..3.400V
constexpr PMU_Reg<&PMU_Layout::REG_3P0, 1,  7> VBUS_SEL;                   // Select input voltage source for LDO_3P0 from either USB_OTG1_VBUS or USB_OTG2_VBUS
    // 0b0..Utilize VBUS OTG2 power
    // 0b1..Utilize VBUS OTG1 power
constexpr PMU_Reg<&PMU_Layout::REG_3P0, 3,  4> BO_OFFSET;                  // Control bits to adjust the regulator brownout offset voltage in 25mV steps
constexpr PMU_Reg<&PMU_Layout::REG_3P0, 1,  2> ENABLE_ILIMIT;              // Control bit to enable the current-limit circuitry in the regulator.
constexpr PMU_Reg<&PMU_Layout::REG_3P0, 1,  1> ENABLE_BO;                  // Control bit to enable the brownout circuitry in the regulator.
constexpr PMU_Reg<&PMU_Layout::REG_3P0, 1,  0> ENABLE_LINREG;              // Control bit to enable the regulator output to be set by the programmed target voltage setting and internal bandgap reference
}  // namespace REG_3P0

// Regulator 3P0 Register
namespace REG_3P0_SET {
constexpr PMU_Reg<regs::constify(&PMU_Layout::REG_3P0_SET), 1, 17> OK_VDD3P0;  // Status bit that signals when the regulator output is ok.
    // 1 = regulator output > brownout target
constexpr PMU_Reg<regs::constify(&PMU_Layout::REG_3P0_SET), 1, 16> BO_VDD3P0;  // Status bit that signals when a brownout is detected on the regulator output.
constexpr PMU_Reg<&PMU_Layout::REG_3P0_SET, 5,  8, 0x0> OUTPUT_TRG;            // Control bits to adjust the regulator output voltage
    // 0b00000..2.625V
    // 0b01111..3.000V
    // 0b11111..3.400V
constexpr PMU_Reg<&PMU_Layout::REG_3P0_SET, 1,  7, 0x0> VBUS_SEL;              // Select input voltage source for LDO_3P0 from either USB_OTG1_VBUS or USB_OTG2_VBUS
    // 0b0..Utilize VBUS OTG2 power
    // 0b1..Utilize VBUS OTG1 power
constexpr PMU_Reg<&PMU_Layout::REG_3P0_SET, 3,  4, 0x0> BO_OFFSET;             // Control bits to adjust the regulator brownout offset voltage in 25mV steps
constexpr PMU_Reg<&PMU_Layout::REG_3P0_SET, 1,  2, 0x0> ENABLE_ILIMIT;         // Control bit to enable the current-limit circuitry in the regulator.
constexpr PMU_Reg<&PMU_Layout::REG_3P0_SET, 1,  1, 0x0> ENABLE_BO;             // Control bit to enable the brownout circuitry in the regulator.
constexpr PMU_Reg<&PMU_Layout::REG_3P0_SET, 1,  0, 0x0> ENABLE_LINREG;         // Control bit to enable the regulator output to be set by the programmed target voltage setting and internal bandgap reference
}  // namespace REG_3P0_SET

// Regulator 3P0 Register
namespace REG_3P0_CLR {
constexpr PMU_Reg<regs::constify(&PMU_Layout::REG_3P0_CLR), 1, 17> OK_VDD3P0;  // Status bit that signals when the regulator output is ok.
    // 1 = regulator output > brownout target
constexpr PMU_Reg<regs::constify(&PMU_Layout::REG_3P0_CLR), 1, 16> BO_VDD3P0;  // Status bit that signals when a brownout is detected on the regulator output.
constexpr PMU_Reg<&PMU_Layout::REG_3P0_CLR, 5,  8, 0x0> OUTPUT_TRG;            // Control bits to adjust the regulator output voltage
    // 0b00000..2.625V
    // 0b01111..3.000V
    // 0b11111..3.400V
constexpr PMU_Reg<&PMU_Layout::REG_3P0_CLR, 1,  7, 0x0> VBUS_SEL;              // Select input voltage source for LDO_3P0 from either USB_OTG1_VBUS or USB_OTG2_VBUS
    // 0b0..Utilize VBUS OTG2 power
    // 0b1..Utilize VBUS OTG1 power
constexpr PMU_Reg<&PMU_Layout::REG_3P0_CLR, 3,  4, 0x0> BO_OFFSET;             // Control bits to adjust the regulator brownout offset voltage in 25mV steps
constexpr PMU_Reg<&PMU_Layout::REG_3P0_CLR, 1,  2, 0x0> ENABLE_ILIMIT;         // Control bit to enable the current-limit circuitry in the regulator.
constexpr PMU_Reg<&PMU_Layout::REG_3P0_CLR, 1,  1, 0x0> ENABLE_BO;             // Control bit to enable the brownout circuitry in the regulator.
constexpr PMU_Reg<&PMU_Layout::REG_3P0_CLR, 1,  0, 0x0> ENABLE_LINREG;         // Control bit to enable the regulator output to be set by the programmed target voltage setting and internal bandgap reference
}  // namespace REG_3P0_CLR

// Regulator 3P0 Register
namespace REG_3P0_TOG {
constexpr PMU_Reg<regs::constify(&PMU_Layout::REG_3P0_TOG), 1, 17> OK_VDD3P0;  // Status bit that signals when the regulator output is ok.
    // 1 = regulator output > brownout target
constexpr PMU_Reg<regs::constify(&PMU_Layout::REG_3P0_TOG), 1, 16> BO_VDD3P0;  // Status bit that signals when a brownout is detected on the regulator output.
constexpr PMU_Reg<&PMU_Layout::REG_3P0_TOG, 5,  8, 0x0> OUTPUT_TRG;            // Control bits to adjust the regulator output voltage
    // 0b00000..2.625V
    // 0b01111..3.000V
    // 0b11111..3.400V
constexpr PMU_Reg<&PMU_Layout::REG_3P0_TOG, 1,  7, 0x0> VBUS_SEL;              // Select input voltage source for LDO_3P0 from either USB_OTG1_VBUS or USB_OTG2_VBUS
    // 0b0..Utilize VBUS OTG2 power
    // 0b1..Utilize VBUS OTG1 power
constexpr PMU_Reg<&PMU_Layout::REG_3P0_TOG, 3,  4, 0x0> BO_OFFSET;             // Control bits to adjust the regulator brownout offset voltage in 25mV steps
constexpr PMU_Reg<&PMU_Layout::REG_3P0_TOG, 1,  2, 0x0> ENABLE_ILIMIT;         // Control bit to enable the current-limit circuitry in the regulator.
constexpr PMU_Reg<&PMU_Layout::REG_3P0_TOG, 1,  1, 0x0> ENABLE_BO;             // Control bit to enable the brownout circuitry in the regulator.
constexpr PMU_Reg<&PMU_Layout::REG_3P0_TOG, 1,  0, 0x0> ENABLE_LINREG;         // Control bit to enable the regulator output to be set by the programmed target voltage setting and internal bandgap reference
}  // namespace REG_3P0_TOG

// Regulator 2P5 Register
namespace REG_2P5 {
constexpr PMU_Reg<&PMU_Layout::REG_2P5, 1, 18> ENABLE_WEAK_LINREG;         // Enables the weak 2p5 regulator
constexpr PMU_Reg<regs::constify(&PMU_Layout::REG_2P5), 1, 17> OK_VDD2P5;  // Status bit that signals when the regulator output is ok.
    // 1 = regulator output > brownout target
constexpr PMU_Reg<regs::constify(&PMU_Layout::REG_2P5), 1, 16> BO_VDD2P5;  // Status bit that signals when a brownout is detected on the regulator output.
constexpr PMU_Reg<&PMU_Layout::REG_2P5, 5,  8> OUTPUT_TRG;                 // Control bits to adjust the regulator output voltage
    // 0b00000..2.10V
    // 0b10000..2.50V
    // 0b11111..2.875V
constexpr PMU_Reg<&PMU_Layout::REG_2P5, 3,  4> BO_OFFSET;                  // Control bits to adjust the regulator brownout offset voltage in 25mV steps
constexpr PMU_Reg<&PMU_Layout::REG_2P5, 1,  3> ENABLE_PULLDOWN;            // Control bit to enable the pull-down circuitry in the regulator
constexpr PMU_Reg<&PMU_Layout::REG_2P5, 1,  2> ENABLE_ILIMIT;              // Control bit to enable the current-limit circuitry in the regulator.
constexpr PMU_Reg<&PMU_Layout::REG_2P5, 1,  1> ENABLE_BO;                  // Control bit to enable the brownout circuitry in the regulator.
constexpr PMU_Reg<&PMU_Layout::REG_2P5, 1,  0> ENABLE_LINREG;              // Control bit to enable the regulator output.
}  // namespace REG_2P5

// Regulator 2P5 Register
namespace REG_2P5_SET {
constexpr PMU_Reg<&PMU_Layout::REG_2P5_SET, 1, 18, 0x0> ENABLE_WEAK_LINREG;    // Enables the weak 2p5 regulator
constexpr PMU_Reg<regs::constify(&PMU_Layout::REG_2P5_SET), 1, 17> OK_VDD2P5;  // Status bit that signals when the regulator output is ok.
    // 1 = regulator output > brownout target
constexpr PMU_Reg<regs::constify(&PMU_Layout::REG_2P5_SET), 1, 16> BO_VDD2P5;  // Status bit that signals when a brownout is detected on the regulator output.
constexpr PMU_Reg<&PMU_Layout::REG_2P5_SET, 5,  8, 0x0> OUTPUT_TRG;            // Control bits to adjust the regulator output voltage
    // 0b00000..2.10V
    // 0b10000..2.50V
    // 0b11111..2.875V
constexpr PMU_Reg<&PMU_Layout::REG_2P5_SET, 3,  4, 0x0> BO_OFFSET;             // Control bits to adjust the regulator brownout offset voltage in 25mV steps
constexpr PMU_Reg<&PMU_Layout::REG_2P5_SET, 1,  3, 0x0> ENABLE_PULLDOWN;       // Control bit to enable the pull-down circuitry in the regulator
constexpr PMU_Reg<&PMU_Layout::REG_2P5_SET, 1,  2, 0x0> ENABLE_ILIMIT;         // Control bit to enable the current-limit circuitry in the regulator.
constexpr PMU_Reg<&PMU_Layout::REG_2P5_SET, 1,  1, 0x0> ENABLE_BO;             // Control bit to enable the brownout circuitry in the regulator.
constexpr PMU_Reg<&PMU_Layout::REG_2P5_SET, 1,  0, 0x0> ENABLE_LINREG;         // Control bit to enable the regulator output.
}  // namespace REG_2P5_SET

// Regulator 2P5 Register
namespace REG_2P5_CLR {
constexpr PMU_Reg<&PMU_Layout::REG_2P5_CLR, 1, 18, 0x0> ENABLE_WEAK_LINREG;    // Enables the weak 2p5 regulator
constexpr PMU_Reg<regs::constify(&PMU_Layout::REG_2P5_CLR), 1, 17> OK_VDD2P5;  // Status bit that signals when the regulator output is ok.
    // 1 = regulator output > brownout target
constexpr PMU_Reg<regs::constify(&PMU_Layout::REG_2P5_CLR), 1, 16> BO_VDD2P5;  // Status bit that signals when a brownout is detected on the regulator output.
constexpr PMU_Reg<&PMU_Layout::REG_2P5_CLR, 5,  8, 0x0> OUTPUT_TRG;            // Control bits to adjust the regulator output voltage
    // 0b00000..2.10V
    // 0b10000..2.50V
    // 0b11111..2.875V
constexpr PMU_Reg<&PMU_Layout::REG_2P5_CLR, 3,  4, 0x0> BO_OFFSET;             // Control bits to adjust the regulator brownout offset voltage in 25mV steps
constexpr PMU_Reg<&PMU_Layout::REG_2P5_CLR, 1,  3, 0x0> ENABLE_PULLDOWN;       // Control bit to enable the pull-down circuitry in the regulator
constexpr PMU_Reg<&PMU_Layout::REG_2P5_CLR, 1,  2, 0x0> ENABLE_ILIMIT;         // Control bit to enable the current-limit circuitry in the regulator.
constexpr PMU_Reg<&PMU_Layout::REG_2P5_CLR, 1,  1, 0x0> ENABLE_BO;             // Control bit to enable the brownout circuitry in the regulator.
constexpr PMU_Reg<&PMU_Layout::REG_2P5_CLR, 1,  0, 0x0> ENABLE_LINREG;         // Control bit to enable the regulator output.
}  // namespace REG_2P5_CLR

// Regulator 2P5 Register
namespace REG_2P5_TOG {
constexpr PMU_Reg<&PMU_Layout::REG_2P5_TOG, 1, 18, 0x0> ENABLE_WEAK_LINREG;    // Enables the weak 2p5 regulator
constexpr PMU_Reg<regs::constify(&PMU_Layout::REG_2P5_TOG), 1, 17> OK_VDD2P5;  // Status bit that signals when the regulator output is ok.
    // 1 = regulator output > brownout target
constexpr PMU_Reg<regs::constify(&PMU_Layout::REG_2P5_TOG), 1, 16> BO_VDD2P5;  // Status bit that signals when a brownout is detected on the regulator output.
constexpr PMU_Reg<&PMU_Layout::REG_2P5_TOG, 5,  8, 0x0> OUTPUT_TRG;            // Control bits to adjust the regulator output voltage
    // 0b00000..2.10V
    // 0b10000..2.50V
    // 0b11111..2.875V
constexpr PMU_Reg<&PMU_Layout::REG_2P5_TOG, 3,  4, 0x0> BO_OFFSET;             // Control bits to adjust the regulator brownout offset voltage in 25mV steps
constexpr PMU_Reg<&PMU_Layout::REG_2P5_TOG, 1,  3, 0x0> ENABLE_PULLDOWN;       // Control bit to enable the pull-down circuitry in the regulator
constexpr PMU_Reg<&PMU_Layout::REG_2P5_TOG, 1,  2, 0x0> ENABLE_ILIMIT;         // Control bit to enable the current-limit circuitry in the regulator.
constexpr PMU_Reg<&PMU_Layout::REG_2P5_TOG, 1,  1, 0x0> ENABLE_BO;             // Control bit to enable the brownout circuitry in the regulator.
constexpr PMU_Reg<&PMU_Layout::REG_2P5_TOG, 1,  0, 0x0> ENABLE_LINREG;         // Control bit to enable the regulator output.
}  // namespace REG_2P5_TOG

// Digital Regulator Core Register
namespace REG_CORE {
constexpr PMU_Reg<&PMU_Layout::REG_CORE, 1, 29> FET_ODRIVE;  // If set, increases the gate drive on power gating FETs to reduce leakage in the off state
constexpr PMU_Reg<&PMU_Layout::REG_CORE, 2, 27> RAMP_RATE;   // Regulator voltage ramp rate.
    // 0b00..Fast
    // 0b01..Medium Fast
    // 0b10..Medium Slow
    // 0b11..Slow
constexpr PMU_Reg<&PMU_Layout::REG_CORE, 4, 23> REG2_ADJ;    // This bit field defines the adjustment bits to calibrate the target value of Reg2.
    // The adjustment is applied on top on any adjustment applied to the global reference in the misc0 register.
    // 0b0000..No adjustment
    // 0b0001..+ 0.25%
    // 0b0010..+ 0.50%
    // 0b0011..+ 0.75%
    // 0b0100..+ 1.00%
    // 0b0101..+ 1.25%
    // 0b0110..+ 1.50%
    // 0b0111..+ 1.75%
    // 0b1000..- 0.25%
    // 0b1001..- 0.50%
    // 0b1010..- 0.75%
    // 0b1011..- 1.00%
    // 0b1100..- 1.25%
    // 0b1101..- 1.50%
    // 0b1110..- 1.75%
    // 0b1111..- 2.00%
constexpr PMU_Reg<&PMU_Layout::REG_CORE, 5, 18> REG2_TARG;   // This field defines the target voltage for the SOC power domain
    // 0b00000..Power gated off
    // 0b00001..Target core voltage = 0.725V
    // 0b00010..Target core voltage = 0.750V
    // 0b00011..Target core voltage = 0.775V
    // 0b10000..Target core voltage = 1.100V
    // 0b11110..Target core voltage = 1.450V
    // 0b11111..Power FET switched full on. No regulation.
constexpr PMU_Reg<&PMU_Layout::REG_CORE, 4, 14> REG1_ADJ;    // This bit field defines the adjustment bits to calibrate the target value of Reg1.
    // The adjustment is applied on top on any adjustment applied to the global reference in the misc0 register.
    // 0b0000..No adjustment
    // 0b0001..+ 0.25%
    // 0b0010..+ 0.50%
    // 0b0011..+ 0.75%
    // 0b0100..+ 1.00%
    // 0b0101..+ 1.25%
    // 0b0110..+ 1.50%
    // 0b0111..+ 1.75%
    // 0b1000..- 0.25%
    // 0b1001..- 0.50%
    // 0b1010..- 0.75%
    // 0b1011..- 1.00%
    // 0b1100..- 1.25%
    // 0b1101..- 1.50%
    // 0b1110..- 1.75%
    // 0b1111..- 2.00%
constexpr PMU_Reg<&PMU_Layout::REG_CORE, 5,  9> REG1_TARG;   // This bit field defines the target voltage for the vpu/gpu power domain.
    // Single bit increments reflect 25mV core voltage steps. Not all steps will make sense to use either because of input supply limitations or load operation.
    // 0b00000..Power gated off
    // 0b00001..Target core voltage = 0.725V
    // 0b00010..Target core voltage = 0.750V
    // 0b00011..Target core voltage = 0.775V
    // 0b10000..Target core voltage = 1.100V
    // 0b11110..Target core voltage = 1.450V
    // 0b11111..Power FET switched full on. No regulation.
constexpr PMU_Reg<&PMU_Layout::REG_CORE, 4,  5> REG0_ADJ;    // This bit field defines the adjustment bits to calibrate the target value of Reg0.
    // The adjustment is applied on top on any adjustment applied to the global reference in the misc0 register.
    // 0b0000..No adjustment
    // 0b0001..+ 0.25%
    // 0b0010..+ 0.50%
    // 0b0011..+ 0.75%
    // 0b0100..+ 1.00%
    // 0b0101..+ 1.25%
    // 0b0110..+ 1.50%
    // 0b0111..+ 1.75%
    // 0b1000..- 0.25%
    // 0b1001..- 0.50%
    // 0b1010..- 0.75%
    // 0b1011..- 1.00%
    // 0b1100..- 1.25%
    // 0b1101..- 1.50%
    // 0b1110..- 1.75%
    // 0b1111..- 2.00%
constexpr PMU_Reg<&PMU_Layout::REG_CORE, 5,  0> REG0_TARG;   // This field defines the target voltage for the Arm core power domain
    // 0b00000..Power gated off
    // 0b00001..Target core voltage = 0.725V
    // 0b00010..Target core voltage = 0.750V
    // 0b00011..Target core voltage = 0.775V
    // 0b10000..Target core voltage = 1.100V
    // 0b11110..Target core voltage = 1.450V
    // 0b11111..Power FET switched full on. No regulation.
}  // namespace REG_CORE

// Digital Regulator Core Register
namespace REG_CORE_SET {
constexpr PMU_Reg<&PMU_Layout::REG_CORE_SET, 1, 29, 0x0> FET_ODRIVE;  // If set, increases the gate drive on power gating FETs to reduce leakage in the off state
constexpr PMU_Reg<&PMU_Layout::REG_CORE_SET, 2, 27, 0x0> RAMP_RATE;   // Regulator voltage ramp rate.
    // 0b00..Fast
    // 0b01..Medium Fast
    // 0b10..Medium Slow
    // 0b11..Slow
constexpr PMU_Reg<&PMU_Layout::REG_CORE_SET, 4, 23, 0x0> REG2_ADJ;    // This bit field defines the adjustment bits to calibrate the target value of Reg2.
    // The adjustment is applied on top on any adjustment applied to the global reference in the misc0 register.
    // 0b0000..No adjustment
    // 0b0001..+ 0.25%
    // 0b0010..+ 0.50%
    // 0b0011..+ 0.75%
    // 0b0100..+ 1.00%
    // 0b0101..+ 1.25%
    // 0b0110..+ 1.50%
    // 0b0111..+ 1.75%
    // 0b1000..- 0.25%
    // 0b1001..- 0.50%
    // 0b1010..- 0.75%
    // 0b1011..- 1.00%
    // 0b1100..- 1.25%
    // 0b1101..- 1.50%
    // 0b1110..- 1.75%
    // 0b1111..- 2.00%
constexpr PMU_Reg<&PMU_Layout::REG_CORE_SET, 5, 18, 0x0> REG2_TARG;   // This field defines the target voltage for the SOC power domain
    // 0b00000..Power gated off
    // 0b00001..Target core voltage = 0.725V
    // 0b00010..Target core voltage = 0.750V
    // 0b00011..Target core voltage = 0.775V
    // 0b10000..Target core voltage = 1.100V
    // 0b11110..Target core voltage = 1.450V
    // 0b11111..Power FET switched full on. No regulation.
constexpr PMU_Reg<&PMU_Layout::REG_CORE_SET, 4, 14, 0x0> REG1_ADJ;    // This bit field defines the adjustment bits to calibrate the target value of Reg1.
    // The adjustment is applied on top on any adjustment applied to the global reference in the misc0 register.
    // 0b0000..No adjustment
    // 0b0001..+ 0.25%
    // 0b0010..+ 0.50%
    // 0b0011..+ 0.75%
    // 0b0100..+ 1.00%
    // 0b0101..+ 1.25%
    // 0b0110..+ 1.50%
    // 0b0111..+ 1.75%
    // 0b1000..- 0.25%
    // 0b1001..- 0.50%
    // 0b1010..- 0.75%
    // 0b1011..- 1.00%
    // 0b1100..- 1.25%
    // 0b1101..- 1.50%
    // 0b1110..- 1.75%
    // 0b1111..- 2.00%
constexpr PMU_Reg<&PMU_Layout::REG_CORE_SET, 5,  9, 0x0> REG1_TARG;   // This bit field defines the target voltage for the vpu/gpu power domain.
    // Single bit increments reflect 25mV core voltage steps. Not all steps will make sense to use either because of input supply limitations or load operation.
    // 0b00000..Power gated off
    // 0b00001..Target core voltage = 0.725V
    // 0b00010..Target core voltage = 0.750V
    // 0b00011..Target core voltage = 0.775V
    // 0b10000..Target core voltage = 1.100V
    // 0b11110..Target core voltage = 1.450V
    // 0b11111..Power FET switched full on. No regulation.
constexpr PMU_Reg<&PMU_Layout::REG_CORE_SET, 4,  5, 0x0> REG0_ADJ;    // This bit field defines the adjustment bits to calibrate the target value of Reg0.
    // The adjustment is applied on top on any adjustment applied to the global reference in the misc0 register.
    // 0b0000..No adjustment
    // 0b0001..+ 0.25%
    // 0b0010..+ 0.50%
    // 0b0011..+ 0.75%
    // 0b0100..+ 1.00%
    // 0b0101..+ 1.25%
    // 0b0110..+ 1.50%
    // 0b0111..+ 1.75%
    // 0b1000..- 0.25%
    // 0b1001..- 0.50%
    // 0b1010..- 0.75%
    // 0b1011..- 1.00%
    // 0b1100..- 1.25%
    // 0b1101..- 1.50%
    // 0b1110..- 1.75%
    // 0b1111..- 2.00%
constexpr PMU_Reg<&PMU_Layout::REG_CORE_SET, 5,  0, 0x0> REG0_TARG;   // This field defines the target voltage for the Arm core power domain
    // 0b00000..Power gated off
    // 0b00001..Target core voltage = 0.725V
    // 0b00010..Target core voltage = 0.750V
    // 0b00011..Target core voltage = 0.775V
    // 0b10000..Target core voltage = 1.100V
    // 0b11110..Target core voltage = 1.450V
    // 0b11111..Power FET switched full on. No regulation.
}  // namespace REG_CORE_SET

// Digital Regulator Core Register
namespace REG_CORE_CLR {
constexpr PMU_Reg<&PMU_Layout::REG_CORE_CLR, 1, 29, 0x0> FET_ODRIVE;  // If set, increases the gate drive on power gating FETs to reduce leakage in the off state
constexpr PMU_Reg<&PMU_Layout::REG_CORE_CLR, 2, 27, 0x0> RAMP_RATE;   // Regulator voltage ramp rate.
    // 0b00..Fast
    // 0b01..Medium Fast
    // 0b10..Medium Slow
    // 0b11..Slow
constexpr PMU_Reg<&PMU_Layout::REG_CORE_CLR, 4, 23, 0x0> REG2_ADJ;    // This bit field defines the adjustment bits to calibrate the target value of Reg2.
    // The adjustment is applied on top on any adjustment applied to the global reference in the misc0 register.
    // 0b0000..No adjustment
    // 0b0001..+ 0.25%
    // 0b0010..+ 0.50%
    // 0b0011..+ 0.75%
    // 0b0100..+ 1.00%
    // 0b0101..+ 1.25%
    // 0b0110..+ 1.50%
    // 0b0111..+ 1.75%
    // 0b1000..- 0.25%
    // 0b1001..- 0.50%
    // 0b1010..- 0.75%
    // 0b1011..- 1.00%
    // 0b1100..- 1.25%
    // 0b1101..- 1.50%
    // 0b1110..- 1.75%
    // 0b1111..- 2.00%
constexpr PMU_Reg<&PMU_Layout::REG_CORE_CLR, 5, 18, 0x0> REG2_TARG;   // This field defines the target voltage for the SOC power domain
    // 0b00000..Power gated off
    // 0b00001..Target core voltage = 0.725V
    // 0b00010..Target core voltage = 0.750V
    // 0b00011..Target core voltage = 0.775V
    // 0b10000..Target core voltage = 1.100V
    // 0b11110..Target core voltage = 1.450V
    // 0b11111..Power FET switched full on. No regulation.
constexpr PMU_Reg<&PMU_Layout::REG_CORE_CLR, 4, 14, 0x0> REG1_ADJ;    // This bit field defines the adjustment bits to calibrate the target value of Reg1.
    // The adjustment is applied on top on any adjustment applied to the global reference in the misc0 register.
    // 0b0000..No adjustment
    // 0b0001..+ 0.25%
    // 0b0010..+ 0.50%
    // 0b0011..+ 0.75%
    // 0b0100..+ 1.00%
    // 0b0101..+ 1.25%
    // 0b0110..+ 1.50%
    // 0b0111..+ 1.75%
    // 0b1000..- 0.25%
    // 0b1001..- 0.50%
    // 0b1010..- 0.75%
    // 0b1011..- 1.00%
    // 0b1100..- 1.25%
    // 0b1101..- 1.50%
    // 0b1110..- 1.75%
    // 0b1111..- 2.00%
constexpr PMU_Reg<&PMU_Layout::REG_CORE_CLR, 5,  9, 0x0> REG1_TARG;   // This bit field defines the target voltage for the vpu/gpu power domain.
    // Single bit increments reflect 25mV core voltage steps. Not all steps will make sense to use either because of input supply limitations or load operation.
    // 0b00000..Power gated off
    // 0b00001..Target core voltage = 0.725V
    // 0b00010..Target core voltage = 0.750V
    // 0b00011..Target core voltage = 0.775V
    // 0b10000..Target core voltage = 1.100V
    // 0b11110..Target core voltage = 1.450V
    // 0b11111..Power FET switched full on. No regulation.
constexpr PMU_Reg<&PMU_Layout::REG_CORE_CLR, 4,  5, 0x0> REG0_ADJ;    // This bit field defines the adjustment bits to calibrate the target value of Reg0.
    // The adjustment is applied on top on any adjustment applied to the global reference in the misc0 register.
    // 0b0000..No adjustment
    // 0b0001..+ 0.25%
    // 0b0010..+ 0.50%
    // 0b0011..+ 0.75%
    // 0b0100..+ 1.00%
    // 0b0101..+ 1.25%
    // 0b0110..+ 1.50%
    // 0b0111..+ 1.75%
    // 0b1000..- 0.25%
    // 0b1001..- 0.50%
    // 0b1010..- 0.75%
    // 0b1011..- 1.00%
    // 0b1100..- 1.25%
    // 0b1101..- 1.50%
    // 0b1110..- 1.75%
    // 0b1111..- 2.00%
constexpr PMU_Reg<&PMU_Layout::REG_CORE_CLR, 5,  0, 0x0> REG0_TARG;   // This field defines the target voltage for the Arm core power domain
    // 0b00000..Power gated off
    // 0b00001..Target core voltage = 0.725V
    // 0b00010..Target core voltage = 0.750V
    // 0b00011..Target core voltage = 0.775V
    // 0b10000..Target core voltage = 1.100V
    // 0b11110..Target core voltage = 1.450V
    // 0b11111..Power FET switched full on. No regulation.
}  // namespace REG_CORE_CLR

// Digital Regulator Core Register
namespace REG_CORE_TOG {
constexpr PMU_Reg<&PMU_Layout::REG_CORE_TOG, 1, 29, 0x0> FET_ODRIVE;  // If set, increases the gate drive on power gating FETs to reduce leakage in the off state
constexpr PMU_Reg<&PMU_Layout::REG_CORE_TOG, 2, 27, 0x0> RAMP_RATE;   // Regulator voltage ramp rate.
    // 0b00..Fast
    // 0b01..Medium Fast
    // 0b10..Medium Slow
    // 0b11..Slow
constexpr PMU_Reg<&PMU_Layout::REG_CORE_TOG, 4, 23, 0x0> REG2_ADJ;    // This bit field defines the adjustment bits to calibrate the target value of Reg2.
    // The adjustment is applied on top on any adjustment applied to the global reference in the misc0 register.
    // 0b0000..No adjustment
    // 0b0001..+ 0.25%
    // 0b0010..+ 0.50%
    // 0b0011..+ 0.75%
    // 0b0100..+ 1.00%
    // 0b0101..+ 1.25%
    // 0b0110..+ 1.50%
    // 0b0111..+ 1.75%
    // 0b1000..- 0.25%
    // 0b1001..- 0.50%
    // 0b1010..- 0.75%
    // 0b1011..- 1.00%
    // 0b1100..- 1.25%
    // 0b1101..- 1.50%
    // 0b1110..- 1.75%
    // 0b1111..- 2.00%
constexpr PMU_Reg<&PMU_Layout::REG_CORE_TOG, 5, 18, 0x0> REG2_TARG;   // This field defines the target voltage for the SOC power domain
    // 0b00000..Power gated off
    // 0b00001..Target core voltage = 0.725V
    // 0b00010..Target core voltage = 0.750V
    // 0b00011..Target core voltage = 0.775V
    // 0b10000..Target core voltage = 1.100V
    // 0b11110..Target core voltage = 1.450V
    // 0b11111..Power FET switched full on. No regulation.
constexpr PMU_Reg<&PMU_Layout::REG_CORE_TOG, 4, 14, 0x0> REG1_ADJ;    // This bit field defines the adjustment bits to calibrate the target value of Reg1.
    // The adjustment is applied on top on any adjustment applied to the global reference in the misc0 register.
    // 0b0000..No adjustment
    // 0b0001..+ 0.25%
    // 0b0010..+ 0.50%
    // 0b0011..+ 0.75%
    // 0b0100..+ 1.00%
    // 0b0101..+ 1.25%
    // 0b0110..+ 1.50%
    // 0b0111..+ 1.75%
    // 0b1000..- 0.25%
    // 0b1001..- 0.50%
    // 0b1010..- 0.75%
    // 0b1011..- 1.00%
    // 0b1100..- 1.25%
    // 0b1101..- 1.50%
    // 0b1110..- 1.75%
    // 0b1111..- 2.00%
constexpr PMU_Reg<&PMU_Layout::REG_CORE_TOG, 5,  9, 0x0> REG1_TARG;   // This bit field defines the target voltage for the vpu/gpu power domain.
    // Single bit increments reflect 25mV core voltage steps. Not all steps will make sense to use either because of input supply limitations or load operation.
    // 0b00000..Power gated off
    // 0b00001..Target core voltage = 0.725V
    // 0b00010..Target core voltage = 0.750V
    // 0b00011..Target core voltage = 0.775V
    // 0b10000..Target core voltage = 1.100V
    // 0b11110..Target core voltage = 1.450V
    // 0b11111..Power FET switched full on. No regulation.
constexpr PMU_Reg<&PMU_Layout::REG_CORE_TOG, 4,  5, 0x0> REG0_ADJ;    // This bit field defines the adjustment bits to calibrate the target value of Reg0.
    // The adjustment is applied on top on any adjustment applied to the global reference in the misc0 register.
    // 0b0000..No adjustment
    // 0b0001..+ 0.25%
    // 0b0010..+ 0.50%
    // 0b0011..+ 0.75%
    // 0b0100..+ 1.00%
    // 0b0101..+ 1.25%
    // 0b0110..+ 1.50%
    // 0b0111..+ 1.75%
    // 0b1000..- 0.25%
    // 0b1001..- 0.50%
    // 0b1010..- 0.75%
    // 0b1011..- 1.00%
    // 0b1100..- 1.25%
    // 0b1101..- 1.50%
    // 0b1110..- 1.75%
    // 0b1111..- 2.00%
constexpr PMU_Reg<&PMU_Layout::REG_CORE_TOG, 5,  0, 0x0> REG0_TARG;   // This field defines the target voltage for the Arm core power domain
    // 0b00000..Power gated off
    // 0b00001..Target core voltage = 0.725V
    // 0b00010..Target core voltage = 0.750V
    // 0b00011..Target core voltage = 0.775V
    // 0b10000..Target core voltage = 1.100V
    // 0b11110..Target core voltage = 1.450V
    // 0b11111..Power FET switched full on. No regulation.
}  // namespace REG_CORE_TOG

// Miscellaneous Register 0
namespace MISC0 {
constexpr PMU_Reg<&PMU_Layout::MISC0, 1, 31> VID_PLL_PREDIV;                   // Predivider for the source clock of the PLL's.
    // 0b0..Divide by 1
    // 0b1..Divide by 2
constexpr PMU_Reg<&PMU_Layout::MISC0, 1, 30> XTAL_24M_PWD;                     // This field powers down the 24M crystal oscillator if set true.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC0), 1, 29> RTC_XTAL_SOURCE;  // This field indicates which chip source is being used for the rtc clock.
    // 0b0..Internal ring oscillator
    // 0b1..RTC_XTAL
constexpr PMU_Reg<&PMU_Layout::MISC0, 3, 26> CLKGATE_DELAY;                    // This field specifies the delay between powering up the XTAL 24MHz clock and releasing the clock to the digital logic inside the analog block
    // 0b000..0.5ms
    // 0b001..1.0ms
    // 0b010..2.0ms
    // 0b011..3.0ms
    // 0b100..4.0ms
    // 0b101..5.0ms
    // 0b110..6.0ms
    // 0b111..7.0ms
constexpr PMU_Reg<&PMU_Layout::MISC0, 1, 25> CLKGATE_CTRL;                     // This bit allows disabling the clock gate (always ungated) for the xtal 24MHz clock that clocks the digital logic in the analog block
    // 0b0..Allow the logic to automatically gate the clock when the XTAL is powered down.
    // 0b1..Prevent the logic from ever gating off the clock.
constexpr PMU_Reg<&PMU_Layout::MISC0, 1, 16> OSC_XTALOK_EN;                    // This bit enables the detector that signals when the 24MHz crystal oscillator is stable
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC0), 1, 15> OSC_XTALOK;       // Status bit that signals that the output of the 24-MHz crystal oscillator is stable
constexpr PMU_Reg<&PMU_Layout::MISC0, 2, 13> OSC_I;                            // This field determines the bias current in the 24MHz oscillator
    // 0b00..Nominal
    // 0b01..Decrease current by 12.5%
    // 0b10..Decrease current by 25.0%
    // 0b11..Decrease current by 37.5%
constexpr PMU_Reg<&PMU_Layout::MISC0, 1, 12> DISCON_HIGH_SNVS;                 // This bit controls a switch from VDD_HIGH_IN to VDD_SNVS_IN.
    // 0b0..Turn on the switch
    // 0b1..Turn off the switch
constexpr PMU_Reg<&PMU_Layout::MISC0, 2, 10> STOP_MODE_CONFIG;                 // Configure the analog behavior in stop mode.
    // 0b00..SUSPEND (DSM)
    // 0b01..Analog regulators are ON.
    // 0b10..STOP (lower power)
    // 0b11..STOP (very lower power)
constexpr PMU_Reg<&PMU_Layout::MISC0, 1,  7> REFTOP_VBGUP;                     // Status bit that signals the analog bandgap voltage is up and stable.
    // 1 - Stable.
constexpr PMU_Reg<&PMU_Layout::MISC0, 3,  4> REFTOP_VBGADJ;
    // 0b000..Nominal VBG
    // 0b001..VBG+0.78%
    // 0b010..VBG+1.56%
    // 0b011..VBG+2.34%
    // 0b100..VBG-0.78%
    // 0b101..VBG-1.56%
    // 0b110..VBG-2.34%
    // 0b111..VBG-3.12%
constexpr PMU_Reg<&PMU_Layout::MISC0, 1,  3> REFTOP_SELFBIASOFF;               // Control bit to disable the self-bias circuit in the analog bandgap
    // 0b0..Uses coarse bias currents for startup
    // 0b1..Uses bandgap-based bias currents for best performance.
constexpr PMU_Reg<&PMU_Layout::MISC0, 1,  2> REFTOP_LOWPOWER;                  // Control bit to enable the low-power mode in the analog bandgap.
constexpr PMU_Reg<&PMU_Layout::MISC0, 1,  1> REFTOP_PWDVBGUP;                  // Control bit to power down the VBG-up detection circuitry in the analog bandgap.
constexpr PMU_Reg<&PMU_Layout::MISC0, 1,  0> REFTOP_PWD;                       // Control bit to power-down the analog bandgap reference circuitry
}  // namespace MISC0

// Miscellaneous Register 0
namespace MISC0_SET {
constexpr PMU_Reg<&PMU_Layout::MISC0_SET, 1, 31, 0x0> VID_PLL_PREDIV;              // Predivider for the source clock of the PLL's.
    // 0b0..Divide by 1
    // 0b1..Divide by 2
constexpr PMU_Reg<&PMU_Layout::MISC0_SET, 1, 30, 0x0> XTAL_24M_PWD;                // This field powers down the 24M crystal oscillator if set true.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC0_SET), 1, 29> RTC_XTAL_SOURCE;  // This field indicates which chip source is being used for the rtc clock.
    // 0b0..Internal ring oscillator
    // 0b1..RTC_XTAL
constexpr PMU_Reg<&PMU_Layout::MISC0_SET, 3, 26, 0x0> CLKGATE_DELAY;               // This field specifies the delay between powering up the XTAL 24MHz clock and releasing the clock to the digital logic inside the analog block
    // 0b000..0.5ms
    // 0b001..1.0ms
    // 0b010..2.0ms
    // 0b011..3.0ms
    // 0b100..4.0ms
    // 0b101..5.0ms
    // 0b110..6.0ms
    // 0b111..7.0ms
constexpr PMU_Reg<&PMU_Layout::MISC0_SET, 1, 25, 0x0> CLKGATE_CTRL;                // This bit allows disabling the clock gate (always ungated) for the xtal 24MHz clock that clocks the digital logic in the analog block
    // 0b0..Allow the logic to automatically gate the clock when the XTAL is powered down.
    // 0b1..Prevent the logic from ever gating off the clock.
constexpr PMU_Reg<&PMU_Layout::MISC0_SET, 1, 16, 0x0> OSC_XTALOK_EN;               // This bit enables the detector that signals when the 24MHz crystal oscillator is stable
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC0_SET), 1, 15> OSC_XTALOK;       // Status bit that signals that the output of the 24-MHz crystal oscillator is stable
constexpr PMU_Reg<&PMU_Layout::MISC0_SET, 2, 13, 0x0> OSC_I;                       // This field determines the bias current in the 24MHz oscillator
    // 0b00..Nominal
    // 0b01..Decrease current by 12.5%
    // 0b10..Decrease current by 25.0%
    // 0b11..Decrease current by 37.5%
constexpr PMU_Reg<&PMU_Layout::MISC0_SET, 1, 12, 0x0> DISCON_HIGH_SNVS;            // This bit controls a switch from VDD_HIGH_IN to VDD_SNVS_IN.
    // 0b0..Turn on the switch
    // 0b1..Turn off the switch
constexpr PMU_Reg<&PMU_Layout::MISC0_SET, 2, 10, 0x0> STOP_MODE_CONFIG;            // Configure the analog behavior in stop mode.
    // 0b00..SUSPEND (DSM)
    // 0b01..Analog regulators are ON.
    // 0b10..STOP (lower power)
    // 0b11..STOP (very lower power)
constexpr PMU_Reg<&PMU_Layout::MISC0_SET, 1,  7, 0x0> REFTOP_VBGUP;                // Status bit that signals the analog bandgap voltage is up and stable.
    // 1 - Stable.
constexpr PMU_Reg<&PMU_Layout::MISC0_SET, 3,  4, 0x0> REFTOP_VBGADJ;
    // 0b000..Nominal VBG
    // 0b001..VBG+0.78%
    // 0b010..VBG+1.56%
    // 0b011..VBG+2.34%
    // 0b100..VBG-0.78%
    // 0b101..VBG-1.56%
    // 0b110..VBG-2.34%
    // 0b111..VBG-3.12%
constexpr PMU_Reg<&PMU_Layout::MISC0_SET, 1,  3, 0x0> REFTOP_SELFBIASOFF;          // Control bit to disable the self-bias circuit in the analog bandgap
    // 0b0..Uses coarse bias currents for startup
    // 0b1..Uses bandgap-based bias currents for best performance.
constexpr PMU_Reg<&PMU_Layout::MISC0_SET, 1,  2, 0x0> REFTOP_LOWPOWER;             // Control bit to enable the low-power mode in the analog bandgap.
constexpr PMU_Reg<&PMU_Layout::MISC0_SET, 1,  1, 0x0> REFTOP_PWDVBGUP;             // Control bit to power down the VBG-up detection circuitry in the analog bandgap.
constexpr PMU_Reg<&PMU_Layout::MISC0_SET, 1,  0, 0x0> REFTOP_PWD;                  // Control bit to power-down the analog bandgap reference circuitry
}  // namespace MISC0_SET

// Miscellaneous Register 0
namespace MISC0_CLR {
constexpr PMU_Reg<&PMU_Layout::MISC0_CLR, 1, 31, 0x0> VID_PLL_PREDIV;              // Predivider for the source clock of the PLL's.
    // 0b0..Divide by 1
    // 0b1..Divide by 2
constexpr PMU_Reg<&PMU_Layout::MISC0_CLR, 1, 30, 0x0> XTAL_24M_PWD;                // This field powers down the 24M crystal oscillator if set true.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC0_CLR), 1, 29> RTC_XTAL_SOURCE;  // This field indicates which chip source is being used for the rtc clock.
    // 0b0..Internal ring oscillator
    // 0b1..RTC_XTAL
constexpr PMU_Reg<&PMU_Layout::MISC0_CLR, 3, 26, 0x0> CLKGATE_DELAY;               // This field specifies the delay between powering up the XTAL 24MHz clock and releasing the clock to the digital logic inside the analog block
    // 0b000..0.5ms
    // 0b001..1.0ms
    // 0b010..2.0ms
    // 0b011..3.0ms
    // 0b100..4.0ms
    // 0b101..5.0ms
    // 0b110..6.0ms
    // 0b111..7.0ms
constexpr PMU_Reg<&PMU_Layout::MISC0_CLR, 1, 25, 0x0> CLKGATE_CTRL;                // This bit allows disabling the clock gate (always ungated) for the xtal 24MHz clock that clocks the digital logic in the analog block
    // 0b0..Allow the logic to automatically gate the clock when the XTAL is powered down.
    // 0b1..Prevent the logic from ever gating off the clock.
constexpr PMU_Reg<&PMU_Layout::MISC0_CLR, 1, 16, 0x0> OSC_XTALOK_EN;               // This bit enables the detector that signals when the 24MHz crystal oscillator is stable
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC0_CLR), 1, 15> OSC_XTALOK;       // Status bit that signals that the output of the 24-MHz crystal oscillator is stable
constexpr PMU_Reg<&PMU_Layout::MISC0_CLR, 2, 13, 0x0> OSC_I;                       // This field determines the bias current in the 24MHz oscillator
    // 0b00..Nominal
    // 0b01..Decrease current by 12.5%
    // 0b10..Decrease current by 25.0%
    // 0b11..Decrease current by 37.5%
constexpr PMU_Reg<&PMU_Layout::MISC0_CLR, 1, 12, 0x0> DISCON_HIGH_SNVS;            // This bit controls a switch from VDD_HIGH_IN to VDD_SNVS_IN.
    // 0b0..Turn on the switch
    // 0b1..Turn off the switch
constexpr PMU_Reg<&PMU_Layout::MISC0_CLR, 2, 10, 0x0> STOP_MODE_CONFIG;            // Configure the analog behavior in stop mode.
    // 0b00..SUSPEND (DSM)
    // 0b01..Analog regulators are ON.
    // 0b10..STOP (lower power)
    // 0b11..STOP (very lower power)
constexpr PMU_Reg<&PMU_Layout::MISC0_CLR, 1,  7, 0x0> REFTOP_VBGUP;                // Status bit that signals the analog bandgap voltage is up and stable.
    // 1 - Stable.
constexpr PMU_Reg<&PMU_Layout::MISC0_CLR, 3,  4, 0x0> REFTOP_VBGADJ;
    // 0b000..Nominal VBG
    // 0b001..VBG+0.78%
    // 0b010..VBG+1.56%
    // 0b011..VBG+2.34%
    // 0b100..VBG-0.78%
    // 0b101..VBG-1.56%
    // 0b110..VBG-2.34%
    // 0b111..VBG-3.12%
constexpr PMU_Reg<&PMU_Layout::MISC0_CLR, 1,  3, 0x0> REFTOP_SELFBIASOFF;          // Control bit to disable the self-bias circuit in the analog bandgap
    // 0b0..Uses coarse bias currents for startup
    // 0b1..Uses bandgap-based bias currents for best performance.
constexpr PMU_Reg<&PMU_Layout::MISC0_CLR, 1,  2, 0x0> REFTOP_LOWPOWER;             // Control bit to enable the low-power mode in the analog bandgap.
constexpr PMU_Reg<&PMU_Layout::MISC0_CLR, 1,  1, 0x0> REFTOP_PWDVBGUP;             // Control bit to power down the VBG-up detection circuitry in the analog bandgap.
constexpr PMU_Reg<&PMU_Layout::MISC0_CLR, 1,  0, 0x0> REFTOP_PWD;                  // Control bit to power-down the analog bandgap reference circuitry
}  // namespace MISC0_CLR

// Miscellaneous Register 0
namespace MISC0_TOG {
constexpr PMU_Reg<&PMU_Layout::MISC0_TOG, 1, 31, 0x0> VID_PLL_PREDIV;              // Predivider for the source clock of the PLL's.
    // 0b0..Divide by 1
    // 0b1..Divide by 2
constexpr PMU_Reg<&PMU_Layout::MISC0_TOG, 1, 30, 0x0> XTAL_24M_PWD;                // This field powers down the 24M crystal oscillator if set true.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC0_TOG), 1, 29> RTC_XTAL_SOURCE;  // This field indicates which chip source is being used for the rtc clock.
    // 0b0..Internal ring oscillator
    // 0b1..RTC_XTAL
constexpr PMU_Reg<&PMU_Layout::MISC0_TOG, 3, 26, 0x0> CLKGATE_DELAY;               // This field specifies the delay between powering up the XTAL 24MHz clock and releasing the clock to the digital logic inside the analog block
    // 0b000..0.5ms
    // 0b001..1.0ms
    // 0b010..2.0ms
    // 0b011..3.0ms
    // 0b100..4.0ms
    // 0b101..5.0ms
    // 0b110..6.0ms
    // 0b111..7.0ms
constexpr PMU_Reg<&PMU_Layout::MISC0_TOG, 1, 25, 0x0> CLKGATE_CTRL;                // This bit allows disabling the clock gate (always ungated) for the xtal 24MHz clock that clocks the digital logic in the analog block
    // 0b0..Allow the logic to automatically gate the clock when the XTAL is powered down.
    // 0b1..Prevent the logic from ever gating off the clock.
constexpr PMU_Reg<&PMU_Layout::MISC0_TOG, 1, 16, 0x0> OSC_XTALOK_EN;               // This bit enables the detector that signals when the 24MHz crystal oscillator is stable
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC0_TOG), 1, 15> OSC_XTALOK;       // Status bit that signals that the output of the 24-MHz crystal oscillator is stable
constexpr PMU_Reg<&PMU_Layout::MISC0_TOG, 2, 13, 0x0> OSC_I;                       // This field determines the bias current in the 24MHz oscillator
    // 0b00..Nominal
    // 0b01..Decrease current by 12.5%
    // 0b10..Decrease current by 25.0%
    // 0b11..Decrease current by 37.5%
constexpr PMU_Reg<&PMU_Layout::MISC0_TOG, 1, 12, 0x0> DISCON_HIGH_SNVS;            // This bit controls a switch from VDD_HIGH_IN to VDD_SNVS_IN.
    // 0b0..Turn on the switch
    // 0b1..Turn off the switch
constexpr PMU_Reg<&PMU_Layout::MISC0_TOG, 2, 10, 0x0> STOP_MODE_CONFIG;            // Configure the analog behavior in stop mode.
    // 0b00..SUSPEND (DSM)
    // 0b01..Analog regulators are ON.
    // 0b10..STOP (lower power)
    // 0b11..STOP (very lower power)
constexpr PMU_Reg<&PMU_Layout::MISC0_TOG, 1,  7, 0x0> REFTOP_VBGUP;                // Status bit that signals the analog bandgap voltage is up and stable.
    // 1 - Stable.
constexpr PMU_Reg<&PMU_Layout::MISC0_TOG, 3,  4, 0x0> REFTOP_VBGADJ;
    // 0b000..Nominal VBG
    // 0b001..VBG+0.78%
    // 0b010..VBG+1.56%
    // 0b011..VBG+2.34%
    // 0b100..VBG-0.78%
    // 0b101..VBG-1.56%
    // 0b110..VBG-2.34%
    // 0b111..VBG-3.12%
constexpr PMU_Reg<&PMU_Layout::MISC0_TOG, 1,  3, 0x0> REFTOP_SELFBIASOFF;          // Control bit to disable the self-bias circuit in the analog bandgap
    // 0b0..Uses coarse bias currents for startup
    // 0b1..Uses bandgap-based bias currents for best performance.
constexpr PMU_Reg<&PMU_Layout::MISC0_TOG, 1,  2, 0x0> REFTOP_LOWPOWER;             // Control bit to enable the low-power mode in the analog bandgap.
constexpr PMU_Reg<&PMU_Layout::MISC0_TOG, 1,  1, 0x0> REFTOP_PWDVBGUP;             // Control bit to power down the VBG-up detection circuitry in the analog bandgap.
constexpr PMU_Reg<&PMU_Layout::MISC0_TOG, 1,  0, 0x0> REFTOP_PWD;                  // Control bit to power-down the analog bandgap reference circuitry
}  // namespace MISC0_TOG

// Miscellaneous Register 1
namespace MISC1 {
constexpr uint32_t kW1C = 0xF800'0000;

constexpr PMU_Reg<&PMU_Layout::MISC1, 1, 31, kW1C> IRQ_DIG_BO;                                          // This status bit is set to one when when any of the digital regulator brownout interrupts assert
constexpr PMU_Reg<&PMU_Layout::MISC1, 1, 30, kW1C> IRQ_ANA_BO;                                          // This status bit is set to one when when any of the analog regulator brownout interrupts assert
constexpr PMU_Reg<&PMU_Layout::MISC1, 1, 29, kW1C> IRQ_TEMPHIGH;                                        // This status bit is set to one when the temperature sensor high interrupt asserts for high temperature
constexpr PMU_Reg<&PMU_Layout::MISC1, 1, 28, kW1C> IRQ_TEMPLOW;                                         // This status bit is set to one when the temperature sensor low interrupt asserts for low temperature
constexpr PMU_Reg<&PMU_Layout::MISC1, 1, 27, kW1C> IRQ_TEMPPANIC;                                       // This status bit is set to one when the temperature sensor panic interrupt asserts for a panic high temperature
constexpr PMU_Reg<&PMU_Layout::MISC1, 1, 17, regs::shiftedMask32<1, 17>() | kW1C> PFD_528_AUTOGATE_EN;  // This enables a feature that will clkgate (reset) all PFD_528 clocks anytime the PLL_528 is unlocked or powered off
constexpr PMU_Reg<&PMU_Layout::MISC1, 1, 16, regs::shiftedMask32<1, 16>() | kW1C> PFD_480_AUTOGATE_EN;  // This enables a feature that will clkgate (reset) all PFD_480 clocks anytime the USB1_PLL_480 is unlocked or powered off
constexpr PMU_Reg<&PMU_Layout::MISC1, 1, 13, regs::shiftedMask32<1, 13>() | kW1C> LVDSCLK2_IBEN;        // This enables the LVDS input buffer for anaclk2/2b
constexpr PMU_Reg<&PMU_Layout::MISC1, 1, 12, regs::shiftedMask32<1, 12>() | kW1C> LVDSCLK1_IBEN;        // This enables the LVDS input buffer for anaclk1/1b
constexpr PMU_Reg<&PMU_Layout::MISC1, 1, 11, regs::shiftedMask32<1, 11>() | kW1C> LVDSCLK2_OBEN;        // This enables the LVDS output buffer for anaclk2/2b
constexpr PMU_Reg<&PMU_Layout::MISC1, 1, 10, regs::shiftedMask32<1, 10>() | kW1C> LVDSCLK1_OBEN;        // This enables the LVDS output buffer for anaclk1/1b
constexpr PMU_Reg<&PMU_Layout::MISC1, 5,  5, regs::shiftedMask32<5,  5>() | kW1C> LVDS2_CLK_SEL;        // This field selects the clk to be routed to anaclk2/2b.
    // Not related to PMU.
    // 0b00000..ARM PLL
    // 0b00001..System PLL
    // 0b00010..ref_pfd4_clk == pll2_pfd0_clk
    // 0b00011..ref_pfd5_clk == pll2_pfd1_clk
    // 0b00100..ref_pfd6_clk == pll2_pfd2_clk
    // 0b00101..ref_pfd7_clk == pll2_pfd3_clk
    // 0b00110..Audio PLL
    // 0b00111..Video PLL
    // 0b01000..MLB PLL
    // 0b01001..ethernet ref clock (ENET_PLL)
    // 0b01010..PCIe ref clock (125M)
    // 0b01011..SATA ref clock (100M)
    // 0b01100..USB1 PLL clock
    // 0b01101..USB2 PLL clock
    // 0b01110..ref_pfd0_clk == pll3_pfd0_clk
    // 0b01111..ref_pfd1_clk == pll3_pfd1_clk
    // 0b10000..ref_pfd2_clk == pll3_pfd2_clk
    // 0b10001..ref_pfd3_clk == pll3_pfd3_clk
    // 0b10010..xtal (24M)
    // 0b10011..LVDS1 (loopback)
    // 0b10100..LVDS2 (not useful)
constexpr PMU_Reg<&PMU_Layout::MISC1, 5,  0, regs::shiftedMask32<5,  0>() | kW1C> LVDS1_CLK_SEL;        // This field selects the clk to be routed to anaclk1/1b.
    // Not related to PMU.
    // 0b00000..ARM PLL
    // 0b00001..System PLL
    // 0b00010..ref_pfd4_clk == pll2_pfd0_clk
    // 0b00011..ref_pfd5_clk == pll2_pfd1_clk
    // 0b00100..ref_pfd6_clk == pll2_pfd2_clk
    // 0b00101..ref_pfd7_clk == pll2_pfd3_clk
    // 0b00110..Audio PLL
    // 0b00111..Video PLL
    // 0b01001..ethernet ref clock (ENET_PLL)
    // 0b01100..USB1 PLL clock
    // 0b01101..USB2 PLL clock
    // 0b01110..ref_pfd0_clk == pll3_pfd0_clk
    // 0b01111..ref_pfd1_clk == pll3_pfd1_clk
    // 0b10000..ref_pfd2_clk == pll3_pfd2_clk
    // 0b10001..ref_pfd3_clk == pll3_pfd3_clk
    // 0b10010..xtal (24M)
}  // namespace MISC1

// Miscellaneous Register 1
namespace MISC1_SET {
constexpr PMU_Reg<&PMU_Layout::MISC1_SET, 1, 31, 0x0> IRQ_DIG_BO;           // This status bit is set to one when when any of the digital regulator brownout interrupts assert
constexpr PMU_Reg<&PMU_Layout::MISC1_SET, 1, 30, 0x0> IRQ_ANA_BO;           // This status bit is set to one when when any of the analog regulator brownout interrupts assert
constexpr PMU_Reg<&PMU_Layout::MISC1_SET, 1, 29, 0x0> IRQ_TEMPHIGH;         // This status bit is set to one when the temperature sensor high interrupt asserts for high temperature
constexpr PMU_Reg<&PMU_Layout::MISC1_SET, 1, 28, 0x0> IRQ_TEMPLOW;          // This status bit is set to one when the temperature sensor low interrupt asserts for low temperature
constexpr PMU_Reg<&PMU_Layout::MISC1_SET, 1, 27, 0x0> IRQ_TEMPPANIC;        // This status bit is set to one when the temperature sensor panic interrupt asserts for a panic high temperature
constexpr PMU_Reg<&PMU_Layout::MISC1_SET, 1, 17, 0x0> PFD_528_AUTOGATE_EN;  // This enables a feature that will clkgate (reset) all PFD_528 clocks anytime the PLL_528 is unlocked or powered off
constexpr PMU_Reg<&PMU_Layout::MISC1_SET, 1, 16, 0x0> PFD_480_AUTOGATE_EN;  // This enables a feature that will clkgate (reset) all PFD_480 clocks anytime the USB1_PLL_480 is unlocked or powered off
constexpr PMU_Reg<&PMU_Layout::MISC1_SET, 1, 13, 0x0> LVDSCLK2_IBEN;        // This enables the LVDS input buffer for anaclk2/2b
constexpr PMU_Reg<&PMU_Layout::MISC1_SET, 1, 12, 0x0> LVDSCLK1_IBEN;        // This enables the LVDS input buffer for anaclk1/1b
constexpr PMU_Reg<&PMU_Layout::MISC1_SET, 1, 11, 0x0> LVDSCLK2_OBEN;        // This enables the LVDS output buffer for anaclk2/2b
constexpr PMU_Reg<&PMU_Layout::MISC1_SET, 1, 10, 0x0> LVDSCLK1_OBEN;        // This enables the LVDS output buffer for anaclk1/1b
constexpr PMU_Reg<&PMU_Layout::MISC1_SET, 5,  5, 0x0> LVDS2_CLK_SEL;        // This field selects the clk to be routed to anaclk2/2b.
    // Not related to PMU.
    // 0b00000..ARM PLL
    // 0b00001..System PLL
    // 0b00010..ref_pfd4_clk == pll2_pfd0_clk
    // 0b00011..ref_pfd5_clk == pll2_pfd1_clk
    // 0b00100..ref_pfd6_clk == pll2_pfd2_clk
    // 0b00101..ref_pfd7_clk == pll2_pfd3_clk
    // 0b00110..Audio PLL
    // 0b00111..Video PLL
    // 0b01000..MLB PLL
    // 0b01001..ethernet ref clock (ENET_PLL)
    // 0b01010..PCIe ref clock (125M)
    // 0b01011..SATA ref clock (100M)
    // 0b01100..USB1 PLL clock
    // 0b01101..USB2 PLL clock
    // 0b01110..ref_pfd0_clk == pll3_pfd0_clk
    // 0b01111..ref_pfd1_clk == pll3_pfd1_clk
    // 0b10000..ref_pfd2_clk == pll3_pfd2_clk
    // 0b10001..ref_pfd3_clk == pll3_pfd3_clk
    // 0b10010..xtal (24M)
    // 0b10011..LVDS1 (loopback)
    // 0b10100..LVDS2 (not useful)
constexpr PMU_Reg<&PMU_Layout::MISC1_SET, 5,  0, 0x0> LVDS1_CLK_SEL;        // This field selects the clk to be routed to anaclk1/1b.
    // Not related to PMU.
    // 0b00000..ARM PLL
    // 0b00001..System PLL
    // 0b00010..ref_pfd4_clk == pll2_pfd0_clk
    // 0b00011..ref_pfd5_clk == pll2_pfd1_clk
    // 0b00100..ref_pfd6_clk == pll2_pfd2_clk
    // 0b00101..ref_pfd7_clk == pll2_pfd3_clk
    // 0b00110..Audio PLL
    // 0b00111..Video PLL
    // 0b01001..ethernet ref clock (ENET_PLL)
    // 0b01100..USB1 PLL clock
    // 0b01101..USB2 PLL clock
    // 0b01110..ref_pfd0_clk == pll3_pfd0_clk
    // 0b01111..ref_pfd1_clk == pll3_pfd1_clk
    // 0b10000..ref_pfd2_clk == pll3_pfd2_clk
    // 0b10001..ref_pfd3_clk == pll3_pfd3_clk
    // 0b10010..xtal (24M)
}  // namespace MISC1_SET

// Miscellaneous Register 1
namespace MISC1_CLR {
constexpr PMU_Reg<&PMU_Layout::MISC1_CLR, 1, 31, 0x0> IRQ_DIG_BO;           // This status bit is set to one when when any of the digital regulator brownout interrupts assert
constexpr PMU_Reg<&PMU_Layout::MISC1_CLR, 1, 30, 0x0> IRQ_ANA_BO;           // This status bit is set to one when when any of the analog regulator brownout interrupts assert
constexpr PMU_Reg<&PMU_Layout::MISC1_CLR, 1, 29, 0x0> IRQ_TEMPHIGH;         // This status bit is set to one when the temperature sensor high interrupt asserts for high temperature
constexpr PMU_Reg<&PMU_Layout::MISC1_CLR, 1, 28, 0x0> IRQ_TEMPLOW;          // This status bit is set to one when the temperature sensor low interrupt asserts for low temperature
constexpr PMU_Reg<&PMU_Layout::MISC1_CLR, 1, 27, 0x0> IRQ_TEMPPANIC;        // This status bit is set to one when the temperature sensor panic interrupt asserts for a panic high temperature
constexpr PMU_Reg<&PMU_Layout::MISC1_CLR, 1, 17, 0x0> PFD_528_AUTOGATE_EN;  // This enables a feature that will clkgate (reset) all PFD_528 clocks anytime the PLL_528 is unlocked or powered off
constexpr PMU_Reg<&PMU_Layout::MISC1_CLR, 1, 16, 0x0> PFD_480_AUTOGATE_EN;  // This enables a feature that will clkgate (reset) all PFD_480 clocks anytime the USB1_PLL_480 is unlocked or powered off
constexpr PMU_Reg<&PMU_Layout::MISC1_CLR, 1, 13, 0x0> LVDSCLK2_IBEN;        // This enables the LVDS input buffer for anaclk2/2b
constexpr PMU_Reg<&PMU_Layout::MISC1_CLR, 1, 12, 0x0> LVDSCLK1_IBEN;        // This enables the LVDS input buffer for anaclk1/1b
constexpr PMU_Reg<&PMU_Layout::MISC1_CLR, 1, 11, 0x0> LVDSCLK2_OBEN;        // This enables the LVDS output buffer for anaclk2/2b
constexpr PMU_Reg<&PMU_Layout::MISC1_CLR, 1, 10, 0x0> LVDSCLK1_OBEN;        // This enables the LVDS output buffer for anaclk1/1b
constexpr PMU_Reg<&PMU_Layout::MISC1_CLR, 5,  5, 0x0> LVDS2_CLK_SEL;        // This field selects the clk to be routed to anaclk2/2b.
    // Not related to PMU.
    // 0b00000..ARM PLL
    // 0b00001..System PLL
    // 0b00010..ref_pfd4_clk == pll2_pfd0_clk
    // 0b00011..ref_pfd5_clk == pll2_pfd1_clk
    // 0b00100..ref_pfd6_clk == pll2_pfd2_clk
    // 0b00101..ref_pfd7_clk == pll2_pfd3_clk
    // 0b00110..Audio PLL
    // 0b00111..Video PLL
    // 0b01000..MLB PLL
    // 0b01001..ethernet ref clock (ENET_PLL)
    // 0b01010..PCIe ref clock (125M)
    // 0b01011..SATA ref clock (100M)
    // 0b01100..USB1 PLL clock
    // 0b01101..USB2 PLL clock
    // 0b01110..ref_pfd0_clk == pll3_pfd0_clk
    // 0b01111..ref_pfd1_clk == pll3_pfd1_clk
    // 0b10000..ref_pfd2_clk == pll3_pfd2_clk
    // 0b10001..ref_pfd3_clk == pll3_pfd3_clk
    // 0b10010..xtal (24M)
    // 0b10011..LVDS1 (loopback)
    // 0b10100..LVDS2 (not useful)
constexpr PMU_Reg<&PMU_Layout::MISC1_CLR, 5,  0, 0x0> LVDS1_CLK_SEL;        // This field selects the clk to be routed to anaclk1/1b.
    // Not related to PMU.
    // 0b00000..ARM PLL
    // 0b00001..System PLL
    // 0b00010..ref_pfd4_clk == pll2_pfd0_clk
    // 0b00011..ref_pfd5_clk == pll2_pfd1_clk
    // 0b00100..ref_pfd6_clk == pll2_pfd2_clk
    // 0b00101..ref_pfd7_clk == pll2_pfd3_clk
    // 0b00110..Audio PLL
    // 0b00111..Video PLL
    // 0b01001..ethernet ref clock (ENET_PLL)
    // 0b01100..USB1 PLL clock
    // 0b01101..USB2 PLL clock
    // 0b01110..ref_pfd0_clk == pll3_pfd0_clk
    // 0b01111..ref_pfd1_clk == pll3_pfd1_clk
    // 0b10000..ref_pfd2_clk == pll3_pfd2_clk
    // 0b10001..ref_pfd3_clk == pll3_pfd3_clk
    // 0b10010..xtal (24M)
}  // namespace MISC1_CLR

// Miscellaneous Register 1
namespace MISC1_TOG {
constexpr PMU_Reg<&PMU_Layout::MISC1_TOG, 1, 31, 0x0> IRQ_DIG_BO;           // This status bit is set to one when when any of the digital regulator brownout interrupts assert
constexpr PMU_Reg<&PMU_Layout::MISC1_TOG, 1, 30, 0x0> IRQ_ANA_BO;           // This status bit is set to one when when any of the analog regulator brownout interrupts assert
constexpr PMU_Reg<&PMU_Layout::MISC1_TOG, 1, 29, 0x0> IRQ_TEMPHIGH;         // This status bit is set to one when the temperature sensor high interrupt asserts for high temperature
constexpr PMU_Reg<&PMU_Layout::MISC1_TOG, 1, 28, 0x0> IRQ_TEMPLOW;          // This status bit is set to one when the temperature sensor low interrupt asserts for low temperature
constexpr PMU_Reg<&PMU_Layout::MISC1_TOG, 1, 27, 0x0> IRQ_TEMPPANIC;        // This status bit is set to one when the temperature sensor panic interrupt asserts for a panic high temperature
constexpr PMU_Reg<&PMU_Layout::MISC1_TOG, 1, 17, 0x0> PFD_528_AUTOGATE_EN;  // This enables a feature that will clkgate (reset) all PFD_528 clocks anytime the PLL_528 is unlocked or powered off
constexpr PMU_Reg<&PMU_Layout::MISC1_TOG, 1, 16, 0x0> PFD_480_AUTOGATE_EN;  // This enables a feature that will clkgate (reset) all PFD_480 clocks anytime the USB1_PLL_480 is unlocked or powered off
constexpr PMU_Reg<&PMU_Layout::MISC1_TOG, 1, 13, 0x0> LVDSCLK2_IBEN;        // This enables the LVDS input buffer for anaclk2/2b
constexpr PMU_Reg<&PMU_Layout::MISC1_TOG, 1, 12, 0x0> LVDSCLK1_IBEN;        // This enables the LVDS input buffer for anaclk1/1b
constexpr PMU_Reg<&PMU_Layout::MISC1_TOG, 1, 11, 0x0> LVDSCLK2_OBEN;        // This enables the LVDS output buffer for anaclk2/2b
constexpr PMU_Reg<&PMU_Layout::MISC1_TOG, 1, 10, 0x0> LVDSCLK1_OBEN;        // This enables the LVDS output buffer for anaclk1/1b
constexpr PMU_Reg<&PMU_Layout::MISC1_TOG, 5,  5, 0x0> LVDS2_CLK_SEL;        // This field selects the clk to be routed to anaclk2/2b.
    // Not related to PMU.
    // 0b00000..ARM PLL
    // 0b00001..System PLL
    // 0b00010..ref_pfd4_clk == pll2_pfd0_clk
    // 0b00011..ref_pfd5_clk == pll2_pfd1_clk
    // 0b00100..ref_pfd6_clk == pll2_pfd2_clk
    // 0b00101..ref_pfd7_clk == pll2_pfd3_clk
    // 0b00110..Audio PLL
    // 0b00111..Video PLL
    // 0b01000..MLB PLL
    // 0b01001..ethernet ref clock (ENET_PLL)
    // 0b01010..PCIe ref clock (125M)
    // 0b01011..SATA ref clock (100M)
    // 0b01100..USB1 PLL clock
    // 0b01101..USB2 PLL clock
    // 0b01110..ref_pfd0_clk == pll3_pfd0_clk
    // 0b01111..ref_pfd1_clk == pll3_pfd1_clk
    // 0b10000..ref_pfd2_clk == pll3_pfd2_clk
    // 0b10001..ref_pfd3_clk == pll3_pfd3_clk
    // 0b10010..xtal (24M)
    // 0b10011..LVDS1 (loopback)
    // 0b10100..LVDS2 (not useful)
constexpr PMU_Reg<&PMU_Layout::MISC1_TOG, 5,  0, 0x0> LVDS1_CLK_SEL;        // This field selects the clk to be routed to anaclk1/1b.
    // Not related to PMU.
    // 0b00000..ARM PLL
    // 0b00001..System PLL
    // 0b00010..ref_pfd4_clk == pll2_pfd0_clk
    // 0b00011..ref_pfd5_clk == pll2_pfd1_clk
    // 0b00100..ref_pfd6_clk == pll2_pfd2_clk
    // 0b00101..ref_pfd7_clk == pll2_pfd3_clk
    // 0b00110..Audio PLL
    // 0b00111..Video PLL
    // 0b01001..ethernet ref clock (ENET_PLL)
    // 0b01100..USB1 PLL clock
    // 0b01101..USB2 PLL clock
    // 0b01110..ref_pfd0_clk == pll3_pfd0_clk
    // 0b01111..ref_pfd1_clk == pll3_pfd1_clk
    // 0b10000..ref_pfd2_clk == pll3_pfd2_clk
    // 0b10001..ref_pfd3_clk == pll3_pfd3_clk
    // 0b10010..xtal (24M)
}  // namespace MISC1_TOG

// Miscellaneous Control Register
namespace MISC2 {
constexpr PMU_Reg<&PMU_Layout::MISC2, 2, 30> VIDEO_DIV;                       // Post-divider for video
    // 0b00..divide by 1 (Default)
    // 0b01..divide by 2
    // 0b10..divide by 1
    // 0b11..divide by 4
constexpr PMU_Reg<&PMU_Layout::MISC2, 2, 28> REG2_STEP_TIME;                  // Number of clock periods (24MHz clock).
    // 0b00..64
    // 0b01..128
    // 0b10..256
    // 0b11..512
constexpr PMU_Reg<&PMU_Layout::MISC2, 2, 26> REG1_STEP_TIME;                  // Number of clock periods (24MHz clock).
    // 0b00..64
    // 0b01..128
    // 0b10..256
    // 0b11..512
constexpr PMU_Reg<&PMU_Layout::MISC2, 2, 24> REG0_STEP_TIME;                  // Number of clock periods (24MHz clock).
    // 0b00..64
    // 0b01..128
    // 0b10..256
    // 0b11..512
constexpr PMU_Reg<&PMU_Layout::MISC2, 1, 23> AUDIO_DIV_MSB;                   // MSB of Post-divider for Audio PLL
    // 0b0..divide by 1 (Default)
    // 0b1..divide by 2
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2), 1, 22> REG2_OK;         // Signals that the voltage is above the brownout level for the SOC supply
constexpr PMU_Reg<&PMU_Layout::MISC2, 1, 21> REG2_ENABLE_BO;                  // Enables the brownout detection.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2), 1, 19> REG2_BO_STATUS;  // Reg2 brownout status bit.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2), 3, 16> REG2_BO_OFFSET;  // This field defines the brown out voltage offset for the xPU power domain
    // 0b100..Brownout offset = 0.100V
    // 0b111..Brownout offset = 0.175V
constexpr PMU_Reg<&PMU_Layout::MISC2, 1, 15> AUDIO_DIV_LSB;                   // LSB of Post-divider for Audio PLL
    // 0b0..divide by 1 (Default)
    // 0b1..divide by 2
constexpr PMU_Reg<&PMU_Layout::MISC2, 1, 13> REG1_ENABLE_BO;                  // Enables the brownout detection.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2), 1, 11> REG1_BO_STATUS;  // Reg1 brownout status bit.
    // 0b1..Brownout, supply is below target minus brownout offset.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2), 3,  8> REG1_BO_OFFSET;  // This field defines the brown out voltage offset for the xPU power domain
    // 0b100..Brownout offset = 0.100V
    // 0b111..Brownout offset = 0.175V
constexpr PMU_Reg<&PMU_Layout::MISC2, 1,  7> PLL3_disable;                    // Default value of "0"
constexpr PMU_Reg<&PMU_Layout::MISC2, 1,  5> REG0_ENABLE_BO;                  // Enables the brownout detection.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2), 1,  3> REG0_BO_STATUS;  // Reg0 brownout status bit.
    // 0b1..Brownout, supply is below target minus brownout offset.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2), 3,  0> REG0_BO_OFFSET;  // This field defines the brown out voltage offset for the CORE power domain
    // 0b100..Brownout offset = 0.100V
    // 0b111..Brownout offset = 0.175V
}  // namespace MISC2

// Miscellaneous Control Register
namespace MISC2_SET {
constexpr PMU_Reg<&PMU_Layout::MISC2_SET, 2, 30, 0x0> VIDEO_DIV;                  // Post-divider for video
    // 0b00..divide by 1 (Default)
    // 0b01..divide by 2
    // 0b10..divide by 1
    // 0b11..divide by 4
constexpr PMU_Reg<&PMU_Layout::MISC2_SET, 2, 28, 0x0> REG2_STEP_TIME;             // Number of clock periods (24MHz clock).
    // 0b00..64
    // 0b01..128
    // 0b10..256
    // 0b11..512
constexpr PMU_Reg<&PMU_Layout::MISC2_SET, 2, 26, 0x0> REG1_STEP_TIME;             // Number of clock periods (24MHz clock).
    // 0b00..64
    // 0b01..128
    // 0b10..256
    // 0b11..512
constexpr PMU_Reg<&PMU_Layout::MISC2_SET, 2, 24, 0x0> REG0_STEP_TIME;             // Number of clock periods (24MHz clock).
    // 0b00..64
    // 0b01..128
    // 0b10..256
    // 0b11..512
constexpr PMU_Reg<&PMU_Layout::MISC2_SET, 1, 23, 0x0> AUDIO_DIV_MSB;              // MSB of Post-divider for Audio PLL
    // 0b0..divide by 1 (Default)
    // 0b1..divide by 2
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2_SET), 1, 22> REG2_OK;         // Signals that the voltage is above the brownout level for the SOC supply
constexpr PMU_Reg<&PMU_Layout::MISC2_SET, 1, 21, 0x0> REG2_ENABLE_BO;             // Enables the brownout detection.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2_SET), 1, 19> REG2_BO_STATUS;  // Reg2 brownout status bit.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2_SET), 3, 16> REG2_BO_OFFSET;  // This field defines the brown out voltage offset for the xPU power domain
    // 0b100..Brownout offset = 0.100V
    // 0b111..Brownout offset = 0.175V
constexpr PMU_Reg<&PMU_Layout::MISC2_SET, 1, 15, 0x0> AUDIO_DIV_LSB;              // LSB of Post-divider for Audio PLL
    // 0b0..divide by 1 (Default)
    // 0b1..divide by 2
constexpr PMU_Reg<&PMU_Layout::MISC2_SET, 1, 13, 0x0> REG1_ENABLE_BO;             // Enables the brownout detection.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2_SET), 1, 11> REG1_BO_STATUS;  // Reg1 brownout status bit.
    // 0b1..Brownout, supply is below target minus brownout offset.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2_SET), 3,  8> REG1_BO_OFFSET;  // This field defines the brown out voltage offset for the xPU power domain
    // 0b100..Brownout offset = 0.100V
    // 0b111..Brownout offset = 0.175V
constexpr PMU_Reg<&PMU_Layout::MISC2_SET, 1,  7, 0x0> PLL3_disable;               // Default value of "0"
constexpr PMU_Reg<&PMU_Layout::MISC2_SET, 1,  5, 0x0> REG0_ENABLE_BO;             // Enables the brownout detection.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2_SET), 1,  3> REG0_BO_STATUS;  // Reg0 brownout status bit.
    // 0b1..Brownout, supply is below target minus brownout offset.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2_SET), 3,  0> REG0_BO_OFFSET;  // This field defines the brown out voltage offset for the CORE power domain
    // 0b100..Brownout offset = 0.100V
    // 0b111..Brownout offset = 0.175V
}  // namespace MISC2_SET

// Miscellaneous Control Register
namespace MISC2_CLR {
constexpr PMU_Reg<&PMU_Layout::MISC2_CLR, 2, 30, 0x0> VIDEO_DIV;                  // Post-divider for video
    // 0b00..divide by 1 (Default)
    // 0b01..divide by 2
    // 0b10..divide by 1
    // 0b11..divide by 4
constexpr PMU_Reg<&PMU_Layout::MISC2_CLR, 2, 28, 0x0> REG2_STEP_TIME;             // Number of clock periods (24MHz clock).
    // 0b00..64
    // 0b01..128
    // 0b10..256
    // 0b11..512
constexpr PMU_Reg<&PMU_Layout::MISC2_CLR, 2, 26, 0x0> REG1_STEP_TIME;             // Number of clock periods (24MHz clock).
    // 0b00..64
    // 0b01..128
    // 0b10..256
    // 0b11..512
constexpr PMU_Reg<&PMU_Layout::MISC2_CLR, 2, 24, 0x0> REG0_STEP_TIME;             // Number of clock periods (24MHz clock).
    // 0b00..64
    // 0b01..128
    // 0b10..256
    // 0b11..512
constexpr PMU_Reg<&PMU_Layout::MISC2_CLR, 1, 23, 0x0> AUDIO_DIV_MSB;              // MSB of Post-divider for Audio PLL
    // 0b0..divide by 1 (Default)
    // 0b1..divide by 2
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2_CLR), 1, 22> REG2_OK;         // Signals that the voltage is above the brownout level for the SOC supply
constexpr PMU_Reg<&PMU_Layout::MISC2_CLR, 1, 21, 0x0> REG2_ENABLE_BO;             // Enables the brownout detection.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2_CLR), 1, 19> REG2_BO_STATUS;  // Reg2 brownout status bit.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2_CLR), 3, 16> REG2_BO_OFFSET;  // This field defines the brown out voltage offset for the xPU power domain
    // 0b100..Brownout offset = 0.100V
    // 0b111..Brownout offset = 0.175V
constexpr PMU_Reg<&PMU_Layout::MISC2_CLR, 1, 15, 0x0> AUDIO_DIV_LSB;              // LSB of Post-divider for Audio PLL
    // 0b0..divide by 1 (Default)
    // 0b1..divide by 2
constexpr PMU_Reg<&PMU_Layout::MISC2_CLR, 1, 13, 0x0> REG1_ENABLE_BO;             // Enables the brownout detection.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2_CLR), 1, 11> REG1_BO_STATUS;  // Reg1 brownout status bit.
    // 0b1..Brownout, supply is below target minus brownout offset.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2_CLR), 3,  8> REG1_BO_OFFSET;  // This field defines the brown out voltage offset for the xPU power domain
    // 0b100..Brownout offset = 0.100V
    // 0b111..Brownout offset = 0.175V
constexpr PMU_Reg<&PMU_Layout::MISC2_CLR, 1,  7, 0x0> PLL3_disable;               // Default value of "0"
constexpr PMU_Reg<&PMU_Layout::MISC2_CLR, 1,  5, 0x0> REG0_ENABLE_BO;             // Enables the brownout detection.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2_CLR), 1,  3> REG0_BO_STATUS;  // Reg0 brownout status bit.
    // 0b1..Brownout, supply is below target minus brownout offset.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2_CLR), 3,  0> REG0_BO_OFFSET;  // This field defines the brown out voltage offset for the CORE power domain
    // 0b100..Brownout offset = 0.100V
    // 0b111..Brownout offset = 0.175V
}  // namespace MISC2_CLR

// Miscellaneous Control Register
namespace MISC2_TOG {
constexpr PMU_Reg<&PMU_Layout::MISC2_TOG, 2, 30, 0x0> VIDEO_DIV;                  // Post-divider for video
    // 0b00..divide by 1 (Default)
    // 0b01..divide by 2
    // 0b10..divide by 1
    // 0b11..divide by 4
constexpr PMU_Reg<&PMU_Layout::MISC2_TOG, 2, 28, 0x0> REG2_STEP_TIME;             // Number of clock periods (24MHz clock).
    // 0b00..64
    // 0b01..128
    // 0b10..256
    // 0b11..512
constexpr PMU_Reg<&PMU_Layout::MISC2_TOG, 2, 26, 0x0> REG1_STEP_TIME;             // Number of clock periods (24MHz clock).
    // 0b00..64
    // 0b01..128
    // 0b10..256
    // 0b11..512
constexpr PMU_Reg<&PMU_Layout::MISC2_TOG, 2, 24, 0x0> REG0_STEP_TIME;             // Number of clock periods (24MHz clock).
    // 0b00..64
    // 0b01..128
    // 0b10..256
    // 0b11..512
constexpr PMU_Reg<&PMU_Layout::MISC2_TOG, 1, 23, 0x0> AUDIO_DIV_MSB;              // MSB of Post-divider for Audio PLL
    // 0b0..divide by 1 (Default)
    // 0b1..divide by 2
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2_TOG), 1, 22> REG2_OK;         // Signals that the voltage is above the brownout level for the SOC supply
constexpr PMU_Reg<&PMU_Layout::MISC2_TOG, 1, 21, 0x0> REG2_ENABLE_BO;             // Enables the brownout detection.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2_TOG), 1, 19> REG2_BO_STATUS;  // Reg2 brownout status bit.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2_TOG), 3, 16> REG2_BO_OFFSET;  // This field defines the brown out voltage offset for the xPU power domain
    // 0b100..Brownout offset = 0.100V
    // 0b111..Brownout offset = 0.175V
constexpr PMU_Reg<&PMU_Layout::MISC2_TOG, 1, 15, 0x0> AUDIO_DIV_LSB;              // LSB of Post-divider for Audio PLL
    // 0b0..divide by 1 (Default)
    // 0b1..divide by 2
constexpr PMU_Reg<&PMU_Layout::MISC2_TOG, 1, 13, 0x0> REG1_ENABLE_BO;             // Enables the brownout detection.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2_TOG), 1, 11> REG1_BO_STATUS;  // Reg1 brownout status bit.
    // 0b1..Brownout, supply is below target minus brownout offset.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2_TOG), 3,  8> REG1_BO_OFFSET;  // This field defines the brown out voltage offset for the xPU power domain
    // 0b100..Brownout offset = 0.100V
    // 0b111..Brownout offset = 0.175V
constexpr PMU_Reg<&PMU_Layout::MISC2_TOG, 1,  7, 0x0> PLL3_disable;               // Default value of "0"
constexpr PMU_Reg<&PMU_Layout::MISC2_TOG, 1,  5, 0x0> REG0_ENABLE_BO;             // Enables the brownout detection.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2_TOG), 1,  3> REG0_BO_STATUS;  // Reg0 brownout status bit.
    // 0b1..Brownout, supply is below target minus brownout offset.
constexpr PMU_Reg<regs::constify(&PMU_Layout::MISC2_TOG), 3,  0> REG0_BO_OFFSET;  // This field defines the brown out voltage offset for the CORE power domain
    // 0b100..Brownout offset = 0.100V
    // 0b111..Brownout offset = 0.175V
}  // namespace MISC2_TOG

}  // namespace PMU

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
