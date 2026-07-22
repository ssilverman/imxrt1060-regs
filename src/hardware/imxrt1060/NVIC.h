// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// NVIC.h defines all the NVIC registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// NVIC layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcu-sdk-cmsis/blob/mcux_main/Core/Include/core_cm7.h
struct NVIC_Layout {
  volatile uint32_t ISER[8];               /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[24];
  volatile uint32_t ICER[8];               /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[24];
  volatile uint32_t ISPR[8];               /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[24];
  volatile uint32_t ICPR[8];               /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[24];
  volatile uint32_t IABR[8];               /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[56];
  volatile uint8_t  IPR[240];              /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[644];
  volatile uint32_t STIR;                  /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
};

constexpr size_t    kNVIC_size = 0xE04;
static constexpr uintptr_t kSCS_base = 0xE000E000;    /*!< System Control Space Base Address */
constexpr uintptr_t kNVIC_base = kSCS_base + 0x0100;  /*!< NVIC Base Address */

namespace NVIC {
constexpr regs::RegGroup<NVIC_Layout, kNVIC_size, kNVIC_base> group;
}  // namespace NVIC

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
