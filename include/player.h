#pragma once
#include <SFML/Graphics.hpp>

class Player {
    public:
        Player();
        //Setters
        void setRadius(float r);
        void setVel(sf::Vector2f vel);

        //Updates
        void accel(sf::Vector2f a);
        void update();

        void friction();

        //Getter
        sf::Vector2f getVel();
        sf::CircleShape playerShape;
    private:
        //Vectors
        sf::Vector2f vel;
        sf::Vector2f pos;

        //Double
        float playerHealth;
};