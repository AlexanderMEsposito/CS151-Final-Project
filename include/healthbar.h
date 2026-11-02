#pragma once
#include <SFML/Graphics.hpp>

class HealthBar {
    public:
        void setSize(float width, float height);
        HealthBar();
        void update(float hp);
    private:
        int outlinepx;
        sf::Color fillColor;
        sf::Color borderColor;
        sf::Vector2f size;
        sf::RectangleShape border;
        sf::RectangleShape fill;

};