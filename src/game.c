

#include <windows.h>
#include "gameLogic.h"

int main(int argc, char **argv) {
    board gameBoard;
    char *fileName = NULL;
    int iterations = 0, i;

    if (argc != 3) {
        fprintf(stderr, "ERROR: Wrong number of arguments passed to main()\n");
        exit(EXIT_FAILURE);
    }

    fileName = argv[1];
    iterations = atoi(argv[2]);

    createBoard(&gameBoard);
    initWithLifFile(&gameBoard, fileName);

    for (i = 0; i < iterations; i++) {
        updateBoard(&gameBoard);
        system("cls");
        printBoard(&gameBoard);
    }

    destroyBoard(&gameBoard);
    
    return 0;
}
