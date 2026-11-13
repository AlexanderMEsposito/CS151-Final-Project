#pragma once

#include <SFML/Graphics.hpp>

class Object
{

public:

    Object(sf::Vector2f spawnpoint);

    void update();
    void render(sf::RenderWindow& window);

private:

    sf::Vector2f pos;
    sf::Vector2f vel;

    sf::RectangleShape shape;

    static sf::Texture temp_texture {""};

};

