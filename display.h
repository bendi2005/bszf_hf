#ifndef DISPLAY_H
#define DISPLAY_H
#include "stdint.h"
#include "stdbool.h"

// Initialises display 
void Display_InitDisplay(void);

// Clears displays (so the board, the "invalid" segments and score is clear)
void Display_ClearLCD(void);

// Displays the current state of the board 
// Iterates through the segments, and displays the active ones
void Display_UpdateBoard(void);

// Displays the current lenght (== score) on the upper segments
void Display_UpdateScore(uint8_t);

// Function called by app.c
// calls Display_UpdateBoard and Display_UpdateScore
void Display_DisplayGameState(void);

// Toggles the displaying of the decimal points 
void Display_ToggleDecimalPoints(void);

#endif
