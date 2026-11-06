#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "timer.h"

class Weapon
{

public:
    // Basic Variables
    // ------------------------

    std::string name {"Weapon"};

    int damage {10};
    float range {500.0f};
    sf::RectangleShape beam;

    // ------------------------
    // Constructors
    Weapon();
    Weapon(std::string name, int dmg, float Range);

    // ------------------------
    // Functions
    void updateMag(float dt, sf::RectangleShape& reloadBar);

    bool fire(sf::Vector2f playerPos, sf::Vector2f mousePos);

    void update(bool left_click, sf::Vector2f playerPos, sf::Vector2f mousePos);

    void render(sf::RenderWindow& window);


    bool firing = false; // If the weapon is currently firing
    bool ready = true; // If the weapon is ready to fire

    Timer fire_timer {.02f};

    int getAmmo() const;
    void reload();
    

private:
    //per bullet
    float reloadTime = 0.22f;
    float reloadTimer = 0.22f;

    bool isReload = false;
    int magSize;
    int ammo;

};



