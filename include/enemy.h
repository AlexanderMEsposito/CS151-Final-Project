#pragma once

#include <SFML/Graphics.hpp>

class Enemy 
{

public:

    Enemy();
    Enemy(int hitpoints);

private:

    int health;

    sf::Vector2f pos;
    sf::Vector2f vel;

};

