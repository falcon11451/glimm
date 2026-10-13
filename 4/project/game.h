#ifndef GAME_H
#define GAME_H 

#ifdef __cplusplus
extern "C"{
#endif

#define BOARD_SIZE 9
#define WIN_LENGTH 5
#define EMPTY_CELL ' '

typedef struct {
    char cells[BOARD_SIZE][BOARD_SIZE]; // 棋盘信息
    char current_player;
    int move_count; // 步数统计
    int x, y;
    //GameStatus status;
} Game;

void initGame(Game *game);
void moveGameCursor(Game *game, int x, int y);
static int judgeRow(char cells[BOARD_SIZE][BOARD_SIZE], int x, int y);
static int judgeCol(char cells[BOARD_SIZE][BOARD_SIZE], int x, int y);
static int judgeDiag(char cells[BOARD_SIZE][BOARD_SIZE], int x, int y);
static int judgeDiag1(char cells[BOARD_SIZE][BOARD_SIZE], int x, int y);
int judgeIfWin(char cells[BOARD_SIZE][BOARD_SIZE]);
int judgeIfValidCell(char cells[BOARD_SIZE][BOARD_SIZE], int x, int y);
void put(char cells[BOARD_SIZE][BOARD_SIZE], int x, int y, char current_player);
void changePlayer(char *current_player);

#ifdef __cplusplus
}
#endif

#endif
