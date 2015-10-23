

CC = clang
CFLAGS = -Wall -Wextra -pedantic -Wfloat-equal -std=c90
LIBS = -lm
SRC_PATH = src/
INCLUDE_PATH = -I/GitHub/GameOfLife_C/include
SOURCE = $(SRC_PATH)game.c $(SRC_PATH)gameLogic.c $(SRC_PATH)board.c
EXECUTABLE = bin\game.exe

LIF_FILE = lif\GooseGun.lif
ITER = 250

build: $(SOURCE)
	$(CC) $(SOURCE) -o $(EXECUTABLE) $(CFLAGS) $(INCLUDE_PATH) $(LIBS)

run: $(EXECUTABLE)
	.\$(EXECUTABLE) $(LIF_FILE) $(ITER)

clean:
	del .\$(EXECUTABLE)

