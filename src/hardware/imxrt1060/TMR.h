// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// TMR.h defines all the TMR registers.
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
constexpr size_t kTMR_CHANNEL_count = 4;

// Structure type to access the Quad Timer (TMR) registers.
//
// Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_TMR.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct TMR_Layout {
  struct CHANNEL_Layout {                          /* offset: 0x0, array step: 0x20 */
    volatile uint16_t COMP1;                       /**< Timer Channel Compare Register 1, array offset: 0x0, array step: 0x20 */
    volatile uint16_t COMP2;                       /**< Timer Channel Compare Register 2, array offset: 0x2, array step: 0x20 */
    volatile uint16_t CAPT;                        /**< Timer Channel Capture Register, array offset: 0x4, array step: 0x20 */
    volatile uint16_t LOAD;                        /**< Timer Channel Load Register, array offset: 0x6, array step: 0x20 */
    volatile uint16_t HOLD;                        /**< Timer Channel Hold Register, array offset: 0x8, array step: 0x20 */
    volatile uint16_t CNTR;                        /**< Timer Channel Counter Register, array offset: 0xA, array step: 0x20 */
    volatile uint16_t CTRL;                        /**< Timer Channel Control Register, array offset: 0xC, array step: 0x20 */
    volatile uint16_t SCTRL;                       /**< Timer Channel Status and Control Register, array offset: 0xE, array step: 0x20 */
    volatile uint16_t CMPLD1;                      /**< Timer Channel Comparator Load Register 1, array offset: 0x10, array step: 0x20 */
    volatile uint16_t CMPLD2;                      /**< Timer Channel Comparator Load Register 2, array offset: 0x12, array step: 0x20 */
    volatile uint16_t CSCTRL;                      /**< Timer Channel Comparator Status and Control Register, array offset: 0x14, array step: 0x20 */
    volatile uint16_t FILT;                        /**< Timer Channel Input Filter Register, array offset: 0x16, array step: 0x20 */
    volatile uint16_t DMA;                         /**< Timer Channel DMA Enable Register, array offset: 0x18, array step: 0x20 */
    uint8_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[4];
    volatile uint16_t ENBL;                        /**< Timer Channel Enable Register, array offset: 0x1E, array step: 0x20, valid indices: [0] */
  } CHANNEL[kTMR_CHANNEL_count];
};

constexpr size_t    kTMR_size  = 0x80;
constexpr uintptr_t kTMR1_base = 0x401DC000;
constexpr uintptr_t kTMR2_base = 0x401E0000;
constexpr uintptr_t kTMR3_base = 0x401E4000;
constexpr uintptr_t kTMR4_base = 0x401E8000;

namespace TMR1 {
constexpr regs::RegGroup<TMR_Layout, kTMR_size, kTMR1_base> group;
}  // namespace TMR1

namespace TMR2 {
constexpr regs::RegGroup<TMR_Layout, kTMR_size, kTMR2_base> group;
}  // namespace TMR2

namespace TMR3 {
constexpr regs::RegGroup<TMR_Layout, kTMR_size, kTMR3_base> group;
}  // namespace TMR3

namespace TMR4 {
constexpr regs::RegGroup<TMR_Layout, kTMR_size, kTMR4_base> group;
}  // namespace TMR4

namespace TMR1 {

template <size_t Index,
          typename = std::enable_if_t<(Index < kTMR_CHANNEL_count)>>
constexpr uintptr_t ChannelBase() {
  return kTMR1_base + offsetof(TMR_Layout, CHANNEL) +
         Index*sizeof(TMR_Layout::CHANNEL_Layout);
}

template <size_t Index, auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint16_t, Bits, Shift>()>
using CHANNEL_Reg =
    regs::Reg16<ChannelBase<Index>(), TMR_Layout::CHANNEL_Layout, Member, 0,
                Bits, Shift, AssignMask>;

namespace CHANNEL {

// Timer Channel Control Register
namespace CTRL {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 3, 13> CM;       // Count Mode
    // 0b000..No operation
    // 0b001..Count rising edges of primary sourceRising edges are counted only when SCTRL[IPS] = 0. Falling edges
    //        are counted when SCTRL[IPS] = 1. If the primary count source is IP bus clock divide by 1, only rising
    //        edges are counted regardless of the value of SCTRL[IPS].
    // 0b010..Count rising and falling edges of primary sourceIP bus clock divide by 1 cannot be used as a primary count source in edge count mode.
    // 0b011..Count rising edges of primary source while secondary input high active
    // 0b100..Quadrature count mode, uses primary and secondary sources
    // 0b101..Count rising edges of primary source; secondary source specifies directionRising edges are counted only
    //        when SCTRL[IPS] = 0. Falling edges are counted when SCTRL[IPS] = 1.
    // 0b110..Edge of secondary source triggers primary count until compare
    // 0b111..Cascaded counter mode (up/down)The primary count source must be set to one of the counter outputs.
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 4,  9> PCS;      // Primary Count Source
    // 0b0000..Counter 0 input pin
    // 0b0001..Counter 1 input pin
    // 0b0010..Counter 2 input pin
    // 0b0011..Counter 3 input pin
    // 0b0100..Counter 0 output
    // 0b0101..Counter 1 output
    // 0b0110..Counter 2 output
    // 0b0111..Counter 3 output
    // 0b1000..IP bus clock divide by 1 prescaler
    // 0b1001..IP bus clock divide by 2 prescaler
    // 0b1010..IP bus clock divide by 4 prescaler
    // 0b1011..IP bus clock divide by 8 prescaler
    // 0b1100..IP bus clock divide by 16 prescaler
    // 0b1101..IP bus clock divide by 32 prescaler
    // 0b1110..IP bus clock divide by 64 prescaler
    // 0b1111..IP bus clock divide by 128 prescaler
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 2,  7> SCS;      // Secondary Count Source
    // 0b00..Counter 0 input pin
    // 0b01..Counter 1 input pin
    // 0b10..Counter 2 input pin
    // 0b11..Counter 3 input pin
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 1,  6> ONCE;     // Count Once
    // 0b0..Count repeatedly.
    // 0b1..Count until compare and then stop. If counting up, a successful compare occurs when the counter reaches a
    //      COMP1 value. If counting down, a successful compare occurs when the counter reaches a COMP2 value. When
    //      output mode $4 is used, the counter re-initializes after reaching the COMP1 value, continues to count to
    //      the COMP2 value, and then stops.
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 1,  5> LENGTH;   // Count Length
    // 0b0..Count until roll over at $FFFF and continue from $0000.
    // 0b1..Count until compare, then re-initialize. If counting up, a successful compare occurs when the counter
    //      reaches a COMP1 value. If counting down, a successful compare occurs when the counter reaches a COMP2 value.
    //      When output mode $4 is used, alternating values of COMP1 and COMP2 are used to generate successful
    //      comparisons. For example, the counter counts until a COMP1 value is reached, re-initializes, counts until COMP2
    //      value is reached, re-initializes, counts until COMP1 value is reached, and so on.
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 1,  4> DIR;      // Count Direction
    // 0b0..Count up.
    // 0b1..Count down.
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 1,  3> COINIT;   // Co-Channel Initialization
    // 0b0..Co-channel counter/timers cannot force a re-initialization of this counter/timer
    // 0b1..Co-channel counter/timers may force a re-initialization of this counter/timer
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 3,  0> OUTMODE;  // Output Mode
    // 0b000..Asserted while counter is active
    // 0b001..Clear OFLAG output on successful compare
    // 0b010..Set OFLAG output on successful compare
    // 0b011..Toggle OFLAG output on successful compare
    // 0b100..Toggle OFLAG output using alternating compare registers
    // 0b101..Set on compare, cleared on secondary source input edge
    // 0b110..Set on compare, cleared on counter rollover
    // 0b111..Enable gated clock output while counter is active
}  // namespace CTRL

// Timer Channel Status and Control Register
namespace SCTRL {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1, 15> TCF;           // Timer Compare Flag
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1, 14> TCFIE;         // Timer Compare Flag Interrupt Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1, 13> TOF;           // Timer Overflow Flag
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1, 12> TOFIE;         // Timer Overflow Flag Interrupt Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1, 11> IEF;           // Input Edge Flag
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1, 10> IEFIE;         // Input Edge Flag Interrupt Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  9> IPS;           // Input Polarity Select
template <size_t Index>
constexpr CHANNEL_Reg<Index, regs::constify(&TMR_Layout::CHANNEL_Layout::SCTRL), 1,  8> INPUT;         // External Input Signal
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 2,  6> CAPTURE_MODE;  // Input Capture Mode
    // 0b00..Capture function is disabled
    // 0b01..Load capture register on rising edge (when IPS=0) or falling edge (when IPS=1) of input
    // 0b10..Load capture register on falling edge (when IPS=0) or rising edge (when IPS=1) of input
    // 0b11..Load capture register on both edges of input
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  5> MSTR;          // Master Mode
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  4> EEOF;          // Enable External OFLAG Force
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  3> VAL;           // Forced OFLAG Value
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  2> FORCE;         // Force OFLAG Output
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  1> OPS;           // Output Polarity Select
    // 0b0..True polarity.
    // 0b1..Inverted polarity.
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  0> OEN;           // Output Enable
    // 0b0..The external pin is configured as an input.
    // 0b1..The OFLAG output signal is driven on the external pin. Other timer groups using this external pin as
    //      their input see the driven value. The polarity of the signal is determined by OPS.
}  // namespace SCTRL

// Timer Channel Comparator Status and Control Register
namespace CSCTRL {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 2, 14> DBG_EN;    // Debug Actions Enable
    // 0b00..Continue with normal operation during debug mode. (default)
    // 0b01..Halt TMR counter during debug mode.
    // 0b10..Force TMR output to logic 0 (prior to consideration of SCTRL[OPS]).
    // 0b11..Both halt counter and force output to 0 during debug mode.
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1, 13> FAULT;     // Fault Enable
    // 0b0..Fault function disabled.
    // 0b1..Fault function enabled.
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1, 12> ALT_LOAD;  // Alternative Load Enable
    // 0b0..Counter can be re-initialized only with the LOAD register.
    // 0b1..Counter can be re-initialized with the LOAD or CMPLD2 registers depending on count direction.
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1, 11> ROC;       // Reload on Capture
    // 0b0..Do not reload the counter on a capture event.
    // 0b1..Reload the counter on a capture event.
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1, 10> TCI;       // Triggered Count Initialization Control
    // 0b0..Stop counter upon receiving a second trigger event while still counting from the first trigger event.
    // 0b1..Reload the counter upon receiving a second trigger event while still counting from the first trigger event.
template <size_t Index>
constexpr CHANNEL_Reg<Index, regs::constify(&TMR_Layout::CHANNEL_Layout::CSCTRL), 1,  9> UP;        // Counting Direction Indicator
    // 0b0..The last count was in the DOWN direction.
    // 0b1..The last count was in the UP direction.
template <size_t Index>
constexpr CHANNEL_Reg<Index, regs::constify(&TMR_Layout::CHANNEL_Layout::CSCTRL), 1,  8> OFLAG;     // Output flag
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1,  7> TCF2EN;    // Timer Compare 2 Interrupt Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1,  6> TCF1EN;    // Timer Compare 1 Interrupt Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1,  5> TCF2;      // Timer Compare 2 Interrupt Flag
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1,  4> TCF1;      // Timer Compare 1 Interrupt Flag
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 2,  2> CL2;       // Compare Load Control 2
    // 0b00..Never preload
    // 0b01..Load upon successful compare with the value in COMP1
    // 0b10..Load upon successful compare with the value in COMP2
    // 0b11..Reserved
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 2,  0> CL1;       // Compare Load Control 1
    // 0b00..Never preload
    // 0b01..Load upon successful compare with the value in COMP1
    // 0b10..Load upon successful compare with the value in COMP2
    // 0b11..Reserved
}  // namespace CSCTRL

// Timer Channel Input Filter Register
namespace FILT {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::FILT, 3, 8> FILT_CNT;  // Input Filter Sample Count
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::FILT, 8, 0> FILT_PER;  // Input Filter Sample Period
}  // namespace FILT

// Timer Channel DMA Enable Register
namespace DMA {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::DMA, 1, 2> CMPLD2DE;  // Comparator Preload Register 2 DMA Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::DMA, 1, 1> CMPLD1DE;  // Comparator Preload Register 1 DMA Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::DMA, 1, 0> IEFDE;     // Input Edge Flag DMA Enable
}  // namespace DMA

// Timer Channel Enable Register
namespace ENBL {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::ENBL, 4, 0> ENBL;  // Timer Channel Enable
    // 0b0000..Timer channel is disabled.
    // 0b0001..Timer channel is enabled. (default)
}  // namespace ENBL

}  // namespace CHANNEL

}  // namespace TMR1

namespace TMR2 {

template <size_t Index,
          typename = std::enable_if_t<(Index < kTMR_CHANNEL_count)>>
constexpr uintptr_t ChannelBase() {
  return kTMR2_base + offsetof(TMR_Layout, CHANNEL) +
         Index*sizeof(TMR_Layout::CHANNEL_Layout);
}

template <size_t Index, auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint16_t, Bits, Shift>()>
using CHANNEL_Reg =
    regs::Reg16<ChannelBase<Index>(), TMR_Layout::CHANNEL_Layout, Member, 0,
                Bits, Shift, AssignMask>;

namespace CHANNEL {

// Timer Channel Control Register
namespace CTRL {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 3, 13> CM;       // Count Mode
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 4,  9> PCS;      // Primary Count Source
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 2,  7> SCS;      // Secondary Count Source
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 1,  6> ONCE;     // Count Once
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 1,  5> LENGTH;   // Count Length
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 1,  4> DIR;      // Count Direction
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 1,  3> COINIT;   // Co-Channel Initialization
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 3,  0> OUTMODE;  // Output Mode
}  // namespace CTRL

// Timer Channel Status and Control Register
namespace SCTRL {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1, 15> TCF;           // Timer Compare Flag
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1, 14> TCFIE;         // Timer Compare Flag Interrupt Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1, 13> TOF;           // Timer Overflow Flag
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1, 12> TOFIE;         // Timer Overflow Flag Interrupt Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1, 11> IEF;           // Input Edge Flag
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1, 10> IEFIE;         // Input Edge Flag Interrupt Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  9> IPS;           // Input Polarity Select
template <size_t Index>
constexpr CHANNEL_Reg<Index, regs::constify(&TMR_Layout::CHANNEL_Layout::SCTRL), 1,  8> INPUT;         // External Input Signal
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 2,  6> CAPTURE_MODE;  // Input Capture Mode
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  5> MSTR;          // Master Mode
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  4> EEOF;          // Enable External OFLAG Force
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  3> VAL;           // Forced OFLAG Value
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  2> FORCE;         // Force OFLAG Output
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  1> OPS;           // Output Polarity Select
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  0> OEN;           // Output Enable
}  // namespace SCTRL

// Timer Channel Comparator Status and Control Register
namespace CSCTRL {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 2, 14> DBG_EN;    // Debug Actions Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1, 13> FAULT;     // Fault Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1, 12> ALT_LOAD;  // Alternative Load Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1, 11> ROC;       // Reload on Capture
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1, 10> TCI;       // Triggered Count Initialization Control
template <size_t Index>
constexpr CHANNEL_Reg<Index, regs::constify(&TMR_Layout::CHANNEL_Layout::CSCTRL), 1,  9> UP;        // Counting Direction Indicator
template <size_t Index>
constexpr CHANNEL_Reg<Index, regs::constify(&TMR_Layout::CHANNEL_Layout::CSCTRL), 1,  8> OFLAG;     // Output flag
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1,  7> TCF2EN;    // Timer Compare 2 Interrupt Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1,  6> TCF1EN;    // Timer Compare 1 Interrupt Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1,  5> TCF2;      // Timer Compare 2 Interrupt Flag
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1,  4> TCF1;      // Timer Compare 1 Interrupt Flag
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 2,  2> CL2;       // Compare Load Control 2
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 2,  0> CL1;       // Compare Load Control 1
}  // namespace CSCTRL

// Timer Channel Input Filter Register
namespace FILT {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::FILT, 3, 8> FILT_CNT;  // Input Filter Sample Count
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::FILT, 8, 0> FILT_PER;  // Input Filter Sample Period
}  // namespace FILT

// Timer Channel DMA Enable Register
namespace DMA {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::DMA, 1, 2> CMPLD2DE;  // Comparator Preload Register 2 DMA Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::DMA, 1, 1> CMPLD1DE;  // Comparator Preload Register 1 DMA Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::DMA, 1, 0> IEFDE;     // Input Edge Flag DMA Enable
}  // namespace DMA

// Timer Channel Enable Register
namespace ENBL {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::ENBL, 4, 0> ENBL;  // Timer Channel Enable
}  // namespace ENBL

}  // namespace CHANNEL

}  // namespace TMR2

namespace TMR3 {

template <size_t Index,
          typename = std::enable_if_t<(Index < kTMR_CHANNEL_count)>>
constexpr uintptr_t ChannelBase() {
  return kTMR3_base + offsetof(TMR_Layout, CHANNEL) +
         Index*sizeof(TMR_Layout::CHANNEL_Layout);
}

template <size_t Index, auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint16_t, Bits, Shift>()>
using CHANNEL_Reg =
    regs::Reg16<ChannelBase<Index>(), TMR_Layout::CHANNEL_Layout, Member, 0,
                Bits, Shift, AssignMask>;

namespace CHANNEL {

// Timer Channel Control Register
namespace CTRL {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 3, 13> CM;       // Count Mode
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 4,  9> PCS;      // Primary Count Source
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 2,  7> SCS;      // Secondary Count Source
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 1,  6> ONCE;     // Count Once
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 1,  5> LENGTH;   // Count Length
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 1,  4> DIR;      // Count Direction
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 1,  3> COINIT;   // Co-Channel Initialization
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 3,  0> OUTMODE;  // Output Mode
}  // namespace CTRL

// Timer Channel Status and Control Register
namespace SCTRL {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1, 15> TCF;           // Timer Compare Flag
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1, 14> TCFIE;         // Timer Compare Flag Interrupt Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1, 13> TOF;           // Timer Overflow Flag
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1, 12> TOFIE;         // Timer Overflow Flag Interrupt Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1, 11> IEF;           // Input Edge Flag
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1, 10> IEFIE;         // Input Edge Flag Interrupt Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  9> IPS;           // Input Polarity Select
template <size_t Index>
constexpr CHANNEL_Reg<Index, regs::constify(&TMR_Layout::CHANNEL_Layout::SCTRL), 1,  8> INPUT;         // External Input Signal
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 2,  6> CAPTURE_MODE;  // Input Capture Mode
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  5> MSTR;          // Master Mode
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  4> EEOF;          // Enable External OFLAG Force
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  3> VAL;           // Forced OFLAG Value
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  2> FORCE;         // Force OFLAG Output
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  1> OPS;           // Output Polarity Select
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  0> OEN;           // Output Enable
}  // namespace SCTRL

// Timer Channel Comparator Status and Control Register
namespace CSCTRL {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 2, 14> DBG_EN;    // Debug Actions Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1, 13> FAULT;     // Fault Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1, 12> ALT_LOAD;  // Alternative Load Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1, 11> ROC;       // Reload on Capture
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1, 10> TCI;       // Triggered Count Initialization Control
template <size_t Index>
constexpr CHANNEL_Reg<Index, regs::constify(&TMR_Layout::CHANNEL_Layout::CSCTRL), 1,  9> UP;        // Counting Direction Indicator
template <size_t Index>
constexpr CHANNEL_Reg<Index, regs::constify(&TMR_Layout::CHANNEL_Layout::CSCTRL), 1,  8> OFLAG;     // Output flag
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1,  7> TCF2EN;    // Timer Compare 2 Interrupt Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1,  6> TCF1EN;    // Timer Compare 1 Interrupt Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1,  5> TCF2;      // Timer Compare 2 Interrupt Flag
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1,  4> TCF1;      // Timer Compare 1 Interrupt Flag
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 2,  2> CL2;       // Compare Load Control 2
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 2,  0> CL1;       // Compare Load Control 1
}  // namespace CSCTRL

// Timer Channel Input Filter Register
namespace FILT {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::FILT, 3, 8> FILT_CNT;  // Input Filter Sample Count
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::FILT, 8, 0> FILT_PER;  // Input Filter Sample Period
}  // namespace FILT

// Timer Channel DMA Enable Register
namespace DMA {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::DMA, 1, 2> CMPLD2DE;  // Comparator Preload Register 2 DMA Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::DMA, 1, 1> CMPLD1DE;  // Comparator Preload Register 1 DMA Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::DMA, 1, 0> IEFDE;     // Input Edge Flag DMA Enable
}  // namespace DMA

// Timer Channel Enable Register
namespace ENBL {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::ENBL, 4, 0> ENBL;  // Timer Channel Enable
}  // namespace ENBL

}  // namespace CHANNEL

}  // namespace TMR3

namespace TMR4 {

template <size_t Index,
          typename = std::enable_if_t<(Index < kTMR_CHANNEL_count)>>
constexpr uintptr_t ChannelBase() {
  return kTMR4_base + offsetof(TMR_Layout, CHANNEL) +
         Index*sizeof(TMR_Layout::CHANNEL_Layout);
}

template <size_t Index, auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint16_t, Bits, Shift>()>
using CHANNEL_Reg =
    regs::Reg16<ChannelBase<Index>(), TMR_Layout::CHANNEL_Layout, Member, 0,
                Bits, Shift, AssignMask>;

namespace CHANNEL {

// Timer Channel Control Register
namespace CTRL {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 3, 13> CM;       // Count Mode
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 4,  9> PCS;      // Primary Count Source
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 2,  7> SCS;      // Secondary Count Source
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 1,  6> ONCE;     // Count Once
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 1,  5> LENGTH;   // Count Length
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 1,  4> DIR;      // Count Direction
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 1,  3> COINIT;   // Co-Channel Initialization
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CTRL, 3,  0> OUTMODE;  // Output Mode
}  // namespace CTRL

// Timer Channel Status and Control Register
namespace SCTRL {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1, 15> TCF;           // Timer Compare Flag
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1, 14> TCFIE;         // Timer Compare Flag Interrupt Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1, 13> TOF;           // Timer Overflow Flag
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1, 12> TOFIE;         // Timer Overflow Flag Interrupt Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1, 11> IEF;           // Input Edge Flag
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1, 10> IEFIE;         // Input Edge Flag Interrupt Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  9> IPS;           // Input Polarity Select
template <size_t Index>
constexpr CHANNEL_Reg<Index, regs::constify(&TMR_Layout::CHANNEL_Layout::SCTRL), 1,  8> INPUT;         // External Input Signal
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 2,  6> CAPTURE_MODE;  // Input Capture Mode
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  5> MSTR;          // Master Mode
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  4> EEOF;          // Enable External OFLAG Force
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  3> VAL;           // Forced OFLAG Value
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  2> FORCE;         // Force OFLAG Output
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  1> OPS;           // Output Polarity Select
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::SCTRL, 1,  0> OEN;           // Output Enable
}  // namespace SCTRL

// Timer Channel Comparator Status and Control Register
namespace CSCTRL {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 2, 14> DBG_EN;    // Debug Actions Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1, 13> FAULT;     // Fault Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1, 12> ALT_LOAD;  // Alternative Load Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1, 11> ROC;       // Reload on Capture
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1, 10> TCI;       // Triggered Count Initialization Control
template <size_t Index>
constexpr CHANNEL_Reg<Index, regs::constify(&TMR_Layout::CHANNEL_Layout::CSCTRL), 1,  9> UP;        // Counting Direction Indicator
template <size_t Index>
constexpr CHANNEL_Reg<Index, regs::constify(&TMR_Layout::CHANNEL_Layout::CSCTRL), 1,  8> OFLAG;     // Output flag
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1,  7> TCF2EN;    // Timer Compare 2 Interrupt Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1,  6> TCF1EN;    // Timer Compare 1 Interrupt Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1,  5> TCF2;      // Timer Compare 2 Interrupt Flag
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 1,  4> TCF1;      // Timer Compare 1 Interrupt Flag
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 2,  2> CL2;       // Compare Load Control 2
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::CSCTRL, 2,  0> CL1;       // Compare Load Control 1
}  // namespace CSCTRL

// Timer Channel Input Filter Register
namespace FILT {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::FILT, 3, 8> FILT_CNT;  // Input Filter Sample Count
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::FILT, 8, 0> FILT_PER;  // Input Filter Sample Period
}  // namespace FILT

// Timer Channel DMA Enable Register
namespace DMA {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::DMA, 1, 2> CMPLD2DE;  // Comparator Preload Register 2 DMA Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::DMA, 1, 1> CMPLD1DE;  // Comparator Preload Register 1 DMA Enable
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::DMA, 1, 0> IEFDE;     // Input Edge Flag DMA Enable
}  // namespace DMA

// Timer Channel Enable Register
namespace ENBL {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &TMR_Layout::CHANNEL_Layout::ENBL, 4, 0> ENBL;  // Timer Channel Enable
}  // namespace ENBL

}  // namespace CHANNEL

}  // namespace TMR4

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
