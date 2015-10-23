

#include "gameLogic.h"

void updateBoard(board *gameBoard) {
    int i, j;

    memcpy(gameBoard->prevState, gameBoard->currentState, WIDTH * HEIGHT * sizeof(char));

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            updateCell(gameBoard, j, i);
        }
    }
}

void updateCell(board *gameBoard, int x, int y) {
    int idx = y * WIDTH + x;
    int n = getNumNeighbors(gameBoard->prevState, x, y);
    
    if ((n == 2 || n == 3) && gameBoard->prevState[idx] == LIFE) {
        gameBoard->currentState[idx] = LIFE;
        return;
    }

    if (n == 3 && gameBoard->prevState[idx] == NO_LIFE) {
        gameBoard->currentState[idx] = LIFE;
        return;
    }

    gameBoard->currentState[idx] = NO_LIFE;
}

int getNumNeighbors(char *boardState, int x, int y) {
    int i, j, newX, newY, cnt = 0;

    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (!(i == 0 && j == 0)) {
                newX = wrapCoord(x + i, WIDTH);
                newY = wrapCoord(y + j, HEIGHT);

                if (boardState[newY * WIDTH + newX] == LIFE) {
                    cnt++;
                }
            }
        }
    }

    return cnt;
}

