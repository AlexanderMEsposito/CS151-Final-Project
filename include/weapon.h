#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Weapon
{

public:

    // ------------------------

    std::string name {"Weapon"};

    int damage {10};
    float range {500.0f};

    // ------------------------

    Weapon();

    Weapon(std::string name, int dmg, float Range);

    // ------------------------
    void fire(sf::Vector2f playerPos, sf::Vector2f mousePos);

    void update(bool left_click, sf::Vector2f playerPos, sf::Vector2f mousePos);

    void render(sf::RenderWindow& window);

    sf::RectangleShape beam;

    bool firing = false; // If the weapon is currently firing
    bool ready = true; // If the weapon is ready to fire

    sf::Clock fire_timer;

    float fire_duration {.02f};

private:
    

};



