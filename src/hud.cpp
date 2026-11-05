#include "../include/hud.h"
#include "../include/constants.h"

//Default Constructor
HUD::HUD() {
    healthBar.setIsHud(true);
    healthBar.setOutline(sf::Color::Black, 10);
    healthBar.setSize(350, 40);
    hpStr.setFont(Oswald);
    hpStr.setOrigin({hpStr.getLocalBounds().getCenter()});
    hpStr.setPosition(Constants::HP_TEXT_POS);
    ammoStr.setFont(Oswald);
    ammoStr.setOrigin({hpStr.getLocalBounds().getCenter()});
    ammoStr.setPosition(Constants::AMMO_TEXT_POS);
    bulletsIcon.setScale({0.1, 0.1});
    bulletsIcon.setPosition(Constants::AMMO_ICON_POS);

}
void HUD::update(float health, float maxHealth, int ammo, int maxAmmo) {
    healthBar.update(health, {130, 900});

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
    window.draw(bulletsIcon);

}