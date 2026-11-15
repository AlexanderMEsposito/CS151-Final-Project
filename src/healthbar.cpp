#include "healthbar.h"
#include <algorithm>


HealthBar::HealthBar() {
    width = 100;
    height = 10;
    size = {width, height};
    offset = {-50, 50};
    outlinepx = 3;
    //Colors
    fillColor = sf::Color::Red;
    borderColor = sf::Color::Black;
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
void HealthBar::update(float ratio, sf::Vector2f entityPos) {
    ratio = std::clamp(ratio, 0.f, 1.f);
    fill.setSize({size.x * ratio, size.y});
    border.setSize({size});
    border.setPosition(entityPos + offset);
    fill.setPosition(entityPos + offset);

}
void HealthBar::render(sf::RenderWindow &window) {
    if (!isHud) {
        if(fill.getSize().x < width) {
            window.draw(fill);
            window.draw(border);
        }
    } else {
        window.draw(fill);
        window.draw(border);
    }


}
void HealthBar::setIsHud(bool b) {
    isHud = b;
}
void HealthBar::setSize(float width, float height) {
    size = {width, height};
}
void HealthBar::setOutline(sf::Color color, float thickness) {
    border.setOutlineColor(color);
    border.setOutlineThickness(thickness);
}
sf::RectangleShape HealthBar::getBorder() const{
    return border;
}
sf::RectangleShape HealthBar::getFill() const{
    return fill;
}