// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// CCM.h defines all the CCM registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

constexpr size_t kENET_TXIC_count    = 1;
constexpr size_t kENET_RXIC_count    = 1;
constexpr size_t kENET_CHANNEL_count = 4;

// ENET layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_ENET.h
// * https://github.com/nxp-mcuxpresso/legacy-mcux-sdk/blob/main/devices/MIMXRT1062/MIMXRT1062.h
struct ENET_Layout {
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t EIR;                               /**< Interrupt Event Register, offset: 0x4 */
  volatile uint32_t EIMR;                              /**< Interrupt Mask Register, offset: 0x8 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t RDAR;                              /**< Receive Descriptor Active Register - Ring 0, offset: 0x10 */
  volatile uint32_t TDAR;                              /**< Transmit Descriptor Active Register - Ring 0, offset: 0x14 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t ECR;                               /**< Ethernet Control Register, offset: 0x24 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[6];
  volatile uint32_t MMFR;                              /**< MII Management Frame Register, offset: 0x40 */
  volatile uint32_t MSCR;                              /**< MII Speed Control Register, offset: 0x44 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[7];
  volatile uint32_t MIBC;                              /**< MIB Control Register, offset: 0x64 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[7];
  volatile uint32_t RCR;                               /**< Receive Control Register, offset: 0x84 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[15];
  volatile uint32_t TCR;                               /**< Transmit Control Register, offset: 0xC4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[7];
  volatile uint32_t PALR;                              /**< Physical Address Lower Register, offset: 0xE4 */
  volatile uint32_t PAUR;                              /**< Physical Address Upper Register, offset: 0xE8 */
  volatile uint32_t OPD;                               /**< Opcode/Pause Duration Register, offset: 0xEC */
  volatile uint32_t TXIC[kENET_TXIC_count];            /**< Transmit Interrupt Coalescing Register, array offset: 0xF0, array step: 0x4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t RXIC[kENET_RXIC_count];            /**< Receive Interrupt Coalescing Register, array offset: 0x100, array step: 0x4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[5];
  volatile uint32_t IAUR;                              /**< Descriptor Individual Upper Address Register, offset: 0x118 */
  volatile uint32_t IALR;                              /**< Descriptor Individual Lower Address Register, offset: 0x11C */
  volatile uint32_t GAUR;                              /**< Descriptor Group Upper Address Register, offset: 0x120 */
  volatile uint32_t GALR;                              /**< Descriptor Group Lower Address Register, offset: 0x124 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[7];
  volatile uint32_t TFWR;                              /**< Transmit FIFO Watermark Register, offset: 0x144 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[14];
  volatile uint32_t RDSR;                              /**< Receive Descriptor Ring 0 Start Register, offset: 0x180 */
  volatile uint32_t TDSR;                              /**< Transmit Buffer Descriptor Ring 0 Start Register, offset: 0x184 */
  volatile uint32_t MRBR;                              /**< Maximum Receive Buffer Size Register - Ring 0, offset: 0x188 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t RSFL;                              /**< Receive FIFO Section Full Threshold, offset: 0x190 */
  volatile uint32_t RSEM;                              /**< Receive FIFO Section Empty Threshold, offset: 0x194 */
  volatile uint32_t RAEM;                              /**< Receive FIFO Almost Empty Threshold, offset: 0x198 */
  volatile uint32_t RAFL;                              /**< Receive FIFO Almost Full Threshold, offset: 0x19C */
  volatile uint32_t TSEM;                              /**< Transmit FIFO Section Empty Threshold, offset: 0x1A0 */
  volatile uint32_t TAEM;                              /**< Transmit FIFO Almost Empty Threshold, offset: 0x1A4 */
  volatile uint32_t TAFL;                              /**< Transmit FIFO Almost Full Threshold, offset: 0x1A8 */
  volatile uint32_t TIPG;                              /**< Transmit Inter-Packet Gap, offset: 0x1AC */
  volatile uint32_t FTRL;                              /**< Frame Truncation Length, offset: 0x1B0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t TACC;                              /**< Transmit Accelerator Function Configuration, offset: 0x1C0 */
  volatile uint32_t RACC;                              /**< Receive Accelerator Function Configuration, offset: 0x1C4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[15];
  const volatile uint32_t RMON_T_PACKETS;              /**< Tx Packet Count Statistic Register, offset: 0x204 */
  const volatile uint32_t RMON_T_BC_PKT;               /**< Tx Broadcast Packets Statistic Register, offset: 0x208 */
  const volatile uint32_t RMON_T_MC_PKT;               /**< Tx Multicast Packets Statistic Register, offset: 0x20C */
  const volatile uint32_t RMON_T_CRC_ALIGN;            /**< Tx Packets with CRC/Align Error Statistic Register, offset: 0x210 */
  const volatile uint32_t RMON_T_UNDERSIZE;            /**< Tx Packets Less Than Bytes and Good CRC Statistic Register, offset: 0x214 */
  const volatile uint32_t RMON_T_OVERSIZE;             /**< Tx Packets GT MAX_FL bytes and Good CRC Statistic Register, offset: 0x218 */
  const volatile uint32_t RMON_T_FRAG;                 /**< Tx Packets Less Than 64 Bytes and Bad CRC Statistic Register, offset: 0x21C */
  const volatile uint32_t RMON_T_JAB;                  /**< Tx Packets Greater Than MAX_FL bytes and Bad CRC Statistic Register, offset: 0x220 */
  const volatile uint32_t RMON_T_COL;                  /**< Tx Collision Count Statistic Register, offset: 0x224 */
  const volatile uint32_t RMON_T_P64;                  /**< Tx 64-Byte Packets Statistic Register, offset: 0x228 */
  const volatile uint32_t RMON_T_P65TO127;             /**< Tx 65- to 127-byte Packets Statistic Register, offset: 0x22C */
  const volatile uint32_t RMON_T_P128TO255;            /**< Tx 128- to 255-byte Packets Statistic Register, offset: 0x230 */
  const volatile uint32_t RMON_T_P256TO511;            /**< Tx 256- to 511-byte Packets Statistic Register, offset: 0x234 */
  const volatile uint32_t RMON_T_P512TO1023;           /**< Tx 512- to 1023-byte Packets Statistic Register, offset: 0x238 */
  const volatile uint32_t RMON_T_P1024TO2047;          /**< Tx 1024- to 2047-byte Packets Statistic Register, offset: 0x23C */
  const volatile uint32_t RMON_T_P_GTE2048;            /**< Tx Packets Greater Than 2048 Bytes Statistic Register, offset: 0x240 */
  const volatile uint32_t RMON_T_OCTETS;               /**< Tx Octets Statistic Register, offset: 0x244 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  const volatile uint32_t IEEE_T_FRAME_OK;             /**< Frames Transmitted OK Statistic Register, offset: 0x24C */
  const volatile uint32_t IEEE_T_1COL;                 /**< Frames Transmitted with Single Collision Statistic Register, offset: 0x250 */
  const volatile uint32_t IEEE_T_MCOL;                 /**< Frames Transmitted with Multiple Collisions Statistic Register, offset: 0x254 */
  const volatile uint32_t IEEE_T_DEF;                  /**< Frames Transmitted after Deferral Delay Statistic Register, offset: 0x258 */
  const volatile uint32_t IEEE_T_LCOL;                 /**< Frames Transmitted with Late Collision Statistic Register, offset: 0x25C */
  const volatile uint32_t IEEE_T_EXCOL;                /**< Frames Transmitted with Excessive Collisions Statistic Register, offset: 0x260 */
  const volatile uint32_t IEEE_T_MACERR;               /**< Frames Transmitted with Tx FIFO Underrun Statistic Register, offset: 0x264 */
  const volatile uint32_t IEEE_T_CSERR;                /**< Frames Transmitted with Carrier Sense Error Statistic Register, offset: 0x268 */
  const volatile uint32_t IEEE_T_SQE;                  /**< Reserved Statistic Register, offset: 0x26C */
  const volatile uint32_t IEEE_T_FDXFC;                /**< Flow Control Pause Frames Transmitted Statistic Register, offset: 0x270 */
  const volatile uint32_t IEEE_T_OCTETS_OK;            /**< Octet Count for Frames Transmitted w/o Error Statistic Register, offset: 0x274 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  const volatile uint32_t RMON_R_PACKETS;              /**< Rx Packet Count Statistic Register, offset: 0x284 */
  const volatile uint32_t RMON_R_BC_PKT;               /**< Rx Broadcast Packets Statistic Register, offset: 0x288 */
  const volatile uint32_t RMON_R_MC_PKT;               /**< Rx Multicast Packets Statistic Register, offset: 0x28C */
  const volatile uint32_t RMON_R_CRC_ALIGN;            /**< Rx Packets with CRC/Align Error Statistic Register, offset: 0x290 */
  const volatile uint32_t RMON_R_UNDERSIZE;            /**< Rx Packets with Less Than 64 Bytes and Good CRC Statistic Register, offset: 0x294 */
  const volatile uint32_t RMON_R_OVERSIZE;             /**< Rx Packets Greater Than MAX_FL and Good CRC Statistic Register, offset: 0x298 */
  const volatile uint32_t RMON_R_FRAG;                 /**< Rx Packets Less Than 64 Bytes and Bad CRC Statistic Register, offset: 0x29C */
  const volatile uint32_t RMON_R_JAB;                  /**< Rx Packets Greater Than MAX_FL Bytes and Bad CRC Statistic Register, offset: 0x2A0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  const volatile uint32_t RMON_R_P64;                  /**< Rx 64-Byte Packets Statistic Register, offset: 0x2A8 */
  const volatile uint32_t RMON_R_P65TO127;             /**< Rx 65- to 127-Byte Packets Statistic Register, offset: 0x2AC */
  const volatile uint32_t RMON_R_P128TO255;            /**< Rx 128- to 255-Byte Packets Statistic Register, offset: 0x2B0 */
  const volatile uint32_t RMON_R_P256TO511;            /**< Rx 256- to 511-Byte Packets Statistic Register, offset: 0x2B4 */
  const volatile uint32_t RMON_R_P512TO1023;           /**< Rx 512- to 1023-Byte Packets Statistic Register, offset: 0x2B8 */
  const volatile uint32_t RMON_R_P1024TO2047;          /**< Rx 1024- to 2047-Byte Packets Statistic Register, offset: 0x2BC */
  const volatile uint32_t RMON_R_P_GTE2048;            /**< Rx Packets Greater than 2048 Bytes Statistic Register, offset: 0x2C0 */
  const volatile uint32_t RMON_R_OCTETS;               /**< Rx Octets Statistic Register, offset: 0x2C4 */
  const volatile uint32_t IEEE_R_DROP;                 /**< Frames not Counted Correctly Statistic Register, offset: 0x2C8 */
  const volatile uint32_t IEEE_R_FRAME_OK;             /**< Frames Received OK Statistic Register, offset: 0x2CC */
  const volatile uint32_t IEEE_R_CRC;                  /**< Frames Received with CRC Error Statistic Register, offset: 0x2D0 */
  const volatile uint32_t IEEE_R_ALIGN;                /**< Frames Received with Alignment Error Statistic Register, offset: 0x2D4 */
  const volatile uint32_t IEEE_R_MACERR;               /**< Receive FIFO Overflow Count Statistic Register, offset: 0x2D8 */
  const volatile uint32_t IEEE_R_FDXFC;                /**< Flow Control Pause Frames Received Statistic Register, offset: 0x2DC */
  const volatile uint32_t IEEE_R_OCTETS_OK;            /**< Octet Count for Frames Received without Error Statistic Register, offset: 0x2E0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[71];
  volatile uint32_t ATCR;                              /**< Adjustable Timer Control Register, offset: 0x400 */
  volatile uint32_t ATVR;                              /**< Timer Value Register, offset: 0x404 */
  volatile uint32_t ATOFF;                             /**< Timer Offset Register, offset: 0x408 */
  volatile uint32_t ATPER;                             /**< Timer Period Register, offset: 0x40C */
  volatile uint32_t ATCOR;                             /**< Timer Correction Register, offset: 0x410 */
  volatile uint32_t ATINC;                             /**< Time-Stamping Clock Period Register, offset: 0x414 */
  const volatile uint32_t ATSTMP;                      /**< Timestamp of Last Transmitted Frame, offset: 0x418 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[122];
  volatile uint32_t TGSR;                              /**< Timer Global Status Register, offset: 0x604 */
  struct CHANNEL_Layout {                          /* offset: 0x608, array step: 0x8 */
    volatile uint32_t TCSR;                            /**< Timer Control Status Register, array offset: 0x608, array step: 0x8 */
    volatile uint32_t TCCR;                            /**< Timer Compare Capture Register, array offset: 0x60C, array step: 0x8 */
  } CHANNEL[kENET_CHANNEL_count];
};

constexpr size_t    kENET_size  = 0x628;
constexpr uintptr_t kENET_base  = 0x402D8000;
constexpr uintptr_t kENET2_base = 0x402D4000;

constexpr uintptr_t ChannelBase(const uintptr_t base, const size_t index) {
  return base + offsetof(ENET_Layout, CHANNEL) +
         index*sizeof(ENET_Layout::CHANNEL_Layout);
}

namespace ENET {
constexpr regs::RegGroup<ENET_Layout, kENET_size, kENET_base> group;
}  // namespace ENET

namespace ENET2 {
constexpr regs::RegGroup<ENET_Layout, kENET_size, kENET2_base> group;
}  // namespace ENET2

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using ENET_Reg =
    regs::Reg32<kENET_base, ENET_Layout, Member, 0, Bits, Shift, DirectAssign>;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using ENET2_Reg =
    regs::Reg32<kENET2_base, ENET_Layout, Member, 0, Bits, Shift, DirectAssign>;

template <size_t Index, auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using ENET_CHANNEL_Reg =
    regs::Reg32<ChannelBase(kENET_base, Index), ENET_Layout::CHANNEL_Layout,
                Member, 0, Bits, Shift, DirectAssign>;

template <size_t Index, auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using ENET2_CHANNEL_Reg =
    regs::Reg32<ChannelBase(kENET2_base, Index), ENET_Layout::CHANNEL_Layout,
                Member, 0, Bits, Shift, DirectAssign>;

namespace ENET {

// Interrupt Event Register
namespace EIR {
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 30, true> BABR;      // Babbling Receive Error
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 29, true> BABT;      // Babbling Transmit Error
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 28, true> GRA;       // Graceful Stop Complete
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 27, true> TXF;       // Transmit Frame Interrupt
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 26, true> TXB;       // Transmit Buffer Interrupt
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 25, true> RXF;       // Receive Frame Interrupt
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 24, true> RXB;       // Receive Buffer Interrupt
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 23, true> MII;       // MII Interrupt
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 22, true> EBERR;     // Ethernet Bus Error
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 21, true> LC;        // Late Collision
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 20, true> RL;        // Collision Retry Limit
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 19, true> UN;        // Transmit FIFO Underrun
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 18, true> PLR;       // Payload Receive Error
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 17, true> WAKEUP;    // Node Wakeup Request Indication
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 16, true> TS_AVAIL;  // Transmit Timestamp Available
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 15, true> TS_TIMER;  // Timestamp Timer
}  // namespace EIR

// Interrupt Mask Register
namespace EIMR {
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 30> BABR;      // BABR Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 29> BABT;      // BABT Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 28> GRA;       // GRA Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 27> TXF;       // TXF Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 26> TXB;       // TXB Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 25> RXF;       // RXF Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 24> RXB;       // RXB Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 23> MII;       // MII Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 22> EBERR;     // EBERR Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 21> LC;        // LC Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 20> RL;        // RL Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 19> UN;        // UN Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 18> PLR;       // PLR Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 17> WAKEUP;    // WAKEUP Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 16> TS_AVAIL;  // TS_AVAIL Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 15> TS_TIMER;  // TS_TIMER Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
}  // namespace EIMR

// Receive Descriptor Active Register - Ring 0
namespace RDAR {
constexpr ENET_Reg<&ENET_Layout::RDAR, 1, 24> RDAR;  // Receive Descriptor Active
}  // namespace RDAR

// Transmit Descriptor Active Register - Ring 0
namespace TDAR {
constexpr ENET_Reg<&ENET_Layout::TDAR, 1, 24> TDAR;  // Transmit Descriptor Active
}  // namespace TDAR

// Ethernet Control Register
namespace ECR {
constexpr ENET_Reg<&ENET_Layout::ECR, 1, 8> DBSWP;    // Descriptor Byte Swapping Enable
    // 0b0..The buffer descriptor bytes are not swapped to support big-endian devices.
    // 0b1..The buffer descriptor bytes are swapped to support little-endian devices.
constexpr ENET_Reg<&ENET_Layout::ECR, 1, 6> DBGEN;    // Debug Enable
    // 0b0..MAC continues operation in debug mode.
    // 0b1..MAC enters hardware freeze mode when the processor is in debug mode.
constexpr ENET_Reg<&ENET_Layout::ECR, 1, 4> EN1588;   // EN1588 Enable
    // 0b0..Legacy FEC buffer descriptors and functions enabled.
    // 0b1..Enhanced frame time-stamping functions enabled. Has no effect within the MAC besides controlling the DMA control bit ena_1588.
constexpr ENET_Reg<&ENET_Layout::ECR, 1, 3> SLEEP;    // Sleep Mode Enable
    // 0b0..Normal operating mode.
    // 0b1..Sleep mode.
constexpr ENET_Reg<&ENET_Layout::ECR, 1, 2> MAGICEN;  // Magic Packet Detection Enable
    // 0b0..Magic detection logic disabled.
    // 0b1..The MAC core detects magic packets and asserts EIR[WAKEUP] when a frame is detected.
constexpr ENET_Reg<&ENET_Layout::ECR, 1, 1> ETHEREN;  // Ethernet Enable
    // 0b0..Reception immediately stops and transmission stops after a bad CRC is appended to any currently transmitted frame.
    // 0b1..MAC is enabled, and reception and transmission are possible.
constexpr ENET_Reg<&ENET_Layout::ECR, 1, 0> RESET;    // Ethernet MAC Reset
}  // namespace ECR

// MII Management Frame Register
namespace MMFR {
constexpr ENET_Reg<&ENET_Layout::MMFR,  2, 30> ST;    // Start Of Frame Delimiter
constexpr ENET_Reg<&ENET_Layout::MMFR,  2, 28> OP;    // Operation Code
constexpr ENET_Reg<&ENET_Layout::MMFR,  5, 23> PA;    // PHY Address
constexpr ENET_Reg<&ENET_Layout::MMFR,  5, 18> RA;    // Register Address
constexpr ENET_Reg<&ENET_Layout::MMFR,  2, 16> TA;    // Turn Around
constexpr ENET_Reg<&ENET_Layout::MMFR, 16,  0> DATA;  // Management Frame Data
}  // namespace MMFR

// MII Speed Control Register
namespace MSCR {
constexpr ENET_Reg<&ENET_Layout::MSCR, 3, 8> HOLDTIME;   // Hold time On MDIO Output
    // 'value + 1' internal module clock cycles:
    // 0b000..1 internal module clock cycle
    // 0b001..2 internal module clock cycles
    // 0b010..3 internal module clock cycles
    // 0b111..8 internal module clock cycles
constexpr ENET_Reg<&ENET_Layout::MSCR, 1, 7> DIS_PRE;    // Disable Preamble
    // 0b0..Preamble enabled.
    // 0b1..Preamble (32 ones) is not prepended to the MII management frame.
constexpr ENET_Reg<&ENET_Layout::MSCR, 6, 1> MII_SPEED;  // MII Speed
}  // namespace MSCR

// MIB Control Register
namespace MIBC {
constexpr ENET_Reg<&ENET_Layout::MIBC, 1, 31> MIB_DIS;    // Disable MIB Logic
    // 0b0..MIB logic is enabled.
    // 0b1..MIB logic is disabled. The MIB logic halts and does not update any MIB counters.
constexpr ENET_Reg<&ENET_Layout::MIBC, 1, 30> MIB_IDLE;   // MIB Idle
    // 0b0..The MIB block is updating MIB counters.
    // 0b1..The MIB block is not currently updating any MIB counters.
constexpr ENET_Reg<&ENET_Layout::MIBC, 1, 29> MIB_CLEAR;  // MIB Clear
    // 0b0..See note above.
    // 0b1..All statistics counters are reset to 0.
}  // namespace MIBC

// Receive Control Register
namespace RCR {
constexpr ENET_Reg<&ENET_Layout::RCR,  1, 31> GRS;        // Graceful Receive Stopped
    // 0b0..Receive not stopped
    // 0b1..Receive stopped
constexpr ENET_Reg<&ENET_Layout::RCR,  1, 30> NLC;        // Payload Length Check Disable
    // 0b0..The payload length check is disabled.
    // 0b1..The core checks the frame's payload length with the frame length/type field. Errors are indicated in the EIR[PLR] field.
constexpr ENET_Reg<&ENET_Layout::RCR, 14, 16> MAX_FL;     // Maximum Frame Length
constexpr ENET_Reg<&ENET_Layout::RCR,  1, 15> CFEN;       // MAC Control Frame Enable
    // 0b0..MAC control frames with any opcode other than 0x0001 (pause frame) are accepted and forwarded to the client interface.
    // 0b1..MAC control frames with any opcode other than 0x0001 (pause frame) are silently discarded.
constexpr ENET_Reg<&ENET_Layout::RCR,  1, 14> CRCFWD;     // Terminate/Forward Received CRC
    // 0b0..The CRC field of received frames is transmitted to the user application.
    // 0b1..The CRC field is stripped from the frame.
constexpr ENET_Reg<&ENET_Layout::RCR,  1, 13> PAUFWD;     // Terminate/Forward Pause Frames
    // 0b0..Pause frames are terminated and discarded in the MAC.
    // 0b1..Pause frames are forwarded to the user application.
constexpr ENET_Reg<&ENET_Layout::RCR,  1, 12> PADEN;      // Enable Frame Padding Remove On Receive
    // 0b0..No padding is removed on receive by the MAC.
    // 0b1..Padding is removed from received frames.
constexpr ENET_Reg<&ENET_Layout::RCR,  1,  9> RMII_10T;
    // 0b0..100-Mbit/s operation.
    // 0b1..10-Mbit/s operation.
constexpr ENET_Reg<&ENET_Layout::RCR,  1,  8> RMII_MODE;  // RMII Mode Enable
    // 0b0..MAC configured for MII mode.
    // 0b1..MAC configured for RMII operation.
constexpr ENET_Reg<&ENET_Layout::RCR,  1,  5> FCE;        // Flow Control Enable
    // 0b0..Disable flow control
    // 0b1..Enable flow control
constexpr ENET_Reg<&ENET_Layout::RCR,  1,  4> BC_REJ;     // Broadcast Frame Reject
    // 0b0..Will not reject frames as described above
    // 0b1..Will reject frames as described above
constexpr ENET_Reg<&ENET_Layout::RCR,  1,  3> PROM;       // Promiscuous Mode
    // 0b0..Disabled.
    // 0b1..Enabled.
constexpr ENET_Reg<&ENET_Layout::RCR,  1,  2> MII_MODE;   // Media Independent Interface Mode
    // 0b0..Reserved.
    // 0b1..MII or RMII mode, as indicated by the RMII_MODE field.
constexpr ENET_Reg<&ENET_Layout::RCR,  1,  1> DRT;        // Disable Receive On Transmit
    // 0b0..Receive path operates independently of transmit (i.e., full-duplex mode). Can also be used to monitor transmit activity in half-duplex mode.
    // 0b1..Disable reception of frames while transmitting. (Normally used for half-duplex mode.)
constexpr ENET_Reg<&ENET_Layout::RCR,  1,  0> LOOP;       // Internal Loopback
    // 0b0..Loopback disabled.
    // 0b1..Transmitted frames are looped back internal to the device and transmit MII output signals are not asserted. DRT must be cleared.
}  // namespace RCR

// Transmit Control Register
namespace TCR {
constexpr ENET_Reg<&ENET_Layout::TCR, 1, 9> CRCFWD;     // Forward Frame From Application With CRC
    // 0b0..TxBD[TC] controls whether the frame has a CRC from the application.
    // 0b1..The transmitter does not append any CRC to transmitted frames, as it is expecting a frame with CRC from the application.
constexpr ENET_Reg<&ENET_Layout::TCR, 1, 8> ADDINS;     // Set MAC Address On Transmit
    // 0b0..The source MAC address is not modified by the MAC.
    // 0b1..The MAC overwrites the source MAC address with the programmed MAC address according to ADDSEL.
constexpr ENET_Reg<&ENET_Layout::TCR, 3, 5> ADDSEL;     // Source MAC Address Select On Transmit
    // 0b000..Node MAC address programmed on PADDR1/2 registers.
    // 0b100..Reserved.
    // 0b101..Reserved.
    // 0b110..Reserved.
constexpr ENET_Reg<&ENET_Layout::TCR, 1, 4> RFC_PAUSE;  // Receive Frame Control Pause
constexpr ENET_Reg<&ENET_Layout::TCR, 1, 3> TFC_PAUSE;  // Transmit Frame Control Pause
    // 0b0..No PAUSE frame transmitted.
    // 0b1..The MAC stops transmission of data frames after the current transmission is complete.
constexpr ENET_Reg<&ENET_Layout::TCR, 1, 2> FDEN;       // Full-Duplex Enable
    // 0b0..Disable full-duplex
    // 0b1..Enable full-duplex
constexpr ENET_Reg<&ENET_Layout::TCR, 1, 0> GTS;        // Graceful Transmit Stop
    // 0b0..Disable graceful transmit stop
    // 0b1..Enable graceful transmit stop
}  // namespace TCR

// Physical Address Upper Register
namespace PAUR {
constexpr ENET_Reg<&ENET_Layout::PAUR, 16, 16> PADDR2;
constexpr ENET_Reg<&ENET_Layout::PAUR, 16,  0> TYPE;  // Type Field In PAUSE Frames
}  // namespace PAUR

// Opcode/Pause Duration Register
namespace OPD {
constexpr ENET_Reg<&ENET_Layout::OPD, 16, 16> OPCODE;     // Opcode Field In PAUSE Frames
constexpr ENET_Reg<&ENET_Layout::OPD, 16,  0> PAUSE_DUR;  // Pause Duration
}  // namespace OPD

// Transmit Interrupt Coalescing Register
namespace TXIC {
constexpr ENET_Reg<&ENET_Layout::TXIC,  1, 31> ICEN;  // Interrupt Coalescing Enable
    // 0b0..Disable Interrupt coalescing.
    // 0b1..Enable Interrupt coalescing.
constexpr ENET_Reg<&ENET_Layout::TXIC,  1, 30> ICCS;  // Interrupt Coalescing Timer Clock Source Select
    // 0b0..Use MII/GMII TX clocks.
    // 0b1..Use ENET system clock.
constexpr ENET_Reg<&ENET_Layout::TXIC,  8, 20> ICFT;  // Interrupt coalescing frame count threshold
constexpr ENET_Reg<&ENET_Layout::TXIC, 16,  0> ICTT;  // Interrupt coalescing timer threshold
}  // namespace TXIC

// Receive Interrupt Coalescing Register
namespace RXIC {
constexpr ENET_Reg<&ENET_Layout::RXIC,   1, 31> ICEN;  // Interrupt Coalescing Enable
    // 0b0..Disable Interrupt coalescing.
    // 0b1..Enable Interrupt coalescing.
constexpr ENET_Reg<&ENET_Layout::RXIC,   1, 30> ICCS;  // Interrupt Coalescing Timer Clock Source Select
    // 0b0..Use MII/GMII TX clocks.
    // 0b1..Use ENET system clock.
constexpr ENET_Reg<&ENET_Layout::RXIC,   8, 20> ICFT;  // Interrupt coalescing frame count threshold
constexpr ENET_Reg<&ENET_Layout::RXIC,  16,  0> ICTT;  // Interrupt coalescing timer threshold
}  // namespace RXIC

// Transmit FIFO Watermark Register
namespace TFWR {
constexpr ENET_Reg<&ENET_Layout::TFWR, 1, 8> STRFWD;  // Store And Forward Enable
    // 0b0..Reset. The transmission start threshold is programmed in TFWR[TFWR].
    // 0b1..Enabled.
constexpr ENET_Reg<&ENET_Layout::TFWR, 6, 0> TFWR;  // Transmit FIFO Write
    // 0b000000..64 bytes written.
    // 0b000001..64 bytes written.
    // 0b000010..128 bytes written.
    // 0b000011..192 bytes written.
    // 0b011111..1984 bytes written.
}  // namespace TFWR

// Receive Descriptor Ring 0 Start Register
namespace RDSR {
constexpr ENET_Reg<&ENET_Layout::RDSR, 29, 3> R_DES_START;
}  // namespace RDSR

// Transmit Buffer Descriptor Ring 0 Start Register
namespace TDSR {
constexpr ENET_Reg<&ENET_Layout::TDSR, 29, 3> X_DES_START;
}  // namespace TDSR

// Maximum Receive Buffer Size Register - Ring 0
namespace MRBR {
constexpr ENET_Reg<&ENET_Layout::MRBR, 10, 4> R_BUF_SIZE;
}  // namespace MRBR

// Receive FIFO Section Full Threshold
namespace RSFL {
constexpr ENET_Reg<&ENET_Layout::RSFL, 8, 0> RX_SECTION_FULL;  // Value Of Receive FIFO Section Full Threshold
}  // namespace RSFL

// Receive FIFO Section Empty Threshold
namespace RSEM {
constexpr ENET_Reg<&ENET_Layout::RSEM, 5, 16> STAT_SECTION_EMPTY;  // RX Status FIFO Section Empty Threshold
constexpr ENET_Reg<&ENET_Layout::RSEM, 8,  0> RX_SECTION_EMPTY;    // Value Of The Receive FIFO Section Empty Threshold
}  // namespace RSEM

// Receive FIFO Almost Empty Threshold
namespace RAEM {
constexpr ENET_Reg<&ENET_Layout::RAEM, 8, 0> RX_ALMOST_EMPTY;  // Value Of The Receive FIFO Almost Empty Threshold
}  // namespace RAEM

// Receive FIFO Almost Full Threshold
namespace RAFL {
constexpr ENET_Reg<&ENET_Layout::RAFL, 8, 0> RX_ALMOST_FULL;  // Value Of The Receive FIFO Almost Full Threshold
}  // namespace RAFL

// Transmit FIFO Section Empty Threshold
namespace TSEM {
constexpr ENET_Reg<&ENET_Layout::TSEM, 8, 0> TX_SECTION_EMPTY;  // Value Of The Transmit FIFO Section Empty Threshold
}  // namespace TSEM

// Transmit FIFO Almost Empty Threshold
namespace TAEM {
constexpr ENET_Reg<&ENET_Layout::TAEM, 8, 0> TX_ALMOST_EMPTY;  // Value of Transmit FIFO Almost Empty Threshold
}  // namespace TAEM

// Transmit FIFO Almost Full Threshold
namespace TAFL {
constexpr ENET_Reg<&ENET_Layout::TAFL, 8, 0> TX_ALMOST_FULL;  // Value Of The Transmit FIFO Almost Full Threshold
}  // namespace TAFL

// Transmit Inter-Packet Gap
namespace TIPG {
constexpr ENET_Reg<&ENET_Layout::TIPG, 5, 0> IPG;  // Transmit Inter-Packet Gap
}  // namespace TIPG

// Frame Truncation Length
namespace FTRL {
constexpr ENET_Reg<&ENET_Layout::FTRL, 14, 0> TRUNC_FL;  // Frame Truncation Length
}  // namespace FTRL

// Transmit Accelerator Function Configuration
namespace TACC {
constexpr ENET_Reg<&ENET_Layout::TACC, 1, 4> PROCHK;
    // 0b0..Checksum not inserted.
    // 0b1..If an IP frame with a known protocol is transmitted, the checksum is inserted automatically into the
    //      frame. The checksum field must be cleared. The other frames are not modified.
constexpr ENET_Reg<&ENET_Layout::TACC, 1, 3> IPCHK;
    // 0b0..Checksum is not inserted.
    // 0b1..If an IP frame is transmitted, the checksum is inserted automatically. The IP header checksum field must
    //      be cleared. If a non-IP frame is transmitted the frame is not modified.
constexpr ENET_Reg<&ENET_Layout::TACC, 1, 0> SHIFT16;  // TX FIFO Shift-16
    // 0b0..Disabled.
    // 0b1..Indicates to the transmit data FIFO that the written frames contain two additional octets before the
    //      frame data. This means the actual frame begins at bit 16 of the first word written into the FIFO. This
    //      function allows putting the frame payload on a 32-bit boundary in memory, as the 14-byte Ethernet header is
    //      extended to a 16-byte header.
}  // namespace TACC

// Receive Accelerator Function Configuration
namespace RACC {
constexpr ENET_Reg<&ENET_Layout::RACC, 1, 7> SHIFT16;  // RX FIFO Shift-16
    // 0b0..Disabled.
    // 0b1..Instructs the MAC to write two additional bytes in front of each frame received into the RX FIFO.
constexpr ENET_Reg<&ENET_Layout::RACC, 1, 6> LINEDIS;  // Enable Discard Of Frames With MAC Layer Errors
    // 0b0..Frames with errors are not discarded.
    // 0b1..Any frame received with a CRC, length, or PHY error is automatically discarded and not forwarded to the user application interface.
constexpr ENET_Reg<&ENET_Layout::RACC, 1, 2> PRODIS;   // Enable Discard Of Frames With Wrong Protocol Checksum
    // 0b0..Frames with wrong checksum are not discarded.
    // 0b1..If a TCP/IP, UDP/IP, or ICMP/IP frame is received that has a wrong TCP, UDP, or ICMP checksum, the frame
    //      is discarded. Discarding is only available when the RX FIFO operates in store and forward mode (RSFL
    //      cleared).
constexpr ENET_Reg<&ENET_Layout::RACC, 1, 1> IPDIS;    // Enable Discard Of Frames With Wrong IPv4 Header Checksum
    // 0b0..Frames with wrong IPv4 header checksum are not discarded.
    // 0b1..If an IPv4 frame is received with a mismatching header checksum, the frame is discarded. IPv6 has no
    //      header checksum and is not affected by this setting. Discarding is only available when the RX FIFO operates in
    //      store and forward mode (RSFL cleared).
constexpr ENET_Reg<&ENET_Layout::RACC, 1, 0> PADREM;  // Enable Padding Removal For Short IP Frames
    // 0b0..Padding not removed.
    // 0b1..Any bytes following the IP payload section of the frame are removed from the frame.
}  // namespace RACC

// Adjustable Timer Control Register
namespace ATCR {
constexpr ENET_Reg<&ENET_Layout::ATCR, 1, 13> SLAVE;    // Enable Timer Slave Mode
    // 0b0..The timer is active and all configuration fields in this register are relevant.
    // 0b1..The internal timer is disabled and the externally provided timer value is used. All other fields, except
    //      CAPTURE, in this register have no effect. CAPTURE can still be used to capture the current timer value.
constexpr ENET_Reg<&ENET_Layout::ATCR, 1, 11> CAPTURE;  // Capture Timer Value
    // 0b0..No effect.
    // 0b1..The current time is captured and can be read from the ATVR register.
constexpr ENET_Reg<&ENET_Layout::ATCR, 1,  9> RESTART;  // Reset Timer
constexpr ENET_Reg<&ENET_Layout::ATCR, 1,  7> PINPER;   // Enables event signal output external pin frc_evt_period assertion on period event
    // 0b0..Disable.
    // 0b1..Enable.
constexpr ENET_Reg<&ENET_Layout::ATCR, 1,  4> PEREN;    // Enable Periodical Event
    // 0b0..Disable.
    // 0b1..A period event interrupt can be generated (EIR[TS_TIMER]) and the event signal output is asserted when
    //      the timer wraps around according to the periodic setting ATPER. The timer period value must be set before
    //      setting this bit. Not all devices contain the event signal output. See the chip configuration details.
constexpr ENET_Reg<&ENET_Layout::ATCR, 1,  3> OFFRST;   // Reset Timer On Offset Event
    // 0b0..The timer is not affected and no action occurs, besides clearing OFFEN, when the offset is reached.
    // 0b1..If OFFEN is set, the timer resets to zero when the offset setting is reached. The offset event does not cause a timer interrupt.
constexpr ENET_Reg<&ENET_Layout::ATCR, 1,  2> OFFEN;    // Enable One-Shot Offset Event
    // 0b0..Disable.
    // 0b1..The timer can be reset to zero when the given offset time is reached (offset event). The field is cleared
    //      when the offset event is reached, so no further event occurs until the field is set again. The timer
    //      offset value must be set before setting this field.
constexpr ENET_Reg<&ENET_Layout::ATCR, 1,  0> EN;       // Enable Timer
    // 0b0..The timer stops at the current value.
    // 0b1..The timer starts incrementing.
}  // namespace ATCR

// Timer Correction Register
namespace ATCOR {
constexpr ENET_Reg<&ENET_Layout::ATCOR, 31, 0> COR;  // Correction Counter Wrap-Around Value
}  // namespace ATCOR

// Time-Stamping Clock Period Register
namespace ATINC {
constexpr ENET_Reg<&ENET_Layout::ATINC, 7, 8> INC_CORR;  // Correction Increment Value
constexpr ENET_Reg<&ENET_Layout::ATINC, 7, 0> INC;       // Clock Period Of The Timestamping Clock (ts_clk) In Nanoseconds
}  // namespace ATINC

// Timer Global Status Register
namespace TGSR {
constexpr ENET_Reg<&ENET_Layout::TGSR, 1, 3, true> TF3;  // Copy Of Timer Flag For Channel 3
    // 0b0..Timer Flag for Channel 3 is clear
    // 0b1..Timer Flag for Channel 3 is set
constexpr ENET_Reg<&ENET_Layout::TGSR, 1, 2, true> TF2;  // Copy Of Timer Flag For Channel 2
    // 0b0..Timer Flag for Channel 2 is clear
    // 0b1..Timer Flag for Channel 2 is set
constexpr ENET_Reg<&ENET_Layout::TGSR, 1, 1, true> TF1;  // Copy Of Timer Flag For Channel 1
    // 0b0..Timer Flag for Channel 1 is clear
    // 0b1..Timer Flag for Channel 1 is set
constexpr ENET_Reg<&ENET_Layout::TGSR, 1, 0, true> TF0;  // Copy Of Timer Flag For Channel 0
    // 0b0..Timer Flag for Channel 0 is clear
    // 0b1..Timer Flag for Channel 0 is set
}  // namespace TGSR

// Timer Control Status Register
namespace TCSR0 {
constexpr ENET_CHANNEL_Reg<0, &ENET_Layout::CHANNEL_Layout::TCSR, 5, 11> TPWC;   // Timer PulseWidth Control
    // 'value' + 1 1588-clock cycles:
    // 0b00000..Pulse width is one 1588-clock cycle.
    // 0b00001..Pulse width is two 1588-clock cycles.
    // 0b00010..Pulse width is three 1588-clock cycles.
    // 0b00011..Pulse width is four 1588-clock cycles.
    // 0b11111..Pulse width is 32 1588-clock cycles.
constexpr ENET_CHANNEL_Reg<0, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  7> TF;     // Timer Flag
    // 0b0..Input Capture or Output Compare has not occurred.
    // 0b1..Input Capture or Output Compare has occurred.
constexpr ENET_CHANNEL_Reg<0, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  6> TIE;    // Timer Interrupt Enable
    // 0b0..Interrupt is disabled
    // 0b1..Interrupt is enabled
constexpr ENET_CHANNEL_Reg<0, &ENET_Layout::CHANNEL_Layout::TCSR, 4,  2> TMODE;  // Timer Mode
    // 0b0000..Timer Channel is disabled.
    // 0b0001..Timer Channel is configured for Input Capture on rising edge.
    // 0b0010..Timer Channel is configured for Input Capture on falling edge.
    // 0b0011..Timer Channel is configured for Input Capture on both edges.
    // 0b0100..Timer Channel is configured for Output Compare - software only.
    // 0b0101..Timer Channel is configured for Output Compare - toggle output on compare.
    // 0b0110..Timer Channel is configured for Output Compare - clear output on compare.
    // 0b0111..Timer Channel is configured for Output Compare - set output on compare.
    // 0b1000..Reserved
    // 0b1010..Timer Channel is configured for Output Compare - clear output on compare, set output on overflow.
    // 0b10x1..Timer Channel is configured for Output Compare - set output on compare, clear output on overflow.
    // 0b110x..Reserved
    // 0b1110..Timer Channel is configured for Output Compare - pulse output low on compare for 1 to 32 1588-clock cycles as specified by TPWC.
    // 0b1111..Timer Channel is configured for Output Compare - pulse output high on compare for 1 to 32 1588-clock cycles as specified by TPWC.
constexpr ENET_CHANNEL_Reg<0, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  0> TDRE;   // Timer DMA Request Enable
    // 0b0..DMA request is disabled
    // 0b1..DMA request is enabled
}  // namespace TCSR0

namespace TCSR1 {
constexpr ENET_CHANNEL_Reg<1, &ENET_Layout::CHANNEL_Layout::TCSR, 5, 11> TPWC;
constexpr ENET_CHANNEL_Reg<1, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  7> TF;
constexpr ENET_CHANNEL_Reg<1, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  6> TIE;
constexpr ENET_CHANNEL_Reg<1, &ENET_Layout::CHANNEL_Layout::TCSR, 4,  2> TMODE;
constexpr ENET_CHANNEL_Reg<1, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  0> TDRE;
}  // namespace TCSR1

namespace TCSR2 {
constexpr ENET_CHANNEL_Reg<2, &ENET_Layout::CHANNEL_Layout::TCSR, 5, 11> TPWC;
constexpr ENET_CHANNEL_Reg<2, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  7> TF;
constexpr ENET_CHANNEL_Reg<2, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  6> TIE;
constexpr ENET_CHANNEL_Reg<2, &ENET_Layout::CHANNEL_Layout::TCSR, 4,  2> TMODE;
constexpr ENET_CHANNEL_Reg<2, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  0> TDRE;
}  // namespace TCSR2

namespace TCSR3 {
constexpr ENET_CHANNEL_Reg<3, &ENET_Layout::CHANNEL_Layout::TCSR, 5, 11> TPWC;
constexpr ENET_CHANNEL_Reg<3, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  7> TF;
constexpr ENET_CHANNEL_Reg<3, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  6> TIE;
constexpr ENET_CHANNEL_Reg<3, &ENET_Layout::CHANNEL_Layout::TCSR, 4,  2> TMODE;
constexpr ENET_CHANNEL_Reg<3, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  0> TDRE;
}  // namespace TCSR3
}  // namespace ENET

namespace ENET2 {

namespace EIR {
constexpr ENET2_Reg<&ENET_Layout::EIR, 1, 30, true> BABR;
constexpr ENET2_Reg<&ENET_Layout::EIR, 1, 29, true> BABT;
constexpr ENET2_Reg<&ENET_Layout::EIR, 1, 28, true> GRA;
constexpr ENET2_Reg<&ENET_Layout::EIR, 1, 27, true> TXF;
constexpr ENET2_Reg<&ENET_Layout::EIR, 1, 26, true> TXB;
constexpr ENET2_Reg<&ENET_Layout::EIR, 1, 25, true> RXF;
constexpr ENET2_Reg<&ENET_Layout::EIR, 1, 24, true> RXB;
constexpr ENET2_Reg<&ENET_Layout::EIR, 1, 23, true> MII;
constexpr ENET2_Reg<&ENET_Layout::EIR, 1, 22, true> EBERR;
constexpr ENET2_Reg<&ENET_Layout::EIR, 1, 21, true> LC;
constexpr ENET2_Reg<&ENET_Layout::EIR, 1, 20, true> RL;
constexpr ENET2_Reg<&ENET_Layout::EIR, 1, 19, true> UN;
constexpr ENET2_Reg<&ENET_Layout::EIR, 1, 18, true> PLR;
constexpr ENET2_Reg<&ENET_Layout::EIR, 1, 17, true> WAKEUP;
constexpr ENET2_Reg<&ENET_Layout::EIR, 1, 16, true> TS_AVAIL;
constexpr ENET2_Reg<&ENET_Layout::EIR, 1, 15, true> TS_TIMER;
}  // namespace EIR

namespace EIMR {
constexpr ENET2_Reg<&ENET_Layout::EIMR, 1, 30> BABR;
constexpr ENET2_Reg<&ENET_Layout::EIMR, 1, 29> BABT;
constexpr ENET2_Reg<&ENET_Layout::EIMR, 1, 28> GRA;
constexpr ENET2_Reg<&ENET_Layout::EIMR, 1, 27> TXF;
constexpr ENET2_Reg<&ENET_Layout::EIMR, 1, 26> TXB;
constexpr ENET2_Reg<&ENET_Layout::EIMR, 1, 25> RXF;
constexpr ENET2_Reg<&ENET_Layout::EIMR, 1, 24> RXB;
constexpr ENET2_Reg<&ENET_Layout::EIMR, 1, 23> MII;
constexpr ENET2_Reg<&ENET_Layout::EIMR, 1, 22> EBERR;
constexpr ENET2_Reg<&ENET_Layout::EIMR, 1, 21> LC;
constexpr ENET2_Reg<&ENET_Layout::EIMR, 1, 20> RL;
constexpr ENET2_Reg<&ENET_Layout::EIMR, 1, 19> UN;
constexpr ENET2_Reg<&ENET_Layout::EIMR, 1, 18> PLR;
constexpr ENET2_Reg<&ENET_Layout::EIMR, 1, 17> WAKEUP;
constexpr ENET2_Reg<&ENET_Layout::EIMR, 1, 16> TS_AVAIL;
constexpr ENET2_Reg<&ENET_Layout::EIMR, 1, 15> TS_TIMER;
}  // namespace EIMR

namespace RDAR {
constexpr ENET2_Reg<&ENET_Layout::RDAR, 1, 24> RDAR;
}  // namespace RDAR

namespace TDAR {
constexpr ENET2_Reg<&ENET_Layout::TDAR, 1, 24> TDAR;
}  // namespace TDAR

namespace ECR {
constexpr ENET2_Reg<&ENET_Layout::ECR, 1, 8> DBSWP;
constexpr ENET2_Reg<&ENET_Layout::ECR, 1, 6> DBGEN;
constexpr ENET2_Reg<&ENET_Layout::ECR, 1, 4> EN1588;
constexpr ENET2_Reg<&ENET_Layout::ECR, 1, 3> SLEEP;
constexpr ENET2_Reg<&ENET_Layout::ECR, 1, 2> MAGICEN;
constexpr ENET2_Reg<&ENET_Layout::ECR, 1, 1> ETHEREN;
constexpr ENET2_Reg<&ENET_Layout::ECR, 1, 0> RESET;
}  // namespace ECR

namespace MMFR {
constexpr ENET2_Reg<&ENET_Layout::MMFR,  2, 30> ST;
constexpr ENET2_Reg<&ENET_Layout::MMFR,  2, 28> OP;
constexpr ENET2_Reg<&ENET_Layout::MMFR,  5, 23> PA;
constexpr ENET2_Reg<&ENET_Layout::MMFR,  5, 18> RA;
constexpr ENET2_Reg<&ENET_Layout::MMFR,  2, 16> TA;
constexpr ENET2_Reg<&ENET_Layout::MMFR, 16,  0> DATA;
}  // namespace MMFR

namespace MSCR {
constexpr ENET2_Reg<&ENET_Layout::MSCR, 3, 8> HOLDTIME;
constexpr ENET2_Reg<&ENET_Layout::MSCR, 1, 7> DIS_PRE;
constexpr ENET2_Reg<&ENET_Layout::MSCR, 6, 1> MII_SPEED;
}  // namespace MSCR

namespace RCR {
constexpr ENET2_Reg<&ENET_Layout::RCR,  1, 31> GRS;
constexpr ENET2_Reg<&ENET_Layout::RCR,  1, 30> NLC;
constexpr ENET2_Reg<&ENET_Layout::RCR, 14, 16> MAX_FL;
constexpr ENET2_Reg<&ENET_Layout::RCR,  1, 15> CFEN;
constexpr ENET2_Reg<&ENET_Layout::RCR,  1, 14> CRCFWD;
constexpr ENET2_Reg<&ENET_Layout::RCR,  1, 13> PAUFWD;
constexpr ENET2_Reg<&ENET_Layout::RCR,  1, 12> PADEN;
constexpr ENET2_Reg<&ENET_Layout::RCR,  1,  9> RMII_10T;
constexpr ENET2_Reg<&ENET_Layout::RCR,  1,  8> RMII_MODE;
constexpr ENET2_Reg<&ENET_Layout::RCR,  1,  5> FCE;
constexpr ENET2_Reg<&ENET_Layout::RCR,  1,  4> BC_REJ;
constexpr ENET2_Reg<&ENET_Layout::RCR,  1,  3> PROM;
constexpr ENET2_Reg<&ENET_Layout::RCR,  1,  2> MII_MODE;
constexpr ENET2_Reg<&ENET_Layout::RCR,  1,  1> DRT;
constexpr ENET2_Reg<&ENET_Layout::RCR,  1,  0> LOOP;
}  // namespace RCR

namespace TCR {
constexpr ENET2_Reg<&ENET_Layout::TCR, 1, 9> CRCFWD;
constexpr ENET2_Reg<&ENET_Layout::TCR, 1, 8> ADDINS;
constexpr ENET2_Reg<&ENET_Layout::TCR, 3, 5> ADDSEL;
constexpr ENET2_Reg<&ENET_Layout::TCR, 1, 4> RFC_PAUSE;
constexpr ENET2_Reg<&ENET_Layout::TCR, 1, 3> TFC_PAUSE;
constexpr ENET2_Reg<&ENET_Layout::TCR, 1, 2> FDEN;
constexpr ENET2_Reg<&ENET_Layout::TCR, 1, 0> GTS;
}  // namespace TCR

namespace OPD {
constexpr ENET2_Reg<&ENET_Layout::OPD, 16, 16> OPCODE;
constexpr ENET2_Reg<&ENET_Layout::OPD, 16,  0> PAUSE_DUR;
}  // namespace OPD

namespace TXIC {
constexpr ENET2_Reg<&ENET_Layout::TXIC,  1, 31> ICEN;
constexpr ENET2_Reg<&ENET_Layout::TXIC,  1, 30> ICCS;
constexpr ENET2_Reg<&ENET_Layout::TXIC,  8, 20> ICFT;
constexpr ENET2_Reg<&ENET_Layout::TXIC, 16,  0> ICTT;
}  // namespace TXIC

namespace RXIC {
constexpr ENET2_Reg<&ENET_Layout::RXIC,  1, 31> ICEN;
constexpr ENET2_Reg<&ENET_Layout::RXIC,  1, 30> ICCS;
constexpr ENET2_Reg<&ENET_Layout::RXIC,  8, 20> ICFT;
constexpr ENET2_Reg<&ENET_Layout::RXIC, 16,  0> ICTT;
}  // namespace RXIC

namespace TFWR {
constexpr ENET2_Reg<&ENET_Layout::TFWR, 1, 8> STRFWD;
constexpr ENET2_Reg<&ENET_Layout::TFWR, 6, 0> TFWR;
}  // namespace TFWR

namespace RDSR {
constexpr ENET2_Reg<&ENET_Layout::RDSR, 29, 3> R_DES_START;
}  // namespace RDSR

namespace TDSR {
constexpr ENET2_Reg<&ENET_Layout::TDSR, 29, 3> X_DES_START;
}  // namespace TDSR

namespace MRBR {
constexpr ENET2_Reg<&ENET_Layout::MRBR, 10, 4> R_BUF_SIZE;
}  // namespace MRBR

namespace RSFL {
constexpr ENET2_Reg<&ENET_Layout::RSFL, 8, 0> RX_SECTION_FULL;
}  // namespace RSFL

namespace RSEM {
constexpr ENET2_Reg<&ENET_Layout::RSEM, 5, 16> STAT_SECTION_EMPTY;
constexpr ENET2_Reg<&ENET_Layout::RSEM, 8,  0> RX_SECTION_EMPTY;
}  // namespace RSEM

namespace RAEM {
constexpr ENET2_Reg<&ENET_Layout::RAEM, 8, 0> RX_ALMOST_EMPTY;
}  // namespace RAEM

namespace RAFL {
constexpr ENET2_Reg<&ENET_Layout::RAFL, 8, 0> RX_ALMOST_FULL;
}  // namespace RAFL

namespace TSEM {
constexpr ENET2_Reg<&ENET_Layout::TSEM, 8, 0> TX_SECTION_EMPTY;
}  // namespace TSEM

namespace TAEM {
constexpr ENET2_Reg<&ENET_Layout::TAEM, 8, 0> TX_ALMOST_EMPTY;
}  // namespace TAEM

namespace TAFL {
constexpr ENET2_Reg<&ENET_Layout::TAFL, 8, 0> TX_ALMOST_FULL;
}  // namespace TAFL

namespace TIPG {
constexpr ENET2_Reg<&ENET_Layout::TIPG, 5, 0> IPG;
}  // namespace TIPG

namespace FTRL {
constexpr ENET2_Reg<&ENET_Layout::FTRL, 14, 0> TRUNC_FL;
}  // namespace FTRL

namespace TACC {
constexpr ENET2_Reg<&ENET_Layout::TACC, 1, 4> PROCHK;
constexpr ENET2_Reg<&ENET_Layout::TACC, 1, 3> IPCHK;
constexpr ENET2_Reg<&ENET_Layout::TACC, 1, 0> SHIFT16;
}  // namespace TACC

namespace RACC {
constexpr ENET2_Reg<&ENET_Layout::RACC, 1, 7> SHIFT16;
constexpr ENET2_Reg<&ENET_Layout::RACC, 1, 6> LINEDIS;
constexpr ENET2_Reg<&ENET_Layout::RACC, 1, 2> PRODIS;
constexpr ENET2_Reg<&ENET_Layout::RACC, 1, 1> IPDIS;
constexpr ENET2_Reg<&ENET_Layout::RACC, 1, 0> PADREM;
}  // namespace RACC

namespace ATCR {
constexpr ENET2_Reg<&ENET_Layout::ATCR, 1, 13> SLAVE;
constexpr ENET2_Reg<&ENET_Layout::ATCR, 1, 11> CAPTURE;
constexpr ENET2_Reg<&ENET_Layout::ATCR, 1,  9> RESTART;
constexpr ENET2_Reg<&ENET_Layout::ATCR, 1,  7> PINPER;
constexpr ENET2_Reg<&ENET_Layout::ATCR, 1,  4> PEREN;
constexpr ENET2_Reg<&ENET_Layout::ATCR, 1,  3> OFFRST;
constexpr ENET2_Reg<&ENET_Layout::ATCR, 1,  2> OFFEN;
constexpr ENET2_Reg<&ENET_Layout::ATCR, 1,  0> EN;
}  // namespace ATCR

namespace ATCOR {
constexpr ENET2_Reg<&ENET_Layout::ATCOR, 31, 0> COR;
}  // namespace ATCOR

namespace ATINC {
constexpr ENET2_Reg<&ENET_Layout::ATINC, 7, 8> INC_CORR;
constexpr ENET2_Reg<&ENET_Layout::ATINC, 7, 0> INC;
}  // namespace ATINC

namespace TGSR {
constexpr ENET2_Reg<&ENET_Layout::TGSR, 1, 3, true> TF3;
constexpr ENET2_Reg<&ENET_Layout::TGSR, 1, 2, true> TF2;
constexpr ENET2_Reg<&ENET_Layout::TGSR, 1, 1, true> TF1;
constexpr ENET2_Reg<&ENET_Layout::TGSR, 1, 0, true> TF0;
}  // namespace TGSR

namespace TCSR0 {
constexpr ENET2_CHANNEL_Reg<0, &ENET_Layout::CHANNEL_Layout::TCSR, 5, 11> TPWC;
constexpr ENET2_CHANNEL_Reg<0, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  7> TF;
constexpr ENET2_CHANNEL_Reg<0, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  6> TIE;
constexpr ENET2_CHANNEL_Reg<0, &ENET_Layout::CHANNEL_Layout::TCSR, 4,  2> TMODE;
constexpr ENET2_CHANNEL_Reg<0, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  0> TDRE;
}  // namespace TCSR0

namespace TCSR1 {
constexpr ENET2_CHANNEL_Reg<1, &ENET_Layout::CHANNEL_Layout::TCSR, 5, 11> TPWC;
constexpr ENET2_CHANNEL_Reg<1, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  7> TF;
constexpr ENET2_CHANNEL_Reg<1, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  6> TIE;
constexpr ENET2_CHANNEL_Reg<1, &ENET_Layout::CHANNEL_Layout::TCSR, 4,  2> TMODE;
constexpr ENET2_CHANNEL_Reg<1, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  0> TDRE;
}  // namespace TCSR1

namespace TCSR2 {
constexpr ENET2_CHANNEL_Reg<2, &ENET_Layout::CHANNEL_Layout::TCSR, 5, 11> TPWC;
constexpr ENET2_CHANNEL_Reg<2, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  7> TF;
constexpr ENET2_CHANNEL_Reg<2, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  6> TIE;
constexpr ENET2_CHANNEL_Reg<2, &ENET_Layout::CHANNEL_Layout::TCSR, 4,  2> TMODE;
constexpr ENET2_CHANNEL_Reg<2, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  0> TDRE;
}  // namespace TCSR2

namespace TCSR3 {
constexpr ENET2_CHANNEL_Reg<3, &ENET_Layout::CHANNEL_Layout::TCSR, 5, 11> TPWC;
constexpr ENET2_CHANNEL_Reg<3, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  7> TF;
constexpr ENET2_CHANNEL_Reg<3, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  6> TIE;
constexpr ENET2_CHANNEL_Reg<3, &ENET_Layout::CHANNEL_Layout::TCSR, 4,  2> TMODE;
constexpr ENET2_CHANNEL_Reg<3, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  0> TDRE;
}  // namespace TCSR3

}  // namespace ENET2

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
