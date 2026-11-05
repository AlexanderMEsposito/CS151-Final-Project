#pragma once
#include <SFML/Graphics.hpp>

class HealthBar {
    public:
        sf::RectangleShape getBorder() const;
        sf::RectangleShape getFill() const;
        void setSize(float width, float height);
        void setOutline(sf::Color color, float thickness);
        HealthBar();
        void update(float hp, sf::Vector2f entityPos);
        void render(sf::RenderWindow &window);
        void setIsHud(bool b);

    private:
        //Player only
        bool isHud{false};
        sf::Font Oswald{"assets/fonts/Oswald/Oswald-Medium.ttf"};
        sf::Text hpStr{Oswald};
        //All
        float width, height;
        int outlinepx;
        sf::Color fillColor;
        sf::Color borderColor;
        sf::Vector2f size;
        sf::Vector2f offset;
        sf::RectangleShape border;
        sf::RectangleShape fill;

};