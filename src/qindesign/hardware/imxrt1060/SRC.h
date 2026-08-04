// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// SRC.h defines all the SRC registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>
#include <type_traits>

#include "qindesign/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the System Reset Controller (SRC) registers.
//
// Comments are from BSD-3-licensed NXP SDK sources and the NXP reference
// manual.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_SRC.h
// * https://github.com/nxp-mcuxpresso/mcux-soc-svd/blob/main/MIMXRT1062/MIMXRT1062.xml
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
// * i.MX RT1060 Processor Reference Manual, Rev. 4, chapter 21
struct SRC_Layout {
  volatile uint32_t SCR;                               /**< SRC Control Register, offset: 0x0 */
  const volatile uint32_t SBMR1;                       /**< SRC Boot Mode Register 1, offset: 0x4 */
  volatile uint32_t SRSR;                              /**< SRC Reset Status Register, offset: 0x8 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[4];
  const volatile uint32_t SBMR2;                       /**< SRC Boot Mode Register 2, offset: 0x1C */
  volatile uint32_t GPR1;                              /**< SRC General Purpose Register 1, offset: 0x20 */
  volatile uint32_t GPR2;                              /**< SRC General Purpose Register 2, offset: 0x24 */
  volatile uint32_t GPR3;                              /**< SRC General Purpose Register 3, offset: 0x28 */
  volatile uint32_t GPR4;                              /**< SRC General Purpose Register 4, offset: 0x2C */
  volatile uint32_t GPR5;                              /**< SRC General Purpose Register 5, offset: 0x30 */
  volatile uint32_t GPR6;                              /**< SRC General Purpose Register 6, offset: 0x34 */
  volatile uint32_t GPR7;                              /**< SRC General Purpose Register 7, offset: 0x38 */
  volatile uint32_t GPR8;                              /**< SRC General Purpose Register 8, offset: 0x3C */
  const volatile uint32_t GPR9;                        /**< Reserved, SRC General Purpose Register 9, offset: 0x40 */
  volatile uint32_t GPR10;                             /**< SRC General Purpose Register 10, offset: 0x44 */
};

constexpr size_t    kSRC_size = 0x48;
constexpr uintptr_t kSRC_base = 0x400F'8000;

namespace SRC {

constexpr regs::RegGroup<SRC_Layout, kSRC_size, kSRC_base> group;

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>(),
          auto AssignSet = 0, bool WriteOnly = false>
using SRC_Reg = regs::Reg32<kSRC_base, SRC_Layout, Member, 0, Bits, Shift,
                            AssignMask, AssignSet, WriteOnly>;

// SRC Control Register
namespace SCR {
constexpr SRC_Reg<&SRC_Layout::SCR, 4, 28> MASK_WDOG3_RST;  // Mask wdog3_rst_b source
    // 0b0101..wdog3_rst_b is masked
    // 0b1010..wdog3_rst_b is not masked
constexpr SRC_Reg<&SRC_Layout::SCR, 1, 25> DBG_RST_MSK_PG;  // Do not assert debug resets after power gating event of core
    // 0b0..do not mask core debug resets (debug resets will be asserted after power gating event)
    // 0b1..mask core debug resets (debug resets won't be asserted after power gating event)
constexpr SRC_Reg<&SRC_Layout::SCR, 1, 17> CORE0_DBG_RST;   // Software reset for core0 debug only
    // 0b0..do not assert core0 debug reset
    // 0b1..assert core0 debug reset
constexpr SRC_Reg<&SRC_Layout::SCR, 1, 13> CORE0_RST;       // Software reset for core0 only
    // 0b0..do not assert core0 reset
    // 0b1..assert core0 reset
constexpr SRC_Reg<&SRC_Layout::SCR, 4,  7> MASK_WDOG_RST;   // Mask wdog_rst_b source
    // 0b0101..wdog_rst_b is masked
    // 0b1010..wdog_rst_b is not masked (default)
}  // namespace SCR

// SRC Boot Mode Register 1
namespace SBMR1 {
constexpr SRC_Reg<&SRC_Layout::SBMR1, 8, 24> BOOT_CFG4;  // Refer to fusemap.
constexpr SRC_Reg<&SRC_Layout::SBMR1, 8, 16> BOOT_CFG3;  // Refer to fusemap.
constexpr SRC_Reg<&SRC_Layout::SBMR1, 8,  8> BOOT_CFG2;  // Refer to fusemap.
constexpr SRC_Reg<&SRC_Layout::SBMR1, 8,  0> BOOT_CFG1;  // Refer to fusemap.
}  // namespace SBMR1

// SRC Reset Status Register
namespace SRSR {
constexpr uint32_t kW1C = 0x0000'00FF;

constexpr SRC_Reg<&SRC_Layout::SRSR, 1, 8, regs::shiftedMask32<1, 8>() | kW1C> TEMPSENSE_RST_B;  // Temper Sensor software reset
    // Writing 0 clears this field.
    // 0b0..Reset is not a result of software reset from Temperature Sensor.
    // 0b1..Reset is a result of software reset from Temperature Sensor.
constexpr SRC_Reg<&SRC_Layout::SRSR, 1, 7, kW1C> WDOG3_RST_B;                                    // IC Watchdog3 Time-out reset
    // Writing 1 clears this field.
    // 0b0..Reset is not a result of the watchdog3 time-out event.
    // 0b1..Reset is a result of the watchdog3 time-out event.
constexpr SRC_Reg<&SRC_Layout::SRSR, 1, 6, kW1C> JTAG_SW_RST;                                    // JTAG software reset.
    // Indicates whether the reset was the result of software reset from JTAG.
    // Writing 1 clears this field.
    // 0b0..Reset is not a result of the mentioned case.
    // 0b1..Reset is a result of the mentioned case.
constexpr SRC_Reg<&SRC_Layout::SRSR, 1, 5, kW1C> JTAG_RST_B;                                     // HIGH - Z JTAG reset.
    // Indicates whether the reset was the result of HIGH-Z reset from JTAG.
    // Writing 1 clears this field.
    // 0b0..Reset is not a result of HIGH-Z reset from JTAG.
    // 0b1..Reset is a result of HIGH-Z reset from JTAG.
constexpr SRC_Reg<&SRC_Layout::SRSR, 1, 4, kW1C> WDOG_RST_B;                                     // IC Watchdog Time-out reset
    // Writing 1 clears this field.
    // 0b0..Reset is not a result of the watchdog time-out event.
    // 0b1..Reset is a result of the watchdog time-out event.
constexpr SRC_Reg<&SRC_Layout::SRSR, 1, 3, kW1C> IPP_USER_RESET_B;                               // Indicates whether the reset was the result of the ipp_user_reset_b qualified reset.
    // Writing 1 clears this field.
    // 0b0..Reset is not a result of the ipp_user_reset_b qualified as COLD reset event.
    // 0b1..Reset is a result of the ipp_user_reset_b qualified as COLD reset event.
constexpr SRC_Reg<&SRC_Layout::SRSR, 1, 2, kW1C> CSU_RESET_B;                                    // Indicates whether the reset was the result of the csu_reset_b input.
    // Writing 1 clears this field.
    // 0b0..Reset is not a result of the csu_reset_b event.
    // 0b1..Reset is a result of the csu_reset_b event.
constexpr SRC_Reg<&SRC_Layout::SRSR, 1, 1, kW1C> LOCKUP_SYSRESETREQ;                             // Indicates a reset has been caused by CPU lockup or software setting of SYSRESETREQ bit in Application Interrupt and Reset Control Register of the Arm core
    // Writing 1 clears this field.
    // 0b0..Reset is not a result of the mentioned case.
    // 0b1..Reset is a result of the mentioned case.
constexpr SRC_Reg<&SRC_Layout::SRSR, 1, 0, kW1C> IPP_RESET_B;                                    // Indicates whether reset was the result of ipp_reset_b pin (Power-up sequence)
    // Writing 1 clears this field.
    // 0b0..Reset is not a result of ipp_reset_b pin.
    // 0b1..Reset is a result of ipp_reset_b pin.
}  // namespace SRSR

// SRC Boot Mode Register 2
namespace SBMR2 {
constexpr SRC_Reg<&SRC_Layout::SBMR2, 2, 24> BMOD;         // BMOD[1:0] shows the latched state of the BOOT_MODE1 and BOOT_MODE0 signals on the rising edge of POR_B
constexpr SRC_Reg<&SRC_Layout::SBMR2, 1,  4> BT_FUSE_SEL;  // BT_FUSE_SEL (connected to gpio bt_fuse_sel) shows the state of the BT_FUSE_SEL fuse
constexpr SRC_Reg<&SRC_Layout::SBMR2, 2,  0> SEC_CONFIG;   // SECONFIG[1] shows the state of the SECONFIG[1] fuse
}  // namespace SBMR2

// SRC General Purpose Register 1
namespace GPR1 {
constexpr SRC_Reg<&SRC_Layout::GPR1, 32, 0> PERSISTENT_ENTRY0;  // Holds entry function for core0 for waking-up from low power mode
}  // namespace GPR1

// SRC General Purpose Register 2
namespace GPR2 {
constexpr SRC_Reg<&SRC_Layout::GPR2, 32, 0> PERSISTENT_ARG0;  // Holds argument of entry function for core0 for waking-up from low power mode
}  // namespace GPR2

// SRC General Purpose Register 10
namespace GPR10 {
constexpr SRC_Reg<&SRC_Layout::GPR10, 1, 30> PERSIST_SECONDARY_BOOT;  // This bit identifies which image must be used - primary and secondary
    // 0b0: Use the primary image.
    // 0b1: Use the secondary image.
constexpr SRC_Reg<&SRC_Layout::GPR10, 2, 26> PERSIST_REDUNDANT_BOOT;  // This field identifies which image must be used - 0/1/2/3
    // Used for both SPI NAND and SLC raw NAND devices.
}  // namespace GPR10

}  // namespace SRC

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
