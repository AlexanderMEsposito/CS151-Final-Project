#include "healthbar.h"


HealthBar::HealthBar() {
    size = {100, 20};
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

}
void HealthBar::update(float hp) {
    fill.setSize({size.x, hp});
}
void HealthBar::setSize(float width, float height) {
    size = {width, height};
}