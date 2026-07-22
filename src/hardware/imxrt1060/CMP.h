// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// CMP.h defines all the CMP registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// CMP layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_CMP.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct CMP_Layout {
  volatile uint8_t CR0;                                /**< CMP Control Register 0, offset: 0x0 */
  volatile uint8_t CR1;                                /**< CMP Control Register 1, offset: 0x1 */
  volatile uint8_t FPR;                                /**< CMP Filter Period Register, offset: 0x2 */
  volatile uint8_t SCR;                                /**< CMP Status and Control Register, offset: 0x3 */
  volatile uint8_t DACCR;                              /**< DAC Control Register, offset: 0x4 */
  volatile uint8_t MUXCR;                              /**< MUX Control Register, offset: 0x5 */
};

constexpr size_t    kCMP_size  = 0x06;
constexpr uintptr_t kCMP1_base = 0x40094000;
constexpr uintptr_t kCMP2_base = 0x40094008;
constexpr uintptr_t kCMP3_base = 0x40094010;
constexpr uintptr_t kCMP4_base = 0x40094018;

namespace CMP1 {
constexpr regs::RegGroup<CMP_Layout, kCMP_size, kCMP1_base> group;
}  // namespace CMP1

namespace CMP2 {
constexpr regs::RegGroup<CMP_Layout, kCMP_size, kCMP2_base> group;
}  // namespace CMP2

namespace CMP3 {
constexpr regs::RegGroup<CMP_Layout, kCMP_size, kCMP3_base> group;
}  // namespace CMP3

namespace CMP4 {
constexpr regs::RegGroup<CMP_Layout, kCMP_size, kCMP4_base> group;
}  // namespace CMP4

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using CMP1_Reg =
    regs::Reg<uint8_t, kCMP1_base, CMP_Layout, Member, 0, Bits, Shift, DirectAssign>;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using CMP2_Reg =
    regs::Reg<uint8_t, kCMP2_base, CMP_Layout, Member, 0, Bits, Shift, DirectAssign>;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using CMP3_Reg =
    regs::Reg<uint8_t, kCMP3_base, CMP_Layout, Member, 0, Bits, Shift, DirectAssign>;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using CMP4_Reg =
    regs::Reg<uint8_t, kCMP4_base, CMP_Layout, Member, 0, Bits, Shift, DirectAssign>;

namespace CMP1 {

// CMP Control Register 0
namespace CR0 {
constexpr CMP1_Reg<&CMP_Layout::CR0, 3, 4> FILTER_CNT;  // Filter Sample Count
    // 0b000..Filter is disabled. If SE = 1, then COUT is a logic 0. This is not a legal state, and is not recommended. If SE = 0, COUT = COUTA.
    // 0b001..One sample must agree. The comparator output is simply sampled.
    // 0b010..2 consecutive samples must agree.
    // 0b011..3 consecutive samples must agree.
    // 0b100..4 consecutive samples must agree.
    // 0b101..5 consecutive samples must agree.
    // 0b110..6 consecutive samples must agree.
    // 0b111..7 consecutive samples must agree.
constexpr CMP1_Reg<&CMP_Layout::CR0, 2, 0> HYSTCTR;     // Comparator hard block hysteresis control
    // 0b00..Level 0
    // 0b01..Level 1
    // 0b10..Level 2
    // 0b11..Level 3
}  // namespace CR0

// CMP Control Register 1
namespace CR1 {
constexpr CMP1_Reg<&CMP_Layout::CR1, 1, 7> SE;     // Sample Enable
    // 0b0..Sampling mode is not selected.
    // 0b1..Sampling mode is selected.
constexpr CMP1_Reg<&CMP_Layout::CR1, 1, 6> WE;     // Windowing Enable
    // 0b0..Windowing mode is not selected.
    // 0b1..Windowing mode is selected.
constexpr CMP1_Reg<&CMP_Layout::CR1, 1, 4> PMODE;  // Power Mode Select
    // 0b0..Low-Speed (LS) Comparison mode selected. In this mode, CMP has slower output propagation delay and lower current consumption.
    // 0b1..High-Speed (HS) Comparison mode selected. In this mode, CMP has faster output propagation delay and higher current consumption.
constexpr CMP1_Reg<&CMP_Layout::CR1, 1, 3> INV;    // Comparator INVERT
    // 0b0..Does not invert the comparator output.
    // 0b1..Inverts the comparator output.
constexpr CMP1_Reg<&CMP_Layout::CR1, 1, 2> COS;    // Comparator Output Select
    // 0b0..Set the filtered comparator output (CMPO) to equal COUT.
    // 0b1..Set the unfiltered comparator output (CMPO) to equal COUTA.
constexpr CMP1_Reg<&CMP_Layout::CR1, 1, 1> OPE;    // Comparator Output Pin Enable
    // 0b0..CMPO is not available on the associated CMPO output pin. If the comparator does not own the pin, this field has no effect.
    // 0b1..CMPO is available on the associated CMPO output pin. The comparator output (CMPO) is driven out on the
    //      associated CMPO output pin if the comparator owns the pin. If the comparator does not own the field, this
    //      bit has no effect.
constexpr CMP1_Reg<&CMP_Layout::CR1, 1, 0> EN;     // Comparator Module Enable
    // 0b0..Analog Comparator is disabled.
    // 0b1..Analog Comparator is enabled.
}  // namespace CR1

// CMP Filter Period Register
namespace FPR {
constexpr CMP1_Reg<&CMP_Layout::FPR, 8, 0> FILT_PER;  // Filter Sample Period
}  // namespace FPR

// CMP Status and Control Register
namespace SCR {
constexpr CMP1_Reg<&CMP_Layout::SCR, 1, 6>       DMAEN;  // DMA Enable Control
    // 0b0..DMA is disabled.
    // 0b1..DMA is enabled.
constexpr CMP1_Reg<&CMP_Layout::SCR, 1, 4>       IER;    // Comparator Interrupt Enable Rising
    // 0b0..Interrupt is disabled.
    // 0b1..Interrupt is enabled.
constexpr CMP1_Reg<&CMP_Layout::SCR, 1, 3>       IEF;    // Comparator Interrupt Enable Falling
    // 0b0..Interrupt is disabled.
    // 0b1..Interrupt is enabled.
constexpr CMP1_Reg<&CMP_Layout::SCR, 1, 2, true> CFR;    // Analog Comparator Flag Rising
    // 0b0..Rising-edge on COUT has not been detected.
    // 0b1..Rising-edge on COUT has occurred.
constexpr CMP1_Reg<&CMP_Layout::SCR, 1, 1, true> CFF;    // Analog Comparator Flag Falling
    // 0b0..Falling-edge on COUT has not been detected.
    // 0b1..Falling-edge on COUT has occurred.
constexpr CMP1_Reg<&CMP_Layout::SCR, 1, 0>       COUT;   // Analog Comparator Output
}  // namespace SCR

// DAC Control Register
namespace DACCR {
constexpr CMP1_Reg<&CMP_Layout::DACCR, 1, 7> DACEN;  // DAC Enable
    // 0b0..DAC is disabled.
    // 0b1..DAC is enabled.
constexpr CMP1_Reg<&CMP_Layout::DACCR, 1, 6> VRSEL;  // Supply Voltage Reference Source Select
    // 0b0..Vin1 is selected as resistor ladder network supply reference.
    // 0b1..Vin2 is selected as resistor ladder network supply reference.
constexpr CMP1_Reg<&CMP_Layout::DACCR, 6, 0> VOSEL;  // DAC Output Voltage Select
}  // namespace DACCR

// MUX Control Register
namespace MUXCR {
constexpr CMP1_Reg<&CMP_Layout::MUXCR, 3, 3> PSEL;  // Plus Input Mux Control
    // 0b000..IN0
    // 0b001..IN1
    // 0b010..IN2
    // 0b011..IN3
    // 0b100..IN4
    // 0b101..IN5
    // 0b110..IN6
    // 0b111..IN7
constexpr CMP1_Reg<&CMP_Layout::MUXCR, 3, 0> MSEL;  // Minus Input Mux Control
    // 0b000..IN0
    // 0b001..IN1
    // 0b010..IN2
    // 0b011..IN3
    // 0b100..IN4
    // 0b101..IN5
    // 0b110..IN6
    // 0b111..IN7
}  // namespace MUXCR

}  // namespace CMP1

namespace CMP2 {

// CMP2 CMP Control Register 0
namespace CR0 {
constexpr CMP2_Reg<&CMP_Layout::CR0, 3, 4> FILTER_CNT;
constexpr CMP2_Reg<&CMP_Layout::CR0, 2, 0> HYSTCTR;
}  // namespace CR0

// CMP2 CMP Control Register 1
namespace CR1 {
constexpr CMP2_Reg<&CMP_Layout::CR1, 1, 7> SE;
constexpr CMP2_Reg<&CMP_Layout::CR1, 1, 6> WE;
constexpr CMP2_Reg<&CMP_Layout::CR1, 1, 4> PMODE;
constexpr CMP2_Reg<&CMP_Layout::CR1, 1, 3> INV;
constexpr CMP2_Reg<&CMP_Layout::CR1, 1, 2> COS;
constexpr CMP2_Reg<&CMP_Layout::CR1, 1, 1> OPE;
constexpr CMP2_Reg<&CMP_Layout::CR1, 1, 0> EN;
}  // namespace CR1

// CMP2 CMP Filter Period Register
namespace FPR {
constexpr CMP2_Reg<&CMP_Layout::FPR, 8, 0> FILT_PER;
}  // namespace FPR

// CMP2 CMP Status and Control Register
namespace SCR {
constexpr CMP2_Reg<&CMP_Layout::SCR, 1, 6>       DMAEN;
constexpr CMP2_Reg<&CMP_Layout::SCR, 1, 4>       IER;
constexpr CMP2_Reg<&CMP_Layout::SCR, 1, 3>       IEF;
constexpr CMP2_Reg<&CMP_Layout::SCR, 1, 2, true> CFR;
constexpr CMP2_Reg<&CMP_Layout::SCR, 1, 1, true> CFF;
constexpr CMP2_Reg<&CMP_Layout::SCR, 1, 0>       COUT;
}  // namespace SCR

// CMP2 DAC Control Register
namespace DACCR {
constexpr CMP2_Reg<&CMP_Layout::DACCR, 1, 7> DACEN;
constexpr CMP2_Reg<&CMP_Layout::DACCR, 1, 6> VRSEL;
constexpr CMP2_Reg<&CMP_Layout::DACCR, 6, 0> VOSEL;
}  // namespace DACCR

// CMP2 MUX Control Register
namespace MUXCR {
constexpr CMP2_Reg<&CMP_Layout::MUXCR, 3, 3> PSEL;
constexpr CMP2_Reg<&CMP_Layout::MUXCR, 3, 0> MSEL;
}  // namespace MUXCR

}  // namespace CMP2

namespace CMP3 {

// CMP3 CMP Control Register 0
namespace CR0 {
constexpr CMP3_Reg<&CMP_Layout::CR0, 3, 4> FILTER_CNT;
constexpr CMP3_Reg<&CMP_Layout::CR0, 2, 0> HYSTCTR;
}  // namespace CR0

// CMP3 CMP Control Register 1
namespace CR1 {
constexpr CMP3_Reg<&CMP_Layout::CR1, 1, 7> SE;
constexpr CMP3_Reg<&CMP_Layout::CR1, 1, 6> WE;
constexpr CMP3_Reg<&CMP_Layout::CR1, 1, 4> PMODE;
constexpr CMP3_Reg<&CMP_Layout::CR1, 1, 3> INV;
constexpr CMP3_Reg<&CMP_Layout::CR1, 1, 2> COS;
constexpr CMP3_Reg<&CMP_Layout::CR1, 1, 1> OPE;
constexpr CMP3_Reg<&CMP_Layout::CR1, 1, 0> EN;
}  // namespace CR1

// CMP3 CMP Filter Period Register
namespace FPR {
constexpr CMP3_Reg<&CMP_Layout::FPR, 8, 0> FILT_PER;
}  // namespace FPR

// CMP3 CMP Status and Control Register
namespace SCR {
constexpr CMP3_Reg<&CMP_Layout::SCR, 1, 6>       DMAEN;
constexpr CMP3_Reg<&CMP_Layout::SCR, 1, 4>       IER;
constexpr CMP3_Reg<&CMP_Layout::SCR, 1, 3>       IEF;
constexpr CMP3_Reg<&CMP_Layout::SCR, 1, 2, true> CFR;
constexpr CMP3_Reg<&CMP_Layout::SCR, 1, 1, true> CFF;
constexpr CMP3_Reg<&CMP_Layout::SCR, 1, 0>       COUT;
}  // namespace SCR

// CMP3 DAC Control Register
namespace DACCR {
constexpr CMP3_Reg<&CMP_Layout::DACCR, 1, 7> DACEN;
constexpr CMP3_Reg<&CMP_Layout::DACCR, 1, 6> VRSEL;
constexpr CMP3_Reg<&CMP_Layout::DACCR, 6, 0> VOSEL;
}  // namespace DACCR

// CMP3 MUX Control Register
namespace MUXCR {
constexpr CMP3_Reg<&CMP_Layout::MUXCR, 3, 3> PSEL;
constexpr CMP3_Reg<&CMP_Layout::MUXCR, 3, 0> MSEL;
}  // namespace MUXCR

}  // namespace CMP3

namespace CMP4 {

// CMP4 CMP Control Register 0
namespace CR0 {
constexpr CMP4_Reg<&CMP_Layout::CR0, 3, 4> FILTER_CNT;
constexpr CMP4_Reg<&CMP_Layout::CR0, 2, 0> HYSTCTR;
}  // namespace CR0

// CMP4 CMP Control Register 1
namespace CR1 {
constexpr CMP4_Reg<&CMP_Layout::CR1, 1, 7> SE;
constexpr CMP4_Reg<&CMP_Layout::CR1, 1, 6> WE;
constexpr CMP4_Reg<&CMP_Layout::CR1, 1, 4> PMODE;
constexpr CMP4_Reg<&CMP_Layout::CR1, 1, 3> INV;
constexpr CMP4_Reg<&CMP_Layout::CR1, 1, 2> COS;
constexpr CMP4_Reg<&CMP_Layout::CR1, 1, 1> OPE;
constexpr CMP4_Reg<&CMP_Layout::CR1, 1, 0> EN;
}  // namespace CR1

// CMP4 CMP Filter Period Register
namespace FPR {
constexpr CMP4_Reg<&CMP_Layout::FPR, 8, 0> FILT_PER;
}  // namespace FPR

// CMP4 CMP Status and Control Register
namespace SCR {
constexpr CMP4_Reg<&CMP_Layout::SCR, 1, 6>       DMAEN;
constexpr CMP4_Reg<&CMP_Layout::SCR, 1, 4>       IER;
constexpr CMP4_Reg<&CMP_Layout::SCR, 1, 3>       IEF;
constexpr CMP4_Reg<&CMP_Layout::SCR, 1, 2, true> CFR;
constexpr CMP4_Reg<&CMP_Layout::SCR, 1, 1, true> CFF;
constexpr CMP4_Reg<&CMP_Layout::SCR, 1, 0>       COUT;
}  // namespace SCR

// CMP4 DAC Control Register
namespace DACCR {
constexpr CMP4_Reg<&CMP_Layout::DACCR, 1, 7> DACEN;
constexpr CMP4_Reg<&CMP_Layout::DACCR, 1, 6> VRSEL;
constexpr CMP4_Reg<&CMP_Layout::DACCR, 6, 0> VOSEL;
}  // namespace DACCR

// CMP4 MUX Control Register
namespace MUXCR {
constexpr CMP4_Reg<&CMP_Layout::MUXCR, 3, 3> PSEL;
constexpr CMP4_Reg<&CMP_Layout::MUXCR, 3, 0> MSEL;
}  // namespace MUXCR

}  // namespace CMP4

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
