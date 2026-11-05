#include "noise.h"
#include <math.h>

float gradient(int Hash, float x, float y)
{
    int h = Hash & 7; // Only look at first 3 bits (---- -XXX)

    // Check first bit (--- -X00)
    float u = (h < 4) ? x : y;
    float v = (h < 4) ? y : x;

    //  u if h & 1 == 0 else -u + v if h & 2 == 0 else -v
    return (((h & 1) == 0) ? u : -u) + (((h & 2) == 0) ? v : -v);
}

float noise(float x, float y)
{

    int X = floor(x); // Get integer coordinates (find grid coordinates on an integer grid)
    int Y = floor(y);

    x -= float(X); // Relative coords to the grid
    y -= float(Y);


    X = X & 255; // Lock to 0-255
    Y = Y & 255;

    float u = quintic(x); // Smooth the values out
    float v = quintic(y);

    int aa, ab, ba, bb;

    // Determine point hashes
    aa = p[(p[X] + Y) & 255];
    ab = p[(p[X] + Y + 1) & 255];
    ba = p[(p[(X + 1) & 255] + Y) & 255];
    bb = p[(p[(X + 1) & 255] + Y + 1) & 255];

    // Get final noise value at this point by interpolating x and y
    return sigmoid(lerp(
        v,
        lerp(u, gradient(aa, x, y), gradient(ba, x - 1, y)),
        lerp(u, gradient(ab, x, y - 1), gradient(bb, x - 1, y - 1))
    ));
}

// def noise(x: float, y: float):
//     X = floor(x)
//     Y = floor(y)

//     x -= X  # Relative coords to the grid
//     y -= Y

//     X = X & 255  # Lock to 0-255
//     Y = Y & 255

//     u, v = fade(x), fade(y)

//     aa = p[(p[X] + Y) & 255]
//     ab = p[(p[X] + Y + 1) & 255]
//     ba = p[(p[(X + 1) & 255] + Y) & 255]
//     bb = p[(p[(X + 1) & 255] + Y + 1) & 255]

//     return lerp(
//         v,
//         lerp(u, grad(aa, x, y), grad(ba, x - 1, y)),
//         lerp(u, grad(ab, x, y - 1), grad(bb, x - 1, y - 1))
//     )