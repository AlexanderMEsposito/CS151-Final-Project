include config.mk

CC = g++
FLAGS = -std=c++17 -Wall -I$(SFML_DIR)/include -Iinclude
LDFLAGS = -L$(SFML_DIR)/lib
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

OBJS = main.o game.o menuscreen.o player.o weapon.o enemy.o

game: $(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS) $(LDLIBS)

main.o: src/main.cpp include/game.h include/menuscreen.h include/screen.h include/player.h include/constants.h
	$(CC) $(FLAGS) -c $< -o $@

game.o: src/game.cpp include/game.h include/menuscreen.h include/screen.h include/player.h
	$(CC) $(FLAGS) -c $< -o $@

menuscreen.o: src/menuscreen.cpp include/menuscreen.h include/screen.h
	$(CC) $(FLAGS) -c $< -o $@

player.o: src/player.cpp include/player.h include/constants.h
	$(CC) $(FLAGS) -c $< -o $@

weapon.o: src/weapon.cpp include/weapon.h
	$(CC) $(FLAGS) -c $< -o $@

enemy.o: src/enemy.cpp include/enemy.h include/constants.h include/player.h
	$(CC) $(FLAGS) -c $< -o $@

run: game
	.\game.exe
