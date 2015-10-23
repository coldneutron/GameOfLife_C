

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADER      "#Life 1.06"
#define WIDTH       50
#define HEIGHT      50
#define LIFE        '+'
#define NO_LIFE     ' '

typedef struct board {
    char *prevState;
    char *currentState;
} board;

void openLifFile(char *fileName, FILE **file);

void createBoard(board *gameBoard);

void destroyBoard(board *gameBoard);

void resetCurrentState(board *gameBoard);

void initWithLifFile(board *gameBoard, char *fileName);

void printBoard(board *gameBoard);

int wrapCoord(int val, int max);

