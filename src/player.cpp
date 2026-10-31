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
#include <cmath>
using std::abs;

Player::Player() {
    setRadius(15);
    playerShape.setFillColor(sf::Color::Blue);
    vel = {0, 0};
    playerShape.setPosition({(Constants::WINDOW_WIDTH)/2, (Constants::WINDOW_HEIGHT)/2});
}
void Player::setRadius(float r) {
    playerShape.setRadius(r);
    playerShape.setOrigin(playerShape.getGeometricCenter());
}
void Player::setVel(sf::Vector2f v) {
    vel = v;
}
void Player::update(float dt) {

    if (inputDir.x != 0 || inputDir.y != 0) // Only check if there is player input
    {
        inputDir = inputDir.normalized();
        inputDir *= Constants::PLAYER_ACCEL * dt;
    }
    

    accel(inputDir); // Accelerate from the player input
    friction(dt); // Apply friction every update


    if (vel.length() > Constants::MAX_SPEED) {
        vel *= (Constants::MAX_SPEED / vel.length());
    }
    playerShape.setPosition(playerShape.getPosition() + (vel * dt));

}
void Player::handleInput() {
    //reset input dir per tick
    inputDir = {0, 0};
    //Process input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        // Dir Up
        inputDir += {0, -1};
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        // Dir Down
        inputDir += {0, 1};
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        // Dir Left
        inputDir += {-1, 0};
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        // Dir Right
        inputDir += {1, 0};
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        weapon.fire(playerShape.getPosition(), static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
    }
}
void Player::friction(float dt)
{
    if (vel.length() <= (dt * Constants::FRICTION))
    {
        vel = {0, 0};
    } else
    {
        vel = vel/vel.length() * (vel.length() - (dt * Constants::FRICTION));
    }
}

/**
 * @brief Accel takes a of a given frame and checks if adding that acceleration to current velocity would surpass MAX_SPEED; then it will sum it!
 * 
 * @param a Acceleration summed over a single game frame (in pixels)
 */
void Player::accel(sf::Vector2f a) {
    //Handle Max Speed
    //If summed speed is not over one then set vel to sum of accel and vel
    if ((abs((vel.x + a.x)) <= Constants::MAX_SPEED) && abs((vel.y + a.y)) <= Constants::MAX_SPEED) {
        setVel(vel + a);
    //If sum of x magnitude is less than one then you can add the x values, but y is set to MAX_SPEED keeping the sign
    } else if(abs(vel.x + a.x) < Constants::MAX_SPEED) {
        setVel({(vel.x + a.x), ((vel.y) / abs(vel.y))});
        setVel({
            (vel.x + a.x), std::copysign(Constants::MAX_SPEED, vel.y)
        });
    } else if(abs(vel.y + a.y) < Constants::MAX_SPEED) {
        setVel({
            (std::copysign(Constants::MAX_SPEED, vel.x)), (vel.y + a.y)
        });
    }
}
sf::Vector2f Player::getVel() {
    return vel;
}

const sf::Vector2f& Player::getPos() const
{
    return pos;
}