#include "game.h"

//todo starter mezo makrok
static bool hasAteApple;
static bool isGameOver; 
static Direction_t curDir;
static snake lajos;

// thank you Gemini
static tile board[TILE_COUNT] = {
    // --- Top horizontal row: A segments (Digits 1..7) ---
    { .tile_id =  0, .tile_isActive = false, .tile_neighbours = {  1, 30,  6, 22 } }, // 1A
    { .tile_id =  1, .tile_isActive = false, .tile_neighbours = {  2, 31,  0, 23 } }, // 2A
    { .tile_id =  2, .tile_isActive = false, .tile_neighbours = {  3, 32,  1, 24 } }, // 3A
    { .tile_id =  3, .tile_isActive = false, .tile_neighbours = {  4, 33,  2, 25 } }, // 4A
    { .tile_id =  4, .tile_isActive = false, .tile_neighbours = {  5, 34,  3, 26 } }, // 5A
    { .tile_id =  5, .tile_isActive = false, .tile_neighbours = {  6, 35,  4, 27 } }, // 6A
    { .tile_id =  6, .tile_isActive = false, .tile_neighbours = {  0, 36,  5, 28 } }, // 7A

    // --- Middle horizontal row: G+M combined (Digits 1..7) ---
    { .tile_id =  7, .tile_isActive = false, .tile_neighbours = {  8, 22, 13, 30 } }, // 1GM (START)
    { .tile_id =  8, .tile_isActive = false, .tile_neighbours = {  9, 23,  7, 31 } }, // 2GM
    { .tile_id =  9, .tile_isActive = false, .tile_neighbours = { 10, 24,  8, 32 } }, // 3GM
    { .tile_id = 10, .tile_isActive = false, .tile_neighbours = { 11, 25,  9, 33 } }, // 4GM
    { .tile_id = 11, .tile_isActive = false, .tile_neighbours = { 12, 26, 10, 34 } }, // 5GM
    { .tile_id = 12, .tile_isActive = false, .tile_neighbours = { 13, 27, 11, 35 } }, // 6GM
    { .tile_id = 13, .tile_isActive = false, .tile_neighbours = {  7, 28, 12, 36 } }, // 7GM

    // --- Bottom horizontal row: D segments (Digits 1..7) ---
    { .tile_id = 14, .tile_isActive = false, .tile_neighbours = { 15, 30, 20, 22 } }, // 1D
    { .tile_id = 15, .tile_isActive = false, .tile_neighbours = { 16, 31, 14, 23 } }, // 2D
    { .tile_id = 16, .tile_isActive = false, .tile_neighbours = { 17, 32, 15, 24 } }, // 3D
    { .tile_id = 17, .tile_isActive = false, .tile_neighbours = { 18, 33, 16, 25 } }, // 4D
    { .tile_id = 18, .tile_isActive = false, .tile_neighbours = { 19, 34, 17, 26 } }, // 5D
    { .tile_id = 19, .tile_isActive = false, .tile_neighbours = { 20, 35, 18, 27 } }, // 6D
    { .tile_id = 20, .tile_isActive = false, .tile_neighbours = { 14, 36, 19, 28 } }, // 7D

    // --- Upper vertical row: 1F..7F and 7B ---
    { .tile_id = 21, .tile_isActive = false, .tile_neighbours = {  7, 29, 13, 29 } }, // 1F
    { .tile_id = 22, .tile_isActive = false, .tile_neighbours = {  8, 30,  7, 30 } }, // 2F
    { .tile_id = 23, .tile_isActive = false, .tile_neighbours = {  9, 31,  8, 31 } }, // 3F
    { .tile_id = 24, .tile_isActive = false, .tile_neighbours = { 10, 32,  9, 32 } }, // 4F
    { .tile_id = 25, .tile_isActive = false, .tile_neighbours = { 11, 33, 10, 33 } }, // 5F
    { .tile_id = 26, .tile_isActive = false, .tile_neighbours = { 12, 34, 11, 34 } }, // 6F
    { .tile_id = 27, .tile_isActive = false, .tile_neighbours = { 13, 35, 12, 35 } }, // 7F
    { .tile_id = 28, .tile_isActive = false, .tile_neighbours = {  7, 36, 13, 36 } }, // 7B

    // --- Lower vertical row: 1E..7E and 7C ---
    { .tile_id = 29, .tile_isActive = false, .tile_neighbours = { 14, 21, 20, 21 } }, // 1E
    { .tile_id = 30, .tile_isActive = false, .tile_neighbours = { 15, 22, 14, 22 } }, // 2E
    { .tile_id = 31, .tile_isActive = false, .tile_neighbours = { 16, 23, 15, 23 } }, // 3E
    { .tile_id = 32, .tile_isActive = false, .tile_neighbours = { 17, 24, 16, 24 } }, // 4E
    { .tile_id = 33, .tile_isActive = false, .tile_neighbours = { 18, 25, 17, 25 } }, // 5E
    { .tile_id = 34, .tile_isActive = false, .tile_neighbours = { 19, 26, 18, 26 } }, // 6E
    { .tile_id = 35, .tile_isActive = false, .tile_neighbours = { 20, 27, 19, 27 } }, // 7E
    { .tile_id = 36, .tile_isActive = false, .tile_neighbours = { 14, 28, 20, 28 } }, // 7C


};static uint8_t foodPos;

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
