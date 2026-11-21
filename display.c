#include "segmentlcd_individual.h"
#include "segmentlcd.h"
#include "em_device.h"
#include "em_cmu.h"
#include <stdbool.h>
#include <stdint.h>
#include "game.h"
#include "segmentlcdconfig.h"

// Stores the 7 chars (not tile or segment) the lower lcd represents
static SegmentLCD_LowerCharSegments_TypeDef lowerSegments[SEGMENT_LCD_NUM_OF_LOWER_CHARS] = { 0 };

static volatile bool decimalstatus = 0;

// Iterates through the segments and sets all of their bits to 0 (off)
void Display_ClearLCD(void) {
	decimalstatus = false;
	for(int i = 0; i < SEGMENT_LCD_NUM_OF_LOWER_CHARS; i++) {
		// acces to all segments in a char (see segmentlcd_individual.h)
		lowerSegments[i].raw = 0;
	}
	return;
}

void Display_InitDisplay(void) {
	SegmentLCD_Init(false);
	// just to be sure the display is empty
	//Display_ClearLCD();
}



// Displays a new state of the game (snake parts, food)
// Sets each segment (physical) to be turned on (1) or off (0)
// Calls the function to update the lower segments of the board  
void Display_UpdateBoard(void) {

	// TODO: we might need to clear the display, if this function is too slow in rendering the new gamestate

	// There are 7 chars on the display, so each "type" of segment has 7 instances*
	// *except for the 7B and 7C tiles

	// Food kicsit gany
	Game_ToggleFoodTileActive();	
    for (uint8_t i = 0; i < SEGMENT_LCD_NUM_OF_LOWER_CHARS; i++) {
        // Top horizontal row: 1A..7A (tile_id: 0..6)
        lowerSegments[i].a = Game_getTileIsActive(i);

        // Middle horizontal row: 1GM..7GM (tile_id: 7..13)
        bool middleActive = Game_getTileIsActive(7 + i);
        lowerSegments[i].g = middleActive;
        lowerSegments[i].m = middleActive;

        // Lower horizontal row: 1D..7D (tile_id: 14..20)
        lowerSegments[i].d = Game_getTileIsActive(14 + i);

        // Upper vertical row: 1F..7F (tile_id: 21..27)
        lowerSegments[i].f = Game_getTileIsActive(21 + i);

        // Lower vertical row: 1E..7E (tile_id: 29..35)
        lowerSegments[i].e = Game_getTileIsActive(29 + i);
    }

    // 7B and 7C (tile_id: 28, 36)
    lowerSegments[6].b = Game_getTileIsActive(28);
    lowerSegments[6].c = Game_getTileIsActive(36);

    // Turns on the segments we need 
    SegmentLCD_LowerSegments(lowerSegments);

	// Toggle food back to inactive
	Game_ToggleFoodTileActive();	

	return;
}

// Displays score (lenght of the current snake)
void Display_UpdateScore(uint8_t cur_len) {
    SegmentLCD_Number(cur_len);
	return;
}

// Helps with encapsulation
void Display_DisplayGameState(void) {
	Display_UpdateBoard();
	// Calls the public getter function of game.c
    Display_UpdateScore(Game_getLen());
	return;
}

void Display_ToggleDecimalPoints(void){

	// Sets on (true) or off (false) for the segments of decimal points on the board
	SegmentLCD_Symbol(LCD_SYMBOL_DP1, decimalstatus);
	SegmentLCD_Symbol(LCD_SYMBOL_DP2, decimalstatus);
    SegmentLCD_Symbol(LCD_SYMBOL_DP3, decimalstatus);
    SegmentLCD_Symbol(LCD_SYMBOL_DP4, decimalstatus);
    SegmentLCD_Symbol(LCD_SYMBOL_DP5, decimalstatus);
    SegmentLCD_Symbol(LCD_SYMBOL_DP6, decimalstatus);

	// Toggles on and off
	decimalstatus = !decimalstatus;

	return;
}

