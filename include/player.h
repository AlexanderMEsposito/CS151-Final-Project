#pragma once
#include <SFML/Graphics.hpp>

class Player {
    public:
        Player();
        void setRadius(float r);
        void setOrigin(sf::Vector2f);

        sf::CircleShape playerShape;
    private:
        //Vectors
        sf::Vector2f vel;
        sf::Vector2f pos = {};

        //Double
        float playerHealth;
};