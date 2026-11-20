/***************************************************************************//**
 * @file
 * @brief Top level application functions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
#include "game.h"
#include "timing.h"
#include "uart_stuff.h"
#include "display.h"






// Initialises the modules
// First the timer (the order of this is unimportant, it is a relative delay, more info in timing.h)
// Initialises UART to recieve input
// Clear the display (turn off every tile)
// Initialises Game (more in game.h) 
// Displays the game state
// Clears recieve buffer of UART and enables it to throw interrupts and allows it the cpu to serve it
void app_init(void)
{
	Timing_InitTiming();
	Uartstuff_InitUsart();
	Display_InitDisplay();
	Game_InitGame();
	Display_DisplayGameState();
	Uartstuff_EnableInterrupt();
}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
	/*
	if(!gameover) {
		delay(gametick)
		game refresh
		if(gameover) { return }
		display game state
	}
	else 
	{
	display decimal points flashing
	delay(gameover tick)
	}

	*/
	if(!Game_getIsGameOver()) 
	{
		Timing_Delay(1000);		// set tickspeed (speed of snake) 

		Game_Refresh_Snake();
		if(Game_getIsGameOver())
		{
			return;
		}
		Display_DisplayGameState();
	}
	else	
	{
		Display_ToggleDecimalPoints();
		Timing_Delay(500); // set flashing speed
	}
}
