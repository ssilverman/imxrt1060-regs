// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// XBARB.h defines all the XBARB registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// XBARB layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_XBARB.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct XBARB_Layout {
  volatile uint16_t SEL0;                              /**< Crossbar B Select Register 0, offset: 0x0 */
  volatile uint16_t SEL1;                              /**< Crossbar B Select Register 1, offset: 0x2 */
  volatile uint16_t SEL2;                              /**< Crossbar B Select Register 2, offset: 0x4 */
  volatile uint16_t SEL3;                              /**< Crossbar B Select Register 3, offset: 0x6 */
  volatile uint16_t SEL4;                              /**< Crossbar B Select Register 4, offset: 0x8 */
  volatile uint16_t SEL5;                              /**< Crossbar B Select Register 5, offset: 0xA */
  volatile uint16_t SEL6;                              /**< Crossbar B Select Register 6, offset: 0xC */
  volatile uint16_t SEL7;                              /**< Crossbar B Select Register 7, offset: 0xE */
};

constexpr size_t    kXBARB_size  = 0x10;
constexpr uintptr_t kXBARB2_base = 0x403C0000;
constexpr uintptr_t kXBARB3_base = 0x403C4000;

namespace XBARB2 {
constexpr regs::RegGroup<XBARB_Layout, kXBARB_size, kXBARB2_base> group;
}  // namespace XBARB2

namespace XBARB3 {
constexpr regs::RegGroup<XBARB_Layout, kXBARB_size, kXBARB3_base> group;
}  // namespace XBARB3

namespace XBARB2 {

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using XBARB2_Reg = regs::Reg16<kXBARB2_base, XBARB_Layout, Member, 0, Bits,
                               Shift, DirectAssign>;

// Crossbar B Select Register 0
namespace SEL0 {
constexpr XBARB2_Reg<&XBARB_Layout::SEL0, 6, 8> SEL1;
constexpr XBARB2_Reg<&XBARB_Layout::SEL0, 6, 0> SEL0;
}  // namespace SEL0

// Crossbar B Select Register 1
namespace SEL1 {
constexpr XBARB2_Reg<&XBARB_Layout::SEL1, 6, 8> SEL3;
constexpr XBARB2_Reg<&XBARB_Layout::SEL1, 6, 0> SEL2;
}  // namespace SEL1

// Crossbar B Select Register 2
namespace SEL2 {
constexpr XBARB2_Reg<&XBARB_Layout::SEL2, 6, 8> SEL5;
constexpr XBARB2_Reg<&XBARB_Layout::SEL2, 6, 0> SEL4;
}  // namespace SEL2

// Crossbar B Select Register 3
namespace SEL3 {
constexpr XBARB2_Reg<&XBARB_Layout::SEL3, 6, 8> SEL7;
constexpr XBARB2_Reg<&XBARB_Layout::SEL3, 6, 0> SEL6;
}  // namespace SEL3

// Crossbar B Select Register 4
namespace SEL4 {
constexpr XBARB2_Reg<&XBARB_Layout::SEL4, 6, 8> SEL9;
constexpr XBARB2_Reg<&XBARB_Layout::SEL4, 6, 0> SEL8;
}  // namespace SEL4

// Crossbar B Select Register 5
namespace SEL5 {
constexpr XBARB2_Reg<&XBARB_Layout::SEL5, 6, 8> SEL11;
constexpr XBARB2_Reg<&XBARB_Layout::SEL5, 6, 0> SEL10;
}  // namespace SEL5

// Crossbar B Select Register 6
namespace SEL6 {
constexpr XBARB2_Reg<&XBARB_Layout::SEL6, 6, 8> SEL13;
constexpr XBARB2_Reg<&XBARB_Layout::SEL6, 6, 0> SEL12;
}  // namespace SEL6

// Crossbar B Select Register 7
namespace SEL7 {
constexpr XBARB2_Reg<&XBARB_Layout::SEL7, 6, 8> SEL15;
constexpr XBARB2_Reg<&XBARB_Layout::SEL7, 6, 0> SEL14;
}  // namespace SEL7

namespace IN {
constexpr uint16_t kLOGIC_LOW               = 0;
constexpr uint16_t kLOGIC_HIGH              = 1;
//Reserved 2
//Reserved 3
//Reserved 4
//Reserved 5
constexpr uint16_t kACMP1_OUT               = 6;
constexpr uint16_t kACMP2_OUT               = 7;
constexpr uint16_t kACMP3_OUT               = 8;
constexpr uint16_t kACMP4_OUT               = 9;
//Reserved 10
//Reserved 11
constexpr uint16_t kQTIMER3_TIMER0          = 12;
constexpr uint16_t kQTIMER3_TIMER1          = 13;
constexpr uint16_t kQTIMER3_TIMER2          = 14;
constexpr uint16_t kQTIMER3_TIMER3          = 15;
constexpr uint16_t kQTIMER4_TIMER0          = 16;
constexpr uint16_t kQTIMER4_TIMER1          = 17;
constexpr uint16_t kQTIMER4_TIMER2          = 18;
constexpr uint16_t kQTIMER4_TIMER3          = 19;
constexpr uint16_t kFLEXPWM1_PWM1_OUT_TRIG0 = 20;
constexpr uint16_t kFLEXPWM1_PWM1_OUT_TRIG1 = 20;
constexpr uint16_t kFLEXPWM1_PWM2_OUT_TRIG0 = 21;
constexpr uint16_t kFLEXPWM1_PWM2_OUT_TRIG1 = 21;
constexpr uint16_t kFLEXPWM1_PWM3_OUT_TRIG0 = 22;
constexpr uint16_t kFLEXPWM1_PWM3_OUT_TRIG1 = 22;
constexpr uint16_t kFLEXPWM1_PWM4_OUT_TRIG0 = 23;
constexpr uint16_t kFLEXPWM1_PWM4_OUT_TRIG1 = 23;
constexpr uint16_t kFLEXPWM2_PWM1_OUT_TRIG0 = 24;
constexpr uint16_t kFLEXPWM2_PWM1_OUT_TRIG1 = 24;
constexpr uint16_t kFLEXPWM2_PWM2_OUT_TRIG0 = 25;
constexpr uint16_t kFLEXPWM2_PWM2_OUT_TRIG1 = 25;
constexpr uint16_t kFLEXPWM2_PWM3_OUT_TRIG0 = 26;
constexpr uint16_t kFLEXPWM2_PWM3_OUT_TRIG1 = 26;
constexpr uint16_t kFLEXPWM2_PWM4_OUT_TRIG0 = 27;
constexpr uint16_t kFLEXPWM2_PWM4_OUT_TRIG1 = 27;
constexpr uint16_t kFLEXPWM3_PWM1_OUT_TRIG0 = 28;
constexpr uint16_t kFLEXPWM3_PWM1_OUT_TRIG1 = 28;
constexpr uint16_t kFLEXPWM3_PWM2_OUT_TRIG0 = 29;
constexpr uint16_t kFLEXPWM3_PWM2_OUT_TRIG1 = 29;
constexpr uint16_t kFLEXPWM3_PWM3_OUT_TRIG0 = 30;
constexpr uint16_t kFLEXPWM3_PWM3_OUT_TRIG1 = 30;
constexpr uint16_t kFLEXPWM3_PWM4_OUT_TRIG0 = 31;
constexpr uint16_t kFLEXPWM3_PWM4_OUT_TRIG1 = 31;
constexpr uint16_t kFLEXPWM4_PWM1_OUT_TRIG0 = 32;
constexpr uint16_t kFLEXPWM4_PWM1_OUT_TRIG1 = 32;
constexpr uint16_t kFLEXPWM4_PWM2_OUT_TRIG0 = 33;
constexpr uint16_t kFLEXPWM4_PWM2_OUT_TRIG1 = 33;
constexpr uint16_t kFLEXPWM4_PWM3_OUT_TRIG0 = 34;
constexpr uint16_t kFLEXPWM4_PWM3_OUT_TRIG1 = 34;
constexpr uint16_t kFLEXPWM4_PWM4_OUT_TRIG0 = 35;
constexpr uint16_t kFLEXPWM4_PWM4_OUT_TRIG1 = 35;
constexpr uint16_t kPIT_TRIGGER0            = 36;
constexpr uint16_t kPIT_TRIGGER1            = 37;
constexpr uint16_t kADC_ETC0_COCO0          = 38;
constexpr uint16_t kADC_ETC0_COCO1          = 39;
constexpr uint16_t kADC_ETC0_COCO2          = 40;
constexpr uint16_t kADC_ETC0_COCO3          = 41;
constexpr uint16_t kADC_ETC1_COCO0          = 42;
constexpr uint16_t kADC_ETC1_COCO1          = 43;
constexpr uint16_t kADC_ETC1_COCO2          = 44;
constexpr uint16_t kADC_ETC1_COCO3          = 45;
constexpr uint16_t kENC1_POS_MATCH          = 46;
constexpr uint16_t kENC2_POS_MATCH          = 47;
constexpr uint16_t kENC3_POS_MATCH          = 48;
constexpr uint16_t kENC4_POS_MATCH          = 49;
constexpr uint16_t kDMA_DONE0               = 50;
constexpr uint16_t kDMA_DONE1               = 51;
constexpr uint16_t kDMA_DONE2               = 52;
constexpr uint16_t kDMA_DONE3               = 53;
constexpr uint16_t kDMA_DONE4               = 54;
constexpr uint16_t kDMA_DONE5               = 55;
constexpr uint16_t kDMA_DONE6               = 56;
constexpr uint16_t kDMA_DONE7               = 57;
}  // namespace IN

namespace OUT {
constexpr uint16_t kAOI1_IN00 = 0;
constexpr uint16_t kAOI1_IN01 = 1;
constexpr uint16_t kAOI1_IN02 = 2;
constexpr uint16_t kAOI1_IN03 = 3;
constexpr uint16_t kAOI1_IN04 = 4;
constexpr uint16_t kAOI1_IN05 = 5;
constexpr uint16_t kAOI1_IN06 = 6;
constexpr uint16_t kAOI1_IN07 = 7;
constexpr uint16_t kAOI1_IN08 = 8;
constexpr uint16_t kAOI1_IN09 = 9;
constexpr uint16_t kAOI1_IN10 = 10;
constexpr uint16_t kAOI1_IN11 = 11;
constexpr uint16_t kAOI1_IN12 = 12;
constexpr uint16_t kAOI1_IN13 = 13;
constexpr uint16_t kAOI1_IN14 = 14;
}  // namespace OUT

}  // namespace XBARB2

namespace XBARB3 {

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using XBARB3_Reg = regs::Reg16<kXBARB3_base, XBARB_Layout, Member, 0, Bits,
                               Shift, DirectAssign>;

// XBARB3 Crossbar B Select Register 0
namespace SEL0 {
constexpr XBARB3_Reg<&XBARB_Layout::SEL0, 6, 8> SEL1;
constexpr XBARB3_Reg<&XBARB_Layout::SEL0, 6, 0> SEL0;
}  // namespace SEL0

// XBARB3 Crossbar B Select Register 1
namespace SEL1 {
constexpr XBARB3_Reg<&XBARB_Layout::SEL1, 6, 8> SEL3;
constexpr XBARB3_Reg<&XBARB_Layout::SEL1, 6, 0> SEL2;
}  // namespace SEL1

// XBARB3 Crossbar B Select Register 2
namespace SEL2 {
constexpr XBARB3_Reg<&XBARB_Layout::SEL2, 6, 8> SEL5;
constexpr XBARB3_Reg<&XBARB_Layout::SEL2, 6, 0> SEL4;
}  // namespace SEL2

// XBARB3 Crossbar B Select Register 3
namespace SEL3 {
constexpr XBARB3_Reg<&XBARB_Layout::SEL3, 6, 8> SEL7;
constexpr XBARB3_Reg<&XBARB_Layout::SEL3, 6, 0> SEL6;
}  // namespace SEL3

// XBARB3 Crossbar B Select Register 4
namespace SEL4 {
constexpr XBARB3_Reg<&XBARB_Layout::SEL4, 6, 8> SEL9;
constexpr XBARB3_Reg<&XBARB_Layout::SEL4, 6, 0> SEL8;
}  // namespace SEL4

// XBARB3 Crossbar B Select Register 5
namespace SEL5 {
constexpr XBARB3_Reg<&XBARB_Layout::SEL5, 6, 8> SEL11;
constexpr XBARB3_Reg<&XBARB_Layout::SEL5, 6, 0> SEL10;
}  // namespace SEL5

// XBARB3 Crossbar B Select Register 6
namespace SEL6 {
constexpr XBARB3_Reg<&XBARB_Layout::SEL6, 6, 8> SEL13;
constexpr XBARB3_Reg<&XBARB_Layout::SEL6, 6, 0> SEL12;
}  // namespace SEL6

// XBARB3 Crossbar B Select Register 7
namespace SEL7 {
constexpr XBARB3_Reg<&XBARB_Layout::SEL7, 6, 8> SEL15;
constexpr XBARB3_Reg<&XBARB_Layout::SEL7, 6, 0> SEL14;
}  // namespace SEL7

namespace IN {
constexpr uint16_t kLOGIC_LOW               = 0;
constexpr uint16_t kLOGIC_HIGH              = 1;
//Reserved 2
//Reserved 3
//Reserved 4
//Reserved 5
constexpr uint16_t kACMP1_OUT               = 6;
constexpr uint16_t kACMP2_OUT               = 7;
constexpr uint16_t kACMP3_OUT               = 8;
constexpr uint16_t kACMP4_OUT               = 9;
//Reserved 10
//Reserved 11
constexpr uint16_t kQTIMER3_TIMER0          = 12;
constexpr uint16_t kQTIMER3_TIMER1          = 13;
constexpr uint16_t kQTIMER3_TIMER2          = 14;
constexpr uint16_t kQTIMER3_TIMER3          = 15;
constexpr uint16_t kQTIMER4_TIMER0          = 16;
constexpr uint16_t kQTIMER4_TIMER1          = 17;
constexpr uint16_t kQTIMER4_TIMER2          = 18;
constexpr uint16_t kQTIMER4_TIMER3          = 19;
constexpr uint16_t kFLEXPWM1_PWM1_OUT_TRIG0 = 20;
constexpr uint16_t kFLEXPWM1_PWM2_OUT_TRIG0 = 21;
constexpr uint16_t kFLEXPWM1_PWM3_OUT_TRIG0 = 22;
constexpr uint16_t kFLEXPWM1_PWM4_OUT_TRIG0 = 23;
constexpr uint16_t kFLEXPWM2_PWM1_OUT_TRIG0 = 24;
constexpr uint16_t kFLEXPWM2_PWM2_OUT_TRIG0 = 25;
constexpr uint16_t kFLEXPWM2_PWM3_OUT_TRIG0 = 26;
constexpr uint16_t kFLEXPWM2_PWM4_OUT_TRIG0 = 27;
constexpr uint16_t kFLEXPWM3_PWM1_OUT_TRIG0 = 28;
constexpr uint16_t kFLEXPWM3_PWM2_OUT_TRIG0 = 29;
constexpr uint16_t kFLEXPWM3_PWM3_OUT_TRIG0 = 30;
constexpr uint16_t kFLEXPWM3_PWM4_OUT_TRIG0 = 31;
constexpr uint16_t kFLEXPWM4_PWM1_OUT_TRIG0 = 32;
constexpr uint16_t kFLEXPWM4_PWM2_OUT_TRIG0 = 33;
constexpr uint16_t kFLEXPWM4_PWM3_OUT_TRIG0 = 34;
constexpr uint16_t kFLEXPWM4_PWM4_OUT_TRIG0 = 35;
constexpr uint16_t kPIT_TRIGGER0            = 36;
constexpr uint16_t kPIT_TRIGGER1            = 37;
constexpr uint16_t kADC_ETC0_COCO0          = 38;
constexpr uint16_t kADC_ETC0_COCO1          = 39;
constexpr uint16_t kADC_ETC0_COCO2          = 40;
constexpr uint16_t kADC_ETC0_COCO3          = 41;
constexpr uint16_t kADC_ETC1_COCO0          = 42;
constexpr uint16_t kADC_ETC1_COCO1          = 43;
constexpr uint16_t kADC_ETC1_COCO2          = 44;
constexpr uint16_t kADC_ETC1_COCO3          = 45;
constexpr uint16_t kENC1_POS_MATCH          = 46;
constexpr uint16_t kENC2_POS_MATCH          = 47;
constexpr uint16_t kENC3_POS_MATCH          = 48;
constexpr uint16_t kENC4_POS_MATCH          = 49;
constexpr uint16_t kDMA_DONE0               = 50;
constexpr uint16_t kDMA_DONE1               = 51;
constexpr uint16_t kDMA_DONE2               = 52;
constexpr uint16_t kDMA_DONE3               = 53;
constexpr uint16_t kDMA_DONE4               = 54;
constexpr uint16_t kDMA_DONE5               = 55;
constexpr uint16_t kDMA_DONE6               = 56;
constexpr uint16_t kDMA_DONE7               = 57;
}  // namespace IN

namespace OUT {
constexpr uint16_t kAOI2_IN00 = 0;
constexpr uint16_t kAOI2_IN01 = 1;
constexpr uint16_t kAOI2_IN02 = 2;
constexpr uint16_t kAOI2_IN03 = 3;
constexpr uint16_t kAOI2_IN04 = 4;
constexpr uint16_t kAOI2_IN05 = 5;
constexpr uint16_t kAOI2_IN06 = 6;
constexpr uint16_t kAOI2_IN07 = 7;
constexpr uint16_t kAOI2_IN08 = 8;
constexpr uint16_t kAOI2_IN09 = 9;
constexpr uint16_t kAOI2_IN10 = 10;
constexpr uint16_t kAOI2_IN11 = 11;
constexpr uint16_t kAOI2_IN12 = 12;
constexpr uint16_t kAOI2_IN13 = 13;
constexpr uint16_t kAOI2_IN14 = 14;
constexpr uint16_t kAOI2_IN15 = 15;
}  // namespace OUT

}  // namespace XBARB3

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
