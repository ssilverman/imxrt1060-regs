// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// LPSPI.h defines all the LPSPI registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the Low Power Serial Peripheral Interface
// (LPSPI) registers.
//
// Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_LPSPI.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct LPSPI_Layout {
  const volatile uint32_t VERID;                       /**< Version ID, offset: 0x0 */
  const volatile uint32_t PARAM;                       /**< Parameter, offset: 0x4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[2];
  volatile uint32_t CR;                                /**< Control, offset: 0x10 */
  volatile uint32_t SR;                                /**< Status, offset: 0x14 */
  volatile uint32_t IER;                               /**< Interrupt Enable, offset: 0x18 */
  volatile uint32_t DER;                               /**< DMA Enable, offset: 0x1C */
  volatile uint32_t CFGR0;                             /**< Configuration 0, offset: 0x20 */
  volatile uint32_t CFGR1;                             /**< Configuration 1, offset: 0x24 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[2];
  volatile uint32_t DMR0;                              /**< Data Match 0, offset: 0x30 */
  volatile uint32_t DMR1;                              /**< Data Match 1, offset: 0x34 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[2];
  volatile uint32_t CCR;                               /**< Clock Configuration, offset: 0x40 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[5];
  volatile uint32_t FCR;                               /**< FIFO Control, offset: 0x58 */
  const volatile uint32_t FSR;                         /**< FIFO Status, offset: 0x5C */
  volatile uint32_t TCR;                               /**< Transmit Command, offset: 0x60 */
  volatile uint32_t TDR;                               /**< Transmit Data, offset: 0x64 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[2];
  const volatile uint32_t RSR;                         /**< Receive Status, offset: 0x70 */
  const volatile uint32_t RDR;                         /**< Receive Data, offset: 0x74 */
};

constexpr size_t    kLPSPI_size  = 0x78;
constexpr uintptr_t kLPSPI1_base = 0x40394000;
constexpr uintptr_t kLPSPI2_base = 0x40398000;
constexpr uintptr_t kLPSPI3_base = 0x4039C000;
constexpr uintptr_t kLPSPI4_base = 0x403A0000;

namespace LPSPI1 {
constexpr regs::RegGroup<LPSPI_Layout, kLPSPI_size, kLPSPI1_base> group;
}  // namespace LPSPI1

namespace LPSPI2 {
constexpr regs::RegGroup<LPSPI_Layout, kLPSPI_size, kLPSPI2_base> group;
}  // namespace LPSPI2

namespace LPSPI3 {
constexpr regs::RegGroup<LPSPI_Layout, kLPSPI_size, kLPSPI3_base> group;
}  // namespace LPSPI3

namespace LPSPI4 {
constexpr regs::RegGroup<LPSPI_Layout, kLPSPI_size, kLPSPI4_base> group;
}  // namespace LPSPI4

namespace LPSPI1 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false>
using LPSPI1_Reg =
    regs::Reg32<kLPSPI1_base, LPSPI_Layout, Member, 0, Bits, Shift,
                AssignMask, WriteOnly>;

// Version ID
namespace VERID {
constexpr LPSPI1_Reg<&LPSPI_Layout::VERID,  8, 24> MAJOR;    // Major Version Number
constexpr LPSPI1_Reg<&LPSPI_Layout::VERID,  8, 16> MINOR;    // Minor Version Number
constexpr LPSPI1_Reg<&LPSPI_Layout::VERID, 16,  0> FEATURE;  // Module Identification Number
    // 0b0000000000000100..Standard feature set supporting a 32-bit shift register.
}  // namespace VERID

// Parameter
namespace PARAM {
constexpr LPSPI1_Reg<&LPSPI_Layout::PARAM, 8, 16> PCSNUM;  // PCS Number
constexpr LPSPI1_Reg<&LPSPI_Layout::PARAM, 8,  8> RXFIFO;  // Receive FIFO Size
constexpr LPSPI1_Reg<&LPSPI_Layout::PARAM, 8,  0> TXFIFO;  // Transmit FIFO Size
}  // namespace PARAM

// Control
namespace CR {
// TODO: Is this the correct way?
constexpr uint32_t kWO = 0x0000'0300;

constexpr LPSPI1_Reg<&LPSPI_Layout::CR, 1, 9, kWO, true> RRF;                     // Reset Receive FIFO
    // 0b0..No effect
    // 0b1..Reset the Receive FIFO. The register bit always reads zero.
constexpr LPSPI1_Reg<&LPSPI_Layout::CR, 1, 8, kWO, true> RTF;                     // Reset Transmit FIFO
    // 0b0..No effect
    // 0b1..Reset the Transmit FIFO. The register bit always reads zero.
constexpr LPSPI1_Reg<&LPSPI_Layout::CR, 1, 3, (uint32_t{0x1} << 3) | kWO> DBGEN;  // Debug Enable
    // 0b0..LPSPI module is disabled when the CPU is halted. When LPSPI is disabled, the PCS will be negated once
    //     the transmit FIFO is empty regardless of the state of TCR register.
    // 0b1..LPSPI module is enabled in debug mode
constexpr LPSPI1_Reg<&LPSPI_Layout::CR, 1, 2, (uint32_t{0x1} << 2) | kWO> DOZEN;  // Doze Mode Enable
    // 0b0..LPSPI module is enabled in Doze mode
    // 0b1..LPSPI module is disabled in Doze mode
constexpr LPSPI1_Reg<&LPSPI_Layout::CR, 1, 1, (uint32_t{0x1} << 1) | kWO> RST;    // Software Reset
    // 0b0..Module is not reset
    // 0b1..Module is reset
constexpr LPSPI1_Reg<&LPSPI_Layout::CR, 1, 0, (uint32_t{0x1} << 0) | kWO> MEN;    // Module Enable
    // 0b0..Module is disabled
    // 0b1..Module is enabled
}  // namespace CR

// Status
namespace SR {
constexpr LPSPI1_Reg<regs::constify(&LPSPI_Layout::SR), 1, 24> MBF;  // Module Busy Flag
    // 0b0..LPSPI is idle
    // 0b1..LPSPI is busy
constexpr LPSPI1_Reg<&LPSPI_Layout::SR, 1, 13, 0x0> DMF;             // Data Match Flag
    // 0b0..Have not received matching data
    // 0b1..Have received matching data
constexpr LPSPI1_Reg<&LPSPI_Layout::SR, 1, 12, 0x0> REF;             // Receive Error Flag
    // 0b0..Receive FIFO has not overflowed
    // 0b1..Receive FIFO has overflowed
constexpr LPSPI1_Reg<&LPSPI_Layout::SR, 1, 11, 0x0> TEF;             // Transmit Error Flag
    // 0b0..Transmit FIFO underrun has not occurred
    // 0b1..Transmit FIFO underrun has occurred
constexpr LPSPI1_Reg<&LPSPI_Layout::SR, 1, 10, 0x0> TCF;             // Transfer Complete Flag
    // 0b0..All transfers have not completed
    // 0b1..All transfers have completed
constexpr LPSPI1_Reg<&LPSPI_Layout::SR, 1,  9, 0x0> FCF;             // Frame Complete Flag
    // 0b0..Frame transfer has not completed
    // 0b1..Frame transfer has completed
constexpr LPSPI1_Reg<&LPSPI_Layout::SR, 1,  8, 0x0> WCF;             // Word Complete Flag
    // 0b0..Transfer of a received word has not yet completed
    // 0b1..Transfer of a received word has completed
constexpr LPSPI1_Reg<regs::constify(&LPSPI_Layout::SR), 1,  1> RDF;  // Receive Data Flag
    // 0b0..Receive Data is not ready
    // 0b1..Receive data is ready
constexpr LPSPI1_Reg<regs::constify(&LPSPI_Layout::SR), 1,  0> TDF;  // Transmit Data Flag
    // 0b0..Transmit data not requested
    // 0b1..Transmit data is requested
}  // namespace SR

// Interrupt Enable
namespace IER {
constexpr LPSPI1_Reg<&LPSPI_Layout::IER, 1, 13> DMIE;  // Data Match Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr LPSPI1_Reg<&LPSPI_Layout::IER, 1, 12> REIE;  // Receive Error Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr LPSPI1_Reg<&LPSPI_Layout::IER, 1, 11> TEIE;  // Transmit Error Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr LPSPI1_Reg<&LPSPI_Layout::IER, 1, 10> TCIE;  // Transfer Complete Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr LPSPI1_Reg<&LPSPI_Layout::IER, 1,  9> FCIE;  // Frame Complete Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr LPSPI1_Reg<&LPSPI_Layout::IER, 1,  8> WCIE;  // Word Complete Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr LPSPI1_Reg<&LPSPI_Layout::IER, 1,  1> RDIE;  // Receive Data Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
constexpr LPSPI1_Reg<&LPSPI_Layout::IER, 1,  0> TDIE;  // Transmit Data Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
}  // namespace IER

// DMA Enable
namespace DER {
constexpr LPSPI1_Reg<&LPSPI_Layout::DER, 1, 1> RDDE;  // Receive Data DMA Enable
    // 0b0..DMA request is disabled
    // 0b1..DMA request is enabled
constexpr LPSPI1_Reg<&LPSPI_Layout::DER, 1, 0> TDDE;  // Transmit Data DMA Enable
    // 0b0..DMA request is disabled
    // 0b1..DMA request is enabled
}  // namespace DER

// Configuration 0
namespace CFGR0 {
constexpr LPSPI1_Reg<&LPSPI_Layout::CFGR0, 1, 9> RDMO;     // Receive Data Match Only
    // 0b0..Received data is stored in the receive FIFO as in normal operations
    // 0b1..Received data is discarded unless the SR[DMF] = 1
constexpr LPSPI1_Reg<&LPSPI_Layout::CFGR0, 1, 8> CIRFIFO;  // Circular FIFO Enable
    // 0b0..Circular FIFO is disabled
    // 0b1..Circular FIFO is enabled
constexpr LPSPI1_Reg<&LPSPI_Layout::CFGR0, 1, 2> HRSEL;    // Host Request Select
    // 0b0..Host request input is the HREQ pin
    // 0b1..Host request input is the input trigger
constexpr LPSPI1_Reg<&LPSPI_Layout::CFGR0, 1, 1> HRPOL;    // Host Request Polarity
    // 0b0..HREQ pin is active high provided PCSPOL[1] is clear
    // 0b1..HREQ pin is active low provided PCSPOL[1] is clear
constexpr LPSPI1_Reg<&LPSPI_Layout::CFGR0, 1, 0> HREN;     // Host Request Enable
    // 0b0..Host request is disabled
    // 0b1..Host request is enabled
}  // namespace CFGR0

// Configuration 1
namespace CFGR1 {
constexpr LPSPI1_Reg<&LPSPI_Layout::CFGR1, 1, 27> PCSCFG;   // Peripheral Chip Select Configuration
    // 0b0..PCS[3:2] are configured for chip select function
    // 0b1..PCS[3:2] are configured for half-duplex 4-bit transfers (PCS[3:2] = DATA[3:2])
constexpr LPSPI1_Reg<&LPSPI_Layout::CFGR1, 1, 26> OUTCFG;   // Output Configuration
    // 0b0..Output data retains last value when chip select is negated
    // 0b1..Output data is tristated when chip select is negated
constexpr LPSPI1_Reg<&LPSPI_Layout::CFGR1, 2, 24> PINCFG;   // Pin Configuration
    // 0b00..SIN is used for input data and SOUT is used for output data
    // 0b01..SIN is used for both input and output data, only half-duplex serial transfers are supported
    // 0b10..SOUT is used for both input and output data, only half-duplex serial transfers are supported
    // 0b11..SOUT is used for input data and SIN is used for output data
constexpr LPSPI1_Reg<&LPSPI_Layout::CFGR1, 3, 16> MATCFG;   // Match Configuration
    // 0b000..Match is disabled
    // 0b001..Reserved
    // 0b010..Match is enabled is 1st data word is MATCH0 or MATCH1
    // 0b011..Match is enabled on any data word equal MATCH0 or MATCH1
    // 0b100..Match is enabled on data match sequence
    // 0b101..Match is enabled on data match sequence
    // 0b110..Match is enabled
    // 0b111..Match is enabled
constexpr LPSPI1_Reg<&LPSPI_Layout::CFGR1, 4,  8> PCSPOL;   // Peripheral Chip Select Polarity
constexpr LPSPI1_Reg<&LPSPI_Layout::CFGR1, 1,  3> NOSTALL;  // No Stall
    // 0b0..Transfers stall when the transmit FIFO is empty
    // 0b1..Transfers do not stall, allowing transmit FIFO underruns to occur
constexpr LPSPI1_Reg<&LPSPI_Layout::CFGR1, 1,  2> AUTOPCS;  // Automatic PCS
    // 0b0..Automatic PCS generation is disabled
    // 0b1..Automatic PCS generation is enabled
constexpr LPSPI1_Reg<&LPSPI_Layout::CFGR1, 1,  1> SAMPLE;   // Sample Point
    // 0b0..Input data is sampled on SCK edge
    // 0b1..Input data is sampled on delayed SCK edge
constexpr LPSPI1_Reg<&LPSPI_Layout::CFGR1, 1,  0> MASTER;   // Master Mode
    // 0b0..Slave mode
    // 0b1..Master mode
}  // namespace CFGR1

// Data Match 0
namespace DMR0 {
constexpr LPSPI1_Reg<&LPSPI_Layout::DMR0, 32, 0> MATCH0;  // Match 0 Value
}  // namespace DMR0

// Data Match 1
namespace DMR1 {
constexpr LPSPI1_Reg<&LPSPI_Layout::DMR1, 32, 0> MATCH1;  // Match 1 Value
}  // namespace DMR1

// Clock Configuration
namespace CCR {
constexpr LPSPI1_Reg<&LPSPI_Layout::CCR, 8, 24> SCKPCS;  // SCK-to-PCS Delay
constexpr LPSPI1_Reg<&LPSPI_Layout::CCR, 8, 16> PCSSCK;  // PCS-to-SCK Delay
constexpr LPSPI1_Reg<&LPSPI_Layout::CCR, 8,  8> DBT;     // Delay Between Transfers
constexpr LPSPI1_Reg<&LPSPI_Layout::CCR, 8,  0> SCKDIV;  // SCK Divider
}  // namespace CCR

// FIFO Control
namespace FCR {
constexpr LPSPI1_Reg<&LPSPI_Layout::FCR, 4, 16> RXWATER;  // Receive FIFO Watermark
constexpr LPSPI1_Reg<&LPSPI_Layout::FCR, 4,  0> TXWATER;  // Transmit FIFO Watermark
}  // namespace FCR

// FIFO Status
namespace FSR {
constexpr LPSPI1_Reg<&LPSPI_Layout::FSR, 5, 16> RXCOUNT;  // Receive FIFO Count
constexpr LPSPI1_Reg<&LPSPI_Layout::FSR, 5,  0> TXCOUNT;  // Transmit FIFO Count
}  // namespace FSR

// Transmit Command
namespace TCR {
constexpr LPSPI1_Reg<&LPSPI_Layout::TCR,  1, 31> CPOL;      // Clock Polarity
    // 0b0..The inactive state value of SCK is low
    // 0b1..The inactive state value of SCK is high
constexpr LPSPI1_Reg<&LPSPI_Layout::TCR,  1, 30> CPHA;      // Clock Phase
    // 0b0..Captured
    // 0b1..Changed
constexpr LPSPI1_Reg<&LPSPI_Layout::TCR,  3, 27> PRESCALE;  // Prescaler Value
    // 0b000..Divide by 1
    // 0b001..Divide by 2
    // 0b010..Divide by 4
    // 0b011..Divide by 8
    // 0b100..Divide by 16
    // 0b101..Divide by 32
    // 0b110..Divide by 64
    // 0b111..Divide by 128
constexpr LPSPI1_Reg<&LPSPI_Layout::TCR,  2, 24> PCS;       // Peripheral Chip Select
    // 0b00..Transfer using PCS[0]
    // 0b01..Transfer using PCS[1]
    // 0b10..Transfer using PCS[2]
    // 0b11..Transfer using PCS[3]
constexpr LPSPI1_Reg<&LPSPI_Layout::TCR,  1, 23> LSBF;      // LSB First
    // 0b0..Data is transferred MSB first
    // 0b1..Data is transferred LSB first
constexpr LPSPI1_Reg<&LPSPI_Layout::TCR,  1, 22> BYSW;      // Byte Swap
    // 0b0..Byte swap is disabled
    // 0b1..Byte swap is enabled
constexpr LPSPI1_Reg<&LPSPI_Layout::TCR,  1, 21> CONT;      // Continuous Transfer
    // 0b0..Continuous transfer is disabled
    // 0b1..Continuous transfer is enabled
constexpr LPSPI1_Reg<&LPSPI_Layout::TCR,  1, 20> CONTC;     // Continuing Command
    // 0b0..Command word for start of new transfer
    // 0b1..Command word for continuing transfer
constexpr LPSPI1_Reg<&LPSPI_Layout::TCR,  1, 19> RXMSK;     // Receive Data Mask
    // 0b0..Normal transfer
    // 0b1..Receive data is masked
constexpr LPSPI1_Reg<&LPSPI_Layout::TCR,  1, 18> TXMSK;     // Transmit Data Mask
    // 0b0..Normal transfer
    // 0b1..Mask transmit data
constexpr LPSPI1_Reg<&LPSPI_Layout::TCR,  2, 16> WIDTH;     // Transfer Width
    // 0b00..1 bit transfer
    // 0b01..2 bit transfer
    // 0b10..4 bit transfer
    // 0b11..Reserved
constexpr LPSPI1_Reg<&LPSPI_Layout::TCR, 12,  0> FRAMESZ;   // Frame Size
}  // namespace TCR

// Slave Transmit Data
namespace TDR {
constexpr LPSPI1_Reg<&LPSPI_Layout::TDR, 32, 0, 0x0, true> DATA;  // Transmit Data
}  // namespace TDR

// Receive Status
namespace RSR {
constexpr LPSPI1_Reg<&LPSPI_Layout::RSR, 1, 1> RXEMPTY;  // RX FIFO Empty
    // 0b0..RX FIFO is not empty
    // 0b1..RX FIFO is empty
constexpr LPSPI1_Reg<&LPSPI_Layout::RSR, 1, 0> SOF;      // Start Of Frame
    // 0b0..Subsequent data word received after PCS assertion
    // 0b1..First data word received after PCS assertion
}  // namespace RSR

// Receive Data
namespace RDR {
constexpr LPSPI1_Reg<&LPSPI_Layout::RDR, 32, 0> DATA;  // Receive Data
}  // namespace RDR

}  // namespace LPSPI1

namespace LPSPI2 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false>
using LPSPI2_Reg =
    regs::Reg32<kLPSPI2_base, LPSPI_Layout, Member, 0, Bits, Shift,
                AssignMask, WriteOnly>;

// Version ID
namespace VERID {
constexpr LPSPI2_Reg<&LPSPI_Layout::VERID,  8, 24> MAJOR;
constexpr LPSPI2_Reg<&LPSPI_Layout::VERID,  8, 16> MINOR;
constexpr LPSPI2_Reg<&LPSPI_Layout::VERID, 16,  0> FEATURE;
}  // namespace VERID

// Parameter
namespace PARAM {
constexpr LPSPI2_Reg<&LPSPI_Layout::PARAM, 8, 16> PCSNUM;
constexpr LPSPI2_Reg<&LPSPI_Layout::PARAM, 8,  8> RXFIFO;
constexpr LPSPI2_Reg<&LPSPI_Layout::PARAM, 8,  0> TXFIFO;
}  // namespace PARAM

// Control
namespace CR {
// TODO: Is this the correct way?
constexpr uint32_t kWO = 0x0000'0300;

constexpr LPSPI2_Reg<&LPSPI_Layout::CR, 1, 9, kWO, true> RRF;
constexpr LPSPI2_Reg<&LPSPI_Layout::CR, 1, 8, kWO, true> RTF;
constexpr LPSPI2_Reg<&LPSPI_Layout::CR, 1, 3, (uint32_t{0x1} << 3) | kWO> DBGEN;
constexpr LPSPI2_Reg<&LPSPI_Layout::CR, 1, 2, (uint32_t{0x1} << 2) | kWO> DOZEN;
constexpr LPSPI2_Reg<&LPSPI_Layout::CR, 1, 1, (uint32_t{0x1} << 1) | kWO> RST;
constexpr LPSPI2_Reg<&LPSPI_Layout::CR, 1, 0, (uint32_t{0x1} << 0) | kWO> MEN;
}  // namespace CR

// Status
namespace SR {
constexpr LPSPI2_Reg<regs::constify(&LPSPI_Layout::SR), 1, 24> MBF;
constexpr LPSPI2_Reg<&LPSPI_Layout::SR, 1, 13, 0x0> DMF;
constexpr LPSPI2_Reg<&LPSPI_Layout::SR, 1, 12, 0x0> REF;
constexpr LPSPI2_Reg<&LPSPI_Layout::SR, 1, 11, 0x0> TEF;
constexpr LPSPI2_Reg<&LPSPI_Layout::SR, 1, 10, 0x0> TCF;
constexpr LPSPI2_Reg<&LPSPI_Layout::SR, 1,  9, 0x0> FCF;
constexpr LPSPI2_Reg<&LPSPI_Layout::SR, 1,  8, 0x0> WCF;
constexpr LPSPI2_Reg<regs::constify(&LPSPI_Layout::SR), 1,  1> RDF;
constexpr LPSPI2_Reg<regs::constify(&LPSPI_Layout::SR), 1,  0> TDF;
}  // namespace SR

// Interrupt Enable
namespace IER {
constexpr LPSPI2_Reg<&LPSPI_Layout::IER, 1, 13> DMIE;
constexpr LPSPI2_Reg<&LPSPI_Layout::IER, 1, 12> REIE;
constexpr LPSPI2_Reg<&LPSPI_Layout::IER, 1, 11> TEIE;
constexpr LPSPI2_Reg<&LPSPI_Layout::IER, 1, 10> TCIE;
constexpr LPSPI2_Reg<&LPSPI_Layout::IER, 1,  9> FCIE;
constexpr LPSPI2_Reg<&LPSPI_Layout::IER, 1,  8> WCIE;
constexpr LPSPI2_Reg<&LPSPI_Layout::IER, 1,  1> RDIE;
constexpr LPSPI2_Reg<&LPSPI_Layout::IER, 1,  0> TDIE;
}  // namespace IER

// DMA Enable
namespace DER {
constexpr LPSPI2_Reg<&LPSPI_Layout::DER, 1, 1> RDDE;
constexpr LPSPI2_Reg<&LPSPI_Layout::DER, 1, 0> TDDE;
}  // namespace DER

// Configuration 0
namespace CFGR0 {
constexpr LPSPI2_Reg<&LPSPI_Layout::CFGR0, 1, 9> RDMO;
constexpr LPSPI2_Reg<&LPSPI_Layout::CFGR0, 1, 8> CIRFIFO;
constexpr LPSPI2_Reg<&LPSPI_Layout::CFGR0, 1, 2> HRSEL;
constexpr LPSPI2_Reg<&LPSPI_Layout::CFGR0, 1, 1> HRPOL;
constexpr LPSPI2_Reg<&LPSPI_Layout::CFGR0, 1, 0> HREN;
}  // namespace CFGR0

// Configuration 1
namespace CFGR1 {
constexpr LPSPI2_Reg<&LPSPI_Layout::CFGR1, 1, 27> PCSCFG;
constexpr LPSPI2_Reg<&LPSPI_Layout::CFGR1, 1, 26> OUTCFG;
constexpr LPSPI2_Reg<&LPSPI_Layout::CFGR1, 2, 24> PINCFG;
constexpr LPSPI2_Reg<&LPSPI_Layout::CFGR1, 3, 16> MATCFG;
constexpr LPSPI2_Reg<&LPSPI_Layout::CFGR1, 4,  8> PCSPOL;
constexpr LPSPI2_Reg<&LPSPI_Layout::CFGR1, 1,  3> NOSTALL;
constexpr LPSPI2_Reg<&LPSPI_Layout::CFGR1, 1,  2> AUTOPCS;
constexpr LPSPI2_Reg<&LPSPI_Layout::CFGR1, 1,  1> SAMPLE;
constexpr LPSPI2_Reg<&LPSPI_Layout::CFGR1, 1,  0> MASTER;
}  // namespace CFGR1

// Data Match 0
namespace DMR0 {
constexpr LPSPI2_Reg<&LPSPI_Layout::DMR0, 32, 0> MATCH0;
}  // namespace DMR0

// Data Match 1
namespace DMR1 {
constexpr LPSPI2_Reg<&LPSPI_Layout::DMR1, 32, 0> MATCH1;
}  // namespace DMR1

// Clock Configuration
namespace CCR {
constexpr LPSPI2_Reg<&LPSPI_Layout::CCR, 8, 24> SCKPCS;
constexpr LPSPI2_Reg<&LPSPI_Layout::CCR, 8, 16> PCSSCK;
constexpr LPSPI2_Reg<&LPSPI_Layout::CCR, 8,  8> DBT;
constexpr LPSPI2_Reg<&LPSPI_Layout::CCR, 8,  0> SCKDIV;
}  // namespace CCR

// FIFO Control
namespace FCR {
constexpr LPSPI2_Reg<&LPSPI_Layout::FCR, 4, 16> RXWATER;
constexpr LPSPI2_Reg<&LPSPI_Layout::FCR, 4,  0> TXWATER;
}  // namespace FCR

// FIFO Status
namespace FSR {
constexpr LPSPI2_Reg<&LPSPI_Layout::FSR, 5, 16> RXCOUNT;
constexpr LPSPI2_Reg<&LPSPI_Layout::FSR, 5,  0> TXCOUNT;
}  // namespace FSR

// Transmit Command
namespace TCR {
constexpr LPSPI2_Reg<&LPSPI_Layout::TCR,  1, 31> CPOL;
constexpr LPSPI2_Reg<&LPSPI_Layout::TCR,  1, 30> CPHA;
constexpr LPSPI2_Reg<&LPSPI_Layout::TCR,  3, 27> PRESCALE;
constexpr LPSPI2_Reg<&LPSPI_Layout::TCR,  2, 24> PCS;
constexpr LPSPI2_Reg<&LPSPI_Layout::TCR,  1, 23> LSBF;
constexpr LPSPI2_Reg<&LPSPI_Layout::TCR,  1, 22> BYSW;
constexpr LPSPI2_Reg<&LPSPI_Layout::TCR,  1, 21> CONT;
constexpr LPSPI2_Reg<&LPSPI_Layout::TCR,  1, 20> CONTC;
constexpr LPSPI2_Reg<&LPSPI_Layout::TCR,  1, 19> RXMSK;
constexpr LPSPI2_Reg<&LPSPI_Layout::TCR,  1, 18> TXMSK;
constexpr LPSPI2_Reg<&LPSPI_Layout::TCR,  2, 16> WIDTH;
constexpr LPSPI2_Reg<&LPSPI_Layout::TCR, 12,  0> FRAMESZ;
}  // namespace TCR

// Slave Transmit Data
namespace TDR {
constexpr LPSPI2_Reg<&LPSPI_Layout::TDR, 32, 0, 0x0, true> DATA;  // Transmit Data
}  // namespace TDR

// Receive Status
namespace RSR {
constexpr LPSPI2_Reg<&LPSPI_Layout::RSR, 1, 1> RXEMPTY;
constexpr LPSPI2_Reg<&LPSPI_Layout::RSR, 1, 0> SOF;
}  // namespace RSR

// Receive Data
namespace RDR {
constexpr LPSPI2_Reg<&LPSPI_Layout::RDR, 32, 0> DATA;
}  // namespace RDR

}  // namespace LPSPI2

namespace LPSPI3 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false>
using LPSPI3_Reg =
    regs::Reg32<kLPSPI3_base, LPSPI_Layout, Member, 0, Bits, Shift,
                AssignMask, WriteOnly>;

// Version ID
namespace VERID {
constexpr LPSPI3_Reg<&LPSPI_Layout::VERID,  8, 24> MAJOR;
constexpr LPSPI3_Reg<&LPSPI_Layout::VERID,  8, 16> MINOR;
constexpr LPSPI3_Reg<&LPSPI_Layout::VERID, 16,  0> FEATURE;
}  // namespace VERID

// Parameter
namespace PARAM {
constexpr LPSPI3_Reg<&LPSPI_Layout::PARAM, 8, 16> PCSNUM;
constexpr LPSPI3_Reg<&LPSPI_Layout::PARAM, 8,  8> RXFIFO;
constexpr LPSPI3_Reg<&LPSPI_Layout::PARAM, 8,  0> TXFIFO;
}  // namespace PARAM

// Control
namespace CR {
// TODO: Is this the correct way?
constexpr uint32_t kWO = 0x0000'0300;

constexpr LPSPI3_Reg<&LPSPI_Layout::CR, 1, 9, kWO, true> RRF;
constexpr LPSPI3_Reg<&LPSPI_Layout::CR, 1, 8, kWO, true> RTF;
constexpr LPSPI3_Reg<&LPSPI_Layout::CR, 1, 3, (uint32_t{0x1} << 3) | kWO> DBGEN;
constexpr LPSPI3_Reg<&LPSPI_Layout::CR, 1, 2, (uint32_t{0x1} << 2) | kWO> DOZEN;
constexpr LPSPI3_Reg<&LPSPI_Layout::CR, 1, 1, (uint32_t{0x1} << 1) | kWO> RST;
constexpr LPSPI3_Reg<&LPSPI_Layout::CR, 1, 0, (uint32_t{0x1} << 0) | kWO> MEN;
}  // namespace CR

// Status
namespace SR {
constexpr LPSPI3_Reg<regs::constify(&LPSPI_Layout::SR), 1, 24> MBF;
constexpr LPSPI3_Reg<&LPSPI_Layout::SR, 1, 13, 0x0> DMF;
constexpr LPSPI3_Reg<&LPSPI_Layout::SR, 1, 12, 0x0> REF;
constexpr LPSPI3_Reg<&LPSPI_Layout::SR, 1, 11, 0x0> TEF;
constexpr LPSPI3_Reg<&LPSPI_Layout::SR, 1, 10, 0x0> TCF;
constexpr LPSPI3_Reg<&LPSPI_Layout::SR, 1,  9, 0x0> FCF;
constexpr LPSPI3_Reg<&LPSPI_Layout::SR, 1,  8, 0x0> WCF;
constexpr LPSPI3_Reg<regs::constify(&LPSPI_Layout::SR), 1,  1> RDF;
constexpr LPSPI3_Reg<regs::constify(&LPSPI_Layout::SR), 1,  0> TDF;
}  // namespace SR

// Interrupt Enable
namespace IER {
constexpr LPSPI3_Reg<&LPSPI_Layout::IER, 1, 13> DMIE;
constexpr LPSPI3_Reg<&LPSPI_Layout::IER, 1, 12> REIE;
constexpr LPSPI3_Reg<&LPSPI_Layout::IER, 1, 11> TEIE;
constexpr LPSPI3_Reg<&LPSPI_Layout::IER, 1, 10> TCIE;
constexpr LPSPI3_Reg<&LPSPI_Layout::IER, 1,  9> FCIE;
constexpr LPSPI3_Reg<&LPSPI_Layout::IER, 1,  8> WCIE;
constexpr LPSPI3_Reg<&LPSPI_Layout::IER, 1,  1> RDIE;
constexpr LPSPI3_Reg<&LPSPI_Layout::IER, 1,  0> TDIE;
}  // namespace IER

// DMA Enable
namespace DER {
constexpr LPSPI3_Reg<&LPSPI_Layout::DER, 1, 1> RDDE;
constexpr LPSPI3_Reg<&LPSPI_Layout::DER, 1, 0> TDDE;
}  // namespace DER

// Configuration 0
namespace CFGR0 {
constexpr LPSPI3_Reg<&LPSPI_Layout::CFGR0, 1, 9> RDMO;
constexpr LPSPI3_Reg<&LPSPI_Layout::CFGR0, 1, 8> CIRFIFO;
constexpr LPSPI3_Reg<&LPSPI_Layout::CFGR0, 1, 2> HRSEL;
constexpr LPSPI3_Reg<&LPSPI_Layout::CFGR0, 1, 1> HRPOL;
constexpr LPSPI3_Reg<&LPSPI_Layout::CFGR0, 1, 0> HREN;
}  // namespace CFGR0

// Configuration 1
namespace CFGR1 {
constexpr LPSPI3_Reg<&LPSPI_Layout::CFGR1, 1, 27> PCSCFG;
constexpr LPSPI3_Reg<&LPSPI_Layout::CFGR1, 1, 26> OUTCFG;
constexpr LPSPI3_Reg<&LPSPI_Layout::CFGR1, 2, 24> PINCFG;
constexpr LPSPI3_Reg<&LPSPI_Layout::CFGR1, 3, 16> MATCFG;
constexpr LPSPI3_Reg<&LPSPI_Layout::CFGR1, 4,  8> PCSPOL;
constexpr LPSPI3_Reg<&LPSPI_Layout::CFGR1, 1,  3> NOSTALL;
constexpr LPSPI3_Reg<&LPSPI_Layout::CFGR1, 1,  2> AUTOPCS;
constexpr LPSPI3_Reg<&LPSPI_Layout::CFGR1, 1,  1> SAMPLE;
constexpr LPSPI3_Reg<&LPSPI_Layout::CFGR1, 1,  0> MASTER;
}  // namespace CFGR1

// Data Match 0
namespace DMR0 {
constexpr LPSPI3_Reg<&LPSPI_Layout::DMR0, 32, 0> MATCH0;
}  // namespace DMR0

// Data Match 1
namespace DMR1 {
constexpr LPSPI3_Reg<&LPSPI_Layout::DMR1, 32, 0> MATCH1;
}  // namespace DMR1

// Clock Configuration
namespace CCR {
constexpr LPSPI3_Reg<&LPSPI_Layout::CCR, 8, 24> SCKPCS;
constexpr LPSPI3_Reg<&LPSPI_Layout::CCR, 8, 16> PCSSCK;
constexpr LPSPI3_Reg<&LPSPI_Layout::CCR, 8,  8> DBT;
constexpr LPSPI3_Reg<&LPSPI_Layout::CCR, 8,  0> SCKDIV;
}  // namespace CCR

// FIFO Control
namespace FCR {
constexpr LPSPI3_Reg<&LPSPI_Layout::FCR, 4, 16> RXWATER;
constexpr LPSPI3_Reg<&LPSPI_Layout::FCR, 4,  0> TXWATER;
}  // namespace FCR

// FIFO Status
namespace FSR {
constexpr LPSPI3_Reg<&LPSPI_Layout::FSR, 5, 16> RXCOUNT;
constexpr LPSPI3_Reg<&LPSPI_Layout::FSR, 5,  0> TXCOUNT;
}  // namespace FSR

// Transmit Command
namespace TCR {
constexpr LPSPI3_Reg<&LPSPI_Layout::TCR,  1, 31> CPOL;
constexpr LPSPI3_Reg<&LPSPI_Layout::TCR,  1, 30> CPHA;
constexpr LPSPI3_Reg<&LPSPI_Layout::TCR,  3, 27> PRESCALE;
constexpr LPSPI3_Reg<&LPSPI_Layout::TCR,  2, 24> PCS;
constexpr LPSPI3_Reg<&LPSPI_Layout::TCR,  1, 23> LSBF;
constexpr LPSPI3_Reg<&LPSPI_Layout::TCR,  1, 22> BYSW;
constexpr LPSPI3_Reg<&LPSPI_Layout::TCR,  1, 21> CONT;
constexpr LPSPI3_Reg<&LPSPI_Layout::TCR,  1, 20> CONTC;
constexpr LPSPI3_Reg<&LPSPI_Layout::TCR,  1, 19> RXMSK;
constexpr LPSPI3_Reg<&LPSPI_Layout::TCR,  1, 18> TXMSK;
constexpr LPSPI3_Reg<&LPSPI_Layout::TCR,  2, 16> WIDTH;
constexpr LPSPI3_Reg<&LPSPI_Layout::TCR, 12,  0> FRAMESZ;
}  // namespace TCR

// Slave Transmit Data
namespace TDR {
constexpr LPSPI3_Reg<&LPSPI_Layout::TDR, 32, 0, 0x0, true> DATA;  // Transmit Data
}  // namespace TDR

// Receive Status
namespace RSR {
constexpr LPSPI3_Reg<&LPSPI_Layout::RSR, 1, 1> RXEMPTY;
constexpr LPSPI3_Reg<&LPSPI_Layout::RSR, 1, 0> SOF;
}  // namespace RSR

// Receive Data
namespace RDR {
constexpr LPSPI3_Reg<&LPSPI_Layout::RDR, 32, 0> DATA;
}  // namespace RDR

}  // namespace LPSPI3

namespace LPSPI4 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false>
using LPSPI4_Reg =
    regs::Reg32<kLPSPI4_base, LPSPI_Layout, Member, 0, Bits, Shift,
                AssignMask, WriteOnly>;

// Version ID
namespace VERID {
constexpr LPSPI4_Reg<&LPSPI_Layout::VERID,  8, 24> MAJOR;
constexpr LPSPI4_Reg<&LPSPI_Layout::VERID,  8, 16> MINOR;
constexpr LPSPI4_Reg<&LPSPI_Layout::VERID, 16,  0> FEATURE;
}  // namespace VERID

// Parameter
namespace PARAM {
constexpr LPSPI4_Reg<&LPSPI_Layout::PARAM, 8, 16> PCSNUM;
constexpr LPSPI4_Reg<&LPSPI_Layout::PARAM, 8,  8> RXFIFO;
constexpr LPSPI4_Reg<&LPSPI_Layout::PARAM, 8,  0> TXFIFO;
}  // namespace PARAM

// Control
namespace CR {
// TODO: Is this the correct way?
constexpr uint32_t kWO = 0x0000'0300;

constexpr LPSPI4_Reg<&LPSPI_Layout::CR, 1, 9, kWO, true> RRF;
constexpr LPSPI4_Reg<&LPSPI_Layout::CR, 1, 8, kWO, true> RTF;
constexpr LPSPI4_Reg<&LPSPI_Layout::CR, 1, 3, (uint32_t{0x1} << 3) | kWO> DBGEN;
constexpr LPSPI4_Reg<&LPSPI_Layout::CR, 1, 2, (uint32_t{0x1} << 2) | kWO> DOZEN;
constexpr LPSPI4_Reg<&LPSPI_Layout::CR, 1, 1, (uint32_t{0x1} << 1) | kWO> RST;
constexpr LPSPI4_Reg<&LPSPI_Layout::CR, 1, 0, (uint32_t{0x1} << 0) | kWO> MEN;
}  // namespace CR

// Status
namespace SR {
constexpr LPSPI4_Reg<regs::constify(&LPSPI_Layout::SR), 1, 24> MBF;
constexpr LPSPI4_Reg<&LPSPI_Layout::SR, 1, 13, 0x0> DMF;
constexpr LPSPI4_Reg<&LPSPI_Layout::SR, 1, 12, 0x0> REF;
constexpr LPSPI4_Reg<&LPSPI_Layout::SR, 1, 11, 0x0> TEF;
constexpr LPSPI4_Reg<&LPSPI_Layout::SR, 1, 10, 0x0> TCF;
constexpr LPSPI4_Reg<&LPSPI_Layout::SR, 1,  9, 0x0> FCF;
constexpr LPSPI4_Reg<&LPSPI_Layout::SR, 1,  8, 0x0> WCF;
constexpr LPSPI4_Reg<regs::constify(&LPSPI_Layout::SR), 1,  1> RDF;
constexpr LPSPI4_Reg<regs::constify(&LPSPI_Layout::SR), 1,  0> TDF;
}  // namespace SR

// Interrupt Enable
namespace IER {
constexpr LPSPI4_Reg<&LPSPI_Layout::IER, 1, 13> DMIE;
constexpr LPSPI4_Reg<&LPSPI_Layout::IER, 1, 12> REIE;
constexpr LPSPI4_Reg<&LPSPI_Layout::IER, 1, 11> TEIE;
constexpr LPSPI4_Reg<&LPSPI_Layout::IER, 1, 10> TCIE;
constexpr LPSPI4_Reg<&LPSPI_Layout::IER, 1,  9> FCIE;
constexpr LPSPI4_Reg<&LPSPI_Layout::IER, 1,  8> WCIE;
constexpr LPSPI4_Reg<&LPSPI_Layout::IER, 1,  1> RDIE;
constexpr LPSPI4_Reg<&LPSPI_Layout::IER, 1,  0> TDIE;
}  // namespace IER

// DMA Enable
namespace DER {
constexpr LPSPI4_Reg<&LPSPI_Layout::DER, 1, 1> RDDE;
constexpr LPSPI4_Reg<&LPSPI_Layout::DER, 1, 0> TDDE;
}  // namespace DER

// Configuration 0
namespace CFGR0 {
constexpr LPSPI4_Reg<&LPSPI_Layout::CFGR0, 1, 9> RDMO;
constexpr LPSPI4_Reg<&LPSPI_Layout::CFGR0, 1, 8> CIRFIFO;
constexpr LPSPI4_Reg<&LPSPI_Layout::CFGR0, 1, 2> HRSEL;
constexpr LPSPI4_Reg<&LPSPI_Layout::CFGR0, 1, 1> HRPOL;
constexpr LPSPI4_Reg<&LPSPI_Layout::CFGR0, 1, 0> HREN;
}  // namespace CFGR0

// Configuration 1
namespace CFGR1 {
constexpr LPSPI4_Reg<&LPSPI_Layout::CFGR1, 1, 27> PCSCFG;
constexpr LPSPI4_Reg<&LPSPI_Layout::CFGR1, 1, 26> OUTCFG;
constexpr LPSPI4_Reg<&LPSPI_Layout::CFGR1, 2, 24> PINCFG;
constexpr LPSPI4_Reg<&LPSPI_Layout::CFGR1, 3, 16> MATCFG;
constexpr LPSPI4_Reg<&LPSPI_Layout::CFGR1, 4,  8> PCSPOL;
constexpr LPSPI4_Reg<&LPSPI_Layout::CFGR1, 1,  3> NOSTALL;
constexpr LPSPI4_Reg<&LPSPI_Layout::CFGR1, 1,  2> AUTOPCS;
constexpr LPSPI4_Reg<&LPSPI_Layout::CFGR1, 1,  1> SAMPLE;
constexpr LPSPI4_Reg<&LPSPI_Layout::CFGR1, 1,  0> MASTER;
}  // namespace CFGR1

// Data Match 0
namespace DMR0 {
constexpr LPSPI4_Reg<&LPSPI_Layout::DMR0, 32, 0> MATCH0;
}  // namespace DMR0

// Data Match 1
namespace DMR1 {
constexpr LPSPI4_Reg<&LPSPI_Layout::DMR1, 32, 0> MATCH1;
}  // namespace DMR1

// Clock Configuration
namespace CCR {
constexpr LPSPI4_Reg<&LPSPI_Layout::CCR, 8, 24> SCKPCS;
constexpr LPSPI4_Reg<&LPSPI_Layout::CCR, 8, 16> PCSSCK;
constexpr LPSPI4_Reg<&LPSPI_Layout::CCR, 8,  8> DBT;
constexpr LPSPI4_Reg<&LPSPI_Layout::CCR, 8,  0> SCKDIV;
}  // namespace CCR

// FIFO Control
namespace FCR {
constexpr LPSPI4_Reg<&LPSPI_Layout::FCR, 4, 16> RXWATER;
constexpr LPSPI4_Reg<&LPSPI_Layout::FCR, 4,  0> TXWATER;
}  // namespace FCR

// FIFO Status
namespace FSR {
constexpr LPSPI4_Reg<&LPSPI_Layout::FSR, 5, 16> RXCOUNT;
constexpr LPSPI4_Reg<&LPSPI_Layout::FSR, 5,  0> TXCOUNT;
}  // namespace FSR

// Transmit Command
namespace TCR {
constexpr LPSPI4_Reg<&LPSPI_Layout::TCR,  1, 31> CPOL;
constexpr LPSPI4_Reg<&LPSPI_Layout::TCR,  1, 30> CPHA;
constexpr LPSPI4_Reg<&LPSPI_Layout::TCR,  3, 27> PRESCALE;
constexpr LPSPI4_Reg<&LPSPI_Layout::TCR,  2, 24> PCS;
constexpr LPSPI4_Reg<&LPSPI_Layout::TCR,  1, 23> LSBF;
constexpr LPSPI4_Reg<&LPSPI_Layout::TCR,  1, 22> BYSW;
constexpr LPSPI4_Reg<&LPSPI_Layout::TCR,  1, 21> CONT;
constexpr LPSPI4_Reg<&LPSPI_Layout::TCR,  1, 20> CONTC;
constexpr LPSPI4_Reg<&LPSPI_Layout::TCR,  1, 19> RXMSK;
constexpr LPSPI4_Reg<&LPSPI_Layout::TCR,  1, 18> TXMSK;
constexpr LPSPI4_Reg<&LPSPI_Layout::TCR,  2, 16> WIDTH;
constexpr LPSPI4_Reg<&LPSPI_Layout::TCR, 12,  0> FRAMESZ;
}  // namespace TCR

// Slave Transmit Data
namespace TDR {
constexpr LPSPI4_Reg<&LPSPI_Layout::TDR, 32, 0, 0x0, true> DATA;  // Transmit Data
}  // namespace TDR

// Receive Status
namespace RSR {
constexpr LPSPI4_Reg<&LPSPI_Layout::RSR, 1, 1> RXEMPTY;
constexpr LPSPI4_Reg<&LPSPI_Layout::RSR, 1, 0> SOF;
}  // namespace RSR

// Receive Data
namespace RDR {
constexpr LPSPI4_Reg<&LPSPI_Layout::RDR, 32, 0> DATA;
}  // namespace RDR

}  // namespace LPSPI4

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
