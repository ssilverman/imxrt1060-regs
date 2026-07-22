// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// ADC.h defines all the ADC registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Size of Registers Arrays
constexpr size_t kADC_HC_count = 8;
constexpr size_t kADC_R_count  = 8;

// ADC layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_ADC.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct ADC_Layout {
  volatile uint32_t HC[kADC_HC_count];                  /**< Control register for hardware triggers, array offset: 0x0, array step: 0x4 */
  const volatile uint32_t HS;                           /**< Status register for HW triggers, offset: 0x20 */
  const volatile uint32_t R[kADC_R_count];              /**< Data result register for HW triggers, array offset: 0x24, array step: 0x4 */
  volatile uint32_t CFG;                                /**< Configuration register, offset: 0x44 */
  volatile uint32_t GC;                                 /**< General control register, offset: 0x48 */
  volatile uint32_t GS;                                 /**< General status register, offset: 0x4C */
  volatile uint32_t CV;                                 /**< Compare value register, offset: 0x50 */
  volatile uint32_t OFS;                                /**< Offset correction value register, offset: 0x54 */
  volatile uint32_t CAL;                                /**< Calibration value register, offset: 0x58 */
};

constexpr size_t    kADC_size  = 0x5C;
constexpr uintptr_t kADC1_base = 0x400C4000;
constexpr uintptr_t kADC2_base = 0x400C8000;

namespace ADC1 {
constexpr regs::RegGroup<ADC_Layout, kADC_size, kADC1_base> group;
}  // namespace ADC1

namespace ADC2 {
constexpr regs::RegGroup<ADC_Layout, kADC_size, kADC2_base> group;
}  // namespace ADC2

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using ADC1_Reg =
    regs::Reg32<kADC1_base, ADC_Layout, Member, 0, Bits, Shift, DirectAssign>;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using ADC2_Reg =
    regs::Reg32<kADC2_base, ADC_Layout, Member, 0, Bits, Shift, DirectAssign>;

namespace ADC1 {

// Status register for HW triggers
namespace HS {
constexpr ADC1_Reg<&ADC_Layout::HS, 1, 7> COCO7;
constexpr ADC1_Reg<&ADC_Layout::HS, 1, 6> COCO6;
constexpr ADC1_Reg<&ADC_Layout::HS, 1, 5> COCO5;
constexpr ADC1_Reg<&ADC_Layout::HS, 1, 4> COCO4;
constexpr ADC1_Reg<&ADC_Layout::HS, 1, 3> COCO3;
constexpr ADC1_Reg<&ADC_Layout::HS, 1, 2> COCO2;
constexpr ADC1_Reg<&ADC_Layout::HS, 1, 1> COCO1;  // Conversion Complete Flag
constexpr ADC1_Reg<&ADC_Layout::HS, 1, 0> COCO0;  // Conversion Complete Flag
}  // namespace HS

// Configuration register
namespace CFG {
constexpr ADC1_Reg<&ADC_Layout::CFG, 1, 16> OVWREN;  // Data Overwrite Enable
    // 0b0..Disable the overwriting. Existing Data in Data result register will not be overwritten by subsequent converted data.
    // 0b1..Enable the overwriting.
constexpr ADC1_Reg<&ADC_Layout::CFG, 2, 14> AVGS;    // Hardware Average select
    // 0b00..4 samples averaged
    // 0b01..8 samples averaged
    // 0b10..16 samples averaged
    // 0b11..32 samples averaged
constexpr ADC1_Reg<&ADC_Layout::CFG, 1, 13> ADTRG;   // Conversion Trigger Select
    // 0b0..Software trigger selected
    // 0b1..Hardware trigger selected
constexpr ADC1_Reg<&ADC_Layout::CFG, 2, 11> REFSEL;  // Voltage Reference Selection
    // 0b00..Selects VREFH/VREFL as reference voltage.
    // 0b01..Reserved
    // 0b10..Reserved
    // 0b11..Reserved
constexpr ADC1_Reg<&ADC_Layout::CFG, 1, 10> ADHSC;   // High Speed Configuration
    // 0b0..Normal conversion selected.
    // 0b1..High speed conversion selected.
constexpr ADC1_Reg<&ADC_Layout::CFG, 2,  8> ADSTS;
    // 0b00..Sample period (ADC clocks) = 3 if ADLSMP=0b Sample period (ADC clocks) = 13 if ADLSMP=1b
    // 0b01..Sample period (ADC clocks) = 5 if ADLSMP=0b Sample period (ADC clocks) = 17 if ADLSMP=1b
    // 0b10..Sample period (ADC clocks) = 7 if ADLSMP=0b Sample period (ADC clocks) = 21 if ADLSMP=1b
    // 0b11..Sample period (ADC clocks) = 9 if ADLSMP=0b Sample period (ADC clocks) = 25 if ADLSMP=1b
constexpr ADC1_Reg<&ADC_Layout::CFG, 1,  7> ADLPC;   // Low-Power Configuration
    // 0b0..ADC hard block not in low power mode.
    // 0b1..ADC hard block in low power mode.
constexpr ADC1_Reg<&ADC_Layout::CFG, 2,  5> ADIV;    // Clock Divide Select
    // 0b00..Input clock
    // 0b01..Input clock / 2
    // 0b10..Input clock / 4
    // 0b11..Input clock / 8
constexpr ADC1_Reg<&ADC_Layout::CFG, 1,  4> ADLSMP;  // Long Sample Time Configuration
    // 0b0..Short sample mode.
    // 0b1..Long sample mode.
constexpr ADC1_Reg<&ADC_Layout::CFG, 2,  2> MODE;    // Conversion Mode Selection
    // 0b00..8-bit conversion
    // 0b01..10-bit conversion
    // 0b10..12-bit conversion
    // 0b11..Reserved
constexpr ADC1_Reg<&ADC_Layout::CFG, 2,  0> ADICLK;  // Input Clock Select
    // 0b00..IPG clock
    // 0b01..IPG clock divided by 2
    // 0b10..Reserved
    // 0b11..Asynchronous clock (ADACK)
}  // namespace CFG

// General control register
namespace GC {
constexpr ADC1_Reg<&ADC_Layout::GC, 1, 7> CAL;      // Calibration
constexpr ADC1_Reg<&ADC_Layout::GC, 1, 6> ADCO;     // Continuous Conversion Enable
    // 0b0..One conversion or one set of conversions if the hardware average function is enabled (AVGE=1) after initiating a conversion.
    // 0b1..Continuous conversions or sets of conversions if the hardware average function is enabled (AVGE=1) after initiating a conversion.
constexpr ADC1_Reg<&ADC_Layout::GC, 1, 5> AVGE;     // Hardware average enable
    // 0b0..Hardware average function disabled
    // 0b1..Hardware average function enabled
constexpr ADC1_Reg<&ADC_Layout::GC, 1, 4> ACFE;     // Compare Function Enable
    // 0b0..Compare function disabled
    // 0b1..Compare function enabled
constexpr ADC1_Reg<&ADC_Layout::GC, 1, 3> ACFGT;    // Compare Function Greater Than Enable
    // 0b0..Configures "Less Than Threshold, Outside Range Not Inclusive and Inside Range Not Inclusive"
    //      functionality based on the values placed in the ADC_CV register.
    // 0b1..Configures "Greater Than Or Equal To Threshold, Outside Range Inclusive and Inside Range Inclusive"
    //      functionality based on the values placed in the ADC_CV registers.
constexpr ADC1_Reg<&ADC_Layout::GC, 1, 2> ACREN;    // Compare Function Range Enable
    // 0b0..Range function disabled. Only the compare value 1 of ADC_CV register (CV1) is compared.
    // 0b1..Range function enabled. Both compare values of ADC_CV registers (CV1 and CV2) are compared.
constexpr ADC1_Reg<&ADC_Layout::GC, 1, 1> DMAEN;    // DMA Enable
    // 0b0..DMA disabled (default)
    // 0b1..DMA enabled
constexpr ADC1_Reg<&ADC_Layout::GC, 1, 0> ADACKEN;  // Asynchronous clock output enable
    // 0b0..Asynchronous clock output disabled; Asynchronous clock only enabled if selected by ADICLK and a conversion is active.
    // 0b1..Asynchronous clock and clock output enabled regardless of the state of the ADC
}  // namespace GC

// General status register
namespace GS {
constexpr ADC1_Reg<&ADC_Layout::GS, 1, 2, true> AWKST;  // Asynchronous wakeup interrupt status
    // 0b0..No asynchronous interrupt.
    // 0b1..Asynchronous wake up interrupt occurred in stop mode.
constexpr ADC1_Reg<&ADC_Layout::GS, 1, 1, true> CALF;   // Calibration Failed Flag
    // 0b0..Calibration completed normally.
    // 0b1..Calibration failed. ADC accuracy specifications are not guaranteed.
constexpr ADC1_Reg<regs::constify(&ADC_Layout::GS), 1, 0> ADACT;  // Conversion Active
    // 0b0..Conversion not in progress.
    // 0b1..Conversion in progress.
}  // namespace GS

// Compare value register
namespace CV {
constexpr ADC1_Reg<&ADC_Layout::CV, 12, 16> CV2;  // Compare Value 2
constexpr ADC1_Reg<&ADC_Layout::CV, 12,  0> CV1;  // Compare Value 1
}  // namespace CV

// Offset correction value register
namespace OFS {
constexpr ADC1_Reg<&ADC_Layout::OFS,  1, 12> SIGN;  // Sign bit
    // 0b0..The offset value is added with the raw result
    // 0b1..The offset value is subtracted from the raw converted value
constexpr ADC1_Reg<&ADC_Layout::OFS, 12,  0> OFS;   // Offset value
}  // namespace OFS

// Calibration value register
namespace CAL {
constexpr ADC1_Reg<&ADC_Layout::CAL, 4, 0> CAL_CODE;  // Calibration Result Value
}  // namespace CAL

}  // namespace ADC1

namespace ADC {

// Control register for hardware triggers values
namespace HC {
constexpr regs::RegValue32<1, 7> AIEN;  // Conversion Complete Interrupt Enable/Disable Control
    // 0b0..Conversion complete interrupt disabled
    // 0b1..Conversion complete interrupt enabled
constexpr regs::RegValue32<5, 0> ADCH;  // Input Channel Select
    // 0b00000-0b01111..External channels 0 to 15 See External Signals for more information
    // 0b10000..External channel selection from ADC_ETC
    // 0b10001-0b10111..Reserved
    // 0b11000..Reserved.
    // 0b11001..VREFSH = internal channel, for ADC self-test, hard connected to VRH internally
    // 0b11010..Reserved.
    // 0b11011..Reserved.
    // 0b11100-0b11110..Reserved.
    // 0b11111..Conversion Disabled. Hardware Triggers will not initiate any conversion.
}  // namespace HC

// Data result register for HW triggers values
namespace R {
constexpr regs::RegValue32<12, 0> CDATA;  // R/O, Data (result of an ADC conversion)
}  // namespace R

}  // namespace ADC

namespace ADC2 {

// ADC2 Status register for HW triggers
namespace HS {
constexpr ADC2_Reg<&ADC_Layout::HS, 1, 7> COCO7;
constexpr ADC2_Reg<&ADC_Layout::HS, 1, 6> COCO6;
constexpr ADC2_Reg<&ADC_Layout::HS, 1, 5> COCO5;
constexpr ADC2_Reg<&ADC_Layout::HS, 1, 4> COCO4;
constexpr ADC2_Reg<&ADC_Layout::HS, 1, 3> COCO3;
constexpr ADC2_Reg<&ADC_Layout::HS, 1, 2> COCO2;
constexpr ADC2_Reg<&ADC_Layout::HS, 1, 1> COCO1;
constexpr ADC2_Reg<&ADC_Layout::HS, 1, 0> COCO0;
}  // namespace HS

// ADC2 Configuration register
namespace CFG {
constexpr ADC2_Reg<&ADC_Layout::CFG, 1, 16> OVWREN;
constexpr ADC2_Reg<&ADC_Layout::CFG, 2, 14> AVGS;
constexpr ADC2_Reg<&ADC_Layout::CFG, 1, 13> ADTRG;
constexpr ADC2_Reg<&ADC_Layout::CFG, 2, 11> REFSEL;
constexpr ADC2_Reg<&ADC_Layout::CFG, 1, 10> ADHSC;
constexpr ADC2_Reg<&ADC_Layout::CFG, 2,  8> ADSTS;
constexpr ADC2_Reg<&ADC_Layout::CFG, 1,  7> ADLPC;
constexpr ADC2_Reg<&ADC_Layout::CFG, 2,  5> ADIV;
constexpr ADC2_Reg<&ADC_Layout::CFG, 1,  4> ADLSMP;
constexpr ADC2_Reg<&ADC_Layout::CFG, 2,  2> MODE;
constexpr ADC2_Reg<&ADC_Layout::CFG, 2,  0> ADICLK;
}  // namespace CFG

// ADC2 General control register
namespace GC {
constexpr ADC2_Reg<&ADC_Layout::GC, 1, 7> CAL;
constexpr ADC2_Reg<&ADC_Layout::GC, 1, 6> ADCO;
constexpr ADC2_Reg<&ADC_Layout::GC, 1, 5> AVGE;
constexpr ADC2_Reg<&ADC_Layout::GC, 1, 4> ACFE;
constexpr ADC2_Reg<&ADC_Layout::GC, 1, 3> ACFGT;
constexpr ADC2_Reg<&ADC_Layout::GC, 1, 2> ACREN;
constexpr ADC2_Reg<&ADC_Layout::GC, 1, 1> DMAEN;
constexpr ADC2_Reg<&ADC_Layout::GC, 1, 0> ADACKEN;
}  // namespace GC

// ADC2 General status register
namespace GS {
constexpr ADC2_Reg<&ADC_Layout::GS, 1, 2> AWKST;
constexpr ADC2_Reg<&ADC_Layout::GS, 1, 1> CALF;
constexpr ADC2_Reg<&ADC_Layout::GS, 1, 0> ADACT;
}  // namespace GS

// ADC2 Compare value register
namespace CV {
constexpr ADC2_Reg<&ADC_Layout::CV, 12, 16> CV2;
constexpr ADC2_Reg<&ADC_Layout::CV, 12,  0> CV1;
}  // namespace CV

// ADC2 Offset correction value register
namespace OFS {
constexpr ADC2_Reg<&ADC_Layout::OFS,  1, 12> SIGN;
constexpr ADC2_Reg<&ADC_Layout::OFS, 12,  0> OFS;
}  // namespace OFS

// ADC2 Calibration value register
namespace CAL {
constexpr ADC2_Reg<&ADC_Layout::CAL, 4, 0> CAL_CODE;
}  // namespace CAL

}  // namespace ADC2

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
