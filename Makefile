CC=gcc
LDFLAGS= -g -lm
CFLAGS=-Wextra -g -Wall -pedantic -ansi -std=c99 -I inc

all: main

obj/main.o: src/main.c

obj/%.o: src/%.c
	$(CC) -c $< -o $@ $(CFLAGS)
main: obj/main.o
	$(CC) $^ -o $@ $(LDFLAGS)

clean:
	-rm obj/*o
distclean:
	-rm main

