// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// XBARA.h defines all the XBARA registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "qindesign/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the Inter-Peripheral Crossbar Switch A
// (XBARA) registers.
//
// Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_XBARA.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct XBARA_Layout {
  volatile uint16_t SEL0;                              /**< Crossbar A Select Register 0, offset: 0x0 */
  volatile uint16_t SEL1;                              /**< Crossbar A Select Register 1, offset: 0x2 */
  volatile uint16_t SEL2;                              /**< Crossbar A Select Register 2, offset: 0x4 */
  volatile uint16_t SEL3;                              /**< Crossbar A Select Register 3, offset: 0x6 */
  volatile uint16_t SEL4;                              /**< Crossbar A Select Register 4, offset: 0x8 */
  volatile uint16_t SEL5;                              /**< Crossbar A Select Register 5, offset: 0xA */
  volatile uint16_t SEL6;                              /**< Crossbar A Select Register 6, offset: 0xC */
  volatile uint16_t SEL7;                              /**< Crossbar A Select Register 7, offset: 0xE */
  volatile uint16_t SEL8;                              /**< Crossbar A Select Register 8, offset: 0x10 */
  volatile uint16_t SEL9;                              /**< Crossbar A Select Register 9, offset: 0x12 */
  volatile uint16_t SEL10;                             /**< Crossbar A Select Register 10, offset: 0x14 */
  volatile uint16_t SEL11;                             /**< Crossbar A Select Register 11, offset: 0x16 */
  volatile uint16_t SEL12;                             /**< Crossbar A Select Register 12, offset: 0x18 */
  volatile uint16_t SEL13;                             /**< Crossbar A Select Register 13, offset: 0x1A */
  volatile uint16_t SEL14;                             /**< Crossbar A Select Register 14, offset: 0x1C */
  volatile uint16_t SEL15;                             /**< Crossbar A Select Register 15, offset: 0x1E */
  volatile uint16_t SEL16;                             /**< Crossbar A Select Register 16, offset: 0x20 */
  volatile uint16_t SEL17;                             /**< Crossbar A Select Register 17, offset: 0x22 */
  volatile uint16_t SEL18;                             /**< Crossbar A Select Register 18, offset: 0x24 */
  volatile uint16_t SEL19;                             /**< Crossbar A Select Register 19, offset: 0x26 */
  volatile uint16_t SEL20;                             /**< Crossbar A Select Register 20, offset: 0x28 */
  volatile uint16_t SEL21;                             /**< Crossbar A Select Register 21, offset: 0x2A */
  volatile uint16_t SEL22;                             /**< Crossbar A Select Register 22, offset: 0x2C */
  volatile uint16_t SEL23;                             /**< Crossbar A Select Register 23, offset: 0x2E */
  volatile uint16_t SEL24;                             /**< Crossbar A Select Register 24, offset: 0x30 */
  volatile uint16_t SEL25;                             /**< Crossbar A Select Register 25, offset: 0x32 */
  volatile uint16_t SEL26;                             /**< Crossbar A Select Register 26, offset: 0x34 */
  volatile uint16_t SEL27;                             /**< Crossbar A Select Register 27, offset: 0x36 */
  volatile uint16_t SEL28;                             /**< Crossbar A Select Register 28, offset: 0x38 */
  volatile uint16_t SEL29;                             /**< Crossbar A Select Register 29, offset: 0x3A */
  volatile uint16_t SEL30;                             /**< Crossbar A Select Register 30, offset: 0x3C */
  volatile uint16_t SEL31;                             /**< Crossbar A Select Register 31, offset: 0x3E */
  volatile uint16_t SEL32;                             /**< Crossbar A Select Register 32, offset: 0x40 */
  volatile uint16_t SEL33;                             /**< Crossbar A Select Register 33, offset: 0x42 */
  volatile uint16_t SEL34;                             /**< Crossbar A Select Register 34, offset: 0x44 */
  volatile uint16_t SEL35;                             /**< Crossbar A Select Register 35, offset: 0x46 */
  volatile uint16_t SEL36;                             /**< Crossbar A Select Register 36, offset: 0x48 */
  volatile uint16_t SEL37;                             /**< Crossbar A Select Register 37, offset: 0x4A */
  volatile uint16_t SEL38;                             /**< Crossbar A Select Register 38, offset: 0x4C */
  volatile uint16_t SEL39;                             /**< Crossbar A Select Register 39, offset: 0x4E */
  volatile uint16_t SEL40;                             /**< Crossbar A Select Register 40, offset: 0x50 */
  volatile uint16_t SEL41;                             /**< Crossbar A Select Register 41, offset: 0x52 */
  volatile uint16_t SEL42;                             /**< Crossbar A Select Register 42, offset: 0x54 */
  volatile uint16_t SEL43;                             /**< Crossbar A Select Register 43, offset: 0x56 */
  volatile uint16_t SEL44;                             /**< Crossbar A Select Register 44, offset: 0x58 */
  volatile uint16_t SEL45;                             /**< Crossbar A Select Register 45, offset: 0x5A */
  volatile uint16_t SEL46;                             /**< Crossbar A Select Register 46, offset: 0x5C */
  volatile uint16_t SEL47;                             /**< Crossbar A Select Register 47, offset: 0x5E */
  volatile uint16_t SEL48;                             /**< Crossbar A Select Register 48, offset: 0x60 */
  volatile uint16_t SEL49;                             /**< Crossbar A Select Register 49, offset: 0x62 */
  volatile uint16_t SEL50;                             /**< Crossbar A Select Register 50, offset: 0x64 */
  volatile uint16_t SEL51;                             /**< Crossbar A Select Register 51, offset: 0x66 */
  volatile uint16_t SEL52;                             /**< Crossbar A Select Register 52, offset: 0x68 */
  volatile uint16_t SEL53;                             /**< Crossbar A Select Register 53, offset: 0x6A */
  volatile uint16_t SEL54;                             /**< Crossbar A Select Register 54, offset: 0x6C */
  volatile uint16_t SEL55;                             /**< Crossbar A Select Register 55, offset: 0x6E */
  volatile uint16_t SEL56;                             /**< Crossbar A Select Register 56, offset: 0x70 */
  volatile uint16_t SEL57;                             /**< Crossbar A Select Register 57, offset: 0x72 */
  volatile uint16_t SEL58;                             /**< Crossbar A Select Register 58, offset: 0x74 */
  volatile uint16_t SEL59;                             /**< Crossbar A Select Register 59, offset: 0x76 */
  volatile uint16_t SEL60;                             /**< Crossbar A Select Register 60, offset: 0x78 */
  volatile uint16_t SEL61;                             /**< Crossbar A Select Register 61, offset: 0x7A */
  volatile uint16_t SEL62;                             /**< Crossbar A Select Register 62, offset: 0x7C */
  volatile uint16_t SEL63;                             /**< Crossbar A Select Register 63, offset: 0x7E */
  volatile uint16_t SEL64;                             /**< Crossbar A Select Register 64, offset: 0x80 */
  volatile uint16_t SEL65;                             /**< Crossbar A Select Register 65, offset: 0x82 */
  volatile uint16_t CTRL0;                             /**< Crossbar A Control Register 0, offset: 0x84 */
  volatile uint16_t CTRL1;                             /**< Crossbar A Control Register 1, offset: 0x86 */
};

constexpr size_t    kXBARA_size  = 0x88;
constexpr uintptr_t kXBARA1_base = 0x403B'C000;

namespace XBARA1 {
constexpr regs::RegGroup<XBARA_Layout, kXBARA_size, kXBARA1_base> group;
}  // namespace XBARA1

namespace XBARA1 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask16<Bits, Shift>()>
using XBARA1_Reg =
    regs::Reg16<kXBARA1_base, XBARA_Layout, Member, 0, Bits, Shift, AssignMask>;

// Crossbar A Select Register 0
namespace SEL0 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL0, 7, 8> SEL1;  // Input (XBARA_INn) to be muxed to XBARA_OUT1 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL0, 7, 0> SEL0;  // Input (XBARA_INn) to be muxed to XBARA_OUT0 (refer to Functional Description section for input/output assignment)
}  // namespace SEL0

// Crossbar A Select Register 1
namespace SEL1 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL1, 7, 8> SEL3;  // Input (XBARA_INn) to be muxed to XBARA_OUT3 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL1, 7, 0> SEL2;  // Input (XBARA_INn) to be muxed to XBARA_OUT2 (refer to Functional Description section for input/output assignment)
}  // namespace SEL1

// Crossbar A Select Register 2
namespace SEL2 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL2, 7, 8> SEL5;  // Input (XBARA_INn) to be muxed to XBARA_OUT5 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL2, 7, 0> SEL4;  // Input (XBARA_INn) to be muxed to XBARA_OUT4 (refer to Functional Description section for input/output assignment)
}  // namespace SEL2

// Crossbar A Select Register 3
namespace SEL3 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL3, 7, 8> SEL7;  // Input (XBARA_INn) to be muxed to XBARA_OUT7 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL3, 7, 0> SEL6;  // Input (XBARA_INn) to be muxed to XBARA_OUT6 (refer to Functional Description section for input/output assignment)
}  // namespace SEL3

// Crossbar A Select Register 4
namespace SEL4 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL4, 7, 8> SEL9;  // Input (XBARA_INn) to be muxed to XBARA_OUT9 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL4, 7, 0> SEL8;  // Input (XBARA_INn) to be muxed to XBARA_OUT8 (refer to Functional Description section for input/output assignment)
}  // namespace SEL4

// Crossbar A Select Register 5
namespace SEL5 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL5, 7, 8> SEL11;  // Input (XBARA_INn) to be muxed to XBARA_OUT11 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL5, 7, 0> SEL10;  // Input (XBARA_INn) to be muxed to XBARA_OUT10 (refer to Functional Description section for input/output assignment)
}  // namespace SEL5

// Crossbar A Select Register 6
namespace SEL6 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL6, 7, 8> SEL13;  // Input (XBARA_INn) to be muxed to XBARA_OUT13 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL6, 7, 0> SEL12;  // Input (XBARA_INn) to be muxed to XBARA_OUT12 (refer to Functional Description section for input/output assignment)
}  // namespace SEL6

// Crossbar A Select Register 7
namespace SEL7 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL7, 7, 8> SEL15;  // Input (XBARA_INn) to be muxed to XBARA_OUT15 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL7, 7, 0> SEL14;  // Input (XBARA_INn) to be muxed to XBARA_OUT14 (refer to Functional Description section for input/output assignment)
}  // namespace SEL7

// Crossbar A Select Register 8
namespace SEL8 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL8, 7, 8> SEL17;  // Input (XBARA_INn) to be muxed to XBARA_OUT17 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL8, 7, 0> SEL16;  // Input (XBARA_INn) to be muxed to XBARA_OUT16 (refer to Functional Description section for input/output assignment)
}  // namespace SEL8

// Crossbar A Select Register 9
namespace SEL9 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL9, 7, 8> SEL19;  // Input (XBARA_INn) to be muxed to XBARA_OUT19 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL9, 7, 0> SEL18;  // Input (XBARA_INn) to be muxed to XBARA_OUT18 (refer to Functional Description section for input/output assignment)
}  // namespace SEL9

// Crossbar A Select Register 10
namespace SEL10 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL10, 7, 8> SEL21;  // Input (XBARA_INn) to be muxed to XBARA_OUT21 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL10, 7, 0> SEL20;  // Input (XBARA_INn) to be muxed to XBARA_OUT20 (refer to Functional Description section for input/output assignment)
}  // namespace SEL10

// Crossbar A Select Register 11
namespace SEL11 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL11, 7, 8> SEL23;  // Input (XBARA_INn) to be muxed to XBARA_OUT23 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL11, 7, 0> SEL22;  // Input (XBARA_INn) to be muxed to XBARA_OUT22 (refer to Functional Description section for input/output assignment)
}  // namespace SEL11

// Crossbar A Select Register 12
namespace SEL12 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL12, 7, 8> SEL25;  // Input (XBARA_INn) to be muxed to XBARA_OUT25 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL12, 7, 0> SEL24;  // Input (XBARA_INn) to be muxed to XBARA_OUT24 (refer to Functional Description section for input/output assignment)
}  // namespace SEL12

// Crossbar A Select Register 13
namespace SEL13 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL13, 7, 8> SEL27;  // Input (XBARA_INn) to be muxed to XBARA_OUT27 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL13, 7, 0> SEL26;  // Input (XBARA_INn) to be muxed to XBARA_OUT26 (refer to Functional Description section for input/output assignment)
}  // namespace SEL13

// Crossbar A Select Register 14
namespace SEL14 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL14, 7, 8> SEL29;  // Input (XBARA_INn) to be muxed to XBARA_OUT29 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL14, 7, 0> SEL28;  // Input (XBARA_INn) to be muxed to XBARA_OUT28 (refer to Functional Description section for input/output assignment)
}  // namespace SEL14

// Crossbar A Select Register 15
namespace SEL15 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL15, 7, 8> SEL31;  // Input (XBARA_INn) to be muxed to XBARA_OUT31 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL15, 7, 0> SEL30;  // Input (XBARA_INn) to be muxed to XBARA_OUT30 (refer to Functional Description section for input/output assignment)
}  // namespace SEL15

// Crossbar A Select Register 16
namespace SEL16 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL16, 7, 8> SEL33;  // Input (XBARA_INn) to be muxed to XBARA_OUT33 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL16, 7, 0> SEL32;  // Input (XBARA_INn) to be muxed to XBARA_OUT32 (refer to Functional Description section for input/output assignment)
}  // namespace SEL16

// Crossbar A Select Register 17
namespace SEL17 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL17, 7, 8> SEL35;  // Input (XBARA_INn) to be muxed to XBARA_OUT35 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL17, 7, 0> SEL34;  // Input (XBARA_INn) to be muxed to XBARA_OUT34 (refer to Functional Description section for input/output assignment)
}  // namespace SEL17

// Crossbar A Select Register 18
namespace SEL18 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL18, 7, 8> SEL37;  // Input (XBARA_INn) to be muxed to XBARA_OUT37 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL18, 7, 0> SEL36;  // Input (XBARA_INn) to be muxed to XBARA_OUT36 (refer to Functional Description section for input/output assignment)
}  // namespace SEL18

// Crossbar A Select Register 19
namespace SEL19 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL19, 7, 8> SEL39;  // Input (XBARA_INn) to be muxed to XBARA_OUT39 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL19, 7, 0> SEL38;  // Input (XBARA_INn) to be muxed to XBARA_OUT38 (refer to Functional Description section for input/output assignment)
}  // namespace SEL19

// Crossbar A Select Register 20
namespace SEL20 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL20, 7, 8> SEL41;  // Input (XBARA_INn) to be muxed to XBARA_OUT41 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL20, 7, 0> SEL40;  // Input (XBARA_INn) to be muxed to XBARA_OUT40 (refer to Functional Description section for input/output assignment)
}  // namespace SEL20

// Crossbar A Select Register 21
namespace SEL21 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL21, 7, 8> SEL43;  // Input (XBARA_INn) to be muxed to XBARA_OUT43 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL21, 7, 0> SEL42;  // Input (XBARA_INn) to be muxed to XBARA_OUT42 (refer to Functional Description section for input/output assignment)
}  // namespace SEL21

// Crossbar A Select Register 22
namespace SEL22 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL22, 7, 8> SEL45;  // Input (XBARA_INn) to be muxed to XBARA_OUT45 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL22, 7, 0> SEL44;  // Input (XBARA_INn) to be muxed to XBARA_OUT44 (refer to Functional Description section for input/output assignment)
}  // namespace SEL22

// Crossbar A Select Register 23
namespace SEL23 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL23, 7, 8> SEL47;  // Input (XBARA_INn) to be muxed to XBARA_OUT47 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL23, 7, 0> SEL46;  // Input (XBARA_INn) to be muxed to XBARA_OUT46 (refer to Functional Description section for input/output assignment)
}  // namespace SEL23

// Crossbar A Select Register 24
namespace SEL24 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL24, 7, 8> SEL49;  // Input (XBARA_INn) to be muxed to XBARA_OUT49 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL24, 7, 0> SEL48;  // Input (XBARA_INn) to be muxed to XBARA_OUT48 (refer to Functional Description section for input/output assignment)
}  // namespace SEL24

// Crossbar A Select Register 25
namespace SEL25 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL25, 7, 8> SEL51;  // Input (XBARA_INn) to be muxed to XBARA_OUT51 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL25, 7, 0> SEL50;  // Input (XBARA_INn) to be muxed to XBARA_OUT50 (refer to Functional Description section for input/output assignment)
}  // namespace SEL25

// Crossbar A Select Register 26
namespace SEL26 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL26, 7, 8> SEL53;  // Input (XBARA_INn) to be muxed to XBARA_OUT53 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL26, 7, 0> SEL52;  // Input (XBARA_INn) to be muxed to XBARA_OUT52 (refer to Functional Description section for input/output assignment)
}  // namespace SEL26

// Crossbar A Select Register 27
namespace SEL27 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL27, 7, 8> SEL55;  // Input (XBARA_INn) to be muxed to XBARA_OUT55 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL27, 7, 0> SEL54;  // Input (XBARA_INn) to be muxed to XBARA_OUT54 (refer to Functional Description section for input/output assignment)
}  // namespace SEL27

// Crossbar A Select Register 28
namespace SEL28 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL28, 7, 8> SEL57;  // Input (XBARA_INn) to be muxed to XBARA_OUT57 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL28, 7, 0> SEL56;  // Input (XBARA_INn) to be muxed to XBARA_OUT56 (refer to Functional Description section for input/output assignment)
}  // namespace SEL28

// Crossbar A Select Register 29
namespace SEL29 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL29, 7, 8> SEL59;  // Input (XBARA_INn) to be muxed to XBARA_OUT59 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL29, 7, 0> SEL58;  // Input (XBARA_INn) to be muxed to XBARA_OUT58 (refer to Functional Description section for input/output assignment)
}  // namespace SEL29

// Crossbar A Select Register 30
namespace SEL30 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL30, 7, 8> SEL61;  // Input (XBARA_INn) to be muxed to XBARA_OUT61 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL30, 7, 0> SEL60;  // Input (XBARA_INn) to be muxed to XBARA_OUT60 (refer to Functional Description section for input/output assignment)
}  // namespace SEL30

// Crossbar A Select Register 31
namespace SEL31 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL31, 7, 8> SEL63;  // Input (XBARA_INn) to be muxed to XBARA_OUT63 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL31, 7, 0> SEL62;  // Input (XBARA_INn) to be muxed to XBARA_OUT62 (refer to Functional Description section for input/output assignment)
}  // namespace SEL31

// Crossbar A Select Register 32
namespace SEL32 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL32, 7, 8> SEL65;  // Input (XBARA_INn) to be muxed to XBARA_OUT65 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL32, 7, 0> SEL64;  // Input (XBARA_INn) to be muxed to XBARA_OUT64 (refer to Functional Description section for input/output assignment)
}  // namespace SEL32

// Crossbar A Select Register 33
namespace SEL33 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL33, 7, 8> SEL67;  // Input (XBARA_INn) to be muxed to XBARA_OUT67 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL33, 7, 0> SEL66;  // Input (XBARA_INn) to be muxed to XBARA_OUT66 (refer to Functional Description section for input/output assignment)
}  // namespace SEL33

// Crossbar A Select Register 34
namespace SEL34 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL34, 7, 8> SEL69;  // Input (XBARA_INn) to be muxed to XBARA_OUT69 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL34, 7, 0> SEL68;  // Input (XBARA_INn) to be muxed to XBARA_OUT68 (refer to Functional Description section for input/output assignment)
}  // namespace SEL34

// Crossbar A Select Register 35
namespace SEL35 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL35, 7, 8> SEL71;  // Input (XBARA_INn) to be muxed to XBARA_OUT71 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL35, 7, 0> SEL70;  // Input (XBARA_INn) to be muxed to XBARA_OUT70 (refer to Functional Description section for input/output assignment)
}  // namespace SEL35

// Crossbar A Select Register 36
namespace SEL36 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL36, 7, 8> SEL73;  // Input (XBARA_INn) to be muxed to XBARA_OUT73 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL36, 7, 0> SEL72;  // Input (XBARA_INn) to be muxed to XBARA_OUT72 (refer to Functional Description section for input/output assignment)
}  // namespace SEL36

// Crossbar A Select Register 37
namespace SEL37 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL37, 7, 8> SEL75;  // Input (XBARA_INn) to be muxed to XBARA_OUT75 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL37, 7, 0> SEL74;  // Input (XBARA_INn) to be muxed to XBARA_OUT74 (refer to Functional Description section for input/output assignment)
}  // namespace SEL37

// Crossbar A Select Register 38
namespace SEL38 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL38, 7, 8> SEL77;  // Input (XBARA_INn) to be muxed to XBARA_OUT77 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL38, 7, 0> SEL76;  // Input (XBARA_INn) to be muxed to XBARA_OUT76 (refer to Functional Description section for input/output assignment)
}  // namespace SEL38

// Crossbar A Select Register 39
namespace SEL39 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL39, 7, 8> SEL79;  // Input (XBARA_INn) to be muxed to XBARA_OUT79 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL39, 7, 0> SEL78;  // Input (XBARA_INn) to be muxed to XBARA_OUT78 (refer to Functional Description section for input/output assignment)
}  // namespace SEL39

// Crossbar A Select Register 40
namespace SEL40 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL40, 7, 8> SEL81;  // Input (XBARA_INn) to be muxed to XBARA_OUT81 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL40, 7, 0> SEL80;  // Input (XBARA_INn) to be muxed to XBARA_OUT80 (refer to Functional Description section for input/output assignment)
}  // namespace SEL40

// Crossbar A Select Register 41
namespace SEL41 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL41, 7, 8> SEL83;  // Input (XBARA_INn) to be muxed to XBARA_OUT83 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL41, 7, 0> SEL82;  // Input (XBARA_INn) to be muxed to XBARA_OUT82 (refer to Functional Description section for input/output assignment)
}  // namespace SEL41

// Crossbar A Select Register 42
namespace SEL42 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL42, 7, 8> SEL85;  // Input (XBARA_INn) to be muxed to XBARA_OUT85 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL42, 7, 0> SEL84;  // Input (XBARA_INn) to be muxed to XBARA_OUT84 (refer to Functional Description section for input/output assignment)
}  // namespace SEL42

// Crossbar A Select Register 43
namespace SEL43 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL43, 7, 8> SEL87;  // Input (XBARA_INn) to be muxed to XBARA_OUT87 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL43, 7, 0> SEL86;  // Input (XBARA_INn) to be muxed to XBARA_OUT86 (refer to Functional Description section for input/output assignment)
}  // namespace SEL43

// Crossbar A Select Register 44
namespace SEL44 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL44, 7, 8> SEL89;  // Input (XBARA_INn) to be muxed to XBARA_OUT89 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL44, 7, 0> SEL88;  // Input (XBARA_INn) to be muxed to XBARA_OUT88 (refer to Functional Description section for input/output assignment)
}  // namespace SEL44

// Crossbar A Select Register 45
namespace SEL45 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL45, 7, 8> SEL91;  // Input (XBARA_INn) to be muxed to XBARA_OUT91 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL45, 7, 0> SEL90;  // Input (XBARA_INn) to be muxed to XBARA_OUT90 (refer to Functional Description section for input/output assignment)
}  // namespace SEL45

// Crossbar A Select Register 46
namespace SEL46 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL46, 7, 8> SEL93;  // Input (XBARA_INn) to be muxed to XBARA_OUT93 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL46, 7, 0> SEL92;  // Input (XBARA_INn) to be muxed to XBARA_OUT92 (refer to Functional Description section for input/output assignment)
}  // namespace SEL46

// Crossbar A Select Register 47
namespace SEL47 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL47, 7, 8> SEL95;  // Input (XBARA_INn) to be muxed to XBARA_OUT95 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL47, 7, 0> SEL94;  // Input (XBARA_INn) to be muxed to XBARA_OUT94 (refer to Functional Description section for input/output assignment)
}  // namespace SEL47

// Crossbar A Select Register 48
namespace SEL48 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL48, 7, 8> SEL97;  // Input (XBARA_INn) to be muxed to XBARA_OUT97 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL48, 7, 0> SEL96;  // Input (XBARA_INn) to be muxed to XBARA_OUT96 (refer to Functional Description section for input/output assignment)
}  // namespace SEL48

// Crossbar A Select Register 49
namespace SEL49 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL49, 7, 8> SEL99;  // Input (XBARA_INn) to be muxed to XBARA_OUT99 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL49, 7, 0> SEL98;  // Input (XBARA_INn) to be muxed to XBARA_OUT98 (refer to Functional Description section for input/output assignment)
}  // namespace SEL49

// Crossbar A Select Register 50
namespace SEL50 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL50, 7, 8> SEL101;  // Input (XBARA_INn) to be muxed to XBARA_OUT101 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL50, 7, 0> SEL100;  // Input (XBARA_INn) to be muxed to XBARA_OUT100 (refer to Functional Description section for input/output assignment)
}  // namespace SEL50

// Crossbar A Select Register 51
namespace SEL51 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL51, 7, 8> SEL103;  // Input (XBARA_INn) to be muxed to XBARA_OUT103 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL51, 7, 0> SEL102;  // Input (XBARA_INn) to be muxed to XBARA_OUT102 (refer to Functional Description section for input/output assignment)
}  // namespace SEL51

// Crossbar A Select Register 52
namespace SEL52 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL52, 7, 8> SEL105;  // Input (XBARA_INn) to be muxed to XBARA_OUT105 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL52, 7, 0> SEL104;  // Input (XBARA_INn) to be muxed to XBARA_OUT104 (refer to Functional Description section for input/output assignment)
}  // namespace SEL52

// Crossbar A Select Register 53
namespace SEL53 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL53, 7, 8> SEL107;  // Input (XBARA_INn) to be muxed to XBARA_OUT107 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL53, 7, 0> SEL106;  // Input (XBARA_INn) to be muxed to XBARA_OUT106 (refer to Functional Description section for input/output assignment)
}  // namespace SEL53

// Crossbar A Select Register 54
namespace SEL54 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL54, 7, 8> SEL109;  // Input (XBARA_INn) to be muxed to XBARA_OUT109 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL54, 7, 0> SEL108;  // Input (XBARA_INn) to be muxed to XBARA_OUT108 (refer to Functional Description section for input/output assignment)
}  // namespace SEL54

// Crossbar A Select Register 55
namespace SEL55 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL55, 7, 8> SEL111;  // Input (XBARA_INn) to be muxed to XBARA_OUT111 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL55, 7, 0> SEL110;  // Input (XBARA_INn) to be muxed to XBARA_OUT110 (refer to Functional Description section for input/output assignment)
}  // namespace SEL55

// Crossbar A Select Register 56
namespace SEL56 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL56, 7, 8> SEL113;  // Input (XBARA_INn) to be muxed to XBARA_OUT113 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL56, 7, 0> SEL112;  // Input (XBARA_INn) to be muxed to XBARA_OUT112 (refer to Functional Description section for input/output assignment)
}  // namespace SEL56

// Crossbar A Select Register 57
namespace SEL57 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL57, 7, 8> SEL115;  // Input (XBARA_INn) to be muxed to XBARA_OUT115 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL57, 7, 0> SEL114;  // Input (XBARA_INn) to be muxed to XBARA_OUT114 (refer to Functional Description section for input/output assignment)
}  // namespace SEL57

// Crossbar A Select Register 58
namespace SEL58 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL58, 7, 8> SEL117;  // Input (XBARA_INn) to be muxed to XBARA_OUT117 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL58, 7, 0> SEL116;  // Input (XBARA_INn) to be muxed to XBARA_OUT116 (refer to Functional Description section for input/output assignment)
}  // namespace SEL58

// Crossbar A Select Register 59
namespace SEL59 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL59, 7, 8> SEL119;  // Input (XBARA_INn) to be muxed to XBARA_OUT119 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL59, 7, 0> SEL118;  // Input (XBARA_INn) to be muxed to XBARA_OUT118 (refer to Functional Description section for input/output assignment)
}  // namespace SEL59

// Crossbar A Select Register 60
namespace SEL60 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL60, 7, 8> SEL121;  // Input (XBARA_INn) to be muxed to XBARA_OUT121 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL60, 7, 0> SEL120;  // Input (XBARA_INn) to be muxed to XBARA_OUT120 (refer to Functional Description section for input/output assignment)
}  // namespace SEL60

// Crossbar A Select Register 61
namespace SEL61 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL61, 7, 8> SEL123;  // Input (XBARA_INn) to be muxed to XBARA_OUT123 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL61, 7, 0> SEL122;  // Input (XBARA_INn) to be muxed to XBARA_OUT122 (refer to Functional Description section for input/output assignment)
}  // namespace SEL61

// Crossbar A Select Register 62
namespace SEL62 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL62, 7, 8> SEL125;  // Input (XBARA_INn) to be muxed to XBARA_OUT125 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL62, 7, 0> SEL124;  // Input (XBARA_INn) to be muxed to XBARA_OUT124 (refer to Functional Description section for input/output assignment)
}  // namespace SEL62

// Crossbar A Select Register 63
namespace SEL63 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL63, 7, 8> SEL127;  // Input (XBARA_INn) to be muxed to XBARA_OUT127 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL63, 7, 0> SEL126;  // Input (XBARA_INn) to be muxed to XBARA_OUT126 (refer to Functional Description section for input/output assignment)
}  // namespace SEL63

// Crossbar A Select Register 64
namespace SEL64 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL64, 7, 8> SEL129;  // Input (XBARA_INn) to be muxed to XBARA_OUT129 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL64, 7, 0> SEL128;  // Input (XBARA_INn) to be muxed to XBARA_OUT128 (refer to Functional Description section for input/output assignment)
}  // namespace SEL64

// Crossbar A Select Register 65
namespace SEL65 {
constexpr XBARA1_Reg<&XBARA_Layout::SEL65, 7, 8> SEL131;  // Input (XBARA_INn) to be muxed to XBARA_OUT131 (refer to Functional Description section for input/output assignment)
constexpr XBARA1_Reg<&XBARA_Layout::SEL65, 7, 0> SEL130;  // Input (XBARA_INn) to be muxed to XBARA_OUT130 (refer to Functional Description section for input/output assignment)
}  // namespace SEL65

// Crossbar A Control Register 0
namespace CTRL0 {
constexpr uint16_t kW1C = 0x1010;

constexpr XBARA1_Reg<&XBARA_Layout::CTRL0, 1, 12, kW1C> STS1;                                  // Edge detection status for XBAR_OUT1
    // 0b0..Active edge not yet detected on XBAR_OUT1
    // 0b1..Active edge detected on XBAR_OUT1
constexpr XBARA1_Reg<&XBARA_Layout::CTRL0, 2, 10, regs::shiftedMask16<2, 10>() | kW1C> EDGE1;  // Active edge for edge detection on XBAR_OUT1
    // 0b00..STS1 never asserts
    // 0b01..STS1 asserts on rising edges of XBAR_OUT1
    // 0b10..STS1 asserts on falling edges of XBAR_OUT1
    // 0b11..STS1 asserts on rising and falling edges of XBAR_OUT1
constexpr XBARA1_Reg<&XBARA_Layout::CTRL0, 1,  9, regs::shiftedMask16<1,  9>() | kW1C> IEN1;   // Interrupt Enable for XBAR_OUT1
    // 0b0..Interrupt disabled
    // 0b1..Interrupt enabled
constexpr XBARA1_Reg<&XBARA_Layout::CTRL0, 1,  8, regs::shiftedMask16<1,  8>() | kW1C> DEN1;   // DMA Enable for XBAR_OUT1
    // 0b0..DMA disabled
    // 0b1..DMA enabled
constexpr XBARA1_Reg<&XBARA_Layout::CTRL0, 1,  4, kW1C> STS0;                                  // Edge detection status for XBAR_OUT0
    // 0b0..Active edge not yet detected on XBAR_OUT0
    // 0b1..Active edge detected on XBAR_OUT0
constexpr XBARA1_Reg<&XBARA_Layout::CTRL0, 2,  2, regs::shiftedMask16<2,  2>() | kW1C> EDGE0;  // Active edge for edge detection on XBAR_OUT0
    // 0b00..STS0 never asserts
    // 0b01..STS0 asserts on rising edges of XBAR_OUT0
    // 0b10..STS0 asserts on falling edges of XBAR_OUT0
    // 0b11..STS0 asserts on rising and falling edges of XBAR_OUT0
constexpr XBARA1_Reg<&XBARA_Layout::CTRL0, 1,  1, regs::shiftedMask16<1,  1>() | kW1C> IEN0;   // Interrupt Enable for XBAR_OUT0
    // 0b0..Interrupt disabled
    // 0b1..Interrupt enabled
constexpr XBARA1_Reg<&XBARA_Layout::CTRL0, 1,  0, regs::shiftedMask16<1,  0>() | kW1C> DEN0;   // DMA Enable for XBAR_OUT0
    // 0b0..DMA disabled
    // 0b1..DMA enabled
}  // namespace CTRL0

// Crossbar A Control Register 1
namespace CTRL1 {
constexpr uint16_t kW1C = 0x1010;

constexpr XBARA1_Reg<&XBARA_Layout::CTRL1, 1, 12, kW1C> STS3;                                  // Edge detection status for XBAR_OUT3
    // 0b0..Active edge not yet detected on XBAR_OUT3
    // 0b1..Active edge detected on XBAR_OUT3
constexpr XBARA1_Reg<&XBARA_Layout::CTRL1, 2, 10, regs::shiftedMask16<2, 10>() | kW1C> EDGE3;  // Active edge for edge detection on XBAR_OUT3
    // 0b00..STS3 never asserts
    // 0b01..STS3 asserts on rising edges of XBAR_OUT3
    // 0b10..STS3 asserts on falling edges of XBAR_OUT3
    // 0b11..STS3 asserts on rising and falling edges of XBAR_OUT3
constexpr XBARA1_Reg<&XBARA_Layout::CTRL1, 1,  9, regs::shiftedMask16<1,  9>() | kW1C> IEN3;   // Interrupt Enable for XBAR_OUT3
    // 0b0..Interrupt disabled
    // 0b1..Interrupt enabled
constexpr XBARA1_Reg<&XBARA_Layout::CTRL1, 1,  8, regs::shiftedMask16<1,  8>() | kW1C> DEN3;   // DMA Enable for XBAR_OUT3
    // 0b0..DMA disabled
    // 0b1..DMA enabled
constexpr XBARA1_Reg<&XBARA_Layout::CTRL1, 1,  4, kW1C> STS2;                                  // Edge detection status for XBAR_OUT2
    // 0b0..Active edge not yet detected on XBAR_OUT2
    // 0b1..Active edge detected on XBAR_OUT2
constexpr XBARA1_Reg<&XBARA_Layout::CTRL1, 2,  2, regs::shiftedMask16<2,  2>() | kW1C> EDGE2;  // Active edge for edge detection on XBAR_OUT2
    // 0b00..STS2 never asserts
    // 0b01..STS2 asserts on rising edges of XBAR_OUT2
    // 0b10..STS2 asserts on falling edges of XBAR_OUT2
    // 0b11..STS2 asserts on rising and falling edges of XBAR_OUT2
constexpr XBARA1_Reg<&XBARA_Layout::CTRL1, 1,  1, regs::shiftedMask16<1,  1>() | kW1C> IEN2;   // Interrupt Enable for XBAR_OUT2
    // 0b0..Interrupt disabled
    // 0b1..Interrupt enabled
constexpr XBARA1_Reg<&XBARA_Layout::CTRL1, 1,  0, regs::shiftedMask16<1,  0>() | kW1C> DEN2;   // DMA Enable for XBAR_OUT2
    // 0b0..DMA disabled
    // 0b1..DMA enabled
}  // namespace CTRL1

namespace IN {
constexpr uint16_t kLOGIC_LOW               = 0;
constexpr uint16_t kLOGIC_HIGH              = 1;
constexpr uint16_t kIOMUX_XBAR_IN02         = 2;
constexpr uint16_t kIOMUX_XBAR_IN03         = 3;
constexpr uint16_t kIOMUX_XBAR_INOUT04      = 4;
constexpr uint16_t kIOMUX_XBAR_INOUT05      = 5;
constexpr uint16_t kIOMUX_XBAR_INOUT06      = 6;
constexpr uint16_t kIOMUX_XBAR_INOUT07      = 7;
constexpr uint16_t kIOMUX_XBAR_INOUT08      = 8;
constexpr uint16_t kIOMUX_XBAR_INOUT09      = 9;
constexpr uint16_t kIOMUX_XBAR_INOUT10      = 10;
constexpr uint16_t kIOMUX_XBAR_INOUT11      = 11;
constexpr uint16_t kIOMUX_XBAR_INOUT12      = 12;
constexpr uint16_t kIOMUX_XBAR_INOUT13      = 13;
constexpr uint16_t kIOMUX_XBAR_INOUT14      = 14;
constexpr uint16_t kIOMUX_XBAR_INOUT15      = 15;
constexpr uint16_t kIOMUX_XBAR_INOUT16      = 16;
constexpr uint16_t kIOMUX_XBAR_INOUT17      = 17;
constexpr uint16_t kIOMUX_XBAR_INOUT18      = 18;
constexpr uint16_t kIOMUX_XBAR_INOUT19      = 19;
constexpr uint16_t kIOMUX_XBAR_IN20         = 20;
constexpr uint16_t kIOMUX_XBAR_IN21         = 21;
constexpr uint16_t kIOMUX_XBAR_IN22         = 22;
constexpr uint16_t kIOMUX_XBAR_IN23         = 23;
constexpr uint16_t kIOMUX_XBAR_IN24         = 24;
constexpr uint16_t kIOMUX_XBAR_IN25         = 25;
constexpr uint16_t kACMP1_OUT               = 26;
constexpr uint16_t kACMP2_OUT               = 27;
constexpr uint16_t kACMP3_OUT               = 28;
constexpr uint16_t kACMP4_OUT               = 29;
// Reserved 30
// Reserved 31
constexpr uint16_t kQTIMER3_TIMER0          = 32;
constexpr uint16_t kQTIMER3_TIMER1          = 33;
constexpr uint16_t kQTIMER3_TIMER2          = 34;
constexpr uint16_t kQTIMER3_TIMER3          = 35;
constexpr uint16_t kQTIMER4_TIMER0          = 36;
constexpr uint16_t kQTIMER4_TIMER1          = 37;
constexpr uint16_t kQTIMER4_TIMER2          = 38;
constexpr uint16_t kQTIMER4_TIMER3          = 39;
constexpr uint16_t kFLEXPWM1_PWM1_OUT_TRIG0 = 40;
constexpr uint16_t kFLEXPWM1_PWM1_OUT_TRIG1 = 40;
constexpr uint16_t kFLEXPWM1_PWM2_OUT_TRIG0 = 41;
constexpr uint16_t kFLEXPWM1_PWM2_OUT_TRIG1 = 41;
constexpr uint16_t kFLEXPWM1_PWM3_OUT_TRIG0 = 42;
constexpr uint16_t kFLEXPWM1_PWM3_OUT_TRIG1 = 42;
constexpr uint16_t kFLEXPWM1_PWM4_OUT_TRIG0 = 43;
constexpr uint16_t kFLEXPWM1_PWM4_OUT_TRIG1 = 43;
constexpr uint16_t kFLEXPWM2_PWM1_OUT_TRIG0 = 44;
constexpr uint16_t kFLEXPWM2_PWM1_OUT_TRIG1 = 44;
constexpr uint16_t kFLEXPWM2_PWM2_OUT_TRIG0 = 45;
constexpr uint16_t kFLEXPWM2_PWM2_OUT_TRIG1 = 45;
constexpr uint16_t kFLEXPWM2_PWM3_OUT_TRIG0 = 46;
constexpr uint16_t kFLEXPWM2_PWM3_OUT_TRIG1 = 46;
constexpr uint16_t kFLEXPWM2_PWM4_OUT_TRIG0 = 47;
constexpr uint16_t kFLEXPWM2_PWM4_OUT_TRIG1 = 47;
constexpr uint16_t kFLEXPWM3_PWM1_OUT_TRIG0 = 48;
constexpr uint16_t kFLEXPWM3_PWM1_OUT_TRIG1 = 48;
constexpr uint16_t kFLEXPWM3_PWM2_OUT_TRIG0 = 49;
constexpr uint16_t kFLEXPWM3_PWM2_OUT_TRIG1 = 49;
constexpr uint16_t kFLEXPWM3_PWM3_OUT_TRIG0 = 50;
constexpr uint16_t kFLEXPWM3_PWM3_OUT_TRIG1 = 50;
constexpr uint16_t kFLEXPWM3_PWM4_OUT_TRIG0 = 51;
constexpr uint16_t kFLEXPWM3_PWM4_OUT_TRIG1 = 51;
constexpr uint16_t kFLEXPWM4_PWM1_OUT_TRIG0 = 52;
constexpr uint16_t kFLEXPWM4_PWM1_OUT_TRIG1 = 52;
constexpr uint16_t kFLEXPWM4_PWM2_OUT_TRIG0 = 53;
constexpr uint16_t kFLEXPWM4_PWM2_OUT_TRIG1 = 53;
constexpr uint16_t kFLEXPWM4_PWM3_OUT_TRIG0 = 54;
constexpr uint16_t kFLEXPWM4_PWM3_OUT_TRIG1 = 54;
constexpr uint16_t kFLEXPWM4_PWM4_OUT_TRIG0 = 55;
constexpr uint16_t kFLEXPWM4_PWM4_OUT_TRIG1 = 55;
constexpr uint16_t kPIT_TRIGGER0            = 56;
constexpr uint16_t kPIT_TRIGGER1            = 57;
constexpr uint16_t kPIT_TRIGGER2            = 58;
constexpr uint16_t kPIT_TRIGGER3            = 59;
constexpr uint16_t kENC1_POS_MATCH          = 60;
constexpr uint16_t kENC2_POS_MATCH          = 61;
constexpr uint16_t kENC3_POS_MATCH          = 62;
constexpr uint16_t kENC4_POS_MATCH          = 63;
constexpr uint16_t kDMA_DONE0               = 64;
constexpr uint16_t kDMA_DONE1               = 65;
constexpr uint16_t kDMA_DONE2               = 66;
constexpr uint16_t kDMA_DONE3               = 67;
constexpr uint16_t kDMA_DONE4               = 68;
constexpr uint16_t kDMA_DONE5               = 69;
constexpr uint16_t kDMA_DONE6               = 70;
constexpr uint16_t kDMA_DONE7               = 71;
constexpr uint16_t kAOI1_OUT0               = 72;
constexpr uint16_t kAOI1_OUT1               = 73;
constexpr uint16_t kAOI1_OUT2               = 74;
constexpr uint16_t kAOI1_OUT3               = 75;
constexpr uint16_t kAOI2_OUT0               = 76;
constexpr uint16_t kAOI2_OUT1               = 77;
constexpr uint16_t kAOI2_OUT2               = 78;
constexpr uint16_t kAOI2_OUT3               = 79;
constexpr uint16_t kADC_ETC0_COCO0          = 80;
constexpr uint16_t kADC_ETC0_COCO1          = 81;
constexpr uint16_t kADC_ETC0_COCO2          = 82;
constexpr uint16_t kADC_ETC0_COCO3          = 83;
constexpr uint16_t kADC_ETC1_COCO0          = 84;
constexpr uint16_t kADC_ETC1_COCO1          = 85;
constexpr uint16_t kADC_ETC1_COCO2          = 86;
constexpr uint16_t kADC_ETC1_COCO3          = 87;
}  // namespace IN

namespace OUT {
constexpr uint16_t kDMA_CH_MUX_REQ30       = 0;
constexpr uint16_t kDMA_CH_MUX_REQ31       = 1;
constexpr uint16_t kDMA_CH_MUX_REQ94       = 2;
constexpr uint16_t kDMA_CH_MUX_REQ95       = 3;
constexpr uint16_t kIOMUX_XBAR_INOUT04     = 4;
constexpr uint16_t kIOMUX_XBAR_INOUT05     = 5;
constexpr uint16_t kIOMUX_XBAR_INOUT06     = 6;
constexpr uint16_t kIOMUX_XBAR_INOUT07     = 7;
constexpr uint16_t kIOMUX_XBAR_INOUT08     = 8;
constexpr uint16_t kIOMUX_XBAR_INOUT09     = 9;
constexpr uint16_t kIOMUX_XBAR_INOUT10     = 10;
constexpr uint16_t kIOMUX_XBAR_INOUT11     = 11;
constexpr uint16_t kIOMUX_XBAR_INOUT12     = 12;
constexpr uint16_t kIOMUX_XBAR_INOUT13     = 13;
constexpr uint16_t kIOMUX_XBAR_INOUT14     = 14;
constexpr uint16_t kIOMUX_XBAR_INOUT15     = 15;
constexpr uint16_t kIOMUX_XBAR_INOUT16     = 16;
constexpr uint16_t kIOMUX_XBAR_INOUT17     = 17;
constexpr uint16_t kIOMUX_XBAR_INOUT18     = 18;
constexpr uint16_t kIOMUX_XBAR_INOUT19     = 19;
constexpr uint16_t kACMP1_SAMPLE           = 20;
constexpr uint16_t kACMP2_SAMPLE           = 21;
constexpr uint16_t kACMP3_SAMPLE           = 22;
constexpr uint16_t kACMP4_SAMPLE           = 23;
// Reserved 24
// Reserved 25
constexpr uint16_t kFLEXPWM1_PWM0_EXTA     = 26;
constexpr uint16_t kFLEXPWM1_PWM1_EXTA     = 27;
constexpr uint16_t kFLEXPWM1_PWM2_EXTA     = 28;
constexpr uint16_t kFLEXPWM1_PWM3_EXTA     = 29;
constexpr uint16_t kFLEXPWM1_PWM0_EXT_SYNC = 30;
constexpr uint16_t kFLEXPWM1_PWM1_EXT_SYNC = 31;
constexpr uint16_t kFLEXPWM1_PWM2_EXT_SYNC = 32;
constexpr uint16_t kFLEXPWM1_PWM3_EXT_SYNC = 33;
constexpr uint16_t kFLEXPWM1_EXT_CLK       = 34;
constexpr uint16_t kFLEXPWM1_FAULT0        = 35;
constexpr uint16_t kFLEXPWM1_FAULT1        = 36;
constexpr uint16_t kFLEXPWM1_FAULT2        = 37;
constexpr uint16_t kFLEXPWM2_FAULT2        = 37;
constexpr uint16_t kFLEXPWM3_FAULT2        = 37;
constexpr uint16_t kFLEXPWM4_FAULT2        = 37;
constexpr uint16_t kFLEXPWM1_FAULT3        = 38;
constexpr uint16_t kFLEXPWM2_FAULT3        = 38;
constexpr uint16_t kFLEXPWM3_FAULT3        = 38;
constexpr uint16_t kFLEXPWM4_FAULT3        = 38;
constexpr uint16_t kFLEXPWM1_EXT_FORCE     = 39;
constexpr uint16_t kFLEXPWM2_PWM0_EXTA     = 40;
constexpr uint16_t kFLEXPWM3_PWM0_EXTA     = 40;
constexpr uint16_t kFLEXPWM4_PWM0_EXTA     = 40;
constexpr uint16_t kFLEXPWM2_PWM1_EXTA     = 41;
constexpr uint16_t kFLEXPWM3_PWM1_EXTA     = 41;
constexpr uint16_t kFLEXPWM4_PWM1_EXTA     = 41;
constexpr uint16_t kFLEXPWM2_PWM2_EXTA     = 42;
constexpr uint16_t kFLEXPWM3_PWM2_EXTA     = 42;
constexpr uint16_t kFLEXPWM4_PWM2_EXTA     = 42;
constexpr uint16_t kFLEXPWM2_PWM3_EXTA     = 43;
constexpr uint16_t kFLEXPWM3_PWM3_EXTA     = 43;
constexpr uint16_t kFLEXPWM4_PWM3_EXTA     = 43;
constexpr uint16_t kFLEXPWM2_PWM0_EXT_SYNC = 44;
constexpr uint16_t kFLEXPWM2_PWM1_EXT_SYNC = 45;
constexpr uint16_t kFLEXPWM2_PWM2_EXT_SYNC = 46;
constexpr uint16_t kFLEXPWM2_PWM3_EXT_SYNC = 47;
constexpr uint16_t kFLEXPWM2_EXT_CLK       = 48;
constexpr uint16_t kFLEXPWM3_EXT_CLK       = 48;
constexpr uint16_t kFLEXPWM4_EXT_CLK       = 48;
constexpr uint16_t kFLEXPWM2_FAULT0        = 49;
constexpr uint16_t kFLEXPWM2_FAULT1        = 50;
constexpr uint16_t kFLEXPWM2_EXT_FORCE     = 51;
constexpr uint16_t kFLEXPWM3_EXT_SYNC0     = 52;
constexpr uint16_t kFLEXPWM3_EXT_SYNC1     = 53;
constexpr uint16_t kFLEXPWM3_EXT_SYNC2     = 54;
constexpr uint16_t kFLEXPWM3_EXT_SYNC3     = 55;
constexpr uint16_t kFLEXPWM3_FAULT0        = 56;
constexpr uint16_t kFLEXPWM3_FAULT1        = 57;
constexpr uint16_t kFLEXPWM3_EXT_FORCE     = 58;
constexpr uint16_t kFLEXPWM4_EXT_SYNC0     = 59;
constexpr uint16_t kFLEXPWM4_EXT_SYNC1     = 60;
constexpr uint16_t kFLEXPWM4_EXT_SYNC2     = 61;
constexpr uint16_t kFLEXPWM4_EXT_SYNC3     = 62;
constexpr uint16_t kFLEXPWM4_FAULT0        = 63;
constexpr uint16_t kFLEXPWM4_FAULT1        = 64;
constexpr uint16_t kFLEXPWM4_EXT_FORCE     = 65;
constexpr uint16_t kENC1_PHASEA_INPUT      = 66;
constexpr uint16_t kENC1_PHASEB_INPUT      = 67;
constexpr uint16_t kENC1_INDEX             = 68;
constexpr uint16_t kENC1_HOME              = 69;
constexpr uint16_t kENC1_TRIGGER           = 70;
constexpr uint16_t kENC2_PHASEA_INPUT      = 71;
constexpr uint16_t kENC2_PHASEB_INPUT      = 72;
constexpr uint16_t kENC2_INDEX             = 73;
constexpr uint16_t kENC2_HOME              = 74;
constexpr uint16_t kENC2_TRIGGER           = 75;
constexpr uint16_t kENC3_PHASEA_INPUT      = 76;
constexpr uint16_t kENC3_PHASEB_INPUT      = 77;
constexpr uint16_t kENC3_INDEX             = 78;
constexpr uint16_t kENC3_HOME              = 79;
constexpr uint16_t kENC3_TRIGGER           = 80;
constexpr uint16_t kENC4_PHASEA_INPUT      = 81;
constexpr uint16_t kENC4_PHASEB_INPUT      = 82;
constexpr uint16_t kENC4_INDEX             = 83;
constexpr uint16_t kENC4_HOME              = 84;
constexpr uint16_t kENC4_TRIGGER           = 85;
constexpr uint16_t kQTIMER1_TIMER0         = 86;
constexpr uint16_t kQTIMER1_TIMER1         = 87;
constexpr uint16_t kQTIMER1_TIMER2         = 88;
constexpr uint16_t kQTIMER1_TIMER3         = 89;
constexpr uint16_t kQTIMER2_TIMER0         = 90;
constexpr uint16_t kQTIMER2_TIMER1         = 91;
constexpr uint16_t kQTIMER2_TIMER2         = 92;
constexpr uint16_t kQTIMER2_TIMER3         = 93;
constexpr uint16_t kQTIMER3_TIMER0         = 94;
constexpr uint16_t kQTIMER3_TIMER1         = 95;
constexpr uint16_t kQTIMER3_TIMER2         = 96;
constexpr uint16_t kQTIMER3_TIMER3         = 97;
constexpr uint16_t kQTIMER4_TIMER0         = 98;
constexpr uint16_t kQTIMER4_TIMER1         = 99;
constexpr uint16_t kQTIMER4_TIMER2         = 100;
constexpr uint16_t kQTIMER4_TIMER3         = 101;
constexpr uint16_t kEWM_EWM_IN             = 102;
constexpr uint16_t kADC_ETC_TRIG00         = 103;
constexpr uint16_t kADC_ETC_TRIG01         = 104;
constexpr uint16_t kADC_ETC_TRIG02         = 105;
constexpr uint16_t kADC_ETC_TRIG03         = 106;
constexpr uint16_t kADC_ETC_TRIG10         = 107;
constexpr uint16_t kADC_ETC_TRIG11         = 108;
constexpr uint16_t kADC_ETC_TRIG12         = 109;
constexpr uint16_t kADC_ETC_TRIG13         = 110;
constexpr uint16_t kLPI2C1_TRG_INPUT       = 111;
constexpr uint16_t kLPI2C2_TRG_INPUT       = 112;
constexpr uint16_t kLPI2C3_TRG_INPUT       = 113;
constexpr uint16_t kLPI2C4_TRG_INPUT       = 114;
constexpr uint16_t kLPSPI1_TRG_INPUT       = 115;
constexpr uint16_t kLPSPI2_TRG_INPUT       = 116;
constexpr uint16_t kLPSPI3_TRG_INPUT       = 117;
constexpr uint16_t kLPSPI4_TRG_INPUT       = 118;
constexpr uint16_t kLPUART1_TRG_INPUT      = 119;
constexpr uint16_t kLPUART2_TRG_INPUT      = 120;
constexpr uint16_t kLPUART3_TRG_INPUT      = 121;
constexpr uint16_t kLPUART4_TRG_INPUT      = 122;
constexpr uint16_t kLPUART5_TRG_INPUT      = 123;
constexpr uint16_t kLPUART6_TRG_INPUT      = 124;
constexpr uint16_t kLPUART7_TRG_INPUT      = 125;
constexpr uint16_t kLPUART8_TRG_INPUT      = 126;
constexpr uint16_t kFLEXIO1_TRIGGER_IN0    = 127;
constexpr uint16_t kFLEXIO1_TRIGGER_IN1    = 128;
constexpr uint16_t kFLEXIO2_TRIGGER_IN0    = 129;
constexpr uint16_t kFLEXIO2_TRIGGER_IN1    = 130;
}  // namespace OUT

}  // namespace XBARA1

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
