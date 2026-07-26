// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// DMAMUX.h defines all the DMAMUX registers.
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
constexpr size_t kDMAMUX_CHCFG_count = 32;

// Structure type to access the Direct Memory Access Multiplexer
// (DMAMUX) registers.
//
// Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_DMAMUX.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct DMAMUX_Layout {
  volatile uint32_t CHCFG[kDMAMUX_CHCFG_count];  /**< Channel 0 Configuration Register..Channel 31 Configuration Register, array offset: 0x0, array step: 0x4 */
};

constexpr size_t    kDMAMUX_size = 0x80;
constexpr uintptr_t kDMAMUX_base = 0x400EC000;

namespace DMAMUX {
constexpr regs::RegGroup<DMAMUX_Layout, kDMAMUX_size, kDMAMUX_base> group;
}  // namespace DMAMUX

namespace DMAMUX {

template <size_t Index, size_t Bits, unsigned int Shift,
          bool DirectAssign = false,
          typename = std::enable_if_t<(Index < kDMAMUX_CHCFG_count)>>
using CHCFG_Reg =
    regs::Reg32<kDMAMUX_base, DMAMUX_Layout, &DMAMUX_Layout::CHCFG, Index, Bits,
                Shift, DirectAssign>;

// Channel 0 Configuration Register..Channel 31 Configuration Register values
namespace CHCFG {
template <size_t Index>
constexpr CHCFG_Reg<Index, 1, 31> ENBL;    // DMA Mux Channel Enable
    // 0b0..DMA Mux channel is disabled
    // 0b1..DMA Mux channel is enabled
template <size_t Index>
constexpr CHCFG_Reg<Index, 1, 30> TRIG;    // DMA Channel Trigger Enable
    // 0b0..Triggering is disabled. If triggering is disabled and ENBL is set, the DMA Channel will simply route the
    //      specified source to the DMA channel. (Normal mode)
    // 0b1..Triggering is enabled. If triggering is enabled and ENBL is set, the DMA_CH_MUX is in Periodic Trigger mode.
template <size_t Index>
constexpr CHCFG_Reg<Index, 1, 29> A_ON;    // DMA Channel Always Enable
    // 0b0..DMA Channel Always ON function is disabled
    // 0b1..DMA Channel Always ON function is enabled
template <size_t Index>
constexpr CHCFG_Reg<Index, 7,  0> SOURCE;  // DMA Channel Source (Slot Number)
}  // namespace CHCFG

}  // namespace DMAMUX

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
