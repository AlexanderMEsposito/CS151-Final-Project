#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>

#include "bullet.h"
#include "timer.h"

#include "weaponData.h"

class Weapon
{

public:
    // Basic Variables
    // ------------------------

    std::string name {"Weapon"};

    //sf::RectangleShape beam;

    // ------------------------
    // Constructors
    Weapon();
    Weapon(int type);

    // ------------------------
    // Functions
    void updateMag(float dt, sf::RectangleShape& reloadBar);

    bool fire(sf::Vector2f playerPos, sf::Vector2f mousePos);

    void update(bool left_click, sf::Vector2f playerPos, sf::Vector2f mousePos);

    void render(Renderer& window, sf::RectangleShape& reloadBar);

    std::vector<Bullet>& getBullets();
    const std::vector<Bullet>& getBullets() const;

    WeaponData data;
    
    Timer fire_timer {data.duration};
    Timer cooldownTimer {data.cooldown};

    int getAmmo() const;
    void reload();
    
    bool firing;
    bool ready; 

private:
    //per bullet

    Timer reloadTimer {data.reload_time};

    bool isReload = false;
    int ammo;
    std::vector<Bullet> bullets;

    sf::SoundBuffer gunFire2B{"assets/sfx/heavy-gun-fire2.mp3"};
    sf::Sound gunFire2{gunFire2B};

};



