#include "healthbar.h"


HealthBar::HealthBar() {
    width = 100;
    height = 10;
    size = {width, height};
    offset = {-50, 50};
    outlinepx = 4;
    //Colors
    fillColor = sf::Color::Red;
    borderColor = sf::Color::White;
    border.setFillColor(sf::Color::Transparent);
    border.setOutlineColor(borderColor);
    fill.setFillColor(fillColor);
    //Size and shape

    border.setSize(size);
    border.setOutlineThickness(outlinepx);
    fill.setSize(size);
    fill.setOrigin({0, (size.y)/2});
    border.setOrigin({0, (size.y)/2});

}
void HealthBar::update(float hp, sf::Vector2f playerPos) {
    fill.setSize({size.x * (hp/100), size.y});
    border.setPosition(playerPos + offset);
    fill.setPosition(playerPos + offset);

}
void HealthBar::setSize(float width, float height) {
    size = {width, height};
}
sf::RectangleShape HealthBar::getBorder() const{
    return border;
}
sf::RectangleShape HealthBar::getFill() const{
    return fill;
}