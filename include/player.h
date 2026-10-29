#pragma once
#include <SFML/Graphics.hpp>

class Player {
    public:
        Player();
        void setRadius(float r);
        void accel(sf::Vector2f a);
        void setVel(sf::Vector2f vel);
        void update();

        //Getter
        sf::Vector2f getVel();
        sf::CircleShape playerShape;
    private:
        //Vectors
        sf::Vector2f vel;
        sf::Vector2f pos = {};

        //Double
        float playerHealth;
};