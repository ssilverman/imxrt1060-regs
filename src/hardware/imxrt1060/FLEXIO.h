// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// FLEXIO.h defines all the FLEXIO registers.
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
constexpr size_t kFLEXIO_SHIFTCTL_count    = 8;
constexpr size_t kFLEXIO_SHIFTCFG_count    = 8;
constexpr size_t kFLEXIO_SHIFTBUF_count    = 8;
constexpr size_t kFLEXIO_SHIFTBUFBIS_count = 8;
constexpr size_t kFLEXIO_SHIFTBUFBYS_count = 8;
constexpr size_t kFLEXIO_SHIFTBUFBBS_count = 8;
constexpr size_t kFLEXIO_TIMCTL_count      = 8;
constexpr size_t kFLEXIO_TIMCFG_count      = 8;
constexpr size_t kFLEXIO_TIMCMP_count      = 8;
constexpr size_t kFLEXIO_SHIFTBUFNBS_count = 8;
constexpr size_t kFLEXIO_SHIFTBUFHWS_count = 8;
constexpr size_t kFLEXIO_SHIFTBUFNIS_count = 8;

// Structure type to access the Flexible I/O (FLEXIO) registers.
//
// Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_FLEXIO.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct FLEXIO_Layout {
  const volatile uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  const volatile uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  volatile uint32_t CTRL;                                    /**< FlexIO Control Register, offset: 0x8 */
  const volatile uint32_t PIN;                               /**< Pin State Register, offset: 0xC */
  volatile uint32_t SHIFTSTAT;                               /**< Shifter Status Register, offset: 0x10 */
  volatile uint32_t SHIFTERR;                                /**< Shifter Error Register, offset: 0x14 */
  volatile uint32_t TIMSTAT;                                 /**< Timer Status Register, offset: 0x18 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t SHIFTSIEN;                               /**< Shifter Status Interrupt Enable, offset: 0x20 */
  volatile uint32_t SHIFTEIEN;                               /**< Shifter Error Interrupt Enable, offset: 0x24 */
  volatile uint32_t TIMIEN;                                  /**< Timer Interrupt Enable Register, offset: 0x28 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t SHIFTSDEN;                               /**< Shifter Status DMA Enable, offset: 0x30 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SHIFTSTATE;                              /**< Shifter State Register, offset: 0x40 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[15];
  volatile uint32_t SHIFTCTL[kFLEXIO_SHIFTCTL_count];        /**< Shifter Control N Register, array offset: 0x80, array step: 0x4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[24];
  volatile uint32_t SHIFTCFG[kFLEXIO_SHIFTCFG_count];        /**< Shifter Configuration N Register, array offset: 0x100, array step: 0x4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[56];
  volatile uint32_t SHIFTBUF[kFLEXIO_SHIFTBUF_count];        /**< Shifter Buffer N Register, array offset: 0x200, array step: 0x4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[24];
  volatile uint32_t SHIFTBUFBIS[kFLEXIO_SHIFTBUFBIS_count];  /**< Shifter Buffer N Bit Swapped Register, array offset: 0x280, array step: 0x4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[24];
  volatile uint32_t SHIFTBUFBYS[kFLEXIO_SHIFTBUFBYS_count];  /**< Shifter Buffer N Byte Swapped Register, array offset: 0x300, array step: 0x4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[24];
  volatile uint32_t SHIFTBUFBBS[kFLEXIO_SHIFTBUFBBS_count];  /**< Shifter Buffer N Bit Byte Swapped Register, array offset: 0x380, array step: 0x4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[24];
  volatile uint32_t TIMCTL[kFLEXIO_TIMCTL_count];            /**< Timer Control N Register, array offset: 0x400, array step: 0x4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[24];
  volatile uint32_t TIMCFG[kFLEXIO_TIMCFG_count];            /**< Timer Configuration N Register, array offset: 0x480, array step: 0x4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[24];
  volatile uint32_t TIMCMP[kFLEXIO_TIMCMP_count];            /**< Timer Compare N Register, array offset: 0x500, array step: 0x4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[88];
  volatile uint32_t SHIFTBUFNBS[kFLEXIO_SHIFTBUFNBS_count];  /**< Shifter Buffer N Nibble Byte Swapped Register, array offset: 0x680, array step: 0x4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[24];
  volatile uint32_t SHIFTBUFHWS[kFLEXIO_SHIFTBUFHWS_count];  /**< Shifter Buffer N Half Word Swapped Register, array offset: 0x700, array step: 0x4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[24];
  volatile uint32_t SHIFTBUFNIS[kFLEXIO_SHIFTBUFNIS_count];  /**< Shifter Buffer N Nibble Swapped Register, array offset: 0x780, array step: 0x4 */
};

constexpr size_t    kFLEXIO_size  = 0x7A0;
constexpr uintptr_t kFLEXIO1_base = 0x401AC000;
constexpr uintptr_t kFLEXIO2_base = 0x401B0000;
constexpr uintptr_t kFLEXIO3_base = 0x42020000;

namespace FLEXIO1 {
constexpr regs::RegGroup<FLEXIO_Layout, kFLEXIO_size, kFLEXIO1_base> group;
}  // namespace FLEXIO1

namespace FLEXIO2 {
constexpr regs::RegGroup<FLEXIO_Layout, kFLEXIO_size, kFLEXIO2_base> group;
}  // namespace FLEXIO2

namespace FLEXIO3 {
constexpr regs::RegGroup<FLEXIO_Layout, kFLEXIO_size, kFLEXIO3_base> group;
}  // namespace FLEXIO3

namespace FLEXIO1 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false>
using FLEXIO1_Reg = regs::Reg32<kFLEXIO1_base, FLEXIO_Layout, Member, 0, Bits,
                                Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTCTL_count)>>
using SHIFTCTL_Reg =
    regs::Reg32<kFLEXIO1_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTCTL, Index,
                Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTCFG_count)>>
using SHIFTCFG_Reg =
    regs::Reg32<kFLEXIO1_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTCFG, Index,
                Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTBUF_count)>>
using SHIFTBUF_Reg =
    regs::Reg32<kFLEXIO1_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTBUF, Index,
                Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTBUFBIS_count)>>
using SHIFTBUFBIS_Reg =
    regs::Reg32<kFLEXIO1_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTBUFBIS,
                Index, Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTBUFBYS_count)>>
using SHIFTBUFBYS_Reg =
    regs::Reg32<kFLEXIO1_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTBUFBYS,
                Index, Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTBUFBBS_count)>>
using SHIFTBUFBBS_Reg =
    regs::Reg32<kFLEXIO1_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTBUFBBS,
                Index, Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_TIMCTL_count)>>
using TIMCTL_Reg =
    regs::Reg32<kFLEXIO1_base, FLEXIO_Layout, &FLEXIO_Layout::TIMCTL, Index,
                Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_TIMCFG_count)>>
using TIMCFG_Reg =
    regs::Reg32<kFLEXIO1_base, FLEXIO_Layout, &FLEXIO_Layout::TIMCFG, Index,
                Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_TIMCMP_count)>>
using TIMCMP_Reg =
    regs::Reg32<kFLEXIO1_base, FLEXIO_Layout, &FLEXIO_Layout::TIMCMP, Index,
                Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTBUFNBS_count)>>
using SHIFTBUFNBS_Reg =
    regs::Reg32<kFLEXIO1_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTBUFNBS,
                Index, Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTBUFHWS_count)>>
using SHIFTBUFHWS_Reg =
    regs::Reg32<kFLEXIO1_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTBUFHWS,
                Index, Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTBUFNIS_count)>>
using SHIFTBUFNIS_Reg =
    regs::Reg32<kFLEXIO1_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTBUFNIS,
                Index, Bits, Shift, AssignMask, WriteOnly>;

// Version ID Register
namespace VERID {
constexpr FLEXIO1_Reg<&FLEXIO_Layout::VERID,  8, 24> MAJOR;    // Major Version Number
constexpr FLEXIO1_Reg<&FLEXIO_Layout::VERID,  8, 16> MINOR;    // Minor Version Number
constexpr FLEXIO1_Reg<&FLEXIO_Layout::VERID, 16,  0> FEATURE;  // Feature Specification Number
    // 0b0000000000000000..Standard features implemented.
    // 0b0000000000000001..Supports state, logic and parallel modes.
}  // namespace VERID

// Parameter Register
namespace PARAM {
constexpr FLEXIO1_Reg<&FLEXIO_Layout::PARAM, 8, 24> TRIGGER;  // Trigger Number
constexpr FLEXIO1_Reg<&FLEXIO_Layout::PARAM, 8, 16> PIN;      // Pin Number
constexpr FLEXIO1_Reg<&FLEXIO_Layout::PARAM, 8,  8> TIMER;    // Timer Number
constexpr FLEXIO1_Reg<&FLEXIO_Layout::PARAM, 8,  0> SHIFTER;  // Shifter Number
}  // namespace PARAM

// FlexIO Control Register
namespace CTRL {
constexpr FLEXIO1_Reg<&FLEXIO_Layout::CTRL, 1, 31> DOZEN;    // Doze Enable
    // 0b0..FlexIO enabled in Doze modes.
    // 0b1..FlexIO disabled in Doze modes.
constexpr FLEXIO1_Reg<&FLEXIO_Layout::CTRL, 1, 30> DBGE;     // Debug Enable
    // 0b0..FlexIO is disabled in debug modes.
    // 0b1..FlexIO is enabled in debug modes
constexpr FLEXIO1_Reg<&FLEXIO_Layout::CTRL, 1,  2> FASTACC;  // Fast Access
    // 0b0..Configures for normal register accesses to FlexIO
    // 0b1..Configures for fast register accesses to FlexIO
constexpr FLEXIO1_Reg<&FLEXIO_Layout::CTRL, 1,  1> SWRST;    // Software Reset
    // 0b0..Software reset is disabled
    // 0b1..Software reset is enabled, all FlexIO registers except the Control Register are reset.
constexpr FLEXIO1_Reg<&FLEXIO_Layout::CTRL, 1,  0> FLEXEN;   // FlexIO Enable
    // 0b0..FlexIO module is disabled.
    // 0b1..FlexIO module is enabled.
}  // namespace CTRL

// Pin State Register
namespace PIN {
constexpr FLEXIO1_Reg<&FLEXIO_Layout::PIN, 16, 0> PDI;  // Pin Data Input
}  // namespace PIN

// Shifter Status Register
namespace SHIFTSTAT {
constexpr FLEXIO1_Reg<&FLEXIO_Layout::SHIFTSTAT, 8, 0, 0x0> SSF;  // Shifter Status Flag
}  // namespace SHIFTSTAT

// Shifter Error Register
namespace SHIFTERR {
constexpr FLEXIO1_Reg<&FLEXIO_Layout::SHIFTERR, 8, 0, 0x0> SEF;  // Shifter Error Flags
}  // namespace SHIFTERR

// Timer Status Register
namespace TIMSTAT {
constexpr FLEXIO1_Reg<&FLEXIO_Layout::TIMSTAT, 8, 0, 0x0> TSF;  // Timer Status Flags
}  // namespace TIMSTAT

// Shifter Status Interrupt Enable
namespace SHIFTSIEN {
constexpr FLEXIO1_Reg<&FLEXIO_Layout::SHIFTSIEN, 8, 0> SSIE;  // Shifter Status Interrupt Enable
}  // namespace SHIFTSIEN

// Shifter Error Interrupt Enable
namespace SHIFTEIEN {
constexpr FLEXIO1_Reg<&FLEXIO_Layout::SHIFTEIEN, 8, 0> SEIE;  // Shifter Error Interrupt Enable
}  // namespace SHIFTEIEN

// Timer Interrupt Enable Register
namespace TIMIEN {
constexpr FLEXIO1_Reg<&FLEXIO_Layout::TIMIEN, 8, 0> TEIE;  // Timer Status Interrupt Enable
}  // namespace TIMIEN

// Shifter Status DMA Enable
namespace SHIFTSDEN {
constexpr FLEXIO1_Reg<&FLEXIO_Layout::SHIFTSDEN, 8, 0> SSDE;  // Shifter Status DMA Enable
}  // namespace SHIFTSDEN

// Shifter State Register
namespace SHIFTSTATE {
constexpr FLEXIO1_Reg<&FLEXIO_Layout::SHIFTSTATE, 3, 0> STATE;  // Current State Pointer
}  // namespace SHIFTSTATE

// Shifter Control N Register
namespace SHIFTCTL {
template <size_t Index>
constexpr SHIFTCTL_Reg<Index, 3, 24> TIMSEL;  // Timer Select
template <size_t Index>
constexpr SHIFTCTL_Reg<Index, 1, 23> TIMPOL;  // Timer Polarity
    // 0b0..Shift on posedge of Shift clock
    // 0b1..Shift on negedge of Shift clock
template <size_t Index>
constexpr SHIFTCTL_Reg<Index, 2, 16> PINCFG;  // Shifter Pin Configuration
    // 0b00..Shifter pin output disabled
    // 0b01..Shifter pin open drain or bidirectional output enable
    // 0b10..Shifter pin bidirectional output data
    // 0b11..Shifter pin output
template <size_t Index>
constexpr SHIFTCTL_Reg<Index, 5,  8> PINSEL;  // Shifter Pin Select
template <size_t Index>
constexpr SHIFTCTL_Reg<Index, 1,  7> PINPOL;  // Shifter Pin Polarity
    // 0b0..Pin is active high
    // 0b1..Pin is active low
template <size_t Index>
constexpr SHIFTCTL_Reg<Index, 3,  0> SMOD;    // Shifter Mode
    // 0b000..Disabled.
    // 0b001..Receive mode. Captures the current Shifter content into the SHIFTBUF on expiration of the Timer.
    // 0b010..Transmit mode. Load SHIFTBUF contents into the Shifter on expiration of the Timer.
    // 0b011..Reserved.
    // 0b100..Match Store mode. Shifter data is compared to SHIFTBUF content on expiration of the Timer.
    // 0b101..Match Continuous mode. Shifter data is continuously compared to SHIFTBUF contents.
    // 0b110..State mode. SHIFTBUF contents are used for storing programmable state attributes.
    // 0b111..Logic mode. SHIFTBUF contents are used for implementing programmable logic look up table.
}  // namespace SHIFTCTL

// Shifter Configuration N Register
namespace SHIFTCFG {
template <size_t Index>
constexpr SHIFTCFG_Reg<Index, 5, 16> PWIDTH;  // Parallel Width
template <size_t Index>
constexpr SHIFTCFG_Reg<Index, 1,  8> INSRC;   // Input Source
    // 0b0..Pin
    // 0b1..Shifter N+1 Output
template <size_t Index>
constexpr SHIFTCFG_Reg<Index, 2,  4> SSTOP;   // Shifter Stop bit
    // 0b00..Stop bit disabled for transmitter/receiver/match store
    // 0b01..Stop bit disabled for transmitter/receiver/match store, receiver/match store will store receive data on
    //     the configured shift edge when timer in stop condition
    // 0b10..Transmitter outputs stop bit value 0 on store, receiver/match store sets error flag if stop bit is not
    //     0, receiver/match store will also store receive data on the configured shift edge when timer in stop
    //     condition
    // 0b11..Transmitter outputs stop bit value 1 on store, receiver/match store sets error flag if stop bit is not
    //     1, receiver/match store will also store receive data on the configured shift edge when timer in stop
    //     condition
template <size_t Index>
constexpr SHIFTCFG_Reg<Index, 2,  0> SSTART;  // Shifter Start bit
    // 0b00..Start bit disabled for transmitter/receiver/match store, transmitter loads data on enable
    // 0b01..Start bit disabled for transmitter/receiver/match store, transmitter loads data on first shift
    // 0b10..Transmitter outputs start bit value 0 before loading data on first shift, receiver/match store sets
    //     error flag if start bit is not 0
    // 0b11..Transmitter outputs start bit value 1 before loading data on first shift, receiver/match store sets
    //     error flag if start bit is not 1
}  // namespace SHIFTCFG

// Shifter Buffer N Register
namespace SHIFTBUF {
template <size_t Index>
constexpr SHIFTBUF_Reg<Index, 32, 0> SHIFTBUF;  // Shift Buffer
}  // namespace SHIFTBUF

// Shifter Buffer N Bit Swapped Register
namespace SHIFTBUFBIS {
template <size_t Index>
constexpr SHIFTBUFBIS_Reg<Index, 32, 0> SHIFTBUFBIS;  // Shift Buffer
}  // namespace SHIFTBUFBIS

// Shifter Buffer N Byte Swapped Register
namespace SHIFTBUFBYS {
template <size_t Index>
constexpr SHIFTBUFBYS_Reg<Index, 32, 0> SHIFTBUFBYS;  // Shift Buffer
}  // namespace SHIFTBUFBYS

// Shifter Buffer N Bit Byte Swapped Register
namespace SHIFTBUFBBS {
template <size_t Index>
constexpr SHIFTBUFBBS_Reg<Index, 32, 0> SHIFTBUFBBS;  // Shift Buffer
}  // namespace SHIFTBUFBBS

// Timer Control N Register
namespace TIMCTL {
template <size_t Index>
constexpr TIMCTL_Reg<Index, 6, 24> TRGSEL;  // Trigger Select
template <size_t Index>
constexpr TIMCTL_Reg<Index, 1, 23> TRGPOL;  // Trigger Polarity
    // 0b0..Trigger active high
    // 0b1..Trigger active low
template <size_t Index>
constexpr TIMCTL_Reg<Index, 1, 22> TRGSRC;  // Trigger Source
    // 0b0..External trigger selected
    // 0b1..Internal trigger selected
template <size_t Index>
constexpr TIMCTL_Reg<Index, 2, 16> PINCFG;  // Timer Pin Configuration
    // 0b00..Timer pin output disabled
    // 0b01..Timer pin open drain or bidirectional output enable
    // 0b10..Timer pin bidirectional output data
    // 0b11..Timer pin output
template <size_t Index>
constexpr TIMCTL_Reg<Index, 5,  8> PINSEL;  // Timer Pin Select
template <size_t Index>
constexpr TIMCTL_Reg<Index, 1,  7> PINPOL;  // Timer Pin Polarity
    // 0b0..Pin is active high
    // 0b1..Pin is active low
template <size_t Index>
constexpr TIMCTL_Reg<Index, 2,  0> TIMOD;   // Timer Mode
    // 0b00..Timer Disabled.
    // 0b01..Dual 8-bit counters baud mode.
    // 0b10..Dual 8-bit counters PWM high mode.
    // 0b11..Single 16-bit counter mode.
}  // namespace TIMCTL

// Timer Configuration N Register
namespace TIMCFG {
template <size_t Index>
constexpr TIMCFG_Reg<Index, 2, 24> TIMOUT;  // Timer Output
    // 0b00..Timer output is logic one when enabled and is not affected by timer reset
    // 0b01..Timer output is logic zero when enabled and is not affected by timer reset
    // 0b10..Timer output is logic one when enabled and on timer reset
    // 0b11..Timer output is logic zero when enabled and on timer reset
template <size_t Index>
constexpr TIMCFG_Reg<Index, 2, 20> TIMDEC;  // Timer Decrement
    // 0b00..Decrement counter on FlexIO clock, Shift clock equals Timer output.
    // 0b01..Decrement counter on Trigger input (both edges), Shift clock equals Timer output.
    // 0b10..Decrement counter on Pin input (both edges), Shift clock equals Pin input.
    // 0b11..Decrement counter on Trigger input (both edges), Shift clock equals Trigger input.
template <size_t Index>
constexpr TIMCFG_Reg<Index, 3, 16> TIMRST;  // Timer Reset
    // 0b000..Timer never reset
    // 0b001..Reserved
    // 0b010..Timer reset on Timer Pin equal to Timer Output
    // 0b011..Timer reset on Timer Trigger equal to Timer Output
    // 0b100..Timer reset on Timer Pin rising edge
    // 0b101..Reserved
    // 0b110..Timer reset on Trigger rising edge
    // 0b111..Timer reset on Trigger rising or falling edge
template <size_t Index>
constexpr TIMCFG_Reg<Index, 3, 12> TIMDIS;  // Timer Disable
    // 0b000..Timer never disabled
    // 0b001..Timer disabled on Timer N-1 disable
    // 0b010..Timer disabled on Timer compare (upper 8-bits match and decrement)
    // 0b011..Timer disabled on Timer compare (upper 8-bits match and decrement) and Trigger Low
    // 0b100..Timer disabled on Pin rising or falling edge
    // 0b101..Timer disabled on Pin rising or falling edge provided Trigger is high
    // 0b110..Timer disabled on Trigger falling edge
    // 0b111..Reserved
template <size_t Index>
constexpr TIMCFG_Reg<Index, 3,  8> TIMENA;  // Timer Enable
    // 0b000..Timer always enabled
    // 0b001..Timer enabled on Timer N-1 enable
    // 0b010..Timer enabled on Trigger high
    // 0b011..Timer enabled on Trigger high and Pin high
    // 0b100..Timer enabled on Pin rising edge
    // 0b101..Timer enabled on Pin rising edge and Trigger high
    // 0b110..Timer enabled on Trigger rising edge
    // 0b111..Timer enabled on Trigger rising or falling edge
template <size_t Index>
constexpr TIMCFG_Reg<Index, 2,  4> TSTOP;   // Timer Stop Bit
    // 0b00..Stop bit disabled
    // 0b01..Stop bit is enabled on timer compare
    // 0b10..Stop bit is enabled on timer disable
    // 0b11..Stop bit is enabled on timer compare and timer disable
template <size_t Index>
constexpr TIMCFG_Reg<Index, 1,  1> TSTART;  // Timer Start Bit
    // 0b0..Start bit disabled
    // 0b1..Start bit enabled
}  // namespace TIMCFG

// Timer Compare N Register
namespace TIMCMP {
template <size_t Index>
constexpr TIMCMP_Reg<Index, 16, 0> CMP;  // Timer Compare Value
}  // namespace TIMCMP

// Shifter Buffer N Nibble Byte Swapped Register
namespace SHIFTBUFNBS {
template <size_t Index>
constexpr SHIFTBUFNBS_Reg<Index, 32, 0> SHIFTBUFNBS;  // Shift Buffer
}  // namespace SHIFTBUFNBS

// Shifter Buffer N Half Word Swapped Register
namespace SHIFTBUFHWS {
template <size_t Index>
constexpr SHIFTBUFHWS_Reg<Index, 32, 0> SHIFTBUFHWS;  // Shift Buffer
}  // namespace SHIFTBUFHWS

// Shifter Buffer N Nibble Swapped Register
namespace SHIFTBUFNIS {
template <size_t Index>
constexpr SHIFTBUFNIS_Reg<Index, 32, 0> SHIFTBUFNIS;  // Shift Buffer
}  // namespace SHIFTBUFNIS

}  // namespace FLEXIO1

namespace FLEXIO2 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false>
using FLEXIO2_Reg = regs::Reg32<kFLEXIO2_base, FLEXIO_Layout, Member, 0, Bits,
                                Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTCTL_count)>>
using SHIFTCTL_Reg =
    regs::Reg32<kFLEXIO2_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTCTL, Index,
                Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTCFG_count)>>
using SHIFTCFG_Reg =
    regs::Reg32<kFLEXIO2_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTCFG, Index,
                Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTBUF_count)>>
using SHIFTBUF_Reg =
    regs::Reg32<kFLEXIO2_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTBUF, Index,
                Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTBUFBIS_count)>>
using SHIFTBUFBIS_Reg =
    regs::Reg32<kFLEXIO2_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTBUFBIS,
                Index, Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTBUFBYS_count)>>
using SHIFTBUFBYS_Reg =
    regs::Reg32<kFLEXIO2_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTBUFBYS,
                Index, Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTBUFBBS_count)>>
using SHIFTBUFBBS_Reg =
    regs::Reg32<kFLEXIO2_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTBUFBBS,
                Index, Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_TIMCTL_count)>>
using TIMCTL_Reg =
    regs::Reg32<kFLEXIO2_base, FLEXIO_Layout, &FLEXIO_Layout::TIMCTL, Index,
                Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_TIMCFG_count)>>
using TIMCFG_Reg =
    regs::Reg32<kFLEXIO2_base, FLEXIO_Layout, &FLEXIO_Layout::TIMCFG, Index,
                Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_TIMCMP_count)>>
using TIMCMP_Reg =
    regs::Reg32<kFLEXIO2_base, FLEXIO_Layout, &FLEXIO_Layout::TIMCMP, Index,
                Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTBUFNBS_count)>>
using SHIFTBUFNBS_Reg =
    regs::Reg32<kFLEXIO2_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTBUFNBS,
                Index, Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTBUFHWS_count)>>
using SHIFTBUFHWS_Reg =
    regs::Reg32<kFLEXIO2_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTBUFHWS,
                Index, Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTBUFNIS_count)>>
using SHIFTBUFNIS_Reg =
    regs::Reg32<kFLEXIO2_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTBUFNIS,
                Index, Bits, Shift, AssignMask, WriteOnly>;

// Version ID Register
namespace VERID {
constexpr FLEXIO2_Reg<&FLEXIO_Layout::VERID,  8, 24> MAJOR;
constexpr FLEXIO2_Reg<&FLEXIO_Layout::VERID,  8, 16> MINOR;
constexpr FLEXIO2_Reg<&FLEXIO_Layout::VERID, 16,  0> FEATURE;
}  // namespace VERID

// Parameter Register
namespace PARAM {
constexpr FLEXIO2_Reg<&FLEXIO_Layout::PARAM, 8, 24> TRIGGER;
constexpr FLEXIO2_Reg<&FLEXIO_Layout::PARAM, 8, 16> PIN;
constexpr FLEXIO2_Reg<&FLEXIO_Layout::PARAM, 8,  8> TIMER;
constexpr FLEXIO2_Reg<&FLEXIO_Layout::PARAM, 8,  0> SHIFTER;
}  // namespace PARAM

// FlexIO Control Register
namespace CTRL {
constexpr FLEXIO2_Reg<&FLEXIO_Layout::CTRL, 1, 31> DOZEN;
constexpr FLEXIO2_Reg<&FLEXIO_Layout::CTRL, 1, 30> DBGE;
constexpr FLEXIO2_Reg<&FLEXIO_Layout::CTRL, 1,  2> FASTACC;
constexpr FLEXIO2_Reg<&FLEXIO_Layout::CTRL, 1,  1> SWRST;
constexpr FLEXIO2_Reg<&FLEXIO_Layout::CTRL, 1,  0> FLEXEN;
}  // namespace CTRL

// Pin State Register
namespace PIN {
constexpr FLEXIO2_Reg<&FLEXIO_Layout::PIN, 32, 0> PDI;
}  // namespace PIN

// Shifter Status Register
namespace SHIFTSTAT {
constexpr FLEXIO2_Reg<&FLEXIO_Layout::SHIFTSTAT, 8, 0, 0x0> SSF;
}  // namespace SHIFTSTAT

// Shifter Error Register
namespace SHIFTERR {
constexpr FLEXIO2_Reg<&FLEXIO_Layout::SHIFTERR, 8, 0, 0x0> SEF;
}  // namespace SHIFTERR

// Timer Status Register
namespace TIMSTAT {
constexpr FLEXIO2_Reg<&FLEXIO_Layout::TIMSTAT, 8, 0, 0x0> TSF;
}  // namespace TIMSTAT

// Shifter Status Interrupt Enable
namespace SHIFTSIEN {
constexpr FLEXIO2_Reg<&FLEXIO_Layout::SHIFTSIEN, 8, 0> SSIE;
}  // namespace SHIFTSIEN

// Shifter Error Interrupt Enable
namespace SHIFTEIEN {
constexpr FLEXIO2_Reg<&FLEXIO_Layout::SHIFTEIEN, 8, 0> SEIE;
}  // namespace SHIFTEIEN

// Timer Interrupt Enable Register
namespace TIMIEN {
constexpr FLEXIO2_Reg<&FLEXIO_Layout::TIMIEN, 8, 0> TEIE;
}  // namespace TIMIEN

// Shifter Status DMA Enable
namespace SHIFTSDEN {
constexpr FLEXIO2_Reg<&FLEXIO_Layout::SHIFTSDEN, 8, 0> SSDE;
}  // namespace SHIFTSDEN

// Shifter State Register
namespace SHIFTSTATE {
constexpr FLEXIO2_Reg<&FLEXIO_Layout::SHIFTSTATE, 3, 0> STATE;
}  // namespace SHIFTSTATE

// Shifter Control N Register
namespace SHIFTCTL {
template <size_t Index>
constexpr SHIFTCTL_Reg<Index, 3, 24> TIMSEL;
template <size_t Index>
constexpr SHIFTCTL_Reg<Index, 1, 23> TIMPOL;
template <size_t Index>
constexpr SHIFTCTL_Reg<Index, 2, 16> PINCFG;
template <size_t Index>
constexpr SHIFTCTL_Reg<Index, 5,  8> PINSEL;
template <size_t Index>
constexpr SHIFTCTL_Reg<Index, 1,  7> PINPOL;
template <size_t Index>
constexpr SHIFTCTL_Reg<Index, 3,  0> SMOD;
}  // namespace SHIFTCTL

// Shifter Configuration N Register
namespace SHIFTCFG {
template <size_t Index>
constexpr SHIFTCFG_Reg<Index, 5, 16> PWIDTH;
template <size_t Index>
constexpr SHIFTCFG_Reg<Index, 1,  8> INSRC;
template <size_t Index>
constexpr SHIFTCFG_Reg<Index, 2,  4> SSTOP;
template <size_t Index>
constexpr SHIFTCFG_Reg<Index, 2,  0> SSTART;
}  // namespace SHIFTCFG

// Shifter Buffer N Register
namespace SHIFTBUF {
template <size_t Index>
constexpr SHIFTBUF_Reg<Index, 32, 0> SHIFTBUF;
}  // namespace SHIFTBUF

// Shifter Buffer N Bit Swapped Register
namespace SHIFTBUFBIS {
template <size_t Index>
constexpr SHIFTBUFBIS_Reg<Index, 32, 0> SHIFTBUFBIS;
}  // namespace SHIFTBUFBIS

// Shifter Buffer N Byte Swapped Register
namespace SHIFTBUFBYS {
template <size_t Index>
constexpr SHIFTBUFBYS_Reg<Index, 32, 0> SHIFTBUFBYS;
}  // namespace SHIFTBUFBYS

// Shifter Buffer N Bit Byte Swapped Register
namespace SHIFTBUFBBS {
template <size_t Index>
constexpr SHIFTBUFBBS_Reg<Index, 32, 0> SHIFTBUFBBS;
}  // namespace SHIFTBUFBBS

// Timer Control N Register
namespace TIMCTL {
template <size_t Index>
constexpr TIMCTL_Reg<Index, 6, 24> TRGSEL;
template <size_t Index>
constexpr TIMCTL_Reg<Index, 1, 23> TRGPOL;
template <size_t Index>
constexpr TIMCTL_Reg<Index, 1, 22> TRGSRC;
template <size_t Index>
constexpr TIMCTL_Reg<Index, 2, 16> PINCFG;
template <size_t Index>
constexpr TIMCTL_Reg<Index, 5,  8> PINSEL;
template <size_t Index>
constexpr TIMCTL_Reg<Index, 1,  7> PINPOL;
template <size_t Index>
constexpr TIMCTL_Reg<Index, 2,  0> TIMOD;
}  // namespace TIMCTL

// Timer Configuration N Register
namespace TIMCFG {
template <size_t Index>
constexpr TIMCFG_Reg<Index, 2, 24> TIMOUT;
template <size_t Index>
constexpr TIMCFG_Reg<Index, 2, 20> TIMDEC;
template <size_t Index>
constexpr TIMCFG_Reg<Index, 3, 16> TIMRST;
template <size_t Index>
constexpr TIMCFG_Reg<Index, 3, 12> TIMDIS;
template <size_t Index>
constexpr TIMCFG_Reg<Index, 3,  8> TIMENA;
template <size_t Index>
constexpr TIMCFG_Reg<Index, 2,  4> TSTOP;
template <size_t Index>
constexpr TIMCFG_Reg<Index, 1,  1> TSTART;
}  // namespace TIMCFG

// Timer Compare N Register
namespace TIMCMP {
template <size_t Index>
constexpr TIMCMP_Reg<Index, 16, 0> CMP;
}  // namespace TIMCMP

// Shifter Buffer N Nibble Byte Swapped Register
namespace SHIFTBUFNBS {
template <size_t Index>
constexpr SHIFTBUFNBS_Reg<Index, 32, 0> SHIFTBUFNBS;
}  // namespace SHIFTBUFNBS

// Shifter Buffer N Half Word Swapped Register
namespace SHIFTBUFHWS {
template <size_t Index>
constexpr SHIFTBUFHWS_Reg<Index, 32, 0> SHIFTBUFHWS;
}  // namespace SHIFTBUFHWS

// Shifter Buffer N Nibble Swapped Register
namespace SHIFTBUFNIS {
template <size_t Index>
constexpr SHIFTBUFNIS_Reg<Index, 32, 0> SHIFTBUFNIS;
}  // namespace SHIFTBUFNIS

}  // namespace FLEXIO2

namespace FLEXIO3 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false>
using FLEXIO3_Reg = regs::Reg32<kFLEXIO3_base, FLEXIO_Layout, Member, 0, Bits,
                                Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTCTL_count)>>
using SHIFTCTL_Reg =
    regs::Reg32<kFLEXIO3_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTCTL, Index,
                Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTCFG_count)>>
using SHIFTCFG_Reg =
    regs::Reg32<kFLEXIO3_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTCFG, Index,
                Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTBUF_count)>>
using SHIFTBUF_Reg =
    regs::Reg32<kFLEXIO3_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTBUF, Index,
                Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTBUFBIS_count)>>
using SHIFTBUFBIS_Reg =
    regs::Reg32<kFLEXIO3_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTBUFBIS,
                Index, Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTBUFBYS_count)>>
using SHIFTBUFBYS_Reg =
    regs::Reg32<kFLEXIO3_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTBUFBYS,
                Index, Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTBUFBBS_count)>>
using SHIFTBUFBBS_Reg =
    regs::Reg32<kFLEXIO3_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTBUFBBS,
                Index, Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_TIMCTL_count)>>
using TIMCTL_Reg =
    regs::Reg32<kFLEXIO3_base, FLEXIO_Layout, &FLEXIO_Layout::TIMCTL, Index,
                Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_TIMCFG_count)>>
using TIMCFG_Reg =
    regs::Reg32<kFLEXIO3_base, FLEXIO_Layout, &FLEXIO_Layout::TIMCFG, Index,
                Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_TIMCMP_count)>>
using TIMCMP_Reg =
    regs::Reg32<kFLEXIO3_base, FLEXIO_Layout, &FLEXIO_Layout::TIMCMP, Index,
                Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTBUFNBS_count)>>
using SHIFTBUFNBS_Reg =
    regs::Reg32<kFLEXIO3_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTBUFNBS,
                Index, Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTBUFHWS_count)>>
using SHIFTBUFHWS_Reg =
    regs::Reg32<kFLEXIO3_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTBUFHWS,
                Index, Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXIO_SHIFTBUFNIS_count)>>
using SHIFTBUFNIS_Reg =
    regs::Reg32<kFLEXIO3_base, FLEXIO_Layout, &FLEXIO_Layout::SHIFTBUFNIS,
                Index, Bits, Shift, AssignMask, WriteOnly>;

// Version ID Register
namespace VERID {
constexpr FLEXIO3_Reg<&FLEXIO_Layout::VERID,  8, 24> MAJOR;
constexpr FLEXIO3_Reg<&FLEXIO_Layout::VERID,  8, 16> MINOR;
constexpr FLEXIO3_Reg<&FLEXIO_Layout::VERID, 16,  0> FEATURE;
}  // namespace VERID

// Parameter Register
namespace PARAM {
constexpr FLEXIO3_Reg<&FLEXIO_Layout::PARAM, 8, 24> TRIGGER;
constexpr FLEXIO3_Reg<&FLEXIO_Layout::PARAM, 8, 16> PIN;
constexpr FLEXIO3_Reg<&FLEXIO_Layout::PARAM, 8,  8> TIMER;
constexpr FLEXIO3_Reg<&FLEXIO_Layout::PARAM, 8,  0> SHIFTER;
}  // namespace PARAM

// FlexIO Control Register
namespace CTRL {
constexpr FLEXIO3_Reg<&FLEXIO_Layout::CTRL, 1, 31> DOZEN;
constexpr FLEXIO3_Reg<&FLEXIO_Layout::CTRL, 1, 30> DBGE;
constexpr FLEXIO3_Reg<&FLEXIO_Layout::CTRL, 1,  2> FASTACC;
constexpr FLEXIO3_Reg<&FLEXIO_Layout::CTRL, 1,  1> SWRST;
constexpr FLEXIO3_Reg<&FLEXIO_Layout::CTRL, 1,  0> FLEXEN;
}  // namespace CTRL

// Pin State Register
namespace PIN {
constexpr FLEXIO3_Reg<&FLEXIO_Layout::PIN, 32, 0> PDI;
}  // namespace PIN

// Shifter Status Register
namespace SHIFTSTAT {
constexpr FLEXIO3_Reg<&FLEXIO_Layout::SHIFTSTAT, 8, 0, 0x0> SSF;
}  // namespace SHIFTSTAT

// Shifter Error Register
namespace SHIFTERR {
constexpr FLEXIO3_Reg<&FLEXIO_Layout::SHIFTERR, 8, 0, 0x0> SEF;
}  // namespace SHIFTERR

// Timer Status Register
namespace TIMSTAT {
constexpr FLEXIO3_Reg<&FLEXIO_Layout::TIMSTAT, 8, 0, 0x0> TSF;
}  // namespace TIMSTAT

// Shifter Status Interrupt Enable
namespace SHIFTSIEN {
constexpr FLEXIO3_Reg<&FLEXIO_Layout::SHIFTSIEN, 8, 0> SSIE;
}  // namespace SHIFTSIEN

// Shifter Error Interrupt Enable
namespace SHIFTEIEN {
constexpr FLEXIO3_Reg<&FLEXIO_Layout::SHIFTEIEN, 8, 0> SEIE;
}  // namespace SHIFTEIEN

// Timer Interrupt Enable Register
namespace TIMIEN {
constexpr FLEXIO3_Reg<&FLEXIO_Layout::TIMIEN, 8, 0> TEIE;
}  // namespace TIMIEN

// Shifter Status DMA Enable
namespace SHIFTSDEN {
constexpr FLEXIO3_Reg<&FLEXIO_Layout::SHIFTSDEN, 8, 0> SSDE;
}  // namespace SHIFTSDEN

// Shifter State Register
namespace SHIFTSTATE {
constexpr FLEXIO3_Reg<&FLEXIO_Layout::SHIFTSTATE, 3, 0> STATE;
}  // namespace SHIFTSTATE

// Shifter Control N Register
namespace SHIFTCTL {
template <size_t Index>
constexpr SHIFTCTL_Reg<Index, 3, 24> TIMSEL;
template <size_t Index>
constexpr SHIFTCTL_Reg<Index, 1, 23> TIMPOL;
template <size_t Index>
constexpr SHIFTCTL_Reg<Index, 2, 16> PINCFG;
template <size_t Index>
constexpr SHIFTCTL_Reg<Index, 5,  8> PINSEL;
template <size_t Index>
constexpr SHIFTCTL_Reg<Index, 1,  7> PINPOL;
template <size_t Index>
constexpr SHIFTCTL_Reg<Index, 3,  0> SMOD;
}  // namespace SHIFTCTL

// Shifter Configuration N Register
namespace SHIFTCFG {
template <size_t Index>
constexpr SHIFTCFG_Reg<Index, 5, 16> PWIDTH;
template <size_t Index>
constexpr SHIFTCFG_Reg<Index, 1,  8> INSRC;
template <size_t Index>
constexpr SHIFTCFG_Reg<Index, 2,  4> SSTOP;
template <size_t Index>
constexpr SHIFTCFG_Reg<Index, 2,  0> SSTART;
}  // namespace SHIFTCFG

// Shifter Buffer N Register
namespace SHIFTBUF {
template <size_t Index>
constexpr SHIFTBUF_Reg<Index, 32, 0> SHIFTBUF;
}  // namespace SHIFTBUF

// Shifter Buffer N Bit Swapped Register
namespace SHIFTBUFBIS {
template <size_t Index>
constexpr SHIFTBUFBIS_Reg<Index, 32, 0> SHIFTBUFBIS;
}  // namespace SHIFTBUFBIS

// Shifter Buffer N Byte Swapped Register
namespace SHIFTBUFBYS {
template <size_t Index>
constexpr SHIFTBUFBYS_Reg<Index, 32, 0> SHIFTBUFBYS;
}  // namespace SHIFTBUFBYS

// Shifter Buffer N Bit Byte Swapped Register
namespace SHIFTBUFBBS {
template <size_t Index>
constexpr SHIFTBUFBBS_Reg<Index, 32, 0> SHIFTBUFBBS;
}  // namespace SHIFTBUFBBS

// Timer Control N Register
namespace TIMCTL {
template <size_t Index>
constexpr TIMCTL_Reg<Index, 6, 24> TRGSEL;
template <size_t Index>
constexpr TIMCTL_Reg<Index, 1, 23> TRGPOL;
template <size_t Index>
constexpr TIMCTL_Reg<Index, 1, 22> TRGSRC;
template <size_t Index>
constexpr TIMCTL_Reg<Index, 2, 16> PINCFG;
template <size_t Index>
constexpr TIMCTL_Reg<Index, 5,  8> PINSEL;
template <size_t Index>
constexpr TIMCTL_Reg<Index, 1,  7> PINPOL;
template <size_t Index>
constexpr TIMCTL_Reg<Index, 2,  0> TIMOD;
}  // namespace TIMCTL

// Timer Configuration N Register
namespace TIMCFG {
template <size_t Index>
constexpr TIMCFG_Reg<Index, 2, 24> TIMOUT;
template <size_t Index>
constexpr TIMCFG_Reg<Index, 2, 20> TIMDEC;
template <size_t Index>
constexpr TIMCFG_Reg<Index, 3, 16> TIMRST;
template <size_t Index>
constexpr TIMCFG_Reg<Index, 3, 12> TIMDIS;
template <size_t Index>
constexpr TIMCFG_Reg<Index, 3,  8> TIMENA;
template <size_t Index>
constexpr TIMCFG_Reg<Index, 2,  4> TSTOP;
template <size_t Index>
constexpr TIMCFG_Reg<Index, 1,  1> TSTART;
}  // namespace TIMCFG

// Timer Compare N Register
namespace TIMCMP {
template <size_t Index>
constexpr TIMCMP_Reg<Index, 16, 0> CMP;
}  // namespace TIMCMP

// Shifter Buffer N Nibble Byte Swapped Register
namespace SHIFTBUFNBS {
template <size_t Index>
constexpr SHIFTBUFNBS_Reg<Index, 32, 0> SHIFTBUFNBS;
}  // namespace SHIFTBUFNBS

// Shifter Buffer N Half Word Swapped Register
namespace SHIFTBUFHWS {
template <size_t Index>
constexpr SHIFTBUFHWS_Reg<Index, 32, 0> SHIFTBUFHWS;
}  // namespace SHIFTBUFHWS

// Shifter Buffer N Nibble Swapped Register
namespace SHIFTBUFNIS {
template <size_t Index>
constexpr SHIFTBUFNIS_Reg<Index, 32, 0> SHIFTBUFNIS;
}  // namespace SHIFTBUFNIS

}  // namespace FLEXIO3

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
