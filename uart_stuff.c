#include "uart_stuff.h"
// based on class #3 and #4's material
static volatile bool input_in_buffer;

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
void UART0_RX_IRQHandler(void){
	uint8_t input = UART0->RXDATA; 
	input_in_buffer = true;
	
	return;	
}
