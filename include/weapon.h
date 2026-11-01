#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Weapon
{

public:

    // ------------------------

    std::string name;

    int damage;
    float range;

    // ------------------------

    Weapon();

    Weapon(std::string name, int dmg, float Range);

    // ------------------------
    void fire(sf::Vector2f playerPos, sf::Vector2f mousePos);
    sf::RectangleShape beam;
private:
    

};



