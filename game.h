//Az a megvalositasi otlet, hogy: a szegmensek tudjak hogy mi az idjuk (mittudomen 0-32) es tudja, hogy mik az utana kovetkezo 4egtaj szerinti mezok. minden ticken meghiv a jatek egy frissito fuggvenyt, megnezi, hogy volt-e input az uarton (es akkor az lesz az uj iranya a kigyo fejenek), aztan meghiv egy fuggvenyt ami vegigmegy a kigyo strukturajan, ahol minden kigyoreszt (tudja melyik szegmensen van, es milyen 4egtaj iranyba megy), megnezi, hogy a kigyo eleje elotti szegmens ures-e (ha nem akkor a kovetkezo ciklust nem csinalja meg es gameover) aztan a legelso szegmenst lepteti a kovetkezore, a tobbit pedig a listaban az elotte levo "regi" helyere (ezt ugy, hogy hatulrol megyunk es a legelso elemet kulon utana kezeljuk, mert csak o tudja milyen iranyba kell menni),  ehhhez pl a display.h-ba be kell includeolnom a segmentlcd.h-t nem? hogy sajat mezo adatstrukturat csinaljak belole


// TODO getters for app.c
// TODO static 
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
void Game_InitGame(void);

// Initialises snake:
// Sets starting position, direction, and length
void Game_InitSnake(void);

// TODO: rewrite comment on the fixed behavior
// Main gameplay loop: (in order)
// Checks if gameover happened
// Moves each body part and the head to the next tile
// Moves body parts, by iterating backwards
// and placing the body part to the previous location of the one in front of it

// Moves head
// Checks if food was eaten: if yes; extends the snake and spawns new food
void Game_Refresh_Snake(void);

// Checks if the head would collide with a body part: if yes; game is over
void Game_isGameOver(void);

// returns length of the snake (including head)
uint8_t Game_getLen(void);

// generates random number to place the food on TODO real random (srand)
uint8_t Game_GenRandomTileNumber(void);

// spawns food on an eligible tile
void Game_SpawnFood(void);

// checks if a food is on the same tile as head 
void Game_FoodCheck(void);

// Places the "new" body part, behind the existing last (the "old" tail after moving)
void Game_ExtendSnake(uint8_t);

// Moves a body part to the location of the one in front
// edge case: first body part behind head: handled
void Game_MoveSnakeBody(uint8_t);

// "Getters" Used only in game.c, for clearer code 
uint8_t Game_getSnakeBodyPos(uint8_t);
uint8_t Game_getSnakeHeadPos(void);
uint8_t Game_getSnakeHeadNextPos(void);

uint8_t Game_SearchTileByPos(uint8_t);

// Updates snakes direction (turns it) based on input
// 'j' => right		'b' => left
//checking the validity of the input is handled by uart_stuff
void Game_Step(uint8_t);

// getters for app.c (since the variables are static)
bool Game_getIsGameOver(void);
uint8_t Game_getFoodPos(void);
bool Game_getTileIsActive(uint8_t);

// Toggles food tile activity for displaying it
void Game_ToggleFoodTileActive(void);

#endif

