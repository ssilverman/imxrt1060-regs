// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// ADC_ETC.h defines all the ADC_ETC registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

/** ADC_ETC - Size of Registers Arrays */
constexpr size_t kADC_ETC_TRIG_count = 8;

// ADC_ETC layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_ADC_ETC.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct ADC_ETC_Layout {
  volatile uint32_t CTRL;                              /**< ADC_ETC Global Control Register, offset: 0x0 */
  volatile uint32_t DONE0_1_IRQ;                       /**< ETC DONE0 and DONE1 IRQ State Register, offset: 0x4 */
  volatile uint32_t DONE2_3_ERR_IRQ;                   /**< ETC DONE_2 and DONE_ERR IRQ State Register, offset: 0x8 */
  volatile uint32_t DMA_CTRL;                          /**< ETC DMA control Register, offset: 0xC */
  struct TRIG_Layout {                                 /* offset: 0x10, array step: 0x28 */
    volatile uint32_t CTRL;                              /**< ETC_TRIG Control Register, array offset: 0x10, array step: 0x28 */
    volatile uint32_t COUNTER;                           /**< ETC_TRIG Counter Register, array offset: 0x14, array step: 0x28 */
    volatile uint32_t CHAIN_1_0;                         /**< ETC_TRIG Chain 0/1 Register, array offset: 0x18, array step: 0x28 */
    volatile uint32_t CHAIN_3_2;                         /**< ETC_TRIG Chain 2/3 Register, array offset: 0x1C, array step: 0x28 */
    volatile uint32_t CHAIN_5_4;                         /**< ETC_TRIG Chain 4/5 Register, array offset: 0x20, array step: 0x28 */
    volatile uint32_t CHAIN_7_6;                         /**< ETC_TRIG Chain 6/7 Register, array offset: 0x24, array step: 0x28 */
    const volatile uint32_t RESULT_1_0;                  /**< ETC_TRIG Result Data 1/0 Register, array offset: 0x28, array step: 0x28 */
    const volatile uint32_t RESULT_3_2;                  /**< ETC_TRIG Result Data 3/2 Register, array offset: 0x2C, array step: 0x28 */
    const volatile uint32_t RESULT_5_4;                  /**< ETC_TRIG Result Data 5/4 Register, array offset: 0x30, array step: 0x28 */
    const volatile uint32_t RESULT_7_6;                  /**< ETC_TRIG Result Data 7/6 Register, array offset: 0x34, array step: 0x28 */
  } TRIG[kADC_ETC_TRIG_count];
};

constexpr size_t    kADC_ETC_size = 0x150;
constexpr uintptr_t kADC_ETC_base = 0x403B0000;

constexpr uintptr_t TrigBase(const uintptr_t base, const size_t index) {
  return base + offsetof(ADC_ETC_Layout, TRIG) +
         index*sizeof(ADC_ETC_Layout::TRIG_Layout);
}

namespace ADC_ETC {
constexpr regs::RegGroup<ADC_ETC_Layout, kADC_ETC_size, kADC_ETC_base> group;
}  // namespace ADC_ETC

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using ADC_ETC_Reg =
    regs::Reg32<kADC_ETC_base, ADC_ETC_Layout, Member, 0, Bits, Shift, DirectAssign>;

template <size_t Bits, unsigned int Shift>
using ADC_ETC_TRIG_RegValue = regs::RegValue32<Bits, Shift>;

namespace ADC_ETC {

// ADC_ETC Global Control Register
namespace CTRL {
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::CTRL, 1, 31> SOFTRST;
    // 0b0..ADC_ETC works normally.
    // 0b1..All registers inside ADC_ETC will be reset to the default value.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::CTRL, 1, 30> TSC_BYPASS;
    // 0b0..TSC not bypassed.
    // 0b1..TSC is bypassed to ADC2, that means TSC will control ADC2 directly.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::CTRL, 1, 29> DMA_MODE_SEL;
    // 0b0..Trig DMA_REQ with latched signal, REQ will be cleared when ACK and source request cleared.
    // 0b1..Trig DMA_REQ with pulsed signal, REQ will be cleared by ACK only.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::CTRL, 8, 16> PRE_DIVIDER;
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::CTRL, 3, 13> EXT1_TRIG_PRIORITY;
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::CTRL, 1, 12> EXT1_TRIG_ENABLE;
    // 0b0..disable external TSC1 trigger.
    // 0b1..enable external TSC1 trigger.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::CTRL, 3,  9> EXT0_TRIG_PRIORITY;
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::CTRL, 1,  8> EXT0_TRIG_ENABLE;
    // 0b0..disable external TSC0 trigger.
    // 0b1..enable external TSC0 trigger.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::CTRL, 8,  0> TRIG_ENABLE;
    // 0b00000000..disable all 8 external XBAR triggers.
    // 0b00000001..enable external XBAR trigger0.
    // 0b00000010..enable external XBAR trigger1.
    // 0b00000011..enable external XBAR trigger0 and trigger1.
    // 0b11111111..enable all 8 external XBAR triggers.
}  // namespace CTRL

// ETC DONE0 and DONE1 IRQ State Register
namespace DONE0_1_IRQ {
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1, 23, true> TRIG7_DONE1;
    // 0b0..No TRIG7_DONE1 interrupt detected
    // 0b1..TRIG7_DONE1 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1, 22, true> TRIG6_DONE1;
    // 0b0..No TRIG6_DONE1 interrupt detected
    // 0b1..TRIG6_DONE1 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1, 21, true> TRIG5_DONE1;
    // 0b0..No TRIG5_DONE1 interrupt detected
    // 0b1..TRIG5_DONE1 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1, 20, true> TRIG4_DONE1;
    // 0b0..No TRIG4_DONE1 interrupt detected
    // 0b1..TRIG4_DONE1 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1, 19, true> TRIG3_DONE1;
    // 0b0..No TRIG3_DONE1 interrupt detected
    // 0b1..TRIG3_DONE1 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1, 18, true> TRIG2_DONE1;
    // 0b0..No TRIG2_DONE1 interrupt detected
    // 0b1..TRIG2_DONE1 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1, 17, true> TRIG1_DONE1;
    // 0b0..No TRIG1_DONE1 interrupt detected
    // 0b1..TRIG1_DONE1 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1, 16, true> TRIG0_DONE1;
    // 0b0..No TRIG0_DONE1 interrupt detected
    // 0b1..TRIG0_DONE1 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1,  7, true> TRIG7_DONE0;
    // 0b0..No TRIG7_DONE0 interrupt detected
    // 0b1..TRIG7_DONE0 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1,  6, true> TRIG6_DONE0;
    // 0b0..No TRIG6_DONE0 interrupt detected
    // 0b1..TRIG6_DONE0 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1,  5, true> TRIG5_DONE0;
    // 0b0..No TRIG5_DONE0 interrupt detected
    // 0b1..TRIG5_DONE0 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1,  4, true> TRIG4_DONE0;
    // 0b0..No TRIG4_DONE0 interrupt detected
    // 0b1..TRIG4_DONE0 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1,  3, true> TRIG3_DONE0;
    // 0b0..No TRIG3_DONE0 interrupt detected
    // 0b1..TRIG3_DONE0 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1,  2, true> TRIG2_DONE0;
    // 0b0..No TRIG2_DONE0 interrupt detected
    // 0b1..TRIG2_DONE0 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1,  1, true> TRIG1_DONE0;
    // 0b0..No TRIG1_DONE0 interrupt detected
    // 0b1..TRIG1_DONE0 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1,  0, true> TRIG0_DONE0;
    // 0b0..No TRIG0_DONE0 interrupt detected
    // 0b1..TRIG0_DONE0 interrupt detected
}  // namespace DONE0_1_IRQ

// ETC DONE_2 and DONE_ERR IRQ State Register
namespace DONE2_3_ERR_IRQ {
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1, 23> TRIG7_ERR;
    // 0b0..No TRIG7_ERR interrupt detected
    // 0b1..TRIG7_ERR interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1, 22> TRIG6_ERR;
    // 0b0..No TRIG6_ERR interrupt detected
    // 0b1..TRIG6_ERR interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1, 21> TRIG5_ERR;
    // 0b0..No TRIG5_ERR interrupt detected
    // 0b1..TRIG5_ERR interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1, 20> TRIG4_ERR;
    // 0b0..No TRIG4_ERR interrupt detected
    // 0b1..TRIG4_ERR interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1, 19> TRIG3_ERR;
    // 0b0..No TRIG3_ERR interrupt detected
    // 0b1..TRIG3_ERR interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1, 18> TRIG2_ERR;
    // 0b0..No TRIG2_ERR interrupt detected
    // 0b1..TRIG2_ERR interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1, 17> TRIG1_ERR;
    // 0b0..No TRIG1_ERR interrupt detected
    // 0b1..TRIG1_ERR interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1, 16> TRIG0_ERR;
    // 0b0..No TRIG0_ERR interrupt detected
    // 0b1..TRIG0_ERR interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1,  7, true> TRIG7_DONE2;
    // 0b0..No TRIG7_DONE2 interrupt detected
    // 0b1..TRIG7_DONE2 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1,  6, true> TRIG6_DONE2;
    // 0b0..No TRIG6_DONE2 interrupt detected
    // 0b1..TRIG6_DONE2 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1,  5, true> TRIG5_DONE2;
    // 0b0..No TRIG5_DONE2 interrupt detected
    // 0b1..TRIG5_DONE2 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1,  4, true> TRIG4_DONE2;
    // 0b0..No TRIG4_DONE2 interrupt detected
    // 0b1..TRIG4_DONE2 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1,  3, true> TRIG3_DONE2;
    // 0b0..No TRIG3_DONE2 interrupt detected
    // 0b1..TRIG3_DONE2 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1,  2, true> TRIG2_DONE2;
    // 0b0..No TRIG2_DONE2 interrupt detected
    // 0b1..TRIG2_DONE2 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1,  1, true> TRIG1_DONE2;
    // 0b0..No TRIG1_DONE2 interrupt detected
    // 0b1..TRIG1_DONE2 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1,  0, true> TRIG0_DONE2;
    // 0b0..No TRIG0_DONE2 interrupt detected
    // 0b1..TRIG0_DONE2 interrupt detected
}  // namespace DONE2_3_ERR_IRQ

// ETC DMA control Register
namespace DMA_CTRL {
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1, 23, true> TRIG7_REQ;
    // 0b0..TRIG7_REQ not detected.
    // 0b1..TRIG7_REQ detected.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1, 22, true> TRIG6_REQ;
    // 0b0..TRIG6_REQ not detected.
    // 0b1..TRIG6_REQ detected.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1, 21, true> TRIG5_REQ;
    // 0b0..TRIG5_REQ not detected.
    // 0b1..TRIG5_REQ detected.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1, 20, true> TRIG4_REQ;
    // 0b0..TRIG4_REQ not detected.
    // 0b1..TRIG4_REQ detected.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1, 19, true> TRIG3_REQ;
    // 0b0..TRIG3_REQ not detected.
    // 0b1..TRIG3_REQ detected.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1, 18, true> TRIG2_REQ;
    // 0b0..TRIG2_REQ not detected.
    // 0b1..TRIG2_REQ detected.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1, 17, true> TRIG1_REQ;
    // 0b0..TRIG1_REQ not detected.
    // 0b1..TRIG1_REQ detected.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1, 16, true> TRIG0_REQ;
    // 0b0..TRIG0_REQ not detected.
    // 0b1..TRIG0_REQ detected.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1,  7> TRIG7_ENABLE;
    // 0b0..TRIG7 DMA request disabled.
    // 0b1..TRIG7 DMA request enabled.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1,  6> TRIG6_ENABLE;
    // 0b0..TRIG6 DMA request disabled.
    // 0b1..TRIG6 DMA request enabled.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1,  5> TRIG5_ENABLE;
    // 0b0..TRIG5 DMA request disabled.
    // 0b1..TRIG5 DMA request enabled.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1,  4> TRIG4_ENABLE;
    // 0b0..TRIG4 DMA request disabled.
    // 0b1..TRIG4 DMA request enabled.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1,  3> TRIG3_ENABLE;
    // 0b0..TRIG3 DMA request disabled.
    // 0b1..TRIG3 DMA request enabled.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1,  2> TRIG2_ENABLE;
    // 0b0..TRIG2 DMA request disabled.
    // 0b1..TRIG2 DMA request enabled.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1,  1> TRIG1_ENABLE;
    // 0b0..TRIG1 DMA request disabled.
    // 0b1..TRIG1 DMA request enabled.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1,  0> TRIG0_ENABLE;
    // 0b0..TRIG0 DMA request disabled.
    // 0b1..TRIG0 DMA request enabled.
}  // namespace DMA_CTRL

}  // namespace ADC_ETC

namespace ADC_ETC {

namespace TRIG {

// ETC_TRIG Control Register
namespace CTRL {
constexpr ADC_ETC_TRIG_RegValue<1, 16> SYNC_MODE;
    // 0b0..Synchronization mode disabled, TRIGa and TRIG(a+4) are triggered independently.
    // 0b1..Synchronization mode enabled, TRIGa and TRIG(a+4) are triggered by TRIGa source synchronously.
constexpr ADC_ETC_TRIG_RegValue<3, 12> TRIG_PRIORITY;
constexpr ADC_ETC_TRIG_RegValue<3,  8> TRIG_CHAIN;
    // 0b000..Trigger chain length is 1
    // 0b001..Trigger chain length is 2
    // 0b010..Trigger chain length is 3
    // 0b011..Trigger chain length is 4
    // 0b100..Trigger chain length is 5
    // 0b101..Trigger chain length is 6
    // 0b110..Trigger chain length is 7
    // 0b111..Trigger chain length is 8
constexpr ADC_ETC_TRIG_RegValue<1,  4> TRIG_MODE;
    // 0b0..Hardware trigger. The softerware trigger will be ignored.
    // 0b1..Software trigger. The hardware trigger will be ignored.
constexpr ADC_ETC_TRIG_RegValue<1,  0> SW_TRIG;
    // 0b0..No software trigger event generated.
    // 0b1..Software trigger event generated.
}  // namespace CTRL

// ETC_TRIG Counter Register
namespace COUNTER {
constexpr ADC_ETC_TRIG_RegValue<16, 16> SAMPLE_INTERVAL;
constexpr ADC_ETC_TRIG_RegValue<16,  0> INIT_DELAY;
}  // namespace COUNTER

// ETC_TRIG Chain 0/1 Register
namespace CHAIN_1_0 {
constexpr ADC_ETC_TRIG_RegValue<2, 29> IE1;
    // 0b00..No interrupt when finished
    // 0b01..Generate interrupt on Done0 when Segment 1 finish.
    // 0b10..Generate interrupt on Done1 when Segment 1 finish.
    // 0b11..Generate interrupt on Done2 when Segment 1 finish.
constexpr ADC_ETC_TRIG_RegValue<1, 28> B2B1;
    // 0b0..Disable B2B. Wait until delay value defined by TRIG1_COUNTER[SAMPLE_INTERVAL] is reached
    // 0b1..Enable B2B. When Segment 0 finished (ADC COCO) then automatically trigger next ADC conversion, no need to wait until interval delay reached.
constexpr ADC_ETC_TRIG_RegValue<8, 20> HWTS1;
    // 0b00000000..no trigger selected
    // 0b00000001..ADC TRIG0 selected
    // 0b00000010..ADC TRIG1 selected
    // 0b00000100..ADC TRIG2 selected
    // 0b00001000..ADC TRIG3 selected
    // 0b00010000..ADC TRIG4 selected
    // 0b00100000..ADC TRIG5 selected
    // 0b01000000..ADC TRIG6 selected
    // 0b10000000..ADC TRIG7 selected
constexpr ADC_ETC_TRIG_RegValue<4, 16> CSEL1;
    // 0b0000..ADC Channel 0 selected
    // 0b0001..ADC Channel 1 selected.
    // 0b0010..ADC Channel 2 selected.
    // 0b0011..ADC Channel 3 selected.
    // 0b0100..ADC Channel 4 selected.
    // 0b0101..ADC Channel 5 selected.
    // 0b0110..ADC Channel 6 selected.
    // 0b0111..ADC Channel 7 selected.
    // 0b1000..ADC Channel 8 selected.
    // 0b1001..ADC Channel 9 selected.
    // 0b1010..ADC Channel 10 selected.
    // 0b1011..ADC Channel 11 selected.
    // 0b1100..ADC Channel 12 selected.
    // 0b1101..ADC Channel 13 selected.
    // 0b1110..ADC Channel 14 selected.
    // 0b1111..ADC Channel 15 selected.
constexpr ADC_ETC_TRIG_RegValue<2, 13> IE0;
    // 0b00..No interrupt when finished
    // 0b01..Generate interrupt on Done0 when segment 0 finish.
    // 0b10..Generate interrupt on Done1 when segment 0 finish.
    // 0b11..Generate interrupt on Done2 when segment 0 finish.
constexpr ADC_ETC_TRIG_RegValue<1, 12> B2B0;
    // 0b0..Disable B2B. Wait until delay value defined by TRIG0_COUNTER[SAMPLE_INTERVAL] is reached
    // 0b1..Enable B2B. When Segment 0 finished (ADC COCO) then automatically trigger next ADC conversion, no need to wait until interval delay reached.
constexpr ADC_ETC_TRIG_RegValue<8,  4> HWTS0;
    // 0b00000000..no trigger selected
    // 0b00000001..ADC TRIG0 selected
    // 0b00000010..ADC TRIG1 selected
    // 0b00000100..ADC TRIG2 selected
    // 0b00001000..ADC TRIG3 selected
    // 0b00010000..ADC TRIG4 selected
    // 0b00100000..ADC TRIG5 selected
    // 0b01000000..ADC TRIG6 selected
    // 0b10000000..ADC TRIG7 selected
constexpr ADC_ETC_TRIG_RegValue<4,  0> CSEL0;
    // 0b0000..ADC Channel 0 selected
    // 0b0001..ADC Channel 1 selected.
    // 0b0010..ADC Channel 2 selected.
    // 0b0011..ADC Channel 3 selected.
    // 0b0100..ADC Channel 4 selected.
    // 0b0101..ADC Channel 5 selected.
    // 0b0110..ADC Channel 6 selected.
    // 0b0111..ADC Channel 7 selected.
    // 0b1000..ADC Channel 8 selected.
    // 0b1001..ADC Channel 9 selected.
    // 0b1010..ADC Channel 10 selected.
    // 0b1011..ADC Channel 11 selected.
    // 0b1100..ADC Channel 12 selected.
    // 0b1101..ADC Channel 13 selected.
    // 0b1110..ADC Channel 14 selected.
    // 0b1111..ADC Channel 15 selected.
}  // namespace CHAIN_1_0

// ETC_TRIG Chain 2/3 Register
namespace CHAIN_3_2 {
constexpr ADC_ETC_TRIG_RegValue<2, 29> IE3;
    // 0b00..No interrupt when finished
    // 0b01..Generate interrupt on Done0 when segment 3 finish.
    // 0b10..Generate interrupt on Done1 when segment 3 finish.
    // 0b11..Generate interrupt on Done2 when segment 3 finish.
constexpr ADC_ETC_TRIG_RegValue<1, 28> B2B3;
    // 0b0..Disable B2B. Wait until delay value defined by TRIG3_COUNTER[SAMPLE_INTERVAL] is reached
    // 0b1..Enable B2B. When Segment 0 finished (ADC COCO) then automatically trigger next ADC conversion, no need to wait until interval delay reached.
constexpr ADC_ETC_TRIG_RegValue<8, 20> HWTS3;
    // 0b00000000..no trigger selected
    // 0b00000001..ADC TRIG0 selected
    // 0b00000010..ADC TRIG1 selected
    // 0b00000100..ADC TRIG2 selected
    // 0b00001000..ADC TRIG3 selected
    // 0b00010000..ADC TRIG4 selected
    // 0b00100000..ADC TRIG5 selected
    // 0b01000000..ADC TRIG6 selected
    // 0b10000000..ADC TRIG7 selected
constexpr ADC_ETC_TRIG_RegValue<4, 16> CSEL3;
    // 0b0000..ADC Channel 0 selected
    // 0b0001..ADC Channel 1 selected.
    // 0b0010..ADC Channel 2 selected.
    // 0b0011..ADC Channel 3 selected.
    // 0b0100..ADC Channel 4 selected.
    // 0b0101..ADC Channel 5 selected.
    // 0b0110..ADC Channel 6 selected.
    // 0b0111..ADC Channel 7 selected.
    // 0b1000..ADC Channel 8 selected.
    // 0b1001..ADC Channel 9 selected.
    // 0b1010..ADC Channel 10 selected.
    // 0b1011..ADC Channel 11 selected.
    // 0b1100..ADC Channel 12 selected.
    // 0b1101..ADC Channel 13 selected.
    // 0b1110..ADC Channel 14 selected.
    // 0b1111..ADC Channel 15 selected.
constexpr ADC_ETC_TRIG_RegValue<2, 13> IE2;
    // 0b00..No interrupt when finished
    // 0b01..Generate interrupt on Done0 when segment 2 finish.
    // 0b10..Generate interrupt on Done1 when segment 2 finish.
    // 0b11..Generate interrupt on Done2 when segment 2 finish.
constexpr ADC_ETC_TRIG_RegValue<1, 12> B2B2;
    // 0b0..Disable B2B. Wait until delay value defined by TRIG2_COUNTER[SAMPLE_INTERVAL] is reached
    // 0b1..Enable B2B. When Segment 0 finished (ADC COCO) then automatically trigger next ADC conversion, no need to wait until interval delay reached.
constexpr ADC_ETC_TRIG_RegValue<8,  4> HWTS2;
    // 0b00000000..no trigger selected
    // 0b00000001..ADC TRIG0 selected
    // 0b00000010..ADC TRIG1 selected
    // 0b00000100..ADC TRIG2 selected
    // 0b00001000..ADC TRIG3 selected
    // 0b00010000..ADC TRIG4 selected
    // 0b00100000..ADC TRIG5 selected
    // 0b01000000..ADC TRIG6 selected
    // 0b10000000..ADC TRIG7 selected
constexpr ADC_ETC_TRIG_RegValue<4,  0> CSEL2;
    // 0b0000..ADC Channel 0 selected
    // 0b0001..ADC Channel 1 selected.
    // 0b0010..ADC Channel 2 selected.
    // 0b0011..ADC Channel 3 selected.
    // 0b0100..ADC Channel 4 selected.
    // 0b0101..ADC Channel 5 selected.
    // 0b0110..ADC Channel 6 selected.
    // 0b0111..ADC Channel 7 selected.
    // 0b1000..ADC Channel 8 selected.
    // 0b1001..ADC Channel 9 selected.
    // 0b1010..ADC Channel 10 selected.
    // 0b1011..ADC Channel 11 selected.
    // 0b1100..ADC Channel 12 selected.
    // 0b1101..ADC Channel 13 selected.
    // 0b1110..ADC Channel 14 selected.
    // 0b1111..ADC Channel 15 selected.
}  // namespace CHAIN_3_2

// ETC_TRIG Chain 4/5 Register
namespace CHAIN_5_4 {
constexpr ADC_ETC_TRIG_RegValue<2, 29> IE5;
    // 0b00..No interrupt when finished
    // 0b01..Generate interrupt on Done0 when segment 5 finish.
    // 0b10..Generate interrupt on Done1 when segment 5 finish.
    // 0b11..Generate interrupt on Done2 when segment 5 finish.
constexpr ADC_ETC_TRIG_RegValue<1, 28> B2B5;
    // 0b0..Disable B2B. Wait until delay value defined by TRIG5_COUNTER[SAMPLE_INTERVAL] is reached
    // 0b1..Enable B2B. When Segment 0 finished (ADC COCO) then automatically trigger next ADC conversion, no need to wait until interval delay reached.
constexpr ADC_ETC_TRIG_RegValue<8, 20> HWTS5;
    // 0b00000000..no trigger selected
    // 0b00000001..ADC TRIG0 selected
    // 0b00000010..ADC TRIG1 selected
    // 0b00000100..ADC TRIG2 selected
    // 0b00001000..ADC TRIG3 selected
    // 0b00010000..ADC TRIG4 selected
    // 0b00100000..ADC TRIG5 selected
    // 0b01000000..ADC TRIG6 selected
    // 0b10000000..ADC TRIG7 selected
constexpr ADC_ETC_TRIG_RegValue<4, 16> CSEL5;
    // 0b0000..ADC Channel 0 selected
    // 0b0001..ADC Channel 1 selected.
    // 0b0010..ADC Channel 2 selected.
    // 0b0011..ADC Channel 3 selected.
    // 0b0100..ADC Channel 4 selected.
    // 0b0101..ADC Channel 5 selected.
    // 0b0110..ADC Channel 6 selected.
    // 0b0111..ADC Channel 7 selected.
    // 0b1000..ADC Channel 8 selected.
    // 0b1001..ADC Channel 9 selected.
    // 0b1010..ADC Channel 10 selected.
    // 0b1011..ADC Channel 11 selected.
    // 0b1100..ADC Channel 12 selected.
    // 0b1101..ADC Channel 13 selected.
    // 0b1110..ADC Channel 14 selected.
    // 0b1111..ADC Channel 15 selected.
constexpr ADC_ETC_TRIG_RegValue<2, 13> IE4;
    // 0b00..No interrupt when finished
    // 0b01..Generate interrupt on Done0 when segment 4 finish.
    // 0b10..Generate interrupt on Done1 when segment 4 finish.
    // 0b11..Generate interrupt on Done2 when segment 4 finish.
constexpr ADC_ETC_TRIG_RegValue<1, 12> B2B4;
    // 0b0..Disable B2B. Wait until delay value defined by TRIG4_COUNTER[SAMPLE_INTERVAL] is reached
    // 0b1..Enable B2B. When Segment 0 finished (ADC COCO) then automatically trigger next ADC conversion, no need to wait until interval delay reached.
constexpr ADC_ETC_TRIG_RegValue<8,  4> HWTS4;
    // 0b00000000..no trigger selected
    // 0b00000001..ADC TRIG0 selected
    // 0b00000010..ADC TRIG1 selected
    // 0b00000100..ADC TRIG2 selected
    // 0b00001000..ADC TRIG3 selected
    // 0b00010000..ADC TRIG4 selected
    // 0b00100000..ADC TRIG5 selected
    // 0b01000000..ADC TRIG6 selected
    // 0b10000000..ADC TRIG7 selected
constexpr ADC_ETC_TRIG_RegValue<4,  0> CSEL4;
    // 0b0000..ADC Channel 0 selected
    // 0b0001..ADC Channel 1 selected.
    // 0b0010..ADC Channel 2 selected.
    // 0b0011..ADC Channel 3 selected.
    // 0b0100..ADC Channel 4 selected.
    // 0b0101..ADC Channel 5 selected.
    // 0b0110..ADC Channel 6 selected.
    // 0b0111..ADC Channel 7 selected.
    // 0b1000..ADC Channel 8 selected.
    // 0b1001..ADC Channel 9 selected.
    // 0b1010..ADC Channel 10 selected.
    // 0b1011..ADC Channel 11 selected.
    // 0b1100..ADC Channel 12 selected.
    // 0b1101..ADC Channel 13 selected.
    // 0b1110..ADC Channel 14 selected.
    // 0b1111..ADC Channel 15 selected.
}  // namespace CHAIN_5_4

// ETC_TRIG Chain 6/7 Register
namespace CHAIN_7_6 {
constexpr ADC_ETC_TRIG_RegValue<2, 29> IE7;
    // 0b00..No interrupt when finished
    // 0b01..Generate interrupt on Done0 when segment 7 finish.
    // 0b10..Generate interrupt on Done1 when segment 7 finish.
    // 0b11..Generate interrupt on Done2 when segment 7 finish.
constexpr ADC_ETC_TRIG_RegValue<1, 28> B2B7;
    // 0b0..Disable B2B. Wait until delay value defined by TRIG7_COUNTER[SAMPLE_INTERVAL] is reached
    // 0b1..Enable B2B. When Segment 0 finished (ADC COCO) then automatically trigger next ADC conversion, no need to wait until interval delay reached.
constexpr ADC_ETC_TRIG_RegValue<8, 20> HWTS7;
    // 0b00000000..no trigger selected
    // 0b00000001..ADC TRIG0 selected
    // 0b00000010..ADC TRIG1 selected
    // 0b00000100..ADC TRIG2 selected
    // 0b00001000..ADC TRIG3 selected
    // 0b00010000..ADC TRIG4 selected
    // 0b00100000..ADC TRIG5 selected
    // 0b01000000..ADC TRIG6 selected
    // 0b10000000..ADC TRIG7 selected
constexpr ADC_ETC_TRIG_RegValue<4, 16> CSEL7;
    // 0b0000..ADC Channel 0 selected.
    // 0b0001..ADC Channel 1 selected.
    // 0b0010..ADC Channel 2 selected.
    // 0b0011..ADC Channel 3 selected.
    // 0b0100..ADC Channel 4 selected.
    // 0b0101..ADC Channel 5 selected.
    // 0b0110..ADC Channel 6 selected.
    // 0b0111..ADC Channel 7 selected.
    // 0b1000..ADC Channel 8 selected.
    // 0b1001..ADC Channel 9 selected.
    // 0b1010..ADC Channel 10 selected.
    // 0b1011..ADC Channel 11 selected.
    // 0b1100..ADC Channel 12 selected.
    // 0b1101..ADC Channel 13 selected.
    // 0b1110..ADC Channel 14 selected.
    // 0b1111..ADC Channel 15 selected.
constexpr ADC_ETC_TRIG_RegValue<2, 13> IE6;
    // 0b00..No interrupt when finished
    // 0b01..Generate interrupt on Done0 when segment 6 finish.
    // 0b10..Generate interrupt on Done1 when segment 6 finish.
    // 0b11..Generate interrupt on Done2 when segment 6 finish.
constexpr ADC_ETC_TRIG_RegValue<1, 12> B2B6;
    // 0b0..Disable B2B. Wait until delay value defined by TRIG6_COUNTER[SAMPLE_INTERVAL] is reached
    // 0b1..Enable B2B. When Segment 0 finished (ADC COCO) then automatically trigger next ADC conversion, no need to wait until interval delay reached.
constexpr ADC_ETC_TRIG_RegValue<8,  4> HWTS6;
    // 0b00000000..no trigger selected
    // 0b00000001..ADC TRIG0 selected
    // 0b00000010..ADC TRIG1 selected
    // 0b00000100..ADC TRIG2 selected
    // 0b00001000..ADC TRIG3 selected
    // 0b00010000..ADC TRIG4 selected
    // 0b00100000..ADC TRIG5 selected
    // 0b01000000..ADC TRIG6 selected
    // 0b10000000..ADC TRIG7 selected
constexpr ADC_ETC_TRIG_RegValue<4,  0> CSEL6;
    // 0b0000..ADC Channel 0 selected
    // 0b0001..ADC Channel 1 selected.
    // 0b0010..ADC Channel 2 selected.
    // 0b0011..ADC Channel 3 selected.
    // 0b0100..ADC Channel 4 selected.
    // 0b0101..ADC Channel 5 selected.
    // 0b0110..ADC Channel 6 selected.
    // 0b0111..ADC Channel 7 selected.
    // 0b1000..ADC Channel 8 selected.
    // 0b1001..ADC Channel 9 selected.
    // 0b1010..ADC Channel 10 selected.
    // 0b1011..ADC Channel 11 selected.
    // 0b1100..ADC Channel 12 selected.
    // 0b1101..ADC Channel 13 selected.
    // 0b1110..ADC Channel 14 selected.
    // 0b1111..ADC Channel 15 selected.
}  // namespace CHAIN_7_6

// ETC_TRIG Result Data 1/0 Register
namespace RESULT_1_0 {
constexpr ADC_ETC_TRIG_RegValue<12, 16> DATA1;
constexpr ADC_ETC_TRIG_RegValue<12,  0> DATA0;
}  // namespace RESULT_1_0

// ETC_TRIG Result Data 3/2 Register
namespace RESULT_3_2 {
constexpr ADC_ETC_TRIG_RegValue<12, 16> DATA3;
constexpr ADC_ETC_TRIG_RegValue<12,  0> DATA2;
}  // namespace RESULT_3_2

// ETC_TRIG Result Data 5/4 Register
namespace RESULT_5_4 {
constexpr ADC_ETC_TRIG_RegValue<12, 16> DATA5;
constexpr ADC_ETC_TRIG_RegValue<12,  0> DATA4;
}  // namespace RESULT_5_4

// ETC_TRIG Result Data 7/6 Register
namespace RESULT_7_6 {
constexpr ADC_ETC_TRIG_RegValue<12, 16> DATA7;
constexpr ADC_ETC_TRIG_RegValue<12,  0> DATA6;
}  // namespace RESULT_7_6

}  // namespace TRIG

}  // namespace ADC_ETC

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
