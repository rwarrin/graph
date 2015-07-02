CC = clang
CFLAGS = -std=c11 -g -ggdb -Wall -Werror -Wextra -pedantic -O0 -I$(INC_DIR)

INC_DIR = ./include/
SRC_DIR = ./src/
OBJ_DIR = ./obj/
BIN_DIR = ./bin/

APP_NAME = app

all: graph.o main.o APP_NAME

APP_NAME:
	$(CC) $(CFLAGS) $(OBJ_DIR)*.o -o $(BIN_DIR)$@

main.o: $(SRC_DIR)main.c
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)$@

graph.o: $(SRC_DIR)graph.c $(INC_DIR)graph.h
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)$@

clean:
	rm -rf bin/$(APP_NAME) *.exe *.o *.out


