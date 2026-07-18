// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// IOMUXC.h defines all the IOMUXC registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// IOMUXC layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_IOMUXC.h
// * https://github.com/nxp-mcuxpresso/legacy-mcux-sdk/blob/main/devices/MIMXRT1062/MIMXRT1062.h

constexpr size_t kIOMUXC_SW_MUX_CTL_PAD_count   = 124;
constexpr size_t kIOMUXC_SW_PAD_CTL_PAD_count   = 124;
constexpr size_t kIOMUXC_SELECT_INPUT_count     = 154;
constexpr size_t kIOMUXC_SW_MUX_CTL_PAD_1_count =  22;
constexpr size_t kIOMUXC_SW_PAD_CTL_PAD_1_count =  22;
constexpr size_t kIOMUXC_SELECT_INPUT_1_count   =  33;

struct IOMUXC_Layout {
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[5];
  volatile uint32_t SW_MUX_CTL_PAD[kIOMUXC_SW_MUX_CTL_PAD_count];      /**< SW_MUX_CTL_PAD_GPIO_EMC_00 SW MUX Control Register..SW_MUX_CTL_PAD_GPIO_SD_B1_11 SW MUX Control Register, array offset: 0x14, array step: 0x4 */
  volatile uint32_t SW_PAD_CTL_PAD[kIOMUXC_SW_PAD_CTL_PAD_count];      /**< SW_PAD_CTL_PAD_GPIO_EMC_00 SW PAD Control Register..SW_PAD_CTL_PAD_GPIO_SD_B1_11 SW PAD Control Register, array offset: 0x204, array step: 0x4 */
  volatile uint32_t SELECT_INPUT[kIOMUXC_SELECT_INPUT_count];          /**< ANATOP_USB_OTG1_ID_SELECT_INPUT DAISY Register..XBAR1_IN23_SELECT_INPUT DAISY Register, array offset: 0x3F4, array step: 0x4 */
  volatile uint32_t SW_MUX_CTL_PAD_1[kIOMUXC_SW_MUX_CTL_PAD_1_count];  /**< SW_MUX_CTL_PAD_GPIO_SPI_B0_00 SW MUX Control Register..SW_MUX_CTL_PAD_GPIO_SPI_B1_07 SW MUX Control Register, array offset: 0x65C, array step: 0x4 */
  volatile uint32_t SW_PAD_CTL_PAD_1[kIOMUXC_SW_PAD_CTL_PAD_1_count];  /**< SW_PAD_CTL_PAD_GPIO_SPI_B0_00 SW PAD Control Register..SW_PAD_CTL_PAD_GPIO_SPI_B1_07 SW PAD Control Register, array offset: 0x6B4, array step: 0x4 */
  volatile uint32_t SELECT_INPUT_1[kIOMUXC_SELECT_INPUT_1_count];      /**< ENET2_IPG_CLK_RMII_SELECT_INPUT DAISY Register..CANFD_IPP_IND_CANRX_SELECT_INPUT DAISY Register, array offset: 0x70C, array step: 0x4 */
};

constexpr size_t    kIOMUXC_size = 0x790;
constexpr uintptr_t kIOMUXC_base = 0x401F8000;

namespace IOMUXC {
constexpr regs::RegGroup<IOMUXC_Layout, kIOMUXC_size, kIOMUXC_base> group;
}  // namespace IOMUXC

namespace IOMUXC {

namespace SW_MUX_CTL_PAD {
// IOMUXC_SW_MUX_CTL_PAD values
constexpr regs::RegValue32<1, 4> SION;      // Software Input On Field.
    // 0b0..Input Path is determined by functionality
    // 0b1..Force input path of pad GPIO_AD_B0_00
constexpr regs::RegValue32<4, 0> MUX_MODE;  // MUX Mode Select Field.
    // 0b0000..Select mux mode: ALT0 mux port: USB_OTG1_PWR of instance: usb
    // 0b0001..Select mux mode: ALT1 mux port: QTIMER3_TIMER1 of instance: qtimer3
    // 0b0010..Select mux mode: ALT2 mux port: LPUART2_RTS_B of instance: lpuart2
    // 0b0011..Select mux mode: ALT3 mux port: LPI2C1_SDA of instance: lpi2c1
    // 0b0100..Select mux mode: ALT4 mux port: CCM_PMIC_READY of instance: ccm
    // 0b0101..Select mux mode: ALT5 mux port: GPIO1_IO17 of instance: gpio1
    // 0b0110..Select mux mode: ALT6 mux port: USDHC1_VSELECT of instance: usdhc1
    // 0b0111..Select mux mode: ALT7 mux port: KPP_COL07 of instance: kpp
    // 0b1000..Select mux mode: ALT8 mux port: ENET2_1588_EVENT0_IN of instance: enet2
    // 0b1001..Select mux mode: ALT9 mux port: FLEXIO3_FLEXIO01 of instance: flexio3
}  // namespace SW_MUX_CTL_PAD

namespace SW_PAD_CTL_PAD {
// IOMUXC_SW_PAD_CTL_PAD values
constexpr regs::RegValue32<1, 16> HYS;    // Hyst. Enable Field
    // 0b0..Hysteresis Disabled
    // 0b1..Hysteresis Enabled
constexpr regs::RegValue32<2, 14> PUS;    // Pull Up / Down Config. Field
    // 0b00..100K Ohm Pull Down
    // 0b01..47K Ohm Pull Up
    // 0b10..100K Ohm Pull Up
    // 0b11..22K Ohm Pull Up
constexpr regs::RegValue32<1, 13> PUE;    // Pull / Keep Select Field
    // 0b0..Keeper
    // 0b1..Pull
constexpr regs::RegValue32<1, 12> PKE;    // Pull / Keep Enable Field
    // 0b0..Pull/Keeper Disabled
    // 0b1..Pull/Keeper Enabled
constexpr regs::RegValue32<1, 11> ODE;    // Open Drain Enable Field
    // 0b0..Open Drain Disabled
    // 0b1..Open Drain Enabled
constexpr regs::RegValue32<2,  6> SPEED;  // Speed Field
    // 0b00..low(50MHz)
    // 0b01..medium(100MHz)
    // 0b10..fast(150MHz)
    // 0b11..max(200MHz)
constexpr regs::RegValue32<3,  3> DSE;    // Drive Strength Field
    // 0b000..output driver disabled;
    // 0b001..R0(150 Ohm @ 3.3V, 260 Ohm@1.8V)
    // 0b010..R0/2
    // 0b011..R0/3
    // 0b100..R0/4
    // 0b101..R0/5
    // 0b110..R0/6
    // 0b111..R0/7
constexpr regs::RegValue32<1,  0> SRE;    // Slew Rate Field
    // 0b0..Slow Slew Rate
    // 0b1..Fast Slew Rate
}  // namespace SW_PAD_CTL_PAD

namespace SELECT_INPUT {
// IOMUXC_SELECT_INPUT_DAISY
constexpr regs::RegValue32<3, 0> DAISY;  // Selecting Pads Involved in Daisy Chain.
    // 0b000..Selecting Pad: GPIO_SD_B1_03 for Mode: ALT6
    // 0b001..Selecting Pad: GPIO_AD_B0_12 for Mode: ALT1
    // 0b010..Selecting Pad: GPIO_AD_B1_01 for Mode: ALT4
    // 0b011..Selecting Pad: GPIO_AD_B1_08 for Mode: ALT3
    // 0b100..Selecting Pad: GPIO_EMC_32 for Mode: ALT3
}  // namespace SELECT_INPUT

namespace SW_MUX_CTL_PAD_1 {
// IOMUXC_SW_MUX_CTL_PAD_1 values
constexpr regs::RegValue32<1, 4> SION;      // Software Input On Field.
    // 0b0..Input Path is determined by functionality
    // 0b1..Force input path of pad GPIO_SPI_B0_00
constexpr regs::RegValue32<3, 0> MUX_MODE;  // MUX Mode Select Field.
    // 0b000..Select mux mode: ALT0 mux port: FLEXSPI2_A_DATA00 of instance: flexspi2
    // 0b101..Select mux mode: ALT5 mux port: GPIO10_IO02 of instance: gpio10
}  // namespace SW_MUX_CTL_PAD_1

namespace SW_PAD_CTL_PAD_1 {
// IOMUXC_SW_PAD_CTL_PAD_1 values
constexpr regs::RegValue32<1, 16> HYS;   // Hyst. Enable Field
    // 0b0..Hysteresis Disabled
    // 0b1..Hysteresis Enabled
constexpr regs::RegValue32<2, 14> PUS;   // Pull Up / Down Config. Field
    // 0b00..100K Ohm Pull Down
    // 0b01..47K Ohm Pull Up
    // 0b10..100K Ohm Pull Up
    // 0b11..22K Ohm Pull Up
constexpr regs::RegValue32<1, 13> PUE;   // Pull / Keep Select Field
    // 0b0..Keeper
    // 0b1..Pull
constexpr regs::RegValue32<1, 12> PKE;   // Pull / Keep Enable Field
    // 0b0..Pull/Keeper Disabled
    // 0b1..Pull/Keeper Enabled
constexpr regs::RegValue32<1, 11> ODE;   // Open Drain Enable Field
    // 0b0..Open Drain Disabled
    // 0b1..Open Drain Enabled
constexpr regs::RegValue32<2,  6> SPEED;  // Speed Field
    // 0b00..low(50MHz)
    // 0b01..medium(100MHz)
    // 0b10..fast(150MHz)
    // 0b11..max(200MHz)
constexpr regs::RegValue32<3,  3> DSE;    // Drive Strength Field
    // 0b000..output driver disabled;
    // 0b001..R0(150 Ohm @ 3.3V, 260 Ohm@1.8V)
    // 0b010..R0/2
    // 0b011..R0/3
    // 0b100..R0/4
    // 0b101..R0/5
    // 0b110..R0/6
    // 0b111..R0/7
constexpr regs::RegValue32<1,  0> SRE;  // Slew Rate Field
    // 0b0..Slow Slew Rate
    // 0b1..Fast Slew Rate
}  // namespace SW_PAD_CTL_PAD_1

namespace SELECT_INPUT_1 {
// IOMUXC_SELECT_INPUT_1 values
constexpr regs::RegValue32<2, 0> DAISY;  // Selecting Pads Involved in Daisy Chain.
    // 0b00..Selecting Pad: GPIO_SD_B0_00 for Mode: ALT9
    // 0b01..Selecting Pad: GPIO_EMC_39 for Mode: ALT9
    // 0b10..Selecting Pad: GPIO_AD_B0_09 for Mode: ALT9
    // 0b11..Selecting Pad: GPIO_B1_13 for Mode: ALT8
}  // namespace SELECT_INPUT_1

}  // namespace IOMUXC

template <auto Member, size_t MemberOffset, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using IOMUXC_Reg = regs::Reg32<kIOMUXC_base, IOMUXC_Layout, Member,
                               MemberOffset, Bits, Shift, DirectAssign>;

namespace IOMUXC {

// IOMUXC SW_MUX_CTL_PAD
namespace SW_MUX_CTL_PAD {

constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,   0, 32, 0> GPIO_EMC_00;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,   1, 32, 0> GPIO_EMC_01;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,   2, 32, 0> GPIO_EMC_02;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,   3, 32, 0> GPIO_EMC_03;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,   4, 32, 0> GPIO_EMC_04;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,   5, 32, 0> GPIO_EMC_05;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,   6, 32, 0> GPIO_EMC_06;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,   7, 32, 0> GPIO_EMC_07;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,   8, 32, 0> GPIO_EMC_08;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,   9, 32, 0> GPIO_EMC_09;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  10, 32, 0> GPIO_EMC_10;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  11, 32, 0> GPIO_EMC_11;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  12, 32, 0> GPIO_EMC_12;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  13, 32, 0> GPIO_EMC_13;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  14, 32, 0> GPIO_EMC_14;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  15, 32, 0> GPIO_EMC_15;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  16, 32, 0> GPIO_EMC_16;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  17, 32, 0> GPIO_EMC_17;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  18, 32, 0> GPIO_EMC_18;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  19, 32, 0> GPIO_EMC_19;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  20, 32, 0> GPIO_EMC_20;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  21, 32, 0> GPIO_EMC_21;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  22, 32, 0> GPIO_EMC_22;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  23, 32, 0> GPIO_EMC_23;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  24, 32, 0> GPIO_EMC_24;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  25, 32, 0> GPIO_EMC_25;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  26, 32, 0> GPIO_EMC_26;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  27, 32, 0> GPIO_EMC_27;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  28, 32, 0> GPIO_EMC_28;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  29, 32, 0> GPIO_EMC_29;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  30, 32, 0> GPIO_EMC_30;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  31, 32, 0> GPIO_EMC_31;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  32, 32, 0> GPIO_EMC_32;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  33, 32, 0> GPIO_EMC_33;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  34, 32, 0> GPIO_EMC_34;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  35, 32, 0> GPIO_EMC_35;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  36, 32, 0> GPIO_EMC_36;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  37, 32, 0> GPIO_EMC_37;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  38, 32, 0> GPIO_EMC_38;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  39, 32, 0> GPIO_EMC_39;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  40, 32, 0> GPIO_EMC_40;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  41, 32, 0> GPIO_EMC_41;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  42, 32, 0> GPIO_AD_B0_00;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  43, 32, 0> GPIO_AD_B0_01;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  44, 32, 0> GPIO_AD_B0_02;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  45, 32, 0> GPIO_AD_B0_03;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  46, 32, 0> GPIO_AD_B0_04;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  47, 32, 0> GPIO_AD_B0_05;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  48, 32, 0> GPIO_AD_B0_06;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  49, 32, 0> GPIO_AD_B0_07;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  50, 32, 0> GPIO_AD_B0_08;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  51, 32, 0> GPIO_AD_B0_09;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  52, 32, 0> GPIO_AD_B0_10;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  53, 32, 0> GPIO_AD_B0_11;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  54, 32, 0> GPIO_AD_B0_12;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  55, 32, 0> GPIO_AD_B0_13;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  56, 32, 0> GPIO_AD_B0_14;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  57, 32, 0> GPIO_AD_B0_15;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  58, 32, 0> GPIO_AD_B1_00;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  59, 32, 0> GPIO_AD_B1_01;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  60, 32, 0> GPIO_AD_B1_02;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  61, 32, 0> GPIO_AD_B1_03;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  62, 32, 0> GPIO_AD_B1_04;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  63, 32, 0> GPIO_AD_B1_05;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  64, 32, 0> GPIO_AD_B1_06;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  65, 32, 0> GPIO_AD_B1_07;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  66, 32, 0> GPIO_AD_B1_08;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  67, 32, 0> GPIO_AD_B1_09;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  68, 32, 0> GPIO_AD_B1_10;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  69, 32, 0> GPIO_AD_B1_11;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  70, 32, 0> GPIO_AD_B1_12;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  71, 32, 0> GPIO_AD_B1_13;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  72, 32, 0> GPIO_AD_B1_14;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  73, 32, 0> GPIO_AD_B1_15;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  74, 32, 0> GPIO_B0_00;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  75, 32, 0> GPIO_B0_01;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  76, 32, 0> GPIO_B0_02;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  77, 32, 0> GPIO_B0_03;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  78, 32, 0> GPIO_B0_04;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  79, 32, 0> GPIO_B0_05;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  80, 32, 0> GPIO_B0_06;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  81, 32, 0> GPIO_B0_07;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  82, 32, 0> GPIO_B0_08;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  83, 32, 0> GPIO_B0_09;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  84, 32, 0> GPIO_B0_10;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  85, 32, 0> GPIO_B0_11;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  86, 32, 0> GPIO_B0_12;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  87, 32, 0> GPIO_B0_13;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  88, 32, 0> GPIO_B0_14;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  89, 32, 0> GPIO_B0_15;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  90, 32, 0> GPIO_B1_00;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  91, 32, 0> GPIO_B1_01;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  92, 32, 0> GPIO_B1_02;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  93, 32, 0> GPIO_B1_03;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  94, 32, 0> GPIO_B1_04;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  95, 32, 0> GPIO_B1_05;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  96, 32, 0> GPIO_B1_06;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  97, 32, 0> GPIO_B1_07;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  98, 32, 0> GPIO_B1_08;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD,  99, 32, 0> GPIO_B1_09;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD, 100, 32, 0> GPIO_B1_10;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD, 101, 32, 0> GPIO_B1_11;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD, 102, 32, 0> GPIO_B1_12;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD, 103, 32, 0> GPIO_B1_13;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD, 104, 32, 0> GPIO_B1_14;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD, 105, 32, 0> GPIO_B1_15;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD, 106, 32, 0> GPIO_SD_B0_00;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD, 107, 32, 0> GPIO_SD_B0_01;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD, 108, 32, 0> GPIO_SD_B0_02;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD, 109, 32, 0> GPIO_SD_B0_03;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD, 110, 32, 0> GPIO_SD_B0_04;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD, 111, 32, 0> GPIO_SD_B0_05;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD, 112, 32, 0> GPIO_SD_B1_00;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD, 113, 32, 0> GPIO_SD_B1_01;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD, 114, 32, 0> GPIO_SD_B1_02;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD, 115, 32, 0> GPIO_SD_B1_03;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD, 116, 32, 0> GPIO_SD_B1_04;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD, 117, 32, 0> GPIO_SD_B1_05;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD, 118, 32, 0> GPIO_SD_B1_06;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD, 119, 32, 0> GPIO_SD_B1_07;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD, 120, 32, 0> GPIO_SD_B1_08;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD, 121, 32, 0> GPIO_SD_B1_09;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD, 122, 32, 0> GPIO_SD_B1_10;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_MUX_CTL_PAD, 123, 32, 0> GPIO_SD_B1_11;
}  // namespace SW_MUX_CTL_PAD

// IOMUXC SW_PAD_CTL_PAD
namespace SW_PAD_CTL_PAD {

constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,   0, 32, 0> GPIO_EMC_00;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,   1, 32, 0> GPIO_EMC_01;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,   2, 32, 0> GPIO_EMC_02;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,   3, 32, 0> GPIO_EMC_03;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,   4, 32, 0> GPIO_EMC_04;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,   5, 32, 0> GPIO_EMC_05;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,   6, 32, 0> GPIO_EMC_06;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,   7, 32, 0> GPIO_EMC_07;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,   8, 32, 0> GPIO_EMC_08;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,   9, 32, 0> GPIO_EMC_09;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  10, 32, 0> GPIO_EMC_10;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  11, 32, 0> GPIO_EMC_11;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  12, 32, 0> GPIO_EMC_12;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  13, 32, 0> GPIO_EMC_13;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  14, 32, 0> GPIO_EMC_14;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  15, 32, 0> GPIO_EMC_15;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  16, 32, 0> GPIO_EMC_16;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  17, 32, 0> GPIO_EMC_17;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  18, 32, 0> GPIO_EMC_18;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  19, 32, 0> GPIO_EMC_19;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  20, 32, 0> GPIO_EMC_20;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  21, 32, 0> GPIO_EMC_21;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  22, 32, 0> GPIO_EMC_22;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  23, 32, 0> GPIO_EMC_23;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  24, 32, 0> GPIO_EMC_24;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  25, 32, 0> GPIO_EMC_25;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  26, 32, 0> GPIO_EMC_26;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  27, 32, 0> GPIO_EMC_27;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  28, 32, 0> GPIO_EMC_28;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  29, 32, 0> GPIO_EMC_29;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  30, 32, 0> GPIO_EMC_30;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  31, 32, 0> GPIO_EMC_31;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  32, 32, 0> GPIO_EMC_32;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  33, 32, 0> GPIO_EMC_33;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  34, 32, 0> GPIO_EMC_34;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  35, 32, 0> GPIO_EMC_35;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  36, 32, 0> GPIO_EMC_36;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  37, 32, 0> GPIO_EMC_37;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  38, 32, 0> GPIO_EMC_38;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  39, 32, 0> GPIO_EMC_39;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  40, 32, 0> GPIO_EMC_40;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  41, 32, 0> GPIO_EMC_41;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  42, 32, 0> GPIO_AD_B0_00;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  43, 32, 0> GPIO_AD_B0_01;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  44, 32, 0> GPIO_AD_B0_02;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  45, 32, 0> GPIO_AD_B0_03;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  46, 32, 0> GPIO_AD_B0_04;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  47, 32, 0> GPIO_AD_B0_05;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  48, 32, 0> GPIO_AD_B0_06;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  49, 32, 0> GPIO_AD_B0_07;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  50, 32, 0> GPIO_AD_B0_08;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  51, 32, 0> GPIO_AD_B0_09;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  52, 32, 0> GPIO_AD_B0_10;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  53, 32, 0> GPIO_AD_B0_11;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  54, 32, 0> GPIO_AD_B0_12;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  55, 32, 0> GPIO_AD_B0_13;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  56, 32, 0> GPIO_AD_B0_14;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  57, 32, 0> GPIO_AD_B0_15;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  58, 32, 0> GPIO_AD_B1_00;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  59, 32, 0> GPIO_AD_B1_01;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  60, 32, 0> GPIO_AD_B1_02;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  61, 32, 0> GPIO_AD_B1_03;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  62, 32, 0> GPIO_AD_B1_04;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  63, 32, 0> GPIO_AD_B1_05;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  64, 32, 0> GPIO_AD_B1_06;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  65, 32, 0> GPIO_AD_B1_07;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  66, 32, 0> GPIO_AD_B1_08;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  67, 32, 0> GPIO_AD_B1_09;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  68, 32, 0> GPIO_AD_B1_10;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  69, 32, 0> GPIO_AD_B1_11;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  70, 32, 0> GPIO_AD_B1_12;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  71, 32, 0> GPIO_AD_B1_13;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  72, 32, 0> GPIO_AD_B1_14;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  73, 32, 0> GPIO_AD_B1_15;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  74, 32, 0> GPIO_B0_00;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  75, 32, 0> GPIO_B0_01;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  76, 32, 0> GPIO_B0_02;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  77, 32, 0> GPIO_B0_03;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  78, 32, 0> GPIO_B0_04;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  79, 32, 0> GPIO_B0_05;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  80, 32, 0> GPIO_B0_06;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  81, 32, 0> GPIO_B0_07;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  82, 32, 0> GPIO_B0_08;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  83, 32, 0> GPIO_B0_09;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  84, 32, 0> GPIO_B0_10;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  85, 32, 0> GPIO_B0_11;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  86, 32, 0> GPIO_B0_12;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  87, 32, 0> GPIO_B0_13;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  88, 32, 0> GPIO_B0_14;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  89, 32, 0> GPIO_B0_15;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  90, 32, 0> GPIO_B1_00;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  91, 32, 0> GPIO_B1_01;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  92, 32, 0> GPIO_B1_02;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  93, 32, 0> GPIO_B1_03;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  94, 32, 0> GPIO_B1_04;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  95, 32, 0> GPIO_B1_05;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  96, 32, 0> GPIO_B1_06;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  97, 32, 0> GPIO_B1_07;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  98, 32, 0> GPIO_B1_08;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD,  99, 32, 0> GPIO_B1_09;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD, 100, 32, 0> GPIO_B1_10;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD, 101, 32, 0> GPIO_B1_11;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD, 102, 32, 0> GPIO_B1_12;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD, 103, 32, 0> GPIO_B1_13;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD, 104, 32, 0> GPIO_B1_14;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD, 105, 32, 0> GPIO_B1_15;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD, 106, 32, 0> GPIO_SD_B0_00;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD, 107, 32, 0> GPIO_SD_B0_01;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD, 108, 32, 0> GPIO_SD_B0_02;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD, 109, 32, 0> GPIO_SD_B0_03;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD, 110, 32, 0> GPIO_SD_B0_04;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD, 111, 32, 0> GPIO_SD_B0_05;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD, 112, 32, 0> GPIO_SD_B1_00;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD, 113, 32, 0> GPIO_SD_B1_01;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD, 114, 32, 0> GPIO_SD_B1_02;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD, 115, 32, 0> GPIO_SD_B1_03;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD, 116, 32, 0> GPIO_SD_B1_04;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD, 117, 32, 0> GPIO_SD_B1_05;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD, 118, 32, 0> GPIO_SD_B1_06;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD, 119, 32, 0> GPIO_SD_B1_07;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD, 120, 32, 0> GPIO_SD_B1_08;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD, 121, 32, 0> GPIO_SD_B1_09;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD, 122, 32, 0> GPIO_SD_B1_10;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SW_PAD_CTL_PAD, 123, 32, 0> GPIO_SD_B1_11;
}  // namespace SW_PAD_CTL_PAD

// IOMUXC SELECT_INPUT
namespace SELECT_INPUT {

constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,   0, 32, 0> ANATOP_USB_OTG1_ID_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,   1, 32, 0> ANATOP_USB_OTG2_ID_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,   2, 32, 0> CCM_PMIC_READY_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,   3, 32, 0> CSI_DATA02_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,   4, 32, 0> CSI_DATA03_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,   5, 32, 0> CSI_DATA04_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,   6, 32, 0> CSI_DATA05_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,   7, 32, 0> CSI_DATA06_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,   8, 32, 0> CSI_DATA07_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,   9, 32, 0> CSI_DATA08_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  10, 32, 0> CSI_DATA09_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  11, 32, 0> CSI_HSYNC_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  12, 32, 0> CSI_PIXCLK_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  13, 32, 0> CSI_VSYNC_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  14, 32, 0> ENET_IPG_CLK_RMII_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  15, 32, 0> ENET_MDIO_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  16, 32, 0> ENET0_RXDATA_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  17, 32, 0> ENET1_RXDATA_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  18, 32, 0> ENET_RXEN_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  19, 32, 0> ENET_RXERR_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  20, 32, 0> ENET0_TIMER_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  21, 32, 0> ENET_TXCLK_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  22, 32, 0> FLEXCAN1_RX_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  23, 32, 0> FLEXCAN2_RX_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  24, 32, 0> FLEXPWM1_PWMA3_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  25, 32, 0> FLEXPWM1_PWMA0_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  26, 32, 0> FLEXPWM1_PWMA1_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  27, 32, 0> FLEXPWM1_PWMA2_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  28, 32, 0> FLEXPWM1_PWMB3_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  29, 32, 0> FLEXPWM1_PWMB0_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  30, 32, 0> FLEXPWM1_PWMB1_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  31, 32, 0> FLEXPWM1_PWMB2_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  32, 32, 0> FLEXPWM2_PWMA3_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  33, 32, 0> FLEXPWM2_PWMA0_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  34, 32, 0> FLEXPWM2_PWMA1_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  35, 32, 0> FLEXPWM2_PWMA2_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  36, 32, 0> FLEXPWM2_PWMB3_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  37, 32, 0> FLEXPWM2_PWMB0_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  38, 32, 0> FLEXPWM2_PWMB1_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  39, 32, 0> FLEXPWM2_PWMB2_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  40, 32, 0> FLEXPWM4_PWMA0_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  41, 32, 0> FLEXPWM4_PWMA1_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  42, 32, 0> FLEXPWM4_PWMA2_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  43, 32, 0> FLEXPWM4_PWMA3_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  44, 32, 0> FLEXSPIA_DQS_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  45, 32, 0> FLEXSPIA_DATA0_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  46, 32, 0> FLEXSPIA_DATA1_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  47, 32, 0> FLEXSPIA_DATA2_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  48, 32, 0> FLEXSPIA_DATA3_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  49, 32, 0> FLEXSPIB_DATA0_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  50, 32, 0> FLEXSPIB_DATA1_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  51, 32, 0> FLEXSPIB_DATA2_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  52, 32, 0> FLEXSPIB_DATA3_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  53, 32, 0> FLEXSPIA_SCK_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  54, 32, 0> LPI2C1_SCL_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  55, 32, 0> LPI2C1_SDA_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  56, 32, 0> LPI2C2_SCL_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  57, 32, 0> LPI2C2_SDA_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  58, 32, 0> LPI2C3_SCL_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  59, 32, 0> LPI2C3_SDA_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  60, 32, 0> LPI2C4_SCL_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  61, 32, 0> LPI2C4_SDA_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  62, 32, 0> LPSPI1_PCS0_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  63, 32, 0> LPSPI1_SCK_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  64, 32, 0> LPSPI1_SDI_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  65, 32, 0> LPSPI1_SDO_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  66, 32, 0> LPSPI2_PCS0_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  67, 32, 0> LPSPI2_SCK_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  68, 32, 0> LPSPI2_SDI_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  69, 32, 0> LPSPI2_SDO_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  70, 32, 0> LPSPI3_PCS0_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  71, 32, 0> LPSPI3_SCK_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  72, 32, 0> LPSPI3_SDI_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  73, 32, 0> LPSPI3_SDO_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  74, 32, 0> LPSPI4_PCS0_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  75, 32, 0> LPSPI4_SCK_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  76, 32, 0> LPSPI4_SDI_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  77, 32, 0> LPSPI4_SDO_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  78, 32, 0> LPUART2_RX_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  79, 32, 0> LPUART2_TX_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  80, 32, 0> LPUART3_CTS_B_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  81, 32, 0> LPUART3_RX_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  82, 32, 0> LPUART3_TX_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  83, 32, 0> LPUART4_RX_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  84, 32, 0> LPUART4_TX_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  85, 32, 0> LPUART5_RX_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  86, 32, 0> LPUART5_TX_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  87, 32, 0> LPUART6_RX_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  88, 32, 0> LPUART6_TX_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  89, 32, 0> LPUART7_RX_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  90, 32, 0> LPUART7_TX_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  91, 32, 0> LPUART8_RX_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  92, 32, 0> LPUART8_TX_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  93, 32, 0> NMI_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  94, 32, 0> QTIMER2_TIMER0_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  95, 32, 0> QTIMER2_TIMER1_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  96, 32, 0> QTIMER2_TIMER2_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  97, 32, 0> QTIMER2_TIMER3_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  98, 32, 0> QTIMER3_TIMER0_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT,  99, 32, 0> QTIMER3_TIMER1_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 100, 32, 0> QTIMER3_TIMER2_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 101, 32, 0> QTIMER3_TIMER3_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 102, 32, 0> SAI1_MCLK2_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 103, 32, 0> SAI1_RX_BCLK_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 104, 32, 0> SAI1_RX_DATA0_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 105, 32, 0> SAI1_RX_DATA1_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 106, 32, 0> SAI1_RX_DATA2_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 107, 32, 0> SAI1_RX_DATA3_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 108, 32, 0> SAI1_RX_SYNC_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 109, 32, 0> SAI1_TX_BCLK_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 110, 32, 0> SAI1_TX_SYNC_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 111, 32, 0> SAI2_MCLK2_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 112, 32, 0> SAI2_RX_BCLK_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 113, 32, 0> SAI2_RX_DATA0_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 114, 32, 0> SAI2_RX_SYNC_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 115, 32, 0> SAI2_TX_BCLK_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 116, 32, 0> SAI2_TX_SYNC_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 117, 32, 0> SPDIF_IN_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 118, 32, 0> USB_OTG2_OC_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 119, 32, 0> USB_OTG1_OC_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 120, 32, 0> USDHC1_CD_B_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 121, 32, 0> USDHC1_WP_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 122, 32, 0> USDHC2_CLK_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 123, 32, 0> USDHC2_CD_B_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 124, 32, 0> USDHC2_CMD_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 125, 32, 0> USDHC2_DATA0_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 126, 32, 0> USDHC2_DATA1_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 127, 32, 0> USDHC2_DATA2_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 128, 32, 0> USDHC2_DATA3_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 129, 32, 0> USDHC2_DATA4_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 130, 32, 0> USDHC2_DATA5_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 131, 32, 0> USDHC2_DATA6_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 132, 32, 0> USDHC2_DATA7_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 133, 32, 0> USDHC2_WP_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 134, 32, 0> XBAR1_IN02_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 135, 32, 0> XBAR1_IN03_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 136, 32, 0> XBAR1_IN04_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 137, 32, 0> XBAR1_IN05_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 138, 32, 0> XBAR1_IN06_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 139, 32, 0> XBAR1_IN07_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 140, 32, 0> XBAR1_IN08_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 141, 32, 0> XBAR1_IN09_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 142, 32, 0> XBAR1_IN17_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 143, 32, 0> XBAR1_IN18_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 144, 32, 0> XBAR1_IN20_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 145, 32, 0> XBAR1_IN22_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 146, 32, 0> XBAR1_IN23_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 147, 32, 0> XBAR1_IN24_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 148, 32, 0> XBAR1_IN14_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 149, 32, 0> XBAR1_IN15_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 150, 32, 0> XBAR1_IN16_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 151, 32, 0> XBAR1_IN25_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 152, 32, 0> XBAR1_IN19_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT, 153, 32, 0> XBAR1_IN21_SELECT_INPUT;
}  // namespace SELECT_INPUT

// IOMUXC SELECT_INPUT_1
namespace SELECT_INPUT_1 {

constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1,  0, 32, 0> ENET2_IPG_CLK_RMII_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1,  1, 32, 0> ENET2_IPP_IND_MAC0_MDIO_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1,  2, 32, 0> ENET2_IPP_IND_MAC0_RXDATA_SELECT_INPUT_0;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1,  3, 32, 0> ENET2_IPP_IND_MAC0_RXDATA_SELECT_INPUT_1;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1,  4, 32, 0> ENET2_IPP_IND_MAC0_RXEN_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1,  5, 32, 0> ENET2_IPP_IND_MAC0_RXERR_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1,  6, 32, 0> ENET2_IPP_IND_MAC0_TIMER_SELECT_INPUT_0;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1,  7, 32, 0> ENET2_IPP_IND_MAC0_TXCLK_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1,  8, 32, 0> FLEXSPI2_IPP_IND_DQS_FA_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1,  9, 32, 0> FLEXSPI2_IPP_IND_IO_FA_BIT0_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1, 10, 32, 0> FLEXSPI2_IPP_IND_IO_FA_BIT1_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1, 11, 32, 0> FLEXSPI2_IPP_IND_IO_FA_BIT2_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1, 12, 32, 0> FLEXSPI2_IPP_IND_IO_FA_BIT3_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1, 13, 32, 0> FLEXSPI2_IPP_IND_IO_FB_BIT0_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1, 14, 32, 0> FLEXSPI2_IPP_IND_IO_FB_BIT1_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1, 15, 32, 0> FLEXSPI2_IPP_IND_IO_FB_BIT2_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1, 16, 32, 0> FLEXSPI2_IPP_IND_IO_FB_BIT3_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1, 17, 32, 0> FLEXSPI2_IPP_IND_SCK_FA_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1, 18, 32, 0> FLEXSPI2_IPP_IND_SCK_FB_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1, 19, 32, 0> GPT1_IPP_IND_CAPIN1_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1, 20, 32, 0> GPT1_IPP_IND_CAPIN2_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1, 21, 32, 0> GPT1_IPP_IND_CLKIN_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1, 22, 32, 0> GPT2_IPP_IND_CAPIN1_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1, 23, 32, 0> GPT2_IPP_IND_CAPIN2_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1, 24, 32, 0> GPT2_IPP_IND_CLKIN_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1, 25, 32, 0> SAI3_IPG_CLK_SAI_MCLK_SELECT_INPUT_2;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1, 26, 32, 0> SAI3_IPP_IND_SAI_RXBCLK_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1, 27, 32, 0> SAI3_IPP_IND_SAI_RXDATA_SELECT_INPUT_0;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1, 28, 32, 0> SAI3_IPP_IND_SAI_RXSYNC_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1, 29, 32, 0> SAI3_IPP_IND_SAI_TXBCLK_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1, 30, 32, 0> SAI3_IPP_IND_SAI_TXSYNC_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1, 31, 32, 0> SEMC_I_IPP_IND_DQS4_SELECT_INPUT;
constexpr IOMUXC_Reg<&IOMUXC_Layout::SELECT_INPUT_1, 32, 32, 0> CANFD_IPP_IND_CANRX_SELECT_INPUT;
}  // namespace SELECT_INPUT_1

}  // namespace IOMUXC

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign

// // IOMUXC SW_MUX_CTL_PAD indexes.
// enum IOMUXC_SW_MUX_CTL_PAD : size_t {
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_00 =  0,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_01 =  1,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_02 =  2,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_03 =  3,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_04 =  4,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_05 =  5,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_06 =  6,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_07 =  7,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_08 =  8,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_09 =  9,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_10 = 10,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_11 = 11,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_12 = 12,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_13 = 13,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_14 = 14,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_15 = 15,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_16 = 16,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_17 = 17,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_18 = 18,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_19 = 19,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_20 = 20,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_21 = 21,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_22 = 22,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_23 = 23,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_24 = 24,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_25 = 25,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_26 = 26,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_27 = 27,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_28 = 28,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_29 = 29,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_30 = 30,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_31 = 31,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_32 = 32,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_33 = 33,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_34 = 34,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_35 = 35,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_36 = 36,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_37 = 37,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_38 = 38,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_39 = 39,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_40 = 40,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_41 = 41,

//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_00 = 42,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_01 = 43,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_02 = 44,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_03 = 45,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_04 = 46,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_05 = 47,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_06 = 48,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_07 = 49,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_08 = 50,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_09 = 51,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_10 = 52,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_11 = 53,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_12 = 54,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_13 = 55,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_14 = 56,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_15 = 57,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_00 = 58,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_01 = 59,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_02 = 60,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_03 = 61,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_04 = 62,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_05 = 63,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_06 = 64,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_07 = 65,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_08 = 66,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_09 = 67,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_10 = 68,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_11 = 69,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_12 = 70,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_13 = 71,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_14 = 72,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_15 = 73,

//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B0_00 =  74,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B0_01 =  75,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B0_02 =  76,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B0_03 =  77,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B0_04 =  78,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B0_05 =  79,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B0_06 =  80,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B0_07 =  81,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B0_08 =  82,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B0_09 =  83,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B0_10 =  84,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B0_11 =  85,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B0_12 =  86,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B0_13 =  87,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B0_14 =  88,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B0_15 =  89,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_00 =  90,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_01 =  91,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_02 =  92,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_03 =  93,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_04 =  94,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_05 =  95,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_06 =  96,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_07 =  97,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_08 =  98,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_09 =  99,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_10 = 100,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_11 = 101,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_12 = 102,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_13 = 103,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_14 = 104,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_15 = 105,

//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B0_00 = 106,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B0_01 = 107,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B0_02 = 108,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B0_03 = 109,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B0_04 = 110,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B0_05 = 111,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_00 = 112,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_01 = 113,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_02 = 114,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_03 = 115,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_04 = 116,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_05 = 117,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_06 = 118,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_07 = 119,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_08 = 120,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_09 = 121,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_10 = 122,
//   kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_11 = 123,
// };

// // IOMUXC SW_PAD_CTL_PAD indexes.
// enum IOMUXC_SW_PAD_CTL_PAD : size_t {
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_00 =  0,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_01 =  1,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_02 =  2,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_03 =  3,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_04 =  4,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_05 =  5,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_06 =  6,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_07 =  7,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_08 =  8,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_09 =  9,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_10 = 10,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_11 = 11,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_12 = 12,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_13 = 13,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_14 = 14,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_15 = 15,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_16 = 16,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_17 = 17,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_18 = 18,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_19 = 19,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_20 = 20,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_21 = 21,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_22 = 22,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_23 = 23,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_24 = 24,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_25 = 25,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_26 = 26,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_27 = 27,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_28 = 28,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_29 = 29,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_30 = 30,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_31 = 31,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_32 = 32,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_33 = 33,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_34 = 34,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_35 = 35,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_36 = 36,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_37 = 37,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_38 = 38,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_39 = 39,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_40 = 40,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_41 = 41,

//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_00 = 42,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_01 = 43,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_02 = 44,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_03 = 45,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_04 = 46,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_05 = 47,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_06 = 48,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_07 = 49,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_08 = 50,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_09 = 51,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_10 = 52,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_11 = 53,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_12 = 54,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_13 = 55,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_14 = 56,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_15 = 57,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_00 = 58,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_01 = 59,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_02 = 60,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_03 = 61,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_04 = 62,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_05 = 63,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_06 = 64,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_07 = 65,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_08 = 66,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_09 = 67,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_10 = 68,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_11 = 69,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_12 = 70,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_13 = 71,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_14 = 72,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_15 = 73,

//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B0_00 =  74,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B0_01 =  75,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B0_02 =  76,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B0_03 =  77,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B0_04 =  78,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B0_05 =  79,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B0_06 =  80,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B0_07 =  81,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B0_08 =  82,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B0_09 =  83,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B0_10 =  84,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B0_11 =  85,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B0_12 =  86,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B0_13 =  87,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B0_14 =  88,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B0_15 =  89,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_00 =  90,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_01 =  91,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_02 =  92,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_03 =  93,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_04 =  94,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_05 =  95,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_06 =  96,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_07 =  97,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_08 =  98,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_09 =  99,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_10 = 100,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_11 = 101,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_12 = 102,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_13 = 103,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_14 = 104,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_15 = 105,

//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B0_00 = 106,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B0_01 = 107,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B0_02 = 108,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B0_03 = 109,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B0_04 = 110,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B0_05 = 111,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_00 = 112,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_01 = 113,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_02 = 114,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_03 = 115,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_04 = 116,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_05 = 117,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_06 = 118,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_07 = 119,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_08 = 120,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_09 = 121,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_10 = 122,
//     kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_11 = 123,
// };

// // IOMUXC SELECT_INPUT indexes.
// enum IOMUXC_SELECT_INPUT {
//   kIOMUXC_ANATOP_USB_OTG1_ID_SELECT_INPUT = 0,
//   kIOMUXC_ANATOP_USB_OTG2_ID_SELECT_INPUT = 1,

//   kIOMUXC_CCM_PMIC_READY_SELECT_INPUT = 2,

//   kIOMUXC_CSI_DATA02_SELECT_INPUT =  3,
//   kIOMUXC_CSI_DATA03_SELECT_INPUT =  4,
//   kIOMUXC_CSI_DATA04_SELECT_INPUT =  5,
//   kIOMUXC_CSI_DATA05_SELECT_INPUT =  6,
//   kIOMUXC_CSI_DATA06_SELECT_INPUT =  7,
//   kIOMUXC_CSI_DATA07_SELECT_INPUT =  8,
//   kIOMUXC_CSI_DATA08_SELECT_INPUT =  9,
//   kIOMUXC_CSI_DATA09_SELECT_INPUT = 10,
//   kIOMUXC_CSI_HSYNC_SELECT_INPUT  = 11,
//   kIOMUXC_CSI_PIXCLK_SELECT_INPUT = 12,
//   kIOMUXC_CSI_VSYNC_SELECT_INPUT  = 13,

//   kIOMUXC_ENET_IPG_CLK_RMII_SELECT_INPUT = 14,
//   kIOMUXC_ENET_MDIO_SELECT_INPUT         = 15,
//   kIOMUXC_ENET0_RXDATA_SELECT_INPUT      = 16,
//   kIOMUXC_ENET1_RXDATA_SELECT_INPUT      = 17,
//   kIOMUXC_ENET_RXEN_SELECT_INPUT         = 18,
//   kIOMUXC_ENET_RXERR_SELECT_INPUT        = 19,
//   kIOMUXC_ENET0_TIMER_SELECT_INPUT       = 20,
//   kIOMUXC_ENET_TXCLK_SELECT_INPUT        = 21,

//   kIOMUXC_FLEXCAN1_RX_SELECT_INPUT = 22,
//   kIOMUXC_FLEXCAN2_RX_SELECT_INPUT = 23,

//   kIOMUXC_FLEXPWM1_PWMA3_SELECT_INPUT = 24,
//   kIOMUXC_FLEXPWM1_PWMA0_SELECT_INPUT = 25,
//   kIOMUXC_FLEXPWM1_PWMA1_SELECT_INPUT = 26,
//   kIOMUXC_FLEXPWM1_PWMA2_SELECT_INPUT = 27,
//   kIOMUXC_FLEXPWM1_PWMB3_SELECT_INPUT = 28,
//   kIOMUXC_FLEXPWM1_PWMB0_SELECT_INPUT = 29,
//   kIOMUXC_FLEXPWM1_PWMB1_SELECT_INPUT = 30,
//   kIOMUXC_FLEXPWM1_PWMB2_SELECT_INPUT = 31,
//   kIOMUXC_FLEXPWM2_PWMA3_SELECT_INPUT = 32,
//   kIOMUXC_FLEXPWM2_PWMA0_SELECT_INPUT = 33,
//   kIOMUXC_FLEXPWM2_PWMA1_SELECT_INPUT = 34,
//   kIOMUXC_FLEXPWM2_PWMA2_SELECT_INPUT = 35,
//   kIOMUXC_FLEXPWM2_PWMB3_SELECT_INPUT = 36,
//   kIOMUXC_FLEXPWM2_PWMB0_SELECT_INPUT = 37,
//   kIOMUXC_FLEXPWM2_PWMB1_SELECT_INPUT = 38,
//   kIOMUXC_FLEXPWM2_PWMB2_SELECT_INPUT = 39,
//   kIOMUXC_FLEXPWM4_PWMA0_SELECT_INPUT = 40,
//   kIOMUXC_FLEXPWM4_PWMA1_SELECT_INPUT = 41,
//   kIOMUXC_FLEXPWM4_PWMA2_SELECT_INPUT = 42,
//   kIOMUXC_FLEXPWM4_PWMA3_SELECT_INPUT = 43,

//   kIOMUXC_FLEXSPIA_DQS_SELECT_INPUT   = 44,
//   kIOMUXC_FLEXSPIA_DATA0_SELECT_INPUT = 45,
//   kIOMUXC_FLEXSPIA_DATA1_SELECT_INPUT = 46,
//   kIOMUXC_FLEXSPIA_DATA2_SELECT_INPUT = 47,
//   kIOMUXC_FLEXSPIA_DATA3_SELECT_INPUT = 48,
//   kIOMUXC_FLEXSPIB_DATA0_SELECT_INPUT = 49,
//   kIOMUXC_FLEXSPIB_DATA1_SELECT_INPUT = 50,
//   kIOMUXC_FLEXSPIB_DATA2_SELECT_INPUT = 51,
//   kIOMUXC_FLEXSPIB_DATA3_SELECT_INPUT = 52,
//   kIOMUXC_FLEXSPIA_SCK_SELECT_INPUT   = 53,

//   kIOMUXC_LPI2C1_SCL_SELECT_INPUT = 54,
//   kIOMUXC_LPI2C1_SDA_SELECT_INPUT = 55,
//   kIOMUXC_LPI2C2_SCL_SELECT_INPUT = 56,
//   kIOMUXC_LPI2C2_SDA_SELECT_INPUT = 57,
//   kIOMUXC_LPI2C3_SCL_SELECT_INPUT = 58,
//   kIOMUXC_LPI2C3_SDA_SELECT_INPUT = 59,
//   kIOMUXC_LPI2C4_SCL_SELECT_INPUT = 60,
//   kIOMUXC_LPI2C4_SDA_SELECT_INPUT = 61,

//   kIOMUXC_LPSPI1_PCS0_SELECT_INPUT = 62,
//   kIOMUXC_LPSPI1_SCK_SELECT_INPUT  = 63,
//   kIOMUXC_LPSPI1_SDI_SELECT_INPUT  = 64,
//   kIOMUXC_LPSPI1_SDO_SELECT_INPUT  = 65,
//   kIOMUXC_LPSPI2_PCS0_SELECT_INPUT = 66,
//   kIOMUXC_LPSPI2_SCK_SELECT_INPUT  = 67,
//   kIOMUXC_LPSPI2_SDI_SELECT_INPUT  = 68,
//   kIOMUXC_LPSPI2_SDO_SELECT_INPUT  = 69,
//   kIOMUXC_LPSPI3_PCS0_SELECT_INPUT = 70,
//   kIOMUXC_LPSPI3_SCK_SELECT_INPUT  = 71,
//   kIOMUXC_LPSPI3_SDI_SELECT_INPUT  = 72,
//   kIOMUXC_LPSPI3_SDO_SELECT_INPUT  = 73,
//   kIOMUXC_LPSPI4_PCS0_SELECT_INPUT = 74,
//   kIOMUXC_LPSPI4_SCK_SELECT_INPUT  = 75,
//   kIOMUXC_LPSPI4_SDI_SELECT_INPUT  = 76,
//   kIOMUXC_LPSPI4_SDO_SELECT_INPUT  = 77,

//   kIOMUXC_LPUART2_RX_SELECT_INPUT    = 78,
//   kIOMUXC_LPUART2_TX_SELECT_INPUT    = 79,
//   kIOMUXC_LPUART3_CTS_B_SELECT_INPUT = 80,
//   kIOMUXC_LPUART3_RX_SELECT_INPUT    = 81,
//   kIOMUXC_LPUART3_TX_SELECT_INPUT    = 82,
//   kIOMUXC_LPUART4_RX_SELECT_INPUT    = 83,
//   kIOMUXC_LPUART4_TX_SELECT_INPUT    = 84,
//   kIOMUXC_LPUART5_RX_SELECT_INPUT    = 85,
//   kIOMUXC_LPUART5_TX_SELECT_INPUT    = 86,
//   kIOMUXC_LPUART6_RX_SELECT_INPUT    = 87,
//   kIOMUXC_LPUART6_TX_SELECT_INPUT    = 88,
//   kIOMUXC_LPUART7_RX_SELECT_INPUT    = 89,
//   kIOMUXC_LPUART7_TX_SELECT_INPUT    = 90,
//   kIOMUXC_LPUART8_RX_SELECT_INPUT    = 91,
//   kIOMUXC_LPUART8_TX_SELECT_INPUT    = 92,

//   kIOMUXC_NMI_SELECT_INPUT = 93,

//   kIOMUXC_QTIMER2_TIMER0_SELECT_INPUT =  94,
//   kIOMUXC_QTIMER2_TIMER1_SELECT_INPUT =  95,
//   kIOMUXC_QTIMER2_TIMER2_SELECT_INPUT =  96,
//   kIOMUXC_QTIMER2_TIMER3_SELECT_INPUT =  97,
//   kIOMUXC_QTIMER3_TIMER0_SELECT_INPUT =  98,
//   kIOMUXC_QTIMER3_TIMER1_SELECT_INPUT =  99,
//   kIOMUXC_QTIMER3_TIMER2_SELECT_INPUT = 100,
//   kIOMUXC_QTIMER3_TIMER3_SELECT_INPUT = 101,

//   kIOMUXC_SAI1_MCLK2_SELECT_INPUT    = 102,
//   kIOMUXC_SAI1_RX_BCLK_SELECT_INPUT  = 103,
//   kIOMUXC_SAI1_RX_DATA0_SELECT_INPUT = 104,
//   kIOMUXC_SAI1_RX_DATA1_SELECT_INPUT = 105,
//   kIOMUXC_SAI1_RX_DATA2_SELECT_INPUT = 106,
//   kIOMUXC_SAI1_RX_DATA3_SELECT_INPUT = 107,
//   kIOMUXC_SAI1_RX_SYNC_SELECT_INPUT  = 108,
//   kIOMUXC_SAI1_TX_BCLK_SELECT_INPUT  = 109,
//   kIOMUXC_SAI1_TX_SYNC_SELECT_INPUT  = 110,
//   kIOMUXC_SAI2_MCLK2_SELECT_INPUT    = 111,
//   kIOMUXC_SAI2_RX_BCLK_SELECT_INPUT  = 112,
//   kIOMUXC_SAI2_RX_DATA0_SELECT_INPUT = 113,
//   kIOMUXC_SAI2_RX_SYNC_SELECT_INPUT  = 114,
//   kIOMUXC_SAI2_TX_BCLK_SELECT_INPUT  = 115,
//   kIOMUXC_SAI2_TX_SYNC_SELECT_INPUT  = 116,

//   kIOMUXC_SPDIF_IN_SELECT_INPUT = 117,

//   kIOMUXC_USB_OTG2_OC_SELECT_INPUT = 118,
//   kIOMUXC_USB_OTG1_OC_SELECT_INPUT = 119,

//   kIOMUXC_USDHC1_CD_B_SELECT_INPUT = 120,
//   kIOMUXC_USDHC1_WP_SELECT_INPUT   = 121,

//   kIOMUXC_USDHC2_CLK_SELECT_INPUT   = 122,
//   kIOMUXC_USDHC2_CD_B_SELECT_INPUT  = 123,
//   kIOMUXC_USDHC2_CMD_SELECT_INPUT   = 124,
//   kIOMUXC_USDHC2_DATA0_SELECT_INPUT = 125,
//   kIOMUXC_USDHC2_DATA1_SELECT_INPUT = 126,
//   kIOMUXC_USDHC2_DATA2_SELECT_INPUT = 127,
//   kIOMUXC_USDHC2_DATA3_SELECT_INPUT = 128,
//   kIOMUXC_USDHC2_DATA4_SELECT_INPUT = 129,
//   kIOMUXC_USDHC2_DATA5_SELECT_INPUT = 130,
//   kIOMUXC_USDHC2_DATA6_SELECT_INPUT = 131,
//   kIOMUXC_USDHC2_DATA7_SELECT_INPUT = 132,
//   kIOMUXC_USDHC2_WP_SELECT_INPUT    = 133,

//   kIOMUXC_XBAR1_IN02_SELECT_INPUT = 134,
//   kIOMUXC_XBAR1_IN03_SELECT_INPUT = 135,
//   kIOMUXC_XBAR1_IN04_SELECT_INPUT = 136,
//   kIOMUXC_XBAR1_IN05_SELECT_INPUT = 137,
//   kIOMUXC_XBAR1_IN06_SELECT_INPUT = 138,
//   kIOMUXC_XBAR1_IN07_SELECT_INPUT = 139,
//   kIOMUXC_XBAR1_IN08_SELECT_INPUT = 140,
//   kIOMUXC_XBAR1_IN09_SELECT_INPUT = 141,
//   kIOMUXC_XBAR1_IN17_SELECT_INPUT = 142,
//   kIOMUXC_XBAR1_IN18_SELECT_INPUT = 143,
//   kIOMUXC_XBAR1_IN20_SELECT_INPUT = 144,
//   kIOMUXC_XBAR1_IN22_SELECT_INPUT = 145,
//   kIOMUXC_XBAR1_IN23_SELECT_INPUT = 146,
//   kIOMUXC_XBAR1_IN24_SELECT_INPUT = 147,
//   kIOMUXC_XBAR1_IN14_SELECT_INPUT = 148,
//   kIOMUXC_XBAR1_IN15_SELECT_INPUT = 149,
//   kIOMUXC_XBAR1_IN16_SELECT_INPUT = 150,
//   kIOMUXC_XBAR1_IN25_SELECT_INPUT = 151,
//   kIOMUXC_XBAR1_IN19_SELECT_INPUT = 152,
//   kIOMUXC_XBAR1_IN21_SELECT_INPUT = 153,
// };

// // IOMUXC SELECT_INPUT_1 indexes.
// enum IOMUXC_SELECT_INPUT_1 {
//     kIOMUXC_ENET2_IPG_CLK_RMII_SELECT_INPUT          = 0,
//     kIOMUXC_ENET2_IPP_IND_MAC0_MDIO_SELECT_INPUT     = 1,
//     kIOMUXC_ENET2_IPP_IND_MAC0_RXDATA_SELECT_INPUT_0 = 2,
//     kIOMUXC_ENET2_IPP_IND_MAC0_RXDATA_SELECT_INPUT_1 = 3,
//     kIOMUXC_ENET2_IPP_IND_MAC0_RXEN_SELECT_INPUT     = 4,
//     kIOMUXC_ENET2_IPP_IND_MAC0_RXERR_SELECT_INPUT    = 5,
//     kIOMUXC_ENET2_IPP_IND_MAC0_TIMER_SELECT_INPUT_0  = 6,
//     kIOMUXC_ENET2_IPP_IND_MAC0_TXCLK_SELECT_INPUT    = 7,

//     kIOMUXC_FLEXSPI2_IPP_IND_DQS_FA_SELECT_INPUT     =  8,
//     kIOMUXC_FLEXSPI2_IPP_IND_IO_FA_BIT0_SELECT_INPUT =  9,
//     kIOMUXC_FLEXSPI2_IPP_IND_IO_FA_BIT1_SELECT_INPUT = 10,
//     kIOMUXC_FLEXSPI2_IPP_IND_IO_FA_BIT2_SELECT_INPUT = 11,
//     kIOMUXC_FLEXSPI2_IPP_IND_IO_FA_BIT3_SELECT_INPUT = 12,
//     kIOMUXC_FLEXSPI2_IPP_IND_IO_FB_BIT0_SELECT_INPUT = 13,
//     kIOMUXC_FLEXSPI2_IPP_IND_IO_FB_BIT1_SELECT_INPUT = 14,
//     kIOMUXC_FLEXSPI2_IPP_IND_IO_FB_BIT2_SELECT_INPUT = 15,
//     kIOMUXC_FLEXSPI2_IPP_IND_IO_FB_BIT3_SELECT_INPUT = 16,
//     kIOMUXC_FLEXSPI2_IPP_IND_SCK_FA_SELECT_INPUT     = 17,
//     kIOMUXC_FLEXSPI2_IPP_IND_SCK_FB_SELECT_INPUT     = 18,

//     kIOMUXC_GPT1_IPP_IND_CAPIN1_SELECT_INPUT = 19,
//     kIOMUXC_GPT1_IPP_IND_CAPIN2_SELECT_INPUT = 20,
//     kIOMUXC_GPT1_IPP_IND_CLKIN_SELECT_INPUT  = 21,
//     kIOMUXC_GPT2_IPP_IND_CAPIN1_SELECT_INPUT = 22,
//     kIOMUXC_GPT2_IPP_IND_CAPIN2_SELECT_INPUT = 23,
//     kIOMUXC_GPT2_IPP_IND_CLKIN_SELECT_INPUT  = 24,

//     kIOMUXC_SAI3_IPG_CLK_SAI_MCLK_SELECT_INPUT_2   = 25,
//     kIOMUXC_SAI3_IPP_IND_SAI_RXBCLK_SELECT_INPUT   = 26,
//     kIOMUXC_SAI3_IPP_IND_SAI_RXDATA_SELECT_INPUT_0 = 27,
//     kIOMUXC_SAI3_IPP_IND_SAI_RXSYNC_SELECT_INPUT   = 28,
//     kIOMUXC_SAI3_IPP_IND_SAI_TXBCLK_SELECT_INPUT   = 29,
//     kIOMUXC_SAI3_IPP_IND_SAI_TXSYNC_SELECT_INPUT   = 30,

//     kIOMUXC_SEMC_I_IPP_IND_DQS4_SELECT_INPUT = 31,

//     kIOMUXC_CANFD_IPP_IND_CANRX_SELECT_INPUT = 32,
// };
