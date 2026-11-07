#pragma once

#include "chunk.h"

#include <SFML/Graphics.hpp>

#include <map>

class Game; // Forward declaration

class World
{

public:

    World(Game* owner): game(owner) {};

    void setOrigin(sf::Vector2f origin);

    void updateChunks();

    void renderChunks(sf::RenderWindow& window, const sf::Vector2f reference);

    Chunk& access_chunk_at(int row, int column);

private:

    // Player position in chunkspace (if player pos is [1500, 1500] and chunksize is 1000, the origin will be [1, 1])
    int origin_x {};
    int origin_y {};

    // Corners of a quad of the area to load
    int load_ax {};
    int load_ay {};
    int load_bx {};
    int load_by {};

    // Radius around the player in which chunks are loaded
    int load_dist = 2;

    std::map<int, std::map<int, Chunk>> chunk_data;

    // World should know about the Game object (for enemy spawning, etc.)
    Game* game {};

};

