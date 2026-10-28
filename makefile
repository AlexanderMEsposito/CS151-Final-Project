include config.mk

CC = g++
FLAGS = -std=c++17 -Wall -I$(SFML_DIR)/include -Isrc
LDFLAGS = -L$(SFML_DIR)/lib
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

game: main.o player.o
	$(CC) $^ -o $@ $(LDFLAGS) $(LDLIBS)

main.o: src/main.cpp
	$(CC) $(FLAGS) -c $< -o $@

player.o: src/player.cpp include/player.h
	$(CC) $(FLAGS) -c $< -o $@

run: game
	.\game.exe