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

void app_init(void)
{
	Timing_InitTiming();
	// DISP_CLR
	Game_InitGame();
	// Disp game 
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
		Timing_Delay(1000);
		Game_Refresh_Snake();
		if(Game_getIsGameOver())
		{
			return;
		}
		// Display game state
	}
	else	
	{
		// display decimal points flashing (game over state)
		Timing_Delay(500); // fast flashing
	}
}
