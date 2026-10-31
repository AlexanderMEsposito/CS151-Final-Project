#pragma once
#include <SFML/Graphics.hpp>
#include "../include/weapon.h"

class Player {
    public:
        Player();
        //Setters
        void setRadius(float r);
        void setVel(sf::Vector2f vel);

        //Updates
        void handleInput(sf::Vector2f &mousePos);
        void accel(sf::Vector2f a);
        void update(float dt);

        void friction(float dt);

        //Getter
        sf::Vector2f getVel();
        const sf::Vector2f& getPos() const;

        sf::CircleShape playerShape;
        Weapon weapon;
    private:
        //Vectors
        sf::Vector2f vel;
        sf::Vector2f pos;
        sf::Vector2f inputDir;
        //Double
        float playerHealth;

        
};