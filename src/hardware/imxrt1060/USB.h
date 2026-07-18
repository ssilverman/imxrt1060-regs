// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// USB.h defines all the USB registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

constexpr size_t kUSB_ENDPTCTRL_count = 8;

// USB layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_USB.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct USB_Layout {
  const volatile uint32_t ID;                                /**< Identification register, offset: 0x0 */
  const volatile uint32_t HWGENERAL;                         /**< Hardware General, offset: 0x4 */
  const volatile uint32_t HWHOST;                            /**< Host Hardware Parameters, offset: 0x8 */
  const volatile uint32_t HWDEVICE;                          /**< Device Hardware Parameters, offset: 0xC */
  const volatile uint32_t HWTXBUF;                           /**< TX Buffer Hardware Parameters, offset: 0x10 */
  const volatile uint32_t HWRXBUF;                           /**< RX Buffer Hardware Parameters, offset: 0x14 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[26];
  volatile uint32_t GPTIMER0LD;                              /**< General Purpose Timer #0 Load, offset: 0x80 */
  volatile uint32_t GPTIMER0CTRL;                            /**< General Purpose Timer #0 Controller, offset: 0x84 */
  volatile uint32_t GPTIMER1LD;                              /**< General Purpose Timer #1 Load, offset: 0x88 */
  volatile uint32_t GPTIMER1CTRL;                            /**< General Purpose Timer #1 Controller, offset: 0x8C */
  volatile uint32_t SBUSCFG;                                 /**< System Bus Config, offset: 0x90 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[27];
  const volatile uint8_t CAPLENGTH;                          /**< Capability Registers Length, offset: 0x100 */
  uint8_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  const volatile uint16_t HCIVERSION;                        /**< Host Controller Interface Version, offset: 0x102 */
  const volatile uint32_t HCSPARAMS;                         /**< Host Controller Structural Parameters, offset: 0x104 */
  const volatile uint32_t HCCPARAMS;                         /**< Host Controller Capability Parameters, offset: 0x108 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[5];
  const volatile uint16_t DCIVERSION;                        /**< Device Controller Interface Version, offset: 0x120 */
  uint8_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[2];
  const volatile uint32_t DCCPARAMS;                         /**< Device Controller Capability Parameters, offset: 0x124 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[6];
  volatile uint32_t USBCMD;                                  /**< USB Command Register, offset: 0x140 */
  volatile uint32_t USBSTS;                                  /**< USB Status Register, offset: 0x144 */
  volatile uint32_t USBINTR;                                 /**< Interrupt Enable Register, offset: 0x148 */
  volatile uint32_t FRINDEX;                                 /**< USB Frame Index, offset: 0x14C */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  union {                                                /* offset: 0x154 */
    volatile uint32_t DEVICEADDR;                            /**< Device Address, offset: 0x154 */
    volatile uint32_t PERIODICLISTBASE;                      /**< Frame List Base Address, offset: 0x154 */
  };
  union {                                                /* offset: 0x158 */
    volatile uint32_t ASYNCLISTADDR;                         /**< Next Asynch. Address, offset: 0x158 */
    volatile uint32_t ENDPTLISTADDR;                         /**< Endpoint List Address, offset: 0x158 */
  };
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t BURSTSIZE;                               /**< Programmable Burst Size, offset: 0x160 */
  volatile uint32_t TXFILLTUNING;                            /**< TX FIFO Fill Tuning, offset: 0x164 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[4];
  volatile uint32_t ENDPTNAK;                                /**< Endpoint NAK, offset: 0x178 */
  volatile uint32_t ENDPTNAKEN;                              /**< Endpoint NAK Enable, offset: 0x17C */
  const volatile uint32_t CONFIGFLAG;                        /**< Configure Flag Register, offset: 0x180 */
  volatile uint32_t PORTSC1;                                 /**< Port Status & Control, offset: 0x184 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[7];
  volatile uint32_t OTGSC;                                   /**< On-The-Go Status & control, offset: 0x1A4 */
  volatile uint32_t USBMODE;                                 /**< USB Device Mode, offset: 0x1A8 */
  volatile uint32_t ENDPTSETUPSTAT;                          /**< Endpoint Setup Status, offset: 0x1AC */
  volatile uint32_t ENDPTPRIME;                              /**< Endpoint Prime, offset: 0x1B0 */
  volatile uint32_t ENDPTFLUSH;                              /**< Endpoint Flush, offset: 0x1B4 */
  const volatile uint32_t ENDPTSTAT;                         /**< Endpoint Status, offset: 0x1B8 */
  volatile uint32_t ENDPTCOMPLETE;                           /**< Endpoint Complete, offset: 0x1BC */
//   volatile uint32_t ENDPTCTRL0;                              /**< Endpoint Control0, offset: 0x1C0 */
//   volatile uint32_t ENDPTCTRL[kUSB_ENDPTCTRL_count];         /**< Endpoint Control 1..Endpoint Control 7, array offset: 0x1C4, array step: 0x4 */
  volatile uint32_t ENDPTCTRL[kUSB_ENDPTCTRL_count];         /**< Endpoint Control 0..Endpoint Control 7, array offset: 0x1C0, array step: 0x4 */
};

constexpr size_t    kUSB_size  = 0x1E0;
constexpr uintptr_t kUSB1_base = 0x402E0000;
constexpr uintptr_t kUSB2_base = 0x402E0200;

namespace USB1 {
constexpr regs::RegGroup<USB_Layout, kUSB_size, kUSB1_base> group;
}  // namespace USB1

namespace USB2 {
constexpr regs::RegGroup<USB_Layout, kUSB_size, kUSB2_base> group;
}  // namespace USB2

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using USB1_Reg =
    regs::Reg32<kUSB1_base, USB_Layout, Member, 0, Bits, Shift, DirectAssign>;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using USB2_Reg =
    regs::Reg32<kUSB2_base, USB_Layout, Member, 0, Bits, Shift, DirectAssign>;

namespace USB1 {

// USB1 Identification register
namespace ID {
constexpr USB1_Reg<&USB_Layout::ID, 8, 16> REVISION;
constexpr USB1_Reg<&USB_Layout::ID, 6,  8> NID;
constexpr USB1_Reg<&USB_Layout::ID, 6,  0> ID;
}  // namespace ID

// USB1 Hardware General
namespace HWGENERAL {
constexpr USB1_Reg<&USB_Layout::HWGENERAL, 2, 9> SM;
    // 0b00..No Serial Engine, always use parallel signalling.
    // 0b01..Serial Engine present, always use serial signalling for FS/LS.
    // 0b10..Software programmable - Reset to use parallel signalling for FS/LS
    // 0b11..Software programmable - Reset to use serial signalling for FS/LS
constexpr USB1_Reg<&USB_Layout::HWGENERAL, 3, 6> PHYM;
    // 0b000..UTMI/UMTI+
    // 0b001..ULPI DDR
    // 0b010..ULPI
    // 0b011..Serial Only
    // 0b100..Software programmable - reset to UTMI/UTMI+
    // 0b101..Software programmable - reset to ULPI DDR
    // 0b110..Software programmable - reset to ULPI
    // 0b111..Software programmable - reset to Serial
constexpr USB1_Reg<&USB_Layout::HWGENERAL, 2, 4> PHYW;
    // 0b00..8 bit wide data bus Software non-programmable
    // 0b01..16 bit wide data bus Software non-programmable
    // 0b10..Reset to 8 bit wide data bus Software programmable
    // 0b11..Reset to 16 bit wide data bus Software programmable
}  // namespace HWGENERAL

// USB1 Host Hardware Parameters
namespace HWHOST {
constexpr USB1_Reg<&USB_Layout::HWHOST, 3, 1> NPORT;
constexpr USB1_Reg<&USB_Layout::HWHOST, 1, 0> HC;
    // 0b0..Not supported
    // 0b1..Supported
}  // namespace HWHOST

// USB1 Device Hardware Parameters
namespace HWDEVICE {
constexpr USB1_Reg<&USB_Layout::HWDEVICE, 5, 1> DEVEP;
constexpr USB1_Reg<&USB_Layout::HWDEVICE, 1, 0> DC;
    // 0b0..Not supported
    // 0b1..Supported
}  // namespace HWDEVICE

// USB1 TX Buffer Hardware Parameters
namespace HWTXBUF {
constexpr USB1_Reg<&USB_Layout::HWTXBUF, 8, 16> TXCHANADD;
constexpr USB1_Reg<&USB_Layout::HWTXBUF, 8,  0> TXBURST;
}  // namespace HWTXBUF

// USB1 RX Buffer Hardware Parameters
namespace HWRXBUF {
constexpr USB1_Reg<&USB_Layout::HWRXBUF, 8, 8> RXADD;
constexpr USB1_Reg<&USB_Layout::HWRXBUF, 8, 0> RXBURST;
}  // namespace HWRXBUF

// USB1 General Purpose Timer #0 Load
namespace GPTIMER0LD {
constexpr USB1_Reg<&USB_Layout::GPTIMER0LD, 24, 0> GPTLD;
}  // namespace GPTIMER0LD

// USB1 General Purpose Timer #0 Controller
namespace GPTIMER0CTRL {
constexpr USB1_Reg<&USB_Layout::GPTIMER0CTRL,  1, 31> GPTRUN;
    // 0b0..Stop counting
    // 0b1..Run
constexpr USB1_Reg<&USB_Layout::GPTIMER0CTRL,  1, 30> GPTRST;
    // 0b0..No action
    // 0b1..Load counter value from GPTLD bits in n_GPTIMER0LD
constexpr USB1_Reg<&USB_Layout::GPTIMER0CTRL,  1, 24> GPTMODE;
    // 0b0..One Shot Mode
    // 0b1..Repeat Mode
constexpr USB1_Reg<&USB_Layout::GPTIMER0CTRL, 24,  0> GPTCNT;
}  // namespace GPTIMER0CTRL

// USB1 General Purpose Timer #1 Load
namespace GPTIMER1LD {
constexpr USB1_Reg<&USB_Layout::GPTIMER1LD, 24,  0> GPTLD;
}  // namespace GPTIMER1LD

// USB1 General Purpose Timer #1 Controller
namespace GPTIMER1CTRL {
constexpr USB1_Reg<&USB_Layout::GPTIMER1CTRL,  1, 31> GPTRUN;
    // 0b0..Stop counting
    // 0b1..Run
constexpr USB1_Reg<&USB_Layout::GPTIMER1CTRL,  1, 30> GPTRST;
    // 0b0..No action
    // 0b1..Load counter value from GPTLD bits in USB_n_GPTIMER0LD
constexpr USB1_Reg<&USB_Layout::GPTIMER1CTRL,  1, 24> GPTMODE;
    // 0b0..One Shot Mode
    // 0b1..Repeat Mode
constexpr USB1_Reg<&USB_Layout::GPTIMER1CTRL, 24,  0> GPTCNT;
}  // namespace GPTIMER1CTRL

// USB1 System Bus Config
namespace SBUSCFG {
constexpr USB1_Reg<&USB_Layout::SBUSCFG, 3, 0> AHBBRST;
    // 0b000..Incremental burst of unspecified length only
    // 0b001..INCR4 burst, then single transfer
    // 0b010..INCR8 burst, INCR4 burst, then single transfer
    // 0b011..INCR16 burst, INCR8 burst, INCR4 burst, then single transfer
    // 0b100..Reserved, don't use
    // 0b101..INCR4 burst, then incremental burst of unspecified length
    // 0b110..INCR8 burst, INCR4 burst, then incremental burst of unspecified length
    // 0b111..INCR16 burst, INCR8 burst, INCR4 burst, then incremental burst of unspecified length
}  // namespace SBUSCFG

// USB1 Host Controller Structural Parameters
namespace HCSPARAMS {
constexpr USB1_Reg<&USB_Layout::HCSPARAMS, 4, 24> N_TT;
constexpr USB1_Reg<&USB_Layout::HCSPARAMS, 4, 20> N_PTT;
constexpr USB1_Reg<&USB_Layout::HCSPARAMS, 1, 16> PI;
constexpr USB1_Reg<&USB_Layout::HCSPARAMS, 4, 12> N_CC;
    // 0b0000..There is no internal Companion Controller and port-ownership hand-off is not supported.
    // 0b0001..There are internal companion controller(s) and port-ownership hand-offs is supported.
constexpr USB1_Reg<&USB_Layout::HCSPARAMS, 4,  8> N_PCC;
constexpr USB1_Reg<&USB_Layout::HCSPARAMS, 1,  4> PPC;
constexpr USB1_Reg<&USB_Layout::HCSPARAMS, 4,  0> N_PORTS;
}  // namespace HCSPARAMS

// USB1 Host Controller Capability Parameters
namespace HCCPARAMS {
constexpr USB1_Reg<&USB_Layout::HCCPARAMS, 8, 8> EECP;
constexpr USB1_Reg<&USB_Layout::HCCPARAMS, 4, 4> IST;
constexpr USB1_Reg<&USB_Layout::HCCPARAMS, 1, 2> ASP;
constexpr USB1_Reg<&USB_Layout::HCCPARAMS, 1, 1> PFL;
constexpr USB1_Reg<&USB_Layout::HCCPARAMS, 1, 0> ADC;
}  // namespace HCCPARAMS

// USB1 Device Controller Capability Parameters
namespace DCCPARAMS {
constexpr USB1_Reg<&USB_Layout::DCCPARAMS, 1, 8> HC;
constexpr USB1_Reg<&USB_Layout::DCCPARAMS, 1, 7> DC;
constexpr USB1_Reg<&USB_Layout::DCCPARAMS, 5, 0> DEN;
}  // namespace DCCPARAMS

// USB1 USB Command Register
namespace USBCMD {
constexpr USB1_Reg<&USB_Layout::USBCMD, 8, 16> ITC;
    // 0b00000000..Immediate (no threshold)
    // 0b00000001..1 micro-frame
    // 0b00000010..2 micro-frames
    // 0b00000100..4 micro-frames
    // 0b00001000..8 micro-frames
    // 0b00010000..16 micro-frames
    // 0b00100000..32 micro-frames
    // 0b01000000..64 micro-frames
constexpr USB1_Reg<&USB_Layout::USBCMD, 1, 15> FS_2;
    // 0b0..1024 elements (4096 bytes) Default value
    // 0b1..512 elements (2048 bytes)
constexpr USB1_Reg<&USB_Layout::USBCMD, 1, 14> ATDTW;
constexpr USB1_Reg<&USB_Layout::USBCMD, 1, 13> SUTW;
constexpr USB1_Reg<&USB_Layout::USBCMD, 1, 11> ASPE;
constexpr USB1_Reg<&USB_Layout::USBCMD, 2,  8> ASP;
constexpr USB1_Reg<&USB_Layout::USBCMD, 1,  6> IAA;
constexpr USB1_Reg<&USB_Layout::USBCMD, 1,  5> ASE;
    // 0b0..Do not process the Asynchronous Schedule.
    // 0b1..Use the ASYNCLISTADDR register to access the Asynchronous Schedule.
constexpr USB1_Reg<&USB_Layout::USBCMD, 1,  4> PSE;
    // 0b0..Do not process the Periodic Schedule
    // 0b1..Use the PERIODICLISTBASE register to access the Periodic Schedule.
constexpr USB1_Reg<&USB_Layout::USBCMD, 2,  2> FS_1;
constexpr USB1_Reg<&USB_Layout::USBCMD, 1,  1> RST;
constexpr USB1_Reg<&USB_Layout::USBCMD, 1,  0> RS;
}  // namespace USBCMD

// USB1 USB Status Register
namespace USBSTS {
constexpr USB1_Reg<&USB_Layout::USBSTS, 1, 25> TI1;
constexpr USB1_Reg<&USB_Layout::USBSTS, 1, 24> TI0;
constexpr USB1_Reg<&USB_Layout::USBSTS, 1, 16> NAKI;
constexpr USB1_Reg<&USB_Layout::USBSTS, 1, 15> AS;
constexpr USB1_Reg<&USB_Layout::USBSTS, 1, 14> PS;
constexpr USB1_Reg<&USB_Layout::USBSTS, 1, 13> RCL;
constexpr USB1_Reg<&USB_Layout::USBSTS, 1, 12> HCH;
constexpr USB1_Reg<&USB_Layout::USBSTS, 1, 10> ULPII;
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  8> SLI;
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  7> SRI;
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  6> URI;
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  5> AAI;
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  4> SEI;
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  3> FRI;
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  2> PCI;
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  1> UEI;
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  0> UI;
}  // namespace USBSTS

// USB1 Interrupt Enable Register
namespace USBINTR {
constexpr USB1_Reg<&USB_Layout::USBINTR, 1, 25> TIE1;
constexpr USB1_Reg<&USB_Layout::USBINTR, 1, 24> TIE0;
constexpr USB1_Reg<&USB_Layout::USBINTR, 1, 19> UPIE;
constexpr USB1_Reg<&USB_Layout::USBINTR, 1, 18> UAIE;
constexpr USB1_Reg<&USB_Layout::USBINTR, 1, 16> NAKE;
constexpr USB1_Reg<&USB_Layout::USBINTR, 1, 10> ULPIE;
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  8> SLE;
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  7> SRE;
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  6> URE;
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  5> AAE;
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  4> SEE;
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  3> FRE;
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  2> PCE;
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  1> UEE;
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  0> UE;
}  // namespace USBINTR

// USB1 USB Frame Index
namespace FRINDEX {
constexpr USB1_Reg<&USB_Layout::FRINDEX, 14, 0> FRINDEX;
    // 0b00000000000000..(1024) 12
    // 0b00000000000001..(512) 11
    // 0b00000000000010..(256) 10
    // 0b00000000000011..(128) 9
    // 0b00000000000100..(64) 8
    // 0b00000000000101..(32) 7
    // 0b00000000000110..(16) 6
    // 0b00000000000111..(8) 5
}  // namespace FRINDEX

// USB1 Device Address
namespace DEVICEADDR {
constexpr USB1_Reg<&USB_Layout::DEVICEADDR, 7, 25> USBADR;
constexpr USB1_Reg<&USB_Layout::DEVICEADDR, 1, 24> USBADRA;
}  // namespace DEVICEADDR

// USB1 Frame List Base Address
namespace PERIODICLISTBASE {
constexpr USB1_Reg<&USB_Layout::PERIODICLISTBASE, 20, 12> BASEADR;
}  // namespace PERIODICLISTBASE

// USB1 Next Asynch. Address
namespace ASYNCLISTADDR {
constexpr USB1_Reg<&USB_Layout::ASYNCLISTADDR, 27, 5> ASYBASE;
}  // namespace ASYNCLISTADDR

// USB1 Endpoint List Address
namespace ENDPTLISTADDR {
constexpr USB1_Reg<&USB_Layout::ENDPTLISTADDR, 21, 11> EPBASE;
}  // namespace ENDPTLISTADDR

// USB1 Programmable Burst Size
namespace BURSTSIZE {
constexpr USB1_Reg<&USB_Layout::BURSTSIZE, 9, 8> TXPBURST;
constexpr USB1_Reg<&USB_Layout::BURSTSIZE, 8, 0> RXPBURST;
}  // namespace BURSTSIZE

// USB1 TX FIFO Fill Tuning
namespace TXFILLTUNING {
constexpr USB1_Reg<&USB_Layout::TXFILLTUNING, 6, 16> TXFIFOTHRES;
constexpr USB1_Reg<&USB_Layout::TXFILLTUNING, 5,  8> TXSCHHEALTH;
constexpr USB1_Reg<&USB_Layout::TXFILLTUNING, 8,  0> TXSCHOH;
}  // namespace TXFILLTUNING

// USB1 Endpoint NAK
namespace ENDPTNAK {
constexpr USB1_Reg<&USB_Layout::ENDPTNAK, 8, 16> EPTN;
constexpr USB1_Reg<&USB_Layout::ENDPTNAK, 8,  0> EPRN;
}  // namespace ENDPTNAK

// USB1 Endpoint NAK Enable
namespace ENDPTNAKEN {
constexpr USB1_Reg<&USB_Layout::ENDPTNAKEN, 8, 16> EPTNE;
constexpr USB1_Reg<&USB_Layout::ENDPTNAKEN, 8,  0> EPRNE;
}  // namespace ENDPTNAKEN

// USB1 Configure Flag Register
namespace CONFIGFLAG {
constexpr USB1_Reg<&USB_Layout::CONFIGFLAG, 1, 0> CF;
    // 0b0..Port routing control logic default-routes each port to an implementation dependent classic host controller.
    // 0b1..Port routing control logic default-routes all ports to this host controller.
}  // namespace CONFIGFLAG

// USB1 Port Status & Control
namespace PORTSC1 {
constexpr USB1_Reg<&USB_Layout::PORTSC1, 2, 30> PTS_1;
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 29> STS;
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 28> PTW;
    // 0b0..Select the 8-bit UTMI interface [60MHz]
    // 0b1..Select the 16-bit UTMI interface [30MHz]
constexpr USB1_Reg<&USB_Layout::PORTSC1, 2, 26> PSPD;
    // 0b00..Full Speed
    // 0b01..Low Speed
    // 0b10..High Speed
    // 0b11..Undefined
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 25> PTS_2;
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 24> PFSC;
    // 0b0..Normal operation
    // 0b1..Forced to full speed
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 23> PHCD;
    // 0b0..Enable PHY clock
    // 0b1..Disable PHY clock
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 22> WKOC;
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 21> WKDC;
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 20> WKCN;
constexpr USB1_Reg<&USB_Layout::PORTSC1, 4, 16> PTC;
    // 0b0000..TEST_MODE_DISABLE
    // 0b0001..J_STATE
    // 0b0010..K_STATE
    // 0b0011..SE0 (host) / NAK (device)
    // 0b0100..Packet
    // 0b0101..FORCE_ENABLE_HS
    // 0b0110..FORCE_ENABLE_FS
    // 0b0111..FORCE_ENABLE_LS
    // 0b1000-0b1111..Reserved
constexpr USB1_Reg<&USB_Layout::PORTSC1, 2, 14> PIC;
    // 0b00..Port indicators are off
    // 0b01..Amber
    // 0b10..Green
    // 0b11..Undefined
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 13> PO;
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 12> PP;
constexpr USB1_Reg<&USB_Layout::PORTSC1, 2, 10> LS;
    // 0b00..SE0
    // 0b01..K-state
    // 0b10..J-state
    // 0b11..Undefined
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 9> HSP;
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 8> PR;
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 7> SUSP;
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 6> FPR;
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 5> OCC;
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 4> OCA;
    // 0b0..This port does not have an over-current condition.
    // 0b1..This port currently has an over-current condition
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 3> PEC;
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 2> PE;
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 1> CSC;
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 0> CCS;
}  // namespace PORTSC1

// USB1 On-The-Go Status & control
namespace OTGSC {
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 30> DPIE;
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 29> EN_1MS;
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 28> BSEIE;
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 27> BSVIE;
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 26> ASVIE;
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 25> AVVIE;
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 24> IDIE;
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 22> DPIS;
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 21> STATUS_1MS;
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 20> BSEIS;
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 19> BSVIS;
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 18> ASVIS;
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 17> AVVIS;
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 16> IDIS;
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 14> DPS;
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 13> TOG_1MS;
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 12> BSE;
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 11> BSV;
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 10> ASV;
constexpr USB1_Reg<&USB_Layout::OTGSC, 1,  9> AVV;
constexpr USB1_Reg<&USB_Layout::OTGSC, 1,  8> ID;
constexpr USB1_Reg<&USB_Layout::OTGSC, 1,  5> IDPU;
constexpr USB1_Reg<&USB_Layout::OTGSC, 1,  4> DP;
constexpr USB1_Reg<&USB_Layout::OTGSC, 1,  3> OT;
constexpr USB1_Reg<&USB_Layout::OTGSC, 1,  1> VC;
constexpr USB1_Reg<&USB_Layout::OTGSC, 1,  0> VD;
}  // namespace OTGSC

// USB1 USB Device Mode
namespace USBMODE {
constexpr USB1_Reg<&USB_Layout::USBMODE, 1, 4> SDIS;
constexpr USB1_Reg<&USB_Layout::USBMODE, 1, 3> SLOM;
    // 0b0..Setup Lockouts On (default);
    // 0b1..Setup Lockouts Off (DCD requires use of Setup Data Buffer Tripwire in USBCMDUSB Command Register .
constexpr USB1_Reg<&USB_Layout::USBMODE, 1, 2> ES;
    // 0b0..Little Endian [Default]
    // 0b1..Big Endian
constexpr USB1_Reg<&USB_Layout::USBMODE, 2, 0> CM;
    // 0b00..Idle [Default for combination host/device]
    // 0b01..Reserved
    // 0b10..Device Controller [Default for device only controller]
    // 0b11..Host Controller [Default for host only controller]
}  // namespace USBMODE

// USB1 Endpoint Setup Status
namespace ENDPTSETUPSTAT {
constexpr USB1_Reg<&USB_Layout::ENDPTSETUPSTAT, 16, 0> ENDPTSETUPSTAT;
}  // namespace ENDPTSETUPSTAT

// USB1 Endpoint Prime
namespace ENDPTPRIME {
constexpr USB1_Reg<&USB_Layout::ENDPTPRIME, 8, 16> PETB;
constexpr USB1_Reg<&USB_Layout::ENDPTPRIME, 8,  0> PERB;
}  // namespace ENDPTPRIME

// USB1 Endpoint Flush
namespace ENDPTFLUSH {
constexpr USB1_Reg<&USB_Layout::ENDPTFLUSH, 8, 16> FETB;
constexpr USB1_Reg<&USB_Layout::ENDPTFLUSH, 8,  0> FERB;
}  // namespace ENDPTFLUSH

// USB1 Endpoint Status
namespace ENDPTSTAT {
constexpr USB1_Reg<&USB_Layout::ENDPTSTAT, 8, 16> ETBR;
constexpr USB1_Reg<&USB_Layout::ENDPTSTAT, 8,  0> ERBR;
}  // namespace ENDPTSTAT

// USB1 Endpoint Complete
namespace ENDPTCOMPLETE {
constexpr USB1_Reg<&USB_Layout::ENDPTCOMPLETE, 8, 16> ETCE;
constexpr USB1_Reg<&USB_Layout::ENDPTCOMPLETE, 8,  0> ERCE;
}  // namespace ENDPTCOMPLETE

}  // namespace USB1

namespace USB {

// Endpoint Control values
namespace ENDPTCTRL {
constexpr regs::RegValue32<1, 23> TXE;
constexpr regs::RegValue32<1, 22> TXR;
constexpr regs::RegValue32<1, 21> TXI;
constexpr regs::RegValue32<2, 18> TXT;
constexpr regs::RegValue32<1, 17> TXD;
constexpr regs::RegValue32<1, 16> TXS;
constexpr regs::RegValue32<1,  7> RXE;
constexpr regs::RegValue32<1,  6> RXR;
constexpr regs::RegValue32<1,  5> RXI;
constexpr regs::RegValue32<2,  2> RXT;
constexpr regs::RegValue32<1,  1> RXD;
constexpr regs::RegValue32<1,  0> RXS;
}  // namespace ENDPTCTRL

}  // namespace USB

namespace USB2 {

// USB2 Identification register
namespace ID {
constexpr USB2_Reg<&USB_Layout::ID, 8, 16> REVISION;
constexpr USB2_Reg<&USB_Layout::ID, 6,  8> NID;
constexpr USB2_Reg<&USB_Layout::ID, 6,  0> ID;
}  // namespace ID

// USB2 Hardware General
namespace HWGENERAL {
constexpr USB2_Reg<&USB_Layout::HWGENERAL, 2, 9> SM;
constexpr USB2_Reg<&USB_Layout::HWGENERAL, 3, 6> PHYM;
constexpr USB2_Reg<&USB_Layout::HWGENERAL, 2, 4> PHYW;
}  // namespace HWGENERAL

// USB2 Host Hardware Parameters
namespace HWHOST {
constexpr USB2_Reg<&USB_Layout::HWHOST, 3, 1> NPORT;
constexpr USB2_Reg<&USB_Layout::HWHOST, 1, 0> HC;
}  // namespace HWHOST

// USB2 Device Hardware Parameters
namespace HWDEVICE {
constexpr USB2_Reg<&USB_Layout::HWDEVICE, 5, 1> DEVEP;
constexpr USB2_Reg<&USB_Layout::HWDEVICE, 1, 0> DC;
}  // namespace HWDEVICE

// USB2 TX Buffer Hardware Parameters
namespace HWTXBUF {
constexpr USB2_Reg<&USB_Layout::HWTXBUF, 8, 16> TXCHANADD;
constexpr USB2_Reg<&USB_Layout::HWTXBUF, 8,  0> TXBURST;
}  // namespace HWTXBUF

// USB2 RX Buffer Hardware Parameters
namespace HWRXBUF {
constexpr USB2_Reg<&USB_Layout::HWRXBUF, 8, 8> RXADD;
constexpr USB2_Reg<&USB_Layout::HWRXBUF, 8, 0> RXBURST;
}  // namespace HWRXBUF

// USB2 General Purpose Timer #0 Load
namespace GPTIMER0LD {
constexpr USB2_Reg<&USB_Layout::GPTIMER0LD, 24, 0> GPTLD;
}  // namespace GPTIMER0LD

// USB2 General Purpose Timer #0 Controller
namespace GPTIMER0CTRL {
constexpr USB2_Reg<&USB_Layout::GPTIMER0CTRL,  1, 31> GPTRUN;
constexpr USB2_Reg<&USB_Layout::GPTIMER0CTRL,  1, 30> GPTRST;
constexpr USB2_Reg<&USB_Layout::GPTIMER0CTRL,  1, 24> GPTMODE;
constexpr USB2_Reg<&USB_Layout::GPTIMER0CTRL, 24,  0> GPTCNT;
}  // namespace GPTIMER0CTRL

// USB2 General Purpose Timer #1 Load
namespace GPTIMER1LD {
constexpr USB2_Reg<&USB_Layout::GPTIMER1LD, 24, 0> GPTLD;
}  // namespace GPTIMER1LD

// USB2 General Purpose Timer #1 Controller
namespace GPTIMER1CTRL {
constexpr USB2_Reg<&USB_Layout::GPTIMER1CTRL,  1, 31> GPTRUN;
constexpr USB2_Reg<&USB_Layout::GPTIMER1CTRL,  1, 30> GPTRST;
constexpr USB2_Reg<&USB_Layout::GPTIMER1CTRL,  1, 24> GPTMODE;
constexpr USB2_Reg<&USB_Layout::GPTIMER1CTRL, 24,  0> GPTCNT;
}  // namespace GPTIMER1CTRL

// USB2 System Bus Config
namespace SBUSCFG {
constexpr USB2_Reg<&USB_Layout::SBUSCFG, 3, 0> AHBBRST;
}  // namespace SBUSCFG

// USB2 Host Controller Structural Parameters
namespace HCSPARAMS {
constexpr USB2_Reg<&USB_Layout::HCSPARAMS, 4, 24> N_TT;
constexpr USB2_Reg<&USB_Layout::HCSPARAMS, 4, 20> N_PTT;
constexpr USB2_Reg<&USB_Layout::HCSPARAMS, 1, 16> PI;
constexpr USB2_Reg<&USB_Layout::HCSPARAMS, 4, 12> N_CC;
constexpr USB2_Reg<&USB_Layout::HCSPARAMS, 4,  8> N_PCC;
constexpr USB2_Reg<&USB_Layout::HCSPARAMS, 1,  4> PPC;
constexpr USB2_Reg<&USB_Layout::HCSPARAMS, 4,  0> N_PORTS;
}  // namespace HCSPARAMS

// USB2 Host Controller Capability Parameters
namespace HCCPARAMS {
constexpr USB2_Reg<&USB_Layout::HCCPARAMS, 8, 8> EECP;
constexpr USB2_Reg<&USB_Layout::HCCPARAMS, 4, 4> IST;
constexpr USB2_Reg<&USB_Layout::HCCPARAMS, 1, 2> ASP;
constexpr USB2_Reg<&USB_Layout::HCCPARAMS, 1, 1> PFL;
constexpr USB2_Reg<&USB_Layout::HCCPARAMS, 1, 0> ADC;
}  // namespace HCCPARAMS

// USB2 Device Controller Capability Parameters
namespace DCCPARAMS {
constexpr USB2_Reg<&USB_Layout::DCCPARAMS, 1, 8> HC;
constexpr USB2_Reg<&USB_Layout::DCCPARAMS, 1, 7> DC;
constexpr USB2_Reg<&USB_Layout::DCCPARAMS, 5, 0> DEN;
}  // namespace DCCPARAMS

// USB2 USB Command Register
namespace USBCMD {
constexpr USB2_Reg<&USB_Layout::USBCMD, 8, 16> ITC;
constexpr USB2_Reg<&USB_Layout::USBCMD, 1, 15> FS_2;
constexpr USB2_Reg<&USB_Layout::USBCMD, 1, 14> ATDTW;
constexpr USB2_Reg<&USB_Layout::USBCMD, 1, 13> SUTW;
constexpr USB2_Reg<&USB_Layout::USBCMD, 1, 11> ASPE;
constexpr USB2_Reg<&USB_Layout::USBCMD, 2,  8> ASP;
constexpr USB2_Reg<&USB_Layout::USBCMD, 1,  6> IAA;
constexpr USB2_Reg<&USB_Layout::USBCMD, 1,  5> ASE;
constexpr USB2_Reg<&USB_Layout::USBCMD, 1,  4> PSE;
constexpr USB2_Reg<&USB_Layout::USBCMD, 2,  2> FS_1;
constexpr USB2_Reg<&USB_Layout::USBCMD, 1,  1> RST;
constexpr USB2_Reg<&USB_Layout::USBCMD, 1,  0> RS;
}  // namespace USBCMD

// USB2 USB Status Register
namespace USBSTS {
constexpr USB2_Reg<&USB_Layout::USBSTS, 1, 25> TI1;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1, 24> TI0;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1, 16> NAKI;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1, 15> AS;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1, 14> PS;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1, 13> RCL;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1, 12> HCH;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1, 10> ULPII;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  8> SLI;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  7> SRI;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  6> URI;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  5> AAI;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  4> SEI;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  3> FRI;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  2> PCI;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  1> UEI;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  0> UI;
}  // namespace USBSTS

// USB2 Interrupt Enable Register
namespace USBINTR {
constexpr USB2_Reg<&USB_Layout::USBINTR, 1, 25> TIE1;
constexpr USB2_Reg<&USB_Layout::USBINTR, 1, 24> TIE0;
constexpr USB2_Reg<&USB_Layout::USBINTR, 1, 19> UPIE;
constexpr USB2_Reg<&USB_Layout::USBINTR, 1, 18> UAIE;
constexpr USB2_Reg<&USB_Layout::USBINTR, 1, 16> NAKE;
constexpr USB2_Reg<&USB_Layout::USBINTR, 1, 10> ULPIE;
constexpr USB2_Reg<&USB_Layout::USBINTR, 1,  8> SLE;
constexpr USB2_Reg<&USB_Layout::USBINTR, 1,  7> SRE;
constexpr USB2_Reg<&USB_Layout::USBINTR, 1,  6> URE;
constexpr USB2_Reg<&USB_Layout::USBINTR, 1,  5> AAE;
constexpr USB2_Reg<&USB_Layout::USBINTR, 1,  4> SEE;
constexpr USB2_Reg<&USB_Layout::USBINTR, 1,  3> FRE;
constexpr USB2_Reg<&USB_Layout::USBINTR, 1,  2> PCE;
constexpr USB2_Reg<&USB_Layout::USBINTR, 1,  1> UEE;
constexpr USB2_Reg<&USB_Layout::USBINTR, 1,  0> UE;
}  // namespace USBINTR

// USB2 USB Frame Index
namespace FRINDEX {
constexpr USB2_Reg<&USB_Layout::FRINDEX, 14, 0> FRINDEX;
}  // namespace FRINDEX

// USB2 Device Address
namespace DEVICEADDR {
constexpr USB2_Reg<&USB_Layout::DEVICEADDR, 7, 25> USBADR;
constexpr USB2_Reg<&USB_Layout::DEVICEADDR, 1, 24> USBADRA;
}  // namespace DEVICEADDR

// USB2 Frame List Base Address
namespace PERIODICLISTBASE {
constexpr USB2_Reg<&USB_Layout::PERIODICLISTBASE, 20, 12> BASEADR;
}  // namespace PERIODICLISTBASE

// USB2 Next Asynch. Address
namespace ASYNCLISTADDR {
constexpr USB2_Reg<&USB_Layout::ASYNCLISTADDR, 27, 5> ASYBASE;
}  // namespace ASYNCLISTADDR

// USB2 Endpoint List Address
namespace ENDPTLISTADDR {
constexpr USB2_Reg<&USB_Layout::ENDPTLISTADDR, 21, 11> EPBASE;
}  // namespace ENDPTLISTADDR

// USB2 Programmable Burst Size
namespace BURSTSIZE {
constexpr USB2_Reg<&USB_Layout::BURSTSIZE, 9, 8> TXPBURST;
constexpr USB2_Reg<&USB_Layout::BURSTSIZE, 8, 0> RXPBURST;
}  // namespace BURSTSIZE

// USB2 TX FIFO Fill Tuning
namespace TXFILLTUNING {
constexpr USB2_Reg<&USB_Layout::TXFILLTUNING, 6, 16> TXFIFOTHRES;
constexpr USB2_Reg<&USB_Layout::TXFILLTUNING, 5,  8> TXSCHHEALTH;
constexpr USB2_Reg<&USB_Layout::TXFILLTUNING, 8,  0> TXSCHOH;
}  // namespace TXFILLTUNING

// USB2 Endpoint NAK
namespace ENDPTNAK {
constexpr USB2_Reg<&USB_Layout::ENDPTNAK, 8, 16> EPTN;
constexpr USB2_Reg<&USB_Layout::ENDPTNAK, 8,  0> EPRN;
}  // namespace ENDPTNAK

// USB2 Endpoint NAK Enable
namespace ENDPTNAKEN {
constexpr USB2_Reg<&USB_Layout::ENDPTNAKEN, 8, 16> EPTNE;
constexpr USB2_Reg<&USB_Layout::ENDPTNAKEN, 8,  0> EPRNE;
}  // namespace ENDPTNAKEN

// USB2 Configure Flag Register
namespace CONFIGFLAG {
constexpr USB2_Reg<&USB_Layout::CONFIGFLAG, 1, 0> CF;
}  // namespace CONFIGFLAG

// USB2 Port Status & Control
namespace PORTSC1 {
constexpr USB2_Reg<&USB_Layout::PORTSC1, 2, 30> PTS_1;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 29> STS;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 28> PTW;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 2, 26> PSPD;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 25> PTS_2;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 24> PFSC;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 23> PHCD;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 22> WKOC;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 21> WKDC;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 20> WKCN;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 4, 16> PTC;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 2, 14> PIC;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 13> PO;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 12> PP;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 2, 10> LS;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  9> HSP;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  8> PR;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  7> SUSP;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  6> FPR;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  5> OCC;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  4> OCA;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  3> PEC;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  2> PE;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  1> CSC;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  0> CCS;
}  // namespace PORTSC1

// USB2 On-The-Go Status & control
namespace OTGSC {
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 30> DPIE;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 29> EN_1MS;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 28> BSEIE;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 27> BSVIE;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 26> ASVIE;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 25> AVVIE;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 24> IDIE;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 22> DPIS;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 21> STATUS_1MS;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 20> BSEIS;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 19> BSVIS;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 18> ASVIS;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 17> AVVIS;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 16> IDIS;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 14> DPS;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 13> TOG_1MS;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 12> BSE;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 11> BSV;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 10> ASV;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1,  9> AVV;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1,  8> ID;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1,  5> IDPU;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1,  4> DP;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1,  3> OT;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1,  1> VC;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1,  0> VD;
}  // namespace OTGSC

// USB2 USB Device Mode
namespace USBMODE {
constexpr USB2_Reg<&USB_Layout::USBMODE, 1, 4> SDIS;
constexpr USB2_Reg<&USB_Layout::USBMODE, 1, 3> SLOM;
constexpr USB2_Reg<&USB_Layout::USBMODE, 1, 2> ES;
constexpr USB2_Reg<&USB_Layout::USBMODE, 2, 0> CM;
}  // namespace USBMODE

// USB2 Endpoint Setup Status
namespace ENDPTSETUPSTAT {
constexpr USB2_Reg<&USB_Layout::ENDPTSETUPSTAT, 16, 0> ENDPTSETUPSTAT;
}  // namespace ENDPTSETUPSTAT

// USB2 Endpoint Prime
namespace ENDPTPRIME {
constexpr USB2_Reg<&USB_Layout::ENDPTPRIME, 8, 16> PETB;
constexpr USB2_Reg<&USB_Layout::ENDPTPRIME, 8,  0> PERB;
}  // namespace ENDPTPRIME

// USB2 Endpoint Flush
namespace ENDPTFLUSH {
constexpr USB2_Reg<&USB_Layout::ENDPTFLUSH, 8, 16> FETB;
constexpr USB2_Reg<&USB_Layout::ENDPTFLUSH, 8,  0> FERB;
}  // namespace ENDPTFLUSH

// USB2 Endpoint Status
namespace ENDPTSTAT {
constexpr USB2_Reg<&USB_Layout::ENDPTSTAT, 8, 16> ETBR;
constexpr USB2_Reg<&USB_Layout::ENDPTSTAT, 8,  0> ERBR;
}  // namespace ENDPTSTAT

// USB2 Endpoint Complete
namespace ENDPTCOMPLETE {
constexpr USB2_Reg<&USB_Layout::ENDPTCOMPLETE, 8, 16> ETCE;
constexpr USB2_Reg<&USB_Layout::ENDPTCOMPLETE, 8,  0> ERCE;
}  // namespace ENDPTCOMPLETE

}  // namespace USB2

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
