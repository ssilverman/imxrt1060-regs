// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// IOMUXC_SNVS.h defines all the IOMUXC_SNVS registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "qindesign/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the IOMUX Controller SNVS (IOMUXC_SNVS) registers.
//
// Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_IOMUXC_SNVS.h
// * https://github.com/nxp-mcuxpresso/mcux-soc-svd/blob/main/MIMXRT1062/MIMXRT1062.xml
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct IOMUXC_SNVS_Layout {
  volatile uint32_t SW_MUX_CTL_PAD_WAKEUP;             /**< SW_MUX_CTL_PAD_WAKEUP SW MUX Control Register, offset: 0x0 */
  volatile uint32_t SW_MUX_CTL_PAD_PMIC_ON_REQ;        /**< SW_MUX_CTL_PAD_PMIC_ON_REQ SW MUX Control Register, offset: 0x4 */
  volatile uint32_t SW_MUX_CTL_PAD_PMIC_STBY_REQ;      /**< SW_MUX_CTL_PAD_PMIC_STBY_REQ SW MUX Control Register, offset: 0x8 */
  volatile uint32_t SW_PAD_CTL_PAD_TEST_MODE;          /**< SW_PAD_CTL_PAD_TEST_MODE SW PAD Control Register, offset: 0xC */
  volatile uint32_t SW_PAD_CTL_PAD_POR_B;              /**< SW_PAD_CTL_PAD_POR_B SW PAD Control Register, offset: 0x10 */
  volatile uint32_t SW_PAD_CTL_PAD_ONOFF;              /**< SW_PAD_CTL_PAD_ONOFF SW PAD Control Register, offset: 0x14 */
  volatile uint32_t SW_PAD_CTL_PAD_WAKEUP;             /**< SW_PAD_CTL_PAD_WAKEUP SW PAD Control Register, offset: 0x18 */
  volatile uint32_t SW_PAD_CTL_PAD_PMIC_ON_REQ;        /**< SW_PAD_CTL_PAD_PMIC_ON_REQ SW PAD Control Register, offset: 0x1C */
  volatile uint32_t SW_PAD_CTL_PAD_PMIC_STBY_REQ;      /**< SW_PAD_CTL_PAD_PMIC_STBY_REQ SW PAD Control Register, offset: 0x20 */
};

constexpr size_t    kIOMUXC_SNVS_size = 0x24;
constexpr uintptr_t kIOMUXC_SNVS_base = 0x400A'8000;

namespace IOMUXC_SNVS {
constexpr regs::RegGroup<IOMUXC_SNVS_Layout, kIOMUXC_SNVS_size,
                         kIOMUXC_SNVS_base>
    group;
}  // namespace IOMUXC_SNVS

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using IOMUXC_SNVS_Reg = regs::Reg32<kIOMUXC_SNVS_base, IOMUXC_SNVS_Layout,
                                    Member, 0, Bits, Shift, AssignMask>;

namespace IOMUXC_SNVS {

// SW_MUX_CTL_PAD_WAKEUP SW MUX Control Register
namespace SW_MUX_CTL_PAD_WAKEUP {
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_MUX_CTL_PAD_WAKEUP, 1, 4> SION;      // Software Input On Field.
    // 0b0..Input Path is determined by functionality
    // 0b1..Force input path of pad WAKEUP
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_MUX_CTL_PAD_WAKEUP, 3, 0> MUX_MODE;  // MUX Mode Select Field.
    // 0b101..Select mux mode: ALT5 mux port: GPIO5_IO00 of instance: gpio5
    // 0b111..Select mux mode: ALT7 mux port: NMI of instance: CM7
}  // namespace SW_MUX_CTL_PAD_WAKEUP

// SW_MUX_CTL_PAD_PMIC_ON_REQ SW MUX Control Register
namespace SW_MUX_CTL_PAD_PMIC_ON_REQ {
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_MUX_CTL_PAD_PMIC_ON_REQ, 1, 4> SION;      // Software Input On Field.
    // 0b0..Input Path is determined by functionality
    // 0b1..Force input path of pad PMIC_ON_REQ
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_MUX_CTL_PAD_PMIC_ON_REQ, 3, 0> MUX_MODE;  // MUX Mode Select Field.
    // 0b000..Select mux mode: ALT0 mux port: SNVS_PMIC_ON_REQ of instance: snvs
    // 0b101..Select mux mode: ALT5 mux port: GPIO5_IO01 of instance: gpio5
}  // namespace SW_MUX_CTL_PAD_PMIC_ON_REQ

// SW_MUX_CTL_PAD_PMIC_STBY_REQ SW MUX Control Register
namespace SW_MUX_CTL_PAD_PMIC_STBY_REQ {
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_MUX_CTL_PAD_PMIC_STBY_REQ, 1, 4> SION;      // Software Input On Field.
    // 0b0..Input Path is determined by functionality
    // 0b1..Force input path of pad PMIC_STBY_REQ
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_MUX_CTL_PAD_PMIC_STBY_REQ, 3, 0> MUX_MODE;  // MUX Mode Select Field.
    // 0b000..Select mux mode: ALT0 mux port: CCM_PMIC_STBY_REQ of instance: ccm
    // 0b101..Select mux mode: ALT5 mux port: GPIO5_IO02 of instance: gpio5
}  // namespace SW_MUX_CTL_PAD_PMIC_STBY_REQ

// SW_PAD_CTL_PAD_TEST_MODE SW PAD Control Register
namespace SW_PAD_CTL_PAD_TEST_MODE {
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_TEST_MODE, 1, 16> HYS;                    // Hyst. Enable Field
    // 0b0..Hysteresis Disabled (CMOS input)
    // 0b1..Hysteresis Enabled (Schmitt Trigger input)
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_TEST_MODE, 2, 14> PUS;                    // Pull Up / Down Config. Field Controls signals to select pull-up or pull-down internal resistance strength.
    // 0b00..100K Ohm Pull Down
    // 0b01..47K Ohm Pull Up
    // 0b10..100K Ohm Pull Up
    // 0b11..22K Ohm Pull Up
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_TEST_MODE, 1, 13> PUE;                    // Pull / Keep Select Field Control signal to enable internal pull-up/down resistors or pad keeper functionality.
    // 0b0..Keep the previous output value when the output driver is disabled.
    // 0b1..Pull-up or pull-down (determined by PUS field).
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_TEST_MODE, 1, 12> PKE;                    // Pull / Keep Enable Field
    // 0b0..Pull/Keeper Disabled
    // 0b1..Pull/Keeper Enabled
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_TEST_MODE, 1, 11> ODE;                    // Open Drain Enable Field
    // 0b0..Open Drain Disabled (Output is CMOS)
    // 0b1..Open Drain Enabled (Output is Open Drain)
constexpr IOMUXC_SNVS_Reg<regs::constify(&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_TEST_MODE), 2,  6> SPEED;  // Speed Field
    // 0b10..100MHz
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_TEST_MODE, 3,  3> DSE;                    // Drive Strength Field
    // 0b000..HI-Z
    // 0b001..Dual/Single voltage: 262/260 Ohm @ 1.8V, 247/157 Ohm @ 3.3V
    // 0b010..Dual/Single voltage: 134/130 Ohm @ 1.8V, 126/78 Ohm @ 3.3V
    // 0b011..Dual/Single voltage: 88/88 Ohm @ 1.8V, 84/53 Ohm @ 3.3V
    // 0b100..Dual/Single voltage: 62/65 Ohm @ 1.8V, 57/39 Ohm @ 3.3V
    // 0b101..Dual/Single voltage: 51/52 Ohm @ 1.8V, 47/32 Ohm @ 3.3V
    // 0b110..Dual/Single voltage: 43/43 Ohm @ 1.8V, 40/26 Ohm @ 3.3V
    // 0b111..Dual/Single voltage: 37/37 Ohm @ 1.8V, 34/23 Ohm @ 3.3V
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_TEST_MODE, 1,  0> SRE;                    // Slew Rate Field
    // 0b0..Slow Slew Rate
    // 0b1..Fast Slew Rate
}  // namespace SW_PAD_CTL_PAD_TEST_MODE

// SW_PAD_CTL_PAD_POR_B SW PAD Control Register
namespace SW_PAD_CTL_PAD_POR_B {
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_POR_B, 1, 16> HYS;                    // Hyst. Enable Field
    // 0b0..Hysteresis Disabled (CMOS input)
    // 0b1..Hysteresis Enabled (Schmitt Trigger input)
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_POR_B, 2, 14> PUS;                    // Pull Up / Down Config. Field Controls signals to select pull-up or pull-down internal resistance strength.
    // 0b00..100K Ohm Pull Down
    // 0b01..47K Ohm Pull Up
    // 0b10..100K Ohm Pull Up
    // 0b11..22K Ohm Pull Up
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_POR_B, 1, 13> PUE;                    // Pull / Keep Select Field Control signal to enable internal pull-up/down resistors or pad keeper functionality.
    // 0b0..Keep the previous output value when the output driver is disabled.
    // 0b1..Pull-up or pull-down (determined by PUS field).
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_POR_B, 1, 12> PKE;                    // Pull / Keep Enable Field
    // 0b0..Pull/Keeper Disabled
    // 0b1..Pull/Keeper Enabled
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_POR_B, 1, 11> ODE;                    // Open Drain Enable Field
    // 0b0..Open Drain Disabled (Output is CMOS)
    // 0b1..Open Drain Enabled (Output is Open Drain)
constexpr IOMUXC_SNVS_Reg<regs::constify(&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_POR_B), 2,  6> SPEED;  // Speed Field
    // 0b10..100MHz
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_POR_B, 3,  3> DSE;                    // Drive Strength Field
    // 0b000..HI-Z
    // 0b001..Dual/Single voltage: 262/260 Ohm @ 1.8V, 247/157 Ohm @ 3.3V
    // 0b010..Dual/Single voltage: 134/130 Ohm @ 1.8V, 126/78 Ohm @ 3.3V
    // 0b011..Dual/Single voltage: 88/88 Ohm @ 1.8V, 84/53 Ohm @ 3.3V
    // 0b100..Dual/Single voltage: 62/65 Ohm @ 1.8V, 57/39 Ohm @ 3.3V
    // 0b101..Dual/Single voltage: 51/52 Ohm @ 1.8V, 47/32 Ohm @ 3.3V
    // 0b110..Dual/Single voltage: 43/43 Ohm @ 1.8V, 40/26 Ohm @ 3.3V
    // 0b111..Dual/Single voltage: 37/37 Ohm @ 1.8V, 34/23 Ohm @ 3.3V
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_POR_B, 1,  0> SRE;                    // Slew Rate Field
    // 0b0..Slow Slew Rate
    // 0b1..Fast Slew Rate
}  // namespace SW_PAD_CTL_PAD_POR_B

// SW_PAD_CTL_PAD_ONOFF SW PAD Control Register
namespace SW_PAD_CTL_PAD_ONOFF {
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_ONOFF, 1, 16> HYS;                    // Hyst. Enable Field
    // 0b0..Hysteresis Disabled (CMOS input)
    // 0b1..Hysteresis Enabled (Schmitt Trigger input)
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_ONOFF, 2, 14> PUS;                    // Pull Up / Down Config. Field Controls signals to select pull-up or pull-down internal resistance strength.
    // 0b00..100K Ohm Pull Down
    // 0b01..47K Ohm Pull Up
    // 0b10..100K Ohm Pull Up
    // 0b11..22K Ohm Pull Up
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_ONOFF, 1, 13> PUE;                    // Pull / Keep Select Field Control signal to enable internal pull-up/down resistors or pad keeper functionality.
    // 0b0..Keep the previous output value when the output driver is disabled.
    // 0b1..Pull-up or pull-down (determined by PUS field).
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_ONOFF, 1, 12> PKE;                    // Pull / Keep Enable Field
    // 0b0..Pull/Keeper Disabled
    // 0b1..Pull/Keeper Enabled
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_ONOFF, 1, 11> ODE;                    // Open Drain Enable Field
    // 0b0..Open Drain Disabled (Output is CMOS)
    // 0b1..Open Drain Enabled (Output is Open Drain)
constexpr IOMUXC_SNVS_Reg<regs::constify(&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_ONOFF), 2,  6> SPEED;  // Speed Field
    // 0b10..100MHz
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_ONOFF, 3,  3> DSE;                    // Drive Strength Field
    // 0b000..HI-Z
    // 0b001..Dual/Single voltage: 262/260 Ohm @ 1.8V, 247/157 Ohm @ 3.3V
    // 0b010..Dual/Single voltage: 134/130 Ohm @ 1.8V, 126/78 Ohm @ 3.3V
    // 0b011..Dual/Single voltage: 88/88 Ohm @ 1.8V, 84/53 Ohm @ 3.3V
    // 0b100..Dual/Single voltage: 62/65 Ohm @ 1.8V, 57/39 Ohm @ 3.3V
    // 0b101..Dual/Single voltage: 51/52 Ohm @ 1.8V, 47/32 Ohm @ 3.3V
    // 0b110..Dual/Single voltage: 43/43 Ohm @ 1.8V, 40/26 Ohm @ 3.3V
    // 0b111..Dual/Single voltage: 37/37 Ohm @ 1.8V, 34/23 Ohm @ 3.3V
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_ONOFF, 1,  0> SRE;                    // Slew Rate Field
    // 0b0..Slow Slew Rate
    // 0b1..Fast Slew Rate
}  // namespace SW_PAD_CTL_PAD_ONOFF

// SW_PAD_CTL_PAD_WAKEUP SW PAD Control Register
namespace SW_PAD_CTL_PAD_WAKEUP {
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_WAKEUP, 1, 16> HYS;                    // Hyst. Enable Field
    // 0b0..Hysteresis Disabled (CMOS input)
    // 0b1..Hysteresis Enabled (Schmitt Trigger input)
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_WAKEUP, 2, 14> PUS;                    // Pull Up / Down Config. Field Controls signals to select pull-up or pull-down internal resistance strength.
    // 0b00..100K Ohm Pull Down
    // 0b01..47K Ohm Pull Up
    // 0b10..100K Ohm Pull Up
    // 0b11..22K Ohm Pull Up
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_WAKEUP, 1, 13> PUE;                    // Pull / Keep Select Field Control signal to enable internal pull-up/down resistors or pad keeper functionality.
    // 0b0..Keep the previous output value when the output driver is disabled.
    // 0b1..Pull-up or pull-down (determined by PUS field).
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_WAKEUP, 1, 12> PKE;                    // Pull / Keep Enable Field
    // 0b0..Pull/Keeper Disabled
    // 0b1..Pull/Keeper Enabled
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_WAKEUP, 1, 11> ODE;                    // Open Drain Enable Field
    // 0b0..Open Drain Disabled (Output is CMOS)
    // 0b1..Open Drain Enabled (Output is Open Drain)
constexpr IOMUXC_SNVS_Reg<regs::constify(&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_WAKEUP), 2,  6> SPEED;  // Speed Field
    // 0b10..100MHz
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_WAKEUP, 3,  3> DSE;                    // Drive Strength Field
    // 0b000..HI-Z
    // 0b001..Dual/Single voltage: 262/260 Ohm @ 1.8V, 247/157 Ohm @ 3.3V
    // 0b010..Dual/Single voltage: 134/130 Ohm @ 1.8V, 126/78 Ohm @ 3.3V
    // 0b011..Dual/Single voltage: 88/88 Ohm @ 1.8V, 84/53 Ohm @ 3.3V
    // 0b100..Dual/Single voltage: 62/65 Ohm @ 1.8V, 57/39 Ohm @ 3.3V
    // 0b101..Dual/Single voltage: 51/52 Ohm @ 1.8V, 47/32 Ohm @ 3.3V
    // 0b110..Dual/Single voltage: 43/43 Ohm @ 1.8V, 40/26 Ohm @ 3.3V
    // 0b111..Dual/Single voltage: 37/37 Ohm @ 1.8V, 34/23 Ohm @ 3.3V
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_WAKEUP, 1,  0> SRE;                    // Slew Rate Field
    // 0b0..Slow Slew Rate
    // 0b1..Fast Slew Rate
}  // namespace SW_PAD_CTL_PAD_WAKEUP

// SW_PAD_CTL_PAD_PMIC_ON_REQ SW PAD Control Register
namespace SW_PAD_CTL_PAD_PMIC_ON_REQ {
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_PMIC_ON_REQ, 1, 16> HYS;                    // Hyst. Enable Field
    // 0b0..Hysteresis Disabled (CMOS input)
    // 0b1..Hysteresis Enabled (Schmitt Trigger input)
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_PMIC_ON_REQ, 2, 14> PUS;                    // Pull Up / Down Config. Field Controls signals to select pull-up or pull-down internal resistance strength.
    // 0b00..100K Ohm Pull Down
    // 0b01..47K Ohm Pull Up
    // 0b10..100K Ohm Pull Up
    // 0b11..22K Ohm Pull Up
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_PMIC_ON_REQ, 1, 13> PUE;                    // Pull / Keep Select Field Control signal to enable internal pull-up/down resistors or pad keeper functionality.
    // 0b0..Keep the previous output value when the output driver is disabled.
    // 0b1..Pull-up or pull-down (determined by PUS field).
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_PMIC_ON_REQ, 1, 12> PKE;                    // Pull / Keep Enable Field
    // 0b0..Pull/Keeper Disabled
    // 0b1..Pull/Keeper Enabled
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_PMIC_ON_REQ, 1, 11> ODE;                    // Open Drain Enable Field
    // 0b0..Open Drain Disabled (Output is CMOS)
    // 0b1..Open Drain Enabled (Output is Open Drain)
constexpr IOMUXC_SNVS_Reg<regs::constify(&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_PMIC_ON_REQ), 2,  6> SPEED;  // Speed Field
    // 0b10..100MHz
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_PMIC_ON_REQ, 3,  3> DSE;                    // Drive Strength Field
    // 0b000..HI-Z
    // 0b001..Dual/Single voltage: 262/260 Ohm @ 1.8V, 247/157 Ohm @ 3.3V
    // 0b010..Dual/Single voltage: 134/130 Ohm @ 1.8V, 126/78 Ohm @ 3.3V
    // 0b011..Dual/Single voltage: 88/88 Ohm @ 1.8V, 84/53 Ohm @ 3.3V
    // 0b100..Dual/Single voltage: 62/65 Ohm @ 1.8V, 57/39 Ohm @ 3.3V
    // 0b101..Dual/Single voltage: 51/52 Ohm @ 1.8V, 47/32 Ohm @ 3.3V
    // 0b110..Dual/Single voltage: 43/43 Ohm @ 1.8V, 40/26 Ohm @ 3.3V
    // 0b111..Dual/Single voltage: 37/37 Ohm @ 1.8V, 34/23 Ohm @ 3.3V
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_PMIC_ON_REQ, 1,  0> SRE;                    // Slew Rate Field
    // 0b0..Slow Slew Rate
    // 0b1..Fast Slew Rate
}  // namespace SW_PAD_CTL_PAD_PMIC_ON_REQ

// SW_PAD_CTL_PAD_PMIC_STBY_REQ SW PAD Control Register
namespace SW_PAD_CTL_PAD_PMIC_STBY_REQ {
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_PMIC_STBY_REQ, 1, 16> HYS;                    // Hyst. Enable Field
    // 0b0..Hysteresis Disabled (CMOS input)
    // 0b1..Hysteresis Enabled (Schmitt Trigger input)
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_PMIC_STBY_REQ, 2, 14> PUS;                    // Pull Up / Down Config. Field Controls signals to select pull-up or pull-down internal resistance strength.
    // 0b00..100K Ohm Pull Down
    // 0b01..47K Ohm Pull Up
    // 0b10..100K Ohm Pull Up
    // 0b11..22K Ohm Pull Up
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_PMIC_STBY_REQ, 1, 13> PUE;                    // Pull / Keep Select Field Control signal to enable internal pull-up/down resistors or pad keeper functionality.
    // 0b0..Keep the previous output value when the output driver is disabled.
    // 0b1..Pull-up or pull-down (determined by PUS field).
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_PMIC_STBY_REQ, 1, 12> PKE;                    // Pull / Keep Enable Field
    // 0b0..Pull/Keeper Disabled
    // 0b1..Pull/Keeper Enabled
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_PMIC_STBY_REQ, 1, 11> ODE;                    // Open Drain Enable Field
    // 0b0..Open Drain Disabled (Output is CMOS)
    // 0b1..Open Drain Enabled (Output is Open Drain)
constexpr IOMUXC_SNVS_Reg<regs::constify(&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_PMIC_STBY_REQ), 2,  6> SPEED;  // Speed Field
    // 0b10..100MHz
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_PMIC_STBY_REQ, 3,  3> DSE;                    // Drive Strength Field
    // 0b000..HI-Z
    // 0b001..Dual/Single voltage: 262/260 Ohm @ 1.8V, 247/157 Ohm @ 3.3V
    // 0b010..Dual/Single voltage: 134/130 Ohm @ 1.8V, 126/78 Ohm @ 3.3V
    // 0b011..Dual/Single voltage: 88/88 Ohm @ 1.8V, 84/53 Ohm @ 3.3V
    // 0b100..Dual/Single voltage: 62/65 Ohm @ 1.8V, 57/39 Ohm @ 3.3V
    // 0b101..Dual/Single voltage: 51/52 Ohm @ 1.8V, 47/32 Ohm @ 3.3V
    // 0b110..Dual/Single voltage: 43/43 Ohm @ 1.8V, 40/26 Ohm @ 3.3V
    // 0b111..Dual/Single voltage: 37/37 Ohm @ 1.8V, 34/23 Ohm @ 3.3V
constexpr IOMUXC_SNVS_Reg<&IOMUXC_SNVS_Layout::SW_PAD_CTL_PAD_PMIC_STBY_REQ, 1,  0> SRE;                    // Slew Rate Field
    // 0b0..Slow Slew Rate
    // 0b1..Fast Slew Rate
}  // namespace SW_PAD_CTL_PAD_PMIC_STBY_REQ

}  // namespace IOMUXC_SNVS

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
