#ifndef UART_STUFF_H
#define UART_STUFF_H
#include "em_usart.h"
#include "em_gpio.h"
#include "em_cmu.h"
#include "em_device.h"

// UART0 init
void Uartstuff_InitUsart(void);

// Enables UART0 interrupt 
void Uartstuff_EnableInterrupt(void);

// overriding default ISR
void UART0_RX_IRQHandler(void);

uint8_t Uartstuff_getMove(void);

#endif


