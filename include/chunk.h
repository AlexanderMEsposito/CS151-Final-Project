#pragma once

#include <SFML/Graphics.hpp>

class Chunk
{

public:

    Chunk() {};
    Chunk(int u, int v);

    Chunk& initialize(int u, int v);

    void render(sf::RenderWindow& window, const sf::Vector2f& reference);

private:

    int u {0}, v {0};

    bool initialized {false};

    sf::Vector2f corner_upper_left {0.0f, 0.0f};
    sf::Vector2f corner_lower_right {0.0f, 0.0f};

    sf::RectangleShape temp_display;

};



