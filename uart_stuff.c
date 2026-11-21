#include "uart_stuff.h"
// based on class #3 and #4's material
// this "buffer" is not the same as the UART's input buffer
// this is for latching the input given by the user 
// TODO: if this is confusing just rename
static volatile bool input_in_buffer;

// flag for logically valid input
static volatile uint8_t valid_input;

void Uartstuff_InitUsart(void) {
	// Enable clocks 
	CMU_ClockEnable(cmuClock_GPIO, true);
	CMU_ClockEnable(cmuClock_UART0, true);

	// Link uart pins to board controller
	GPIO_PinModeSet(gpioPortF, 7, gpioModePushPull, 1);

		
	// UART0 config
	// 115200 Baud, 8N1 frame 
	USART_InitAsync_TypeDef init = USART_INITASYNC_DEFAULT;
	USART_InitAsync(UART0, &init);

	// PE1: input
	GPIO_PinModeSet(gpioPortE, 1, gpioModeInput, 0);

	// Ask UART0 nicely, to please use these pins
	// Select "Location 1" as the routing configuration
	UART0->ROUTE |= UART_ROUTE_LOCATION_LOC1;
	// Enable TX for routing
	UART0->ROUTE |= UART_ROUTE_RXPEN;
	
	input_in_buffer = false;
	valid_input = 0;
	return;
}

void Uartstuff_EnableInterrupt(void) {
	// Clears recieve buffer from any input it might have recieved during the init phase of the game
	UART0->CMD = UART_CMD_CLEARRX;
	NVIC_ClearPendingIRQ(UART0_RX_IRQn);

	// Raises interrupt if anything enters the buffer
	USART_IntEnable(UART0,USART_IF_RXDATAV);

	// Allows interrupt to be served by processor
	// enum from: efm32gg_usart.h
	NVIC_EnableIRQ(UART0_RX_IRQn);

	return; 
}


// ISR function name from: startup_efm32gg.c
void UART0_RX_IRQHandler(void) {
	// Reads valid (not the same as logically valid) input from UART0 and lowers interrupt flag
	// Using a non-static variable is actually faster, because the comparison after
	// happens using the register inside the cpu (whereas a static var would be in bss (thanks gemini))
	uint8_t input = USART_RxDataGet(UART0);
	// We read the input, even if it "goes to waste", as RxDataGet lowers the interrupt flag 
	// Another branch in the if would be slower (i think)
	if(!input_in_buffer) {
		// check if its a logically valid input
		if(('j' == input) || ('b' == input))
		{
			valid_input = input;
			input_in_buffer = true;
		} 
	}
	
	return;	
}

	// TODO: will this cause problems? (interrupt) (if so we need an interrupenable and disable function)// Passes logically valid input to the game 
uint8_t Uartstuff_getMove(void) {
	// If no input is given, it should go straight (and not the last input) 
	uint8_t ret_valid_input = 0;
	if(input_in_buffer) 
	{
		ret_valid_input = valid_input;

		// Open latch, for new potential move
		input_in_buffer = false;
	}
	
	return ret_valid_input;
}
