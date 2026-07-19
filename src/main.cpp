// To use the old way, set this to 1.
#define USE_OLD_WAY 0

#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <utility>

#include <Arduino.h>
#include <elapsedMillis.h>

// Undefine some conflicting Arduino-defined things
#undef PI

#if !USE_OLD_WAY
#include "hardware/imxrt1060/CCM.h"
#include "hardware/imxrt1060/CCM_ANALOG.h"
#include "hardware/imxrt1060/DCB.h"
#include "hardware/imxrt1060/DWT.h"
#include "hardware/imxrt1060/IOMUXC_GPR.h"
#include "hardware/imxrt1060/SCB.h"
#include "hardware/imxrt1060/USB.h"
#endif  // !USE_OLD_WAY

#if !USE_OLD_WAY
using namespace qindesign::hardware::imxrt1060;
#endif  // !USE_OLD_WAY

static void reboot();
static void enable_enet_clocks();
static void disable_enet_clocks();
static bool arm_high_resolution_clock_init();
static uint32_t arm_high_resolution_clock_count();

static constexpr float kStartupDelay = 1.5f;
static constexpr float kRunTime      = 20.0f;

static bool hasARMCounter = false;
static elapsedMillis mainTimer;
static elapsedMillis counterTimer;

#if USE_OLD_WAY
// #define CLRSET(reg, clear, set) ((reg) = ((reg) & ~(clear)) | (set))

// Clears some bits in a 32-bit register and then sets others.
[[gnu::always_inline]]
static inline void clearAndSet32(volatile uint32_t* const reg,
                                 const uint32_t clear, const uint32_t set) {
  *reg = (*reg & ~clear) | set;
}
#endif  // USE_OLD_WAY

// Main program setup.
[[gnu::weak]]
void setup() {
  Serial.begin(115200);
  while (!Serial && millis() < 4'000) {
    // Wait for Serial
  }
  printf("Waiting for %gs...\r\n", kStartupDelay);
  delay(static_cast<uint32_t>(kStartupDelay * 1'000));

  enable_enet_clocks();
  printf("ENET enabled\r\n");
  delay(500);
  disable_enet_clocks();
  printf("ENET disabled\r\n");

  hasARMCounter = arm_high_resolution_clock_init();
  if (!hasARMCounter) {
    printf("Error: ARM HRC init\r\n");
  }

  printf("Running for %gs...\r\n", kRunTime);

  mainTimer = 0;
  counterTimer = 0;
}

[[gnu::weak]]
// Main program loop.
void loop() {
  // Print the cycle count every second
  if (hasARMCounter) {
    if (counterTimer >= 1'000) {
      printf("%" PRIu32 "\r\n", arm_high_resolution_clock_count());
      counterTimer = 0;
    }
  }

  if (mainTimer >= static_cast<uint32_t>(kRunTime * 1'000)) {
    printf("Rebooting...\r\n");
    delay(1000);
    reboot();
  }
}

// Reboots the Teensy.
[[noreturn]]
static void reboot() {
#if !USE_OLD_WAY
  USB1::group->USBCMD = 0;  // Disconnect USB
  delay(50);                // Enough time for USB hubs/ports to detect disconnect

  asm volatile ("dsb sy" ::: "memory");
  SCB::group->AIRCR = SCB::AIRCR::VECTKEY(0x05fa) |
                      (SCB::group->AIRCR & SCB::AIRCR::PRIGROUP.kMask) |
                      SCB::AIRCR::SYSRESETREQ(1);
      // Keep priority group unchanged
#else
  USB1_USBCMD = 0;  // Disconnect USB
  delay(50);        // Enough time for USB hubs/ports to detect disconnect

  asm volatile ("dsb sy" ::: "memory");
  SCB_AIRCR = (0x05faU << 16) | (SCB_AIRCR & (0x7U << 8)) | 0x0004U;
      // Keep priority group unchanged
#endif  // !USE_OLD_WAY

  asm volatile ("dsb sy" ::: "memory");

  // Wait for reboot
  while (true) {
    asm volatile ("nop");
  }

#if (__cplusplus < 202302L)
  __builtin_unreachable();
#else
  std::unreachable();
#endif  // C++ < 23
}

// Enables the Ethernet-related clocks. See also disable_enet_clocks().
static void enable_enet_clocks() {
#if !USE_OLD_WAY
  // Enable the Ethernet clock
  CCM::CCGR1::ENET = CCM::CCGR::kON;

  // Configure PLL6 for 50 MHz (page 1112)
  CCM_ANALOG::group->PLL_ENET_SET = CCM_ANALOG::PLL_ENET::BYPASS(1);
  CCM_ANALOG::group->PLL_ENET_CLR = 0
                                    | CCM_ANALOG::PLL_ENET::BYPASS_CLK_SRC(3)
                                    | CCM_ANALOG::PLL_ENET::ENET2_DIV_SELECT(3)
                                    | CCM_ANALOG::PLL_ENET::DIV_SELECT(3);
  CCM_ANALOG::group->PLL_ENET_SET = 0
                                    | CCM_ANALOG::PLL_ENET::ENET_25M_REF_EN(1)
                                    // | CCM_ANALOG::PLL_ENET::ENET2_REF_EN(1)
                                    | CCM_ANALOG::PLL_ENET::ENABLE(1)
                                    // | CCM_ANALOG::PLL_ENET::ENET2_DIV_SELECT(1)
                                    | CCM_ANALOG::PLL_ENET::DIV_SELECT(1);
  CCM_ANALOG::group->PLL_ENET_CLR = CCM_ANALOG::PLL_ENET::POWERDOWN(1);
  while (CCM_ANALOG::PLL_ENET::LOCK == 0) {
    // Wait for PLL lock
  }
  CCM_ANALOG::group->PLL_ENET_CLR = CCM_ANALOG::PLL_ENET::BYPASS(1);

  // Configure REFCLK to be driven as output by PLL6 (page 325)
  IOMUXC_GPR::GPR1::ENET1_CLK_SEL     = 0;
  IOMUXC_GPR::GPR1::ENET_IPG_CLK_S_EN = 1;
  IOMUXC_GPR::GPR1::ENET1_TX_CLK_DIR  = 1;
#else
  // Enable the Ethernet clock
  CCM_CCGR1 |= CCM_CCGR1_ENET(CCM_CCGR_ON);

  // Configure PLL6 for 50 MHz (page 1112)
  CCM_ANALOG_PLL_ENET_SET = CCM_ANALOG_PLL_ENET_BYPASS;
  CCM_ANALOG_PLL_ENET_CLR = 0
                            | CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC(3)
                            | CCM_ANALOG_PLL_ENET_ENET2_DIV_SELECT(3)
                            | CCM_ANALOG_PLL_ENET_DIV_SELECT(3)
                            ;
  CCM_ANALOG_PLL_ENET_SET = 0
                            | CCM_ANALOG_PLL_ENET_ENET_25M_REF_EN
                            // | CCM_ANALOG_PLL_ENET_ENET2_REF_EN
                            | CCM_ANALOG_PLL_ENET_ENABLE
                            // | CCM_ANALOG_PLL_ENET_ENET2_DIV_SELECT(1)
                            | CCM_ANALOG_PLL_ENET_DIV_SELECT(1)
                            ;
  CCM_ANALOG_PLL_ENET_CLR = CCM_ANALOG_PLL_ENET_POWERDOWN;
  while ((CCM_ANALOG_PLL_ENET & CCM_ANALOG_PLL_ENET_LOCK) == 0) {
    // Wait for PLL lock
  }
  CCM_ANALOG_PLL_ENET_CLR = CCM_ANALOG_PLL_ENET_BYPASS;
  // printf("PLL6 = %08" PRIX32 "h (should be 80202001h)\n", CCM_ANALOG_PLL_ENET);

  // Configure REFCLK to be driven as output by PLL6 (page 325)
  clearAndSet32(
      &IOMUXC_GPR_GPR1,
      IOMUXC_GPR_GPR1_ENET1_CLK_SEL,
      IOMUXC_GPR_GPR1_ENET_IPG_CLK_S_EN | IOMUXC_GPR_GPR1_ENET1_TX_CLK_DIR);
#endif  // !USE_OLD_WAY
}

// Disables everything enabled with enable_enet_clocks().
static void disable_enet_clocks() {
#if !USE_OLD_WAY
  // Configure REFCLK
  IOMUXC_GPR::GPR1::ENET1_TX_CLK_DIR = 0;

  // Stop the PLL (first bypassing)
  CCM_ANALOG::group->PLL_ENET_SET = CCM_ANALOG::PLL_ENET::BYPASS(1);
  CCM_ANALOG::group->PLL_ENET = 0
                                | CCM_ANALOG::PLL_ENET::BYPASS(1)  // Reset to default
                                | CCM_ANALOG::PLL_ENET::POWERDOWN(1)
                                | CCM_ANALOG::PLL_ENET::DIV_SELECT(1);

  // Disable the clock for ENET
  CCM::CCGR1::ENET = CCM::CCGR::kOFF;
#else
  // Configure REFCLK
  clearAndSet32(&IOMUXC_GPR_GPR1, IOMUXC_GPR_GPR1_ENET1_TX_CLK_DIR, 0);

  // Stop the PLL (first bypassing)
  CCM_ANALOG_PLL_ENET_SET = CCM_ANALOG_PLL_ENET_BYPASS;
  CCM_ANALOG_PLL_ENET = 0
                        | CCM_ANALOG_PLL_ENET_BYPASS         // Reset to default
                        | CCM_ANALOG_PLL_ENET_POWERDOWN
                        | CCM_ANALOG_PLL_ENET_DIV_SELECT(1)
                        ;

  // Disable the clock for ENET
  CCM_CCGR1 &= ~CCM_CCGR1_ENET(CCM_CCGR_ON);
#endif  // !USE_OLD_WAY
}

#if USE_OLD_WAY
// DWT Control Register
static const auto kDWT_CTRL   = reinterpret_cast<volatile uint32_t*>(0xE0001000);
// DWT Cycle Count Register
static const auto kDWT_CYCCNT = reinterpret_cast<volatile uint32_t*>(0xE0001004);
// Debug Exeption and Monitor Control Register
static const auto kDEMCR      = reinterpret_cast<volatile uint32_t*>(0xE000EDFC);

// Values
static constexpr auto kDEMCR_TRCENA       = uint32_t{1 << 24};
static constexpr auto kDWT_CTRL_CYCCNTENA = uint32_t{1 <<  0};
static constexpr auto kDWT_CTRL_NOCYCCNT  = uint32_t{1 << 25};
#endif  // USE_OLD_WAY

// Initializes the cycle counter and returns whether it's supported. This uses
// heuristics and isn't guaranteed to work for all cases.
static bool arm_high_resolution_clock_init() {
#if !USE_OLD_WAY
  // First enable DWT and check
  if (DCB::DEMCR::TRCENA == 0) {
    DCB::DEMCR::TRCENA = 1;

    // Check that it was enabled
    if (DCB::DEMCR::TRCENA == 0) {
      return false;
    }
  }

  // Next, check the obvious feature presence
  if (DWT::CTRL::NOCYCCNT != 0) {
    return false;
  }

  // Next, check if the cycle count is enabled
  if (DWT::CTRL::CYCCNTENA == 0) {
    DWT::CTRL::CYCCNTENA = 1;

    // Check that it was enabled
    if (DWT::CTRL::CYCCNTENA == 0) {
      return false;
    }
  }
#else
  // First enable DWT and check
  if ((*kDEMCR & kDEMCR_TRCENA) == 0) {
    *kDEMCR |= kDEMCR_TRCENA;

    // Check that it was enabled
    if ((*kDEMCR & kDEMCR_TRCENA) == 0) {
      return false;
    }
  }

  // Next, check the obvious feature presence
  if ((*kDWT_CTRL & kDWT_CTRL_NOCYCCNT) != 0) {
    return false;
  }

  // Next, check if the cycle count is enabled
  if ((*kDWT_CTRL & kDWT_CTRL_CYCCNTENA) == 0) {
    *kDWT_CTRL |= kDWT_CTRL_CYCCNTENA;

    // Check that it was enabled
    if ((*kDWT_CTRL & kDWT_CTRL_CYCCNTENA) == 0) {
      return false;
    }
  }
#endif  // !USE_OLD_WAY

  return true;
}

static uint32_t arm_high_resolution_clock_count() {
#if !USE_OLD_WAY
  return DWT::group->CYCCNT;
#else
  return ARM_DWT_CYCCNT;
#endif  // !USE_OLD_WAY
}
