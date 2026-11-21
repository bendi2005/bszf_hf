#include "game.h"
#include "uart_stuff.h"
#include <stdlib.h>

// static flags
static bool hasAteApple;
static bool isGameOver; 
static Direction_t curDir;
static Turn_t nextTurn;
static uint8_t foodPos;

// the snake himself
static snake lajos;

// lookup table for the tiles: each tile (identified by unique id) knows its 6 neighbours in the 6 directions
// thank you Gemini
static tile board[TILE_COUNT] = {
    // --- Top horizontal row: A (Digits 1..7) | [0]=EAST, [1]=WEST ---
    { .tile_id =  0, .tile_isActive = false, .tile_neighbours = { {  1, 22, 30 }, {  6, 29, 21 } } }, // 1A
    { .tile_id =  1, .tile_isActive = false, .tile_neighbours = { {  2, 23, 31 }, {  0, 30, 22 } } }, // 2A
    { .tile_id =  2, .tile_isActive = false, .tile_neighbours = { {  3, 24, 32 }, {  1, 31, 23 } } }, // 3A
    { .tile_id =  3, .tile_isActive = false, .tile_neighbours = { {  4, 25, 33 }, {  2, 32, 24 } } }, // 4A
    { .tile_id =  4, .tile_isActive = false, .tile_neighbours = { {  5, 26, 34 }, {  3, 33, 25 } } }, // 5A
    { .tile_id =  5, .tile_isActive = false, .tile_neighbours = { {  6, 27, 35 }, {  4, 34, 26 } } }, // 6A
    { .tile_id =  6, .tile_isActive = false, .tile_neighbours = { {  0, 28, 36 }, {  5, 35, 27 } } }, // 7A

    // --- Middle horizontal row: G+M (Digits 1..7) | [0]=EAST, [1]=WEST ---
    { .tile_id =  7, .tile_isActive = false, .tile_neighbours = { {  8, 30, 22 }, { 13, 21, 29 } } }, // 1GM (START)
    { .tile_id =  8, .tile_isActive = false, .tile_neighbours = { {  9, 31, 23 }, {  7, 22, 30 } } }, // 2GM
    { .tile_id =  9, .tile_isActive = false, .tile_neighbours = { { 10, 32, 24 }, {  8, 23, 31 } } }, // 3GM
    { .tile_id = 10, .tile_isActive = false, .tile_neighbours = { { 11, 33, 25 }, {  9, 24, 32 } } }, // 4GM
    { .tile_id = 11, .tile_isActive = false, .tile_neighbours = { { 12, 34, 26 }, { 10, 25, 33 } } }, // 5GM
    { .tile_id = 12, .tile_isActive = false, .tile_neighbours = { { 13, 35, 27 }, { 11, 26, 34 } } }, // 6GM
    { .tile_id = 13, .tile_isActive = false, .tile_neighbours = { {  7, 36, 28 }, { 12, 27, 35 } } }, // 7GM

    // --- Bottom horizontal row: D (Digits 1..7) | [0]=EAST, [1]=WEST ---
    { .tile_id = 14, .tile_isActive = false, .tile_neighbours = { { 15, 22, 30 }, { 20, 29, 21 } } }, // 1D
    { .tile_id = 15, .tile_isActive = false, .tile_neighbours = { { 16, 23, 31 }, { 14, 30, 22 } } }, // 2D
    { .tile_id = 16, .tile_isActive = false, .tile_neighbours = { { 17, 24, 32 }, { 15, 31, 23 } } }, // 3D
    { .tile_id = 17, .tile_isActive = false, .tile_neighbours = { { 18, 25, 33 }, { 16, 32, 24 } } }, // 4D
    { .tile_id = 18, .tile_isActive = false, .tile_neighbours = { { 19, 26, 34 }, { 17, 33, 25 } } }, // 5D
    { .tile_id = 19, .tile_isActive = false, .tile_neighbours = { { 20, 27, 35 }, { 18, 34, 26 } } }, // 6D
    { .tile_id = 20, .tile_isActive = false, .tile_neighbours = { { 14, 28, 36 }, { 19, 35, 27 } } }, // 7D

    // --- Upper vertical row: 1F..7F, 7B | [0]=NORTH, [1]=SOUTH ---
    { .tile_id = 21, .tile_isActive = false, .tile_neighbours = { { 29,  0,  6 }, { 29, 13,  7 } } }, // 1F
    { .tile_id = 22, .tile_isActive = false, .tile_neighbours = { { 30,  1,  0 }, { 30,  7,  8 } } }, // 2F
    { .tile_id = 23, .tile_isActive = false, .tile_neighbours = { { 31,  2,  1 }, { 31,  8,  9 } } }, // 3F
    { .tile_id = 24, .tile_isActive = false, .tile_neighbours = { { 32,  3,  2 }, { 32,  9, 10 } } }, // 4F
    { .tile_id = 25, .tile_isActive = false, .tile_neighbours = { { 33,  4,  3 }, { 33, 10, 11 } } }, // 5F
    { .tile_id = 26, .tile_isActive = false, .tile_neighbours = { { 34,  5,  4 }, { 34, 11, 12 } } }, // 6F
    { .tile_id = 27, .tile_isActive = false, .tile_neighbours = { { 35,  6,  5 }, { 35, 12, 13 } } }, // 7F
    { .tile_id = 28, .tile_isActive = false, .tile_neighbours = { { 36,  0,  6 }, { 36, 13,  7 } } }, // 7B

    // --- Lower vertical row: 1E..7E, 7C | [0]=NORTH, [1]=SOUTH ---
    { .tile_id = 29, .tile_isActive = false, .tile_neighbours = { { 21,  7, 13 }, { 21, 20, 14 } } }, // 1E
    { .tile_id = 30, .tile_isActive = false, .tile_neighbours = { { 22,  8,  7 }, { 22, 14, 15 } } }, // 2E
    { .tile_id = 31, .tile_isActive = false, .tile_neighbours = { { 23,  9,  8 }, { 23, 15, 16 } } }, // 3E
    { .tile_id = 32, .tile_isActive = false, .tile_neighbours = { { 24, 10,  9 }, { 24, 16, 17 } } }, // 4E
    { .tile_id = 33, .tile_isActive = false, .tile_neighbours = { { 25, 11, 10 }, { 25, 17, 18 } } }, // 5E
    { .tile_id = 34, .tile_isActive = false, .tile_neighbours = { { 26, 12, 11 }, { 26, 18, 19 } } }, // 6E
    { .tile_id = 35, .tile_isActive = false, .tile_neighbours = { { 27, 13, 12 }, { 27, 19, 20 } } }, // 7E
    { .tile_id = 36, .tile_isActive = false, .tile_neighbours = { { 28,  7, 13 }, { 28, 20, 14 } } }, // 7C
};



// using srand would require stdlib, which is too bloated IMO
uint8_t Game_GenRandomTileNumber(void) {
	return rand() % TILE_COUNT;
}

void Game_SpawnFood(void) {
	uint8_t new_foodpos = Game_GenRandomTileNumber();
	// check for a valid tile (cannot spawn food onto snake)
	while(board[new_foodpos].tile_isActive)
	{
		new_foodpos = Game_GenRandomTileNumber();
	}
	foodPos = new_foodpos;
	return;
}

void Game_InitGame(void) {
	// clears all tiles
	for(int i = 0; i < TILE_COUNT; i++)
	{
		board[i].tile_isActive = false;
	}

	isGameOver = false;	
	hasAteApple = false;
	
	Game_InitSnake();

	// order matters here, to avoid spawning food onto the snake
	Game_SpawnFood();
}

// head would go to an active tile == bodypart is already there
void Game_isGameOver(void) {
	isGameOver = board[Game_getSnakeHeadNextPos()].tile_isActive;
	return;
}

void Game_InitSnake(void) {
	// starting location and direction as specified
	curDir = EAST;
	nextTurn = STRAIGHT;
	lajos.ingame_snake_len = 1;

	lajos.ingame_snake_head.head_dir = curDir;

	// sets starter tile active
	lajos.ingame_snake_head.head_pos = STARTER_TILE_ID;
	board[Game_SearchTileByPos(Game_getSnakeHeadPos())].tile_isActive = true;

	// we dont have to initalise the body, the parts of it will come when the snake gets extended

 	return;	

}

uint8_t Game_SearchTileByPos(uint8_t tilepos) {
	uint8_t r_tileid = 67;
	for(int i = 0; i < TILE_COUNT; i++) 
	{
		if(board[i].tile_id == tilepos) {
			r_tileid = i;
		}
	}
	if(r_tileid == 67){
		// hopefully this is redundant
	}
	return r_tileid;
}

uint8_t Game_getLen(void) {
	return lajos.ingame_snake_len;
}

uint8_t Game_getSnakeBodyPos(uint8_t bodyid) {
	return lajos.ingame_snake_body[bodyid].body_pos;
}

uint8_t Game_getSnakeHeadPos(void) {
	return lajos.ingame_snake_head.head_pos;
}

uint8_t Game_getSnakeHeadNextPos(void) {
	// Example: snake is on the middle horizontal tile, depending on the direction 
	// a turn right could mean NORTH or SOUTH 
	uint8_t facing = (curDir == WEST || curDir == SOUTH) ? 1 : 0;
    return board[Game_getSnakeHeadPos()].tile_neighbours[facing][nextTurn];
}

void Game_FoodCheck(void) {
	if(Game_getSnakeHeadPos() == foodPos) {
		hasAteApple = true;
	}	
	return;
}

void Game_ExtendSnake(uint8_t new_body_pos) {

	// Puts the new body into the array of body parts
	lajos.ingame_snake_body[Game_getLen() - 1].body_pos = new_body_pos;
	// Sets the tile of the new body part active
	board[new_body_pos].tile_isActive = true;
	lajos.ingame_snake_len++;
	// If the snake extended, it ate the food before, we spawn a new one
	hasAteApple = false;
	Game_SpawnFood();
	return;
}

void Game_Refresh_Snake(void) {

	// This has to happen before moving the snake
	uint8_t old_tail_pos = (Game_getLen() == 1)
                       ? Game_getSnakeHeadPos() // if the lenght is 1 (at the start) it would underflow
                       : Game_getSnakeBodyPos(Game_getLen() - 2);
	// Iterate on body
	for(int i = Game_getLen() - 2; i >= 0; i--)
	{
		Game_MoveSnakeBody(i);
	}

	// Set old head to inactive
	board[Game_getSnakeHeadPos()].tile_isActive = false;

	// Set new tiles active
	for(int i = Game_getLen() - 2; i >= 0; i--) 
	{
		board[Game_getSnakeBodyPos(i)].tile_isActive = true;
	}

	// Finally, move head

	// Sets nextTurn to the new value
	Game_Step(Uartstuff_getMove());

	// Moves the head to the next position 
	lajos.ingame_snake_head.head_pos = Game_getSnakeHeadNextPos(); 
	board[Game_getSnakeHeadPos()].tile_isActive = true;
	

	// TODO szebb lenne switch case
	// Sets direction depending on what kind of move we made
	if(nextTurn == RIGHT) 
	{
		curDir = (curDir + 3) % DIR_COUNT;
	} else if (nextTurn == LEFT) 
	{
		curDir = (curDir + 1) % DIR_COUNT;
	}

	// If nothing ever happens, we continue straight
	nextTurn = STRAIGHT;

	// if the head moved to the food, the snake ate it
	Game_FoodCheck();
	if(hasAteApple) {
		Game_ExtendSnake(old_tail_pos);
	}
	return;
}

void Game_MoveSnakeBody(uint8_t bodyid) {
	if(0 != bodyid) 
	{
		board[Game_getSnakeBodyPos(bodyid)].tile_isActive = false; //the tile it moved away from becomes inactive
		lajos.ingame_snake_body[bodyid].body_pos = Game_getSnakeBodyPos(bodyid - 1); //the new position, is the "old" position the body part that was ahead
	} else // if its the first body part (the head), the new position is calculated differently
	{
		board[Game_getSnakeBodyPos(bodyid)].tile_isActive = false;
		lajos.ingame_snake_body[bodyid].body_pos = Game_getSnakeHeadPos();
	}
	return;
}



// (all type of) validity of the input is checked by the UART module
void Game_Step(uint8_t input) {
	switch(input){
		case 'j':
			nextTurn = RIGHT;
			break;
		case 'b':
			nextTurn = LEFT;
			break;
		default: // no move was made
			nextTurn = STRAIGHT;
			break;
	}
	return;
}




bool Game_getIsGameOver(void) {
	return isGameOver;
}

uint8_t Game_getFoodPos(void) {
	return foodPos;
}

bool Game_getTileIsActive(uint8_t p_tileid) {
	return board[p_tileid].tile_isActive;
}

void Game_ToggleFoodTileActive(void) {
	// TODO: ez nem csak anny hogy !xy ?
	board[foodPos].tile_isActive = !board[foodPos].tile_isActive;
	return;
}

