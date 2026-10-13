#include <stdio.h>
#include "game.h"

void initGame(Game *game)
{
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
			game->cells[i][j] = EMPTY_CELL;
	game->current_player = 'X';
	game->x = 0;
	game->y = 0;
	game->move_count = 0;
}

void moveGameCursor(Game *game, int x, int y)
{
	if (x >= BOARD_SIZE || x < 0 || y >= BOARD_SIZE || y < 0) return;
	game->x = x;
	game->y = y;
}

static int judgeRow(char cells[BOARD_SIZE][BOARD_SIZE], int x, int y)
{
	if (x+WIN_LENGTH-1 >= BOARD_SIZE || cells[x][y] == EMPTY_CELL) return 0;
	char player = cells[x][y];
	for (int i = 1; i < WIN_LENGTH; i++)
		if (cells[x+i][y] != player) return 0;
	return 1;
}
static int judgeCol(char cells[BOARD_SIZE][BOARD_SIZE], int x, int y)
{
	if (y+WIN_LENGTH-1 >= BOARD_SIZE || cells[x][y] == EMPTY_CELL) return 0;
	char player = cells[x][y];
	for (int i = 1; i < WIN_LENGTH; i++)
		if (cells[x][y+i] != player) return 0;
	return 1;
	
}
static int judgeDiag(char cells[BOARD_SIZE][BOARD_SIZE], int x, int y)
{
	if (x+WIN_LENGTH-1 >= BOARD_SIZE || y+WIN_LENGTH-1 >= BOARD_SIZE || cells[x][y] == EMPTY_CELL) return 0;
	char player = cells[x][y];
	for (int i = 1; i < WIN_LENGTH; i++)
		if (cells[x+i][y+i] != player) return 0;
	return 1;
}
static int judgeDiag1(char cells[BOARD_SIZE][BOARD_SIZE], int x, int y)
{
	if (x+WIN_LENGTH-1 >= BOARD_SIZE || y-WIN_LENGTH+1 < 0 || cells[x][y] == EMPTY_CELL) return 0;
	char player = cells[x][y];
	for (int i = 1; i < WIN_LENGTH; i++)
		if (cells[x+i][y-i] != player) return 0;
	return 1;
}

int judgeIfWin(char cells[BOARD_SIZE][BOARD_SIZE])
{
	for (int x = 0; x < BOARD_SIZE; x++)
		for (int y = 0; y < BOARD_SIZE; y++)
			if (judgeRow(cells, x, y) || judgeCol(cells, x, y) || judgeDiag(cells, x, y) || judgeDiag1(cells, x, y)) return 1;
	return 0;
}

int judgeIfValidCell(char cells[BOARD_SIZE][BOARD_SIZE], int x, int y)
{
	if (x >= BOARD_SIZE || x < 0 || y >= BOARD_SIZE || y < 0 || cells[x][y] != EMPTY_CELL) return 0;
	return 1;
}

void put(char cells[BOARD_SIZE][BOARD_SIZE], int x, int y, char current_player)
{
	cells[x][y] = current_player;
}

void changePlayer(char *current_player)
{
	if (*current_player == 'X') *current_player = 'O';
	else *current_player = 'X';
}

