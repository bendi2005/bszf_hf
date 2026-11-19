#include "timing.h"
#include "em_cmu.h"
static uint32_t msTicks = 0;

void Timing_Init(void) {
    if (SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE) / 1000)) {
        while (1);
    }
}

void Timing_Delay(uint32_t ms) {
    uint32_t start = msTicks;
    while ((msTicks - start) < ms);
}
