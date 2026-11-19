#include "uart_stuff.h"
// based on class #3 and #4's material
static volatile bool input_in_buffer;
static volatile uint8_t valid_input;

void Uartstuff_InitUsart(void) {
	// Enable clocks 
	CMU_ClockEnable(cmuClock_GPIO, true);
	CMU_ClockEnable(cmuClock_USART0, true);

	// Link uart pins to board controller
	GPIO_PinModeSet(gpioPortF, 7, gpioModePushPull, 1);

		
	// UART0 config
	// 115200 Baud, 8N1 frame 
	USART_InitAsync_TypeDef init = USART_INITASYNC_DEFAULT;
	USART_InitAsync(USART0, &init);

	// PE0: output	PE1: input
	GPIO_PinModeSet(gpioPortE, 0, gpioModePushPull, 1);
	GPIO_PinModeSet(gpioPortE, 1, gpioModeInput, 0);

	// Ask UART0 nicely, to please use these pins
	// Select "Location 1" as the routing configuration
	UART0->ROUTE |= UART_ROUTE_LOCATION_LOC1;
	// Enable both RX and TX for routing
	UART0->ROUTE |= UART_ROUTE_TXPEN | UART_ROUTE_RXPEN;
	
	input_in_buffer = false;
	valid_input = 0;
	return;
}

void Uartstuff_EnableInterrupt(void) {
	// Raises interrupt if anything enters the buffer
	USART_IntEnable(UART0,USART_IF_RXDATAV);
	// Allows interrupt to be served by processor
	// efm32gg_usart.h
	NVIC_EnableIRQ(UART0_RX_IRQn);

	return; 
}

// startup_efm32gg.c
void UART0_RX_IRQHandler(void) {
	// reads valid (not the same as logically valid) input from UART0 and lowers interrupt flag
	
	// using a non-static variable is actually faster, because the comparison after
	// happens using the register inside the cpu (whereas a static var would be in bss (thanks gemini))
	uint8_t input = USART_RxDataGet(UART0);
	// we read the input, even if it "goes to waste", as RxDataGet lowers the interrupt flag 
	// another branch in the if would be slower (i think)
	if(!input_in_buffer) {
		// check if its a logically valid input
		if((input != 'j') || (input == 'b'))
		{
			valid_input = input;
			input_in_buffer = true;
		} 
	}
	
	return;	
}

uint8_t Uartstuff_getMove(void) {
	return valid_input;
}
