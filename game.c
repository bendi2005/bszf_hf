#include "game.h"

//todo starter mezo makrok
static bool hasAteApple;
static bool isGameOver; 
static Direction_t curDir;
static snake lajos;
static tile board[TILE_COUNT] = {0}; //TODO make board graph
static uint8_t foodPos;

uint8_t Game_GenRandomTileNumber(void) {
	//temporary rng
	return 13;
}

void Game_SpawnFood(void) {
	uint8_t new_foodpos = Game_GenRandomTileNumber();
	while(board[new_foodpos].tile_isActive)
	{
		new_foodpos = Game_GenRandomTileNumber();
	}
	foodPos = new_foodpos;
	return;
}

void Game_InitGame(void) {
	for(int i = 0; i < TILE_COUNT; i++)
	{
		board[i].tile_isActive = false;
	}
	//kezdo mezo board[67].tile_isActive = true
	// kezdo kaja

	isGameOver = false;	
	hasAteApple = false;
	curDir = EAST;
	
	Game_InitSnake();

	// order matters here
	Game_SpawnFood();
}

void Game_isGameOver(void) {
	isGameOver = board[Game_getSnakeHeadNextPos(curDir)].tile_isActive;
	return;
}

void Game_InitSnake(void) {
	lajos.ingame_snake_len = 1;

lajos.ingame_snake_head.head_dir = curDir;

	// starter mezo 
	lajos.ingame_snake_head.head_pos = 67;
	board[Game_SearchTileByPos(Game_getSnakeHeadPos())].tile_isActive = true;


	// bodyt nem kell inicializalni mert ...

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
		//baj van
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

uint8_t Game_getSnakeHeadNextPos(Direction_t dir) {
	uint8_t idx = Game_SearchTileByPos(Game_getSnakeHeadPos());
    return board[idx].tile_neighbours[dir];
}

void Game_FoodCheck(void) {
	if(Game_getSnakeHeadPos() == foodPos) {
		hasAteApple = true;
	}	
	return;
}

void Game_ExtendSnake(uint8_t new_body_pos) {

	lajos.ingame_snake_body[Game_getLen() - 1].body_pos = new_body_pos;
	board[new_body_pos].tile_isActive = true;
	lajos.ingame_snake_len++;
	hasAteApple = false;
	Game_SpawnFood();
	return;
}

void Game_Refresh_Snake(void) {
	Game_isGameOver();

	uint8_t old_tail_pos = (Game_getLen() == 1)
                       ? Game_getSnakeHeadPos()
                       : Game_getSnakeBodyPos(Game_getLen() - 2);
	if(!isGameOver) 
	{

		// vegigmegyunk a bodyn
		for(int i = Game_getLen() - 2; i >= 0; i--)
		{
			Game_MoveSnakeBody(i);
		}

		// set old head to inactive
		board[Game_getSnakeHeadPos()].tile_isActive = false;

		for(int i = Game_getLen() - 2; i >= 0; i--) 
		{
			board[Game_getSnakeBodyPos(i)].tile_isActive = true;
		}

		// leptetjuk a headet is
		lajos.ingame_snake_head.head_pos = Game_getSnakeHeadNextPos(curDir); 
		board[Game_getSnakeHeadPos()].tile_isActive = true;

		Game_FoodCheck();
		if(hasAteApple) {
			Game_ExtendSnake(old_tail_pos);
		}
	} else 
	{
		Game_GameOverRoutine();
	}
	return;
}

void Game_MoveSnakeBody(uint8_t bodyid) {
	if(0 != bodyid) 
	{
		board[Game_getSnakeBodyPos(bodyid)].tile_isActive = false;
		lajos.ingame_snake_body[bodyid].body_pos = Game_getSnakeBodyPos(bodyid - 1);
	} else 
	{
		board[Game_getSnakeBodyPos(bodyid)].tile_isActive = false;
		lajos.ingame_snake_body[bodyid].body_pos = Game_getSnakeHeadPos();
	}
	return;
}



void Game_Step(uint8_t input)
{
	// curDir is a 4 long enum
	switch(input){
		case 'j':
			curDir = (curDir + 3) % 4; // clockwise turn 
			break;
		case 'b':
			curDir = (curDir + 1) % 4; // counterclockwise turn
			break;
		default:
			curDir = curDir; // dont change direction
			break;
	}
	return;
}

void Game_GameOverRoutine(void)
{
	//TODO
	return;
}
