// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// TSC.h defines all the TSC registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "qindesign/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the Touch Screen Controller (TSC) registers.
//
// Comments are from BSD-3-licensed NXP SDK sources.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_TSC.h
// * https://github.com/nxp-mcuxpresso/mcux-soc-svd/blob/main/MIMXRT1062/MIMXRT1062.xml
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct TSC_Layout {
  volatile uint32_t BASIC_SETTING;                     /**< Basic Setting, offset: 0x0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PRE_CHARGE_TIME;                   /**< Pre-charge Time, offset: 0x10 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t FLOW_CONTROL;                      /**< Flow Control, offset: 0x20 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  const volatile uint32_t MEASEURE_VALUE;              /**< Measure Value, offset: 0x30 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t INT_EN;                            /**< Interrupt Enable, offset: 0x40 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t INT_SIG_EN;                        /**< Interrupt Signal Enable, offset: 0x50 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t INT_STATUS;                        /**< Intterrupt Status, offset: 0x60 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t DEBUG_MODE;                        /**< Debug Mode Register, offset: 0x70 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t DEBUG_MODE2;                       /**< Debug Mode Register 2, offset: 0x80 */
};

constexpr size_t    kTSC_size = 0x84;
constexpr uintptr_t kTSC_base = 0x400E'0000;

namespace TSC {

constexpr regs::RegGroup<TSC_Layout, kTSC_size, kTSC_base> group;

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using TSC_Reg =
    regs::Reg32<kTSC_base, TSC_Layout, Member, 0, Bits, Shift, AssignMask>;

// Basic Setting
namespace BASIC_SETTING {
constexpr TSC_Reg<&TSC_Layout::BASIC_SETTING, 24, 8> MEASURE_DELAY_TIME;  // Measure Delay Time
constexpr TSC_Reg<&TSC_Layout::BASIC_SETTING,  1, 4> WIRE_4_5;            // 4/5 Wire detection
    // 0b0..4-Wire Detection Mode
    // 0b1..5-Wire Detection Mode
constexpr TSC_Reg<&TSC_Layout::BASIC_SETTING,  1, 0> AUTO_MEASURE;        // Auto Measure
    // 0b0..Disable Auto Measure
    // 0b1..Auto Measure
}  // namespace BASIC_SETTING

// Pre-charge Time
namespace PRE_CHARGE_TIME {
constexpr TSC_Reg<&TSC_Layout::PRE_CHARGE_TIME, 32, 0> PRE_CHARGE_TIME;  // Before detection, the top screen needs some time before being pulled up to a high voltage.
}  // namespace PRE_CHARGE_TIME

// Flow Control
// All fields are HW self-clearing
namespace FLOW_CONTROL {
constexpr TSC_Reg<&TSC_Layout::FLOW_CONTROL, 1, 16> DISABLE;        // This bit is for SW disable registers
    // 0b0..Leave HW state machine control
    // 0b1..SW set to idle status
constexpr TSC_Reg<&TSC_Layout::FLOW_CONTROL, 1, 12> START_SENSE;    // Start Sense
    // 0b0..Stay at idle status
    // 0b1..Start sense detection and (if auto_measure set to 1) measure after detect a touch
constexpr TSC_Reg<&TSC_Layout::FLOW_CONTROL, 1,  8> DROP_MEASURE;   // Drop Measure
    // 0b0..Do not drop measure for now
    // 0b1..Drop the measure and controller return to idle status
constexpr TSC_Reg<&TSC_Layout::FLOW_CONTROL, 1,  4> START_MEASURE;  // Start Measure
    // 0b0..Do not start measure for now
    // 0b1..Start measure the X/Y coordinate value
constexpr TSC_Reg<&TSC_Layout::FLOW_CONTROL, 1,  0> SW_RST;         // Soft Reset
}  // namespace FLOW_CONTROL

// Measure Value
namespace MEASEURE_VALUE {
constexpr TSC_Reg<&TSC_Layout::MEASEURE_VALUE, 12, 16> X_VALUE;  // X Value
constexpr TSC_Reg<&TSC_Layout::MEASEURE_VALUE, 12,  0> Y_VALUE;  // Y Value
}  // namespace MEASEURE_VALUE

// Interrupt Enable
namespace INT_EN {
constexpr TSC_Reg<&TSC_Layout::INT_EN, 1, 12> IDLE_SW_INT_EN;  // Idle Software Interrupt Enable
    // 0b0..Disable idle software interrupt
    // 0b1..Enable idle software interrupt
constexpr TSC_Reg<&TSC_Layout::INT_EN, 1,  4> DETECT_INT_EN;   // Detect Interrupt Enable
    // 0b0..Disable detect interrupt
    // 0b1..Enable detect interrupt
constexpr TSC_Reg<&TSC_Layout::INT_EN, 1,  0> MEASURE_INT_EN;  // Measure Interrupt Enable
    // 0b0..Disable measure interrupt
    // 0b1..Enable measure interrupt
}  // namespace INT_EN

// Interrupt Signal Enable
namespace INT_SIG_EN {
constexpr TSC_Reg<&TSC_Layout::INT_SIG_EN, 1, 12> IDLE_SW_SIG_EN;  // Idle Software Signal Enable
    // 0b0..Disable idle software signal
    // 0b1..Enable idle software signal
constexpr TSC_Reg<&TSC_Layout::INT_SIG_EN, 1,  8> VALID_SIG_EN;    // Valid Signal Enable
    // 0b0..Disable valid signal
    // 0b1..Enable valid signal
constexpr TSC_Reg<&TSC_Layout::INT_SIG_EN, 1,  4> DETECT_SIG_EN;   // Detect Signal Enable
    // 0b0..Disable detect signal
    // 0b1..Enable detect signal
constexpr TSC_Reg<&TSC_Layout::INT_SIG_EN, 1,  0> MEASURE_SIG_EN;  // Measure Signal Enable
}  // namespace INT_SIG_EN

// Intterrupt Status
namespace INT_STATUS {
// Note: TSC_ClearInterruptStatusFlags() in mcusdk-core:drivers/tsc/fsl_tsc.h
//       implies that this is a W1C register

constexpr TSC_Reg<&TSC_Layout::INT_STATUS, 1, 12, 0x0> IDLE_SW;  // Idle Software
    // 0b0..Haven't return to idle status
    // 0b1..Already return to idle status
constexpr TSC_Reg<&TSC_Layout::INT_STATUS, 1,  8, 0x0> VALID;    // Valid Signal
    // 0b0..There is no touch detected after measurement, indicates that the measured value is not valid
    // 0b1..There is touch detection after measurement, indicates that the measure is valid
constexpr TSC_Reg<&TSC_Layout::INT_STATUS, 1,  4, 0x0> DETECT;   // Detect Signal
    // 0b0..Does not exist a detect signal
    // 0b1..Exist detect signal
constexpr TSC_Reg<&TSC_Layout::INT_STATUS, 1,  0, 0x0> MEASURE;  // Measure Signal
    // 0b0..Does not exist a measure signal
    // 0b1..Exist a measure signal
}  // namespace INT_STATUS

// Debug Mode Register
namespace DEBUG_MODE {
constexpr TSC_Reg<&TSC_Layout::DEBUG_MODE, 1, 28> DEBUG_EN;                        // Debug Enable
    // 0b0..Enable debug mode
    // 0b1..Disable debug mode
    // Note: TSC_EnableDebugMode() in mcusdk-core:drivers/tsc/fsl_tsc.h implies
    //       that the field descriptions are reversed, i.e. 1 to enable and
    //       0 to disable

constexpr TSC_Reg<&TSC_Layout::DEBUG_MODE, 1, 26> ADC_COCO_CLEAR_DISABLE;          // ADC COCO Clear Disable
    // 0b0..Allow TSC hardware generates ADC COCO clear
    // 0b1..Prevent TSC from generate ADC COCO clear signal
constexpr TSC_Reg<&TSC_Layout::DEBUG_MODE, 1, 25> ADC_COCO_CLEAR;                  // ADC Coco Clear
    // 0b0..No ADC COCO clear
    // 0b1..Set ADC COCO clear
constexpr TSC_Reg<&TSC_Layout::DEBUG_MODE, 1, 24> TRIGGER;                         // Trigger
    // 0b0..No hardware trigger signal
    // 0b1..Hardware trigger signal, the signal must last at least 1 ips clock period
constexpr TSC_Reg<&TSC_Layout::DEBUG_MODE, 5, 16> EXT_HWTS;                        // Hardware Trigger Select Signal
constexpr TSC_Reg<regs::constify(&TSC_Layout::DEBUG_MODE), 1, 12> ADC_COCO;        // ADC COCO Signal
constexpr TSC_Reg<regs::constify(&TSC_Layout::DEBUG_MODE), 12, 0> ADC_CONV_VALUE;  // ADC Conversion Value
}  // namespace DEBUG_MODE

// Debug Mode Register 2
namespace DEBUG_MODE2 {
constexpr TSC_Reg<regs::constify(&TSC_Layout::DEBUG_MODE2), 2, 29> DE_GLITCH;         // This field indicates glitch threshold
    // 0b00..Normal function: 0x1fff ipg clock cycles; Low power mode: 0x9 low power clock cycles
    // 0b01..Normal function: 0xfff ipg clock cycles; Low power mode: :0x7 low power clock cycles
    // 0b10..Normal function: 0x7ff ipg clock cycles; Low power mode:0x5 low power clock cycles
    // 0b11..Normal function: 0x3 ipg clock cycles; Low power mode:0x3 low power clock cycles
constexpr TSC_Reg<&TSC_Layout::DEBUG_MODE2, 1, 28> DETECT_ENABLE_FIVE_WIRE;           // Detect Enable Five Wire
    // 0b0..Do not read five wire detect value, read default value from analogue
    // 0b1..Read five wire detect status from analogue
constexpr TSC_Reg<&TSC_Layout::DEBUG_MODE2, 1, 24> DETECT_ENABLE_FOUR_WIRE;           // Detect Enable Four Wire
    // 0b0..Do not read four wire detect value, read default value from analogue
    // 0b1..Read four wire detect status from analogue
constexpr TSC_Reg<regs::constify(&TSC_Layout::DEBUG_MODE2), 1, 23> INTERMEDIATE;      // Intermediate State
    // 0b0..Not in intermedia
    // 0b1..Intermedia
constexpr TSC_Reg<regs::constify(&TSC_Layout::DEBUG_MODE2), 3, 20> STATE_MACHINE;     // State Machine
    // 0b000..Idle
    // 0b001..Pre-charge
    // 0b010..Detect
    // 0b011..X-measure
    // 0b100..Y-measure
    // 0b101..Pre-charge
    // 0b110..Detect
constexpr TSC_Reg<regs::constify(&TSC_Layout::DEBUG_MODE2), 1, 17> DETECT_FIVE_WIRE;  // Detect Five Wire
    // 0b0..No detect signal
    // 0b1..Yes, there is a detect on the touch screen.
constexpr TSC_Reg<regs::constify(&TSC_Layout::DEBUG_MODE2), 1, 16> DETECT_FOUR_WIRE;  // Detect Four Wire
    // 0b0..No detect signal
    // 0b1..Yes, there is a detect on the touch screen.
constexpr TSC_Reg<&TSC_Layout::DEBUG_MODE2, 1, 14> WIPER_200K_PULL_UP;                // Wiper Wire 200K Pull Up Switch
    // 0b0..Close the switch
    // 0b1..Open up the switch
constexpr TSC_Reg<&TSC_Layout::DEBUG_MODE2, 1, 13> WIPER_PULL_UP;                     // Wiper Wire Pull Up Switch
    // 0b0..Close the switch
    // 0b1..Open up the switch
constexpr TSC_Reg<&TSC_Layout::DEBUG_MODE2, 1, 12> WIPER_PULL_DOWN;                   // Wiper Wire Pull Down Switch
    // 0b0..Close the switch
    // 0b1..Open up the switch
constexpr TSC_Reg<&TSC_Layout::DEBUG_MODE2, 1, 11> YNLR_200K_PULL_UP;                 // YNLR Wire 200K Pull Up Switch
    // 0b0..Close the switch
    // 0b1..Open up the switch
constexpr TSC_Reg<&TSC_Layout::DEBUG_MODE2, 1, 10> YNLR_PULL_UP;                      // YNLR Wire Pull Up Switch
    // 0b0..Close the switch
    // 0b1..Open up the switch
constexpr TSC_Reg<&TSC_Layout::DEBUG_MODE2, 1,  9> YNLR_PULL_DOWN;                    // YNLR Wire Pull Down Switch
    // 0b0..Close the switch
    // 0b1..Open up the switch
constexpr TSC_Reg<&TSC_Layout::DEBUG_MODE2, 1,  8> YPLL_200K_PULL_UP;                 // YPLL Wire 200K Pull Up Switch
    // 0b0..Close the switch
    // 0b1..Open up the switch
constexpr TSC_Reg<&TSC_Layout::DEBUG_MODE2, 1,  7> YPLL_PULL_UP;                      // YPLL Wire Pull Up Switch
    // 0b0..Close the switch
    // 0b1..Open the switch
constexpr TSC_Reg<&TSC_Layout::DEBUG_MODE2, 1,  6> YPLL_PULL_DOWN;                    // YPLL Wire Pull Down Switch
    // 0b0..Close the switch
    // 0b1..Open up the switch
constexpr TSC_Reg<&TSC_Layout::DEBUG_MODE2, 1,  5> XNUR_200K_PULL_UP;                 // XNUR Wire 200K Pull Up Switch
    // 0b0..Close the switch
    // 0b1..Open up the switch
constexpr TSC_Reg<&TSC_Layout::DEBUG_MODE2, 1,  4> XNUR_PULL_UP;                      // XNUR Wire Pull Up Switch
    // 0b0..Close the switch
    // 0b1..Open up the switch
constexpr TSC_Reg<&TSC_Layout::DEBUG_MODE2, 1,  3> XNUR_PULL_DOWN;                    // XNUR Wire Pull Down Switch
    // 0b0..Close the switch
    // 0b1..Open up the switch
constexpr TSC_Reg<&TSC_Layout::DEBUG_MODE2, 1,  2> XPUL_200K_PULL_UP;                 // XPUL Wire 200K Pull Up Switch
    // 0b0..Close the switch
    // 0b1..Open up the switch
constexpr TSC_Reg<&TSC_Layout::DEBUG_MODE2, 1,  1> XPUL_PULL_UP;                      // XPUL Wire Pull Up Switch
    // 0b0..Close the switch
    // 0b1..Open up the switch
constexpr TSC_Reg<&TSC_Layout::DEBUG_MODE2, 1,  0> XPUL_PULL_DOWN;                    // XPUL Wire Pull Down Switch
    // 0b0..Close the switch
    // 0b1..Open up the switch
}  // namespace DEBUG_MODE2

}  // namespace TSC

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
