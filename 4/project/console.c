#include <stdio.h>
#include <windows.h>
#include "game.h"
#include "console.h"

void initConsole(Console *console)
{
	system("title Chess");
	system("mode con cols=60 lines=30");
	console->hIn = GetStdHandle(STD_INPUT_HANDLE);
	console->hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//console->cursorInfo = {0};
	GetConsoleCursorInfo(console->hOut, &(console->cursorInfo));
	console->cursorInfo.dwSize = 100;
	SetConsoleCursorInfo(console->hOut, &(console->cursorInfo));
	console->pos.X = 1;
	console->pos.Y = 1;
	DWORD mode;
	GetConsoleMode(console->hIn, &mode);
	mode &= ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT | ENABLE_PROCESSED_INPUT
        | ENABLE_QUICK_EDIT_MODE | ENABLE_INSERT_MODE);
	mode |= ENABLE_EXTENDED_FLAGS;   // ¹Ø±Õ QuickEdit 
	
	SetConsoleMode(console->hIn, mode);
}

void closeConsole(Console *console)
{
	CloseHandle(console->hIn);
	CloseHandle(console->hOut);
}

int translateGameCursorPosX(int x)
{
	return 2*x+1;
}

int translateGameCursorPosY(int y)
{
	return 2*y+1;
}

void moveConsoleCursor(Console *console, COORD *cursorPos, int x, int y)
{
	cursorPos->X = x;
	cursorPos->Y = y;
	SetConsoleCursorPosition(console->hOut, *cursorPos);
}

void printBoard(Console *console, char cells[BOARD_SIZE][BOARD_SIZE])
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
			printf("__");
		printf("_\n");
		for (int j = 0; j < BOARD_SIZE; j++)
			printf("|%c", cells[j][i]);
		printf("|\n");
	}
	for (int j = 0; j < BOARD_SIZE; j++)
			printf("__");
	printf("_\n");
	printf("Press wasd to move, press space to put, press q to quit\n");
}

void clearBoard(Console *console)
{
	system("cls");
}

void printWinner(Console *console, char winner)
{
	moveConsoleCursor(console, &console->pos, 0, 20);
	printf("Player %c is winner, yes!\n", winner);
}

void printDraw(Console *console)
{
	moveConsoleCursor(console, &console->pos, 0, 20);
	printf("No winner, yes!\n");
}

void interrupt(Console *console)
{
	moveConsoleCursor(console, &console->pos, 0, 20);
	printf("Game has been interrupted.\n");
}

void freshPos(Console *console, Game *game)
{
	moveConsoleCursor(console, &console->pos, translateGameCursorPosX(game->x), translateGameCursorPosY(game->y));
}

void debuger(Console *console, Game *game, char cells[BOARD_SIZE][BOARD_SIZE])
{
	moveConsoleCursor(console, &console->pos, 0, 35);
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
			printf("%d ", cells[j][i]);
		printf("\n");
	}
	printf("%d %d\n", game->x, game->y);
}
