#pragma once

#include <SFML/Graphics.hpp>
#include "renderer.h"

class Object
{

public:

    Object(sf::Vector2f spawnpoint);

    void update();
    void render(Renderer& window);

private:

    sf::Vector2f pos;
    sf::Vector2f vel;

    sf::RectangleShape shape;

    sf::Texture temp_texture {"assets/art/objects/tree.png"};

};

