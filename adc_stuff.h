#ifndef ADC_STUFF_H
#define ADC_STUFF_H
#include "em_adc.h"
#include "em_cmu.h"
#include "stdint.h"

#define SEED_LEN 32

// Initialises ADC0 
// Default settings
// Single sample mode
void Adcstuff_InitAdc(void); 


// Getter that gets called in app.c
uint32_t Adcstuff_getSeed(void);

#endif
