// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// CCM_ANALOG.h defines all the CCM_ANALOG registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// CCM_ANALOG layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_CCM_ANALOG.h
// * https://github.com/nxp-mcuxpresso/legacy-mcux-sdk/blob/main/devices/MIMXRT1062/MIMXRT1062.h
struct CCM_ANALOG_Layout {
  volatile uint32_t PLL_ARM;                           /**< Analog ARM PLL control Register, offset: 0x0 */
  volatile uint32_t PLL_ARM_SET;                       /**< Analog ARM PLL control Register, offset: 0x4 */
  volatile uint32_t PLL_ARM_CLR;                       /**< Analog ARM PLL control Register, offset: 0x8 */
  volatile uint32_t PLL_ARM_TOG;                       /**< Analog ARM PLL control Register, offset: 0xC */
  volatile uint32_t PLL_USB1;                          /**< Analog USB1 480MHz PLL Control Register, offset: 0x10 */
  volatile uint32_t PLL_USB1_SET;                      /**< Analog USB1 480MHz PLL Control Register, offset: 0x14 */
  volatile uint32_t PLL_USB1_CLR;                      /**< Analog USB1 480MHz PLL Control Register, offset: 0x18 */
  volatile uint32_t PLL_USB1_TOG;                      /**< Analog USB1 480MHz PLL Control Register, offset: 0x1C */
  volatile uint32_t PLL_USB2;                          /**< Analog USB2 480MHz PLL Control Register, offset: 0x20 */
  volatile uint32_t PLL_USB2_SET;                      /**< Analog USB2 480MHz PLL Control Register, offset: 0x24 */
  volatile uint32_t PLL_USB2_CLR;                      /**< Analog USB2 480MHz PLL Control Register, offset: 0x28 */
  volatile uint32_t PLL_USB2_TOG;                      /**< Analog USB2 480MHz PLL Control Register, offset: 0x2C */
  volatile uint32_t PLL_SYS;                           /**< Analog System PLL Control Register, offset: 0x30 */
  volatile uint32_t PLL_SYS_SET;                       /**< Analog System PLL Control Register, offset: 0x34 */
  volatile uint32_t PLL_SYS_CLR;                       /**< Analog System PLL Control Register, offset: 0x38 */
  volatile uint32_t PLL_SYS_TOG;                       /**< Analog System PLL Control Register, offset: 0x3C */
  volatile uint32_t PLL_SYS_SS;                        /**< 528MHz System PLL Spread Spectrum Register, offset: 0x40 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PLL_SYS_NUM;                       /**< Numerator of 528MHz System PLL Fractional Loop Divider Register, offset: 0x50 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PLL_SYS_DENOM;                     /**< Denominator of 528MHz System PLL Fractional Loop Divider Register, offset: 0x60 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PLL_AUDIO;                         /**< Analog Audio PLL control Register, offset: 0x70 */
  volatile uint32_t PLL_AUDIO_SET;                     /**< Analog Audio PLL control Register, offset: 0x74 */
  volatile uint32_t PLL_AUDIO_CLR;                     /**< Analog Audio PLL control Register, offset: 0x78 */
  volatile uint32_t PLL_AUDIO_TOG;                     /**< Analog Audio PLL control Register, offset: 0x7C */
  volatile uint32_t PLL_AUDIO_NUM;                     /**< Numerator of Audio PLL Fractional Loop Divider Register, offset: 0x80 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PLL_AUDIO_DENOM;                   /**< Denominator of Audio PLL Fractional Loop Divider Register, offset: 0x90 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PLL_VIDEO;                         /**< Analog Video PLL control Register, offset: 0xA0 */
  volatile uint32_t PLL_VIDEO_SET;                     /**< Analog Video PLL control Register, offset: 0xA4 */
  volatile uint32_t PLL_VIDEO_CLR;                     /**< Analog Video PLL control Register, offset: 0xA8 */
  volatile uint32_t PLL_VIDEO_TOG;                     /**< Analog Video PLL control Register, offset: 0xAC */
  volatile uint32_t PLL_VIDEO_NUM;                     /**< Numerator of Video PLL Fractional Loop Divider Register, offset: 0xB0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PLL_VIDEO_DENOM;                   /**< Denominator of Video PLL Fractional Loop Divider Register, offset: 0xC0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[7];
  volatile uint32_t PLL_ENET;                          /**< Analog ENET PLL Control Register, offset: 0xE0 */
  volatile uint32_t PLL_ENET_SET;                      /**< Analog ENET PLL Control Register, offset: 0xE4 */
  volatile uint32_t PLL_ENET_CLR;                      /**< Analog ENET PLL Control Register, offset: 0xE8 */
  volatile uint32_t PLL_ENET_TOG;                      /**< Analog ENET PLL Control Register, offset: 0xEC */
  volatile uint32_t PFD_480;                           /**< 480MHz Clock (PLL3) Phase Fractional Divider Control Register, offset: 0xF0 */
  volatile uint32_t PFD_480_SET;                       /**< 480MHz Clock (PLL3) Phase Fractional Divider Control Register, offset: 0xF4 */
  volatile uint32_t PFD_480_CLR;                       /**< 480MHz Clock (PLL3) Phase Fractional Divider Control Register, offset: 0xF8 */
  volatile uint32_t PFD_480_TOG;                       /**< 480MHz Clock (PLL3) Phase Fractional Divider Control Register, offset: 0xFC */
  volatile uint32_t PFD_528;                           /**< 528MHz Clock (PLL2) Phase Fractional Divider Control Register, offset: 0x100 */
  volatile uint32_t PFD_528_SET;                       /**< 528MHz Clock (PLL2) Phase Fractional Divider Control Register, offset: 0x104 */
  volatile uint32_t PFD_528_CLR;                       /**< 528MHz Clock (PLL2) Phase Fractional Divider Control Register, offset: 0x108 */
  volatile uint32_t PFD_528_TOG;                       /**< 528MHz Clock (PLL2) Phase Fractional Divider Control Register, offset: 0x10C */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[16];
  volatile uint32_t MISC0;                             /**< Miscellaneous Register 0, offset: 0x150 */
  volatile uint32_t MISC0_SET;                         /**< Miscellaneous Register 0, offset: 0x154 */
  volatile uint32_t MISC0_CLR;                         /**< Miscellaneous Register 0, offset: 0x158 */
  volatile uint32_t MISC0_TOG;                         /**< Miscellaneous Register 0, offset: 0x15C */
  volatile uint32_t MISC1;                             /**< Miscellaneous Register 1, offset: 0x160 */
  volatile uint32_t MISC1_SET;                         /**< Miscellaneous Register 1, offset: 0x164 */
  volatile uint32_t MISC1_CLR;                         /**< Miscellaneous Register 1, offset: 0x168 */
  volatile uint32_t MISC1_TOG;                         /**< Miscellaneous Register 1, offset: 0x16C */
  volatile uint32_t MISC2;                             /**< Miscellaneous Register 2, offset: 0x170 */
  volatile uint32_t MISC2_SET;                         /**< Miscellaneous Register 2, offset: 0x174 */
  volatile uint32_t MISC2_CLR;                         /**< Miscellaneous Register 2, offset: 0x178 */
  volatile uint32_t MISC2_TOG;                         /**< Miscellaneous Register 2, offset: 0x17C */
};

constexpr size_t    kCCM_ANALOG_size = 0x180;
constexpr uintptr_t kCCM_ANALOG_base = 0x400D8000;

namespace CCM_ANALOG {
constexpr regs::RegGroup<CCM_ANALOG_Layout, kCCM_ANALOG_size, kCCM_ANALOG_base>
    group;
}  // namespace CCM_ANALOG

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using CCM_ANALOG_Reg = regs::Reg32<kCCM_ANALOG_base, CCM_ANALOG_Layout, Member,
                                   0, Bits, Shift, DirectAssign>;

namespace CCM_ANALOG {

// Analog ARM PLL control Register
namespace PLL_ARM {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM, 1, 31> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM, 1, 19> PLL_SEL;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM, 1, 16> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM, 2, 14> BYPASS_CLK_SRC;
    // 0b00..Select the 24MHz oscillator as source.
    // 0b01..Select the CLK1_N / CLK1_P as source.
    // 0b10..Reserved1
    // 0b11..Reserved2
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM, 1, 13> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM, 1, 12> POWERDOWN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM, 7,  0> DIV_SELECT;
}  // namespace PLL_ARM

// Analog ARM PLL control Register
namespace PLL_ARM_SET {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_SET, 1, 31, true> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_SET, 1, 19, true> PLL_SEL;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_SET, 1, 16, true> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_SET, 2, 14, true> BYPASS_CLK_SRC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_SET, 1, 13, true> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_SET, 1, 12, true> POWERDOWN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_SET, 7,  0, true> DIV_SELECT;
}  // namespace PLL_ARM_SET

// Analog ARM PLL control Register
namespace PLL_ARM_CLR {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_CLR, 1, 31, true> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_CLR, 1, 19, true> PLL_SEL;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_CLR, 1, 16, true> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_CLR, 2, 14, true> BYPASS_CLK_SRC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_CLR, 1, 13, true> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_CLR, 1, 12, true> POWERDOWN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_CLR, 7,  0, true> DIV_SELECT;
}  // namespace PLL_ARM_CLR

// Analog ARM PLL control Register
namespace PLL_ARM_TOG {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_TOG, 1, 31, true> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_TOG, 1, 19, true> PLL_SEL;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_TOG, 1, 16, true> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_TOG, 2, 14, true> BYPASS_CLK_SRC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_TOG, 1, 13, true> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_TOG, 1, 12, true> POWERDOWN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_TOG, 7,  0, true> DIV_SELECT;
}  // namespace PLL_ARM_TOG

// Analog USB1 480MHz PLL Control Register
namespace PLL_USB1 {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1, 1, 31> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1, 1, 16> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1, 2, 14> BYPASS_CLK_SRC;
    // 0b00..Select the 24MHz oscillator as source.
    // 0b01..Select the CLK1_N / CLK1_P as source.
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1, 1, 13> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1, 1, 12> POWER;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1, 1,  6> EN_USB_CLKS;
    // 0b0..PLL outputs for USBPHYn off.
    // 0b1..PLL outputs for USBPHYn on.
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1, 1,  1> DIV_SELECT;
}  // namespace PLL_USB1

// Analog USB1 480MHz PLL Control Register
namespace PLL_USB1_SET {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_SET, 1, 31, true> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_SET, 1, 16, true> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_SET, 2, 14, true> BYPASS_CLK_SRC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_SET, 1, 13, true> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_SET, 1, 12, true> POWER;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_SET, 1,  6, true> EN_USB_CLKS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_SET, 1,  1, true> DIV_SELECT;
}  // namespace PLL_USB1_SET

// Analog USB1 480MHz PLL Control Register
namespace PLL_USB1_CLR {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_CLR, 1, 31, true> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_CLR, 1, 16, true> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_CLR, 2, 14, true> BYPASS_CLK_SRC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_CLR, 1, 13, true> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_CLR, 1, 12, true> POWER;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_CLR, 1,  6, true> EN_USB_CLKS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_CLR, 1,  1, true> DIV_SELECT;
}  // namespace PLL_USB1_CLR

// Analog USB1 480MHz PLL Control Register
namespace PLL_USB1_TOG {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_TOG, 1, 31, true> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_TOG, 1, 16, true> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_TOG, 2, 14, true> BYPASS_CLK_SRC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_TOG, 1, 13, true> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_TOG, 1, 12, true> POWER;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_TOG, 1,  6, true> EN_USB_CLKS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_TOG, 1,  1, true> DIV_SELECT;
}  // namespace PLL_USB1_TOG

// Analog USB2 480MHz PLL Control Register
namespace PLL_USB2 {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2, 1, 31> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2, 1, 16> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2, 2, 14> BYPASS_CLK_SRC;
    // 0b00..Select the 24MHz oscillator as source.
    // 0b01..Select the CLK1_N / CLK1_P as source.
    // 0b10..Reserved1
    // 0b11..Reserved2
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2, 1, 13> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2, 1, 12> POWER;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2, 1,  6> EN_USB_CLKS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2, 1,  1> DIV_SELECT;
}  // namespace PLL_USB2

// Analog USB2 480MHz PLL Control Register
namespace PLL_USB2_SET {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_SET, 1, 31, true> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_SET, 1, 16, true> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_SET, 2, 14, true> BYPASS_CLK_SRC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_SET, 1, 13, true> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_SET, 1, 12, true> POWER;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_SET, 1,  6, true> EN_USB_CLKS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_SET, 1,  1, true> DIV_SELECT;
}  // namespace PLL_USB2_SET

// Analog USB2 480MHz PLL Control Register
namespace PLL_USB2_CLR {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_CLR, 1, 31, true> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_CLR, 1, 16, true> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_CLR, 2, 14, true> BYPASS_CLK_SRC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_CLR, 1, 13, true> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_CLR, 1, 12, true> POWER;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_CLR, 1,  6, true> EN_USB_CLKS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_CLR, 1,  1, true> DIV_SELECT;
}  // namespace PLL_USB2_CLR

// Analog USB2 480MHz PLL Control Register
namespace PLL_USB2_TOG {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_TOG, 1, 31, true> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_TOG, 1, 16, true> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_TOG, 2, 14, true> BYPASS_CLK_SRC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_TOG, 1, 13, true> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_TOG, 1, 12, true> POWER;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_TOG, 1,  6, true> EN_USB_CLKS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_TOG, 1,  1, true> DIV_SELECT;
}  // namespace PLL_USB2_TOG

// Analog System PLL Control Register
namespace PLL_SYS {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS, 1, 31> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS, 1, 16> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS, 2, 14> BYPASS_CLK_SRC;
    // 0b00..Select the 24MHz oscillator as source.
    // 0b01..Select the CLK1_N / CLK1_P as source.
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS, 1, 13> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS, 1, 12> POWERDOWN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS, 1,  0> DIV_SELECT_MASK;
}  // namespace PLL_SYS

// Analog System PLL Control Register
namespace PLL_SYS_SET {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_SET, 1, 31, true> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_SET, 1, 16, true> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_SET, 2, 14, true> BYPASS_CLK_SRC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_SET, 1, 13, true> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_SET, 1, 12, true> POWERDOWN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_SET, 1,  0, true> DIV_SELECT_MASK;
}  // namespace PLL_SYS_SET

// Analog System PLL Control Register
namespace PLL_SYS_CLR {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_CLR, 1, 31, true> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_CLR, 1, 16, true> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_CLR, 2, 14, true> BYPASS_CLK_SRC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_CLR, 1, 13, true> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_CLR, 1, 12, true> POWERDOWN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_CLR, 1,  0, true> DIV_SELECT_MASK;
}  // namespace PLL_SYS_CLR

// Analog System PLL Control Register
namespace PLL_SYS_TOG {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_TOG, 1, 31, true> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_TOG, 1, 16, true> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_TOG, 2, 14, true> BYPASS_CLK_SRC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_TOG, 1, 13, true> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_TOG, 1, 12, true> POWERDOWN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_TOG, 1,  0, true> DIV_SELECT_MASK;
}  // namespace PLL_SYS_TOG

// 528MHz System PLL Spread Spectrum Register
namespace PLL_SYS_SS {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_SS, 16, 16> STOP;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_SS,  1, 15> ENABLE;  // Enable bit
    // 0b0..Spread spectrum modulation disabled
    // 0b1..Spread spectrum modulation enabled
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_SS, 15,  0> STEP;
}  // namespace PLL_SYS_SS

// Numerator of 528MHz System PLL Fractional Loop Divider Register
namespace PLL_SYS_NUM {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_NUM, 30, 0> A;
}  // namespace PLL_SYS_NUM

// Denominator of 528MHz System PLL Fractional Loop Divider Register
namespace PLL_SYS_DENOM {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_DENOM, 30, 0> B;
}  // namespace PLL_SYS_DENOM

// Analog Audio PLL control Register
namespace PLL_AUDIO {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO, 1, 31> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO, 2, 19> POST_DIV_SELECT;
    // 0b00..Divide by 4.
    // 0b01..Divide by 2.
    // 0b10..Divide by 1.
    // 0b11..Reserved
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO, 1, 16> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO, 2, 14> BYPASS_CLK_SRC;
    // 0b00..Select the 24MHz oscillator as source.
    // 0b01..Select the CLK1_N / CLK1_P as source.
    // 0b10..Reserved1
    // 0b11..Reserved2
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO, 1, 13> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO, 1, 12> POWERDOWN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO, 7,  0> DIV_SELECT;
}  // namespace PLL_AUDIO

// Analog Audio PLL control Register
namespace PLL_AUDIO_SET {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_SET, 1, 31, true> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_SET, 2, 19, true> POST_DIV_SELECT;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_SET, 1, 16, true> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_SET, 2, 14, true> BYPASS_CLK_SRC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_SET, 1, 13, true> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_SET, 1, 12, true> POWERDOWN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_SET, 7,  0, true> DIV_SELECT;
}  // namespace PLL_AUDIO_SET

// Analog Audio PLL control Register
namespace PLL_AUDIO_CLR {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_CLR, 1, 31, true> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_CLR, 2, 19, true> POST_DIV_SELECT;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_CLR, 1, 16, true> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_CLR, 2, 14, true> BYPASS_CLK_SRC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_CLR, 1, 13, true> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_CLR, 1, 12, true> POWERDOWN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_CLR, 7,  0, true> DIV_SELECT;
}  // namespace PLL_AUDIO_CLR

// Analog Audio PLL control Register
namespace PLL_AUDIO_TOG {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_TOG, 1, 31, true> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_TOG, 2, 19, true> POST_DIV_SELECT;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_TOG, 1, 16, true> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_TOG, 2, 14, true> BYPASS_CLK_SRC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_TOG, 1, 13, true> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_TOG, 1, 12, true> POWERDOWN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_TOG, 7,  0, true> DIV_SELECT;
}  // namespace PLL_AUDIO_TOG

// Numerator of Audio PLL Fractional Loop Divider Register
namespace PLL_AUDIO_NUM {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_NUM, 30, 0> A;
}  // namespace PLL_AUDIO_NUM

// Denominator of Audio PLL Fractional Loop Divider Register
namespace PLL_AUDIO_DENOM {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_DENOM, 30, 0> B;
}  // namespace PLL_AUDIO_DENOM

// Analog Video PLL control Register
namespace PLL_VIDEO {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO, 1, 31> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO, 2, 19> POST_DIV_SELECT;
    // 0b00..Divide by 4.
    // 0b01..Divide by 2.
    // 0b10..Divide by 1.
    // 0b11..Reserved
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO, 1, 16> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO, 2, 14> BYPASS_CLK_SRC;
    // 0b00..Select the 24MHz oscillator as source.
    // 0b01..Select the CLK1_N / CLK1_P as source.
    // 0b10..Reserved1
    // 0b11..Reserved2
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO, 1, 13> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO, 1, 12> POWERDOWN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO, 7,  0> DIV_SELECT;
}  // namespace PLL_VIDEO

// Analog Video PLL control Register
namespace PLL_VIDEO_SET {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_SET, 1, 31, true> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_SET, 2, 19, true> POST_DIV_SELECT;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_SET, 1, 16, true> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_SET, 2, 14, true> BYPASS_CLK_SRC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_SET, 1, 13, true> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_SET, 1, 12, true> POWERDOWN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_SET, 7,  0, true> DIV_SELECT;
}  // namespace PLL_VIDEO_SET

// Analog Video PLL control Register
namespace PLL_VIDEO_CLR {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_CLR, 1, 31, true> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_CLR, 2, 19, true> POST_DIV_SELECT;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_CLR, 1, 16, true> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_CLR, 2, 14, true> BYPASS_CLK_SRC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_CLR, 1, 13, true> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_CLR, 1, 12, true> POWERDOWN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_CLR, 7,  0, true> DIV_SELECT;
}  // namespace PLL_VIDEO_CLR

// Analog Video PLL control Register
namespace PLL_VIDEO_TOG {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_TOG, 1, 31, true> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_TOG, 2, 19, true> POST_DIV_SELECT;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_TOG, 1, 16, true> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_TOG, 2, 14, true> BYPASS_CLK_SRC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_TOG, 1, 13, true> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_TOG, 1, 12, true> POWERDOWN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_TOG, 7,  0, true> DIV_SELECT;
}  // namespace PLL_VIDEO_TOG

// Numerator of Video PLL Fractional Loop Divider Register
namespace PLL_VIDEO_NUM {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_NUM, 30, 0> A;
}  // namespace PLL_VIDEO_NUM

// Denominator of Video PLL Fractional Loop Divider Register
namespace PLL_VIDEO_DENOM {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_DENOM, 30, 0> B;
}  // namespace PLL_VIDEO_DENOM

// Analog ENET PLL Control Register
namespace PLL_ENET {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET, 1, 31> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET, 1, 21> ENET_25M_REF_EN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET, 1, 20> ENET2_REF_EN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET, 1, 16> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET, 2, 14> BYPASS_CLK_SRC;
    // 0b00..Select the 24MHz oscillator as source.
    // 0b01..Select the CLK1_N / CLK1_P as source.
    // 0b10..Reserved1
    // 0b11..Reserved2
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET, 1, 13> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET, 1, 12> POWERDOWN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET, 2,  2> ENET2_DIV_SELECT;
    // 0b00..25MHz
    // 0b01..50MHz
    // 0b10..100MHz (not 50% duty cycle)
    // 0b11..125MHz
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET, 2, 0> DIV_SELECT;

// Analog ENET PLL Control Register values
constexpr uint32_t kENET2_DIV_SELECT_25MHZ  = 0;
constexpr uint32_t kENET2_DIV_SELECT_50MHZ  = 1;
constexpr uint32_t kENET2_DIV_SELECT_100MHZ = 2;
constexpr uint32_t kENET2_DIV_SELECT_125MHZ = 3;
}  // namespace PLL_ENET

// Analog ENET PLL Control Register
namespace PLL_ENET_SET {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_SET, 1, 31, true> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_SET, 1, 21, true> ENET_25M_REF_EN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_SET, 1, 20, true> ENET2_REF_EN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_SET, 1, 16, true> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_SET, 2, 14, true> BYPASS_CLK_SRC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_SET, 1, 13, true> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_SET, 1, 12, true> POWERDOWN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_SET, 2,  2, true> ENET2_DIV_SELECT;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_SET, 2,  0, true> DIV_SELECT;
}  // namespace PLL_ENET_SET

// Analog ENET PLL Control Register
namespace PLL_ENET_CLR {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_CLR, 1, 31, true> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_CLR, 1, 21, true> ENET_25M_REF_EN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_CLR, 1, 20, true> ENET2_REF_EN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_CLR, 1, 16, true> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_CLR, 2, 14, true> BYPASS_CLK_SRC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_CLR, 1, 13, true> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_CLR, 1, 12, true> POWERDOWN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_CLR, 2,  2, true> ENET2_DIV_SELECT;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_CLR, 2,  0, true> DIV_SELECT;
}  // namespace PLL_ENET_CLR

// Analog ENET PLL Control Register
namespace PLL_ENET_TOG {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_TOG, 1, 31, true> LOCK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_TOG, 1, 21, true> ENET_25M_REF_EN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_TOG, 1, 20, true> ENET2_REF_EN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_TOG, 1, 16, true> BYPASS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_TOG, 2, 14, true> BYPASS_CLK_SRC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_TOG, 1, 13, true> ENABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_TOG, 1, 12, true> POWERDOWN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_TOG, 2,  2, true> ENET2_DIV_SELECT;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_TOG, 2,  0, true> DIV_SELECT;
}  // namespace PLL_ENET_TOG

// 480MHz Clock (PLL3) Phase Fractional Divider Control Register
namespace PFD_480 {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480, 1, 31> PFD3_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480, 1, 30> PFD3_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480, 6, 24> PFD3_FRAC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480, 1, 23> PFD2_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480, 1, 22> PFD2_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480, 6, 16> PFD2_FRAC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480, 1, 15> PFD1_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480, 1, 14> PFD1_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480, 6,  8> PFD1_FRAC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480, 1,  7> PFD0_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480, 1,  6> PFD0_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480, 6,  0> PFD0_FRAC;
}  // namespace PFD_480

// 480MHz Clock (PLL3) Phase Fractional Divider Control Register
namespace PFD_480_SET {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_SET, 1, 31, true> PFD3_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_SET, 1, 30, true> PFD3_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_SET, 6, 24, true> PFD3_FRAC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_SET, 1, 23, true> PFD2_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_SET, 1, 22, true> PFD2_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_SET, 6, 16, true> PFD2_FRAC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_SET, 1, 15, true> PFD1_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_SET, 1, 14, true> PFD1_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_SET, 6,  8, true> PFD1_FRAC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_SET, 1,  7, true> PFD0_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_SET, 1,  6, true> PFD0_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_SET, 6,  0, true> PFD0_FRAC;
}  // namespace PFD_480_SET

// 480MHz Clock (PLL3) Phase Fractional Divider Control Register
namespace PFD_480_CLR {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_CLR, 1, 31, true> PFD3_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_CLR, 1, 30, true> PFD3_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_CLR, 6, 24, true> PFD3_FRAC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_CLR, 1, 23, true> PFD2_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_CLR, 1, 22, true> PFD2_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_CLR, 6, 16, true> PFD2_FRAC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_CLR, 1, 15, true> PFD1_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_CLR, 1, 14, true> PFD1_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_CLR, 6,  8, true> PFD1_FRAC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_CLR, 1,  7, true> PFD0_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_CLR, 1,  6, true> PFD0_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_CLR, 6,  0, true> PFD0_FRAC;
}  // namespace PFD_480_CLR

// 480MHz Clock (PLL3) Phase Fractional Divider Control Register
namespace PFD_480_TOG {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_TOG, 1, 31, true> PFD3_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_TOG, 1, 30, true> PFD3_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_TOG, 6, 24, true> PFD3_FRAC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_TOG, 1, 23, true> PFD2_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_TOG, 1, 22, true> PFD2_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_TOG, 6, 16, true> PFD2_FRAC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_TOG, 1, 15, true> PFD1_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_TOG, 1, 14, true> PFD1_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_TOG, 6,  8, true> PFD1_FRAC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_TOG, 1,  7, true> PFD0_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_TOG, 1,  6, true> PFD0_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_TOG, 6,  0, true> PFD0_FRAC;
}  // namespace PFD_480_TOG

// 528MHz Clock (PLL2) Phase Fractional Divider Control Register
namespace PFD_528 {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528, 1, 31> PFD3_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528, 1, 30> PFD3_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528, 6, 24> PFD3_FRAC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528, 1, 23> PFD2_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528, 1, 22> PFD2_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528, 6, 16> PFD2_FRAC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528, 1, 15> PFD1_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528, 1, 14> PFD1_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528, 6,  8> PFD1_FRAC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528, 1,  7> PFD0_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528, 1,  6> PFD0_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528, 6,  0> PFD0_FRAC;
}  // namespace PFD_528

// 528MHz Clock (PLL2) Phase Fractional Divider Control Register
namespace PFD_528_SET {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_SET, 1, 31, true> PFD3_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_SET, 1, 30, true> PFD3_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_SET, 6, 24, true> PFD3_FRAC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_SET, 1, 23, true> PFD2_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_SET, 1, 22, true> PFD2_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_SET, 6, 16, true> PFD2_FRAC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_SET, 1, 15, true> PFD1_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_SET, 1, 14, true> PFD1_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_SET, 6,  8, true> PFD1_FRAC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_SET, 1,  7, true> PFD0_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_SET, 1,  6, true> PFD0_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_SET, 6,  0, true> PFD0_FRAC;
}  // namespace PFD_528_SET

// 528MHz Clock (PLL2) Phase Fractional Divider Control Register
namespace PFD_528_CLR {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_CLR, 1, 31, true> PFD3_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_CLR, 1, 30, true> PFD3_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_CLR, 6, 24, true> PFD3_FRAC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_CLR, 1, 23, true> PFD2_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_CLR, 1, 22, true> PFD2_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_CLR, 6, 16, true> PFD2_FRAC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_CLR, 1, 15, true> PFD1_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_CLR, 1, 14, true> PFD1_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_CLR, 6,  8, true> PFD1_FRAC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_CLR, 1,  7, true> PFD0_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_CLR, 1,  6, true> PFD0_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_CLR, 6,  0, true> PFD0_FRAC;
}  // namespace PFD_528_CLR

// 528MHz Clock (PLL2) Phase Fractional Divider Control Register
namespace PFD_528_TOG {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_TOG, 1, 31, true> PFD3_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_TOG, 1, 30, true> PFD3_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_TOG, 6, 24, true> PFD3_FRAC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_TOG, 1, 23, true> PFD2_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_TOG, 1, 22, true> PFD2_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_TOG, 6, 16, true> PFD2_FRAC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_TOG, 1, 15, true> PFD1_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_TOG, 1, 14, true> PFD1_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_TOG, 6,  8, true> PFD1_FRAC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_TOG, 1,  7, true> PFD0_CLKGATE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_TOG, 1,  6, true> PFD0_STABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_TOG, 6,  0, true> PFD0_FRAC;
}  // namespace PFD_528_TOG

// Miscellaneous Register 0
namespace MISC0 {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0, 1, 30> XTAL_24M_PWD;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0, 1, 29> RTC_XTAL_SOURCE;
    // 0b0..Internal ring oscillator
    // 0b1..RTC_XTAL
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0, 3, 26> CLKGATE_DELAY;
    // 0b000..0.5ms
    // 0b001..1.0ms
    // 0b010..2.0ms
    // 0b011..3.0ms
    // 0b100..4.0ms
    // 0b101..5.0ms
    // 0b110..6.0ms
    // 0b111..7.0ms
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0, 1, 25> CLKGATE_CTRL;
    // 0b0..Allow the logic to automatically gate the clock when the XTAL is powered down.
    // 0b1..Prevent the logic from ever gating off the clock.
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0, 1, 16> OSC_XTALOK_EN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0, 1, 15> OSC_XTALOK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0, 2, 13> OSC_I;
    // Decrease current by 'value'*12.5%:
    // 0b00..Nominal
    // 0b01..Decrease current by 12.5%
    // 0b10..Decrease current by 25.0%
    // 0b11..Decrease current by 37.5%
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0, 1, 12> DISCON_HIGH_SNVS;
    // 0b0..Turn on the switch
    // 0b1..Turn off the switch
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0, 2, 10> STOP_MODE_CONFIG;
    // 0b00..All analog except RTC powered down on stop mode assertion.
    // 0b01..Beside RTC, analog bandgap, 1p1 and 2p5 regulators are also on.
    // 0b10..Beside RTC, 1p1 and 2p5 regulators are also on, low-power bandgap is selected so that the normal analog
    //       bandgap together with the rest analog is powered down.
    // 0b11..Beside RTC, low-power bandgap is selected and the rest analog is powered down.
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0, 1, 7> REFTOP_VBGUP;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0, 3, 4> REFTOP_VBGADJ;
    // 0b000..Nominal VBG
    // 0b001..VBG+0.78%
    // 0b010..VBG+1.56%
    // 0b011..VBG+2.34%
    // 0b100..VBG-0.78%
    // 0b101..VBG-1.56%
    // 0b110..VBG-2.34%
    // 0b111..VBG-3.12%
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0, 1, 3> REFTOP_SELFBIASOFF;
    // 0b0..Uses coarse bias currents for startup
    // 0b1..Uses bandgap-based bias currents for best performance.
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0, 1, 0> REFTOP_PWD;

// Miscellaneous Register 0 values
constexpr uint32_t kREFTOP_VBGADJ_NOMINAL    = 0;
constexpr uint32_t kREFTOP_VBGADJ_PLUS_0p78  = 1;
constexpr uint32_t kREFTOP_VBGADJ_PLUS_1p56  = 2;
constexpr uint32_t kREFTOP_VBGADJ_PLUS_2p34  = 3;
constexpr uint32_t kREFTOP_VBGADJ_MINUS_0p78 = 4;
constexpr uint32_t kREFTOP_VBGADJ_MINUS_1p56 = 5;
constexpr uint32_t kREFTOP_VBGADJ_MINUS_2p34 = 6;
constexpr uint32_t kREFTOP_VBGADJ_MINUS_3p12 = 7;
constexpr uint32_t kRTC_XTAL_SOURCE_INTERNAL = 0;
constexpr uint32_t kRTC_XTAL_SOURCE_XTAL     = 1;
}  // namespace MISC0

// Miscellaneous Register 0
namespace MISC0_SET {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_SET, 1, 30, true> XTAL_24M_PWD;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_SET, 1, 29, true> RTC_XTAL_SOURCE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_SET, 3, 26, true> CLKGATE_DELAY;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_SET, 1, 25, true> CLKGATE_CTRL;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_SET, 1, 16, true> OSC_XTALOK_EN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_SET, 1, 15, true> OSC_XTALOK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_SET, 2, 13, true> OSC_I;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_SET, 1, 12, true> DISCON_HIGH_SNVS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_SET, 2, 10, true> STOP_MODE_CONFIG;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_SET, 1,  7, true> REFTOP_VBGUP;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_SET, 3,  4, true> REFTOP_VBGADJ;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_SET, 1,  3, true> REFTOP_SELFBIASOFF;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_SET, 1,  0, true> REFTOP_PWD;
}  // namespace MISC0_SET

// Miscellaneous Register 0
namespace MISC0_CLR {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_CLR, 1, 30, true> XTAL_24M_PWD;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_CLR, 1, 29, true> RTC_XTAL_SOURCE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_CLR, 3, 26, true> CLKGATE_DELAY;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_CLR, 1, 25, true> CLKGATE_CTRL;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_CLR, 1, 16, true> OSC_XTALOK_EN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_CLR, 1, 15, true> OSC_XTALOK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_CLR, 2, 13, true> OSC_I;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_CLR, 1, 12, true> DISCON_HIGH_SNVS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_CLR, 2, 10, true> STOP_MODE_CONFIG;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_CLR, 1,  7, true> REFTOP_VBGUP;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_CLR, 3,  4, true> REFTOP_VBGADJ;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_CLR, 1,  3, true> REFTOP_SELFBIASOFF;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_CLR, 1,  0, true> REFTOP_PWD;
}  // namespace MISC0_CLR

// Miscellaneous Register 0
namespace MISC0_TOG {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_TOG, 1, 30, true> XTAL_24M_PWD;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_TOG, 1, 29, true> RTC_XTAL_SOURCE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_TOG, 3, 26, true> CLKGATE_DELAY;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_TOG, 1, 25, true> CLKGATE_CTRL;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_TOG, 1, 16, true> OSC_XTALOK_EN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_TOG, 1, 15, true> OSC_XTALOK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_TOG, 2, 13, true> OSC_I;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_TOG, 1, 12, true> DISCON_HIGH_SNVS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_TOG, 2, 10, true> STOP_MODE_CONFIG;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_TOG, 1,  7, true> REFTOP_VBGUP;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_TOG, 3,  4, true> REFTOP_VBGADJ;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_TOG, 1,  3, true> REFTOP_SELFBIASOFF;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_TOG, 1,  0, true> REFTOP_PWD;
}  // namespace MISC0_TOG

// Miscellaneous Register 1
namespace MISC1 {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1, 1, 31> IRQ_DIG_BO;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1, 1, 30> IRQ_ANA_BO;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1, 1, 29> IRQ_TEMPHIGH;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1, 1, 28> IRQ_TEMPLOW;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1, 1, 27> IRQ_TEMPPANIC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1, 1, 17> PFD_528_AUTOGATE_EN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1, 1, 16> PFD_480_AUTOGATE_EN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1, 1, 12> LVDSCLK1_IBEN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1, 1, 10> LVDSCLK1_OBEN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1, 5,  0> LVDS1_CLK_SEL;
    // 0b00000..Arm PLL
    // 0b00001..System PLL
    // 0b00010..ref_pfd4_clk == pll2_pfd0_clk
    // 0b00011..ref_pfd5_clk == pll2_pfd1_clk
    // 0b00100..ref_pfd6_clk == pll2_pfd2_clk
    // 0b00101..ref_pfd7_clk == pll2_pfd3_clk
    // 0b00110..Audio PLL
    // 0b00111..Video PLL
    // 0b01001..ethernet ref clock (ENET_PLL)
    // 0b01100..USB1 PLL clock
    // 0b01101..USB2 PLL clock
    // 0b01110..ref_pfd0_clk == pll3_pfd0_clk
    // 0b01111..ref_pfd1_clk == pll3_pfd1_clk
    // 0b10000..ref_pfd2_clk == pll3_pfd2_clk
    // 0b10001..ref_pfd3_clk == pll3_pfd3_clk
    // 0b10010..xtal (24M)
}  // namespace MISC1

// Miscellaneous Register 1
namespace MISC1_SET {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_SET, 1, 31, true> IRQ_DIG_BO;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_SET, 1, 30, true> IRQ_ANA_BO;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_SET, 1, 29, true> IRQ_TEMPHIGH;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_SET, 1, 28, true> IRQ_TEMPLOW;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_SET, 1, 27, true> IRQ_TEMPPANIC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_SET, 1, 17, true> PFD_528_AUTOGATE_EN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_SET, 1, 16, true> PFD_480_AUTOGATE_EN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_SET, 1, 12, true> LVDSCLK1_IBEN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_SET, 1, 10, true> LVDSCLK1_OBEN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_SET, 5,  0, true> LVDS1_CLK_SEL;
}  // namespace MISC1_SET

// Miscellaneous Register 1
namespace MISC1_CLR {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_CLR, 1, 31, true> IRQ_DIG_BO;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_CLR, 1, 30, true> IRQ_ANA_BO;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_CLR, 1, 29, true> IRQ_TEMPHIGH;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_CLR, 1, 28, true> IRQ_TEMPLOW;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_CLR, 1, 27, true> IRQ_TEMPPANIC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_CLR, 1, 17, true> PFD_528_AUTOGATE_EN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_CLR, 1, 16, true> PFD_480_AUTOGATE_EN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_CLR, 1, 12, true> LVDSCLK1_IBEN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_CLR, 1, 10, true> LVDSCLK1_OBEN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_CLR, 5,  0, true> LVDS1_CLK_SEL;
}  // namespace MISC1_CLR

// Miscellaneous Register 1
namespace MISC1_TOG {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_TOG, 1, 31, true> IRQ_DIG_BO;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_TOG, 1, 30, true> IRQ_ANA_BO;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_TOG, 1, 29, true> IRQ_TEMPHIGH;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_TOG, 1, 28, true> IRQ_TEMPLOW;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_TOG, 1, 27, true> IRQ_TEMPPANIC;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_TOG, 1, 17, true> PFD_528_AUTOGATE_EN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_TOG, 1, 16, true> PFD_480_AUTOGATE_EN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_TOG, 1, 12, true> LVDSCLK1_IBEN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_TOG, 1, 10, true> LVDSCLK1_OBEN;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_TOG, 5,  0, true> LVDS1_CLK_SEL;
}  // namespace MISC1_TOG

// Miscellaneous Register 2
namespace MISC2 {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 2, 30> VIDEO_DIV;
    // 0b00..divide by 1 (Default)
    // 0b01..divide by 2
    // 0b10..divide by 1
    // 0b11..divide by 4
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 2, 28> REG2_STEP_TIME;
    // 64 * 2^'value':
    // 0b00..64
    // 0b01..128
    // 0b10..256
    // 0b11..512
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 2, 26> REG1_STEP_TIME;
    // 64 * 2^'value':
    // 0b00..64
    // 0b01..128
    // 0b10..256
    // 0b11..512
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 2, 24> REG0_STEP_TIME;
    // 64 * 2^'value':
    // 0b00..64
    // 0b01..128
    // 0b10..256
    // 0b11..512
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 1, 23> AUDIO_DIV_MSB;
    // 1/2^'value':
    // 0b0..divide by 1 (Default)
    // 0b1..divide by 2
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 1, 22> REG2_OK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 1, 21> REG2_ENABLE_BO;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 1, 19> REG2_BO_STATUS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 3, 16> REG2_BO_OFFSET;
    // 0b100..Brownout offset = 0.100V
    // 0b111..Brownout offset = 0.175V
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 1, 15> AUDIO_DIV_LSB;
    // 1/2^'value':
    // 0b0..divide by 1 (Default)
    // 0b1..divide by 2
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 1, 14> REG1_OK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 1, 13> REG1_ENABLE_BO;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 1, 11> REG1_BO_STATUS;
    // 0b1..Brownout, supply is below target minus brownout offset.
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 3,  8> REG1_BO_OFFSET;
    // 0b100..Brownout offset = 0.100V
    // 0b111..Brownout offset = 0.175V
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 1,  7> PLL3_DISABLE;
    // 0b0..PLL3 is being used by peripherals and is enabled when SoC is not in any low power mode
    // 0b1..PLL3 can be disabled when the SoC is not in any low power mode
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 1,  6> REG0_OK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 1,  5> REG0_ENABLE_BO;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 1,  3> REG0_BO_STATUS;
    // 0b1..Brownout, supply is below target minus brownout offset.
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 3,  0> REG0_BO_OFFSET;
    // 0b100..Brownout offset = 0.100V
    // 0b111..Brownout offset = 0.175V
}  // namespace MISC2

// Miscellaneous Register 2
namespace MISC2_SET {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 2, 30, true> VIDEO_DIV;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 2, 28, true> REG2_STEP_TIME;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 2, 26, true> REG1_STEP_TIME;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 2, 24, true> REG0_STEP_TIME;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 1, 23, true> AUDIO_DIV_MSB;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 1, 22, true> REG2_OK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 1, 21, true> REG2_ENABLE_BO;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 1, 19, true> REG2_BO_STATUS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 3, 16, true> REG2_BO_OFFSET;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 1, 15, true> AUDIO_DIV_LSB;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 1, 14, true> REG1_OK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 1, 13, true> REG1_ENABLE_BO;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 1, 11, true> REG1_BO_STATUS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 3,  8, true> REG1_BO_OFFSET;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 1,  7, true> PLL3_DISABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 1,  6, true> REG0_OK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 1,  5, true> REG0_ENABLE_BO;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 1,  3, true> REG0_BO_STATUS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 3,  0, true> REG0_BO_OFFSET;
}  // namespace MISC2_SET

// Miscellaneous Register 2
namespace MISC2_CLR {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 2, 30, true> VIDEO_DIV;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 2, 28, true> REG2_STEP_TIME;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 2, 26, true> REG1_STEP_TIME;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 2, 24, true> REG0_STEP_TIME;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 1, 23, true> AUDIO_DIV_MSB;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 1, 22, true> REG2_OK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 1, 21, true> REG2_ENABLE_BO;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 1, 19, true> REG2_BO_STATUS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 3, 16, true> REG2_BO_OFFSET;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 1, 15, true> AUDIO_DIV_LSB;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 1, 14, true> REG1_OK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 1, 13, true> REG1_ENABLE_BO;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 1, 11, true> REG1_BO_STATUS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 3,  8, true> REG1_BO_OFFSET;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 1,  7, true> PLL3_DISABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 1,  6, true> REG0_OK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 1,  5, true> REG0_ENABLE_BO;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 1,  3, true> REG0_BO_STATUS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 3,  0, true> REG0_BO_OFFSET;
}  // namespace MISC2_CLR

// Miscellaneous Register 2
namespace MISC2_TOG {
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 2, 30, true> VIDEO_DIV;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 2, 28, true> REG2_STEP_TIME;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 2, 26, true> REG1_STEP_TIME;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 2, 24, true> REG0_STEP_TIME;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 1, 23, true> AUDIO_DIV_MSB;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 1, 22, true> REG2_OK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 1, 21, true> REG2_ENABLE_BO;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 1, 19, true> REG2_BO_STATUS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 3, 16, true> REG2_BO_OFFSET;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 1, 15, true> AUDIO_DIV_LSB;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 1, 14, true> REG1_OK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 1, 13, true> REG1_ENABLE_BO;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 1, 11, true> REG1_BO_STATUS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 3,  8, true> REG1_BO_OFFSET;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 1,  7, true> PLL3_DISABLE;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 1,  6, true> REG0_OK;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 1,  5, true> REG0_ENABLE_BO;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 1,  3, true> REG0_BO_STATUS;
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 3,  0, true> REG0_BO_OFFSET;
}  // namespace MISC2_TOG

// CCM_ANALOG_PLL_xxx_BYPASS_CLK_SRC values
namespace PLL {
constexpr uint32_t kBYPASS_CLK_SRC_24MHZ = 0;
constexpr uint32_t kBYPASS_CLK_SRC_CLK1  = 1;
}  // namespace PLL

}  // namespace CCM_ANALOG

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
