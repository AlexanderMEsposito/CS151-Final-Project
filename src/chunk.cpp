#include "chunk.h"

#include "constants.h"

Chunk::Chunk(int U, int V)
{
    initialize(U, V);
}

Chunk& Chunk::initialize(int U, int V)
{
    if (initialized) return *this;

    u = U;
    v = V;

    corner_upper_left.x = u * Constants::CHUNK_SIZE;
    corner_upper_left.y = v * Constants::CHUNK_SIZE;

    corner_lower_right.x = (u + 1) * Constants::CHUNK_SIZE;
    corner_lower_right.y = (v + 1) * Constants::CHUNK_SIZE;

    initialized = true;

    temp_display.setSize({Constants::CHUNK_SIZE, Constants::CHUNK_SIZE});
    temp_display.setFillColor({25, 75 + 1 * ((u + v) % 2), 25});

    return *this;
}

void Chunk::render(sf::RenderWindow& window, const sf::Vector2f& reference)
{
    temp_display.setPosition(corner_upper_left - reference);

    window.draw(temp_display);
}