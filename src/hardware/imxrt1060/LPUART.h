// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// LPUART.h defines all the LPUART registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the Low-Power Universal Asynchronous
// Receiver/Transmitter (LPUART) registers.
//
// Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_LPUART.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct LPUART_Layout {
  const volatile uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  const volatile uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  volatile uint32_t GLOBAL;                                  /**< LPUART Global Register, offset: 0x8 */
  volatile uint32_t PINCFG;                                  /**< LPUART Pin Configuration Register, offset: 0xC */
  volatile uint32_t BAUD;                                    /**< LPUART Baud Rate Register, offset: 0x10 */
  volatile uint32_t STAT;                                    /**< LPUART Status Register, offset: 0x14 */
  volatile uint32_t CTRL;                                    /**< LPUART Control Register, offset: 0x18 */
  volatile uint32_t DATA;                                    /**< LPUART Data Register, offset: 0x1C */
  volatile uint32_t MATCH;                                   /**< LPUART Match Address Register, offset: 0x20 */
  volatile uint32_t MODIR;                                   /**< LPUART Modem IrDA Register, offset: 0x24 */
  volatile uint32_t FIFO;                                    /**< LPUART FIFO Register, offset: 0x28 */
  volatile uint32_t WATER;                                   /**< LPUART Watermark Register, offset: 0x2C */
};

constexpr size_t    kLPUART_size  = 0x30;
constexpr uintptr_t kLPUART1_base = 0x40184000;
constexpr uintptr_t kLPUART2_base = 0x40188000;
constexpr uintptr_t kLPUART3_base = 0x4018C000;
constexpr uintptr_t kLPUART4_base = 0x40190000;
constexpr uintptr_t kLPUART5_base = 0x40194000;
constexpr uintptr_t kLPUART6_base = 0x40198000;
constexpr uintptr_t kLPUART7_base = 0x4019C000;
constexpr uintptr_t kLPUART8_base = 0x401A0000;

namespace LPUART1 {
constexpr regs::RegGroup<LPUART_Layout, kLPUART_size, kLPUART1_base> group;
}  // namespace LPUART1

namespace LPUART2 {
constexpr regs::RegGroup<LPUART_Layout, kLPUART_size, kLPUART2_base> group;
}  // namespace LPUART2

namespace LPUART3 {
constexpr regs::RegGroup<LPUART_Layout, kLPUART_size, kLPUART3_base> group;
}  // namespace LPUART3

namespace LPUART4 {
constexpr regs::RegGroup<LPUART_Layout, kLPUART_size, kLPUART4_base> group;
}  // namespace LPUART4

namespace LPUART5 {
constexpr regs::RegGroup<LPUART_Layout, kLPUART_size, kLPUART5_base> group;
}  // namespace LPUART5

namespace LPUART6 {
constexpr regs::RegGroup<LPUART_Layout, kLPUART_size, kLPUART6_base> group;
}  // namespace LPUART6

namespace LPUART7 {
constexpr regs::RegGroup<LPUART_Layout, kLPUART_size, kLPUART7_base> group;
}  // namespace LPUART7

namespace LPUART8 {
constexpr regs::RegGroup<LPUART_Layout, kLPUART_size, kLPUART8_base> group;
}  // namespace LPUART8

namespace LPUART1 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false>
using LPUART1_Reg =
    regs::Reg32<kLPUART1_base, LPUART_Layout, Member, 0, Bits, Shift,
                AssignMask, WriteOnly>;

// Version ID Register
namespace VERID {
constexpr LPUART1_Reg<&LPUART_Layout::VERID,  8, 24> MAJOR;    // Major Version Number
constexpr LPUART1_Reg<&LPUART_Layout::VERID,  8, 16> MINOR;    // Minor Version Number
constexpr LPUART1_Reg<&LPUART_Layout::VERID, 16,  0> FEATURE;  // Feature Identification Number
    // 0b0000000000000001..Standard feature set.
    // 0b0000000000000011..Standard feature set with MODEM/IrDA support.
}  // namespace VERID

// Parameter Register
namespace PARAM {
constexpr LPUART1_Reg<&LPUART_Layout::PARAM, 8, 8> RXFIFO;  // Receive FIFO Size
constexpr LPUART1_Reg<&LPUART_Layout::PARAM, 8, 0> TXFIFO;  // Transmit FIFO Size
}  // namespace PARAM

// LPUART Global Register
namespace GLOBAL {
constexpr LPUART1_Reg<&LPUART_Layout::GLOBAL, 1, 1> RST;  // Software Reset
    // 0b0..Module is not reset.
    // 0b1..Module is reset.
}  // namespace GLOBAL

// LPUART Pin Configuration Register
namespace PINCFG {
constexpr LPUART1_Reg<&LPUART_Layout::PINCFG, 2, 0> TRGSEL;  // Trigger Select
    // 0b00..Input trigger is disabled.
    // 0b01..Input trigger is used instead of RXD pin input.
    // 0b10..Input trigger is used instead of CTS_B pin input.
    // 0b11..Input trigger is used to modulate the TXD pin output. The TXD pin output (after TXINV configuration) is
    //     internally ANDed with the input trigger.
}  // namespace PINCFG

// LPUART Baud Rate Register
namespace BAUD {
constexpr LPUART1_Reg<&LPUART_Layout::BAUD,  1, 31> MAEN1;      // Match Address Mode Enable 1
    // 0b0..Normal operation.
    // 0b1..Enables automatic address matching or data matching mode for MATCH[MA1].
constexpr LPUART1_Reg<&LPUART_Layout::BAUD,  1, 30> MAEN2;      // Match Address Mode Enable 2
    // 0b0..Normal operation.
    // 0b1..Enables automatic address matching or data matching mode for MATCH[MA2].
constexpr LPUART1_Reg<&LPUART_Layout::BAUD,  1, 29> M10;        // 10-bit Mode select
    // 0b0..Receiver and transmitter use 7-bit to 9-bit data characters.
    // 0b1..Receiver and transmitter use 10-bit data characters.
constexpr LPUART1_Reg<&LPUART_Layout::BAUD,  5, 24> OSR;        // Oversampling Ratio
    // 0b00000..Writing 0 to this field results in an oversampling ratio of 16
    // 0b00001..Reserved
    // 0b00010..Reserved
    // 0b00011..Oversampling ratio of 4, requires BOTHEDGE to be set.
    // 0b00100..Oversampling ratio of 5, requires BOTHEDGE to be set.
    // 0b00101..Oversampling ratio of 6, requires BOTHEDGE to be set.
    // 0b00110..Oversampling ratio of 7, requires BOTHEDGE to be set.
    // 0b00111..Oversampling ratio of 8.
    // 0b01000..Oversampling ratio of 9.
    // 0b01001..Oversampling ratio of 10.
    // 0b01010..Oversampling ratio of 11.
    // 0b01011..Oversampling ratio of 12.
    // 0b01100..Oversampling ratio of 13.
    // 0b01101..Oversampling ratio of 14.
    // 0b01110..Oversampling ratio of 15.
    // 0b01111..Oversampling ratio of 16.
    // 0b10000..Oversampling ratio of 17.
    // 0b10001..Oversampling ratio of 18.
    // 0b10010..Oversampling ratio of 19.
    // 0b10011..Oversampling ratio of 20.
    // 0b10100..Oversampling ratio of 21.
    // 0b10101..Oversampling ratio of 22.
    // 0b10110..Oversampling ratio of 23.
    // 0b10111..Oversampling ratio of 24.
    // 0b11000..Oversampling ratio of 25.
    // 0b11001..Oversampling ratio of 26.
    // 0b11010..Oversampling ratio of 27.
    // 0b11011..Oversampling ratio of 28.
    // 0b11100..Oversampling ratio of 29.
    // 0b11101..Oversampling ratio of 30.
    // 0b11110..Oversampling ratio of 31.
    // 0b11111..Oversampling ratio of 32.
constexpr LPUART1_Reg<&LPUART_Layout::BAUD,  1, 23> TDMAE;      // Transmitter DMA Enable
    // 0b0..DMA request disabled.
    // 0b1..DMA request enabled.
constexpr LPUART1_Reg<&LPUART_Layout::BAUD,  1, 21> RDMAE;      // Receiver Full DMA Enable
    // 0b0..DMA request disabled.
    // 0b1..DMA request enabled.
constexpr LPUART1_Reg<&LPUART_Layout::BAUD,  2, 18> MATCFG;     // Match Configuration
    // 0b00..Address Match Wakeup
    // 0b01..Idle Match Wakeup
    // 0b10..Match On and Match Off
    // 0b11..Enables RWU on Data Match and Match On/Off for transmitter CTS input
constexpr LPUART1_Reg<&LPUART_Layout::BAUD,  1, 17> BOTHEDGE;   // Both Edge Sampling
    // 0b0..Receiver samples input data using the rising edge of the baud rate clock.
    // 0b1..Receiver samples input data using the rising and falling edge of the baud rate clock.
constexpr LPUART1_Reg<&LPUART_Layout::BAUD,  1, 16> RESYNCDIS;  // Resynchronization Disable
    // 0b0..Resynchronization during received data word is supported.
    // 0b1..Resynchronization during received data word is disabled.
constexpr LPUART1_Reg<&LPUART_Layout::BAUD,  1, 15> LBKDIE;     // LIN Break Detect Interrupt Enable
    // 0b0..Hardware interrupts from STAT[LBKDIF] flag are disabled (use polling).
    // 0b1..Hardware interrupt is requested when STAT[LBKDIF] flag is 1.
constexpr LPUART1_Reg<&LPUART_Layout::BAUD,  1, 14> RXEDGIE;    // RX Input Active Edge Interrupt Enable
    // 0b0..Hardware interrupts from STAT[RXEDGIF] are disabled.
    // 0b1..Hardware interrupt is requested when STAT[RXEDGIF] flag is 1.
constexpr LPUART1_Reg<&LPUART_Layout::BAUD,  1, 13> SBNS;       // Stop Bit Number Select
    // 0b0..One stop bit.
    // 0b1..Two stop bits.
constexpr LPUART1_Reg<&LPUART_Layout::BAUD, 13,  0> SBR;        // Baud Rate Modulo Divisor.
}  // namespace BAUD

// LPUART Status Register
namespace STAT {
constexpr uint32_t kW1C = 0xc01f'c000;

constexpr LPUART1_Reg<&LPUART_Layout::STAT, 1, 31, kW1C> LBKDIF;                         // LIN Break Detect Interrupt Flag
    // 0b0..No LIN break character has been detected.
    // 0b1..LIN break character has been detected.
constexpr LPUART1_Reg<&LPUART_Layout::STAT, 1, 30, kW1C> RXEDGIF;                        // RXD Pin Active Edge Interrupt Flag
    // 0b0..No active edge on the receive pin has occurred.
    // 0b1..An active edge on the receive pin has occurred.
constexpr LPUART1_Reg<&LPUART_Layout::STAT, 1, 29, (uint32_t{0x1} << 29) | kW1C> MSBF;   // MSB First
    // 0b0..LSB (bit0) is the first bit that is transmitted following the start bit. Further, the first bit received
    //     after the start bit is identified as bit0.
    // 0b1..MSB (identified as bit9, bit8, bit7 or bit6) is the first bit that is transmitted following the start
    //     bit depending on the setting of CTRL[M], CTRL[PE] and BAUD[M10]. .
constexpr LPUART1_Reg<&LPUART_Layout::STAT, 1, 28, (uint32_t{0x1} << 28) | kW1C> RXINV;  // Receive Data Inversion
    // 0b0..Receive data not inverted.
    // 0b1..Receive data inverted.
constexpr LPUART1_Reg<&LPUART_Layout::STAT, 1, 27, (uint32_t{0x1} << 27) | kW1C> RWUID;  // Receive Wake Up Idle Detect
    // 0b0..During receive standby state (RWU = 1), the IDLE bit does not get set upon detection of an idle
    //     character. During address match wakeup, the IDLE bit does not set when an address does not match.
    // 0b1..During receive standby state (RWU = 1), the IDLE bit gets set upon detection of an idle character.
    //     During address match wakeup, the IDLE bit does set when an address does not match.
constexpr LPUART1_Reg<&LPUART_Layout::STAT, 1, 26, (uint32_t{0x1} << 26) | kW1C> BRK13;  // Break Character Generation Length
    // 0b0..Break character is transmitted with length of 9 to 13 bit times.
    // 0b1..Break character is transmitted with length of 12 to 15 bit times.
constexpr LPUART1_Reg<&LPUART_Layout::STAT, 1, 25, (uint32_t{0x1} << 25) | kW1C> LBKDE;  // LIN Break Detection Enable
    // 0b0..LIN break detect is disabled, normal break character can be detected.
    // 0b1..LIN break detect is enabled. LIN break character is detected at length of 11 bit times (if M = 0) or 12
    //     (if M = 1) or 13 (M10 = 1).
constexpr LPUART1_Reg<regs::constify(&LPUART_Layout::STAT), 1, 24> RAF;                  // Receiver Active Flag
    // 0b0..LPUART receiver idle waiting for a start bit.
    // 0b1..LPUART receiver active (RXD input not idle).
constexpr LPUART1_Reg<regs::constify(&LPUART_Layout::STAT), 1, 23> TDRE;                 // Transmit Data Register Empty Flag
    // 0b0..Transmit FIFO level is greater than watermark.
    // 0b1..Transmit FIFO level is equal or less than watermark.
constexpr LPUART1_Reg<regs::constify(&LPUART_Layout::STAT), 1, 22> TC;                   // Transmission Complete Flag
    // 0b0..Transmitter active (sending data, a preamble, or a break).
    // 0b1..Transmitter idle (transmission activity complete).
constexpr LPUART1_Reg<regs::constify(&LPUART_Layout::STAT), 1, 21> RDRF;                 // Receive Data Register Full Flag
    // 0b0..Receive FIFO level is less than watermark.
    // 0b1..Receive FIFO level is equal or greater than watermark.
constexpr LPUART1_Reg<&LPUART_Layout::STAT, 1, 20, kW1C> IDLE;                           // Idle Line Flag
    // 0b0..No idle line detected.
    // 0b1..Idle line is detected.
constexpr LPUART1_Reg<&LPUART_Layout::STAT, 1, 19, kW1C> OR;                             // Receiver Overrun Flag
    // 0b0..No overrun.
    // 0b1..Receive overrun (new LPUART data lost).
constexpr LPUART1_Reg<&LPUART_Layout::STAT, 1, 18, kW1C> NF;                             // Noise Flag
    // 0b0..No noise detected.
    // 0b1..Noise detected in the received character in the DATA register.
constexpr LPUART1_Reg<&LPUART_Layout::STAT, 1, 17, kW1C> FE;                             // Framing Error Flag
    // 0b0..No framing error detected. This does not guarantee the framing is correct.
    // 0b1..Framing error.
constexpr LPUART1_Reg<&LPUART_Layout::STAT, 1, 16, kW1C> PF;                             // Parity Error Flag
    // 0b0..No parity error.
    // 0b1..Parity error.
constexpr LPUART1_Reg<&LPUART_Layout::STAT, 1, 15, kW1C> MA1F;                           // Match 1 Flag
    // 0b0..Received data is not equal to MA1
    // 0b1..Received data is equal to MA1
constexpr LPUART1_Reg<&LPUART_Layout::STAT, 1, 14, kW1C> MA2F;                           // Match 2 Flag
    // 0b0..Received data is not equal to MA2
    // 0b1..Received data is equal to MA2
}  // namespace STAT

// LPUART Control Register
namespace CTRL {
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1, 31> R8T9;     // Receive Bit 8 / Transmit Bit 9
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1, 30> R9T8;     // Receive Bit 9 / Transmit Bit 8
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1, 29> TXDIR;    // TXD Pin Direction in Single-Wire Mode
    // 0b0..TXD pin is an input in single-wire mode.
    // 0b1..TXD pin is an output in single-wire mode.
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1, 28> TXINV;    // Transmit Data Inversion
    // 0b0..Transmit data not inverted.
    // 0b1..Transmit data inverted.
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1, 27> ORIE;     // Overrun Interrupt Enable
    // 0b0..OR interrupts disabled; use polling.
    // 0b1..Hardware interrupt is requested when OR is set.
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1, 26> NEIE;     // Noise Error Interrupt Enable
    // 0b0..NF interrupts disabled; use polling.
    // 0b1..Hardware interrupt is requested when NF is set.
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1, 25> FEIE;     // Framing Error Interrupt Enable
    // 0b0..FE interrupts disabled; use polling.
    // 0b1..Hardware interrupt is requested when FE is set.
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1, 24> PEIE;     // Parity Error Interrupt Enable
    // 0b0..PF interrupts disabled; use polling).
    // 0b1..Hardware interrupt is requested when PF is set.
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1, 23> TIE;      // Transmit Interrupt Enable
    // 0b0..Hardware interrupts from TDRE disabled.
    // 0b1..Hardware interrupt is requested when TDRE flag is 1.
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1, 22> TCIE;     // Transmission Complete Interrupt Enable
    // 0b0..Hardware interrupts from TC disabled.
    // 0b1..Hardware interrupt is requested when TC flag is 1.
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1, 21> RIE;      // Receiver Interrupt Enable
    // 0b0..Hardware interrupts from RDRF disabled.
    // 0b1..Hardware interrupt is requested when RDRF flag is 1.
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1, 20> ILIE;     // Idle Line Interrupt Enable
    // 0b0..Hardware interrupts from IDLE disabled; use polling.
    // 0b1..Hardware interrupt is requested when IDLE flag is 1.
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1, 19> TE;       // Transmitter Enable
    // 0b0..Transmitter disabled.
    // 0b1..Transmitter enabled.
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1, 18> RE;       // Receiver Enable
    // 0b0..Receiver disabled.
    // 0b1..Receiver enabled.
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1, 17> RWU;      // Receiver Wakeup Control
    // 0b0..Normal receiver operation.
    // 0b1..LPUART receiver in standby waiting for wakeup condition.
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1, 16> SBK;      // Send Break
    // 0b0..Normal transmitter operation.
    // 0b1..Queue break character(s) to be sent.
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1, 15> MA1IE;    // Match 1 Interrupt Enable
    // 0b0..MA1F interrupt disabled
    // 0b1..MA1F interrupt enabled
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1, 14> MA2IE;    // Match 2 Interrupt Enable
    // 0b0..MA2F interrupt disabled
    // 0b1..MA2F interrupt enabled
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1, 11> M7;       // 7-Bit Mode Select
    // 0b0..Receiver and transmitter use 8-bit to 10-bit data characters.
    // 0b1..Receiver and transmitter use 7-bit data characters.
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 3,  8> IDLECFG;  // Idle Configuration
    // 2^'value':
    // 0b000..1 idle character
    // 0b001..2 idle characters
    // 0b010..4 idle characters
    // 0b011..8 idle characters
    // 0b100..16 idle characters
    // 0b101..32 idle characters
    // 0b110..64 idle characters
    // 0b111..128 idle characters
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1,  7> LOOPS;    // Loop Mode Select
    // 0b0..Normal operation - RXD and TXD use separate pins.
    // 0b1..Loop mode or single-wire mode where transmitter outputs are internally connected to receiver input (see
    //     RSRC bit).
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1,  6> DOZEEN;   // Doze Enable
    // 0b0..LPUART is enabled in Doze mode.
    // 0b1..LPUART is disabled in Doze mode .
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1,  5> RSRC;     // Receiver Source Select
    // 0b0..Provided LOOPS is set, RSRC is cleared, selects internal loop back mode and the LPUART does not use the
    //     RXD pin.
    // 0b1..Single-wire LPUART mode where the TXD pin is connected to the transmitter output and receiver input.
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1,  4> M;        // 9-Bit or 8-Bit Mode Select
    // 0b0..Receiver and transmitter use 8-bit data characters.
    // 0b1..Receiver and transmitter use 9-bit data characters.
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1,  3> WAKE;     // Receiver Wakeup Method Select
    // 0b0..Configures RWU for idle-line wakeup.
    // 0b1..Configures RWU with address-mark wakeup.
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1,  2> ILT;      // Idle Line Type Select
    // 0b0..Idle character bit count starts after start bit.
    // 0b1..Idle character bit count starts after stop bit.
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1,  1> PE;       // Parity Enable
    // 0b0..No hardware parity generation or checking.
    // 0b1..Parity enabled.
constexpr LPUART1_Reg<&LPUART_Layout::CTRL, 1,  0> PT;       // Parity Type
    // 0b0..Even parity.
    // 0b1..Odd parity.
}  // namespace CTRL

// LPUART Data Register
namespace DATA {
constexpr LPUART1_Reg<regs::constify(&LPUART_Layout::DATA), 1, 15> NOISY;    // Noisy Data Received
    // 0b0..The dataword is received without noise.
    // 0b1..The data is received with noise.
constexpr LPUART1_Reg<regs::constify(&LPUART_Layout::DATA), 1, 14> PARITYE;  // Parity Error
    // 0b0..The dataword is received without a parity error.
    // 0b1..The dataword is received with a parity error.
constexpr LPUART1_Reg<&LPUART_Layout::DATA, 1, 13> FRETSC;                   // Frame Error / Transmit Special Character
    // 0b0..The dataword is received without a frame error on read, or transmit a normal character on write.
    // 0b1..The dataword is received with a frame error, or transmit an idle or break character on transmit.
constexpr LPUART1_Reg<regs::constify(&LPUART_Layout::DATA), 1, 12> RXEMPT;   // Receive Buffer Empty
    // 0b0..Receive buffer contains valid data.
    // 0b1..Receive buffer is empty, data returned on read is not valid.
constexpr LPUART1_Reg<regs::constify(&LPUART_Layout::DATA), 1, 11> IDLINE;   // Idle Line
    // 0b0..Receiver was not idle before receiving this character.
    // 0b1..Receiver was idle before receiving this character.
constexpr LPUART1_Reg<&LPUART_Layout::DATA, 1,  9> R9T9;                     // R9T9
constexpr LPUART1_Reg<&LPUART_Layout::DATA, 1,  8> R8T8;                     // R8T8
constexpr LPUART1_Reg<&LPUART_Layout::DATA, 1,  7> R7T7;                     // R7T7
constexpr LPUART1_Reg<&LPUART_Layout::DATA, 1,  6> R6T6;                     // R6T6
constexpr LPUART1_Reg<&LPUART_Layout::DATA, 1,  5> R5T5;                     // R5T5
constexpr LPUART1_Reg<&LPUART_Layout::DATA, 1,  4> R4T4;                     // R4T4
constexpr LPUART1_Reg<&LPUART_Layout::DATA, 1,  3> R3T3;                     // R3T3
constexpr LPUART1_Reg<&LPUART_Layout::DATA, 1,  2> R2T2;                     // R2T2
constexpr LPUART1_Reg<&LPUART_Layout::DATA, 1,  1> R1T1;                     // R1T1
constexpr LPUART1_Reg<&LPUART_Layout::DATA, 1,  0> R0T0;                     // R0T0
}  // namespace DATA

// LPUART Match Address Register
namespace MATCH {
constexpr LPUART1_Reg<&LPUART_Layout::MATCH, 10, 16> MA2;  // Match Address 2
constexpr LPUART1_Reg<&LPUART_Layout::MATCH, 10,  0> MA1;  // Match Address 1
}  // namespace MATCH

// LPUART Modem IrDA Register
namespace MODIR {
constexpr LPUART1_Reg<&LPUART_Layout::MODIR, 1, 18> IREN;      // Infrared enable
    // 0b0..IR disabled.
    // 0b1..IR enabled.
constexpr LPUART1_Reg<&LPUART_Layout::MODIR, 2, 16> TNP;       // Transmitter narrow pulse
    // ('value' + 1)/OSR:
    // 0b00..1/OSR.
    // 0b01..2/OSR.
    // 0b10..3/OSR.
    // 0b11..4/OSR.
constexpr LPUART1_Reg<&LPUART_Layout::MODIR, 2,  8> RTSWATER;  // Receive RTS Configuration
constexpr LPUART1_Reg<&LPUART_Layout::MODIR, 1,  5> TXCTSSRC;  // Transmit CTS Source
    // 0b0..CTS input is the CTS_B pin.
    // 0b1..CTS input is an internal connection to the receiver address match result.
constexpr LPUART1_Reg<&LPUART_Layout::MODIR, 1,  4> TXCTSC;    // Transmit CTS Configuration
    // 0b0..CTS input is sampled at the start of each character.
    // 0b1..CTS input is sampled when the transmitter is idle.
constexpr LPUART1_Reg<&LPUART_Layout::MODIR, 1,  3> RXRTSE;    // Receiver request-to-send enable
    // 0b0..The receiver has no effect on RTS.
    // 0b1..RTS is deasserted if the receiver data register is full or a start bit has been detected that would
    //     cause the receiver data register to become full. RTS is asserted if the receiver data register is not
    //     full and has not detected a start bit that would cause the receiver data register to become full.
constexpr LPUART1_Reg<&LPUART_Layout::MODIR, 1,  2> TXRTSPOL;  // Transmitter request-to-send polarity
    // 0b0..Transmitter RTS is active low.
    // 0b1..Transmitter RTS is active high.
constexpr LPUART1_Reg<&LPUART_Layout::MODIR, 1,  1> TXRTSE;    // Transmitter request-to-send enable
    // 0b0..The transmitter has no effect on RTS.
    // 0b1..When a character is placed into an empty transmit shift register, RTS asserts one bit time before the
    //     start bit is transmitted. RTS deasserts one bit time after all characters in the transmitter FIFO and
    //     shift register are completely sent, including the last stop bit.
constexpr LPUART1_Reg<&LPUART_Layout::MODIR, 1,  0> TXCTSE;    // Transmitter clear-to-send enable
    // 0b0..CTS has no effect on the transmitter.
    // 0b1..Enables clear-to-send operation. The transmitter checks the state of CTS each time it is ready to send a
    //     character. If CTS is asserted, the character is sent. If CTS is deasserted, the signal TXD remains in the
    //     mark state and transmission is delayed until CTS is asserted. Changes in CTS as a character is being sent
    //     do not affect its transmission.
}  // namespace MODIR

// LPUART FIFO Register
namespace FIFO {
constexpr uint32_t kW1C  = 0x0003'0000;
constexpr uint32_t kWORZ = 0x0000'c000;

constexpr LPUART1_Reg<regs::constify(&LPUART_Layout::FIFO), 1, 23> TXEMPT;                // Transmit FIFO/Buffer Empty
    // 0b0..Transmit buffer is not empty.
    // 0b1..Transmit buffer is empty.
constexpr LPUART1_Reg<regs::constify(&LPUART_Layout::FIFO), 1, 22> RXEMPT;                // Receive FIFO/Buffer Empty
    // 0b0..Receive buffer is not empty.
    // 0b1..Receive buffer is empty.
constexpr LPUART1_Reg<&LPUART_Layout::FIFO, 1, 17, kW1C> TXOF;                            // Transmitter FIFO Overflow Flag
    // 0b0..No transmit FIFO overflow has occurred since the last time the flag was cleared.
    // 0b1..At least one transmit FIFO overflow has occurred since the last time the flag was cleared.
constexpr LPUART1_Reg<&LPUART_Layout::FIFO, 1, 16, kW1C> RXUF;                            // Receiver FIFO Underflow Flag
    // 0b0..No receive FIFO underflow has occurred since the last time the flag was cleared.
    // 0b1..At least one receive FIFO underflow has occurred since the last time the flag was cleared.
constexpr LPUART1_Reg<&LPUART_Layout::FIFO, 1, 15, kWORZ | kW1C> TXFLUSH;                 // Transmit FIFO Flush
    // WORZ
    // 0b0..No flush operation occurs.
    // 0b1..All data in the transmit FIFO is cleared out.
constexpr LPUART1_Reg<&LPUART_Layout::FIFO, 1, 14, kWORZ | kW1C> RXFLUSH;                 // Receive FIFO Flush
    // WORZ
    // 0b0..No flush operation occurs.
    // 0b1..All data in the receive FIFO/buffer is cleared out.
constexpr LPUART1_Reg<&LPUART_Layout::FIFO, 3, 10, (uint32_t{0x7} << 10) | kW1C> RXIDEN;  // Receiver Idle Empty Enable
    // 0b000..Disable RDRF assertion due to partially filled FIFO when receiver is idle.
    // 0b001..Enable RDRF assertion due to partially filled FIFO when receiver is idle for 1 character.
    // 0b010..Enable RDRF assertion due to partially filled FIFO when receiver is idle for 2 characters.
    // 0b011..Enable RDRF assertion due to partially filled FIFO when receiver is idle for 4 characters.
    // 0b100..Enable RDRF assertion due to partially filled FIFO when receiver is idle for 8 characters.
    // 0b101..Enable RDRF assertion due to partially filled FIFO when receiver is idle for 16 characters.
    // 0b110..Enable RDRF assertion due to partially filled FIFO when receiver is idle for 32 characters.
    // 0b111..Enable RDRF assertion due to partially filled FIFO when receiver is idle for 64 characters.
constexpr LPUART1_Reg<&LPUART_Layout::FIFO, 1,  9, (uint32_t{0x1} <<  9) | kW1C> TXOFE;   // Transmit FIFO Overflow Interrupt Enable
    // 0b0..TXOF flag does not generate an interrupt to the host.
    // 0b1..TXOF flag generates an interrupt to the host.
constexpr LPUART1_Reg<&LPUART_Layout::FIFO, 1,  8, (uint32_t{0x1} <<  8) | kW1C> RXUFE;   // Receive FIFO Underflow Interrupt Enable
    // 0b0..RXUF flag does not generate an interrupt to the host.
    // 0b1..RXUF flag generates an interrupt to the host.
constexpr LPUART1_Reg<&LPUART_Layout::FIFO, 1,  7, (uint32_t{0x1} <<  7) | kW1C> TXFE;    // Transmit FIFO Enable
    // 0b0..Transmit FIFO is not enabled. Buffer depth is 1.
    // 0b1..Transmit FIFO is enabled. Buffer depth is indicated by TXFIFOSIZE.
constexpr LPUART1_Reg<regs::constify(&LPUART_Layout::FIFO), 3,  4> TXFIFOSIZE;            // Transmit FIFO Buffer Depth
    // 0b000..Transmit FIFO/Buffer depth = 1 dataword.
    // 0b001..Transmit FIFO/Buffer depth = 4 datawords.
    // 0b010..Transmit FIFO/Buffer depth = 8 datawords.
    // 0b011..Transmit FIFO/Buffer depth = 16 datawords.
    // 0b100..Transmit FIFO/Buffer depth = 32 datawords.
    // 0b101..Transmit FIFO/Buffer depth = 64 datawords.
    // 0b110..Transmit FIFO/Buffer depth = 128 datawords.
    // 0b111..Transmit FIFO/Buffer depth = 256 datawords
constexpr LPUART1_Reg<&LPUART_Layout::FIFO, 1,  3, (uint32_t{0x1} <<  3) | kW1C> RXFE;    // Receive FIFO Enable
    // 0b0..Receive FIFO is not enabled. Buffer depth is 1.
    // 0b1..Receive FIFO is enabled. Buffer depth is indicted by RXFIFOSIZE.
constexpr LPUART1_Reg<regs::constify(&LPUART_Layout::FIFO), 3,  0> RXFIFOSIZE;            // Receive FIFO Buffer Depth
    // 0b000..Receive FIFO/Buffer depth = 1 dataword.
    // 0b001..Receive FIFO/Buffer depth = 4 datawords.
    // 0b010..Receive FIFO/Buffer depth = 8 datawords.
    // 0b011..Receive FIFO/Buffer depth = 16 datawords.
    // 0b100..Receive FIFO/Buffer depth = 32 datawords.
    // 0b101..Receive FIFO/Buffer depth = 64 datawords.
    // 0b110..Receive FIFO/Buffer depth = 128 datawords.
    // 0b111..Receive FIFO/Buffer depth = 256 datawords.
}  // namespace FIFO

// LPUART Watermark Register
namespace WATER {
constexpr LPUART1_Reg<regs::constify(&LPUART_Layout::WATER), 3, 24> RXCOUNT;  // Receive Counter
constexpr LPUART1_Reg<&LPUART_Layout::WATER, 2, 16> RXWATER;                  // Receive Watermark
constexpr LPUART1_Reg<regs::constify(&LPUART_Layout::WATER), 3,  8> TXCOUNT;  // Transmit Counter
constexpr LPUART1_Reg<&LPUART_Layout::WATER, 2,  0> TXWATER;                  // Transmit Watermark
}  // namespace WATER

}  // namespace LPUART1

namespace LPUART2 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false>
using LPUART2_Reg =
    regs::Reg32<kLPUART2_base, LPUART_Layout, Member, 0, Bits, Shift,
                AssignMask, WriteOnly>;

// Version ID Register
namespace VERID {
constexpr LPUART2_Reg<&LPUART_Layout::VERID,  8, 24> MAJOR;
constexpr LPUART2_Reg<&LPUART_Layout::VERID,  8, 16> MINOR;
constexpr LPUART2_Reg<&LPUART_Layout::VERID, 16,  0> FEATURE;
}  // namespace VERID

// Parameter Register
namespace PARAM {
constexpr LPUART2_Reg<&LPUART_Layout::PARAM, 8, 8> RXFIFO;
constexpr LPUART2_Reg<&LPUART_Layout::PARAM, 8, 0> TXFIFO;
}  // namespace PARAM

// LPUART Global Register
namespace GLOBAL {
constexpr LPUART2_Reg<&LPUART_Layout::GLOBAL, 1, 1> RST;
}  // namespace GLOBAL

// LPUART Pin Configuration Register
namespace PINCFG {
constexpr LPUART2_Reg<&LPUART_Layout::PINCFG, 2, 0> TRGSEL;
}  // namespace PINCFG

// LPUART Baud Rate Register
namespace BAUD {
constexpr LPUART2_Reg<&LPUART_Layout::BAUD,  1, 31> MAEN1;
constexpr LPUART2_Reg<&LPUART_Layout::BAUD,  1, 30> MAEN2;
constexpr LPUART2_Reg<&LPUART_Layout::BAUD,  1, 29> M10;
constexpr LPUART2_Reg<&LPUART_Layout::BAUD,  5, 24> OSR;
constexpr LPUART2_Reg<&LPUART_Layout::BAUD,  1, 23> TDMAE;
constexpr LPUART2_Reg<&LPUART_Layout::BAUD,  1, 21> RDMAE;
constexpr LPUART2_Reg<&LPUART_Layout::BAUD,  2, 18> MATCFG;
constexpr LPUART2_Reg<&LPUART_Layout::BAUD,  1, 17> BOTHEDGE;
constexpr LPUART2_Reg<&LPUART_Layout::BAUD,  1, 16> RESYNCDIS;
constexpr LPUART2_Reg<&LPUART_Layout::BAUD,  1, 15> LBKDIE;
constexpr LPUART2_Reg<&LPUART_Layout::BAUD,  1, 14> RXEDGIE;
constexpr LPUART2_Reg<&LPUART_Layout::BAUD,  1, 13> SBNS;
constexpr LPUART2_Reg<&LPUART_Layout::BAUD, 13,  0> SBR;
}  // namespace BAUD

// LPUART Status Register
namespace STAT {
constexpr uint32_t kW1C = 0xc01f'c000;

constexpr LPUART2_Reg<&LPUART_Layout::STAT, 1, 31, kW1C> LBKDIF;
constexpr LPUART2_Reg<&LPUART_Layout::STAT, 1, 30, kW1C> RXEDGIF;
constexpr LPUART2_Reg<&LPUART_Layout::STAT, 1, 29, (uint32_t{0x1} << 29) | kW1C> MSBF;
constexpr LPUART2_Reg<&LPUART_Layout::STAT, 1, 28, (uint32_t{0x1} << 28) | kW1C> RXINV;
constexpr LPUART2_Reg<&LPUART_Layout::STAT, 1, 27, (uint32_t{0x1} << 27) | kW1C> RWUID;
constexpr LPUART2_Reg<&LPUART_Layout::STAT, 1, 26, (uint32_t{0x1} << 26) | kW1C> BRK13;
constexpr LPUART2_Reg<&LPUART_Layout::STAT, 1, 25, (uint32_t{0x1} << 25) | kW1C> LBKDE;
constexpr LPUART2_Reg<regs::constify(&LPUART_Layout::STAT), 1, 24> RAF;
constexpr LPUART2_Reg<regs::constify(&LPUART_Layout::STAT), 1, 23> TDRE;
constexpr LPUART2_Reg<regs::constify(&LPUART_Layout::STAT), 1, 22> TC;
constexpr LPUART2_Reg<regs::constify(&LPUART_Layout::STAT), 1, 21> RDRF;
constexpr LPUART2_Reg<&LPUART_Layout::STAT, 1, 20, kW1C> IDLE;
constexpr LPUART2_Reg<&LPUART_Layout::STAT, 1, 19, kW1C> OR;
constexpr LPUART2_Reg<&LPUART_Layout::STAT, 1, 18, kW1C> NF;
constexpr LPUART2_Reg<&LPUART_Layout::STAT, 1, 17, kW1C> FE;
constexpr LPUART2_Reg<&LPUART_Layout::STAT, 1, 16, kW1C> PF;
constexpr LPUART2_Reg<&LPUART_Layout::STAT, 1, 15, kW1C> MA1F;
constexpr LPUART2_Reg<&LPUART_Layout::STAT, 1, 14, kW1C> MA2F;
}  // namespace STAT

// LPUART Control Register
namespace CTRL {
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1, 31> R8T9;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1, 30> R9T8;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1, 29> TXDIR;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1, 28> TXINV;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1, 27> ORIE;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1, 26> NEIE;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1, 25> FEIE;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1, 24> PEIE;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1, 23> TIE;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1, 22> TCIE;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1, 21> RIE;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1, 20> ILIE;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1, 19> TE;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1, 18> RE;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1, 17> RWU;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1, 16> SBK;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1, 15> MA1IE;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1, 14> MA2IE;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1, 11> M7;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 3,  8> IDLECFG;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1,  7> LOOPS;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1,  6> DOZEEN;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1,  5> RSRC;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1,  4> M;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1,  3> WAKE;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1,  2> ILT;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1,  1> PE;
constexpr LPUART2_Reg<&LPUART_Layout::CTRL, 1,  0> PT;
}  // namespace CTRL

// LPUART Data Register
namespace DATA {
constexpr LPUART2_Reg<regs::constify(&LPUART_Layout::DATA), 1, 15> NOISY;
constexpr LPUART2_Reg<regs::constify(&LPUART_Layout::DATA), 1, 14> PARITYE;
constexpr LPUART2_Reg<&LPUART_Layout::DATA, 1, 13> FRETSC;
constexpr LPUART2_Reg<regs::constify(&LPUART_Layout::DATA), 1, 12> RXEMPT;
constexpr LPUART2_Reg<regs::constify(&LPUART_Layout::DATA), 1, 11> IDLINE;
constexpr LPUART2_Reg<&LPUART_Layout::DATA, 1,  9> R9T9;
constexpr LPUART2_Reg<&LPUART_Layout::DATA, 1,  8> R8T8;
constexpr LPUART2_Reg<&LPUART_Layout::DATA, 1,  7> R7T7;
constexpr LPUART2_Reg<&LPUART_Layout::DATA, 1,  6> R6T6;
constexpr LPUART2_Reg<&LPUART_Layout::DATA, 1,  5> R5T5;
constexpr LPUART2_Reg<&LPUART_Layout::DATA, 1,  4> R4T4;
constexpr LPUART2_Reg<&LPUART_Layout::DATA, 1,  3> R3T3;
constexpr LPUART2_Reg<&LPUART_Layout::DATA, 1,  2> R2T2;
constexpr LPUART2_Reg<&LPUART_Layout::DATA, 1,  1> R1T1;
constexpr LPUART2_Reg<&LPUART_Layout::DATA, 1,  0> R0T0;
}  // namespace DATA

// LPUART Match Address Register
namespace MATCH {
constexpr LPUART2_Reg<&LPUART_Layout::MATCH, 10, 16> MA2;
constexpr LPUART2_Reg<&LPUART_Layout::MATCH, 10,  0> MA1;
}  // namespace MATCH

// LPUART Modem IrDA Register
namespace MODIR {
constexpr LPUART2_Reg<&LPUART_Layout::MODIR, 1, 18> IREN;
constexpr LPUART2_Reg<&LPUART_Layout::MODIR, 2, 16> TNP;
constexpr LPUART2_Reg<&LPUART_Layout::MODIR, 2,  8> RTSWATER;
constexpr LPUART2_Reg<&LPUART_Layout::MODIR, 1,  5> TXCTSSRC;
constexpr LPUART2_Reg<&LPUART_Layout::MODIR, 1,  4> TXCTSC;
constexpr LPUART2_Reg<&LPUART_Layout::MODIR, 1,  3> RXRTSE;
constexpr LPUART2_Reg<&LPUART_Layout::MODIR, 1,  2> TXRTSPOL;
constexpr LPUART2_Reg<&LPUART_Layout::MODIR, 1,  1> TXRTSE;
constexpr LPUART2_Reg<&LPUART_Layout::MODIR, 1,  0> TXCTSE;
}  // namespace MODIR

// LPUART FIFO Register
namespace FIFO {
constexpr uint32_t kW1C  = 0x0003'0000;
constexpr uint32_t kWORZ = 0x0000'c000;

constexpr LPUART2_Reg<regs::constify(&LPUART_Layout::FIFO), 1, 23> TXEMPT;
constexpr LPUART2_Reg<regs::constify(&LPUART_Layout::FIFO), 1, 22> RXEMPT;
constexpr LPUART2_Reg<&LPUART_Layout::FIFO, 1, 17, kW1C> TXOF;
constexpr LPUART2_Reg<&LPUART_Layout::FIFO, 1, 16, kW1C> RXUF;
constexpr LPUART2_Reg<&LPUART_Layout::FIFO, 1, 15, kWORZ | kW1C> TXFLUSH;
constexpr LPUART2_Reg<&LPUART_Layout::FIFO, 1, 14, kWORZ | kW1C> RXFLUSH;
constexpr LPUART2_Reg<&LPUART_Layout::FIFO, 3, 10, (uint32_t{0x7} << 10) | kW1C> RXIDEN;
constexpr LPUART2_Reg<&LPUART_Layout::FIFO, 1,  9, (uint32_t{0x1} <<  9) | kW1C> TXOFE;
constexpr LPUART2_Reg<&LPUART_Layout::FIFO, 1,  8, (uint32_t{0x1} <<  8) | kW1C> RXUFE;
constexpr LPUART2_Reg<&LPUART_Layout::FIFO, 1,  7, (uint32_t{0x1} <<  7) | kW1C> TXFE;
constexpr LPUART2_Reg<regs::constify(&LPUART_Layout::FIFO), 3,  4> TXFIFOSIZE;
constexpr LPUART2_Reg<&LPUART_Layout::FIFO, 1,  3, (uint32_t{0x1} <<  3) | kW1C> RXFE;
constexpr LPUART2_Reg<regs::constify(&LPUART_Layout::FIFO), 3,  0> RXFIFOSIZE;
}  // namespace FIFO

// LPUART Watermark Register
namespace WATER {
constexpr LPUART2_Reg<regs::constify(&LPUART_Layout::WATER), 3, 24> RXCOUNT;
constexpr LPUART2_Reg<&LPUART_Layout::WATER, 2, 16> RXWATER;
constexpr LPUART2_Reg<regs::constify(&LPUART_Layout::WATER), 3,  8> TXCOUNT;
constexpr LPUART2_Reg<&LPUART_Layout::WATER, 2,  0> TXWATER;
}  // namespace WATER

}  // namespace LPUART2

namespace LPUART3 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false>
using LPUART3_Reg =
    regs::Reg32<kLPUART3_base, LPUART_Layout, Member, 0, Bits, Shift,
                AssignMask, WriteOnly>;

// Version ID Register
namespace VERID {
constexpr LPUART3_Reg<&LPUART_Layout::VERID,  8, 24> MAJOR;
constexpr LPUART3_Reg<&LPUART_Layout::VERID,  8, 16> MINOR;
constexpr LPUART3_Reg<&LPUART_Layout::VERID, 16,  0> FEATURE;
}  // namespace VERID

// Parameter Register
namespace PARAM {
constexpr LPUART3_Reg<&LPUART_Layout::PARAM, 8, 8> RXFIFO;
constexpr LPUART3_Reg<&LPUART_Layout::PARAM, 8, 0> TXFIFO;
}  // namespace PARAM

// LPUART Global Register
namespace GLOBAL {
constexpr LPUART3_Reg<&LPUART_Layout::GLOBAL, 1, 1> RST;
}  // namespace GLOBAL

// LPUART Pin Configuration Register
namespace PINCFG {
constexpr LPUART3_Reg<&LPUART_Layout::PINCFG, 2, 0> TRGSEL;
}  // namespace PINCFG

// LPUART Baud Rate Register
namespace BAUD {
constexpr LPUART3_Reg<&LPUART_Layout::BAUD,  1, 31> MAEN1;
constexpr LPUART3_Reg<&LPUART_Layout::BAUD,  1, 30> MAEN2;
constexpr LPUART3_Reg<&LPUART_Layout::BAUD,  1, 29> M10;
constexpr LPUART3_Reg<&LPUART_Layout::BAUD,  5, 24> OSR;
constexpr LPUART3_Reg<&LPUART_Layout::BAUD,  1, 23> TDMAE;
constexpr LPUART3_Reg<&LPUART_Layout::BAUD,  1, 21> RDMAE;
constexpr LPUART3_Reg<&LPUART_Layout::BAUD,  2, 18> MATCFG;
constexpr LPUART3_Reg<&LPUART_Layout::BAUD,  1, 17> BOTHEDGE;
constexpr LPUART3_Reg<&LPUART_Layout::BAUD,  1, 16> RESYNCDIS;
constexpr LPUART3_Reg<&LPUART_Layout::BAUD,  1, 15> LBKDIE;
constexpr LPUART3_Reg<&LPUART_Layout::BAUD,  1, 14> RXEDGIE;
constexpr LPUART3_Reg<&LPUART_Layout::BAUD,  1, 13> SBNS;
constexpr LPUART3_Reg<&LPUART_Layout::BAUD, 13,  0> SBR;
}  // namespace BAUD

// LPUART Status Register
namespace STAT {
constexpr uint32_t kW1C = 0xc01f'c000;

constexpr LPUART3_Reg<&LPUART_Layout::STAT, 1, 31, kW1C> LBKDIF;
constexpr LPUART3_Reg<&LPUART_Layout::STAT, 1, 30, kW1C> RXEDGIF;
constexpr LPUART3_Reg<&LPUART_Layout::STAT, 1, 29, (uint32_t{0x1} << 29) | kW1C> MSBF;
constexpr LPUART3_Reg<&LPUART_Layout::STAT, 1, 28, (uint32_t{0x1} << 28) | kW1C> RXINV;
constexpr LPUART3_Reg<&LPUART_Layout::STAT, 1, 27, (uint32_t{0x1} << 27) | kW1C> RWUID;
constexpr LPUART3_Reg<&LPUART_Layout::STAT, 1, 26, (uint32_t{0x1} << 26) | kW1C> BRK13;
constexpr LPUART3_Reg<&LPUART_Layout::STAT, 1, 25, (uint32_t{0x1} << 25) | kW1C> LBKDE;
constexpr LPUART3_Reg<regs::constify(&LPUART_Layout::STAT), 1, 24> RAF;
constexpr LPUART3_Reg<regs::constify(&LPUART_Layout::STAT), 1, 23> TDRE;
constexpr LPUART3_Reg<regs::constify(&LPUART_Layout::STAT), 1, 22> TC;
constexpr LPUART3_Reg<regs::constify(&LPUART_Layout::STAT), 1, 21> RDRF;
constexpr LPUART3_Reg<&LPUART_Layout::STAT, 1, 20, kW1C> IDLE;
constexpr LPUART3_Reg<&LPUART_Layout::STAT, 1, 19, kW1C> OR;
constexpr LPUART3_Reg<&LPUART_Layout::STAT, 1, 18, kW1C> NF;
constexpr LPUART3_Reg<&LPUART_Layout::STAT, 1, 17, kW1C> FE;
constexpr LPUART3_Reg<&LPUART_Layout::STAT, 1, 16, kW1C> PF;
constexpr LPUART3_Reg<&LPUART_Layout::STAT, 1, 15, kW1C> MA1F;
constexpr LPUART3_Reg<&LPUART_Layout::STAT, 1, 14, kW1C> MA2F;
}  // namespace STAT

// LPUART Control Register
namespace CTRL {
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1, 31> R8T9;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1, 30> R9T8;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1, 29> TXDIR;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1, 28> TXINV;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1, 27> ORIE;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1, 26> NEIE;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1, 25> FEIE;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1, 24> PEIE;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1, 23> TIE;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1, 22> TCIE;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1, 21> RIE;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1, 20> ILIE;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1, 19> TE;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1, 18> RE;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1, 17> RWU;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1, 16> SBK;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1, 15> MA1IE;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1, 14> MA2IE;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1, 11> M7;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 3,  8> IDLECFG;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1,  7> LOOPS;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1,  6> DOZEEN;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1,  5> RSRC;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1,  4> M;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1,  3> WAKE;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1,  2> ILT;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1,  1> PE;
constexpr LPUART3_Reg<&LPUART_Layout::CTRL, 1,  0> PT;
}  // namespace CTRL

// LPUART Data Register
namespace DATA {
constexpr LPUART3_Reg<regs::constify(&LPUART_Layout::DATA), 1, 15> NOISY;
constexpr LPUART3_Reg<regs::constify(&LPUART_Layout::DATA), 1, 14> PARITYE;
constexpr LPUART3_Reg<&LPUART_Layout::DATA, 1, 13> FRETSC;
constexpr LPUART3_Reg<regs::constify(&LPUART_Layout::DATA), 1, 12> RXEMPT;
constexpr LPUART3_Reg<regs::constify(&LPUART_Layout::DATA), 1, 11> IDLINE;
constexpr LPUART3_Reg<&LPUART_Layout::DATA, 1,  9> R9T9;
constexpr LPUART3_Reg<&LPUART_Layout::DATA, 1,  8> R8T8;
constexpr LPUART3_Reg<&LPUART_Layout::DATA, 1,  7> R7T7;
constexpr LPUART3_Reg<&LPUART_Layout::DATA, 1,  6> R6T6;
constexpr LPUART3_Reg<&LPUART_Layout::DATA, 1,  5> R5T5;
constexpr LPUART3_Reg<&LPUART_Layout::DATA, 1,  4> R4T4;
constexpr LPUART3_Reg<&LPUART_Layout::DATA, 1,  3> R3T3;
constexpr LPUART3_Reg<&LPUART_Layout::DATA, 1,  2> R2T2;
constexpr LPUART3_Reg<&LPUART_Layout::DATA, 1,  1> R1T1;
constexpr LPUART3_Reg<&LPUART_Layout::DATA, 1,  0> R0T0;
}  // namespace DATA

// LPUART Match Address Register
namespace MATCH {
constexpr LPUART3_Reg<&LPUART_Layout::MATCH, 10, 16> MA2;
constexpr LPUART3_Reg<&LPUART_Layout::MATCH, 10,  0> MA1;
}  // namespace MATCH

// LPUART Modem IrDA Register
namespace MODIR {
constexpr LPUART3_Reg<&LPUART_Layout::MODIR, 1, 18> IREN;
constexpr LPUART3_Reg<&LPUART_Layout::MODIR, 2, 16> TNP;
constexpr LPUART3_Reg<&LPUART_Layout::MODIR, 2,  8> RTSWATER;
constexpr LPUART3_Reg<&LPUART_Layout::MODIR, 1,  5> TXCTSSRC;
constexpr LPUART3_Reg<&LPUART_Layout::MODIR, 1,  4> TXCTSC;
constexpr LPUART3_Reg<&LPUART_Layout::MODIR, 1,  3> RXRTSE;
constexpr LPUART3_Reg<&LPUART_Layout::MODIR, 1,  2> TXRTSPOL;
constexpr LPUART3_Reg<&LPUART_Layout::MODIR, 1,  1> TXRTSE;
constexpr LPUART3_Reg<&LPUART_Layout::MODIR, 1,  0> TXCTSE;
}  // namespace MODIR

// LPUART FIFO Register
namespace FIFO {
constexpr uint32_t kW1C  = 0x0003'0000;
constexpr uint32_t kWORZ = 0x0000'c000;

constexpr LPUART3_Reg<regs::constify(&LPUART_Layout::FIFO), 1, 23> TXEMPT;
constexpr LPUART3_Reg<regs::constify(&LPUART_Layout::FIFO), 1, 22> RXEMPT;
constexpr LPUART3_Reg<&LPUART_Layout::FIFO, 1, 17, kW1C> TXOF;
constexpr LPUART3_Reg<&LPUART_Layout::FIFO, 1, 16, kW1C> RXUF;
constexpr LPUART3_Reg<&LPUART_Layout::FIFO, 1, 15, kWORZ | kW1C> TXFLUSH;
constexpr LPUART3_Reg<&LPUART_Layout::FIFO, 1, 14, kWORZ | kW1C> RXFLUSH;
constexpr LPUART3_Reg<&LPUART_Layout::FIFO, 3, 10, (uint32_t{0x7} << 10) | kW1C> RXIDEN;
constexpr LPUART3_Reg<&LPUART_Layout::FIFO, 1,  9, (uint32_t{0x1} <<  9) | kW1C> TXOFE;
constexpr LPUART3_Reg<&LPUART_Layout::FIFO, 1,  8, (uint32_t{0x1} <<  8) | kW1C> RXUFE;
constexpr LPUART3_Reg<&LPUART_Layout::FIFO, 1,  7, (uint32_t{0x1} <<  7) | kW1C> TXFE;
constexpr LPUART3_Reg<regs::constify(&LPUART_Layout::FIFO), 3,  4> TXFIFOSIZE;
constexpr LPUART3_Reg<&LPUART_Layout::FIFO, 1,  3, (uint32_t{0x1} <<  3) | kW1C> RXFE;
constexpr LPUART3_Reg<regs::constify(&LPUART_Layout::FIFO), 3,  0> RXFIFOSIZE;
}  // namespace FIFO

// LPUART Watermark Register
namespace WATER {
constexpr LPUART3_Reg<regs::constify(&LPUART_Layout::WATER), 3, 24> RXCOUNT;
constexpr LPUART3_Reg<&LPUART_Layout::WATER, 2, 16> RXWATER;
constexpr LPUART3_Reg<regs::constify(&LPUART_Layout::WATER), 3,  8> TXCOUNT;
constexpr LPUART3_Reg<&LPUART_Layout::WATER, 2,  0> TXWATER;
}  // namespace WATER

}  // namespace LPUART3

namespace LPUART4 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false>
using LPUART4_Reg =
    regs::Reg32<kLPUART4_base, LPUART_Layout, Member, 0, Bits, Shift,
                AssignMask, WriteOnly>;

// Version ID Register
namespace VERID {
constexpr LPUART4_Reg<&LPUART_Layout::VERID,  8, 24> MAJOR;
constexpr LPUART4_Reg<&LPUART_Layout::VERID,  8, 16> MINOR;
constexpr LPUART4_Reg<&LPUART_Layout::VERID, 16,  0> FEATURE;
}  // namespace VERID

// Parameter Register
namespace PARAM {
constexpr LPUART4_Reg<&LPUART_Layout::PARAM, 8, 8> RXFIFO;
constexpr LPUART4_Reg<&LPUART_Layout::PARAM, 8, 0> TXFIFO;
}  // namespace PARAM

// LPUART Global Register
namespace GLOBAL {
constexpr LPUART4_Reg<&LPUART_Layout::GLOBAL, 1, 1> RST;
}  // namespace GLOBAL

// LPUART Pin Configuration Register
namespace PINCFG {
constexpr LPUART4_Reg<&LPUART_Layout::PINCFG, 2, 0> TRGSEL;
}  // namespace PINCFG

// LPUART Baud Rate Register
namespace BAUD {
constexpr LPUART4_Reg<&LPUART_Layout::BAUD,  1, 31> MAEN1;
constexpr LPUART4_Reg<&LPUART_Layout::BAUD,  1, 30> MAEN2;
constexpr LPUART4_Reg<&LPUART_Layout::BAUD,  1, 29> M10;
constexpr LPUART4_Reg<&LPUART_Layout::BAUD,  5, 24> OSR;
constexpr LPUART4_Reg<&LPUART_Layout::BAUD,  1, 23> TDMAE;
constexpr LPUART4_Reg<&LPUART_Layout::BAUD,  1, 21> RDMAE;
constexpr LPUART4_Reg<&LPUART_Layout::BAUD,  2, 18> MATCFG;
constexpr LPUART4_Reg<&LPUART_Layout::BAUD,  1, 17> BOTHEDGE;
constexpr LPUART4_Reg<&LPUART_Layout::BAUD,  1, 16> RESYNCDIS;
constexpr LPUART4_Reg<&LPUART_Layout::BAUD,  1, 15> LBKDIE;
constexpr LPUART4_Reg<&LPUART_Layout::BAUD,  1, 14> RXEDGIE;
constexpr LPUART4_Reg<&LPUART_Layout::BAUD,  1, 13> SBNS;
constexpr LPUART4_Reg<&LPUART_Layout::BAUD, 13,  0> SBR;
}  // namespace BAUD

// LPUART Status Register
namespace STAT {
constexpr uint32_t kW1C = 0xc01f'c000;

constexpr LPUART4_Reg<&LPUART_Layout::STAT, 1, 31, kW1C> LBKDIF;
constexpr LPUART4_Reg<&LPUART_Layout::STAT, 1, 30, kW1C> RXEDGIF;
constexpr LPUART4_Reg<&LPUART_Layout::STAT, 1, 29, (uint32_t{0x1} << 29) | kW1C> MSBF;
constexpr LPUART4_Reg<&LPUART_Layout::STAT, 1, 28, (uint32_t{0x1} << 28) | kW1C> RXINV;
constexpr LPUART4_Reg<&LPUART_Layout::STAT, 1, 27, (uint32_t{0x1} << 27) | kW1C> RWUID;
constexpr LPUART4_Reg<&LPUART_Layout::STAT, 1, 26, (uint32_t{0x1} << 26) | kW1C> BRK13;
constexpr LPUART4_Reg<&LPUART_Layout::STAT, 1, 25, (uint32_t{0x1} << 25) | kW1C> LBKDE;
constexpr LPUART4_Reg<regs::constify(&LPUART_Layout::STAT), 1, 24> RAF;
constexpr LPUART4_Reg<regs::constify(&LPUART_Layout::STAT), 1, 23> TDRE;
constexpr LPUART4_Reg<regs::constify(&LPUART_Layout::STAT), 1, 22> TC;
constexpr LPUART4_Reg<regs::constify(&LPUART_Layout::STAT), 1, 21> RDRF;
constexpr LPUART4_Reg<&LPUART_Layout::STAT, 1, 20, kW1C> IDLE;
constexpr LPUART4_Reg<&LPUART_Layout::STAT, 1, 19, kW1C> OR;
constexpr LPUART4_Reg<&LPUART_Layout::STAT, 1, 18, kW1C> NF;
constexpr LPUART4_Reg<&LPUART_Layout::STAT, 1, 17, kW1C> FE;
constexpr LPUART4_Reg<&LPUART_Layout::STAT, 1, 16, kW1C> PF;
constexpr LPUART4_Reg<&LPUART_Layout::STAT, 1, 15, kW1C> MA1F;
constexpr LPUART4_Reg<&LPUART_Layout::STAT, 1, 14, kW1C> MA2F;
}  // namespace STAT

// LPUART Control Register
namespace CTRL {
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1, 31> R8T9;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1, 30> R9T8;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1, 29> TXDIR;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1, 28> TXINV;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1, 27> ORIE;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1, 26> NEIE;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1, 25> FEIE;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1, 24> PEIE;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1, 23> TIE;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1, 22> TCIE;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1, 21> RIE;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1, 20> ILIE;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1, 19> TE;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1, 18> RE;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1, 17> RWU;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1, 16> SBK;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1, 15> MA1IE;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1, 14> MA2IE;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1, 11> M7;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 3,  8> IDLECFG;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1,  7> LOOPS;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1,  6> DOZEEN;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1,  5> RSRC;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1,  4> M;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1,  3> WAKE;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1,  2> ILT;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1,  1> PE;
constexpr LPUART4_Reg<&LPUART_Layout::CTRL, 1,  0> PT;
}  // namespace CTRL

// LPUART Data Register
namespace DATA {
constexpr LPUART4_Reg<regs::constify(&LPUART_Layout::DATA), 1, 15> NOISY;
constexpr LPUART4_Reg<regs::constify(&LPUART_Layout::DATA), 1, 14> PARITYE;
constexpr LPUART4_Reg<&LPUART_Layout::DATA, 1, 13> FRETSC;
constexpr LPUART4_Reg<regs::constify(&LPUART_Layout::DATA), 1, 12> RXEMPT;
constexpr LPUART4_Reg<regs::constify(&LPUART_Layout::DATA), 1, 11> IDLINE;
constexpr LPUART4_Reg<&LPUART_Layout::DATA, 1,  9> R9T9;
constexpr LPUART4_Reg<&LPUART_Layout::DATA, 1,  8> R8T8;
constexpr LPUART4_Reg<&LPUART_Layout::DATA, 1,  7> R7T7;
constexpr LPUART4_Reg<&LPUART_Layout::DATA, 1,  6> R6T6;
constexpr LPUART4_Reg<&LPUART_Layout::DATA, 1,  5> R5T5;
constexpr LPUART4_Reg<&LPUART_Layout::DATA, 1,  4> R4T4;
constexpr LPUART4_Reg<&LPUART_Layout::DATA, 1,  3> R3T3;
constexpr LPUART4_Reg<&LPUART_Layout::DATA, 1,  2> R2T2;
constexpr LPUART4_Reg<&LPUART_Layout::DATA, 1,  1> R1T1;
constexpr LPUART4_Reg<&LPUART_Layout::DATA, 1,  0> R0T0;
}  // namespace DATA

// LPUART Match Address Register
namespace MATCH {
constexpr LPUART4_Reg<&LPUART_Layout::MATCH, 10, 16> MA2;
constexpr LPUART4_Reg<&LPUART_Layout::MATCH, 10,  0> MA1;
}  // namespace MATCH

// LPUART Modem IrDA Register
namespace MODIR {
constexpr LPUART4_Reg<&LPUART_Layout::MODIR, 1, 18> IREN;
constexpr LPUART4_Reg<&LPUART_Layout::MODIR, 2, 16> TNP;
constexpr LPUART4_Reg<&LPUART_Layout::MODIR, 2,  8> RTSWATER;
constexpr LPUART4_Reg<&LPUART_Layout::MODIR, 1,  5> TXCTSSRC;
constexpr LPUART4_Reg<&LPUART_Layout::MODIR, 1,  4> TXCTSC;
constexpr LPUART4_Reg<&LPUART_Layout::MODIR, 1,  3> RXRTSE;
constexpr LPUART4_Reg<&LPUART_Layout::MODIR, 1,  2> TXRTSPOL;
constexpr LPUART4_Reg<&LPUART_Layout::MODIR, 1,  1> TXRTSE;
constexpr LPUART4_Reg<&LPUART_Layout::MODIR, 1,  0> TXCTSE;
}  // namespace MODIR

// LPUART FIFO Register
namespace FIFO {
constexpr uint32_t kW1C  = 0x0003'0000;
constexpr uint32_t kWORZ = 0x0000'c000;

constexpr LPUART4_Reg<regs::constify(&LPUART_Layout::FIFO), 1, 23> TXEMPT;
constexpr LPUART4_Reg<regs::constify(&LPUART_Layout::FIFO), 1, 22> RXEMPT;
constexpr LPUART4_Reg<&LPUART_Layout::FIFO, 1, 17, kW1C> TXOF;
constexpr LPUART4_Reg<&LPUART_Layout::FIFO, 1, 16, kW1C> RXUF;
constexpr LPUART4_Reg<&LPUART_Layout::FIFO, 1, 15, kWORZ | kW1C> TXFLUSH;
constexpr LPUART4_Reg<&LPUART_Layout::FIFO, 1, 14, kWORZ | kW1C> RXFLUSH;
constexpr LPUART4_Reg<&LPUART_Layout::FIFO, 3, 10, (uint32_t{0x7} << 10) | kW1C> RXIDEN;
constexpr LPUART4_Reg<&LPUART_Layout::FIFO, 1,  9, (uint32_t{0x1} <<  9) | kW1C> TXOFE;
constexpr LPUART4_Reg<&LPUART_Layout::FIFO, 1,  8, (uint32_t{0x1} <<  8) | kW1C> RXUFE;
constexpr LPUART4_Reg<&LPUART_Layout::FIFO, 1,  7, (uint32_t{0x1} <<  7) | kW1C> TXFE;
constexpr LPUART4_Reg<regs::constify(&LPUART_Layout::FIFO), 3,  4> TXFIFOSIZE;
constexpr LPUART4_Reg<&LPUART_Layout::FIFO, 1,  3, (uint32_t{0x1} <<  3) | kW1C> RXFE;
constexpr LPUART4_Reg<regs::constify(&LPUART_Layout::FIFO), 3,  0> RXFIFOSIZE;
}  // namespace FIFO

// LPUART Watermark Register
namespace WATER {
constexpr LPUART4_Reg<regs::constify(&LPUART_Layout::WATER), 3, 24> RXCOUNT;
constexpr LPUART4_Reg<&LPUART_Layout::WATER, 2, 16> RXWATER;
constexpr LPUART4_Reg<regs::constify(&LPUART_Layout::WATER), 3,  8> TXCOUNT;
constexpr LPUART4_Reg<&LPUART_Layout::WATER, 2,  0> TXWATER;
}  // namespace WATER

}  // namespace LPUART4

namespace LPUART5 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false>
using LPUART5_Reg =
    regs::Reg32<kLPUART5_base, LPUART_Layout, Member, 0, Bits, Shift,
                AssignMask, WriteOnly>;

// Version ID Register
namespace VERID {
constexpr LPUART5_Reg<&LPUART_Layout::VERID,  8, 24> MAJOR;
constexpr LPUART5_Reg<&LPUART_Layout::VERID,  8, 16> MINOR;
constexpr LPUART5_Reg<&LPUART_Layout::VERID, 16,  0> FEATURE;
}  // namespace VERID

// Parameter Register
namespace PARAM {
constexpr LPUART5_Reg<&LPUART_Layout::PARAM, 8, 8> RXFIFO;
constexpr LPUART5_Reg<&LPUART_Layout::PARAM, 8, 0> TXFIFO;
}  // namespace PARAM

// LPUART Global Register
namespace GLOBAL {
constexpr LPUART5_Reg<&LPUART_Layout::GLOBAL, 1, 1> RST;
}  // namespace GLOBAL

// LPUART Pin Configuration Register
namespace PINCFG {
constexpr LPUART5_Reg<&LPUART_Layout::PINCFG, 2, 0> TRGSEL;
}  // namespace PINCFG

// LPUART Baud Rate Register
namespace BAUD {
constexpr LPUART5_Reg<&LPUART_Layout::BAUD,  1, 31> MAEN1;
constexpr LPUART5_Reg<&LPUART_Layout::BAUD,  1, 30> MAEN2;
constexpr LPUART5_Reg<&LPUART_Layout::BAUD,  1, 29> M10;
constexpr LPUART5_Reg<&LPUART_Layout::BAUD,  5, 24> OSR;
constexpr LPUART5_Reg<&LPUART_Layout::BAUD,  1, 23> TDMAE;
constexpr LPUART5_Reg<&LPUART_Layout::BAUD,  1, 21> RDMAE;
constexpr LPUART5_Reg<&LPUART_Layout::BAUD,  2, 18> MATCFG;
constexpr LPUART5_Reg<&LPUART_Layout::BAUD,  1, 17> BOTHEDGE;
constexpr LPUART5_Reg<&LPUART_Layout::BAUD,  1, 16> RESYNCDIS;
constexpr LPUART5_Reg<&LPUART_Layout::BAUD,  1, 15> LBKDIE;
constexpr LPUART5_Reg<&LPUART_Layout::BAUD,  1, 14> RXEDGIE;
constexpr LPUART5_Reg<&LPUART_Layout::BAUD,  1, 13> SBNS;
constexpr LPUART5_Reg<&LPUART_Layout::BAUD, 13,  0> SBR;
}  // namespace BAUD

// LPUART Status Register
namespace STAT {
constexpr uint32_t kW1C = 0xc01f'c000;

constexpr LPUART5_Reg<&LPUART_Layout::STAT, 1, 31, kW1C> LBKDIF;
constexpr LPUART5_Reg<&LPUART_Layout::STAT, 1, 30, kW1C> RXEDGIF;
constexpr LPUART5_Reg<&LPUART_Layout::STAT, 1, 29, (uint32_t{0x1} << 29) | kW1C> MSBF;
constexpr LPUART5_Reg<&LPUART_Layout::STAT, 1, 28, (uint32_t{0x1} << 28) | kW1C> RXINV;
constexpr LPUART5_Reg<&LPUART_Layout::STAT, 1, 27, (uint32_t{0x1} << 27) | kW1C> RWUID;
constexpr LPUART5_Reg<&LPUART_Layout::STAT, 1, 26, (uint32_t{0x1} << 26) | kW1C> BRK13;
constexpr LPUART5_Reg<&LPUART_Layout::STAT, 1, 25, (uint32_t{0x1} << 25) | kW1C> LBKDE;
constexpr LPUART5_Reg<regs::constify(&LPUART_Layout::STAT), 1, 24> RAF;
constexpr LPUART5_Reg<regs::constify(&LPUART_Layout::STAT), 1, 23> TDRE;
constexpr LPUART5_Reg<regs::constify(&LPUART_Layout::STAT), 1, 22> TC;
constexpr LPUART5_Reg<regs::constify(&LPUART_Layout::STAT), 1, 21> RDRF;
constexpr LPUART5_Reg<&LPUART_Layout::STAT, 1, 20, kW1C> IDLE;
constexpr LPUART5_Reg<&LPUART_Layout::STAT, 1, 19, kW1C> OR;
constexpr LPUART5_Reg<&LPUART_Layout::STAT, 1, 18, kW1C> NF;
constexpr LPUART5_Reg<&LPUART_Layout::STAT, 1, 17, kW1C> FE;
constexpr LPUART5_Reg<&LPUART_Layout::STAT, 1, 16, kW1C> PF;
constexpr LPUART5_Reg<&LPUART_Layout::STAT, 1, 15, kW1C> MA1F;
constexpr LPUART5_Reg<&LPUART_Layout::STAT, 1, 14, kW1C> MA2F;
}  // namespace STAT

// LPUART Control Register
namespace CTRL {
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1, 31> R8T9;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1, 30> R9T8;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1, 29> TXDIR;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1, 28> TXINV;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1, 27> ORIE;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1, 26> NEIE;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1, 25> FEIE;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1, 24> PEIE;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1, 23> TIE;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1, 22> TCIE;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1, 21> RIE;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1, 20> ILIE;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1, 19> TE;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1, 18> RE;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1, 17> RWU;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1, 16> SBK;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1, 15> MA1IE;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1, 14> MA2IE;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1, 11> M7;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 3,  8> IDLECFG;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1,  7> LOOPS;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1,  6> DOZEEN;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1,  5> RSRC;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1,  4> M;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1,  3> WAKE;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1,  2> ILT;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1,  1> PE;
constexpr LPUART5_Reg<&LPUART_Layout::CTRL, 1,  0> PT;
}  // namespace CTRL

// LPUART Data Register
namespace DATA {
constexpr LPUART5_Reg<regs::constify(&LPUART_Layout::DATA), 1, 15> NOISY;
constexpr LPUART5_Reg<regs::constify(&LPUART_Layout::DATA), 1, 14> PARITYE;
constexpr LPUART5_Reg<&LPUART_Layout::DATA, 1, 13> FRETSC;
constexpr LPUART5_Reg<regs::constify(&LPUART_Layout::DATA), 1, 12> RXEMPT;
constexpr LPUART5_Reg<regs::constify(&LPUART_Layout::DATA), 1, 11> IDLINE;
constexpr LPUART5_Reg<&LPUART_Layout::DATA, 1,  9> R9T9;
constexpr LPUART5_Reg<&LPUART_Layout::DATA, 1,  8> R8T8;
constexpr LPUART5_Reg<&LPUART_Layout::DATA, 1,  7> R7T7;
constexpr LPUART5_Reg<&LPUART_Layout::DATA, 1,  6> R6T6;
constexpr LPUART5_Reg<&LPUART_Layout::DATA, 1,  5> R5T5;
constexpr LPUART5_Reg<&LPUART_Layout::DATA, 1,  4> R4T4;
constexpr LPUART5_Reg<&LPUART_Layout::DATA, 1,  3> R3T3;
constexpr LPUART5_Reg<&LPUART_Layout::DATA, 1,  2> R2T2;
constexpr LPUART5_Reg<&LPUART_Layout::DATA, 1,  1> R1T1;
constexpr LPUART5_Reg<&LPUART_Layout::DATA, 1,  0> R0T0;
}  // namespace DATA

// LPUART Match Address Register
namespace MATCH {
constexpr LPUART5_Reg<&LPUART_Layout::MATCH, 10, 16> MA2;
constexpr LPUART5_Reg<&LPUART_Layout::MATCH, 10,  0> MA1;
}  // namespace MATCH

// LPUART Modem IrDA Register
namespace MODIR {
constexpr LPUART5_Reg<&LPUART_Layout::MODIR, 1, 18> IREN;
constexpr LPUART5_Reg<&LPUART_Layout::MODIR, 2, 16> TNP;
constexpr LPUART5_Reg<&LPUART_Layout::MODIR, 2,  8> RTSWATER;
constexpr LPUART5_Reg<&LPUART_Layout::MODIR, 1,  5> TXCTSSRC;
constexpr LPUART5_Reg<&LPUART_Layout::MODIR, 1,  4> TXCTSC;
constexpr LPUART5_Reg<&LPUART_Layout::MODIR, 1,  3> RXRTSE;
constexpr LPUART5_Reg<&LPUART_Layout::MODIR, 1,  2> TXRTSPOL;
constexpr LPUART5_Reg<&LPUART_Layout::MODIR, 1,  1> TXRTSE;
constexpr LPUART5_Reg<&LPUART_Layout::MODIR, 1,  0> TXCTSE;
}  // namespace MODIR

// LPUART FIFO Register
namespace FIFO {
constexpr uint32_t kW1C  = 0x0003'0000;
constexpr uint32_t kWORZ = 0x0000'c000;

constexpr LPUART5_Reg<regs::constify(&LPUART_Layout::FIFO), 1, 23> TXEMPT;
constexpr LPUART5_Reg<regs::constify(&LPUART_Layout::FIFO), 1, 22> RXEMPT;
constexpr LPUART5_Reg<&LPUART_Layout::FIFO, 1, 17, kW1C> TXOF;
constexpr LPUART5_Reg<&LPUART_Layout::FIFO, 1, 16, kW1C> RXUF;
constexpr LPUART5_Reg<&LPUART_Layout::FIFO, 1, 15, kWORZ | kW1C> TXFLUSH;
constexpr LPUART5_Reg<&LPUART_Layout::FIFO, 1, 14, kWORZ | kW1C> RXFLUSH;
constexpr LPUART5_Reg<&LPUART_Layout::FIFO, 3, 10, (uint32_t{0x7} << 10) | kW1C> RXIDEN;
constexpr LPUART5_Reg<&LPUART_Layout::FIFO, 1,  9, (uint32_t{0x1} <<  9) | kW1C> TXOFE;
constexpr LPUART5_Reg<&LPUART_Layout::FIFO, 1,  8, (uint32_t{0x1} <<  8) | kW1C> RXUFE;
constexpr LPUART5_Reg<&LPUART_Layout::FIFO, 1,  7, (uint32_t{0x1} <<  7) | kW1C> TXFE;
constexpr LPUART5_Reg<regs::constify(&LPUART_Layout::FIFO), 3,  4> TXFIFOSIZE;
constexpr LPUART5_Reg<&LPUART_Layout::FIFO, 1,  3, (uint32_t{0x1} <<  3) | kW1C> RXFE;
constexpr LPUART5_Reg<regs::constify(&LPUART_Layout::FIFO), 3,  0> RXFIFOSIZE;
}  // namespace FIFO

// LPUART Watermark Register
namespace WATER {
constexpr LPUART5_Reg<regs::constify(&LPUART_Layout::WATER), 3, 24> RXCOUNT;
constexpr LPUART5_Reg<&LPUART_Layout::WATER, 2, 16> RXWATER;
constexpr LPUART5_Reg<regs::constify(&LPUART_Layout::WATER), 3,  8> TXCOUNT;
constexpr LPUART5_Reg<&LPUART_Layout::WATER, 2,  0> TXWATER;
}  // namespace WATER

}  // namespace LPUART5

namespace LPUART6 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false>
using LPUART6_Reg =
    regs::Reg32<kLPUART6_base, LPUART_Layout, Member, 0, Bits, Shift,
                AssignMask, WriteOnly>;

// Version ID Register
namespace VERID {
constexpr LPUART6_Reg<&LPUART_Layout::VERID,  8, 24> MAJOR;
constexpr LPUART6_Reg<&LPUART_Layout::VERID,  8, 16> MINOR;
constexpr LPUART6_Reg<&LPUART_Layout::VERID, 16,  0> FEATURE;
}  // namespace VERID

// Parameter Register
namespace PARAM {
constexpr LPUART6_Reg<&LPUART_Layout::PARAM, 8, 8> RXFIFO;
constexpr LPUART6_Reg<&LPUART_Layout::PARAM, 8, 0> TXFIFO;
}  // namespace PARAM

// LPUART Global Register
namespace GLOBAL {
constexpr LPUART6_Reg<&LPUART_Layout::GLOBAL, 1, 1> RST;
}  // namespace GLOBAL

// LPUART Pin Configuration Register
namespace PINCFG {
constexpr LPUART6_Reg<&LPUART_Layout::PINCFG, 2, 0> TRGSEL;
}  // namespace PINCFG

// LPUART Baud Rate Register
namespace BAUD {
constexpr LPUART6_Reg<&LPUART_Layout::BAUD,  1, 31> MAEN1;
constexpr LPUART6_Reg<&LPUART_Layout::BAUD,  1, 30> MAEN2;
constexpr LPUART6_Reg<&LPUART_Layout::BAUD,  1, 29> M10;
constexpr LPUART6_Reg<&LPUART_Layout::BAUD,  5, 24> OSR;
constexpr LPUART6_Reg<&LPUART_Layout::BAUD,  1, 23> TDMAE;
constexpr LPUART6_Reg<&LPUART_Layout::BAUD,  1, 21> RDMAE;
constexpr LPUART6_Reg<&LPUART_Layout::BAUD,  2, 18> MATCFG;
constexpr LPUART6_Reg<&LPUART_Layout::BAUD,  1, 17> BOTHEDGE;
constexpr LPUART6_Reg<&LPUART_Layout::BAUD,  1, 16> RESYNCDIS;
constexpr LPUART6_Reg<&LPUART_Layout::BAUD,  1, 15> LBKDIE;
constexpr LPUART6_Reg<&LPUART_Layout::BAUD,  1, 14> RXEDGIE;
constexpr LPUART6_Reg<&LPUART_Layout::BAUD,  1, 13> SBNS;
constexpr LPUART6_Reg<&LPUART_Layout::BAUD, 13,  0> SBR;
}  // namespace BAUD

// LPUART Status Register
namespace STAT {
constexpr uint32_t kW1C = 0xc01f'c000;

constexpr LPUART6_Reg<&LPUART_Layout::STAT, 1, 31, kW1C> LBKDIF;
constexpr LPUART6_Reg<&LPUART_Layout::STAT, 1, 30, kW1C> RXEDGIF;
constexpr LPUART6_Reg<&LPUART_Layout::STAT, 1, 29, (uint32_t{0x1} << 29) | kW1C> MSBF;
constexpr LPUART6_Reg<&LPUART_Layout::STAT, 1, 28, (uint32_t{0x1} << 28) | kW1C> RXINV;
constexpr LPUART6_Reg<&LPUART_Layout::STAT, 1, 27, (uint32_t{0x1} << 27) | kW1C> RWUID;
constexpr LPUART6_Reg<&LPUART_Layout::STAT, 1, 26, (uint32_t{0x1} << 26) | kW1C> BRK13;
constexpr LPUART6_Reg<&LPUART_Layout::STAT, 1, 25, (uint32_t{0x1} << 25) | kW1C> LBKDE;
constexpr LPUART6_Reg<regs::constify(&LPUART_Layout::STAT), 1, 24> RAF;
constexpr LPUART6_Reg<regs::constify(&LPUART_Layout::STAT), 1, 23> TDRE;
constexpr LPUART6_Reg<regs::constify(&LPUART_Layout::STAT), 1, 22> TC;
constexpr LPUART6_Reg<regs::constify(&LPUART_Layout::STAT), 1, 21> RDRF;
constexpr LPUART6_Reg<&LPUART_Layout::STAT, 1, 20, kW1C> IDLE;
constexpr LPUART6_Reg<&LPUART_Layout::STAT, 1, 19, kW1C> OR;
constexpr LPUART6_Reg<&LPUART_Layout::STAT, 1, 18, kW1C> NF;
constexpr LPUART6_Reg<&LPUART_Layout::STAT, 1, 17, kW1C> FE;
constexpr LPUART6_Reg<&LPUART_Layout::STAT, 1, 16, kW1C> PF;
constexpr LPUART6_Reg<&LPUART_Layout::STAT, 1, 15, kW1C> MA1F;
constexpr LPUART6_Reg<&LPUART_Layout::STAT, 1, 14, kW1C> MA2F;
}  // namespace STAT

// LPUART Control Register
namespace CTRL {
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1, 31> R8T9;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1, 30> R9T8;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1, 29> TXDIR;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1, 28> TXINV;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1, 27> ORIE;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1, 26> NEIE;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1, 25> FEIE;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1, 24> PEIE;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1, 23> TIE;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1, 22> TCIE;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1, 21> RIE;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1, 20> ILIE;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1, 19> TE;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1, 18> RE;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1, 17> RWU;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1, 16> SBK;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1, 15> MA1IE;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1, 14> MA2IE;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1, 11> M7;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 3,  8> IDLECFG;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1,  7> LOOPS;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1,  6> DOZEEN;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1,  5> RSRC;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1,  4> M;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1,  3> WAKE;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1,  2> ILT;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1,  1> PE;
constexpr LPUART6_Reg<&LPUART_Layout::CTRL, 1,  0> PT;
}  // namespace CTRL

// LPUART Data Register
namespace DATA {
constexpr LPUART6_Reg<regs::constify(&LPUART_Layout::DATA), 1, 15> NOISY;
constexpr LPUART6_Reg<regs::constify(&LPUART_Layout::DATA), 1, 14> PARITYE;
constexpr LPUART6_Reg<&LPUART_Layout::DATA, 1, 13> FRETSC;
constexpr LPUART6_Reg<regs::constify(&LPUART_Layout::DATA), 1, 12> RXEMPT;
constexpr LPUART6_Reg<regs::constify(&LPUART_Layout::DATA), 1, 11> IDLINE;
constexpr LPUART6_Reg<&LPUART_Layout::DATA, 1,  9> R9T9;
constexpr LPUART6_Reg<&LPUART_Layout::DATA, 1,  8> R8T8;
constexpr LPUART6_Reg<&LPUART_Layout::DATA, 1,  7> R7T7;
constexpr LPUART6_Reg<&LPUART_Layout::DATA, 1,  6> R6T6;
constexpr LPUART6_Reg<&LPUART_Layout::DATA, 1,  5> R5T5;
constexpr LPUART6_Reg<&LPUART_Layout::DATA, 1,  4> R4T4;
constexpr LPUART6_Reg<&LPUART_Layout::DATA, 1,  3> R3T3;
constexpr LPUART6_Reg<&LPUART_Layout::DATA, 1,  2> R2T2;
constexpr LPUART6_Reg<&LPUART_Layout::DATA, 1,  1> R1T1;
constexpr LPUART6_Reg<&LPUART_Layout::DATA, 1,  0> R0T0;
}  // namespace DATA

// LPUART Match Address Register
namespace MATCH {
constexpr LPUART6_Reg<&LPUART_Layout::MATCH, 10, 16> MA2;
constexpr LPUART6_Reg<&LPUART_Layout::MATCH, 10,  0> MA1;
}  // namespace MATCH

// LPUART Modem IrDA Register
namespace MODIR {
constexpr LPUART6_Reg<&LPUART_Layout::MODIR, 1, 18> IREN;
constexpr LPUART6_Reg<&LPUART_Layout::MODIR, 2, 16> TNP;
constexpr LPUART6_Reg<&LPUART_Layout::MODIR, 2,  8> RTSWATER;
constexpr LPUART6_Reg<&LPUART_Layout::MODIR, 1,  5> TXCTSSRC;
constexpr LPUART6_Reg<&LPUART_Layout::MODIR, 1,  4> TXCTSC;
constexpr LPUART6_Reg<&LPUART_Layout::MODIR, 1,  3> RXRTSE;
constexpr LPUART6_Reg<&LPUART_Layout::MODIR, 1,  2> TXRTSPOL;
constexpr LPUART6_Reg<&LPUART_Layout::MODIR, 1,  1> TXRTSE;
constexpr LPUART6_Reg<&LPUART_Layout::MODIR, 1,  0> TXCTSE;
}  // namespace MODIR

// LPUART FIFO Register
namespace FIFO {
constexpr uint32_t kW1C  = 0x0003'0000;
constexpr uint32_t kWORZ = 0x0000'c000;

constexpr LPUART6_Reg<regs::constify(&LPUART_Layout::FIFO), 1, 23> TXEMPT;
constexpr LPUART6_Reg<regs::constify(&LPUART_Layout::FIFO), 1, 22> RXEMPT;
constexpr LPUART6_Reg<&LPUART_Layout::FIFO, 1, 17, kW1C> TXOF;
constexpr LPUART6_Reg<&LPUART_Layout::FIFO, 1, 16, kW1C> RXUF;
constexpr LPUART6_Reg<&LPUART_Layout::FIFO, 1, 15, kWORZ | kW1C> TXFLUSH;
constexpr LPUART6_Reg<&LPUART_Layout::FIFO, 1, 14, kWORZ | kW1C> RXFLUSH;
constexpr LPUART6_Reg<&LPUART_Layout::FIFO, 3, 10, (uint32_t{0x7} << 10) | kW1C> RXIDEN;
constexpr LPUART6_Reg<&LPUART_Layout::FIFO, 1,  9, (uint32_t{0x1} <<  9) | kW1C> TXOFE;
constexpr LPUART6_Reg<&LPUART_Layout::FIFO, 1,  8, (uint32_t{0x1} <<  8) | kW1C> RXUFE;
constexpr LPUART6_Reg<&LPUART_Layout::FIFO, 1,  7, (uint32_t{0x1} <<  7) | kW1C> TXFE;
constexpr LPUART6_Reg<regs::constify(&LPUART_Layout::FIFO), 3,  4> TXFIFOSIZE;
constexpr LPUART6_Reg<&LPUART_Layout::FIFO, 1,  3, (uint32_t{0x1} <<  3) | kW1C> RXFE;
constexpr LPUART6_Reg<regs::constify(&LPUART_Layout::FIFO), 3,  0> RXFIFOSIZE;
}  // namespace FIFO

// LPUART Watermark Register
namespace WATER {
constexpr LPUART6_Reg<regs::constify(&LPUART_Layout::WATER), 3, 24> RXCOUNT;
constexpr LPUART6_Reg<&LPUART_Layout::WATER, 2, 16> RXWATER;
constexpr LPUART6_Reg<regs::constify(&LPUART_Layout::WATER), 3,  8> TXCOUNT;
constexpr LPUART6_Reg<&LPUART_Layout::WATER, 2,  0> TXWATER;
}  // namespace WATER

}  // namespace LPUART6

namespace LPUART7 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false>
using LPUART7_Reg =
    regs::Reg32<kLPUART7_base, LPUART_Layout, Member, 0, Bits, Shift,
                AssignMask, WriteOnly>;

// Version ID Register
namespace VERID {
constexpr LPUART7_Reg<&LPUART_Layout::VERID,  8, 24> MAJOR;
constexpr LPUART7_Reg<&LPUART_Layout::VERID,  8, 16> MINOR;
constexpr LPUART7_Reg<&LPUART_Layout::VERID, 16,  0> FEATURE;
}  // namespace VERID

// Parameter Register
namespace PARAM {
constexpr LPUART7_Reg<&LPUART_Layout::PARAM, 8, 8> RXFIFO;
constexpr LPUART7_Reg<&LPUART_Layout::PARAM, 8, 0> TXFIFO;
}  // namespace PARAM

// LPUART Global Register
namespace GLOBAL {
constexpr LPUART7_Reg<&LPUART_Layout::GLOBAL, 1, 1> RST;
}  // namespace GLOBAL

// LPUART Pin Configuration Register
namespace PINCFG {
constexpr LPUART7_Reg<&LPUART_Layout::PINCFG, 2, 0> TRGSEL;
}  // namespace PINCFG

// LPUART Baud Rate Register
namespace BAUD {
constexpr LPUART7_Reg<&LPUART_Layout::BAUD,  1, 31> MAEN1;
constexpr LPUART7_Reg<&LPUART_Layout::BAUD,  1, 30> MAEN2;
constexpr LPUART7_Reg<&LPUART_Layout::BAUD,  1, 29> M10;
constexpr LPUART7_Reg<&LPUART_Layout::BAUD,  5, 24> OSR;
constexpr LPUART7_Reg<&LPUART_Layout::BAUD,  1, 23> TDMAE;
constexpr LPUART7_Reg<&LPUART_Layout::BAUD,  1, 21> RDMAE;
constexpr LPUART7_Reg<&LPUART_Layout::BAUD,  2, 18> MATCFG;
constexpr LPUART7_Reg<&LPUART_Layout::BAUD,  1, 17> BOTHEDGE;
constexpr LPUART7_Reg<&LPUART_Layout::BAUD,  1, 16> RESYNCDIS;
constexpr LPUART7_Reg<&LPUART_Layout::BAUD,  1, 15> LBKDIE;
constexpr LPUART7_Reg<&LPUART_Layout::BAUD,  1, 14> RXEDGIE;
constexpr LPUART7_Reg<&LPUART_Layout::BAUD,  1, 13> SBNS;
constexpr LPUART7_Reg<&LPUART_Layout::BAUD, 13,  0> SBR;
}  // namespace BAUD

// LPUART Status Register
namespace STAT {
constexpr uint32_t kW1C = 0xc01f'c000;

constexpr LPUART7_Reg<&LPUART_Layout::STAT, 1, 31, kW1C> LBKDIF;
constexpr LPUART7_Reg<&LPUART_Layout::STAT, 1, 30, kW1C> RXEDGIF;
constexpr LPUART7_Reg<&LPUART_Layout::STAT, 1, 29, (uint32_t{0x1} << 29) | kW1C> MSBF;
constexpr LPUART7_Reg<&LPUART_Layout::STAT, 1, 28, (uint32_t{0x1} << 28) | kW1C> RXINV;
constexpr LPUART7_Reg<&LPUART_Layout::STAT, 1, 27, (uint32_t{0x1} << 27) | kW1C> RWUID;
constexpr LPUART7_Reg<&LPUART_Layout::STAT, 1, 26, (uint32_t{0x1} << 26) | kW1C> BRK13;
constexpr LPUART7_Reg<&LPUART_Layout::STAT, 1, 25, (uint32_t{0x1} << 25) | kW1C> LBKDE;
constexpr LPUART7_Reg<regs::constify(&LPUART_Layout::STAT), 1, 24> RAF;
constexpr LPUART7_Reg<regs::constify(&LPUART_Layout::STAT), 1, 23> TDRE;
constexpr LPUART7_Reg<regs::constify(&LPUART_Layout::STAT), 1, 22> TC;
constexpr LPUART7_Reg<regs::constify(&LPUART_Layout::STAT), 1, 21> RDRF;
constexpr LPUART7_Reg<&LPUART_Layout::STAT, 1, 20, kW1C> IDLE;
constexpr LPUART7_Reg<&LPUART_Layout::STAT, 1, 19, kW1C> OR;
constexpr LPUART7_Reg<&LPUART_Layout::STAT, 1, 18, kW1C> NF;
constexpr LPUART7_Reg<&LPUART_Layout::STAT, 1, 17, kW1C> FE;
constexpr LPUART7_Reg<&LPUART_Layout::STAT, 1, 16, kW1C> PF;
constexpr LPUART7_Reg<&LPUART_Layout::STAT, 1, 15, kW1C> MA1F;
constexpr LPUART7_Reg<&LPUART_Layout::STAT, 1, 14, kW1C> MA2F;
}  // namespace STAT

// LPUART Control Register
namespace CTRL {
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1, 31> R8T9;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1, 30> R9T8;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1, 29> TXDIR;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1, 28> TXINV;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1, 27> ORIE;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1, 26> NEIE;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1, 25> FEIE;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1, 24> PEIE;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1, 23> TIE;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1, 22> TCIE;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1, 21> RIE;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1, 20> ILIE;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1, 19> TE;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1, 18> RE;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1, 17> RWU;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1, 16> SBK;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1, 15> MA1IE;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1, 14> MA2IE;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1, 11> M7;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 3,  8> IDLECFG;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1,  7> LOOPS;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1,  6> DOZEEN;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1,  5> RSRC;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1,  4> M;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1,  3> WAKE;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1,  2> ILT;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1,  1> PE;
constexpr LPUART7_Reg<&LPUART_Layout::CTRL, 1,  0> PT;
}  // namespace CTRL

// LPUART Data Register
namespace DATA {
constexpr LPUART7_Reg<regs::constify(&LPUART_Layout::DATA), 1, 15> NOISY;
constexpr LPUART7_Reg<regs::constify(&LPUART_Layout::DATA), 1, 14> PARITYE;
constexpr LPUART7_Reg<&LPUART_Layout::DATA, 1, 13> FRETSC;
constexpr LPUART7_Reg<regs::constify(&LPUART_Layout::DATA), 1, 12> RXEMPT;
constexpr LPUART7_Reg<regs::constify(&LPUART_Layout::DATA), 1, 11> IDLINE;
constexpr LPUART7_Reg<&LPUART_Layout::DATA, 1,  9> R9T9;
constexpr LPUART7_Reg<&LPUART_Layout::DATA, 1,  8> R8T8;
constexpr LPUART7_Reg<&LPUART_Layout::DATA, 1,  7> R7T7;
constexpr LPUART7_Reg<&LPUART_Layout::DATA, 1,  6> R6T6;
constexpr LPUART7_Reg<&LPUART_Layout::DATA, 1,  5> R5T5;
constexpr LPUART7_Reg<&LPUART_Layout::DATA, 1,  4> R4T4;
constexpr LPUART7_Reg<&LPUART_Layout::DATA, 1,  3> R3T3;
constexpr LPUART7_Reg<&LPUART_Layout::DATA, 1,  2> R2T2;
constexpr LPUART7_Reg<&LPUART_Layout::DATA, 1,  1> R1T1;
constexpr LPUART7_Reg<&LPUART_Layout::DATA, 1,  0> R0T0;
}  // namespace DATA

// LPUART Match Address Register
namespace MATCH {
constexpr LPUART7_Reg<&LPUART_Layout::MATCH, 10, 16> MA2;
constexpr LPUART7_Reg<&LPUART_Layout::MATCH, 10,  0> MA1;
}  // namespace MATCH

// LPUART Modem IrDA Register
namespace MODIR {
constexpr LPUART7_Reg<&LPUART_Layout::MODIR, 1, 18> IREN;
constexpr LPUART7_Reg<&LPUART_Layout::MODIR, 2, 16> TNP;
constexpr LPUART7_Reg<&LPUART_Layout::MODIR, 2,  8> RTSWATER;
constexpr LPUART7_Reg<&LPUART_Layout::MODIR, 1,  5> TXCTSSRC;
constexpr LPUART7_Reg<&LPUART_Layout::MODIR, 1,  4> TXCTSC;
constexpr LPUART7_Reg<&LPUART_Layout::MODIR, 1,  3> RXRTSE;
constexpr LPUART7_Reg<&LPUART_Layout::MODIR, 1,  2> TXRTSPOL;
constexpr LPUART7_Reg<&LPUART_Layout::MODIR, 1,  1> TXRTSE;
constexpr LPUART7_Reg<&LPUART_Layout::MODIR, 1,  0> TXCTSE;
}  // namespace MODIR

// LPUART FIFO Register
namespace FIFO {
constexpr uint32_t kW1C  = 0x0003'0000;
constexpr uint32_t kWORZ = 0x0000'c000;

constexpr LPUART7_Reg<regs::constify(&LPUART_Layout::FIFO), 1, 23> TXEMPT;
constexpr LPUART7_Reg<regs::constify(&LPUART_Layout::FIFO), 1, 22> RXEMPT;
constexpr LPUART7_Reg<&LPUART_Layout::FIFO, 1, 17, kW1C> TXOF;
constexpr LPUART7_Reg<&LPUART_Layout::FIFO, 1, 16, kW1C> RXUF;
constexpr LPUART7_Reg<&LPUART_Layout::FIFO, 1, 15, kWORZ | kW1C> TXFLUSH;
constexpr LPUART7_Reg<&LPUART_Layout::FIFO, 1, 14, kWORZ | kW1C> RXFLUSH;
constexpr LPUART7_Reg<&LPUART_Layout::FIFO, 3, 10, (uint32_t{0x7} << 10) | kW1C> RXIDEN;
constexpr LPUART7_Reg<&LPUART_Layout::FIFO, 1,  9, (uint32_t{0x1} <<  9) | kW1C> TXOFE;
constexpr LPUART7_Reg<&LPUART_Layout::FIFO, 1,  8, (uint32_t{0x1} <<  8) | kW1C> RXUFE;
constexpr LPUART7_Reg<&LPUART_Layout::FIFO, 1,  7, (uint32_t{0x1} <<  7) | kW1C> TXFE;
constexpr LPUART7_Reg<regs::constify(&LPUART_Layout::FIFO), 3,  4> TXFIFOSIZE;
constexpr LPUART7_Reg<&LPUART_Layout::FIFO, 1,  3, (uint32_t{0x1} <<  3) | kW1C> RXFE;
constexpr LPUART7_Reg<regs::constify(&LPUART_Layout::FIFO), 3,  0> RXFIFOSIZE;
}  // namespace FIFO

// LPUART Watermark Register
namespace WATER {
constexpr LPUART7_Reg<regs::constify(&LPUART_Layout::WATER), 3, 24> RXCOUNT;
constexpr LPUART7_Reg<&LPUART_Layout::WATER, 2, 16> RXWATER;
constexpr LPUART7_Reg<regs::constify(&LPUART_Layout::WATER), 3,  8> TXCOUNT;
constexpr LPUART7_Reg<&LPUART_Layout::WATER, 2,  0> TXWATER;
}  // namespace WATER

}  // namespace LPUART7

namespace LPUART8 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask<uint32_t, Bits, Shift>(),
          bool WriteOnly = false>
using LPUART8_Reg =
    regs::Reg32<kLPUART8_base, LPUART_Layout, Member, 0, Bits, Shift,
                AssignMask, WriteOnly>;

// Version ID Register
namespace VERID {
constexpr LPUART8_Reg<&LPUART_Layout::VERID,  8, 24> MAJOR;
constexpr LPUART8_Reg<&LPUART_Layout::VERID,  8, 16> MINOR;
constexpr LPUART8_Reg<&LPUART_Layout::VERID, 16,  0> FEATURE;
}  // namespace VERID

// Parameter Register
namespace PARAM {
constexpr LPUART8_Reg<&LPUART_Layout::PARAM, 8, 8> RXFIFO;
constexpr LPUART8_Reg<&LPUART_Layout::PARAM, 8, 0> TXFIFO;
}  // namespace PARAM

// LPUART Global Register
namespace GLOBAL {
constexpr LPUART8_Reg<&LPUART_Layout::GLOBAL, 1, 1> RST;
}  // namespace GLOBAL

// LPUART Pin Configuration Register
namespace PINCFG {
constexpr LPUART8_Reg<&LPUART_Layout::PINCFG, 2, 0> TRGSEL;
}  // namespace PINCFG

// LPUART Baud Rate Register
namespace BAUD {
constexpr LPUART8_Reg<&LPUART_Layout::BAUD,  1, 31> MAEN1;
constexpr LPUART8_Reg<&LPUART_Layout::BAUD,  1, 30> MAEN2;
constexpr LPUART8_Reg<&LPUART_Layout::BAUD,  1, 29> M10;
constexpr LPUART8_Reg<&LPUART_Layout::BAUD,  5, 24> OSR;
constexpr LPUART8_Reg<&LPUART_Layout::BAUD,  1, 23> TDMAE;
constexpr LPUART8_Reg<&LPUART_Layout::BAUD,  1, 21> RDMAE;
constexpr LPUART8_Reg<&LPUART_Layout::BAUD,  2, 18> MATCFG;
constexpr LPUART8_Reg<&LPUART_Layout::BAUD,  1, 17> BOTHEDGE;
constexpr LPUART8_Reg<&LPUART_Layout::BAUD,  1, 16> RESYNCDIS;
constexpr LPUART8_Reg<&LPUART_Layout::BAUD,  1, 15> LBKDIE;
constexpr LPUART8_Reg<&LPUART_Layout::BAUD,  1, 14> RXEDGIE;
constexpr LPUART8_Reg<&LPUART_Layout::BAUD,  1, 13> SBNS;
constexpr LPUART8_Reg<&LPUART_Layout::BAUD, 13,  0> SBR;
}  // namespace BAUD

// LPUART Status Register
namespace STAT {
constexpr uint32_t kW1C = 0xc01f'c000;

constexpr LPUART8_Reg<&LPUART_Layout::STAT, 1, 31, kW1C> LBKDIF;
constexpr LPUART8_Reg<&LPUART_Layout::STAT, 1, 30, kW1C> RXEDGIF;
constexpr LPUART8_Reg<&LPUART_Layout::STAT, 1, 29, (uint32_t{0x1} << 29) | kW1C> MSBF;
constexpr LPUART8_Reg<&LPUART_Layout::STAT, 1, 28, (uint32_t{0x1} << 28) | kW1C> RXINV;
constexpr LPUART8_Reg<&LPUART_Layout::STAT, 1, 27, (uint32_t{0x1} << 27) | kW1C> RWUID;
constexpr LPUART8_Reg<&LPUART_Layout::STAT, 1, 26, (uint32_t{0x1} << 26) | kW1C> BRK13;
constexpr LPUART8_Reg<&LPUART_Layout::STAT, 1, 25, (uint32_t{0x1} << 25) | kW1C> LBKDE;
constexpr LPUART8_Reg<regs::constify(&LPUART_Layout::STAT), 1, 24> RAF;
constexpr LPUART8_Reg<regs::constify(&LPUART_Layout::STAT), 1, 23> TDRE;
constexpr LPUART8_Reg<regs::constify(&LPUART_Layout::STAT), 1, 22> TC;
constexpr LPUART8_Reg<regs::constify(&LPUART_Layout::STAT), 1, 21> RDRF;
constexpr LPUART8_Reg<&LPUART_Layout::STAT, 1, 20, kW1C> IDLE;
constexpr LPUART8_Reg<&LPUART_Layout::STAT, 1, 19, kW1C> OR;
constexpr LPUART8_Reg<&LPUART_Layout::STAT, 1, 18, kW1C> NF;
constexpr LPUART8_Reg<&LPUART_Layout::STAT, 1, 17, kW1C> FE;
constexpr LPUART8_Reg<&LPUART_Layout::STAT, 1, 16, kW1C> PF;
constexpr LPUART8_Reg<&LPUART_Layout::STAT, 1, 15, kW1C> MA1F;
constexpr LPUART8_Reg<&LPUART_Layout::STAT, 1, 14, kW1C> MA2F;
}  // namespace STAT

// LPUART Control Register
namespace CTRL {
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1, 31> R8T9;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1, 30> R9T8;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1, 29> TXDIR;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1, 28> TXINV;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1, 27> ORIE;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1, 26> NEIE;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1, 25> FEIE;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1, 24> PEIE;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1, 23> TIE;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1, 22> TCIE;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1, 21> RIE;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1, 20> ILIE;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1, 19> TE;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1, 18> RE;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1, 17> RWU;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1, 16> SBK;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1, 15> MA1IE;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1, 14> MA2IE;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1, 11> M7;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 3,  8> IDLECFG;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1,  7> LOOPS;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1,  6> DOZEEN;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1,  5> RSRC;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1,  4> M;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1,  3> WAKE;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1,  2> ILT;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1,  1> PE;
constexpr LPUART8_Reg<&LPUART_Layout::CTRL, 1,  0> PT;
}  // namespace CTRL

// LPUART Data Register
namespace DATA {
constexpr LPUART8_Reg<regs::constify(&LPUART_Layout::DATA), 1, 15> NOISY;
constexpr LPUART8_Reg<regs::constify(&LPUART_Layout::DATA), 1, 14> PARITYE;
constexpr LPUART8_Reg<&LPUART_Layout::DATA, 1, 13> FRETSC;
constexpr LPUART8_Reg<regs::constify(&LPUART_Layout::DATA), 1, 12> RXEMPT;
constexpr LPUART8_Reg<regs::constify(&LPUART_Layout::DATA), 1, 11> IDLINE;
constexpr LPUART8_Reg<&LPUART_Layout::DATA, 1,  9> R9T9;
constexpr LPUART8_Reg<&LPUART_Layout::DATA, 1,  8> R8T8;
constexpr LPUART8_Reg<&LPUART_Layout::DATA, 1,  7> R7T7;
constexpr LPUART8_Reg<&LPUART_Layout::DATA, 1,  6> R6T6;
constexpr LPUART8_Reg<&LPUART_Layout::DATA, 1,  5> R5T5;
constexpr LPUART8_Reg<&LPUART_Layout::DATA, 1,  4> R4T4;
constexpr LPUART8_Reg<&LPUART_Layout::DATA, 1,  3> R3T3;
constexpr LPUART8_Reg<&LPUART_Layout::DATA, 1,  2> R2T2;
constexpr LPUART8_Reg<&LPUART_Layout::DATA, 1,  1> R1T1;
constexpr LPUART8_Reg<&LPUART_Layout::DATA, 1,  0> R0T0;
}  // namespace DATA

// LPUART Match Address Register
namespace MATCH {
constexpr LPUART8_Reg<&LPUART_Layout::MATCH, 10, 16> MA2;
constexpr LPUART8_Reg<&LPUART_Layout::MATCH, 10,  0> MA1;
}  // namespace MATCH

// LPUART Modem IrDA Register
namespace MODIR {
constexpr LPUART8_Reg<&LPUART_Layout::MODIR, 1, 18> IREN;
constexpr LPUART8_Reg<&LPUART_Layout::MODIR, 2, 16> TNP;
constexpr LPUART8_Reg<&LPUART_Layout::MODIR, 2,  8> RTSWATER;
constexpr LPUART8_Reg<&LPUART_Layout::MODIR, 1,  5> TXCTSSRC;
constexpr LPUART8_Reg<&LPUART_Layout::MODIR, 1,  4> TXCTSC;
constexpr LPUART8_Reg<&LPUART_Layout::MODIR, 1,  3> RXRTSE;
constexpr LPUART8_Reg<&LPUART_Layout::MODIR, 1,  2> TXRTSPOL;
constexpr LPUART8_Reg<&LPUART_Layout::MODIR, 1,  1> TXRTSE;
constexpr LPUART8_Reg<&LPUART_Layout::MODIR, 1,  0> TXCTSE;
}  // namespace MODIR

// LPUART FIFO Register
namespace FIFO {
constexpr uint32_t kW1C  = 0x0003'0000;
constexpr uint32_t kWORZ = 0x0000'c000;

constexpr LPUART8_Reg<regs::constify(&LPUART_Layout::FIFO), 1, 23> TXEMPT;
constexpr LPUART8_Reg<regs::constify(&LPUART_Layout::FIFO), 1, 22> RXEMPT;
constexpr LPUART8_Reg<&LPUART_Layout::FIFO, 1, 17, kW1C> TXOF;
constexpr LPUART8_Reg<&LPUART_Layout::FIFO, 1, 16, kW1C> RXUF;
constexpr LPUART8_Reg<&LPUART_Layout::FIFO, 1, 15, kWORZ | kW1C> TXFLUSH;
constexpr LPUART8_Reg<&LPUART_Layout::FIFO, 1, 14, kWORZ | kW1C> RXFLUSH;
constexpr LPUART8_Reg<&LPUART_Layout::FIFO, 3, 10, (uint32_t{0x7} << 10) | kW1C> RXIDEN;
constexpr LPUART8_Reg<&LPUART_Layout::FIFO, 1,  9, (uint32_t{0x1} <<  9) | kW1C> TXOFE;
constexpr LPUART8_Reg<&LPUART_Layout::FIFO, 1,  8, (uint32_t{0x1} <<  8) | kW1C> RXUFE;
constexpr LPUART8_Reg<&LPUART_Layout::FIFO, 1,  7, (uint32_t{0x1} <<  7) | kW1C> TXFE;
constexpr LPUART8_Reg<regs::constify(&LPUART_Layout::FIFO), 3,  4> TXFIFOSIZE;
constexpr LPUART8_Reg<&LPUART_Layout::FIFO, 1,  3, (uint32_t{0x1} <<  3) | kW1C> RXFE;
constexpr LPUART8_Reg<regs::constify(&LPUART_Layout::FIFO), 3,  0> RXFIFOSIZE;
}  // namespace FIFO

// LPUART Watermark Register
namespace WATER {
constexpr LPUART8_Reg<regs::constify(&LPUART_Layout::WATER), 3, 24> RXCOUNT;
constexpr LPUART8_Reg<&LPUART_Layout::WATER, 2, 16> RXWATER;
constexpr LPUART8_Reg<regs::constify(&LPUART_Layout::WATER), 3,  8> TXCOUNT;
constexpr LPUART8_Reg<&LPUART_Layout::WATER, 2,  0> TXWATER;
}  // namespace WATER

}  // namespace LPUART8

namespace LPUART {

namespace PINCFG {
constexpr uint32_t kTRGSEL_DISABLED     = 0;
constexpr uint32_t kTRGSEL_NOT_RXD      = 1;
constexpr uint32_t kTRGSEL_NOT_CTS_B    = 2;
constexpr uint32_t kTRGSEL_MODULATE_TXD = 3;
}  // namespace PINCFG

namespace BAUD {
constexpr uint32_t kMATCFG_ADDRESS_MATCH_WAKEUP                   = 0;
constexpr uint32_t kMATCFG_IDLE_MATCH_WAKEUP                      = 1;
constexpr uint32_t kMATCFG_MATCH_ON_OFF                           = 2;
constexpr uint32_t kMATCFG_DATA_MATCH_RWU_AND_MATCH_ON_OFF_TX_CTS = 3;
}  // namespace BAUD

}  // namespace LPUART

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
