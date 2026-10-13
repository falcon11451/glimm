#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "game.h"
#include "console.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define IF_PRESS(VK) ((GetAsyncKeyState(VK))&1)

int main(int argc, char *argv[]) 
{
	Console console;
	Game game;
	
	initConsole(&console);
	initGame(&game);
	
	printf("Press q to exit, press s to start\n");
	while (!IF_PRESS(0x53)) 
	{
		if (IF_PRESS(0x51)) 
		{
			closeConsole(&console);
			return 0;
		}
	}
	
	clearBoard(&console);
	
	while (1)
	{
		printBoard(&console, game.cells);
		freshPos(&console, &game);
		
		while (1)
		{
			if (IF_PRESS(0x51)) 
			{
				interrupt(&console);
				closeConsole(&console);
				return 0;
			}
			
			if (IF_PRESS(VK_SPACE)) 
			{
				if (!judgeIfValidCell(game.cells, game.x, game.y)) continue;
				put(game.cells, game.x, game.y, game.current_player);
				game.move_count++;
				clearBoard(&console);
				printBoard(&console, game.cells);
				freshPos(&console, &game);
				if (judgeIfWin(game.cells)) goto A;
				if (game.move_count >= BOARD_SIZE*BOARD_SIZE) goto B;
				changePlayer(&game.current_player);
			}
			
			if (IF_PRESS(0x41)) 
			{
				moveGameCursor(&game, game.x-1, game.y);
				moveConsoleCursor(&console, &(console.pos), translateGameCursorPosX(game.x), translateGameCursorPosY(game.y));
			}
			if (IF_PRESS(0x57)) 
			{
				moveGameCursor(&game, game.x, game.y-1);
				moveConsoleCursor(&console, &(console.pos), translateGameCursorPosX(game.x), translateGameCursorPosY(game.y));
			}
			if (IF_PRESS(0x44)) 
			{
				moveGameCursor(&game, game.x+1, game.y);
				moveConsoleCursor(&console, &(console.pos), translateGameCursorPosX(game.x), translateGameCursorPosY(game.y));
			}
			if (IF_PRESS(0x53)) 
			{
				moveGameCursor(&game, game.x, game.y+1);
				moveConsoleCursor(&console, &(console.pos), translateGameCursorPosX(game.x), translateGameCursorPosY(game.y));
			}
		}
	}
A:
	printWinner(&console, game.current_player);
	while (!IF_PRESS(0x51)) ;
	return 0;
B:
	printDraw(&console);
	while (!IF_PRESS(0x51)) ;
	return 0;
}
