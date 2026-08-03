// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// GPC.h defines all the GPC registers.
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
constexpr size_t kGPC_IMR_count = 4;
constexpr size_t kGPC_ISR_count = 4;

// Structure type to access the General Power Controller (GPC) registers.
//
// Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_GPC.h
// * https://github.com/nxp-mcuxpresso/mcux-soc-svd/blob/main/MIMXRT1062/MIMXRT1062.xml
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct GPC_Layout {
  volatile uint32_t CNTR;                              /**< GPC Interface control register, offset: 0x0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t IMR[kGPC_IMR_count];               /**< IRQ masking register 1..IRQ masking register 4, array offset: 0x8, array step: 0x4 */
  const volatile uint32_t ISR[kGPC_ISR_count];         /**< IRQ status register 1..IRQ status register 4, array offset: 0x18, array step: 0x4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t IMR5;                              /**< IRQ masking register 5, offset: 0x34 */
  const volatile uint32_t ISR5;                        /**< IRQ status register 5, offset: 0x38 */
};

constexpr size_t    kGPC_size = 0x3C;
constexpr uintptr_t kGPC_base = 0x400F'4000;

namespace GPC {
constexpr regs::RegGroup<GPC_Layout, kGPC_size, kGPC_base> group;
}  // namespace GPC

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using GPC_Reg =
    regs::Reg32<kGPC_base, GPC_Layout, Member, 0, Bits, Shift, AssignMask>;

namespace GPC {

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>(),
          typename = std::enable_if_t<(Index < kGPC_IMR_count)>>
using IMR_Reg = regs::Reg32<kGPC_base, GPC_Layout, &GPC_Layout::IMR, Index,
                            Bits, Shift, AssignMask>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>(),
          typename = std::enable_if_t<(Index < kGPC_ISR_count)>>
using ISR_Reg = regs::Reg32<kGPC_base, GPC_Layout, &GPC_Layout::ISR, Index,
                            Bits, Shift, AssignMask>;

// GPC Interface control register
namespace CNTR {
constexpr GPC_Reg<&GPC_Layout::CNTR, 1, 22> PDRAM0_PGE;    // FlexRAM PDRAM0 Power Gate Enable
    // 0b0..FlexRAM PDRAM0 domain will keep power even if the CPU core is powered down.
    // 0b1..FlexRAM PDRAM0 domain will be powered down when the CPU core is powered down.
constexpr GPC_Reg<&GPC_Layout::CNTR, 1,  3> MEGA_PUP_REQ;  // MEGA domain (FlexRAM PDRAM1) power up request
    // 0b0..No Request
    // 0b1..Request power up sequence
constexpr GPC_Reg<&GPC_Layout::CNTR, 1,  2> MEGA_PDN_REQ;  // MEGA domain (FlexRAM PDRAM1) power down request
    // 0b0..No Request
    // 0b1..Request power down sequence
}  // namespace CNTR

// IRQ masking register 1..IRQ masking register 4
namespace IMR {
constexpr IMR_Reg<0, 32, 0> IMR1;  // IRQ[31:0] masking bits: 1-irq masked, 0-irq is not masked
constexpr IMR_Reg<1, 32, 0> IMR2;  // IRQ[63:32] masking bits: 1-irq masked, 0-irq is not masked
constexpr IMR_Reg<2, 32, 0> IMR3;  // IRQ[95:64] masking bits: 1-irq masked, 0-irq is not masked
constexpr IMR_Reg<3, 32, 0> IMR4;  // IRQ[127:96] masking bits: 1-irq masked, 0-irq is not masked
}  // namespace IMR

// IRQ status register 1..IRQ status register 4
namespace ISR {
constexpr ISR_Reg<0, 32, 0> ISR1;  // IRQ[31:0] status, read only
constexpr ISR_Reg<1, 32, 0> ISR2;  // IRQ[63:32] status, read only
constexpr ISR_Reg<2, 32, 0> ISR3;  // IRQ[95:64] status, read only
constexpr ISR_Reg<3, 32, 0> ISR4;  // IRQ[127:96] status, read only
}  // namespace ISR

// IRQ masking register 5
namespace IMR5 {
constexpr GPC_Reg<&GPC_Layout::IMR5, 32, 0> IMR5;  // IRQ[159:128] masking bits:
    // 1-irq masked, 0-irq is not masked
}  // namespace IMR5

// IRQ status register 5
namespace ISR5 {
constexpr GPC_Reg<&GPC_Layout::ISR5, 32, 0> ISR5;  // IRQ[159:128] status, read only
}  // namespace ISR5

}  // namespace GPC

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
