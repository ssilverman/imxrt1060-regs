// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// BEE.h defines all the BEE registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "qindesign/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the Bus Encryption Engine (BEE) registers.
//
// Comments are from BSD-3-licensed NXP SDK sources.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_BEE.h
// * https://github.com/nxp-mcuxpresso/mcux-soc-svd/blob/main/MIMXRT1062/MIMXRT1062.xml
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct BEE_Layout {
  volatile uint32_t CTRL;                              /**< Control Register, offset: 0x0 */
  volatile uint32_t ADDR_OFFSET0;                      /**< Offset region 0 Register, offset: 0x4 */
  volatile uint32_t ADDR_OFFSET1;                      /**< Offset region 1 Register, offset: 0x8 */
  volatile uint32_t AES_KEY0_W0;                       /**< AES Key 0 Register, offset: 0xC */
  volatile uint32_t AES_KEY0_W1;                       /**< AES Key 1 Register, offset: 0x10 */
  volatile uint32_t AES_KEY0_W2;                       /**< AES Key 2 Register, offset: 0x14 */
  volatile uint32_t AES_KEY0_W3;                       /**< AES Key 3 Register, offset: 0x18 */
  volatile uint32_t STATUS;                            /**< Status Register, offset: 0x1C */
  volatile uint32_t CTR_NONCE0_W0;                     /**< NONCE00 Register, offset: 0x20 */
  volatile uint32_t CTR_NONCE0_W1;                     /**< NONCE01 Register, offset: 0x24 */
  volatile uint32_t CTR_NONCE0_W2;                     /**< NONCE02 Register, offset: 0x28 */
  volatile uint32_t CTR_NONCE0_W3;                     /**< NONCE03 Register, offset: 0x2C */
  volatile uint32_t CTR_NONCE1_W0;                     /**< NONCE10 Register, offset: 0x30 */
  volatile uint32_t CTR_NONCE1_W1;                     /**< NONCE11 Register, offset: 0x34 */
  volatile uint32_t CTR_NONCE1_W2;                     /**< NONCE12 Register, offset: 0x38 */
  volatile uint32_t CTR_NONCE1_W3;                     /**< NONCE13 Register, offset: 0x3C */
  volatile uint32_t REGION1_TOP;                       /**< Region1 Top Address Register, offset: 0x40 */
  volatile uint32_t REGION1_BOT;                       /**< Region1 Bottom Address Register, offset: 0x44 */
};

constexpr size_t    kBEE_size = 0x48;
constexpr uintptr_t kBEE_base = 0x403E'C000;

namespace BEE {
constexpr regs::RegGroup<BEE_Layout, kBEE_size, kBEE_base> group;

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>(),
          bool WriteOnly = false>
using BEE_Reg =
    regs::Reg32<kBEE_base, BEE_Layout, Member, 0, Bits, Shift, AssignMask, 0,
                WriteOnly>;

// Control Register
namespace CTRL {
constexpr BEE_Reg<&BEE_Layout::CTRL, 1, 31> REGION1_KEY_LOCK;        // Lock bit for region1 AES key
constexpr BEE_Reg<&BEE_Layout::CTRL, 1, 30> CTRL_AES_MODE_R1_LOCK;   // Lock bit for region1 ctrl_aes_mode
constexpr BEE_Reg<&BEE_Layout::CTRL, 2, 28> SECURITY_LEVEL_R1_LOCK;  // Lock bits for security_level_r1
constexpr BEE_Reg<&BEE_Layout::CTRL, 1, 27> REGION0_KEY_LOCK;        // Lock bit for region0 AES key
constexpr BEE_Reg<&BEE_Layout::CTRL, 1, 26> CTRL_AES_MODE_R0_LOCK;   // Lock bit for region0 ctrl_aes_mode
constexpr BEE_Reg<&BEE_Layout::CTRL, 2, 24> SECURITY_LEVEL_R0_LOCK;  // Lock bits for security_level_r0
constexpr BEE_Reg<&BEE_Layout::CTRL, 1, 23> LITTLE_ENDIAN_LOCK;      // Lock bit for little_endian
constexpr BEE_Reg<&BEE_Layout::CTRL, 1, 22> AC_PROT_EN_LOCK;         // Lock bit for ac_prot
constexpr BEE_Reg<&BEE_Layout::CTRL, 1, 21> KEY_REGION_SEL_LOCK;     // Lock bit for key_region_sel
constexpr BEE_Reg<&BEE_Layout::CTRL, 1, 20> KEY_VALID_LOCK;          // Lock bit for key_valid
constexpr BEE_Reg<&BEE_Layout::CTRL, 1, 19> REGION1_ADDR_LOCK;       // Lock bit for region1 address boundary
constexpr BEE_Reg<&BEE_Layout::CTRL, 1, 18> CTRL_SFTRST_N_LOCK;      // Lock bit for ctrl_sftrst
constexpr BEE_Reg<&BEE_Layout::CTRL, 1, 17> CTRL_CLK_EN_LOCK;        // Lock bit for ctrl_clk_en
constexpr BEE_Reg<&BEE_Layout::CTRL, 1, 16> BEE_ENABLE_LOCK;         // Lock bit for bee_enable
constexpr BEE_Reg<&BEE_Layout::CTRL, 1, 14> CTRL_AES_MODE_R1;        // AES mode of region1
    // 0b0..ECB
    // 0b1..CTR
constexpr BEE_Reg<&BEE_Layout::CTRL, 2, 12> SECURITY_LEVEL_R1;       // Security level of the allowed access for memory region1
constexpr BEE_Reg<&BEE_Layout::CTRL, 1, 10> CTRL_AES_MODE_R0;        // AES mode of region0
    // 0b0..ECB
    // 0b1..CTR
constexpr BEE_Reg<&BEE_Layout::CTRL, 2,  8> SECURITY_LEVEL_R0;       // Security level of the allowed access for memory region0
constexpr BEE_Reg<&BEE_Layout::CTRL, 1,  7> LITTLE_ENDIAN_MODE;      // Endian swap control for the 16 bytes input and output data of AES core.
    // Originally "LITTLE_ENDIAN", but this might conflict with some compiler definitions
    // 0b0..The input and output data of the AES core is swapped as below: {B15,B14,B13,B12,B11,B10,B9,B8,
    // B7,B6,B5,B4,B3,B2,B1,B0} swap to {B0,B1,B2,B3,B4,B5,B6,B7, B8,B9,B10,B11,B12,B13,B14,B15}, where B0~B15 refers to
    // Byte0 to Byte15.
    // 0b1..The input and output data of AES core is not swapped.
constexpr BEE_Reg<&BEE_Layout::CTRL, 1,  6> AC_PROT_EN;              // Access permission control enable; when enabled, encrypted regions are limited to Arm core access
constexpr BEE_Reg<&BEE_Layout::CTRL, 1,  5> KEY_REGION_SEL;          // AES key region select
    // 0b0..Load AES key for region0
    // 0b1..Load AES key for region1
constexpr BEE_Reg<&BEE_Layout::CTRL, 1,  4> KEY_VALID;               // AES-128 key ready; load the key by changing this bit from 0 to 1
constexpr BEE_Reg<&BEE_Layout::CTRL, 1,  2> CTRL_SFTRST_N;           // Soft reset input, low active
constexpr BEE_Reg<&BEE_Layout::CTRL, 1,  1> CTRL_CLK_EN;             // Clock enable input, low inactive
constexpr BEE_Reg<&BEE_Layout::CTRL, 1,  0> BEE_ENABLE;              // BEE enable bit
    // 0b0..Disable BEE
    // 0b1..Enable BEE
}  // namespace CTRL

// Offset region 0 Register
namespace ADDR_OFFSET0 {
constexpr BEE_Reg<&BEE_Layout::ADDR_OFFSET0, 16, 16> ADDR_OFFSET0_LOCK;  // Lock bits for addr_offset0
constexpr BEE_Reg<&BEE_Layout::ADDR_OFFSET0, 16,  0> ADDR_OFFSET0;       // Signed offset for BEE region 0
}  // namespace ADDR_OFFSET0

// Offset region 1 Register
namespace ADDR_OFFSET1 {
constexpr BEE_Reg<&BEE_Layout::ADDR_OFFSET1, 16, 16> ADDR_OFFSET1_LOCK;  // Lock bits for addr_offset1
constexpr BEE_Reg<&BEE_Layout::ADDR_OFFSET1, 16,  0> ADDR_OFFSET1;       // Signed offset for BEE region 1
}  // namespace ADDR_OFFSET1

// AES Key 0 Register
namespace AES_KEY0_W0 {
constexpr BEE_Reg<&BEE_Layout::AES_KEY0_W0, 32, 0, 0x0, true> KEY0;  // AES 128 key from software
}  // namespace AES_KEY0_W0

// AES Key 1 Register
namespace AES_KEY0_W1 {
constexpr BEE_Reg<&BEE_Layout::AES_KEY0_W1, 32, 0, 0x0, true> KEY1;  // AES 128 key from software
}  // namespace AES_KEY0_W1

// AES Key 2 Register
namespace AES_KEY0_W2 {
constexpr BEE_Reg<&BEE_Layout::AES_KEY0_W2, 32, 0, 0x0, true> KEY2;  // AES 128 key from software
}  // namespace AES_KEY0_W2

// AES Key 3 Register
namespace AES_KEY0_W3 {
constexpr BEE_Reg<&BEE_Layout::AES_KEY0_W3, 32, 0, 0x0, true> KEY3;  // AES 128 key from software
}  // namespace AES_KEY0_W3

// Status Register
namespace STATUS {
constexpr BEE_Reg<regs::constify(&BEE_Layout::STATUS), 1, 8> BEE_IDLE;  // BEE idle status
    // 0b0..BEE is active.
    // 0b1..BEE is idle.
constexpr BEE_Reg<&BEE_Layout::STATUS, 8, 0, 0x0> IRQ_VEC;              // Access violation and abort interrupt vector
    // Bit 7: Protected region 3 access violation.
    // Bit 6: Protected region 2 access violation.
    // Bit 5: Protected region 1 access violation.
    // Bit 4: Protected region 0 access violation.
    // Bit 3: Region 1 read-channel security violation.
    // Bit 2: Read-channel illegal access detected.
    // Bit 1: Region 0 read-channel security violation.
    // Bit 0: Disable abort.
    // Writing 1 clears the corresponding status bit.
}  // namespace STATUS

// NONCE00 Register
namespace CTR_NONCE0_W0 {
constexpr BEE_Reg<&BEE_Layout::CTR_NONCE0_W0, 32, 0, 0x0, true> NONCE00;  // Nonce0 from software for CTR, for region0.
    // Nonce0={Nonce03,Nonce02,Nonce01,Nonce00}
}  // namespace CTR_NONCE0_W0

// NONCE01 Register
namespace CTR_NONCE0_W1 {
constexpr BEE_Reg<&BEE_Layout::CTR_NONCE0_W1, 32, 0, 0x0, true> NONCE01;  // Nonce0 from software for CTR, for region0.
    // Nonce0={Nonce03,Nonce02,Nonce01,Nonce00}
}  // namespace CTR_NONCE0_W1

// NONCE02 Register
namespace CTR_NONCE0_W2 {
constexpr BEE_Reg<&BEE_Layout::CTR_NONCE0_W2, 32, 0, 0x0, true> NONCE02;  // Nonce0 from software for CTR, for region0.
    // Nonce0={Nonce03,Nonce02,Nonce01,Nonce00}
}  // namespace CTR_NONCE0_W2

// NONCE03 Register
namespace CTR_NONCE0_W3 {
constexpr BEE_Reg<&BEE_Layout::CTR_NONCE0_W3, 32, 0, 0x0, true> NONCE03;  // Nonce0 from software for CTR, for region0.
    // Nonce0={Nonce03,Nonce02,Nonce01,Nonce00}
}  // namespace CTR_NONCE0_W3

// NONCE10 Register
namespace CTR_NONCE1_W0 {
constexpr BEE_Reg<&BEE_Layout::CTR_NONCE1_W0, 32, 0, 0x0, true> NONCE10;  // Nonce1 from software for CTR, for region1.
    // Nonce1={Nonce13,Nonce12,Nonce11,Nonce10}
}  // namespace CTR_NONCE1_W0

// NONCE11 Register
namespace CTR_NONCE1_W1 {
constexpr BEE_Reg<&BEE_Layout::CTR_NONCE1_W1, 32, 0, 0x0, true> NONCE11;  // Nonce1 from software for CTR, for region1.
    // Nonce1={Nonce13,Nonce12,Nonce11,Nonce10}
}  // namespace CTR_NONCE1_W1

// NONCE12 Register
namespace CTR_NONCE1_W2 {
constexpr BEE_Reg<&BEE_Layout::CTR_NONCE1_W2, 32, 0, 0x0, true> NONCE12;  // Nonce1 from software for CTR, for region1.
    // Nonce1={Nonce13,Nonce12,Nonce11,Nonce10}
}  // namespace CTR_NONCE1_W2

// NONCE13 Register
namespace CTR_NONCE1_W3 {
constexpr BEE_Reg<&BEE_Layout::CTR_NONCE1_W3, 32, 0, 0x0, true> NONCE13;  // Nonce1 from software for CTR, for region1.
    // Nonce1={Nonce13,Nonce12,Nonce11,Nonce10}
}  // namespace CTR_NONCE1_W3

// Region1 Top Address Register
namespace REGION1_TOP {
constexpr BEE_Reg<&BEE_Layout::REGION1_TOP, 32, 0> REGION1_TOP;  // Address upper limit of region1
}  // namespace REGION1_TOP

// Region1 Bottom Address Register
namespace REGION1_BOT {
constexpr BEE_Reg<&BEE_Layout::REGION1_BOT, 32, 0> REGION1_BOT;  // Address lower limit of region1
}  // namespace REGION1_BOT

}  // namespace BEE

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
