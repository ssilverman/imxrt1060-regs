#include <cinttypes>
#include <cstdint>

#include <Arduino.h>

#include "hardware/teensy4/CCM.h"
#include "hardware/teensy4/CCM_ANALOG.h"
#include "hardware/teensy4/DCB.h"
#include "hardware/teensy4/DWT.h"
#include "hardware/teensy4/IOMUXC_GPR.h"

using namespace qindesign::hardware::teensy4;

static void enable_enet_clocks();
static void disable_enet_clocks();
static bool arm_high_resolution_clock_init();
static uint32_t arm_high_resolution_clock_count();

static bool armCounterInitted = false;

void setup() {
  Serial.begin(115200);
  while (!Serial && millis() < 4000) {
    // Wait for Serial
  }
  printf("Waiting for 1.5s...\r\n");
  delay(1500);

  enable_enet_clocks();
  printf("ENET enabled\r\n");
  delay(500);
  disable_enet_clocks();
  printf("ENET disabled\r\n");

  armCounterInitted = arm_high_resolution_clock_init();
  if (!armCounterInitted) {
    printf("Error: ARM HRC init\r\n");
  }
}

void loop() {
  // Print the cycle count every second
  if (armCounterInitted) {
    printf("%" PRIu32 "\r\n", arm_high_resolution_clock_count());
    delay(1000);
  }
}

// Enables the Ethernet-related clocks. See also disable_enet_clocks().
static void enable_enet_clocks() {
  // Enable the Ethernet clock

  CCM_CCGR1_ENET = kCCM_CCGR_ON;

  // Configure PLL6 for 50 MHz (page 1112)
  CCM_ANALOG->PLL_ENET_SET = CCM_ANALOG_PLL_ENET_BYPASS(1);
  CCM_ANALOG->PLL_ENET_CLR = 0
                             | CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC(3)
                             | CCM_ANALOG_PLL_ENET_ENET2_DIV_SELECT(3)
                             | CCM_ANALOG_PLL_ENET_DIV_SELECT(3)
                             ;
  CCM_ANALOG->PLL_ENET_SET = 0
                             | CCM_ANALOG_PLL_ENET_ENET_25M_REF_EN(1)
                             // | CCM_ANALOG_PLL_ENET_ENET2_REF_EN(1)
                             | CCM_ANALOG_PLL_ENET_ENABLE(1)
                             // | CCM_ANALOG_PLL_ENET_ENET2_DIV_SELECT(1)
                             | CCM_ANALOG_PLL_ENET_DIV_SELECT(1)
                             ;
  CCM_ANALOG->PLL_ENET_CLR = CCM_ANALOG_PLL_ENET_POWERDOWN(1);
  while (CCM_ANALOG_PLL_ENET_LOCK == 0) {
    // Wait for PLL lock
  }
  CCM_ANALOG->PLL_ENET_CLR = CCM_ANALOG_PLL_ENET_BYPASS(1);

  // Configure REFCLK to be driven as output by PLL6 (page 325)
  IOMUXC_GPR_GPR1_ENET1_CLK_SEL     = 0;
  IOMUXC_GPR_GPR1_ENET_IPG_CLK_S_EN = 1;
  IOMUXC_GPR_GPR1_ENET1_TX_CLK_DIR  = 1;
}

// Disables everything enabled with enable_enet_clocks().
static void disable_enet_clocks() {
  // Configure REFCLK
  IOMUXC_GPR_GPR1_ENET1_TX_CLK_DIR = 0;

  // Stop the PLL (first bypassing)
  CCM_ANALOG->PLL_ENET_SET = CCM_ANALOG_PLL_ENET_BYPASS(1);
  CCM_ANALOG->PLL_ENET = 0
                         | CCM_ANALOG_PLL_ENET_BYPASS(1)      // Reset to default
                         | CCM_ANALOG_PLL_ENET_POWERDOWN(1)
                         | CCM_ANALOG_PLL_ENET_DIV_SELECT(1)
                         ;

  // Disable the clock for ENET
  CCM_CCGR1_ENET = kCCM_CCGR_OFF;
}

// Initializes the cycle counter and returns whether it's supported. This uses
// heuristics and isn't guaranteed to work for all cases.
static bool arm_high_resolution_clock_init() {
  // First enable DWT and check
  if (DCB_DEMCR_TRCENA == 0) {
    DCB_DEMCR_TRCENA = 1;

    // Check that it was enabled
    if (DCB_DEMCR_TRCENA == 0) {
      return false;
    }
  }

  // Next, check the obvious feature presence
  if (DWT_CTRL_NOCYCCNT != 0) {
    return false;
  }

  // Next, check if the cycle count is enabled
  if (DWT_CTRL_CYCCNTENA == 0) {
    DWT_CTRL_CYCCNTENA = 1;

    // Check that it was enabled
    if (DWT_CTRL_CYCCNTENA == 0) {
      return false;
    }
  }

  return true;
}

static uint32_t arm_high_resolution_clock_count() {
  return DWT->CYCCNT;
}
