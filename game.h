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

typedef enum {
	EAST, NORTH, WEST, SOUTH
} Direction_t;


typedef enum {
		STRAIGHT, RIGHT, LEFT
} Turn_t;

typedef struct {
	const uint8_t tile_id;
	bool tile_isActive;	
	const uint8_t tile_neighbours[2][3];
} tile;

typedef struct {
	uint8_t body_pos;
} snake_body;

typedef struct {
	uint8_t head_pos;
	Direction_t head_dir;
} snake_head;

typedef struct {
	snake_body ingame_snake_body[TILE_COUNT - 1];
	snake_head ingame_snake_head;
	uint8_t ingame_snake_len;
} snake;

void Game_InitGame(void);
void Game_InitSnake(void);
void Game_GameOverRoutine();

void Game_Refresh_Snake(void);

void Game_isGameOver(void);

uint8_t Game_getLen(void);

uint8_t Game_GenRandomTileNumber(void);
void Game_SpawnFood(void);
void Game_FoodCheck(void);

void Game_ExtendSnake(uint8_t);
void Game_MoveSnakeBody(uint8_t);

uint8_t Game_getSnakeBodyPos(uint8_t);
uint8_t Game_getSnakeHeadPos(void);
uint8_t Game_getSnakeHeadNextPos(void);

uint8_t Game_SearchTileByPos(uint8_t);

// Updates snakes direction (turns it) based on input
// 'j' => right		'b' => left
//checking the validity of the input is handled by uart_stuff
void Game_Step(uint8_t);

#endif

