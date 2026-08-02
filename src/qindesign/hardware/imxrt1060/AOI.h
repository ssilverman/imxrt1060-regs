// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// AOI.h defines all the AOI registers.
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
constexpr size_t kAOI_BFCRT_count = 4;

// Structure type to access the And-Or-Inverter (AOI) registers.
//
// Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_AOI.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct AOI_Layout {
  struct BFCRT_Layout {                                /* offset: 0x0, array step: 0x4 */
    volatile uint16_t BFCRT01;                           /**< Boolean Function Term 0 and 1 Configuration Register, array offset: 0x0, array step: 0x4 */
    volatile uint16_t BFCRT23;                           /**< Boolean Function Term 2 and 3 Configuration Register, array offset: 0x2, array step: 0x4 */
  } BFCRT[kAOI_BFCRT_count];
};

constexpr size_t    kAOI_size  = 0x10;
constexpr uintptr_t kAOI1_base = 0x403B'4000;
constexpr uintptr_t kAOI2_base = 0x403B'8000;

namespace AOI1 {
constexpr regs::RegGroup<AOI_Layout, kAOI_size, kAOI1_base> group;
}  // namespace AOI1

namespace AOI2 {
constexpr regs::RegGroup<AOI_Layout, kAOI_size, kAOI2_base> group;
}  // namespace AOI2

namespace AOI1 {

template <size_t Index,
          typename = std::enable_if_t<(Index < kAOI_BFCRT_count)>>
constexpr uintptr_t BfcrtBase() {
  return kAOI1_base + offsetof(AOI_Layout, BFCRT) +
         Index * sizeof(AOI_Layout::BFCRT_Layout);
}

template <size_t Index, auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask16<Bits, Shift>()>
using BFCRT_Reg = regs::Reg16<BfcrtBase<Index>(), AOI_Layout::BFCRT_Layout,
                              Member, 0, Bits, Shift, AssignMask>;

namespace BFCRT {

// Boolean Function Term 0 and 1 Configuration Register
namespace BFCRT01 {
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT01, 2, 14> PT0_AC;  // Product term 0, A input configuration
    // 0b00..Force the A input in this product term to a logical zero.
    // 0b01..Pass the A input in this product term.
    // 0b10..Complement the A input in this product term.
    // 0b11..Force the A input in this product term to a logical one.
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT01, 2, 12> PT0_BC;  // Product term 0, B input configuration
    // 0b00..Force the B input in this product term to a logical zero.
    // 0b01..Pass the B input in this product term.
    // 0b10..Complement the B input in this product term.
    // 0b11..Force the B input in this product term to a logical one.
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT01, 2, 10> PT0_CC;  // Product term 0, C input configuration
    // 0b00..Force the C input in this product term to a logical zero.
    // 0b01..Pass the C input in this product term.
    // 0b10..Complement the C input in this product term.
    // 0b11..Force the C input in this product term to a logical one.
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT01, 2,  8> PT0_DC;  // Product term 0, D input configuration
    // 0b00..Force the D input in this product term to a logical zero.
    // 0b01..Pass the D input in this product term.
    // 0b10..Complement the D input in this product term.
    // 0b11..Force the D input in this product term to a logical one.
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT01, 2,  6> PT1_AC;  // Product term 1, A input configuration
    // 0b00..Force the A input in this product term to a logical zero.
    // 0b01..Pass the A input in this product term.
    // 0b10..Complement the A input in this product term.
    // 0b11..Force the A input in this product term to a logical one.
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT01, 2,  4> PT1_BC;  // Product term 1, B input configuration
    // 0b00..Force the B input in this product term to a logical zero.
    // 0b01..Pass the B input in this product term.
    // 0b10..Complement the B input in this product term.
    // 0b11..Force the B input in this product term to a logical one.
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT01, 2,  2> PT1_CC;  // Product term 1, C input configuration
    // 0b00..Force the C input in this product term to a logical zero.
    // 0b01..Pass the C input in this product term.
    // 0b10..Complement the C input in this product term.
    // 0b11..Force the C input in this product term to a logical one.
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT01, 2,  0> PT1_DC;  // Product term 1, D input configuration
    // 0b00..Force the D input in this product term to a logical zero.
    // 0b01..Pass the D input in this product term.
    // 0b10..Complement the D input in this product term.
    // 0b11..Force the D input in this product term to a logical one.
}  // namespace BFCRT01

// Boolean Function Term 2 and 3 Configuration Register
namespace BFCRT23 {
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT23, 2, 14> PT2_AC;  // Product term 2, A input configuration
    // 0b00..Force the A input in this product term to a logical zero.
    // 0b01..Pass the A input in this product term.
    // 0b10..Complement the A input in this product term.
    // 0b11..Force the A input in this product term to a logical one.
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT23, 2, 12> PT2_BC;  // Product term 2, B input configuration
    // 0b00..Force the B input in this product term to a logical zero.
    // 0b01..Pass the B input in this product term.
    // 0b10..Complement the B input in this product term.
    // 0b11..Force the B input in this product term to a logical one.
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT23, 2, 10> PT2_CC;  // Product term 2, C input configuration
    // 0b00..Force the C input in this product term to a logical zero.
    // 0b01..Pass the C input in this product term.
    // 0b10..Complement the C input in this product term.
    // 0b11..Force the C input in this product term to a logical one.
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT23, 2,  8> PT2_DC;  // Product term 2, D input configuration
    // 0b00..Force the D input in this product term to a logical zero.
    // 0b01..Pass the D input in this product term.
    // 0b10..Complement the D input in this product term.
    // 0b11..Force the D input in this product term to a logical one.
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT23, 2,  6> PT3_AC;  // Product term 3, A input configuration
    // 0b00..Force the A input in this product term to a logical zero.
    // 0b01..Pass the A input in this product term.
    // 0b10..Complement the A input in this product term.
    // 0b11..Force the A input in this product term to a logical one.
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT23, 2,  4> PT3_BC;  // Product term 3, B input configuration
    // 0b00..Force the B input in this product term to a logical zero.
    // 0b01..Pass the B input in this product term.
    // 0b10..Complement the B input in this product term.
    // 0b11..Force the B input in this product term to a logical one.
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT23, 2,  2> PT3_CC;  // Product term 3, C input configuration
    // 0b00..Force the C input in this product term to a logical zero.
    // 0b01..Pass the C input in this product term.
    // 0b10..Complement the C input in this product term.
    // 0b11..Force the C input in this product term to a logical one.
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT23, 2,  0> PT3_DC;  // Product term 3, D input configuration
    // 0b00..Force the D input in this product term to a logical zero.
    // 0b01..Pass the D input in this product term.
    // 0b10..Complement the D input in this product term.
    // 0b11..Force the D input in this product term to a logical one.
}  // namespace BFCRT23

}  // namespace BFCRT

}  // namespace AOI1

namespace AOI2 {

template <size_t Index,
          typename = std::enable_if_t<(Index < kAOI_BFCRT_count)>>
constexpr uintptr_t BfcrtBase() {
  return kAOI2_base + offsetof(AOI_Layout, BFCRT) +
         Index * sizeof(AOI_Layout::BFCRT_Layout);
}

template <size_t Index, auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask16<Bits, Shift>()>
using BFCRT_Reg = regs::Reg16<BfcrtBase<Index>(), AOI_Layout::BFCRT_Layout,
                              Member, 0, Bits, Shift, AssignMask>;

namespace BFCRT {

// AOI2 Boolean Function Term 0 and 1 Configuration Register
namespace BFCRT01 {
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT01, 2, 14> PT0_AC;
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT01, 2, 12> PT0_BC;
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT01, 2, 10> PT0_CC;
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT01, 2,  8> PT0_DC;
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT01, 2,  6> PT1_AC;
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT01, 2,  4> PT1_BC;
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT01, 2,  2> PT1_CC;
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT01, 2,  0> PT1_DC;
}  // namespace BFCRT01

// AOI2 Boolean Function Term 2 and 3 Configuration Register
namespace BFCRT23 {
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT23, 2, 14> PT2_AC;
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT23, 2, 12> PT2_BC;
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT23, 2, 10> PT2_CC;
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT23, 2,  8> PT2_DC;
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT23, 2,  6> PT3_AC;
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT23, 2,  4> PT3_BC;
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT23, 2,  2> PT3_CC;
template <size_t Index>
constexpr BFCRT_Reg<Index, &AOI_Layout::BFCRT_Layout::BFCRT23, 2,  0> PT3_DC;
}  // namespace BFCRT23

}  // namespace BFCRT

}  // namespace AOI2

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
