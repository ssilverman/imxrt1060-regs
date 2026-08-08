// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// ADC_ETC.h defines all the ADC_ETC registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <type_traits>

#include "qindesign/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Size of Registers Arrays
constexpr size_t kADC_ETC_TRIG_count = 8;

// Structure type to access the ADC External Trigger Control
// (ADC_ETC) registers.
//
// Comments are from BSD-3-licensed NXP SDK.
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
constexpr uintptr_t kADC_ETC_base = 0x403B'0000;

namespace ADC_ETC {

constexpr regs::RegGroup<ADC_ETC_Layout, kADC_ETC_size, kADC_ETC_base> group;

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using ADC_ETC_Reg = regs::Reg32<kADC_ETC_base, ADC_ETC_Layout, Member, 0, Bits,
                                Shift, AssignMask>;

template <size_t Index,
          typename = std::enable_if_t<(Index < kADC_ETC_TRIG_count)>>
constexpr uintptr_t TrigBase() {
  return kADC_ETC_base + offsetof(ADC_ETC_Layout, TRIG) +
         Index * sizeof(ADC_ETC_Layout::TRIG_Layout);
}

template <size_t Index, auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using TRIG_Reg = regs::Reg32<TrigBase<Index>(), ADC_ETC_Layout::TRIG_Layout,
                             Member, 0, Bits, Shift, AssignMask>;

// ADC_ETC Global Control Register
namespace CTRL {
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::CTRL, 1, 31> SOFTRST;             // Software synchronous reset, active high.
    // 0b0..ADC_ETC works normally.
    // 0b1..All registers inside ADC_ETC will be reset to the default value.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::CTRL, 1, 30> TSC_BYPASS;          // TSC Bypass
    // To use ADC2, this bit should be cleared.
    // 0b0..TSC not bypassed.
    // 0b1..TSC is bypassed to ADC2, that means TSC will control ADC2 directly.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::CTRL, 1, 29> DMA_MODE_SEL;        // Select the trigger type of the DMA_REQ.
    // 0b0..Trig DMA_REQ with latched signal, REQ will be cleared when ACK and source request cleared.
    // 0b1..Trig DMA_REQ with pulsed signal, REQ will be cleared by ACK only.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::CTRL, 8, 16> PRE_DIVIDER;         // Pre-divider for trig delay and interval
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::CTRL, 3, 13> EXT1_TRIG_PRIORITY;  // External TSC1 trigger priority, 7 is highest priority, while 0 is lowest.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::CTRL, 1, 12> EXT1_TRIG_ENABLE;    // TSC1 TRIG enable register.
    // 0b0..disable external TSC1 trigger.
    // 0b1..enable external TSC1 trigger.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::CTRL, 3,  9> EXT0_TRIG_PRIORITY;  // External TSC0 trigger priority, 7 is highest priority, while 0 is lowest.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::CTRL, 1,  8> EXT0_TRIG_ENABLE;    // TSC0 TRIG enable register.
    // 0b0..disable external TSC0 trigger.
    // 0b1..enable external TSC0 trigger.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::CTRL, 8,  0> TRIG_ENABLE;         // TRIG enable register.
    // 0b00000000..disable all 8 external XBAR triggers.
    // 0b00000001..enable external XBAR trigger0.
    // 0b00000010..enable external XBAR trigger1.
    // 0b00000011..enable external XBAR trigger0 and trigger1.
    // 0b11111111..enable all 8 external XBAR triggers.
}  // namespace CTRL

// ETC DONE0 and DONE1 IRQ State Register
namespace DONE0_1_IRQ {
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1, 23, 0x0> TRIG7_DONE1;  // TRIG7 done1 interrupt detection.
    // 0b0..No TRIG7_DONE1 interrupt detected
    // 0b1..TRIG7_DONE1 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1, 22, 0x0> TRIG6_DONE1;  // TRIG6 done1 interrupt detection.
    // 0b0..No TRIG6_DONE1 interrupt detected
    // 0b1..TRIG6_DONE1 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1, 21, 0x0> TRIG5_DONE1;  // TRIG5 done1 interrupt detection.
    // 0b0..No TRIG5_DONE1 interrupt detected
    // 0b1..TRIG5_DONE1 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1, 20, 0x0> TRIG4_DONE1;  // TRIG4 done1 interrupt detection.
    // 0b0..No TRIG4_DONE1 interrupt detected
    // 0b1..TRIG4_DONE1 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1, 19, 0x0> TRIG3_DONE1;  // TRIG3 done1 interrupt detection.
    // 0b0..No TRIG3_DONE1 interrupt detected
    // 0b1..TRIG3_DONE1 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1, 18, 0x0> TRIG2_DONE1;  // TRIG2 done1 interrupt detection.
    // 0b0..No TRIG2_DONE1 interrupt detected
    // 0b1..TRIG2_DONE1 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1, 17, 0x0> TRIG1_DONE1;  // TRIG1 done1 interrupt detection.
    // 0b0..No TRIG1_DONE1 interrupt detected
    // 0b1..TRIG1_DONE1 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1, 16, 0x0> TRIG0_DONE1;  // TRIG0 done1 interrupt detection.
    // 0b0..No TRIG0_DONE1 interrupt detected
    // 0b1..TRIG0_DONE1 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1,  7, 0x0> TRIG7_DONE0;  // TRIG7 done0 interrupt detection.
    // 0b0..No TRIG7_DONE0 interrupt detected
    // 0b1..TRIG7_DONE0 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1,  6, 0x0> TRIG6_DONE0;  // TRIG6 done0 interrupt detection.
    // 0b0..No TRIG6_DONE0 interrupt detected
    // 0b1..TRIG6_DONE0 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1,  5, 0x0> TRIG5_DONE0;  // TRIG5 done0 interrupt detection.
    // 0b0..No TRIG5_DONE0 interrupt detected
    // 0b1..TRIG5_DONE0 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1,  4, 0x0> TRIG4_DONE0;  // TRIG4 done0 interrupt detection.
    // 0b0..No TRIG4_DONE0 interrupt detected
    // 0b1..TRIG4_DONE0 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1,  3, 0x0> TRIG3_DONE0;  // TRIG3 done0 interrupt detection.
    // 0b0..No TRIG3_DONE0 interrupt detected
    // 0b1..TRIG3_DONE0 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1,  2, 0x0> TRIG2_DONE0;  // TRIG2 done0 interrupt detection.
    // 0b0..No TRIG2_DONE0 interrupt detected
    // 0b1..TRIG2_DONE0 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1,  1, 0x0> TRIG1_DONE0;  // TRIG1 done0 interrupt detection.
    // 0b0..No TRIG1_DONE0 interrupt detected
    // 0b1..TRIG1_DONE0 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE0_1_IRQ, 1,  0, 0x0> TRIG0_DONE0;  // TRIG0 done0 interrupt detection.
    // 0b0..No TRIG0_DONE0 interrupt detected
    // 0b1..TRIG0_DONE0 interrupt detected
}  // namespace DONE0_1_IRQ

// ETC DONE_2 and DONE_ERR IRQ State Register
namespace DONE2_3_ERR_IRQ {
constexpr uint32_t kW1C = 0x0000'00ff;

constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1, 23, regs::shiftedMask32<1, 23>() | kW1C> TRIG7_ERR;  // TRIG7 error interrupt detection.
    // 0b0..No TRIG7_ERR interrupt detected
    // 0b1..TRIG7_ERR interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1, 22, regs::shiftedMask32<1, 22>() | kW1C> TRIG6_ERR;  // TRIG6 error interrupt detection.
    // 0b0..No TRIG6_ERR interrupt detected
    // 0b1..TRIG6_ERR interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1, 21, regs::shiftedMask32<1, 21>() | kW1C> TRIG5_ERR;  // TRIG5 error interrupt detection.
    // 0b0..No TRIG5_ERR interrupt detected
    // 0b1..TRIG5_ERR interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1, 20, regs::shiftedMask32<1, 20>() | kW1C> TRIG4_ERR;  // TRIG4 error interrupt detection.
    // 0b0..No TRIG4_ERR interrupt detected
    // 0b1..TRIG4_ERR interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1, 19, regs::shiftedMask32<1, 19>() | kW1C> TRIG3_ERR;  // TRIG3 error interrupt detection.
    // 0b0..No TRIG3_ERR interrupt detected
    // 0b1..TRIG3_ERR interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1, 18, regs::shiftedMask32<1, 18>() | kW1C> TRIG2_ERR;  // TRIG2 error interrupt detection.
    // 0b0..No TRIG2_ERR interrupt detected
    // 0b1..TRIG2_ERR interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1, 17, regs::shiftedMask32<1, 17>() | kW1C> TRIG1_ERR;  // TRIG1 error interrupt detection.
    // 0b0..No TRIG1_ERR interrupt detected
    // 0b1..TRIG1_ERR interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1, 16, regs::shiftedMask32<1, 16>() | kW1C> TRIG0_ERR;  // TRIG0 error interrupt detection.
    // 0b0..No TRIG0_ERR interrupt detected
    // 0b1..TRIG0_ERR interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1,  7, kW1C> TRIG7_DONE2;                               // TRIG7 done2 interrupt detection.
    // 0b0..No TRIG7_DONE2 interrupt detected
    // 0b1..TRIG7_DONE2 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1,  6, kW1C> TRIG6_DONE2;                               // TRIG6 done2 interrupt detection.
    // 0b0..No TRIG6_DONE2 interrupt detected
    // 0b1..TRIG6_DONE2 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1,  5, kW1C> TRIG5_DONE2;                               // TRIG5 done2 interrupt detection.
    // 0b0..No TRIG5_DONE2 interrupt detected
    // 0b1..TRIG5_DONE2 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1,  4, kW1C> TRIG4_DONE2;                               // TRIG4 done2 interrupt detection.
    // 0b0..No TRIG4_DONE2 interrupt detected
    // 0b1..TRIG4_DONE2 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1,  3, kW1C> TRIG3_DONE2;                               // TRIG3 done2 interrupt detection.
    // 0b0..No TRIG3_DONE2 interrupt detected
    // 0b1..TRIG3_DONE2 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1,  2, kW1C> TRIG2_DONE2;                               // TRIG2 done2 interrupt detection.
    // 0b0..No TRIG2_DONE2 interrupt detected
    // 0b1..TRIG2_DONE2 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1,  1, kW1C> TRIG1_DONE2;                               // TRIG1 done2 interrupt detection.
    // 0b0..No TRIG1_DONE2 interrupt detected
    // 0b1..TRIG1_DONE2 interrupt detected
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DONE2_3_ERR_IRQ, 1,  0, kW1C> TRIG0_DONE2;                               // TRIG0 done2 interrupt detection.
    // 0b0..No TRIG0_DONE2 interrupt detected
    // 0b1..TRIG0_DONE2 interrupt detected
}  // namespace DONE2_3_ERR_IRQ

// ETC DMA control Register
namespace DMA_CTRL {
constexpr uint32_t kW1C = 0x00ff'0000;

constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1, 23, kW1C> TRIG7_REQ;                                   // Flag bit for DMA request
    // 0b0..TRIG7_REQ not detected.
    // 0b1..TRIG7_REQ detected.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1, 22, kW1C> TRIG6_REQ;                                   // Flag bit for DMA request
    // 0b0..TRIG6_REQ not detected.
    // 0b1..TRIG6_REQ detected.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1, 21, kW1C> TRIG5_REQ;                                   // Flag bit for DMA request
    // 0b0..TRIG5_REQ not detected.
    // 0b1..TRIG5_REQ detected.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1, 20, kW1C> TRIG4_REQ;                                   // Flag bit for DMA request
    // 0b0..TRIG4_REQ not detected.
    // 0b1..TRIG4_REQ detected.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1, 19, kW1C> TRIG3_REQ;                                   // Flag bit for DMA request
    // 0b0..TRIG3_REQ not detected.
    // 0b1..TRIG3_REQ detected.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1, 18, kW1C> TRIG2_REQ;                                   // Flag bit for DMA request
    // 0b0..TRIG2_REQ not detected.
    // 0b1..TRIG2_REQ detected.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1, 17, kW1C> TRIG1_REQ;                                   // Flag bit for DMA request
    // 0b0..TRIG1_REQ not detected.
    // 0b1..TRIG1_REQ detected.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1, 16, kW1C> TRIG0_REQ;                                   // Flag bit for DMA request
    // 0b0..TRIG0_REQ not detected.
    // 0b1..TRIG0_REQ detected.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1,  7, regs::shiftedMask32<1, 7>() | kW1C> TRIG7_ENABLE;  // Enable DMA request when TRIG7 done.
    // 0b0..TRIG7 DMA request disabled.
    // 0b1..TRIG7 DMA request enabled.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1,  6, regs::shiftedMask32<1, 6>() | kW1C> TRIG6_ENABLE;  // Enable DMA request when TRIG6 done.
    // 0b0..TRIG6 DMA request disabled.
    // 0b1..TRIG6 DMA request enabled.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1,  5, regs::shiftedMask32<1, 5>() | kW1C> TRIG5_ENABLE;  // Enable DMA request when TRIG5 done.
    // 0b0..TRIG5 DMA request disabled.
    // 0b1..TRIG5 DMA request enabled.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1,  4, regs::shiftedMask32<1, 4>() | kW1C> TRIG4_ENABLE;  // Enable DMA request when TRIG4 done.
    // 0b0..TRIG4 DMA request disabled.
    // 0b1..TRIG4 DMA request enabled.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1,  3, regs::shiftedMask32<1, 3>() | kW1C> TRIG3_ENABLE;  // Enable DMA request when TRIG3 done.
    // 0b0..TRIG3 DMA request disabled.
    // 0b1..TRIG3 DMA request enabled.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1,  2, regs::shiftedMask32<1, 2>() | kW1C> TRIG2_ENABLE;  // Enable DMA request when TRIG2 done.
    // 0b0..TRIG2 DMA request disabled.
    // 0b1..TRIG2 DMA request enabled.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1,  1, regs::shiftedMask32<1, 1>() | kW1C> TRIG1_ENABLE;  // Enable DMA request when TRIG1 done.
    // 0b0..TRIG1 DMA request disabled.
    // 0b1..TRIG1 DMA request enabled.
constexpr ADC_ETC_Reg<&ADC_ETC_Layout::DMA_CTRL, 1,  0, regs::shiftedMask32<1, 0>() | kW1C> TRIG0_ENABLE;  // Enable DMA request when TRIG0 done.
    // 0b0..TRIG0 DMA request disabled.
    // 0b1..TRIG0 DMA request enabled.
}  // namespace DMA_CTRL

}  // namespace ADC_ETC

namespace ADC_ETC {

namespace TRIG {

// ETC_TRIG Control Register
namespace CTRL {
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CTRL, 1, 16> SYNC_MODE;      // Trigger synchronization mode selection
    // 0b0..Synchronization mode disabled, TRIGa and TRIG(a+4) are triggered independently.
    // 0b1..Synchronization mode enabled, TRIGa and TRIG(a+4) are triggered by TRIGa source synchronously.
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CTRL, 3, 12> TRIG_PRIORITY;  // External trigger priority, 7 is highest priority, while 0 is lowest
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CTRL, 3,  8> TRIG_CHAIN;     // The number of segments inside the trigger chain of TRIGa.
    // 0b000..Trigger chain length is 1
    // 0b001..Trigger chain length is 2
    // 0b010..Trigger chain length is 3
    // 0b011..Trigger chain length is 4
    // 0b100..Trigger chain length is 5
    // 0b101..Trigger chain length is 6
    // 0b110..Trigger chain length is 7
    // 0b111..Trigger chain length is 8
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CTRL, 1,  4> TRIG_MODE;      // Trigger mode selection.
    // 0b0..Hardware trigger. The softerware trigger will be ignored.
    // 0b1..Software trigger. The hardware trigger will be ignored.
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CTRL, 1,  0> SW_TRIG;        // Software trigger.
    // This field is self-clearing.
    // 0b0..No software trigger event generated.
    // 0b1..Software trigger event generated.

namespace vals {
constexpr regs::RegValue32<1, 16> SYNC_MODE;
constexpr regs::RegValue32<3, 12> TRIG_PRIORITY;
constexpr regs::RegValue32<3,  8> TRIG_CHAIN;
constexpr regs::RegValue32<1,  4> TRIG_MODE;
constexpr regs::RegValue32<1,  0> SW_TRIG;
}  // namespace vals
}  // namespace CTRL

// ETC_TRIG Counter Register
namespace COUNTER {
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::COUNTER, 16, 16> SAMPLE_INTERVAL;  // TRIGGER sampling interval counter
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::COUNTER, 16,  0> INIT_DELAY;       // TRIGGER initial delay counter.
    // Initial_delay = (INIT_DELAY+1)*(PRE_DIVIDER+1)*ipg_clk

namespace vals {
constexpr regs::RegValue32<16, 16> SAMPLE_INTERVAL;
constexpr regs::RegValue32<16,  0> INIT_DELAY;
}  // namespace vals
}  // namespace COUNTER

// ETC_TRIG Chain 0/1 Register
namespace CHAIN_1_0 {
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_1_0, 2, 29> IE1;    // Segment 1 done interrupt selection
    // 0b00..No interrupt when finished
    // 0b01..Generate interrupt on Done0 when Segment 1 finish.
    // 0b10..Generate interrupt on Done1 when Segment 1 finish.
    // 0b11..Generate interrupt on Done2 when Segment 1 finish.
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_1_0, 1, 28> B2B1;   // Segment 1 B2B
    // 0b0..Disable B2B. Wait until delay value defined by TRIG1_COUNTER[SAMPLE_INTERVAL] is reached
    // 0b1..Enable B2B. When Segment 0 finished (ADC COCO) then automatically trigger next ADC conversion, no need to wait until interval delay reached.
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_1_0, 8, 20> HWTS1;  // Segment 1 HWTS ADC hardware trigger selection
    // 0b00000000..no trigger selected
    // 0b00000001..ADC TRIG0 selected
    // 0b00000010..ADC TRIG1 selected
    // 0b00000100..ADC TRIG2 selected
    // 0b00001000..ADC TRIG3 selected
    // 0b00010000..ADC TRIG4 selected
    // 0b00100000..ADC TRIG5 selected
    // 0b01000000..ADC TRIG6 selected
    // 0b10000000..ADC TRIG7 selected
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_1_0, 4, 16> CSEL1;  // ADC channel selection
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
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_1_0, 2, 13> IE0;    // Segment 0 done interrupt selection
    // 0b00..No interrupt when finished
    // 0b01..Generate interrupt on Done0 when segment 0 finish.
    // 0b10..Generate interrupt on Done1 when segment 0 finish.
    // 0b11..Generate interrupt on Done2 when segment 0 finish.
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_1_0, 1, 12> B2B0;   // Segment 0 B2B
    // 0b0..Disable B2B. Wait until delay value defined by TRIG0_COUNTER[SAMPLE_INTERVAL] is reached
    // 0b1..Enable B2B. When Segment 0 finished (ADC COCO) then automatically trigger next ADC conversion, no need to wait until interval delay reached.
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_1_0, 8,  4> HWTS0;  // Segment 0 HWTS ADC hardware trigger selection
    // 0b00000000..no trigger selected
    // 0b00000001..ADC TRIG0 selected
    // 0b00000010..ADC TRIG1 selected
    // 0b00000100..ADC TRIG2 selected
    // 0b00001000..ADC TRIG3 selected
    // 0b00010000..ADC TRIG4 selected
    // 0b00100000..ADC TRIG5 selected
    // 0b01000000..ADC TRIG6 selected
    // 0b10000000..ADC TRIG7 selected
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_1_0, 4,  0> CSEL0;  // ADC channel selection
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

namespace vals {
constexpr regs::RegValue32<2, 29> IE1;
constexpr regs::RegValue32<1, 28> B2B1;
constexpr regs::RegValue32<8, 20> HWTS1;
constexpr regs::RegValue32<4, 16> CSEL1;
constexpr regs::RegValue32<2, 13> IE0;
constexpr regs::RegValue32<1, 12> B2B0;
constexpr regs::RegValue32<8,  4> HWTS0;
constexpr regs::RegValue32<4,  0> CSEL0;
}  // namespace vals
}  // namespace CHAIN_1_0

// ETC_TRIG Chain 2/3 Register
namespace CHAIN_3_2 {
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_3_2, 2, 29> IE3;    // Segment 3 done interrupt selection
    // 0b00..No interrupt when finished
    // 0b01..Generate interrupt on Done0 when segment 3 finish.
    // 0b10..Generate interrupt on Done1 when segment 3 finish.
    // 0b11..Generate interrupt on Done2 when segment 3 finish.
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_3_2, 1, 28> B2B3;   // Segment 3 B2B
    // 0b0..Disable B2B. Wait until delay value defined by TRIG3_COUNTER[SAMPLE_INTERVAL] is reached
    // 0b1..Enable B2B. When Segment 0 finished (ADC COCO) then automatically trigger next ADC conversion, no need to wait until interval delay reached.
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_3_2, 8, 20> HWTS3;  // Segment 3 HWTS ADC hardware trigger selection
    // 0b00000000..no trigger selected
    // 0b00000001..ADC TRIG0 selected
    // 0b00000010..ADC TRIG1 selected
    // 0b00000100..ADC TRIG2 selected
    // 0b00001000..ADC TRIG3 selected
    // 0b00010000..ADC TRIG4 selected
    // 0b00100000..ADC TRIG5 selected
    // 0b01000000..ADC TRIG6 selected
    // 0b10000000..ADC TRIG7 selected
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_3_2, 4, 16> CSEL3;  // ADC channel selection
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
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_3_2, 2, 13> IE2;    // Segment 2 done interrupt selection
    // 0b00..No interrupt when finished
    // 0b01..Generate interrupt on Done0 when segment 2 finish.
    // 0b10..Generate interrupt on Done1 when segment 2 finish.
    // 0b11..Generate interrupt on Done2 when segment 2 finish.
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_3_2, 1, 12> B2B2;   // Segment 2 B2B
    // 0b0..Disable B2B. Wait until delay value defined by TRIG2_COUNTER[SAMPLE_INTERVAL] is reached
    // 0b1..Enable B2B. When Segment 0 finished (ADC COCO) then automatically trigger next ADC conversion, no need to wait until interval delay reached.
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_3_2, 8,  4> HWTS2;  // Segment 2 HWTS ADC hardware trigger selection
    // 0b00000000..no trigger selected
    // 0b00000001..ADC TRIG0 selected
    // 0b00000010..ADC TRIG1 selected
    // 0b00000100..ADC TRIG2 selected
    // 0b00001000..ADC TRIG3 selected
    // 0b00010000..ADC TRIG4 selected
    // 0b00100000..ADC TRIG5 selected
    // 0b01000000..ADC TRIG6 selected
    // 0b10000000..ADC TRIG7 selected
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_3_2, 4,  0> CSEL2;  // ADC channel selection
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

namespace vals {
constexpr regs::RegValue32<2, 29> IE3;
constexpr regs::RegValue32<1, 28> B2B3;
constexpr regs::RegValue32<8, 20> HWTS3;
constexpr regs::RegValue32<4, 16> CSEL3;
constexpr regs::RegValue32<2, 13> IE2;
constexpr regs::RegValue32<1, 12> B2B2;
constexpr regs::RegValue32<8,  4> HWTS2;
constexpr regs::RegValue32<4,  0> CSEL2;
}  // namespace vals
}  // namespace CHAIN_3_2

// ETC_TRIG Chain 4/5 Register
namespace CHAIN_5_4 {
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_5_4, 2, 29> IE5;    // Segment 5 done interrupt selection
    // 0b00..No interrupt when finished
    // 0b01..Generate interrupt on Done0 when segment 5 finish.
    // 0b10..Generate interrupt on Done1 when segment 5 finish.
    // 0b11..Generate interrupt on Done2 when segment 5 finish.
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_5_4, 1, 28> B2B5;   // Segment 5 B2B
    // 0b0..Disable B2B. Wait until delay value defined by TRIG5_COUNTER[SAMPLE_INTERVAL] is reached
    // 0b1..Enable B2B. When Segment 0 finished (ADC COCO) then automatically trigger next ADC conversion, no need to wait until interval delay reached.
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_5_4, 8, 20> HWTS5;  // Segment 5 HWTS ADC hardware trigger selection
    // 0b00000000..no trigger selected
    // 0b00000001..ADC TRIG0 selected
    // 0b00000010..ADC TRIG1 selected
    // 0b00000100..ADC TRIG2 selected
    // 0b00001000..ADC TRIG3 selected
    // 0b00010000..ADC TRIG4 selected
    // 0b00100000..ADC TRIG5 selected
    // 0b01000000..ADC TRIG6 selected
    // 0b10000000..ADC TRIG7 selected
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_5_4, 4, 16> CSEL5;  // ADC channel selection
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
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_5_4, 2, 13> IE4;    // Segment 4 done interrupt selection
    // 0b00..No interrupt when finished
    // 0b01..Generate interrupt on Done0 when segment 4 finish.
    // 0b10..Generate interrupt on Done1 when segment 4 finish.
    // 0b11..Generate interrupt on Done2 when segment 4 finish.
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_5_4, 1, 12> B2B4;   // Segment 4 B2B
    // 0b0..Disable B2B. Wait until delay value defined by TRIG4_COUNTER[SAMPLE_INTERVAL] is reached
    // 0b1..Enable B2B. When Segment 0 finished (ADC COCO) then automatically trigger next ADC conversion, no need to wait until interval delay reached.
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_5_4, 8,  4> HWTS4;  // Segment 4 HWTS ADC hardware trigger selection
    // 0b00000000..no trigger selected
    // 0b00000001..ADC TRIG0 selected
    // 0b00000010..ADC TRIG1 selected
    // 0b00000100..ADC TRIG2 selected
    // 0b00001000..ADC TRIG3 selected
    // 0b00010000..ADC TRIG4 selected
    // 0b00100000..ADC TRIG5 selected
    // 0b01000000..ADC TRIG6 selected
    // 0b10000000..ADC TRIG7 selected
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_5_4, 4,  0> CSEL4;  // ADC channel selection
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

namespace vals {
constexpr regs::RegValue32<2, 29> IE5;
constexpr regs::RegValue32<1, 28> B2B5;
constexpr regs::RegValue32<8, 20> HWTS5;
constexpr regs::RegValue32<4, 16> CSEL5;
constexpr regs::RegValue32<2, 13> IE4;
constexpr regs::RegValue32<1, 12> B2B4;
constexpr regs::RegValue32<8,  4> HWTS4;
constexpr regs::RegValue32<4,  0> CSEL4;
}  // namespace vals
}  // namespace CHAIN_5_4

// ETC_TRIG Chain 6/7 Register
namespace CHAIN_7_6 {
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_7_6, 2, 29> IE7;    // Segment 7 done interrupt selection
    // 0b00..No interrupt when finished
    // 0b01..Generate interrupt on Done0 when segment 7 finish.
    // 0b10..Generate interrupt on Done1 when segment 7 finish.
    // 0b11..Generate interrupt on Done2 when segment 7 finish.
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_7_6, 1, 28> B2B7;   // Segment 7 B2B
    // 0b0..Disable B2B. Wait until delay value defined by TRIG7_COUNTER[SAMPLE_INTERVAL] is reached
    // 0b1..Enable B2B. When Segment 0 finished (ADC COCO) then automatically trigger next ADC conversion, no need to wait until interval delay reached.
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_7_6, 8, 20> HWTS7;  // Segment 7 HWTS ADC hardware trigger selection
    // 0b00000000..no trigger selected
    // 0b00000001..ADC TRIG0 selected
    // 0b00000010..ADC TRIG1 selected
    // 0b00000100..ADC TRIG2 selected
    // 0b00001000..ADC TRIG3 selected
    // 0b00010000..ADC TRIG4 selected
    // 0b00100000..ADC TRIG5 selected
    // 0b01000000..ADC TRIG6 selected
    // 0b10000000..ADC TRIG7 selected
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_7_6, 4, 16> CSEL7;  // ADC channel selection
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
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_7_6, 2, 13> IE6;    // Segment 6 done interrupt selection
    // 0b00..No interrupt when finished
    // 0b01..Generate interrupt on Done0 when segment 6 finish.
    // 0b10..Generate interrupt on Done1 when segment 6 finish.
    // 0b11..Generate interrupt on Done2 when segment 6 finish.
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_7_6, 1, 12> B2B6;   // Segment 6 B2B
    // 0b0..Disable B2B. Wait until delay value defined by TRIG6_COUNTER[SAMPLE_INTERVAL] is reached
    // 0b1..Enable B2B. When Segment 0 finished (ADC COCO) then automatically trigger next ADC conversion, no need to wait until interval delay reached.
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_7_6, 8,  4> HWTS6;  // Segment 6 HWTS ADC hardware trigger selection
    // 0b00000000..no trigger selected
    // 0b00000001..ADC TRIG0 selected
    // 0b00000010..ADC TRIG1 selected
    // 0b00000100..ADC TRIG2 selected
    // 0b00001000..ADC TRIG3 selected
    // 0b00010000..ADC TRIG4 selected
    // 0b00100000..ADC TRIG5 selected
    // 0b01000000..ADC TRIG6 selected
    // 0b10000000..ADC TRIG7 selected
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::CHAIN_7_6, 4,  0> CSEL6;  // ADC channel selection
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

namespace vals {
constexpr regs::RegValue32<2, 29> IE7;
constexpr regs::RegValue32<1, 28> B2B7;
constexpr regs::RegValue32<8, 20> HWTS7;
constexpr regs::RegValue32<4, 16> CSEL7;
constexpr regs::RegValue32<2, 13> IE6;
constexpr regs::RegValue32<1, 12> B2B6;
constexpr regs::RegValue32<8,  4> HWTS6;
constexpr regs::RegValue32<4,  0> CSEL6;
}  // namespace vals
}  // namespace CHAIN_7_6

// ETC_TRIG Result Data 1/0 Register
namespace RESULT_1_0 {
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::RESULT_1_0, 12, 16> DATA1;  // Result DATA1
    // The sign bit from ADC result FIFO is ignored by ETC_TRIG result, so only 12-bit unsigned results is supported by ADC_ETC module
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::RESULT_1_0, 12,  0> DATA0;  // Result DATA0
    // The sign bit from ADC result FIFO is ignored by ETC_TRIG result, so only 12-bit unsigned results is supported by ADC_ETC module

namespace vals {
constexpr regs::RegValue32<12, 16> DATA1;
constexpr regs::RegValue32<12,  0> DATA0;
}  // namespace vals
}  // namespace RESULT_1_0

// ETC_TRIG Result Data 3/2 Register
namespace RESULT_3_2 {
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::RESULT_3_2, 12, 16> DATA3;  // Result DATA3
    // The sign bit from ADC result FIFO is ignored by ETC_TRIG result, so only 12-bit unsigned results is supported by ADC_ETC module
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::RESULT_3_2, 12,  0> DATA2;  // Result DATA2
    // The sign bit from ADC result FIFO is ignored by ETC_TRIG result, so only 12-bit unsigned results is supported by ADC_ETC module

namespace vals {
constexpr regs::RegValue32<12, 16> DATA3;
constexpr regs::RegValue32<12,  0> DATA2;
}  // namespace vals
}  // namespace RESULT_3_2

// ETC_TRIG Result Data 5/4 Register
namespace RESULT_5_4 {
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::RESULT_5_4, 12, 16> DATA5;  // Result DATA5
    // The sign bit from ADC result FIFO is ignored by ETC_TRIG result, so only 12-bit unsigned results is supported by ADC_ETC module
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::RESULT_5_4, 12,  0> DATA4;  // Result DATA4
    // The sign bit from ADC result FIFO is ignored by ETC_TRIG result, so only 12-bit unsigned results is supported by ADC_ETC module

namespace vals {
constexpr regs::RegValue32<12, 16> DATA5;
constexpr regs::RegValue32<12,  0> DATA4;
}  // namespace vals
}  // namespace RESULT_5_4

// ETC_TRIG Result Data 7/6 Register
namespace RESULT_7_6 {
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::RESULT_7_6, 12, 16> DATA7;  // Result DATA7
    // The sign bit from ADC result FIFO is ignored by ETC_TRIG result, so only 12-bit unsigned results is supported by ADC_ETC module
template <size_t Index>
constexpr TRIG_Reg<Index, &ADC_ETC_Layout::TRIG_Layout::RESULT_7_6, 12,  0> DATA6;  // Result DATA6
    // The sign bit from ADC result FIFO is ignored by ETC_TRIG result, so only 12-bit unsigned results is supported by ADC_ETC module

namespace vals {
constexpr regs::RegValue32<12, 16> DATA7;
constexpr regs::RegValue32<12,  0> DATA6;
}  // namespace vals
}  // namespace RESULT_7_6

}  // namespace TRIG

}  // namespace ADC_ETC

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
