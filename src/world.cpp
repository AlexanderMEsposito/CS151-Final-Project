#include "world.h"
#include "constants.h"

#include "../include/game.h"

Chunk& World::access_chunk_at(int row, int column)
{
    return chunk_data[row][column].initialize(row, column, game);
}

void World::setOrigin(sf::Vector2f origin)
{
    // Get world origin in terms of chunks (row, column)
    origin_x = int(origin.x / Constants::CHUNK_SIZE);
    origin_y = int(origin.y / Constants::CHUNK_SIZE);

    load_ax = origin_x - load_dist;
    load_ay = origin_y - load_dist;

    load_bx = origin_x + load_dist;
    load_by = origin_y + load_dist;

}

void World::updateChunks()
{
    for (int row {load_ax}; row < load_bx; row++)
    {
        for (int column {load_ay}; column < load_by; column++)
        {
            access_chunk_at(row, column);
        }
    }
}

void World::renderChunks(sf::RenderWindow& window, const sf::Vector2f reference)
{   
    for (int row {load_ax}; row <= load_bx; row++)
    {
        for (int column {load_ay}; column <= load_by; column++)
        {
            access_chunk_at(row, column).render(window, reference);
        }
    }
}