

#include "board.h"

void openLifFile(char *fileName, FILE **file) {
    if ((*file = fopen(fileName, "r")) == NULL) {
        fprintf(stderr, "ERROR: cannot open file %s\n", fileName);
        exit(EXIT_FAILURE);
    }
}

void createBoard(board *gameBoard) {
    gameBoard->currentState = (char *)malloc(WIDTH * HEIGHT * sizeof(char));
    gameBoard->prevState = (char *)malloc(WIDTH * HEIGHT * sizeof(char));

    if (gameBoard->currentState == NULL || gameBoard->prevState == NULL) {
        fprintf(stderr, "ERROR: memory allocation error\n");
        exit(EXIT_FAILURE);
    }
}

void destroyBoard(board *gameBoard) {
    free(gameBoard->currentState);
    free(gameBoard->prevState);
}

void resetCurrentState(board *gameBoard) {
    /*int i;

    for (i = 0; i < WIDTH * HEIGHT; i++) {
        gameBoard->currentState[i] = NO_LIFE;
    }*/

    memset(gameBoard->currentState, NO_LIFE, WIDTH * HEIGHT);
}

void initWithLifFile(board *gameBoard, char *fileName) {
    char name[8];
    char ver[8];
    int x, y, newX, newY;
    FILE *file = NULL;

    resetCurrentState(gameBoard);
    openLifFile(fileName, &file);

    if(fscanf(file, "%s %s", name, ver) != 2) {
        fprintf(stderr, "ERROR: not a Life 1.06 file\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%d %d", &x, &y) != EOF) {
        newX = wrapCoord(x, WIDTH);
        newY = wrapCoord(y, HEIGHT);
        gameBoard->currentState[newY * WIDTH + newX] = LIFE;
    }

    fclose(file);
}

void printBoard(board *gameBoard) {
    int i;

    for (i = 0; i < WIDTH * HEIGHT; i++) {
        printf("%c ", gameBoard->currentState[i]);

        if ((i + 1) % WIDTH == 0) {
            printf("\n");
        }
    }

    printf("\n");
}

/*int wrapCoord(int val, int max) {
    if (val < 0) {
        return (max + val) % max;
    }

    return val % max;
}*/

int wrapCoord(int val, int max) {
    /*if (val < 0) {
        return (max + val) % max;
    }

    return val % max;*/

    return val < 0 ? ((max + val) % max) : (val % max);
}

