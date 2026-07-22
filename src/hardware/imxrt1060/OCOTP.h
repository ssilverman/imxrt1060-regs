// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// SNVS.h defines all the SNVS registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// OCOTP layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_OCOTP.h
// * https://github.com/nxp-mcuxpresso/legacy-mcux-sdk/blob/main/devices/MIMXRT1062/MIMXRT1062.h

struct OCOTP_Layout {
  volatile uint32_t CTRL;                              /**< OTP Controller Control and Status Register, offset: 0x0 */
  volatile uint32_t CTRL_SET;                          /**< OTP Controller Control and Status Register, offset: 0x4 */
  volatile uint32_t CTRL_CLR;                          /**< OTP Controller Control and Status Register, offset: 0x8 */
  volatile uint32_t CTRL_TOG;                          /**< OTP Controller Control and Status Register, offset: 0xC */
  volatile uint32_t TIMING;                            /**< OTP Controller Timing Register, offset: 0x10 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t DATA;                              /**< OTP Controller Write Data Register, offset: 0x20 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t READ_CTRL;                         /**< OTP Controller Write Data Register, offset: 0x30 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t READ_FUSE_DATA;                    /**< OTP Controller Read Data Register, offset: 0x40 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SW_STICKY;                         /**< Sticky bit Register, offset: 0x50 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SCS;                               /**< Software Controllable Signals Register, offset: 0x60 */
  volatile uint32_t SCS_SET;                           /**< Software Controllable Signals Register, offset: 0x64 */
  volatile uint32_t SCS_CLR;                           /**< Software Controllable Signals Register, offset: 0x68 */
  volatile uint32_t SCS_TOG;                           /**< Software Controllable Signals Register, offset: 0x6C */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[8];
  const volatile uint32_t VERSION;                     /**< OTP Controller Version Register, offset: 0x90 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[27];
  volatile uint32_t TIMING2;                           /**< OTP Controller Timing Register 2, offset: 0x100 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[191];
  const volatile uint32_t LOCK;                        /**< Value of OTP Bank0 Word0 (Lock controls), offset: 0x400 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CFG0;                              /**< Value of OTP Bank0 Word1 (Configuration and Manufacturing Info.), offset: 0x410 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CFG1;                              /**< Value of OTP Bank0 Word2 (Configuration and Manufacturing Info.), offset: 0x420 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CFG2;                              /**< Value of OTP Bank0 Word3 (Configuration and Manufacturing Info.), offset: 0x430 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CFG3;                              /**< Value of OTP Bank0 Word4 (Configuration and Manufacturing Info.), offset: 0x440 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CFG4;                              /**< Value of OTP Bank0 Word5 (Configuration and Manufacturing Info.), offset: 0x450 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CFG5;                              /**< Value of OTP Bank0 Word6 (Configuration and Manufacturing Info.), offset: 0x460 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CFG6;                              /**< Value of OTP Bank0 Word7 (Configuration and Manufacturing Info.), offset: 0x470 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t MEM0;                              /**< Value of OTP Bank1 Word0 (Memory Related Info.), offset: 0x480 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t MEM1;                              /**< Value of OTP Bank1 Word1 (Memory Related Info.), offset: 0x490 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t MEM2;                              /**< Value of OTP Bank1 Word2 (Memory Related Info.), offset: 0x4A0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t MEM3;                              /**< Value of OTP Bank1 Word3 (Memory Related Info.), offset: 0x4B0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t MEM4;                              /**< Value of OTP Bank1 Word4 (Memory Related Info.), offset: 0x4C0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t ANA0;                              /**< Value of OTP Bank1 Word5 (Analog Info.), offset: 0x4D0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t ANA1;                              /**< Value of OTP Bank1 Word6 (Analog Info.), offset: 0x4E0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t ANA2;                              /**< Value of OTP Bank1 Word7 (Analog Info.), offset: 0x4F0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[35];
  volatile uint32_t SRK0;                              /**< Shadow Register for OTP Bank3 Word0 (SRK Hash), offset: 0x580 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SRK1;                              /**< Shadow Register for OTP Bank3 Word1 (SRK Hash), offset: 0x590 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SRK2;                              /**< Shadow Register for OTP Bank3 Word2 (SRK Hash), offset: 0x5A0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SRK3;                              /**< Shadow Register for OTP Bank3 Word3 (SRK Hash), offset: 0x5B0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SRK4;                              /**< Shadow Register for OTP Bank3 Word4 (SRK Hash), offset: 0x5C0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SRK5;                              /**< Shadow Register for OTP Bank3 Word5 (SRK Hash), offset: 0x5D0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SRK6;                              /**< Shadow Register for OTP Bank3 Word6 (SRK Hash), offset: 0x5E0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SRK7;                              /**< Shadow Register for OTP Bank3 Word7 (SRK Hash), offset: 0x5F0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SJC_RESP0;                         /**< Value of OTP Bank4 Word0 (Secure JTAG Response Field), offset: 0x600 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SJC_RESP1;                         /**< Value of OTP Bank4 Word1 (Secure JTAG Response Field), offset: 0x610 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t MAC0;                              /**< Value of OTP Bank4 Word2 (MAC Address), offset: 0x620 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t MAC1;                              /**< Value of OTP Bank4 Word3 (MAC Address), offset: 0x630 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t MAC2;                              /**< Value of OTP Bank4 Word4 (MAC2 Address), offset: 0x640 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[7];
  volatile uint32_t GP1;                               /**< Value of OTP Bank4 Word6 (General Purpose Customer Defined Info), offset: 0x660 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t GP2;                               /**< Value of OTP Bank4 Word7 (General Purpose Customer Defined Info), offset: 0x670 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SW_GP1;                            /**< Value of OTP Bank5 Word0 (SW GP1), offset: 0x680 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SW_GP20;                           /**< Value of OTP Bank5 Word1 (SW GP2), offset: 0x690 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SW_GP21;                           /**< Value of OTP Bank5 Word2 (SW GP2), offset: 0x6A0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SW_GP22;                           /**< Value of OTP Bank5 Word3 (SW GP2), offset: 0x6B0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SW_GP23;                           /**< Value of OTP Bank5 Word4 (SW GP2), offset: 0x6C0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t MISC_CONF0;                        /**< Value of OTP Bank5 Word5 (Misc Conf), offset: 0x6D0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t MISC_CONF1;                        /**< Value of OTP Bank5 Word6 (Misc Conf), offset: 0x6E0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SRK_REVOKE;                        /**< Value of OTP Bank5 Word7 (SRK Revoke), offset: 0x6F0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[99];
  volatile uint32_t GP30;                              /**< Value of OTP Bank7 Word0 (GP3), offset: 0x880 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t GP31;                              /**< Value of OTP Bank7 Word1 (GP3), offset: 0x890 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t GP32;                              /**< Value of OTP Bank7 Word2 (GP3), offset: 0x8A0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t GP33;                              /**< Value of OTP Bank7 Word3 (GP3), offset: 0x8B0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t GP40;                              /**< Value of OTP Bank7 Word4 (GP4), offset: 0x8C0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t GP41;                              /**< Value of OTP Bank7 Word5 (GP4), offset: 0x8D0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t GP42;                              /**< Value of OTP Bank7 Word6 (GP4), offset: 0x8E0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t GP43;                              /**< Value of OTP Bank7 Word7 (GP4), offset: 0x8F0 */
};

constexpr size_t    kOCOTP_size = 0x8F4;
constexpr uintptr_t kOCOTP_base = 0x401F4000;

namespace OCOTP {
constexpr regs::RegGroup<OCOTP_Layout, kOCOTP_size, kOCOTP_base> group;
}  // namespace OCOTP

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using OCOTP_Reg = regs::Reg32<kOCOTP_base, OCOTP_Layout, Member, 0, Bits, Shift,
                              DirectAssign>;

namespace OCOTP {

// OTP Controller Control and Status Register
namespace CTRL {
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL, 16, 16> WR_UNLOCK;       // Write Unlock
    // 0b0000000000000000..OTP write access is locked.
    // 0b0011111001110111..OTP write access is unlocked.
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL,  1, 10> RELOAD_SHADOWS;  // Reload Shadow Registers
    // 0b0..Do not force shadow register re-load.
    // 0b1..Force shadow register re-load. This bit is cleared automatically after shadow registers are re-loaded.
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL,  1,  9> ERROR;           // Locked Region Access Error
    // 0b0..No error.
    // 0b1..Error - access to a locked region requested.
constexpr OCOTP_Reg<constify(&OCOTP_Layout::CTRL),  1,  8> BUSY;            // OTP controller status bit
    // 0b0..No write or read access to OTP started.
    // 0b1..Write or read access to OTP started.
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL,  6,  0> ADDR;            // OTP write and read access address register
}  // namespace CTRL

// OTP Controller Control and Status Register
namespace CTRL_SET {
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_SET, 16, 16, true> WR_UNLOCK;
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_SET,  1, 10, true> RELOAD_SHADOWS;
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_SET,  1,  9, true> ERROR;
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_SET,  1,  8, true> BUSY;
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_SET,  6,  0, true> ADDR;
}  // namespace CTRL_SET

// OTP Controller Control and Status Register
namespace CTRL_CLR {
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_CLR, 16, 16, true> WR_UNLOCK;
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_CLR,  1, 10, true> RELOAD_SHADOWS;
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_CLR,  1,  9, true> ERROR;
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_CLR,  1,  8, true> BUSY;
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_CLR,  6,  0, true> ADDR;
}  // namespace CTRL_CLR

// OTP Controller Control and Status Register
namespace CTRL_TOG {
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_TOG, 16, 16, true> WR_UNLOCK;
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_TOG,  1, 10, true> RELOAD_SHADOWS;
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_TOG,  1,  9, true> ERROR;
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_TOG,  1,  8, true> BUSY;
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_TOG,  6,  0, true> ADDR;
}  // namespace CTRL_TOG

// OTP Controller Timing Register
namespace TIMING {
constexpr OCOTP_Reg<&OCOTP_Layout::TIMING,  6, 22> WAIT;         // Wait Interval
constexpr OCOTP_Reg<&OCOTP_Layout::TIMING,  6, 16> STROBE_READ;  // Read Strobe Period
constexpr OCOTP_Reg<&OCOTP_Layout::TIMING,  4, 12> RELAX;        // Relax Count Value
constexpr OCOTP_Reg<&OCOTP_Layout::TIMING, 12,  0> STROBE_PROG;  // Write Strobe Period
}  // namespace TIMING

// OTP Controller Write Data Register
namespace READ_CTRL {
constexpr OCOTP_Reg<&OCOTP_Layout::READ_CTRL, 1, 0> READ_FUSE;
}  // namespace READ_CTRL

// Sticky bit Register
namespace SW_STICKY {
constexpr OCOTP_Reg<&OCOTP_Layout::SW_STICKY, 1, 2> FIELD_RETURN_LOCK;  // Field Return Lock
    // 0b0..Writing to this region's shadow register and OTP fuse word are not blocked.
    // 0b1..Writing to this region's shadow register and OTP fuse word are blocked. Once this bit is set, it is always high unless a POR is issued.
constexpr OCOTP_Reg<&OCOTP_Layout::SW_STICKY, 1, 1> SRK_REVOKE_LOCK;    // SRK Revoke Lock
    // 0b0..The writing of this region's shadow register and OTP fuse word are not blocked.
    // 0b1..The writing of this region's shadow register and OTP fuse word are blocked. Once this bit is set, it is always high unless a POR is issued.
}  // namespace SW_STICKY

// Software Controllable Signals Register
namespace SCS {
constexpr OCOTP_Reg<&OCOTP_Layout::SCS,  1, 31> LOCK;
    // 0b0..Bits in this register are unlocked.
    // 0b1..Bits in this register are locked. When set, all of the bits in this register are locked and can not be
    //      changed through SW programming. After this bit is set, it can only be cleared by a POR.
constexpr OCOTP_Reg<&OCOTP_Layout::SCS, 30,  1> SPARE;
constexpr OCOTP_Reg<&OCOTP_Layout::SCS,  1,  0> HAB_JDE;  // HAB JTAG Debug Enable
    // 0b0..JTAG debugging is not enabled by the HAB (it may still be enabled by other mechanisms).
    // 0b1..JTAG debugging is enabled by the HAB (though this signal may be gated off).
}  // namespace SCS

// Software Controllable Signals Register
namespace SCS_SET {
constexpr OCOTP_Reg<&OCOTP_Layout::SCS_SET,  1, 31, true> LOCK;
constexpr OCOTP_Reg<&OCOTP_Layout::SCS_SET, 30,  1, true> SPARE;
constexpr OCOTP_Reg<&OCOTP_Layout::SCS_SET,  1,  0, true> HAB_JDE;
}  // namespace SCS_SET

// Software Controllable Signals Register
namespace SCS_CLR {
constexpr OCOTP_Reg<&OCOTP_Layout::SCS_CLR,  1, 31, true> LOCK;
constexpr OCOTP_Reg<&OCOTP_Layout::SCS_CLR, 30,  1, true> SPARE;
constexpr OCOTP_Reg<&OCOTP_Layout::SCS_CLR,  1,  0, true> HAB_JDE;
}  // namespace SCS_CLR

// Software Controllable Signals Register
namespace SCS_TOG {
constexpr OCOTP_Reg<&OCOTP_Layout::SCS_TOG,  1, 31, true> LOCK;
constexpr OCOTP_Reg<&OCOTP_Layout::SCS_TOG, 30,  1, true> SPARE;
constexpr OCOTP_Reg<&OCOTP_Layout::SCS_TOG,  1,  0, true> HAB_JDE;
}  // namespace SCS_TOG

// OTP Controller Version Register
namespace VERSION {
constexpr OCOTP_Reg<&OCOTP_Layout::VERSION,  8, 24> MAJOR;
constexpr OCOTP_Reg<&OCOTP_Layout::VERSION,  8, 16> MINOR;
constexpr OCOTP_Reg<&OCOTP_Layout::VERSION, 16,  0> STEP;
}  // namespace VERSION

// OTP Controller Timing Register 2
namespace TIMING2 {
constexpr OCOTP_Reg<&OCOTP_Layout::TIMING2,  6, 16> RELAX_READ;  // Relax Read count value
constexpr OCOTP_Reg<&OCOTP_Layout::TIMING2, 12,  0> RELAX_PROG;  // Relax Prog. count value
}  // namespace TIMING2

// Value of OTP Bank0 Word0 (Lock controls)
namespace LOCK {
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 1, 31> FIELD_RETURN;  // FIELD RETURN Status
    // 0b0..The device is a functional part.
    // 0b1..The device is a field returned part.
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 2, 26> GP3;           // GP3 Write Lock Status
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 2, 24> GP4;           // GP4 Write Lock Status
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 1, 23> SW_GP2_RLOCK;  // SW_GP2 Read Lock Status
    // 0b0..The reading of this region's shadow register and OTP fuse word are not blocked.
    // 0b1..When set, the reading of this region's shadow register and OTP fuse word are blocked.
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 1, 22> MISC_CONF;     // MISC_CONF Write Lock Status
    // 0b0..Writing of this region's shadow register and OTP fuse word are not blocked.
    // 0b1..When set, the writing of this region's shadow register and OTP fuse word are blocked.
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 1, 21> SW_GP2_LOCK;   // SW_GP2 Write Lock Status
    // 0b0..Writing of this region's shadow register and OTP fuse word are not blocked.
    // 0b1..When set, the writing of this region's shadow register and OTP fuse word are blocked.
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 2, 18> ANALOG;        // ANALOG Write Lock Status
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 1, 16> SW_GP1;        // SW_GP1 Write Lock Status
    // 0b0..Writing of this region's shadow register and OTP fuse word are not blocked.
    // 0b1..When set, the writing of this region's shadow register and OTP fuse word are blocked.
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 2, 12> GP2;           // GP2 Write Lock Status
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 2, 10> GP1;           // GP1 Write Lock Status
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 2,  8> MAC_ADDR;      // MAC_ADDR Write Lock Status
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 1,  7> GP4_RLOCK;     // GP4 Read Lock Status
    // 0b0..Reading of this region's shadow register and OTP fuse word are not blocked.
    // 0b1..When set, the reading of this region's shadow register and OTP fuse word are blocked.
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 1,  6> SJC_RESP;      // SJC_RESP Lock Status
    // 0b0..The writing or reading of this region's shadow register and OTP fuse word are not blocked.
    // 0b1..When set, the writing of this region's shadow register and OTP fuse word are blocked. The read of this
    //      region's shadow register and OTP fuse word are also blocked
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 2,  2> BOOT_CFG;      // BOOT_CFG Write Lock Status
}  // namespace LOCK

}  // namespace OCOTP

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
