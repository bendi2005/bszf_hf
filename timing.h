#ifndef TIMING_H
#define TIMING_H
#include "stdint.h"

// timing init
void Timing_InitTiming(void);

// function that app.c uses
// delay is in miliseconds
void Timing_Delay(uint32_t ms);

// Handles incrementing the delay
void SysTick_Handler(void);


#endif


