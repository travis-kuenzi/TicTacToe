CFLAGS= -g -Wall
.PHONY: all
all: game 

game.o: game.c 
game: game.o 

.PHONY: clean
clean:
	rm -f game game.o 
