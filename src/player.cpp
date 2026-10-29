/**
 * @file player.cpp
 * @author The Cool Guys
 * @brief Defines Player class definitions, constructors, etc
 * @version 0.1
 * @date 2026-10-28
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include "../include/player.h"
#include "../include/constants.h"

Player::Player() {
    setRadius(15);
    playerShape.setFillColor(sf::Color::Blue);
    vel = {0, 0};
    playerShape.setPosition({(Constants::WINDOW_WIDTH)/2, (Constants::WINDOW_HEIGHT)/2});
}
void Player::setRadius(float r) {
    playerShape.setRadius(r);
    playerShape.setOrigin({r, r});
}