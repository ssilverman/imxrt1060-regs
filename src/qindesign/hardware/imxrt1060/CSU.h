// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// CSU.h defines all the CSU registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>
#include <type_traits>

#include "qindesign/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the Central Security Unit (CSU) registers.
//
// Comments are from BSD-3-licensed NXP SDK sources.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_CSU.h
// * https://github.com/nxp-mcuxpresso/mcux-soc-svd/blob/main/MIMXRT1062/MIMXRT1062.xml
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
// Size of Registers Arrays
constexpr size_t kCSU_CSL_count = 32;

struct CSU_Layout {
  volatile uint32_t CSL[kCSU_CSL_count];               /**< Config security level register, array offset: 0x0, array step: 0x4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[96];
  volatile uint32_t HP0;                               /**< HP0 register, offset: 0x200 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[5];
  volatile uint32_t SA;                                /**< Secure access register, offset: 0x218 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[79];
  volatile uint32_t HPCONTROL0;                        /**< HPCONTROL0 register, offset: 0x358 */
};

constexpr size_t    kCSU_size = 0x35C;
constexpr uintptr_t kCSU_base = 0x400D'C000;

namespace CSU {
constexpr regs::RegGroup<CSU_Layout, kCSU_size, kCSU_base> group;

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using CSU_Reg =
    regs::Reg32<kCSU_base, CSU_Layout, Member, 0, Bits, Shift, AssignMask>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>(),
          typename = std::enable_if_t<(Index < kCSU_CSL_count)>>
using CSL_Reg =
    regs::Reg32<kCSU_base, CSU_Layout, &CSU_Layout::CSL, Index, Bits, Shift,
                AssignMask>;

// Config security level register
namespace CSL {
template <size_t Index>
constexpr CSL_Reg<Index, 1, 24> LOCK_S1;  // The lock bit corresponding to the first slave.
    // It is written by the secure software.
    // 0b0..Not locked. The bits 16-23 can be written by the software.
    // 0b1..The bits 16-23 are locked and can't be written by the software.
template <size_t Index>
constexpr CSL_Reg<Index, 1, 23> NSW_S1;   // Non-secure supervisor write access control for the first slave
    // 0b0..The non-secure supervisor write access is disabled for the first slave.
    // 0b1..The non-secure supervisor write access is enabled for the first slave
template <size_t Index>
constexpr CSL_Reg<Index, 1, 22> NUW_S1;   // Non-secure user write access control for the first slave
    // 0b0..The non-secure user write access is disabled for the first slave.
    // 0b1..The non-secure user write access is enabled for the first slave.
template <size_t Index>
constexpr CSL_Reg<Index, 1, 21> SSW_S1;   // Secure supervisor write access control for the first slave
    // 0b0..The secure supervisor write access is disabled for the first slave.
    // 0b1..The secure supervisor write access is enabled for the first slave.
template <size_t Index>
constexpr CSL_Reg<Index, 1, 20> SUW_S1;   // Secure user write access control for the first slave
    // 0b0..The secure user write access is disabled for the first slave.
    // 0b1..The secure user write access is enabled for the first slave.
template <size_t Index>
constexpr CSL_Reg<Index, 1, 19> NSR_S1;   // Non-secure supervisor read access control for the first slave
    // 0b0..The non-secure supervisor read access is disabled for the first slave.
    // 0b1..The non-secure supervisor read access is enabled for the first slave.
template <size_t Index>
constexpr CSL_Reg<Index, 1, 18> NUR_S1;   // Non-secure user read access control for the first slave
    // 0b0..The non-secure user read access is disabled for the first slave.
    // 0b1..The non-secure user read access is enabled for the first slave.
template <size_t Index>
constexpr CSL_Reg<Index, 1, 17> SSR_S1;   // Secure supervisor read access control for the first slave
    // 0b0..The secure supervisor read access is disabled for the first slave.
    // 0b1..The secure supervisor read access is enabled for the first slave.
template <size_t Index>
constexpr CSL_Reg<Index, 1, 16> SUR_S1;   // Secure user read access control for the first slave
    // 0b0..The secure user read access is disabled for the first slave.
    // 0b1..The secure user read access is enabled for the first slave.
template <size_t Index>
constexpr CSL_Reg<Index, 1,  8> LOCK_S2;  // The lock bit corresponding to the second slave.
    // It is written by the secure software.
    // 0b0..Not locked. Bits 7-0 can be written by the software.
    // 0b1..Bits 7-0 are locked and cannot be written by the software
template <size_t Index>
constexpr CSL_Reg<Index, 1,  7> NSW_S2;   // Non-secure supervisor write access control for the second slave
    // 0b0..The non-secure supervisor write access is disabled for the second slave.
    // 0b1..The non-secure supervisor write access is enabled for the second slave.
template <size_t Index>
constexpr CSL_Reg<Index, 1,  6> NUW_S2;   // Non-secure user write access control for the second slave
    // 0b0..The non-secure user write access is disabled for the second slave.
    // 0b1..The non-secure user write access is enabled for the second slave.
template <size_t Index>
constexpr CSL_Reg<Index, 1,  5> SSW_S2;   // Secure supervisor write access control for the second slave
    // 0b0..The secure supervisor write access is disabled for the second slave.
    // 0b1..The secure supervisor write access is enabled for the second slave.
template <size_t Index>
constexpr CSL_Reg<Index, 1,  4> SUW_S2;   // Secure user write access control for the second slave
    // 0b0..The secure user write access is disabled for the second slave.
    // 0b1..The secure user write access is enabled for the second slave.
template <size_t Index>
constexpr CSL_Reg<Index, 1,  3> NSR_S2;   // Non-secure supervisor read access control for the second slave
    // 0b0..The non-secure supervisor read access is disabled for the second slave.
    // 0b1..The non-secure supervisor read access is enabled for the second slave.
template <size_t Index>
constexpr CSL_Reg<Index, 1,  2> NUR_S2;   // Non-secure user read access control for the second slave
    // 0b0..The non-secure user read access is disabled for the second slave.
    // 0b1..The non-secure user read access is enabled for the second slave.
template <size_t Index>
constexpr CSL_Reg<Index, 1,  1> SSR_S2;   // Secure supervisor read access control for the second slave
    // 0b0..The secure supervisor read access is disabled for the second slave.
    // 0b1..The secure supervisor read access is enabled for the second slave.
template <size_t Index>
constexpr CSL_Reg<Index, 1,  0> SUR_S2;   // Secure user read access control for the second slave
    // 0b0..The secure user read access is disabled for the second slave.
    // 0b1..The secure user read access is enabled for the second slave.
}  // namespace CSL

// HP0 register
namespace HP0 {
constexpr CSU_Reg<&CSU_Layout::HP0, 1, 25> L_ENET2;    // Lock bit set by the TZ software for the ENET2
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::HP0, 1, 24> HP_ENET2;   // Determines whether the register value of the corresponding HP field is passed as the hprot[1] of the ENET2
    // 0b0..The hprot1 input signal value is routed to the csu_hprot1 output for the corresponding master.
    // 0b1..The HP register bit is routed to the csu_hprot1 output for the corresponding master.
constexpr CSU_Reg<&CSU_Layout::HP0, 1, 23> L_USB;      // Lock bit set by the TZ software for the USB
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::HP0, 1, 22> HP_USB;     // Determines whether the register value of the corresponding HP field is passed as the hprot[1] of the USB
    // 0b0..The hprot1 input signal value is routed to the csu_hprot1 output for the corresponding master.
    // 0b1..The HP register bit is routed to the csu_hprot1 output for the corresponding master.
constexpr CSU_Reg<&CSU_Layout::HP0, 1, 21> L_TPSMP;    // Lock bit set by the TZ software for the TPSMP
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::HP0, 1, 20> HP_TPSMP;   // Determines whether the register value of the corresponding HP field is passed as the hprot[1] of the TPSMP
    // 0b0..The hprot1 input signal value is routed to the csu_hprot1 output for the corresponding master.
    // 0b1..The HP register bit is routed to the csu_hprot1 output for the corresponding master.
constexpr CSU_Reg<&CSU_Layout::HP0, 1, 19> L_USDHC2;   // Lock bit set by the TZ software for the USDHC2
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::HP0, 1, 18> HP_USDHC2;  // Determines whether the register value of the corresponding HP field is passed as the hprot[1] of the USDHC2
    // 0b0..The hprot1 input signal value is routed to the csu_hprot1 output for the corresponding master.
    // 0b1..The HP register bit is routed to the csu_hprot1 output for the corresponding master.
constexpr CSU_Reg<&CSU_Layout::HP0, 1, 17> L_USDHC1;   // Lock bit set by the TZ software for the USDHC1
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::HP0, 1, 16> HP_USDHC1;  // Determines whether the register value of the corresponding HP field is passed as the hprot[1] of the USDHC1
    // 0b0..The hprot1 input signal value is routed to the csu_hprot1 output for the corresponding master.
    // 0b1..The HP register bit is routed to the csu_hprot1 output for the corresponding master.
constexpr CSU_Reg<&CSU_Layout::HP0, 1, 15> L_ENET;     // Lock bit set by the TZ software for the ENET
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::HP0, 1, 14> HP_ENET;    // Determines whether the register value of the corresponding HP field is passed as the hprot[1] of the ENET
    // 0b0..The hprot1 input signal value is routed to the csu_hprot1 output for the corresponding master.
    // 0b1..The HP register bit is routed to the csu_hprot1 output for the corresponding master.
constexpr CSU_Reg<&CSU_Layout::HP0, 1, 11> L_DCP;      // Lock bit set by the TZ software for the DCP
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::HP0, 1, 10> HP_DCP;     // Determines whether the register value of the corresponding HP field is passed as the hprot[1] of the DCP
    // 0b0..The hprot1 input signal value is routed to the csu_hprot1 output for the corresponding master.
    // 0b1..The HP register bit is routed to the csu_hprot1 output for the corresponding master.
constexpr CSU_Reg<&CSU_Layout::HP0, 1,  9> L_PXP;      // Lock bit set by the TZ software for the PXP
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::HP0, 1,  8> HP_PXP;     // Determines whether the register value of the corresponding HP field is passed as the hprot[1] of the PXP
    // 0b0..The hprot1 input signal value is routed to the csu_hprot1 output for the corresponding master.
    // 0b1..The HP register bit is routed to the csu_hprot1 output for the corresponding master.
constexpr CSU_Reg<&CSU_Layout::HP0, 1,  7> L_CSI;      // Lock bit set by the TZ software for the CSI
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::HP0, 1,  6> HP_CSI;     // Determines whether the register value of the corresponding HP field is passed as the hprot[1] of the CSI
    // 0b0..The hprot1 input signal value is routed to the csu_hprot1 output for the corresponding master.
    // 0b1..The HP register bit is routed to the csu_hprot1 output for the corresponding master.
constexpr CSU_Reg<&CSU_Layout::HP0, 1,  5> L_LCDIF;    // Lock bit set by the TZ software for the LCDIF
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::HP0, 1,  4> HP_LCDIF;   // Determines whether the register value of the corresponding HP field is passed as the hprot[1] of the LCDIF
    // 0b0..The hprot1 input signal value is routed to the csu_hprot1 output for the corresponding master.
    // 0b1..The HP register bit is routed to the csu_hprot1 output for the corresponding master.
constexpr CSU_Reg<&CSU_Layout::HP0, 1,  3> L_DMA;      // Lock bit set by the TZ software for the eDMA
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::HP0, 1,  2> HP_DMA;     // Determines whether the register value of the corresponding HP field is passed as the hprot[1] of the eDMA
    // 0b0..The hprot1 input signal value is routed to the csu_hprot1 output for the corresponding master.
    // 0b1..The HP register bit is routed to the csu_hprot1 output for the corresponding master.
}  // namespace HP0

// Secure access register
namespace SA {
constexpr CSU_Reg<&CSU_Layout::SA, 1, 25> L_ENET2;     // Lock bit set by the TZ software for the ENET2
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::SA, 1, 24> NSA_ENET2;   // Non-secure access policy indicator bit
    // 0b0..Secure access for the corresponding type-1 master
    // 0b1..Non-secure access for the corresponding type-1 master
constexpr CSU_Reg<&CSU_Layout::SA, 1, 23> L_USB;       // Lock bit set by the TZ software for the USB
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::SA, 1, 22> NSA_USB;     // Non-secure access policy indicator bit
    // 0b0..Secure access for the corresponding type-1 master
    // 0b1..Non-secure access for the corresponding type-1 master
constexpr CSU_Reg<&CSU_Layout::SA, 1, 21> L_TPSMP;     // Lock bit set by the TZ software for the TPSMP
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::SA, 1, 20> NSA_TPSMP;   // Non-secure access policy indicator bit
    // 0b0..Secure access for the corresponding type-1 master
    // 0b1..Non-secure access for the corresponding type-1 master
constexpr CSU_Reg<&CSU_Layout::SA, 1, 19> L_USDHC2;    // Lock bit set by the TZ software for the USDHC2
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::SA, 1, 18> NSA_USDHC2;  // Non-secure access policy indicator bit
    // 0b0..Secure access for the corresponding type-1 master
    // 0b1..Non-secure access for the corresponding type-1 master
constexpr CSU_Reg<&CSU_Layout::SA, 1, 17> L_USDHC1;    // Lock bit set by the TZ software for the USDHC1
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::SA, 1, 16> NSA_USDHC1;  // Non-secure access policy indicator bit
    // 0b0..Secure access for the corresponding type-1 master
    // 0b1..Non-secure access for the corresponding type-1 master
constexpr CSU_Reg<&CSU_Layout::SA, 1, 15> L_ENET;      // Lock bit set by the TZ software for the ENET
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::SA, 1, 14> NSA_ENET;    // Non-secure access policy indicator bit
    // 0b0..Secure access for the corresponding type-1 master
    // 0b1..Non-secure access for the corresponding type-1 master
constexpr CSU_Reg<&CSU_Layout::SA, 1, 11> L_DCP;       // Lock bit set by the TZ software for the DCP
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::SA, 1, 10> NSA_DCP;     // Non-secure access policy indicator bit
    // 0b0..Secure access for the corresponding type-1 master
    // 0b1..Non-secure access for the corresponding type-1 master
constexpr CSU_Reg<&CSU_Layout::SA, 1,  9> L_PXP;       // Lock bit set by the TZ software for the PXP
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::SA, 1,  8> NSA_PXP;     // Non-Secure Access Policy indicator bit
    // 0b0..Secure access for the corresponding type-1 master
    // 0b1..Non-secure access for the corresponding type-1 master
constexpr CSU_Reg<&CSU_Layout::SA, 1,  7> L_CSI;       // Lock bit set by the TZ software for the CSI
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::SA, 1,  6> NSA_CSI;     // Non-secure access policy indicator bit
    // 0b0..Secure access for the corresponding type-1 master
    // 0b1..Non-secure access for the corresponding type-1 master
constexpr CSU_Reg<&CSU_Layout::SA, 1,  5> L_LCDIF;     // Lock bit set by the TZ software for the LCDIF
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::SA, 1,  4> NSA_LCDIF;   // Non-secure access policy indicator bit
    // 0b0..Secure access for the corresponding type-1 master
    // 0b1..Non-secure access for the corresponding type-1 master
constexpr CSU_Reg<&CSU_Layout::SA, 1,  3> L_DMA;       // Lock bit set by the TZ software for the eDMA
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::SA, 1,  2> NSA_DMA;     // Non-secure access policy indicator bit
    // 0b0..Secure access for the corresponding type-1 master
    // 0b1..Non-secure access for the corresponding type-1 master
}  // namespace SA

// HPCONTROL0 register
namespace HPCONTROL0 {
constexpr CSU_Reg<&CSU_Layout::HPCONTROL0, 1, 25> L_ENET2;     // Lock bit set by the TZ software for the ENET2
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::HPCONTROL0, 1, 24> HPC_ENET2;   // Indicates the privilege/user mode for the ENET2
    // 0b0..User mode for the corresponding master
    // 0b1..Supervisor mode for the corresponding master
constexpr CSU_Reg<&CSU_Layout::HPCONTROL0, 1, 23> L_USB;       // Lock bit set by the TZ software for the USB.
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::HPCONTROL0, 1, 22> HPC_USB;     // Indicates the privilege/user mode for the USB
    // 0b0..User mode for the corresponding master
    // 0b1..Supervisor mode for the corresponding master
constexpr CSU_Reg<&CSU_Layout::HPCONTROL0, 1, 21> L_TPSMP;     // Lock bit set by the TZ software for the TPSMP.
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::HPCONTROL0, 1, 20> HPC_TPSMP;   // Indicates the privilege/user mode for the TPSMP
    // 0b0..User mode for the corresponding master
    // 0b1..Supervisor mode for the corresponding master
constexpr CSU_Reg<&CSU_Layout::HPCONTROL0, 1, 19> L_USDHC2;    // Lock bit set by the TZ software for the USDHC2.
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::HPCONTROL0, 1, 18> HPC_USDHC2;  // Indicates the privilege/user mode for the USDHC2
    // 0b0..User mode for the corresponding master
    // 0b1..Supervisor mode for the corresponding master
constexpr CSU_Reg<&CSU_Layout::HPCONTROL0, 1, 17> L_USDHC1;    // Lock bit set by the TZ software for the USDHC1
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::HPCONTROL0, 1, 16> HPC_USDHC1;  // Indicates the privilege/user mode for the USDHC1
    // 0b0..User mode for the corresponding master
    // 0b1..Supervisor mode for the corresponding master
constexpr CSU_Reg<&CSU_Layout::HPCONTROL0, 1, 15> L_ENET;      // Lock bit set by the TZ software for the ENET
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::HPCONTROL0, 1, 14> HPC_ENET;    // Indicates the privilege/user mode for the ENET
    // 0b0..User mode for the corresponding master
    // 0b1..Supervisor mode for the corresponding master
constexpr CSU_Reg<&CSU_Layout::HPCONTROL0, 1, 11> L_DCP;       // Lock bit set by the TZ software for the DCP
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::HPCONTROL0, 1, 10> HPC_DCP;     // Indicates the privilege/user mode for the DCP
    // 0b0..User mode for the corresponding master
    // 0b1..Supervisor mode for the corresponding master
constexpr CSU_Reg<&CSU_Layout::HPCONTROL0, 1,  9> L_PXP;       // Lock bit set by the TZ software for the PXP
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::HPCONTROL0, 1,  8> HPC_PXP;     // Indicates the privilege/user mode for the PXP
    // 0b0..User mode for the corresponding master
    // 0b1..Supervisor mode for the corresponding master
constexpr CSU_Reg<&CSU_Layout::HPCONTROL0, 1,  7> L_CSI;       // Lock bit set by the TZ software for the CSI
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::HPCONTROL0, 1,  6> HPC_CSI;     // Indicates the privilege/user mode for the CSI
    // 0b0..User mode for the corresponding master
    // 0b1..Supervisor mode for the corresponding master
constexpr CSU_Reg<&CSU_Layout::HPCONTROL0, 1,  5> L_LCDIF;     // Lock bit set by the TZ software for the LCDIF
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::HPCONTROL0, 1,  4> HPC_LCDIF;   // Indicates the privilege/user mode for the LCDIF
    // 0b0..User mode for the corresponding master
    // 0b1..Supervisor mode for the corresponding master
constexpr CSU_Reg<&CSU_Layout::HPCONTROL0, 1,  3> L_DMA;       // Lock bit set by the TZ software for the eDMA
    // 0b0..Not locked: the adjacent (next lower) bit can be written by software.
    // 0b1..Locked: the adjacent (next lower) bit cannot be written by software.
constexpr CSU_Reg<&CSU_Layout::HPCONTROL0, 1,  2> HPC_DMA;     // Indicates the privilege/user mode for the eDMA
    // 0b0..User mode for the corresponding master
    // 0b1..Supervisor mode for the corresponding master
}  // namespace HPCONTROL0

}  // namespace CSU

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
