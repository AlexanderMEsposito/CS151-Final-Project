CC = g++
FLAGS = -std=c++17 -Wall -I$(SFML_DIR)/include -Isrc
LDFLAGS = -L$(SFML_DIR)/lib
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system lsfml-audio

game: main.o
	$(CC) $^ -o $@ $(LDFLAGS) $(LDLIBS)