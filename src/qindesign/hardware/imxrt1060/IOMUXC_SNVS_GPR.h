// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// IOMUXC_SNVS_GPR.h defines all the IOMUXC_SNVS_GPR registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "qindesign/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the IOMUX Controller SNVS general-purpose
// (IOMUXC_SNVS_GPR) registers.
//
// Comments are from BSD-3-licensed NXP SDK and the NXP reference manual.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_IOMUXC_SNVS_GPR.h
// * https://github.com/nxp-mcuxpresso/mcux-soc-svd/blob/main/MIMXRT1062/MIMXRT1062.xml
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct IOMUXC_SNVS_GPR_Layout {
  const volatile uint32_t GPR0;                        /**< Reserved, GPR0 General Purpose Register, offset: 0x0 */
  const volatile uint32_t GPR1;                        /**< Reserved, GPR1 General Purpose Register, offset: 0x4 */
  const volatile uint32_t GPR2;                        /**< Reserved, GPR2 General Purpose Register, offset: 0x8 */
  volatile uint32_t GPR3;                              /**< GPR3 General Purpose Register, offset: 0xC */
};

constexpr size_t    kIOMUXC_SNVS_GPR_size = 0x10;
constexpr uintptr_t kIOMUXC_SNVS_GPR_base = 0x400A'4000;

namespace IOMUXC_SNVS_GPR {
constexpr regs::RegGroup<IOMUXC_SNVS_GPR_Layout, kIOMUXC_SNVS_GPR_size,
                         kIOMUXC_SNVS_GPR_base>
    group;
}  // namespace IOMUXC_SNVS_GPR

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using IOMUXC_SNVS_GPR_Reg =
    regs::Reg32<kIOMUXC_SNVS_GPR_base, IOMUXC_SNVS_GPR_Layout, Member, 0, Bits,
                Shift, AssignMask>;

namespace IOMUXC_SNVS_GPR {

// GPR3 General Purpose Register
namespace GPR3 {
constexpr IOMUXC_SNVS_GPR_Reg<regs::constify(&IOMUXC_SNVS_GPR_Layout::GPR3), 1, 19> DCDC_STS_DC_OK;   // DCDC status OK
    // 0b0..DCDC is ramping up and not ready
    // 0b1..DCDC is ready
constexpr IOMUXC_SNVS_GPR_Reg<regs::constify(&IOMUXC_SNVS_GPR_Layout::GPR3), 1, 18> DCDC_OVER_VOL;    // DCDC output over voltage alert
    // 0b0..No over voltage detected
    // 0b1..Over voltage detected
constexpr IOMUXC_SNVS_GPR_Reg<regs::constify(&IOMUXC_SNVS_GPR_Layout::GPR3), 1, 17> DCDC_OVER_CUR;    // DCDC output over current alert
    // 0b0..No over current detected
    // 0b1..Over current detected
constexpr IOMUXC_SNVS_GPR_Reg<regs::constify(&IOMUXC_SNVS_GPR_Layout::GPR3), 1, 16> DCDC_IN_LOW_VOL;  // DCDC_IN low voltage detect.
    // 0b0..DCDC_IN is ok
    // 0b1..DCDC_IN is too low
constexpr IOMUXC_SNVS_GPR_Reg<&IOMUXC_SNVS_GPR_Layout::GPR3, 2,  2> POR_PULL_TYPE;                    // POR_B pad control
    // 0b00..100 Ohm pull up enabled for POR_B always
    // 0b01..Disable pull in SNVS mode, 100 Ohm pull up enabled otherwise
    // 0b10..Disable pull of POR_B always
    // 0b11..100 Ohm pull down enabled in SNVS mode, 100 Ohm pull up enabled otherwise
constexpr IOMUXC_SNVS_GPR_Reg<&IOMUXC_SNVS_GPR_Layout::GPR3, 1,  1> DCDC_STATUS_CAPT_CLR;             // DCDC captured status clear
    // Write 1 to clear the three captured DCDC status bits, then write 0 to re-enable status capture.
constexpr IOMUXC_SNVS_GPR_Reg<&IOMUXC_SNVS_GPR_Layout::GPR3, 1,  0> LPSR_MODE_ENABLE;                 // Set to enable LPSR mode.
    // 0b0..SNVS domain will reset when system reset happens
    // 0b1..SNVS domain will only reset with SNVS POR
}  // namespace GPR3

}  // namespace IOMUXC_SNVS_GPR

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
