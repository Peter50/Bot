CC=gcc
LDFLAGS= -g -lm
CFLAGS=-Wextra -g -Wall -pedantic -ansi -std=c99 -I inc

all: main test


obj/pile.o: src/pile.c
obj/file.o: src/file.c
obj/acceleration.o: src/acceleration.c
obj/vitesse.o: src/acceleration.c src/vitesse.c
obj/position.o: src/acceleration.c src/vitesse.c src/position.c
obj/voiture.o: src/acceleration.c src/vitesse.c src/position.c src/voiture.c
obj/map.o: src/acceleration.c src/vitesse.c src/position.c src/voiture.c src/map.c src/pile.c
obj/main.o: src/main.c
obj/test.o: src/test.c

obj/%.o: src/%.c
	$(CC) -c $< -o $@ $(CFLAGS)
main: obj/file.o obj/pile.o obj/acceleration.o obj/vitesse.o obj/position.o obj/voiture.o obj/map.o obj/main.o
	$(CC) $^ -o $@ $(LDFLAGS)
test: obj/file.o obj/pile.o obj/acceleration.o obj/vitesse.o obj/position.o obj/voiture.o obj/map.o obj/test.o
	$(CC) $^ -o $@ $(LDFLAGS)

clean:
	-rm obj/*o
distclean:
	-rm main

