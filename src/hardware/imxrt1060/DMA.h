// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// DMA.h defines all the DMA registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

/** DMA - Size of Registers Arrays */
constexpr size_t kDMA_TCD_count = 32;

// DMA layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_DMA.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct DMA_Layout {
  volatile uint32_t CR;                                /**< Control, offset: 0x0 */
  const volatile uint32_t ES;                                /**< Error Status, offset: 0x4 */
  int8_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[4];
  volatile uint32_t ERQ;                               /**< Enable Request, offset: 0xC */
  int8_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[4];
  volatile uint32_t EEI;                               /**< Enable Error Interrupt, offset: 0x14 */
  volatile uint8_t CEEI;                               /**< Clear Enable Error Interrupt, offset: 0x18 */
  volatile uint8_t SEEI;                               /**< Set Enable Error Interrupt, offset: 0x19 */
  volatile uint8_t CERQ;                               /**< Clear Enable Request, offset: 0x1A */
  volatile uint8_t SERQ;                               /**< Set Enable Request, offset: 0x1B */
  volatile uint8_t CDNE;                               /**< Clear DONE Status Bit, offset: 0x1C */
  volatile uint8_t SSRT;                               /**< Set START Bit, offset: 0x1D */
  volatile uint8_t CERR;                               /**< Clear Error, offset: 0x1E */
  volatile uint8_t CINT;                               /**< Clear Interrupt Request, offset: 0x1F */
  uint8_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[4];
  volatile uint32_t INT;                               /**< Interrupt Request, offset: 0x24 */
  uint8_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[4];
  volatile uint32_t ERR;                               /**< Error, offset: 0x2C */
  uint8_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[4];
  const volatile uint32_t HRS;                         /**< Hardware Request Status, offset: 0x34 */
  uint8_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[12];
  volatile uint32_t EARS;                              /**< Enable Asynchronous Request in Stop, offset: 0x44 */
  uint8_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[184];
  volatile uint8_t DCHPRI3;                            /**< Channel Priority, offset: 0x100 */
  volatile uint8_t DCHPRI2;                            /**< Channel Priority, offset: 0x101 */
  volatile uint8_t DCHPRI1;                            /**< Channel Priority, offset: 0x102 */
  volatile uint8_t DCHPRI0;                            /**< Channel Priority, offset: 0x103 */
  volatile uint8_t DCHPRI7;                            /**< Channel Priority, offset: 0x104 */
  volatile uint8_t DCHPRI6;                            /**< Channel Priority, offset: 0x105 */
  volatile uint8_t DCHPRI5;                            /**< Channel Priority, offset: 0x106 */
  volatile uint8_t DCHPRI4;                            /**< Channel Priority, offset: 0x107 */
  volatile uint8_t DCHPRI11;                           /**< Channel Priority, offset: 0x108 */
  volatile uint8_t DCHPRI10;                           /**< Channel Priority, offset: 0x109 */
  volatile uint8_t DCHPRI9;                            /**< Channel Priority, offset: 0x10A */
  volatile uint8_t DCHPRI8;                            /**< Channel Priority, offset: 0x10B */
  volatile uint8_t DCHPRI15;                           /**< Channel Priority, offset: 0x10C */
  volatile uint8_t DCHPRI14;                           /**< Channel Priority, offset: 0x10D */
  volatile uint8_t DCHPRI13;                           /**< Channel Priority, offset: 0x10E */
  volatile uint8_t DCHPRI12;                           /**< Channel Priority, offset: 0x10F */
  volatile uint8_t DCHPRI19;                           /**< Channel Priority, offset: 0x110 */
  volatile uint8_t DCHPRI18;                           /**< Channel Priority, offset: 0x111 */
  volatile uint8_t DCHPRI17;                           /**< Channel Priority, offset: 0x112 */
  volatile uint8_t DCHPRI16;                           /**< Channel Priority, offset: 0x113 */
  volatile uint8_t DCHPRI23;                           /**< Channel Priority, offset: 0x114 */
  volatile uint8_t DCHPRI22;                           /**< Channel Priority, offset: 0x115 */
  volatile uint8_t DCHPRI21;                           /**< Channel Priority, offset: 0x116 */
  volatile uint8_t DCHPRI20;                           /**< Channel Priority, offset: 0x117 */
  volatile uint8_t DCHPRI27;                           /**< Channel Priority, offset: 0x118 */
  volatile uint8_t DCHPRI26;                           /**< Channel Priority, offset: 0x119 */
  volatile uint8_t DCHPRI25;                           /**< Channel Priority, offset: 0x11A */
  volatile uint8_t DCHPRI24;                           /**< Channel Priority, offset: 0x11B */
  volatile uint8_t DCHPRI31;                           /**< Channel Priority, offset: 0x11C */
  volatile uint8_t DCHPRI30;                           /**< Channel Priority, offset: 0x11D */
  volatile uint8_t DCHPRI29;                           /**< Channel Priority, offset: 0x11E */
  volatile uint8_t DCHPRI28;                           /**< Channel Priority, offset: 0x11F */
  uint8_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3808];
  struct {                                         /* offset: 0x1000, array step: 0x20 */
    volatile uint32_t SADDR;                             /**< TCD Source Address, array offset: 0x1000, array step: 0x20 */
    volatile uint16_t SOFF;                              /**< TCD Signed Source Address Offset, array offset: 0x1004, array step: 0x20 */
    volatile uint16_t ATTR;                              /**< TCD Transfer Attributes, array offset: 0x1006, array step: 0x20 */
    union {                                          /* offset: 0x1008, array step: 0x20 */
      volatile uint32_t NBYTES_MLNO;                       /**< TCD Minor Byte Count (Minor Loop Mapping Disabled), array offset: 0x1008, array step: 0x20 */
      volatile uint32_t NBYTES_MLOFFNO;                    /**< TCD Signed Minor Loop Offset (Minor Loop Mapping Enabled and Offset Disabled), array offset: 0x1008, array step: 0x20 */
      volatile uint32_t NBYTES_MLOFFYES;                   /**< TCD Signed Minor Loop Offset (Minor Loop Mapping and Offset Enabled), array offset: 0x1008, array step: 0x20 */
    };
    volatile int32_t SLAST;                              /**< TCD Last Source Address Adjustment, array offset: 0x100C, array step: 0x20 */
    volatile uint32_t DADDR;                             /**< TCD Destination Address, array offset: 0x1010, array step: 0x20 */
    volatile uint16_t DOFF;                              /**< TCD Signed Destination Address Offset, array offset: 0x1014, array step: 0x20 */
    union {                                          /* offset: 0x1016, array step: 0x20 */
      volatile uint16_t CITER_ELINKNO;                     /**< TCD Current Minor Loop Link, Major Loop Count (Channel Linking Disabled), array offset: 0x1016, array step: 0x20 */
      volatile uint16_t CITER_ELINKYES;                    /**< TCD Current Minor Loop Link, Major Loop Count (Channel Linking Enabled), array offset: 0x1016, array step: 0x20 */
    };
    volatile int32_t DLAST_SGA;                          /**< TCD Last Destination Address Adjustment/Scatter Gather Address, array offset: 0x1018, array step: 0x20 */
    volatile uint16_t CSR;                               /**< TCD Control and Status, array offset: 0x101C, array step: 0x20 */
    union {                                          /* offset: 0x101E, array step: 0x20 */
      volatile uint16_t BITER_ELINKNO;                     /**< TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Disabled), array offset: 0x101E, array step: 0x20 */
      volatile uint16_t BITER_ELINKYES;                    /**< TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Enabled), array offset: 0x101E, array step: 0x20 */
    };
  } TCD[kDMA_TCD_count];
};

constexpr size_t    kDMA_size = 0x1400;
constexpr uintptr_t kDMA_base = 0x400E8000;

namespace DMA {
constexpr regs::RegGroup<DMA_Layout, kDMA_size, kDMA_base> group;
}  // namespace DMA

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using DMA_Reg8 =
    regs::Reg<uint8_t, kDMA_base, DMA_Layout, Member, 0, Bits, Shift, DirectAssign>;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using DMA_Reg32 =
    regs::Reg32<kDMA_base, DMA_Layout, Member, 0, Bits, Shift, DirectAssign>;

namespace DMA {

// Control
namespace CR {
constexpr DMA_Reg32<regs::constify(&DMA_Layout::CR), 1, 31> ACTIVE;   // eDMA Active Status
    // 0b0..eDMA is idle
    // 0b1..eDMA is executing a channel
constexpr DMA_Reg32<&DMA_Layout::CR, 1, 17> CX;       // Cancel Transfer
    // 0b0..Normal operation
    // 0b1..Cancel the remaining data transfer
constexpr DMA_Reg32<&DMA_Layout::CR, 1, 16> ECX;      // Error Cancel Transfer
    // 0b0..Normal operation
    // 0b1..Cancel the remaining data transfer
constexpr DMA_Reg32<&DMA_Layout::CR, 1, 10> GRP1PRI;  // Channel Group 1 Priority
constexpr DMA_Reg32<&DMA_Layout::CR, 1,  8> GRP0PRI;  // Channel Group 0 Priority
constexpr DMA_Reg32<&DMA_Layout::CR, 1,  7> EMLM;     // Enable Minor Loop Mapping
    // 0b0..Disabled
    // 0b1..Enabled
constexpr DMA_Reg32<&DMA_Layout::CR, 1,  6> CLM;      // Continuous Link Mode
    // 0b0..Continuous link mode is off
    // 0b1..Continuous link mode is on
constexpr DMA_Reg32<&DMA_Layout::CR, 1,  5> HALT;     // Halt eDMA Operations
    // 0b0..Normal operation
    // 0b1..eDMA operations halted
constexpr DMA_Reg32<&DMA_Layout::CR, 1,  4> HOE;      // Halt On Error
    // 0b0..Normal operation
    // 0b1..Error causes HALT field to be automatically set to 1
constexpr DMA_Reg32<&DMA_Layout::CR, 1,  3> ERGA;     // Enable Round Robin Group Arbitration
    // 0b0..Fixed priority arbitration
    // 0b1..Round robin arbitration
constexpr DMA_Reg32<&DMA_Layout::CR, 1,  2> ERCA;     // Enable Round Robin Channel Arbitration
    // 0b0..Fixed priority arbitration within each group
    // 0b1..Round robin arbitration within each group
constexpr DMA_Reg32<&DMA_Layout::CR, 1,  1> EDBG;     // Enable Debug
    // 0b0..When the chip is in Debug mode, the eDMA continues to operate.
    // 0b1..When the chip is in debug mode, the DMA stalls the start of a new channel. Executing channels are allowed to complete.
}  // namespace CR

// Error Status
namespace ES {
constexpr DMA_Reg32<&DMA_Layout::ES, 1, 31> VLD;     // Logical OR of all ERR status fields
    // 0b0..No ERR fields are 1
    // 0b1..At least one ERR field has a value of 1, indicating a valid error exists that has not been cleared
constexpr DMA_Reg32<&DMA_Layout::ES, 1, 16> ECX;     // Transfer Canceled
    // 0b0..No canceled transfers
    // 0b1..The most-recently recorded entry was a canceled transfer initiated by the error cancel transfer field
constexpr DMA_Reg32<&DMA_Layout::ES, 1, 15> GPE;     // Group Priority Error
    // 0b0..No group priority error.
    // 0b1..The most-recently recorded error was a configuration error among the group priorities. All group priorities are not unique.
constexpr DMA_Reg32<&DMA_Layout::ES, 1, 14> CPE;     // Channel Priority Error
    // 0b0..No channel priority error.
    // 0b1..The most-recently recorded error was a configuration error in the channel priorities within a group.
    //      Channel priorities within a group are not unique.
constexpr DMA_Reg32<&DMA_Layout::ES, 5,  8> ERRCHN;  // Error Channel Number or Canceled Channel Number
constexpr DMA_Reg32<&DMA_Layout::ES, 1,  7> SAE;     // Source Address Error
    // 0b0..No source address configuration error.
    // 0b1..The most-recently recorded error was a configuration error detected in the TCDn_SADDR field. TCDn_SADDR
    //      is inconsistent with TCDn_ATTR[SSIZE].
constexpr DMA_Reg32<&DMA_Layout::ES, 1,  6> SOE;     // Source Offset Error
    // 0b0..No source offset configuration error.
    // 0b1..The most-recently recorded error was a configuration error detected in the TCDn_SOFF field. TCDn_SOFF is inconsistent with TCDn_ATTR[SSIZE].
constexpr DMA_Reg32<&DMA_Layout::ES, 1,  5> DAE;     // Destination Address Error
    // 0b0..No destination address configuration error.
    // 0b1..The most-recently recorded error was a configuration error detected in the TCDn_DADDR field. TCDn_DADDR
    //      is inconsistent with TCDn_ATTR[DSIZE].
constexpr DMA_Reg32<&DMA_Layout::ES, 1,  4> DOE;     // Destination Offset Error
    // 0b0..No destination offset configuration error.
    // 0b1..The most-recently recorded error was a configuration error detected in the TCDn_DOFF field. TCDn_DOFF is inconsistent with TCDn_ATTR[DSIZE].
constexpr DMA_Reg32<&DMA_Layout::ES, 1,  3> NCE;     // NBYTES/CITER Configuration Error
    // 0b0..No NBYTES/CITER configuration error.
    // 0b1..The most-recently recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER
    //      fields. TCDn_NBYTES is not a multiple of TCDn_ATTR[SSIZE] and TCDn_ATTR[DSIZE], or TCDn_CITER[CITER] = 0, or
    //      TCDn_CITER[ELINK] is not equal to TCDn_BITER[ELINK].
constexpr DMA_Reg32<&DMA_Layout::ES, 1,  2> SGE;     // Scatter/Gather Configuration Error
    // 0b0..No scatter/gather configuration error.
    // 0b1..The most-recently recorded error was a configuration error detected in the TCDn_DLASTSGA field.
constexpr DMA_Reg32<&DMA_Layout::ES, 1,  1> SBE;     // Source Bus Error
    // 0b0..No source bus error.
    // 0b1..The most-recently recorded error was a bus error on a source read.
constexpr DMA_Reg32<&DMA_Layout::ES, 1,  0> DBE;     // Destination Bus Error
    // 0b0..No destination bus error.
    // 0b1..The most-recently recorded error was a bus error on a destination write.
}  // namespace ES

// Enable Request
namespace ERQ {
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1, 31> ERQ31;  // Enable DMA Request 31
    // 0b0..The DMA request signal for channel 31 is disabled
    // 0b1..The DMA request signal for channel 31 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1, 30> ERQ30;  // Enable DMA Request 30
    // 0b0..The DMA request signal for channel 30 is disabled
    // 0b1..The DMA request signal for channel 30 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1, 29> ERQ29;  // Enable DMA Request 29
    // 0b0..The DMA request signal for channel 29 is disabled
    // 0b1..The DMA request signal for channel 29 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1, 28> ERQ28;  // Enable DMA Request 28
    // 0b0..The DMA request signal for channel 28 is disabled
    // 0b1..The DMA request signal for channel 28 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1, 27> ERQ27;  // Enable DMA Request 27
    // 0b0..The DMA request signal for channel 27 is disabled
    // 0b1..The DMA request signal for channel 27 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1, 26> ERQ26;  // Enable DMA Request 26
    // 0b0..The DMA request signal for channel 26 is disabled
    // 0b1..The DMA request signal for channel 26 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1, 25> ERQ25;  // Enable DMA Request 25
    // 0b0..The DMA request signal for channel 25 is disabled
    // 0b1..The DMA request signal for channel 25 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1, 24> ERQ24;  // Enable DMA Request 24
    // 0b0..The DMA request signal for channel 24 is disabled
    // 0b1..The DMA request signal for channel 24 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1, 23> ERQ23;  // Enable DMA Request 23
    // 0b0..The DMA request signal for channel 23 is disabled
    // 0b1..The DMA request signal for channel 23 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1, 22> ERQ22;  // Enable DMA Request 22
    // 0b0..The DMA request signal for channel 22 is disabled
    // 0b1..The DMA request signal for channel 22 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1, 21> ERQ21;  // Enable DMA Request 21
    // 0b0..The DMA request signal for channel 21 is disabled
    // 0b1..The DMA request signal for channel 21 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1, 20> ERQ20;  // Enable DMA Request 20
    // 0b0..The DMA request signal for channel 20 is disabled
    // 0b1..The DMA request signal for channel 20 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1, 19> ERQ19;  // Enable DMA Request 19
    // 0b0..The DMA request signal for channel 19 is disabled
    // 0b1..The DMA request signal for channel 19 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1, 18> ERQ18;  // Enable DMA Request 18
    // 0b0..The DMA request signal for channel 18 is disabled
    // 0b1..The DMA request signal for channel 18 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1, 17> ERQ17;  // Enable DMA Request 17
    // 0b0..The DMA request signal for channel 17 is disabled
    // 0b1..The DMA request signal for channel 17 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1, 16> ERQ16;  // Enable DMA Request 16
    // 0b0..The DMA request signal for channel 16 is disabled
    // 0b1..The DMA request signal for channel 16 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1, 15> ERQ15;  // Enable DMA Request 15
    // 0b0..The DMA request signal for channel 15 is disabled
    // 0b1..The DMA request signal for channel 15 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1, 14> ERQ14;  // Enable DMA Request 14
    // 0b0..The DMA request signal for channel 14 is disabled
    // 0b1..The DMA request signal for channel 14 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1, 13> ERQ13;  // Enable DMA Request 13
    // 0b0..The DMA request signal for channel 13 is disabled
    // 0b1..The DMA request signal for channel 13 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1, 12> ERQ12;  // Enable DMA Request 12
    // 0b0..The DMA request signal for channel 12 is disabled
    // 0b1..The DMA request signal for channel 12 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1, 11> ERQ11;  // Enable DMA Request 11
    // 0b0..The DMA request signal for channel 11 is disabled
    // 0b1..The DMA request signal for channel 11 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1, 10> ERQ10;  // Enable DMA Request 10
    // 0b0..The DMA request signal for channel 10 is disabled
    // 0b1..The DMA request signal for channel 10 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1,  9> ERQ9;   // Enable DMA Request 9
    // 0b0..The DMA request signal for channel 9 is disabled
    // 0b1..The DMA request signal for channel 9 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1,  8> ERQ8;   // Enable DMA Request 8
    // 0b0..The DMA request signal for channel 8 is disabled
    // 0b1..The DMA request signal for channel 8 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1,  7> ERQ7;   // Enable DMA Request 7
    // 0b0..The DMA request signal for channel 7 is disabled
    // 0b1..The DMA request signal for channel 7 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1,  6> ERQ6;   // Enable DMA Request 6
    // 0b0..The DMA request signal for channel 6 is disabled
    // 0b1..The DMA request signal for channel 6 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1,  5> ERQ5;   // Enable DMA Request 5
    // 0b0..The DMA request signal for channel 5 is disabled
    // 0b1..The DMA request signal for channel 5 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1,  4> ERQ4;   // Enable DMA Request 4
    // 0b0..The DMA request signal for channel 4 is disabled
    // 0b1..The DMA request signal for channel 4 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1,  3> ERQ3;   // Enable DMA Request 3
    // 0b0..The DMA request signal for channel 3 is disabled
    // 0b1..The DMA request signal for channel 3 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1,  2> ERQ2;   // Enable DMA Request 2
    // 0b0..The DMA request signal for channel 2 is disabled
    // 0b1..The DMA request signal for channel 2 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1,  1> ERQ1;   // Enable DMA Request 1
    // 0b0..The DMA request signal for channel 1 is disabled
    // 0b1..The DMA request signal for channel 1 is enabled
constexpr DMA_Reg32<&DMA_Layout::ERQ, 1,  0> ERQ0;   // Enable DMA Request 0
    // 0b0..The DMA request signal for channel 0 is disabled
    // 0b1..The DMA request signal for channel 0 is enabled
}  // namespace ERQ

// Enable Error Interrupt
namespace EEI {
constexpr DMA_Reg32<&DMA_Layout::EEI, 1, 31> EEI31;  // Enable Error Interrupt 31
    // 0b0..An error on channel 31 does not generate an error interrupt
    // 0b1..An error on channel 31 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1, 30> EEI30;  // Enable Error Interrupt 30
    // 0b0..An error on channel 30 does not generate an error interrupt
    // 0b1..An error on channel 30 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1, 29> EEI29;  // Enable Error Interrupt 29
    // 0b0..An error on channel 29 does not generate an error interrupt
    // 0b1..An error on channel 29 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1, 28> EEI28;  // Enable Error Interrupt 28
    // 0b0..An error on channel 28 does not generate an error interrupt
    // 0b1..An error on channel 28 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1, 27> EEI27;  // Enable Error Interrupt 27
    // 0b0..An error on channel 27 does not generate an error interrupt
    // 0b1..An error on channel 27 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1, 26> EEI26;  // Enable Error Interrupt 26
    // 0b0..An error on channel 26 does not generate an error interrupt
    // 0b1..An error on channel 26 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1, 25> EEI25;  // Enable Error Interrupt 25
    // 0b0..An error on channel 25 does not generate an error interrupt
    // 0b1..An error on channel 25 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1, 24> EEI24;  // Enable Error Interrupt 24
    // 0b0..An error on channel 24 does not generate an error interrupt
    // 0b1..An error on channel 24 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1, 23> EEI23;  // Enable Error Interrupt 23
    // 0b0..An error on channel 23 does not generate an error interrupt
    // 0b1..An error on channel 23 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1, 22> EEI22;  // Enable Error Interrupt 22
    // 0b0..An error on channel 22 does not generate an error interrupt
    // 0b1..An error on channel 22 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1, 21> EEI21;  // Enable Error Interrupt 21
    // 0b0..An error on channel 21 does not generate an error interrupt
    // 0b1..An error on channel 21 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1, 20> EEI20;  // Enable Error Interrupt 20
    // 0b0..An error on channel 20 does not generate an error interrupt
    // 0b1..An error on channel 20 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1, 19> EEI19;  // Enable Error Interrupt 19
    // 0b0..An error on channel 19 does not generate an error interrupt
    // 0b1..An error on channel 19 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1, 18> EEI18;  // Enable Error Interrupt 18
    // 0b0..An error on channel 18 does not generate an error interrupt
    // 0b1..An error on channel 18 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1, 17> EEI17;  // Enable Error Interrupt 17
    // 0b0..An error on channel 17 does not generate an error interrupt
    // 0b1..An error on channel 17 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1, 16> EEI16;  // Enable Error Interrupt 16
    // 0b0..An error on channel 16 does not generate an error interrupt
    // 0b1..An error on channel 16 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1, 15> EEI15;  // Enable Error Interrupt 15
    // 0b0..An error on channel 15 does not generate an error interrupt
    // 0b1..An error on channel 15 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1, 14> EEI14;  // Enable Error Interrupt 14
    // 0b0..An error on channel 14 does not generate an error interrupt
    // 0b1..An error on channel 14 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1, 13> EEI13;  // Enable Error Interrupt 13
    // 0b0..An error on channel 13 does not generate an error interrupt
    // 0b1..An error on channel 13 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1, 12> EEI12;  // Enable Error Interrupt 12
    // 0b0..An error on channel 12 does not generate an error interrupt
    // 0b1..An error on channel 12 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1, 11> EEI11;  // Enable Error Interrupt 11
    // 0b0..An error on channel 11 does not generate an error interrupt
    // 0b1..An error on channel 11 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1, 10> EEI10;  // Enable Error Interrupt 10
    // 0b0..An error on channel 10 does not generate an error interrupt
    // 0b1..An error on channel 10 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1,  9> EEI9;   // Enable Error Interrupt 9
    // 0b0..An error on channel 9 does not generate an error interrupt
    // 0b1..An error on channel 9 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1,  8> EEI8;   // Enable Error Interrupt 8
    // 0b0..An error on channel 8 does not generate an error interrupt
    // 0b1..An error on channel 8 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1,  7> EEI7;   // Enable Error Interrupt 7
    // 0b0..An error on channel 7 does not generate an error interrupt
    // 0b1..An error on channel 7 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1,  6> EEI6;   // Enable Error Interrupt 6
    // 0b0..An error on channel 6 does not generate an error interrupt
    // 0b1..An error on channel 6 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1,  5> EEI5;   // Enable Error Interrupt 5
    // 0b0..An error on channel 5 does not generate an error interrupt
    // 0b1..An error on channel 5 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1,  4> EEI4;   // Enable Error Interrupt 4
    // 0b0..An error on channel 4 does not generate an error interrupt
    // 0b1..An error on channel 4 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1,  3> EEI3;   // Enable Error Interrupt 3
    // 0b0..An error on channel 3 does not generate an error interrupt
    // 0b1..An error on channel 3 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1,  2> EEI2;   // Enable Error Interrupt 2
    // 0b0..An error on channel 2 does not generate an error interrupt
    // 0b1..An error on channel 2 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1,  1> EEI1;   // Enable Error Interrupt 1
    // 0b0..An error on channel 1 does not generate an error interrupt
    // 0b1..An error on channel 1 generates an error interrupt request
constexpr DMA_Reg32<&DMA_Layout::EEI, 1,  0> EEI0;   // Enable Error Interrupt 0
    // 0b0..An error on channel 0 does not generate an error interrupt
    // 0b1..An error on channel 0 generates an error interrupt request
}  // namespace EEI

// Clear Enable Error Interrupt
namespace CEEI {
constexpr DMA_Reg8<&DMA_Layout::CEEI, 1, 7> NOP;   // No Op Enable
    // 0b0..Normal operation
    // 0b1..No operation, ignore the other fields in this register
constexpr DMA_Reg8<&DMA_Layout::CEEI, 1, 6> CAEE;  // Clear All Enable Error Interrupts
    // 0b0..Write 0 only to the EEI field specified in the CEEI field
    // 0b1..Write 0 to all fields in EEI
constexpr DMA_Reg8<&DMA_Layout::CEEI, 5, 0> CEEI;  // Clear Enable Error Interrupt
}  // namespace CEEI

// Set Enable Error Interrupt
namespace SEEI {
constexpr DMA_Reg8<&DMA_Layout::SEEI, 1, 7> NOP;   // No Op Enable
    // 0b0..Normal operation
    // 0b1..No operation, ignore the other fields in this register
constexpr DMA_Reg8<&DMA_Layout::SEEI, 1, 6> SAEE;  // Set All Enable Error Interrupts
    // 0b0..Write 1 only to the EEI field specified in the SEEI field
    // 0b1..Writes 1 to all fields in EEI
constexpr DMA_Reg8<&DMA_Layout::SEEI, 5, 0> SEEI;  // Set Enable Error Interrupt
}  // namespace SEEI

// Clear Enable Request
namespace CERQ {
constexpr DMA_Reg8<&DMA_Layout::CERQ, 1, 7> NOP;   // No Op Enable
    // 0b0..Normal operation
    // 0b1..No operation, ignore the other fields in this register
constexpr DMA_Reg8<&DMA_Layout::CERQ, 1, 6> CAER;  // Clear All Enable Requests
    // 0b0..Write 0 to only the ERQ field specified in the CERQ field
    // 0b1..Write 0 to all fields in ERQ
constexpr DMA_Reg8<&DMA_Layout::CERQ, 5, 0> CERQ;  // Clear Enable Request
}  // namespace CERQ

// Set Enable Request
namespace SERQ {
constexpr DMA_Reg8<&DMA_Layout::SERQ, 1, 7> NOP;   // No Op Enable
    // 0b0..Normal operation
    // 0b1..No operation, ignore the other fields in this register
constexpr DMA_Reg8<&DMA_Layout::SERQ, 1, 6> SAER;  // Set All Enable Requests
    // 0b0..Write 1 to only the ERQ field specified in the SERQ field
    // 0b1..Write 1 to all fields in ERQ
constexpr DMA_Reg8<&DMA_Layout::SERQ, 5, 0> SERQ;  // Set Enable Request
}  // namespace SERQ

// Clear DONE Status Bit
namespace CDNE {
constexpr DMA_Reg8<&DMA_Layout::CDNE, 1, 7> NOP;   // No Op Enable
    // 0b0..Normal operation
    // 0b1..No operation; all other fields in this register are ignored.
constexpr DMA_Reg8<&DMA_Layout::CDNE, 1, 6> CADN;  // Clears All DONE fields
    // 0b0..Writes 0 to only the TCDn_CSR[DONE] field specified in the CDNE field
    // 0b1..Writes 0 to all bits in TCDn_CSR[DONE]
constexpr DMA_Reg8<&DMA_Layout::CDNE, 5, 0> CDNE;  // Clear DONE field
}  // namespace CDNE

// Set START Bit
namespace SSRT {
constexpr DMA_Reg8<&DMA_Layout::SSRT, 1, 7> NOP;   // No Op Enable
    // 0b0..Normal operation
    // 0b1..No operation; all other fields in this register are ignored.
constexpr DMA_Reg8<&DMA_Layout::SSRT, 1, 6> SAST;  // Set All START fields (activates all channels)
    // 0b0..Write 1 to only the TCDn_CSR[START] field specified in the SSRT field
    // 0b1..Write 1 to all bits in TCDn_CSR[START]
constexpr DMA_Reg8<&DMA_Layout::SSRT, 5, 0> SSRT;  // Set START field
}  // namespace SSRT

// Clear Error
namespace CERR {
constexpr DMA_Reg8<&DMA_Layout::CERR, 1, 7> NOP;   // No Op Enable
    // 0b0..Normal operation
    // 0b1..No operation; all other fields in this register are ignored.
constexpr DMA_Reg8<&DMA_Layout::CERR, 1, 6> CAEI;  // Clear All Error Indicators
    // 0b0..Write 0 to only the ERR field specified in the CERR field
    // 0b1..Write 0 to all fields in ERR
constexpr DMA_Reg8<&DMA_Layout::CERR, 5, 0> CERR;  // Clear Error Indicator
}  // namespace CERR

// Clear Interrupt Request
namespace CINT {
constexpr DMA_Reg8<&DMA_Layout::CINT, 1, 7> NOP;   // No Op Enable
    // 0b0..Normal operation
    // 0b1..No operation; all other fields in this register are ignored.
constexpr DMA_Reg8<&DMA_Layout::CINT, 1, 6> CAIR;  // Clear All Interrupt Requests
    // 0b0..Clear only the INT field specified in the CINT field
    // 0b1..Clear all bits in INT
constexpr DMA_Reg8<&DMA_Layout::CINT, 5, 0> CINT;  // Clear Interrupt Request
}  // namespace CINT

// Interrupt Request
namespace INT {
constexpr DMA_Reg32<&DMA_Layout::INT, 1, 31, true> INT31;  // Interrupt Request 31
    // 0b0..The interrupt request for channel 31 is cleared
    // 0b1..The interrupt request for channel 31 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1, 30, true> INT30;  // Interrupt Request 30
    // 0b0..The interrupt request for channel 30 is cleared
    // 0b1..The interrupt request for channel 30 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1, 29, true> INT29;  // Interrupt Request 29
    // 0b0..The interrupt request for channel 29 is cleared
    // 0b1..The interrupt request for channel 29 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1, 28, true> INT28;  // Interrupt Request 28
    // 0b0..The interrupt request for channel 28 is cleared
    // 0b1..The interrupt request for channel 28 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1, 27, true> INT27;  // Interrupt Request 27
    // 0b0..The interrupt request for channel 27 is cleared
    // 0b1..The interrupt request for channel 27 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1, 26, true> INT26;  // Interrupt Request 26
    // 0b0..The interrupt request for channel 26 is cleared
    // 0b1..The interrupt request for channel 26 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1, 25, true> INT25;  // Interrupt Request 25
    // 0b0..The interrupt request for channel 25 is cleared
    // 0b1..The interrupt request for channel 25 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1, 24, true> INT24;  // Interrupt Request 24
    // 0b0..The interrupt request for channel 24 is cleared
    // 0b1..The interrupt request for channel 24 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1, 23, true> INT23;  // Interrupt Request 23
    // 0b0..The interrupt request for channel 23 is cleared
    // 0b1..The interrupt request for channel 23 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1, 22, true> INT22;  // Interrupt Request 22
    // 0b0..The interrupt request for channel 22 is cleared
    // 0b1..The interrupt request for channel 22 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1, 21, true> INT21;  // Interrupt Request 21
    // 0b0..The interrupt request for channel 21 is cleared
    // 0b1..The interrupt request for channel 21 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1, 20, true> INT20;  // Interrupt Request 20
    // 0b0..The interrupt request for channel 20 is cleared
    // 0b1..The interrupt request for channel 20 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1, 19, true> INT19;  // Interrupt Request 19
    // 0b0..The interrupt request for channel 19 is cleared
    // 0b1..The interrupt request for channel 19 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1, 18, true> INT18;  // Interrupt Request 18
    // 0b0..The interrupt request for channel 18 is cleared
    // 0b1..The interrupt request for channel 18 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1, 17, true> INT17;  // Interrupt Request 17
    // 0b0..The interrupt request for channel 17 is cleared
    // 0b1..The interrupt request for channel 17 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1, 16, true> INT16;  // Interrupt Request 16
    // 0b0..The interrupt request for channel 16 is cleared
    // 0b1..The interrupt request for channel 16 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1, 15, true> INT15;  // Interrupt Request 15
    // 0b0..The interrupt request for channel 15 is cleared
    // 0b1..The interrupt request for channel 15 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1, 14, true> INT14;  // Interrupt Request 14
    // 0b0..The interrupt request for channel 14 is cleared
    // 0b1..The interrupt request for channel 14 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1, 13, true> INT13;  // Interrupt Request 13
    // 0b0..The interrupt request for channel 13 is cleared
    // 0b1..The interrupt request for channel 13 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1, 12, true> INT12;  // Interrupt Request 12
    // 0b0..The interrupt request for channel 12 is cleared
    // 0b1..The interrupt request for channel 12 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1, 11, true> INT11;  // Interrupt Request 11
    // 0b0..The interrupt request for channel 11 is cleared
    // 0b1..The interrupt request for channel 11 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1, 10, true> INT10;  // Interrupt Request 10
    // 0b0..The interrupt request for channel 10 is cleared
    // 0b1..The interrupt request for channel 10 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1,  9, true> INT9;   // Interrupt Request 9
    // 0b0..The interrupt request for channel 9 is cleared
    // 0b1..The interrupt request for channel 9 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1,  8, true> INT8;   // Interrupt Request 8
    // 0b0..The interrupt request for channel 8 is cleared
    // 0b1..The interrupt request for channel 8 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1,  7, true> INT7;   // Interrupt Request 7
    // 0b0..The interrupt request for channel 7 is cleared
    // 0b1..The interrupt request for channel 7 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1,  6, true> INT6;   // Interrupt Request 6
    // 0b0..The interrupt request for channel 6 is cleared
    // 0b1..The interrupt request for channel 6 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1,  5, true> INT5;   // Interrupt Request 5
    // 0b0..The interrupt request for channel 5 is cleared
    // 0b1..The interrupt request for channel 5 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1,  4, true> INT4;   // Interrupt Request 4
    // 0b0..The interrupt request for channel 4 is cleared
    // 0b1..The interrupt request for channel 4 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1,  3, true> INT3;   // Interrupt Request 3
    // 0b0..The interrupt request for channel 3 is cleared
    // 0b1..The interrupt request for channel 3 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1,  2, true> INT2;   // Interrupt Request 2
    // 0b0..The interrupt request for channel 2 is cleared
    // 0b1..The interrupt request for channel 2 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1,  1, true> INT1;   // Interrupt Request 1
    // 0b0..The interrupt request for channel 1 is cleared
    // 0b1..The interrupt request for channel 1 is active
constexpr DMA_Reg32<&DMA_Layout::INT, 1,  0, true> INT0;   // Interrupt Request 0
    // 0b0..The interrupt request for channel 0 is cleared
    // 0b1..The interrupt request for channel 0 is active
}  // namespace INT

// Error
namespace ERR {
constexpr DMA_Reg32<&DMA_Layout::ERR, 1, 31, true> ERR31;  // Error In Channel 31
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1, 30, true> ERR30;  // Error In Channel 30
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1, 29, true> ERR29;  // Error In Channel 29
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1, 28, true> ERR28;  // Error In Channel 28
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1, 27, true> ERR27;  // Error In Channel 27
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1, 26, true> ERR26;  // Error In Channel 26
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1, 25, true> ERR25;  // Error In Channel 25
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1, 24, true> ERR24;  // Error In Channel 24
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1, 23, true> ERR23;  // Error In Channel 23
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1, 22, true> ERR22;  // Error In Channel 22
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1, 21, true> ERR21;  // Error In Channel 21
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1, 20, true> ERR20;  // Error In Channel 20
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1, 19, true> ERR19;  // Error In Channel 19
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1, 18, true> ERR18;  // Error In Channel 18
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1, 17, true> ERR17;  // Error In Channel 17
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1, 16, true> ERR16;  // Error In Channel 16
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1, 15, true> ERR15;  // Error In Channel 15
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1, 14, true> ERR14;  // Error In Channel 14
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1, 13, true> ERR13;  // Error In Channel 13
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1, 12, true> ERR12;  // Error In Channel 12
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1, 11, true> ERR11;  // Error In Channel 11
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1, 10, true> ERR10;  // Error In Channel 10
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1,  9, true> ERR9;   // Error In Channel 9
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1,  8, true> ERR8;   // Error In Channel 8
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1,  7, true> ERR7;   // Error In Channel 7
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1,  6, true> ERR6;   // Error In Channel 6
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1,  5, true> ERR5;   // Error In Channel 5
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1,  4, true> ERR4;   // Error In Channel 4
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1,  3, true> ERR3;   // Error In Channel 3
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1,  2, true> ERR2;   // Error In Channel 2
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1,  1, true> ERR1;   // Error In Channel 1
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
constexpr DMA_Reg32<&DMA_Layout::ERR, 1,  0, true> ERR0;   // Error In Channel 0
    // 0b0..No error in this channel has occurred
    // 0b1..An error in this channel has occurred
}  // namespace ERR

// Hardware Request Status
namespace HRS {
constexpr DMA_Reg32<&DMA_Layout::HRS, 1, 31> HRS31;  // Hardware Request Status Channel 31
    // 0b0..A hardware service request for channel 31 is not present
    // 0b1..A hardware service request for channel 31 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1, 30> HRS30;  // Hardware Request Status Channel 30
    // 0b0..A hardware service request for channel 30 is not present
    // 0b1..A hardware service request for channel 30 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1, 29> HRS29;  // Hardware Request Status Channel 29
    // 0b0..A hardware service request for channel 29 is not preset
    // 0b1..A hardware service request for channel 29 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1, 28> HRS28;  // Hardware Request Status Channel 28
    // 0b0..A hardware service request for channel 28 is not present
    // 0b1..A hardware service request for channel 28 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1, 27> HRS27;  // Hardware Request Status Channel 27
    // 0b0..A hardware service request for channel 27 is not present
    // 0b1..A hardware service request for channel 27 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1, 26> HRS26;  // Hardware Request Status Channel 26
    // 0b0..A hardware service request for channel 26 is not present
    // 0b1..A hardware service request for channel 26 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1, 25> HRS25;  // Hardware Request Status Channel 25
    // 0b0..A hardware service request for channel 25 is not present
    // 0b1..A hardware service request for channel 25 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1, 24> HRS24;  // Hardware Request Status Channel 24
    // 0b0..A hardware service request for channel 24 is not present
    // 0b1..A hardware service request for channel 24 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1, 23> HRS23;  // Hardware Request Status Channel 23
    // 0b0..A hardware service request for channel 23 is not present
    // 0b1..A hardware service request for channel 23 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1, 22> HRS22;  // Hardware Request Status Channel 22
    // 0b0..A hardware service request for channel 22 is not present
    // 0b1..A hardware service request for channel 22 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1, 21> HRS21;  // Hardware Request Status Channel 21
    // 0b0..A hardware service request for channel 21 is not present
    // 0b1..A hardware service request for channel 21 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1, 20> HRS20;  // Hardware Request Status Channel 20
    // 0b0..A hardware service request for channel 20 is not present
    // 0b1..A hardware service request for channel 20 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1, 19> HRS19;  // Hardware Request Status Channel 19
    // 0b0..A hardware service request for channel 19 is not present
    // 0b1..A hardware service request for channel 19 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1, 18> HRS18;  // Hardware Request Status Channel 18
    // 0b0..A hardware service request for channel 18 is not present
    // 0b1..A hardware service request for channel 18 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1, 17> HRS17;  // Hardware Request Status Channel 17
    // 0b0..A hardware service request for channel 17 is not present
    // 0b1..A hardware service request for channel 17 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1, 16> HRS16;  // Hardware Request Status Channel 16
    // 0b0..A hardware service request for channel 16 is not present
    // 0b1..A hardware service request for channel 16 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1, 15> HRS15;  // Hardware Request Status Channel 15
    // 0b0..A hardware service request for channel 15 is not present
    // 0b1..A hardware service request for channel 15 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1, 14> HRS14;  // Hardware Request Status Channel 14
    // 0b0..A hardware service request for channel 14 is not present
    // 0b1..A hardware service request for channel 14 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1, 13> HRS13;  // Hardware Request Status Channel 13
    // 0b0..A hardware service request for channel 13 is not present
    // 0b1..A hardware service request for channel 13 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1, 12> HRS12;  // Hardware Request Status Channel 12
    // 0b0..A hardware service request for channel 12 is not present
    // 0b1..A hardware service request for channel 12 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1, 11> HRS11;  // Hardware Request Status Channel 11
    // 0b0..A hardware service request for channel 11 is not present
    // 0b1..A hardware service request for channel 11 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1, 10> HRS10;  // Hardware Request Status Channel 10
    // 0b0..A hardware service request for channel 10 is not present
    // 0b1..A hardware service request for channel 10 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1,  9> HRS9;   // Hardware Request Status Channel 9
    // 0b0..A hardware service request for channel 9 is not present
    // 0b1..A hardware service request for channel 9 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1,  8> HRS8;   // Hardware Request Status Channel 8
    // 0b0..A hardware service request for channel 8 is not present
    // 0b1..A hardware service request for channel 8 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1,  7> HRS7;   // Hardware Request Status Channel 7
    // 0b0..A hardware service request for channel 7 is not present
    // 0b1..A hardware service request for channel 7 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1,  6> HRS6;   // Hardware Request Status Channel 6
    // 0b0..A hardware service request for channel 6 is not present
    // 0b1..A hardware service request for channel 6 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1,  5> HRS5;   // Hardware Request Status Channel 5
    // 0b0..A hardware service request for channel 5 is not present
    // 0b1..A hardware service request for channel 5 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1,  4> HRS4;   // Hardware Request Status Channel 4
    // 0b0..A hardware service request for channel 4 is not present
    // 0b1..A hardware service request for channel 4 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1,  3> HRS3;   // Hardware Request Status Channel 3
    // 0b0..A hardware service request for channel 3 is not present
    // 0b1..A hardware service request for channel 3 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1,  2> HRS2;   // Hardware Request Status Channel 2
    // 0b0..A hardware service request for channel 2 is not present
    // 0b1..A hardware service request for channel 2 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1,  1> HRS1;   // Hardware Request Status Channel 1
    // 0b0..A hardware service request for channel 1 is not present
    // 0b1..A hardware service request for channel 1 is present
constexpr DMA_Reg32<&DMA_Layout::HRS, 1,  0> HRS0;   // Hardware Request Status Channel 0
    // 0b0..A hardware service request for channel 0 is not present
    // 0b1..A hardware service request for channel 0 is present
}  // namespace HRS

// Enable Asynchronous Request in Stop
namespace EARS {
constexpr DMA_Reg32<&DMA_Layout::EARS, 1, 31> EDREQ_31;  // Enable asynchronous DMA request in stop mode for channel 31.
    // 0b0..Disable asynchronous DMA request for channel 31
    // 0b1..Enable asynchronous DMA request for channel 31
constexpr DMA_Reg32<&DMA_Layout::EARS, 1, 30> EDREQ_30;  // Enable asynchronous DMA request in stop mode for channel 30.
    // 0b0..Disable asynchronous DMA request for channel 30
    // 0b1..Enable asynchronous DMA request for channel 30
constexpr DMA_Reg32<&DMA_Layout::EARS, 1, 29> EDREQ_29;  // Enable asynchronous DMA request in stop mode for channel 29.
    // 0b0..Disable asynchronous DMA request for channel 29
    // 0b1..Enable asynchronous DMA request for channel 29
constexpr DMA_Reg32<&DMA_Layout::EARS, 1, 28> EDREQ_28;  // Enable asynchronous DMA request in stop mode for channel 28.
    // 0b0..Disable asynchronous DMA request for channel 28
    // 0b1..Enable asynchronous DMA request for channel 28
constexpr DMA_Reg32<&DMA_Layout::EARS, 1, 27> EDREQ_27;  // Enable asynchronous DMA request in stop mode for channel 27.
    // 0b0..Disable asynchronous DMA request for channel 27
    // 0b1..Enable asynchronous DMA request for channel 27
constexpr DMA_Reg32<&DMA_Layout::EARS, 1, 26> EDREQ_26;  // Enable asynchronous DMA request in stop mode for channel 26.
    // 0b0..Disable asynchronous DMA request for channel 26
    // 0b1..Enable asynchronous DMA request for channel 26
constexpr DMA_Reg32<&DMA_Layout::EARS, 1, 25> EDREQ_25;  // Enable asynchronous DMA request in stop mode for channel 25.
    // 0b0..Disable asynchronous DMA request for channel 25
    // 0b1..Enable asynchronous DMA request for channel 25
constexpr DMA_Reg32<&DMA_Layout::EARS, 1, 24> EDREQ_24;  // Enable asynchronous DMA request in stop mode for channel 24.
    // 0b0..Disable asynchronous DMA request for channel 24
    // 0b1..Enable asynchronous DMA request for channel 24
constexpr DMA_Reg32<&DMA_Layout::EARS, 1, 23> EDREQ_23;  // Enable asynchronous DMA request in stop mode for channel 23.
    // 0b0..Disable asynchronous DMA request for channel 23
    // 0b1..Enable asynchronous DMA request for channel 23
constexpr DMA_Reg32<&DMA_Layout::EARS, 1, 22> EDREQ_22;  // Enable asynchronous DMA request in stop mode for channel 22.
    // 0b0..Disable asynchronous DMA request for channel 22
    // 0b1..Enable asynchronous DMA request for channel 22
constexpr DMA_Reg32<&DMA_Layout::EARS, 1, 21> EDREQ_21;  // Enable asynchronous DMA request in stop mode for channel 21.
    // 0b0..Disable asynchronous DMA request for channel 21
    // 0b1..Enable asynchronous DMA request for channel 21
constexpr DMA_Reg32<&DMA_Layout::EARS, 1, 20> EDREQ_20;  // Enable asynchronous DMA request in stop mode for channel 20.
    // 0b0..Disable asynchronous DMA request for channel 20
    // 0b1..Enable asynchronous DMA request for channel 20
constexpr DMA_Reg32<&DMA_Layout::EARS, 1, 19> EDREQ_19;  // Enable asynchronous DMA request in stop mode for channel 19.
    // 0b0..Disable asynchronous DMA request for channel 19
    // 0b1..Enable asynchronous DMA request for channel 19
constexpr DMA_Reg32<&DMA_Layout::EARS, 1, 18> EDREQ_18;  // Enable asynchronous DMA request in stop mode for channel 18.
    // 0b0..Disable asynchronous DMA request for channel 18
    // 0b1..Enable asynchronous DMA request for channel 18
constexpr DMA_Reg32<&DMA_Layout::EARS, 1, 17> EDREQ_17;  // Enable asynchronous DMA request in stop mode for channel 17.
    // 0b0..Disable asynchronous DMA request for channel 17
    // 0b1..Enable asynchronous DMA request for channel 17
constexpr DMA_Reg32<&DMA_Layout::EARS, 1, 16> EDREQ_16;  // Enable asynchronous DMA request in stop mode for channel 16.
    // 0b0..Disable asynchronous DMA request for channel 16
    // 0b1..Enable asynchronous DMA request for channel 16
constexpr DMA_Reg32<&DMA_Layout::EARS, 1, 15> EDREQ_15;  // Enable asynchronous DMA request in stop mode for channel 15.
    // 0b0..Disable asynchronous DMA request for channel 15
    // 0b1..Enable asynchronous DMA request for channel 15
constexpr DMA_Reg32<&DMA_Layout::EARS, 1, 14> EDREQ_14;  // Enable asynchronous DMA request in stop mode for channel 14.
    // 0b0..Disable asynchronous DMA request for channel 14
    // 0b1..Enable asynchronous DMA request for channel 14
constexpr DMA_Reg32<&DMA_Layout::EARS, 1, 13> EDREQ_13;  // Enable asynchronous DMA request in stop mode for channel 13.
    // 0b0..Disable asynchronous DMA request for channel 13
    // 0b1..Enable asynchronous DMA request for channel 13
constexpr DMA_Reg32<&DMA_Layout::EARS, 1, 12> EDREQ_12;  // Enable asynchronous DMA request in stop mode for channel 12.
    // 0b0..Disable asynchronous DMA request for channel 12
    // 0b1..Enable asynchronous DMA request for channel 12
constexpr DMA_Reg32<&DMA_Layout::EARS, 1, 11> EDREQ_11;  // Enable asynchronous DMA request in stop mode for channel 11.
    // 0b0..Disable asynchronous DMA request for channel 11
    // 0b1..Enable asynchronous DMA request for channel 11
constexpr DMA_Reg32<&DMA_Layout::EARS, 1, 10> EDREQ_10;  // Enable asynchronous DMA request in stop mode for channel 10.
    // 0b0..Disable asynchronous DMA request for channel 10
    // 0b1..Enable asynchronous DMA request for channel 10
constexpr DMA_Reg32<&DMA_Layout::EARS, 1,  9> EDREQ_9;   // Enable asynchronous DMA request in stop mode for channel 9.
    // 0b0..Disable asynchronous DMA request for channel 9
    // 0b1..Enable asynchronous DMA request for channel 9
constexpr DMA_Reg32<&DMA_Layout::EARS, 1,  8> EDREQ_8;   // Enable asynchronous DMA request in stop mode for channel 8.
    // 0b0..Disable asynchronous DMA request for channel 8
    // 0b1..Enable asynchronous DMA request for channel 8
constexpr DMA_Reg32<&DMA_Layout::EARS, 1,  7> EDREQ_7;   // Enable asynchronous DMA request in stop mode for channel 7.
    // 0b0..Disable asynchronous DMA request for channel 7
    // 0b1..Enable asynchronous DMA request for channel 7
constexpr DMA_Reg32<&DMA_Layout::EARS, 1,  6> EDREQ_6;   // Enable asynchronous DMA request in stop mode for channel 6.
    // 0b0..Disable asynchronous DMA request for channel 6
    // 0b1..Enable asynchronous DMA request for channel 6
constexpr DMA_Reg32<&DMA_Layout::EARS, 1,  5> EDREQ_5;   // Enable asynchronous DMA request in stop mode for channel 5.
    // 0b0..Disable asynchronous DMA request for channel 5
    // 0b1..Enable asynchronous DMA request for channel 5
constexpr DMA_Reg32<&DMA_Layout::EARS, 1,  4> EDREQ_4;   // Enable asynchronous DMA request in stop mode for channel 4.
    // 0b0..Disable asynchronous DMA request for channel 4
    // 0b1..Enable asynchronous DMA request for channel 4
constexpr DMA_Reg32<&DMA_Layout::EARS, 1,  3> EDREQ_3;   // Enable asynchronous DMA request in stop mode for channel 3.
    // 0b0..Disable asynchronous DMA request for channel 3
    // 0b1..Enable asynchronous DMA request for channel 3
constexpr DMA_Reg32<&DMA_Layout::EARS, 1,  2> EDREQ_2;   // Enable asynchronous DMA request in stop mode for channel 2.
    // 0b0..Disable asynchronous DMA request for channel 2
    // 0b1..Enable asynchronous DMA request for channel 2
constexpr DMA_Reg32<&DMA_Layout::EARS, 1,  1> EDREQ_1;   // Enable asynchronous DMA request in stop mode for channel 1.
    // 0b0..Disable asynchronous DMA request for channel 1
    // 0b1..Enable asynchronous DMA request for channel 1
constexpr DMA_Reg32<&DMA_Layout::EARS, 1,  0> EDREQ_0;   // Enable asynchronous DMA request in stop mode for channel 0.
    // 0b0..Disable asynchronous DMA request for channel 0
    // 0b1..Enable asynchronous DMA request for channel 0
}  // namespace EARS

// Channel Priority
namespace DCHPRI3 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI3, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI3, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI3), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI3, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI3

// Channel Priority
namespace DCHPRI2 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI2, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI2, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI2), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI2, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI2

// Channel Priority
namespace DCHPRI1 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI1, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI1, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI1), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI1, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI1

// Channel Priority
namespace DCHPRI0 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI0, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI0, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI0), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI0, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI0

// Channel Priority
namespace DCHPRI7 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI7, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI7, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI7), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI7, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI7

// Channel Priority
namespace DCHPRI6 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI6, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI6, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI6), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI6, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI6

// Channel Priority
namespace DCHPRI5 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI5, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI5, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI5), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI5, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI5

// Channel Priority
namespace DCHPRI4 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI4, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI4, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI4), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI4, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI4

// Channel Priority
namespace DCHPRI11 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI11, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI11, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI11), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI11, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI11

// Channel Priority
namespace DCHPRI10 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI10, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI10, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI10), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI10, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI10

// Channel Priority
namespace DCHPRI9 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI9, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI9, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI9), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI9, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI9

// Channel Priority
namespace DCHPRI8 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI8, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI8, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI8), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI8, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI8

// Channel Priority
namespace DCHPRI15 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI15, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI15, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI15), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI15, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI15

// Channel Priority
namespace DCHPRI14 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI14, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI14, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI14), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI14, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI14

// Channel Priority
namespace DCHPRI13 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI13, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI13, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI13), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI13, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI13

// Channel Priority
namespace DCHPRI12 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI12, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI12, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI12), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI12, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI12

// Channel Priority
namespace DCHPRI19 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI19, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI19, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI19), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI19, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI19

// Channel Priority
namespace DCHPRI18 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI18, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI18, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI18), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI18, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI18

// Channel Priority
namespace DCHPRI17 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI17, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI17, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI17), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI17, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI17

// Channel Priority
namespace DCHPRI16 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI16, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI16, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI16), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI16, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI16

// Channel Priority
namespace DCHPRI23 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI23, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI23, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI23), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI23, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI23

// Channel Priority
namespace DCHPRI22 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI22, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI22, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI22), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI22, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI22

// Channel Priority
namespace DCHPRI21 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI21, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI21, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI21), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI21, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI21

// Channel Priority
namespace DCHPRI20 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI20, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI20, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI20), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI20, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI20

// Channel Priority
namespace DCHPRI27 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI27, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI27, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI27), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI27, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI27

// Channel Priority
namespace DCHPRI26 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI26, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI26, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI26), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI26, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI26

// Channel Priority
namespace DCHPRI25 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI25, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI25, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI25), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI25, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI25

// Channel Priority
namespace DCHPRI24 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI24, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI24, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI24), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI24, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI24

// Channel Priority
namespace DCHPRI31 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI31, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI31, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI31), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI31, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI31

// Channel Priority
namespace DCHPRI30 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI30, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI30, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI30), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI30, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI30

// Channel Priority
namespace DCHPRI29 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI29, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI29, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI29), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI29, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI29

// Channel Priority
namespace DCHPRI28 {
constexpr DMA_Reg8<&DMA_Layout::DCHPRI28, 1, 7> ECP;     // Enable Channel Preemption. This field resets to 0.
    // 0b0..Channel n cannot be suspended by a higher priority channel's service request
    // 0b1..Channel n can be temporarily suspended by the service request of a higher priority channel
constexpr DMA_Reg8<&DMA_Layout::DCHPRI28, 1, 6> DPA;     // Disable Preempt Ability. This field resets to 0.
    // 0b0..Channel n can suspend a lower priority channel
    // 0b1..Channel n cannot suspend any channel, regardless of channel priority
constexpr DMA_Reg8<regs::constify(&DMA_Layout::DCHPRI28), 2, 4> GRPPRI;  // Channel n Current Group Priority
constexpr DMA_Reg8<&DMA_Layout::DCHPRI28, 4, 0> CHPRI;   // Channel n Arbitration Priority
}  // namespace DCHPRI28

// TCD Transfer Attributes values
namespace ATTR {
constexpr regs::RegValue16<5, 11> SMOD;    // Source Address Modulo
    // 0b00000..Source address modulo feature is disabled
    // 0b00001-0b11111..Value defines address range used to set up circular data queue
constexpr regs::RegValue16<3,  8> SSIZE;   // Source data transfer size
    // 0b000..8-bit
    // 0b001..16-bit
    // 0b010..32-bit
    // 0b011..64-bit
    // 0b100..Reserved
    // 0b101..32-byte burst (4 beats of 64 bits)
    // 0b110..Reserved
    // 0b111..Reserved
constexpr regs::RegValue16<5,  3> DMOD;    // Destination Address Modulo
constexpr regs::RegValue16<3,  0> DSIZE;   // Destination data transfer size
}  // namespace ATTR

// TCD Signed Minor Loop Offset (Minor Loop Mapping Enabled and Offset Disabled) values
namespace NBYTES_MLOFFNO {
constexpr regs::RegValue32<1,  31> SMLOE;   // Source Minor Loop Offset Enable
    // 0b0..The minor loop offset is not applied to the SADDR
    // 0b1..The minor loop offset is applied to the SADDR
constexpr regs::RegValue32<1,  30> DMLOE;   // Destination Minor Loop Offset Enable
    // 0b0..The minor loop offset is not applied to the DADDR
    // 0b1..The minor loop offset is applied to the DADDR
constexpr regs::RegValue32<30,  0> NBYTES;  // Minor Byte Transfer Count
}  // namespace NBYTES_MLOFFNO

// TCD Signed Minor Loop Offset (Minor Loop Mapping and Offset Enabled) values
namespace NBYTES_MLOFFYES {
constexpr regs::RegValue32< 1, 31> SMLOE;   // Source Minor Loop Offset Enable
    // 0b0..The minor loop offset is not applied to the SADDR
    // 0b1..The minor loop offset is applied to the SADDR
constexpr regs::RegValue32< 1, 30> DMLOE;   // Destination Minor Loop Offset Enable
    // 0b0..The minor loop offset is not applied to the DADDR
    // 0b1..The minor loop offset is applied to the DADDR
constexpr regs::RegValue32<20, 10> MLOFF;
    // If SMLOE = 1 or DMLOE = 1, this field represents a sign-extended offset applied to the
    //   source or destination address to form the next-state value after the minor loop completes.
constexpr regs::RegValue32<10,  0> NBYTES;  // Minor Byte Transfer Count
}  // namespace NBYTES_MLOFFYES

// TCD Current Minor Loop Link, Major Loop Count (Channel Linking Disabled) values
namespace CITER_ELINKNO {
constexpr regs::RegValue16< 1, 15> ELINK;  // Enable channel-to-channel linking on minor-loop complete
    // 0b0..Channel-to-channel linking is disabled
    // 0b1..Channel-to-channel linking is enabled
constexpr regs::RegValue16<15,  0> CITER;  // Current Major Iteration Count
}  // namespace CITER_ELINKNO

// TCD Current Minor Loop Link, Major Loop Count (Channel Linking Enabled) values
namespace CITER_ELINKYES {
constexpr regs::RegValue16<1, 15> ELINK;   // Enable channel-to-channel linking on minor-loop complete
    // 0b0..Channel-to-channel linking is disabled
    // 0b1..Channel-to-channel linking is enabled
constexpr regs::RegValue16<5,  9> LINKCH;  // Minor Loop Link Channel Number
constexpr regs::RegValue16<9,  0> CITER;   // Current Major Iteration Count
}  // namespace CITER_ELINKYES

// TCD Control and Status values
namespace CSR {
constexpr regs::RegValue16<2, 14> BWC;          // Bandwidth Control
    // 0b00..No eDMA engine stalls
    // 0b01..Reserved
    // 0b10..eDMA engine stalls for 4 cycles after each R/W
    // 0b11..eDMA engine stalls for 8 cycles after each R/W
constexpr regs::RegValue16<5,  8> MAJORLINKCH;  // Major Loop Link Channel Number
constexpr regs::RegValue16<1,  7> DONE;         // Channel Done
constexpr regs::RegValue16<1,  6> ACTIVE;       // R/O, Channel Active
constexpr regs::RegValue16<1,  5> MAJORELINK;   // Enable channel-to-channel linking on major loop complete
    // 0b0..Channel-to-channel linking is disabled
    // 0b1..Channel-to-channel linking is enabled
constexpr regs::RegValue16<1,  4> ESG;          // Enable Scatter/Gather Processing
    // 0b0..The current channel's TCD is normal format
    // 0b1..The current channel's TCD specifies a scatter gather format
constexpr regs::RegValue16<1,  3> DREQ;         // Disable Request
    // 0b0..The channel's ERQ field is not affected
    // 0b1..The channel's ERQ field value changes to 0 when the major loop is complete
constexpr regs::RegValue16<1,  2> INTHALF;      // Enable an interrupt when major counter is half complete.
    // 0b0..Half-point interrupt is disabled
    // 0b1..Half-point interrupt is enabled
constexpr regs::RegValue16<1,  1> INTMAJOR;     // Enable an interrupt when major iteration count completes.
    // 0b0..End of major loop interrupt is disabled
    // 0b1..End of major loop interrupt is enabled
constexpr regs::RegValue16<1,  0> START;        // Channel Start
    // 0b0..Channel is not explicitly started
    // 0b1..Channel is explicitly started via a software initiated service request
}  // namespace CSR

// TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Disabled) values
namespace BITER_ELINKNO {
constexpr regs::RegValue16< 1, 15> ELINK;  // Enables channel-to-channel linking on minor loop complete
    // 0b0..Channel-to-channel linking is disabled
    // 0b1..Channel-to-channel linking is enabled
constexpr regs::RegValue16<15,  0> BITER;  // Starting Major Iteration Count
}  // namespace BITER_ELINKNO

// TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Enabled) values
namespace BITER_ELINKYES {
constexpr regs::RegValue16<1, 15> ELINK;   // Enables channel-to-channel linking on minor loop complete
    // 0b0..Channel-to-channel linking is disabled
    // 0b1..Channel-to-channel linking is enabled
constexpr regs::RegValue16<5,  9> LINKCH;  // Link Channel Number
constexpr regs::RegValue16<9,  0> BITER;   // Starting major iteration count
}  // namespace BITER_ELINKYES

}  // namespace DMA

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
