// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// I2S.h defines all the I2S registers.
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
constexpr size_t kI2S_TDR_count = 4;
constexpr size_t kI2S_TFR_count = 4;
constexpr size_t kI2S_RDR_count = 4;
constexpr size_t kI2S_RFR_count = 4;

// Valid data lines by instance
constexpr size_t kI2S1_DATALINE_count = 4;
constexpr size_t kI2S2_DATALINE_count = 1;
constexpr size_t kI2S3_DATALINE_count = 1;

// Structure type to access the Synchronous Audio Interface (I2S/SAI) registers.
//
// Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_I2S.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct I2S_Layout {
  const volatile uint32_t VERID;                            /**< Version ID, offset: 0x0 */
  const volatile uint32_t PARAM;                            /**< Parameter, offset: 0x4 */
  volatile uint32_t TCSR;                                   /**< Transmit Control, offset: 0x8 */
  volatile uint32_t TCR1;                                   /**< Transmit Configuration 1, offset: 0xC */
  volatile uint32_t TCR2;                                   /**< Transmit Configuration 2, offset: 0x10 */
  volatile uint32_t TCR3;                                   /**< Transmit Configuration 3, offset: 0x14 */
  volatile uint32_t TCR4;                                   /**< Transmit Configuration 4, offset: 0x18 */
  volatile uint32_t TCR5;                                   /**< Transmit Configuration 5, offset: 0x1C */
  volatile uint32_t TDR[kI2S_TDR_count];                    /**< Transmit Data, array offset: 0x20, array step: 0x4, irregular array, not all indices are valid */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[4];
  const volatile uint32_t TFR[kI2S_TFR_count];              /**< Transmit FIFO, array offset: 0x40, array step: 0x4, irregular array, not all indices are valid */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[4];
  volatile uint32_t TMR;                                    /**< Transmit Mask, offset: 0x60 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[9];
  volatile uint32_t RCSR;                                   /**< Receive Control, offset: 0x88 */
  volatile uint32_t RCR1;                                   /**< Receive Configuration 1, offset: 0x8C */
  volatile uint32_t RCR2;                                   /**< Receive Configuration 2, offset: 0x90 */
  volatile uint32_t RCR3;                                   /**< Receive Configuration 3, offset: 0x94 */
  volatile uint32_t RCR4;                                   /**< Receive Configuration 4, offset: 0x98 */
  volatile uint32_t RCR5;                                   /**< Receive Configuration 5, offset: 0x9C */
  const volatile uint32_t RDR[kI2S_RDR_count];              /**< Receive Data, array offset: 0xA0, array step: 0x4, irregular array, not all indices are valid */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[4];
  const volatile uint32_t RFR[kI2S_RFR_count];              /**< Receive FIFO, array offset: 0xC0, array step: 0x4, irregular array, not all indices are valid */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[4];
  volatile uint32_t RMR;                                    /**< Receive Mask, offset: 0xE0 */
};

constexpr size_t    kI2S_size  = 0xE4;
constexpr uintptr_t kI2S1_base = 0x40384000;
constexpr uintptr_t kI2S2_base = 0x40388000;
constexpr uintptr_t kI2S3_base = 0x4038C000;

namespace I2S1 {
constexpr regs::RegGroup<I2S_Layout, kI2S_size, kI2S1_base> group;
}  // namespace I2S1

namespace I2S2 {
constexpr regs::RegGroup<I2S_Layout, kI2S_size, kI2S2_base> group;
}  // namespace I2S2

namespace I2S3 {
constexpr regs::RegGroup<I2S_Layout, kI2S_size, kI2S3_base> group;
}  // namespace I2S3

namespace I2S1 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false>
using I2S1_Reg = regs::Reg32<kI2S1_base, I2S_Layout, Member, 0, Bits, Shift,
                             AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kI2S1_DATALINE_count)>>
using TDR_Reg = regs::Reg32<kI2S1_base, I2S_Layout, &I2S_Layout::TDR, Index,
                            Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kI2S1_DATALINE_count)>>
using TFR_Reg = regs::Reg32<kI2S1_base, I2S_Layout, &I2S_Layout::TFR, Index,
                            Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kI2S1_DATALINE_count)>>
using RDR_Reg = regs::Reg32<kI2S1_base, I2S_Layout, &I2S_Layout::RDR, Index,
                            Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kI2S1_DATALINE_count)>>
using RFR_Reg = regs::Reg32<kI2S1_base, I2S_Layout, &I2S_Layout::RFR, Index,
                            Bits, Shift, AssignMask, WriteOnly>;

// Version ID
namespace VERID {
constexpr I2S1_Reg<regs::constify(&I2S_Layout::VERID),  8, 24> MAJOR;    // Major Version Number
constexpr I2S1_Reg<regs::constify(&I2S_Layout::VERID),  8, 16> MINOR;    // Minor Version Number
constexpr I2S1_Reg<regs::constify(&I2S_Layout::VERID), 16,  0> FEATURE;  // Feature Specification Number
    // 0b0000000000000000..Standard feature set.
}  // namespace VERID

// Parameter
namespace PARAM {
constexpr I2S1_Reg<regs::constify(&I2S_Layout::PARAM), 4, 16> FRAME;     // Frame Size
constexpr I2S1_Reg<regs::constify(&I2S_Layout::PARAM), 4,  8> FIFO;      // FIFO Size
constexpr I2S1_Reg<regs::constify(&I2S_Layout::PARAM), 4,  0> DATALINE;  // Number of Datalines
}  // namespace PARAM

// Transmit Control
namespace TCSR {
constexpr uint32_t kW1C = 0x001c'0000;

constexpr I2S1_Reg<&I2S_Layout::TCSR, 1, 31, (uint32_t{0x1} << 31) | kW1C> TE;      // Transmitter Enable
    // 0b0..Transmitter is disabled.
    // 0b1..Transmitter is enabled, or transmitter has been disabled and has not yet reached end of frame.
constexpr I2S1_Reg<&I2S_Layout::TCSR, 1, 30, (uint32_t{0x1} << 30) | kW1C> STOPE;   // Stop Enable
    // 0b0..Transmitter disabled in Stop mode.
    // 0b1..Transmitter enabled in Stop mode.
constexpr I2S1_Reg<&I2S_Layout::TCSR, 1, 29, (uint32_t{0x1} << 29) | kW1C> DBGE;    // Debug Enable
    // 0b0..Transmitter is disabled in Debug mode, after completing the current frame.
    // 0b1..Transmitter is enabled in Debug mode.
constexpr I2S1_Reg<&I2S_Layout::TCSR, 1, 28, (uint32_t{0x1} << 28) | kW1C> BCE;     // Bit Clock Enable
    // 0b0..Transmit bit clock is disabled.
    // 0b1..Transmit bit clock is enabled.
constexpr I2S1_Reg<&I2S_Layout::TCSR, 1, 25, (uint32_t{0x1} << 25) | kW1C> FR;      // FIFO Reset
    // WORZ
    // 0b0..No effect.
    // 0b1..FIFO reset.
constexpr I2S1_Reg<&I2S_Layout::TCSR, 1, 24, (uint32_t{0x1} << 24) | kW1C> SR;      // Software Reset
    // 0b0..No effect.
    // 0b1..Software reset.
constexpr I2S1_Reg<&I2S_Layout::TCSR, 1, 20, kW1C> WSF;            // Word Start Flag
    // 0b0..Start of word not detected.
    // 0b1..Start of word detected.
constexpr I2S1_Reg<&I2S_Layout::TCSR, 1, 19, kW1C> SEF;            // Sync Error Flag
    // 0b0..Sync error not detected.
    // 0b1..Frame sync error detected.
constexpr I2S1_Reg<&I2S_Layout::TCSR, 1, 18, kW1C> FEF;            // FIFO Error Flag
    // 0b0..Transmit underrun not detected.
    // 0b1..Transmit underrun detected.
constexpr I2S1_Reg<regs::constify(&I2S_Layout::TCSR), 1, 17> FWF;  // FIFO Warning Flag
    // 0b0..No enabled transmit FIFO is empty.
    // 0b1..Enabled transmit FIFO is empty.
constexpr I2S1_Reg<regs::constify(&I2S_Layout::TCSR), 1, 16> FRF;  // FIFO Request Flag
    // 0b0..Transmit FIFO watermark has not been reached.
    // 0b1..Transmit FIFO watermark has been reached.
constexpr I2S1_Reg<&I2S_Layout::TCSR, 1, 12, (uint32_t{0x1} << 12) | kW1C> WSIE;    // Word Start Interrupt Enable
    // 0b0..Disables interrupt.
    // 0b1..Enables interrupt.
constexpr I2S1_Reg<&I2S_Layout::TCSR, 1, 11, (uint32_t{0x1} << 11) | kW1C> SEIE;    // Sync Error Interrupt Enable
    // 0b0..Disables interrupt.
    // 0b1..Enables interrupt.
constexpr I2S1_Reg<&I2S_Layout::TCSR, 1, 10, (uint32_t{0x1} << 10) | kW1C> FEIE;    // FIFO Error Interrupt Enable
    // 0b0..Disables the interrupt.
    // 0b1..Enables the interrupt.
constexpr I2S1_Reg<&I2S_Layout::TCSR, 1,  9, (uint32_t{0x1} <<  9) | kW1C> FWIE;    // FIFO Warning Interrupt Enable
    // 0b0..Disables the interrupt.
    // 0b1..Enables the interrupt.
constexpr I2S1_Reg<&I2S_Layout::TCSR, 1,  8, (uint32_t{0x1} <<  8) | kW1C> FRIE;    // FIFO Request Interrupt Enable
    // 0b0..Disables the interrupt.
    // 0b1..Enables the interrupt.
constexpr I2S1_Reg<&I2S_Layout::TCSR, 1,  1, (uint32_t{0x1} <<  1) | kW1C> FWDE;    // FIFO Warning DMA Enable
    // 0b0..Disables the DMA request.
    // 0b1..Enables the DMA request.
constexpr I2S1_Reg<&I2S_Layout::TCSR, 1,  0, (uint32_t{0x1} <<  0) | kW1C> FRDE;    // FIFO Request DMA Enable
    // 0b0..Disables the DMA request.
    // 0b1..Enables the DMA request.
}  // namespace TCSR

// Transmit Configuration 1
namespace TCR1 {
constexpr I2S1_Reg<&I2S_Layout::TCR1, 5, 0> TFW;  // Transmit FIFO Watermark
}  // namespace TCR1

// Transmit Configuration 2
namespace TCR2 {
constexpr I2S1_Reg<&I2S_Layout::TCR2, 1, 30> SYNC;  // Synchronous Mode
    // 0b0..Asynchronous mode.
    // 0b1..Synchronous with receiver.
constexpr I2S1_Reg<&I2S_Layout::TCR2, 1, 29> BCS;   // Bit Clock Swap
    // 0b0..Use the normal bit clock source.
    // 0b1..Swap the bit clock source.
constexpr I2S1_Reg<&I2S_Layout::TCR2, 1, 28> BCI;   // Bit Clock Input
    // 0b0..No effect.
    // 0b1..Internal logic is clocked as if bit clock was externally generated.
constexpr I2S1_Reg<&I2S_Layout::TCR2, 2, 26> MSEL;  // MCLK Select
    // 0b00..Bus Clock selected.
    // 0b01..Master Clock (MCLK) 1 option selected.
    // 0b10..Master Clock (MCLK) 2 option selected.
    // 0b11..Master Clock (MCLK) 3 option selected.
constexpr I2S1_Reg<&I2S_Layout::TCR2, 1, 25> BCP;   // Bit Clock Polarity
    // 0b0..Bit clock is active high with drive outputs on rising edge and sample inputs on falling edge.
    // 0b1..Bit clock is active low with drive outputs on falling edge and sample inputs on rising edge.
constexpr I2S1_Reg<&I2S_Layout::TCR2, 1, 24> BCD;   // Bit Clock Direction
    // 0b0..Bit clock is generated externally in Slave mode.
    // 0b1..Bit clock is generated internally in Master mode.
constexpr I2S1_Reg<&I2S_Layout::TCR2, 8,  0> DIV;   // Bit Clock Divide
}  // namespace TCR2

// Transmit Configuration 3
namespace TCR3 {
constexpr I2S1_Reg<&I2S_Layout::TCR3, 4, 24> CFR;   // Channel FIFO Reset
    // WORZ
constexpr I2S1_Reg<&I2S_Layout::TCR3, 4, 16> TCE;   // Transmit Channel Enable
constexpr I2S1_Reg<&I2S_Layout::TCR3, 5,  0> WDFL;  // Word Flag Configuration
}  // namespace TCR3

// Transmit Configuration 4
namespace TCR4 {
constexpr I2S1_Reg<&I2S_Layout::TCR4, 1, 28> FCONT;  // FIFO Continue on Error
    // 0b0..On FIFO error, the SAI will continue from the start of the next frame after the FIFO error flag has been
    //     cleared.
    // 0b1..On FIFO error, the SAI will continue from the same word that caused the FIFO error to set after the FIFO
    //     warning flag has been cleared.
constexpr I2S1_Reg<&I2S_Layout::TCR4, 2, 26> FCOMB;  // FIFO Combine Mode
    // 0b00..FIFO combine mode disabled.
    // 0b01..FIFO combine mode enabled on FIFO reads (from transmit shift registers).
    // 0b10..FIFO combine mode enabled on FIFO writes (by software).
    // 0b11..FIFO combine mode enabled on FIFO reads (from transmit shift registers) and writes (by software).
constexpr I2S1_Reg<&I2S_Layout::TCR4, 2, 24> FPACK;  // FIFO Packing Mode
    // 0b00..FIFO packing is disabled.
    // 0b01..Reserved
    // 0b10..8-bit FIFO packing is enabled.
    // 0b11..16-bit FIFO packing is enabled.
constexpr I2S1_Reg<&I2S_Layout::TCR4, 5, 16> FRSZ;   // Frame size
constexpr I2S1_Reg<&I2S_Layout::TCR4, 5,  8> SYWD;   // Sync Width
constexpr I2S1_Reg<&I2S_Layout::TCR4, 1,  5> CHMOD;  // Channel Mode
    // 0b0..TDM mode, transmit data pins are tri-stated when slots are masked or channels are disabled.
    // 0b1..Output mode, transmit data pins are never tri-stated and will output zero when slots are masked or
    //     channels are disabled.
constexpr I2S1_Reg<&I2S_Layout::TCR4, 1,  4> MF;     // MSB First
    // 0b0..LSB is transmitted first.
    // 0b1..MSB is transmitted first.
constexpr I2S1_Reg<&I2S_Layout::TCR4, 1,  3> FSE;    // Frame Sync Early
    // 0b0..Frame sync asserts with the first bit of the frame.
    // 0b1..Frame sync asserts one bit before the first bit of the frame.
constexpr I2S1_Reg<&I2S_Layout::TCR4, 1,  2> ONDEM;  // On Demand Mode
    // 0b0..Internal frame sync is generated continuously.
    // 0b1..Internal frame sync is generated when the FIFO warning flag is clear.
constexpr I2S1_Reg<&I2S_Layout::TCR4, 1,  1> FSP;    // Frame Sync Polarity
    // 0b0..Frame sync is active high.
    // 0b1..Frame sync is active low.
constexpr I2S1_Reg<&I2S_Layout::TCR4, 1,  0> FSD;    // Frame Sync Direction
    // 0b0..Frame sync is generated externally in Slave mode.
    // 0b1..Frame sync is generated internally in Master mode.
}  // namespace TCR4

// Transmit Configuration 5
namespace TCR5 {
constexpr I2S1_Reg<&I2S_Layout::TCR5, 5, 24> WNW;  // Word N Width
constexpr I2S1_Reg<&I2S_Layout::TCR5, 5, 16> W0W;  // Word 0 Width
constexpr I2S1_Reg<&I2S_Layout::TCR5, 5,  8> FBT;  // First Bit Shifted
}  // namespace TCR5

// Transmit Data
namespace TDR {
template <size_t Index>
constexpr TDR_Reg<Index, 32, 0> TDR;  // Transmit Data Register
    // WORZ
}  // namespace TDR

// Transmit FIFO
namespace TFR {
template <size_t Index>
constexpr TFR_Reg<Index, 1, 31> WCP;  // Write Channel Pointer
    // 0b0..No effect.
    // 0b1..FIFO combine is enabled for FIFO writes and this FIFO will be written on the next FIFO write.
template <size_t Index>
constexpr TFR_Reg<Index, 6, 16> WFP;  // Write FIFO Pointer
template <size_t Index>
constexpr TFR_Reg<Index, 6,  0> RFP;  // Read FIFO Pointer
}  // namespace TFR

// Transmit Mask
namespace TMR {
constexpr I2S1_Reg<&I2S_Layout::TMR, 32, 0> TWM;  // Transmit Word Mask
    // 0b00000000000000000000000000000000..Word N is enabled.
    // 0b00000000000000000000000000000001..Word N is masked. The transmit data pins are tri-stated or drive zero
    //     when masked.
}  // namespace TMR

// Receive Control
namespace RCSR {
constexpr uint32_t kW1C = 0x001c'0000;

constexpr I2S1_Reg<&I2S_Layout::RCSR, 1, 31, (uint32_t{0x1} << 31) | kW1C> RE;      // Receiver Enable
    // 0b0..Receiver is disabled.
    // 0b1..Receiver is enabled, or receiver has been disabled and has not yet reached end of frame.
constexpr I2S1_Reg<&I2S_Layout::RCSR, 1, 30, (uint32_t{0x1} << 30) | kW1C> STOPE;   // Stop Enable
    // 0b0..Receiver disabled in Stop mode.
    // 0b1..Receiver enabled in Stop mode.
constexpr I2S1_Reg<&I2S_Layout::RCSR, 1, 29, (uint32_t{0x1} << 29) | kW1C> DBGE;    // Debug Enable
    // 0b0..Receiver is disabled in Debug mode, after completing the current frame.
    // 0b1..Receiver is enabled in Debug mode.
constexpr I2S1_Reg<&I2S_Layout::RCSR, 1, 28, (uint32_t{0x1} << 28) | kW1C> BCE;     // Bit Clock Enable
    // 0b0..Receive bit clock is disabled.
    // 0b1..Receive bit clock is enabled.
constexpr I2S1_Reg<&I2S_Layout::RCSR, 1, 25, (uint32_t{0x1} << 25) | kW1C> FR;      // FIFO Reset
    // WORZ
    // 0b0..No effect.
    // 0b1..FIFO reset.
constexpr I2S1_Reg<&I2S_Layout::RCSR, 1, 24, (uint32_t{0x1} << 24) | kW1C> SR;      // Software Reset
    // 0b0..No effect.
    // 0b1..Software reset.
constexpr I2S1_Reg<&I2S_Layout::RCSR, 1, 20, kW1C> WSF;            // Word Start Flag
    // 0b0..Start of word not detected.
    // 0b1..Start of word detected.
constexpr I2S1_Reg<&I2S_Layout::RCSR, 1, 19, kW1C> SEF;            // Sync Error Flag
    // 0b0..Sync error not detected.
    // 0b1..Frame sync error detected.
constexpr I2S1_Reg<&I2S_Layout::RCSR, 1, 18, kW1C> FEF;            // FIFO Error Flag
    // 0b0..Receive overflow not detected.
    // 0b1..Receive overflow detected.
constexpr I2S1_Reg<regs::constify(&I2S_Layout::RCSR), 1, 17> FWF;  // FIFO Warning Flag
    // 0b0..No enabled receive FIFO is full.
    // 0b1..Enabled receive FIFO is full.
constexpr I2S1_Reg<regs::constify(&I2S_Layout::RCSR), 1, 16> FRF;  // FIFO Request Flag
    // 0b0..Receive FIFO watermark not reached.
    // 0b1..Receive FIFO watermark has been reached.
constexpr I2S1_Reg<&I2S_Layout::RCSR, 1, 12, (uint32_t{0x1} << 12) | kW1C> WSIE;    // Word Start Interrupt Enable
    // 0b0..Disables interrupt.
    // 0b1..Enables interrupt.
constexpr I2S1_Reg<&I2S_Layout::RCSR, 1, 11, (uint32_t{0x1} << 11) | kW1C> SEIE;    // Sync Error Interrupt Enable
    // 0b0..Disables interrupt.
    // 0b1..Enables interrupt.
constexpr I2S1_Reg<&I2S_Layout::RCSR, 1, 10, (uint32_t{0x1} << 10) | kW1C> FEIE;    // FIFO Error Interrupt Enable
    // 0b0..Disables the interrupt.
    // 0b1..Enables the interrupt.
constexpr I2S1_Reg<&I2S_Layout::RCSR, 1,  9, (uint32_t{0x1} <<  9) | kW1C> FWIE;    // FIFO Warning Interrupt Enable
    // 0b0..Disables the interrupt.
    // 0b1..Enables the interrupt.
constexpr I2S1_Reg<&I2S_Layout::RCSR, 1,  8, (uint32_t{0x1} <<  8) | kW1C> FRIE;    // FIFO Request Interrupt Enable
    // 0b0..Disables the interrupt.
    // 0b1..Enables the interrupt.
constexpr I2S1_Reg<&I2S_Layout::RCSR, 1,  1, (uint32_t{0x1} <<  1) | kW1C> FWDE;    // FIFO Warning DMA Enable
    // 0b0..Disables the DMA request.
    // 0b1..Enables the DMA request.
constexpr I2S1_Reg<&I2S_Layout::RCSR, 1,  0, (uint32_t{0x1} <<  0) | kW1C> FRDE;    // FIFO Request DMA Enable
    // 0b0..Disables the DMA request.
    // 0b1..Enables the DMA request.
}  // namespace RCSR

// Receive Configuration 1
namespace RCR1 {
constexpr I2S1_Reg<&I2S_Layout::RCR1, 5, 0> RFW;  // Receive FIFO Watermark
}  // namespace RCR1

// Receive Configuration 2
namespace RCR2 {
constexpr I2S1_Reg<&I2S_Layout::RCR2, 1, 30> SYNC;  // Synchronous Mode
    // 0b0..Asynchronous mode.
    // 0b1..Synchronous with transmitter.
constexpr I2S1_Reg<&I2S_Layout::RCR2, 1, 29> BCS;   // Bit Clock Swap
    // 0b0..Use the normal bit clock source.
    // 0b1..Swap the bit clock source.
constexpr I2S1_Reg<&I2S_Layout::RCR2, 1, 28> BCI;   // Bit Clock Input
    // 0b0..No effect.
    // 0b1..Internal logic is clocked as if bit clock was externally generated.
constexpr I2S1_Reg<&I2S_Layout::RCR2, 2, 26> MSEL;  // MCLK Select
    // 0b00..Bus Clock selected.
    // 0b01..Master Clock (MCLK) 1 option selected.
    // 0b10..Master Clock (MCLK) 2 option selected.
    // 0b11..Master Clock (MCLK) 3 option selected.
constexpr I2S1_Reg<&I2S_Layout::RCR2, 1, 25> BCP;   // Bit Clock Polarity
    // 0b0..Bit Clock is active high with drive outputs on rising edge and sample inputs on falling edge.
    // 0b1..Bit Clock is active low with drive outputs on falling edge and sample inputs on rising edge.
constexpr I2S1_Reg<&I2S_Layout::RCR2, 1, 24> BCD;   // Bit Clock Direction
    // 0b0..Bit clock is generated externally in Slave mode.
    // 0b1..Bit clock is generated internally in Master mode.
constexpr I2S1_Reg<&I2S_Layout::RCR2, 8,  0> DIV;   // Bit Clock Divide
}  // namespace RCR2

// Receive Configuration 3
namespace RCR3 {
constexpr I2S1_Reg<&I2S_Layout::RCR3, 4, 24> CFR;   // Channel FIFO Reset
    // WORZ
constexpr I2S1_Reg<&I2S_Layout::RCR3, 4, 16> RCE;   // Receive Channel Enable
constexpr I2S1_Reg<&I2S_Layout::RCR3, 5,  0> WDFL;  // Word Flag Configuration
}  // namespace RCR3

// Receive Configuration 4
namespace RCR4 {
constexpr I2S1_Reg<&I2S_Layout::RCR4, 1, 28> FCONT;  // FIFO Continue on Error
    // 0b0..On FIFO error, the SAI will continue from the start of the next frame after the FIFO error flag has been
    //     cleared.
    // 0b1..On FIFO error, the SAI will continue from the same word that caused the FIFO error to set after the FIFO
    //     warning flag has been cleared.
constexpr I2S1_Reg<&I2S_Layout::RCR4, 2, 26> FCOMB;  // FIFO Combine Mode
    // 0b00..FIFO combine mode disabled.
    // 0b01..FIFO combine mode enabled on FIFO writes (from receive shift registers).
    // 0b10..FIFO combine mode enabled on FIFO reads (by software).
    // 0b11..FIFO combine mode enabled on FIFO writes (from receive shift registers) and reads (by software).
constexpr I2S1_Reg<&I2S_Layout::RCR4, 2, 24> FPACK;  // FIFO Packing Mode
    // 0b00..FIFO packing is disabled
    // 0b01..Reserved.
    // 0b10..8-bit FIFO packing is enabled
    // 0b11..16-bit FIFO packing is enabled
constexpr I2S1_Reg<&I2S_Layout::RCR4, 5, 16> FRSZ;   // Frame Size
constexpr I2S1_Reg<&I2S_Layout::RCR4, 5,  8> SYWD;   // Sync Width
constexpr I2S1_Reg<&I2S_Layout::RCR4, 1,  4> MF;     // MSB First
    // 0b0..LSB is received first.
    // 0b1..MSB is received first.
constexpr I2S1_Reg<&I2S_Layout::RCR4, 1,  3> FSE;    // Frame Sync Early
    // 0b0..Frame sync asserts with the first bit of the frame.
    // 0b1..Frame sync asserts one bit before the first bit of the frame.
constexpr I2S1_Reg<&I2S_Layout::RCR4, 1,  2> ONDEM;  // On Demand Mode
    // 0b0..Internal frame sync is generated continuously.
    // 0b1..Internal frame sync is generated when the FIFO warning flag is clear.
constexpr I2S1_Reg<&I2S_Layout::RCR4, 1,  1> FSP;    // Frame Sync Polarity
    // 0b0..Frame sync is active high.
    // 0b1..Frame sync is active low.
constexpr I2S1_Reg<&I2S_Layout::RCR4, 1,  0> FSD;    // Frame Sync Direction
    // 0b0..Frame Sync is generated externally in Slave mode.
    // 0b1..Frame Sync is generated internally in Master mode.
}  // namespace RCR4

// Receive Configuration 5
namespace RCR5 {
constexpr I2S1_Reg<&I2S_Layout::RCR5, 5, 24> WNW;  // Word N Width
constexpr I2S1_Reg<&I2S_Layout::RCR5, 5, 16> W0W;  // Word 0 Width
constexpr I2S1_Reg<&I2S_Layout::RCR5, 5,  8> FBT;  // First Bit Shifted
}  // namespace RCR5

// Receive Data
namespace RDR {
template <size_t Index>
constexpr RDR_Reg<Index, 32, 0> RDR;  // Receive Data Register
}  // namespace RDR

// Receive FIFO
namespace RFR {
template <size_t Index>
constexpr RFR_Reg<Index, 6, 16> WFP;  // Write FIFO Pointer
template <size_t Index>
constexpr RFR_Reg<Index, 1, 15> RCP;  // Receive Channel Pointer
    // 0b0..No effect.
    // 0b1..FIFO combine is enabled for FIFO reads and this FIFO will be read on the next FIFO read.
template <size_t Index>
constexpr RFR_Reg<Index, 6,  0> RFP;  // Read FIFO Pointer
}  // namespace RFR

// Receive Mask
namespace RMR {
constexpr I2S1_Reg<&I2S_Layout::RMR, 32,  0> RWM;  // Receive Word Mask
    // 0b00000000000000000000000000000000..Word N is enabled.
    // 0b00000000000000000000000000000001..Word N is masked.
}  // namespace RMR

}  // namespace I2S1

namespace I2S2 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false>
using I2S2_Reg = regs::Reg32<kI2S2_base, I2S_Layout, Member, 0, Bits, Shift,
                             AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kI2S2_DATALINE_count)>>
using TDR_Reg = regs::Reg32<kI2S2_base, I2S_Layout, &I2S_Layout::TDR, Index,
                            Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kI2S2_DATALINE_count)>>
using TFR_Reg = regs::Reg32<kI2S2_base, I2S_Layout, &I2S_Layout::TFR, Index,
                            Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kI2S2_DATALINE_count)>>
using RDR_Reg = regs::Reg32<kI2S2_base, I2S_Layout, &I2S_Layout::RDR, Index,
                            Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kI2S2_DATALINE_count)>>
using RFR_Reg = regs::Reg32<kI2S2_base, I2S_Layout, &I2S_Layout::RFR, Index,
                            Bits, Shift, AssignMask, WriteOnly>;

// Version ID
namespace VERID {
constexpr I2S2_Reg<regs::constify(&I2S_Layout::VERID),  8, 24> MAJOR;
constexpr I2S2_Reg<regs::constify(&I2S_Layout::VERID),  8, 16> MINOR;
constexpr I2S2_Reg<regs::constify(&I2S_Layout::VERID), 16,  0> FEATURE;
}  // namespace VERID

// Parameter
namespace PARAM {
constexpr I2S2_Reg<regs::constify(&I2S_Layout::PARAM),  4, 16> FRAME;
constexpr I2S2_Reg<regs::constify(&I2S_Layout::PARAM),  4,  8> FIFO;
constexpr I2S2_Reg<regs::constify(&I2S_Layout::PARAM),  4,  0> DATALINE;
}  // namespace PARAM

// Transmit Control
namespace TCSR {
constexpr uint32_t kW1C = 0x001c'0000;

constexpr I2S2_Reg<&I2S_Layout::TCSR, 1, 31, (uint32_t{0x1} << 31) | kW1C> TE;
constexpr I2S2_Reg<&I2S_Layout::TCSR, 1, 30, (uint32_t{0x1} << 30) | kW1C> STOPE;
constexpr I2S2_Reg<&I2S_Layout::TCSR, 1, 29, (uint32_t{0x1} << 29) | kW1C> DBGE;
constexpr I2S2_Reg<&I2S_Layout::TCSR, 1, 28, (uint32_t{0x1} << 28) | kW1C> BCE;
constexpr I2S2_Reg<&I2S_Layout::TCSR, 1, 25, (uint32_t{0x1} << 25) | kW1C> FR;
constexpr I2S2_Reg<&I2S_Layout::TCSR, 1, 24, (uint32_t{0x1} << 24) | kW1C> SR;
constexpr I2S2_Reg<&I2S_Layout::TCSR, 1, 20, kW1C> WSF;
constexpr I2S2_Reg<&I2S_Layout::TCSR, 1, 19, kW1C> SEF;
constexpr I2S2_Reg<&I2S_Layout::TCSR, 1, 18, kW1C> FEF;
constexpr I2S2_Reg<regs::constify(&I2S_Layout::TCSR), 1, 17> FWF;
constexpr I2S2_Reg<regs::constify(&I2S_Layout::TCSR), 1, 16> FRF;
constexpr I2S2_Reg<&I2S_Layout::TCSR, 1, 12, (uint32_t{0x1} << 12) | kW1C> WSIE;
constexpr I2S2_Reg<&I2S_Layout::TCSR, 1, 11, (uint32_t{0x1} << 11) | kW1C> SEIE;
constexpr I2S2_Reg<&I2S_Layout::TCSR, 1, 10, (uint32_t{0x1} << 10) | kW1C> FEIE;
constexpr I2S2_Reg<&I2S_Layout::TCSR, 1,  9, (uint32_t{0x1} <<  9) | kW1C> FWIE;
constexpr I2S2_Reg<&I2S_Layout::TCSR, 1,  8, (uint32_t{0x1} <<  8) | kW1C> FRIE;
constexpr I2S2_Reg<&I2S_Layout::TCSR, 1,  1, (uint32_t{0x1} <<  1) | kW1C> FWDE;
constexpr I2S2_Reg<&I2S_Layout::TCSR, 1,  0, (uint32_t{0x1} <<  0) | kW1C> FRDE;
}  // namespace TCSR

// Transmit Configuration 1
namespace TCR1 {
constexpr I2S2_Reg<&I2S_Layout::TCR1, 5, 0> TFW;
}  // namespace TCR1

// Transmit Configuration 2
namespace TCR2 {
constexpr I2S2_Reg<&I2S_Layout::TCR2, 1, 30> SYNC;
constexpr I2S2_Reg<&I2S_Layout::TCR2, 1, 29> BCS;
constexpr I2S2_Reg<&I2S_Layout::TCR2, 1, 28> BCI;
constexpr I2S2_Reg<&I2S_Layout::TCR2, 2, 26> MSEL;
constexpr I2S2_Reg<&I2S_Layout::TCR2, 1, 25> BCP;
constexpr I2S2_Reg<&I2S_Layout::TCR2, 1, 24> BCD;
constexpr I2S2_Reg<&I2S_Layout::TCR2, 8,  0> DIV;
}  // namespace TCR2

// Transmit Configuration 3
namespace TCR3 {
// CFR not in SAI2
constexpr I2S2_Reg<&I2S_Layout::TCR3, 1, 16> TCE;  // Different than I2S1
constexpr I2S2_Reg<&I2S_Layout::TCR3, 5,  0> WDFL;
}  // namespace TCR3

// Transmit Configuration 4
namespace TCR4 {
constexpr I2S2_Reg<&I2S_Layout::TCR4, 1, 28> FCONT;
// FCOMB not in SAI2
constexpr I2S2_Reg<&I2S_Layout::TCR4, 2, 24> FPACK;
constexpr I2S2_Reg<&I2S_Layout::TCR4, 5, 16> FRSZ;
constexpr I2S2_Reg<&I2S_Layout::TCR4, 5,  8> SYWD;
constexpr I2S2_Reg<&I2S_Layout::TCR4, 1,  5> CHMOD;
constexpr I2S2_Reg<&I2S_Layout::TCR4, 1,  4> MF;
constexpr I2S2_Reg<&I2S_Layout::TCR4, 1,  3> FSE;
constexpr I2S2_Reg<&I2S_Layout::TCR4, 1,  2> ONDEM;
constexpr I2S2_Reg<&I2S_Layout::TCR4, 1,  1> FSP;
constexpr I2S2_Reg<&I2S_Layout::TCR4, 1,  0> FSD;
}  // namespace TCR4

// Transmit Configuration 5
namespace TCR5 {
constexpr I2S2_Reg<&I2S_Layout::TCR5, 5, 24> WNW;
constexpr I2S2_Reg<&I2S_Layout::TCR5, 5, 16> W0W;
constexpr I2S2_Reg<&I2S_Layout::TCR5, 5,  8> FBT;
}  // namespace TCR5

// Transmit Data
namespace TDR {
template <size_t Index>
constexpr TDR_Reg<Index, 32, 0> TDR;
    // WORZ
}  // namespace TDR

// Transmit FIFO
namespace TFR {
template <size_t Index>
constexpr TFR_Reg<Index, 1, 31> WCP;
template <size_t Index>
constexpr TFR_Reg<Index, 6, 16> WFP;
template <size_t Index>
constexpr TFR_Reg<Index, 6,  0> RFP;
}  // namespace TFR

// Transmit Mask
namespace TMR {
constexpr I2S2_Reg<&I2S_Layout::TMR, 32, 0> TWM;
}  // namespace TMR

// Receive Control
namespace RCSR {
constexpr uint32_t kW1C = 0x001c'0000;

constexpr I2S2_Reg<&I2S_Layout::RCSR, 1, 31, (uint32_t{0x1} << 31) | kW1C> RE;
constexpr I2S2_Reg<&I2S_Layout::RCSR, 1, 30, (uint32_t{0x1} << 30) | kW1C> STOPE;
constexpr I2S2_Reg<&I2S_Layout::RCSR, 1, 29, (uint32_t{0x1} << 29) | kW1C> DBGE;
constexpr I2S2_Reg<&I2S_Layout::RCSR, 1, 28, (uint32_t{0x1} << 28) | kW1C> BCE;
constexpr I2S2_Reg<&I2S_Layout::RCSR, 1, 25, (uint32_t{0x1} << 25) | kW1C> FR;
constexpr I2S2_Reg<&I2S_Layout::RCSR, 1, 24, (uint32_t{0x1} << 24) | kW1C> SR;
constexpr I2S2_Reg<&I2S_Layout::RCSR, 1, 20, kW1C> WSF;
constexpr I2S2_Reg<&I2S_Layout::RCSR, 1, 19, kW1C> SEF;
constexpr I2S2_Reg<&I2S_Layout::RCSR, 1, 18, kW1C> FEF;
constexpr I2S2_Reg<regs::constify(&I2S_Layout::RCSR), 1, 17> FWF;
constexpr I2S2_Reg<regs::constify(&I2S_Layout::RCSR), 1, 16> FRF;
constexpr I2S2_Reg<&I2S_Layout::RCSR, 1, 12, (uint32_t{0x1} << 12) | kW1C> WSIE;
constexpr I2S2_Reg<&I2S_Layout::RCSR, 1, 11, (uint32_t{0x1} << 11) | kW1C> SEIE;
constexpr I2S2_Reg<&I2S_Layout::RCSR, 1, 10, (uint32_t{0x1} << 10) | kW1C> FEIE;
constexpr I2S2_Reg<&I2S_Layout::RCSR, 1,  9, (uint32_t{0x1} <<  9) | kW1C> FWIE;
constexpr I2S2_Reg<&I2S_Layout::RCSR, 1,  8, (uint32_t{0x1} <<  8) | kW1C> FRIE;
constexpr I2S2_Reg<&I2S_Layout::RCSR, 1,  1, (uint32_t{0x1} <<  1) | kW1C> FWDE;
constexpr I2S2_Reg<&I2S_Layout::RCSR, 1,  0, (uint32_t{0x1} <<  0) | kW1C> FRDE;
}  // namespace RCSR

// Receive Configuration 1
namespace RCR1 {
constexpr I2S2_Reg<&I2S_Layout::RCR1, 5, 0> RFW;
}  // namespace RCR1

// Receive Configuration 2
namespace RCR2 {
constexpr I2S2_Reg<&I2S_Layout::RCR2, 1, 30> SYNC;
constexpr I2S2_Reg<&I2S_Layout::RCR2, 1, 29> BCS;
constexpr I2S2_Reg<&I2S_Layout::RCR2, 1, 28> BCI;
constexpr I2S2_Reg<&I2S_Layout::RCR2, 2, 26> MSEL;
constexpr I2S2_Reg<&I2S_Layout::RCR2, 1, 25> BCP;
constexpr I2S2_Reg<&I2S_Layout::RCR2, 1, 24> BCD;
constexpr I2S2_Reg<&I2S_Layout::RCR2, 8,  0> DIV;
}  // namespace RCR2

// Receive Configuration 3
namespace RCR3 {
// CFR not in SAI2
constexpr I2S2_Reg<&I2S_Layout::RCR3, 1, 16> RCE;  // Different than I2S1
constexpr I2S2_Reg<&I2S_Layout::RCR3, 5,  0> WDFL;
}  // namespace RCR3

// Receive Configuration 4
namespace RCR4 {
constexpr I2S2_Reg<&I2S_Layout::RCR4, 1, 28> FCONT;
// FCOMB not in SAI2
constexpr I2S2_Reg<&I2S_Layout::RCR4, 2, 24> FPACK;
constexpr I2S2_Reg<&I2S_Layout::RCR4, 5, 16> FRSZ;
constexpr I2S2_Reg<&I2S_Layout::RCR4, 5,  8> SYWD;
constexpr I2S2_Reg<&I2S_Layout::RCR4, 1,  4> MF;
constexpr I2S2_Reg<&I2S_Layout::RCR4, 1,  3> FSE;
constexpr I2S2_Reg<&I2S_Layout::RCR4, 1,  2> ONDEM;
constexpr I2S2_Reg<&I2S_Layout::RCR4, 1,  1> FSP;
constexpr I2S2_Reg<&I2S_Layout::RCR4, 1,  0> FSD;
}  // namespace RCR4

// Receive Configuration 5
namespace RCR5 {
constexpr I2S2_Reg<&I2S_Layout::RCR5, 5, 24> WNW;
constexpr I2S2_Reg<&I2S_Layout::RCR5, 5, 16> W0W;
constexpr I2S2_Reg<&I2S_Layout::RCR5, 5,  8> FBT;
}  // namespace RCR5

// Receive Data
namespace RDR {
template <size_t Index>
constexpr RDR_Reg<Index, 32, 0> RDR;
}  // namespace RDR

// Receive FIFO
namespace RFR {
template <size_t Index>
constexpr RFR_Reg<Index, 6, 16> WFP;
template <size_t Index>
constexpr RFR_Reg<Index, 1, 15> RCP;
template <size_t Index>
constexpr RFR_Reg<Index, 6,  0> RFP;
}  // namespace RFR

// Receive Mask
namespace RMR {
constexpr I2S2_Reg<&I2S_Layout::RMR, 32, 0> RWM;
}  // namespace RMR

}  // namespace I2S2

namespace I2S3 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false>
using I2S3_Reg = regs::Reg32<kI2S3_base, I2S_Layout, Member, 0, Bits, Shift,
                             AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kI2S3_DATALINE_count)>>
using TDR_Reg = regs::Reg32<kI2S3_base, I2S_Layout, &I2S_Layout::TDR, Index,
                            Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kI2S3_DATALINE_count)>>
using TFR_Reg = regs::Reg32<kI2S3_base, I2S_Layout, &I2S_Layout::TFR, Index,
                            Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kI2S3_DATALINE_count)>>
using RDR_Reg = regs::Reg32<kI2S3_base, I2S_Layout, &I2S_Layout::RDR, Index,
                            Bits, Shift, AssignMask, WriteOnly>;

template <size_t Index, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false,
          typename = std::enable_if_t<(Index < kI2S3_DATALINE_count)>>
using RFR_Reg = regs::Reg32<kI2S3_base, I2S_Layout, &I2S_Layout::RFR, Index,
                            Bits, Shift, AssignMask, WriteOnly>;

// Version ID
namespace VERID {
constexpr I2S3_Reg<regs::constify(&I2S_Layout::VERID),  8, 24> MAJOR;
constexpr I2S3_Reg<regs::constify(&I2S_Layout::VERID),  8, 16> MINOR;
constexpr I2S3_Reg<regs::constify(&I2S_Layout::VERID), 16,  0> FEATURE;
}  // namespace VERID

// Parameter
namespace PARAM {
constexpr I2S3_Reg<regs::constify(&I2S_Layout::PARAM), 4, 16> FRAME;
constexpr I2S3_Reg<regs::constify(&I2S_Layout::PARAM), 4,  8> FIFO;
constexpr I2S3_Reg<regs::constify(&I2S_Layout::PARAM), 4,  0> DATALINE;
}  // namespace PARAM

// Transmit Control
namespace TCSR {
constexpr uint32_t kW1C = 0x001c'0000;

constexpr I2S3_Reg<&I2S_Layout::TCSR, 1, 31, (uint32_t{0x1} << 31) | kW1C> TE;      // Transmitter Enable
constexpr I2S3_Reg<&I2S_Layout::TCSR, 1, 30, (uint32_t{0x1} << 30) | kW1C> STOPE;   // Stop Enable
constexpr I2S3_Reg<&I2S_Layout::TCSR, 1, 29, (uint32_t{0x1} << 29) | kW1C> DBGE;    // Debug Enable
constexpr I2S3_Reg<&I2S_Layout::TCSR, 1, 28, (uint32_t{0x1} << 28) | kW1C> BCE;     // Bit Clock Enable
constexpr I2S3_Reg<&I2S_Layout::TCSR, 1, 25, (uint32_t{0x1} << 25) | kW1C> FR;      // FIFO Reset
constexpr I2S3_Reg<&I2S_Layout::TCSR, 1, 24, (uint32_t{0x1} << 24) | kW1C> SR;      // Software Reset
constexpr I2S3_Reg<&I2S_Layout::TCSR, 1, 20, kW1C> WSF;            // Word Start Flag
constexpr I2S3_Reg<&I2S_Layout::TCSR, 1, 19, kW1C> SEF;            // Sync Error Flag
constexpr I2S3_Reg<&I2S_Layout::TCSR, 1, 18, kW1C> FEF;            // FIFO Error Flag
constexpr I2S3_Reg<regs::constify(&I2S_Layout::TCSR), 1, 17> FWF;  // FIFO Warning Flag
constexpr I2S3_Reg<regs::constify(&I2S_Layout::TCSR), 1, 16> FRF;  // FIFO Request Flag
constexpr I2S3_Reg<&I2S_Layout::TCSR, 1, 12, (uint32_t{0x1} << 12) | kW1C> WSIE;    // Word Start Interrupt Enable
constexpr I2S3_Reg<&I2S_Layout::TCSR, 1, 11, (uint32_t{0x1} << 11) | kW1C> SEIE;    // Sync Error Interrupt Enable
constexpr I2S3_Reg<&I2S_Layout::TCSR, 1, 10, (uint32_t{0x1} << 10) | kW1C> FEIE;    // FIFO Error Interrupt Enable
constexpr I2S3_Reg<&I2S_Layout::TCSR, 1,  9, (uint32_t{0x1} <<  9) | kW1C> FWIE;    // FIFO Warning Interrupt Enable
constexpr I2S3_Reg<&I2S_Layout::TCSR, 1,  8, (uint32_t{0x1} <<  8) | kW1C> FRIE;    // FIFO Request Interrupt Enable
constexpr I2S3_Reg<&I2S_Layout::TCSR, 1,  1, (uint32_t{0x1} <<  1) | kW1C> FWDE;    // FIFO Warning DMA Enable
constexpr I2S3_Reg<&I2S_Layout::TCSR, 1,  0, (uint32_t{0x1} <<  0) | kW1C> FRDE;    // FIFO Request DMA Enable
}  // namespace TCSR

// Transmit Configuration 1
namespace TCR1 {
constexpr I2S3_Reg<&I2S_Layout::TCR1, 5, 0> TFW;
}  // namespace TCR1

// Transmit Configuration 2
namespace TCR2 {
constexpr I2S3_Reg<&I2S_Layout::TCR2, 1, 30> SYNC;
constexpr I2S3_Reg<&I2S_Layout::TCR2, 1, 29> BCS;
constexpr I2S3_Reg<&I2S_Layout::TCR2, 1, 28> BCI;
constexpr I2S3_Reg<&I2S_Layout::TCR2, 2, 26> MSEL;
constexpr I2S3_Reg<&I2S_Layout::TCR2, 1, 25> BCP;
constexpr I2S3_Reg<&I2S_Layout::TCR2, 1, 24> BCD;
constexpr I2S3_Reg<&I2S_Layout::TCR2, 8,  0> DIV;
}  // namespace TCR2

// Transmit Configuration 3
namespace TCR3 {
// CFR not in SAI3
constexpr I2S3_Reg<&I2S_Layout::TCR3, 1, 16> TCE;  // Different than I2S1
constexpr I2S3_Reg<&I2S_Layout::TCR3, 5,  0> WDFL;
}  // namespace TCR3

// Transmit Configuration 4
namespace TCR4 {
constexpr I2S3_Reg<&I2S_Layout::TCR4, 1, 28> FCONT;
// FCOMB not in SAI3
constexpr I2S3_Reg<&I2S_Layout::TCR4, 2, 24> FPACK;
constexpr I2S3_Reg<&I2S_Layout::TCR4, 5, 16> FRSZ;
constexpr I2S3_Reg<&I2S_Layout::TCR4, 5,  8> SYWD;
constexpr I2S3_Reg<&I2S_Layout::TCR4, 1,  5> CHMOD;
constexpr I2S3_Reg<&I2S_Layout::TCR4, 1,  4> MF;
constexpr I2S3_Reg<&I2S_Layout::TCR4, 1,  3> FSE;
constexpr I2S3_Reg<&I2S_Layout::TCR4, 1,  2> ONDEM;
constexpr I2S3_Reg<&I2S_Layout::TCR4, 1,  1> FSP;
constexpr I2S3_Reg<&I2S_Layout::TCR4, 1,  0> FSD;
}  // namespace TCR4

// Transmit Configuration 5
namespace TCR5 {
constexpr I2S3_Reg<&I2S_Layout::TCR5, 5, 24> WNW;
constexpr I2S3_Reg<&I2S_Layout::TCR5, 5, 16> W0W;
constexpr I2S3_Reg<&I2S_Layout::TCR5, 5,  8> FBT;
}  // namespace TCR5

// Transmit Data
namespace TDR {
template <size_t Index>
constexpr TDR_Reg<Index, 32, 0> TDR;
}  // namespace TDR

// Transmit FIFO
namespace TFR {
template <size_t Index>
constexpr TFR_Reg<Index, 1, 31> WCP;
template <size_t Index>
constexpr TFR_Reg<Index, 6, 16> WFP;
template <size_t Index>
constexpr TFR_Reg<Index, 6,  0> RFP;
}  // namespace TFR

// Transmit Mask
namespace TMR {
constexpr I2S3_Reg<&I2S_Layout::TMR, 32, 0> TWM;
}  // namespace TMR

// Receive Control
namespace RCSR {
constexpr uint32_t kW1C = 0x001c'0000;

constexpr I2S3_Reg<&I2S_Layout::RCSR, 1, 31, (uint32_t{0x1} << 31) | kW1C> RE;
constexpr I2S3_Reg<&I2S_Layout::RCSR, 1, 30, (uint32_t{0x1} << 30) | kW1C> STOPE;
constexpr I2S3_Reg<&I2S_Layout::RCSR, 1, 29, (uint32_t{0x1} << 29) | kW1C> DBGE;
constexpr I2S3_Reg<&I2S_Layout::RCSR, 1, 28, (uint32_t{0x1} << 28) | kW1C> BCE;
constexpr I2S3_Reg<&I2S_Layout::RCSR, 1, 25, (uint32_t{0x1} << 25) | kW1C> FR;
constexpr I2S3_Reg<&I2S_Layout::RCSR, 1, 24, (uint32_t{0x1} << 24) | kW1C> SR;
constexpr I2S3_Reg<&I2S_Layout::RCSR, 1, 20, kW1C> WSF;
constexpr I2S3_Reg<&I2S_Layout::RCSR, 1, 19, kW1C> SEF;
constexpr I2S3_Reg<&I2S_Layout::RCSR, 1, 18, kW1C> FEF;
constexpr I2S3_Reg<regs::constify(&I2S_Layout::RCSR), 1, 17> FWF;
constexpr I2S3_Reg<regs::constify(&I2S_Layout::RCSR), 1, 16> FRF;
constexpr I2S3_Reg<&I2S_Layout::RCSR, 1, 12, (uint32_t{0x1} << 12) | kW1C> WSIE;
constexpr I2S3_Reg<&I2S_Layout::RCSR, 1, 11, (uint32_t{0x1} << 11) | kW1C> SEIE;
constexpr I2S3_Reg<&I2S_Layout::RCSR, 1, 10, (uint32_t{0x1} << 10) | kW1C> FEIE;
constexpr I2S3_Reg<&I2S_Layout::RCSR, 1,  9, (uint32_t{0x1} <<  9) | kW1C> FWIE;
constexpr I2S3_Reg<&I2S_Layout::RCSR, 1,  8, (uint32_t{0x1} <<  8) | kW1C> FRIE;
constexpr I2S3_Reg<&I2S_Layout::RCSR, 1,  1, (uint32_t{0x1} <<  1) | kW1C> FWDE;
constexpr I2S3_Reg<&I2S_Layout::RCSR, 1,  0, (uint32_t{0x1} <<  0) | kW1C> FRDE;
}  // namespace RCSR

// Receive Configuration 1
namespace RCR1 {
constexpr I2S3_Reg<&I2S_Layout::RCR1, 5, 0> RFW;
}  // namespace RCR1

// Receive Configuration 2
namespace RCR2 {
constexpr I2S3_Reg<&I2S_Layout::RCR2, 1, 30> SYNC;
constexpr I2S3_Reg<&I2S_Layout::RCR2, 1, 29> BCS;
constexpr I2S3_Reg<&I2S_Layout::RCR2, 1, 28> BCI;
constexpr I2S3_Reg<&I2S_Layout::RCR2, 2, 26> MSEL;
constexpr I2S3_Reg<&I2S_Layout::RCR2, 1, 25> BCP;
constexpr I2S3_Reg<&I2S_Layout::RCR2, 1, 24> BCD;
constexpr I2S3_Reg<&I2S_Layout::RCR2, 8,  0> DIV;
}  // namespace RCR2

// Receive Configuration 3
namespace RCR3 {
// CFR not in SAI3
constexpr I2S3_Reg<&I2S_Layout::RCR3, 1, 16> RCE;  // Different than I2S1
constexpr I2S3_Reg<&I2S_Layout::RCR3, 5,  0> WDFL;
}  // namespace RCR3

// Receive Configuration 4
namespace RCR4 {
constexpr I2S3_Reg<&I2S_Layout::RCR4, 1, 28> FCONT;
// FCOMB not in SAI3
constexpr I2S3_Reg<&I2S_Layout::RCR4, 2, 24> FPACK;
constexpr I2S3_Reg<&I2S_Layout::RCR4, 5, 16> FRSZ;
constexpr I2S3_Reg<&I2S_Layout::RCR4, 5,  8> SYWD;
constexpr I2S3_Reg<&I2S_Layout::RCR4, 1,  4> MF;
constexpr I2S3_Reg<&I2S_Layout::RCR4, 1,  3> FSE;
constexpr I2S3_Reg<&I2S_Layout::RCR4, 1,  2> ONDEM;
constexpr I2S3_Reg<&I2S_Layout::RCR4, 1,  1> FSP;
constexpr I2S3_Reg<&I2S_Layout::RCR4, 1,  0> FSD;
}  // namespace RCR4

// Receive Configuration 5
namespace RCR5 {
constexpr I2S3_Reg<&I2S_Layout::RCR5, 5, 24> WNW;
constexpr I2S3_Reg<&I2S_Layout::RCR5, 5, 16> W0W;
constexpr I2S3_Reg<&I2S_Layout::RCR5, 5,  8> FBT;
}  // namespace RCR5

// Receive Data
namespace RDR {
template <size_t Index>
constexpr RDR_Reg<Index, 32, 0> RDR;
}  // namespace RDR

// Receive FIFO
namespace RFR {
template <size_t Index>
constexpr RFR_Reg<Index, 6, 16> WFP;
template <size_t Index>
constexpr RFR_Reg<Index, 1, 15> RCP;
template <size_t Index>
constexpr RFR_Reg<Index, 6,  0> RFP;
}  // namespace RFR

// Receive Mask
namespace RMR {
constexpr I2S3_Reg<&I2S_Layout::RMR, 32, 0> RWM;
}  // namespace RMR

}  // namespace I2S3

namespace I2S {

namespace TCR2 {
// MCLK Select values
constexpr uint32_t kMSEL_BUS    = 0;
constexpr uint32_t kMSEL_MCLK_1 = 1;
constexpr uint32_t kMSEL_MCLK_2 = 2;
constexpr uint32_t kMSEL_MCLK_3 = 3;
}  // namespace TCR2

namespace TCR4 {
// FIFO Combine Mode values
constexpr uint32_t kFCOMB_DISABLED         = 0;
constexpr uint32_t kFCOMB_READS            = 1;
constexpr uint32_t kFCOMB_WRITES           = 2;
constexpr uint32_t kFCOMB_READS_AND_WRITES = 3;

// FIFO Packing Mode values
constexpr uint32_t kFPACK_DISABLED = 0;
constexpr uint32_t kFPACK_8_BIT    = 2;
constexpr uint32_t kFPACK_16_BIT   = 3;
}  // namespace TCR4

namespace RCR4 {
// FIFO Combine Mode values
constexpr uint32_t kFCOMB_DISABLED         = 0;
constexpr uint32_t kFCOMB_WRITES           = 1;
constexpr uint32_t kFCOMB_READS            = 2;
constexpr uint32_t kFCOMB_WRITES_AND_READS = 3;

// FIFO Packing Mode values
constexpr uint32_t kFPACK_DISABLED = 0;
constexpr uint32_t kFPACK_8_BIT    = 2;
constexpr uint32_t kFPACK_16_BIT   = 3;
}  // namespace RCR4

}  // namespace I2S

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
