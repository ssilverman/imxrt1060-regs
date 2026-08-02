// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// GPT.h defines all the GPT registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>
#include <type_traits>

#include "qindesign/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Size of Registers Arrays
constexpr size_t kGPT_OCR_count = 3;
constexpr size_t kGPT_ICR_count = 2;

// Structure type to access the General Purpose Timer (GPT) registers.
//
// Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_GPT.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct GPT_Layout {
  volatile uint32_t CR;                                /**< GPT Control Register, offset: 0x0 */
  volatile uint32_t PR;                                /**< GPT Prescaler Register, offset: 0x4 */
  volatile uint32_t SR;                                /**< GPT Status Register, offset: 0x8 */
  volatile uint32_t IR;                                /**< GPT Interrupt Register, offset: 0xC */
  volatile uint32_t OCR[kGPT_OCR_count];               /**< GPT Output Compare Register, array offset: 0x10, array step: 0x4 */
  const volatile uint32_t ICR[kGPT_ICR_count];         /**< GPT Input Capture Register, array offset: 0x1C, array step: 0x4 */
  const volatile uint32_t CNT;                         /**< GPT Counter Register, offset: 0x24 */
};

constexpr size_t    kGPT_size  = 0x28;
constexpr uintptr_t kGPT1_base = 0x401E'C000;
constexpr uintptr_t kGPT2_base = 0x401F'0000;

namespace GPT1 {
constexpr regs::RegGroup<GPT_Layout, kGPT_size, kGPT1_base> group;
}  // namespace GPT1

namespace GPT2 {
constexpr regs::RegGroup<GPT_Layout, kGPT_size, kGPT2_base> group;
}  // namespace GPT2

namespace GPT1 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using GPT1_Reg =
    regs::Reg32<kGPT1_base, GPT_Layout, Member, 0, Bits, Shift, AssignMask>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>(),
          typename = std::enable_if_t<(Index < kGPT_OCR_count)>>
using OCR_Reg = regs::Reg32<kGPT1_base, GPT_Layout, &GPT_Layout::OCR, Index,
                            Bits, Shift, AssignMask>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>(),
          typename = std::enable_if_t<(Index < kGPT_ICR_count)>>
using ICR_Reg = regs::Reg32<kGPT1_base, GPT_Layout, &GPT_Layout::ICR, Index,
                            Bits, Shift, AssignMask>;

// GPT1 Control Register
namespace CR {
constexpr GPT1_Reg<&GPT_Layout::CR, 1, 31> FO3;     // Force Output Compare for Channel 3
    // WORZ
    // 0b0..No effect
    // 0b1..Trigger the programmed response on the pin
constexpr GPT1_Reg<&GPT_Layout::CR, 1, 30> FO2;     // Force Output Compare for Channel 2
    // WORZ
    // 0b0..No effect
    // 0b1..Trigger the programmed response on the pin
constexpr GPT1_Reg<&GPT_Layout::CR, 1, 29> FO1;     // Force Output Compare for Channel 1
    // WORZ
    // 0b0..No effect
    // 0b1..Trigger the programmed response on the pin
constexpr GPT1_Reg<&GPT_Layout::CR, 3, 26> OM3;     // Output Compare Operating Mode for Channel 3
    // 0b000..Output disabled. No response on pin.
    // 0b001..Toggle output pin
    // 0b010..Clear output pin
    // 0b011..Set output pin
    // 0b1xx..Generate a low pulse that is one input clock cycle wide on the output pin. When OMn is first programmed
    //         as 1xx, the output pin is set to one immediately on the next input clock (if it was not one already).
    //         "Input clock" here refers to the clock selected by the CLKSRC field of this register.
constexpr GPT1_Reg<&GPT_Layout::CR, 3, 23> OM2;     // Output Compare Operating Mode for Channel 2
    // 0b000..Output disabled. No response on pin.
    // 0b001..Toggle output pin
    // 0b010..Clear output pin
    // 0b011..Set output pin
    // 0b1xx..Generate a low pulse that is one input clock cycle wide on the output pin. When OMn is first programmed
    //         as 1xx, the output pin is set to one immediately on the next input clock (if it was not one already).
    //         "Input clock" here refers to the clock selected by the CLKSRC field of this register.
constexpr GPT1_Reg<&GPT_Layout::CR, 3, 20> OM1;     // Output Compare Operating Mode for Channel 1
    // 0b000..Output disabled. No response on pin.
    // 0b001..Toggle output pin
    // 0b010..Clear output pin
    // 0b011..Set output pin
    // 0b1xx..Generate a low pulse that is one input clock cycle wide on the output pin. When OMn is first programmed
    //         as 1xx, the output pin is set to one immediately on the next input clock (if it was not one already).
    //         "Input clock" here refers to the clock selected by the CLKSRC field of this register.
constexpr GPT1_Reg<&GPT_Layout::CR, 2, 18> IM2;     // Input Capture Operating Mode for Channel 2
    // 0b00..Capture disabled
    // 0b01..Capture on rising edge only
    // 0b10..Capture on falling edge only
    // 0b11..Capture on both edges
constexpr GPT1_Reg<&GPT_Layout::CR, 2, 16> IM1;     // Input Capture Operating Mode for Channel 1
    // 0b00..Capture disabled
    // 0b01..Capture on rising edge only
    // 0b10..Capture on falling edge only
    // 0b11..Capture on both edges
constexpr GPT1_Reg<&GPT_Layout::CR, 1, 15> SWR;     // Software Reset
    // 0b0..GPT is not in software reset state
    // 0b1..GPT is in software reset state
constexpr GPT1_Reg<&GPT_Layout::CR, 1, 10> EN_24M;  // Enable Oscillator Clock Input
    // 0b0..Disable
    // 0b1..Enable
constexpr GPT1_Reg<&GPT_Layout::CR, 1,  9> FRR;     // Free-Run or Restart Mode
    // 0b0..Restart mode. After a compare event, the counter resets to 0x0000_0000 and resumes counting.
    // 0b1..Free-Run mode. After a compare event, the counter continues counting until 0xFFFF_FFFF and then rolls over
    //     to 0.
constexpr GPT1_Reg<&GPT_Layout::CR, 3,  6> CLKSRC;  // Clock Source Select
    // 0b000..No clock
    // 0b001..Peripheral Clock (ipg_clk)
    // 0b010..High Frequency Reference Clock (ipg_clk_highfreq)
    // 0b011..External Clock
    // 0b100..Low Frequency Reference Clock (ipg_clk_32k)
    // 0b101..Oscillator as Reference Clock (ipg_clk_24M)
constexpr GPT1_Reg<&GPT_Layout::CR, 1,  5> STOPEN;  // GPT Stop Mode Enable
    // 0b0..Disable in Stop mode
    // 0b1..Enable in Stop mode
constexpr GPT1_Reg<&GPT_Layout::CR, 1,  4> DOZEEN;  // GPT Doze Mode Enable
    // 0b0..Disable in Doze mode
    // 0b1..Enable in Doze mode
constexpr GPT1_Reg<&GPT_Layout::CR, 1,  3> WAITEN;  // GPT Wait Mode Enable
    // 0b0..Disable in Wait mode
    // 0b1..Enable in Wait mode
constexpr GPT1_Reg<&GPT_Layout::CR, 1,  2> DBGEN;   // GPT Debug Mode Enable
    // 0b0..Disable in Debug mode
    // 0b1..Enable in Debug mode
constexpr GPT1_Reg<&GPT_Layout::CR, 1,  1> ENMOD;   // GPT Enable Mode
    // 0b0..Restart counting from their frozen values after GPT is enabled (EN=1).
    // 0b1..Reset counting from 0 after GPT is enabled (EN=1).
constexpr GPT1_Reg<&GPT_Layout::CR, 1,  0> EN;      // GPT Enable
    // 0b0..Disable
    // 0b1..Enable
}  // namespace CR

// GPT1 Prescaler Register
namespace PR {
constexpr GPT1_Reg<&GPT_Layout::PR,  4, 12> PRESCALER24M;  // Prescaler divide value for the oscillator clock
    // 0b0000..Divide by 1
    // 0b0001..Divide by 2
    // 0b1111..Divide by 16
constexpr GPT1_Reg<&GPT_Layout::PR, 12,  0> PRESCALER;     // Prescaler divide value
    // 0b000000000000..Divide by 1
    // 0b000000000001..Divide by 2
    // 0b111111111111..Divide by 4096
}  // namespace PR

// GPT1 Status Register
namespace SR {
constexpr GPT1_Reg<&GPT_Layout::SR, 1, 5, 0x0> ROV;  // Rollover Flag
    // 0b0..Rollover has not occurred.
    // 0b1..Rollover has occurred.
constexpr GPT1_Reg<&GPT_Layout::SR, 1, 4, 0x0> IF2;  // Input Capture Flag for Channel 2
    // 0b0..Capture event has not occurred.
    // 0b1..Capture event has occurred.
constexpr GPT1_Reg<&GPT_Layout::SR, 1, 3, 0x0> IF1;  // Input Capture Flag for Channel 1
    // 0b0..Capture event has not occurred.
    // 0b1..Capture event has occurred.
constexpr GPT1_Reg<&GPT_Layout::SR, 1, 2, 0x0> OF3;  // Output Compare Flag for Channel 3
    // 0b0..Compare event has not occurred.
    // 0b1..Compare event has occurred.
constexpr GPT1_Reg<&GPT_Layout::SR, 1, 1, 0x0> OF2;  // Output Compare Flag for Channel 2
    // 0b0..Compare event has not occurred.
    // 0b1..Compare event has occurred.
constexpr GPT1_Reg<&GPT_Layout::SR, 1, 0, 0x0> OF1;  // Output Compare Flag for Channel 1
    // 0b0..Compare event has not occurred.
    // 0b1..Compare event has occurred.
}  // namespace SR

// GPT1 Interrupt Register
namespace IR {
constexpr GPT1_Reg<&GPT_Layout::IR, 1, 5> ROVIE;  // Rollover Interrupt Enable
    // 0b0..Disable
    // 0b1..Enable
constexpr GPT1_Reg<&GPT_Layout::IR, 1, 4> IF2IE;  // Input Capture Flag for Channel 2 Interrupt Enable
    // 0b0..Disable
    // 0b1..Enable
constexpr GPT1_Reg<&GPT_Layout::IR, 1, 3> IF1IE;  // Input Capture Flag for Channel 1 Interrupt Enable
    // 0b0..Disable
    // 0b1..Enable
constexpr GPT1_Reg<&GPT_Layout::IR, 1, 2> OF3IE;  // Output Compare Flag for Channel 3 Interrupt Enable
    // 0b0..Disable
    // 0b1..Enable
constexpr GPT1_Reg<&GPT_Layout::IR, 1, 1> OF2IE;  // Output Compare Flag for Channel 2 Interrupt Enable
    // 0b0..Disable
    // 0b1..Enable
constexpr GPT1_Reg<&GPT_Layout::IR, 1, 0> OF1IE;  // Output Compare Flag for Channel 1 Interrupt Enable
    // 0b0..Disable
    // 0b1..Enable
}  // namespace IR

// GPT1 Output Compare Register
namespace OCR {
template <size_t Index>
constexpr OCR_Reg<Index, 32, 0> COMP;  // Compare Value
}  // namespace OCR

// GPT1 Input Capture Register
namespace ICR {
template <size_t Index>
constexpr ICR_Reg<Index, 32, 0> CAPT;  // Capture Value
}  // namespace ICR

// GPT1 Counter Register
namespace CNT {
constexpr GPT1_Reg<regs::constify(&GPT_Layout::CNT), 32, 0> COUNT;  // Counter Value
}  // namespace CNT

}  // namespace GPT1

namespace GPT2 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using GPT2_Reg =
    regs::Reg32<kGPT2_base, GPT_Layout, Member, 0, Bits, Shift, AssignMask>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>(),
          typename = std::enable_if_t<(Index < kGPT_OCR_count)>>
using OCR_Reg = regs::Reg32<kGPT2_base, GPT_Layout, &GPT_Layout::OCR, Index,
                            Bits, Shift, AssignMask>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>(),
          typename = std::enable_if_t<(Index < kGPT_ICR_count)>>
using ICR_Reg = regs::Reg32<kGPT2_base, GPT_Layout, &GPT_Layout::ICR, Index,
                            Bits, Shift, AssignMask>;

// GPT2 Control Register
namespace CR {
constexpr GPT2_Reg<&GPT_Layout::CR, 1, 31> FO3;
constexpr GPT2_Reg<&GPT_Layout::CR, 1, 30> FO2;
constexpr GPT2_Reg<&GPT_Layout::CR, 1, 29> FO1;
constexpr GPT2_Reg<&GPT_Layout::CR, 3, 26> OM3;
constexpr GPT2_Reg<&GPT_Layout::CR, 3, 23> OM2;
constexpr GPT2_Reg<&GPT_Layout::CR, 3, 20> OM1;
constexpr GPT2_Reg<&GPT_Layout::CR, 2, 18> IM2;
constexpr GPT2_Reg<&GPT_Layout::CR, 2, 16> IM1;
constexpr GPT2_Reg<&GPT_Layout::CR, 1, 15> SWR;
constexpr GPT2_Reg<&GPT_Layout::CR, 1, 10> EN_24M;
constexpr GPT2_Reg<&GPT_Layout::CR, 1,  9> FRR;
constexpr GPT2_Reg<&GPT_Layout::CR, 3,  6> CLKSRC;
constexpr GPT2_Reg<&GPT_Layout::CR, 1,  5> STOPEN;
constexpr GPT2_Reg<&GPT_Layout::CR, 1,  4> DOZEEN;
constexpr GPT2_Reg<&GPT_Layout::CR, 1,  3> WAITEN;
constexpr GPT2_Reg<&GPT_Layout::CR, 1,  2> DBGEN;
constexpr GPT2_Reg<&GPT_Layout::CR, 1,  1> ENMOD;
constexpr GPT2_Reg<&GPT_Layout::CR, 1,  0> EN;
}  // namespace CR

// GPT2 Prescaler Register
namespace PR {
constexpr GPT2_Reg<&GPT_Layout::PR,  4, 12> PRESCALER24M;
constexpr GPT2_Reg<&GPT_Layout::PR, 12,  0> PRESCALER;
}  // namespace PR

// GPT2 Status Register
namespace SR {
constexpr GPT2_Reg<&GPT_Layout::SR, 1, 5, 0x0> ROV;
constexpr GPT2_Reg<&GPT_Layout::SR, 1, 4, 0x0> IF2;
constexpr GPT2_Reg<&GPT_Layout::SR, 1, 3, 0x0> IF1;
constexpr GPT2_Reg<&GPT_Layout::SR, 1, 2, 0x0> OF3;
constexpr GPT2_Reg<&GPT_Layout::SR, 1, 1, 0x0> OF2;
constexpr GPT2_Reg<&GPT_Layout::SR, 1, 0, 0x0> OF1;
}  // namespace SR

// GPT2 Interrupt Register
namespace IR {
constexpr GPT2_Reg<&GPT_Layout::IR, 1, 5> ROVIE;
constexpr GPT2_Reg<&GPT_Layout::IR, 1, 4> IF2IE;
constexpr GPT2_Reg<&GPT_Layout::IR, 1, 3> IF1IE;
constexpr GPT2_Reg<&GPT_Layout::IR, 1, 2> OF3IE;
constexpr GPT2_Reg<&GPT_Layout::IR, 1, 1> OF2IE;
constexpr GPT2_Reg<&GPT_Layout::IR, 1, 0> OF1IE;
}  // namespace IR

// GPT2 Output Compare Register
namespace OCR {
template <size_t Index>
constexpr OCR_Reg<Index, 32, 0> COMP;
}  // namespace OCR

// GPT2 Input Capture Register
namespace ICR {
template <size_t Index>
constexpr ICR_Reg<Index, 32, 0> CAPT;
}  // namespace ICR

// GPT2 Counter Register
namespace CNT {
constexpr GPT2_Reg<regs::constify(&GPT_Layout::CNT), 32, 0> COUNT;
}  // namespace CNT

}  // namespace GPT2

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
