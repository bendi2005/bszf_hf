#ifndef TIMING_H
#define TIMING_H

#include <stdint.h>
#include <stdbool.h>

void Timing_InitTiming(void);
void Timing_StartPeriodicMs(uint32_t period_ms);
bool Timing_ConsumeTick(void);
void Timing_SleepEM1(void);

void Timing_Delay(uint32_t ms);

#endif 
