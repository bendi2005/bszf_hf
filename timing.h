#ifndef TIMING_H
#define TIMING_H

#include <stdint.h>
#include <stdbool.h>

// Initialises sleeptimer 
void Timing_InitTiming(void);
// Start the periodic timing of given ms  
void Timing_StartPeriodicMs(uint32_t period_ms);


// Returns true if timer tick occured
// Clears tickflag
bool Timing_ConsumeTick(void);
// Puts the CPU into EM1 sleep mode until an interrupt wakes it
void Timing_SleepEM1(void);

// (Blocking) delay for given in EM1 mode
void Timing_Delay(uint32_t ms);
#endif 
