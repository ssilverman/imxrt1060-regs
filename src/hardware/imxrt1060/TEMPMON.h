// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// TEMPMON.h defines all the TEMPMON registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the Temperature Monitor (TEMPMON) registers.
//
// Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_TEMPMON.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct TEMPMON_Layout {
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[96];
  volatile uint32_t TEMPSENSE0;                        /**< Tempsensor Control Register 0, offset: 0x180 */
  volatile uint32_t TEMPSENSE0_SET;                    /**< Tempsensor Control Register 0, offset: 0x184 */
  volatile uint32_t TEMPSENSE0_CLR;                    /**< Tempsensor Control Register 0, offset: 0x188 */
  volatile uint32_t TEMPSENSE0_TOG;                    /**< Tempsensor Control Register 0, offset: 0x18C */
  volatile uint32_t TEMPSENSE1;                        /**< Tempsensor Control Register 1, offset: 0x190 */
  volatile uint32_t TEMPSENSE1_SET;                    /**< Tempsensor Control Register 1, offset: 0x194 */
  volatile uint32_t TEMPSENSE1_CLR;                    /**< Tempsensor Control Register 1, offset: 0x198 */
  volatile uint32_t TEMPSENSE1_TOG;                    /**< Tempsensor Control Register 1, offset: 0x19C */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[60];
  volatile uint32_t TEMPSENSE2;                        /**< Tempsensor Control Register 2, offset: 0x290 */
  volatile uint32_t TEMPSENSE2_SET;                    /**< Tempsensor Control Register 2, offset: 0x294 */
  volatile uint32_t TEMPSENSE2_CLR;                    /**< Tempsensor Control Register 2, offset: 0x298 */
  volatile uint32_t TEMPSENSE2_TOG;                    /**< Tempsensor Control Register 2, offset: 0x29C */
};

constexpr size_t    kTEMPMON_size = 0x2A0;
constexpr uintptr_t kTEMPMON_base = 0x400D'8000;

namespace TEMPMON {
constexpr regs::RegGroup<TEMPMON_Layout, kTEMPMON_size, kTEMPMON_base> group;
}  // namespace TEMPMON

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using TEMPMON_Reg = regs::Reg32<kTEMPMON_base, TEMPMON_Layout, Member, 0, Bits,
                                Shift, AssignMask>;

namespace TEMPMON {

// Tempsensor Control Register 0
namespace TEMPSENSE0 {
constexpr TEMPMON_Reg<&TEMPMON_Layout::TEMPSENSE0, 12, 20> ALARM_VALUE;               // This bit field contains the temperature count (raw sensor output) that will generate a high alarm when TEMP_CNT is smaller than this field
constexpr TEMPMON_Reg<regs::constify(&TEMPMON_Layout::TEMPSENSE0), 12,  8> TEMP_CNT;  // This bit field contains the last measured temperature count.
constexpr TEMPMON_Reg<regs::constify(&TEMPMON_Layout::TEMPSENSE0),  1,  2> FINISHED;  // Indicates that the latest temperature is valid
    // 0b0..Last measurement is not ready yet.
    // 0b1..Last measurement is valid.
constexpr TEMPMON_Reg<&TEMPMON_Layout::TEMPSENSE0,  1,  1> MEASURE_TEMP;              // Starts the measurement process
    // 0b0..Do not start the measurement process.
    // 0b1..Start the measurement process.
constexpr TEMPMON_Reg<&TEMPMON_Layout::TEMPSENSE0,  1,  0> POWER_DOWN;                // This bit powers down the temperature sensor.
    // 0b0..Enable power to the temperature sensor.
    // 0b1..Power down the temperature sensor.
}  // namespace TEMPSENSE0

// Tempsensor Control Register 0
namespace TEMPSENSE0_SET {
constexpr TEMPMON_Reg<&TEMPMON_Layout::TEMPSENSE0_SET, 12, 20, 0x0> ALARM_VALUE;          // This bit field contains the temperature count (raw sensor output) that will generate a high alarm when TEMP_CNT is smaller than this field
constexpr TEMPMON_Reg<regs::constify(&TEMPMON_Layout::TEMPSENSE0_SET), 12,  8> TEMP_CNT;  // This bit field contains the last measured temperature count.
constexpr TEMPMON_Reg<regs::constify(&TEMPMON_Layout::TEMPSENSE0_SET),  1,  2> FINISHED;  // Indicates that the latest temperature is valid
constexpr TEMPMON_Reg<&TEMPMON_Layout::TEMPSENSE0_SET,  1,  1, 0x0> MEASURE_TEMP;         // Starts the measurement process
constexpr TEMPMON_Reg<&TEMPMON_Layout::TEMPSENSE0_SET,  1,  0, 0x0> POWER_DOWN;           // This bit powers down the temperature sensor.
}  // namespace TEMPSENSE0_SET

// Tempsensor Control Register 0
namespace TEMPSENSE0_CLR {
constexpr TEMPMON_Reg<&TEMPMON_Layout::TEMPSENSE0_CLR, 12, 20, 0x0> ALARM_VALUE;          // This bit field contains the temperature count (raw sensor output) that will generate a high alarm when TEMP_CNT is smaller than this field
constexpr TEMPMON_Reg<regs::constify(&TEMPMON_Layout::TEMPSENSE0_CLR), 12,  8> TEMP_CNT;  // This bit field contains the last measured temperature count.
constexpr TEMPMON_Reg<regs::constify(&TEMPMON_Layout::TEMPSENSE0_CLR),  1,  2> FINISHED;  // Indicates that the latest temperature is valid
constexpr TEMPMON_Reg<&TEMPMON_Layout::TEMPSENSE0_CLR,  1,  1, 0x0> MEASURE_TEMP;         // Starts the measurement process
constexpr TEMPMON_Reg<&TEMPMON_Layout::TEMPSENSE0_CLR,  1,  0, 0x0> POWER_DOWN;           // This bit powers down the temperature sensor.
}  // namespace TEMPSENSE0_CLR

// Tempsensor Control Register 0
namespace TEMPSENSE0_TOG {
constexpr TEMPMON_Reg<&TEMPMON_Layout::TEMPSENSE0_TOG, 12, 20, 0x0> ALARM_VALUE;          // This bit field contains the temperature count (raw sensor output) that will generate a high alarm when TEMP_CNT is smaller than this field
constexpr TEMPMON_Reg<regs::constify(&TEMPMON_Layout::TEMPSENSE0_TOG), 12,  8> TEMP_CNT;  // This bit field contains the last measured temperature count.
constexpr TEMPMON_Reg<regs::constify(&TEMPMON_Layout::TEMPSENSE0_TOG),  1,  2> FINISHED;  // Indicates that the latest temperature is valid
constexpr TEMPMON_Reg<&TEMPMON_Layout::TEMPSENSE0_TOG,  1,  1, 0x0> MEASURE_TEMP;         // Starts the measurement process
constexpr TEMPMON_Reg<&TEMPMON_Layout::TEMPSENSE0_TOG,  1,  0, 0x0> POWER_DOWN;           // This bit powers down the temperature sensor.
}  // namespace TEMPSENSE0_TOG

// Tempsensor Control Register 1
namespace TEMPSENSE1 {
constexpr TEMPMON_Reg<&TEMPMON_Layout::TEMPSENSE1, 16, 0> MEASURE_FREQ;  // These bits determine how many RTC clocks to wait before automatically repeating a temperature measurement
    // 0x0000..Single measurement mode. New measurements are not automatically taken.
    // 0x0001..Measurements are taken at the RTC clock rate.
    // 0x0002..Measurements are taken at one-half the RTC clock rate.
    // 0xFFFF..Two-second sample rate with a 32.768 kHz RTC clock.
}  // namespace TEMPSENSE1

// Tempsensor Control Register 1
namespace TEMPSENSE1_SET {
constexpr TEMPMON_Reg<&TEMPMON_Layout::TEMPSENSE1_SET, 16, 0, 0x0> MEASURE_FREQ;  // These bits determine how many RTC clocks to wait before automatically repeating a temperature measurement
}  // namespace TEMPSENSE1_SET

// Tempsensor Control Register 1
namespace TEMPSENSE1_CLR {
constexpr TEMPMON_Reg<&TEMPMON_Layout::TEMPSENSE1_CLR, 16, 0, 0x0> MEASURE_FREQ;  // These bits determine how many RTC clocks to wait before automatically repeating a temperature measurement
}  // namespace TEMPSENSE1_CLR

// Tempsensor Control Register 1
namespace TEMPSENSE1_TOG {
constexpr TEMPMON_Reg<&TEMPMON_Layout::TEMPSENSE1_TOG, 16, 0, 0x0> MEASURE_FREQ;  // These bits determine how many RTC clocks to wait before automatically repeating a temperature measurement
}  // namespace TEMPSENSE1_TOG

// Tempsensor Control Register 2
namespace TEMPSENSE2 {
constexpr TEMPMON_Reg<&TEMPMON_Layout::TEMPSENSE2, 12, 16> PANIC_ALARM_VALUE;  // This bit field contains the temperature count that will generate a panic interrupt when TEMP_CNT is smaller than this field
constexpr TEMPMON_Reg<&TEMPMON_Layout::TEMPSENSE2, 12,  0> LOW_ALARM_VALUE;    // This bit field contains the temperature count that will generate a low alarm interrupt when the field is exceeded by TEMP_CNT
}  // namespace TEMPSENSE2

// Tempsensor Control Register 2
namespace TEMPSENSE2_SET {
constexpr TEMPMON_Reg<&TEMPMON_Layout::TEMPSENSE2_SET, 12, 16, 0x0> PANIC_ALARM_VALUE;  // This bit field contains the temperature count that will generate a panic interrupt when TEMP_CNT is smaller than this field
constexpr TEMPMON_Reg<&TEMPMON_Layout::TEMPSENSE2_SET, 12,  0, 0x0> LOW_ALARM_VALUE;    // This bit field contains the temperature count that will generate a low alarm interrupt when the field is exceeded by TEMP_CNT
}  // namespace TEMPSENSE2_SET

// Tempsensor Control Register 2
namespace TEMPSENSE2_CLR {
constexpr TEMPMON_Reg<&TEMPMON_Layout::TEMPSENSE2_CLR, 12, 16, 0x0> PANIC_ALARM_VALUE;  // This bit field contains the temperature count that will generate a panic interrupt when TEMP_CNT is smaller than this field
constexpr TEMPMON_Reg<&TEMPMON_Layout::TEMPSENSE2_CLR, 12,  0, 0x0> LOW_ALARM_VALUE;    // This bit field contains the temperature count that will generate a low alarm interrupt when the field is exceeded by TEMP_CNT
}  // namespace TEMPSENSE2_CLR

// Tempsensor Control Register 2
namespace TEMPSENSE2_TOG {
constexpr TEMPMON_Reg<&TEMPMON_Layout::TEMPSENSE2_TOG, 12, 16, 0x0> PANIC_ALARM_VALUE;  // This bit field contains the temperature count that will generate a panic interrupt when TEMP_CNT is smaller than this field
constexpr TEMPMON_Reg<&TEMPMON_Layout::TEMPSENSE2_TOG, 12,  0, 0x0> LOW_ALARM_VALUE;    // This bit field contains the temperature count that will generate a low alarm interrupt when the field is exceeded by TEMP_CNT
}  // namespace TEMPSENSE2_TOG

}  // namespace TEMPMON

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
