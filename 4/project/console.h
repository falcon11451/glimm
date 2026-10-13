#ifndef CONSOLE_H
#define CONSOLE_H

#ifdef __cplusplus
extern "C"{
#endif

#include <windows.h>
#include "game.h"

typedef struct{
	HANDLE hIn, hOut;
	CONSOLE_CURSOR_INFO cursorInfo;
	COORD pos;
} Console;

void initConsole(Console *console);
void closeConsole(Console *console);

int translateGameCursorPosX(int x);
int translateGameCursorPosY(int y);

void moveConsoleCursor(Console *console, COORD *cursorPos, int x, int y);

void printBoard(Console *console, char cells[BOARD_SIZE][BOARD_SIZE]);
void clearBoard(Console *console);
void printWinner(Console *console, char winner);
void printDraw(Console *console);
void interrupt(Console *console);
void debuger(Console *console, Game *game, char cells[BOARD_SIZE][BOARD_SIZE]);

void freshPos(Console *console, Game *game);

#ifdef __cplusplus 
}
#endif

#endif
