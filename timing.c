#include "timing.h"
#include "em_cmu.h"
static uint32_t msTicks = 0;

// initialises delayer to ms
// TODO: szebb lenne makroval
void Timing_InitTiming(void) {
    if (SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE) / 1000)) {
        while (1);
    }
}

// countrs down and ends when the specified time passes
void Timing_Delay(uint32_t ms) {
    uint32_t start = msTicks;
    while ((msTicks - start) < ms);
}
