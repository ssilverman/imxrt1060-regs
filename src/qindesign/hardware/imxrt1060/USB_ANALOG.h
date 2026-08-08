// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// USB_ANALOG.h defines all the USB_ANALOG registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>
#include <type_traits>

#include "qindesign/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the USB Analog (USB_ANALOG) registers.
//
// Comments are from BSD-3-licensed NXP SDK sources.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_USB_ANALOG.h
// * https://github.com/nxp-mcuxpresso/mcux-soc-svd/blob/main/MIMXRT1062/MIMXRT1062.xml
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h

// Size of Registers Arrays
constexpr size_t kUSB_ANALOG_INSTANCE_count = 2;

struct USB_ANALOG_Layout {
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[104];
  struct INSTANCE_Layout {                             /* offset: 0x1A0, array step: 0x60 */
    volatile uint32_t VBUS_DETECT;                       /**< USB VBUS Detect Register, array offset: 0x1A0, array step: 0x60 */
    volatile uint32_t VBUS_DETECT_SET;                   /**< USB VBUS Detect Register, array offset: 0x1A4, array step: 0x60 */
    volatile uint32_t VBUS_DETECT_CLR;                   /**< USB VBUS Detect Register, array offset: 0x1A8, array step: 0x60 */
    volatile uint32_t VBUS_DETECT_TOG;                   /**< USB VBUS Detect Register, array offset: 0x1AC, array step: 0x60 */
    volatile uint32_t CHRG_DETECT;                       /**< USB Charger Detect Register, array offset: 0x1B0, array step: 0x60 */
    volatile uint32_t CHRG_DETECT_SET;                   /**< USB Charger Detect Register, array offset: 0x1B4, array step: 0x60 */
    volatile uint32_t CHRG_DETECT_CLR;                   /**< USB Charger Detect Register, array offset: 0x1B8, array step: 0x60 */
    volatile uint32_t CHRG_DETECT_TOG;                   /**< USB Charger Detect Register, array offset: 0x1BC, array step: 0x60 */
    const volatile uint32_t VBUS_DETECT_STAT;            /**< USB VBUS Detect Status Register, array offset: 0x1C0, array step: 0x60 */
    uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
    const volatile uint32_t CHRG_DETECT_STAT;            /**< USB Charger Detect Status Register, array offset: 0x1D0, array step: 0x60 */
    uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
    volatile uint32_t LOOPBACK;                          /**< USB Loopback Test Register, array offset: 0x1E0, array step: 0x60 */
    volatile uint32_t LOOPBACK_SET;                      /**< USB Loopback Test Register, array offset: 0x1E4, array step: 0x60 */
    volatile uint32_t LOOPBACK_CLR;                      /**< USB Loopback Test Register, array offset: 0x1E8, array step: 0x60 */
    volatile uint32_t LOOPBACK_TOG;                      /**< USB Loopback Test Register, array offset: 0x1EC, array step: 0x60 */
    volatile uint32_t MISC;                              /**< USB Misc Register, array offset: 0x1F0, array step: 0x60 */
    volatile uint32_t MISC_SET;                          /**< USB Misc Register, array offset: 0x1F4, array step: 0x60 */
    volatile uint32_t MISC_CLR;                          /**< USB Misc Register, array offset: 0x1F8, array step: 0x60 */
    volatile uint32_t MISC_TOG;                          /**< USB Misc Register, array offset: 0x1FC, array step: 0x60 */
  } INSTANCE[kUSB_ANALOG_INSTANCE_count];
  const volatile uint32_t DIGPROG;                     /**< Chip Silicon Version, offset: 0x260 */
};

constexpr size_t    kUSB_ANALOG_size = 0x264;
constexpr uintptr_t kUSB_ANALOG_base = 0x400D'8000;

namespace USB_ANALOG {

constexpr regs::RegGroup<USB_ANALOG_Layout, kUSB_ANALOG_size, kUSB_ANALOG_base> group;

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using USB_ANALOG_Reg = regs::Reg32<kUSB_ANALOG_base, USB_ANALOG_Layout,
                                   Member, 0, Bits, Shift, AssignMask>;

template <size_t Index,
          typename = std::enable_if_t<(Index < kUSB_ANALOG_INSTANCE_count)>>
constexpr uintptr_t InstanceBase() {
  return kUSB_ANALOG_base + offsetof(USB_ANALOG_Layout, INSTANCE) +
         Index * sizeof(USB_ANALOG_Layout::INSTANCE_Layout);
}

template <size_t Index, auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using INSTANCE_Reg =
    regs::Reg32<InstanceBase<Index>(), USB_ANALOG_Layout::INSTANCE_Layout,
                Member, 0, Bits, Shift, AssignMask>;

namespace INSTANCE {

// USB VBUS Detect Register
namespace VBUS_DETECT {
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::VBUS_DETECT, 1, 27> CHARGE_VBUS;           // USB OTG charge VBUS.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::VBUS_DETECT, 1, 26> DISCHARGE_VBUS;        // USB OTG discharge VBUS.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::VBUS_DETECT, 1, 20> VBUSVALID_PWRUP_CMPS;  // Powers up comparators for vbus_valid detector.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::VBUS_DETECT, 3,  0> VBUSVALID_THRESH;      // Set the threshold for the VBUSVALID comparator
    // 0b000..4.0V
    // 0b001..4.1V
    // 0b010..4.2V
    // 0b011..4.3V
    // 0b100..4.4V (default)
    // 0b101..4.5V
    // 0b110..4.6V
    // 0b111..4.7V

namespace vals {
constexpr regs::RegValue32<1, 27> CHARGE_VBUS;
constexpr regs::RegValue32<1, 26> DISCHARGE_VBUS;
constexpr regs::RegValue32<1, 20> VBUSVALID_PWRUP_CMPS;
constexpr regs::RegValue32<3,  0> VBUSVALID_THRESH;
}  // namespace vals
}  // namespace VBUS_DETECT

// USB VBUS Detect Register
namespace VBUS_DETECT_SET {
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::VBUS_DETECT_SET, 1, 27, 0x0> CHARGE_VBUS;           // USB OTG charge VBUS.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::VBUS_DETECT_SET, 1, 26, 0x0> DISCHARGE_VBUS;        // USB OTG discharge VBUS.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::VBUS_DETECT_SET, 1, 20, 0x0> VBUSVALID_PWRUP_CMPS;  // Powers up comparators for vbus_valid detector.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::VBUS_DETECT_SET, 3,  0, 0x0> VBUSVALID_THRESH;      // Set the threshold for the VBUSVALID comparator
    // 0b000..4.0V
    // 0b001..4.1V
    // 0b010..4.2V
    // 0b011..4.3V
    // 0b100..4.4V (default)
    // 0b101..4.5V
    // 0b110..4.6V
    // 0b111..4.7V
}  // namespace VBUS_DETECT_SET

// USB VBUS Detect Register
namespace VBUS_DETECT_CLR {
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::VBUS_DETECT_CLR, 1, 27, 0x0> CHARGE_VBUS;           // USB OTG charge VBUS.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::VBUS_DETECT_CLR, 1, 26, 0x0> DISCHARGE_VBUS;        // USB OTG discharge VBUS.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::VBUS_DETECT_CLR, 1, 20, 0x0> VBUSVALID_PWRUP_CMPS;  // Powers up comparators for vbus_valid detector.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::VBUS_DETECT_CLR, 3,  0, 0x0> VBUSVALID_THRESH;      // Set the threshold for the VBUSVALID comparator
    // 0b000..4.0V
    // 0b001..4.1V
    // 0b010..4.2V
    // 0b011..4.3V
    // 0b100..4.4V (default)
    // 0b101..4.5V
    // 0b110..4.6V
    // 0b111..4.7V
}  // namespace VBUS_DETECT_CLR

// USB VBUS Detect Register
namespace VBUS_DETECT_TOG {
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::VBUS_DETECT_TOG, 1, 27, 0x0> CHARGE_VBUS;           // USB OTG charge VBUS.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::VBUS_DETECT_TOG, 1, 26, 0x0> DISCHARGE_VBUS;        // USB OTG discharge VBUS.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::VBUS_DETECT_TOG, 1, 20, 0x0> VBUSVALID_PWRUP_CMPS;  // Powers up comparators for vbus_valid detector.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::VBUS_DETECT_TOG, 3,  0, 0x0> VBUSVALID_THRESH;      // Set the threshold for the VBUSVALID comparator
    // 0b000..4.0V
    // 0b001..4.1V
    // 0b010..4.2V
    // 0b011..4.3V
    // 0b100..4.4V (default)
    // 0b101..4.5V
    // 0b110..4.6V
    // 0b111..4.7V
}  // namespace VBUS_DETECT_TOG

// USB Charger Detect Register
namespace CHRG_DETECT {
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::CHRG_DETECT, 1, 20> EN_B;         // Control the charger detector.
    // 0b0..Enable the charger detector.
    // 0b1..Disable the charger detector.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::CHRG_DETECT, 1, 19> CHK_CHRG_B;   // Check the charger connection
    // 0b0..Check whether a charger (either a dedicated charger or a host charger) is connected to USB port.
    // 0b1..Do not check whether a charger is connected to the USB port.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::CHRG_DETECT, 1, 18> CHK_CONTACT;  // Check the contact of USB plug
    // 0b0..Do not check the contact of USB plug.
    // 0b1..Check whether the USB plug has been in contact with each other

namespace vals {
constexpr regs::RegValue32<1, 20> EN_B;
constexpr regs::RegValue32<1, 19> CHK_CHRG_B;
constexpr regs::RegValue32<1, 18> CHK_CONTACT;
}  // namespace vals
}  // namespace CHRG_DETECT

// USB Charger Detect Register
namespace CHRG_DETECT_SET {
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::CHRG_DETECT_SET, 1, 20, 0x0> EN_B;         // Control the charger detector.
    // 0b0..Enable the charger detector.
    // 0b1..Disable the charger detector.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::CHRG_DETECT_SET, 1, 19, 0x0> CHK_CHRG_B;   // Check the charger connection
    // 0b0..Check whether a charger (either a dedicated charger or a host charger) is connected to USB port.
    // 0b1..Do not check whether a charger is connected to the USB port.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::CHRG_DETECT_SET, 1, 18, 0x0> CHK_CONTACT;  // Check the contact of USB plug
    // 0b0..Do not check the contact of USB plug.
    // 0b1..Check whether the USB plug has been in contact with each other
}  // namespace CHRG_DETECT_SET

// USB Charger Detect Register
namespace CHRG_DETECT_CLR {
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::CHRG_DETECT_CLR, 1, 20, 0x0> EN_B;         // Control the charger detector.
    // 0b0..Enable the charger detector.
    // 0b1..Disable the charger detector.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::CHRG_DETECT_CLR, 1, 19, 0x0> CHK_CHRG_B;   // Check the charger connection
    // 0b0..Check whether a charger (either a dedicated charger or a host charger) is connected to USB port.
    // 0b1..Do not check whether a charger is connected to the USB port.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::CHRG_DETECT_CLR, 1, 18, 0x0> CHK_CONTACT;  // Check the contact of USB plug
    // 0b0..Do not check the contact of USB plug.
    // 0b1..Check whether the USB plug has been in contact with each other
}  // namespace CHRG_DETECT_CLR

// USB Charger Detect Register
namespace CHRG_DETECT_TOG {
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::CHRG_DETECT_TOG, 1, 20, 0x0> EN_B;         // Control the charger detector.
    // 0b0..Enable the charger detector.
    // 0b1..Disable the charger detector.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::CHRG_DETECT_TOG, 1, 19, 0x0> CHK_CHRG_B;   // Check the charger connection
    // 0b0..Check whether a charger (either a dedicated charger or a host charger) is connected to USB port.
    // 0b1..Do not check whether a charger is connected to the USB port.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::CHRG_DETECT_TOG, 1, 18, 0x0> CHK_CONTACT;  // Check the contact of USB plug
    // 0b0..Do not check the contact of USB plug.
    // 0b1..Check whether the USB plug has been in contact with each other
}  // namespace CHRG_DETECT_TOG

// USB VBUS Detect Status Register
namespace VBUS_DETECT_STAT {
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::VBUS_DETECT_STAT, 1, 3> VBUS_VALID;  // VBus valid for USB OTG
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::VBUS_DETECT_STAT, 1, 2> AVALID;      // Indicates VBus is valid for a A-peripheral
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::VBUS_DETECT_STAT, 1, 1> BVALID;      // Indicates VBus is valid for a B-peripheral
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::VBUS_DETECT_STAT, 1, 0> SESSEND;     // Session End for USB OTG

namespace vals {
constexpr regs::RegValue32<1, 3> VBUS_VALID;
constexpr regs::RegValue32<1, 2> AVALID;
constexpr regs::RegValue32<1, 1> BVALID;
constexpr regs::RegValue32<1, 0> SESSEND;
}  // namespace vals
}  // namespace VBUS_DETECT_STAT

// USB Charger Detect Status Register
namespace CHRG_DETECT_STAT {
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::CHRG_DETECT_STAT, 1, 3> DP_STATE;       // DP line state output of the charger detector.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::CHRG_DETECT_STAT, 1, 2> DM_STATE;       // DM line state output of the charger detector.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::CHRG_DETECT_STAT, 1, 1> CHRG_DETECTED;  // State of charger detection. This bit is a read only version of the state of the analog signal.
    // 0b0..The USB port is not connected to a charger.
    // 0b1..A charger (either a dedicated charger or a host charger) is connected to the USB port.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::CHRG_DETECT_STAT, 1, 0> PLUG_CONTACT;   // State of the USB plug contact detector.
    // 0b0..The USB plug has not made contact.
    // 0b1..The USB plug has made good contact.

namespace vals {
constexpr regs::RegValue32<1, 3> DP_STATE;
constexpr regs::RegValue32<1, 2> DM_STATE;
constexpr regs::RegValue32<1, 1> CHRG_DETECTED;
constexpr regs::RegValue32<1, 0> PLUG_CONTACT;
}  // namespace vals
}  // namespace CHRG_DETECT_STAT

// USB Loopback Test Register
namespace LOOPBACK {
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::LOOPBACK, 1, 0> UTMI_TESTSTART;  // Setting this bit can enable 1

namespace vals {
constexpr regs::RegValue32<1, 0> UTMI_TESTSTART;
}  // namespace vals
}  // namespace LOOPBACK

// USB Loopback Test Register
namespace LOOPBACK_SET {
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::LOOPBACK_SET, 1, 0, 0x0> UTMI_TESTSTART;  // Setting this bit can enable 1
}  // namespace LOOPBACK_SET

// USB Loopback Test Register
namespace LOOPBACK_CLR {
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::LOOPBACK_CLR, 1, 0, 0x0> UTMI_TESTSTART;  // Setting this bit can enable 1
}  // namespace LOOPBACK_CLR

// USB Loopback Test Register
namespace LOOPBACK_TOG {
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::LOOPBACK_TOG, 1, 0, 0x0> UTMI_TESTSTART;  // Setting this bit can enable 1
}  // namespace LOOPBACK_TOG

// USB Misc Register
namespace MISC {
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::MISC, 1, 30> EN_CLK_UTMI;        // Enables the clk to the UTMI block.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::MISC, 1,  1> EN_DEGLITCH;        // Enable the deglitching circuit of the USB PLL output.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::MISC, 1,  0> HS_USE_EXTERNAL_R;  // Use external resistor to generate the current bias for the high speed transmitter
    // This bit should not be changed unless recommended by NXP.

namespace vals {
constexpr regs::RegValue32<1, 30> EN_CLK_UTMI;
constexpr regs::RegValue32<1,  1> EN_DEGLITCH;
constexpr regs::RegValue32<1,  0> HS_USE_EXTERNAL_R;
}  // namespace vals
}  // namespace MISC

// USB Misc Register
namespace MISC_SET {
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::MISC_SET, 1, 30, 0x0> EN_CLK_UTMI;        // Enables the clk to the UTMI block.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::MISC_SET, 1,  1, 0x0> EN_DEGLITCH;        // Enable the deglitching circuit of the USB PLL output.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::MISC_SET, 1,  0, 0x0> HS_USE_EXTERNAL_R;  // Use external resistor to generate the current bias for the high speed transmitter
    // This bit should not be changed unless recommended by NXP.
}  // namespace MISC_SET

// USB Misc Register
namespace MISC_CLR {
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::MISC_CLR, 1, 30, 0x0> EN_CLK_UTMI;        // Enables the clk to the UTMI block.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::MISC_CLR, 1,  1, 0x0> EN_DEGLITCH;        // Enable the deglitching circuit of the USB PLL output.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::MISC_CLR, 1,  0, 0x0> HS_USE_EXTERNAL_R;  // Use external resistor to generate the current bias for the high speed transmitter
    // This bit should not be changed unless recommended by NXP.
}  // namespace MISC_CLR

// USB Misc Register
namespace MISC_TOG {
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::MISC_TOG, 1, 30, 0x0> EN_CLK_UTMI;        // Enables the clk to the UTMI block.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::MISC_TOG, 1,  1, 0x0> EN_DEGLITCH;        // Enable the deglitching circuit of the USB PLL output.
template <size_t Index>
constexpr INSTANCE_Reg<Index, &USB_ANALOG_Layout::INSTANCE_Layout::MISC_TOG, 1,  0, 0x0> HS_USE_EXTERNAL_R;  // Use external resistor to generate the current bias for the high speed transmitter
    // This bit should not be changed unless recommended by NXP.
}  // namespace MISC_TOG

}  // namespace INSTANCE

// Chip Silicon Version
namespace DIGPROG {
constexpr USB_ANALOG_Reg<&USB_ANALOG_Layout::DIGPROG, 32, 0> SILICON_REVISION;  // Chip silicon revision
    // 0b00000000011011000000000000000000..Silicon revision 1.0
}  // namespace DIGPROG

}  // namespace USB_ANALOG

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
