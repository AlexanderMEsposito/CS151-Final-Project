include config.mk

CC = g++
FLAGS = -std=c++17 -Wall -I$(SFML_DIR)/include -Iinclude
LDFLAGS = -L$(SFML_DIR)/lib
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

OBJS = main.o game.o menuscreen.o player.o weapon.o enemy.o timer.o healthbar.o

# Header groups: each lists a header plus every header it includes (directly or indirectly)
PLAYER_H = include/player.h include/weapon.h include/timer.h include/healthbar.h
ENEMY_H  = include/enemy.h $(PLAYER_H)
GAME_H   = include/game.h $(ENEMY_H) include/menuscreen.h include/screen.h include/constants.h

game: $(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS) $(LDLIBS)

main.o: src/main.cpp $(GAME_H)
	$(CC) $(FLAGS) -c $< -o $@

game.o: src/game.cpp $(GAME_H)
	$(CC) $(FLAGS) -c $< -o $@

menuscreen.o: src/menuscreen.cpp include/menuscreen.h include/screen.h
	$(CC) $(FLAGS) -c $< -o $@

player.o: src/player.cpp $(PLAYER_H) include/constants.h
	$(CC) $(FLAGS) -c $< -o $@

weapon.o: src/weapon.cpp include/weapon.h include/timer.h include/constants.h
	$(CC) $(FLAGS) -c $< -o $@

enemy.o: src/enemy.cpp $(ENEMY_H) include/constants.h
	$(CC) $(FLAGS) -c $< -o $@

timer.o: src/timer.cpp include/timer.h
	$(CC) $(FLAGS) -c $< -o $@

healthbar.o: src/healthbar.cpp include/healthbar.h
	$(CC) $(FLAGS) -c $< -o $@

run: game
	.\game.exe
