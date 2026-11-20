#ifndef UART_STUFF_H
#define UART_STUFF_H
#include "em_usart.h"
#include "em_gpio.h"
#include "em_cmu.h"
#include "em_device.h"

// UART0 init
void Uartstuff_InitUsart(void);

// Enables UART0 interrupt and clears recieve buffer
void Uartstuff_EnableInterrupt(void);

// Overrides default ISR
void UART0_RX_IRQHandler(void);

// Getter for logically valid input to the game 
uint8_t Uartstuff_getMove(void);

#endif


