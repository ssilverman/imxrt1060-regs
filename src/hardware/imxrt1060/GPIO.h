// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// GPIO.h defines all the GPIO registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// GPIO layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_GPIO.h
// * https://github.com/nxp-mcuxpresso/legacy-mcux-sdk/blob/main/devices/MIMXRT1062/MIMXRT1062.h

struct GPIO_Layout {
  volatile uint32_t DR;                                /**< GPIO data register, offset: 0x0 */
  volatile uint32_t GDIR;                              /**< GPIO direction register, offset: 0x4 */
  const volatile uint32_t PSR;                         /**< GPIO pad status register, offset: 0x8 */
  volatile uint32_t ICR1;                              /**< GPIO interrupt configuration register1, offset: 0xC */
  volatile uint32_t ICR2;                              /**< GPIO interrupt configuration register2, offset: 0x10 */
  volatile uint32_t IMR;                               /**< GPIO interrupt mask register, offset: 0x14 */
  volatile uint32_t ISR;                               /**< GPIO interrupt status register, offset: 0x18 */
  volatile uint32_t EDGE_SEL;                          /**< GPIO edge select register, offset: 0x1C */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[25];
  volatile uint32_t DR_SET;                            /**< GPIO data register SET, offset: 0x84 */
  volatile uint32_t DR_CLEAR;                          /**< GPIO data register CLEAR, offset: 0x88 */
  volatile uint32_t DR_TOGGLE;                         /**< GPIO data register TOGGLE, offset: 0x8C */
};

constexpr size_t    kGPIO_size  = 0x90;
constexpr uintptr_t kGPIO1_base = 0x401B8000;
constexpr uintptr_t kGPIO2_base = 0x401BC000;
constexpr uintptr_t kGPIO3_base = 0x401C0000;
constexpr uintptr_t kGPIO4_base = 0x401C4000;
constexpr uintptr_t kGPIO5_base = 0x400C0000;
constexpr uintptr_t kGPIO6_base = 0x42000000;
constexpr uintptr_t kGPIO7_base = 0x42004000;
constexpr uintptr_t kGPIO8_base = 0x42008000;
constexpr uintptr_t kGPIO9_base = 0x4200C000;

namespace GPIO1 {
constexpr regs::RegGroup<GPIO_Layout, kGPIO_size, kGPIO1_base> group;
}  // namespace GPIO1

namespace GPIO2 {
constexpr regs::RegGroup<GPIO_Layout, kGPIO_size, kGPIO2_base> group;
}  // namespace GPIO2

namespace GPIO3 {
constexpr regs::RegGroup<GPIO_Layout, kGPIO_size, kGPIO3_base> group;
}  // namespace GPIO3

namespace GPIO4 {
constexpr regs::RegGroup<GPIO_Layout, kGPIO_size, kGPIO4_base> group;
}  // namespace GPIO4

namespace GPIO5 {
constexpr regs::RegGroup<GPIO_Layout, kGPIO_size, kGPIO5_base> group;
}  // namespace GPIO5

namespace GPIO6 {
constexpr regs::RegGroup<GPIO_Layout, kGPIO_size, kGPIO6_base> group;
}  // namespace GPIO6

namespace GPIO7 {
constexpr regs::RegGroup<GPIO_Layout, kGPIO_size, kGPIO7_base> group;
}  // namespace GPIO7

namespace GPIO8 {
constexpr regs::RegGroup<GPIO_Layout, kGPIO_size, kGPIO8_base> group;
}  // namespace GPIO8

namespace GPIO9 {
constexpr regs::RegGroup<GPIO_Layout, kGPIO_size, kGPIO9_base> group;
}  // namespace GPIO9

namespace GPIO {

// ICR1 values
namespace ICR1 {
constexpr regs::RegValue32<2, 30> ICR15;
constexpr regs::RegValue32<2, 28> ICR14;
constexpr regs::RegValue32<2, 26> ICR13;
constexpr regs::RegValue32<2, 24> ICR12;
constexpr regs::RegValue32<2, 22> ICR11;
constexpr regs::RegValue32<2, 20> ICR10;
constexpr regs::RegValue32<2, 18> ICR9;
constexpr regs::RegValue32<2, 16> ICR8;
constexpr regs::RegValue32<2, 14> ICR7;
constexpr regs::RegValue32<2, 12> ICR6;
constexpr regs::RegValue32<2, 10> ICR5;
constexpr regs::RegValue32<2,  8> ICR4;
constexpr regs::RegValue32<2,  6> ICR3;
constexpr regs::RegValue32<2,  4> ICR2;
constexpr regs::RegValue32<2,  2> ICR1;
constexpr regs::RegValue32<2,  0> ICR0;
}  // namespace ICR1

// ICR2 values
namespace ICR2 {
constexpr regs::RegValue32<2, 30> ICR31;
constexpr regs::RegValue32<2, 28> ICR30;
constexpr regs::RegValue32<2, 26> ICR29;
constexpr regs::RegValue32<2, 24> ICR28;
constexpr regs::RegValue32<2, 22> ICR27;
constexpr regs::RegValue32<2, 20> ICR26;
constexpr regs::RegValue32<2, 18> ICR25;
constexpr regs::RegValue32<2, 16> ICR24;
constexpr regs::RegValue32<2, 14> ICR23;
constexpr regs::RegValue32<2, 12> ICR22;
constexpr regs::RegValue32<2, 10> ICR21;
constexpr regs::RegValue32<2,  8> ICR20;
constexpr regs::RegValue32<2,  6> ICR19;
constexpr regs::RegValue32<2,  4> ICR18;
constexpr regs::RegValue32<2,  2> ICR17;
constexpr regs::RegValue32<2,  0> ICR16;
}  // namespace ICR2

// Individual bits
constexpr regs::RegValue32<1, 31> BIT_31;
constexpr regs::RegValue32<1, 30> BIT_30;
constexpr regs::RegValue32<1, 29> BIT_29;
constexpr regs::RegValue32<1, 28> BIT_28;
constexpr regs::RegValue32<1, 27> BIT_27;
constexpr regs::RegValue32<1, 26> BIT_26;
constexpr regs::RegValue32<1, 25> BIT_25;
constexpr regs::RegValue32<1, 24> BIT_24;
constexpr regs::RegValue32<1, 23> BIT_23;
constexpr regs::RegValue32<1, 22> BIT_22;
constexpr regs::RegValue32<1, 21> BIT_21;
constexpr regs::RegValue32<1, 20> BIT_20;
constexpr regs::RegValue32<1, 19> BIT_19;
constexpr regs::RegValue32<1, 18> BIT_18;
constexpr regs::RegValue32<1, 17> BIT_17;
constexpr regs::RegValue32<1, 16> BIT_16;
constexpr regs::RegValue32<1, 15> BIT_15;
constexpr regs::RegValue32<1, 14> BIT_14;
constexpr regs::RegValue32<1, 13> BIT_13;
constexpr regs::RegValue32<1, 12> BIT_12;
constexpr regs::RegValue32<1, 11> BIT_11;
constexpr regs::RegValue32<1, 10> BIT_10;
constexpr regs::RegValue32<1,  9> BIT_9;
constexpr regs::RegValue32<1,  8> BIT_8;
constexpr regs::RegValue32<1,  7> BIT_7;
constexpr regs::RegValue32<1,  6> BIT_6;
constexpr regs::RegValue32<1,  5> BIT_5;
constexpr regs::RegValue32<1,  4> BIT_4;
constexpr regs::RegValue32<1,  3> BIT_3;
constexpr regs::RegValue32<1,  2> BIT_2;
constexpr regs::RegValue32<1,  1> BIT_1;
constexpr regs::RegValue32<1,  0> BIT_0;

// Directions
namespace GDIR {
constexpr uint32_t kINPUT  = 0;
constexpr uint32_t kOUTPUT = 1;
}  // namespace GDIR

// ICR active condition values
namespace ICR {
constexpr uint32_t kLOW     = 0;
constexpr uint32_t kHIGH    = 1;
constexpr uint32_t kRISING  = 2;
constexpr uint32_t kFALLING = 3;
}  // namespace ICR

}  // namespace GPIO

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
