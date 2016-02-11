DIR_INC = ./include
DIR_SRC = ./src
DIR_OBJ = ./obj

SRC = $(wildcard ${DIR_SRC}/*.c)
OBJ = $(patsubst %.c, ${DIR_OBJ}/%.o, $(notdir ${SRC}))

TARGET = sims
BIN_TARGET = ${TARGET}

CC = gcc
CFLAGS = -Wall -I${DIR_INC}

${BIN_TARGET}: ${OBJ}
	$(CC) $(OBJ) -o $@

${DIR_OBJ}/%.o: ${DIR_SRC}/%.c
	$(CC) -c $< -o $@ $(CFLAGS) 

.PHONY: clean
clean: 
	find ${DIR_OBJ} -name *.o -exec rm -rf {} \; 
