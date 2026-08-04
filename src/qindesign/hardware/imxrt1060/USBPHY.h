// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// USBPHY.h defines all the USBPHY registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "qindesign/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the USB PHY (USBPHY) registers.
//
// Comments are from BSD-3-licensed NXP SDK sources.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_USBPHY.h
// * https://github.com/nxp-mcuxpresso/mcux-soc-svd/blob/main/MIMXRT1062/MIMXRT1062.xml
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h

struct USBPHY_Layout {
  volatile uint32_t PWD;                               /**< USB PHY Power-Down Register, offset: 0x0 */
  volatile uint32_t PWD_SET;                           /**< USB PHY Power-Down Register, offset: 0x4 */
  volatile uint32_t PWD_CLR;                           /**< USB PHY Power-Down Register, offset: 0x8 */
  volatile uint32_t PWD_TOG;                           /**< USB PHY Power-Down Register, offset: 0xC */
  volatile uint32_t TX;                                /**< USB PHY Transmitter Control Register, offset: 0x10 */
  volatile uint32_t TX_SET;                            /**< USB PHY Transmitter Control Register, offset: 0x14 */
  volatile uint32_t TX_CLR;                            /**< USB PHY Transmitter Control Register, offset: 0x18 */
  volatile uint32_t TX_TOG;                            /**< USB PHY Transmitter Control Register, offset: 0x1C */
  volatile uint32_t RX;                                /**< USB PHY Receiver Control Register, offset: 0x20 */
  volatile uint32_t RX_SET;                            /**< USB PHY Receiver Control Register, offset: 0x24 */
  volatile uint32_t RX_CLR;                            /**< USB PHY Receiver Control Register, offset: 0x28 */
  volatile uint32_t RX_TOG;                            /**< USB PHY Receiver Control Register, offset: 0x2C */
  volatile uint32_t CTRL;                              /**< USB PHY General Control Register, offset: 0x30 */
  volatile uint32_t CTRL_SET;                          /**< USB PHY General Control Register, offset: 0x34 */
  volatile uint32_t CTRL_CLR;                          /**< USB PHY General Control Register, offset: 0x38 */
  volatile uint32_t CTRL_TOG;                          /**< USB PHY General Control Register, offset: 0x3C */
  volatile uint32_t STATUS;                            /**< USB PHY Status Register, offset: 0x40 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t DEBUG;                             /**< USB PHY Debug Register, offset: 0x50, 'r' suffix has been added to avoid clash with DEBUG symbolic constant */
  volatile uint32_t DEBUG_SET;                         /**< USB PHY Debug Register, offset: 0x54 */
  volatile uint32_t DEBUG_CLR;                         /**< USB PHY Debug Register, offset: 0x58 */
  volatile uint32_t DEBUG_TOG;                         /**< USB PHY Debug Register, offset: 0x5C */
  const volatile uint32_t DEBUG0_STATUS;               /**< UTMI Debug Status Register 0, offset: 0x60 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t DEBUG1;                            /**< UTMI Debug Status Register 1, offset: 0x70 */
  volatile uint32_t DEBUG1_SET;                        /**< UTMI Debug Status Register 1, offset: 0x74 */
  volatile uint32_t DEBUG1_CLR;                        /**< UTMI Debug Status Register 1, offset: 0x78 */
  volatile uint32_t DEBUG1_TOG;                        /**< UTMI Debug Status Register 1, offset: 0x7C */
  const volatile uint32_t VERSION;                     /**< UTMI RTL Version, offset: 0x80 */
};

constexpr size_t    kUSBPHY_size  = 0x84;
constexpr uintptr_t kUSBPHY1_base = 0x400D'9000;
constexpr uintptr_t kUSBPHY2_base = 0x400D'A000;

namespace USBPHY1 {
constexpr regs::RegGroup<USBPHY_Layout, kUSBPHY_size, kUSBPHY1_base> group;
}  // namespace USBPHY1

namespace USBPHY2 {
constexpr regs::RegGroup<USBPHY_Layout, kUSBPHY_size, kUSBPHY2_base> group;
}  // namespace USBPHY2

namespace USBPHY1 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using USBPHY1_Reg =
    regs::Reg32<kUSBPHY1_base, USBPHY_Layout, Member, 0, Bits, Shift, AssignMask>;

// USB PHY Power-Down Register
namespace PWD {
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::PWD), 11, 21> RSVD2;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD,  1, 20> RXPWDRX;                // 0 = Normal operation
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD,  1, 19> RXPWDDIFF;              // 0 = Normal operation
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD,  1, 18> RXPWD1PT1;              // 0 = Normal operation
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD,  1, 17> RXPWDENV;               // 0 = Normal operation
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::PWD),  4, 13> RSVD1;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD,  1, 12> TXPWDV2I;               // 0 = Normal operation
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD,  1, 11> TXPWDIBIAS;             // 0 = Normal operation
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD,  1, 10> TXPWDFS;                // 0 = Normal operation
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::PWD), 10,  0> RSVD0;  // Reserved.
}  // namespace PWD

// USB PHY Power-Down Register
namespace PWD_SET {
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::PWD_SET), 11, 21> RSVD2;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD_SET,  1, 20, 0x0> RXPWDRX;           // 0 = Normal operation
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD_SET,  1, 19, 0x0> RXPWDDIFF;         // 0 = Normal operation
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD_SET,  1, 18, 0x0> RXPWD1PT1;         // 0 = Normal operation
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD_SET,  1, 17, 0x0> RXPWDENV;          // 0 = Normal operation
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::PWD_SET),  4, 13> RSVD1;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD_SET,  1, 12, 0x0> TXPWDV2I;          // 0 = Normal operation
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD_SET,  1, 11, 0x0> TXPWDIBIAS;        // 0 = Normal operation
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD_SET,  1, 10, 0x0> TXPWDFS;           // 0 = Normal operation
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::PWD_SET), 10,  0> RSVD0;  // Reserved.
}  // namespace PWD_SET

// USB PHY Power-Down Register
namespace PWD_CLR {
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::PWD_CLR), 11, 21> RSVD2;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD_CLR,  1, 20, 0x0> RXPWDRX;           // 0 = Normal operation
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD_CLR,  1, 19, 0x0> RXPWDDIFF;         // 0 = Normal operation
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD_CLR,  1, 18, 0x0> RXPWD1PT1;         // 0 = Normal operation
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD_CLR,  1, 17, 0x0> RXPWDENV;          // 0 = Normal operation
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::PWD_CLR),  4, 13> RSVD1;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD_CLR,  1, 12, 0x0> TXPWDV2I;          // 0 = Normal operation
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD_CLR,  1, 11, 0x0> TXPWDIBIAS;        // 0 = Normal operation
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD_CLR,  1, 10, 0x0> TXPWDFS;           // 0 = Normal operation
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::PWD_CLR), 10,  0> RSVD0;  // Reserved.
}  // namespace PWD_CLR

// USB PHY Power-Down Register
namespace PWD_TOG {
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::PWD_TOG), 11, 21> RSVD2;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD_TOG,  1, 20, 0x0> RXPWDRX;           // 0 = Normal operation
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD_TOG,  1, 19, 0x0> RXPWDDIFF;         // 0 = Normal operation
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD_TOG,  1, 18, 0x0> RXPWD1PT1;         // 0 = Normal operation
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD_TOG,  1, 17, 0x0> RXPWDENV;          // 0 = Normal operation
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::PWD_TOG),  4, 13> RSVD1;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD_TOG,  1, 12, 0x0> TXPWDV2I;          // 0 = Normal operation
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD_TOG,  1, 11, 0x0> TXPWDIBIAS;        // 0 = Normal operation
constexpr USBPHY1_Reg<&USBPHY_Layout::PWD_TOG,  1, 10, 0x0> TXPWDFS;           // 0 = Normal operation
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::PWD_TOG), 10,  0> RSVD0;  // Reserved.
}  // namespace PWD_TOG

// USB PHY Transmitter Control Register
namespace TX {
constexpr uint32_t kWOZ =
    regs::shiftedMask32<4, 12>() | regs::shiftedMask32<4, 4>();

constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::TX), 3, 29> RSVD5;                                    // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::TX, 3, 26, regs::shiftedMask32<3, 26>() | kWOZ> USBPHY_TX_EDGECTRL;  // Controls the edge-rate of the current sensing transistors used in HS transmit
    // NOT FOR CUSTOMER USE.
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::TX), 6, 20> RSVD2;                                    // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::TX, 4, 16, regs::shiftedMask32<4, 16>() | kWOZ> TXCAL45DP;           // Decode to select a 45-Ohm resistance to the USB_DP output pin
constexpr USBPHY1_Reg<&USBPHY_Layout::TX, 4, 12, regs::shiftedMask32<4, 12>() | kWOZ> RSVD1;               // Reserved.
    // Note: This bit should remain clear.
constexpr USBPHY1_Reg<&USBPHY_Layout::TX, 4,  8, regs::shiftedMask32<4,  8>() | kWOZ> TXCAL45DN;           // Decode to select a 45-Ohm resistance to the USB_DN output pin
constexpr USBPHY1_Reg<&USBPHY_Layout::TX, 4,  4, regs::shiftedMask32<4,  4>() | kWOZ> RSVD0;               // Reserved.
    // Note: This bit should remain clear.
constexpr USBPHY1_Reg<&USBPHY_Layout::TX, 4,  0, regs::shiftedMask32<4,  0>() | kWOZ> D_CAL;               // Resistor Trimming Code: 0000 = 0.16% 0111 = Nominal 1111 = +25%
}  // namespace TX

// USB PHY Transmitter Control Register
namespace TX_SET {
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::TX_SET), 3, 29> RSVD5;    // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::TX_SET, 3, 26, 0x0> USBPHY_TX_EDGECTRL;  // Controls the edge-rate of the current sensing transistors used in HS transmit
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::TX_SET), 6, 20> RSVD2;    // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::TX_SET, 4, 16, 0x0> TXCAL45DP;           // Decode to select a 45-Ohm resistance to the USB_DP output pin
constexpr USBPHY1_Reg<&USBPHY_Layout::TX_SET, 4, 12, 0x0> RSVD1;               // Reserved.
    // Note: This bit should remain clear.
constexpr USBPHY1_Reg<&USBPHY_Layout::TX_SET, 4,  8, 0x0> TXCAL45DN;           // Decode to select a 45-Ohm resistance to the USB_DN output pin
constexpr USBPHY1_Reg<&USBPHY_Layout::TX_SET, 4,  4, 0x0> RSVD0;               // Reserved.
    // Note: This bit should remain clear.
constexpr USBPHY1_Reg<&USBPHY_Layout::TX_SET, 4,  0, 0x0> D_CAL;               // Resistor Trimming Code: 0000 = 0.16% 0111 = Nominal 1111 = +25%
}  // namespace TX_SET

// USB PHY Transmitter Control Register
namespace TX_CLR {
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::TX_CLR), 3, 29> RSVD5;    // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::TX_CLR, 3, 26, 0x0> USBPHY_TX_EDGECTRL;  // Controls the edge-rate of the current sensing transistors used in HS transmit
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::TX_CLR), 6, 20> RSVD2;    // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::TX_CLR, 4, 16, 0x0> TXCAL45DP;           // Decode to select a 45-Ohm resistance to the USB_DP output pin
constexpr USBPHY1_Reg<&USBPHY_Layout::TX_CLR, 4, 12, 0x0> RSVD1;               // Reserved.
    // Note: This bit should remain clear.
constexpr USBPHY1_Reg<&USBPHY_Layout::TX_CLR, 4,  8, 0x0> TXCAL45DN;           // Decode to select a 45-Ohm resistance to the USB_DN output pin
constexpr USBPHY1_Reg<&USBPHY_Layout::TX_CLR, 4,  4, 0x0> RSVD0;               // Reserved.
    // Note: This bit should remain clear.
constexpr USBPHY1_Reg<&USBPHY_Layout::TX_CLR, 4,  0, 0x0> D_CAL;               // Resistor Trimming Code: 0000 = 0.16% 0111 = Nominal 1111 = +25%
}  // namespace TX_CLR

// USB PHY Transmitter Control Register
namespace TX_TOG {
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::TX_TOG), 3, 29> RSVD5;    // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::TX_TOG, 3, 26, 0x0> USBPHY_TX_EDGECTRL;  // Controls the edge-rate of the current sensing transistors used in HS transmit
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::TX_TOG), 6, 20> RSVD2;    // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::TX_TOG, 4, 16, 0x0> TXCAL45DP;           // Decode to select a 45-Ohm resistance to the USB_DP output pin
constexpr USBPHY1_Reg<&USBPHY_Layout::TX_TOG, 4, 12, 0x0> RSVD1;               // Reserved.
    // Note: This bit should remain clear.
constexpr USBPHY1_Reg<&USBPHY_Layout::TX_TOG, 4,  8, 0x0> TXCAL45DN;           // Decode to select a 45-Ohm resistance to the USB_DN output pin
constexpr USBPHY1_Reg<&USBPHY_Layout::TX_TOG, 4,  4, 0x0> RSVD0;               // Reserved.
    // Note: This bit should remain clear.
constexpr USBPHY1_Reg<&USBPHY_Layout::TX_TOG, 4,  0, 0x0> D_CAL;               // Resistor Trimming Code: 0000 = 0.16% 0111 = Nominal 1111 = +25%
}  // namespace TX_TOG

// USB PHY Receiver Control Register
namespace RX {
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::RX),  9, 23> RSVD2;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::RX,  1, 22> RXDBYPASS;              // 0 = Normal operation
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::RX), 15,  7> RSVD1;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::RX,  3,  4> DISCONADJ;              // The DISCONADJ field adjusts the trip point for the disconnect detector: 000 = Trip-Level Voltage is 0
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::RX),  1,  3> RSVD0;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::RX,  3,  0> ENVADJ;                 // The ENVADJ field adjusts the trip point for the envelope detector
}  // namespace RX

// USB PHY Receiver Control Register
namespace RX_SET {
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::RX_SET),  9, 23> RSVD2;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::RX_SET,  1, 22, 0x0> RXDBYPASS;         // 0 = Normal operation
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::RX_SET), 15,  7> RSVD1;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::RX_SET,  3,  4, 0x0> DISCONADJ;         // The DISCONADJ field adjusts the trip point for the disconnect detector: 000 = Trip-Level Voltage is 0
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::RX_SET),  1,  3> RSVD0;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::RX_SET,  3,  0, 0x0> ENVADJ;            // The ENVADJ field adjusts the trip point for the envelope detector
}  // namespace RX_SET

// USB PHY Receiver Control Register
namespace RX_CLR {
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::RX_CLR),  9, 23> RSVD2;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::RX_CLR,  1, 22, 0x0> RXDBYPASS;         // 0 = Normal operation
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::RX_CLR), 15,  7> RSVD1;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::RX_CLR,  3,  4, 0x0> DISCONADJ;         // The DISCONADJ field adjusts the trip point for the disconnect detector: 000 = Trip-Level Voltage is 0
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::RX_CLR),  1,  3> RSVD0;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::RX_CLR,  3,  0, 0x0> ENVADJ;            // The ENVADJ field adjusts the trip point for the envelope detector
}  // namespace RX_CLR

// USB PHY Receiver Control Register
namespace RX_TOG {
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::RX_TOG),  9, 23> RSVD2;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::RX_TOG,  1, 22, 0x0> RXDBYPASS;         // 0 = Normal operation
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::RX_TOG), 15,  7> RSVD1;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::RX_TOG,  3,  4, 0x0> DISCONADJ;         // The DISCONADJ field adjusts the trip point for the disconnect detector: 000 = Trip-Level Voltage is 0
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::RX_TOG),  1,  3> RSVD0;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::RX_TOG,  3,  0, 0x0> ENVADJ;            // The ENVADJ field adjusts the trip point for the envelope detector
}  // namespace RX_TOG

// USB PHY General Control Register
namespace CTRL {
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1, 31> SFTRST;                         // Writing a 1 to this bit will soft-reset the USBPHYx_PWD, USBPHYx_TX, USBPHYx_RX, and USBPHYx_CTRL registers
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1, 30> CLKGATE;                        // Gate UTMI Clocks
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::CTRL), 1, 29> UTMI_SUSPENDM;  // Used by the PHY to indicate a powered-down state
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1, 28> HOST_FORCE_LS_SE0;              // Forces the next FS packet that is transmitted to have a EOP with LS timing
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::CTRL), 1, 27> OTG_ID_VALUE;   // Almost same as OTGID_STATUS in USBPHYx_STATUS Register
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::CTRL), 2, 25> RSVD1;          // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1, 24> FSDLL_RST_EN;                   // Enables the feature to reset the FSDLL lock detection logic at the end of each TX packet.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1, 23> ENVBUSCHG_WKUP;                 // Enables the feature to wakeup USB if VBUS is toggled when USB is suspended.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1, 22> ENIDCHG_WKUP;                   // Enables the feature to wakeup USB if ID is toggled when USB is suspended.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1, 21> ENDPDMCHG_WKUP;                 // Enables the feature to wakeup USB if DP/DM is toggled when USB is suspended
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1, 20> ENAUTOCLR_PHY_PWD;              // Enables the feature to auto-clear the PWD register bits in USBPHYx_PWD if there is wakeup event while USB is suspended
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1, 19> ENAUTOCLR_CLKGATE;              // Enables the feature to auto-clear the CLKGATE bit if there is wakeup event while USB is suspended
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1, 18> ENAUTO_PWRON_PLL;               // Enables the feature to auto-enable the POWER bit of HW_CLKCTRL_PLLxCTRL0 if there is wakeup event if USB is suspended
// constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1, 17> WAKEUP_IRQ;                     // Indicates that there is a wakeup event
    // Reset only by writing a 1 to the clear address space
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1, 16> ENIRQWAKEUP;                    // Enables interrupt for the wakeup events.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1, 15> ENUTMILEVEL3;                   // Enables UTMI+ Level3
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1, 14> ENUTMILEVEL2;                   // Enables UTMI+ Level2. This should be enabled if needs to support LS device
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1, 13> DATA_ON_LRADC;                  // Enables the LRADC to monitor USB_DP and USB_DM. This is for use in non-USB modes only.
// constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1, 12> DEVPLUGIN_IRQ;                  // Indicates that the device is connected
    // Reset only by writing a 1 to the clear address space
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1, 11> ENIRQDEVPLUGIN;                 // Enables interrupt for the detection of connectivity to the USB line.
// constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1, 10> RESUME_IRQ;                     // Indicates that the host is sending a wake-up after suspend
    // Reset only by writing a 1 to the clear address space
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1,  9> ENIRQRESUMEDETECT;              // Enables interrupt for detection of a non-J state on the USB line
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1,  8> RESUMEIRQSTICKY;                // Set to 1 will make RESUME_IRQ bit a sticky bit until software clear it
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1,  7> ENOTGIDDETECT;                  // Enables circuit to detect resistance of MiniAB ID pin.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1,  6> OTG_ID_CHG_IRQ;                 // OTG ID change interrupt. Indicates the value of ID pin changed.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1,  5> DEVPLUGIN_POLARITY;             // For device mode, if this bit is cleared to 0, then it trips the interrupt if the device is plugged in
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1,  4> ENDEVPLUGINDETECT;              // For device mode, enables 200-KOhm pullups for detecting connectivity to the host.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1,  3> HOSTDISCONDETECT_IRQ;           // Indicates that the device has disconnected in high-speed mode
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1,  2> ENIRQHOSTDISCON;                // Enables interrupt for detection of disconnection to Device when in high-speed host mode
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1,  1> ENHOSTDISCONDETECT;             // For host mode, enables high-speed disconnect detector
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL, 1,  0> ENOTG_ID_CHG_IRQ;               // Enable OTG_ID_CHG_IRQ.
}  // namespace CTRL

// USB PHY General Control Register
namespace CTRL_SET {
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1, 31, 0x0> SFTRST;                    // Writing a 1 to this bit will soft-reset the USBPHYx_PWD, USBPHYx_TX, USBPHYx_RX, and USBPHYx_CTRL registers
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1, 30, 0x0> CLKGATE;                   // Gate UTMI Clocks
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::CTRL_SET), 1, 29> UTMI_SUSPENDM;  // Used by the PHY to indicate a powered-down state
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1, 28, 0x0> HOST_FORCE_LS_SE0;         // Forces the next FS packet that is transmitted to have a EOP with LS timing
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::CTRL_SET), 1, 27> OTG_ID_VALUE;   // Almost same as OTGID_STATUS in USBPHYx_STATUS Register
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::CTRL_SET), 2, 25> RSVD1;          // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1, 24, 0x0> FSDLL_RST_EN;              // Enables the feature to reset the FSDLL lock detection logic at the end of each TX packet.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1, 23, 0x0> ENVBUSCHG_WKUP;            // Enables the feature to wakeup USB if VBUS is toggled when USB is suspended.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1, 22, 0x0> ENIDCHG_WKUP;              // Enables the feature to wakeup USB if ID is toggled when USB is suspended.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1, 21, 0x0> ENDPDMCHG_WKUP;            // Enables the feature to wakeup USB if DP/DM is toggled when USB is suspended
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1, 20, 0x0> ENAUTOCLR_PHY_PWD;         // Enables the feature to auto-clear the PWD register bits in USBPHYx_PWD if there is wakeup event while USB is suspended
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1, 19, 0x0> ENAUTOCLR_CLKGATE;         // Enables the feature to auto-clear the CLKGATE bit if there is wakeup event while USB is suspended
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1, 18, 0x0> ENAUTO_PWRON_PLL;          // Enables the feature to auto-enable the POWER bit of HW_CLKCTRL_PLLxCTRL0 if there is wakeup event if USB is suspended
// constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1, 17, 0x0> WAKEUP_IRQ;                // Indicates that there is a wakeup event
    // Reset only by writing a 1 to the clear address space
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1, 16, 0x0> ENIRQWAKEUP;               // Enables interrupt for the wakeup events.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1, 15, 0x0> ENUTMILEVEL3;              // Enables UTMI+ Level3
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1, 14, 0x0> ENUTMILEVEL2;              // Enables UTMI+ Level2. This should be enabled if needs to support LS device
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1, 13, 0x0> DATA_ON_LRADC;             // Enables the LRADC to monitor USB_DP and USB_DM. This is for use in non-USB modes only.
// constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1, 12, 0x0> DEVPLUGIN_IRQ;             // Indicates that the device is connected
    // Reset only by writing a 1 to the clear address space
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1, 11, 0x0> ENIRQDEVPLUGIN;            // Enables interrupt for the detection of connectivity to the USB line.
// constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1, 10, 0x0> RESUME_IRQ;                // Indicates that the host is sending a wake-up after suspend
    // Reset only by writing a 1 to the clear address space
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1,  9, 0x0> ENIRQRESUMEDETECT;         // Enables interrupt for detection of a non-J state on the USB line
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1,  8, 0x0> RESUMEIRQSTICKY;           // Set to 1 will make RESUME_IRQ bit a sticky bit until software clear it
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1,  7, 0x0> ENOTGIDDETECT;             // Enables circuit to detect resistance of MiniAB ID pin.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1,  6, 0x0> OTG_ID_CHG_IRQ;            // OTG ID change interrupt. Indicates the value of ID pin changed.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1,  5, 0x0> DEVPLUGIN_POLARITY;        // For device mode, if this bit is cleared to 0, then it trips the interrupt if the device is plugged in
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1,  4, 0x0> ENDEVPLUGINDETECT;         // For device mode, enables 200-KOhm pullups for detecting connectivity to the host.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1,  3, 0x0> HOSTDISCONDETECT_IRQ;      // Indicates that the device has disconnected in high-speed mode
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1,  2, 0x0> ENIRQHOSTDISCON;           // Enables interrupt for detection of disconnection to Device when in high-speed host mode
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1,  1, 0x0> ENHOSTDISCONDETECT;        // For host mode, enables high-speed disconnect detector
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_SET, 1,  0, 0x0> ENOTG_ID_CHG_IRQ;          // Enable OTG_ID_CHG_IRQ.
}  // namespace CTRL_SET

// USB PHY General Control Register
namespace CTRL_CLR {
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1, 31, 0x0> SFTRST;                    // Writing a 1 to this bit will soft-reset the USBPHYx_PWD, USBPHYx_TX, USBPHYx_RX, and USBPHYx_CTRL registers
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1, 30, 0x0> CLKGATE;                   // Gate UTMI Clocks
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::CTRL_CLR), 1, 29> UTMI_SUSPENDM;  // Used by the PHY to indicate a powered-down state
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1, 28, 0x0> HOST_FORCE_LS_SE0;         // Forces the next FS packet that is transmitted to have a EOP with LS timing
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::CTRL_CLR), 1, 27> OTG_ID_VALUE;   // Almost same as OTGID_STATUS in USBPHYx_STATUS Register
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::CTRL_CLR), 2, 25> RSVD1;          // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1, 24, 0x0> FSDLL_RST_EN;              // Enables the feature to reset the FSDLL lock detection logic at the end of each TX packet.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1, 23, 0x0> ENVBUSCHG_WKUP;            // Enables the feature to wakeup USB if VBUS is toggled when USB is suspended.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1, 22, 0x0> ENIDCHG_WKUP;              // Enables the feature to wakeup USB if ID is toggled when USB is suspended.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1, 21, 0x0> ENDPDMCHG_WKUP;            // Enables the feature to wakeup USB if DP/DM is toggled when USB is suspended
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1, 20, 0x0> ENAUTOCLR_PHY_PWD;         // Enables the feature to auto-clear the PWD register bits in USBPHYx_PWD if there is wakeup event while USB is suspended
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1, 19, 0x0> ENAUTOCLR_CLKGATE;         // Enables the feature to auto-clear the CLKGATE bit if there is wakeup event while USB is suspended
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1, 18, 0x0> ENAUTO_PWRON_PLL;          // Enables the feature to auto-enable the POWER bit of HW_CLKCTRL_PLLxCTRL0 if there is wakeup event if USB is suspended
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1, 17, 0x0> WAKEUP_IRQ;                // Indicates that there is a wakeup event
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1, 16, 0x0> ENIRQWAKEUP;               // Enables interrupt for the wakeup events.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1, 15, 0x0> ENUTMILEVEL3;              // Enables UTMI+ Level3
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1, 14, 0x0> ENUTMILEVEL2;              // Enables UTMI+ Level2. This should be enabled if needs to support LS device
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1, 13, 0x0> DATA_ON_LRADC;             // Enables the LRADC to monitor USB_DP and USB_DM. This is for use in non-USB modes only.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1, 12, 0x0> DEVPLUGIN_IRQ;             // Indicates that the device is connected
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1, 11, 0x0> ENIRQDEVPLUGIN;            // Enables interrupt for the detection of connectivity to the USB line.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1, 10, 0x0> RESUME_IRQ;                // Indicates that the host is sending a wake-up after suspend
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1,  9, 0x0> ENIRQRESUMEDETECT;         // Enables interrupt for detection of a non-J state on the USB line
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1,  8, 0x0> RESUMEIRQSTICKY;           // Set to 1 will make RESUME_IRQ bit a sticky bit until software clear it
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1,  7, 0x0> ENOTGIDDETECT;             // Enables circuit to detect resistance of MiniAB ID pin.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1,  6, 0x0> OTG_ID_CHG_IRQ;            // OTG ID change interrupt. Indicates the value of ID pin changed.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1,  5, 0x0> DEVPLUGIN_POLARITY;        // For device mode, if this bit is cleared to 0, then it trips the interrupt if the device is plugged in
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1,  4, 0x0> ENDEVPLUGINDETECT;         // For device mode, enables 200-KOhm pullups for detecting connectivity to the host.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1,  3, 0x0> HOSTDISCONDETECT_IRQ;      // Indicates that the device has disconnected in high-speed mode
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1,  2, 0x0> ENIRQHOSTDISCON;           // Enables interrupt for detection of disconnection to Device when in high-speed host mode
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1,  1, 0x0> ENHOSTDISCONDETECT;        // For host mode, enables high-speed disconnect detector
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_CLR, 1,  0, 0x0> ENOTG_ID_CHG_IRQ;          // Enable OTG_ID_CHG_IRQ.
}  // namespace CTRL_CLR

// USB PHY General Control Register
namespace CTRL_TOG {
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1, 31, 0x0> SFTRST;                    // Writing a 1 to this bit will soft-reset the USBPHYx_PWD, USBPHYx_TX, USBPHYx_RX, and USBPHYx_CTRL registers
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1, 30, 0x0> CLKGATE;                   // Gate UTMI Clocks
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::CTRL_TOG), 1, 29> UTMI_SUSPENDM;  // Used by the PHY to indicate a powered-down state
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1, 28, 0x0> HOST_FORCE_LS_SE0;         // Forces the next FS packet that is transmitted to have a EOP with LS timing
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::CTRL_TOG), 1, 27> OTG_ID_VALUE;   // Almost same as OTGID_STATUS in USBPHYx_STATUS Register
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::CTRL_TOG), 2, 25> RSVD1;          // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1, 24, 0x0> FSDLL_RST_EN;              // Enables the feature to reset the FSDLL lock detection logic at the end of each TX packet.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1, 23, 0x0> ENVBUSCHG_WKUP;            // Enables the feature to wakeup USB if VBUS is toggled when USB is suspended.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1, 22, 0x0> ENIDCHG_WKUP;              // Enables the feature to wakeup USB if ID is toggled when USB is suspended.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1, 21, 0x0> ENDPDMCHG_WKUP;            // Enables the feature to wakeup USB if DP/DM is toggled when USB is suspended
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1, 20, 0x0> ENAUTOCLR_PHY_PWD;         // Enables the feature to auto-clear the PWD register bits in USBPHYx_PWD if there is wakeup event while USB is suspended
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1, 19, 0x0> ENAUTOCLR_CLKGATE;         // Enables the feature to auto-clear the CLKGATE bit if there is wakeup event while USB is suspended
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1, 18, 0x0> ENAUTO_PWRON_PLL;          // Enables the feature to auto-enable the POWER bit of HW_CLKCTRL_PLLxCTRL0 if there is wakeup event if USB is suspended
// constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1, 17, 0x0> WAKEUP_IRQ;                // Indicates that there is a wakeup event
    // Reset only by writing a 1 to the clear address space
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1, 16, 0x0> ENIRQWAKEUP;               // Enables interrupt for the wakeup events.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1, 15, 0x0> ENUTMILEVEL3;              // Enables UTMI+ Level3
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1, 14, 0x0> ENUTMILEVEL2;              // Enables UTMI+ Level2. This should be enabled if needs to support LS device
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1, 13, 0x0> DATA_ON_LRADC;             // Enables the LRADC to monitor USB_DP and USB_DM. This is for use in non-USB modes only.
// constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1, 12, 0x0> DEVPLUGIN_IRQ;             // Indicates that the device is connected
    // Reset only by writing a 1 to the clear address space
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1, 11, 0x0> ENIRQDEVPLUGIN;            // Enables interrupt for the detection of connectivity to the USB line.
// constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1, 10, 0x0> RESUME_IRQ;                // Indicates that the host is sending a wake-up after suspend
    // Reset only by writing a 1 to the clear address space
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1,  9, 0x0> ENIRQRESUMEDETECT;         // Enables interrupt for detection of a non-J state on the USB line
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1,  8, 0x0> RESUMEIRQSTICKY;           // Set to 1 will make RESUME_IRQ bit a sticky bit until software clear it
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1,  7, 0x0> ENOTGIDDETECT;             // Enables circuit to detect resistance of MiniAB ID pin.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1,  6, 0x0> OTG_ID_CHG_IRQ;            // OTG ID change interrupt. Indicates the value of ID pin changed.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1,  5, 0x0> DEVPLUGIN_POLARITY;        // For device mode, if this bit is cleared to 0, then it trips the interrupt if the device is plugged in
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1,  4, 0x0> ENDEVPLUGINDETECT;         // For device mode, enables 200-KOhm pullups for detecting connectivity to the host.
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1,  3, 0x0> HOSTDISCONDETECT_IRQ;      // Indicates that the device has disconnected in high-speed mode
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1,  2, 0x0> ENIRQHOSTDISCON;           // Enables interrupt for detection of disconnection to Device when in high-speed host mode
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1,  1, 0x0> ENHOSTDISCONDETECT;        // For host mode, enables high-speed disconnect detector
constexpr USBPHY1_Reg<&USBPHY_Layout::CTRL_TOG, 1,  0, 0x0> ENOTG_ID_CHG_IRQ;          // Enable OTG_ID_CHG_IRQ.
}  // namespace CTRL_TOG

// USB PHY Status Register
namespace STATUS {
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::STATUS), 21, 11> RSVD4;                    // Reserved.
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::STATUS),  1, 10> RESUME_STATUS;            // Indicates that the host is sending a wake-up after suspend and has triggered an interrupt.
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::STATUS),  1,  9> RSVD3;                    // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::STATUS,  1,  8> OTGID_STATUS;                             // Indicates the results of ID pin on MiniAB plug
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::STATUS),  1,  7> RSVD2;                    // Reserved.
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::STATUS),  1,  6> DEVPLUGIN_STATUS;         // Indicates that the device has been connected on the USB_DP and USB_DM lines.
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::STATUS),  2,  4> RSVD1;                    // Reserved.
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::STATUS),  1,  3> HOSTDISCONDETECT_STATUS;  // Indicates that the device has disconnected while in high-speed host mode.
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::STATUS),  3,  0> RSVD0;                    // Reserved.
}  // namespace STATUS

// USB PHY Debug Register
namespace DEBUG {
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::DEBUG), 1, 31> RSVD3;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG, 1, 30> CLKGATE;                // Gate Test Clocks
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG, 1, 29> HOST_RESUME_DEBUG;      // Choose to trigger the host resume SE0 with HOST_FORCE_LS_SE0 = 0 or UTMI_SUSPEND = 1.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG, 4, 25> SQUELCHRESETLENGTH;     // Duration of RESET in terms of the number of 480-MHz cycles.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG, 1, 24> ENSQUELCHRESET;         // Set bit to allow squelch to reset high-speed receive.
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::DEBUG), 3, 21> RSVD2;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG, 5, 16> SQUELCHRESETCOUNT;      // Delay in between the detection of squelch to the reset of high-speed RX.
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::DEBUG), 3, 13> RSVD1;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG, 1, 12> ENTX2RXCOUNT;           // Set this bit to allow a countdown to transition in between TX and RX.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG, 4,  8> TX2RXCOUNT;             // Delay in between the end of transmit to the beginning of receive
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::DEBUG), 2,  6> RSVD0;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG, 2,  4> ENHSTPULLDOWN;          // Set bit 5 to 1 to override the control of the USB_DP 15-KOhm pulldown
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG, 2,  2> HSTPULLDOWN;            // Set bit 3 to 1 to pull down 15-KOhm on USB_DP line
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG, 1,  1> DEBUG_INTERFACE_HOLD;   // Use holding registers to assist in timing for external UTMI interface.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG, 1,  0> OTGIDPIOLOCK;           // Once OTG ID from USBPHYx_STATUS_OTGID_STATUS, use this to hold the value
}  // namespace DEBUG

// USB PHY Debug Register
namespace DEBUG_SET {
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::DEBUG_SET), 1, 31> RSVD3;      // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_SET, 1, 30, 0x0> CLKGATE;               // Gate Test Clocks
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_SET, 1, 29, 0x0> HOST_RESUME_DEBUG;     // Choose to trigger the host resume SE0 with HOST_FORCE_LS_SE0 = 0 or UTMI_SUSPEND = 1.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_SET, 4, 25, 0x0> SQUELCHRESETLENGTH;    // Duration of RESET in terms of the number of 480-MHz cycles.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_SET, 1, 24, 0x0> ENSQUELCHRESET;        // Set bit to allow squelch to reset high-speed receive.
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::DEBUG_SET), 3, 21> RSVD2;      // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_SET, 5, 16, 0x0> SQUELCHRESETCOUNT;     // Delay in between the detection of squelch to the reset of high-speed RX.
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::DEBUG_SET), 3, 13> RSVD1;      // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_SET, 1, 12, 0x0> ENTX2RXCOUNT;          // Set this bit to allow a countdown to transition in between TX and RX.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_SET, 4,  8, 0x0> TX2RXCOUNT;            // Delay in between the end of transmit to the beginning of receive
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::DEBUG_SET), 2,  6> RSVD0;      // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_SET, 2,  4, 0x0> ENHSTPULLDOWN;         // Set bit 5 to 1 to override the control of the USB_DP 15-KOhm pulldown
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_SET, 2,  2, 0x0> HSTPULLDOWN;           // Set bit 3 to 1 to pull down 15-KOhm on USB_DP line
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_SET, 1,  1, 0x0> DEBUG_INTERFACE_HOLD;  // Use holding registers to assist in timing for external UTMI interface.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_SET, 1,  0, 0x0> OTGIDPIOLOCK;          // Once OTG ID from USBPHYx_STATUS_OTGID_STATUS, use this to hold the value
}  // namespace DEBUG_SET

// USB PHY Debug Register
namespace DEBUG_CLR {
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::DEBUG_CLR), 1, 31> RSVD3;      // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_CLR, 1, 30, 0x0> CLKGATE;               // Gate Test Clocks
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_CLR, 1, 29, 0x0> HOST_RESUME_DEBUG;     // Choose to trigger the host resume SE0 with HOST_FORCE_LS_SE0 = 0 or UTMI_SUSPEND = 1.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_CLR, 4, 25, 0x0> SQUELCHRESETLENGTH;    // Duration of RESET in terms of the number of 480-MHz cycles.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_CLR, 1, 24, 0x0> ENSQUELCHRESET;        // Set bit to allow squelch to reset high-speed receive.
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::DEBUG_CLR), 3, 21> RSVD2;      // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_CLR, 5, 16, 0x0> SQUELCHRESETCOUNT;     // Delay in between the detection of squelch to the reset of high-speed RX.
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::DEBUG_CLR), 3, 13> RSVD1;      // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_CLR, 1, 12, 0x0> ENTX2RXCOUNT;          // Set this bit to allow a countdown to transition in between TX and RX.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_CLR, 4,  8, 0x0> TX2RXCOUNT;            // Delay in between the end of transmit to the beginning of receive
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::DEBUG_CLR), 2,  6> RSVD0;      // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_CLR, 2,  4, 0x0> ENHSTPULLDOWN;         // Set bit 5 to 1 to override the control of the USB_DP 15-KOhm pulldown
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_CLR, 2,  2, 0x0> HSTPULLDOWN;           // Set bit 3 to 1 to pull down 15-KOhm on USB_DP line
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_CLR, 1,  1, 0x0> DEBUG_INTERFACE_HOLD;  // Use holding registers to assist in timing for external UTMI interface.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_CLR, 1,  0, 0x0> OTGIDPIOLOCK;          // Once OTG ID from USBPHYx_STATUS_OTGID_STATUS, use this to hold the value
}  // namespace DEBUG_CLR

// USB PHY Debug Register
namespace DEBUG_TOG {
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::DEBUG_TOG), 1, 31> RSVD3;      // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_TOG, 1, 30, 0x0> CLKGATE;               // Gate Test Clocks
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_TOG, 1, 29, 0x0> HOST_RESUME_DEBUG;     // Choose to trigger the host resume SE0 with HOST_FORCE_LS_SE0 = 0 or UTMI_SUSPEND = 1.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_TOG, 4, 25, 0x0> SQUELCHRESETLENGTH;    // Duration of RESET in terms of the number of 480-MHz cycles.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_TOG, 1, 24, 0x0> ENSQUELCHRESET;        // Set bit to allow squelch to reset high-speed receive.
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::DEBUG_TOG), 3, 21> RSVD2;      // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_TOG, 5, 16, 0x0> SQUELCHRESETCOUNT;     // Delay in between the detection of squelch to the reset of high-speed RX.
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::DEBUG_TOG), 3, 13> RSVD1;      // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_TOG, 1, 12, 0x0> ENTX2RXCOUNT;          // Set this bit to allow a countdown to transition in between TX and RX.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_TOG, 4,  8, 0x0> TX2RXCOUNT;            // Delay in between the end of transmit to the beginning of receive
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::DEBUG_TOG), 2,  6> RSVD0;      // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_TOG, 2,  4, 0x0> ENHSTPULLDOWN;         // Set bit 5 to 1 to override the control of the USB_DP 15-KOhm pulldown
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_TOG, 2,  2, 0x0> HSTPULLDOWN;           // Set bit 3 to 1 to pull down 15-KOhm on USB_DP line
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_TOG, 1,  1, 0x0> DEBUG_INTERFACE_HOLD;  // Use holding registers to assist in timing for external UTMI interface.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG_TOG, 1,  0, 0x0> OTGIDPIOLOCK;          // Once OTG ID from USBPHYx_STATUS_OTGID_STATUS, use this to hold the value
}  // namespace DEBUG_TOG

// UTMI Debug Status Register 0
namespace DEBUG0_STATUS {
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG0_STATUS,  6, 26> SQUELCH_COUNT;            // Running count of the squelch reset instead of normal end for HS RX.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG0_STATUS, 10, 16> UTMI_RXERROR_FAIL_COUNT;  // Running count of the UTMI_RXERROR.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG0_STATUS, 16,  0> LOOP_BACK_FAIL_COUNT;     // Running count of the failed pseudo-random generator loopback
}  // namespace DEBUG0_STATUS

// UTMI Debug Status Register 1
namespace DEBUG1 {
constexpr uint32_t kWOZ = regs::shiftedMask32<13, 0>();

constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::DEBUG1), 17, 15> RSVD1;                             // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG1,  2, 13, regs::shiftedMask32<2, 13>() | kWOZ> ENTAILADJVD;  // Delay increment of the rise of squelch: 00 = Delay is nominal 01 = Delay is +20% 10 = Delay is -20% 11 = Delay is -40%
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG1, 13,  0> RSVD0;                                             // Reserved.
    // Note: This bit should remain clear.
}  // namespace DEBUG1

// UTMI Debug Status Register 1
namespace DEBUG1_SET {
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::DEBUG1_SET), 17, 15> RSVD1;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG1_SET,  2, 13, 0x0> ENTAILADJVD;       // Delay increment of the rise of squelch: 00 = Delay is nominal 01 = Delay is +20% 10 = Delay is -20% 11 = Delay is -40%
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG1_SET, 13,  0, 0x0> RSVD0;             // Reserved.
    // Note: This bit should remain clear.
}  // namespace DEBUG1_SET

// UTMI Debug Status Register 1
namespace DEBUG1_CLR {
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::DEBUG1_CLR), 17, 15> RSVD1;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG1_CLR,  2, 13, 0x0> ENTAILADJVD;       // Delay increment of the rise of squelch: 00 = Delay is nominal 01 = Delay is +20% 10 = Delay is -20% 11 = Delay is -40%
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG1_CLR, 13,  0, 0x0> RSVD0;             // Reserved.
    // Note: This bit should remain clear.
}  // namespace DEBUG1_CLR

// UTMI Debug Status Register 1
namespace DEBUG1_TOG {
constexpr USBPHY1_Reg<regs::constify(&USBPHY_Layout::DEBUG1_TOG), 17, 15> RSVD1;  // Reserved.
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG1_TOG,  2, 13, 0x0> ENTAILADJVD;       // Delay increment of the rise of squelch: 00 = Delay is nominal 01 = Delay is +20% 10 = Delay is -20% 11 = Delay is -40%
constexpr USBPHY1_Reg<&USBPHY_Layout::DEBUG1_TOG, 13,  0, 0x0> RSVD0;             // Reserved.
    // Note: This bit should remain clear.
}  // namespace DEBUG1_TOG

// UTMI RTL Version
namespace VERSION {
constexpr USBPHY1_Reg<&USBPHY_Layout::VERSION,  8, 24> MAJOR;  // Fixed read-only value reflecting the MAJOR field of the RTL version.
constexpr USBPHY1_Reg<&USBPHY_Layout::VERSION,  8, 16> MINOR;  // Fixed read-only value reflecting the MINOR field of the RTL version.
constexpr USBPHY1_Reg<&USBPHY_Layout::VERSION, 16,  0> STEP;   // Fixed read-only value reflecting the stepping of the RTL version.
}  // namespace VERSION

}  // namespace USBPHY1

namespace USBPHY2 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using USBPHY2_Reg =
    regs::Reg32<kUSBPHY2_base, USBPHY_Layout, Member, 0, Bits, Shift, AssignMask>;

// USB PHY Power-Down Register
namespace PWD {
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::PWD), 11, 21> RSVD2;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD,  1, 20> RXPWDRX;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD,  1, 19> RXPWDDIFF;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD,  1, 18> RXPWD1PT1;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD,  1, 17> RXPWDENV;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::PWD),  4, 13> RSVD1;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD,  1, 12> TXPWDV2I;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD,  1, 11> TXPWDIBIAS;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD,  1, 10> TXPWDFS;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::PWD), 10,  0> RSVD0;
}  // namespace PWD

// USB PHY Power-Down Register
namespace PWD_SET {
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::PWD_SET), 11, 21> RSVD2;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD_SET,  1, 20, 0x0> RXPWDRX;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD_SET,  1, 19, 0x0> RXPWDDIFF;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD_SET,  1, 18, 0x0> RXPWD1PT1;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD_SET,  1, 17, 0x0> RXPWDENV;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::PWD_SET),  4, 13> RSVD1;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD_SET,  1, 12, 0x0> TXPWDV2I;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD_SET,  1, 11, 0x0> TXPWDIBIAS;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD_SET,  1, 10, 0x0> TXPWDFS;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::PWD_SET), 10,  0> RSVD0;
}  // namespace PWD_SET

// USB PHY Power-Down Register
namespace PWD_CLR {
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::PWD_CLR), 11, 21> RSVD2;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD_CLR,  1, 20, 0x0> RXPWDRX;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD_CLR,  1, 19, 0x0> RXPWDDIFF;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD_CLR,  1, 18, 0x0> RXPWD1PT1;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD_CLR,  1, 17, 0x0> RXPWDENV;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::PWD_CLR),  4, 13> RSVD1;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD_CLR,  1, 12, 0x0> TXPWDV2I;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD_CLR,  1, 11, 0x0> TXPWDIBIAS;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD_CLR,  1, 10, 0x0> TXPWDFS;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::PWD_CLR), 10,  0> RSVD0;
}  // namespace PWD_CLR

// USB PHY Power-Down Register
namespace PWD_TOG {
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::PWD_TOG), 11, 21> RSVD2;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD_TOG,  1, 20, 0x0> RXPWDRX;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD_TOG,  1, 19, 0x0> RXPWDDIFF;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD_TOG,  1, 18, 0x0> RXPWD1PT1;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD_TOG,  1, 17, 0x0> RXPWDENV;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::PWD_TOG),  4, 13> RSVD1;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD_TOG,  1, 12, 0x0> TXPWDV2I;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD_TOG,  1, 11, 0x0> TXPWDIBIAS;
constexpr USBPHY2_Reg<&USBPHY_Layout::PWD_TOG,  1, 10, 0x0> TXPWDFS;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::PWD_TOG), 10,  0> RSVD0;
}  // namespace PWD_TOG

// USB PHY Transmitter Control Register
namespace TX {
constexpr uint32_t kWOZ =
    regs::shiftedMask32<4, 12>() | regs::shiftedMask32<4, 4>();

constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::TX), 3, 29> RSVD5;
constexpr USBPHY2_Reg<&USBPHY_Layout::TX, 3, 26, regs::shiftedMask32<3, 26>() | kWOZ> USBPHY_TX_EDGECTRL;
    // NOT FOR CUSTOMER USE.
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::TX), 6, 20> RSVD2;
constexpr USBPHY2_Reg<&USBPHY_Layout::TX, 4, 16, regs::shiftedMask32<4, 16>() | kWOZ> TXCAL45DP;
constexpr USBPHY2_Reg<&USBPHY_Layout::TX, 4, 12, regs::shiftedMask32<4, 12>() | kWOZ> RSVD1;
constexpr USBPHY2_Reg<&USBPHY_Layout::TX, 4,  8, regs::shiftedMask32<4,  8>() | kWOZ> TXCAL45DN;
constexpr USBPHY2_Reg<&USBPHY_Layout::TX, 4,  4, regs::shiftedMask32<4,  4>() | kWOZ> RSVD0;
constexpr USBPHY2_Reg<&USBPHY_Layout::TX, 4,  0, regs::shiftedMask32<4,  0>() | kWOZ> D_CAL;
}  // namespace TX

// USB PHY Transmitter Control Register
namespace TX_SET {
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::TX_SET), 3, 29> RSVD5;
constexpr USBPHY2_Reg<&USBPHY_Layout::TX_SET, 3, 26, 0x0> USBPHY_TX_EDGECTRL;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::TX_SET), 6, 20> RSVD2;
constexpr USBPHY2_Reg<&USBPHY_Layout::TX_SET, 4, 16, 0x0> TXCAL45DP;
constexpr USBPHY2_Reg<&USBPHY_Layout::TX_SET, 4, 12, 0x0> RSVD1;
constexpr USBPHY2_Reg<&USBPHY_Layout::TX_SET, 4,  8, 0x0> TXCAL45DN;
constexpr USBPHY2_Reg<&USBPHY_Layout::TX_SET, 4,  4, 0x0> RSVD0;
constexpr USBPHY2_Reg<&USBPHY_Layout::TX_SET, 4,  0, 0x0> D_CAL;
}  // namespace TX_SET

// USB PHY Transmitter Control Register
namespace TX_CLR {
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::TX_CLR), 3, 29> RSVD5;
constexpr USBPHY2_Reg<&USBPHY_Layout::TX_CLR, 3, 26, 0x0> USBPHY_TX_EDGECTRL;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::TX_CLR), 6, 20> RSVD2;
constexpr USBPHY2_Reg<&USBPHY_Layout::TX_CLR, 4, 16, 0x0> TXCAL45DP;
constexpr USBPHY2_Reg<&USBPHY_Layout::TX_CLR, 4, 12, 0x0> RSVD1;
constexpr USBPHY2_Reg<&USBPHY_Layout::TX_CLR, 4,  8, 0x0> TXCAL45DN;
constexpr USBPHY2_Reg<&USBPHY_Layout::TX_CLR, 4,  4, 0x0> RSVD0;
constexpr USBPHY2_Reg<&USBPHY_Layout::TX_CLR, 4,  0, 0x0> D_CAL;
}  // namespace TX_CLR

// USB PHY Transmitter Control Register
namespace TX_TOG {
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::TX_TOG), 3, 29> RSVD5;
constexpr USBPHY2_Reg<&USBPHY_Layout::TX_TOG, 3, 26, 0x0> USBPHY_TX_EDGECTRL;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::TX_TOG), 6, 20> RSVD2;
constexpr USBPHY2_Reg<&USBPHY_Layout::TX_TOG, 4, 16, 0x0> TXCAL45DP;
constexpr USBPHY2_Reg<&USBPHY_Layout::TX_TOG, 4, 12, 0x0> RSVD1;
constexpr USBPHY2_Reg<&USBPHY_Layout::TX_TOG, 4,  8, 0x0> TXCAL45DN;
constexpr USBPHY2_Reg<&USBPHY_Layout::TX_TOG, 4,  4, 0x0> RSVD0;
constexpr USBPHY2_Reg<&USBPHY_Layout::TX_TOG, 4,  0, 0x0> D_CAL;
}  // namespace TX_TOG

// USB PHY Receiver Control Register
namespace RX {
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::RX),  9, 23> RSVD2;
constexpr USBPHY2_Reg<&USBPHY_Layout::RX,  1, 22> RXDBYPASS;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::RX), 15,  7> RSVD1;
constexpr USBPHY2_Reg<&USBPHY_Layout::RX,  3,  4> DISCONADJ;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::RX),  1,  3> RSVD0;
constexpr USBPHY2_Reg<&USBPHY_Layout::RX,  3,  0> ENVADJ;
}  // namespace RX

// USB PHY Receiver Control Register
namespace RX_SET {
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::RX_SET),  9, 23> RSVD2;
constexpr USBPHY2_Reg<&USBPHY_Layout::RX_SET,  1, 22, 0x0> RXDBYPASS;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::RX_SET), 15,  7> RSVD1;
constexpr USBPHY2_Reg<&USBPHY_Layout::RX_SET,  3,  4, 0x0> DISCONADJ;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::RX_SET),  1,  3> RSVD0;
constexpr USBPHY2_Reg<&USBPHY_Layout::RX_SET,  3,  0, 0x0> ENVADJ;
}  // namespace RX_SET

// USB PHY Receiver Control Register
namespace RX_CLR {
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::RX_CLR),  9, 23> RSVD2;
constexpr USBPHY2_Reg<&USBPHY_Layout::RX_CLR,  1, 22, 0x0> RXDBYPASS;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::RX_CLR), 15,  7> RSVD1;
constexpr USBPHY2_Reg<&USBPHY_Layout::RX_CLR,  3,  4, 0x0> DISCONADJ;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::RX_CLR),  1,  3> RSVD0;
constexpr USBPHY2_Reg<&USBPHY_Layout::RX_CLR,  3,  0, 0x0> ENVADJ;
}  // namespace RX_CLR

// USB PHY Receiver Control Register
namespace RX_TOG {
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::RX_TOG),  9, 23> RSVD2;
constexpr USBPHY2_Reg<&USBPHY_Layout::RX_TOG,  1, 22, 0x0> RXDBYPASS;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::RX_TOG), 15,  7> RSVD1;
constexpr USBPHY2_Reg<&USBPHY_Layout::RX_TOG,  3,  4, 0x0> DISCONADJ;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::RX_TOG),  1,  3> RSVD0;
constexpr USBPHY2_Reg<&USBPHY_Layout::RX_TOG,  3,  0, 0x0> ENVADJ;
}  // namespace RX_TOG

// USB PHY General Control Register
namespace CTRL {
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1, 31> SFTRST;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1, 30> CLKGATE;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::CTRL), 1, 29> UTMI_SUSPENDM;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1, 28> HOST_FORCE_LS_SE0;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::CTRL), 1, 27> OTG_ID_VALUE;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::CTRL), 2, 25> RSVD1;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1, 24> FSDLL_RST_EN;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1, 23> ENVBUSCHG_WKUP;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1, 22> ENIDCHG_WKUP;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1, 21> ENDPDMCHG_WKUP;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1, 20> ENAUTOCLR_PHY_PWD;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1, 19> ENAUTOCLR_CLKGATE;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1, 18> ENAUTO_PWRON_PLL;
// constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1, 17> WAKEUP_IRQ;
    // Reset only by writing a 1 to the clear address space
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1, 16> ENIRQWAKEUP;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1, 15> ENUTMILEVEL3;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1, 14> ENUTMILEVEL2;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1, 13> DATA_ON_LRADC;
// constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1, 12> DEVPLUGIN_IRQ;
    // Reset only by writing a 1 to the clear address space
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1, 11> ENIRQDEVPLUGIN;
// constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1, 10> RESUME_IRQ;
    // Reset only by writing a 1 to the clear address space
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1,  9> ENIRQRESUMEDETECT;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1,  8> RESUMEIRQSTICKY;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1,  7> ENOTGIDDETECT;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1,  6> OTG_ID_CHG_IRQ;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1,  5> DEVPLUGIN_POLARITY;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1,  4> ENDEVPLUGINDETECT;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1,  3> HOSTDISCONDETECT_IRQ;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1,  2> ENIRQHOSTDISCON;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1,  1> ENHOSTDISCONDETECT;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL, 1,  0> ENOTG_ID_CHG_IRQ;
}  // namespace CTRL

// USB PHY General Control Register
namespace CTRL_SET {
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1, 31, 0x0> SFTRST;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1, 30, 0x0> CLKGATE;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::CTRL_SET), 1, 29> UTMI_SUSPENDM;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1, 28, 0x0> HOST_FORCE_LS_SE0;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::CTRL_SET), 1, 27> OTG_ID_VALUE;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::CTRL_SET), 2, 25> RSVD1;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1, 24, 0x0> FSDLL_RST_EN;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1, 23, 0x0> ENVBUSCHG_WKUP;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1, 22, 0x0> ENIDCHG_WKUP;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1, 21, 0x0> ENDPDMCHG_WKUP;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1, 20, 0x0> ENAUTOCLR_PHY_PWD;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1, 19, 0x0> ENAUTOCLR_CLKGATE;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1, 18, 0x0> ENAUTO_PWRON_PLL;
// constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1, 17, 0x0> WAKEUP_IRQ;
    // Reset only by writing a 1 to the clear address space
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1, 16, 0x0> ENIRQWAKEUP;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1, 15, 0x0> ENUTMILEVEL3;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1, 14, 0x0> ENUTMILEVEL2;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1, 13, 0x0> DATA_ON_LRADC;
// constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1, 12, 0x0> DEVPLUGIN_IRQ;
    // Reset only by writing a 1 to the clear address space
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1, 11, 0x0> ENIRQDEVPLUGIN;
// constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1, 10, 0x0> RESUME_IRQ;
    // Reset only by writing a 1 to the clear address space
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1,  9, 0x0> ENIRQRESUMEDETECT;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1,  8, 0x0> RESUMEIRQSTICKY;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1,  7, 0x0> ENOTGIDDETECT;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1,  6, 0x0> OTG_ID_CHG_IRQ;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1,  5, 0x0> DEVPLUGIN_POLARITY;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1,  4, 0x0> ENDEVPLUGINDETECT;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1,  3, 0x0> HOSTDISCONDETECT_IRQ;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1,  2, 0x0> ENIRQHOSTDISCON;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1,  1, 0x0> ENHOSTDISCONDETECT;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_SET, 1,  0, 0x0> ENOTG_ID_CHG_IRQ;
}  // namespace CTRL_SET

// USB PHY General Control Register
namespace CTRL_CLR {
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1, 31, 0x0> SFTRST;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1, 30, 0x0> CLKGATE;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::CTRL_CLR), 1, 29> UTMI_SUSPENDM;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1, 28, 0x0> HOST_FORCE_LS_SE0;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::CTRL_CLR), 1, 27> OTG_ID_VALUE;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::CTRL_CLR), 2, 25> RSVD1;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1, 24, 0x0> FSDLL_RST_EN;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1, 23, 0x0> ENVBUSCHG_WKUP;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1, 22, 0x0> ENIDCHG_WKUP;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1, 21, 0x0> ENDPDMCHG_WKUP;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1, 20, 0x0> ENAUTOCLR_PHY_PWD;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1, 19, 0x0> ENAUTOCLR_CLKGATE;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1, 18, 0x0> ENAUTO_PWRON_PLL;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1, 17, 0x0> WAKEUP_IRQ;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1, 16, 0x0> ENIRQWAKEUP;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1, 15, 0x0> ENUTMILEVEL3;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1, 14, 0x0> ENUTMILEVEL2;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1, 13, 0x0> DATA_ON_LRADC;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1, 12, 0x0> DEVPLUGIN_IRQ;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1, 11, 0x0> ENIRQDEVPLUGIN;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1, 10, 0x0> RESUME_IRQ;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1,  9, 0x0> ENIRQRESUMEDETECT;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1,  8, 0x0> RESUMEIRQSTICKY;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1,  7, 0x0> ENOTGIDDETECT;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1,  6, 0x0> OTG_ID_CHG_IRQ;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1,  5, 0x0> DEVPLUGIN_POLARITY;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1,  4, 0x0> ENDEVPLUGINDETECT;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1,  3, 0x0> HOSTDISCONDETECT_IRQ;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1,  2, 0x0> ENIRQHOSTDISCON;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1,  1, 0x0> ENHOSTDISCONDETECT;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_CLR, 1,  0, 0x0> ENOTG_ID_CHG_IRQ;
}  // namespace CTRL_CLR

// USB PHY General Control Register
namespace CTRL_TOG {
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1, 31, 0x0> SFTRST;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1, 30, 0x0> CLKGATE;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::CTRL_TOG), 1, 29> UTMI_SUSPENDM;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1, 28, 0x0> HOST_FORCE_LS_SE0;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::CTRL_TOG), 1, 27> OTG_ID_VALUE;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::CTRL_TOG), 2, 25> RSVD1;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1, 24, 0x0> FSDLL_RST_EN;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1, 23, 0x0> ENVBUSCHG_WKUP;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1, 22, 0x0> ENIDCHG_WKUP;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1, 21, 0x0> ENDPDMCHG_WKUP;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1, 20, 0x0> ENAUTOCLR_PHY_PWD;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1, 19, 0x0> ENAUTOCLR_CLKGATE;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1, 18, 0x0> ENAUTO_PWRON_PLL;
// constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1, 17, 0x0> WAKEUP_IRQ;
    // Reset only by writing a 1 to the clear address space
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1, 16, 0x0> ENIRQWAKEUP;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1, 15, 0x0> ENUTMILEVEL3;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1, 14, 0x0> ENUTMILEVEL2;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1, 13, 0x0> DATA_ON_LRADC;
// constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1, 12, 0x0> DEVPLUGIN_IRQ;
    // Reset only by writing a 1 to the clear address space
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1, 11, 0x0> ENIRQDEVPLUGIN;
// constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1, 10, 0x0> RESUME_IRQ;
    // Reset only by writing a 1 to the clear address space
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1,  9, 0x0> ENIRQRESUMEDETECT;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1,  8, 0x0> RESUMEIRQSTICKY;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1,  7, 0x0> ENOTGIDDETECT;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1,  6, 0x0> OTG_ID_CHG_IRQ;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1,  5, 0x0> DEVPLUGIN_POLARITY;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1,  4, 0x0> ENDEVPLUGINDETECT;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1,  3, 0x0> HOSTDISCONDETECT_IRQ;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1,  2, 0x0> ENIRQHOSTDISCON;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1,  1, 0x0> ENHOSTDISCONDETECT;
constexpr USBPHY2_Reg<&USBPHY_Layout::CTRL_TOG, 1,  0, 0x0> ENOTG_ID_CHG_IRQ;
}  // namespace CTRL_TOG

// USB PHY Status Register
namespace STATUS {
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::STATUS), 21, 11> RSVD4;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::STATUS),  1, 10> RESUME_STATUS;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::STATUS),  1,  9> RSVD3;
constexpr USBPHY2_Reg<&USBPHY_Layout::STATUS,  1,  8> OTGID_STATUS;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::STATUS),  1,  7> RSVD2;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::STATUS),  1,  6> DEVPLUGIN_STATUS;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::STATUS),  2,  4> RSVD1;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::STATUS),  1,  3> HOSTDISCONDETECT_STATUS;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::STATUS),  3,  0> RSVD0;
}  // namespace STATUS

// USB PHY Debug Register
namespace DEBUG {
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::DEBUG), 1, 31> RSVD3;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG, 1, 30> CLKGATE;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG, 1, 29> HOST_RESUME_DEBUG;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG, 4, 25> SQUELCHRESETLENGTH;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG, 1, 24> ENSQUELCHRESET;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::DEBUG), 3, 21> RSVD2;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG, 5, 16> SQUELCHRESETCOUNT;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::DEBUG), 3, 13> RSVD1;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG, 1, 12> ENTX2RXCOUNT;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG, 4,  8> TX2RXCOUNT;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::DEBUG), 2,  6> RSVD0;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG, 2,  4> ENHSTPULLDOWN;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG, 2,  2> HSTPULLDOWN;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG, 1,  1> DEBUG_INTERFACE_HOLD;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG, 1,  0> OTGIDPIOLOCK;
}  // namespace DEBUG

// USB PHY Debug Register
namespace DEBUG_SET {
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::DEBUG_SET), 1, 31> RSVD3;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_SET, 1, 30, 0x0> CLKGATE;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_SET, 1, 29, 0x0> HOST_RESUME_DEBUG;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_SET, 4, 25, 0x0> SQUELCHRESETLENGTH;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_SET, 1, 24, 0x0> ENSQUELCHRESET;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::DEBUG_SET), 3, 21> RSVD2;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_SET, 5, 16, 0x0> SQUELCHRESETCOUNT;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::DEBUG_SET), 3, 13> RSVD1;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_SET, 1, 12, 0x0> ENTX2RXCOUNT;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_SET, 4,  8, 0x0> TX2RXCOUNT;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::DEBUG_SET), 2,  6> RSVD0;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_SET, 2,  4, 0x0> ENHSTPULLDOWN;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_SET, 2,  2, 0x0> HSTPULLDOWN;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_SET, 1,  1, 0x0> DEBUG_INTERFACE_HOLD;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_SET, 1,  0, 0x0> OTGIDPIOLOCK;
}  // namespace DEBUG_SET

// USB PHY Debug Register
namespace DEBUG_CLR {
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::DEBUG_CLR), 1, 31> RSVD3;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_CLR, 1, 30, 0x0> CLKGATE;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_CLR, 1, 29, 0x0> HOST_RESUME_DEBUG;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_CLR, 4, 25, 0x0> SQUELCHRESETLENGTH;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_CLR, 1, 24, 0x0> ENSQUELCHRESET;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::DEBUG_CLR), 3, 21> RSVD2;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_CLR, 5, 16, 0x0> SQUELCHRESETCOUNT;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::DEBUG_CLR), 3, 13> RSVD1;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_CLR, 1, 12, 0x0> ENTX2RXCOUNT;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_CLR, 4,  8, 0x0> TX2RXCOUNT;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::DEBUG_CLR), 2,  6> RSVD0;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_CLR, 2,  4, 0x0> ENHSTPULLDOWN;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_CLR, 2,  2, 0x0> HSTPULLDOWN;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_CLR, 1,  1, 0x0> DEBUG_INTERFACE_HOLD;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_CLR, 1,  0, 0x0> OTGIDPIOLOCK;
}  // namespace DEBUG_CLR

// USB PHY Debug Register
namespace DEBUG_TOG {
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::DEBUG_TOG), 1, 31> RSVD3;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_TOG, 1, 30, 0x0> CLKGATE;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_TOG, 1, 29, 0x0> HOST_RESUME_DEBUG;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_TOG, 4, 25, 0x0> SQUELCHRESETLENGTH;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_TOG, 1, 24, 0x0> ENSQUELCHRESET;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::DEBUG_TOG), 3, 21> RSVD2;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_TOG, 5, 16, 0x0> SQUELCHRESETCOUNT;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::DEBUG_TOG), 3, 13> RSVD1;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_TOG, 1, 12, 0x0> ENTX2RXCOUNT;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_TOG, 4,  8, 0x0> TX2RXCOUNT;
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::DEBUG_TOG), 2,  6> RSVD0;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_TOG, 2,  4, 0x0> ENHSTPULLDOWN;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_TOG, 2,  2, 0x0> HSTPULLDOWN;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_TOG, 1,  1, 0x0> DEBUG_INTERFACE_HOLD;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG_TOG, 1,  0, 0x0> OTGIDPIOLOCK;
}  // namespace DEBUG_TOG

// UTMI Debug Status Register 0
namespace DEBUG0_STATUS {
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG0_STATUS,  6, 26> SQUELCH_COUNT;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG0_STATUS, 10, 16> UTMI_RXERROR_FAIL_COUNT;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG0_STATUS, 16,  0> LOOP_BACK_FAIL_COUNT;
}  // namespace DEBUG0_STATUS

// UTMI Debug Status Register 1
namespace DEBUG1 {
constexpr uint32_t kWOZ = regs::shiftedMask32<13, 0>();

constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::DEBUG1), 17, 15> RSVD1;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG1,  2, 13, regs::shiftedMask32<2, 13>() | kWOZ> ENTAILADJVD;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG1, 13,  0> RSVD0;
}  // namespace DEBUG1

// UTMI Debug Status Register 1
namespace DEBUG1_SET {
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::DEBUG1_SET), 17, 15> RSVD1;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG1_SET,  2, 13, 0x0> ENTAILADJVD;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG1_SET, 13,  0, 0x0> RSVD0;
}  // namespace DEBUG1_SET

// UTMI Debug Status Register 1
namespace DEBUG1_CLR {
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::DEBUG1_CLR), 17, 15> RSVD1;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG1_CLR,  2, 13, 0x0> ENTAILADJVD;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG1_CLR, 13,  0, 0x0> RSVD0;
}  // namespace DEBUG1_CLR

// UTMI Debug Status Register 1
namespace DEBUG1_TOG {
constexpr USBPHY2_Reg<regs::constify(&USBPHY_Layout::DEBUG1_TOG), 17, 15> RSVD1;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG1_TOG,  2, 13, 0x0> ENTAILADJVD;
constexpr USBPHY2_Reg<&USBPHY_Layout::DEBUG1_TOG, 13,  0, 0x0> RSVD0;
}  // namespace DEBUG1_TOG

// UTMI RTL Version
namespace VERSION {
constexpr USBPHY2_Reg<&USBPHY_Layout::VERSION,  8, 24> MAJOR;
constexpr USBPHY2_Reg<&USBPHY_Layout::VERSION,  8, 16> MINOR;
constexpr USBPHY2_Reg<&USBPHY_Layout::VERSION, 16,  0> STEP;
}  // namespace VERSION

}  // namespace USBPHY2

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
