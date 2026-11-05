#include "../include/hud.h"

//Default Constructor
HUD::HUD() {
    healthBar.setIsHud(true);
    healthBar.setOutline(sf::Color::Black, 10);
    healthBar.setSize(350, 40);
    hpStr.setFont(Oswald);
    hpStr.setOrigin({hpStr.getLocalBounds().getCenter()});
    hpStr.setPosition({200, 1030});
    ammoStr.setFont(Oswald);
    ammoStr.setOrigin({hpStr.getLocalBounds().getCenter()});
    ammoStr.setPosition({1800, 1030});

}
void HUD::update(float health, float maxHealth, int ammo, int maxAmmo) {
    healthBar.update(health, {200, 900});

    std::string temp;
    temp = std::to_string(static_cast<int>(health));
    temp += " / ";
    temp += std::to_string(static_cast<int>(maxHealth));
    hpStr.setString(temp);

    temp = std::to_string(ammo);
    temp += " / ";
    temp += std::to_string(maxAmmo);
    ammoStr.setString(temp);
}
void HUD::render(sf::RenderWindow &window) {
    healthBar.render(window);
    window.draw(hpStr);
    window.draw(ammoStr);

}