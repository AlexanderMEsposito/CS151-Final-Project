#include "chunk.h"

#include "constants.h"
#include "noise.h"

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

    display.setSize({Constants::CHUNK_SIZE, Constants::CHUNK_SIZE});
    display.setFillColor({25, uint8_t(75 + 1 * ((u + v) % 2)), 25});

    generate();

    initialized = true;

    return *this;
}

void Chunk::render(sf::RenderWindow& window, const sf::Vector2f& reference)
{
    display.setPosition(corner_upper_left - reference);

    window.draw(display);
}

void Chunk::generate()
{
    float val = noise(float(u) / 2, float(v) / 2);

    int green = 155 + int(val * 100);

    display.setFillColor({255, uint8_t(green), 255});
    display.setTexture(&material);

}