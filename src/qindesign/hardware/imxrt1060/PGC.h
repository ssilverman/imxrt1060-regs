// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// PGC.h defines all the PGC registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "qindesign/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the Power Gating Controller (PGC) registers.
//
// Comments are from BSD-3-licensed NXP SDK and the NXP reference manual.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_PGC.h
// * https://github.com/nxp-mcuxpresso/mcux-soc-svd/blob/main/MIMXRT1062/MIMXRT1062.xml
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
// * i.MX RT1060 Processor Reference Manual, Rev. 4, chapter 17
struct PGC_Layout {
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[136];
  volatile uint32_t MEGA_CTRL;                         /**< PGC Mega Control Register, offset: 0x220 */
  volatile uint32_t MEGA_PUPSCR;                       /**< PGC Mega Power Up Sequence Control Register, offset: 0x224 */
  volatile uint32_t MEGA_PDNSCR;                       /**< PGC Mega Pull Down Sequence Control Register, offset: 0x228 */
  volatile uint32_t MEGA_SR;                           /**< PGC Mega Power Gating Controller Status Register, offset: 0x22C */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[28];
  volatile uint32_t CPU_CTRL;                          /**< PGC CPU Control Register, offset: 0x2A0 */
  volatile uint32_t CPU_PUPSCR;                        /**< PGC CPU Power Up Sequence Control Register, offset: 0x2A4 */
  volatile uint32_t CPU_PDNSCR;                        /**< PGC CPU Pull Down Sequence Control Register, offset: 0x2A8 */
  volatile uint32_t CPU_SR;                            /**< PGC CPU Power Gating Controller Status Register, offset: 0x2AC */
};

constexpr size_t    kPGC_size = 0x2B0;
constexpr uintptr_t kPGC_base = 0x400F'4000;

namespace PGC {
constexpr regs::RegGroup<PGC_Layout, kPGC_size, kPGC_base> group;
}  // namespace PGC

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using PGC_Reg =
    regs::Reg32<kPGC_base, PGC_Layout, Member, 0, Bits, Shift, AssignMask>;

namespace PGC {

// PGC Mega Control Register
namespace MEGA_CTRL {
constexpr PGC_Reg<&PGC_Layout::MEGA_CTRL, 1, 0, 0x0> PCR;  // Power Control.
    // PCR must not change from power-down request (pdn_req) assertion until the target subsystem is completely powered up
    // Direct-assign because there's only one writable field
    // 0b0..Do not switch off power even if pdn_req is asserted.
    // 0b1..Switch off power when pdn_req is asserted.
}  // namespace MEGA_CTRL

// PGC Mega Power Up Sequence Control Register
namespace MEGA_PUPSCR {
constexpr PGC_Reg<&PGC_Layout::MEGA_PUPSCR, 6, 8> SW2ISO;  // After asserting power toggle on/off signal (switch_b) to switch on power, the PGC waits a number of IPG clocks equal to the value of SW2ISO before negating isolation
    // Must not be programmed to zero.
constexpr PGC_Reg<&PGC_Layout::MEGA_PUPSCR, 6, 0> SW;      // After a power-up request (pup_req assertion), the PGC waits a number of IPG clocks equal to the value of SW before asserting power toggle on/off signal (switch_b) to switch on power
    // Must not be programmed to zero.
}  // namespace MEGA_PUPSCR

// PGC Mega Pull Down Sequence Control Register
namespace MEGA_PDNSCR {
constexpr PGC_Reg<&PGC_Layout::MEGA_PDNSCR, 6, 8> ISO2SW;  // After asserting isolation, the PGC waits a number of IPG clocks equal to the value of ISO2SW before negating power toggle on/off signal (switch_b) to switch off power
    // Must not be programmed to zero.
constexpr PGC_Reg<&PGC_Layout::MEGA_PDNSCR, 6, 0> ISO;     // After a power-down request (pdn_req assertion), the PGC waits a number of IPG clocks equal to the value of ISO before asserting isolation
    // Must not be programmed to zero.
}  // namespace MEGA_PDNSCR

// PGC Mega Power Gating Controller Status Register
namespace MEGA_SR {
constexpr PGC_Reg<&PGC_Layout::MEGA_SR, 1, 0, 0x0> PSR;  // Power status
    // Direct-assign because there's only one writable field
    // Writing 1 clears this status flag.
    // 0b0..The target subsystem was not powered down for the previous power-down request.
    // 0b1..The target subsystem was powered down for the previous power-down request.
}  // namespace MEGA_SR

// PGC CPU Control Register
namespace CPU_CTRL {
constexpr PGC_Reg<&PGC_Layout::CPU_CTRL, 1, 0, 0x0> PCR;  // Power Control.
    // PCR must not change from power-down request (pdn_req) assertion until the target subsystem is completely powered up
    // Direct-assign because there's only one writable field
    // 0b0..Do not switch off power even if pdn_req is asserted.
    // 0b1..Switch off power when pdn_req is asserted.
}  // namespace CPU_CTRL

// PGC CPU Power Up Sequence Control Register
namespace CPU_PUPSCR {
constexpr PGC_Reg<&PGC_Layout::CPU_PUPSCR, 6, 8> SW2ISO;  // After asserting power toggle on/off signal (switch_b) to switch on power, the PGC waits a number of IPG clocks equal to the value of SW2ISO before negating isolation
    // Must not be programmed to zero.
constexpr PGC_Reg<&PGC_Layout::CPU_PUPSCR, 6, 0> SW;      // After a power-up request (pup_req assertion), the PGC waits a number of IPG clocks equal to the value of SW before asserting power toggle on/off signal (switch_b) to switch on power
    // Must not be programmed to zero.
}  // namespace CPU_PUPSCR

// PGC CPU Pull Down Sequence Control Register
namespace CPU_PDNSCR {
constexpr PGC_Reg<&PGC_Layout::CPU_PDNSCR, 6, 8> ISO2SW;  // After asserting isolation, the PGC waits a number of IPG clocks equal to the value of ISO2SW before negating power toggle on/off signal (switch_b) to switch off power
    // Must not be programmed to zero.
constexpr PGC_Reg<&PGC_Layout::CPU_PDNSCR, 6, 0> ISO;     // After a power-down request (pdn_req assertion), the PGC waits a number of IPG clocks equal to the value of ISO before asserting isolation
    // Must not be programmed to zero.
}  // namespace CPU_PDNSCR

// PGC CPU Power Gating Controller Status Register
namespace CPU_SR {
constexpr PGC_Reg<&PGC_Layout::CPU_SR, 1, 0, 0x0> PSR;  // Power status
    // Direct-assign because there's only one writable field
    // Writing 1 clears this status flag.
    // 0b0..The target subsystem was not powered down for the previous power-down request.
    // 0b1..The target subsystem was powered down for the previous power-down request.
}  // namespace CPU_SR

}  // namespace PGC

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
