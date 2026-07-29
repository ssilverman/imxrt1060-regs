// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// ENC.h defines all the ENC registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the Quadrature Decoder (QDC) registers.
//
// Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_ENC.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct ENC_Layout {
  volatile uint16_t CTRL;                              /**< Control Register, offset: 0x0 */
  volatile uint16_t FILT;                              /**< Input Filter Register, offset: 0x2 */
  volatile uint16_t WTR;                               /**< Watchdog Timeout Register, offset: 0x4 */
  volatile uint16_t POSD;                              /**< Position Difference Counter Register, offset: 0x6 */
  const volatile uint16_t POSDH;                       /**< Position Difference Hold Register, offset: 0x8 */
  volatile uint16_t REV;                               /**< Revolution Counter Register, offset: 0xA */
  const volatile uint16_t REVH;                        /**< Revolution Hold Register, offset: 0xC */
  volatile uint16_t UPOS;                              /**< Upper Position Counter Register, offset: 0xE */
  volatile uint16_t LPOS;                              /**< Lower Position Counter Register, offset: 0x10 */
  const volatile uint16_t UPOSH;                       /**< Upper Position Hold Register, offset: 0x12 */
  const volatile uint16_t LPOSH;                       /**< Lower Position Hold Register, offset: 0x14 */
  volatile uint16_t UINIT;                             /**< Upper Initialization Register, offset: 0x16 */
  volatile uint16_t LINIT;                             /**< Lower Initialization Register, offset: 0x18 */
  const volatile uint16_t IMR;                         /**< Input Monitor Register, offset: 0x1A */
  volatile uint16_t TST;                               /**< Test Register, offset: 0x1C */
  volatile uint16_t CTRL2;                             /**< Control 2 Register, offset: 0x1E */
  volatile uint16_t UMOD;                              /**< Upper Modulus Register, offset: 0x20 */
  volatile uint16_t LMOD;                              /**< Lower Modulus Register, offset: 0x22 */
  volatile uint16_t UCOMP;                             /**< Upper Position Compare Register, offset: 0x24 */
  volatile uint16_t LCOMP;                             /**< Lower Position Compare Register, offset: 0x26 */
};

constexpr size_t    kENC_size  = 0x28;
constexpr uintptr_t kENC1_base = 0x403C8000;
constexpr uintptr_t kENC2_base = 0x403CC000;
constexpr uintptr_t kENC3_base = 0x403D0000;
constexpr uintptr_t kENC4_base = 0x403D4000;

namespace ENC1 {
constexpr regs::RegGroup<ENC_Layout, kENC_size, kENC1_base> group;
}  // namespace ENC1

namespace ENC2 {
constexpr regs::RegGroup<ENC_Layout, kENC_size, kENC2_base> group;
}  // namespace ENC2

namespace ENC3 {
constexpr regs::RegGroup<ENC_Layout, kENC_size, kENC3_base> group;
}  // namespace ENC3

namespace ENC4 {
constexpr regs::RegGroup<ENC_Layout, kENC_size, kENC4_base> group;
}  // namespace ENC4

namespace ENC1 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint16_t, Bits, Shift>()>
using ENC1_Reg =
    regs::Reg16<kENC1_base, ENC_Layout, Member, 0, Bits, Shift, AssignMask>;

// ENC1 Control Register
namespace CTRL {
constexpr uint16_t kW1C = 0x8112;

constexpr ENC1_Reg<&ENC_Layout::CTRL, 1, 15, kW1C> HIRQ;    // HOME Signal Transition Interrupt Request
    // 0b0..No transition on the HOME signal has occurred
    // 0b1..A transition on the HOME signal has occurred
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1, 14, (uint16_t{0x1} << 14) | kW1C> HIE;     // HOME Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1, 13, (uint16_t{0x1} << 13) | kW1C> HIP;     // Enable HOME to Initialize Position Counters UPOS and LPOS
    // 0b0..No action
    // 0b1..HOME signal initializes the position counter
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1, 12, (uint16_t{0x1} << 12) | kW1C> HNE;     // Use Negative Edge of HOME Input
    // 0b0..Use positive-going edge-to-trigger initialization of position counters UPOS and LPOS
    // 0b1..Use negative-going edge-to-trigger initialization of position counters UPOS and LPOS
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1, 11, (uint16_t{0x1} << 11) | kW1C> SWIP;    // Software-Triggered Initialization of Position Counters UPOS and LPOS
    // 0b0..No action
    // 0b1..Initialize position counter (using upper and lower initialization registers, UINIT and LINIT)
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1, 10, (uint16_t{0x1} << 10) | kW1C> REV;     // Enable Reverse Direction Counting
    // 0b0..Count normally
    // 0b1..Count in the reverse direction
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1,  9, (uint16_t{0x1} <<  9) | kW1C> PH1;     // Enable Signal Phase Count Mode
    // 0b0..Use the standard quadrature decoder, where PHASEA and PHASEB represent a two-phase quadrature signal.
    // 0b1..Bypass the quadrature decoder. A positive transition of the PHASEA input generates a count signal. The
    //      PHASEB input and the REV bit control the counter direction: If CTRL[REV] = 0, PHASEB = 0, then count up If
    //      CTRL[REV] = 1, PHASEB = 1, then count up If CTRL[REV] = 0, PHASEB = 1, then count down If CTRL[REV] = 1,
    //      PHASEB = 0, then count down
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1,  8, kW1C> XIRQ;    // INDEX Pulse Interrupt Request
    // 0b0..INDEX pulse has not occurred
    // 0b1..INDEX pulse has occurred
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1,  7, (uint16_t{0x1} <<  7) | kW1C> XIE;     // INDEX Pulse Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1,  6, (uint16_t{0x1} <<  6) | kW1C> XIP;     // INDEX Triggered Initialization of Position Counters UPOS and LPOS
    // 0b0..INDEX pulse does not initialize the position counter
    // 0b1..INDEX pulse initializes the position counter
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1,  5, (uint16_t{0x1} <<  5) | kW1C> XNE;     // Use Negative Edge of INDEX Pulse
    // 0b0..Use positive edge of INDEX pulse
    // 0b1..Use negative edge of INDEX pulse
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1,  4, kW1C> DIRQ;    // Watchdog Timeout Interrupt Request
    // 0b0..No Watchdog timeout interrupt has occurred
    // 0b1..Watchdog timeout interrupt has occurred
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1,  3, (uint16_t{0x1} <<  3) | kW1C> DIE;     // Watchdog Timeout Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1,  2, (uint16_t{0x1} <<  2) | kW1C> WDE;     // Watchdog Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1,  1, kW1C> CMPIRQ;  // Compare Interrupt Request
    // 0b0..No match has occurred (the counter does not match the COMP value)
    // 0b1..COMP match has occurred (the counter matches the COMP value)
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1,  0, (uint16_t{0x1} <<  0) | kW1C> CMPIE;   // Compare Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
}  // namespace CTRL

// ENC1 Input Filter Register
namespace FILT {
constexpr ENC1_Reg<&ENC_Layout::FILT, 3, 13> FILT_PRSC;  // prescaler divide IPbus clock to FILT clk
constexpr ENC1_Reg<&ENC_Layout::FILT, 3,  8> FILT_CNT;   // Input Filter Sample Count
constexpr ENC1_Reg<&ENC_Layout::FILT, 8,  0> FILT_PER;   // Input Filter Sample Period
}  // namespace FILT

// ENC1 Watchdog Timeout Register
namespace WTR {
constexpr ENC1_Reg<&ENC_Layout::WTR, 16, 0> WDOG;  // WDOG
}  // namespace WTR

// ENC1 Position Difference Counter Register
namespace POSD {
constexpr ENC1_Reg<&ENC_Layout::POSD, 16, 0> POSD;  // POSD
}  // namespace POSD

// ENC1 Position Difference Hold Register
namespace POSDH {
constexpr ENC1_Reg<&ENC_Layout::POSDH, 16, 0> POSDH;  // POSDH
}  // namespace POSDH

// ENC1 Revolution Counter Register
namespace REV {
constexpr ENC1_Reg<&ENC_Layout::REV, 16, 0> REV;  // REV
}  // namespace REV

// ENC1 Revolution Hold Register
namespace REVH {
constexpr ENC1_Reg<&ENC_Layout::REVH, 16, 0> REVH;  // REVH
}  // namespace REVH

// ENC1 Upper Position Counter Register
namespace UPOS {
constexpr ENC1_Reg<&ENC_Layout::UPOS, 16, 0> POS;  // POS
}  // namespace UPOS

// ENC1 Lower Position Counter Register
namespace LPOS {
constexpr ENC1_Reg<&ENC_Layout::LPOS, 16, 0> POS;  // POS
}  // namespace LPOS

// ENC1 Upper Position Hold Register
namespace UPOSH {
constexpr ENC1_Reg<&ENC_Layout::UPOSH, 16, 0> POSH;  // POSH
}  // namespace UPOSH

// ENC1 Lower Position Hold Register
namespace LPOSH {
constexpr ENC1_Reg<&ENC_Layout::LPOSH, 16, 0> POSH;  // POSH
}  // namespace LPOSH

// ENC1 Upper Initialization Register
namespace UINIT {
constexpr ENC1_Reg<&ENC_Layout::UINIT, 16, 0> INIT;  // INIT
}  // namespace UINIT

// ENC1 Lower Initialization Register
namespace LINIT {
constexpr ENC1_Reg<&ENC_Layout::LINIT, 16, 0> INIT;  // INIT
}  // namespace LINIT

// ENC1 Input Monitor Register
namespace IMR {
constexpr ENC1_Reg<&ENC_Layout::IMR, 1, 7> FPHA;
constexpr ENC1_Reg<&ENC_Layout::IMR, 1, 6> FPHB;
constexpr ENC1_Reg<&ENC_Layout::IMR, 1, 5> FIND;
constexpr ENC1_Reg<&ENC_Layout::IMR, 1, 4> FHOM;
constexpr ENC1_Reg<&ENC_Layout::IMR, 1, 3> PHA;
constexpr ENC1_Reg<&ENC_Layout::IMR, 1, 2> PHB;
constexpr ENC1_Reg<&ENC_Layout::IMR, 1, 1> INDEX;
constexpr ENC1_Reg<&ENC_Layout::IMR, 1, 0> HOME;
}  // namespace IMR

// ENC1 Test Register
namespace TST {
constexpr ENC1_Reg<&ENC_Layout::TST, 1, 15> TEN;  // Test Mode Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr ENC1_Reg<&ENC_Layout::TST, 1, 14> TCE;  // Test Counter Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr ENC1_Reg<&ENC_Layout::TST, 1, 13> QDN;  // Quadrature Decoder Negative Signal
    // 0b0..Generates a positive quadrature decoder signal
    // 0b1..Generates a negative quadrature decoder signal
constexpr ENC1_Reg<&ENC_Layout::TST, 5,  8> TEST_PERIOD;
constexpr ENC1_Reg<&ENC_Layout::TST, 8,  0> TEST_COUNT;
}  // namespace TST

// ENC1 Control 2 Register
namespace CTRL2 {
constexpr uint16_t kW1C = 0x00a0;

constexpr ENC1_Reg<&ENC_Layout::CTRL2, 1, 9, (uint16_t{0x1} << 9) | kW1C> OUTCTL;  // Output Control
    // 0b0..POSMATCH pulses when a match occurs between the position counters (POS) and the corresponding compare value (COMP )
    // 0b1..POSMATCH pulses when the UPOS, LPOS, REV, or POSD registers are read
constexpr ENC1_Reg<&ENC_Layout::CTRL2, 1, 8, (uint16_t{0x1} << 8) | kW1C> REVMOD;  // Revolution Counter Modulus Enable
    // 0b0..Use INDEX pulse to increment/decrement revolution counter (REV)
    // 0b1..Use modulus counting roll-over/under to increment/decrement revolution counter (REV)
constexpr ENC1_Reg<&ENC_Layout::CTRL2, 1, 7, kW1C> ROIRQ;   // Roll-over Interrupt Request
    // 0b0..No roll-over has occurred
    // 0b1..Roll-over has occurred
constexpr ENC1_Reg<&ENC_Layout::CTRL2, 1, 6, (uint16_t{0x1} << 6) | kW1C> ROIE;    // Roll-over Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr ENC1_Reg<&ENC_Layout::CTRL2, 1, 5, kW1C> RUIRQ;   // Roll-under Interrupt Request
    // 0b0..No roll-under has occurred
    // 0b1..Roll-under has occurred
constexpr ENC1_Reg<&ENC_Layout::CTRL2, 1, 4, (uint16_t{0x1} << 4) | kW1C> RUIE;    // Roll-under Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr ENC1_Reg<regs::constify(&ENC_Layout::CTRL2), 1, 3> DIR;     // Count Direction Flag
    // 0b0..Last count was in the down direction
    // 0b1..Last count was in the up direction
constexpr ENC1_Reg<&ENC_Layout::CTRL2, 1, 2, (uint16_t{0x1} << 2) | kW1C> MOD;     // Enable Modulo Counting
    // 0b0..Disable modulo counting
    // 0b1..Enable modulo counting
constexpr ENC1_Reg<&ENC_Layout::CTRL2, 1, 1, (uint16_t{0x1} << 1) | kW1C> UPDPOS;  // Update Position Registers
    // 0b0..No action for POSD, REV, UPOS and LPOS registers on rising edge of TRIGGER
    // 0b1..Clear POSD, REV, UPOS and LPOS registers on rising edge of TRIGGER
constexpr ENC1_Reg<&ENC_Layout::CTRL2, 1, 0, (uint16_t{0x1} << 0) | kW1C> UPDHLD;  // Update Hold Registers
    // 0b0..Disable updates of hold registers on the rising edge of TRIGGER input signal
    // 0b1..Enable updates of hold registers on the rising edge of TRIGGER input signal
}  // namespace CTRL2

// ENC1 Upper Modulus Register
namespace UMOD {
constexpr ENC1_Reg<&ENC_Layout::UMOD, 16, 0> MOD;  // MOD
}  // namespace UMOD

// ENC1 Lower Modulus Register
namespace LMOD {
constexpr ENC1_Reg<&ENC_Layout::LMOD, 16, 0> MOD;  // MOD
}  // namespace LMOD

// ENC1 Upper Position Compare Register
namespace UCOMP {
constexpr ENC1_Reg<&ENC_Layout::UCOMP, 16, 0> COMP;  // COMP
}  // namespace UCOMP

// ENC1 Lower Position Compare Register
namespace LCOMP {
constexpr ENC1_Reg<&ENC_Layout::LCOMP, 16, 0> COMP;  // COMP
}  // namespace LCOMP

}  // namespace ENC1

namespace ENC2 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint16_t, Bits, Shift>()>
using ENC2_Reg =
    regs::Reg16<kENC2_base, ENC_Layout, Member, 0, Bits, Shift, AssignMask>;

// ENC2 Control Register
namespace CTRL {
constexpr uint16_t kW1C = 0x8112;

constexpr ENC2_Reg<&ENC_Layout::CTRL, 1, 15, kW1C> HIRQ;
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1, 14, (uint16_t{0x1} << 14) | kW1C> HIE;
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1, 13, (uint16_t{0x1} << 13) | kW1C> HIP;
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1, 12, (uint16_t{0x1} << 12) | kW1C> HNE;
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1, 11, (uint16_t{0x1} << 11) | kW1C> SWIP;
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1, 10, (uint16_t{0x1} << 10) | kW1C> REV;
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1,  9, (uint16_t{0x1} <<  9) | kW1C> PH1;
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1,  8, kW1C> XIRQ;
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1,  7, (uint16_t{0x1} <<  7) | kW1C> XIE;
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1,  6, (uint16_t{0x1} <<  6) | kW1C> XIP;
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1,  5, (uint16_t{0x1} <<  5) | kW1C> XNE;
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1,  4, kW1C> DIRQ;
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1,  3, (uint16_t{0x1} <<  3) | kW1C> DIE;
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1,  2, (uint16_t{0x1} <<  2) | kW1C> WDE;
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1,  1, kW1C> CMPIRQ;
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1,  0, (uint16_t{0x1} <<  0) | kW1C> CMPIE;
}  // namespace CTRL

// ENC2 Input Filter Register
namespace FILT {
constexpr ENC2_Reg<&ENC_Layout::FILT, 3, 13> FILT_PRSC;
constexpr ENC2_Reg<&ENC_Layout::FILT, 3,  8> FILT_CNT;
constexpr ENC2_Reg<&ENC_Layout::FILT, 8,  0> FILT_PER;
}  // namespace FILT

// ENC2 Watchdog Timeout Register
namespace WTR {
constexpr ENC2_Reg<&ENC_Layout::WTR, 16, 0> WDOG;
}  // namespace WTR

// ENC2 Position Difference Counter Register
namespace POSD {
constexpr ENC2_Reg<&ENC_Layout::POSD, 16, 0> POSD;
}  // namespace POSD

// ENC2 Position Difference Hold Register
namespace POSDH {
constexpr ENC2_Reg<&ENC_Layout::POSDH, 16, 0> POSDH;
}  // namespace POSDH

// ENC2 Revolution Counter Register
namespace REV {
constexpr ENC2_Reg<&ENC_Layout::REV, 16, 0> REV;
}  // namespace REV

// ENC2 Revolution Hold Register
namespace REVH {
constexpr ENC2_Reg<&ENC_Layout::REVH, 16, 0> REVH;
}  // namespace REVH

// ENC2 Upper Position Counter Register
namespace UPOS {
constexpr ENC2_Reg<&ENC_Layout::UPOS, 16, 0> POS;
}  // namespace UPOS

// ENC2 Lower Position Counter Register
namespace LPOS {
constexpr ENC2_Reg<&ENC_Layout::LPOS, 16, 0> POS;
}  // namespace LPOS

// ENC2 Upper Position Hold Register
namespace UPOSH {
constexpr ENC2_Reg<&ENC_Layout::UPOSH, 16, 0> POSH;
}  // namespace UPOSH

// ENC2 Lower Position Hold Register
namespace LPOSH {
constexpr ENC2_Reg<&ENC_Layout::LPOSH, 16, 0> POSH;
}  // namespace LPOSH

// ENC2 Upper Initialization Register
namespace UINIT {
constexpr ENC2_Reg<&ENC_Layout::UINIT, 16, 0> INIT;
}  // namespace UINIT

// ENC2 Lower Initialization Register
namespace LINIT {
constexpr ENC2_Reg<&ENC_Layout::LINIT, 16, 0> INIT;
}  // namespace LINIT

// ENC2 Input Monitor Register
namespace IMR {
constexpr ENC2_Reg<&ENC_Layout::IMR, 1, 7> FPHA;
constexpr ENC2_Reg<&ENC_Layout::IMR, 1, 6> FPHB;
constexpr ENC2_Reg<&ENC_Layout::IMR, 1, 5> FIND;
constexpr ENC2_Reg<&ENC_Layout::IMR, 1, 4> FHOM;
constexpr ENC2_Reg<&ENC_Layout::IMR, 1, 3> PHA;
constexpr ENC2_Reg<&ENC_Layout::IMR, 1, 2> PHB;
constexpr ENC2_Reg<&ENC_Layout::IMR, 1, 1> INDEX;
constexpr ENC2_Reg<&ENC_Layout::IMR, 1, 0> HOME;
}  // namespace IMR

// ENC2 Test Register
namespace TST {
constexpr ENC2_Reg<&ENC_Layout::TST, 1, 15> TEN;
constexpr ENC2_Reg<&ENC_Layout::TST, 1, 14> TCE;
constexpr ENC2_Reg<&ENC_Layout::TST, 1, 13> QDN;
constexpr ENC2_Reg<&ENC_Layout::TST, 5,  8> TEST_PERIOD;
constexpr ENC2_Reg<&ENC_Layout::TST, 8,  0> TEST_COUNT;
}  // namespace TST

// ENC2 Control 2 Register
namespace CTRL2 {
constexpr uint16_t kW1C = 0x00a0;

constexpr ENC2_Reg<&ENC_Layout::CTRL2, 1, 9, (uint16_t{1} << 9) | kW1C> OUTCTL;
constexpr ENC2_Reg<&ENC_Layout::CTRL2, 1, 8, (uint16_t{1} << 8) | kW1C> REVMOD;
constexpr ENC2_Reg<&ENC_Layout::CTRL2, 1, 7, kW1C> ROIRQ;
constexpr ENC2_Reg<&ENC_Layout::CTRL2, 1, 6, (uint16_t{1} << 6) | kW1C> ROIE;
constexpr ENC2_Reg<&ENC_Layout::CTRL2, 1, 5, kW1C> RUIRQ;
constexpr ENC2_Reg<&ENC_Layout::CTRL2, 1, 4, (uint16_t{1} << 4) | kW1C> RUIE;
constexpr ENC2_Reg<regs::constify(&ENC_Layout::CTRL2), 1, 3> DIR;
constexpr ENC2_Reg<&ENC_Layout::CTRL2, 1, 2, (uint16_t{1} << 2) | kW1C> MOD;
constexpr ENC2_Reg<&ENC_Layout::CTRL2, 1, 1, (uint16_t{1} << 1) | kW1C> UPDPOS;
constexpr ENC2_Reg<&ENC_Layout::CTRL2, 1, 0, (uint16_t{1} << 0) | kW1C> UPDHLD;
}  // namespace CTRL2

// ENC2 Upper Modulus Register
namespace UMOD {
constexpr ENC2_Reg<&ENC_Layout::UMOD, 16, 0> MOD;
}  // namespace UMOD

// ENC2 Lower Modulus Register
namespace LMOD {
constexpr ENC2_Reg<&ENC_Layout::LMOD, 16, 0> MOD;
}  // namespace LMOD

// ENC2 Upper Position Compare Register
namespace UCOMP {
constexpr ENC2_Reg<&ENC_Layout::UCOMP, 16, 0> COMP;
}  // namespace UCOMP

// ENC2 Lower Position Compare Register
namespace LCOMP {
constexpr ENC2_Reg<&ENC_Layout::LCOMP, 16, 0> COMP;
}  // namespace LCOMP

}  // namespace ENC2

namespace ENC3 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint16_t, Bits, Shift>()>
using ENC3_Reg =
    regs::Reg16<kENC3_base, ENC_Layout, Member, 0, Bits, Shift, AssignMask>;

// ENC3 Control Register
namespace CTRL {
constexpr uint16_t kW1C = 0x8112;

constexpr ENC3_Reg<&ENC_Layout::CTRL, 1, 15, kW1C> HIRQ;
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1, 14, (uint16_t{0x1} << 14) | kW1C> HIE;
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1, 13, (uint16_t{0x1} << 13) | kW1C> HIP;
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1, 12, (uint16_t{0x1} << 12) | kW1C> HNE;
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1, 11, (uint16_t{0x1} << 11) | kW1C> SWIP;
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1, 10, (uint16_t{0x1} << 10) | kW1C> REV;
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1,  9, (uint16_t{0x1} <<  9) | kW1C> PH1;
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1,  8, kW1C> XIRQ;
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1,  7, (uint16_t{0x1} <<  7) | kW1C> XIE;
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1,  6, (uint16_t{0x1} <<  6) | kW1C> XIP;
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1,  5, (uint16_t{0x1} <<  5) | kW1C> XNE;
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1,  4, kW1C> DIRQ;
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1,  3, (uint16_t{0x1} <<  3) | kW1C> DIE;
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1,  2, (uint16_t{0x1} <<  2) | kW1C> WDE;
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1,  1, kW1C> CMPIRQ;
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1,  0, (uint16_t{0x1} <<  0) | kW1C> CMPIE;
}  // namespace CTRL

// ENC3 Input Filter Register
namespace FILT {
constexpr ENC3_Reg<&ENC_Layout::FILT, 3, 13> FILT_PRSC;
constexpr ENC3_Reg<&ENC_Layout::FILT, 3,  8> FILT_CNT;
constexpr ENC3_Reg<&ENC_Layout::FILT, 8,  0> FILT_PER;
}  // namespace FILT

// ENC3 Watchdog Timeout Register
namespace WTR {
constexpr ENC3_Reg<&ENC_Layout::WTR, 16, 0> WDOG;
}  // namespace WTR

// ENC3 Position Difference Counter Register
namespace POSD {
constexpr ENC3_Reg<&ENC_Layout::POSD, 16, 0> POSD;
}  // namespace POSD

// ENC3 Position Difference Hold Register
namespace POSDH {
constexpr ENC3_Reg<&ENC_Layout::POSDH, 16, 0> POSDH;
}  // namespace POSDH

// ENC3 Revolution Counter Register
namespace REV {
constexpr ENC3_Reg<&ENC_Layout::REV, 16, 0> REV;
}  // namespace REV

// ENC3 Revolution Hold Register
namespace REVH {
constexpr ENC3_Reg<&ENC_Layout::REVH, 16, 0> REVH;
}  // namespace REVH

// ENC3 Upper Position Counter Register
namespace UPOS {
constexpr ENC3_Reg<&ENC_Layout::UPOS, 16, 0> POS;
}  // namespace UPOS

// ENC3 Lower Position Counter Register
namespace LPOS {
constexpr ENC3_Reg<&ENC_Layout::LPOS, 16, 0> POS;
}  // namespace LPOS

// ENC3 Upper Position Hold Register
namespace UPOSH {
constexpr ENC3_Reg<&ENC_Layout::UPOSH, 16, 0> POSH;
}  // namespace UPOSH

// ENC3 Lower Position Hold Register
namespace LPOSH {
constexpr ENC3_Reg<&ENC_Layout::LPOSH, 16, 0> POSH;
}  // namespace LPOSH

// ENC3 Upper Initialization Register
namespace UINIT {
constexpr ENC3_Reg<&ENC_Layout::UINIT, 16, 0> INIT;
}  // namespace UINIT

// ENC3 Lower Initialization Register
namespace LINIT {
constexpr ENC3_Reg<&ENC_Layout::LINIT, 16, 0> INIT;
}  // namespace LINIT

// ENC3 Input Monitor Register
namespace IMR {
constexpr ENC3_Reg<&ENC_Layout::IMR, 1, 7> FPHA;
constexpr ENC3_Reg<&ENC_Layout::IMR, 1, 6> FPHB;
constexpr ENC3_Reg<&ENC_Layout::IMR, 1, 5> FIND;
constexpr ENC3_Reg<&ENC_Layout::IMR, 1, 4> FHOM;
constexpr ENC3_Reg<&ENC_Layout::IMR, 1, 3> PHA;
constexpr ENC3_Reg<&ENC_Layout::IMR, 1, 2> PHB;
constexpr ENC3_Reg<&ENC_Layout::IMR, 1, 1> INDEX;
constexpr ENC3_Reg<&ENC_Layout::IMR, 1, 0> HOME;
}  // namespace IMR

// ENC3 Test Register
namespace TST {
constexpr ENC3_Reg<&ENC_Layout::TST, 1, 15> TEN;
constexpr ENC3_Reg<&ENC_Layout::TST, 1, 14> TCE;
constexpr ENC3_Reg<&ENC_Layout::TST, 1, 13> QDN;
constexpr ENC3_Reg<&ENC_Layout::TST, 5,  8> TEST_PERIOD;
constexpr ENC3_Reg<&ENC_Layout::TST, 8,  0> TEST_COUNT;
}  // namespace TST

// ENC3 Control 2 Register
namespace CTRL2 {
constexpr uint16_t kW1C = 0x00a0;

constexpr ENC3_Reg<&ENC_Layout::CTRL2, 1, 9, (uint16_t{1} << 9) | kW1C> OUTCTL;
constexpr ENC3_Reg<&ENC_Layout::CTRL2, 1, 8, (uint16_t{1} << 8) | kW1C> REVMOD;
constexpr ENC3_Reg<&ENC_Layout::CTRL2, 1, 7, kW1C> ROIRQ;
constexpr ENC3_Reg<&ENC_Layout::CTRL2, 1, 6, (uint16_t{1} << 6) | kW1C> ROIE;
constexpr ENC3_Reg<&ENC_Layout::CTRL2, 1, 5, kW1C> RUIRQ;
constexpr ENC3_Reg<&ENC_Layout::CTRL2, 1, 4, (uint16_t{1} << 4) | kW1C> RUIE;
constexpr ENC3_Reg<regs::constify(&ENC_Layout::CTRL2), 1, 3> DIR;
constexpr ENC3_Reg<&ENC_Layout::CTRL2, 1, 2, (uint16_t{1} << 2) | kW1C> MOD;
constexpr ENC3_Reg<&ENC_Layout::CTRL2, 1, 1, (uint16_t{1} << 1) | kW1C> UPDPOS;
constexpr ENC3_Reg<&ENC_Layout::CTRL2, 1, 0, (uint16_t{1} << 0) | kW1C> UPDHLD;
}  // namespace CTRL2

// ENC3 Upper Modulus Register
namespace UMOD {
constexpr ENC3_Reg<&ENC_Layout::UMOD, 16, 0> MOD;
}  // namespace UMOD

// ENC3 Lower Modulus Register
namespace LMOD {
constexpr ENC3_Reg<&ENC_Layout::LMOD, 16, 0> MOD;
}  // namespace LMOD

// ENC3 Upper Position Compare Register
namespace UCOMP {
constexpr ENC3_Reg<&ENC_Layout::UCOMP, 16, 0> COMP;
}  // namespace UCOMP

// ENC3 Lower Position Compare Register
namespace LCOMP {
constexpr ENC3_Reg<&ENC_Layout::LCOMP, 16, 0> COMP;
}  // namespace LCOMP

}  // namespace ENC3

namespace ENC4 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint16_t, Bits, Shift>()>
using ENC4_Reg =
    regs::Reg16<kENC4_base, ENC_Layout, Member, 0, Bits, Shift, AssignMask>;

// ENC4 Control Register
namespace CTRL {
constexpr uint16_t kW1C = 0x8112;

constexpr ENC4_Reg<&ENC_Layout::CTRL, 1, 15, kW1C> HIRQ;
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1, 14, (uint16_t{0x1} << 14) | kW1C> HIE;
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1, 13, (uint16_t{0x1} << 13) | kW1C> HIP;
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1, 12, (uint16_t{0x1} << 12) | kW1C> HNE;
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1, 11, (uint16_t{0x1} << 11) | kW1C> SWIP;
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1, 10, (uint16_t{0x1} << 10) | kW1C> REV;
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1,  9, (uint16_t{0x1} <<  9) | kW1C> PH1;
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1,  8, kW1C> XIRQ;
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1,  7, (uint16_t{0x1} <<  7) | kW1C> XIE;
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1,  6, (uint16_t{0x1} <<  6) | kW1C> XIP;
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1,  5, (uint16_t{0x1} <<  5) | kW1C> XNE;
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1,  4, kW1C> DIRQ;
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1,  3, (uint16_t{0x1} <<  3) | kW1C> DIE;
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1,  2, (uint16_t{0x1} <<  2) | kW1C> WDE;
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1,  1, kW1C> CMPIRQ;
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1,  0, (uint16_t{0x1} <<  0) | kW1C> CMPIE;
}  // namespace CTRL

// ENC4 Input Filter Register
namespace FILT {
constexpr ENC4_Reg<&ENC_Layout::FILT, 3, 13> FILT_PRSC;
constexpr ENC4_Reg<&ENC_Layout::FILT, 3,  8> FILT_CNT;
constexpr ENC4_Reg<&ENC_Layout::FILT, 8,  0> FILT_PER;
}  // namespace FILT

// ENC4 Watchdog Timeout Register
namespace WTR {
constexpr ENC4_Reg<&ENC_Layout::WTR, 16, 0> WDOG;
}  // namespace WTR

// ENC4 Position Difference Counter Register
namespace POSD {
constexpr ENC4_Reg<&ENC_Layout::POSD, 16, 0> POSD;
}  // namespace POSD

// ENC4 Position Difference Hold Register
namespace POSDH {
constexpr ENC4_Reg<&ENC_Layout::POSDH, 16, 0> POSDH;
}  // namespace POSDH

// ENC4 Revolution Counter Register
namespace REV {
constexpr ENC4_Reg<&ENC_Layout::REV, 16, 0> REV;
}  // namespace REV

// ENC4 Revolution Hold Register
namespace REVH {
constexpr ENC4_Reg<&ENC_Layout::REVH, 16, 0> REVH;
}  // namespace REVH

// ENC4 Upper Position Counter Register
namespace UPOS {
constexpr ENC4_Reg<&ENC_Layout::UPOS, 16, 0> POS;
}  // namespace UPOS

// ENC4 Lower Position Counter Register
namespace LPOS {
constexpr ENC4_Reg<&ENC_Layout::LPOS, 16, 0> POS;
}  // namespace LPOS

// ENC4 Upper Position Hold Register
namespace UPOSH {
constexpr ENC4_Reg<&ENC_Layout::UPOSH, 16, 0> POSH;
}  // namespace UPOSH

// ENC4 Lower Position Hold Register
namespace LPOSH {
constexpr ENC4_Reg<&ENC_Layout::LPOSH, 16, 0> POSH;
}  // namespace LPOSH

// ENC4 Upper Initialization Register
namespace UINIT {
constexpr ENC4_Reg<&ENC_Layout::UINIT, 16, 0> INIT;
}  // namespace UINIT

// ENC4 Lower Initialization Register
namespace LINIT {
constexpr ENC4_Reg<&ENC_Layout::LINIT, 16, 0> INIT;
}  // namespace LINIT

// ENC4 Input Monitor Register
namespace IMR {
constexpr ENC4_Reg<&ENC_Layout::IMR, 1, 7> FPHA;
constexpr ENC4_Reg<&ENC_Layout::IMR, 1, 6> FPHB;
constexpr ENC4_Reg<&ENC_Layout::IMR, 1, 5> FIND;
constexpr ENC4_Reg<&ENC_Layout::IMR, 1, 4> FHOM;
constexpr ENC4_Reg<&ENC_Layout::IMR, 1, 3> PHA;
constexpr ENC4_Reg<&ENC_Layout::IMR, 1, 2> PHB;
constexpr ENC4_Reg<&ENC_Layout::IMR, 1, 1> INDEX;
constexpr ENC4_Reg<&ENC_Layout::IMR, 1, 0> HOME;
}  // namespace IMR

// ENC4 Test Register
namespace TST {
constexpr ENC4_Reg<&ENC_Layout::TST, 1, 15> TEN;
constexpr ENC4_Reg<&ENC_Layout::TST, 1, 14> TCE;
constexpr ENC4_Reg<&ENC_Layout::TST, 1, 13> QDN;
constexpr ENC4_Reg<&ENC_Layout::TST, 5,  8> TEST_PERIOD;
constexpr ENC4_Reg<&ENC_Layout::TST, 8,  0> TEST_COUNT;
}  // namespace TST

// ENC4 Control 2 Register
namespace CTRL2 {
constexpr uint16_t kW1C = 0x00a0;

constexpr ENC4_Reg<&ENC_Layout::CTRL2, 1, 9, (uint16_t{1} << 9) | kW1C> OUTCTL;
constexpr ENC4_Reg<&ENC_Layout::CTRL2, 1, 8, (uint16_t{1} << 8) | kW1C> REVMOD;
constexpr ENC4_Reg<&ENC_Layout::CTRL2, 1, 7, kW1C> ROIRQ;
constexpr ENC4_Reg<&ENC_Layout::CTRL2, 1, 6, (uint16_t{1} << 6) | kW1C> ROIE;
constexpr ENC4_Reg<&ENC_Layout::CTRL2, 1, 5, kW1C> RUIRQ;
constexpr ENC4_Reg<&ENC_Layout::CTRL2, 1, 4, (uint16_t{1} << 4) | kW1C> RUIE;
constexpr ENC4_Reg<regs::constify(&ENC_Layout::CTRL2), 1, 3> DIR;
constexpr ENC4_Reg<&ENC_Layout::CTRL2, 1, 2, (uint16_t{1} << 2) | kW1C> MOD;
constexpr ENC4_Reg<&ENC_Layout::CTRL2, 1, 1, (uint16_t{1} << 1) | kW1C> UPDPOS;
constexpr ENC4_Reg<&ENC_Layout::CTRL2, 1, 0, (uint16_t{1} << 0) | kW1C> UPDHLD;
}  // namespace CTRL2

// ENC4 Upper Modulus Register
namespace UMOD {
constexpr ENC4_Reg<&ENC_Layout::UMOD, 16, 0> MOD;
}  // namespace UMOD

// ENC4 Lower Modulus Register
namespace LMOD {
constexpr ENC4_Reg<&ENC_Layout::LMOD, 16, 0> MOD;
}  // namespace LMOD

// ENC4 Upper Position Compare Register
namespace UCOMP {
constexpr ENC4_Reg<&ENC_Layout::UCOMP, 16, 0> COMP;
}  // namespace UCOMP

// ENC4 Lower Position Compare Register
namespace LCOMP {
constexpr ENC4_Reg<&ENC_Layout::LCOMP, 16, 0> COMP;
}  // namespace LCOMP

}  // namespace ENC4

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
