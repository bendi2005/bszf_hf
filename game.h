// Main logic is Game_Refresh_Snake()
#ifndef GAME_H
#define GAME_H
#include "stdint.h"
#include "stdbool.h"

#define DIR_COUNT 4
#define TILE_COUNT 37
#define STARTER_TILE_ID 7

// store direction 
typedef enum {
	EAST, NORTH, WEST, SOUTH
} Direction_t;


// store direction of next turn
typedef enum {
		STRAIGHT, RIGHT, LEFT
} Turn_t;

// tile struct 
typedef struct {
	const uint8_t tile_id; // from 0 to 36 
	bool tile_isActive;		// true, if a part (body or head) of the snake is on it (SEPARATE FROM FOOD)
	const uint8_t tile_neighbours[2][3];  // 6 neighbours 2*3 array
} tile;

// id of the tile the bodypart the snake is on (direction doesnt matter)
typedef struct {
	uint8_t body_pos;
} snake_body;

// id of the tile the head is on, and the direction its going 
typedef struct {
	uint8_t head_pos;
	Direction_t head_dir;
} snake_head;

// has the head, and the array of the body parts, taking up at maximum the whole board
typedef struct {
	snake_body ingame_snake_body[TILE_COUNT - 1];
	snake_head ingame_snake_head;
	uint8_t ingame_snake_len;
} snake;

// Initialises the game:
// Sets all tiles to inactive
// Sets flags for gameover and apple eating to false
// Initialises snake 
// Spawns food 
void Game_InitGame(uint32_t seed);

// Initialises snake:
// Sets starting position, direction, and length
void Game_InitSnake(void);

// Main gameplay loop: (in order)
// Checks for the next move (RIGHT, LEFT, STRAIGHT)
// Steps the body parts to their next position (Head is not a body part), body parts follow each other
// Moves the head
// Checks for GameOver
// If snake ate the food, it extends the snake
void Game_Refresh_Snake(void);

// Checks if the head would collide with a body part (wether its direct contact or cross hit)
void Game_isGameOver(void);

// Returns length of the snake (including head)
uint8_t Game_getLen(void);

// Generates random tile_id to attempt to place the food on 
uint8_t Game_GenRandomTileNumber(void);

// Spawns food on an eligible tile
void Game_SpawnFood(void);

// checks if a food is on the same tile as head 
void Game_FoodCheck(void);

// Places the "new" body part, behind the existing last (the "old" tail after moving)
void Game_ExtendSnake(uint8_t);

// Moves a body part to the location of the one in front
// edge case: first body part behind head: handled
void Game_MoveSnakeBody(uint8_t);

// "Getters" Used only in game.c, for clearer code 
//	uint8_t Game_getSnakeBodyPos(uint8_t);
//	uint8_t Game_getSnakeHeadPos(void);
//	uint8_t Game_getSnakeHeadNextPos(void);

// Returns the index in board, by tile id 
// In hindsight this is unneeded but its late 
uint8_t Game_SearchTileByPos(uint8_t);

// Updates snakes direction (turns it) based on input
// 'j' => right		'b' => left
//checking all validity of the input is handled by uart_stuff
void Game_Step(uint8_t);

// getters for app.c (since the variables are static)
bool Game_getIsGameOver(void);
uint8_t Game_getFoodPos(void);
bool Game_getTileIsActive(uint8_t);

// Toggles food tile activity for displaying it
void Game_ToggleFoodTileActive(void);

#endif

