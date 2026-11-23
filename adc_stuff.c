#include "adc_stuff.h"

void Adcstuff_InitAdc(void) {
	// Give clock to ADC0
	CMU_ClockEnable(cmuClock_ADC0, true);
	// The warmup time is not enough, but timebase is scuffed (cannot set it above 31)
	// We arent measuring for accuracy but for noise so its fine (i think)
	ADC_Init_TypeDef init_adc = ADC_INIT_DEFAULT; 
	// Time spent researching what I need to change from default (nothing): >40 minutes
	ADC_Init(ADC0, &init_adc);
	ADC_InitSingle_TypeDef init_adc_single = ADC_INITSINGLE_DEFAULT;
	init_adc_single.input = adcSingleInpTemp; // Use the temp sensor's voltage for noise
	ADC_InitSingle(ADC0, &init_adc_single);
	return;	
}

// Take a sample from the temperature sensor's voltage for random seed
// Use the LSB as noise
// We take 32 samples, each LSB gets shifted to form a 32 bit unsigned
static uint32_t Adcstuff_TakeSample(void) {
	uint32_t r_seed = 0;
	uint32_t temp = 0;
	uint32_t lsb_mask = 1;
	for(int i = 0; i < SEED_LEN; i++) {
		// Scan the signal
		ADC_Start(ADC0, adcStartSingle);
		// Wait for ADC to finish taking sample
		// If the valid data flag of the ADC is nonzero it finished sampling
		while(0 == ((ADC0->STATUS) & (ADC_STATUS_SINGLEDV)) );
		// Get the data from ADC0's data register
		// Clears valid data flag
		temp = ADC_DataSingleGet(ADC0);
		// Mask temp to get the LSB
		temp = temp & lsb_mask;
		// shift it to the ith digit of the seed 
		temp = temp << i; 
		// set the ith bit of seed to temp's ith bit (the lsb of the signal)
		r_seed = r_seed | temp;
	}
	return r_seed;
}

uint32_t Adcstuff_getSeed(void) {
	return Adcstuff_TakeSample();
}

