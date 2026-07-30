// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// PIT.h defines all the PIT registers.
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
constexpr size_t kPIT_CHANNEL_count = 4;

// Structure type to access the Periodic Interrupt Timer (PIT) registers.
//
// Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_PIT.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct PIT_Layout {
  volatile uint32_t MCR;                               /**< PIT Module Control Register, offset: 0x0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[55];
  const volatile uint32_t LTMR64H;                    /**< PIT Upper Lifetime Timer Register, offset: 0xE0 */
  const volatile uint32_t LTMR64L;                    /**< PIT Lower Lifetime Timer Register, offset: 0xE4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[6];
  struct CHANNEL_Layout {                             /* offset: 0x100, array step: 0x10 */
    volatile uint32_t LDVAL;                            /**< Timer Load Value Register, array offset: 0x100, array step: 0x10 */
    const volatile uint32_t CVAL;                       /**< Current Timer Value Register, array offset: 0x104, array step: 0x10 */
    volatile uint32_t TCTRL;                            /**< Timer Control Register, array offset: 0x108, array step: 0x10 */
    volatile uint32_t TFLG;                             /**< Timer Flag Register, array offset: 0x10C, array step: 0x10 */
  } CHANNEL[kPIT_CHANNEL_count];
};

constexpr size_t    kPIT_size = 0x140;
constexpr uintptr_t kPIT_base = 0x40084000;

namespace PIT {
constexpr regs::RegGroup<PIT_Layout, kPIT_size, kPIT_base> group;
}  // namespace PIT

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>()>
using PIT_Reg =
    regs::Reg32<kPIT_base, PIT_Layout, Member, 0, Bits, Shift, AssignMask>;

namespace PIT {

template <size_t Index,
          typename = std::enable_if_t<(Index < kPIT_CHANNEL_count)>>
constexpr uintptr_t ChannelBase() {
  return kPIT_base + offsetof(PIT_Layout, CHANNEL) +
         Index*sizeof(PIT_Layout::CHANNEL_Layout);
}

template <size_t Index, auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>()>
using CHANNEL_Reg =
    regs::Reg32<ChannelBase<Index>(), PIT_Layout::CHANNEL_Layout, Member, 0,
                Bits, Shift, AssignMask>;

// PIT Module Control Register
namespace MCR {
constexpr PIT_Reg<&PIT_Layout::MCR, 1, 1> MDIS;  // Module Disable for PIT
    // 0b0..Clock for standard PIT timers is enabled.
    // 0b1..Clock for standard PIT timers is disabled.
constexpr PIT_Reg<&PIT_Layout::MCR, 1, 0> FRZ;   // Freeze
    // 0b0..Timers continue to run in Debug mode.
    // 0b1..Timers are stopped in Debug mode.
}  // namespace MCR

// PIT Upper Lifetime Timer Register
namespace LTMR64H {
constexpr PIT_Reg<&PIT_Layout::LTMR64H, 32, 0> LTH;  // Life Timer value
}  // namespace LTMR64H

// PIT Lower Lifetime Timer Register
namespace LTMR64L {
constexpr PIT_Reg<&PIT_Layout::LTMR64L, 32, 0> LTL;  // Life Timer value
}  // namespace LTMR64L

namespace CHANNEL {

// Timer Load Value Register
namespace LDVAL {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &PIT_Layout::CHANNEL_Layout::LDVAL, 32, 0> TSV;  // Timer Start Value
}  // namespace LDVAL

// Current Timer Value Register
namespace CVAL {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &PIT_Layout::CHANNEL_Layout::CVAL, 32, 0> TVL;  // Current Timer Value
}  // namespace CVAL

// Timer Control Register
namespace TCTRL {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &PIT_Layout::CHANNEL_Layout::TCTRL, 1, 2> CHN;  // Chain Mode
    // 0b0..Timer is not chained.
    // 0b1..Timer is chained to a previous timer. For example, for channel 2, if this field is set, Timer 2 is chained to Timer 1.
template <size_t Index>
constexpr CHANNEL_Reg<Index, &PIT_Layout::CHANNEL_Layout::TCTRL, 1, 1> TIE;  // Timer Interrupt Enable
    // 0b0..Interrupt requests from Timer n are disabled.
    // 0b1..Interrupt is requested whenever TIF is set.
template <size_t Index>
constexpr CHANNEL_Reg<Index, &PIT_Layout::CHANNEL_Layout::TCTRL, 1, 0> TEN;  // Timer Enable
    // 0b0..Timer n is disabled.
    // 0b1..Timer n is enabled.
}  // namespace TCTRL

// Timer Flag Register
namespace TFLG {
template <size_t Index>
constexpr CHANNEL_Reg<Index, &PIT_Layout::CHANNEL_Layout::TFLG, 1, 0, 0x0> TIF;  // Timer Interrupt Flag
    // 0b0..Timeout has not yet occurred.
    // 0b1..Timeout has occurred.
}  // namespace TFLG

}  // namespace CHANNEL

}  // namespace PIT

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
