#include "world.h"


Chunk& World::access_chunk_at(int row, int column)
{
    return chunk_data[row][column].initialize(row, column);
}

void World::updateOrigin(sf::Vector2f)
{
    
}