// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// USDHC.h defines all the USDHC registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "qindesign/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the Ultra Secured Digital Host Controller
// (uSDHC) registers.
//
// Comments are from BSD-3-licensed NXP SDK sources.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_USDHC.h
// * https://github.com/nxp-mcuxpresso/mcux-soc-svd/blob/main/MIMXRT1062/MIMXRT1062.xml
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct USDHC_Layout {
  volatile uint32_t DS_ADDR;                           /**< DMA System Address, offset: 0x0 */
  volatile uint32_t BLK_ATT;                           /**< Block Attributes, offset: 0x4 */
  volatile uint32_t CMD_ARG;                           /**< Command Argument, offset: 0x8 */
  volatile uint32_t CMD_XFR_TYP;                       /**< Command Transfer Type, offset: 0xC */
  const volatile uint32_t CMD_RSP0;                    /**< Command Response0, offset: 0x10 */
  const volatile uint32_t CMD_RSP1;                    /**< Command Response1, offset: 0x14 */
  const volatile uint32_t CMD_RSP2;                    /**< Command Response2, offset: 0x18 */
  const volatile uint32_t CMD_RSP3;                    /**< Command Response3, offset: 0x1C */
  volatile uint32_t DATA_BUFF_ACC_PORT;                /**< Data Buffer Access Port, offset: 0x20 */
  const volatile uint32_t PRES_STATE;                  /**< Present State, offset: 0x24 */
  volatile uint32_t PROT_CTRL;                         /**< Protocol Control, offset: 0x28 */
  volatile uint32_t SYS_CTRL;                          /**< System Control, offset: 0x2C */
  volatile uint32_t INT_STATUS;                        /**< Interrupt Status, offset: 0x30 */
  volatile uint32_t INT_STATUS_EN;                     /**< Interrupt Status Enable, offset: 0x34 */
  volatile uint32_t INT_SIGNAL_EN;                     /**< Interrupt Signal Enable, offset: 0x38 */
  volatile uint32_t AUTOCMD12_ERR_STATUS;              /**< Auto CMD12 Error Status, offset: 0x3C */
  volatile uint32_t HOST_CTRL_CAP;                     /**< Host Controller Capabilities, offset: 0x40 */
  volatile uint32_t WTMK_LVL;                          /**< Watermark Level, offset: 0x44 */
  volatile uint32_t MIX_CTRL;                          /**< Mixer Control, offset: 0x48 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t FORCE_EVENT;                       /**< Force Event, offset: 0x50 */
  const volatile uint32_t ADMA_ERR_STATUS;             /**< ADMA Error Status, offset: 0x54 */
  volatile uint32_t ADMA_SYS_ADDR;                     /**< ADMA System Address, offset: 0x58 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t DLL_CTRL;                          /**< DLL (Delay Line) Control, offset: 0x60 */
  const volatile uint32_t DLL_STATUS;                  /**< DLL Status, offset: 0x64 */
  volatile uint32_t CLK_TUNE_CTRL_STATUS;              /**< CLK Tuning Control and Status, offset: 0x68 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[21];
  volatile uint32_t VEND_SPEC;                         /**< Vendor Specific Register, offset: 0xC0 */
  volatile uint32_t MMC_BOOT;                          /**< eMMC Boot, offset: 0xC4 */
  volatile uint32_t VEND_SPEC2;                        /**< Vendor Specific 2 Register, offset: 0xC8 */
  volatile uint32_t TUNING_CTRL;                       /**< Tuning Control, offset: 0xCC */
};

constexpr size_t    kUSDHC_size  = 0xD0;
constexpr uintptr_t kUSDHC1_base = 0x402C'0000;
constexpr uintptr_t kUSDHC2_base = 0x402C'4000;

namespace USDHC1 {
constexpr regs::RegGroup<USDHC_Layout, kUSDHC_size, kUSDHC1_base> group;
}  // namespace USDHC1

namespace USDHC2 {
constexpr regs::RegGroup<USDHC_Layout, kUSDHC_size, kUSDHC2_base> group;
}  // namespace USDHC2

namespace USDHC1 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using USDHC1_Reg =
    regs::Reg32<kUSDHC1_base, USDHC_Layout, Member, 0, Bits, Shift, AssignMask>;

// DMA System Address
namespace DS_ADDR {
constexpr USDHC1_Reg<&USDHC_Layout::DS_ADDR, 32, 0> DS_ADDR;  // System address
}  // namespace DS_ADDR

// Block Attributes
namespace BLK_ATT {
constexpr USDHC1_Reg<&USDHC_Layout::BLK_ATT, 16, 16> BLKCNT;   // Blocks count for current transfer
    // 0b0000000000000000..Stop count
    // 0b0000000000000001..1 block
    // 0b0000000000000010..2 blocks
    // 0b1111111111111111..65535 blocks
constexpr USDHC1_Reg<&USDHC_Layout::BLK_ATT, 13,  0> BLKSIZE;  // Transfer block size
    // 0b0000000000000..No data transfer
    // 0b0000000000001..1 byte
    // 0b0000000000010..2 bytes
    // 0b0000000000011..3 bytes
    // 0b0000000000100..4 bytes
    // 0b0000111111111..511 bytes
    // 0b0001000000000..512 bytes
    // 0b0100000000000..2048 bytes
    // 0b1000000000000..4096 bytes
}  // namespace BLK_ATT

// Command Argument
namespace CMD_ARG {
constexpr USDHC1_Reg<&USDHC_Layout::CMD_ARG, 32, 0> CMDARG;  // Command argument
}  // namespace CMD_ARG

// Command Transfer Type
// Be careful when writing to this register
namespace CMD_XFR_TYP {
constexpr USDHC1_Reg<&USDHC_Layout::CMD_XFR_TYP, 6, 24> CMDINX;  // Command index
constexpr USDHC1_Reg<&USDHC_Layout::CMD_XFR_TYP, 2, 22> CMDTYP;  // Command type
    // 0b00..Normal other commands
    // 0b01..Suspend CMD52 for writing bus suspend in CCCR
    // 0b10..Resume CMD52 for writing function select in CCCR
    // 0b11..Abort CMD12, CMD52 for writing I/O Abort in CCCR
constexpr USDHC1_Reg<&USDHC_Layout::CMD_XFR_TYP, 1, 21> DPSEL;   // Data present select
    // 0b0..No data present
    // 0b1..Data present
constexpr USDHC1_Reg<&USDHC_Layout::CMD_XFR_TYP, 1, 20> CICEN;   // Command index check enable
    // 0b0..Disable command index check
    // 0b1..Enables command index check
constexpr USDHC1_Reg<&USDHC_Layout::CMD_XFR_TYP, 1, 19> CCCEN;   // Command CRC check enable
    // 0b0..Disables command CRC check
    // 0b1..Enables command CRC check
constexpr USDHC1_Reg<&USDHC_Layout::CMD_XFR_TYP, 2, 16> RSPTYP;  // Response type select
    // 0b00..No response
    // 0b01..Response length 136
    // 0b10..Response length 48
    // 0b11..Response length 48, check busy after response
}  // namespace CMD_XFR_TYP

// Command Response0
namespace CMD_RSP0 {
constexpr USDHC1_Reg<&USDHC_Layout::CMD_RSP0, 32, 0> CMDRSP0;  // Command response 0
}  // namespace CMD_RSP0

// Command Response1
namespace CMD_RSP1 {
constexpr USDHC1_Reg<&USDHC_Layout::CMD_RSP1, 32, 0> CMDRSP1;  // Command response 1
}  // namespace CMD_RSP1

// Command Response2
namespace CMD_RSP2 {
constexpr USDHC1_Reg<&USDHC_Layout::CMD_RSP2, 32, 0> CMDRSP2;  // Command response 2
}  // namespace CMD_RSP2

// Command Response3
namespace CMD_RSP3 {
constexpr USDHC1_Reg<&USDHC_Layout::CMD_RSP3, 32, 0> CMDRSP3;  // Command response 3
}  // namespace CMD_RSP3

// Data Buffer Access Port
namespace DATA_BUFF_ACC_PORT {
constexpr USDHC1_Reg<&USDHC_Layout::DATA_BUFF_ACC_PORT, 32, 0> DATCONT;  // Data content
}  // namespace DATA_BUFF_ACC_PORT

// Present State
namespace PRES_STATE {
constexpr USDHC1_Reg<&USDHC_Layout::PRES_STATE, 8, 24> DLSL;    // DATA[7:0] line signal level
    // 0b00000000..Data 0 line signal level
    // 0b00000001..Data 1 line signal level
    // 0b00000010..Data 2 line signal level
    // 0b00000011..Data 3 line signal level
    // 0b00000100..Data 4 line signal level
    // 0b00000101..Data 5 line signal level
    // 0b00000110..Data 6 line signal level
    // 0b00000111..Data 7 line signal level
constexpr USDHC1_Reg<&USDHC_Layout::PRES_STATE, 1, 23> CLSL;    // CMD line signal level
constexpr USDHC1_Reg<&USDHC_Layout::PRES_STATE, 1, 19> WPSPL;   // Write protect switch pin level
    // 0b0..Write protected (WP = 1)
    // 0b1..Write enabled (WP = 0)
constexpr USDHC1_Reg<&USDHC_Layout::PRES_STATE, 1, 18> CDPL;    // Card detect pin level
    // 0b0..No card present (CD_B = 1)
    // 0b1..Card present (CD_B = 0)
constexpr USDHC1_Reg<&USDHC_Layout::PRES_STATE, 1, 16> CINST;   // Card inserted
    // 0b0..Power on reset or no card
    // 0b1..Card inserted
constexpr USDHC1_Reg<&USDHC_Layout::PRES_STATE, 1, 15> TSCD;    // Tap select change done
    // 0b0..Delay cell select change is not finished.
    // 0b1..Delay cell select change is finished.
constexpr USDHC1_Reg<&USDHC_Layout::PRES_STATE, 1, 12> RTR;     // Re-Tuning Request (only for SD3.0 SDR104 mode,and eMMC HS200 mode)
    // 0b0..Fixed or well tuned sampling clock
    // 0b1..Sampling clock needs re-tuning
constexpr USDHC1_Reg<&USDHC_Layout::PRES_STATE, 1, 11> BREN;    // Buffer read enable
    // 0b0..Read disable
    // 0b1..Read enable
constexpr USDHC1_Reg<&USDHC_Layout::PRES_STATE, 1, 10> BWEN;    // Buffer write enable
    // 0b0..Write disable
    // 0b1..Write enable
constexpr USDHC1_Reg<&USDHC_Layout::PRES_STATE, 1,  9> RTA;     // Read transfer active
    // 0b0..No valid data
    // 0b1..Transferring data
constexpr USDHC1_Reg<&USDHC_Layout::PRES_STATE, 1,  8> WTA;     // Write transfer active
    // 0b0..No valid data
    // 0b1..Transferring data
constexpr USDHC1_Reg<&USDHC_Layout::PRES_STATE, 1,  7> SDOFF;   // SD clock gated off internally
    // 0b0..SD clock is active.
    // 0b1..SD clock is gated off.
constexpr USDHC1_Reg<&USDHC_Layout::PRES_STATE, 1,  6> PEROFF;  // IPG_PERCLK gated off internally
    // 0b0..IPG_PERCLK is active.
    // 0b1..IPG_PERCLK is gated off.
constexpr USDHC1_Reg<&USDHC_Layout::PRES_STATE, 1,  5> HCKOFF;  // HCLK gated off internally
    // 0b0..HCLK is active.
    // 0b1..HCLK is gated off.
constexpr USDHC1_Reg<&USDHC_Layout::PRES_STATE, 1,  4> IPGOFF;  // Peripheral clock gated off internally
    // 0b0..Peripheral clock is active.
    // 0b1..Peripheral clock is gated off.
constexpr USDHC1_Reg<&USDHC_Layout::PRES_STATE, 1,  3> SDSTB;   // SD clock stable
    // 0b0..Clock is changing frequency and not stable.
    // 0b1..Clock is stable.
constexpr USDHC1_Reg<&USDHC_Layout::PRES_STATE, 1,  2> DLA;     // Data line active
    // 0b0..DATA line inactive
    // 0b1..DATA line active
constexpr USDHC1_Reg<&USDHC_Layout::PRES_STATE, 1,  1> CDIHB;   // Command Inhibit Data (DATA)
    // 0b0..Can issue command that uses the DATA line
    // 0b1..Cannot issue command that uses the DATA line
constexpr USDHC1_Reg<&USDHC_Layout::PRES_STATE, 1,  0> CIHB;    // Command inhibit (CMD)
    // 0b0..Can issue command using only CMD line
    // 0b1..Cannot issue command
}  // namespace PRES_STATE

// Protocol Control
namespace PROT_CTRL {
constexpr USDHC1_Reg<&USDHC_Layout::PROT_CTRL, 1, 30> NON_EXACT_BLK_RD;  // Non-exact block read
    // 0b0..The block read is exact block read. Host driver does not need to issue abort command to terminate this multi-block read.
    // 0b1..The block read is non-exact block read. Host driver needs to issue abort command to terminate this multi-block read.
constexpr USDHC1_Reg<&USDHC_Layout::PROT_CTRL, 3, 27> BURST_LEN_EN;      // BURST length enable for INCR, INCR4 / INCR8 / INCR16, INCR4-WRAP / INCR8-WRAP / INCR16-WRAP
    // 0b1xx..Burst length is enabled for INCR4-WRAP / INCR8-WRAP / INCR16-WRAP.
    // 0bx1x..Burst length is enabled for INCR4 / INCR8 / INCR16.
    // 0bxx1..Burst length is enabled for INCR.
constexpr USDHC1_Reg<&USDHC_Layout::PROT_CTRL, 1, 26> WECRM;             // Wakeup event enable on SD card removal
    // 0b0..Disables wakeup event enable on SD card removal
    // 0b1..Enables wakeup event enable on SD card removal
constexpr USDHC1_Reg<&USDHC_Layout::PROT_CTRL, 1, 25> WECINS;            // Wakeup event enable on SD card insertion
    // 0b0..Disable wakeup event enable on SD card insertion
    // 0b1..Enable wakeup event enable on SD card insertion
constexpr USDHC1_Reg<&USDHC_Layout::PROT_CTRL, 1, 24> WECINT;            // Wakeup event enable on card interrupt
    // 0b0..Disables wakeup event enable on card interrupt
    // 0b1..Enables wakeup event enable on card interrupt
constexpr USDHC1_Reg<&USDHC_Layout::PROT_CTRL, 1, 20> RD_DONE_NO_8CLK;   // Read performed number 8 clock
constexpr USDHC1_Reg<&USDHC_Layout::PROT_CTRL, 1, 19> IABG;              // Interrupt at block gap
    // 0b0..Disables interrupt at block gap
    // 0b1..Enables interrupt at block gap
constexpr USDHC1_Reg<&USDHC_Layout::PROT_CTRL, 1, 18> RWCTL;             // Read wait control
    // 0b0..Disables read wait control and stop SD clock at block gap when SABGREQ field is set
    // 0b1..Enables read wait control and assert read wait without stopping SD clock at block gap when SABGREQ field is set
constexpr USDHC1_Reg<&USDHC_Layout::PROT_CTRL, 1, 17> CREQ;              // Continue request
    // 0b0..No effect
    // 0b1..Restart
constexpr USDHC1_Reg<&USDHC_Layout::PROT_CTRL, 1, 16> SABGREQ;           // Stop at block gap request
    // 0b0..Transfer
    // 0b1..Stop
constexpr USDHC1_Reg<&USDHC_Layout::PROT_CTRL, 2,  8> DMASEL;            // DMA select
    // 0b00..No DMA or simple DMA is selected.
    // 0b01..ADMA1 is selected.
    // 0b10..ADMA2 is selected.
    // 0b11..Reserved
constexpr USDHC1_Reg<&USDHC_Layout::PROT_CTRL, 1,  7> CDSS;              // Card detect signal selection
    // 0b0..Card detection level is selected (for normal purpose).
    // 0b1..Card detection test level is selected (for test purpose).
constexpr USDHC1_Reg<&USDHC_Layout::PROT_CTRL, 1,  6> CDTL;              // Card detect test level
    // 0b0..Card detect test level is 0, no card inserted
    // 0b1..Card detect test level is 1, card inserted
constexpr USDHC1_Reg<&USDHC_Layout::PROT_CTRL, 2,  4> EMODE;             // Endian mode
    // 0b00..Big endian mode
    // 0b01..Half word big endian mode
    // 0b10..Little endian mode
    // 0b11..Reserved
constexpr USDHC1_Reg<&USDHC_Layout::PROT_CTRL, 1,  3> D3CD;              // DATA3 as card detection pin
    // 0b0..DATA3 does not monitor card insertion
    // 0b1..DATA3 as card detection pin
constexpr USDHC1_Reg<&USDHC_Layout::PROT_CTRL, 2,  1> DTW;               // Data transfer width
    // 0b00..1-bit mode
    // 0b01..4-bit mode
    // 0b10..8-bit mode
    // 0b11..Reserved
}  // namespace PROT_CTRL

// System Control
namespace SYS_CTRL {
constexpr USDHC1_Reg<&USDHC_Layout::SYS_CTRL, 1, 28> RSTT;       // Reset tuning
constexpr USDHC1_Reg<&USDHC_Layout::SYS_CTRL, 1, 27> INITA;      // Initialization active
constexpr USDHC1_Reg<&USDHC_Layout::SYS_CTRL, 1, 26> RSTD;       // Software reset for data line
    // 0b0..No reset
    // 0b1..Reset
constexpr USDHC1_Reg<&USDHC_Layout::SYS_CTRL, 1, 25> RSTC;       // Software reset for CMD line
    // 0b0..No reset
    // 0b1..Reset
constexpr USDHC1_Reg<&USDHC_Layout::SYS_CTRL, 1, 24> RSTA;       // Software reset for all
    // 0b0..No reset
    // 0b1..Reset
constexpr USDHC1_Reg<&USDHC_Layout::SYS_CTRL, 1, 23> IPP_RST_N;  // Hardware reset
constexpr USDHC1_Reg<&USDHC_Layout::SYS_CTRL, 4, 16> DTOCV;      // Data timeout counter value
    // 0b0000..SDCLK x 2 14
    // 0b0001..SDCLK x 2 15
    // 0b0010..SDCLK x 2 16
    // 0b0011..SDCLK x 2 17
    // 0b0100..SDCLK x 2 18
    // 0b0101..SDCLK x 2 19
    // 0b0110..SDCLK x 2 20
    // 0b0111..SDCLK x 2 21
    // 0b1000..SDCLK x 2 22
    // 0b1001..SDCLK x 2 23
    // 0b1010..SDCLK x 2 24
    // 0b1011..SDCLK x 2 25
    // 0b1100..SDCLK x 2 26
    // 0b1101..SDCLK x 2 27
    // 0b1110..SDCLK x 2 28
    // 0b1111..SDCLK x 2 29
constexpr USDHC1_Reg<&USDHC_Layout::SYS_CTRL, 8,  8> SDCLKFS;    // SDCLK frequency select
constexpr USDHC1_Reg<&USDHC_Layout::SYS_CTRL, 4,  4> DVS;        // Divisor
    // 0b0000..Divide-by-1
    // 0b0001..Divide-by-2
    // 0b1110..Divide-by-15
    // 0b1111..Divide-by-16
}  // namespace SYS_CTRL

// Interrupt Status
namespace INT_STATUS {
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS, 1, 28, 0x0> DMAE;                       // DMA error
    // 0b0..No error
    // 0b1..Error
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS, 1, 26, 0x0> TNE;                        // Tuning error: (only for SD3.0 SDR104 mode and eMMC HS200 mode)
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS, 1, 24, 0x0> AC12E;                      // Auto CMD12 error
    // 0b0..No error
    // 0b1..Error
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS, 1, 22, 0x0> DEBE;                       // Data end bit error
    // 0b0..No error
    // 0b1..Error
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS, 1, 21, 0x0> DCE;                        // Data CRC error
    // 0b0..No error
    // 0b1..Error
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS, 1, 20, 0x0> DTOE;                       // Data timeout error
    // 0b0..No error
    // 0b1..Time out
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS, 1, 19, 0x0> CIE;                        // Command index error
    // 0b0..No error
    // 0b1..Error
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS, 1, 18, 0x0> CEBE;                       // Command end bit error
    // 0b0..No error
    // 0b1..End bit error generated
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS, 1, 17, 0x0> CCE;                        // Command CRC error
    // 0b0..No error
    // 0b1..CRC error generated
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS, 1, 16, 0x0> CTOE;                       // Command timeout error
    // 0b0..No error
    // 0b1..Time out
constexpr USDHC1_Reg<regs::constify(&USDHC_Layout::INT_STATUS), 1, 15> ERR_INT_STATUS;  // Error Interrupt Status
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS, 1, 14, 0x0> TP;                         // Tuning pass:(only for SD3.0 SDR104 mode and eMMC HS200 mode)
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS, 1, 12, 0x0> RTE;                        // Re-tuning event: (only for SD3.0 SDR104 mode and eMMC HS200 mode)
    // 0b0..Re-tuning is not required.
    // 0b1..Re-tuning should be performed.
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS, 1,  8, 0x0> CINT;                       // Card interrupt
    // 0b0..No card interrupt
    // 0b1..Generate card interrupt
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS, 1,  7, 0x0> CRM;                        // Card removal
    // 0b0..Card state unstable or inserted
    // 0b1..Card removed
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS, 1,  6, 0x0> CINS;                       // Card insertion
    // 0b0..Card state unstable or removed
    // 0b1..Card inserted
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS, 1,  5, 0x0> BRR;                        // Buffer read ready
    // 0b0..Not ready to read buffer
    // 0b1..Ready to read buffer
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS, 1,  4, 0x0> BWR;                        // Buffer write ready
    // 0b0..Not ready to write buffer
    // 0b1..Ready to write buffer
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS, 1,  3, 0x0> DINT;                       // DMA interrupt
    // 0b0..No DMA interrupt
    // 0b1..DMA interrupt is generated.
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS, 1,  2, 0x0> BGE;                        // Block gap event
    // 0b0..No block gap event
    // 0b1..Transaction stopped at block gap
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS, 1,  1, 0x0> TC;                         // Transfer complete
    // 0b0..Transfer does not complete
    // 0b1..Transfer complete
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS, 1,  0, 0x0> CC;                         // Command complete
    // 0b0..Command not complete
    // 0b1..Command complete
}  // namespace INT_STATUS

// Interrupt Status Enable
namespace INT_STATUS_EN {
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS_EN, 1, 28> DMAESEN;   // DMA error status enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS_EN, 1, 26> TNESEN;    // Tuning error status enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS_EN, 1, 24> AC12ESEN;  // Auto CMD12 error status enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS_EN, 1, 22> DEBESEN;   // Data end bit error status enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS_EN, 1, 21> DCESEN;    // Data CRC error status enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS_EN, 1, 20> DTOESEN;   // Data timeout error status enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS_EN, 1, 19> CIESEN;    // Command index error status enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS_EN, 1, 18> CEBESEN;   // Command end bit error status enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS_EN, 1, 17> CCESEN;    // Command CRC error status enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS_EN, 1, 16> CTOESEN;   // Command timeout error status enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS_EN, 1, 14> TPSEN;     // Tuning pass status enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS_EN, 1, 12> RTESEN;    // Re-tuning event status enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS_EN, 1,  8> CINTSEN;   // Card interrupt status enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS_EN, 1,  7> CRMSEN;    // Card removal status enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS_EN, 1,  6> CINSSEN;   // Card insertion status enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS_EN, 1,  5> BRRSEN;    // Buffer read ready status enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS_EN, 1,  4> BWRSEN;    // Buffer write ready status enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS_EN, 1,  3> DINTSEN;   // DMA interrupt status enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS_EN, 1,  2> BGESEN;    // Block gap event status enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS_EN, 1,  1> TCSEN;     // Transfer complete status enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_STATUS_EN, 1,  0> CCSEN;     // Command complete status enable
    // 0b0..Masked
    // 0b1..Enabled
}  // namespace INT_STATUS_EN

// Interrupt Signal Enable
namespace INT_SIGNAL_EN {
constexpr USDHC1_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1, 28> DMAEIEN;   // DMA error interrupt enable
    // 0b0..Masked
    // 0b1..Enable
constexpr USDHC1_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1, 26> TNEIEN;    // Tuning error interrupt enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1, 24> AC12EIEN;  // Auto CMD12 error interrupt enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1, 22> DEBEIEN;   // Data end bit error interrupt enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1, 21> DCEIEN;    // Data CRC error interrupt enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1, 20> DTOEIEN;   // Data timeout error interrupt enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1, 19> CIEIEN;    // Command index error interrupt enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1, 18> CEBEIEN;   // Command end bit error interrupt enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1, 17> CCEIEN;    // Command CRC error interrupt enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1, 16> CTOEIEN;   // Command timeout error interrupt enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1, 14> TPIEN;     // Tuning Pass interrupt enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1, 12> RTEIEN;    // Re-tuning event interrupt enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1,  8> CINTIEN;   // Card interrupt enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1,  7> CRMIEN;    // Card removal interrupt enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1,  6> CINSIEN;   // Card insertion interrupt enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1,  5> BRRIEN;    // Buffer read ready interrupt enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1,  4> BWRIEN;    // Buffer write ready interrupt enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1,  3> DINTIEN;   // DMA interrupt enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1,  2> BGEIEN;    // Block gap event interrupt enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1,  1> TCIEN;     // Transfer complete interrupt enable
    // 0b0..Masked
    // 0b1..Enabled
constexpr USDHC1_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1,  0> CCIEN;     // Command complete interrupt enable
    // 0b0..Masked
    // 0b1..Enabled
}  // namespace INT_SIGNAL_EN

// Auto CMD12 Error Status
namespace AUTOCMD12_ERR_STATUS {
constexpr USDHC1_Reg<&USDHC_Layout::AUTOCMD12_ERR_STATUS, 1, 23> SMP_CLK_SEL;                // Sample clock select
    // 0b0..Fixed clock is used to sample data
    // 0b1..Tuned clock is used to sample data
constexpr USDHC1_Reg<&USDHC_Layout::AUTOCMD12_ERR_STATUS, 1, 22> EXECUTE_TUNING;             // Execute tuning
    // 0b0..Tuning procedure is aborted
    // 0b1..Start tuning procedure
constexpr USDHC1_Reg<regs::constify(&USDHC_Layout::AUTOCMD12_ERR_STATUS), 1,  7> CNIBAC12E;  // Command not issued by Auto CMD12 error
    // 0b0..No error
    // 0b1..Not issued
constexpr USDHC1_Reg<regs::constify(&USDHC_Layout::AUTOCMD12_ERR_STATUS), 1,  4> AC12IE;     // Auto CMD12 / 23 index error
    // 0b0..No error
    // 0b1..Error, the CMD index in response is not CMD12/23
constexpr USDHC1_Reg<regs::constify(&USDHC_Layout::AUTOCMD12_ERR_STATUS), 1,  3> AC12CE;     // Auto CMD12 / 23 CRC error
    // 0b0..No CRC error
    // 0b1..CRC error met in Auto CMD12/23 response
constexpr USDHC1_Reg<regs::constify(&USDHC_Layout::AUTOCMD12_ERR_STATUS), 1,  2> AC12EBE;    // Auto CMD12 / 23 end bit error
    // 0b0..No error
    // 0b1..End bit error generated
constexpr USDHC1_Reg<regs::constify(&USDHC_Layout::AUTOCMD12_ERR_STATUS), 1,  1> AC12TOE;    // Auto CMD12 / 23 timeout error
    // 0b0..No error
    // 0b1..Time out
constexpr USDHC1_Reg<regs::constify(&USDHC_Layout::AUTOCMD12_ERR_STATUS), 1,  0> AC12NE;     // Auto CMD12 not executed
    // 0b0..Executed
    // 0b1..Not executed
}  // namespace AUTOCMD12_ERR_STATUS

// Host Controller Capabilities
namespace HOST_CTRL_CAP {
constexpr USDHC1_Reg<regs::constify(&USDHC_Layout::HOST_CTRL_CAP), 1, 26> VS18;            // Voltage support 1.8 V
    // 0b0..1.8 V not supported
    // 0b1..1.8 V supported
constexpr USDHC1_Reg<regs::constify(&USDHC_Layout::HOST_CTRL_CAP), 1, 25> VS30;            // Voltage support 3.0 V
    // 0b0..3.0 V not supported
    // 0b1..3.0 V supported
constexpr USDHC1_Reg<regs::constify(&USDHC_Layout::HOST_CTRL_CAP), 1, 24> VS33;            // Voltage support 3.3 V
    // 0b0..3.3 V not supported
    // 0b1..3.3 V supported
constexpr USDHC1_Reg<regs::constify(&USDHC_Layout::HOST_CTRL_CAP), 1, 23> SRS;             // Suspend / resume support
    // 0b0..Not supported
    // 0b1..Supported
constexpr USDHC1_Reg<regs::constify(&USDHC_Layout::HOST_CTRL_CAP), 1, 22> DMAS;            // DMA support
    // 0b0..DMA not supported
    // 0b1..DMA supported
constexpr USDHC1_Reg<regs::constify(&USDHC_Layout::HOST_CTRL_CAP), 1, 21> HSS;             // High speed support
    // 0b0..High speed not supported
    // 0b1..High speed supported
constexpr USDHC1_Reg<regs::constify(&USDHC_Layout::HOST_CTRL_CAP), 1, 20> ADMAS;           // ADMA support
    // 0b0..Advanced DMA not supported
    // 0b1..Advanced DMA supported
constexpr USDHC1_Reg<regs::constify(&USDHC_Layout::HOST_CTRL_CAP), 3, 16> MBL;             // Max block length
    // 0b000..512 bytes
    // 0b001..1024 bytes
    // 0b010..2048 bytes
    // 0b011..4096 bytes
constexpr USDHC1_Reg<&USDHC_Layout::HOST_CTRL_CAP, 1, 13> USE_TUNING_SDR50;                // Use Tuning for SDR50
    // 0b0..SDR50 does not support tuning
    // 0b1..SDR50 supports tuning
constexpr USDHC1_Reg<regs::constify(&USDHC_Layout::HOST_CTRL_CAP), 1,  2> DDR50_SUPPORT;   // DDR50 support
constexpr USDHC1_Reg<regs::constify(&USDHC_Layout::HOST_CTRL_CAP), 1,  1> SDR104_SUPPORT;  // SDR104 support
constexpr USDHC1_Reg<regs::constify(&USDHC_Layout::HOST_CTRL_CAP), 1,  0> SDR50_SUPPORT;   // SDR50 support
}  // namespace HOST_CTRL_CAP

// Watermark Level
namespace WTMK_LVL {
constexpr USDHC1_Reg<&USDHC_Layout::WTMK_LVL, 5, 24> WR_BRST_LEN;  // Write burst length due to system restriction, the actual burst length might not exceed 16
constexpr USDHC1_Reg<&USDHC_Layout::WTMK_LVL, 8, 16> WR_WML;       // Write watermark level
constexpr USDHC1_Reg<&USDHC_Layout::WTMK_LVL, 5,  8> RD_BRST_LEN;  // Read burst length due to system restriction, the actual burst length might not exceed 16
constexpr USDHC1_Reg<&USDHC_Layout::WTMK_LVL, 8,  0> RD_WML;       // Read watermark level
}  // namespace WTMK_LVL

// Mixer Control
namespace MIX_CTRL {
constexpr USDHC1_Reg<&USDHC_Layout::MIX_CTRL, 1, 25> FBCLK_SEL;     // Feedback clock source selection (Only used for SD3.0, SDR104 mode and eMMC HS200 mode)
    // 0b0..Feedback clock comes from the loopback CLK
    // 0b1..Feedback clock comes from the ipp_card_clk_out
constexpr USDHC1_Reg<&USDHC_Layout::MIX_CTRL, 1, 24> AUTO_TUNE_EN;  // Auto tuning enable (Only used for SD3.0, SDR104 mode and and eMMC HS200 mode)
    // 0b0..Disable auto tuning
    // 0b1..Enable auto tuning
constexpr USDHC1_Reg<&USDHC_Layout::MIX_CTRL, 1, 23> SMP_CLK_SEL;   // Clock selection
    // 0b0..Fixed clock is used to sample data / cmd
    // 0b1..Tuned clock is used to sample data / cmd
constexpr USDHC1_Reg<&USDHC_Layout::MIX_CTRL, 1, 22> EXE_TUNE;      // Execute tuning: (Only used for SD3.0, SDR104 mode and eMMC HS200 mode)
    // 0b0..Not tuned or tuning completed
    // 0b1..Execute tuning
constexpr USDHC1_Reg<&USDHC_Layout::MIX_CTRL, 1,  7> AC23EN;        // Auto CMD23 enable
constexpr USDHC1_Reg<&USDHC_Layout::MIX_CTRL, 1,  6> NIBBLE_POS;    // Nibble position indication
constexpr USDHC1_Reg<&USDHC_Layout::MIX_CTRL, 1,  5> MSBSEL;        // Multi / Single block select
    // 0b0..Single block
    // 0b1..Multiple blocks
constexpr USDHC1_Reg<&USDHC_Layout::MIX_CTRL, 1,  4> DTDSEL;        // Data transfer direction select
    // 0b0..Write (Host to card)
    // 0b1..Read (Card to host)
constexpr USDHC1_Reg<&USDHC_Layout::MIX_CTRL, 1,  3> DDR_EN;        // Dual data rate mode selection
constexpr USDHC1_Reg<&USDHC_Layout::MIX_CTRL, 1,  2> AC12EN;        // Auto CMD12 enable
    // 0b0..Disable
    // 0b1..Enable
constexpr USDHC1_Reg<&USDHC_Layout::MIX_CTRL, 1,  1> BCEN;          // Block count enable
    // 0b0..Disable
    // 0b1..Enable
constexpr USDHC1_Reg<&USDHC_Layout::MIX_CTRL, 1,  0> DMAEN;         // DMA enable
    // 0b0..Disable
    // 0b1..Enable
}  // namespace MIX_CTRL

// Force Event
namespace FORCE_EVENT {
// All fields are WORZ

constexpr USDHC1_Reg<&USDHC_Layout::FORCE_EVENT, 1, 31, 0x0> FEVTCINT;       // Force event card interrupt
constexpr USDHC1_Reg<&USDHC_Layout::FORCE_EVENT, 1, 28, 0x0> FEVTDMAE;       // Force event DMA error
constexpr USDHC1_Reg<&USDHC_Layout::FORCE_EVENT, 1, 26, 0x0> FEVTTNE;        // Force tuning error
constexpr USDHC1_Reg<&USDHC_Layout::FORCE_EVENT, 1, 24, 0x0> FEVTAC12E;      // Force event Auto Command 12 error
constexpr USDHC1_Reg<&USDHC_Layout::FORCE_EVENT, 1, 22, 0x0> FEVTDEBE;       // Force event data end bit error
constexpr USDHC1_Reg<&USDHC_Layout::FORCE_EVENT, 1, 21, 0x0> FEVTDCE;        // Force event data CRC error
constexpr USDHC1_Reg<&USDHC_Layout::FORCE_EVENT, 1, 20, 0x0> FEVTDTOE;       // Force event data time out error
constexpr USDHC1_Reg<&USDHC_Layout::FORCE_EVENT, 1, 19, 0x0> FEVTCIE;        // Force event command index error
constexpr USDHC1_Reg<&USDHC_Layout::FORCE_EVENT, 1, 18, 0x0> FEVTCEBE;       // Force event command end bit error
constexpr USDHC1_Reg<&USDHC_Layout::FORCE_EVENT, 1, 17, 0x0> FEVTCCE;        // Force event command CRC error
constexpr USDHC1_Reg<&USDHC_Layout::FORCE_EVENT, 1, 16, 0x0> FEVTCTOE;       // Force event command time out error
constexpr USDHC1_Reg<&USDHC_Layout::FORCE_EVENT, 1,  7, 0x0> FEVTCNIBAC12E;  // Force event command not executed by Auto Command 12 error
constexpr USDHC1_Reg<&USDHC_Layout::FORCE_EVENT, 1,  4, 0x0> FEVTAC12IE;     // Force event Auto Command 12 index error
constexpr USDHC1_Reg<&USDHC_Layout::FORCE_EVENT, 1,  3, 0x0> FEVTAC12EBE;    // Force event Auto Command 12 end bit error
constexpr USDHC1_Reg<&USDHC_Layout::FORCE_EVENT, 1,  2, 0x0> FEVTAC12CE;     // Force event auto command 12 CRC error
constexpr USDHC1_Reg<&USDHC_Layout::FORCE_EVENT, 1,  1, 0x0> FEVTAC12TOE;    // Force event auto command 12 time out error
constexpr USDHC1_Reg<&USDHC_Layout::FORCE_EVENT, 1,  0, 0x0> FEVTAC12NE;     // Force event auto command 12 not executed
}  // namespace FORCE_EVENT

// ADMA Error Status
namespace ADMA_ERR_STATUS {
constexpr USDHC1_Reg<&USDHC_Layout::ADMA_ERR_STATUS, 1, 3> ADMADCE;  // ADMA descriptor error
    // 0b0..No error
    // 0b1..Error
constexpr USDHC1_Reg<&USDHC_Layout::ADMA_ERR_STATUS, 1, 2> ADMALME;  // ADMA length mismatch error
    // 0b0..No error
    // 0b1..Error
constexpr USDHC1_Reg<&USDHC_Layout::ADMA_ERR_STATUS, 2, 0> ADMAES;   // ADMA error state (when ADMA error is occurred)
}  // namespace ADMA_ERR_STATUS

// ADMA System Address
namespace ADMA_SYS_ADDR {
constexpr USDHC1_Reg<&USDHC_Layout::ADMA_SYS_ADDR, 30, 2> ADS_ADDR;  // ADMA system address
}  // namespace ADMA_SYS_ADDR

// DLL (Delay Line) Control
namespace DLL_CTRL {
constexpr USDHC1_Reg<&USDHC_Layout::DLL_CTRL, 4, 28> DLL_CTRL_REF_UPDATE_INT;    // DLL control loop update interval
constexpr USDHC1_Reg<&USDHC_Layout::DLL_CTRL, 8, 20> DLL_CTRL_SLV_UPDATE_INT;    // Slave delay line update interval
constexpr USDHC1_Reg<&USDHC_Layout::DLL_CTRL, 3, 16> DLL_CTRL_SLV_DLY_TARGET1;   // DLL slave delay target1
constexpr USDHC1_Reg<&USDHC_Layout::DLL_CTRL, 7,  9> DLL_CTRL_SLV_OVERRIDE_VAL;  // DLL slave override val
constexpr USDHC1_Reg<&USDHC_Layout::DLL_CTRL, 1,  8> DLL_CTRL_SLV_OVERRIDE;      // DLL slave override
constexpr USDHC1_Reg<&USDHC_Layout::DLL_CTRL, 1,  7> DLL_CTRL_GATE_UPDATE;       // DLL gate update
constexpr USDHC1_Reg<&USDHC_Layout::DLL_CTRL, 4,  3> DLL_CTRL_SLV_DLY_TARGET0;   // DLL slave delay target0
constexpr USDHC1_Reg<&USDHC_Layout::DLL_CTRL, 1,  2> DLL_CTRL_SLV_FORCE_UPD;     // DLL slave delay line
constexpr USDHC1_Reg<&USDHC_Layout::DLL_CTRL, 1,  1> DLL_CTRL_RESET;             // DLL reset
constexpr USDHC1_Reg<&USDHC_Layout::DLL_CTRL, 1,  0> DLL_CTRL_ENABLE;            // DLL and delay chain
}  // namespace DLL_CTRL

// DLL Status
namespace DLL_STATUS {
constexpr USDHC1_Reg<&USDHC_Layout::DLL_STATUS, 7, 9> DLL_STS_REF_SEL;   // Reference delay line select taps
constexpr USDHC1_Reg<&USDHC_Layout::DLL_STATUS, 7, 2> DLL_STS_SLV_SEL;   // Slave delay line select status
constexpr USDHC1_Reg<&USDHC_Layout::DLL_STATUS, 1, 1> DLL_STS_REF_LOCK;  // Reference DLL lock status
constexpr USDHC1_Reg<&USDHC_Layout::DLL_STATUS, 1, 0> DLL_STS_SLV_LOCK;  // Slave delay-line lock status
}  // namespace DLL_STATUS

// CLK Tuning Control and Status
namespace CLK_TUNE_CTRL_STATUS {
constexpr USDHC1_Reg<regs::constify(&USDHC_Layout::CLK_TUNE_CTRL_STATUS), 1, 31> PRE_ERR;       // PRE error
constexpr USDHC1_Reg<regs::constify(&USDHC_Layout::CLK_TUNE_CTRL_STATUS), 7, 24> TAP_SEL_PRE;   // TAP_SEL_PRE
constexpr USDHC1_Reg<regs::constify(&USDHC_Layout::CLK_TUNE_CTRL_STATUS), 4, 20> TAP_SEL_OUT;   // Delay cells added on the feedback clock between CLK_PRE and CLK_OUT
constexpr USDHC1_Reg<regs::constify(&USDHC_Layout::CLK_TUNE_CTRL_STATUS), 4, 16> TAP_SEL_POST;  // Delay cells added on the feedback clock between CLK_OUT and CLK_POST
constexpr USDHC1_Reg<regs::constify(&USDHC_Layout::CLK_TUNE_CTRL_STATUS), 1, 15> NXT_ERR;       // NXT error
constexpr USDHC1_Reg<&USDHC_Layout::CLK_TUNE_CTRL_STATUS, 7,  8> DLY_CELL_SET_PRE;              // delay cells on the feedback clock between the feedback clock and CLK_PRE
constexpr USDHC1_Reg<&USDHC_Layout::CLK_TUNE_CTRL_STATUS, 4,  4> DLY_CELL_SET_OUT;              // Delay cells on the feedback clock between CLK_PRE and CLK_OUT
constexpr USDHC1_Reg<&USDHC_Layout::CLK_TUNE_CTRL_STATUS, 4,  0> DLY_CELL_SET_POST;             // Delay cells on the feedback clock between CLK_OUT and CLK_POST
}  // namespace CLK_TUNE_CTRL_STATUS

// Vendor Specific Register
namespace VEND_SPEC {
constexpr USDHC1_Reg<&USDHC_Layout::VEND_SPEC, 1, 31> CMD_BYTE_EN;         // Byte access
    // 0b0..Disable
    // 0b1..Enable
constexpr USDHC1_Reg<&USDHC_Layout::VEND_SPEC, 1, 15> CRC_CHK_DIS;         // CRC Check Disable
    // 0b0..Check CRC16 for every read data packet and check CRC fields for every write data packet
    // 0b1..Ignore CRC16 check for every read data packet and ignore CRC fields check for every write data packet
constexpr USDHC1_Reg<&USDHC_Layout::VEND_SPEC, 1,  8> FRC_SDCLK_ON;        // Force CLK
    // 0b0..CLK active or inactive is fully controlled by the hardware.
    // 0b1..Force CLK active
constexpr USDHC1_Reg<&USDHC_Layout::VEND_SPEC, 1,  3> AC12_WR_CHKBUSY_EN;  // Check busy enable
    // 0b0..Do not check busy after auto CMD12 for write data packet
    // 0b1..Check busy after auto CMD12 for write data packet
constexpr USDHC1_Reg<&USDHC_Layout::VEND_SPEC, 1,  2> CONFLICT_CHK_EN;     // Conflict check enable
    // 0b0..Conflict check disable
    // 0b1..Conflict check enable
constexpr USDHC1_Reg<&USDHC_Layout::VEND_SPEC, 1,  1> VSELECT;             // Voltage selection
    // 0b0..Change the voltage to high voltage range, around 3.0 V
    // 0b1..Change the voltage to low voltage range, around 1.8 V
}  // namespace VEND_SPEC

// eMMC Boot
namespace MMC_BOOT {
constexpr USDHC1_Reg<&USDHC_Layout::MMC_BOOT, 16, 16> BOOT_BLK_CNT;      // Stop At Block Gap value of automatic mode
constexpr USDHC1_Reg<&USDHC_Layout::MMC_BOOT,  1,  8> DISABLE_TIME_OUT;  // Time out
    // 0b0..Enable time out
    // 0b1..Disable time out
constexpr USDHC1_Reg<&USDHC_Layout::MMC_BOOT,  1,  7> AUTO_SABG_EN;      // Auto stop at block gap
constexpr USDHC1_Reg<&USDHC_Layout::MMC_BOOT,  1,  6> BOOT_EN;           // Boot enable
    // 0b0..Fast boot disable
    // 0b1..Fast boot enable
constexpr USDHC1_Reg<&USDHC_Layout::MMC_BOOT,  1,  5> BOOT_MODE;         // Boot mode
    // 0b0..Normal boot
    // 0b1..Alternative boot
constexpr USDHC1_Reg<&USDHC_Layout::MMC_BOOT,  1,  4> BOOT_ACK;          // BOOT ACK
    // 0b0..No ack
    // 0b1..Ack
constexpr USDHC1_Reg<&USDHC_Layout::MMC_BOOT,  4,  0> DTOCV_ACK;         // Boot ACK time out
    // 0b0000..SDCLK x 2^14
    // 0b0001..SDCLK x 2^15
    // 0b0010..SDCLK x 2^16
    // 0b0011..SDCLK x 2^17
    // 0b0100..SDCLK x 2^18
    // 0b0101..SDCLK x 2^19
    // 0b0110..SDCLK x 2^20
    // 0b0111..SDCLK x 2^21
    // 0b1110..SDCLK x 2^28
    // 0b1111..SDCLK x 2^29
}  // namespace MMC_BOOT

// Vendor Specific 2 Register
namespace VEND_SPEC2 {
constexpr USDHC1_Reg<&USDHC_Layout::VEND_SPEC2, 1, 12> ACMD23_ARGU2_EN;   // Argument2 register enable for ACMD23
    // 0b0..Disable
    // 0b1..Argument2 register enable for ACMD23 sharing with SDMA system address register. Default is enabled.
constexpr USDHC1_Reg<&USDHC_Layout::VEND_SPEC2, 1,  6> TUNING_CMD_EN;     // Tuning command enable
    // 0b0..Auto tuning circuit does not check the CMD line.
    // 0b1..Auto tuning circuit checks the CMD line.
constexpr USDHC1_Reg<&USDHC_Layout::VEND_SPEC2, 1,  5> TUNING_1bit_EN;    // Tuning 1bit enable
constexpr USDHC1_Reg<&USDHC_Layout::VEND_SPEC2, 1,  4> TUNING_8bit_EN;    // Tuning 8bit enable
constexpr USDHC1_Reg<&USDHC_Layout::VEND_SPEC2, 1,  3> CARD_INT_D3_TEST;  // Card interrupt detection test
    // 0b0..Check the card interrupt only when DATA3 is high.
    // 0b1..Check the card interrupt by ignoring the status of DATA3.
}  // namespace VEND_SPEC2

// Tuning Control
namespace TUNING_CTRL {
constexpr USDHC1_Reg<&USDHC_Layout::TUNING_CTRL, 1, 24> STD_TUNING_EN;               // Standard tuning circuit and procedure enable
constexpr USDHC1_Reg<&USDHC_Layout::TUNING_CTRL, 3, 20> TUNING_WINDOW;               // Data window
constexpr USDHC1_Reg<&USDHC_Layout::TUNING_CTRL, 3, 16> TUNING_STEP;                 // TUNING_STEP
constexpr USDHC1_Reg<&USDHC_Layout::TUNING_CTRL, 8,  8> TUNING_COUNTER;              // Tuning counter
constexpr USDHC1_Reg<&USDHC_Layout::TUNING_CTRL, 1,  7> DIS_CMD_CHK_FOR_STD_TUNING;  // Disable command check for standard tuning
constexpr USDHC1_Reg<&USDHC_Layout::TUNING_CTRL, 7,  0> TUNING_START_TAP;            // Tuning start
}  // namespace TUNING_CTRL

}  // namespace USDHC1

namespace USDHC2 {

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using USDHC2_Reg =
    regs::Reg32<kUSDHC2_base, USDHC_Layout, Member, 0, Bits, Shift, AssignMask>;

// DMA System Address
namespace DS_ADDR {
constexpr USDHC2_Reg<&USDHC_Layout::DS_ADDR, 32, 0> DS_ADDR;
}  // namespace DS_ADDR

// Block Attributes
namespace BLK_ATT {
constexpr USDHC2_Reg<&USDHC_Layout::BLK_ATT, 16, 16> BLKCNT;
constexpr USDHC2_Reg<&USDHC_Layout::BLK_ATT, 13,  0> BLKSIZE;
}  // namespace BLK_ATT

// Command Argument
namespace CMD_ARG {
constexpr USDHC2_Reg<&USDHC_Layout::CMD_ARG, 32, 0> CMDARG;
}  // namespace CMD_ARG

// Command Transfer Type
namespace CMD_XFR_TYP {
constexpr USDHC2_Reg<&USDHC_Layout::CMD_XFR_TYP, 6, 24> CMDINX;
constexpr USDHC2_Reg<&USDHC_Layout::CMD_XFR_TYP, 2, 22> CMDTYP;
constexpr USDHC2_Reg<&USDHC_Layout::CMD_XFR_TYP, 1, 21> DPSEL;
constexpr USDHC2_Reg<&USDHC_Layout::CMD_XFR_TYP, 1, 20> CICEN;
constexpr USDHC2_Reg<&USDHC_Layout::CMD_XFR_TYP, 1, 19> CCCEN;
constexpr USDHC2_Reg<&USDHC_Layout::CMD_XFR_TYP, 2, 16> RSPTYP;
}  // namespace CMD_XFR_TYP

// Command Response0
namespace CMD_RSP0 {
constexpr USDHC2_Reg<&USDHC_Layout::CMD_RSP0, 32, 0> CMDRSP0;
}  // namespace CMD_RSP0

// Command Response1
namespace CMD_RSP1 {
constexpr USDHC2_Reg<&USDHC_Layout::CMD_RSP1, 32, 0> CMDRSP1;
}  // namespace CMD_RSP1

// Command Response2
namespace CMD_RSP2 {
constexpr USDHC2_Reg<&USDHC_Layout::CMD_RSP2, 32, 0> CMDRSP2;
}  // namespace CMD_RSP2

// Command Response3
namespace CMD_RSP3 {
constexpr USDHC2_Reg<&USDHC_Layout::CMD_RSP3, 32, 0> CMDRSP3;
}  // namespace CMD_RSP3

// Data Buffer Access Port
namespace DATA_BUFF_ACC_PORT {
constexpr USDHC2_Reg<&USDHC_Layout::DATA_BUFF_ACC_PORT, 32, 0> DATCONT;
}  // namespace DATA_BUFF_ACC_PORT

// Present State
namespace PRES_STATE {
constexpr USDHC2_Reg<&USDHC_Layout::PRES_STATE, 8, 24> DLSL;
constexpr USDHC2_Reg<&USDHC_Layout::PRES_STATE, 1, 23> CLSL;
constexpr USDHC2_Reg<&USDHC_Layout::PRES_STATE, 1, 19> WPSPL;
constexpr USDHC2_Reg<&USDHC_Layout::PRES_STATE, 1, 18> CDPL;
constexpr USDHC2_Reg<&USDHC_Layout::PRES_STATE, 1, 16> CINST;
constexpr USDHC2_Reg<&USDHC_Layout::PRES_STATE, 1, 15> TSCD;
constexpr USDHC2_Reg<&USDHC_Layout::PRES_STATE, 1, 12> RTR;
constexpr USDHC2_Reg<&USDHC_Layout::PRES_STATE, 1, 11> BREN;
constexpr USDHC2_Reg<&USDHC_Layout::PRES_STATE, 1, 10> BWEN;
constexpr USDHC2_Reg<&USDHC_Layout::PRES_STATE, 1,  9> RTA;
constexpr USDHC2_Reg<&USDHC_Layout::PRES_STATE, 1,  8> WTA;
constexpr USDHC2_Reg<&USDHC_Layout::PRES_STATE, 1,  7> SDOFF;
constexpr USDHC2_Reg<&USDHC_Layout::PRES_STATE, 1,  6> PEROFF;
constexpr USDHC2_Reg<&USDHC_Layout::PRES_STATE, 1,  5> HCKOFF;
constexpr USDHC2_Reg<&USDHC_Layout::PRES_STATE, 1,  4> IPGOFF;
constexpr USDHC2_Reg<&USDHC_Layout::PRES_STATE, 1,  3> SDSTB;
constexpr USDHC2_Reg<&USDHC_Layout::PRES_STATE, 1,  2> DLA;
constexpr USDHC2_Reg<&USDHC_Layout::PRES_STATE, 1,  1> CDIHB;
constexpr USDHC2_Reg<&USDHC_Layout::PRES_STATE, 1,  0> CIHB;
}  // namespace PRES_STATE

// Protocol Control
namespace PROT_CTRL {
constexpr USDHC2_Reg<&USDHC_Layout::PROT_CTRL, 1, 30> NON_EXACT_BLK_RD;
constexpr USDHC2_Reg<&USDHC_Layout::PROT_CTRL, 3, 27> BURST_LEN_EN;
constexpr USDHC2_Reg<&USDHC_Layout::PROT_CTRL, 1, 26> WECRM;
constexpr USDHC2_Reg<&USDHC_Layout::PROT_CTRL, 1, 25> WECINS;
constexpr USDHC2_Reg<&USDHC_Layout::PROT_CTRL, 1, 24> WECINT;
constexpr USDHC2_Reg<&USDHC_Layout::PROT_CTRL, 1, 20> RD_DONE_NO_8CLK;
constexpr USDHC2_Reg<&USDHC_Layout::PROT_CTRL, 1, 19> IABG;
constexpr USDHC2_Reg<&USDHC_Layout::PROT_CTRL, 1, 18> RWCTL;
constexpr USDHC2_Reg<&USDHC_Layout::PROT_CTRL, 1, 17> CREQ;
constexpr USDHC2_Reg<&USDHC_Layout::PROT_CTRL, 1, 16> SABGREQ;
constexpr USDHC2_Reg<&USDHC_Layout::PROT_CTRL, 2,  8> DMASEL;
constexpr USDHC2_Reg<&USDHC_Layout::PROT_CTRL, 1,  7> CDSS;
constexpr USDHC2_Reg<&USDHC_Layout::PROT_CTRL, 1,  6> CDTL;
constexpr USDHC2_Reg<&USDHC_Layout::PROT_CTRL, 2,  4> EMODE;
constexpr USDHC2_Reg<&USDHC_Layout::PROT_CTRL, 1,  3> D3CD;
constexpr USDHC2_Reg<&USDHC_Layout::PROT_CTRL, 2,  1> DTW;
}  // namespace PROT_CTRL

// System Control
namespace SYS_CTRL {
constexpr USDHC2_Reg<&USDHC_Layout::SYS_CTRL, 1, 28> RSTT;
constexpr USDHC2_Reg<&USDHC_Layout::SYS_CTRL, 1, 27> INITA;
constexpr USDHC2_Reg<&USDHC_Layout::SYS_CTRL, 1, 26> RSTD;
constexpr USDHC2_Reg<&USDHC_Layout::SYS_CTRL, 1, 25> RSTC;
constexpr USDHC2_Reg<&USDHC_Layout::SYS_CTRL, 1, 24> RSTA;
constexpr USDHC2_Reg<&USDHC_Layout::SYS_CTRL, 1, 23> IPP_RST_N;
constexpr USDHC2_Reg<&USDHC_Layout::SYS_CTRL, 4, 16> DTOCV;
constexpr USDHC2_Reg<&USDHC_Layout::SYS_CTRL, 8,  8> SDCLKFS;
constexpr USDHC2_Reg<&USDHC_Layout::SYS_CTRL, 4,  4> DVS;
}  // namespace SYS_CTRL

// Interrupt Status
namespace INT_STATUS {
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS, 1, 28, 0x0> DMAE;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS, 1, 26, 0x0> TNE;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS, 1, 24, 0x0> AC12E;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS, 1, 22, 0x0> DEBE;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS, 1, 21, 0x0> DCE;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS, 1, 20, 0x0> DTOE;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS, 1, 19, 0x0> CIE;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS, 1, 18, 0x0> CEBE;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS, 1, 17, 0x0> CCE;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS, 1, 16, 0x0> CTOE;
constexpr USDHC2_Reg<regs::constify(&USDHC_Layout::INT_STATUS), 1, 15> ERR_INT_STATUS;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS, 1, 14, 0x0> TP;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS, 1, 12, 0x0> RTE;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS, 1,  8, 0x0> CINT;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS, 1,  7, 0x0> CRM;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS, 1,  6, 0x0> CINS;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS, 1,  5, 0x0> BRR;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS, 1,  4, 0x0> BWR;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS, 1,  3, 0x0> DINT;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS, 1,  2, 0x0> BGE;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS, 1,  1, 0x0> TC;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS, 1,  0, 0x0> CC;
}  // namespace INT_STATUS

// Interrupt Status Enable
namespace INT_STATUS_EN {
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS_EN, 1, 28> DMAESEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS_EN, 1, 26> TNESEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS_EN, 1, 24> AC12ESEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS_EN, 1, 22> DEBESEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS_EN, 1, 21> DCESEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS_EN, 1, 20> DTOESEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS_EN, 1, 19> CIESEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS_EN, 1, 18> CEBESEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS_EN, 1, 17> CCESEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS_EN, 1, 16> CTOESEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS_EN, 1, 14> TPSEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS_EN, 1, 12> RTESEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS_EN, 1,  8> CINTSEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS_EN, 1,  7> CRMSEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS_EN, 1,  6> CINSSEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS_EN, 1,  5> BRRSEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS_EN, 1,  4> BWRSEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS_EN, 1,  3> DINTSEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS_EN, 1,  2> BGESEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS_EN, 1,  1> TCSEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_STATUS_EN, 1,  0> CCSEN;
}  // namespace INT_STATUS_EN

// Interrupt Signal Enable
namespace INT_SIGNAL_EN {
constexpr USDHC2_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1, 28> DMAEIEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1, 26> TNEIEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1, 24> AC12EIEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1, 22> DEBEIEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1, 21> DCEIEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1, 20> DTOEIEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1, 19> CIEIEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1, 18> CEBEIEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1, 17> CCEIEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1, 16> CTOEIEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1, 14> TPIEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1, 12> RTEIEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1,  8> CINTIEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1,  7> CRMIEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1,  6> CINSIEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1,  5> BRRIEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1,  4> BWRIEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1,  3> DINTIEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1,  2> BGEIEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1,  1> TCIEN;
constexpr USDHC2_Reg<&USDHC_Layout::INT_SIGNAL_EN, 1,  0> CCIEN;
}  // namespace INT_SIGNAL_EN

// Auto CMD12 Error Status
namespace AUTOCMD12_ERR_STATUS {
constexpr USDHC2_Reg<&USDHC_Layout::AUTOCMD12_ERR_STATUS, 1, 23> SMP_CLK_SEL;
constexpr USDHC2_Reg<&USDHC_Layout::AUTOCMD12_ERR_STATUS, 1, 22> EXECUTE_TUNING;
constexpr USDHC2_Reg<regs::constify(&USDHC_Layout::AUTOCMD12_ERR_STATUS), 1,  7> CNIBAC12E;
constexpr USDHC2_Reg<regs::constify(&USDHC_Layout::AUTOCMD12_ERR_STATUS), 1,  4> AC12IE;
constexpr USDHC2_Reg<regs::constify(&USDHC_Layout::AUTOCMD12_ERR_STATUS), 1,  3> AC12CE;
constexpr USDHC2_Reg<regs::constify(&USDHC_Layout::AUTOCMD12_ERR_STATUS), 1,  2> AC12EBE;
constexpr USDHC2_Reg<regs::constify(&USDHC_Layout::AUTOCMD12_ERR_STATUS), 1,  1> AC12TOE;
constexpr USDHC2_Reg<regs::constify(&USDHC_Layout::AUTOCMD12_ERR_STATUS), 1,  0> AC12NE;
}  // namespace AUTOCMD12_ERR_STATUS

// Host Controller Capabilities
namespace HOST_CTRL_CAP {
constexpr USDHC2_Reg<regs::constify(&USDHC_Layout::HOST_CTRL_CAP), 1, 26> VS18;
constexpr USDHC2_Reg<regs::constify(&USDHC_Layout::HOST_CTRL_CAP), 1, 25> VS30;
constexpr USDHC2_Reg<regs::constify(&USDHC_Layout::HOST_CTRL_CAP), 1, 24> VS33;
constexpr USDHC2_Reg<regs::constify(&USDHC_Layout::HOST_CTRL_CAP), 1, 23> SRS;
constexpr USDHC2_Reg<regs::constify(&USDHC_Layout::HOST_CTRL_CAP), 1, 22> DMAS;
constexpr USDHC2_Reg<regs::constify(&USDHC_Layout::HOST_CTRL_CAP), 1, 21> HSS;
constexpr USDHC2_Reg<regs::constify(&USDHC_Layout::HOST_CTRL_CAP), 1, 20> ADMAS;
constexpr USDHC2_Reg<regs::constify(&USDHC_Layout::HOST_CTRL_CAP), 3, 16> MBL;
constexpr USDHC2_Reg<&USDHC_Layout::HOST_CTRL_CAP, 1, 13> USE_TUNING_SDR50;
constexpr USDHC2_Reg<regs::constify(&USDHC_Layout::HOST_CTRL_CAP), 1,  2> DDR50_SUPPORT;
constexpr USDHC2_Reg<regs::constify(&USDHC_Layout::HOST_CTRL_CAP), 1,  1> SDR104_SUPPORT;
constexpr USDHC2_Reg<regs::constify(&USDHC_Layout::HOST_CTRL_CAP), 1,  0> SDR50_SUPPORT;
}  // namespace HOST_CTRL_CAP

// Watermark Level
namespace WTMK_LVL {
constexpr USDHC2_Reg<&USDHC_Layout::WTMK_LVL, 5, 24> WR_BRST_LEN;
constexpr USDHC2_Reg<&USDHC_Layout::WTMK_LVL, 8, 16> WR_WML;
constexpr USDHC2_Reg<&USDHC_Layout::WTMK_LVL, 5,  8> RD_BRST_LEN;
constexpr USDHC2_Reg<&USDHC_Layout::WTMK_LVL, 8,  0> RD_WML;
}  // namespace WTMK_LVL

// Mixer Control
namespace MIX_CTRL {
constexpr USDHC2_Reg<&USDHC_Layout::MIX_CTRL, 1, 25> FBCLK_SEL;
constexpr USDHC2_Reg<&USDHC_Layout::MIX_CTRL, 1, 24> AUTO_TUNE_EN;
constexpr USDHC2_Reg<&USDHC_Layout::MIX_CTRL, 1, 23> SMP_CLK_SEL;
constexpr USDHC2_Reg<&USDHC_Layout::MIX_CTRL, 1, 22> EXE_TUNE;
constexpr USDHC2_Reg<&USDHC_Layout::MIX_CTRL, 1,  7> AC23EN;
constexpr USDHC2_Reg<&USDHC_Layout::MIX_CTRL, 1,  6> NIBBLE_POS;
constexpr USDHC2_Reg<&USDHC_Layout::MIX_CTRL, 1,  5> MSBSEL;
constexpr USDHC2_Reg<&USDHC_Layout::MIX_CTRL, 1,  4> DTDSEL;
constexpr USDHC2_Reg<&USDHC_Layout::MIX_CTRL, 1,  3> DDR_EN;
constexpr USDHC2_Reg<&USDHC_Layout::MIX_CTRL, 1,  2> AC12EN;
constexpr USDHC2_Reg<&USDHC_Layout::MIX_CTRL, 1,  1> BCEN;
constexpr USDHC2_Reg<&USDHC_Layout::MIX_CTRL, 1,  0> DMAEN;
}  // namespace MIX_CTRL

// Force Event
namespace FORCE_EVENT {
constexpr USDHC2_Reg<&USDHC_Layout::FORCE_EVENT, 1, 31, 0x0> FEVTCINT;
constexpr USDHC2_Reg<&USDHC_Layout::FORCE_EVENT, 1, 28, 0x0> FEVTDMAE;
constexpr USDHC2_Reg<&USDHC_Layout::FORCE_EVENT, 1, 26, 0x0> FEVTTNE;
constexpr USDHC2_Reg<&USDHC_Layout::FORCE_EVENT, 1, 24, 0x0> FEVTAC12E;
constexpr USDHC2_Reg<&USDHC_Layout::FORCE_EVENT, 1, 22, 0x0> FEVTDEBE;
constexpr USDHC2_Reg<&USDHC_Layout::FORCE_EVENT, 1, 21, 0x0> FEVTDCE;
constexpr USDHC2_Reg<&USDHC_Layout::FORCE_EVENT, 1, 20, 0x0> FEVTDTOE;
constexpr USDHC2_Reg<&USDHC_Layout::FORCE_EVENT, 1, 19, 0x0> FEVTCIE;
constexpr USDHC2_Reg<&USDHC_Layout::FORCE_EVENT, 1, 18, 0x0> FEVTCEBE;
constexpr USDHC2_Reg<&USDHC_Layout::FORCE_EVENT, 1, 17, 0x0> FEVTCCE;
constexpr USDHC2_Reg<&USDHC_Layout::FORCE_EVENT, 1, 16, 0x0> FEVTCTOE;
constexpr USDHC2_Reg<&USDHC_Layout::FORCE_EVENT, 1,  7, 0x0> FEVTCNIBAC12E;
constexpr USDHC2_Reg<&USDHC_Layout::FORCE_EVENT, 1,  4, 0x0> FEVTAC12IE;
constexpr USDHC2_Reg<&USDHC_Layout::FORCE_EVENT, 1,  3, 0x0> FEVTAC12EBE;
constexpr USDHC2_Reg<&USDHC_Layout::FORCE_EVENT, 1,  2, 0x0> FEVTAC12CE;
constexpr USDHC2_Reg<&USDHC_Layout::FORCE_EVENT, 1,  1, 0x0> FEVTAC12TOE;
constexpr USDHC2_Reg<&USDHC_Layout::FORCE_EVENT, 1,  0, 0x0> FEVTAC12NE;
}  // namespace FORCE_EVENT

// ADMA Error Status
namespace ADMA_ERR_STATUS {
constexpr USDHC2_Reg<&USDHC_Layout::ADMA_ERR_STATUS, 1, 3> ADMADCE;
constexpr USDHC2_Reg<&USDHC_Layout::ADMA_ERR_STATUS, 1, 2> ADMALME;
constexpr USDHC2_Reg<&USDHC_Layout::ADMA_ERR_STATUS, 2, 0> ADMAES;
}  // namespace ADMA_ERR_STATUS

// ADMA System Address
namespace ADMA_SYS_ADDR {
constexpr USDHC2_Reg<&USDHC_Layout::ADMA_SYS_ADDR, 30, 2> ADS_ADDR;
}  // namespace ADMA_SYS_ADDR

// DLL (Delay Line) Control
namespace DLL_CTRL {
constexpr USDHC2_Reg<&USDHC_Layout::DLL_CTRL, 4, 28> DLL_CTRL_REF_UPDATE_INT;
constexpr USDHC2_Reg<&USDHC_Layout::DLL_CTRL, 8, 20> DLL_CTRL_SLV_UPDATE_INT;
constexpr USDHC2_Reg<&USDHC_Layout::DLL_CTRL, 3, 16> DLL_CTRL_SLV_DLY_TARGET1;
constexpr USDHC2_Reg<&USDHC_Layout::DLL_CTRL, 7,  9> DLL_CTRL_SLV_OVERRIDE_VAL;
constexpr USDHC2_Reg<&USDHC_Layout::DLL_CTRL, 1,  8> DLL_CTRL_SLV_OVERRIDE;
constexpr USDHC2_Reg<&USDHC_Layout::DLL_CTRL, 1,  7> DLL_CTRL_GATE_UPDATE;
constexpr USDHC2_Reg<&USDHC_Layout::DLL_CTRL, 4,  3> DLL_CTRL_SLV_DLY_TARGET0;
constexpr USDHC2_Reg<&USDHC_Layout::DLL_CTRL, 1,  2> DLL_CTRL_SLV_FORCE_UPD;
constexpr USDHC2_Reg<&USDHC_Layout::DLL_CTRL, 1,  1> DLL_CTRL_RESET;
constexpr USDHC2_Reg<&USDHC_Layout::DLL_CTRL, 1,  0> DLL_CTRL_ENABLE;
}  // namespace DLL_CTRL

// DLL Status
namespace DLL_STATUS {
constexpr USDHC2_Reg<&USDHC_Layout::DLL_STATUS, 7, 9> DLL_STS_REF_SEL;
constexpr USDHC2_Reg<&USDHC_Layout::DLL_STATUS, 7, 2> DLL_STS_SLV_SEL;
constexpr USDHC2_Reg<&USDHC_Layout::DLL_STATUS, 1, 1> DLL_STS_REF_LOCK;
constexpr USDHC2_Reg<&USDHC_Layout::DLL_STATUS, 1, 0> DLL_STS_SLV_LOCK;
}  // namespace DLL_STATUS

// CLK Tuning Control and Status
namespace CLK_TUNE_CTRL_STATUS {
constexpr USDHC2_Reg<regs::constify(&USDHC_Layout::CLK_TUNE_CTRL_STATUS), 1, 31> PRE_ERR;
constexpr USDHC2_Reg<regs::constify(&USDHC_Layout::CLK_TUNE_CTRL_STATUS), 7, 24> TAP_SEL_PRE;
constexpr USDHC2_Reg<regs::constify(&USDHC_Layout::CLK_TUNE_CTRL_STATUS), 4, 20> TAP_SEL_OUT;
constexpr USDHC2_Reg<regs::constify(&USDHC_Layout::CLK_TUNE_CTRL_STATUS), 4, 16> TAP_SEL_POST;
constexpr USDHC2_Reg<regs::constify(&USDHC_Layout::CLK_TUNE_CTRL_STATUS), 1, 15> NXT_ERR;
constexpr USDHC2_Reg<&USDHC_Layout::CLK_TUNE_CTRL_STATUS, 7,  8> DLY_CELL_SET_PRE;
constexpr USDHC2_Reg<&USDHC_Layout::CLK_TUNE_CTRL_STATUS, 4,  4> DLY_CELL_SET_OUT;
constexpr USDHC2_Reg<&USDHC_Layout::CLK_TUNE_CTRL_STATUS, 4,  0> DLY_CELL_SET_POST;
}  // namespace CLK_TUNE_CTRL_STATUS

// Vendor Specific Register
namespace VEND_SPEC {
constexpr USDHC2_Reg<&USDHC_Layout::VEND_SPEC, 1, 31> CMD_BYTE_EN;
constexpr USDHC2_Reg<&USDHC_Layout::VEND_SPEC, 1, 15> CRC_CHK_DIS;
constexpr USDHC2_Reg<&USDHC_Layout::VEND_SPEC, 1,  8> FRC_SDCLK_ON;
constexpr USDHC2_Reg<&USDHC_Layout::VEND_SPEC, 1,  3> AC12_WR_CHKBUSY_EN;
constexpr USDHC2_Reg<&USDHC_Layout::VEND_SPEC, 1,  2> CONFLICT_CHK_EN;
constexpr USDHC2_Reg<&USDHC_Layout::VEND_SPEC, 1,  1> VSELECT;
}  // namespace VEND_SPEC

// eMMC Boot
namespace MMC_BOOT {
constexpr USDHC2_Reg<&USDHC_Layout::MMC_BOOT, 16, 16> BOOT_BLK_CNT;
constexpr USDHC2_Reg<&USDHC_Layout::MMC_BOOT,  1,  8> DISABLE_TIME_OUT;
constexpr USDHC2_Reg<&USDHC_Layout::MMC_BOOT,  1,  7> AUTO_SABG_EN;
constexpr USDHC2_Reg<&USDHC_Layout::MMC_BOOT,  1,  6> BOOT_EN;
constexpr USDHC2_Reg<&USDHC_Layout::MMC_BOOT,  1,  5> BOOT_MODE;
constexpr USDHC2_Reg<&USDHC_Layout::MMC_BOOT,  1,  4> BOOT_ACK;
constexpr USDHC2_Reg<&USDHC_Layout::MMC_BOOT,  4,  0> DTOCV_ACK;
}  // namespace MMC_BOOT

// Vendor Specific 2 Register
namespace VEND_SPEC2 {
constexpr USDHC2_Reg<&USDHC_Layout::VEND_SPEC2, 1, 12> ACMD23_ARGU2_EN;
constexpr USDHC2_Reg<&USDHC_Layout::VEND_SPEC2, 1,  6> TUNING_CMD_EN;
constexpr USDHC2_Reg<&USDHC_Layout::VEND_SPEC2, 1,  5> TUNING_1bit_EN;
constexpr USDHC2_Reg<&USDHC_Layout::VEND_SPEC2, 1,  4> TUNING_8bit_EN;
constexpr USDHC2_Reg<&USDHC_Layout::VEND_SPEC2, 1,  3> CARD_INT_D3_TEST;
}  // namespace VEND_SPEC2

// Tuning Control
namespace TUNING_CTRL {
constexpr USDHC2_Reg<&USDHC_Layout::TUNING_CTRL, 1, 24> STD_TUNING_EN;
constexpr USDHC2_Reg<&USDHC_Layout::TUNING_CTRL, 3, 20> TUNING_WINDOW;
constexpr USDHC2_Reg<&USDHC_Layout::TUNING_CTRL, 3, 16> TUNING_STEP;
constexpr USDHC2_Reg<&USDHC_Layout::TUNING_CTRL, 8,  8> TUNING_COUNTER;
constexpr USDHC2_Reg<&USDHC_Layout::TUNING_CTRL, 1,  7> DIS_CMD_CHK_FOR_STD_TUNING;
constexpr USDHC2_Reg<&USDHC_Layout::TUNING_CTRL, 7,  0> TUNING_START_TAP;
}  // namespace TUNING_CTRL

}  // namespace USDHC2

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
