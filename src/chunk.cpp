#include "chunk.h"

#include "constants.h"
#include "noise.h"

#include "../include/game.h"

Chunk::Chunk(int U, int V, Game* owner)
{
    initialize(U, V, owner);
}

Chunk& Chunk::initialize(int U, int V, Game* owner)
{
    if (initialized) return *this;

    game = owner;

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

    // Generate a pseudo random integer from the noise
    sf::Vector2i key = Twist2(u, v);

    // In one tenth of the chunks
    if (key.x % 10 == 0)
    {
        game->spawnEnemies(key.y % 10 + 1, corner_upper_left, corner_lower_right);
    }

}

sf::Vector2i Chunk::Twist2(int U, int V){

    constexpr int x {469832}, y {3874}, z {982392}, w {12232334};

    constexpr int p {57839}, q {26483};

    constexpr int a {285989}, b {198375};

    constexpr int H {0xffff};

    return {
            ((U * V * y) % x + p) * a % H
        ,
            (((V + U) * w) % z + q) * b % H
    };
}