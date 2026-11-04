#pragma once
#include <SFML/Graphics.hpp>

class HealthBar {
    public:
        sf::RectangleShape getBorder() const;
        sf::RectangleShape getFill() const;
        void setSize(float width, float height);
        HealthBar();
        void update(float hp, sf::Vector2f entityPos);
        void render(sf::RenderWindow &window);

    private:
        float width, height;
        int outlinepx;
        sf::Color fillColor;
        sf::Color borderColor;
        sf::Vector2f size;
        sf::Vector2f offset;
        sf::RectangleShape border;
        sf::RectangleShape fill;

};