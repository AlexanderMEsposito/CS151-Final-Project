include config.mk

CC = g++
FLAGS = -std=c++17 -Wall -I$(SFML_DIR)/include -Iinclude
LDFLAGS = -L$(SFML_DIR)/lib
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

OBJS = main.o game.o menuscreen.o player.o weapon.o enemy.o timer.o world.o chunk.o

game: $(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS) $(LDLIBS)


# OBJECTS

%.o:
	$(CC) $(FLAGS) -c $< -o $@

main.o: src/main.cpp include/game.h include/menuscreen.h include/screen.h include/player.h include/constants.h

game.o: src/game.cpp include/game.h include/menuscreen.h include/screen.h include/player.h

menuscreen.o: src/menuscreen.cpp include/menuscreen.h include/screen.h

player.o: src/player.cpp include/player.h include/constants.h

weapon.o: src/weapon.cpp include/weapon.h

enemy.o: src/enemy.cpp include/enemy.h include/constants.h include/player.h

timer.o: src/timer.cpp include/timer.h

world.o: src/world.cpp include/world.h

chunk.o: src/chunk.cpp include/chunk.h

run: game
	.\game.exe
