#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>

#include "bullet.h"
#include "timer.h"

class Weapon
{

public:
    // Basic Variables
    // ------------------------

    std::string name {"Weapon"};

    int damage {10};
    float range {500.0f};
    //sf::RectangleShape beam;

    // ------------------------
    // Constructors
    Weapon();
    Weapon(std::string name, int dmg, float Range);

    // ------------------------
    // Functions
    void updateMag(float dt, sf::RectangleShape& reloadBar);

    bool fire(sf::Vector2f playerPos, sf::Vector2f mousePos);

    void update(bool left_click, sf::Vector2f playerPos, sf::Vector2f mousePos);

    void render(sf::RenderWindow& window, sf::RectangleShape& reloadBar);

    std::vector<Bullet>& getBullets();
    const std::vector<Bullet>& getBullets() const;


    bool firing = false; // If the weapon is currently firing
    bool ready = true; // If the weapon is ready to fire

    bool automatic = false; // If false, requires the player to release left mouse before the weapon can fire again
    
    Timer fire_timer {.015f};
    Timer cooldownTimer {.05f};

    int getAmmo() const;
    void reload();
    

private:
    //per bullet

    Timer reloadTimer {0.22f};

    bool isReload = false;
    int magSize;
    int ammo;
    std::vector<Bullet> bullets;

    sf::SoundBuffer gunFire2B{"assets/sfx/heavy-gun-fire2.mp3"};
    sf::Sound gunFire2{gunFire2B};

};



