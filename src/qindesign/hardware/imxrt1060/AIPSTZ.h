// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// AIPSTZ.h defines all the AIPSTZ registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "qindesign/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the AHB to IP Bridge (AIPSTZ) registers.
//
// Comments are from BSD-3-licensed NXP SDK sources and the NXP reference manual.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_AIPSTZ.h
// * https://github.com/nxp-mcuxpresso/mcux-soc-svd/blob/main/MIMXRT1062/MIMXRT1062.xml
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
// * i.MX RT1060 Processor Reference Manual, Rev. 4, chapter 32
struct AIPSTZ_Layout {
  volatile uint32_t MPR;                               /**< Master Privilege Registers, offset: 0x0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[15];
  volatile uint32_t OPACR;                             /**< Off-Platform Peripheral Access Control Registers, offset: 0x40 */
  volatile uint32_t OPACR1;                            /**< Off-Platform Peripheral Access Control Registers, offset: 0x44 */
  volatile uint32_t OPACR2;                            /**< Off-Platform Peripheral Access Control Registers, offset: 0x48 */
  volatile uint32_t OPACR3;                            /**< Off-Platform Peripheral Access Control Registers, offset: 0x4C */
  volatile uint32_t OPACR4;                            /**< Off-Platform Peripheral Access Control Registers, offset: 0x50 */
};

constexpr size_t    kAIPSTZ_size  = 0x54;
constexpr uintptr_t kAIPSTZ1_base = 0x4007'C000;
constexpr uintptr_t kAIPSTZ2_base = 0x4017'C000;
constexpr uintptr_t kAIPSTZ3_base = 0x4027'C000;
constexpr uintptr_t kAIPSTZ4_base = 0x4037'C000;

namespace AIPSTZ1 {
constexpr regs::RegGroup<AIPSTZ_Layout, kAIPSTZ_size, kAIPSTZ1_base> group;
}  // namespace AIPSTZ1

namespace AIPSTZ2 {
constexpr regs::RegGroup<AIPSTZ_Layout, kAIPSTZ_size, kAIPSTZ2_base> group;
}  // namespace AIPSTZ2

namespace AIPSTZ3 {
constexpr regs::RegGroup<AIPSTZ_Layout, kAIPSTZ_size, kAIPSTZ3_base> group;
}  // namespace AIPSTZ3

namespace AIPSTZ4 {
constexpr regs::RegGroup<AIPSTZ_Layout, kAIPSTZ_size, kAIPSTZ4_base> group;
}  // namespace AIPSTZ4

namespace AIPSTZ1 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using AIPSTZ1_Reg =
    regs::Reg32<kAIPSTZ1_base, AIPSTZ_Layout, Member, 0, Bits, Shift,
                AssignMask>;

// Master Privilege Registers
namespace MPR {
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::MPR, 4, 28> MPROT0;  // Master 0 Privilege, Buffer, Read, Write Control
    // 0b1xxx..Write accesses from this master are allowed to be buffered
    // 0bx0xx..This master is not trusted for read accesses.
    // 0bx1xx..This master is trusted for read accesses.
    // 0bxx0x..This master is not trusted for write accesses.
    // 0bxx1x..This master is trusted for write accesses.
    // 0bxxx0..Accesses from this master are forced to user-mode (ips_supervisor_access is forced to zero) regardless of the hprot[1] access attribute.
    // 0bxxx1..Accesses from this master are not forced to user-mode. The hprot[1] access attribute is used directly to determine ips_supervisor_access.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::MPR, 4, 24> MPROT1;  // Master 1 Privilege, Buffer, Read, Write Control
    // 0b1xxx..Write accesses from this master are allowed to be buffered
    // 0bx0xx..This master is not trusted for read accesses.
    // 0bx1xx..This master is trusted for read accesses.
    // 0bxx0x..This master is not trusted for write accesses.
    // 0bxx1x..This master is trusted for write accesses.
    // 0bxxx0..Accesses from this master are forced to user-mode (ips_supervisor_access is forced to zero) regardless of the hprot[1] access attribute.
    // 0bxxx1..Accesses from this master are not forced to user-mode. The hprot[1] access attribute is used directly to determine ips_supervisor_access.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::MPR, 4, 20> MPROT2;  // Master 2 Privilege, Buffer, Read, Write Control
    // 0b1xxx..Write accesses from this master are allowed to be buffered
    // 0bx0xx..This master is not trusted for read accesses.
    // 0bx1xx..This master is trusted for read accesses.
    // 0bxx0x..This master is not trusted for write accesses.
    // 0bxx1x..This master is trusted for write accesses.
    // 0bxxx0..Accesses from this master are forced to user-mode (ips_supervisor_access is forced to zero) regardless of the hprot[1] access attribute.
    // 0bxxx1..Accesses from this master are not forced to user-mode. The hprot[1] access attribute is used directly to determine ips_supervisor_access.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::MPR, 4, 16> MPROT3;  // Master 3 Privilege, Buffer, Read, Write Control.
    // 0b1xxx..Write accesses from this master are allowed to be buffered
    // 0bx0xx..This master is not trusted for read accesses.
    // 0bx1xx..This master is trusted for read accesses.
    // 0bxx0x..This master is not trusted for write accesses.
    // 0bxx1x..This master is trusted for write accesses.
    // 0bxxx0..Accesses from this master are forced to user-mode (ips_supervisor_access is forced to zero) regardless of the hprot[1] access attribute.
    // 0bxxx1..Accesses from this master are not forced to user-mode. The hprot[1] access attribute is used directly to determine ips_supervisor_access.
}  // namespace MPR

// Off-Platform Peripheral Access Control Registers
namespace OPACR {
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR, 4, 28> OPAC0;  // Off-platform Peripheral Access Control 0
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR, 4, 24> OPAC1;  // Off-platform Peripheral Access Control 1
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR, 4, 20> OPAC2;  // Off-platform Peripheral Access Control 2
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR, 4, 16> OPAC3;  // Off-platform Peripheral Access Control 3
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR, 4, 12> OPAC4;  // Off-platform Peripheral Access Control 4
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR, 4,  8> OPAC5;  // Off-platform Peripheral Access Control 5
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR, 4,  4> OPAC6;  // Off-platform Peripheral Access Control 6
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR, 4,  0> OPAC7;  // Off-platform Peripheral Access Control 7
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
}  // namespace OPACR

// Off-Platform Peripheral Access Control Registers
namespace OPACR1 {
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR1, 4, 28> OPAC8;   // Off-platform Peripheral Access Control 8
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR1, 4, 24> OPAC9;   // Off-platform Peripheral Access Control 9
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR1, 4, 20> OPAC10;  // Off-platform Peripheral Access Control 10
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR1, 4, 16> OPAC11;  // Off-platform Peripheral Access Control 11
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR1, 4, 12> OPAC12;  // Off-platform Peripheral Access Control 12
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR1, 4,  8> OPAC13;  // Off-platform Peripheral Access Control 13
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR1, 4,  4> OPAC14;  // Off-platform Peripheral Access Control 14
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR1, 4,  0> OPAC15;  // Off-platform Peripheral Access Control 15
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
}  // namespace OPACR1

// Off-Platform Peripheral Access Control Registers
namespace OPACR2 {
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR2, 4, 28> OPAC16;  // Off-platform Peripheral Access Control 16
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR2, 4, 24> OPAC17;  // Off-platform Peripheral Access Control 17
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR2, 4, 20> OPAC18;  // Off-platform Peripheral Access Control 18
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR2, 4, 16> OPAC19;  // Off-platform Peripheral Access Control 19
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR2, 4, 12> OPAC20;  // Off-platform Peripheral Access Control 20
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR2, 4,  8> OPAC21;  // Off-platform Peripheral Access Control 21
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR2, 4,  4> OPAC22;  // Off-platform Peripheral Access Control 22
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR2, 4,  0> OPAC23;  // Off-platform Peripheral Access Control 23
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
}  // namespace OPACR2

// Off-Platform Peripheral Access Control Registers
namespace OPACR3 {
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR3, 4, 28> OPAC24;  // Off-platform Peripheral Access Control 24
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR3, 4, 24> OPAC25;  // Off-platform Peripheral Access Control 25
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR3, 4, 20> OPAC26;  // Off-platform Peripheral Access Control 26
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR3, 4, 16> OPAC27;  // Off-platform Peripheral Access Control 27
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR3, 4, 12> OPAC28;  // Off-platform Peripheral Access Control 28
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR3, 4,  8> OPAC29;  // Off-platform Peripheral Access Control 29
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR3, 4,  4> OPAC30;  // Off-platform Peripheral Access Control 30
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR3, 4,  0> OPAC31;  // Off-platform Peripheral Access Control 31
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
}  // namespace OPACR3

// Off-Platform Peripheral Access Control Registers
namespace OPACR4 {
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR4, 4, 28> OPAC32;  // Off-platform Peripheral Access Control 32
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
constexpr AIPSTZ1_Reg<&AIPSTZ_Layout::OPACR4, 4, 24> OPAC33;  // Off-platform Peripheral Access Control 33
    // The BW bit must remain 0 because AIPSTZ does not support buffered writes.
    // 0b1xxx..Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
    // 0bx0xx..This peripheral does not require supervisor privilege level for accesses.
    // 0bx1xx..This peripheral requires supervisor privilege level for accesses. The master privilege level must
    // indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must
    // be set. If not, the access is terminated with an error response and no peripheral access is initiated
    // on the IPS bus.
    // 0bxx0x..This peripheral allows write accesses.
    // 0bxx1x..This peripheral is write protected. If a write access is attempted, the access is terminated with an
    // error response and no peripheral access is initiated on the IPS bus.
    // 0bxxx0..Accesses from an untrusted master are allowed.
    // 0bxxx1..Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
    // the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
}  // namespace OPACR4

}  // namespace AIPSTZ1

namespace AIPSTZ2 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using AIPSTZ2_Reg =
    regs::Reg32<kAIPSTZ2_base, AIPSTZ_Layout, Member, 0, Bits, Shift,
                AssignMask>;

// AIPSTZ2 Master Privilege Registers
namespace MPR {
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::MPR, 4, 28> MPROT0;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::MPR, 4, 24> MPROT1;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::MPR, 4, 20> MPROT2;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::MPR, 4, 16> MPROT3;
}  // namespace MPR

// AIPSTZ2 Off-Platform Peripheral Access Control Registers
namespace OPACR {
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR, 4, 28> OPAC0;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR, 4, 24> OPAC1;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR, 4, 20> OPAC2;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR, 4, 16> OPAC3;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR, 4, 12> OPAC4;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR, 4,  8> OPAC5;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR, 4,  4> OPAC6;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR, 4,  0> OPAC7;
}  // namespace OPACR

// AIPSTZ2 Off-Platform Peripheral Access Control Registers
namespace OPACR1 {
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR1, 4, 28> OPAC8;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR1, 4, 24> OPAC9;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR1, 4, 20> OPAC10;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR1, 4, 16> OPAC11;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR1, 4, 12> OPAC12;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR1, 4,  8> OPAC13;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR1, 4,  4> OPAC14;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR1, 4,  0> OPAC15;
}  // namespace OPACR1

// AIPSTZ2 Off-Platform Peripheral Access Control Registers
namespace OPACR2 {
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR2, 4, 28> OPAC16;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR2, 4, 24> OPAC17;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR2, 4, 20> OPAC18;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR2, 4, 16> OPAC19;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR2, 4, 12> OPAC20;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR2, 4,  8> OPAC21;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR2, 4,  4> OPAC22;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR2, 4,  0> OPAC23;
}  // namespace OPACR2

// AIPSTZ2 Off-Platform Peripheral Access Control Registers
namespace OPACR3 {
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR3, 4, 28> OPAC24;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR3, 4, 24> OPAC25;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR3, 4, 20> OPAC26;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR3, 4, 16> OPAC27;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR3, 4, 12> OPAC28;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR3, 4,  8> OPAC29;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR3, 4,  4> OPAC30;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR3, 4,  0> OPAC31;
}  // namespace OPACR3

// AIPSTZ2 Off-Platform Peripheral Access Control Registers
namespace OPACR4 {
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR4, 4, 28> OPAC32;
constexpr AIPSTZ2_Reg<&AIPSTZ_Layout::OPACR4, 4, 24> OPAC33;
}  // namespace OPACR4

}  // namespace AIPSTZ2

namespace AIPSTZ3 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using AIPSTZ3_Reg =
    regs::Reg32<kAIPSTZ3_base, AIPSTZ_Layout, Member, 0, Bits, Shift,
                AssignMask>;

// AIPSTZ3 Master Privilege Registers
namespace MPR {
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::MPR, 4, 28> MPROT0;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::MPR, 4, 24> MPROT1;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::MPR, 4, 20> MPROT2;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::MPR, 4, 16> MPROT3;
}  // namespace MPR

// AIPSTZ3 Off-Platform Peripheral Access Control Registers
namespace OPACR {
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR, 4, 28> OPAC0;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR, 4, 24> OPAC1;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR, 4, 20> OPAC2;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR, 4, 16> OPAC3;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR, 4, 12> OPAC4;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR, 4,  8> OPAC5;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR, 4,  4> OPAC6;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR, 4,  0> OPAC7;
}  // namespace OPACR

// AIPSTZ3 Off-Platform Peripheral Access Control Registers
namespace OPACR1 {
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR1, 4, 28> OPAC8;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR1, 4, 24> OPAC9;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR1, 4, 20> OPAC10;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR1, 4, 16> OPAC11;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR1, 4, 12> OPAC12;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR1, 4,  8> OPAC13;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR1, 4,  4> OPAC14;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR1, 4,  0> OPAC15;
}  // namespace OPACR1

// AIPSTZ3 Off-Platform Peripheral Access Control Registers
namespace OPACR2 {
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR2, 4, 28> OPAC16;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR2, 4, 24> OPAC17;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR2, 4, 20> OPAC18;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR2, 4, 16> OPAC19;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR2, 4, 12> OPAC20;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR2, 4,  8> OPAC21;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR2, 4,  4> OPAC22;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR2, 4,  0> OPAC23;
}  // namespace OPACR2

// AIPSTZ3 Off-Platform Peripheral Access Control Registers
namespace OPACR3 {
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR3, 4, 28> OPAC24;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR3, 4, 24> OPAC25;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR3, 4, 20> OPAC26;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR3, 4, 16> OPAC27;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR3, 4, 12> OPAC28;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR3, 4,  8> OPAC29;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR3, 4,  4> OPAC30;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR3, 4,  0> OPAC31;
}  // namespace OPACR3

// AIPSTZ3 Off-Platform Peripheral Access Control Registers
namespace OPACR4 {
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR4, 4, 28> OPAC32;
constexpr AIPSTZ3_Reg<&AIPSTZ_Layout::OPACR4, 4, 24> OPAC33;
}  // namespace OPACR4

}  // namespace AIPSTZ3

namespace AIPSTZ4 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using AIPSTZ4_Reg =
    regs::Reg32<kAIPSTZ4_base, AIPSTZ_Layout, Member, 0, Bits, Shift,
                AssignMask>;

// AIPSTZ4 Master Privilege Registers
namespace MPR {
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::MPR, 4, 28> MPROT0;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::MPR, 4, 24> MPROT1;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::MPR, 4, 20> MPROT2;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::MPR, 4, 16> MPROT3;
}  // namespace MPR

// AIPSTZ4 Off-Platform Peripheral Access Control Registers
namespace OPACR {
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR, 4, 28> OPAC0;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR, 4, 24> OPAC1;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR, 4, 20> OPAC2;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR, 4, 16> OPAC3;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR, 4, 12> OPAC4;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR, 4,  8> OPAC5;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR, 4,  4> OPAC6;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR, 4,  0> OPAC7;
}  // namespace OPACR

// AIPSTZ4 Off-Platform Peripheral Access Control Registers
namespace OPACR1 {
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR1, 4, 28> OPAC8;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR1, 4, 24> OPAC9;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR1, 4, 20> OPAC10;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR1, 4, 16> OPAC11;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR1, 4, 12> OPAC12;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR1, 4,  8> OPAC13;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR1, 4,  4> OPAC14;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR1, 4,  0> OPAC15;
}  // namespace OPACR1

// AIPSTZ4 Off-Platform Peripheral Access Control Registers
namespace OPACR2 {
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR2, 4, 28> OPAC16;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR2, 4, 24> OPAC17;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR2, 4, 20> OPAC18;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR2, 4, 16> OPAC19;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR2, 4, 12> OPAC20;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR2, 4,  8> OPAC21;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR2, 4,  4> OPAC22;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR2, 4,  0> OPAC23;
}  // namespace OPACR2

// AIPSTZ4 Off-Platform Peripheral Access Control Registers
namespace OPACR3 {
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR3, 4, 28> OPAC24;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR3, 4, 24> OPAC25;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR3, 4, 20> OPAC26;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR3, 4, 16> OPAC27;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR3, 4, 12> OPAC28;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR3, 4,  8> OPAC29;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR3, 4,  4> OPAC30;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR3, 4,  0> OPAC31;
}  // namespace OPACR3

// AIPSTZ4 Off-Platform Peripheral Access Control Registers
namespace OPACR4 {
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR4, 4, 28> OPAC32;
constexpr AIPSTZ4_Reg<&AIPSTZ_Layout::OPACR4, 4, 24> OPAC33;
}  // namespace OPACR4

}  // namespace AIPSTZ4

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
