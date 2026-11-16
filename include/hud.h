#pragma once
#include <SFML/Graphics.hpp>
#include "../include/healthbar.h"
#include "renderer.h"

class HUD {

    public:
        HUD();
        void update(float health, float maxHealth, int ammo, int maxAmmo);
        void render(Renderer &window);
    private:
        HealthBar healthBar;
        sf::Texture bullets{"assets/art/hud/bullets.png"};
        sf::Sprite bulletsIcon{bullets};
        sf::Font Oswald{"assets/fonts/Oswald/Oswald-Medium.ttf"};
        sf::Text hpStr{Oswald, "-- / --", 50};
        sf::Text ammoStr{Oswald, "-- / --", 50};

};