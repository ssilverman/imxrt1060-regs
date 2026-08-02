// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// CAN.h defines all the CAN registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>
#include <type_traits>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Size of Registers Arrays
constexpr size_t kCAN_MB_SIZE_MB_8B_GROUP_MB_8B_WORD_8B_count  = 2;
constexpr size_t kCAN_MB_SIZE_MB_8B_GROUP_MB_8B_count          = 64;
constexpr size_t kCAN_MB_SIZE_MB_16B_MB_16B_L_WORD_16B_L_count = 4;
constexpr size_t kCAN_MB_SIZE_MB_16B_MB_16B_L_count            = 21;
constexpr size_t kCAN_MB_SIZE_MB_16B_MB_16B_H_WORD_16B_H_count = 4;
constexpr size_t kCAN_MB_SIZE_MB_16B_MB_16B_H_count            = 21;
constexpr size_t kCAN_MB_SIZE_MB_32B_MB_32B_L_WORD_32B_L_count = 8;
constexpr size_t kCAN_MB_SIZE_MB_32B_MB_32B_L_count            = 12;
constexpr size_t kCAN_MB_SIZE_MB_32B_MB_32B_H_WORD_32B_H_count = 8;
constexpr size_t kCAN_MB_SIZE_MB_32B_MB_32B_H_count            = 12;
constexpr size_t kCAN_MB_SIZE_MB_64B_MB_64B_L_WORD_64B_L_count = 16;
constexpr size_t kCAN_MB_SIZE_MB_64B_MB_64B_L_count            = 7;
constexpr size_t kCAN_MB_SIZE_MB_64B_MB_64B_H_WORD_64B_H_count = 16;
constexpr size_t kCAN_MB_SIZE_MB_64B_MB_64B_H_count            = 7;
constexpr size_t kCAN_MB_SIZE_MB_GROUP_MB_count                = 64;
constexpr size_t kCAN_RXIMR_count                              = 64;

// Structure type to access the Flexible Data-rate Controller Area Network
// (CANFD/FlexCAN3) and Flexible Controller Area Network (FLEXCAN) registers.
//
// Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_CAN.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct CAN_Layout {
  volatile uint32_t MCR;                               /**< Module Configuration Register, offset: 0x0 */
  volatile uint32_t CTRL1;                             /**< Control 1 Register, offset: 0x4 */
  volatile uint32_t TIMER;                             /**< Free Running Timer, offset: 0x8 */
  uint8_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[4];
  volatile uint32_t RXMGMASK;                          /**< Rx Mailboxes Global Mask Register, offset: 0x10 */
  volatile uint32_t RX14MASK;                          /**< Rx 14 Mask Register, offset: 0x14 */
  volatile uint32_t RX15MASK;                          /**< Rx 15 Mask Register, offset: 0x18 */
  volatile uint32_t ECR;                               /**< Error Counter, offset: 0x1C */
  volatile uint32_t ESR1;                              /**< Error and Status 1 Register, offset: 0x20 */
  volatile uint32_t IMASK2;                            /**< Interrupt Masks 2 Register, offset: 0x24 */
  volatile uint32_t IMASK1;                            /**< Interrupt Masks 1 Register, offset: 0x28 */
  volatile uint32_t IFLAG2;                            /**< w1c, Interrupt Flags 2 Register, offset: 0x2C */
  volatile uint32_t IFLAG1;                            /**< Interrupt Flags 1 Register, offset: 0x30 */
  volatile uint32_t CTRL2;                             /**< Control 2 Register, offset: 0x34 */
  const volatile uint32_t ESR2;                        /**< Error and Status 2 Register, offset: 0x38 */
  uint8_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[8];
  const volatile uint32_t CRCR;                        /**< CRC Register, offset: 0x44 */
  volatile uint32_t RXFGMASK;                          /**< Rx FIFO Global Mask Register, offset: 0x48 */
  const volatile uint32_t RXFIR;                       /**< Rx FIFO Information Register, offset: 0x4C */
  volatile uint32_t CBT;                               /**< CAN Bit Timing Register, offset: 0x50, available only on: CAN3 (missing on CAN1, CAN2) */
  uint8_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[4];
  const volatile uint32_t DBG1;                        /**< Debug 1 register, offset: 0x58, available only on: CAN1, CAN2 (missing on CAN3) */
  const volatile uint32_t DBG2;                        /**< Debug 2 register, offset: 0x5C, available only on: CAN1, CAN2 (missing on CAN3) */
  uint8_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[32];

  struct MB_8B_Layout {                            /* offset: 0x80, array step: 0x10 */
    volatile uint32_t CS;                                /**< Message Buffer 0 CS Register..Message Buffer 63 CS Register, array offset: 0x80, array step: 0x10, available only on: CAN3 (missing on CAN1, CAN2) */
    volatile uint32_t ID;                                /**< Message Buffer 0 ID Register..Message Buffer 63 ID Register, array offset: 0x84, array step: 0x10, available only on: CAN3 (missing on CAN1, CAN2) */
    volatile uint32_t WORD[kCAN_MB_SIZE_MB_8B_GROUP_MB_8B_WORD_8B_count];     /**< Message Buffer 0 WORD_8B Register..Message Buffer 63 WORD_8B Register, array offset: 0x88, array step: index*0x10, index2*0x4, available only on: CAN3 (missing on CAN1, CAN2) */
  };
  struct MB_16B_Layout {                           /* offset: 0x80 */
    struct {                                         /* offset: 0x80, array step: 0x18 */
      volatile uint32_t CS;                                /**< Message Buffer 0 CS Register..Message Buffer 20 CS Register, array offset: 0x80, array step: 0x18, available only on: CAN3 (missing on CAN1, CAN2) */
      volatile uint32_t ID;                                /**< Message Buffer 0 ID Register..Message Buffer 20 ID Register, array offset: 0x84, array step: 0x18, available only on: CAN3 (missing on CAN1, CAN2) */
      volatile uint32_t WORD[kCAN_MB_SIZE_MB_16B_MB_16B_L_WORD_16B_L_count];       /**< Message Buffer 0 WORD_16B Register..Message Buffer 20 WORD_16B Register, array offset: 0x88, array step: index*0x18, index2*0x4, available only on: CAN3 (missing on CAN1, CAN2) */
    } MB_16B_L[kCAN_MB_SIZE_MB_16B_MB_16B_L_count];
    uint8_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[8];
    struct {                                         /* offset: 0x280, array step: 0x18 */
      volatile uint32_t CS;                                /**< Message Buffer 0 CS Register..Message Buffer 20 CS Register, array offset: 0x280, array step: 0x18, available only on: CAN3 (missing on CAN1, CAN2) */
      volatile uint32_t ID;                                /**< Message Buffer 0 ID Register..Message Buffer 20 ID Register, array offset: 0x284, array step: 0x18, available only on: CAN3 (missing on CAN1, CAN2) */
      volatile uint32_t WORD[kCAN_MB_SIZE_MB_16B_MB_16B_H_WORD_16B_H_count];       /**< Message Buffer 0 WORD_16B Register..Message Buffer 20 WORD_16B Register, array offset: 0x288, array step: index*0x18, index2*0x4, available only on: CAN3 (missing on CAN1, CAN2) */
    } MB_16B_H[kCAN_MB_SIZE_MB_16B_MB_16B_H_count];
  };
  struct MB_32B_Layout {                           /* offset: 0x80 */
    struct {                                         /* offset: 0x80, array step: 0x28 */
      volatile uint32_t CS;                                /**< Message Buffer 0 CS Register..Message Buffer 11 CS Register, array offset: 0x80, array step: 0x28, available only on: CAN3 (missing on CAN1, CAN2) */
      volatile uint32_t ID;                                /**< Message Buffer 0 ID Register..Message Buffer 11 ID Register, array offset: 0x84, array step: 0x28, available only on: CAN3 (missing on CAN1, CAN2) */
      volatile uint32_t WORD[kCAN_MB_SIZE_MB_32B_MB_32B_L_WORD_32B_L_count];       /**< Message Buffer 0 WORD_32B Register..Message Buffer 11 WORD_32B Register, array offset: 0x88, array step: index*0x28, index2*0x4, available only on: CAN3 (missing on CAN1, CAN2) */
    } MB_32B_L[kCAN_MB_SIZE_MB_32B_MB_32B_L_count];
    uint8_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[32];
    struct {                                         /* offset: 0x280, array step: 0x28 */
      volatile uint32_t CS;                                /**< Message Buffer 0 CS Register..Message Buffer 11 CS Register, array offset: 0x280, array step: 0x28, available only on: CAN3 (missing on CAN1, CAN2) */
      volatile uint32_t ID;                                /**< Message Buffer 0 ID Register..Message Buffer 11 ID Register, array offset: 0x284, array step: 0x28, available only on: CAN3 (missing on CAN1, CAN2) */
      volatile uint32_t WORD[kCAN_MB_SIZE_MB_32B_MB_32B_H_WORD_32B_H_count];       /**< Message Buffer 0 WORD_32B Register..Message Buffer 11 WORD_32B Register, array offset: 0x288, array step: index*0x28, index2*0x4, available only on: CAN3 (missing on CAN1, CAN2) */
    } MB_32B_H[kCAN_MB_SIZE_MB_32B_MB_32B_H_count];
  };
  struct MB_64B_Layout {                           /* offset: 0x80 */
    struct {                                         /* offset: 0x80, array step: 0x48 */
      volatile uint32_t CS;                                /**< Message Buffer 0 CS Register..Message Buffer 6 CS Register, array offset: 0x80, array step: 0x48, available only on: CAN3 (missing on CAN1, CAN2) */
      volatile uint32_t ID;                                /**< Message Buffer 0 ID Register..Message Buffer 6 ID Register, array offset: 0x84, array step: 0x48, available only on: CAN3 (missing on CAN1, CAN2) */
      volatile uint32_t WORD[kCAN_MB_SIZE_MB_64B_MB_64B_L_WORD_64B_L_count];       /**< Message Buffer 0 WORD_64B Register..Message Buffer 6 WORD_64B Register, array offset: 0x88, array step: index*0x48, index2*0x4, available only on: CAN3 (missing on CAN1, CAN2) */
    } MB_64B_L[kCAN_MB_SIZE_MB_64B_MB_64B_L_count];
    uint8_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[8];
    struct {                                         /* offset: 0x280, array step: 0x48 */
      volatile uint32_t CS;                                /**< Message Buffer 0 CS Register..Message Buffer 6 CS Register, array offset: 0x280, array step: 0x48, available only on: CAN3 (missing on CAN1, CAN2) */
      volatile uint32_t ID;                                /**< Message Buffer 0 ID Register..Message Buffer 6 ID Register, array offset: 0x284, array step: 0x48, available only on: CAN3 (missing on CAN1, CAN2) */
      volatile uint32_t WORD[kCAN_MB_SIZE_MB_64B_MB_64B_H_WORD_64B_H_count];       /**< Message Buffer 0 WORD_64B Register..Message Buffer 6 WORD_64B Register, array offset: 0x288, array step: index*0x48, index2*0x4, available only on: CAN3 (missing on CAN1, CAN2) */
    } MB_64B_H[kCAN_MB_SIZE_MB_64B_MB_64B_H_count];
  };
  struct MB_Layout {                               /* offset: 0x80, array step: 0x10 */
    volatile uint32_t CS;                                /**< Message Buffer 0 CS Register..Message Buffer 63 CS Register, array offset: 0x80, array step: 0x10, available only on: CAN3 (missing on CAN1, CAN2) */
    volatile uint32_t ID;                                /**< Message Buffer 0 ID Register..Message Buffer 63 ID Register, array offset: 0x84, array step: 0x10, available only on: CAN3 (missing on CAN1, CAN2) */
    volatile uint32_t WORD0;                             /**< Message Buffer 0 WORD0 Register..Message Buffer 63 WORD0 Register, array offset: 0x88, array step: 0x10, available only on: CAN3 (missing on CAN1, CAN2) */
    volatile uint32_t WORD1;                             /**< Message Buffer 0 WORD1 Register..Message Buffer 63 WORD1 Register, array offset: 0x8C, array step: 0x10, available only on: CAN3 (missing on CAN1, CAN2) */
  };

  union {                                          /* offset: 0x80 */
    MB_8B_Layout MB_8B[kCAN_MB_SIZE_MB_8B_GROUP_MB_8B_count];
    MB_16B_Layout MB_16B;
    MB_32B_Layout MB_32B;
    MB_64B_Layout MB_64B;
    MB_Layout MB[kCAN_MB_SIZE_MB_GROUP_MB_count];
  };

  uint8_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1024];
  volatile uint32_t RXIMR[kCAN_RXIMR_count];            /**< Rx Individual Mask Registers, array offset: 0x880, array step: 0x4 */
  uint8_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[96];
  volatile uint32_t GFWR;                              /**< Glitch Filter Width Registers, offset: 0x9E0, available only on: CAN1, CAN2 (missing on CAN3) */
  uint8_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[540];
  volatile uint32_t FDCTRL;                            /**< CAN FD Control Register, offset: 0xC00, available only on: CAN3 (missing on CAN1, CAN2) */
  volatile uint32_t FDCBT;                             /**< CAN FD Bit Timing Register, offset: 0xC04, available only on: CAN3 (missing on CAN1, CAN2) */
  const volatile uint32_t FDCRC;                       /**< CAN FD CRC Register, offset: 0xC08, available only on: CAN3 (missing on CAN1, CAN2) */
};

constexpr size_t    kCAN_size  = 0xC0C;
constexpr uintptr_t kCAN1_base = 0x401D'0000;
constexpr uintptr_t kCAN2_base = 0x401D'4000;
constexpr uintptr_t kCAN3_base = 0x401D'8000;

namespace CAN1 {
constexpr regs::RegGroup<CAN_Layout, kCAN_size, kCAN1_base> group;
}  // namespace CAN1

namespace CAN2 {
constexpr regs::RegGroup<CAN_Layout, kCAN_size, kCAN2_base> group;
}  // namespace CAN2

namespace CAN3 {
constexpr regs::RegGroup<CAN_Layout, kCAN_size, kCAN3_base> group;
}  // namespace CAN3

namespace CAN1 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using CAN1_Reg =
    regs::Reg32<kCAN1_base, CAN_Layout, Member, 0, Bits, Shift, AssignMask>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>(),
          typename = std::enable_if_t<(Index < kCAN_RXIMR_count)>>
using RXIMR_Reg =
    regs::Reg32<kCAN1_base, CAN_Layout, &CAN_Layout::RXIMR, Index, Bits, Shift,
                AssignMask>;

// Module Configuration Register
namespace MCR {
constexpr CAN1_Reg<&CAN_Layout::MCR, 1, 31> MDIS;                    // Module Disable
    // 0b0..Enable the FlexCAN module.
    // 0b1..Disable the FlexCAN module.
constexpr CAN1_Reg<&CAN_Layout::MCR, 1, 30> FRZ;                     // Freeze Enable
    // 0b0..Not enabled to enter Freeze mode.
    // 0b1..Enabled to enter Freeze mode.
constexpr CAN1_Reg<&CAN_Layout::MCR, 1, 29> RFEN;                    // Rx FIFO Enable
    // 0b0..Rx FIFO not enabled.
    // 0b1..Rx FIFO enabled.
constexpr CAN1_Reg<&CAN_Layout::MCR, 1, 28> HALT;                    // Halt FlexCAN
    // 0b0..No Freeze Mode request.
    // 0b1..Enters Freeze Mode if the FRZ bit is asserted.
constexpr CAN1_Reg<regs::constify(&CAN_Layout::MCR), 1, 27> NOTRDY;  // FlexCAN Not Ready
    // 0b0..FlexCAN module is either in Normal mode, Listen-Only mode, or Loop-Back mode.
    // 0b1..FlexCAN module is either in Disable mode, Doze mode, Stop mode, or Freeze mode.
constexpr CAN1_Reg<&CAN_Layout::MCR, 1, 26> WAKMSK;                  // Wake Up Interrupt Mask
    // 0b0..Wake Up interrupt is disabled.
    // 0b1..Wake Up interrupt is enabled.
constexpr CAN1_Reg<&CAN_Layout::MCR, 1, 25> SOFTRST;                 // Soft Reset
    // 0b0..No reset request.
    // 0b1..Resets the registers affected by soft reset.
constexpr CAN1_Reg<regs::constify(&CAN_Layout::MCR), 1, 24> FRZACK;  // Freeze Mode Acknowledge
    // 0b0..FlexCAN not in Freeze mode, prescaler running.
    // 0b1..FlexCAN in Freeze mode, prescaler stopped.
constexpr CAN1_Reg<&CAN_Layout::MCR, 1, 23> SUPV;                    // Supervisor Mode
    // 0b0..FlexCAN is in User mode. Affected registers allow both Supervisor and Unrestricted accesses.
    // 0b1..FlexCAN is in Supervisor mode. Affected registers allow only Supervisor access. Unrestricted access
    //      behaves as though the access was done to an unimplemented register location.
constexpr CAN1_Reg<&CAN_Layout::MCR, 1, 22> SLFWAK;                  // Self Wake Up
    // 0b0..FlexCAN Self Wake Up feature is disabled.
    // 0b1..FlexCAN Self Wake Up feature is enabled.
constexpr CAN1_Reg<&CAN_Layout::MCR, 1, 21> WRNEN;                   // Warning Interrupt Enable
    // 0b0..TWRNINT and RWRNINT bits are zero, independent of the values in the error counters.
    // 0b1..TWRNINT and RWRNINT bits are set when the respective error counter transitions from less than 96 to greater than or equal to 96.
constexpr CAN1_Reg<regs::constify(&CAN_Layout::MCR), 1, 20> LPMACK;  // Low-Power Mode Acknowledge
    // 0b0..FLEXCAN not in any of the low power modes
    // 0b1..FLEXCAN is either in Disable Mode, or Stop mode
constexpr CAN1_Reg<&CAN_Layout::MCR, 1, 19> WAKSRC;                  // Wake Up Source
    // 0b0..FLEXCAN uses the unfiltered FLEXCAN_RX input to detect recessive to dominant edges on the CAN bus.
    // 0b1..FLEXCAN uses the filtered FLEXCAN_RX input to detect recessive to dominant edges on the CAN bus
constexpr CAN1_Reg<&CAN_Layout::MCR, 1, 18> DOZE;                    // Doze Mode Enable
    // 0b0..FlexCAN is not enabled to enter low-power mode when Doze mode is requested.
    // 0b1..FlexCAN is enabled to enter low-power mode when Doze mode is requested.
constexpr CAN1_Reg<&CAN_Layout::MCR, 1, 17> SRXDIS;                  // Self Reception Disable
    // 0b0..Self-reception enabled.
    // 0b1..Self-reception disabled.
constexpr CAN1_Reg<&CAN_Layout::MCR, 1, 16> IRMQ;                    // Individual Rx Masking And Queue Enable
    // 0b0..Individual Rx masking and queue feature are disabled. For backward compatibility with legacy
    //      applications, the reading of C/S word locks the MB even if it is EMPTY.
    // 0b1..Individual Rx masking and queue feature are enabled.
constexpr CAN1_Reg<&CAN_Layout::MCR, 1, 15> DMA;                     // DMA Enable
    // 0b0..DMA feature for RX FIFO disabled.
    // 0b1..DMA feature for RX FIFO enabled.
constexpr CAN1_Reg<&CAN_Layout::MCR, 1, 13> LPRIOEN;                 // Local Priority Enable
    // 0b0..Local Priority disabled.
    // 0b1..Local Priority enabled.
constexpr CAN1_Reg<&CAN_Layout::MCR, 1, 12> AEN;                     // Abort Enable
    // 0b0..Abort disabled.
    // 0b1..Abort enabled.
constexpr CAN1_Reg<&CAN_Layout::MCR, 1, 11> FDEN;                    // CAN FD operation enable
    // 0b0..CAN FD is disabled. FlexCAN is able to receive and transmit messages in CAN 2.0 format.
    // 0b1..CAN FD is enabled. FlexCAN is able to receive and transmit messages in both CAN FD and CAN 2.0 formats.
constexpr CAN1_Reg<&CAN_Layout::MCR, 2,  8> IDAM;                    // ID Acceptance Mode
    // 0b00..Format A: One full ID (standard and extended) per ID filter table element.
    // 0b01..Format B: Two full standard IDs or two partial 14-bit (standard and extended) IDs per ID filter table element.
    // 0b10..Format C: Four partial 8-bit standard IDs per ID filter table element.
    // 0b11..Format D: All frames rejected.
constexpr CAN1_Reg<&CAN_Layout::MCR, 7,  0> MAXMB;                   // Number Of The Last Message Buffer
}  // namespace MCR

// Control 1 Register
namespace CTRL1 {
constexpr CAN1_Reg<&CAN_Layout::CTRL1, 8, 24> PRESDIV;  // Prescaler Division Factor
constexpr CAN1_Reg<&CAN_Layout::CTRL1, 2, 22> RJW;      // Resync Jump Width
constexpr CAN1_Reg<&CAN_Layout::CTRL1, 3, 19> PSEG1;    // Phase Segment 1
constexpr CAN1_Reg<&CAN_Layout::CTRL1, 3, 16> PSEG2;    // Phase Segment 2
constexpr CAN1_Reg<&CAN_Layout::CTRL1, 1, 15> BOFFMSK;  // Bus Off Interrupt Mask
    // 0b0..Bus Off interrupt disabled.
    // 0b1..Bus Off interrupt enabled.
constexpr CAN1_Reg<&CAN_Layout::CTRL1, 1, 14> ERRMSK;   // Error Interrupt Mask
    // 0b0..Error interrupt disabled.
    // 0b1..Error interrupt enabled.
constexpr CAN1_Reg<&CAN_Layout::CTRL1, 1, 12> LPB;      // Loop Back Mode
    // 0b0..Loop Back disabled.
    // 0b1..Loop Back enabled.
constexpr CAN1_Reg<&CAN_Layout::CTRL1, 1, 11> TWRNMSK;  // Tx Warning Interrupt Mask
    // 0b0..Tx Warning interrupt disabled.
    // 0b1..Tx Warning interrupt enabled.
constexpr CAN1_Reg<&CAN_Layout::CTRL1, 1, 10> RWRNMSK;  // Rx Warning Interrupt Mask
    // 0b0..Rx Warning interrupt disabled.
    // 0b1..Rx Warning interrupt enabled.
constexpr CAN1_Reg<&CAN_Layout::CTRL1, 1,  7> SMP;      // CAN Bit Sampling
    // 0b0..Just one sample is used to determine the bit value.
    // 0b1..Three samples are used to determine the value of the received bit: the regular one (sample point) and two
    //      preceding samples; a majority rule is used.
constexpr CAN1_Reg<&CAN_Layout::CTRL1, 1,  6> BOFFREC;  // Bus Off Recovery
    // 0b0..Automatic recovering from Bus Off state enabled, according to CAN Spec 2.0 part B
    // 0b1..Automatic recovering from Bus Off state disabled
constexpr CAN1_Reg<&CAN_Layout::CTRL1, 1,  5> TSYN;     // Timer Sync
    // 0b0..Timer Sync feature disabled
    // 0b1..Timer Sync feature enabled
constexpr CAN1_Reg<&CAN_Layout::CTRL1, 1,  4> LBUF;     // Lowest Buffer Transmitted First
    // 0b0..Buffer with highest priority is transmitted first.
    // 0b1..Lowest number buffer is transmitted first.
constexpr CAN1_Reg<&CAN_Layout::CTRL1, 1,  3> LOM;      // Listen-Only Mode
    // 0b0..Listen-Only mode is deactivated.
    // 0b1..FlexCAN module operates in Listen-Only mode.
constexpr CAN1_Reg<&CAN_Layout::CTRL1, 3,  0> PROPSEG;  // Propagation Segment
}  // namespace CTRL1

// Free Running Timer
namespace TIMER {
constexpr CAN1_Reg<&CAN_Layout::TIMER, 16, 0> TIMER;  // Timer Value
}  // namespace TIMER

// Rx Mailboxes Global Mask register
namespace RXMGMASK {
constexpr CAN1_Reg<&CAN_Layout::RXMGMASK, 32, 0> MG;  // Rx Mailboxes Global Mask Bits
}  // namespace RXMGMASK

// Rx 14 Mask register
namespace RX14MASK {
constexpr CAN1_Reg<&CAN_Layout::RX14MASK, 32, 0> RX14M;  // Rx Buffer 14 Mask Bits
}  // namespace RX14MASK

// Rx 15 Mask register
namespace RX15MASK {
constexpr CAN1_Reg<&CAN_Layout::RX15MASK, 32, 0> RX15M;  // Rx Buffer 15 Mask Bits
}  // namespace RX15MASK

// Error Counter
namespace ECR {
constexpr CAN1_Reg<&CAN_Layout::ECR, 8, 24> RXERRCNT_FAST;   // Receive Error Counter for fast bits
    // Writable only with zero in Freeze mode
constexpr CAN1_Reg<&CAN_Layout::ECR, 8, 16> TXERRCNT_FAST;   // Transmit Error Counter for fast bits
    // Writable only with zero in Freeze mode
constexpr CAN1_Reg<&CAN_Layout::ECR, 8,  8> RX_ERR_COUNTER;  // Receive Error Counter
    // Writable only in Freeze mode
constexpr CAN1_Reg<&CAN_Layout::ECR, 8,  0> TX_ERR_COUNTER;  // Transmit Error Counter
    // Writable only in Freeze mode
}  // namespace ECR

// Error and Status 1 Register
namespace ESR1 {
constexpr CAN1_Reg<regs::constify(&CAN_Layout::ESR1), 1, 31> BIT1ERR_FAST;  // Bit1 Error in the Data Phase of CAN FD frames with the BRS bit set
    // 0b0..No such occurrence.
    // 0b1..At least one bit sent as recessive is received as dominant.
constexpr CAN1_Reg<regs::constify(&CAN_Layout::ESR1), 1, 30> BIT0ERR_FAST;  // Bit0 Error in the Data Phase of CAN FD frames with the BRS bit set
    // 0b0..No such occurrence.
    // 0b1..At least one bit sent as dominant is received as recessive.
constexpr CAN1_Reg<regs::constify(&CAN_Layout::ESR1), 1, 28> CRCERR_FAST;   // Cyclic Redundancy Check Error in the CRC field of CAN FD frames with the BRS bit set
    // 0b0..No such occurrence.
    // 0b1..A CRC error occurred since last read of this register.
constexpr CAN1_Reg<regs::constify(&CAN_Layout::ESR1), 1, 27> FRMERR_FAST;   // Form Error in the Data Phase of CAN FD frames with the BRS bit set
    // 0b0..No such occurrence.
    // 0b1..A form error occurred since last read of this register.
constexpr CAN1_Reg<regs::constify(&CAN_Layout::ESR1), 1, 26> STFERR_FAST;   // Stuffing Error in the Data Phase of CAN FD frames with the BRS bit set
    // 0b0..No such occurrence.
    // 0b1..A stuffing error occurred since last read of this register.
constexpr CAN1_Reg<&CAN_Layout::ESR1, 1, 21, 0x0> ERROVR;                   // Error Overrun
    // 0b0..Overrun has not occurred.
    // 0b1..Overrun has occurred.
constexpr CAN1_Reg<&CAN_Layout::ESR1, 1, 20, 0x0> ERRINT_FAST;              // Error interrupt for errors detected in Data Phase of CAN FD frames with BRS bit set
    // 0b0..No such occurrence.
    // 0b1..Indicates setting of any error bit detected in the data phase of CAN FD frames with the BRS bit set.
constexpr CAN1_Reg<&CAN_Layout::ESR1, 1, 19, 0x0> BOFFDONEINT;              // Bus Off Done Interrupt
    // 0b0..No such occurrence.
    // 0b1..FlexCAN module has completed Bus Off process.
constexpr CAN1_Reg<regs::constify(&CAN_Layout::ESR1), 1, 18> SYNCH;         // CAN Synchronization Status
    // 0b0..FlexCAN is not synchronized to the CAN bus.
    // 0b1..FlexCAN is synchronized to the CAN bus.
constexpr CAN1_Reg<&CAN_Layout::ESR1, 1, 17, 0x0> TWRNINT;                  // Tx Warning Interrupt Flag
    // 0b0..No such occurrence.
    // 0b1..The Tx error counter transitioned from less than 96 to greater than or equal to 96.
constexpr CAN1_Reg<&CAN_Layout::ESR1, 1, 16, 0x0> RWRNINT;                  // Rx Warning Interrupt Flag
    // 0b0..No such occurrence.
    // 0b1..The Rx error counter transitioned from less than 96 to greater than or equal to 96.
constexpr CAN1_Reg<regs::constify(&CAN_Layout::ESR1), 1, 15> BIT1ERR;       // Bit1 Error
    // 0b0..No such occurrence.
    // 0b1..At least one bit sent as recessive is received as dominant.
constexpr CAN1_Reg<regs::constify(&CAN_Layout::ESR1), 1, 14> BIT0ERR;       // Bit0 Error
    // 0b0..No such occurrence.
    // 0b1..At least one bit sent as dominant is received as recessive.
constexpr CAN1_Reg<regs::constify(&CAN_Layout::ESR1), 1, 13> ACKERR;        // Acknowledge Error
    // 0b0..No such occurrence.
    // 0b1..An ACK error occurred since last read of this register.
constexpr CAN1_Reg<regs::constify(&CAN_Layout::ESR1), 1, 12> CRCERR;        // Cyclic Redundancy Check Error
    // 0b0..No such occurrence.
    // 0b1..A CRC error occurred since last read of this register.
constexpr CAN1_Reg<regs::constify(&CAN_Layout::ESR1), 1, 11> FRMERR;        // Form Error
    // 0b0..No such occurrence.
    // 0b1..A Form Error occurred since last read of this register.
constexpr CAN1_Reg<regs::constify(&CAN_Layout::ESR1), 1, 10> STFERR;        // Stuffing Error
    // 0b0..No such occurrence.
    // 0b1..A Stuffing Error occurred since last read of this register.
constexpr CAN1_Reg<regs::constify(&CAN_Layout::ESR1), 1,  9> TXWRN;         // TX Error Warning
    // 0b0..No such occurrence.
    // 0b1..TXERRCNT is greater than or equal to 96.
constexpr CAN1_Reg<regs::constify(&CAN_Layout::ESR1), 1,  8> RXWRN;         // Rx Error Warning
    // 0b0..No such occurrence.
    // 0b1..RXERRCNT is greater than or equal to 96.
constexpr CAN1_Reg<regs::constify(&CAN_Layout::ESR1), 1,  7> IDLE;          // IDLE
    // 0b0..No such occurrence.
    // 0b1..CAN bus is now IDLE.
constexpr CAN1_Reg<regs::constify(&CAN_Layout::ESR1), 1,  6> TX;            // FlexCAN In Transmission
    // 0b0..FlexCAN is not transmitting a message.
    // 0b1..FlexCAN is transmitting a message.
constexpr CAN1_Reg<regs::constify(&CAN_Layout::ESR1), 2,  4> FLTCONF;       // Fault Confinement State
    // 0b00..Error Active
    // 0b01..Error Passive
    // 0b1x..Bus Off
constexpr CAN1_Reg<regs::constify(&CAN_Layout::ESR1), 1,  3> RX;            // FlexCAN In Reception
    // 0b0..FlexCAN is not receiving a message.
    // 0b1..FlexCAN is receiving a message.
constexpr CAN1_Reg<&CAN_Layout::ESR1, 1,  2, 0x0> BOFFINT;                  // Bus Off Interrupt
    // 0b0..No such occurrence.
    // 0b1..FlexCAN module entered Bus Off state.
constexpr CAN1_Reg<&CAN_Layout::ESR1, 1,  1, 0x0> ERRINT;                   // Error Interrupt
    // 0b0..No such occurrence.
    // 0b1..Indicates setting of any error bit in the Error and Status register.
constexpr CAN1_Reg<&CAN_Layout::ESR1, 1,  0, 0x0> WAKINT;                   // Wake-Up Interrupt
    // 0b0..No such occurrence
    // 0b1..Indicates a recessive to dominant transition received on the CAN bus when the FLEXCAN module is in Stop Mode
}  // namespace ESR1

// Interrupt Masks 2 register
namespace IMASK2 {
constexpr CAN1_Reg<&CAN_Layout::IMASK2, 32, 0> BUF63TO32M;  // Buffer MBi Mask
}  // namespace IMASK2

// Interrupt Masks 1 register
namespace IMASK1 {
constexpr CAN1_Reg<&CAN_Layout::IMASK1, 32, 0> BUF31TO0M;  // Buffer MBi Mask
}  // namespace IMASK1

// Interrupt Flags 2 register
namespace IFLAG2 {
constexpr CAN1_Reg<&CAN_Layout::IFLAG2, 32, 0, 0x0> BUF63TO32I;  // Buffer MBi Interrupt
}  // namespace IFLAG2

// Interrupt Flags 1 Register
namespace IFLAG1 {
constexpr CAN1_Reg<&CAN_Layout::IFLAG1, 24, 8, 0x0> BUF31TO8I;  // Buffer MBi Interrupt
    // 0b000000000000000000000000..No such occurrence
    // 0b000000000000000000000001..The corresponding MB has successfully completed transmission or reception
constexpr CAN1_Reg<&CAN_Layout::IFLAG1,  1, 7, 0x0> BUF7I;      // Buffer MB7 Interrupt Or Rx FIFO Overflow
    // 0b0..No occurrence of MB7 completing transmission/reception when MCR[RFEN]=0, or of Rx FIFO overflow when MCR[RFEN]=1
    // 0b1..MB7 completed transmission/reception when MCR[RFEN]=0, or Rx FIFO overflow when MCR[RFEN]=1
constexpr CAN1_Reg<&CAN_Layout::IFLAG1,  1, 6, 0x0> BUF6I;      // Buffer MB6 Interrupt Or Rx FIFO Warning
    // 0b0..No occurrence of MB6 completing transmission/reception when MCR[RFEN]=0, or of Rx FIFO almost full when MCR[RFEN]=1
    // 0b1..MB6 completed transmission/reception when MCR[RFEN]=0, or Rx FIFO almost full when MCR[RFEN]=1
constexpr CAN1_Reg<&CAN_Layout::IFLAG1,  1, 5, 0x0> BUF5I;      // Buffer MB5 Interrupt Or Frames available in Rx FIFO
    // 0b0..No occurrence of MB5 completing transmission/reception when MCR[RFEN]=0, or of frame(s) available in the FIFO, when MCR[RFEN]=1
    // 0b1..MB5 completed transmission/reception when MCR[RFEN]=0, or frame(s) available in the Rx FIFO when
    //      MCR[RFEN]=1. It generates a DMA request in case of MCR[RFEN] and MCR[DMA] are enabled.
constexpr CAN1_Reg<&CAN_Layout::IFLAG1,  4, 1, 0x0> BUF4TO1I;   // Buffer MBi Interrupt Or Reserved
constexpr CAN1_Reg<&CAN_Layout::IFLAG1,  1, 0, 0x0> BUF0I;      // Buffer MB0 Interrupt Or Clear FIFO bit
    // 0b0..The corresponding buffer has no occurrence of successfully completed transmission or reception when MCR[RFEN]=0.
    // 0b1..The corresponding buffer has successfully completed transmission or reception when MCR[RFEN]=0.
constexpr CAN1_Reg<&CAN_Layout::IFLAG1,  5, 0, 0x0> BUF4TO0I;   // If the Rx FIFO is not enabled, these bits flag the interrupts for MB0 to MB4
    // 0b00000..No such occurrence
    // 0b00001..Corresponding MB completed transmission/reception
}  // namespace IFLAG1

// Control 2 Register
namespace CTRL2 {
constexpr CAN1_Reg<&CAN_Layout::CTRL2, 1, 31> ERRMSK_FAST;  // Error Interrupt Mask for errors detected in the data phase of fast CAN FD frames
    // 0b0..ERRINT_FAST error interrupt disabled.
    // 0b1..ERRINT_FAST error interrupt enabled.
constexpr CAN1_Reg<&CAN_Layout::CTRL2, 1, 30> BOFFDONEMSK;  // Bus Off Done Interrupt Mask
    // 0b0..Bus off done interrupt disabled.
    // 0b1..Bus off done interrupt enabled.
constexpr CAN1_Reg<&CAN_Layout::CTRL2, 1, 28> WRMFRZ;       // Enable unrestricted write access to FlexCAN memory in Freeze mode
    // 0b0..Keep the write access restricted in some regions of FlexCAN memory
    // 0b1..Enable unrestricted write access to FlexCAN memory
constexpr CAN1_Reg<&CAN_Layout::CTRL2, 4, 24> RFFN;         // Number Of Rx FIFO Filters
constexpr CAN1_Reg<&CAN_Layout::CTRL2, 5, 19> TASD;         // Tx Arbitration Start Delay
constexpr CAN1_Reg<&CAN_Layout::CTRL2, 1, 18> MRP;          // Mailboxes Reception Priority
    // 0b0..Matching starts from Rx FIFO and continues on mailboxes.
    // 0b1..Matching starts from mailboxes and continues on Rx FIFO.
constexpr CAN1_Reg<&CAN_Layout::CTRL2, 1, 17> RRS;          // Remote Request Storing
    // 0b0..Remote response frame is generated.
    // 0b1..Remote request frame is stored.
constexpr CAN1_Reg<&CAN_Layout::CTRL2, 1, 16> EACEN;        // Entire Frame Arbitration Field Comparison Enable For Rx Mailboxes
    // 0b0..Rx Mailbox filter's IDE bit is always compared and RTR is never compared despite mask bits.
    // 0b1..Enables the comparison of both Rx Mailbox filter's IDE and RTR bit with their corresponding bits within
    //      the incoming frame. Mask bits do apply.
constexpr CAN1_Reg<&CAN_Layout::CTRL2, 1, 15> TIMER_SRC;    // Timer Source
    // 0b0..The free running timer is clocked by the CAN bit clock, which defines the baud rate on the CAN bus.
    // 0b1..The free running timer is clocked by an external time tick. The period can be either adjusted to be equal
    //      to the baud rate on the CAN bus, or a different value as required. See the device-specific section for
    //      details about the external time tick.
constexpr CAN1_Reg<&CAN_Layout::CTRL2, 1, 14> PREXCEN;      // Protocol Exception Enable
    // 0b0..Protocol exception is disabled.
    // 0b1..Protocol exception is enabled.
constexpr CAN1_Reg<&CAN_Layout::CTRL2, 1, 12> ISOCANFDEN;   // ISO CAN FD Enable
    // 0b0..FlexCAN operates using the non-ISO CAN FD protocol.
    // 0b1..FlexCAN operates using the ISO CAN FD protocol (ISO 11898-1).
constexpr CAN1_Reg<&CAN_Layout::CTRL2, 1, 11> EDFLTDIS;     // Edge Filter Disable
    // 0b0..Edge filter is enabled
    // 0b1..Edge filter is disabled
}  // namespace CTRL2

// Error and Status 2 Register
namespace ESR2 {
constexpr CAN1_Reg<&CAN_Layout::ESR2, 7, 16> LPTM;  // Lowest Priority Tx Mailbox
constexpr CAN1_Reg<&CAN_Layout::ESR2, 1, 14> VPS;   // Valid Priority Status
    // 0b0..Contents of IMB and LPTM are invalid.
    // 0b1..Contents of IMB and LPTM are valid.
constexpr CAN1_Reg<&CAN_Layout::ESR2, 1, 13> IMB;   // Inactive Mailbox
    // 0b0..If ESR2[VPS] is asserted, the ESR2[LPTM] is not an inactive Mailbox.
    // 0b1..If ESR2[VPS] is asserted, there is at least one inactive Mailbox. LPTM content is the number of the first one.
}  // namespace ESR2

// CRC Register
namespace CRCR {
constexpr CAN1_Reg<&CAN_Layout::CRCR,  7, 16> MBCRC;  // CRC Mailbox
constexpr CAN1_Reg<&CAN_Layout::CRCR, 15,  0> TXCRC;  // Transmitted CRC value
}  // namespace CRCR

// Rx FIFO Global Mask register
namespace RXFGMASK {
constexpr CAN1_Reg<&CAN_Layout::RXFGMASK, 32, 0> FGM;  // Rx FIFO Global Mask Bits
}  // namespace RXFGMASK

// Rx FIFO Information Register
namespace RXFIR {
constexpr CAN1_Reg<&CAN_Layout::RXFIR, 9, 0> IDHIT;  // Identifier Acceptance Filter Hit Indicator
}  // namespace RXFIR

// Debug 1 register
namespace DBG1 {
constexpr CAN1_Reg<&CAN_Layout::DBG1, 5, 24> CBN;   // CAN Bit Number
constexpr CAN1_Reg<&CAN_Layout::DBG1, 6,  0> CFSM;  // CAN Finite State Machine
}  // namespace DBG1

// Debug 2 register
namespace DBG2 {
constexpr CAN1_Reg<&CAN_Layout::DBG2, 1, 15> APP;  // Arbitration Process in Progress
    // 0b0..No matching process ongoing.
    // 0b1..Matching process is in progress.
constexpr CAN1_Reg<&CAN_Layout::DBG2, 7,  8> TAP;  // Tx Arbitration Pointer
constexpr CAN1_Reg<&CAN_Layout::DBG2, 1,  7> MPP;  // Matching Process in Progress
    // 0b0..No matching process ongoing.
    // 0b1..Matching process is in progress.
constexpr CAN1_Reg<&CAN_Layout::DBG2, 7,  0> RMP;  // Rx Matching Pointer
}  // namespace DBG2

// Rx Individual Mask Registers
namespace RXIMR {
template <size_t Index>
constexpr RXIMR_Reg<Index, 32, 0> MI;  // Individual Mask Bits
    // 0b00000000000000000000000000000000..the corresponding bit in the filter is "don't care"
    // 0b00000000000000000000000000000001..The corresponding bit in the filter is checked
}  // namespace RXIMR

// Glitch Filter Width Registers
namespace GFWR {
constexpr CAN1_Reg<&CAN_Layout::GFWR, 8, 0> GFWR;  // It determines the Glitch Filter Width
}  // namespace GFWR

}  // namespace CAN1

namespace CAN2 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using CAN2_Reg =
    regs::Reg32<kCAN2_base, CAN_Layout, Member, 0, Bits, Shift, AssignMask>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>(),
          typename = std::enable_if_t<(Index < kCAN_RXIMR_count)>>
using RXIMR_Reg =
    regs::Reg32<kCAN2_base, CAN_Layout, &CAN_Layout::RXIMR, Index, Bits, Shift,
                AssignMask>;

// CAN2 Module Configuration Register
namespace MCR {
constexpr CAN2_Reg<&CAN_Layout::MCR, 1, 31> MDIS;
constexpr CAN2_Reg<&CAN_Layout::MCR, 1, 30> FRZ;
constexpr CAN2_Reg<&CAN_Layout::MCR, 1, 29> RFEN;
constexpr CAN2_Reg<&CAN_Layout::MCR, 1, 28> HALT;
constexpr CAN2_Reg<regs::constify(&CAN_Layout::MCR), 1, 27> NOTRDY;
constexpr CAN2_Reg<&CAN_Layout::MCR, 1, 26> WAKMSK;
constexpr CAN2_Reg<&CAN_Layout::MCR, 1, 25> SOFTRST;
constexpr CAN2_Reg<regs::constify(&CAN_Layout::MCR), 1, 24> FRZACK;
constexpr CAN2_Reg<&CAN_Layout::MCR, 1, 23> SUPV;
constexpr CAN2_Reg<&CAN_Layout::MCR, 1, 22> SLFWAK;
constexpr CAN2_Reg<&CAN_Layout::MCR, 1, 21> WRNEN;
constexpr CAN2_Reg<regs::constify(&CAN_Layout::MCR), 1, 20> LPMACK;
constexpr CAN2_Reg<&CAN_Layout::MCR, 1, 19> WAKSRC;
constexpr CAN2_Reg<&CAN_Layout::MCR, 1, 18> DOZE;
constexpr CAN2_Reg<&CAN_Layout::MCR, 1, 17> SRXDIS;
constexpr CAN2_Reg<&CAN_Layout::MCR, 1, 16> IRMQ;
constexpr CAN2_Reg<&CAN_Layout::MCR, 1, 15> DMA;
constexpr CAN2_Reg<&CAN_Layout::MCR, 1, 13> LPRIOEN;
constexpr CAN2_Reg<&CAN_Layout::MCR, 1, 12> AEN;
constexpr CAN2_Reg<&CAN_Layout::MCR, 1, 11> FDEN;
constexpr CAN2_Reg<&CAN_Layout::MCR, 2,  8> IDAM;
constexpr CAN2_Reg<&CAN_Layout::MCR, 7,  0> MAXMB;
}  // namespace MCR

// CAN2 Control 1 Register
namespace CTRL1 {
constexpr CAN2_Reg<&CAN_Layout::CTRL1, 8, 24> PRESDIV;
constexpr CAN2_Reg<&CAN_Layout::CTRL1, 2, 22> RJW;
constexpr CAN2_Reg<&CAN_Layout::CTRL1, 3, 19> PSEG1;
constexpr CAN2_Reg<&CAN_Layout::CTRL1, 3, 16> PSEG2;
constexpr CAN2_Reg<&CAN_Layout::CTRL1, 1, 15> BOFFMSK;
constexpr CAN2_Reg<&CAN_Layout::CTRL1, 1, 14> ERRMSK;
constexpr CAN2_Reg<&CAN_Layout::CTRL1, 1, 12> LPB;
constexpr CAN2_Reg<&CAN_Layout::CTRL1, 1, 11> TWRNMSK;
constexpr CAN2_Reg<&CAN_Layout::CTRL1, 1, 10> RWRNMSK;
constexpr CAN2_Reg<&CAN_Layout::CTRL1, 1,  7> SMP;
constexpr CAN2_Reg<&CAN_Layout::CTRL1, 1,  6> BOFFREC;
constexpr CAN2_Reg<&CAN_Layout::CTRL1, 1,  5> TSYN;
constexpr CAN2_Reg<&CAN_Layout::CTRL1, 1,  4> LBUF;
constexpr CAN2_Reg<&CAN_Layout::CTRL1, 1,  3> LOM;
constexpr CAN2_Reg<&CAN_Layout::CTRL1, 3,  0> PROPSEG;
}  // namespace CTRL1

// CAN2 Free Running Timer
namespace TIMER {
constexpr CAN2_Reg<&CAN_Layout::TIMER, 16,  0> TIMER;
}  // namespace TIMER

// CAN2 Rx Mailboxes Global Mask register
namespace RXMGMASK {
constexpr CAN2_Reg<&CAN_Layout::RXMGMASK, 32, 0> MG;
}  // namespace RXMGMASK

// CAN2 Rx 14 Mask register
namespace RX14MASK {
constexpr CAN2_Reg<&CAN_Layout::RX14MASK, 32, 0> RX14M;
}  // namespace RX14MASK

// CAN2 Rx 15 Mask register
namespace RX15MASK {
constexpr CAN2_Reg<&CAN_Layout::RX15MASK, 32, 0> RX15M;
}  // namespace RX15MASK

// CAN2 Error Counter
namespace ECR {
constexpr CAN2_Reg<&CAN_Layout::ECR, 8, 24> RXERRCNT_FAST;
constexpr CAN2_Reg<&CAN_Layout::ECR, 8, 16> TXERRCNT_FAST;
constexpr CAN2_Reg<&CAN_Layout::ECR, 8,  8> RX_ERR_COUNTER;
constexpr CAN2_Reg<&CAN_Layout::ECR, 8,  0> TX_ERR_COUNTER;
}  // namespace ECR

// CAN2 Error and Status 1 Register
namespace ESR1 {
constexpr CAN2_Reg<regs::constify(&CAN_Layout::ESR1), 1, 31> BIT1ERR_FAST;
constexpr CAN2_Reg<regs::constify(&CAN_Layout::ESR1), 1, 30> BIT0ERR_FAST;
constexpr CAN2_Reg<regs::constify(&CAN_Layout::ESR1), 1, 28> CRCERR_FAST;
constexpr CAN2_Reg<regs::constify(&CAN_Layout::ESR1), 1, 27> FRMERR_FAST;
constexpr CAN2_Reg<regs::constify(&CAN_Layout::ESR1), 1, 26> STFERR_FAST;
constexpr CAN2_Reg<&CAN_Layout::ESR1, 1, 21, 0x0> ERROVR;
constexpr CAN2_Reg<&CAN_Layout::ESR1, 1, 20, 0x0> ERRINT_FAST;
constexpr CAN2_Reg<&CAN_Layout::ESR1, 1, 19, 0x0> BOFFDONEINT;
constexpr CAN2_Reg<regs::constify(&CAN_Layout::ESR1), 1, 18> SYNCH;
constexpr CAN2_Reg<&CAN_Layout::ESR1, 1, 17, 0x0> TWRNINT;
constexpr CAN2_Reg<&CAN_Layout::ESR1, 1, 16, 0x0> RWRNINT;
constexpr CAN2_Reg<regs::constify(&CAN_Layout::ESR1), 1, 15> BIT1ERR;
constexpr CAN2_Reg<regs::constify(&CAN_Layout::ESR1), 1, 14> BIT0ERR;
constexpr CAN2_Reg<regs::constify(&CAN_Layout::ESR1), 1, 13> ACKERR;
constexpr CAN2_Reg<regs::constify(&CAN_Layout::ESR1), 1, 12> CRCERR;
constexpr CAN2_Reg<regs::constify(&CAN_Layout::ESR1), 1, 11> FRMERR;
constexpr CAN2_Reg<regs::constify(&CAN_Layout::ESR1), 1, 10> STFERR;
constexpr CAN2_Reg<regs::constify(&CAN_Layout::ESR1), 1,  9> TXWRN;
constexpr CAN2_Reg<regs::constify(&CAN_Layout::ESR1), 1,  8> RXWRN;
constexpr CAN2_Reg<regs::constify(&CAN_Layout::ESR1), 1,  7> IDLE;
constexpr CAN2_Reg<regs::constify(&CAN_Layout::ESR1), 1,  6> TX;
constexpr CAN2_Reg<regs::constify(&CAN_Layout::ESR1), 2,  4> FLTCONF;
constexpr CAN2_Reg<regs::constify(&CAN_Layout::ESR1), 1,  3> RX;
constexpr CAN2_Reg<&CAN_Layout::ESR1, 1,  2, 0x0> BOFFINT;
constexpr CAN2_Reg<&CAN_Layout::ESR1, 1,  1, 0x0> ERRINT;
constexpr CAN2_Reg<&CAN_Layout::ESR1, 1,  0, 0x0> WAKINT;
}  // namespace ESR1

// CAN2 Interrupt Masks 2 register
namespace IMASK2 {
constexpr CAN2_Reg<&CAN_Layout::IMASK2, 32, 0> BUF63TO32M;
}  // namespace IMASK2

// CAN2 Interrupt Masks 1 register
namespace IMASK1 {
constexpr CAN2_Reg<&CAN_Layout::IMASK1, 32, 0> BUF31TO0M;
}  // namespace IMASK1

// CAN2 Interrupt Flags 2 register
namespace IFLAG2 {
constexpr CAN2_Reg<&CAN_Layout::IFLAG2, 32, 0, 0x0> BUF63TO32I;
}  // namespace IFLAG2

// CAN2 Interrupt Flags 1 Register
namespace IFLAG1 {
constexpr CAN2_Reg<&CAN_Layout::IFLAG1, 24, 8, 0x0> BUF31TO8I;
constexpr CAN2_Reg<&CAN_Layout::IFLAG1,  1, 7, 0x0> BUF7I;
constexpr CAN2_Reg<&CAN_Layout::IFLAG1,  1, 6, 0x0> BUF6I;
constexpr CAN2_Reg<&CAN_Layout::IFLAG1,  1, 5, 0x0> BUF5I;
constexpr CAN2_Reg<&CAN_Layout::IFLAG1,  4, 1, 0x0> BUF4TO1I;
constexpr CAN2_Reg<&CAN_Layout::IFLAG1,  1, 0, 0x0> BUF0I;
constexpr CAN2_Reg<&CAN_Layout::IFLAG1,  5, 0, 0x0> BUF4TO0I;
}  // namespace IFLAG1

// CAN2 Control 2 Register
namespace CTRL2 {
constexpr CAN2_Reg<&CAN_Layout::CTRL2, 1, 31> ERRMSK_FAST;
constexpr CAN2_Reg<&CAN_Layout::CTRL2, 1, 30> BOFFDONEMSK;
constexpr CAN2_Reg<&CAN_Layout::CTRL2, 1, 28> WRMFRZ;
constexpr CAN2_Reg<&CAN_Layout::CTRL2, 4, 24> RFFN;
constexpr CAN2_Reg<&CAN_Layout::CTRL2, 5, 19> TASD;
constexpr CAN2_Reg<&CAN_Layout::CTRL2, 1, 18> MRP;
constexpr CAN2_Reg<&CAN_Layout::CTRL2, 1, 17> RRS;
constexpr CAN2_Reg<&CAN_Layout::CTRL2, 1, 16> EACEN;
constexpr CAN2_Reg<&CAN_Layout::CTRL2, 1, 15> TIMER_SRC;
constexpr CAN2_Reg<&CAN_Layout::CTRL2, 1, 14> PREXCEN;
constexpr CAN2_Reg<&CAN_Layout::CTRL2, 1, 12> ISOCANFDEN;
constexpr CAN2_Reg<&CAN_Layout::CTRL2, 1, 11> EDFLTDIS;
}  // namespace CTRL2

// CAN2 Error and Status 2 Register
namespace ESR2 {
constexpr CAN2_Reg<&CAN_Layout::ESR2, 7, 16> LPTM;
constexpr CAN2_Reg<&CAN_Layout::ESR2, 1, 14> VPS;
constexpr CAN2_Reg<&CAN_Layout::ESR2, 1, 13> IMB;
}  // namespace ESR2

// CAN2 CRC Register
namespace CRCR {
constexpr CAN2_Reg<&CAN_Layout::CRCR,  7, 16> MBCRC;
constexpr CAN2_Reg<&CAN_Layout::CRCR, 15,  0> TXCRC;
}  // namespace CRCR

// CAN2 Rx FIFO Global Mask register
namespace RXFGMASK {
constexpr CAN2_Reg<&CAN_Layout::RXFGMASK, 32, 0> FGM;
}  // namespace RXFGMASK

// CAN2 Rx FIFO Information Register
namespace RXFIR {
constexpr CAN2_Reg<&CAN_Layout::RXFIR, 9, 0> IDHIT;
}  // namespace RXFIR

// CAN2 Debug 1 register
namespace DBG1 {
constexpr CAN2_Reg<&CAN_Layout::DBG1, 5, 24> CBN;
constexpr CAN2_Reg<&CAN_Layout::DBG1, 6,  0> CFSM;
}  // namespace DBG1

// CAN2 Debug 2 register
namespace DBG2 {
constexpr CAN2_Reg<&CAN_Layout::DBG2, 1, 15> APP;
constexpr CAN2_Reg<&CAN_Layout::DBG2, 7,  8> TAP;
constexpr CAN2_Reg<&CAN_Layout::DBG2, 1,  7> MPP;
constexpr CAN2_Reg<&CAN_Layout::DBG2, 7,  0> RMP;
}  // namespace DBG2

// CAN2 Rx Individual Mask Registers
namespace RXIMR {
template <size_t Index>
constexpr RXIMR_Reg<Index, 32, 0> MI;
}  // namespace RXIMR

// CAN2 Glitch Filter Width Registers
namespace GFWR {
constexpr CAN2_Reg<&CAN_Layout::GFWR, 8, 0> GFWR;
}  // namespace GFWR

}  // namespace CAN2

namespace CAN3 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using CAN3_Reg =
    regs::Reg32<kCAN3_base, CAN_Layout, Member, 0, Bits, Shift, AssignMask>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>(),
          typename = std::enable_if_t<(Index < kCAN_RXIMR_count)>>
using RXIMR_Reg =
    regs::Reg32<kCAN3_base, CAN_Layout, &CAN_Layout::RXIMR, Index, Bits, Shift,
                AssignMask>;

// CAN3 Module Configuration Register
namespace MCR {
constexpr CAN3_Reg<&CAN_Layout::MCR, 1, 31> MDIS;
constexpr CAN3_Reg<&CAN_Layout::MCR, 1, 30> FRZ;
constexpr CAN3_Reg<&CAN_Layout::MCR, 1, 29> RFEN;
constexpr CAN3_Reg<&CAN_Layout::MCR, 1, 28> HALT;
constexpr CAN3_Reg<regs::constify(&CAN_Layout::MCR), 1, 27> NOTRDY;
constexpr CAN3_Reg<&CAN_Layout::MCR, 1, 26> WAKMSK;
constexpr CAN3_Reg<&CAN_Layout::MCR, 1, 25> SOFTRST;
constexpr CAN3_Reg<regs::constify(&CAN_Layout::MCR), 1, 24> FRZACK;
constexpr CAN3_Reg<&CAN_Layout::MCR, 1, 23> SUPV;
constexpr CAN3_Reg<&CAN_Layout::MCR, 1, 22> SLFWAK;
constexpr CAN3_Reg<&CAN_Layout::MCR, 1, 21> WRNEN;
constexpr CAN3_Reg<regs::constify(&CAN_Layout::MCR), 1, 20> LPMACK;
constexpr CAN3_Reg<&CAN_Layout::MCR, 1, 19> WAKSRC;
constexpr CAN3_Reg<&CAN_Layout::MCR, 1, 18> DOZE;
constexpr CAN3_Reg<&CAN_Layout::MCR, 1, 17> SRXDIS;
constexpr CAN3_Reg<&CAN_Layout::MCR, 1, 16> IRMQ;
constexpr CAN3_Reg<&CAN_Layout::MCR, 1, 15> DMA;
constexpr CAN3_Reg<&CAN_Layout::MCR, 1, 13> LPRIOEN;
constexpr CAN3_Reg<&CAN_Layout::MCR, 1, 12> AEN;
constexpr CAN3_Reg<&CAN_Layout::MCR, 1, 11> FDEN;
constexpr CAN3_Reg<&CAN_Layout::MCR, 2,  8> IDAM;
constexpr CAN3_Reg<&CAN_Layout::MCR, 7,  0> MAXMB;
}  // namespace MCR

// CAN3 Control 1 Register
namespace CTRL1 {
constexpr CAN3_Reg<&CAN_Layout::CTRL1, 8, 24> PRESDIV;
constexpr CAN3_Reg<&CAN_Layout::CTRL1, 2, 22> RJW;
constexpr CAN3_Reg<&CAN_Layout::CTRL1, 3, 19> PSEG1;
constexpr CAN3_Reg<&CAN_Layout::CTRL1, 3, 16> PSEG2;
constexpr CAN3_Reg<&CAN_Layout::CTRL1, 1, 15> BOFFMSK;
constexpr CAN3_Reg<&CAN_Layout::CTRL1, 1, 14> ERRMSK;
constexpr CAN3_Reg<&CAN_Layout::CTRL1, 1, 12> LPB;
constexpr CAN3_Reg<&CAN_Layout::CTRL1, 1, 11> TWRNMSK;
constexpr CAN3_Reg<&CAN_Layout::CTRL1, 1, 10> RWRNMSK;
constexpr CAN3_Reg<&CAN_Layout::CTRL1, 1,  7> SMP;
constexpr CAN3_Reg<&CAN_Layout::CTRL1, 1,  6> BOFFREC;
constexpr CAN3_Reg<&CAN_Layout::CTRL1, 1,  5> TSYN;
constexpr CAN3_Reg<&CAN_Layout::CTRL1, 1,  4> LBUF;
constexpr CAN3_Reg<&CAN_Layout::CTRL1, 1,  3> LOM;
constexpr CAN3_Reg<&CAN_Layout::CTRL1, 3,  0> PROPSEG;
}  // namespace CTRL1

// CAN3 Free Running Timer
namespace TIMER {
constexpr CAN3_Reg<&CAN_Layout::TIMER, 16, 0> TIMER;
}  // namespace TIMER

// CAN3 Rx Mailboxes Global Mask register
namespace RXMGMASK {
constexpr CAN3_Reg<&CAN_Layout::RXMGMASK, 32, 0> MG;
}  // namespace RXMGMASK

// CAN3 Rx 14 Mask register
namespace RX14MASK {
constexpr CAN3_Reg<&CAN_Layout::RX14MASK, 32, 0> RX14M;
}  // namespace RX14MASK

// CAN3 Rx 15 Mask register
namespace RX15MASK {
constexpr CAN3_Reg<&CAN_Layout::RX15MASK, 32, 0> RX15M;
}  // namespace RX15MASK

// CAN3 Error Counter
namespace ECR {
constexpr CAN3_Reg<&CAN_Layout::ECR, 8, 24> RXERRCNT_FAST;
constexpr CAN3_Reg<&CAN_Layout::ECR, 8, 16> TXERRCNT_FAST;
constexpr CAN3_Reg<&CAN_Layout::ECR, 8,  8> RX_ERR_COUNTER;
constexpr CAN3_Reg<&CAN_Layout::ECR, 8,  0> TX_ERR_COUNTER;
}  // namespace ECR

// CAN3 Error and Status 1 Register
namespace ESR1 {
constexpr CAN3_Reg<regs::constify(&CAN_Layout::ESR1), 1, 31> BIT1ERR_FAST;
constexpr CAN3_Reg<regs::constify(&CAN_Layout::ESR1), 1, 30> BIT0ERR_FAST;
constexpr CAN3_Reg<regs::constify(&CAN_Layout::ESR1), 1, 28> CRCERR_FAST;
constexpr CAN3_Reg<regs::constify(&CAN_Layout::ESR1), 1, 27> FRMERR_FAST;
constexpr CAN3_Reg<regs::constify(&CAN_Layout::ESR1), 1, 26> STFERR_FAST;
constexpr CAN3_Reg<&CAN_Layout::ESR1, 1, 21, 0x0> ERROVR;
constexpr CAN3_Reg<&CAN_Layout::ESR1, 1, 20, 0x0> ERRINT_FAST;
constexpr CAN3_Reg<&CAN_Layout::ESR1, 1, 19, 0x0> BOFFDONEINT;
constexpr CAN3_Reg<regs::constify(&CAN_Layout::ESR1), 1, 18> SYNCH;
constexpr CAN3_Reg<&CAN_Layout::ESR1, 1, 17, 0x0> TWRNINT;
constexpr CAN3_Reg<&CAN_Layout::ESR1, 1, 16, 0x0> RWRNINT;
constexpr CAN3_Reg<regs::constify(&CAN_Layout::ESR1), 1, 15> BIT1ERR;
constexpr CAN3_Reg<regs::constify(&CAN_Layout::ESR1), 1, 14> BIT0ERR;
constexpr CAN3_Reg<regs::constify(&CAN_Layout::ESR1), 1, 13> ACKERR;
constexpr CAN3_Reg<regs::constify(&CAN_Layout::ESR1), 1, 12> CRCERR;
constexpr CAN3_Reg<regs::constify(&CAN_Layout::ESR1), 1, 11> FRMERR;
constexpr CAN3_Reg<regs::constify(&CAN_Layout::ESR1), 1, 10> STFERR;
constexpr CAN3_Reg<regs::constify(&CAN_Layout::ESR1), 1,  9> TXWRN;
constexpr CAN3_Reg<regs::constify(&CAN_Layout::ESR1), 1,  8> RXWRN;
constexpr CAN3_Reg<regs::constify(&CAN_Layout::ESR1), 1,  7> IDLE;
constexpr CAN3_Reg<regs::constify(&CAN_Layout::ESR1), 1,  6> TX;
constexpr CAN3_Reg<regs::constify(&CAN_Layout::ESR1), 2,  4> FLTCONF;
constexpr CAN3_Reg<regs::constify(&CAN_Layout::ESR1), 1,  3> RX;
constexpr CAN3_Reg<&CAN_Layout::ESR1, 1,  2, 0x0> BOFFINT;
constexpr CAN3_Reg<&CAN_Layout::ESR1, 1,  1, 0x0> ERRINT;
constexpr CAN3_Reg<&CAN_Layout::ESR1, 1,  0, 0x0> WAKINT;
}  // namespace ESR1

// CAN3 Interrupt Masks 2 register
namespace IMASK2 {
constexpr CAN3_Reg<&CAN_Layout::IMASK2, 32, 0> BUF63TO32M;
}  // namespace IMASK2

// CAN3 Interrupt Masks 1 register
namespace IMASK1 {
constexpr CAN3_Reg<&CAN_Layout::IMASK1, 32, 0> BUF31TO0M;
}  // namespace IMASK1

// CAN3 Interrupt Flags 2 register
namespace IFLAG2 {
constexpr CAN3_Reg<&CAN_Layout::IFLAG2, 32, 0, 0x0> BUF63TO32I;
}  // namespace IFLAG2

// CAN3 Interrupt Flags 1 Register
namespace IFLAG1 {
constexpr CAN3_Reg<&CAN_Layout::IFLAG1, 24, 8, 0x0> BUF31TO8I;
constexpr CAN3_Reg<&CAN_Layout::IFLAG1,  1, 7, 0x0> BUF7I;
constexpr CAN3_Reg<&CAN_Layout::IFLAG1,  1, 6, 0x0> BUF6I;
constexpr CAN3_Reg<&CAN_Layout::IFLAG1,  1, 5, 0x0> BUF5I;
constexpr CAN3_Reg<&CAN_Layout::IFLAG1,  4, 1, 0x0> BUF4TO1I;
constexpr CAN3_Reg<&CAN_Layout::IFLAG1,  1, 0, 0x0> BUF0I;
constexpr CAN3_Reg<&CAN_Layout::IFLAG1,  5, 0, 0x0> BUF4TO0I;
}  // namespace IFLAG1

// CAN3 Control 2 Register
namespace CTRL2 {
constexpr CAN3_Reg<&CAN_Layout::CTRL2, 1, 31> ERRMSK_FAST;
constexpr CAN3_Reg<&CAN_Layout::CTRL2, 1, 30> BOFFDONEMSK;
constexpr CAN3_Reg<&CAN_Layout::CTRL2, 1, 28> WRMFRZ;
constexpr CAN3_Reg<&CAN_Layout::CTRL2, 4, 24> RFFN;
constexpr CAN3_Reg<&CAN_Layout::CTRL2, 5, 19> TASD;
constexpr CAN3_Reg<&CAN_Layout::CTRL2, 1, 18> MRP;
constexpr CAN3_Reg<&CAN_Layout::CTRL2, 1, 17> RRS;
constexpr CAN3_Reg<&CAN_Layout::CTRL2, 1, 16> EACEN;
constexpr CAN3_Reg<&CAN_Layout::CTRL2, 1, 15> TIMER_SRC;
constexpr CAN3_Reg<&CAN_Layout::CTRL2, 1, 14> PREXCEN;
constexpr CAN3_Reg<&CAN_Layout::CTRL2, 1, 12> ISOCANFDEN;
constexpr CAN3_Reg<&CAN_Layout::CTRL2, 1, 11> EDFLTDIS;
}  // namespace CTRL2

// CAN3 Error and Status 2 Register
namespace ESR2 {
constexpr CAN3_Reg<&CAN_Layout::ESR2, 7, 16> LPTM;
constexpr CAN3_Reg<&CAN_Layout::ESR2, 1, 14> VPS;
constexpr CAN3_Reg<&CAN_Layout::ESR2, 1, 13> IMB;
}  // namespace ESR2

// CAN3 CRC Register
namespace CRCR {
constexpr CAN3_Reg<&CAN_Layout::CRCR,  7, 16> MBCRC;
constexpr CAN3_Reg<&CAN_Layout::CRCR, 15,  0> TXCRC;
}  // namespace CRCR

// CAN3 Rx FIFO Global Mask register
namespace RXFGMASK {
constexpr CAN3_Reg<&CAN_Layout::RXFGMASK, 32, 0> FGM;
}  // namespace RXFGMASK

// CAN3 Rx FIFO Information Register
namespace RXFIR {
constexpr CAN3_Reg<&CAN_Layout::RXFIR, 9, 0> IDHIT;
}  // namespace RXFIR

// CAN3 CAN Bit Timing Register
namespace CBT {
constexpr CAN3_Reg<&CAN_Layout::CBT,  1, 31> BTF;       // Bit Timing Format Enable
    // 0b0..Extended bit time definitions disabled.
    // 0b1..Extended bit time definitions enabled.
constexpr CAN3_Reg<&CAN_Layout::CBT, 10, 21> EPRESDIV;  // Extended Prescaler Division Factor
constexpr CAN3_Reg<&CAN_Layout::CBT,  5, 16> ERJW;      // Extended Resync Jump Width
constexpr CAN3_Reg<&CAN_Layout::CBT,  6, 10> EPROPSEG;  // Extended Propagation Segment
constexpr CAN3_Reg<&CAN_Layout::CBT,  5,  5> EPSEG1;    // Extended Phase Segment 1
constexpr CAN3_Reg<&CAN_Layout::CBT,  5,  0> EPSEG2;    // Extended Phase Segment 2
}  // namespace CBT

// CAN3 Rx Individual Mask Registers
namespace RXIMR {
template <size_t Index>
constexpr RXIMR_Reg<Index, 32, 0> MI;
}  // namespace RXIMR

// CAN3 FD Control Register
namespace FDCTRL {
constexpr uint32_t kW1C = regs::shiftedMask32<1, 14>();

constexpr CAN3_Reg<&CAN_Layout::FDCTRL, 1, 31, regs::shiftedMask32<1, 31>() | kW1C> FDRATE;  // Bit Rate Switch Enable
    // 0b0..Transmit a frame in nominal rate. The BRS bit in the Tx MB has no effect.
    // 0b1..Transmit a frame with bit rate switching if the BRS bit in the Tx MB is recessive.
constexpr CAN3_Reg<&CAN_Layout::FDCTRL, 2, 19, regs::shiftedMask32<2, 19>() | kW1C> MBDSR1;  // Message Buffer Data Size for Region 1
    // 0b00..Selects 8 bytes per message buffer.
    // 0b01..Selects 16 bytes per message buffer.
    // 0b10..Selects 32 bytes per message buffer.
    // 0b11..Selects 64 bytes per message buffer.
constexpr CAN3_Reg<&CAN_Layout::FDCTRL, 2, 16, regs::shiftedMask32<2, 16>() | kW1C> MBDSR0;  // Message Buffer Data Size for Region 0
    // 0b00..Selects 8 bytes per message buffer.
    // 0b01..Selects 16 bytes per message buffer.
    // 0b10..Selects 32 bytes per message buffer.
    // 0b11..Selects 64 bytes per message buffer.
constexpr CAN3_Reg<&CAN_Layout::FDCTRL, 1, 15, regs::shiftedMask32<1, 15>() | kW1C> TDCEN;   // Transceiver Delay Compensation Enable
    // 0b0..TDC is disabled
    // 0b1..TDC is enabled
constexpr CAN3_Reg<&CAN_Layout::FDCTRL, 1, 14, kW1C> TDCFAIL;                                // Transceiver Delay Compensation Fail
    // 0b0..Measured loop delay is in range.
    // 0b1..Measured loop delay is out of range.
constexpr CAN3_Reg<&CAN_Layout::FDCTRL, 5,  8, regs::shiftedMask32<5,  8>() | kW1C> TDCOFF;  // Transceiver Delay Compensation Offset
constexpr CAN3_Reg<regs::constify(&CAN_Layout::FDCTRL), 6,  0> TDCVAL;                       // Transceiver Delay Compensation Value
}  // namespace FDCTRL

// CAN3 FD Bit Timing Register
namespace FDCBT {
constexpr CAN3_Reg<&CAN_Layout::FDCBT, 10, 20> FPRESDIV;  // Fast Prescaler Division Factor
constexpr CAN3_Reg<&CAN_Layout::FDCBT,  3, 16> FRJW;      // Fast Resync Jump Width
constexpr CAN3_Reg<&CAN_Layout::FDCBT,  5, 10> FPROPSEG;  // Fast Propagation Segment
constexpr CAN3_Reg<&CAN_Layout::FDCBT,  3,  5> FPSEG1;    // Fast Phase Segment 1
constexpr CAN3_Reg<&CAN_Layout::FDCBT,  3,  0> FPSEG2;    // Fast Phase Segment 2
}  // namespace FDCBT

// CAN3 FD CRC Register
namespace FDCRC {
constexpr CAN3_Reg<&CAN_Layout::FDCRC,  7, 24> FD_MBCRC;  // CRC Mailbox Number for FD_TXCRC
constexpr CAN3_Reg<&CAN_Layout::FDCRC, 21,  0> FD_TXCRC;  // Extended Transmitted CRC value
}  // namespace FDCRC

}  // namespace CAN3

namespace CAN {

// Message Buffer 0 CS Register..Message Buffer 6 CS Register values
namespace CS {
namespace vals {
constexpr regs::RegValue32< 1, 31> EDL;         // Extended Data Length.
    // This bit distinguishes between CAN format and CAN FD format frames.
    //   The EDL bit must not be set for Message Buffers configured to RANSWER with code field 0b1010.
constexpr regs::RegValue32< 1, 30> BRS;         // Bit Rate Switch.
    // This bit defines whether the bit rate is switched inside a CAN FD format frame.
constexpr regs::RegValue32< 1, 29> ESI;         // Error State Indicator.
    // This bit indicates if the transmitting node is error active or error passive.
constexpr regs::RegValue32< 4, 24> CODE;        // Message Buffer Code.
    // This 4-bit field can be accessed (read or write) by the CPU and by
    //   the FlexCAN module itself, as part of the message buffer matching and arbitration process.
constexpr regs::RegValue32< 1, 22> SRR;         // Substitute Remote Request.
    // Contains a fixed recessive bit.
constexpr regs::RegValue32< 1, 21> IDE;         // ID Extended.
    // One/zero for extended/standard format frame.
constexpr regs::RegValue32< 1, 20> RTR;         // Remote Transmission Request.
    // One/zero for remote/data frame.
constexpr regs::RegValue32< 4, 16> DLC;         // Length of the data to be stored/transmitted.
constexpr regs::RegValue32<16,  0> TIME_STAMP;  // Free-Running Counter Time stamp.
    // This 16-bit field is a copy of the Free-Running
    //   Timer, captured for Tx and Rx frames at the time when the beginning of the Identifier field
    //   appears on the CAN bus.
}  // namespace vals
}  // namespace CS

// Message Buffer 0 ID Register..Message Buffer 6 ID Register values
namespace ID {
namespace vals {
constexpr regs::RegValue32< 3, 29> PRIO;          // R/O, Local priority.
    // This 3-bit fieldis only used when LPRIO_EN bit is set in MCR and it only
    //   makes sense for Tx buffers. These bits are not transmitted. They are appended to the regular
    //   ID to define the transmission priority.
constexpr regs::RegValue32<11, 18> STD;           // Contains standard/extended (HIGH word) identifier of message buffer.
constexpr regs::RegValue32<18,  0> EXT;           // Contains extended (LOW word) identifier of message buffer.
constexpr regs::RegValue32<29,  0> EXT_complete;  // Contains the whole extended identifier
    // Note: EXT overlaps STD intentionally
}  // namespace vals
}  // namespace ID

}  // namespace CAN

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
