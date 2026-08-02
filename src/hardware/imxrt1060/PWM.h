// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// PWM.h defines all the PWM registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>
#include <type_traits>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Size of Registers Arrays
constexpr size_t kPWM_SM_DISMAP_count = 1;
constexpr size_t kPWM_SM_count        = 4;

// Structure type to access the Enhanced Flex Pulse Width Modulator
// (eFlexPWM) registers.
//
// Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_PWM.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct PWM_Layout {
  struct SM_Layout {                                /* offset: 0x0, array step: 0x60 */
    const volatile uint16_t CNT;                        /**< Counter Register, array offset: 0x0, array step: 0x60 */
    volatile uint16_t INIT;                             /**< Initial Count Register, array offset: 0x2, array step: 0x60 */
    volatile uint16_t CTRL2;                            /**< Control 2 Register, array offset: 0x4, array step: 0x60 */
    volatile uint16_t CTRL;                             /**< Control Register, array offset: 0x6, array step: 0x60 */
    uint16_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
    volatile uint16_t VAL0;                             /**< Value Register 0, array offset: 0xA, array step: 0x60 */
    volatile uint16_t FRACVAL1;                         /**< Fractional Value Register 1, array offset: 0xC, array step: 0x60 */
    volatile uint16_t VAL1;                             /**< Value Register 1, array offset: 0xE, array step: 0x60 */
    volatile uint16_t FRACVAL2;                         /**< Fractional Value Register 2, array offset: 0x10, array step: 0x60 */
    volatile uint16_t VAL2;                             /**< Value Register 2, array offset: 0x12, array step: 0x60 */
    volatile uint16_t FRACVAL3;                         /**< Fractional Value Register 3, array offset: 0x14, array step: 0x60 */
    volatile uint16_t VAL3;                             /**< Value Register 3, array offset: 0x16, array step: 0x60 */
    volatile uint16_t FRACVAL4;                         /**< Fractional Value Register 4, array offset: 0x18, array step: 0x60 */
    volatile uint16_t VAL4;                             /**< Value Register 4, array offset: 0x1A, array step: 0x60 */
    volatile uint16_t FRACVAL5;                         /**< Fractional Value Register 5, array offset: 0x1C, array step: 0x60 */
    volatile uint16_t VAL5;                             /**< Value Register 5, array offset: 0x1E, array step: 0x60 */
    volatile uint16_t FRCTRL;                           /**< Fractional Control Register, array offset: 0x20, array step: 0x60 */
    volatile uint16_t OCTRL;                            /**< Output Control Register, array offset: 0x22, array step: 0x60 */
    volatile uint16_t STS;                              /**< Status Register, array offset: 0x24, array step: 0x60 */
    volatile uint16_t INTEN;                            /**< Interrupt Enable Register, array offset: 0x26, array step: 0x60 */
    volatile uint16_t DMAEN;                            /**< DMA Enable Register, array offset: 0x28, array step: 0x60 */
    volatile uint16_t TCTRL;                            /**< Output Trigger Control Register, array offset: 0x2A, array step: 0x60 */
    volatile uint16_t DISMAP[kPWM_SM_DISMAP_count];     /**< Fault Disable Mapping Register 0, array offset: 0x2C, array step: index*0x60, index2*0x2 */
    uint16_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
    volatile uint16_t DTCNT0;                           /**< Deadtime Count Register 0, array offset: 0x30, array step: 0x60 */
    volatile uint16_t DTCNT1;                           /**< Deadtime Count Register 1, array offset: 0x32, array step: 0x60 */
    volatile uint16_t CAPTCTRLA;                        /**< Capture Control A Register, array offset: 0x34, array step: 0x60 */
    volatile uint16_t CAPTCOMPA;                        /**< Capture Compare A Register, array offset: 0x36, array step: 0x60 */
    volatile uint16_t CAPTCTRLB;                        /**< Capture Control B Register, array offset: 0x38, array step: 0x60 */
    volatile uint16_t CAPTCOMPB;                        /**< Capture Compare B Register, array offset: 0x3A, array step: 0x60 */
    volatile uint16_t CAPTCTRLX;                        /**< Capture Control X Register, array offset: 0x3C, array step: 0x60 */
    volatile uint16_t CAPTCOMPX;                        /**< Capture Compare X Register, array offset: 0x3E, array step: 0x60 */
    const volatile uint16_t CVAL0;                      /**< Capture Value 0 Register, array offset: 0x40, array step: 0x60 */
    const volatile uint16_t CVAL0CYC;                   /**< Capture Value 0 Cycle Register, array offset: 0x42, array step: 0x60 */
    const volatile uint16_t CVAL1;                      /**< Capture Value 1 Register, array offset: 0x44, array step: 0x60 */
    const volatile uint16_t CVAL1CYC;                   /**< Capture Value 1 Cycle Register, array offset: 0x46, array step: 0x60 */
    const volatile uint16_t CVAL2;                      /**< Capture Value 2 Register, array offset: 0x48, array step: 0x60 */
    const volatile uint16_t CVAL2CYC;                   /**< Capture Value 2 Cycle Register, array offset: 0x4A, array step: 0x60 */
    const volatile uint16_t CVAL3;                      /**< Capture Value 3 Register, array offset: 0x4C, array step: 0x60 */
    const volatile uint16_t CVAL3CYC;                   /**< Capture Value 3 Cycle Register, array offset: 0x4E, array step: 0x60 */
    const volatile uint16_t CVAL4;                      /**< Capture Value 4 Register, array offset: 0x50, array step: 0x60 */
    const volatile uint16_t CVAL4CYC;                   /**< Capture Value 4 Cycle Register, array offset: 0x52, array step: 0x60 */
    const volatile uint16_t CVAL5;                      /**< Capture Value 5 Register, array offset: 0x54, array step: 0x60 */
    const volatile uint16_t CVAL5CYC;                   /**< Capture Value 5 Cycle Register, array offset: 0x56, array step: 0x60 */
    uint16_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[4];
  } SM[kPWM_SM_count];
  volatile uint16_t OUTEN;                              /**< Output Enable Register, offset: 0x180 */
  volatile uint16_t MASK;                               /**< Mask Register, offset: 0x182 */
  volatile uint16_t SWCOUT;                             /**< Software Controlled Output Register, offset: 0x184 */
  volatile uint16_t DTSRCSEL;                           /**< PWM Source Select Register, offset: 0x186 */
  volatile uint16_t MCTRL;                              /**< Master Control Register, offset: 0x188 */
  volatile uint16_t MCTRL2;                             /**< Master Control 2 Register, offset: 0x18A */
  volatile uint16_t FCTRL;                              /**< Fault Control Register, offset: 0x18C */
  volatile uint16_t FSTS;                               /**< Fault Status Register, offset: 0x18E */
  volatile uint16_t FFILT;                              /**< Fault Filter Register, offset: 0x190 */
  volatile uint16_t FTST;                               /**< Fault Test Register, offset: 0x192 */
  volatile uint16_t FCTRL2;                             /**< Fault Control 2 Register, offset: 0x194 */
};

constexpr size_t    kPWM_size  = 0x196;
constexpr uintptr_t kPWM1_base = 0x403D'C000;
constexpr uintptr_t kPWM2_base = 0x403E'0000;
constexpr uintptr_t kPWM3_base = 0x403E'4000;
constexpr uintptr_t kPWM4_base = 0x403E'8000;

namespace PWM1 {
constexpr regs::RegGroup<PWM_Layout, kPWM_size, kPWM1_base> group;
}  // namespace PWM1

namespace PWM2 {
constexpr regs::RegGroup<PWM_Layout, kPWM_size, kPWM2_base> group;
}  // namespace PWM2

namespace PWM3 {
constexpr regs::RegGroup<PWM_Layout, kPWM_size, kPWM3_base> group;
}  // namespace PWM3

namespace PWM4 {
constexpr regs::RegGroup<PWM_Layout, kPWM_size, kPWM4_base> group;
}  // namespace PWM4

namespace PWM1 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask16<Bits, Shift>(),
          bool WriteOnly = false>
using PWM1_Reg = regs::Reg16<kPWM1_base, PWM_Layout, Member, 0, Bits, Shift,
                             AssignMask, 0, WriteOnly>;

template <size_t Index,
          typename = std::enable_if_t<(Index < kPWM_SM_count)>>
constexpr uintptr_t SMBase() {
  return kPWM1_base + offsetof(PWM_Layout, SM) +
         Index*sizeof(PWM_Layout::SM_Layout);
}

template <size_t Index, auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask16<Bits, Shift>(),
          bool WriteOnly = false>
using SM_Reg = regs::Reg16<SMBase<Index>(), PWM_Layout::SM_Layout, Member, 0,
                           Bits, Shift, AssignMask, 0, WriteOnly>;

namespace SM {

// Counter Register
namespace CNT {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CNT), 16, 0> CNT;  // Counter Register Bits
}  // namespace CNT

// Initial Count Register
namespace INIT {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INIT, 16, 0> INIT;  // Initial Count Register Bits
}  // namespace INIT

// Control 2 Register
namespace CTRL2 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1, 15> DBGEN;       // Debug Enable
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1, 14> WAITEN;      // Wait Enable
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1, 13> INDEP;       // Independent or Complementary Pair Operation
    // 0b0..PWM_A and PWM_B form a complementary PWM pair.
    // 0b1..PWM_A and PWM_B outputs are independent PWMs.
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1, 12> PWM23_INIT;  // PWM23 Initial Value
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1, 11> PWM45_INIT;  // PWM45 Initial Value
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1, 10> PWMX_INIT;   // PWM_X Initial Value
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 2,  8> INIT_SEL;    // Initialization Control Select
    // 0b00..Local sync (PWM_X) causes initialization.
    // 0b01..Master reload from submodule 0 causes initialization. This setting should not be used in submodule 0 as
    //     it will force the INIT signal to logic 0. The submodule counter will only reinitialize when a master
    //     reload occurs.
    // 0b10..Master sync from submodule 0 causes initialization. This setting should not be used in submodule 0 as
    //     it will force the INIT signal to logic 0.
    // 0b11..EXT_SYNC causes initialization.
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1,  7> FRCEN;       // FRCEN
    // 0b0..Initialization from a FORCE_OUT is disabled.
    // 0b1..Initialization from a FORCE_OUT is enabled.
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1,  6> FORCE;       // Force Initialization
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 3,  3> FORCE_SEL;   // This read/write bit determines the source of the FORCE OUTPUT signal for this submodule.
    // 0b000..The local force signal, CTRL2[FORCE], from this submodule is used to force updates.
    // 0b001..The master force signal from submodule 0 is used to force updates. This setting should not be used in
    //     submodule 0 as it will hold the FORCE OUTPUT signal to logic 0.
    // 0b010..The local reload signal from this submodule is used to force updates without regard to the state of
    //     LDOK.
    // 0b011..The master reload signal from submodule0 is used to force updates if LDOK is set. This setting should
    //     not be used in submodule0 as it will hold the FORCE OUTPUT signal to logic 0.
    // 0b100..The local sync signal from this submodule is used to force updates.
    // 0b101..The master sync signal from submodule0 is used to force updates. This setting should not be used in
    //     submodule0 as it will hold the FORCE OUTPUT signal to logic 0.
    // 0b110..The external force signal, EXT_FORCE, from outside the PWM module causes updates.
    // 0b111..The external sync signal, EXT_SYNC, from outside the PWM module causes updates.
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1,  2> RELOAD_SEL;  // Reload Source Select
    // 0b0..The local RELOAD signal is used to reload registers.
    // 0b1..The master RELOAD signal (from submodule 0) is used to reload registers. This setting should not be used
    //     in submodule 0 as it will force the RELOAD signal to logic 0.
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 2,  0> CLK_SEL;     // Clock Source Select
    // 0b00..The IPBus clock is used as the clock for the local prescaler and counter.
    // 0b01..EXT_CLK is used as the clock for the local prescaler and counter.
    // 0b10..Submodule 0's clock (AUX_CLK) is used as the source clock for the local prescaler and counter. This
    //     setting should not be used in submodule 0 as it will force the clock to logic 0.
    // 0b11..reserved
}  // namespace CTRL2

// Control Register
namespace CTRL {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 4, 12> LDFQ;                // Load Frequency
    // 0b0000..Every PWM opportunity
    // 0b0001..Every 2 PWM opportunities
    // 0b0010..Every 3 PWM opportunities
    // 0b0011..Every 4 PWM opportunities
    // 0b0100..Every 5 PWM opportunities
    // 0b0101..Every 6 PWM opportunities
    // 0b0110..Every 7 PWM opportunities
    // 0b0111..Every 8 PWM opportunities
    // 0b1000..Every 9 PWM opportunities
    // 0b1001..Every 10 PWM opportunities
    // 0b1010..Every 11 PWM opportunities
    // 0b1011..Every 12 PWM opportunities
    // 0b1100..Every 13 PWM opportunities
    // 0b1101..Every 14 PWM opportunities
    // 0b1110..Every 15 PWM opportunities
    // 0b1111..Every 16 PWM opportunities
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1, 11> HALF;                // Half Cycle Reload
    // 0b0..Half-cycle reloads disabled.
    // 0b1..Half-cycle reloads enabled.
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1, 10> FULL;                // Full Cycle Reload
    // 0b0..Full-cycle reloads disabled.
    // 0b1..Full-cycle reloads enabled.
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CTRL), 2,  8> DT;  // Deadtime
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1,  7> COMPMODE;            // Compare Mode
    // 0b0..The VAL* registers and the PWM counter are compared using an "equal to" method. This means that PWM
    //     edges are only produced when the counter is equal to one of the VAL* register values. This implies that a
    //     PWMA output that is high at the end of a period will maintain this state until a match with VAL3 clears
    //     the output in the following period.
    // 0b1..The VAL* registers and the PWM counter are compared using an "equal to or greater than" method. This
    //     means that PWM edges are produced when the counter is equal to or greater than one of the VAL* register
    //     values. This implies that a PWMA output that is high at the end of a period could go low at the start of
    //     the next period if the starting counter value is greater than (but not necessarily equal to) the new VAL3
    //     value.
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 3,  4> PRSC;                // Prescaler
    // 0b000..Prescaler 1
    // 0b001..Prescaler 2
    // 0b010..Prescaler 4
    // 0b011..Prescaler 8
    // 0b100..Prescaler 16
    // 0b101..Prescaler 32
    // 0b110..Prescaler 64
    // 0b111..Prescaler 128
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1,  3> SPLIT;               // Split the DBLPWM signal to PWMA and PWMB
    // 0b0..DBLPWM is not split. PWMA and PWMB each have double pulses.
    // 0b1..DBLPWM is split to PWMA and PWMB.
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1,  2> LDMOD;               // Load Mode Select
    // 0b0..Buffered registers of this submodule are loaded and take effect at the next PWM reload if MCTRL[LDOK] is
    //     set.
    // 0b1..Buffered registers of this submodule are loaded and take effect immediately upon MCTRL[LDOK] being set.
    //     In this case it is not necessary to set CTRL[FULL] or CTRL[HALF].
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1,  1> DBLX;                // PWMX Double Switching Enable
    // 0b0..PWMX double pulse disabled.
    // 0b1..PWMX double pulse enabled.
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1,  0> DBLEN;               // Double Switching Enable
    // 0b0..Double switching disabled.
    // 0b1..Double switching enabled.
}  // namespace CTRL

// Value Register 0
namespace VAL0 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::VAL0, 16, 0> VAL0;  // Value Register 0
}  // namespace VAL0

// Fractional Value Register 1
namespace FRACVAL1 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRACVAL1, 5, 11> FRACVAL1;  // Fractional Value 1 Register
}  // namespace FRACVAL1

// Value Register 1
namespace VAL1 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::VAL1, 16, 0> VAL1;  // Value Register 1
}  // namespace VAL1

// Fractional Value Register 2
namespace FRACVAL2 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRACVAL2, 5, 11> FRACVAL2;  // Fractional Value 2
}  // namespace FRACVAL2

// Value Register 2
namespace VAL2 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::VAL2, 16, 0> VAL2;  // Value Register 2
}  // namespace VAL2

// Fractional Value Register 3
namespace FRACVAL3 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRACVAL3, 5, 11> FRACVAL3;  // Fractional Value 3
}  // namespace FRACVAL3

// Value Register 3
namespace VAL3 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::VAL3, 16, 0> VAL3;  // Value Register 3
}  // namespace VAL3

// Fractional Value Register 4
namespace FRACVAL4 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRACVAL4, 5, 11> FRACVAL4;  // Fractional Value 4
}  // namespace FRACVAL4

// Value Register 4
namespace VAL4 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::VAL4, 16, 0> VAL4;  // Value Register 4
}  // namespace VAL4

// Fractional Value Register 5
namespace FRACVAL5 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRACVAL5, 5, 11> FRACVAL5;  // Fractional Value 5
}  // namespace FRACVAL5

// Value Register 5
namespace VAL5 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::VAL5, 16, 0> VAL5;  // Value Register 5
}  // namespace VAL5

// Fractional Control Register
namespace FRCTRL {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::FRCTRL), 1, 15> TEST;  // Test Status Bit
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRCTRL, 1,  8> FRAC_PU;               // Fractional Delay Circuit Power Up
    // 0b0..Turn off fractional delay logic.
    // 0b1..Power up fractional delay logic.
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRCTRL, 1,  4> FRAC45_EN;             // Fractional Cycle Placement Enable for PWM_B
    // 0b0..Disable fractional cycle placement for PWM_B.
    // 0b1..Enable fractional cycle placement for PWM_B.
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRCTRL, 1,  2> FRAC23_EN;             // Fractional Cycle Placement Enable for PWM_A
    // 0b0..Disable fractional cycle placement for PWM_A.
    // 0b1..Enable fractional cycle placement for PWM_A.
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRCTRL, 1,  1> FRAC1_EN;              // Fractional Cycle PWM Period Enable
    // 0b0..Disable fractional cycle length for the PWM period.
    // 0b1..Enable fractional cycle length for the PWM period.
}  // namespace FRCTRL

// Output Control Register
namespace OCTRL {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::OCTRL), 1, 15> PWMA_IN;  // PWM_A Input
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::OCTRL), 1, 14> PWMB_IN;  // PWM_B Input
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::OCTRL), 1, 13> PWMX_IN;  // PWM_X Input
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::OCTRL, 1, 10> POLA;                     // PWM_A Output Polarity
    // 0b0..PWM_A output not inverted. A high level on the PWM_A pin represents the "on" or "active" state.
    // 0b1..PWM_A output inverted. A low level on the PWM_A pin represents the "on" or "active" state.
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::OCTRL, 1,  9> POLB;                     // PWM_B Output Polarity
    // 0b0..PWM_B output not inverted. A high level on the PWM_B pin represents the "on" or "active" state.
    // 0b1..PWM_B output inverted. A low level on the PWM_B pin represents the "on" or "active" state.
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::OCTRL, 1,  8> POLX;                     // PWM_X Output Polarity
    // 0b0..PWM_X output not inverted. A high level on the PWM_X pin represents the "on" or "active" state.
    // 0b1..PWM_X output inverted. A low level on the PWM_X pin represents the "on" or "active" state.
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::OCTRL, 2,  4> PWMAFS;                   // PWM_A Fault State
    // 0b00..Output is forced to logic 0 state prior to consideration of output polarity control.
    // 0b01..Output is forced to logic 1 state prior to consideration of output polarity control.
    // 0b10, 0b11..Output is tristated.
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::OCTRL, 2,  2> PWMBFS;                   // PWM_B Fault State
    // 0b00..Output is forced to logic 0 state prior to consideration of output polarity control.
    // 0b01..Output is forced to logic 1 state prior to consideration of output polarity control.
    // 0b10, 0b11..Output is tristated.
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::OCTRL, 2,  0> PWMXFS;                   // PWM_X Fault State
    // 0b00..Output is forced to logic 0 state prior to consideration of output polarity control.
    // 0b01..Output is forced to logic 1 state prior to consideration of output polarity control.
    // 0b10, 0b11..Output is tristated.
}  // namespace OCTRL

// Status Register
namespace STS {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::STS), 1, 14> RUF;  // Registers Updated Flag
    // 0b0..No register update has occurred since last reload.
    // 0b1..At least one of the double buffered registers has been updated since the last reload.
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1, 13, 0x0> REF;             // Reload Error Flag
    // 0b0..No reload error occurred.
    // 0b1..Reload signal occurred with non-coherent data and MCTRL[LDOK] = 0.
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1, 12, 0x0> RF;              // Reload Flag
    // 0b0..No new reload cycle since last STS[RF] clearing
    // 0b1..New reload cycle since last STS[RF] clearing
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1, 11, 0x0> CFA1;            // Capture Flag A1
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1, 10, 0x0> CFA0;            // Capture Flag A0
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1,  9, 0x0> CFB1;            // Capture Flag B1
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1,  8, 0x0> CFB0;            // Capture Flag B0
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1,  7, 0x0> CFX1;            // Capture Flag X1
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1,  6, 0x0> CFX0;            // Capture Flag X0
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 6,  0, 0x0> CMPF;            // Compare Flags
    // 0b000000..No compare event has occurred for a particular VALx value.
    // 0b000001..A compare event has occurred for a particular VALx value.
}  // namespace STS

// Interrupt Enable Register
namespace INTEN {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1, 13> REIE;   // Reload Error Interrupt Enable
    // 0b0..STS[REF] CPU interrupt requests disabled
    // 0b1..STS[REF] CPU interrupt requests enabled
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1, 12> RIE;    // Reload Interrupt Enable
    // 0b0..STS[RF] CPU interrupt requests disabled
    // 0b1..STS[RF] CPU interrupt requests enabled
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1, 11> CA1IE;  // Capture A 1 Interrupt Enable
    // 0b0..Interrupt request disabled for STS[CFA1].
    // 0b1..Interrupt request enabled for STS[CFA1].
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1, 10> CA0IE;  // Capture A 0 Interrupt Enable
    // 0b0..Interrupt request disabled for STS[CFA0].
    // 0b1..Interrupt request enabled for STS[CFA0].
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1,  9> CB1IE;  // Capture B 1 Interrupt Enable
    // 0b0..Interrupt request disabled for STS[CFB1].
    // 0b1..Interrupt request enabled for STS[CFB1].
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1,  8> CB0IE;  // Capture B 0 Interrupt Enable
    // 0b0..Interrupt request disabled for STS[CFB0].
    // 0b1..Interrupt request enabled for STS[CFB0].
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1,  7> CX1IE;  // Capture X 1 Interrupt Enable
    // 0b0..Interrupt request disabled for STS[CFX1].
    // 0b1..Interrupt request enabled for STS[CFX1].
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1,  6> CX0IE;  // Capture X 0 Interrupt Enable
    // 0b0..Interrupt request disabled for STS[CFX0].
    // 0b1..Interrupt request enabled for STS[CFX0].
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 6,  0> CMPIE;  // Compare Interrupt Enables
    // 0b000000..The corresponding STS[CMPF] bit will not cause an interrupt request.
    // 0b000001..The corresponding STS[CMPF] bit will cause an interrupt request.
}  // namespace INTEN

// DMA Enable Register
namespace DMAEN {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 9> VALDE;   // Value Registers DMA Enable
    // 0b0..DMA write requests disabled
    // 0b1..Enabled
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 8> FAND;    // FIFO Watermark AND Control
    // 0b0..Selected FIFO watermarks are OR'ed together.
    // 0b1..Selected FIFO watermarks are AND'ed together.
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 2, 6> CAPTDE;  // Capture DMA Enable Source Select
    // 0b00..Read DMA requests disabled.
    // 0b01..Exceeding a FIFO watermark sets the DMA read request. This requires at least one of DMAEN[CA1DE],
    //     DMAEN[CA0DE], DMAEN[CB1DE], DMAEN[CB0DE], DMAEN[CX1DE], or DMAEN[CX0DE] to also be set in order to
    //     determine to which watermark(s) the DMA request is sensitive.
    // 0b10..A local sync (VAL1 matches counter) sets the read DMA request.
    // 0b11..A local reload (STS[RF] being set) sets the read DMA request.
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 5> CA1DE;   // Capture A1 FIFO DMA Enable
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 4> CA0DE;   // Capture A0 FIFO DMA Enable
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 3> CB1DE;   // Capture B1 FIFO DMA Enable
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 2> CB0DE;   // Capture B0 FIFO DMA Enable
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 1> CX1DE;   // Capture X1 FIFO DMA Enable
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 0> CX0DE;   // Capture X0 FIFO DMA Enable
}  // namespace DMAEN

// Output Trigger Control Register
namespace TCTRL {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::TCTRL, 1, 15> PWAOT0;       // Output Trigger 0 Source Select
    // 0b0..Route the PWM_OUT_TRIG0 signal to PWM_OUT_TRIG0 port.
    // 0b1..Route the PWMA output to the PWM_OUT_TRIG0 port.
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::TCTRL, 1, 14> PWBOT1;       // Output Trigger 1 Source Select
    // 0b0..Route the PWM_OUT_TRIG1 signal to PWM_OUT_TRIG1 port.
    // 0b1..Route the PWMB output to the PWM_OUT_TRIG1 port.
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::TCTRL, 1, 12> TRGFRQ;       // Trigger frequency
    // 0b0..Trigger outputs are generated during every PWM period even if the PWM is not reloaded every period due
    //     to CTRL[LDFQ] being non-zero.
    // 0b1..Trigger outputs are generated only during the final PWM period prior to a reload opportunity when the
    //     PWM is not reloaded every period due to CTRL[LDFQ] being non-zero.
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::TCTRL, 6,  0> OUT_TRIG_EN;  // Output Trigger Enables
    // 0b1xxxxx..PWM_OUT_TRIG1 will set when the counter value matches the VAL5 value.
    // 0bx1xxxx..PWM_OUT_TRIG0 will set when the counter value matches the VAL4 value.
    // 0bxx1xxx..PWM_OUT_TRIG1 will set when the counter value matches the VAL3 value.
    // 0bxxx1xx..PWM_OUT_TRIG0 will set when the counter value matches the VAL2 value.
    // 0bxxxx1x..PWM_OUT_TRIG1 will set when the counter value matches the VAL1 value.
    // 0bxxxxx1..PWM_OUT_TRIG0 will set when the counter value matches the VAL0 value.
}  // namespace TCTRL

// Fault Disable Mapping Register 0
namespace DISMAP {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DISMAP, 4, 8> DIS0X;  // PWM_X Fault Disable Mask 0
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DISMAP, 4, 4> DIS0B;  // PWM_B Fault Disable Mask 0
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DISMAP, 4, 0> DIS0A;  // PWM_A Fault Disable Mask 0
}  // namespace DISMAP

// Deadtime Count Register 0
namespace DTCNT0 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DTCNT0, 16, 0> DTCNT0;  // DTCNT0
}  // namespace DTCNT0

// Deadtime Count Register 1
namespace DTCNT1 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DTCNT1, 16, 0> DTCNT1;  // DTCNT1
}  // namespace DTCNT1

// Capture Control A Register
namespace CAPTCTRLA {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCTRLA), 3, 13> CA1CNT;  // Capture A1 FIFO Word Count
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCTRLA), 3, 10> CA0CNT;  // Capture A0 FIFO Word Count
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 2,  8> CFAWM;                   // Capture A FIFOs Water Mark
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 1,  7> EDGCNTA_EN;              // Edge Counter A Enable
    // 0b0..Edge counter disabled and held in reset
    // 0b1..Edge counter enabled
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 1,  6> INP_SELA;                // Input Select A
    // 0b0..Raw PWM_A input signal selected as source.
    // 0b1..Edge Counter
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 2,  4> EDGA1;                   // Edge A 1
    // 0b00..Disabled
    // 0b01..Capture falling edges
    // 0b10..Capture rising edges
    // 0b11..Capture any edge
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 2,  2> EDGA0;                   // Edge A 0
    // 0b00..Disabled
    // 0b01..Capture falling edges
    // 0b10..Capture rising edges
    // 0b11..Capture any edge
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 1,  1> ONESHOTA;                // One Shot Mode A
    // 0b0..Free Running
    // 0b1..One Shot
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 1,  0> ARMA;                    // Arm A
    // 0b0..Input capture operation is disabled.
    // 0b1..Input capture operation as specified by CAPTCTRLA[EDGAx] is enabled.
}  // namespace CAPTCTRLA

// Capture Compare A Register
namespace CAPTCOMPA {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCOMPA), 8, 8> EDGCNTA;  // Edge Counter A
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCOMPA, 8, 0> EDGCMPA;                  // Edge Compare A
}  // namespace CAPTCOMPA

// Capture Control B Register
namespace CAPTCTRLB {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCTRLB), 3, 13> CB1CNT;  // Capture B1 FIFO Word Count
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCTRLB), 3, 10> CB0CNT;  // Capture B0 FIFO Word Count
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 2,  8> CFBWM;                   // Capture B FIFOs Water Mark
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 1,  7> EDGCNTB_EN;              // Edge Counter B Enable
    // 0b0..Edge counter disabled and held in reset
    // 0b1..Edge counter enabled
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 1,  6> INP_SELB;                // Input Select B
    // 0b0..Raw PWM_B input signal selected as source.
    // 0b1..Edge Counter
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 2,  4> EDGB1;                   // Edge B 1
    // 0b00..Disabled
    // 0b01..Capture falling edges
    // 0b10..Capture rising edges
    // 0b11..Capture any edge
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 2,  2> EDGB0;                   // Edge B 0
    // 0b00..Disabled
    // 0b01..Capture falling edges
    // 0b10..Capture rising edges
    // 0b11..Capture any edge
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 1,  1> ONESHOTB;                // One Shot Mode B
    // 0b0..Free Running
    // 0b1..One Shot
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 1,  0> ARMB;                    // Arm B
    // 0b0..Input capture operation is disabled.
    // 0b1..Input capture operation as specified by CAPTCTRLB[EDGBx] is enabled.
}  // namespace CAPTCTRLB

// Capture Compare B Register
namespace CAPTCOMPB {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCOMPB), 8, 8> EDGCNTB;  // Edge Counter B
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCOMPB, 8, 0> EDGCMPB;                  // Edge Compare B
}  // namespace CAPTCOMPB

// Capture Control X Register
namespace CAPTCTRLX {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCTRLX), 3, 13> CX1CNT;  // Capture X1 FIFO Word Count
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCTRLX), 3, 10> CX0CNT;  // Capture X0 FIFO Word Count
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 2,  8> CFXWM;                   // Capture X FIFOs Water Mark
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 1,  7> EDGCNTX_EN;              // Edge Counter X Enable
    // 0b0..Edge counter disabled and held in reset
    // 0b1..Edge counter enabled
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 1,  6> INP_SELX;                // Input Select X
    // 0b0..Raw PWM_X input signal selected as source.
    // 0b1..Edge Counter
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 2,  4> EDGX1;                   // Edge X 1
    // 0b00..Disabled
    // 0b01..Capture falling edges
    // 0b10..Capture rising edges
    // 0b11..Capture any edge
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 2,  2> EDGX0;                   // Edge X 0
    // 0b00..Disabled
    // 0b01..Capture falling edges
    // 0b10..Capture rising edges
    // 0b11..Capture any edge
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 1,  1> ONESHOTX;                // One Shot Mode Aux
    // 0b0..Free Running
    // 0b1..One Shot
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 1,  0> ARMX;                    // Arm X
    // 0b0..Input capture operation is disabled.
    // 0b1..Input capture operation as specified by CAPTCTRLX[EDGXx] is enabled.
}  // namespace CAPTCTRLX

// Capture Compare X Register
namespace CAPTCOMPX {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCOMPX), 8, 8> EDGCNTX;  // Edge Counter X
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCOMPX, 8, 0> EDGCMPX;                  // Edge Compare X
}  // namespace CAPTCOMPX

// Capture Value 0 Register
namespace CVAL0 {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL0), 16, 0> CAPTVAL0;  // CAPTVAL0
}  // namespace CVAL0

// Capture Value 0 Cycle Register
namespace CVAL0CYC {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL0CYC), 4, 0> CVAL0CYC;  // CVAL0CYC
}  // namespace CVAL0CYC

// Capture Value 1 Register
namespace CVAL1 {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL1), 16, 0> CAPTVAL1;  // CAPTVAL1
}  // namespace CVAL1

// Capture Value 1 Cycle Register
namespace CVAL1CYC {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL1CYC), 4, 0> CVAL1CYC;  // CVAL1CYC
}  // namespace CVAL1CYC

// Capture Value 2 Register
namespace CVAL2 {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL2), 16, 0> CAPTVAL2;  // CAPTVAL2
}  // namespace CVAL2

// Capture Value 2 Cycle Register
namespace CVAL2CYC {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL2CYC), 4, 0> CVAL2CYC;  // CVAL2CYC
}  // namespace CVAL2CYC

// Capture Value 3 Register
namespace CVAL3 {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL3), 16, 0> CAPTVAL3;  // CAPTVAL3
}  // namespace CVAL3

// Capture Value 3 Cycle Register
namespace CVAL3CYC {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL3CYC), 4, 0> CVAL3CYC;  // CVAL3CYC
}  // namespace CVAL3CYC

// Capture Value 4 Register
namespace CVAL4 {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL4), 16, 0> CAPTVAL4;  // CAPTVAL4
}  // namespace CVAL4

// Capture Value 4 Cycle Register
namespace CVAL4CYC {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL4CYC), 4, 0> CVAL4CYC;  // CVAL4CYC
}  // namespace CVAL4CYC

// Capture Value 5 Register
namespace CVAL5 {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL5), 16, 0> CAPTVAL5;  // CAPTVAL5
}  // namespace CVAL5

// Capture Value 5 Cycle Register
namespace CVAL5CYC {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL5CYC), 4, 0> CVAL5CYC;  // CVAL5CYC
}  // namespace CVAL5CYC

}  // namespace SM

// Output Enable Register
namespace OUTEN {
constexpr PWM1_Reg<&PWM_Layout::OUTEN, 4, 8> PWMA_EN;  // PWM_A Output Enables
    // 0b0000..PWM_A output disabled.
    // 0b0001..PWM_A output enabled.
constexpr PWM1_Reg<&PWM_Layout::OUTEN, 4, 4> PWMB_EN;  // PWM_B Output Enables
    // 0b0000..PWM_B output disabled.
    // 0b0001..PWM_B output enabled.
constexpr PWM1_Reg<&PWM_Layout::OUTEN, 4, 0> PWMX_EN;  // PWM_X Output Enables
    // 0b0000..PWM_X output disabled.
    // 0b0001..PWM_X output enabled.
}  // namespace OUTEN

// Mask Register
namespace MASK {
// TODO: Is this the correct way?
constexpr uint16_t kWO = 0xf000;

constexpr PWM1_Reg<&PWM_Layout::MASK, 4, 12, kWO, true> UPDATE_MASK;                    // Update Mask Bits Immediately
    // 0b0000..Normal operation. MASK* bits within the corresponding submodule are not updated until a FORCE_OUT
    //     event occurs within the submodule.
    // 0b0001..Immediate operation. MASK* bits within the corresponding submodule are updated on the following clock
    //     edge after setting this bit.
constexpr PWM1_Reg<&PWM_Layout::MASK, 4,  8, regs::shiftedMask16<4, 8>() | kWO> MASKA;  // PWM_A Masks
    // 0b0000..PWM_A output normal.
    // 0b0001..PWM_A output masked.
constexpr PWM1_Reg<&PWM_Layout::MASK, 4,  4, regs::shiftedMask16<4, 4>() | kWO> MASKB;  // PWM_B Masks
    // 0b0000..PWM_B output normal.
    // 0b0001..PWM_B output masked.
constexpr PWM1_Reg<&PWM_Layout::MASK, 4,  0, regs::shiftedMask16<4, 0>() | kWO> MASKX;  // PWM_X Masks
    // 0b0000..PWM_X output normal.
    // 0b0001..PWM_X output masked.
}  // namespace MASK

// Software Controlled Output Register
namespace SWCOUT {
constexpr PWM1_Reg<&PWM_Layout::SWCOUT, 1, 7> SM3OUT23;  // Submodule 3 Software Controlled Output 23
    // 0b0..A logic 0 is supplied to the deadtime generator of submodule 3 instead of PWM23.
    // 0b1..A logic 1 is supplied to the deadtime generator of submodule 3 instead of PWM23.
constexpr PWM1_Reg<&PWM_Layout::SWCOUT, 1, 6> SM3OUT45;  // Submodule 3 Software Controlled Output 45
    // 0b0..A logic 0 is supplied to the deadtime generator of submodule 3 instead of PWM45.
    // 0b1..A logic 1 is supplied to the deadtime generator of submodule 3 instead of PWM45.
constexpr PWM1_Reg<&PWM_Layout::SWCOUT, 1, 5> SM2OUT23;  // Submodule 2 Software Controlled Output 23
    // 0b0..A logic 0 is supplied to the deadtime generator of submodule 2 instead of PWM23.
    // 0b1..A logic 1 is supplied to the deadtime generator of submodule 2 instead of PWM23.
constexpr PWM1_Reg<&PWM_Layout::SWCOUT, 1, 4> SM2OUT45;  // Submodule 2 Software Controlled Output 45
    // 0b0..A logic 0 is supplied to the deadtime generator of submodule 2 instead of PWM45.
    // 0b1..A logic 1 is supplied to the deadtime generator of submodule 2 instead of PWM45.
constexpr PWM1_Reg<&PWM_Layout::SWCOUT, 1, 3> SM1OUT23;  // Submodule 1 Software Controlled Output 23
    // 0b0..A logic 0 is supplied to the deadtime generator of submodule 1 instead of PWM23.
    // 0b1..A logic 1 is supplied to the deadtime generator of submodule 1 instead of PWM23.
constexpr PWM1_Reg<&PWM_Layout::SWCOUT, 1, 2> SM1OUT45;  // Submodule 1 Software Controlled Output 45
    // 0b0..A logic 0 is supplied to the deadtime generator of submodule 1 instead of PWM45.
    // 0b1..A logic 1 is supplied to the deadtime generator of submodule 1 instead of PWM45.
constexpr PWM1_Reg<&PWM_Layout::SWCOUT, 1, 1> SM0OUT23;  // Submodule 0 Software Controlled Output 23
    // 0b0..A logic 0 is supplied to the deadtime generator of submodule 0 instead of PWM23.
    // 0b1..A logic 1 is supplied to the deadtime generator of submodule 0 instead of PWM23.
constexpr PWM1_Reg<&PWM_Layout::SWCOUT, 1, 0> SM0OUT45;  // Submodule 0 Software Controlled Output 45
    // 0b0..A logic 0 is supplied to the deadtime generator of submodule 0 instead of PWM45.
    // 0b1..A logic 1 is supplied to the deadtime generator of submodule 0 instead of PWM45.
}  // namespace SWCOUT

// PWM Source Select Register
namespace DTSRCSEL {
constexpr PWM1_Reg<&PWM_Layout::DTSRCSEL, 2, 14> SM3SEL23;  // Submodule 3 PWM23 Control Select
    // 0b00..Generated SM3PWM23 signal is used by the deadtime logic.
    // 0b01..Inverted generated SM3PWM23 signal is used by the deadtime logic.
    // 0b10..SWCOUT[SM3OUT23] is used by the deadtime logic.
    // 0b11..PWM3_EXTA signal is used by the deadtime logic.
constexpr PWM1_Reg<&PWM_Layout::DTSRCSEL, 2, 12> SM3SEL45;  // Submodule 3 PWM45 Control Select
    // 0b00..Generated SM3PWM45 signal is used by the deadtime logic.
    // 0b01..Inverted generated SM3PWM45 signal is used by the deadtime logic.
    // 0b10..SWCOUT[SM3OUT45] is used by the deadtime logic.
    // 0b11..PWM3_EXTB signal is used by the deadtime logic.
constexpr PWM1_Reg<&PWM_Layout::DTSRCSEL, 2, 10> SM2SEL23;  // Submodule 2 PWM23 Control Select
    // 0b00..Generated SM2PWM23 signal is used by the deadtime logic.
    // 0b01..Inverted generated SM2PWM23 signal is used by the deadtime logic.
    // 0b10..SWCOUT[SM2OUT23] is used by the deadtime logic.
    // 0b11..PWM2_EXTA signal is used by the deadtime logic.
constexpr PWM1_Reg<&PWM_Layout::DTSRCSEL, 2,  8> SM2SEL45;  // Submodule 2 PWM45 Control Select
    // 0b00..Generated SM2PWM45 signal is used by the deadtime logic.
    // 0b01..Inverted generated SM2PWM45 signal is used by the deadtime logic.
    // 0b10..SWCOUT[SM2OUT45] is used by the deadtime logic.
    // 0b11..PWM2_EXTB signal is used by the deadtime logic.
constexpr PWM1_Reg<&PWM_Layout::DTSRCSEL, 2,  6> SM1SEL23;  // Submodule 1 PWM23 Control Select
    // 0b00..Generated SM1PWM23 signal is used by the deadtime logic.
    // 0b01..Inverted generated SM1PWM23 signal is used by the deadtime logic.
    // 0b10..SWCOUT[SM1OUT23] is used by the deadtime logic.
    // 0b11..PWM1_EXTA signal is used by the deadtime logic.
constexpr PWM1_Reg<&PWM_Layout::DTSRCSEL, 2,  4> SM1SEL45;  // Submodule 1 PWM45 Control Select
    // 0b00..Generated SM1PWM45 signal is used by the deadtime logic.
    // 0b01..Inverted generated SM1PWM45 signal is used by the deadtime logic.
    // 0b10..SWCOUT[SM1OUT45] is used by the deadtime logic.
    // 0b11..PWM1_EXTB signal is used by the deadtime logic.
constexpr PWM1_Reg<&PWM_Layout::DTSRCSEL, 2,  2> SM0SEL23;  // Submodule 0 PWM23 Control Select
    // 0b00..Generated SM0PWM23 signal is used by the deadtime logic.
    // 0b01..Inverted generated SM0PWM23 signal is used by the deadtime logic.
    // 0b10..SWCOUT[SM0OUT23] is used by the deadtime logic.
    // 0b11..PWM0_EXTA signal is used by the deadtime logic.
constexpr PWM1_Reg<&PWM_Layout::DTSRCSEL, 2,  0> SM0SEL45;  // Submodule 0 PWM45 Control Select
    // 0b00..Generated SM0PWM45 signal is used by the deadtime logic.
    // 0b01..Inverted generated SM0PWM45 signal is used by the deadtime logic.
    // 0b10..SWCOUT[SM0OUT45] is used by the deadtime logic.
    // 0b11..PWM0_EXTB signal is used by the deadtime logic.
}  // namespace DTSRCSEL

// Master Control Register
namespace MCTRL {
constexpr PWM1_Reg<&PWM_Layout::MCTRL, 4, 12> IPOL;   // Current Polarity
    // 0b0000..PWM23 is used to generate complementary PWM pair in the corresponding submodule.
    // 0b0001..PWM45 is used to generate complementary PWM pair in the corresponding submodule.
constexpr PWM1_Reg<&PWM_Layout::MCTRL, 4,  8> RUN;    // Run
    // 0b0000..PWM counter is stopped, but PWM outputs will hold the current state.
    // 0b0001..PWM counter is started in the corresponding submodule.
constexpr PWM1_Reg<&PWM_Layout::MCTRL, 4,  4> CLDOK;  // Clear Load Okay
constexpr PWM1_Reg<&PWM_Layout::MCTRL, 4,  0> LDOK;   // Load Okay
    // 0b0000..Do not load new values.
    // 0b0001..Load prescaler, modulus, and PWM values of the corresponding submodule.
}  // namespace MCTRL

// Master Control 2 Register
namespace MCTRL2 {
constexpr PWM1_Reg<&PWM_Layout::MCTRL2, 2, 0> MONPLL;  // Monitor PLL State
    // 0b00..Not locked. Do not monitor PLL operation. Resetting of the fractional delay block in case of PLL losing
    //     lock will be controlled by software.
    // 0b01..Not locked. Monitor PLL operation to automatically disable the fractional delay block when the PLL
    //     encounters problems.
    // 0b10..Locked. Do not monitor PLL operation. Resetting of the fractional delay block in case of PLL losing
    //     lock will be controlled by software. These bits are write protected until the next reset.
    // 0b11..Locked. Monitor PLL operation to automatically disable the fractional delay block when the PLL
    //     encounters problems. These bits are write protected until the next reset.
}  // namespace MCTRL2

// Fault Control Register
namespace FCTRL {
constexpr PWM1_Reg<&PWM_Layout::FCTRL, 4, 12> FLVL;   // Fault Level
    // 0b0000..A logic 0 on the fault input indicates a fault condition.
    // 0b0001..A logic 1 on the fault input indicates a fault condition.
constexpr PWM1_Reg<&PWM_Layout::FCTRL, 4,  8> FAUTO;  // Automatic Fault Clearing
    // 0b0000..Manual fault clearing. PWM outputs disabled by this fault are not enabled until FSTS[FFLAGx] is clear
    //     at the start of a half cycle or full cycle depending the states of FSTS[FHALF] and FSTS[FFULL]. If
    //     neither FFULL nor FHALF is set, then the fault condition cannot be cleared. This is further controlled by
    //     FCTRL[FSAFE].
    // 0b0001..Automatic fault clearing. PWM outputs disabled by this fault are enabled when FSTS[FFPINx] is clear
    //     at the start of a half cycle or full cycle depending on the states of FSTS[FHALF] and FSTS[FFULL] without
    //     regard to the state of FSTS[FFLAGx]. If neither FFULL nor FHALF is set, then the fault condition cannot
    //     be cleared.
constexpr PWM1_Reg<&PWM_Layout::FCTRL, 4,  4> FSAFE;  // Fault Safety Mode
    // 0b0000..Normal mode. PWM outputs disabled by this fault are not enabled until FSTS[FFLAGx] is clear at the
    //     start of a half cycle or full cycle depending on the states of FSTS[FHALF] and FSTS[FFULL] without regard
    //     to the state of FSTS[FFPINx]. If neither FHALF nor FFULL is set then the fault condition cannot be
    //     cleared. The PWM outputs disabled by this fault input will not be re-enabled until the actual FAULTx
    //     input signal de-asserts since the fault input will combinationally disable the PWM outputs (as programmed
    //     in DISMAPn).
    // 0b0001..Safe mode. PWM outputs disabled by this fault are not enabled until FSTS[FFLAGx] is clear and
    //     FSTS[FFPINx] is clear at the start of a half cycle or full cycle depending on the states of FSTS[FHALF]
    //     and FSTS[FFULL]. If neither FHLAF nor FFULL is set, then the fault condition cannot be cleared.
constexpr PWM1_Reg<&PWM_Layout::FCTRL, 4,  0> FIE;    // Fault Interrupt Enables
    // 0b0000..FAULTx CPU interrupt requests disabled.
    // 0b0001..FAULTx CPU interrupt requests enabled.
}  // namespace FCTRL

// Fault Status Register
namespace FSTS {
constexpr uint16_t kW1C = 0x000f;

constexpr PWM1_Reg<&PWM_Layout::FSTS, 4, 12, regs::shiftedMask16<4, 12>() | kW1C> FHALF;  // Half Cycle Fault Recovery
    // 0b0000..PWM outputs are not re-enabled at the start of a half cycle.
    // 0b0001..PWM outputs are re-enabled at the start of a half cycle (as defined by VAL0).
constexpr PWM1_Reg<regs::constify(&PWM_Layout::FSTS), 4,  8> FFPIN;                       // Filtered Fault Pins
constexpr PWM1_Reg<&PWM_Layout::FSTS, 4,  4, regs::shiftedMask16<4,  4>() | kW1C> FFULL;  // Full Cycle
    // 0b0000..PWM outputs are not re-enabled at the start of a full cycle
    // 0b0001..PWM outputs are re-enabled at the start of a full cycle
constexpr PWM1_Reg<&PWM_Layout::FSTS, 4,  0, kW1C> FFLAG;                                 // Fault Flags
    // 0b0000..No fault on the FAULTx pin.
    // 0b0001..Fault on the FAULTx pin.
}  // namespace FSTS

// Fault Filter Register
namespace FFILT {
constexpr PWM1_Reg<&PWM_Layout::FFILT, 1, 15> GSTR;      // Fault Glitch Stretch Enable
    // 0b0..Fault input glitch stretching is disabled.
    // 0b1..Input fault signals will be stretched to at least 2 IPBus clock cycles.
constexpr PWM1_Reg<&PWM_Layout::FFILT, 3,  8> FILT_CNT;  // Fault Filter Count
constexpr PWM1_Reg<&PWM_Layout::FFILT, 8,  0> FILT_PER;  // Fault Filter Period
}  // namespace FFILT

// Fault Test Register
namespace FTST {
constexpr PWM1_Reg<&PWM_Layout::FTST, 1, 0> FTEST;  // Fault Test
    // 0b0..No fault
    // 0b1..Cause a simulated fault
}  // namespace FTST

// Fault Control 2 Register
namespace FCTRL2 {
constexpr PWM1_Reg<&PWM_Layout::FCTRL2, 4, 0> NOCOMB;  // No Combinational Path From Fault Input To PWM Output
    // 0b0000..There is a combinational link from the fault inputs to the PWM outputs. The fault inputs are combined
    //     with the filtered and latched fault signals to disable the PWM outputs.
    // 0b0001..The direct combinational path from the fault inputs to the PWM outputs is disabled and the filtered
    //     and latched fault signals are used to disable the PWM outputs.
}  // namespace FCTRL2

}  // namespace PWM1

namespace PWM2 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask16<Bits, Shift>(),
          bool WriteOnly = false>
using PWM2_Reg =
    regs::Reg16<kPWM2_base, PWM_Layout, Member, 0, Bits, Shift,
                AssignMask, 0, WriteOnly>;

template <size_t Index,
          typename = std::enable_if_t<(Index < kPWM_SM_count)>>
constexpr uintptr_t SMBase() {
  return kPWM2_base + offsetof(PWM_Layout, SM) +
         Index*sizeof(PWM_Layout::SM_Layout);
}

template <size_t Index, auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask16<Bits, Shift>(),
          bool WriteOnly = false>
using SM_Reg =
    regs::Reg16<SMBase<Index>(), PWM_Layout::SM_Layout, Member, 0,
                Bits, Shift, AssignMask, 0, WriteOnly>;

namespace SM {

// Counter Register
namespace CNT {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CNT), 16, 0> CNT;
}  // namespace CNT

// Initial Count Register
namespace INIT {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INIT, 16, 0> INIT;
}  // namespace INIT

// Control 2 Register
namespace CTRL2 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1, 15> DBGEN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1, 14> WAITEN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1, 13> INDEP;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1, 12> PWM23_INIT;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1, 11> PWM45_INIT;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1, 10> PWMX_INIT;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 2,  8> INIT_SEL;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1,  7> FRCEN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1,  6> FORCE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 3,  3> FORCE_SEL;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1,  2> RELOAD_SEL;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 2,  0> CLK_SEL;
}  // namespace CTRL2

// Control Register
namespace CTRL {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 4, 12> LDFQ;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1, 11> HALF;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1, 10> FULL;
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CTRL), 2,  8> DT;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1,  7> COMPMODE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 3,  4> PRSC;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1,  3> SPLIT;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1,  2> LDMOD;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1,  1> DBLX;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1,  0> DBLEN;
}  // namespace CTRL

// Value Register 0
namespace VAL0 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::VAL0, 16, 0> VAL0;
}  // namespace VAL0

// Fractional Value Register 1
namespace FRACVAL1 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRACVAL1, 5, 11> FRACVAL1;
}  // namespace FRACVAL1

// Value Register 1
namespace VAL1 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::VAL1, 16, 0> VAL1;
}  // namespace VAL1

// Fractional Value Register 2
namespace FRACVAL2 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRACVAL2, 5, 11> FRACVAL2;
}  // namespace FRACVAL2

// Value Register 2
namespace VAL2 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::VAL2, 16, 0> VAL2;
}  // namespace VAL2

// Fractional Value Register 3
namespace FRACVAL3 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRACVAL3, 5, 11> FRACVAL3;
}  // namespace FRACVAL3

// Value Register 3
namespace VAL3 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::VAL3, 16, 0> VAL3;
}  // namespace VAL3

// Fractional Value Register 4
namespace FRACVAL4 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRACVAL4, 5, 11> FRACVAL4;
}  // namespace FRACVAL4

// Value Register 4
namespace VAL4 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::VAL4, 16, 0> VAL4;
}  // namespace VAL4

// Fractional Value Register 5
namespace FRACVAL5 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRACVAL5, 5, 11> FRACVAL5;
}  // namespace FRACVAL5

// Value Register 5
namespace VAL5 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::VAL5, 16, 0> VAL5;
}  // namespace VAL5

// Fractional Control Register
namespace FRCTRL {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::FRCTRL), 1, 15> TEST;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRCTRL, 1,  8> FRAC_PU;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRCTRL, 1,  4> FRAC45_EN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRCTRL, 1,  2> FRAC23_EN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRCTRL, 1,  1> FRAC1_EN;
}  // namespace FRCTRL

// Output Control Register
namespace OCTRL {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::OCTRL), 1, 15> PWMA_IN;
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::OCTRL), 1, 14> PWMB_IN;
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::OCTRL), 1, 13> PWMX_IN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::OCTRL, 1, 10> POLA;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::OCTRL, 1,  9> POLB;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::OCTRL, 1,  8> POLX;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::OCTRL, 2,  4> PWMAFS;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::OCTRL, 2,  2> PWMBFS;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::OCTRL, 2,  0> PWMXFS;
}  // namespace OCTRL

// Status Register
namespace STS {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::STS), 1, 14> RUF;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1, 13, 0x0> REF;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1, 12, 0x0> RF;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1, 11, 0x0> CFA1;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1, 10, 0x0> CFA0;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1,  9, 0x0> CFB1;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1,  8, 0x0> CFB0;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1,  7, 0x0> CFX1;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1,  6, 0x0> CFX0;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 6,  0, 0x0> CMPF;
}  // namespace STS

// Interrupt Enable Register
namespace INTEN {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1, 13> REIE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1, 12> RIE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1, 11> CA1IE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1, 10> CA0IE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1,  9> CB1IE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1,  8> CB0IE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1,  7> CX1IE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1,  6> CX0IE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 6,  0> CMPIE;
}  // namespace INTEN

// DMA Enable Register
namespace DMAEN {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 9> VALDE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 8> FAND;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 2, 6> CAPTDE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 5> CA1DE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 4> CA0DE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 3> CB1DE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 2> CB0DE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 1> CX1DE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 0> CX0DE;
}  // namespace DMAEN

// Output Trigger Control Register
namespace TCTRL {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::TCTRL, 1, 15> PWAOT0;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::TCTRL, 1, 14> PWBOT1;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::TCTRL, 1, 12> TRGFRQ;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::TCTRL, 6,  0> OUT_TRIG_EN;
}  // namespace TCTRL

// Fault Disable Mapping Register 0
namespace DISMAP {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DISMAP, 4, 8> DIS0X;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DISMAP, 4, 4> DIS0B;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DISMAP, 4, 0> DIS0A;
}  // namespace DISMAP

// Deadtime Count Register 0
namespace DTCNT0 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DTCNT0, 16, 0> DTCNT0;
}  // namespace DTCNT0

// Deadtime Count Register 1
namespace DTCNT1 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DTCNT1, 16, 0> DTCNT1;
}  // namespace DTCNT1

// Capture Control A Register
namespace CAPTCTRLA {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCTRLA), 3, 13> CA1CNT;
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCTRLA), 3, 10> CA0CNT;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 2,  8> CFAWM;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 1,  7> EDGCNTA_EN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 1,  6> INP_SELA;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 2,  4> EDGA1;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 2,  2> EDGA0;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 1,  1> ONESHOTA;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 1,  0> ARMA;
}  // namespace CAPTCTRLA

// Capture Compare A Register
namespace CAPTCOMPA {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCOMPA), 8, 8> EDGCNTA;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCOMPA, 8, 0> EDGCMPA;
}  // namespace CAPTCOMPA

// Capture Control B Register
namespace CAPTCTRLB {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCTRLB), 3, 13> CB1CNT;
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCTRLB), 3, 10> CB0CNT;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 2,  8> CFBWM;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 1,  7> EDGCNTB_EN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 1,  6> INP_SELB;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 2,  4> EDGB1;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 2,  2> EDGB0;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 1,  1> ONESHOTB;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 1,  0> ARMB;
}  // namespace CAPTCTRLB

// Capture Compare B Register
namespace CAPTCOMPB {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCOMPB), 8, 8> EDGCNTB;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCOMPB, 8, 0> EDGCMPB;
}  // namespace CAPTCOMPB

// Capture Control X Register
namespace CAPTCTRLX {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCTRLX), 3, 13> CX1CNT;
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCTRLX), 3, 10> CX0CNT;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 2,  8> CFXWM;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 1,  7> EDGCNTX_EN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 1,  6> INP_SELX;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 2,  4> EDGX1;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 2,  2> EDGX0;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 1,  1> ONESHOTX;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 1,  0> ARMX;
}  // namespace CAPTCTRLX

// Capture Compare X Register
namespace CAPTCOMPX {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCOMPX), 8, 8> EDGCNTX;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCOMPX, 8, 0> EDGCMPX;
}  // namespace CAPTCOMPX

// Capture Value 0 Register
namespace CVAL0 {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL0), 16, 0> CAPTVAL0;
}  // namespace CVAL0

// Capture Value 0 Cycle Register
namespace CVAL0CYC {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL0CYC), 4, 0> CVAL0CYC;
}  // namespace CVAL0CYC

// Capture Value 1 Register
namespace CVAL1 {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL1), 16, 0> CAPTVAL1;
}  // namespace CVAL1

// Capture Value 1 Cycle Register
namespace CVAL1CYC {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL1CYC), 4, 0> CVAL1CYC;
}  // namespace CVAL1CYC

// Capture Value 2 Register
namespace CVAL2 {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL2), 16, 0> CAPTVAL2;
}  // namespace CVAL2

// Capture Value 2 Cycle Register
namespace CVAL2CYC {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL2CYC), 4, 0> CVAL2CYC;
}  // namespace CVAL2CYC

// Capture Value 3 Register
namespace CVAL3 {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL3), 16, 0> CAPTVAL3;
}  // namespace CVAL3

// Capture Value 3 Cycle Register
namespace CVAL3CYC {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL3CYC), 4, 0> CVAL3CYC;
}  // namespace CVAL3CYC

// Capture Value 4 Register
namespace CVAL4 {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL4), 16, 0> CAPTVAL4;
}  // namespace CVAL4

// Capture Value 4 Cycle Register
namespace CVAL4CYC {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL4CYC), 4, 0> CVAL4CYC;
}  // namespace CVAL4CYC

// Capture Value 5 Register
namespace CVAL5 {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL5), 16, 0> CAPTVAL5;
}  // namespace CVAL5

// Capture Value 5 Cycle Register
namespace CVAL5CYC {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL5CYC), 4, 0> CVAL5CYC;
}  // namespace CVAL5CYC

}  // namespace SM

// Output Enable Register
namespace OUTEN {
constexpr PWM2_Reg<&PWM_Layout::OUTEN, 4, 8> PWMA_EN;
constexpr PWM2_Reg<&PWM_Layout::OUTEN, 4, 4> PWMB_EN;
constexpr PWM2_Reg<&PWM_Layout::OUTEN, 4, 0> PWMX_EN;
}  // namespace OUTEN

// Mask Register
namespace MASK {
// TODO: Is this the correct way?
constexpr uint16_t kWO = 0xf000;

constexpr PWM2_Reg<&PWM_Layout::MASK, 4, 12, kWO, true> UPDATE_MASK;                    // Update Mask Bits Immediately
constexpr PWM2_Reg<&PWM_Layout::MASK, 4,  8, regs::shiftedMask16<4, 8>() | kWO> MASKA;  // PWM_A Masks
constexpr PWM2_Reg<&PWM_Layout::MASK, 4,  4, regs::shiftedMask16<4, 4>() | kWO> MASKB;  // PWM_B Masks
constexpr PWM2_Reg<&PWM_Layout::MASK, 4,  0, regs::shiftedMask16<4, 0>() | kWO> MASKX;  // PWM_X Masks
}  // namespace MASK

// Software Controlled Output Register
namespace SWCOUT {
constexpr PWM2_Reg<&PWM_Layout::SWCOUT, 1, 7> SM3OUT23;
constexpr PWM2_Reg<&PWM_Layout::SWCOUT, 1, 6> SM3OUT45;
constexpr PWM2_Reg<&PWM_Layout::SWCOUT, 1, 5> SM2OUT23;
constexpr PWM2_Reg<&PWM_Layout::SWCOUT, 1, 4> SM2OUT45;
constexpr PWM2_Reg<&PWM_Layout::SWCOUT, 1, 3> SM1OUT23;
constexpr PWM2_Reg<&PWM_Layout::SWCOUT, 1, 2> SM1OUT45;
constexpr PWM2_Reg<&PWM_Layout::SWCOUT, 1, 1> SM0OUT23;
constexpr PWM2_Reg<&PWM_Layout::SWCOUT, 1, 0> SM0OUT45;
}  // namespace SWCOUT

// PWM Source Select Register
namespace DTSRCSEL {
constexpr PWM2_Reg<&PWM_Layout::DTSRCSEL, 2, 14> SM3SEL23;
constexpr PWM2_Reg<&PWM_Layout::DTSRCSEL, 2, 12> SM3SEL45;
constexpr PWM2_Reg<&PWM_Layout::DTSRCSEL, 2, 10> SM2SEL23;
constexpr PWM2_Reg<&PWM_Layout::DTSRCSEL, 2,  8> SM2SEL45;
constexpr PWM2_Reg<&PWM_Layout::DTSRCSEL, 2,  6> SM1SEL23;
constexpr PWM2_Reg<&PWM_Layout::DTSRCSEL, 2,  4> SM1SEL45;
constexpr PWM2_Reg<&PWM_Layout::DTSRCSEL, 2,  2> SM0SEL23;
constexpr PWM2_Reg<&PWM_Layout::DTSRCSEL, 2,  0> SM0SEL45;
}  // namespace DTSRCSEL

// Master Control Register
namespace MCTRL {
constexpr PWM2_Reg<&PWM_Layout::MCTRL, 4, 12> IPOL;
constexpr PWM2_Reg<&PWM_Layout::MCTRL, 4,  8> RUN;
constexpr PWM2_Reg<&PWM_Layout::MCTRL, 4,  4> CLDOK;
constexpr PWM2_Reg<&PWM_Layout::MCTRL, 4,  0> LDOK;
}  // namespace MCTRL

// Master Control 2 Register
namespace MCTRL2 {
constexpr PWM2_Reg<&PWM_Layout::MCTRL2, 2, 0> MONPLL;
}  // namespace MCTRL2

// Fault Control Register
namespace FCTRL {
constexpr PWM2_Reg<&PWM_Layout::FCTRL, 4, 12> FLVL;
constexpr PWM2_Reg<&PWM_Layout::FCTRL, 4,  8> FAUTO;
constexpr PWM2_Reg<&PWM_Layout::FCTRL, 4,  4> FSAFE;
constexpr PWM2_Reg<&PWM_Layout::FCTRL, 4,  0> FIE;
}  // namespace FCTRL

// Fault Status Register
namespace FSTS {
constexpr uint16_t kW1C = 0x000f;

constexpr PWM2_Reg<&PWM_Layout::FSTS, 4, 12, regs::shiftedMask16<4, 12>() | kW1C> FHALF;
constexpr PWM2_Reg<regs::constify(&PWM_Layout::FSTS), 4,  8> FFPIN;
constexpr PWM2_Reg<&PWM_Layout::FSTS, 4,  4, regs::shiftedMask16<4,  4>() | kW1C> FFULL;
constexpr PWM2_Reg<&PWM_Layout::FSTS, 4,  0, kW1C> FFLAG;
}  // namespace FSTS

// Fault Filter Register
namespace FFILT {
constexpr PWM2_Reg<&PWM_Layout::FFILT, 1, 15> GSTR;
constexpr PWM2_Reg<&PWM_Layout::FFILT, 3,  8> FILT_CNT;
constexpr PWM2_Reg<&PWM_Layout::FFILT, 8,  0> FILT_PER;
}  // namespace FFILT

// Fault Test Register
namespace FTST {
constexpr PWM2_Reg<&PWM_Layout::FTST, 1, 0> FTEST;
}  // namespace FTST

// Fault Control 2 Register
namespace FCTRL2 {
constexpr PWM2_Reg<&PWM_Layout::FCTRL2, 4, 0> NOCOMB;
}  // namespace FCTRL2

}  // namespace PWM2

namespace PWM3 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask16<Bits, Shift>(),
          bool WriteOnly = false>
using PWM3_Reg =
    regs::Reg16<kPWM3_base, PWM_Layout, Member, 0, Bits, Shift,
                AssignMask, 0, WriteOnly>;

template <size_t Index,
          typename = std::enable_if_t<(Index < kPWM_SM_count)>>
constexpr uintptr_t SMBase() {
  return kPWM3_base + offsetof(PWM_Layout, SM) +
         Index*sizeof(PWM_Layout::SM_Layout);
}

template <size_t Index, auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask16<Bits, Shift>(),
          bool WriteOnly = false>
using SM_Reg =
    regs::Reg16<SMBase<Index>(), PWM_Layout::SM_Layout, Member, 0,
                Bits, Shift, AssignMask, 0, WriteOnly>;

namespace SM {

// Counter Register
namespace CNT {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CNT), 16, 0> CNT;
}  // namespace CNT

// Initial Count Register
namespace INIT {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INIT, 16, 0> INIT;
}  // namespace INIT

// Control 2 Register
namespace CTRL2 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1, 15> DBGEN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1, 14> WAITEN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1, 13> INDEP;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1, 12> PWM23_INIT;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1, 11> PWM45_INIT;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1, 10> PWMX_INIT;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 2,  8> INIT_SEL;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1,  7> FRCEN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1,  6> FORCE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 3,  3> FORCE_SEL;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1,  2> RELOAD_SEL;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 2,  0> CLK_SEL;
}  // namespace CTRL2

// Control Register
namespace CTRL {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 4, 12> LDFQ;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1, 11> HALF;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1, 10> FULL;
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CTRL), 2,  8> DT;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1,  7> COMPMODE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 3,  4> PRSC;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1,  3> SPLIT;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1,  2> LDMOD;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1,  1> DBLX;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1,  0> DBLEN;
}  // namespace CTRL

// Value Register 0
namespace VAL0 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::VAL0, 16, 0> VAL0;
}  // namespace VAL0

// Fractional Value Register 1
namespace FRACVAL1 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRACVAL1, 5, 11> FRACVAL1;
}  // namespace FRACVAL1

// Value Register 1
namespace VAL1 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::VAL1, 16, 0> VAL1;
}  // namespace VAL1

// Fractional Value Register 2
namespace FRACVAL2 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRACVAL2, 5, 11> FRACVAL2;
}  // namespace FRACVAL2

// Value Register 2
namespace VAL2 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::VAL2, 16, 0> VAL2;
}  // namespace VAL2

// Fractional Value Register 3
namespace FRACVAL3 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRACVAL3, 5, 11> FRACVAL3;
}  // namespace FRACVAL3

// Value Register 3
namespace VAL3 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::VAL3, 16, 0> VAL3;
}  // namespace VAL3

// Fractional Value Register 4
namespace FRACVAL4 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRACVAL4, 5, 11> FRACVAL4;
}  // namespace FRACVAL4

// Value Register 4
namespace VAL4 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::VAL4, 16, 0> VAL4;
}  // namespace VAL4

// Fractional Value Register 5
namespace FRACVAL5 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRACVAL5, 5, 11> FRACVAL5;
}  // namespace FRACVAL5

// Value Register 5
namespace VAL5 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::VAL5, 16, 0> VAL5;
}  // namespace VAL5

// Fractional Control Register
namespace FRCTRL {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::FRCTRL), 1, 15> TEST;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRCTRL, 1,  8> FRAC_PU;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRCTRL, 1,  4> FRAC45_EN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRCTRL, 1,  2> FRAC23_EN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRCTRL, 1,  1> FRAC1_EN;
}  // namespace FRCTRL

// Output Control Register
namespace OCTRL {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::OCTRL), 1, 15> PWMA_IN;
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::OCTRL), 1, 14> PWMB_IN;
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::OCTRL), 1, 13> PWMX_IN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::OCTRL, 1, 10> POLA;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::OCTRL, 1,  9> POLB;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::OCTRL, 1,  8> POLX;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::OCTRL, 2,  4> PWMAFS;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::OCTRL, 2,  2> PWMBFS;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::OCTRL, 2,  0> PWMXFS;
}  // namespace OCTRL

// Status Register
namespace STS {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::STS), 1, 14> RUF;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1, 13, 0x0> REF;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1, 12, 0x0> RF;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1, 11, 0x0> CFA1;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1, 10, 0x0> CFA0;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1,  9, 0x0> CFB1;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1,  8, 0x0> CFB0;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1,  7, 0x0> CFX1;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1,  6, 0x0> CFX0;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 6,  0, 0x0> CMPF;
}  // namespace STS

// Interrupt Enable Register
namespace INTEN {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1, 13> REIE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1, 12> RIE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1, 11> CA1IE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1, 10> CA0IE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1,  9> CB1IE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1,  8> CB0IE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1,  7> CX1IE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1,  6> CX0IE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 6,  0> CMPIE;
}  // namespace INTEN

// DMA Enable Register
namespace DMAEN {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 9> VALDE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 8> FAND;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 2, 6> CAPTDE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 5> CA1DE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 4> CA0DE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 3> CB1DE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 2> CB0DE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 1> CX1DE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 0> CX0DE;
}  // namespace DMAEN

// Output Trigger Control Register
namespace TCTRL {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::TCTRL, 1, 15> PWAOT0;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::TCTRL, 1, 14> PWBOT1;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::TCTRL, 1, 12> TRGFRQ;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::TCTRL, 6,  0> OUT_TRIG_EN;
}  // namespace TCTRL

// Fault Disable Mapping Register 0
namespace DISMAP {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DISMAP, 4, 8> DIS0X;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DISMAP, 4, 4> DIS0B;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DISMAP, 4, 0> DIS0A;
}  // namespace DISMAP

// Deadtime Count Register 0
namespace DTCNT0 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DTCNT0, 16, 0> DTCNT0;
}  // namespace DTCNT0

// Deadtime Count Register 1
namespace DTCNT1 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DTCNT1, 16, 0> DTCNT1;
}  // namespace DTCNT1

// Capture Control A Register
namespace CAPTCTRLA {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCTRLA), 3, 13> CA1CNT;
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCTRLA), 3, 10> CA0CNT;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 2,  8> CFAWM;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 1,  7> EDGCNTA_EN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 1,  6> INP_SELA;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 2,  4> EDGA1;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 2,  2> EDGA0;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 1,  1> ONESHOTA;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 1,  0> ARMA;
}  // namespace CAPTCTRLA

// Capture Compare A Register
namespace CAPTCOMPA {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCOMPA), 8, 8> EDGCNTA;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCOMPA, 8, 0> EDGCMPA;
}  // namespace CAPTCOMPA

// Capture Control B Register
namespace CAPTCTRLB {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCTRLB), 3, 13> CB1CNT;
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCTRLB), 3, 10> CB0CNT;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 2,  8> CFBWM;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 1,  7> EDGCNTB_EN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 1,  6> INP_SELB;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 2,  4> EDGB1;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 2,  2> EDGB0;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 1,  1> ONESHOTB;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 1,  0> ARMB;
}  // namespace CAPTCTRLB

// Capture Compare B Register
namespace CAPTCOMPB {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCOMPB), 8, 8> EDGCNTB;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCOMPB, 8, 0> EDGCMPB;
}  // namespace CAPTCOMPB

// Capture Control X Register
namespace CAPTCTRLX {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCTRLX), 3, 13> CX1CNT;
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCTRLX), 3, 10> CX0CNT;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 2,  8> CFXWM;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 1,  7> EDGCNTX_EN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 1,  6> INP_SELX;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 2,  4> EDGX1;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 2,  2> EDGX0;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 1,  1> ONESHOTX;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 1,  0> ARMX;
}  // namespace CAPTCTRLX

// Capture Compare X Register
namespace CAPTCOMPX {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCOMPX), 8, 8> EDGCNTX;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCOMPX, 8, 0> EDGCMPX;
}  // namespace CAPTCOMPX

// Capture Value 0 Register
namespace CVAL0 {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL0), 16, 0> CAPTVAL0;
}  // namespace CVAL0

// Capture Value 0 Cycle Register
namespace CVAL0CYC {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL0CYC), 4, 0> CVAL0CYC;
}  // namespace CVAL0CYC

// Capture Value 1 Register
namespace CVAL1 {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL1), 16, 0> CAPTVAL1;
}  // namespace CVAL1

// Capture Value 1 Cycle Register
namespace CVAL1CYC {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL1CYC), 4, 0> CVAL1CYC;
}  // namespace CVAL1CYC

// Capture Value 2 Register
namespace CVAL2 {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL2), 16, 0> CAPTVAL2;
}  // namespace CVAL2

// Capture Value 2 Cycle Register
namespace CVAL2CYC {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL2CYC), 4, 0> CVAL2CYC;
}  // namespace CVAL2CYC

// Capture Value 3 Register
namespace CVAL3 {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL3), 16, 0> CAPTVAL3;
}  // namespace CVAL3

// Capture Value 3 Cycle Register
namespace CVAL3CYC {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL3CYC), 4, 0> CVAL3CYC;
}  // namespace CVAL3CYC

// Capture Value 4 Register
namespace CVAL4 {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL4), 16, 0> CAPTVAL4;
}  // namespace CVAL4

// Capture Value 4 Cycle Register
namespace CVAL4CYC {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL4CYC), 4, 0> CVAL4CYC;
}  // namespace CVAL4CYC

// Capture Value 5 Register
namespace CVAL5 {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL5), 16, 0> CAPTVAL5;
}  // namespace CVAL5

// Capture Value 5 Cycle Register
namespace CVAL5CYC {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL5CYC), 4, 0> CVAL5CYC;
}  // namespace CVAL5CYC

}  // namespace SM

// Output Enable Register
namespace OUTEN {
constexpr PWM3_Reg<&PWM_Layout::OUTEN, 4, 8> PWMA_EN;
constexpr PWM3_Reg<&PWM_Layout::OUTEN, 4, 4> PWMB_EN;
constexpr PWM3_Reg<&PWM_Layout::OUTEN, 4, 0> PWMX_EN;
}  // namespace OUTEN

// Mask Register
namespace MASK {
// TODO: Is this the correct way?
constexpr uint16_t kWO = 0xf000;

constexpr PWM3_Reg<&PWM_Layout::MASK, 4, 12, kWO, true> UPDATE_MASK;                    // Update Mask Bits Immediately
constexpr PWM3_Reg<&PWM_Layout::MASK, 4,  8, regs::shiftedMask16<4, 8>() | kWO> MASKA;  // PWM_A Masks
constexpr PWM3_Reg<&PWM_Layout::MASK, 4,  4, regs::shiftedMask16<4, 4>() | kWO> MASKB;  // PWM_B Masks
constexpr PWM3_Reg<&PWM_Layout::MASK, 4,  0, regs::shiftedMask16<4, 0>() | kWO> MASKX;  // PWM_X Masks
}  // namespace MASK

// Software Controlled Output Register
namespace SWCOUT {
constexpr PWM3_Reg<&PWM_Layout::SWCOUT, 1, 7> SM3OUT23;
constexpr PWM3_Reg<&PWM_Layout::SWCOUT, 1, 6> SM3OUT45;
constexpr PWM3_Reg<&PWM_Layout::SWCOUT, 1, 5> SM2OUT23;
constexpr PWM3_Reg<&PWM_Layout::SWCOUT, 1, 4> SM2OUT45;
constexpr PWM3_Reg<&PWM_Layout::SWCOUT, 1, 3> SM1OUT23;
constexpr PWM3_Reg<&PWM_Layout::SWCOUT, 1, 2> SM1OUT45;
constexpr PWM3_Reg<&PWM_Layout::SWCOUT, 1, 1> SM0OUT23;
constexpr PWM3_Reg<&PWM_Layout::SWCOUT, 1, 0> SM0OUT45;
}  // namespace SWCOUT

// PWM Source Select Register
namespace DTSRCSEL {
constexpr PWM3_Reg<&PWM_Layout::DTSRCSEL, 2, 14> SM3SEL23;
constexpr PWM3_Reg<&PWM_Layout::DTSRCSEL, 2, 12> SM3SEL45;
constexpr PWM3_Reg<&PWM_Layout::DTSRCSEL, 2, 10> SM2SEL23;
constexpr PWM3_Reg<&PWM_Layout::DTSRCSEL, 2,  8> SM2SEL45;
constexpr PWM3_Reg<&PWM_Layout::DTSRCSEL, 2,  6> SM1SEL23;
constexpr PWM3_Reg<&PWM_Layout::DTSRCSEL, 2,  4> SM1SEL45;
constexpr PWM3_Reg<&PWM_Layout::DTSRCSEL, 2,  2> SM0SEL23;
constexpr PWM3_Reg<&PWM_Layout::DTSRCSEL, 2,  0> SM0SEL45;
}  // namespace DTSRCSEL

// Master Control Register
namespace MCTRL {
constexpr PWM3_Reg<&PWM_Layout::MCTRL, 4, 12> IPOL;
constexpr PWM3_Reg<&PWM_Layout::MCTRL, 4,  8> RUN;
constexpr PWM3_Reg<&PWM_Layout::MCTRL, 4,  4> CLDOK;
constexpr PWM3_Reg<&PWM_Layout::MCTRL, 4,  0> LDOK;
}  // namespace MCTRL

// Master Control 2 Register
namespace MCTRL2 {
constexpr PWM3_Reg<&PWM_Layout::MCTRL2, 2, 0> MONPLL;
}  // namespace MCTRL2

// Fault Control Register
namespace FCTRL {
constexpr PWM3_Reg<&PWM_Layout::FCTRL, 4, 12> FLVL;
constexpr PWM3_Reg<&PWM_Layout::FCTRL, 4,  8> FAUTO;
constexpr PWM3_Reg<&PWM_Layout::FCTRL, 4,  4> FSAFE;
constexpr PWM3_Reg<&PWM_Layout::FCTRL, 4,  0> FIE;
}  // namespace FCTRL

// Fault Status Register
namespace FSTS {
constexpr uint16_t kW1C = 0x000f;

constexpr PWM3_Reg<&PWM_Layout::FSTS, 4, 12, regs::shiftedMask16<4, 12>() | kW1C> FHALF;
constexpr PWM3_Reg<regs::constify(&PWM_Layout::FSTS), 4,  8> FFPIN;
constexpr PWM3_Reg<&PWM_Layout::FSTS, 4,  4, regs::shiftedMask16<4,  4>() | kW1C> FFULL;
constexpr PWM3_Reg<&PWM_Layout::FSTS, 4,  0, kW1C> FFLAG;
}  // namespace FSTS

// Fault Filter Register
namespace FFILT {
constexpr PWM3_Reg<&PWM_Layout::FFILT, 1, 15> GSTR;
constexpr PWM3_Reg<&PWM_Layout::FFILT, 3,  8> FILT_CNT;
constexpr PWM3_Reg<&PWM_Layout::FFILT, 8,  0> FILT_PER;
}  // namespace FFILT

// Fault Test Register
namespace FTST {
constexpr PWM3_Reg<&PWM_Layout::FTST, 1, 0> FTEST;
}  // namespace FTST

// Fault Control 2 Register
namespace FCTRL2 {
constexpr PWM3_Reg<&PWM_Layout::FCTRL2, 4, 0> NOCOMB;
}  // namespace FCTRL2

}  // namespace PWM3

namespace PWM4 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask16<Bits, Shift>(),
          bool WriteOnly = false>
using PWM4_Reg =
    regs::Reg16<kPWM4_base, PWM_Layout, Member, 0, Bits, Shift,
                AssignMask, 0, WriteOnly>;

template <size_t Index,
          typename = std::enable_if_t<(Index < kPWM_SM_count)>>
constexpr uintptr_t SMBase() {
  return kPWM4_base + offsetof(PWM_Layout, SM) +
         Index*sizeof(PWM_Layout::SM_Layout);
}

template <size_t Index, auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask16<Bits, Shift>(),
          bool WriteOnly = false>
using SM_Reg =
    regs::Reg16<SMBase<Index>(), PWM_Layout::SM_Layout, Member, 0,
                Bits, Shift, AssignMask, 0, WriteOnly>;

namespace SM {

// Counter Register
namespace CNT {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CNT), 16, 0> CNT;
}  // namespace CNT

// Initial Count Register
namespace INIT {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INIT, 16, 0> INIT;
}  // namespace INIT

// Control 2 Register
namespace CTRL2 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1, 15> DBGEN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1, 14> WAITEN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1, 13> INDEP;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1, 12> PWM23_INIT;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1, 11> PWM45_INIT;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1, 10> PWMX_INIT;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 2,  8> INIT_SEL;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1,  7> FRCEN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1,  6> FORCE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 3,  3> FORCE_SEL;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 1,  2> RELOAD_SEL;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL2, 2,  0> CLK_SEL;
}  // namespace CTRL2

// Control Register
namespace CTRL {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 4, 12> LDFQ;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1, 11> HALF;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1, 10> FULL;
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CTRL), 2,  8> DT;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1,  7> COMPMODE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 3,  4> PRSC;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1,  3> SPLIT;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1,  2> LDMOD;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1,  1> DBLX;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CTRL, 1,  0> DBLEN;
}  // namespace CTRL

// Value Register 0
namespace VAL0 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::VAL0, 16, 0> VAL0;
}  // namespace VAL0

// Fractional Value Register 1
namespace FRACVAL1 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRACVAL1, 5, 11> FRACVAL1;
}  // namespace FRACVAL1

// Value Register 1
namespace VAL1 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::VAL1, 16, 0> VAL1;
}  // namespace VAL1

// Fractional Value Register 2
namespace FRACVAL2 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRACVAL2, 5, 11> FRACVAL2;
}  // namespace FRACVAL2

// Value Register 2
namespace VAL2 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::VAL2, 16, 0> VAL2;
}  // namespace VAL2

// Fractional Value Register 3
namespace FRACVAL3 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRACVAL3, 5, 11> FRACVAL3;
}  // namespace FRACVAL3

// Value Register 3
namespace VAL3 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::VAL3, 16, 0> VAL3;
}  // namespace VAL3

// Fractional Value Register 4
namespace FRACVAL4 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRACVAL4, 5, 11> FRACVAL4;
}  // namespace FRACVAL4

// Value Register 4
namespace VAL4 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::VAL4, 16, 0> VAL4;
}  // namespace VAL4

// Fractional Value Register 5
namespace FRACVAL5 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRACVAL5, 5, 11> FRACVAL5;
}  // namespace FRACVAL5

// Value Register 5
namespace VAL5 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::VAL5, 16, 0> VAL5;
}  // namespace VAL5

// Fractional Control Register
namespace FRCTRL {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::FRCTRL), 1, 15> TEST;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRCTRL, 1,  8> FRAC_PU;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRCTRL, 1,  4> FRAC45_EN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRCTRL, 1,  2> FRAC23_EN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::FRCTRL, 1,  1> FRAC1_EN;
}  // namespace FRCTRL

// Output Control Register
namespace OCTRL {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::OCTRL), 1, 15> PWMA_IN;
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::OCTRL), 1, 14> PWMB_IN;
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::OCTRL), 1, 13> PWMX_IN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::OCTRL, 1, 10> POLA;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::OCTRL, 1,  9> POLB;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::OCTRL, 1,  8> POLX;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::OCTRL, 2,  4> PWMAFS;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::OCTRL, 2,  2> PWMBFS;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::OCTRL, 2,  0> PWMXFS;
}  // namespace OCTRL

// Status Register
namespace STS {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::STS), 1, 14> RUF;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1, 13, 0x0> REF;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1, 12, 0x0> RF;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1, 11, 0x0> CFA1;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1, 10, 0x0> CFA0;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1,  9, 0x0> CFB1;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1,  8, 0x0> CFB0;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1,  7, 0x0> CFX1;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 1,  6, 0x0> CFX0;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::STS, 6,  0, 0x0> CMPF;
}  // namespace STS

// Interrupt Enable Register
namespace INTEN {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1, 13> REIE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1, 12> RIE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1, 11> CA1IE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1, 10> CA0IE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1,  9> CB1IE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1,  8> CB0IE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1,  7> CX1IE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 1,  6> CX0IE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::INTEN, 6,  0> CMPIE;
}  // namespace INTEN

// DMA Enable Register
namespace DMAEN {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 9> VALDE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 8> FAND;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 2, 6> CAPTDE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 5> CA1DE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 4> CA0DE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 3> CB1DE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 2> CB0DE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 1> CX1DE;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DMAEN, 1, 0> CX0DE;
}  // namespace DMAEN

// Output Trigger Control Register
namespace TCTRL {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::TCTRL, 1, 15> PWAOT0;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::TCTRL, 1, 14> PWBOT1;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::TCTRL, 1, 12> TRGFRQ;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::TCTRL, 6,  0> OUT_TRIG_EN;
}  // namespace TCTRL

// Fault Disable Mapping Register 0
namespace DISMAP {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DISMAP, 4, 8> DIS0X;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DISMAP, 4, 4> DIS0B;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DISMAP, 4, 0> DIS0A;
}  // namespace DISMAP

// Deadtime Count Register 0
namespace DTCNT0 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DTCNT0, 16, 0> DTCNT0;
}  // namespace DTCNT0

// Deadtime Count Register 1
namespace DTCNT1 {
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::DTCNT1, 16, 0> DTCNT1;
}  // namespace DTCNT1

// Capture Control A Register
namespace CAPTCTRLA {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCTRLA), 3, 13> CA1CNT;
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCTRLA), 3, 10> CA0CNT;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 2,  8> CFAWM;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 1,  7> EDGCNTA_EN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 1,  6> INP_SELA;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 2,  4> EDGA1;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 2,  2> EDGA0;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 1,  1> ONESHOTA;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLA, 1,  0> ARMA;
}  // namespace CAPTCTRLA

// Capture Compare A Register
namespace CAPTCOMPA {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCOMPA), 8, 8> EDGCNTA;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCOMPA, 8, 0> EDGCMPA;
}  // namespace CAPTCOMPA

// Capture Control B Register
namespace CAPTCTRLB {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCTRLB), 3, 13> CB1CNT;
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCTRLB), 3, 10> CB0CNT;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 2,  8> CFBWM;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 1,  7> EDGCNTB_EN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 1,  6> INP_SELB;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 2,  4> EDGB1;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 2,  2> EDGB0;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 1,  1> ONESHOTB;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLB, 1,  0> ARMB;
}  // namespace CAPTCTRLB

// Capture Compare B Register
namespace CAPTCOMPB {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCOMPB), 8, 8> EDGCNTB;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCOMPB, 8, 0> EDGCMPB;
}  // namespace CAPTCOMPB

// Capture Control X Register
namespace CAPTCTRLX {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCTRLX), 3, 13> CX1CNT;
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCTRLX), 3, 10> CX0CNT;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 2,  8> CFXWM;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 1,  7> EDGCNTX_EN;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 1,  6> INP_SELX;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 2,  4> EDGX1;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 2,  2> EDGX0;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 1,  1> ONESHOTX;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCTRLX, 1,  0> ARMX;
}  // namespace CAPTCTRLX

// Capture Compare X Register
namespace CAPTCOMPX {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CAPTCOMPX), 8, 8> EDGCNTX;
template <size_t Index>
constexpr SM_Reg<Index, &PWM_Layout::SM_Layout::CAPTCOMPX, 8, 0> EDGCMPX;
}  // namespace CAPTCOMPX

// Capture Value 0 Register
namespace CVAL0 {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL0), 16, 0> CAPTVAL0;
}  // namespace CVAL0

// Capture Value 0 Cycle Register
namespace CVAL0CYC {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL0CYC), 4, 0> CVAL0CYC;
}  // namespace CVAL0CYC

// Capture Value 1 Register
namespace CVAL1 {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL1), 16, 0> CAPTVAL1;
}  // namespace CVAL1

// Capture Value 1 Cycle Register
namespace CVAL1CYC {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL1CYC), 4, 0> CVAL1CYC;
}  // namespace CVAL1CYC

// Capture Value 2 Register
namespace CVAL2 {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL2), 16, 0> CAPTVAL2;
}  // namespace CVAL2

// Capture Value 2 Cycle Register
namespace CVAL2CYC {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL2CYC), 4, 0> CVAL2CYC;
}  // namespace CVAL2CYC

// Capture Value 3 Register
namespace CVAL3 {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL3), 16, 0> CAPTVAL3;
}  // namespace CVAL3

// Capture Value 3 Cycle Register
namespace CVAL3CYC {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL3CYC), 4, 0> CVAL3CYC;
}  // namespace CVAL3CYC

// Capture Value 4 Register
namespace CVAL4 {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL4), 16, 0> CAPTVAL4;
}  // namespace CVAL4

// Capture Value 4 Cycle Register
namespace CVAL4CYC {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL4CYC), 4, 0> CVAL4CYC;
}  // namespace CVAL4CYC

// Capture Value 5 Register
namespace CVAL5 {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL5), 16, 0> CAPTVAL5;
}  // namespace CVAL5

// Capture Value 5 Cycle Register
namespace CVAL5CYC {
template <size_t Index>
constexpr SM_Reg<Index, regs::constify(&PWM_Layout::SM_Layout::CVAL5CYC), 4, 0> CVAL5CYC;
}  // namespace CVAL5CYC

}  // namespace SM

// Output Enable Register
namespace OUTEN {
constexpr PWM4_Reg<&PWM_Layout::OUTEN, 4, 8> PWMA_EN;
constexpr PWM4_Reg<&PWM_Layout::OUTEN, 4, 4> PWMB_EN;
constexpr PWM4_Reg<&PWM_Layout::OUTEN, 4, 0> PWMX_EN;
}  // namespace OUTEN

// Mask Register
namespace MASK {
// TODO: Is this the correct way?
constexpr uint16_t kWO = 0xf000;

constexpr PWM4_Reg<&PWM_Layout::MASK, 4, 12, kWO, true> UPDATE_MASK;                    // Update Mask Bits Immediately
constexpr PWM4_Reg<&PWM_Layout::MASK, 4,  8, regs::shiftedMask16<4, 8>() | kWO> MASKA;  // PWM_A Masks
constexpr PWM4_Reg<&PWM_Layout::MASK, 4,  4, regs::shiftedMask16<4, 4>() | kWO> MASKB;  // PWM_B Masks
constexpr PWM4_Reg<&PWM_Layout::MASK, 4,  0, regs::shiftedMask16<4, 0>() | kWO> MASKX;  // PWM_X Masks
}  // namespace MASK

// Software Controlled Output Register
namespace SWCOUT {
constexpr PWM4_Reg<&PWM_Layout::SWCOUT, 1, 7> SM3OUT23;
constexpr PWM4_Reg<&PWM_Layout::SWCOUT, 1, 6> SM3OUT45;
constexpr PWM4_Reg<&PWM_Layout::SWCOUT, 1, 5> SM2OUT23;
constexpr PWM4_Reg<&PWM_Layout::SWCOUT, 1, 4> SM2OUT45;
constexpr PWM4_Reg<&PWM_Layout::SWCOUT, 1, 3> SM1OUT23;
constexpr PWM4_Reg<&PWM_Layout::SWCOUT, 1, 2> SM1OUT45;
constexpr PWM4_Reg<&PWM_Layout::SWCOUT, 1, 1> SM0OUT23;
constexpr PWM4_Reg<&PWM_Layout::SWCOUT, 1, 0> SM0OUT45;
}  // namespace SWCOUT

// PWM Source Select Register
namespace DTSRCSEL {
constexpr PWM4_Reg<&PWM_Layout::DTSRCSEL, 2, 14> SM3SEL23;
constexpr PWM4_Reg<&PWM_Layout::DTSRCSEL, 2, 12> SM3SEL45;
constexpr PWM4_Reg<&PWM_Layout::DTSRCSEL, 2, 10> SM2SEL23;
constexpr PWM4_Reg<&PWM_Layout::DTSRCSEL, 2,  8> SM2SEL45;
constexpr PWM4_Reg<&PWM_Layout::DTSRCSEL, 2,  6> SM1SEL23;
constexpr PWM4_Reg<&PWM_Layout::DTSRCSEL, 2,  4> SM1SEL45;
constexpr PWM4_Reg<&PWM_Layout::DTSRCSEL, 2,  2> SM0SEL23;
constexpr PWM4_Reg<&PWM_Layout::DTSRCSEL, 2,  0> SM0SEL45;
}  // namespace DTSRCSEL

// Master Control Register
namespace MCTRL {
constexpr PWM4_Reg<&PWM_Layout::MCTRL, 4, 12> IPOL;
constexpr PWM4_Reg<&PWM_Layout::MCTRL, 4,  8> RUN;
constexpr PWM4_Reg<&PWM_Layout::MCTRL, 4,  4> CLDOK;
constexpr PWM4_Reg<&PWM_Layout::MCTRL, 4,  0> LDOK;
}  // namespace MCTRL

// Master Control 2 Register
namespace MCTRL2 {
constexpr PWM4_Reg<&PWM_Layout::MCTRL2, 2, 0> MONPLL;
}  // namespace MCTRL2

// Fault Control Register
namespace FCTRL {
constexpr PWM4_Reg<&PWM_Layout::FCTRL, 4, 12> FLVL;
constexpr PWM4_Reg<&PWM_Layout::FCTRL, 4,  8> FAUTO;
constexpr PWM4_Reg<&PWM_Layout::FCTRL, 4,  4> FSAFE;
constexpr PWM4_Reg<&PWM_Layout::FCTRL, 4,  0> FIE;
}  // namespace FCTRL

// Fault Status Register
namespace FSTS {
constexpr uint16_t kW1C = 0x000f;

constexpr PWM4_Reg<&PWM_Layout::FSTS, 4, 12, regs::shiftedMask16<4, 12>() | kW1C> FHALF;
constexpr PWM4_Reg<regs::constify(&PWM_Layout::FSTS), 4,  8> FFPIN;
constexpr PWM4_Reg<&PWM_Layout::FSTS, 4,  4, regs::shiftedMask16<4,  4>() | kW1C> FFULL;
constexpr PWM4_Reg<&PWM_Layout::FSTS, 4,  0, kW1C> FFLAG;
}  // namespace FSTS

// Fault Filter Register
namespace FFILT {
constexpr PWM4_Reg<&PWM_Layout::FFILT, 1, 15> GSTR;
constexpr PWM4_Reg<&PWM_Layout::FFILT, 3,  8> FILT_CNT;
constexpr PWM4_Reg<&PWM_Layout::FFILT, 8,  0> FILT_PER;
}  // namespace FFILT

// Fault Test Register
namespace FTST {
constexpr PWM4_Reg<&PWM_Layout::FTST, 1, 0> FTEST;
}  // namespace FTST

// Fault Control 2 Register
namespace FCTRL2 {
constexpr PWM4_Reg<&PWM_Layout::FCTRL2, 4, 0> NOCOMB;
}  // namespace FCTRL2

}  // namespace PWM4

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
