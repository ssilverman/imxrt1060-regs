// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// USB.h defines all the USB registers.
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
constexpr size_t kUSB_ENDPTCTRL_count = 8;

// Structure type to access the Universal Serial Bus Controller (USB) registers.
//
// Comments are from BSD-3-licensed NXP SDK.
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
constexpr uintptr_t kUSB1_base = 0x402E'0000;
constexpr uintptr_t kUSB2_base = 0x402E'0200;

namespace USB1 {
constexpr regs::RegGroup<USB_Layout, kUSB_size, kUSB1_base> group;
}  // namespace USB1

namespace USB2 {
constexpr regs::RegGroup<USB_Layout, kUSB_size, kUSB2_base> group;
}  // namespace USB2

namespace USB1 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using USB1_Reg =
    regs::Reg32<kUSB1_base, USB_Layout, Member, 0, Bits, Shift, AssignMask>;

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask8<Bits, Shift>()>
using USB1_Reg8 =
    regs::Reg8<kUSB1_base, USB_Layout, Member, 0, Bits, Shift, AssignMask>;

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask16<Bits, Shift>()>
using USB1_Reg16 =
    regs::Reg16<kUSB1_base, USB_Layout, Member, 0, Bits, Shift, AssignMask>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>(),
          typename = std::enable_if_t<(Index < kUSB_ENDPTCTRL_count)>>
using ENDPTCTRL_Reg =
    regs::Reg32<kUSB1_base, USB_Layout, &USB_Layout::ENDPTCTRL, Index, Bits,
                Shift, AssignMask>;

// USB1 Identification register
namespace ID {
constexpr USB1_Reg<&USB_Layout::ID, 8, 16> REVISION;  // Revision number of the controller core.
constexpr USB1_Reg<&USB_Layout::ID, 6,  8> NID;       // Complement version of ID
constexpr USB1_Reg<&USB_Layout::ID, 6,  0> ID;        // Configuration number
}  // namespace ID

// USB1 Hardware General
namespace HWGENERAL {
constexpr USB1_Reg<&USB_Layout::HWGENERAL, 2, 9> SM;    // Serial interface mode capability
    // 0b00..No Serial Engine, always use parallel signalling.
    // 0b01..Serial Engine present, always use serial signalling for FS/LS.
    // 0b10..Software programmable - Reset to use parallel signalling for FS/LS
    // 0b11..Software programmable - Reset to use serial signalling for FS/LS
constexpr USB1_Reg<&USB_Layout::HWGENERAL, 3, 6> PHYM;  // Transciever type
    // 0b000..UTMI/UMTI+
    // 0b001..ULPI DDR
    // 0b010..ULPI
    // 0b011..Serial Only
    // 0b100..Software programmable - reset to UTMI/UTMI+
    // 0b101..Software programmable - reset to ULPI DDR
    // 0b110..Software programmable - reset to ULPI
    // 0b111..Software programmable - reset to Serial
constexpr USB1_Reg<&USB_Layout::HWGENERAL, 2, 4> PHYW;  // Data width of the transciever connected to the controller core.
    // PHYW bit reset value is
    // 0b00..8 bit wide data bus Software non-programmable
    // 0b01..16 bit wide data bus Software non-programmable
    // 0b10..Reset to 8 bit wide data bus Software programmable
    // 0b11..Reset to 16 bit wide data bus Software programmable
}  // namespace HWGENERAL

// USB1 Host Hardware Parameters
namespace HWHOST {
constexpr USB1_Reg<&USB_Layout::HWHOST, 3, 1> NPORT;  // The Nmber of downstream ports supported by the host controller is (NPORT+1)
constexpr USB1_Reg<&USB_Layout::HWHOST, 1, 0> HC;     // Host Capable.
    // Indicating whether host operation mode is supported or not.
    // 0b0..Not supported
    // 0b1..Supported
}  // namespace HWHOST

// USB1 Device Hardware Parameters
namespace HWDEVICE {
constexpr USB1_Reg<&USB_Layout::HWDEVICE, 5, 1> DEVEP;  // Device Endpoint Number
constexpr USB1_Reg<&USB_Layout::HWDEVICE, 1, 0> DC;     // Device Capable.
    // Indicating whether device operation mode is supported or not.
    // 0b0..Not supported
    // 0b1..Supported
}  // namespace HWDEVICE

// USB1 TX Buffer Hardware Parameters
namespace HWTXBUF {
constexpr USB1_Reg<&USB_Layout::HWTXBUF, 8, 16> TXCHANADD;  // TX FIFO Buffer size is: (2^TXCHANADD) * 4 Bytes
constexpr USB1_Reg<&USB_Layout::HWTXBUF, 8,  0> TXBURST;    // Default burst size for memory to TX buffer transfer
}  // namespace HWTXBUF

// USB1 RX Buffer Hardware Parameters
namespace HWRXBUF {
constexpr USB1_Reg<&USB_Layout::HWRXBUF, 8, 8> RXADD;    // Buffer total size for all receive endpoints is (2^RXADD)
constexpr USB1_Reg<&USB_Layout::HWRXBUF, 8, 0> RXBURST;  // Default burst size for memory to RX buffer transfer
}  // namespace HWRXBUF

// USB1 General Purpose Timer #0 Load
namespace GPTIMER0LD {
constexpr USB1_Reg<&USB_Layout::GPTIMER0LD, 24, 0> GPTLD;  // General Purpose Timer Load Value
    // These bit fields are loaded to GPTCNT bits when GPTRST bit is set '1b'
}  // namespace GPTIMER0LD

// USB1 General Purpose Timer #0 Controller
namespace GPTIMER0CTRL {
constexpr USB1_Reg<&USB_Layout::GPTIMER0CTRL,  1, 31> GPTRUN;   // General Purpose Timer Run
    // GPTCNT bits are not effected when setting or clearing this bit.
    // 0b0..Stop counting
    // 0b1..Run
constexpr USB1_Reg<&USB_Layout::GPTIMER0CTRL,  1, 30> GPTRST;   // General Purpose Timer Reset
    // 0b0..No action
    // 0b1..Load counter value from GPTLD bits in n_GPTIMER0LD
constexpr USB1_Reg<&USB_Layout::GPTIMER0CTRL,  1, 24> GPTMODE;  // General Purpose Timer Mode
    // In one shot mode, the timer will count down to zero, generate an interrupt, and stop until the counter is reset by software; In repeat mode, the timer will count down to zero, generate an interrupt and automatically reload the counter value from GPTLD bits to start again
    // 0b0..One Shot Mode
    // 0b1..Repeat Mode
constexpr USB1_Reg<&USB_Layout::GPTIMER0CTRL, 24,  0> GPTCNT;   // General Purpose Timer Counter.
    // This field is the count value of the countdown timer.
}  // namespace GPTIMER0CTRL

// USB1 General Purpose Timer #1 Load
namespace GPTIMER1LD {
constexpr USB1_Reg<&USB_Layout::GPTIMER1LD, 24,  0> GPTLD;  // General Purpose Timer Load Value
    // These bit fields are loaded to GPTCNT bits when GPTRST bit is set '1b'
}  // namespace GPTIMER1LD

// USB1 General Purpose Timer #1 Controller
namespace GPTIMER1CTRL {
constexpr USB1_Reg<&USB_Layout::GPTIMER1CTRL,  1, 31> GPTRUN;   // General Purpose Timer Run
    // GPTCNT bits are not effected when setting or clearing this bit.
    // 0b0..Stop counting
    // 0b1..Run
constexpr USB1_Reg<&USB_Layout::GPTIMER1CTRL,  1, 30> GPTRST;   // General Purpose Timer Reset
    // 0b0..No action
    // 0b1..Load counter value from GPTLD bits in USB_n_GPTIMER0LD
constexpr USB1_Reg<&USB_Layout::GPTIMER1CTRL,  1, 24> GPTMODE;  // General Purpose Timer Mode
    // In one shot mode, the timer will count down to zero, generate an interrupt, and stop until the counter is reset by software
    // 0b0..One Shot Mode
    // 0b1..Repeat Mode
constexpr USB1_Reg<&USB_Layout::GPTIMER1CTRL, 24,  0> GPTCNT;   // General Purpose Timer Counter.
    // This field is the count value of the countdown timer.
}  // namespace GPTIMER1CTRL

// USB1 System Bus Config
namespace SBUSCFG {
constexpr USB1_Reg<&USB_Layout::SBUSCFG, 3, 0> AHBBRST;  // AHB master interface Burst configuration
    // These bits control AHB master transfer type sequence (or priority)
    // 0b000..Incremental burst of unspecified length only
    // 0b001..INCR4 burst, then single transfer
    // 0b010..INCR8 burst, INCR4 burst, then single transfer
    // 0b011..INCR16 burst, INCR8 burst, INCR4 burst, then single transfer
    // 0b100..Reserved, don't use
    // 0b101..INCR4 burst, then incremental burst of unspecified length
    // 0b110..INCR8 burst, INCR4 burst, then incremental burst of unspecified length
    // 0b111..INCR16 burst, INCR8 burst, INCR4 burst, then incremental burst of unspecified length
}  // namespace SBUSCFG

// USB1 Capability Registers Length
namespace CAPLENGTH {
constexpr USB1_Reg8<&USB_Layout::CAPLENGTH, 8, 0> CAPLENGTH;  // These bits are used as an offset to add to register base to find the beginning of the Operational Register
}  // namespace CAPLENGTH

// USB1 Host Controller Interface Version
namespace HCIVERSION {
constexpr USB1_Reg16<&USB_Layout::HCIVERSION, 16, 0> HCIVERSION;  // Host Controller Interface Version Number
    // Default value is '10h', which means EHCI rev1.0.
}  // namespace HCIVERSION

// USB1 Host Controller Structural Parameters
namespace HCSPARAMS {
constexpr USB1_Reg<&USB_Layout::HCSPARAMS, 4, 24> N_TT;     // Number of Transaction Translators (N_TT)
constexpr USB1_Reg<&USB_Layout::HCSPARAMS, 4, 20> N_PTT;    // Number of Ports per Transaction Translator (N_PTT)
constexpr USB1_Reg<&USB_Layout::HCSPARAMS, 1, 16> PI;       // Port Indicators (P INDICATOR)
    // This bit indicates whether the ports support port indicator control
constexpr USB1_Reg<&USB_Layout::HCSPARAMS, 4, 12> N_CC;     // Number of Companion Controller (N_CC)
    // 0b0000..There is no internal Companion Controller and port-ownership hand-off is not supported.
    // 0b0001..There are internal companion controller(s) and port-ownership hand-offs is supported.
constexpr USB1_Reg<&USB_Layout::HCSPARAMS, 4,  8> N_PCC;    // Number of Ports per Companion Controller
    // This field indicates the number of ports supported per internal Companion Controller
constexpr USB1_Reg<&USB_Layout::HCSPARAMS, 1,  4> PPC;      // Port Power Control
    // This field indicates whether the host controller implementation includes port power control
constexpr USB1_Reg<&USB_Layout::HCSPARAMS, 4,  0> N_PORTS;  // Number of downstream ports
}  // namespace HCSPARAMS

// USB1 Host Controller Capability Parameters
namespace HCCPARAMS {
constexpr USB1_Reg<&USB_Layout::HCCPARAMS, 8, 8> EECP;  // EHCI Extended Capabilities Pointer
constexpr USB1_Reg<&USB_Layout::HCCPARAMS, 4, 4> IST;   // Isochronous Scheduling Threshold
constexpr USB1_Reg<&USB_Layout::HCCPARAMS, 1, 2> ASP;   // Asynchronous Schedule Park Capability
    // If this bit is set to a one, then the host controller supports the park feature for high-speed queue heads in the Asynchronous Schedule
constexpr USB1_Reg<&USB_Layout::HCCPARAMS, 1, 1> PFL;   // Programmable Frame List Flag
    // If this bit is set to zero, then the system software must use a frame list length of 1024 elements with this host controller
constexpr USB1_Reg<&USB_Layout::HCCPARAMS, 1, 0> ADC;   // 64-bit Addressing Capability
    // This bit is set '0b' in all controller core, no 64-bit addressing capability is supported
}  // namespace HCCPARAMS

// USB1 Device Controller Interface Version
namespace DCIVERSION {
constexpr USB1_Reg16<&USB_Layout::DCIVERSION, 16, 0> DCIVERSION;  // Device Controller Interface Version Number
    // Default value is '01h', which means rev0.1.
}  // namespace DCIVERSION

// USB1 Device Controller Capability Parameters
namespace DCCPARAMS {
constexpr USB1_Reg<&USB_Layout::DCCPARAMS, 1, 8> HC;   // Host Capable
    // When this bit is 1, this controller is capable of operating as an EHCI compatible USB 2
constexpr USB1_Reg<&USB_Layout::DCCPARAMS, 1, 7> DC;   // Device Capable
    // When this bit is 1, this controller is capable of operating as a USB 2.0 device.
constexpr USB1_Reg<&USB_Layout::DCCPARAMS, 5, 0> DEN;  // Device Endpoint Number
    // This field indicates the number of endpoints built into the device controller
}  // namespace DCCPARAMS

// USB1 USB Command Register
namespace USBCMD {
constexpr USB1_Reg<&USB_Layout::USBCMD, 8, 16> ITC;    // Interrupt Threshold Control -Read/Write
    // 0b00000000..Immediate (no threshold)
    // 0b00000001..1 micro-frame
    // 0b00000010..2 micro-frames
    // 0b00000100..4 micro-frames
    // 0b00001000..8 micro-frames
    // 0b00010000..16 micro-frames
    // 0b00100000..32 micro-frames
    // 0b01000000..64 micro-frames
constexpr USB1_Reg<&USB_Layout::USBCMD, 1, 15> FS_2;   // Frame List Size - (Read/Write or Read Only)
    // 0b0..1024 elements (4096 bytes) Default value
    // 0b1..512 elements (2048 bytes)
constexpr USB1_Reg<&USB_Layout::USBCMD, 1, 14> ATDTW;  // Add dTD TripWire - Read/Write
constexpr USB1_Reg<&USB_Layout::USBCMD, 1, 13> SUTW;   // Setup TripWire - Read/Write
constexpr USB1_Reg<&USB_Layout::USBCMD, 1, 11> ASPE;   // Asynchronous Schedule Park Mode Enable - Read/Write
constexpr USB1_Reg<&USB_Layout::USBCMD, 2,  8> ASP;    // Asynchronous Schedule Park Mode Count - Read/Write
constexpr USB1_Reg<&USB_Layout::USBCMD, 1,  6> IAA;    // Interrupt on Async Advance Doorbell - Read/Write
constexpr USB1_Reg<&USB_Layout::USBCMD, 1,  5> ASE;    // Asynchronous Schedule Enable - Read/Write
    // 0b0..Do not process the Asynchronous Schedule.
    // 0b1..Use the ASYNCLISTADDR register to access the Asynchronous Schedule.
constexpr USB1_Reg<&USB_Layout::USBCMD, 1,  4> PSE;    // Periodic Schedule Enable- Read/Write
    // 0b0..Do not process the Periodic Schedule
    // 0b1..Use the PERIODICLISTBASE register to access the Periodic Schedule.
constexpr USB1_Reg<&USB_Layout::USBCMD, 2,  2> FS_1;   // See description at bit 15
constexpr USB1_Reg<&USB_Layout::USBCMD, 1,  1> RST;    // Controller Reset (RESET) - Read/Write
constexpr USB1_Reg<&USB_Layout::USBCMD, 1,  0> RS;     // Run/Stop (RS) - Read/Write
}  // namespace USBCMD

// USB1 USB Status Register
namespace USBSTS {
constexpr USB1_Reg<&USB_Layout::USBSTS, 1, 25, 0x0> TI1;              // General Purpose Timer Interrupt 1(GPTINT1)--R/WC
constexpr USB1_Reg<&USB_Layout::USBSTS, 1, 24, 0x0> TI0;              // General Purpose Timer Interrupt 0(GPTINT0)--R/WC
constexpr USB1_Reg<regs::constify(&USB_Layout::USBSTS), 1, 16> NAKI;  // NAK Interrupt Bit--RO
constexpr USB1_Reg<regs::constify(&USB_Layout::USBSTS), 1, 15> AS;    // Asynchronous Schedule Status - Read Only
constexpr USB1_Reg<regs::constify(&USB_Layout::USBSTS), 1, 14> PS;    // Periodic Schedule Status - Read Only
constexpr USB1_Reg<regs::constify(&USB_Layout::USBSTS), 1, 13> RCL;   // Reclamation - Read Only
constexpr USB1_Reg<regs::constify(&USB_Layout::USBSTS), 1, 12> HCH;   // HCHaIted - Read Only
constexpr USB1_Reg<&USB_Layout::USBSTS, 1, 10, 0x0> ULPII;            // ULPI Interrupt - R/WC
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  8, 0x0> SLI;              // DCSuspend - R/WC
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  7, 0x0> SRI;              // SOF Received - R/WC
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  6, 0x0> URI;              // USB Reset Received - R/WC
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  5, 0x0> AAI;              // Interrupt on Async Advance - R/WC
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  4, 0x0> SEI;              // System Error- R/WC
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  3, 0x0> FRI;              // Frame List Rollover - R/WC
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  2, 0x0> PCI;              // Port Change Detect - R/WC
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  1, 0x0> UEI;              // USB Error Interrupt (USBERRINT) - R/WC
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  0, 0x0> UI;               // USB Interrupt (USBINT) - R/WC
}  // namespace USBSTS

// USB1 Interrupt Enable Register
namespace USBINTR {
constexpr USB1_Reg<&USB_Layout::USBINTR, 1, 25> TIE1;   // General Purpose Timer #1 Interrupt Enable
    // When this bit is one and the TI1 bit in n_USBSTS register is a one the controller will issue an interrupt
constexpr USB1_Reg<&USB_Layout::USBINTR, 1, 24> TIE0;   // General Purpose Timer #0 Interrupt Enable
    // When this bit is one and the TI0 bit in n_USBSTS register is a one the controller will issue an interrupt
constexpr USB1_Reg<&USB_Layout::USBINTR, 1, 19> UPIE;   // USB Host Periodic Interrupt Enable
    // When this bit is one, and the UPI bit in the n_USBSTS register is one, host controller will issue an interrupt at the next interrupt threshold
constexpr USB1_Reg<&USB_Layout::USBINTR, 1, 18> UAIE;   // USB Host Asynchronous Interrupt Enable
    // When this bit is one, and the UAI bit in the n_USBSTS register is one, host controller will issue an interrupt at the next interrupt threshold
constexpr USB1_Reg<&USB_Layout::USBINTR, 1, 16> NAKE;   // NAK Interrupt Enable
    // When this bit is one and the NAKI bit in n_USBSTS register is a one the controller will issue an interrupt
constexpr USB1_Reg<&USB_Layout::USBINTR, 1, 10> ULPIE;  // ULPI Interrupt Enable
    // When this bit is one and the UPLII bit in n_USBSTS register is a one the controller will issue an interrupt
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  8> SLE;    // Sleep Interrupt Enable
    // When this bit is one and the SLI bit in n_n_USBSTS register is a one the controller will issue an interrupt
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  7> SRE;    // SOF Received Interrupt Enable
    // When this bit is one and the SRI bit in n_USBSTS register is a one the controller will issue an interrupt
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  6> URE;    // USB Reset Interrupt Enable
    // When this bit is one and the URI bit in n_USBSTS register is a one the controller will issue an interrupt
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  5> AAE;    // Async Advance Interrupt Enable
    // When this bit is one and the AAI bit in n_USBSTS register is a one the controller will issue an interrupt
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  4> SEE;    // System Error Interrupt Enable
    // When this bit is one and the SEI bit in n_USBSTS register is a one the controller will issue an interrupt
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  3> FRE;    // Frame List Rollover Interrupt Enable
    // When this bit is one and the FRI bit in n_USBSTS register is a one the controller will issue an interrupt
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  2> PCE;    // Port Change Detect Interrupt Enable
    // When this bit is one and the PCI bit in n_USBSTS register is a one the controller will issue an interrupt
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  1> UEE;    // USB Error Interrupt Enable
    // When this bit is one and the UEI bit in n_USBSTS register is a one the controller will issue an interrupt
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  0> UE;     // USB Interrupt Enable
    // When this bit is one and the UI bit in n_USBSTS register is a one the controller will issue an interrupt
}  // namespace USBINTR

// USB1 USB Frame Index
namespace FRINDEX {
constexpr USB1_Reg<&USB_Layout::FRINDEX, 14, 0> FRINDEX;  // Frame Index
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
constexpr USB1_Reg<&USB_Layout::DEVICEADDR, 7, 25> USBADR;   // Device Address.
    // These bits correspond to the USB device address
constexpr USB1_Reg<&USB_Layout::DEVICEADDR, 1, 24> USBADRA;  // Device Address Advance
}  // namespace DEVICEADDR

// USB1 Frame List Base Address
namespace PERIODICLISTBASE {
constexpr USB1_Reg<&USB_Layout::PERIODICLISTBASE, 20, 12> BASEADR;  // Base Address (Low)
}  // namespace PERIODICLISTBASE

// USB1 Next Asynch. Address
namespace ASYNCLISTADDR {
constexpr USB1_Reg<&USB_Layout::ASYNCLISTADDR, 27, 5> ASYBASE;  // Link Pointer Low (LPL)
}  // namespace ASYNCLISTADDR

// USB1 Endpoint List Address
namespace ENDPTLISTADDR {
constexpr USB1_Reg<&USB_Layout::ENDPTLISTADDR, 21, 11> EPBASE;  // Endpoint List Pointer(Low)
}  // namespace ENDPTLISTADDR

// USB1 Programmable Burst Size
namespace BURSTSIZE {
constexpr USB1_Reg<&USB_Layout::BURSTSIZE, 9, 8> TXPBURST;  // Programmable TX Burst Size
constexpr USB1_Reg<&USB_Layout::BURSTSIZE, 8, 0> RXPBURST;  // Programmable RX Burst Size
}  // namespace BURSTSIZE

// USB1 TX FIFO Fill Tuning
namespace TXFILLTUNING {
constexpr USB1_Reg<&USB_Layout::TXFILLTUNING, 6, 16> TXFIFOTHRES;  // FIFO Burst Threshold
constexpr USB1_Reg<&USB_Layout::TXFILLTUNING, 5,  8> TXSCHHEALTH;  // Scheduler Health Counter
constexpr USB1_Reg<&USB_Layout::TXFILLTUNING, 8,  0> TXSCHOH;      // Scheduler Overhead
}  // namespace TXFILLTUNING

// USB1 Endpoint NAK
namespace ENDPTNAK {
constexpr USB1_Reg<&USB_Layout::ENDPTNAK, 8, 16, 0x0> EPTN;  // TX Endpoint NAK - R/WC
constexpr USB1_Reg<&USB_Layout::ENDPTNAK, 8,  0, 0x0> EPRN;  // RX Endpoint NAK - R/WC
}  // namespace ENDPTNAK

// USB1 Endpoint NAK Enable
namespace ENDPTNAKEN {
constexpr USB1_Reg<&USB_Layout::ENDPTNAKEN, 8, 16> EPTNE;  // TX Endpoint NAK Enable - R/W
constexpr USB1_Reg<&USB_Layout::ENDPTNAKEN, 8,  0> EPRNE;  // RX Endpoint NAK Enable - R/W
}  // namespace ENDPTNAKEN

// USB1 Configure Flag Register
namespace CONFIGFLAG {
constexpr USB1_Reg<&USB_Layout::CONFIGFLAG, 1, 0> CF;  // Configure Flag
    // Host software sets this bit as the last action in its process of configuring the Host Controller
    // 0b0..Port routing control logic default-routes each port to an implementation dependent classic host controller.
    // 0b1..Port routing control logic default-routes all ports to this host controller.
}  // namespace CONFIGFLAG

// USB1 Port Status & Control
// Caution when writing to this register: Direct W1C assignment can zero
// ordinary RW fields; read-modify-write can clear unrelated W1C flags.
namespace PORTSC1 {
constexpr uint32_t kW1C = 0x0000'002a;

constexpr USB1_Reg<&USB_Layout::PORTSC1, 2, 30, regs::shiftedMask32<2, 30>() | kW1C> PTS_1;  // All USB port interface modes are listed in this field description, but not all are supported
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 29, regs::shiftedMask32<1, 29>() | kW1C> STS;    // Serial Transceiver Select
    // 1 Serial Interface Engine is selected
    // 0 Parallel Interface signals is selected
    // Serial Interface Engine can be used in combination with UTMI+/ULPI physical interface to provide FS/LS signaling instead of the parallel interface signals
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 28, regs::shiftedMask32<1, 28>() | kW1C> PTW;    // Parallel Transceiver Width
    // This bit has no effect if serial interface engine is used
    // 0b0..Select the 8-bit UTMI interface [60MHz]
    // 0b1..Select the 16-bit UTMI interface [30MHz]
constexpr USB1_Reg<regs::constify(&USB_Layout::PORTSC1), 2, 26> PSPD;                        // Port Speed - Read Only.
    // This register field indicates the speed at which the port is operating.
    // 0b00..Full Speed
    // 0b01..Low Speed
    // 0b10..High Speed
    // 0b11..Undefined
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 25, regs::shiftedMask32<1, 25>() | kW1C> PTS_2;  // See description at bits 31-30
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 24, regs::shiftedMask32<1, 24>() | kW1C> PFSC;   // Port Force Full Speed Connect - Read/Write
    // 0b0..Normal operation
    // 0b1..Forced to full speed
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 23, regs::shiftedMask32<1, 23>() | kW1C> PHCD;   // PHY Low Power Suspend - Clock Disable (PLPSCD) - Read/Write
    // 0b0..Enable PHY clock
    // 0b1..Disable PHY clock
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 22, regs::shiftedMask32<1, 22>() | kW1C> WKOC;   // Wake on Over-current Enable (WKOC_E) - Read/Write
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 21, regs::shiftedMask32<1, 21>() | kW1C> WKDC;   // Wake on Disconnect Enable (WKDSCNNT_E) - Read/Write
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 20, regs::shiftedMask32<1, 20>() | kW1C> WKCN;   // Wake on Connect Enable (WKCNNT_E) - Read/Write
constexpr USB1_Reg<&USB_Layout::PORTSC1, 4, 16, regs::shiftedMask32<4, 16>() | kW1C> PTC;    // Port Test Control - Read/Write
    // 0b0000..TEST_MODE_DISABLE
    // 0b0001..J_STATE
    // 0b0010..K_STATE
    // 0b0011..SE0 (host) / NAK (device)
    // 0b0100..Packet
    // 0b0101..FORCE_ENABLE_HS
    // 0b0110..FORCE_ENABLE_FS
    // 0b0111..FORCE_ENABLE_LS
    // 0b1000-0b1111..Reserved
constexpr USB1_Reg<&USB_Layout::PORTSC1, 2, 14, regs::shiftedMask32<2, 14>() | kW1C> PIC;    // Port Indicator Control - Read/Write
    // 0b00..Port indicators are off
    // 0b01..Amber
    // 0b10..Green
    // 0b11..Undefined
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 13, regs::shiftedMask32<1, 13>() | kW1C> PO;     // Port Owner-Read/Write
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 12, regs::shiftedMask32<1, 12>() | kW1C> PP;     // Port Power (PP)-Read/Write or Read Only
constexpr USB1_Reg<regs::constify(&USB_Layout::PORTSC1), 2, 10> LS;                          // Line Status-Read Only
    // 0b00..SE0
    // 0b01..K-state
    // 0b10..J-state
    // 0b11..Undefined
constexpr USB1_Reg<regs::constify(&USB_Layout::PORTSC1), 1,  9> HSP;                         // High-Speed Port - Read Only
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1,  8, regs::shiftedMask32<1,  8>() | kW1C> PR;     // Port Reset - Read/Write or Read Only
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1,  7, regs::shiftedMask32<1,  7>() | kW1C> SUSP;   // Suspend - Read/Write or Read Only
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1,  6, regs::shiftedMask32<1,  6>() | kW1C> FPR;    // Force Port Resume -Read/Write
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1,  5, kW1C> OCC;                                   // Over-current Change-R/WC
constexpr USB1_Reg<regs::constify(&USB_Layout::PORTSC1), 1,  4> OCA;                         // Over-current Active-Read Only
    // 0b0..This port does not have an over-current condition.
    // 0b1..This port currently has an over-current condition
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1,  3, kW1C> PEC;                                   // Port Enable/Disable Change-R/WC
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1,  2, regs::shiftedMask32<1,  2>() | kW1C> PE;     // Port Enabled/Disabled-Read/Write
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1,  1, kW1C> CSC;                                   // Connect Status Change-R/WC
constexpr USB1_Reg<regs::constify(&USB_Layout::PORTSC1), 1,  0> CCS;                         // Current Connect Status-Read Only
}  // namespace PORTSC1

// USB1 On-The-Go Status & control
// Caution when writing to this register: Direct W1C assignment can zero
// ordinary RW fields; read-modify-write can clear unrelated W1C flags.
namespace OTGSC {
constexpr uint32_t kW1C = 0x007f'0000;

constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 30, regs::shiftedMask32<1, 30>() | kW1C> DPIE;    // Data Pulse Interrupt Enable
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 29, regs::shiftedMask32<1, 29>() | kW1C> EN_1MS;  // 1 millisecond timer Interrupt Enable - Read/Write
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 28, regs::shiftedMask32<1, 28>() | kW1C> BSEIE;   // B Session End Interrupt Enable - Read/Write.
    // Setting this bit enables the B session end interrupt.
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 27, regs::shiftedMask32<1, 27>() | kW1C> BSVIE;   // B Session Valid Interrupt Enable - Read/Write
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 26, regs::shiftedMask32<1, 26>() | kW1C> ASVIE;   // A Session Valid Interrupt Enable - Read/Write
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 25, regs::shiftedMask32<1, 25>() | kW1C> AVVIE;   // A VBus Valid Interrupt Enable - Read/Write.
    // Setting this bit enables the A VBus valid interrupt.
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 24, regs::shiftedMask32<1, 24>() | kW1C> IDIE;    // USB ID Interrupt Enable - Read/Write.
    // Setting this bit enables the USB ID interrupt.
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 22, kW1C> DPIS;                                   // Data Pulse Interrupt Status - Read/Write to Clear
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 21, kW1C> STATUS_1MS;                             // 1 millisecond timer Interrupt Status - Read/Write to Clear
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 20, kW1C> BSEIS;                                  // B Session End Interrupt Status - Read/Write to Clear
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 19, kW1C> BSVIS;                                  // B Session Valid Interrupt Status - Read/Write to Clear
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 18, kW1C> ASVIS;                                  // A Session Valid Interrupt Status - Read/Write to Clear
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 17, kW1C> AVVIS;                                  // A VBus Valid Interrupt Status - Read/Write to Clear
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 16, kW1C> IDIS;                                   // USB ID Interrupt Status - Read/Write
constexpr USB1_Reg<regs::constify(&USB_Layout::OTGSC), 1, 14> DPS;                          // Data Bus Pulsing Status - Read Only
constexpr USB1_Reg<regs::constify(&USB_Layout::OTGSC), 1, 13> TOG_1MS;                      // 1 millisecond timer toggle - Read Only.
    // This bit toggles once per millisecond.
constexpr USB1_Reg<regs::constify(&USB_Layout::OTGSC), 1, 12> BSE;                          // B Session End - Read Only.
    // Indicates VBus is below the B session end threshold.
constexpr USB1_Reg<regs::constify(&USB_Layout::OTGSC), 1, 11> BSV;                          // B Session Valid - Read Only.
    // Indicates VBus is above the B session valid threshold.
constexpr USB1_Reg<regs::constify(&USB_Layout::OTGSC), 1, 10> ASV;                          // A Session Valid - Read Only.
    // Indicates VBus is above the A session valid threshold.
constexpr USB1_Reg<regs::constify(&USB_Layout::OTGSC), 1,  9> AVV;                          // A VBus Valid - Read Only.
    // Indicates VBus is above the A VBus valid threshold.
constexpr USB1_Reg<regs::constify(&USB_Layout::OTGSC), 1,  8> ID;                           // USB ID - Read Only.
    // 0 = A device,
    // 1 = B device
constexpr USB1_Reg<&USB_Layout::OTGSC, 1,  5, regs::shiftedMask32<1,  5>() | kW1C> IDPU;    // ID Pullup - Read/Write
    // This bit provide control over the ID pull-up resistor;
    // 0 = off,
    // 1 = on [default]
constexpr USB1_Reg<&USB_Layout::OTGSC, 1,  4, regs::shiftedMask32<1,  4>() | kW1C> DP;      // Data Pulsing - Read/Write
constexpr USB1_Reg<&USB_Layout::OTGSC, 1,  3, regs::shiftedMask32<1,  3>() | kW1C> OT;      // OTG Termination - Read/Write
constexpr USB1_Reg<&USB_Layout::OTGSC, 1,  1, regs::shiftedMask32<1,  1>() | kW1C> VC;      // VBUS Charge - Read/Write
constexpr USB1_Reg<&USB_Layout::OTGSC, 1,  0, regs::shiftedMask32<1,  0>() | kW1C> VD;      // VBUS_Discharge - Read/Write.
    // Setting this bit causes VBus to discharge through a resistor.
}  // namespace OTGSC

// USB1 USB Device Mode
namespace USBMODE {
constexpr USB1_Reg<&USB_Layout::USBMODE, 1, 4> SDIS;  // Stream Disable Mode
constexpr USB1_Reg<&USB_Layout::USBMODE, 1, 3> SLOM;  // Setup Lockout Mode
    // 0b0..Setup Lockouts On (default);
    // 0b1..Setup Lockouts Off (DCD requires use of Setup Data Buffer Tripwire in USBCMDUSB Command Register .
constexpr USB1_Reg<&USB_Layout::USBMODE, 1, 2> ES;    // Endian Select - Read/Write
    // 0b0..Little Endian [Default]
    // 0b1..Big Endian
constexpr USB1_Reg<&USB_Layout::USBMODE, 2, 0> CM;    // Controller Mode - R/WO
    // 0b00..Idle [Default for combination host/device]
    // 0b01..Reserved
    // 0b10..Device Controller [Default for device only controller]
    // 0b11..Host Controller [Default for host only controller]
}  // namespace USBMODE

// USB1 Endpoint Setup Status
namespace ENDPTSETUPSTAT {
constexpr USB1_Reg<&USB_Layout::ENDPTSETUPSTAT, 16, 0, 0x0> ENDPTSETUPSTAT;  // Setup Endpoint Status
}  // namespace ENDPTSETUPSTAT

// USB1 Endpoint Prime
namespace ENDPTPRIME {
constexpr USB1_Reg<&USB_Layout::ENDPTPRIME, 8, 16, 0x0> PETB;  // Prime Endpoint Transmit Buffer - R/WS
constexpr USB1_Reg<&USB_Layout::ENDPTPRIME, 8,  0, 0x0> PERB;  // Prime Endpoint Receive Buffer - R/WS
}  // namespace ENDPTPRIME

// USB1 Endpoint Flush
namespace ENDPTFLUSH {
constexpr USB1_Reg<&USB_Layout::ENDPTFLUSH, 8, 16, 0x0> FETB;  // Flush Endpoint Transmit Buffer - R/WS
constexpr USB1_Reg<&USB_Layout::ENDPTFLUSH, 8,  0, 0x0> FERB;  // Flush Endpoint Receive Buffer - R/WS
}  // namespace ENDPTFLUSH

// USB1 Endpoint Status
namespace ENDPTSTAT {
constexpr USB1_Reg<&USB_Layout::ENDPTSTAT, 8, 16> ETBR;  // Endpoint Transmit Buffer Ready -- Read Only
constexpr USB1_Reg<&USB_Layout::ENDPTSTAT, 8,  0> ERBR;  // Endpoint Receive Buffer Ready -- Read Only
}  // namespace ENDPTSTAT

// USB1 Endpoint Complete
namespace ENDPTCOMPLETE {
constexpr USB1_Reg<&USB_Layout::ENDPTCOMPLETE, 8, 16, 0x0> ETCE;  // Endpoint Transmit Complete Event - R/WC
constexpr USB1_Reg<&USB_Layout::ENDPTCOMPLETE, 8,  0, 0x0> ERCE;  // Endpoint Receive Complete Event - RW/C
}  // namespace ENDPTCOMPLETE

// Endpoint Control values
// Caution when writing to this register: Read-modify-write can replay the
// TXR/RXR write-one commands.
namespace ENDPTCTRL {
template <size_t Index>
constexpr ENDPTCTRL_Reg<Index, 1, 23> TXE;  // TX Endpoint Enable
    // 0 Disabled [Default]
    // 1 Enabled
    // An Endpoint should be enabled only after it has been configured
template <size_t Index, typename = std::enable_if_t<(Index != 0)>>
constexpr ENDPTCTRL_Reg<Index, 1, 22> TXR;  // TX Data Toggle Reset (WS)
    // Write 1 - Reset PID Sequence
    // Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PID's between the Host and device
    // Doesn't exist in ENDPTCTRL<0>
template <size_t Index, typename = std::enable_if_t<(Index != 0)>>
constexpr ENDPTCTRL_Reg<Index, 1, 21> TXI;  // TX Data Toggle Inhibit
    // 0 PID Sequencing Enabled
    // Doesn't exist in ENDPTCTRL<0>
template <size_t Index>
constexpr ENDPTCTRL_Reg<Index, 2, 18> TXT;  // TX Endpoint Type - Read/Write
    // 00 Control
    // 01 Isochronous
    // 10 Bulk
    // 11 Interrupt
template <size_t Index, typename = std::enable_if_t<(Index != 0)>>
constexpr ENDPTCTRL_Reg<Index, 1, 17> TXD;  // TX Endpoint Data Source - Read/Write
    // 0 Dual Port Memory Buffer/DMA Engine [DEFAULT]
    // Should always be written as 0
    // Doesn't exist in ENDPTCTRL<0>
template <size_t Index>
constexpr ENDPTCTRL_Reg<Index, 1, 16> TXS;  // TX Endpoint Stall - Read/Write
    // 0 End Point OK
    // 1 End Point Stalled
    // This bit will be cleared automatically upon receipt of a SETUP request if this Endpoint is configured as a Control Endpoint and this bit will continue to be cleared by hardware until the associated ENDPTSETUPSTAT bit is cleared
template <size_t Index>
constexpr ENDPTCTRL_Reg<Index, 1,  7> RXE;  // RX Endpoint Enable
    // 0 Disabled [Default]
    // 1 Enabled
    // An Endpoint should be enabled only after it has been configured
template <size_t Index, typename = std::enable_if_t<(Index != 0)>>
constexpr ENDPTCTRL_Reg<Index, 1,  6> RXR;  // RX Data Toggle Reset (WS)
    // Write 1 - Reset PID Sequence
    // Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PID's between the host and device
    // Doesn't exist in ENDPTCTRL<0>
template <size_t Index, typename = std::enable_if_t<(Index != 0)>>
constexpr ENDPTCTRL_Reg<Index, 1,  5> RXI;  // RX Data Toggle Inhibit
    // 0 Disabled [Default]
    // 1 Enabled
    // This bit is only used for test and should always be written as zero
    // Doesn't exist in ENDPTCTRL<0>
template <size_t Index>
constexpr ENDPTCTRL_Reg<Index, 2,  2> RXT;  // RX Endpoint Type - Read/Write
    // 00 Control
    // 01 Isochronous
    // 10 Bulk
    // 11 Interrupt
template <size_t Index, typename = std::enable_if_t<(Index != 0)>>
constexpr ENDPTCTRL_Reg<Index, 1, 1> RXD;   // RX Endpoint Data Sink - Read/Write
    // 0 Dual Port Memory Buffer/DMA Engine [Default]
    // Should always be written as zero
    // Doesn't exist in ENDPTCTRL<0>
template <size_t Index>
constexpr ENDPTCTRL_Reg<Index, 1,  0> RXS;  // RX Endpoint Stall - Read/Write
    // 0 End Point OK
}  // namespace ENDPTCTRL

}  // namespace USB1

namespace USB2 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using USB2_Reg =
    regs::Reg32<kUSB2_base, USB_Layout, Member, 0, Bits, Shift, AssignMask>;

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask8<Bits, Shift>()>
using USB2_Reg8 =
    regs::Reg8<kUSB2_base, USB_Layout, Member, 0, Bits, Shift, AssignMask>;

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask16<Bits, Shift>()>
using USB2_Reg16 =
    regs::Reg16<kUSB2_base, USB_Layout, Member, 0, Bits, Shift, AssignMask>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>(),
          typename = std::enable_if_t<(Index < kUSB_ENDPTCTRL_count)>>
using ENDPTCTRL_Reg =
    regs::Reg32<kUSB2_base, USB_Layout, &USB_Layout::ENDPTCTRL, Index, Bits,
                Shift, AssignMask>;

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

// USB2 Capability Registers Length
namespace CAPLENGTH {
constexpr USB2_Reg8<&USB_Layout::CAPLENGTH, 8, 0> CAPLENGTH;
}  // namespace CAPLENGTH

// USB2 Host Controller Interface Version
namespace HCIVERSION {
constexpr USB2_Reg16<&USB_Layout::HCIVERSION, 16, 0> HCIVERSION;
}  // namespace HCIVERSION

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

// USB2 Device Controller Interface Version
namespace DCIVERSION {
constexpr USB2_Reg16<&USB_Layout::DCIVERSION, 16, 0> DCIVERSION;
}  // namespace DCIVERSION

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
constexpr USB2_Reg<&USB_Layout::USBSTS, 1, 25, 0x0> TI1;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1, 24, 0x0> TI0;
constexpr USB2_Reg<regs::constify(&USB_Layout::USBSTS), 1, 16> NAKI;
constexpr USB2_Reg<regs::constify(&USB_Layout::USBSTS), 1, 15> AS;
constexpr USB2_Reg<regs::constify(&USB_Layout::USBSTS), 1, 14> PS;
constexpr USB2_Reg<regs::constify(&USB_Layout::USBSTS), 1, 13> RCL;
constexpr USB2_Reg<regs::constify(&USB_Layout::USBSTS), 1, 12> HCH;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1, 10, 0x0> ULPII;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  8, 0x0> SLI;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  7, 0x0> SRI;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  6, 0x0> URI;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  5, 0x0> AAI;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  4, 0x0> SEI;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  3, 0x0> FRI;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  2, 0x0> PCI;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  1, 0x0> UEI;
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  0, 0x0> UI;
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
constexpr USB2_Reg<&USB_Layout::ENDPTNAK, 8, 16, 0x0> EPTN;
constexpr USB2_Reg<&USB_Layout::ENDPTNAK, 8,  0, 0x0> EPRN;
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
// Caution when writing to this register: Direct W1C assignment can zero
// ordinary RW fields; read-modify-write can clear unrelated W1C flags.
namespace PORTSC1 {
constexpr uint32_t kW1C = 0x0000'002a;

constexpr USB2_Reg<&USB_Layout::PORTSC1, 2, 30, regs::shiftedMask32<2, 30>() | kW1C> PTS_1;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 29, regs::shiftedMask32<1, 29>() | kW1C> STS;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 28, regs::shiftedMask32<1, 28>() | kW1C> PTW;
constexpr USB2_Reg<regs::constify(&USB_Layout::PORTSC1), 2, 26> PSPD;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 25, regs::shiftedMask32<1, 25>() | kW1C> PTS_2;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 24, regs::shiftedMask32<1, 24>() | kW1C> PFSC;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 23, regs::shiftedMask32<1, 23>() | kW1C> PHCD;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 22, regs::shiftedMask32<1, 22>() | kW1C> WKOC;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 21, regs::shiftedMask32<1, 21>() | kW1C> WKDC;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 20, regs::shiftedMask32<1, 20>() | kW1C> WKCN;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 4, 16, regs::shiftedMask32<4, 16>() | kW1C> PTC;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 2, 14, regs::shiftedMask32<2, 14>() | kW1C> PIC;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 13, regs::shiftedMask32<1, 13>() | kW1C> PO;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 12, regs::shiftedMask32<1, 12>() | kW1C> PP;
constexpr USB2_Reg<regs::constify(&USB_Layout::PORTSC1), 2, 10> LS;
constexpr USB2_Reg<regs::constify(&USB_Layout::PORTSC1), 1,  9> HSP;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  8, regs::shiftedMask32<1,  8>() | kW1C> PR;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  7, regs::shiftedMask32<1,  7>() | kW1C> SUSP;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  6, regs::shiftedMask32<1,  6>() | kW1C> FPR;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  5, kW1C> OCC;
constexpr USB2_Reg<regs::constify(&USB_Layout::PORTSC1), 1,  4> OCA;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  3, kW1C> PEC;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  2, regs::shiftedMask32<1,  2>() | kW1C> PE;
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  1, kW1C> CSC;
constexpr USB2_Reg<regs::constify(&USB_Layout::PORTSC1), 1,  0> CCS;
}  // namespace PORTSC1

// USB2 On-The-Go Status & control
// Caution when writing to this register: Direct W1C assignment can zero
// ordinary RW fields; read-modify-write can clear unrelated W1C flags.
namespace OTGSC {
constexpr uint32_t kW1C = 0x007f'0000;

constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 30, regs::shiftedMask32<1, 30>() | kW1C> DPIE;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 29, regs::shiftedMask32<1, 29>() | kW1C> EN_1MS;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 28, regs::shiftedMask32<1, 28>() | kW1C> BSEIE;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 27, regs::shiftedMask32<1, 27>() | kW1C> BSVIE;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 26, regs::shiftedMask32<1, 26>() | kW1C> ASVIE;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 25, regs::shiftedMask32<1, 25>() | kW1C> AVVIE;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 24, regs::shiftedMask32<1, 24>() | kW1C> IDIE;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 22, kW1C> DPIS;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 21, kW1C> STATUS_1MS;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 20, kW1C> BSEIS;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 19, kW1C> BSVIS;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 18, kW1C> ASVIS;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 17, kW1C> AVVIS;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 16, kW1C> IDIS;
constexpr USB2_Reg<regs::constify(&USB_Layout::OTGSC), 1, 14> DPS;
constexpr USB2_Reg<regs::constify(&USB_Layout::OTGSC), 1, 13> TOG_1MS;
constexpr USB2_Reg<regs::constify(&USB_Layout::OTGSC), 1, 12> BSE;
constexpr USB2_Reg<regs::constify(&USB_Layout::OTGSC), 1, 11> BSV;
constexpr USB2_Reg<regs::constify(&USB_Layout::OTGSC), 1, 10> ASV;
constexpr USB2_Reg<regs::constify(&USB_Layout::OTGSC), 1,  9> AVV;
constexpr USB2_Reg<regs::constify(&USB_Layout::OTGSC), 1,  8> ID;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1,  5, regs::shiftedMask32<1,  5>() | kW1C> IDPU;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1,  4, regs::shiftedMask32<1,  4>() | kW1C> DP;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1,  3, regs::shiftedMask32<1,  3>() | kW1C> OT;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1,  1, regs::shiftedMask32<1,  1>() | kW1C> VC;
constexpr USB2_Reg<&USB_Layout::OTGSC, 1,  0, regs::shiftedMask32<1,  0>() | kW1C> VD;
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
constexpr USB2_Reg<&USB_Layout::ENDPTSETUPSTAT, 16, 0, 0x0> ENDPTSETUPSTAT;
}  // namespace ENDPTSETUPSTAT

// USB2 Endpoint Prime
namespace ENDPTPRIME {
constexpr USB2_Reg<&USB_Layout::ENDPTPRIME, 8, 16, 0x0> PETB;
constexpr USB2_Reg<&USB_Layout::ENDPTPRIME, 8,  0, 0x0> PERB;
}  // namespace ENDPTPRIME

// USB2 Endpoint Flush
namespace ENDPTFLUSH {
constexpr USB2_Reg<&USB_Layout::ENDPTFLUSH, 8, 16, 0x0> FETB;
constexpr USB2_Reg<&USB_Layout::ENDPTFLUSH, 8,  0, 0x0> FERB;
}  // namespace ENDPTFLUSH

// USB2 Endpoint Status
namespace ENDPTSTAT {
constexpr USB2_Reg<&USB_Layout::ENDPTSTAT, 8, 16> ETBR;
constexpr USB2_Reg<&USB_Layout::ENDPTSTAT, 8,  0> ERBR;
}  // namespace ENDPTSTAT

// USB2 Endpoint Complete
namespace ENDPTCOMPLETE {
constexpr USB2_Reg<&USB_Layout::ENDPTCOMPLETE, 8, 16, 0x0> ETCE;
constexpr USB2_Reg<&USB_Layout::ENDPTCOMPLETE, 8,  0, 0x0> ERCE;
}  // namespace ENDPTCOMPLETE

// Endpoint Control values
// Caution when writing to this register: Read-modify-write can replay the
// TXR/RXR write-one commands.
namespace ENDPTCTRL {
template <size_t Index>
constexpr ENDPTCTRL_Reg<Index, 1, 23> TXE;
template <size_t Index, typename = std::enable_if_t<(Index != 0)>>
constexpr ENDPTCTRL_Reg<Index, 1, 22> TXR;
    // Doesn't exist in ENDPTCTRL<0>
template <size_t Index, typename = std::enable_if_t<(Index != 0)>>
constexpr ENDPTCTRL_Reg<Index, 1, 21> TXI;
    // Doesn't exist in ENDPTCTRL<0>
template <size_t Index>
constexpr ENDPTCTRL_Reg<Index, 2, 18> TXT;
template <size_t Index, typename = std::enable_if_t<(Index != 0)>>
constexpr ENDPTCTRL_Reg<Index, 1, 17> TXD;
    // Doesn't exist in ENDPTCTRL<0>
template <size_t Index>
constexpr ENDPTCTRL_Reg<Index, 1, 16> TXS;
template <size_t Index>
constexpr ENDPTCTRL_Reg<Index, 1,  7> RXE;
template <size_t Index, typename = std::enable_if_t<(Index != 0)>>
constexpr ENDPTCTRL_Reg<Index, 1,  6> RXR;
    // Doesn't exist in ENDPTCTRL<0>
template <size_t Index, typename = std::enable_if_t<(Index != 0)>>
constexpr ENDPTCTRL_Reg<Index, 1,  5> RXI;
    // Doesn't exist in ENDPTCTRL<0>
template <size_t Index>
constexpr ENDPTCTRL_Reg<Index, 2,  2> RXT;
template <size_t Index, typename = std::enable_if_t<(Index != 0)>>
constexpr ENDPTCTRL_Reg<Index, 1, 1> RXD;
    // Doesn't exist in ENDPTCTRL<0>
template <size_t Index>
constexpr ENDPTCTRL_Reg<Index, 1,  0> RXS;
}  // namespace ENDPTCTRL

}  // namespace USB2

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
