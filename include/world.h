#pragma once

#include "chunk.h"

#include <SFML/Graphics.hpp>

#include <map>

class World
{

public:

    World() {};

    void updateOrigin(sf::Vector2f origin);

    Chunk& access_chunk_at(int row, int column);

private:

    int load_dist = 2;

    std::map<int, std::map<int, Chunk>> chunk_data;

};

