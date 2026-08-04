// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// USBNC.h defines all the USBNC registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "qindesign/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the USB Non-Core (USBNC) registers.
//
// Comments are from BSD-3-licensed NXP SDK sources.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_USBNC.h
// * https://github.com/nxp-mcuxpresso/mcux-soc-svd/blob/main/MIMXRT1062/MIMXRT1062.xml
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h

struct USBNC_Layout {
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[512];
  volatile uint32_t USB_OTG_CTRL;                     /**< USB OTG Control Register, offset: 0x800 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[5];
  volatile uint32_t USB_OTG_PHY_CTRL_0;               /**< OTG UTMI PHY Control 0 Register, offset: 0x818 */
};

constexpr size_t    kUSBNC_size  = 0x81C;
constexpr uintptr_t kUSBNC1_base = 0x402E'0000;
constexpr uintptr_t kUSBNC2_base = 0x402E'0004;

namespace USBNC1 {
constexpr regs::RegGroup<USBNC_Layout, kUSBNC_size, kUSBNC1_base> group;
}  // namespace USBNC1

namespace USBNC2 {
constexpr regs::RegGroup<USBNC_Layout, kUSBNC_size, kUSBNC2_base> group;
}  // namespace USBNC2

namespace USBNC1 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using USBNC1_Reg =
    regs::Reg32<kUSBNC1_base, USBNC_Layout, Member, 0, Bits, Shift, AssignMask>;

// USB OTG Control Register
namespace USB_OTG_CTRL {
constexpr USBNC1_Reg<regs::constify(&USBNC_Layout::USB_OTG_CTRL), 1, 31> WIR;  // OTG Wake-up Interrupt Request This bit indicates that a wake-up interrupt request is received on the OTG port
    // 0b0..No wake-up interrupt request received
    // 0b1..Wake-up Interrupt Request received
constexpr USBNC1_Reg<&USBNC_Layout::USB_OTG_CTRL, 1, 29> WKUP_DPDM_EN;         // Wake-up on DPDM change enable
    // 0b0..DPDM changes wake-up to be disabled only when VBUS is 0.
    // 0b1..(Default) DPDM changes wake-up to be enabled, it is for device only.
constexpr USBNC1_Reg<&USBNC_Layout::USB_OTG_CTRL, 1, 17> WKUP_VBUS_EN;         // OTG wake-up on VBUS change enable
    // 0b0..Disable
    // 0b1..Enable
constexpr USBNC1_Reg<&USBNC_Layout::USB_OTG_CTRL, 1, 16> WKUP_ID_EN;           // OTG Wake-up on ID change enable
    // 0b0..Disable
    // 0b1..Enable
constexpr USBNC1_Reg<&USBNC_Layout::USB_OTG_CTRL, 1, 15> WKUP_SW;              // OTG Software Wake-up
    // 0b0..Inactive
    // 0b1..Force wake-up
constexpr USBNC1_Reg<&USBNC_Layout::USB_OTG_CTRL, 1, 14> WKUP_SW_EN;           // OTG Software Wake-up Enable
    // 0b0..Disable
    // 0b1..Enable
constexpr USBNC1_Reg<&USBNC_Layout::USB_OTG_CTRL, 1, 10> WIE;                  // OTG Wake-up Interrupt Enable This bit enables or disables the OTG wake-up interrupt
    // 0b0..Interrupt Disabled
    // 0b1..Interrupt Enabled
constexpr USBNC1_Reg<&USBNC_Layout::USB_OTG_CTRL, 1,  9> PWR_POL;              // OTG Power Polarity This bit should be set according to PMIC Power Pin polarity.
    // 0b0..PMIC Power Pin is Low active.
    // 0b1..PMIC Power Pin is High active.
constexpr USBNC1_Reg<&USBNC_Layout::USB_OTG_CTRL, 1,  8> OVER_CUR_POL;         // OTG Polarity of Overcurrent The polarity of OTG port overcurrent event
    // 0b0..High active (high on this signal represents an overcurrent condition)
    // 0b1..Low active (low on this signal represents an overcurrent condition)
constexpr USBNC1_Reg<&USBNC_Layout::USB_OTG_CTRL, 1,  7> OVER_CUR_DIS;         // Disable OTG Overcurrent Detection
    // 0b0..Enables overcurrent detection
    // 0b1..Disables overcurrent detection
}  // namespace USB_OTG_CTRL

// OTG UTMI PHY Control 0 Register
namespace USB_OTG_PHY_CTRL_0 {
constexpr USBNC1_Reg<&USBNC_Layout::USB_OTG_PHY_CTRL_0, 1, 31> UTMI_CLK_VLD;  // Indicating whether OTG UTMI PHY clock is valid
    // 0b0..Invalid
    // 0b1..Valid
}  // namespace USB_OTG_PHY_CTRL_0

}  // namespace USBNC1

namespace USBNC2 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using USBNC2_Reg =
    regs::Reg32<kUSBNC2_base, USBNC_Layout, Member, 0, Bits, Shift, AssignMask>;

// USB OTG Control Register
namespace USB_OTG_CTRL {
constexpr USBNC2_Reg<regs::constify(&USBNC_Layout::USB_OTG_CTRL), 1, 31> WIR;
constexpr USBNC2_Reg<&USBNC_Layout::USB_OTG_CTRL, 1, 29> WKUP_DPDM_EN;
constexpr USBNC2_Reg<&USBNC_Layout::USB_OTG_CTRL, 1, 17> WKUP_VBUS_EN;
constexpr USBNC2_Reg<&USBNC_Layout::USB_OTG_CTRL, 1, 16> WKUP_ID_EN;
constexpr USBNC2_Reg<&USBNC_Layout::USB_OTG_CTRL, 1, 15> WKUP_SW;
constexpr USBNC2_Reg<&USBNC_Layout::USB_OTG_CTRL, 1, 14> WKUP_SW_EN;
constexpr USBNC2_Reg<&USBNC_Layout::USB_OTG_CTRL, 1, 10> WIE;
constexpr USBNC2_Reg<&USBNC_Layout::USB_OTG_CTRL, 1,  9> PWR_POL;
constexpr USBNC2_Reg<&USBNC_Layout::USB_OTG_CTRL, 1,  8> OVER_CUR_POL;
constexpr USBNC2_Reg<&USBNC_Layout::USB_OTG_CTRL, 1,  7> OVER_CUR_DIS;
}  // namespace USB_OTG_CTRL

// OTG UTMI PHY Control 0 Register
namespace USB_OTG_PHY_CTRL_0 {
constexpr USBNC2_Reg<&USBNC_Layout::USB_OTG_PHY_CTRL_0, 1, 31> UTMI_CLK_VLD;
}  // namespace USB_OTG_PHY_CTRL_0

}  // namespace USBNC2

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
