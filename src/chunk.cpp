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

    corner_upper_left_x = u * Constants::CHUNK_SIZE;
    corner_upper_left_y = v * Constants::CHUNK_SIZE;

    corner_lower_right_x = (u + 1) * Constants::CHUNK_SIZE;
    corner_lower_right_y = (v + 1) * Constants::CHUNK_SIZE;

    initialized = true;

    return *this;
}