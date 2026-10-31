#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Weapon
{

public:
    // Basic Variables
    // ------------------------
    std::string name;
    int damage;
    float range;
    sf::RectangleShape beam;

    // ------------------------
    // Constructors
    Weapon();
    Weapon(std::string name, int dmg, float Range);

    // ------------------------
    // Functions
    void update(float &dt);

    void fire(sf::Vector2f playerPos, sf::Vector2f mousePos);
    int getAmmo();
    void reload();
    

private:
    //per bullet
    int reloadTime;
    float reloadTimer;

    bool isReload;
    int magSize;
    int ammo;

};



