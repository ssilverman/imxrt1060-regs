// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// LPI2C.h defines all the LPI2C registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the Low Power Inter-Integrated Circuit
// (LPI2C) registers.
//
// Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_LPI2C.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct LPI2C_Layout {
  const volatile uint32_t VERID;                       /**< Version ID, offset: 0x0 */
  const volatile uint32_t PARAM;                       /**< Parameter, offset: 0x4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[2];
  volatile uint32_t MCR;                               /**< Master Control, offset: 0x10 */
  volatile uint32_t MSR;                               /**< Master Status, offset: 0x14 */
  volatile uint32_t MIER;                              /**< Master Interrupt Enable, offset: 0x18 */
  volatile uint32_t MDER;                              /**< Master DMA Enable, offset: 0x1C */
  volatile uint32_t MCFGR0;                            /**< Master Configuration 0, offset: 0x20 */
  volatile uint32_t MCFGR1;                            /**< Master Configuration 1, offset: 0x24 */
  volatile uint32_t MCFGR2;                            /**< Master Configuration 2, offset: 0x28 */
  volatile uint32_t MCFGR3;                            /**< Master Configuration 3, offset: 0x2C */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[4];
  volatile uint32_t MDMR;                              /**< Master Data Match, offset: 0x40 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t MCCR0;                             /**< Master Clock Configuration 0, offset: 0x48 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t MCCR1;                             /**< Master Clock Configuration 1, offset: 0x50 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t MFCR;                              /**< Master FIFO Control, offset: 0x58 */
  const volatile uint32_t MFSR;                        /**< Master FIFO Status, offset: 0x5C */
  volatile uint32_t MTDR;                              /**< Master Transmit Data, offset: 0x60 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  const volatile uint32_t MRDR;                        /**< Master Receive Data, offset: 0x70 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[39];
  volatile uint32_t SCR;                               /**< Slave Control, offset: 0x110 */
  volatile uint32_t SSR;                               /**< Slave Status, offset: 0x114 */
  volatile uint32_t SIER;                              /**< Slave Interrupt Enable, offset: 0x118 */
  volatile uint32_t SDER;                              /**< Slave DMA Enable, offset: 0x11C */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t SCFGR1;                            /**< Slave Configuration 1, offset: 0x124 */
  volatile uint32_t SCFGR2;                            /**< Slave Configuration 2, offset: 0x128 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[5];
  volatile uint32_t SAMR;                              /**< Slave Address Match, offset: 0x140 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  const volatile uint32_t SASR;                        /**< Slave Address Status, offset: 0x150 */
  volatile uint32_t STAR;                              /**< Slave Transmit ACK, offset: 0x154 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[2];
  volatile uint32_t STDR;                              /**< Slave Transmit Data, offset: 0x160 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  const volatile uint32_t SRDR;                        /**< Slave Receive Data, offset: 0x170 */
};

constexpr size_t    kLPI2C_size  = 0x174;
constexpr uintptr_t kLPI2C1_base = 0x403F'0000;
constexpr uintptr_t kLPI2C2_base = 0x403F'4000;
constexpr uintptr_t kLPI2C3_base = 0x403F'8000;
constexpr uintptr_t kLPI2C4_base = 0x403F'C000;

namespace LPI2C1 {
constexpr regs::RegGroup<LPI2C_Layout, kLPI2C_size, kLPI2C1_base> group;
}  // namespace LPI2C1

namespace LPI2C2 {
constexpr regs::RegGroup<LPI2C_Layout, kLPI2C_size, kLPI2C2_base> group;
}  // namespace LPI2C2

namespace LPI2C3 {
constexpr regs::RegGroup<LPI2C_Layout, kLPI2C_size, kLPI2C3_base> group;
}  // namespace LPI2C3

namespace LPI2C4 {
constexpr regs::RegGroup<LPI2C_Layout, kLPI2C_size, kLPI2C4_base> group;
}  // namespace LPI2C4

namespace LPI2C1 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>(),
          bool WriteOnly = false>
using LPI2C1_Reg =
    regs::Reg32<kLPI2C1_base, LPI2C_Layout, Member, 0, Bits, Shift,
                AssignMask, 0, WriteOnly>;

// Version ID
namespace VERID {
constexpr LPI2C1_Reg<&LPI2C_Layout::VERID,  8, 24> MAJOR;    // Major Version Number
constexpr LPI2C1_Reg<&LPI2C_Layout::VERID,  8, 16> MINOR;    // Minor Version Number
constexpr LPI2C1_Reg<&LPI2C_Layout::VERID, 16,  0> FEATURE;  // Feature Specification Number
    // 0b0000000000000010..Master only, with standard feature set
    // 0b0000000000000011..Master and slave, with standard feature set
}  // namespace VERID

// Parameter
namespace PARAM {
constexpr LPI2C1_Reg<&LPI2C_Layout::PARAM, 4, 8> MRXFIFO;  // Master Receive FIFO Size
constexpr LPI2C1_Reg<&LPI2C_Layout::PARAM, 4, 0> MTXFIFO;  // Master Transmit FIFO Size
}  // namespace PARAM

// Master Control
namespace MCR {
constexpr LPI2C1_Reg<&LPI2C_Layout::MCR, 1, 9> RRF;    // Reset Receive FIFO
    // 0b0..No effect
    // 0b1..Receive FIFO is reset
constexpr LPI2C1_Reg<&LPI2C_Layout::MCR, 1, 8> RTF;    // Reset Transmit FIFO
    // 0b0..No effect
    // 0b1..Transmit FIFO is reset
constexpr LPI2C1_Reg<&LPI2C_Layout::MCR, 1, 3> DBGEN;  // Debug Enable
    // 0b0..Master is disabled in debug mode
    // 0b1..Master is enabled in debug mode
constexpr LPI2C1_Reg<&LPI2C_Layout::MCR, 1, 2> DOZEN;  // Doze mode enable
    // 0b0..Master is enabled in Doze mode
    // 0b1..Master is disabled in Doze mode
constexpr LPI2C1_Reg<&LPI2C_Layout::MCR, 1, 1> RST;    // Software Reset
    // 0b0..Master logic is not reset
    // 0b1..Master logic is reset
constexpr LPI2C1_Reg<&LPI2C_Layout::MCR, 1, 0> MEN;    // Master Enable
    // 0b0..Master logic is disabled
    // 0b1..Master logic is enabled
}  // namespace MCR

// Master Status
namespace MSR {
constexpr LPI2C1_Reg<regs::constify(&LPI2C_Layout::MSR), 1, 25> BBF;  // Bus Busy Flag
    // 0b0..I2C Bus is idle
    // 0b1..I2C Bus is busy
constexpr LPI2C1_Reg<regs::constify(&LPI2C_Layout::MSR), 1, 24> MBF;  // Master Busy Flag
    // 0b0..I2C Master is idle
    // 0b1..I2C Master is busy
constexpr LPI2C1_Reg<&LPI2C_Layout::MSR, 1, 14, 0x0> DMF;             // Data Match Flag
    // 0b0..Have not received matching data
    // 0b1..Have received matching data
constexpr LPI2C1_Reg<&LPI2C_Layout::MSR, 1, 13, 0x0> PLTF;            // Pin Low Timeout Flag
    // 0b0..Pin low timeout has not occurred or is disabled
    // 0b1..Pin low timeout has occurred
constexpr LPI2C1_Reg<&LPI2C_Layout::MSR, 1, 12, 0x0> FEF;             // FIFO Error Flag
    // 0b0..No error
    // 0b1..Master sending or receiving data without a START condition
constexpr LPI2C1_Reg<&LPI2C_Layout::MSR, 1, 11, 0x0> ALF;             // Arbitration Lost Flag
    // 0b0..Master has not lost arbitration
    // 0b1..Master has lost arbitration
constexpr LPI2C1_Reg<&LPI2C_Layout::MSR, 1, 10, 0x0> NDF;             // NACK Detect Flag
    // 0b0..Unexpected NACK was not detected
    // 0b1..Unexpected NACK was detected
constexpr LPI2C1_Reg<&LPI2C_Layout::MSR, 1,  9, 0x0> SDF;             // STOP Detect Flag
    // 0b0..Master has not generated a STOP condition
    // 0b1..Master has generated a STOP condition
constexpr LPI2C1_Reg<&LPI2C_Layout::MSR, 1,  8, 0x0> EPF;             // End Packet Flag
    // 0b0..Master has not generated a STOP or Repeated START condition
    // 0b1..Master has generated a STOP or Repeated START condition
constexpr LPI2C1_Reg<regs::constify(&LPI2C_Layout::MSR), 1,  1> RDF;  // Receive Data Flag
    // 0b0..Receive Data is not ready
    // 0b1..Receive data is ready
constexpr LPI2C1_Reg<regs::constify(&LPI2C_Layout::MSR), 1,  0> TDF;  // Transmit Data Flag
    // 0b0..Transmit data is not requested
    // 0b1..Transmit data is requested
}  // namespace MSR

// Master Interrupt Enable
namespace MIER {
constexpr LPI2C1_Reg<&LPI2C_Layout::MIER, 1, 14> DMIE;   // Data Match Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::MIER, 1, 13> PLTIE;  // Pin Low Timeout Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::MIER, 1, 12> FEIE;   // FIFO Error Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::MIER, 1, 11> ALIE;   // Arbitration Lost Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::MIER, 1, 10> NDIE;   // NACK Detect Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::MIER, 1,  9> SDIE;   // STOP Detect Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::MIER, 1,  8> EPIE;   // End Packet Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::MIER, 1,  1> RDIE;   // Receive Data Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::MIER, 1,  0> TDIE;   // Transmit Data Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
}  // namespace MIER

// Master DMA Enable
namespace MDER {
constexpr LPI2C1_Reg<&LPI2C_Layout::MDER, 1, 1> RDDE;  // Receive Data DMA Enable
    // 0b0..DMA request is disabled
    // 0b1..DMA request is enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::MDER, 1, 0> TDDE;  // Transmit Data DMA Enable
    // 0b0..DMA request is disabled
    // 0b1..DMA request is enabled
}  // namespace MDER

// Master Configuration 0
namespace MCFGR0 {
constexpr LPI2C1_Reg<&LPI2C_Layout::MCFGR0, 1, 9> RDMO;     // Receive Data Match Only
    // 0b0..Received data is stored in the receive FIFO
    // 0b1..Received data is discarded unless the the Data Match Flag (MSR[DMF]) is set
constexpr LPI2C1_Reg<&LPI2C_Layout::MCFGR0, 1, 8> CIRFIFO;  // Circular FIFO Enable
    // 0b0..Circular FIFO is disabled
    // 0b1..Circular FIFO is enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::MCFGR0, 1, 2> HRSEL;    // Host Request Select
    // 0b0..Host request input is pin HREQ
    // 0b1..Host request input is input trigger
constexpr LPI2C1_Reg<&LPI2C_Layout::MCFGR0, 1, 1> HRPOL;    // Host Request Polarity
    // 0b0..Active low
    // 0b1..Active high
constexpr LPI2C1_Reg<&LPI2C_Layout::MCFGR0, 1, 0> HREN;     // Host Request Enable
    // 0b0..Host request input is disabled
    // 0b1..Host request input is enabled
}  // namespace MCFGR0

// Master Configuration 1
namespace MCFGR1 {
constexpr LPI2C1_Reg<&LPI2C_Layout::MCFGR1, 3, 24> PINCFG;    // Pin Configuration
    // 0b000..2-pin open drain mode
    // 0b001..2-pin output only mode (ultra-fast mode)
    // 0b010..2-pin push-pull mode
    // 0b011..4-pin push-pull mode
    // 0b100..2-pin open drain mode with separate LPI2C slave
    // 0b101..2-pin output only mode (ultra-fast mode) with separate LPI2C slave
    // 0b110..2-pin push-pull mode with separate LPI2C slave
    // 0b111..4-pin push-pull mode (inverted outputs)
constexpr LPI2C1_Reg<&LPI2C_Layout::MCFGR1, 3, 16> MATCFG;    // Match Configuration
    // 0b000..Match is disabled
    // 0b001..Reserved
    // 0b010..Match is enabled (1st data word equals MDMR[MATCH0] OR MDMR[MATCH1])
    // 0b011..Match is enabled (any data word equals MDMR[MATCH0] OR MDMR[MATCH1])
    // 0b100..Match is enabled (1st data word equals MDMR[MATCH0] AND 2nd data word equals MDMR[MATCH1)
    // 0b101..Match is enabled (any data word equals MDMR[MATCH0] AND next data word equals MDMR[MATCH1)
    // 0b110..Match is enabled (1st data word AND MDMR[MATCH1] equals MDMR[MATCH0] AND MDMR[MATCH1])
    // 0b111..Match is enabled (any data word AND MDMR[MATCH1] equals MDMR[MATCH0] AND MDMR[MATCH1])
constexpr LPI2C1_Reg<&LPI2C_Layout::MCFGR1, 1, 10> TIMECFG;   // Timeout Configuration
    // 0b0..MSR[PLTF] sets if SCL is low for longer than the configured timeout
    // 0b1..MSR[PLTF] sets if either SCL or SDA is low for longer than the configured timeout
constexpr LPI2C1_Reg<&LPI2C_Layout::MCFGR1, 1,  9> IGNACK;    // IGNACK
    // 0b0..LPI2C Master receives ACK and NACK normally
    // 0b1..LPI2C Master treats a received NACK as if it (NACK) was an ACK
constexpr LPI2C1_Reg<&LPI2C_Layout::MCFGR1, 1,  8> AUTOSTOP;  // Automatic STOP Generation
    // 0b0..No effect
    // 0b1..STOP condition is automatically generated whenever the transmit FIFO is empty and the LPI2C master is
    //     busy
constexpr LPI2C1_Reg<&LPI2C_Layout::MCFGR1, 3,  0> PRESCALE;  // Prescaler
    // 0b000..Divide by 1
    // 0b001..Divide by 2
    // 0b010..Divide by 4
    // 0b011..Divide by 8
    // 0b100..Divide by 16
    // 0b101..Divide by 32
    // 0b110..Divide by 64
    // 0b111..Divide by 128
}  // namespace MCFGR1

// Master Configuration 2
namespace MCFGR2 {
constexpr LPI2C1_Reg<&LPI2C_Layout::MCFGR2,  4, 24> FILTSDA;  // Glitch Filter SDA
constexpr LPI2C1_Reg<&LPI2C_Layout::MCFGR2,  4, 16> FILTSCL;  // Glitch Filter SCL
constexpr LPI2C1_Reg<&LPI2C_Layout::MCFGR2, 12,  0> BUSIDLE;  // Bus Idle Timeout
}  // namespace MCFGR2

// Master Configuration 3
namespace MCFGR3 {
constexpr LPI2C1_Reg<&LPI2C_Layout::MCFGR3, 12, 8> PINLOW;  // Pin Low Timeout
}  // namespace MCFGR3

// Master Data Match
namespace MDMR {
constexpr LPI2C1_Reg<&LPI2C_Layout::MDMR, 8, 16> MATCH1;  // Match 1 Value
constexpr LPI2C1_Reg<&LPI2C_Layout::MDMR, 8,  0> MATCH0;  // Match 0 Value
}  // namespace MDMR

// Master Clock Configuration 0
namespace MCCR0 {
constexpr LPI2C1_Reg<&LPI2C_Layout::MCCR0, 6, 24> DATAVD;   // Data Valid Delay
constexpr LPI2C1_Reg<&LPI2C_Layout::MCCR0, 6, 16> SETHOLD;  // Setup Hold Delay
constexpr LPI2C1_Reg<&LPI2C_Layout::MCCR0, 6,  8> CLKHI;    // Clock High Period
constexpr LPI2C1_Reg<&LPI2C_Layout::MCCR0, 6,  0> CLKLO;    // Clock Low Period
}  // namespace MCCR0

// Master Clock Configuration 1
namespace MCCR1 {
constexpr LPI2C1_Reg<&LPI2C_Layout::MCCR1, 6, 24> DATAVD;   // Data Valid Delay
constexpr LPI2C1_Reg<&LPI2C_Layout::MCCR1, 6, 16> SETHOLD;  // Setup Hold Delay
constexpr LPI2C1_Reg<&LPI2C_Layout::MCCR1, 6,  8> CLKHI;    // Clock High Period
constexpr LPI2C1_Reg<&LPI2C_Layout::MCCR1, 6,  0> CLKLO;    // Clock Low Period
}  // namespace MCCR1

// Master FIFO Control
namespace MFCR {
constexpr LPI2C1_Reg<&LPI2C_Layout::MFCR, 2, 16> RXWATER;  // Receive FIFO Watermark
constexpr LPI2C1_Reg<&LPI2C_Layout::MFCR, 2,  0> TXWATER;  // Transmit FIFO Watermark
}  // namespace MFCR

// Master FIFO Status
namespace MFSR {
constexpr LPI2C1_Reg<&LPI2C_Layout::MFSR, 3, 16> RXCOUNT;  // Receive FIFO Count
constexpr LPI2C1_Reg<&LPI2C_Layout::MFSR, 3,  0> TXCOUNT;  // Transmit FIFO Count
}  // namespace MFSR

// Master Transmit Data
// Exercise caution when setting or assigning fields in this register.
namespace MTDR {
constexpr LPI2C1_Reg<&LPI2C_Layout::MTDR, 3,  8, 0x0, true> CMD;   // Command Data
    // 0b000..Transmit DATA[7:0]
    // 0b001..Receive (DATA[7:0] + 1) bytes
    // 0b010..Generate STOP condition
    // 0b011..Receive and discard (DATA[7:0] + 1) bytes
    // 0b100..Generate (repeated) START and transmit address in DATA[7:0]
    // 0b101..Generate (repeated) START and transmit address in DATA[7:0]. This transfer expects a NACK to be
    //     returned.
    // 0b110..Generate (repeated) START and transmit address in DATA[7:0] using high speed mode
    // 0b111..Generate (repeated) START and transmit address in DATA[7:0] using high speed mode. This transfer
    //     expects a NACK to be returned.
constexpr LPI2C1_Reg<&LPI2C_Layout::MTDR, 8,  0, 0x0, true> DATA;  // Transmit Data
}  // namespace MTDR

// Master Receive Data
namespace MRDR {
constexpr LPI2C1_Reg<&LPI2C_Layout::MRDR, 1, 14> RXEMPTY;  // Receive Empty
    // 0b0..Receive FIFO is not empty
    // 0b1..Receive FIFO is empty
constexpr LPI2C1_Reg<&LPI2C_Layout::MRDR, 8,  0> DATA;     // Receive Data
}  // namespace MRDR

// Slave Control
namespace SCR {
constexpr LPI2C1_Reg<&LPI2C_Layout::SCR, 1, 9> RRF;     // Reset Receive FIFO
    // 0b0..No effect
    // 0b1..Receive Data Register is now empty
constexpr LPI2C1_Reg<&LPI2C_Layout::SCR, 1, 8> RTF;     // Reset Transmit FIFO
    // 0b0..No effect
    // 0b1..Transmit Data Register is now empty
constexpr LPI2C1_Reg<&LPI2C_Layout::SCR, 1, 5> FILTDZ;  // Filter Doze Enable
    // 0b0..Filter remains enabled in Doze mode
    // 0b1..Filter is disabled in Doze mode
constexpr LPI2C1_Reg<&LPI2C_Layout::SCR, 1, 4> FILTEN;  // Filter Enable
    // 0b0..Disable digital filter and output delay counter for slave mode
    // 0b1..Enable digital filter and output delay counter for slave mode
constexpr LPI2C1_Reg<&LPI2C_Layout::SCR, 1, 1> RST;     // Software Reset
    // 0b0..Slave mode logic is not reset
    // 0b1..Slave mode logic is reset
constexpr LPI2C1_Reg<&LPI2C_Layout::SCR, 1, 0> SEN;     // Slave Enable
    // 0b0..I2C Slave mode is disabled
    // 0b1..I2C Slave mode is enabled
}  // namespace SCR

// Slave Status
namespace SSR {
constexpr LPI2C1_Reg<regs::constify(&LPI2C_Layout::SSR), 1, 25> BBF;   // Bus Busy Flag
    // 0b0..I2C Bus is idle
    // 0b1..I2C Bus is busy
constexpr LPI2C1_Reg<regs::constify(&LPI2C_Layout::SSR), 1, 24> SBF;   // Slave Busy Flag
    // 0b0..I2C Slave is idle
    // 0b1..I2C Slave is busy
constexpr LPI2C1_Reg<regs::constify(&LPI2C_Layout::SSR), 1, 15> SARF;  // SMBus Alert Response Flag
    // 0b0..SMBus Alert Response is disabled or not detected
    // 0b1..SMBus Alert Response is enabled and detected
constexpr LPI2C1_Reg<regs::constify(&LPI2C_Layout::SSR), 1, 14> GCF;   // General Call Flag
    // 0b0..Slave has not detected the General Call Address or the General Call Address is disabled
    // 0b1..Slave has detected the General Call Address
constexpr LPI2C1_Reg<regs::constify(&LPI2C_Layout::SSR), 1, 13> AM1F;  // Address Match 1 Flag
    // 0b0..Have not received an ADDR1 or ADDR0/ADDR1 range matching address
    // 0b1..Have received an ADDR1 or ADDR0/ADDR1 range matching address
constexpr LPI2C1_Reg<regs::constify(&LPI2C_Layout::SSR), 1, 12> AM0F;  // Address Match 0 Flag
    // 0b0..Have not received an ADDR0 matching address
    // 0b1..Have received an ADDR0 matching address
constexpr LPI2C1_Reg<&LPI2C_Layout::SSR, 1, 11, 0x0> FEF;              // FIFO Error Flag
    // 0b0..FIFO underflow or overflow was not detected
    // 0b1..FIFO underflow or overflow was detected
constexpr LPI2C1_Reg<&LPI2C_Layout::SSR, 1, 10, 0x0> BEF;              // Bit Error Flag
    // 0b0..Slave has not detected a bit error
    // 0b1..Slave has detected a bit error
constexpr LPI2C1_Reg<&LPI2C_Layout::SSR, 1,  9, 0x0> SDF;              // STOP Detect Flag
    // 0b0..Slave has not detected a STOP condition
    // 0b1..Slave has detected a STOP condition
constexpr LPI2C1_Reg<&LPI2C_Layout::SSR, 1,  8, 0x0> RSF;              // Repeated Start Flag
    // 0b0..Slave has not detected a Repeated START condition
    // 0b1..Slave has detected a Repeated START condition
constexpr LPI2C1_Reg<regs::constify(&LPI2C_Layout::SSR), 1,  3> TAF;   // Transmit ACK Flag
    // 0b0..Transmit ACK/NACK is not required
    // 0b1..Transmit ACK/NACK is required
constexpr LPI2C1_Reg<regs::constify(&LPI2C_Layout::SSR), 1,  2> AVF;   // Address Valid Flag
    // 0b0..Address Status Register is not valid
    // 0b1..Address Status Register is valid
constexpr LPI2C1_Reg<regs::constify(&LPI2C_Layout::SSR), 1,  1> RDF;   // Receive Data Flag
    // 0b0..Receive data is not ready
    // 0b1..Receive data is ready
constexpr LPI2C1_Reg<regs::constify(&LPI2C_Layout::SSR), 1,  0> TDF;   // Transmit Data Flag
    // 0b0..Transmit data not requested
    // 0b1..Transmit data is requested
}  // namespace SSR

// Slave Interrupt Enable
namespace SIER {
constexpr LPI2C1_Reg<&LPI2C_Layout::SIER, 1, 15> SARIE;  // SMBus Alert Response Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::SIER, 1, 14> GCIE;   // General Call Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::SIER, 1, 13> AM1IE;  // Address Match 1 Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::SIER, 1, 12> AM0IE;  // Address Match 0 Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::SIER, 1, 11> FEIE;   // FIFO Error Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::SIER, 1, 10> BEIE;   // Bit Error Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::SIER, 1,  9> SDIE;   // STOP Detect Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::SIER, 1,  8> RSIE;   // Repeated Start Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::SIER, 1,  3> TAIE;   // Transmit ACK Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::SIER, 1,  2> AVIE;   // Address Valid Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::SIER, 1,  1> RDIE;   // Receive Data Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::SIER, 1,  0> TDIE;   // Transmit Data Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
}  // namespace SIER

// Slave DMA Enable
namespace SDER {
constexpr LPI2C1_Reg<&LPI2C_Layout::SDER, 1, 2> AVDE;  // Address Valid DMA Enable
    // 0b0..DMA request is disabled
    // 0b1..DMA request is enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::SDER, 1, 1> RDDE;  // Receive Data DMA Enable
    // 0b0..DMA request is disabled
    // 0b1..DMA request is enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::SDER, 1, 0> TDDE;  // Transmit Data DMA Enable
    // 0b0..DMA request is disabled
    // 0b1..DMA request is enabled
}  // namespace SDER

// Slave Configuration 1
namespace SCFGR1 {
constexpr LPI2C1_Reg<&LPI2C_Layout::SCFGR1, 3, 16> ADDRCFG;   // Address Configuration
    // 0b000..Address match 0 (7-bit)
    // 0b001..Address match 0 (10-bit)
    // 0b010..Address match 0 (7-bit) or Address match 1 (7-bit)
    // 0b011..Address match 0 (10-bit) or Address match 1 (10-bit)
    // 0b100..Address match 0 (7-bit) or Address match 1 (10-bit)
    // 0b101..Address match 0 (10-bit) or Address match 1 (7-bit)
    // 0b110..From Address match 0 (7-bit) to Address match 1 (7-bit)
    // 0b111..From Address match 0 (10-bit) to Address match 1 (10-bit)
constexpr LPI2C1_Reg<&LPI2C_Layout::SCFGR1, 1, 13> HSMEN;     // High Speed Mode Enable
    // 0b0..Disables detection of HS-mode master code
    // 0b1..Enables detection of HS-mode master code
constexpr LPI2C1_Reg<&LPI2C_Layout::SCFGR1, 1, 12> IGNACK;    // Ignore NACK
    // 0b0..Slave ends transfer when NACK is detected
    // 0b1..Slave does not end transfer when NACK detected
constexpr LPI2C1_Reg<&LPI2C_Layout::SCFGR1, 1, 11> RXCFG;     // Receive Data Configuration
    // 0b0..Reading the Receive Data register returns received data and clears the Receive Data flag.
    // 0b1..Reading the Receive Data register when the Address Valid flag (SSR[AVF]) is set, returns the Address
    //     Status register and clear the Address Valid flag. Reading the Receive Data register when the Address
    //     Valid flag is clear, returns received data and clears the Receive Data flag (MSR[RDF]).
constexpr LPI2C1_Reg<&LPI2C_Layout::SCFGR1, 1, 10> TXCFG;     // Transmit Flag Configuration
    // 0b0..Transmit Data Flag only asserts during a slave-transmit transfer when the Transmit Data register is
    //     empty
    // 0b1..Transmit Data Flag asserts whenever the Transmit Data register is empty
constexpr LPI2C1_Reg<&LPI2C_Layout::SCFGR1, 1,  9> SAEN;      // SMBus Alert Enable
    // 0b0..Disables match on SMBus Alert
    // 0b1..Enables match on SMBus Alert
constexpr LPI2C1_Reg<&LPI2C_Layout::SCFGR1, 1,  8> GCEN;      // General Call Enable
    // 0b0..General Call address is disabled
    // 0b1..General Call address is enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::SCFGR1, 1,  3> ACKSTALL;  // ACK SCL Stall
    // 0b0..Clock stretching is disabled
    // 0b1..Clock stretching is enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::SCFGR1, 1,  2> TXDSTALL;  // TX Data SCL Stall
    // 0b0..Clock stretching is disabled
    // 0b1..Clock stretching is enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::SCFGR1, 1,  1> RXSTALL;   // RX SCL Stall
    // 0b0..Clock stretching is disabled
    // 0b1..Clock stretching is enabled
constexpr LPI2C1_Reg<&LPI2C_Layout::SCFGR1, 1,  0> ADRSTALL;  // Address SCL Stall
    // 0b0..Clock stretching is disabled
    // 0b1..Clock stretching is enabled
}  // namespace SCFGR1

// Slave Configuration 2
namespace SCFGR2 {
constexpr LPI2C1_Reg<&LPI2C_Layout::SCFGR2, 4, 24> FILTSDA;  // Glitch Filter SDA
constexpr LPI2C1_Reg<&LPI2C_Layout::SCFGR2, 4, 16> FILTSCL;  // Glitch Filter SCL
constexpr LPI2C1_Reg<&LPI2C_Layout::SCFGR2, 6,  8> DATAVD;   // Data Valid Delay
constexpr LPI2C1_Reg<&LPI2C_Layout::SCFGR2, 4,  0> CLKHOLD;  // Clock Hold Time
}  // namespace SCFGR2

// Slave Address Match
namespace SAMR {
constexpr LPI2C1_Reg<&LPI2C_Layout::SAMR, 10, 17> ADDR1;  // Address 1 Value
constexpr LPI2C1_Reg<&LPI2C_Layout::SAMR, 10,  1> ADDR0;  // Address 0 Value
}  // namespace SAMR

// Slave Address Status
namespace SASR {
constexpr LPI2C1_Reg<&LPI2C_Layout::SASR,  1, 14> ANV;    // Address Not Valid
    // 0b0..Received Address (RADDR) is valid
    // 0b1..Received Address (RADDR) is not valid
constexpr LPI2C1_Reg<&LPI2C_Layout::SASR, 11,  0> RADDR;  // Received Address
}  // namespace SASR

// Slave Transmit ACK
namespace STAR {
constexpr LPI2C1_Reg<&LPI2C_Layout::STAR, 1, 0> TXNACK;  // Transmit NACK
    // 0b0..Write a Transmit ACK for each received word
    // 0b1..Write a Transmit NACK for each received word
}  // namespace STAR

// Slave Transmit Data
namespace STDR {
constexpr LPI2C1_Reg<&LPI2C_Layout::STDR, 8, 0, 0x0, true> DATA;  // Transmit Data
}  // namespace STDR

// Slave Receive Data
namespace SRDR {
constexpr LPI2C1_Reg<&LPI2C_Layout::SRDR, 1, 15> SOF;      // Start Of Frame
    // 0b0..Indicates this is not the first data word since a (repeated) START or STOP condition
    // 0b1..Indicates this is the first data word since a (repeated) START or STOP condition
constexpr LPI2C1_Reg<&LPI2C_Layout::SRDR, 1, 14> RXEMPTY;  // Receive Empty
    // 0b0..The Receive Data Register is not empty
    // 0b1..The Receive Data Register is empty
constexpr LPI2C1_Reg<&LPI2C_Layout::SRDR, 8,  0> DATA;     // Receive Data
}  // namespace SRDR

}  // namespace LPI2C1

namespace LPI2C2 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>(),
          bool WriteOnly = false>
using LPI2C2_Reg =
    regs::Reg32<kLPI2C2_base, LPI2C_Layout, Member, 0, Bits, Shift,
                AssignMask, 0, WriteOnly>;

// Version ID
namespace VERID {
constexpr LPI2C2_Reg<&LPI2C_Layout::VERID,  8, 24> MAJOR;
constexpr LPI2C2_Reg<&LPI2C_Layout::VERID,  8, 16> MINOR;
constexpr LPI2C2_Reg<&LPI2C_Layout::VERID, 16,  0> FEATURE;
}  // namespace VERID

// Parameter
namespace PARAM {
constexpr LPI2C2_Reg<&LPI2C_Layout::PARAM, 4, 8> MRXFIFO;
constexpr LPI2C2_Reg<&LPI2C_Layout::PARAM, 4, 0> MTXFIFO;
}  // namespace PARAM

// Master Control
namespace MCR {
constexpr LPI2C2_Reg<&LPI2C_Layout::MCR, 1, 9> RRF;
constexpr LPI2C2_Reg<&LPI2C_Layout::MCR, 1, 8> RTF;
constexpr LPI2C2_Reg<&LPI2C_Layout::MCR, 1, 3> DBGEN;
constexpr LPI2C2_Reg<&LPI2C_Layout::MCR, 1, 2> DOZEN;
constexpr LPI2C2_Reg<&LPI2C_Layout::MCR, 1, 1> RST;
constexpr LPI2C2_Reg<&LPI2C_Layout::MCR, 1, 0> MEN;
}  // namespace MCR

// Master Status
namespace MSR {
constexpr LPI2C2_Reg<regs::constify(&LPI2C_Layout::MSR), 1, 25> BBF;
constexpr LPI2C2_Reg<regs::constify(&LPI2C_Layout::MSR), 1, 24> MBF;
constexpr LPI2C2_Reg<&LPI2C_Layout::MSR, 1, 14, 0x0> DMF;
constexpr LPI2C2_Reg<&LPI2C_Layout::MSR, 1, 13, 0x0> PLTF;
constexpr LPI2C2_Reg<&LPI2C_Layout::MSR, 1, 12, 0x0> FEF;
constexpr LPI2C2_Reg<&LPI2C_Layout::MSR, 1, 11, 0x0> ALF;
constexpr LPI2C2_Reg<&LPI2C_Layout::MSR, 1, 10, 0x0> NDF;
constexpr LPI2C2_Reg<&LPI2C_Layout::MSR, 1,  9, 0x0> SDF;
constexpr LPI2C2_Reg<&LPI2C_Layout::MSR, 1,  8, 0x0> EPF;
constexpr LPI2C2_Reg<regs::constify(&LPI2C_Layout::MSR), 1,  1> RDF;
constexpr LPI2C2_Reg<regs::constify(&LPI2C_Layout::MSR), 1,  0> TDF;
}  // namespace MSR

// Master Interrupt Enable
namespace MIER {
constexpr LPI2C2_Reg<&LPI2C_Layout::MIER, 1, 14> DMIE;
constexpr LPI2C2_Reg<&LPI2C_Layout::MIER, 1, 13> PLTIE;
constexpr LPI2C2_Reg<&LPI2C_Layout::MIER, 1, 12> FEIE;
constexpr LPI2C2_Reg<&LPI2C_Layout::MIER, 1, 11> ALIE;
constexpr LPI2C2_Reg<&LPI2C_Layout::MIER, 1, 10> NDIE;
constexpr LPI2C2_Reg<&LPI2C_Layout::MIER, 1,  9> SDIE;
constexpr LPI2C2_Reg<&LPI2C_Layout::MIER, 1,  8> EPIE;
constexpr LPI2C2_Reg<&LPI2C_Layout::MIER, 1,  1> RDIE;
constexpr LPI2C2_Reg<&LPI2C_Layout::MIER, 1,  0> TDIE;
}  // namespace MIER

// Master DMA Enable
namespace MDER {
constexpr LPI2C2_Reg<&LPI2C_Layout::MDER, 1, 1> RDDE;
constexpr LPI2C2_Reg<&LPI2C_Layout::MDER, 1, 0> TDDE;
}  // namespace MDER

// Master Configuration 0
namespace MCFGR0 {
constexpr LPI2C2_Reg<&LPI2C_Layout::MCFGR0, 1, 9> RDMO;
constexpr LPI2C2_Reg<&LPI2C_Layout::MCFGR0, 1, 8> CIRFIFO;
constexpr LPI2C2_Reg<&LPI2C_Layout::MCFGR0, 1, 2> HRSEL;
constexpr LPI2C2_Reg<&LPI2C_Layout::MCFGR0, 1, 1> HRPOL;
constexpr LPI2C2_Reg<&LPI2C_Layout::MCFGR0, 1, 0> HREN;
}  // namespace MCFGR0

// Master Configuration 1
namespace MCFGR1 {
constexpr LPI2C2_Reg<&LPI2C_Layout::MCFGR1, 3, 24> PINCFG;
constexpr LPI2C2_Reg<&LPI2C_Layout::MCFGR1, 3, 16> MATCFG;
constexpr LPI2C2_Reg<&LPI2C_Layout::MCFGR1, 1, 10> TIMECFG;
constexpr LPI2C2_Reg<&LPI2C_Layout::MCFGR1, 1,  9> IGNACK;
constexpr LPI2C2_Reg<&LPI2C_Layout::MCFGR1, 1,  8> AUTOSTOP;
constexpr LPI2C2_Reg<&LPI2C_Layout::MCFGR1, 3,  0> PRESCALE;
}  // namespace MCFGR1

// Master Configuration 2
namespace MCFGR2 {
constexpr LPI2C2_Reg<&LPI2C_Layout::MCFGR2,  4, 24> FILTSDA;
constexpr LPI2C2_Reg<&LPI2C_Layout::MCFGR2,  4, 16> FILTSCL;
constexpr LPI2C2_Reg<&LPI2C_Layout::MCFGR2, 12,  0> BUSIDLE;
}  // namespace MCFGR2

// Master Configuration 3
namespace MCFGR3 {
constexpr LPI2C2_Reg<&LPI2C_Layout::MCFGR3, 12, 8> PINLOW;
}  // namespace MCFGR3

// Master Data Match
namespace MDMR {
constexpr LPI2C2_Reg<&LPI2C_Layout::MDMR, 8, 16> MATCH1;
constexpr LPI2C2_Reg<&LPI2C_Layout::MDMR, 8,  0> MATCH0;
}  // namespace MDMR

// Master Clock Configuration 0
namespace MCCR0 {
constexpr LPI2C2_Reg<&LPI2C_Layout::MCCR0, 6, 24> DATAVD;
constexpr LPI2C2_Reg<&LPI2C_Layout::MCCR0, 6, 16> SETHOLD;
constexpr LPI2C2_Reg<&LPI2C_Layout::MCCR0, 6,  8> CLKHI;
constexpr LPI2C2_Reg<&LPI2C_Layout::MCCR0, 6,  0> CLKLO;
}  // namespace MCCR0

// Master Clock Configuration 1
namespace MCCR1 {
constexpr LPI2C2_Reg<&LPI2C_Layout::MCCR1, 6, 24> DATAVD;
constexpr LPI2C2_Reg<&LPI2C_Layout::MCCR1, 6, 16> SETHOLD;
constexpr LPI2C2_Reg<&LPI2C_Layout::MCCR1, 6,  8> CLKHI;
constexpr LPI2C2_Reg<&LPI2C_Layout::MCCR1, 6,  0> CLKLO;
}  // namespace MCCR1

// Master FIFO Control
namespace MFCR {
constexpr LPI2C2_Reg<&LPI2C_Layout::MFCR, 2, 16> RXWATER;
constexpr LPI2C2_Reg<&LPI2C_Layout::MFCR, 2,  0> TXWATER;
}  // namespace MFCR

// Master FIFO Status
namespace MFSR {
constexpr LPI2C2_Reg<&LPI2C_Layout::MFSR, 3, 16> RXCOUNT;
constexpr LPI2C2_Reg<&LPI2C_Layout::MFSR, 3,  0> TXCOUNT;
}  // namespace MFSR

// Master Transmit Data
// Exercise caution when setting or assigning fields in this register.
namespace MTDR {
constexpr LPI2C2_Reg<&LPI2C_Layout::MTDR, 3, 8, 0x0, true> CMD;
constexpr LPI2C2_Reg<&LPI2C_Layout::MTDR, 8, 0, 0x0, true> DATA;
}  // namespace MTDR

// Master Receive Data
namespace MRDR {
constexpr LPI2C2_Reg<&LPI2C_Layout::MRDR, 1, 14> RXEMPTY;
constexpr LPI2C2_Reg<&LPI2C_Layout::MRDR, 8,  0> DATA;
}  // namespace MRDR

// Slave Control
namespace SCR {
constexpr LPI2C2_Reg<&LPI2C_Layout::SCR, 1, 9> RRF;
constexpr LPI2C2_Reg<&LPI2C_Layout::SCR, 1, 8> RTF;
constexpr LPI2C2_Reg<&LPI2C_Layout::SCR, 1, 5> FILTDZ;
constexpr LPI2C2_Reg<&LPI2C_Layout::SCR, 1, 4> FILTEN;
constexpr LPI2C2_Reg<&LPI2C_Layout::SCR, 1, 1> RST;
constexpr LPI2C2_Reg<&LPI2C_Layout::SCR, 1, 0> SEN;
}  // namespace SCR

// Slave Status
namespace SSR {
constexpr LPI2C2_Reg<regs::constify(&LPI2C_Layout::SSR), 1, 25> BBF;
constexpr LPI2C2_Reg<regs::constify(&LPI2C_Layout::SSR), 1, 24> SBF;
constexpr LPI2C2_Reg<regs::constify(&LPI2C_Layout::SSR), 1, 15> SARF;
constexpr LPI2C2_Reg<regs::constify(&LPI2C_Layout::SSR), 1, 14> GCF;
constexpr LPI2C2_Reg<regs::constify(&LPI2C_Layout::SSR), 1, 13> AM1F;
constexpr LPI2C2_Reg<regs::constify(&LPI2C_Layout::SSR), 1, 12> AM0F;
constexpr LPI2C2_Reg<&LPI2C_Layout::SSR, 1, 11, 0x0> FEF;
constexpr LPI2C2_Reg<&LPI2C_Layout::SSR, 1, 10, 0x0> BEF;
constexpr LPI2C2_Reg<&LPI2C_Layout::SSR, 1,  9, 0x0> SDF;
constexpr LPI2C2_Reg<&LPI2C_Layout::SSR, 1,  8, 0x0> RSF;
constexpr LPI2C2_Reg<regs::constify(&LPI2C_Layout::SSR), 1,  3> TAF;
constexpr LPI2C2_Reg<regs::constify(&LPI2C_Layout::SSR), 1,  2> AVF;
constexpr LPI2C2_Reg<regs::constify(&LPI2C_Layout::SSR), 1,  1> RDF;
constexpr LPI2C2_Reg<regs::constify(&LPI2C_Layout::SSR), 1,  0> TDF;
}  // namespace SSR

// Slave Interrupt Enable
namespace SIER {
constexpr LPI2C2_Reg<&LPI2C_Layout::SIER, 1, 15> SARIE;
constexpr LPI2C2_Reg<&LPI2C_Layout::SIER, 1, 14> GCIE;
constexpr LPI2C2_Reg<&LPI2C_Layout::SIER, 1, 13> AM1IE;
constexpr LPI2C2_Reg<&LPI2C_Layout::SIER, 1, 12> AM0IE;
constexpr LPI2C2_Reg<&LPI2C_Layout::SIER, 1, 11> FEIE;
constexpr LPI2C2_Reg<&LPI2C_Layout::SIER, 1, 10> BEIE;
constexpr LPI2C2_Reg<&LPI2C_Layout::SIER, 1,  9> SDIE;
constexpr LPI2C2_Reg<&LPI2C_Layout::SIER, 1,  8> RSIE;
constexpr LPI2C2_Reg<&LPI2C_Layout::SIER, 1,  3> TAIE;
constexpr LPI2C2_Reg<&LPI2C_Layout::SIER, 1,  2> AVIE;
constexpr LPI2C2_Reg<&LPI2C_Layout::SIER, 1,  1> RDIE;
constexpr LPI2C2_Reg<&LPI2C_Layout::SIER, 1,  0> TDIE;
}  // namespace SIER

// Slave DMA Enable
namespace SDER {
constexpr LPI2C2_Reg<&LPI2C_Layout::SDER, 1, 2> AVDE;
constexpr LPI2C2_Reg<&LPI2C_Layout::SDER, 1, 1> RDDE;
constexpr LPI2C2_Reg<&LPI2C_Layout::SDER, 1, 0> TDDE;
}  // namespace SDER

// Slave Configuration 1
namespace SCFGR1 {
constexpr LPI2C2_Reg<&LPI2C_Layout::SCFGR1, 3, 16> ADDRCFG;
constexpr LPI2C2_Reg<&LPI2C_Layout::SCFGR1, 1, 13> HSMEN;
constexpr LPI2C2_Reg<&LPI2C_Layout::SCFGR1, 1, 12> IGNACK;
constexpr LPI2C2_Reg<&LPI2C_Layout::SCFGR1, 1, 11> RXCFG;
constexpr LPI2C2_Reg<&LPI2C_Layout::SCFGR1, 1, 10> TXCFG;
constexpr LPI2C2_Reg<&LPI2C_Layout::SCFGR1, 1,  9> SAEN;
constexpr LPI2C2_Reg<&LPI2C_Layout::SCFGR1, 1,  8> GCEN;
constexpr LPI2C2_Reg<&LPI2C_Layout::SCFGR1, 1,  3> ACKSTALL;
constexpr LPI2C2_Reg<&LPI2C_Layout::SCFGR1, 1,  2> TXDSTALL;
constexpr LPI2C2_Reg<&LPI2C_Layout::SCFGR1, 1,  1> RXSTALL;
constexpr LPI2C2_Reg<&LPI2C_Layout::SCFGR1, 1,  0> ADRSTALL;
}  // namespace SCFGR1

// Slave Configuration 2
namespace SCFGR2 {
constexpr LPI2C2_Reg<&LPI2C_Layout::SCFGR2, 4, 24> FILTSDA;
constexpr LPI2C2_Reg<&LPI2C_Layout::SCFGR2, 4, 16> FILTSCL;
constexpr LPI2C2_Reg<&LPI2C_Layout::SCFGR2, 6,  8> DATAVD;
constexpr LPI2C2_Reg<&LPI2C_Layout::SCFGR2, 4,  0> CLKHOLD;
}  // namespace SCFGR2

// Slave Address Match
namespace SAMR {
constexpr LPI2C2_Reg<&LPI2C_Layout::SAMR, 10, 17> ADDR1;
constexpr LPI2C2_Reg<&LPI2C_Layout::SAMR, 10,  1> ADDR0;
}  // namespace SAMR

// Slave Address Status
namespace SASR {
constexpr LPI2C2_Reg<&LPI2C_Layout::SASR,  1, 14> ANV;
constexpr LPI2C2_Reg<&LPI2C_Layout::SASR, 11,  0> RADDR;
}  // namespace SASR

// Slave Transmit ACK
namespace STAR {
constexpr LPI2C2_Reg<&LPI2C_Layout::STAR, 1, 0> TXNACK;
}  // namespace STAR

// Slave Transmit Data
namespace STDR {
constexpr LPI2C2_Reg<&LPI2C_Layout::STDR, 8, 0, 0x0, true> DATA;
}  // namespace STDR

// Slave Receive Data
namespace SRDR {
constexpr LPI2C2_Reg<&LPI2C_Layout::SRDR, 1, 15> SOF;
constexpr LPI2C2_Reg<&LPI2C_Layout::SRDR, 1, 14> RXEMPTY;
constexpr LPI2C2_Reg<&LPI2C_Layout::SRDR, 8,  0> DATA;
}  // namespace SRDR

}  // namespace LPI2C2

namespace LPI2C3 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>(),
          bool WriteOnly = false>
using LPI2C3_Reg =
    regs::Reg32<kLPI2C3_base, LPI2C_Layout, Member, 0, Bits, Shift,
                AssignMask, 0, WriteOnly>;

// Version ID
namespace VERID {
constexpr LPI2C3_Reg<&LPI2C_Layout::VERID,  8, 24> MAJOR;
constexpr LPI2C3_Reg<&LPI2C_Layout::VERID,  8, 16> MINOR;
constexpr LPI2C3_Reg<&LPI2C_Layout::VERID, 16,  0> FEATURE;
}  // namespace VERID

// Parameter
namespace PARAM {
constexpr LPI2C3_Reg<&LPI2C_Layout::PARAM, 4, 8> MRXFIFO;
constexpr LPI2C3_Reg<&LPI2C_Layout::PARAM, 4, 0> MTXFIFO;
}  // namespace PARAM

// Master Control
namespace MCR {
constexpr LPI2C3_Reg<&LPI2C_Layout::MCR, 1, 9> RRF;
constexpr LPI2C3_Reg<&LPI2C_Layout::MCR, 1, 8> RTF;
constexpr LPI2C3_Reg<&LPI2C_Layout::MCR, 1, 3> DBGEN;
constexpr LPI2C3_Reg<&LPI2C_Layout::MCR, 1, 2> DOZEN;
constexpr LPI2C3_Reg<&LPI2C_Layout::MCR, 1, 1> RST;
constexpr LPI2C3_Reg<&LPI2C_Layout::MCR, 1, 0> MEN;
}  // namespace MCR

// Master Status
namespace MSR {
constexpr LPI2C3_Reg<regs::constify(&LPI2C_Layout::MSR), 1, 25> BBF;
constexpr LPI2C3_Reg<regs::constify(&LPI2C_Layout::MSR), 1, 24> MBF;
constexpr LPI2C3_Reg<&LPI2C_Layout::MSR, 1, 14, 0x0> DMF;
constexpr LPI2C3_Reg<&LPI2C_Layout::MSR, 1, 13, 0x0> PLTF;
constexpr LPI2C3_Reg<&LPI2C_Layout::MSR, 1, 12, 0x0> FEF;
constexpr LPI2C3_Reg<&LPI2C_Layout::MSR, 1, 11, 0x0> ALF;
constexpr LPI2C3_Reg<&LPI2C_Layout::MSR, 1, 10, 0x0> NDF;
constexpr LPI2C3_Reg<&LPI2C_Layout::MSR, 1,  9, 0x0> SDF;
constexpr LPI2C3_Reg<&LPI2C_Layout::MSR, 1,  8, 0x0> EPF;
constexpr LPI2C3_Reg<regs::constify(&LPI2C_Layout::MSR), 1,  1> RDF;
constexpr LPI2C3_Reg<regs::constify(&LPI2C_Layout::MSR), 1,  0> TDF;
}  // namespace MSR

// Master Interrupt Enable
namespace MIER {
constexpr LPI2C3_Reg<&LPI2C_Layout::MIER, 1, 14> DMIE;
constexpr LPI2C3_Reg<&LPI2C_Layout::MIER, 1, 13> PLTIE;
constexpr LPI2C3_Reg<&LPI2C_Layout::MIER, 1, 12> FEIE;
constexpr LPI2C3_Reg<&LPI2C_Layout::MIER, 1, 11> ALIE;
constexpr LPI2C3_Reg<&LPI2C_Layout::MIER, 1, 10> NDIE;
constexpr LPI2C3_Reg<&LPI2C_Layout::MIER, 1,  9> SDIE;
constexpr LPI2C3_Reg<&LPI2C_Layout::MIER, 1,  8> EPIE;
constexpr LPI2C3_Reg<&LPI2C_Layout::MIER, 1,  1> RDIE;
constexpr LPI2C3_Reg<&LPI2C_Layout::MIER, 1,  0> TDIE;
}  // namespace MIER

// Master DMA Enable
namespace MDER {
constexpr LPI2C3_Reg<&LPI2C_Layout::MDER, 1, 1> RDDE;
constexpr LPI2C3_Reg<&LPI2C_Layout::MDER, 1, 0> TDDE;
}  // namespace MDER

// Master Configuration 0
namespace MCFGR0 {
constexpr LPI2C3_Reg<&LPI2C_Layout::MCFGR0, 1, 9> RDMO;
constexpr LPI2C3_Reg<&LPI2C_Layout::MCFGR0, 1, 8> CIRFIFO;
constexpr LPI2C3_Reg<&LPI2C_Layout::MCFGR0, 1, 2> HRSEL;
constexpr LPI2C3_Reg<&LPI2C_Layout::MCFGR0, 1, 1> HRPOL;
constexpr LPI2C3_Reg<&LPI2C_Layout::MCFGR0, 1, 0> HREN;
}  // namespace MCFGR0

// Master Configuration 1
namespace MCFGR1 {
constexpr LPI2C3_Reg<&LPI2C_Layout::MCFGR1, 3, 24> PINCFG;
constexpr LPI2C3_Reg<&LPI2C_Layout::MCFGR1, 3, 16> MATCFG;
constexpr LPI2C3_Reg<&LPI2C_Layout::MCFGR1, 1, 10> TIMECFG;
constexpr LPI2C3_Reg<&LPI2C_Layout::MCFGR1, 1,  9> IGNACK;
constexpr LPI2C3_Reg<&LPI2C_Layout::MCFGR1, 1,  8> AUTOSTOP;
constexpr LPI2C3_Reg<&LPI2C_Layout::MCFGR1, 3,  0> PRESCALE;
}  // namespace MCFGR1

// Master Configuration 2
namespace MCFGR2 {
constexpr LPI2C3_Reg<&LPI2C_Layout::MCFGR2,  4, 24> FILTSDA;
constexpr LPI2C3_Reg<&LPI2C_Layout::MCFGR2,  4, 16> FILTSCL;
constexpr LPI2C3_Reg<&LPI2C_Layout::MCFGR2, 12,  0> BUSIDLE;
}  // namespace MCFGR2

// Master Configuration 3
namespace MCFGR3 {
constexpr LPI2C3_Reg<&LPI2C_Layout::MCFGR3, 12, 8> PINLOW;
}  // namespace MCFGR3

// Master Data Match
namespace MDMR {
constexpr LPI2C3_Reg<&LPI2C_Layout::MDMR, 8, 16> MATCH1;
constexpr LPI2C3_Reg<&LPI2C_Layout::MDMR, 8,  0> MATCH0;
}  // namespace MDMR

// Master Clock Configuration 0
namespace MCCR0 {
constexpr LPI2C3_Reg<&LPI2C_Layout::MCCR0, 6, 24> DATAVD;
constexpr LPI2C3_Reg<&LPI2C_Layout::MCCR0, 6, 16> SETHOLD;
constexpr LPI2C3_Reg<&LPI2C_Layout::MCCR0, 6,  8> CLKHI;
constexpr LPI2C3_Reg<&LPI2C_Layout::MCCR0, 6,  0> CLKLO;
}  // namespace MCCR0

// Master Clock Configuration 1
namespace MCCR1 {
constexpr LPI2C3_Reg<&LPI2C_Layout::MCCR1, 6, 24> DATAVD;
constexpr LPI2C3_Reg<&LPI2C_Layout::MCCR1, 6, 16> SETHOLD;
constexpr LPI2C3_Reg<&LPI2C_Layout::MCCR1, 6,  8> CLKHI;
constexpr LPI2C3_Reg<&LPI2C_Layout::MCCR1, 6,  0> CLKLO;
}  // namespace MCCR1

// Master FIFO Control
namespace MFCR {
constexpr LPI2C3_Reg<&LPI2C_Layout::MFCR, 2, 16> RXWATER;
constexpr LPI2C3_Reg<&LPI2C_Layout::MFCR, 2,  0> TXWATER;
}  // namespace MFCR

// Master FIFO Status
namespace MFSR {
constexpr LPI2C3_Reg<&LPI2C_Layout::MFSR, 3, 16> RXCOUNT;
constexpr LPI2C3_Reg<&LPI2C_Layout::MFSR, 3,  0> TXCOUNT;
}  // namespace MFSR

// Master Transmit Data
// Exercise caution when setting or assigning fields in this register.
namespace MTDR {
constexpr LPI2C3_Reg<&LPI2C_Layout::MTDR, 3, 8, 0x0, true> CMD;
constexpr LPI2C3_Reg<&LPI2C_Layout::MTDR, 8, 0, 0x0, true> DATA;
}  // namespace MTDR

// Master Receive Data
namespace MRDR {
constexpr LPI2C3_Reg<&LPI2C_Layout::MRDR, 1, 14> RXEMPTY;
constexpr LPI2C3_Reg<&LPI2C_Layout::MRDR, 8,  0> DATA;
}  // namespace MRDR

// Slave Control
namespace SCR {
constexpr LPI2C3_Reg<&LPI2C_Layout::SCR, 1, 9> RRF;
constexpr LPI2C3_Reg<&LPI2C_Layout::SCR, 1, 8> RTF;
constexpr LPI2C3_Reg<&LPI2C_Layout::SCR, 1, 5> FILTDZ;
constexpr LPI2C3_Reg<&LPI2C_Layout::SCR, 1, 4> FILTEN;
constexpr LPI2C3_Reg<&LPI2C_Layout::SCR, 1, 1> RST;
constexpr LPI2C3_Reg<&LPI2C_Layout::SCR, 1, 0> SEN;
}  // namespace SCR

// Slave Status
namespace SSR {
constexpr LPI2C3_Reg<regs::constify(&LPI2C_Layout::SSR), 1, 25> BBF;
constexpr LPI2C3_Reg<regs::constify(&LPI2C_Layout::SSR), 1, 24> SBF;
constexpr LPI2C3_Reg<regs::constify(&LPI2C_Layout::SSR), 1, 15> SARF;
constexpr LPI2C3_Reg<regs::constify(&LPI2C_Layout::SSR), 1, 14> GCF;
constexpr LPI2C3_Reg<regs::constify(&LPI2C_Layout::SSR), 1, 13> AM1F;
constexpr LPI2C3_Reg<regs::constify(&LPI2C_Layout::SSR), 1, 12> AM0F;
constexpr LPI2C3_Reg<&LPI2C_Layout::SSR, 1, 11, 0x0> FEF;
constexpr LPI2C3_Reg<&LPI2C_Layout::SSR, 1, 10, 0x0> BEF;
constexpr LPI2C3_Reg<&LPI2C_Layout::SSR, 1,  9, 0x0> SDF;
constexpr LPI2C3_Reg<&LPI2C_Layout::SSR, 1,  8, 0x0> RSF;
constexpr LPI2C3_Reg<regs::constify(&LPI2C_Layout::SSR), 1,  3> TAF;
constexpr LPI2C3_Reg<regs::constify(&LPI2C_Layout::SSR), 1,  2> AVF;
constexpr LPI2C3_Reg<regs::constify(&LPI2C_Layout::SSR), 1,  1> RDF;
constexpr LPI2C3_Reg<regs::constify(&LPI2C_Layout::SSR), 1,  0> TDF;
}  // namespace SSR

// Slave Interrupt Enable
namespace SIER {
constexpr LPI2C3_Reg<&LPI2C_Layout::SIER, 1, 15> SARIE;
constexpr LPI2C3_Reg<&LPI2C_Layout::SIER, 1, 14> GCIE;
constexpr LPI2C3_Reg<&LPI2C_Layout::SIER, 1, 13> AM1IE;
constexpr LPI2C3_Reg<&LPI2C_Layout::SIER, 1, 12> AM0IE;
constexpr LPI2C3_Reg<&LPI2C_Layout::SIER, 1, 11> FEIE;
constexpr LPI2C3_Reg<&LPI2C_Layout::SIER, 1, 10> BEIE;
constexpr LPI2C3_Reg<&LPI2C_Layout::SIER, 1,  9> SDIE;
constexpr LPI2C3_Reg<&LPI2C_Layout::SIER, 1,  8> RSIE;
constexpr LPI2C3_Reg<&LPI2C_Layout::SIER, 1,  3> TAIE;
constexpr LPI2C3_Reg<&LPI2C_Layout::SIER, 1,  2> AVIE;
constexpr LPI2C3_Reg<&LPI2C_Layout::SIER, 1,  1> RDIE;
constexpr LPI2C3_Reg<&LPI2C_Layout::SIER, 1,  0> TDIE;
}  // namespace SIER

// Slave DMA Enable
namespace SDER {
constexpr LPI2C3_Reg<&LPI2C_Layout::SDER, 1, 2> AVDE;
constexpr LPI2C3_Reg<&LPI2C_Layout::SDER, 1, 1> RDDE;
constexpr LPI2C3_Reg<&LPI2C_Layout::SDER, 1, 0> TDDE;
}  // namespace SDER

// Slave Configuration 1
namespace SCFGR1 {
constexpr LPI2C3_Reg<&LPI2C_Layout::SCFGR1, 3, 16> ADDRCFG;
constexpr LPI2C3_Reg<&LPI2C_Layout::SCFGR1, 1, 13> HSMEN;
constexpr LPI2C3_Reg<&LPI2C_Layout::SCFGR1, 1, 12> IGNACK;
constexpr LPI2C3_Reg<&LPI2C_Layout::SCFGR1, 1, 11> RXCFG;
constexpr LPI2C3_Reg<&LPI2C_Layout::SCFGR1, 1, 10> TXCFG;
constexpr LPI2C3_Reg<&LPI2C_Layout::SCFGR1, 1,  9> SAEN;
constexpr LPI2C3_Reg<&LPI2C_Layout::SCFGR1, 1,  8> GCEN;
constexpr LPI2C3_Reg<&LPI2C_Layout::SCFGR1, 1,  3> ACKSTALL;
constexpr LPI2C3_Reg<&LPI2C_Layout::SCFGR1, 1,  2> TXDSTALL;
constexpr LPI2C3_Reg<&LPI2C_Layout::SCFGR1, 1,  1> RXSTALL;
constexpr LPI2C3_Reg<&LPI2C_Layout::SCFGR1, 1,  0> ADRSTALL;
}  // namespace SCFGR1

// Slave Configuration 2
namespace SCFGR2 {
constexpr LPI2C3_Reg<&LPI2C_Layout::SCFGR2, 4, 24> FILTSDA;
constexpr LPI2C3_Reg<&LPI2C_Layout::SCFGR2, 4, 16> FILTSCL;
constexpr LPI2C3_Reg<&LPI2C_Layout::SCFGR2, 6,  8> DATAVD;
constexpr LPI2C3_Reg<&LPI2C_Layout::SCFGR2, 4,  0> CLKHOLD;
}  // namespace SCFGR2

// Slave Address Match
namespace SAMR {
constexpr LPI2C3_Reg<&LPI2C_Layout::SAMR, 10, 17> ADDR1;
constexpr LPI2C3_Reg<&LPI2C_Layout::SAMR, 10,  1> ADDR0;
}  // namespace SAMR

// Slave Address Status
namespace SASR {
constexpr LPI2C3_Reg<&LPI2C_Layout::SASR,  1, 14> ANV;
constexpr LPI2C3_Reg<&LPI2C_Layout::SASR, 11,  0> RADDR;
}  // namespace SASR

// Slave Transmit ACK
namespace STAR {
constexpr LPI2C3_Reg<&LPI2C_Layout::STAR, 1, 0> TXNACK;
}  // namespace STAR

// Slave Transmit Data
namespace STDR {
constexpr LPI2C3_Reg<&LPI2C_Layout::STDR, 8, 0, 0x0, true> DATA;
}  // namespace STDR

// Slave Receive Data
namespace SRDR {
constexpr LPI2C3_Reg<&LPI2C_Layout::SRDR, 1, 15> SOF;
constexpr LPI2C3_Reg<&LPI2C_Layout::SRDR, 1, 14> RXEMPTY;
constexpr LPI2C3_Reg<&LPI2C_Layout::SRDR, 8,  0> DATA;
}  // namespace SRDR

}  // namespace LPI2C3

namespace LPI2C4 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>(),
          bool WriteOnly = false>
using LPI2C4_Reg =
    regs::Reg32<kLPI2C4_base, LPI2C_Layout, Member, 0, Bits, Shift,
                AssignMask, 0, WriteOnly>;

// Version ID
namespace VERID {
constexpr LPI2C4_Reg<&LPI2C_Layout::VERID,  8, 24> MAJOR;
constexpr LPI2C4_Reg<&LPI2C_Layout::VERID,  8, 16> MINOR;
constexpr LPI2C4_Reg<&LPI2C_Layout::VERID, 16,  0> FEATURE;
}  // namespace VERID

// Parameter
namespace PARAM {
constexpr LPI2C4_Reg<&LPI2C_Layout::PARAM, 4, 8> MRXFIFO;
constexpr LPI2C4_Reg<&LPI2C_Layout::PARAM, 4, 0> MTXFIFO;
}  // namespace PARAM

// Master Control
namespace MCR {
constexpr LPI2C4_Reg<&LPI2C_Layout::MCR, 1, 9> RRF;
constexpr LPI2C4_Reg<&LPI2C_Layout::MCR, 1, 8> RTF;
constexpr LPI2C4_Reg<&LPI2C_Layout::MCR, 1, 3> DBGEN;
constexpr LPI2C4_Reg<&LPI2C_Layout::MCR, 1, 2> DOZEN;
constexpr LPI2C4_Reg<&LPI2C_Layout::MCR, 1, 1> RST;
constexpr LPI2C4_Reg<&LPI2C_Layout::MCR, 1, 0> MEN;
}  // namespace MCR

// Master Status
namespace MSR {
constexpr LPI2C4_Reg<regs::constify(&LPI2C_Layout::MSR), 1, 25> BBF;
constexpr LPI2C4_Reg<regs::constify(&LPI2C_Layout::MSR), 1, 24> MBF;
constexpr LPI2C4_Reg<&LPI2C_Layout::MSR, 1, 14, 0x0> DMF;
constexpr LPI2C4_Reg<&LPI2C_Layout::MSR, 1, 13, 0x0> PLTF;
constexpr LPI2C4_Reg<&LPI2C_Layout::MSR, 1, 12, 0x0> FEF;
constexpr LPI2C4_Reg<&LPI2C_Layout::MSR, 1, 11, 0x0> ALF;
constexpr LPI2C4_Reg<&LPI2C_Layout::MSR, 1, 10, 0x0> NDF;
constexpr LPI2C4_Reg<&LPI2C_Layout::MSR, 1,  9, 0x0> SDF;
constexpr LPI2C4_Reg<&LPI2C_Layout::MSR, 1,  8, 0x0> EPF;
constexpr LPI2C4_Reg<regs::constify(&LPI2C_Layout::MSR), 1,  1> RDF;
constexpr LPI2C4_Reg<regs::constify(&LPI2C_Layout::MSR), 1,  0> TDF;
}  // namespace MSR

// Master Interrupt Enable
namespace MIER {
constexpr LPI2C4_Reg<&LPI2C_Layout::MIER, 1, 14> DMIE;
constexpr LPI2C4_Reg<&LPI2C_Layout::MIER, 1, 13> PLTIE;
constexpr LPI2C4_Reg<&LPI2C_Layout::MIER, 1, 12> FEIE;
constexpr LPI2C4_Reg<&LPI2C_Layout::MIER, 1, 11> ALIE;
constexpr LPI2C4_Reg<&LPI2C_Layout::MIER, 1, 10> NDIE;
constexpr LPI2C4_Reg<&LPI2C_Layout::MIER, 1,  9> SDIE;
constexpr LPI2C4_Reg<&LPI2C_Layout::MIER, 1,  8> EPIE;
constexpr LPI2C4_Reg<&LPI2C_Layout::MIER, 1,  1> RDIE;
constexpr LPI2C4_Reg<&LPI2C_Layout::MIER, 1,  0> TDIE;
}  // namespace MIER

// Master DMA Enable
namespace MDER {
constexpr LPI2C4_Reg<&LPI2C_Layout::MDER, 1, 1> RDDE;
constexpr LPI2C4_Reg<&LPI2C_Layout::MDER, 1, 0> TDDE;
}  // namespace MDER

// Master Configuration 0
namespace MCFGR0 {
constexpr LPI2C4_Reg<&LPI2C_Layout::MCFGR0, 1, 9> RDMO;
constexpr LPI2C4_Reg<&LPI2C_Layout::MCFGR0, 1, 8> CIRFIFO;
constexpr LPI2C4_Reg<&LPI2C_Layout::MCFGR0, 1, 2> HRSEL;
constexpr LPI2C4_Reg<&LPI2C_Layout::MCFGR0, 1, 1> HRPOL;
constexpr LPI2C4_Reg<&LPI2C_Layout::MCFGR0, 1, 0> HREN;
}  // namespace MCFGR0

// Master Configuration 1
namespace MCFGR1 {
constexpr LPI2C4_Reg<&LPI2C_Layout::MCFGR1, 3, 24> PINCFG;
constexpr LPI2C4_Reg<&LPI2C_Layout::MCFGR1, 3, 16> MATCFG;
constexpr LPI2C4_Reg<&LPI2C_Layout::MCFGR1, 1, 10> TIMECFG;
constexpr LPI2C4_Reg<&LPI2C_Layout::MCFGR1, 1,  9> IGNACK;
constexpr LPI2C4_Reg<&LPI2C_Layout::MCFGR1, 1,  8> AUTOSTOP;
constexpr LPI2C4_Reg<&LPI2C_Layout::MCFGR1, 3,  0> PRESCALE;
}  // namespace MCFGR1

// Master Configuration 2
namespace MCFGR2 {
constexpr LPI2C4_Reg<&LPI2C_Layout::MCFGR2,  4, 24> FILTSDA;
constexpr LPI2C4_Reg<&LPI2C_Layout::MCFGR2,  4, 16> FILTSCL;
constexpr LPI2C4_Reg<&LPI2C_Layout::MCFGR2, 12,  0> BUSIDLE;
}  // namespace MCFGR2

// Master Configuration 3
namespace MCFGR3 {
constexpr LPI2C4_Reg<&LPI2C_Layout::MCFGR3, 12, 8> PINLOW;
}  // namespace MCFGR3

// Master Data Match
namespace MDMR {
constexpr LPI2C4_Reg<&LPI2C_Layout::MDMR, 8, 16> MATCH1;
constexpr LPI2C4_Reg<&LPI2C_Layout::MDMR, 8,  0> MATCH0;
}  // namespace MDMR

// Master Clock Configuration 0
namespace MCCR0 {
constexpr LPI2C4_Reg<&LPI2C_Layout::MCCR0, 6, 24> DATAVD;
constexpr LPI2C4_Reg<&LPI2C_Layout::MCCR0, 6, 16> SETHOLD;
constexpr LPI2C4_Reg<&LPI2C_Layout::MCCR0, 6,  8> CLKHI;
constexpr LPI2C4_Reg<&LPI2C_Layout::MCCR0, 6,  0> CLKLO;
}  // namespace MCCR0

// Master Clock Configuration 1
namespace MCCR1 {
constexpr LPI2C4_Reg<&LPI2C_Layout::MCCR1, 6, 24> DATAVD;
constexpr LPI2C4_Reg<&LPI2C_Layout::MCCR1, 6, 16> SETHOLD;
constexpr LPI2C4_Reg<&LPI2C_Layout::MCCR1, 6,  8> CLKHI;
constexpr LPI2C4_Reg<&LPI2C_Layout::MCCR1, 6,  0> CLKLO;
}  // namespace MCCR1

// Master FIFO Control
namespace MFCR {
constexpr LPI2C4_Reg<&LPI2C_Layout::MFCR, 2, 16> RXWATER;
constexpr LPI2C4_Reg<&LPI2C_Layout::MFCR, 2,  0> TXWATER;
}  // namespace MFCR

// Master FIFO Status
namespace MFSR {
constexpr LPI2C4_Reg<&LPI2C_Layout::MFSR, 3, 16> RXCOUNT;
constexpr LPI2C4_Reg<&LPI2C_Layout::MFSR, 3,  0> TXCOUNT;
}  // namespace MFSR

// Master Transmit Data
// Exercise caution when setting or assigning fields in this register.
namespace MTDR {
constexpr LPI2C4_Reg<&LPI2C_Layout::MTDR, 3, 8, 0x0, true> CMD;
constexpr LPI2C4_Reg<&LPI2C_Layout::MTDR, 8, 0, 0x0, true> DATA;
}  // namespace MTDR

// Master Receive Data
namespace MRDR {
constexpr LPI2C4_Reg<&LPI2C_Layout::MRDR, 1, 14> RXEMPTY;
constexpr LPI2C4_Reg<&LPI2C_Layout::MRDR, 8,  0> DATA;
}  // namespace MRDR

// Slave Control
namespace SCR {
constexpr LPI2C4_Reg<&LPI2C_Layout::SCR, 1, 9> RRF;
constexpr LPI2C4_Reg<&LPI2C_Layout::SCR, 1, 8> RTF;
constexpr LPI2C4_Reg<&LPI2C_Layout::SCR, 1, 5> FILTDZ;
constexpr LPI2C4_Reg<&LPI2C_Layout::SCR, 1, 4> FILTEN;
constexpr LPI2C4_Reg<&LPI2C_Layout::SCR, 1, 1> RST;
constexpr LPI2C4_Reg<&LPI2C_Layout::SCR, 1, 0> SEN;
}  // namespace SCR

// Slave Status
namespace SSR {
constexpr LPI2C4_Reg<regs::constify(&LPI2C_Layout::SSR), 1, 25> BBF;
constexpr LPI2C4_Reg<regs::constify(&LPI2C_Layout::SSR), 1, 24> SBF;
constexpr LPI2C4_Reg<regs::constify(&LPI2C_Layout::SSR), 1, 15> SARF;
constexpr LPI2C4_Reg<regs::constify(&LPI2C_Layout::SSR), 1, 14> GCF;
constexpr LPI2C4_Reg<regs::constify(&LPI2C_Layout::SSR), 1, 13> AM1F;
constexpr LPI2C4_Reg<regs::constify(&LPI2C_Layout::SSR), 1, 12> AM0F;
constexpr LPI2C4_Reg<&LPI2C_Layout::SSR, 1, 11, 0x0> FEF;
constexpr LPI2C4_Reg<&LPI2C_Layout::SSR, 1, 10, 0x0> BEF;
constexpr LPI2C4_Reg<&LPI2C_Layout::SSR, 1,  9, 0x0> SDF;
constexpr LPI2C4_Reg<&LPI2C_Layout::SSR, 1,  8, 0x0> RSF;
constexpr LPI2C4_Reg<regs::constify(&LPI2C_Layout::SSR), 1,  3> TAF;
constexpr LPI2C4_Reg<regs::constify(&LPI2C_Layout::SSR), 1,  2> AVF;
constexpr LPI2C4_Reg<regs::constify(&LPI2C_Layout::SSR), 1,  1> RDF;
constexpr LPI2C4_Reg<regs::constify(&LPI2C_Layout::SSR), 1,  0> TDF;
}  // namespace SSR

// Slave Interrupt Enable
namespace SIER {
constexpr LPI2C4_Reg<&LPI2C_Layout::SIER, 1, 15> SARIE;
constexpr LPI2C4_Reg<&LPI2C_Layout::SIER, 1, 14> GCIE;
constexpr LPI2C4_Reg<&LPI2C_Layout::SIER, 1, 13> AM1IE;
constexpr LPI2C4_Reg<&LPI2C_Layout::SIER, 1, 12> AM0IE;
constexpr LPI2C4_Reg<&LPI2C_Layout::SIER, 1, 11> FEIE;
constexpr LPI2C4_Reg<&LPI2C_Layout::SIER, 1, 10> BEIE;
constexpr LPI2C4_Reg<&LPI2C_Layout::SIER, 1,  9> SDIE;
constexpr LPI2C4_Reg<&LPI2C_Layout::SIER, 1,  8> RSIE;
constexpr LPI2C4_Reg<&LPI2C_Layout::SIER, 1,  3> TAIE;
constexpr LPI2C4_Reg<&LPI2C_Layout::SIER, 1,  2> AVIE;
constexpr LPI2C4_Reg<&LPI2C_Layout::SIER, 1,  1> RDIE;
constexpr LPI2C4_Reg<&LPI2C_Layout::SIER, 1,  0> TDIE;
}  // namespace SIER

// Slave DMA Enable
namespace SDER {
constexpr LPI2C4_Reg<&LPI2C_Layout::SDER, 1, 2> AVDE;
constexpr LPI2C4_Reg<&LPI2C_Layout::SDER, 1, 1> RDDE;
constexpr LPI2C4_Reg<&LPI2C_Layout::SDER, 1, 0> TDDE;
}  // namespace SDER

// Slave Configuration 1
namespace SCFGR1 {
constexpr LPI2C4_Reg<&LPI2C_Layout::SCFGR1, 3, 16> ADDRCFG;
constexpr LPI2C4_Reg<&LPI2C_Layout::SCFGR1, 1, 13> HSMEN;
constexpr LPI2C4_Reg<&LPI2C_Layout::SCFGR1, 1, 12> IGNACK;
constexpr LPI2C4_Reg<&LPI2C_Layout::SCFGR1, 1, 11> RXCFG;
constexpr LPI2C4_Reg<&LPI2C_Layout::SCFGR1, 1, 10> TXCFG;
constexpr LPI2C4_Reg<&LPI2C_Layout::SCFGR1, 1,  9> SAEN;
constexpr LPI2C4_Reg<&LPI2C_Layout::SCFGR1, 1,  8> GCEN;
constexpr LPI2C4_Reg<&LPI2C_Layout::SCFGR1, 1,  3> ACKSTALL;
constexpr LPI2C4_Reg<&LPI2C_Layout::SCFGR1, 1,  2> TXDSTALL;
constexpr LPI2C4_Reg<&LPI2C_Layout::SCFGR1, 1,  1> RXSTALL;
constexpr LPI2C4_Reg<&LPI2C_Layout::SCFGR1, 1,  0> ADRSTALL;
}  // namespace SCFGR1

// Slave Configuration 2
namespace SCFGR2 {
constexpr LPI2C4_Reg<&LPI2C_Layout::SCFGR2, 4, 24> FILTSDA;
constexpr LPI2C4_Reg<&LPI2C_Layout::SCFGR2, 4, 16> FILTSCL;
constexpr LPI2C4_Reg<&LPI2C_Layout::SCFGR2, 6,  8> DATAVD;
constexpr LPI2C4_Reg<&LPI2C_Layout::SCFGR2, 4,  0> CLKHOLD;
}  // namespace SCFGR2

// Slave Address Match
namespace SAMR {
constexpr LPI2C4_Reg<&LPI2C_Layout::SAMR, 10, 17> ADDR1;
constexpr LPI2C4_Reg<&LPI2C_Layout::SAMR, 10,  1> ADDR0;
}  // namespace SAMR

// Slave Address Status
namespace SASR {
constexpr LPI2C4_Reg<&LPI2C_Layout::SASR,  1, 14> ANV;
constexpr LPI2C4_Reg<&LPI2C_Layout::SASR, 11,  0> RADDR;
}  // namespace SASR

// Slave Transmit ACK
namespace STAR {
constexpr LPI2C4_Reg<&LPI2C_Layout::STAR, 1, 0> TXNACK;
}  // namespace STAR

// Slave Transmit Data
namespace STDR {
constexpr LPI2C4_Reg<&LPI2C_Layout::STDR, 8, 0, 0x0, true> DATA;
}  // namespace STDR

// Slave Receive Data
namespace SRDR {
constexpr LPI2C4_Reg<&LPI2C_Layout::SRDR, 1, 15> SOF;
constexpr LPI2C4_Reg<&LPI2C_Layout::SRDR, 1, 14> RXEMPTY;
constexpr LPI2C4_Reg<&LPI2C_Layout::SRDR, 8,  0> DATA;
}  // namespace SRDR

}  // namespace LPI2C4

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
