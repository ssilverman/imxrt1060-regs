// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// FLEXSPI.h defines all the FLEXSPI registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>
#include <type_traits>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

/** FLEXSPI - Size of Registers Arrays */
constexpr size_t kFLEXSPI_AHBRXBUFCR0_count = 4;
constexpr size_t kFLEXSPI_FLSHCR0_count     = 4;
constexpr size_t kFLEXSPI_FLSHCR1_count     = 4;
constexpr size_t kFLEXSPI_FLSHCR2_count     = 4;
constexpr size_t kFLEXSPI_DLLCR_count       = 2;
constexpr size_t kFLEXSPI_RFDR_count        = 32;
constexpr size_t kFLEXSPI_TFDR_count        = 32;
constexpr size_t kFLEXSPI_LUT_count         = 64;

// FLEXSPI layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_FLEXSPI.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct FLEXSPI_Layout {
  volatile uint32_t MCR0;                              /**< Module Control Register 0, offset: 0x0 */
  volatile uint32_t MCR1;                              /**< Module Control Register 1, offset: 0x4 */
  volatile uint32_t MCR2;                              /**< Module Control Register 2, offset: 0x8 */
  volatile uint32_t AHBCR;                             /**< AHB Bus Control Register, offset: 0xC */
  volatile uint32_t INTEN;                             /**< Interrupt Enable Register, offset: 0x10 */
  volatile uint32_t INTR;                              /**< Interrupt Register, offset: 0x14 */
  volatile uint32_t LUTKEY;                            /**< LUT Key Register, offset: 0x18 */
  volatile uint32_t LUTCR;                             /**< LUT Control Register, offset: 0x1C */
  volatile uint32_t AHBRXBUFCR0[kFLEXSPI_AHBRXBUFCR0_count];  /**< AHB RX Buffer 0 Control Register 0..AHB RX Buffer 3 Control Register 0, array offset: 0x20, array step: 0x4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[12];
  volatile uint32_t FLSHCR0[kFLEXSPI_FLSHCR0_count];   /**< Flash Control Register 0, array offset: 0x60, array step: 0x4 */
  volatile uint32_t FLSHCR1[kFLEXSPI_FLSHCR1_count];   /**< Flash Control Register 1, array offset: 0x70, array step: 0x4 */
  volatile uint32_t FLSHCR2[kFLEXSPI_FLSHCR2_count];   /**< Flash Control Register 2, array offset: 0x80, array step: 0x4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t FLSHCR4;                           /**< Flash Control Register 4, offset: 0x94 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[2];
  volatile uint32_t IPCR0;                             /**< IP Control Register 0, offset: 0xA0 */
  volatile uint32_t IPCR1;                             /**< IP Control Register 1, offset: 0xA4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[2];
  volatile uint32_t IPCMD;                             /**< IP Command Register, offset: 0xB0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t IPRXFCR;                           /**< IP RX FIFO Control Register, offset: 0xB8 */
  volatile uint32_t IPTXFCR;                           /**< IP TX FIFO Control Register, offset: 0xBC */
  volatile uint32_t DLLCR[kFLEXSPI_DLLCR_count];        /**< DLL Control Register 0, array offset: 0xC0, array step: 0x4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[6];
  const volatile uint32_t STS0;                        /**< Status Register 0, offset: 0xE0 */
  const volatile uint32_t STS1;                        /**< Status Register 1, offset: 0xE4 */
  const volatile uint32_t STS2;                        /**< Status Register 2, offset: 0xE8 */
  const volatile uint32_t AHBSPNDSTS;                  /**< AHB Suspend Status Register, offset: 0xEC */
  const volatile uint32_t IPRXFSTS;                    /**< IP RX FIFO Status Register, offset: 0xF0 */
  const volatile uint32_t IPTXFSTS;                    /**< IP TX FIFO Status Register, offset: 0xF4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[2];
  const volatile uint32_t RFDR[kFLEXSPI_RFDR_count];   /**< IP RX FIFO Data Register 0..IP RX FIFO Data Register 31, array offset: 0x100, array step: 0x4 */
  volatile uint32_t TFDR[kFLEXSPI_TFDR_count];         /**< IP TX FIFO Data Register 0..IP TX FIFO Data Register 31, array offset: 0x180, array step: 0x4 */
  volatile uint32_t LUT[kFLEXSPI_LUT_count];           /**< LUT 0..LUT 63, array offset: 0x200, array step: 0x4 */
};

constexpr size_t    kFLEXSPI_size  = 0x300;
constexpr uintptr_t kFLEXSPI_base  = 0x402A8000;
constexpr uintptr_t kFLEXSPI2_base = 0x402A4000;

namespace FLEXSPI {
constexpr regs::RegGroup<FLEXSPI_Layout, kFLEXSPI_size, kFLEXSPI_base> group;
}  // namespace FLEXSPI

namespace FLEXSPI2 {
constexpr regs::RegGroup<FLEXSPI_Layout, kFLEXSPI_size, kFLEXSPI2_base> group;
}  // namespace FLEXSPI2

namespace FLEXSPI {

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false, bool WriteOnly = false>
using FLEXSPI_Reg =
    regs::Reg32<kFLEXSPI_base, FLEXSPI_Layout, Member, 0, Bits, Shift,
                DirectAssign, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          bool DirectAssign = false, bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXSPI_AHBRXBUFCR0_count)>>
using AHBRXBUFCR0_Reg =
    regs::Reg32<kFLEXSPI_base, FLEXSPI_Layout, &FLEXSPI_Layout::AHBRXBUFCR0,
                Index, Bits, Shift, DirectAssign, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          bool DirectAssign = false, bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXSPI_FLSHCR0_count)>>
using FLSHCR0_Reg =
    regs::Reg32<kFLEXSPI_base, FLEXSPI_Layout, &FLEXSPI_Layout::FLSHCR0,
                Index, Bits, Shift, DirectAssign, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          bool DirectAssign = false, bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXSPI_FLSHCR1_count)>>
using FLSHCR1_Reg =
    regs::Reg32<kFLEXSPI_base, FLEXSPI_Layout, &FLEXSPI_Layout::FLSHCR1,
                Index, Bits, Shift, DirectAssign, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          bool DirectAssign = false, bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXSPI_FLSHCR2_count)>>
using FLSHCR2_Reg =
    regs::Reg32<kFLEXSPI_base, FLEXSPI_Layout, &FLEXSPI_Layout::FLSHCR2,
                Index, Bits, Shift, DirectAssign, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          bool DirectAssign = false, bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXSPI_DLLCR_count)>>
using DLLCR_Reg =
    regs::Reg32<kFLEXSPI_base, FLEXSPI_Layout, &FLEXSPI_Layout::DLLCR,
                Index, Bits, Shift, DirectAssign, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          bool DirectAssign = false, bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXSPI_RFDR_count)>>
using RFDR_Reg =
    regs::Reg32<kFLEXSPI_base, FLEXSPI_Layout, &FLEXSPI_Layout::RFDR,
                Index, Bits, Shift, DirectAssign, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          bool DirectAssign = false, bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXSPI_TFDR_count)>>
using TFDR_Reg =
    regs::Reg32<kFLEXSPI_base, FLEXSPI_Layout, &FLEXSPI_Layout::TFDR,
                Index, Bits, Shift, DirectAssign, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          bool DirectAssign = false, bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXSPI_LUT_count)>>
using LUT_Reg =
    regs::Reg32<kFLEXSPI_base, FLEXSPI_Layout, &FLEXSPI_Layout::LUT,
                Index, Bits, Shift, DirectAssign, WriteOnly>;

// Module Control Register 0
namespace MCR0 {
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::MCR0, 8, 24> AHBGRANTWAIT;  // Timeout wait cycle for AHB command grant.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::MCR0, 8, 16> IPGRANTWAIT;   // Time out wait cycle for IP command grant.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::MCR0, 1, 14> SCKFREERUNEN;  // This bit is used to force SCLK output free-running.
    // For FPGA applications, external device may use SCLK as
    //     reference clock to its internal PLL. If SCLK free-running is enabled, data sampling with loopback clock
    //     from SCLK pad is not supported (MCR0[RXCLKSRC]=2).
    // 0b0..Disable.
    // 0b1..Enable.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::MCR0, 1, 13> COMBINATIONEN;
    // This bit is to support Flash Octal mode access by combining Port A and B Data pins (A_DATA[3:0] and
    //     B_DATA[3:0]), when Port A and Port B are of 4 bit data width.
    // 0b0..Disable.
    // 0b1..Enable.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::MCR0, 1, 12> DOZEEN;        // Doze mode enable bit
    // 0b0..Doze mode support disabled. AHB clock and serial clock will not be gated off when there is doze mode
    //     request from system.
    // 0b1..Doze mode support enabled. AHB clock and serial clock will be gated off when there is doze mode request
    //     from system.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::MCR0, 1, 11> HSEN;          // Half Speed Serial Flash access Enable.
    // 0b0..Disable divide by 2 of serial flash clock for half speed commands.
    // 0b1..Enable divide by 2 of serial flash clock for half speed commands.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::MCR0, 3,  8> SERCLKDIV;     // The serial root clock could be divided inside FlexSPI .
    // Refer to "Clocks" chapter for more details on
    //     clocking.
    // 0b000..Divided by 1
    // 0b001..Divided by 2
    // 0b010..Divided by 3
    // 0b011..Divided by 4
    // 0b100..Divided by 5
    // 0b101..Divided by 6
    // 0b110..Divided by 7
    // 0b111..Divided by 8
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::MCR0, 1,  7> ATDFEN;        // Enable AHB bus Write Access to IP TX FIFO.
    // 0b0..IP TX FIFO should be written by IP Bus. AHB Bus write access to IP TX FIFO memory space will get bus
    //     error response.
    // 0b1..IP TX FIFO should be written by AHB Bus. IP Bus write access to IP TX FIFO memory space will be ignored
    //     but no bus error response.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::MCR0, 1,  6> ARDFEN;        // Enable AHB bus Read Access to IP RX FIFO.
    // 0b0..IP RX FIFO should be read by IP Bus. AHB Bus read access to IP RX FIFO memory space will get bus error
    //     response.
    // 0b1..IP RX FIFO should be read by AHB Bus. IP Bus read access to IP RX FIFO memory space will always return
    //     data zero but no bus error response.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::MCR0, 2,  4> RXCLKSRC;      // Sample Clock source selection for Flash Reading
    // 0b00..Dummy Read strobe generated by FlexSPI Controller and loopback internally.
    // 0b01..Dummy Read strobe generated by FlexSPI Controller and loopback from DQS pad.
    // 0b10..Reserved
    // 0b11..Flash provided Read strobe and input from DQS pad
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::MCR0, 1,  1> MDIS;          // Module Disable
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::MCR0, 1,  0> SWRESET;       // Software Reset
}  // namespace MCR0

// Module Control Register 1
namespace MCR1 {
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::MCR1, 16, 16> SEQWAIT;
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::MCR1, 16,  0> AHBBUSWAIT;
}  // namespace MCR1

// Module Control Register 2
namespace MCR2 {
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::MCR2, 8, 24> RESUMEWAIT;
    // Wait cycle (in AHB clock cycle) for idle state before suspended command sequence resumed.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::MCR2, 1, 19> SCKBDIFFOPT;
    // B_SCLK pad can be used as A_SCLK differential clock output (inverted clock to A_SCLK). In this case, port B
    //     flash access is not available. After changing the value of this field, MCR0[SWRESET] should be set.
    // 0b0..B_SCLK pad is used as port B SCLK clock output. Port B flash access is available.
    // 0b1..B_SCLK pad is used as port A SCLK inverted clock output (Differential clock to A_SCLK). Port B flash
    //     access is not available.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::MCR2, 1, 15> SAMEDEVICEEN;
    // All external devices are same devices (both in types and size) for A1/A2/B1/B2.
    // 0b0..In Individual mode, FLSHA1CRx/FLSHA2CRx/FLSHB1CRx/FLSHB2CRx register setting will be applied to Flash
    //     A1/A2/B1/B2 separately. In Parallel mode, FLSHA1CRx register setting will be applied to Flash A1 and B1,
    //     FLSHA2CRx register setting will be applied to Flash A2 and B2. FLSHB1CRx/FLSHB2CRx register settings will
    //     be ignored.
    // 0b1..FLSHA1CR0/FLSHA1CR1/FLSHA1CR2 register settings will be applied to Flash A1/A2/B1/B2.
    //     FLSHA2CRx/FLSHB1CRx/FLSHB2CRx will be ignored.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::MCR2, 1, 11> CLRAHBBUFOPT;
    // This bit determines whether AHB RX Buffer and AHB TX Buffer will be cleaned automatically when FlexSPI
    //     returns STOP mode ACK. Software should set this bit if AHB RX Buffer or AHB TX Buffer will be powered off
    //     in STOP mode. Otherwise AHB read access after exiting STOP mode may hit AHB RX Buffer or AHB TX Buffer
    //     but their data entries are invalid.
    // 0b0..AHB RX/TX Buffer will not be cleaned automatically when FlexSPI return Stop mode ACK.
    // 0b1..AHB RX/TX Buffer will be cleaned automatically when FlexSPI return Stop mode ACK.
}  // namespace MCR2

// AHB Bus Control Register
namespace AHBCR {
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::AHBCR, 2, 20> ALIGNMENT;    // Decides all AHB read/write boundary.
    // All access cross the boundary will be divided into smaller sub accesses.
    // 0b00..No limit
    // 0b01..1 KBytes
    // 0b10..512 Bytes
    // 0b11..256 Bytes
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::AHBCR, 1, 10> READSZALIGN;   // AHB Read Size Alignment
    // 0b0..AHB read size will be decided by other register setting like PREFETCH_EN
    // 0b1..AHB read size to up size to 8 bytes aligned, no prefetching
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::AHBCR, 1,  6> READADDROPT;   // AHB Read Address option bit.
    // This option bit is intend to remove AHB burst start address alignment
    //     limitation.
    // 0b0..There is AHB read burst start address alignment limitation when flash is accessed in parallel mode or
    //     flash is word-addressable.
    // 0b1..There is no AHB read burst start address alignment limitation. FlexSPI will fetch more data than AHB
    //     burst required to meet the alignment requirement.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::AHBCR, 1,  5> PREFETCHEN;    // AHB Read Prefetch Enable.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::AHBCR, 1,  4> BUFFERABLEEN;  // Enable AHB bus bufferable write access support.
    // This field affects the last beat of AHB write access, refer
    //     for more details about AHB bufferable write.
    // 0b0..Disabled. For all AHB write access (no matter bufferable or non-bufferable ), FlexSPI will return AHB
    //     Bus ready after all data is transmitted to External device and AHB command finished.
    // 0b1..Enabled. For AHB bufferable write access, FlexSPI will return AHB Bus ready when the AHB command is
    //     granted by arbitrator and will not wait for AHB command finished.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::AHBCR, 1,  3> CACHABLEEN;    // Enable AHB bus cachable read access support.
    // 0b0..Disabled. When there is AHB bus cachable read access, FlexSPI will not check whether it hit AHB TX
    //     Buffer.
    // 0b1..Enabled. When there is AHB bus cachable read access, FlexSPI will check whether it hit AHB TX Buffer
    //     first.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::AHBCR, 1,  2> CLRAHBTXBUF;  // Clear the status/pointers of AHB TX Buffer. Auto-cleared.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::AHBCR, 1,  1> CLRAHBRXBUF;  // Clear the status/pointers of AHB RX Buffer. Auto-cleared.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::AHBCR, 1,  0> APAREN;
    // Parallel mode enabled for AHB triggered Command (both read and write) .
    // 0b0..Flash will be accessed in Individual mode.
    // 0b1..Flash will be accessed in Parallel mode.
}  // namespace AHBCR

// Interrupt Enable Register
namespace INTEN {
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::INTEN, 1, 11> SEQTIMEOUTEN;     // Sequence execution timeout interrupt enable.
    // Refer Interrupts chapter for more details.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::INTEN, 1, 10> AHBBUSTIMEOUTEN;  // AHB Bus timeout interrupt.
    // Refer Interrupts chapter for more details.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::INTEN, 1,  9> SCKSTOPBYWREN;
    // SCLK is stopped during command sequence because Async TX FIFO empty interrupt enable.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::INTEN, 1,  8> SCKSTOPBYRDEN;
    // SCLK is stopped during command sequence because Async RX FIFO full interrupt enable.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::INTEN, 1,  6> IPTXWEEN;         // IP TX FIFO WaterMark empty interrupt enable.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::INTEN, 1,  5> IPRXWAEN;         // IP RX FIFO WaterMark available interrupt enable.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::INTEN, 1,  4> AHBCMDERREN;      // AHB triggered Command Sequences Error Detected interrupt enable.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::INTEN, 1,  3> IPCMDERREN;       // IP triggered Command Sequences Error Detected interrupt enable.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::INTEN, 1,  2> AHBCMDGEEN;       // AHB triggered Command Sequences Grant Timeout interrupt enable.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::INTEN, 1,  1> IPCMDGEEN;        // IP triggered Command Sequences Grant Timeout interrupt enable.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::INTEN, 1,  0> IPCMDDONEEN;      // IP triggered Command Sequences Execution finished interrupt enable.
}  // namespace INTEN

// Interrupt Register
namespace INTR {
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::INTR, 1, 11, true> SEQTIMEOUT;     // Sequence execution timeout interrupt.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::INTR, 1, 10, true> AHBBUSTIMEOUT;  // AHB Bus timeout interrupt.
    // Refer Interrupts chapter for more details.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::INTR, 1,  9, true> SCKSTOPBYWR;
    // SCLK is stopped during command sequence because Async TX FIFO empty interrupt.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::INTR, 1,  8, true> SCKSTOPBYRD;
    // SCLK is stopped during command sequence because Async RX FIFO full interrupt.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::INTR, 1,  6, true> IPTXWE;         // IP TX FIFO watermark empty interrupt.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::INTR, 1,  5, true> IPRXWA;         // IP RX FIFO watermark available interrupt.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::INTR, 1,  4, true> AHBCMDERR;      // AHB triggered Command Sequences Error Detected interrupt.
    // When an error detected for AHB command, this
    //     command will be ignored and not executed at all.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::INTR, 1,  3, true> IPCMDERR;       // IP triggered Command Sequences Error Detected interrupt.
    // When an error detected for IP command, this command
    //     will be ignored and not executed at all.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::INTR, 1,  2, true> AHBCMDGE;       // AHB triggered Command Sequences Grant Timeout interrupt.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::INTR, 1,  1, true> IPCMDGE;        // IP triggered Command Sequences Grant Timeout interrupt.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::INTR, 1,  0, true> IPCMDDONE;      // IP triggered Command Sequences Execution finished interrupt.
    // This interrupt is also generated when there is
    //     IPCMDGE or IPCMDERR interrupt generated.
}  // namespace INTR

// LUT Control Register
namespace LUTCR {
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::LUTCR, 1, 1> UNLOCK;  // Unlock LUT
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::LUTCR, 1, 0> LOCK;    // Lock LUT
}  // namespace LUTCR

// AHB RX Buffer 0 Control Register 0..AHB RX Buffer 3 Control Register 0
namespace AHBRXBUFCR0 {
template <size_t Index>
constexpr AHBRXBUFCR0_Reg<Index, 1, 31> PREFETCHEN;
    // AHB Read Prefetch Enable for current AHB RX Buffer corresponding Master.
template <size_t Index>
constexpr AHBRXBUFCR0_Reg<Index, 1, 30> REGIONEN;  // AHB RX Buffer address region funciton enable
template <size_t Index>
constexpr AHBRXBUFCR0_Reg<Index, 2, 24> PRIORITY;
    // This priority for AHB Master Read which this AHB RX Buffer is assigned. 7 is the highest priority, 0 the
    //     lowest.
template <size_t Index>
constexpr AHBRXBUFCR0_Reg<Index, 4, 16> MSTRID;
    // This AHB RX Buffer is assigned according to AHB Master with ID (MSTR_ID).
template <size_t Index>
constexpr AHBRXBUFCR0_Reg<Index, 8,  0> BUFSZ;  // AHB RX Buffer Size in 64 bits.
}  // namespace AHBRXBUFCR0

// Flash Control Register 0
namespace FLSHCR0 {
template <size_t Index>
constexpr FLSHCR0_Reg<Index, 23, 0> FLSHSZ;  // Flash Size in KByte.
}  // namespace FLSHCR0

// Flash Control Register 1
namespace FLSHCR1 {
template <size_t Index>
constexpr FLSHCR1_Reg<Index, 16, 16> CSINTERVAL;
    // This field is used to set the minimum interval between flash device Chip selection deassertion and flash
    //     device Chip selection assertion. If external flash has a limitation on the interval between command
    //     sequences, this field should be set accordingly. If there is no limitation, set this field with value
    //     0x0.
template <size_t Index>
constexpr FLSHCR1_Reg<Index,  1, 15> CSINTERVALUNIT;  // CS interval unit
    // 0b0..The CS interval unit is 1 serial clock cycle
    // 0b1..The CS interval unit is 256 serial clock cycle
template <size_t Index>
constexpr FLSHCR1_Reg<Index,  4, 11> CAS;             // Column Address Size.
template <size_t Index>
constexpr FLSHCR1_Reg<Index,  1, 10> WA;              // Word Addressable.
template <size_t Index>
constexpr FLSHCR1_Reg<Index,  5,  5> TCSH;            // Serial Flash CS Hold time.
template <size_t Index>
constexpr FLSHCR1_Reg<Index,  5,  0> TCSS;            // Serial Flash CS setup time.
}  // namespace FLSHCR1

// Flash Control Register 2
namespace FLSHCR2 {
template <size_t Index>
constexpr FLSHCR2_Reg<Index,  1, 31> CLRINSTRPTR;  // Clear the instruction pointer which is internally saved pointer by JMP_ON_CS.
    // Refer Programmable Sequence
    //     Engine for details.
template <size_t Index>
constexpr FLSHCR2_Reg<Index,  3, 28> AWRWAITUNIT;  // AWRWAIT unit
    // 0b000..The AWRWAIT unit is 2 ahb clock cycle
    // 0b001..The AWRWAIT unit is 8 ahb clock cycle
    // 0b010..The AWRWAIT unit is 32 ahb clock cycle
    // 0b011..The AWRWAIT unit is 128 ahb clock cycle
    // 0b100..The AWRWAIT unit is 512 ahb clock cycle
    // 0b101..The AWRWAIT unit is 2048 ahb clock cycle
    // 0b110..The AWRWAIT unit is 8192 ahb clock cycle
    // 0b111..The AWRWAIT unit is 32768 ahb clock cycle
template <size_t Index>
constexpr FLSHCR2_Reg<Index, 12, 16> AWRWAIT;
template <size_t Index>
constexpr FLSHCR2_Reg<Index,  3, 13> AWRSEQNUM;    // Sequence Number for AHB Write triggered Command.
template <size_t Index>
constexpr FLSHCR2_Reg<Index,  4,  8> AWRSEQID;     // Sequence Index for AHB Write triggered Command.
template <size_t Index>
constexpr FLSHCR2_Reg<Index,  3,  5> ARDSEQNUM;    // Sequence Number for AHB Read triggered Command in LUT.
template <size_t Index>
constexpr FLSHCR2_Reg<Index,  4,  0> ARDSEQID;     // Sequence Index for AHB Read triggered Command in LUT.
}  // namespace FLSHCR2

// Flash Control Register 4
namespace FLSHCR4 {
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::FLSHCR4, 1, 11> PAR_ADDR_ADJ_DIS;  // Disable the address shift logic for lower density of 16 bit PSRAM.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::FLSHCR4, 2,  9> PAR_WM;
    // Enable APMEM 16 bit write mask function, bit 9 for A1-B1 pair, bit 10 for A2-B2 pair.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::FLSHCR4, 1,  3> WMENB;             // Write mask enable bit for flash device on port B.
    // When write mask function is needed for memory device on
    //     port B, this bit must be set.
    // 0b0..Write mask is disabled, DQS(RWDS) pin will be un-driven when writing to external device.
    // 0b1..Write mask is enabled, DQS(RWDS) pin will be driven by FlexSPI as write mask output when writing to
    //     external device.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::FLSHCR4, 1,  2> WMENA;             // Write mask enable bit for flash device on port A.
    // When write mask function is needed for memory device on
    //     port A, this bit must be set.
    // 0b0..Write mask is disabled, DQS(RWDS) pin will be un-driven when writing to external device.
    // 0b1..Write mask is enabled, DQS(RWDS) pin will be driven by FlexSPI as write mask output when writing to
    //     external device.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::FLSHCR4, 1,  0> WMOPT1;            // Write mask option bit 1.
    // This option bit could be used to remove AHB write burst start address alignment
    //     limitation.
    // 0b0..DQS pin will be used as Write Mask when writing to external device. There is no limitation on AHB write
    //     burst start address alignment when flash is accessed in individual mode.
    // 0b1..DQS pin will not be used as Write Mask when writing to external device. There is limitation on AHB write
    //     burst start address alignment when flash is accessed in individual mode.
}  // namespace FLSHCR4

// IP Control Register 1
namespace IPCR1 {
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::IPCR1,  1, 31> IPAREN;   // Parallel mode Enabled for IP command.
    // 0b0..Flash will be accessed in Individual mode.
    // 0b1..Flash will be accessed in Parallel mode.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::IPCR1,  3, 24> ISEQNUM;  // Sequence Number for IP command: ISEQNUM+1.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::IPCR1,  4, 16> ISEQID;   // Sequence Index in LUT for IP command.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::IPCR1, 16,  0> IDATSZ;   // Flash Read/Program Data Size (in Bytes) for IP command.
}  // namespace IPCR1

// IP Command Register
namespace IPCMD {
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::IPCMD, 1, 0> TRG;  // Setting this bit will trigger an IP Command.
}  // namespace IPCMD

// IP RX FIFO Control Register
namespace IPRXFCR {
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::IPRXFCR, 4, 2> RXWMRK;  // Watermark level is (RXWMRK+1)*64 Bits.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::IPRXFCR, 1, 1> RXDMAEN;  // IP RX FIFO reading by DMA enabled.
    // 0b0..IP RX FIFO would be read by processor.
    // 0b1..IP RX FIFO would be read by DMA.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::IPRXFCR, 1, 0> CLRIPRXF;  // Clear all valid data entries in IP RX FIFO.
}  // namespace IPRXFCR

// IP TX FIFO Control Register
namespace IPTXFCR {
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::IPTXFCR, 4, 2> TXWMRK;    // Watermark level is (TXWMRK+1)*64 Bits.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::IPTXFCR, 1, 1> TXDMAEN;   // IP TX FIFO filling by DMA enabled.
    // 0b0..IP TX FIFO would be filled by processor.
    // 0b1..IP TX FIFO would be filled by DMA.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::IPTXFCR, 1, 0> CLRIPTXF;  // Clear all valid data entries in IP TX FIFO.
}  // namespace IPTXFCR

// DLL Control Register 0
namespace DLLCR {
template <size_t Index>
constexpr DLLCR_Reg<Index, 2, 15> REFPHASEGAP;  // Reference clock delay line phase adjust gap.
template <size_t Index>
constexpr DLLCR_Reg<Index, 6,  9> OVRDVAL;      // Slave clock delay line delay cell number selection override value.
template <size_t Index>
constexpr DLLCR_Reg<Index, 1,  8> OVRDEN;       // Slave clock delay line delay cell number selection override enable.
template <size_t Index>
constexpr DLLCR_Reg<Index, 4,  3> SLVDLYTARGET;
    // The delay target for slave delay line is: ((SLVDLYTARGET+1) * 1/32 * clock cycle of reference clock (serial
    //     root clock). If serial root clock is >= 100 MHz, DLLEN set to 0x1, OVRDEN set to =0x0, then SLVDLYTARGET
    //     setting of 0xF is recommended.
template <size_t Index>
constexpr DLLCR_Reg<Index, 1,  1> DLLRESET;     // Software could force a reset on DLL by setting this field to 0x1.
    // This will cause the DLL to lose lock and
    //     re-calibrate to detect an ref_clock half period phase shift. The reset action is edge triggered, so
    //     software need to clear this bit after set this bit (no delay limitation).
template <size_t Index>
constexpr DLLCR_Reg<Index, 1,  0> DLLEN;        // DLL calibration enable.
}  // namespace DLLCR

// Status Register 0
namespace STS0 {
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::STS0, 2, 2> ARBCMDSRC;
    // This status field indicates the trigger source of current command sequence granted by arbitrator. This field
    //     value is meaningless when ARB_CTL is not busy (STS0[ARBIDLE]=0x1).
    // 0b00..Triggered by AHB read command (triggered by AHB read).
    // 0b01..Triggered by AHB write command (triggered by AHB Write).
    // 0b10..Triggered by IP command (triggered by setting register bit IPCMD.TRG).
    // 0b11..Triggered by suspended command (resumed).
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::STS0, 1, 1> ARBIDLE;
    // This status bit indicates the state machine in ARB_CTL is busy and there is command sequence granted by
    //     arbitrator and not finished yet on FlexSPI interface. When ARB_CTL state (ARBIDLE=0x1) is idle, there
    //     will be no transaction on FlexSPI interface also (SEQIDLE=0x1). So this bit should be polled to wait for
    //     FlexSPI controller become idle instead of SEQIDLE.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::STS0, 1, 0> SEQIDLE;
    // This status bit indicates the state machine in SEQ_CTL is idle and there is command sequence executing on
    //     FlexSPI interface.
}  // namespace STS0

// Status Register 1
namespace STS1 {
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::STS1, 4, 24> IPCMDERRCODE;   // Indicates the Error Code when IP command Error detected.
    // This field will be cleared when INTR[IPCMDERR] is
    //     write-1-clear(w1c).
    // 0b0000..No error.
    // 0b0010..IP command with JMP_ON_CS instruction used in the sequence.
    // 0b0011..There is unknown instruction opcode in the sequence.
    // 0b0100..Instruction DUMMY_SDR/DUMMY_RWDS_SDR used in DDR sequence.
    // 0b0101..Instruction DUMMY_DDR/DUMMY_RWDS_DDR used in SDR sequence.
    // 0b0110..Flash access start address exceed the whole flash address range (A1/A2/B1/B2).
    // 0b1110..Sequence execution timeout.
    // 0b1111..Flash boundary crossed.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::STS1, 4, 16> IPCMDERRID;     // Indicates the sequence Index when IP command error detected.
    // This field will be cleared when INTR[IPCMDERR]
    //     is write-1-clear(w1c).
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::STS1, 4,  8> AHBCMDERRCODE;  // Indicates the Error Code when AHB command Error detected.
    // This field will be cleared when INTR[AHBCMDERR] is
    //     write-1-clear(w1c).
    // 0b0000..No error.
    // 0b0010..AHB Write command with JMP_ON_CS instruction used in the sequence.
    // 0b0011..There is unknown instruction opcode in the sequence.
    // 0b0100..Instruction DUMMY_SDR/DUMMY_RWDS_SDR used in DDR sequence.
    // 0b0101..Instruction DUMMY_DDR/DUMMY_RWDS_DDR used in SDR sequence.
    // 0b1110..Sequence execution timeout.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::STS1, 4,  0> AHBCMDERRID;    // Indicates the sequence index when an AHB command error is detected.
    // This field will be cleared when
    //     INTR[AHBCMDERR] is write-1-clear(w1c).
}  // namespace STS1

// Status Register 2
namespace STS2 {
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::STS2, 6, 24> BREFSEL;   // Flash B sample clock reference delay line delay cell number selection.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::STS2, 6, 18> BSLVSEL;   // Flash B sample clock slave delay line delay cell number selection.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::STS2, 1, 17> BREFLOCK;  // Flash B sample clock reference delay line locked.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::STS2, 1, 16> BSLVLOCK;  // Flash B sample clock slave delay line locked.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::STS2, 6,  8> AREFSEL;   // Flash A sample clock reference delay line delay cell number selection.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::STS2, 6,  2> ASLVSEL;   // Flash A sample clock slave delay line delay cell number selection .
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::STS2, 1,  1> AREFLOCK;  // Flash A sample clock reference delay line locked.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::STS2, 1,  0> ASLVLOCK;  // Flash A sample clock slave delay line locked.
}  // namespace STS2

// AHB Suspend Status Register
namespace AHBSPNDSTS {
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::AHBSPNDSTS, 16, 16> DATLFT;  // Left Data size for suspended command sequence (in byte).
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::AHBSPNDSTS,  3,  1> BUFID;   // AHB RX BUF ID for suspended command sequence.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::AHBSPNDSTS,  1,  0> ACTIVE;  // Indicates if an AHB read prefetch command sequence has been suspended.
}  // namespace AHBSPNDSTS

// IP RX FIFO Status Register
namespace IPRXFSTS {
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::IPRXFSTS, 16, 16> RDCNTR;  // Total Read Data Counter: RDCNTR * 64 Bits.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::IPRXFSTS,  8,  0> FILL;    // Fill level of IP RX FIFO.
}  // namespace IPRXFSTS

// IP TX FIFO Status Register
namespace IPTXFSTS {
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::IPTXFSTS, 16, 16> WRCNTR;  // Total Write Data Counter: WRCNTR * 64 Bits.
constexpr FLEXSPI_Reg<&FLEXSPI_Layout::IPTXFSTS,  8,  0> FILL;    // Fill level of IP TX FIFO.
}  // namespace IPTXFSTS

// LUT 0..LUT 63
namespace LUT {
template <size_t Index>
constexpr LUT_Reg<Index, 6, 26> OPCODE1;    // OPCODE1
template <size_t Index>
constexpr LUT_Reg<Index, 2, 24> NUM_PADS1;  // NUM_PADS1
template <size_t Index>
constexpr LUT_Reg<Index, 8, 16> OPERAND1;   // OPERAND1
template <size_t Index>
constexpr LUT_Reg<Index, 6, 10> OPCODE0;    // OPCODE
template <size_t Index>
constexpr LUT_Reg<Index, 2,  8> NUM_PADS0;  // NUM_PADS0
template <size_t Index>
constexpr LUT_Reg<Index, 8,  0> OPERAND0;   // OPERAND0
}  // namespace LUT

}  // namespace FLEXSPI

namespace FLEXSPI2 {

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false, bool WriteOnly = false>
using FLEXSPI2_Reg =
    regs::Reg32<kFLEXSPI2_base, FLEXSPI_Layout, Member, 0, Bits, Shift,
                DirectAssign, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          bool DirectAssign = false, bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXSPI_AHBRXBUFCR0_count)>>
using AHBRXBUFCR0_Reg =
    regs::Reg32<kFLEXSPI2_base, FLEXSPI_Layout, &FLEXSPI_Layout::AHBRXBUFCR0,
                Index, Bits, Shift, DirectAssign, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          bool DirectAssign = false, bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXSPI_FLSHCR0_count)>>
using FLSHCR0_Reg =
    regs::Reg32<kFLEXSPI2_base, FLEXSPI_Layout, &FLEXSPI_Layout::FLSHCR0,
                Index, Bits, Shift, DirectAssign, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          bool DirectAssign = false, bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXSPI_FLSHCR1_count)>>
using FLSHCR1_Reg =
    regs::Reg32<kFLEXSPI2_base, FLEXSPI_Layout, &FLEXSPI_Layout::FLSHCR1,
                Index, Bits, Shift, DirectAssign, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          bool DirectAssign = false, bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXSPI_FLSHCR2_count)>>
using FLSHCR2_Reg =
    regs::Reg32<kFLEXSPI2_base, FLEXSPI_Layout, &FLEXSPI_Layout::FLSHCR2,
                Index, Bits, Shift, DirectAssign, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          bool DirectAssign = false, bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXSPI_DLLCR_count)>>
using DLLCR_Reg =
    regs::Reg32<kFLEXSPI2_base, FLEXSPI_Layout, &FLEXSPI_Layout::DLLCR,
                Index, Bits, Shift, DirectAssign, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          bool DirectAssign = false, bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXSPI_RFDR_count)>>
using RFDR_Reg =
    regs::Reg32<kFLEXSPI2_base, FLEXSPI_Layout, &FLEXSPI_Layout::RFDR,
                Index, Bits, Shift, DirectAssign, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          bool DirectAssign = false, bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXSPI_TFDR_count)>>
using TFDR_Reg =
    regs::Reg32<kFLEXSPI2_base, FLEXSPI_Layout, &FLEXSPI_Layout::TFDR,
                Index, Bits, Shift, DirectAssign, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          bool DirectAssign = false, bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kFLEXSPI_LUT_count)>>
using LUT_Reg =
    regs::Reg32<kFLEXSPI2_base, FLEXSPI_Layout, &FLEXSPI_Layout::LUT,
                Index, Bits, Shift, DirectAssign, WriteOnly>;

// Module Control Register 0
namespace MCR0 {
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::MCR0, 8, 24> AHBGRANTWAIT;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::MCR0, 8, 16> IPGRANTWAIT;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::MCR0, 1, 14> SCKFREERUNEN;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::MCR0, 1, 13> COMBINATIONEN;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::MCR0, 1, 12> DOZEEN;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::MCR0, 1, 11> HSEN;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::MCR0, 3,  8> SERCLKDIV;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::MCR0, 1,  7> ATDFEN;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::MCR0, 1,  6> ARDFEN;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::MCR0, 2,  4> RXCLKSRC;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::MCR0, 1,  1> MDIS;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::MCR0, 1,  0> SWRESET;
}  // namespace MCR0

// Module Control Register 1
namespace MCR1 {
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::MCR1, 16, 16> SEQWAIT;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::MCR1, 16,  0> AHBBUSWAIT;
}  // namespace MCR1

// Module Control Register 2
namespace MCR2 {
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::MCR2, 8, 24> RESUMEWAIT;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::MCR2, 1, 19> SCKBDIFFOPT;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::MCR2, 1, 15> SAMEDEVICEEN;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::MCR2, 1, 11> CLRAHBBUFOPT;
}  // namespace MCR2

// AHB Bus Control Register
namespace AHBCR {
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::AHBCR, 2, 20> ALIGNMENT;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::AHBCR, 1, 10> READSZALIGN;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::AHBCR, 1,  6> READADDROPT;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::AHBCR, 1,  5> PREFETCHEN;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::AHBCR, 1,  4> BUFFERABLEEN;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::AHBCR, 1,  3> CACHABLEEN;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::AHBCR, 1,  2> CLRAHBTXBUF;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::AHBCR, 1,  1> CLRAHBRXBUF;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::AHBCR, 1,  0> APAREN;
}  // namespace AHBCR

// Interrupt Enable Register
namespace INTEN {
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::INTEN, 1, 11> SEQTIMEOUTEN;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::INTEN, 1, 10> AHBBUSTIMEOUTEN;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::INTEN, 1,  9> SCKSTOPBYWREN;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::INTEN, 1,  8> SCKSTOPBYRDEN;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::INTEN, 1,  6> IPTXWEEN;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::INTEN, 1,  5> IPRXWAEN;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::INTEN, 1,  4> AHBCMDERREN;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::INTEN, 1,  3> IPCMDERREN;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::INTEN, 1,  2> AHBCMDGEEN;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::INTEN, 1,  1> IPCMDGEEN;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::INTEN, 1,  0> IPCMDDONEEN;
}  // namespace INTEN

// Interrupt Register
namespace INTR {
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::INTR, 1, 11, true> SEQTIMEOUT;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::INTR, 1, 10, true> AHBBUSTIMEOUT;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::INTR, 1,  9, true> SCKSTOPBYWR;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::INTR, 1,  8, true> SCKSTOPBYRD;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::INTR, 1,  6, true> IPTXWE;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::INTR, 1,  5, true> IPRXWA;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::INTR, 1,  4, true> AHBCMDERR;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::INTR, 1,  3, true> IPCMDERR;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::INTR, 1,  2, true> AHBCMDGE;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::INTR, 1,  1, true> IPCMDGE;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::INTR, 1,  0, true> IPCMDDONE;
}  // namespace INTR

// LUT Control Register
namespace LUTCR {
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::LUTCR, 1,  1> UNLOCK;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::LUTCR, 1,  0> LOCK;
}  // namespace LUTCR

// AHB RX Buffer 0 Control Register 0..AHB RX Buffer 3 Control Register 0
namespace AHBRXBUFCR0 {
template <size_t Index>
constexpr AHBRXBUFCR0_Reg<Index, 1, 31> PREFETCHEN;
template <size_t Index>
constexpr AHBRXBUFCR0_Reg<Index, 1, 30> REGIONEN;
template <size_t Index>
constexpr AHBRXBUFCR0_Reg<Index, 2, 24> PRIORITY;
template <size_t Index>
constexpr AHBRXBUFCR0_Reg<Index, 4, 16> MSTRID;
template <size_t Index>
constexpr AHBRXBUFCR0_Reg<Index, 8,  0> BUFSZ;
}  // namespace AHBRXBUFCR0

// Flash Control Register 0
namespace FLSHCR0 {
template <size_t Index>
constexpr FLSHCR0_Reg<Index, 23,  0> FLSHSZ;
}  // namespace FLSHCR0

// Flash Control Register 1
namespace FLSHCR1 {
template <size_t Index>
constexpr FLSHCR1_Reg<Index, 16, 16> CSINTERVAL;
template <size_t Index>
constexpr FLSHCR1_Reg<Index, 1, 15> CSINTERVALUNIT;
template <size_t Index>
constexpr FLSHCR1_Reg<Index, 4, 11> CAS;
template <size_t Index>
constexpr FLSHCR1_Reg<Index, 1, 10> WA;
template <size_t Index>
constexpr FLSHCR1_Reg<Index, 5,  5> TCSH;
template <size_t Index>
constexpr FLSHCR1_Reg<Index, 5,  0> TCSS;
}  // namespace FLSHCR1

// Flash Control Register 2
namespace FLSHCR2 {
template <size_t Index>
constexpr FLSHCR2_Reg<Index, 1, 31> CLRINSTRPTR;
template <size_t Index>
constexpr FLSHCR2_Reg<Index, 3, 28> AWRWAITUNIT;
template <size_t Index>
constexpr FLSHCR2_Reg<Index, 12, 16> AWRWAIT;
template <size_t Index>
constexpr FLSHCR2_Reg<Index, 3, 13> AWRSEQNUM;
template <size_t Index>
constexpr FLSHCR2_Reg<Index, 4,  8> AWRSEQID;
template <size_t Index>
constexpr FLSHCR2_Reg<Index, 3,  5> ARDSEQNUM;
template <size_t Index>
constexpr FLSHCR2_Reg<Index, 4,  0> ARDSEQID;
}  // namespace FLSHCR2

// Flash Control Register 4
namespace FLSHCR4 {
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::FLSHCR4, 1, 11> PAR_ADDR_ADJ_DIS;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::FLSHCR4, 2,  9> PAR_WM;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::FLSHCR4, 1,  3> WMENB;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::FLSHCR4, 1,  2> WMENA;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::FLSHCR4, 1,  0> WMOPT1;
}  // namespace FLSHCR4

// IP Control Register 1
namespace IPCR1 {
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::IPCR1, 1, 31> IPAREN;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::IPCR1, 3, 24> ISEQNUM;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::IPCR1, 4, 16> ISEQID;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::IPCR1, 16,  0> IDATSZ;
    // Flash Read/Program Data Size (in Bytes) for IP command.
}  // namespace IPCR1

// IP Command Register
namespace IPCMD {
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::IPCMD, 1,  0> TRG;
}  // namespace IPCMD

// IP RX FIFO Control Register
namespace IPRXFCR {
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::IPRXFCR, 4,  2> RXWMRK;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::IPRXFCR, 1,  1> RXDMAEN;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::IPRXFCR, 1,  0> CLRIPRXF;
}  // namespace IPRXFCR

// IP TX FIFO Control Register
namespace IPTXFCR {
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::IPTXFCR, 4,  2> TXWMRK;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::IPTXFCR, 1,  1> TXDMAEN;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::IPTXFCR, 1,  0> CLRIPTXF;
}  // namespace IPTXFCR

// DLL Control Register 0
namespace DLLCR {
template <size_t Index>
constexpr DLLCR_Reg<Index, 2, 15> REFPHASEGAP;
template <size_t Index>
constexpr DLLCR_Reg<Index, 6,  9> OVRDVAL;
template <size_t Index>
constexpr DLLCR_Reg<Index, 1,  8> OVRDEN;
template <size_t Index>
constexpr DLLCR_Reg<Index, 4,  3> SLVDLYTARGET;
template <size_t Index>
constexpr DLLCR_Reg<Index, 1,  1> DLLRESET;
template <size_t Index>
constexpr DLLCR_Reg<Index, 1,  0> DLLEN;
}  // namespace DLLCR

// Status Register 0
namespace STS0 {
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::STS0, 2,  2> ARBCMDSRC;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::STS0, 1,  1> ARBIDLE;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::STS0, 1,  0> SEQIDLE;
}  // namespace STS0

// Status Register 1
namespace STS1 {
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::STS1, 4, 24> IPCMDERRCODE;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::STS1, 4, 16> IPCMDERRID;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::STS1, 4,  8> AHBCMDERRCODE;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::STS1, 4,  0> AHBCMDERRID;
}  // namespace STS1

// Status Register 2
namespace STS2 {
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::STS2, 6, 24> BREFSEL;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::STS2, 6, 18> BSLVSEL;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::STS2, 1, 17> BREFLOCK;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::STS2, 1, 16> BSLVLOCK;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::STS2, 6,  8> AREFSEL;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::STS2, 6,  2> ASLVSEL;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::STS2, 1,  1> AREFLOCK;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::STS2, 1,  0> ASLVLOCK;
}  // namespace STS2

// AHB Suspend Status Register
namespace AHBSPNDSTS {
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::AHBSPNDSTS, 16, 16> DATLFT;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::AHBSPNDSTS, 3,  1> BUFID;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::AHBSPNDSTS, 1,  0> ACTIVE;
}  // namespace AHBSPNDSTS

// IP RX FIFO Status Register
namespace IPRXFSTS {
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::IPRXFSTS, 16, 16> RDCNTR;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::IPRXFSTS, 8,  0> FILL;
}  // namespace IPRXFSTS

// IP TX FIFO Status Register
namespace IPTXFSTS {
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::IPTXFSTS, 16, 16> WRCNTR;
constexpr FLEXSPI2_Reg<&FLEXSPI_Layout::IPTXFSTS, 8,  0> FILL;
}  // namespace IPTXFSTS

// LUT 0..LUT 63
namespace LUT {
template <size_t Index>
constexpr LUT_Reg<Index, 6, 26> OPCODE1;
template <size_t Index>
constexpr LUT_Reg<Index, 2, 24> NUM_PADS1;
template <size_t Index>
constexpr LUT_Reg<Index, 8, 16> OPERAND1;
template <size_t Index>
constexpr LUT_Reg<Index, 6, 10> OPCODE0;
template <size_t Index>
constexpr LUT_Reg<Index, 2,  8> NUM_PADS0;
template <size_t Index>
constexpr LUT_Reg<Index, 8,  0> OPERAND0;
}  // namespace LUT

}  // namespace FLEXSPI2

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
