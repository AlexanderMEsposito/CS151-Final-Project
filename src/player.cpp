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
#include "../include/healthbar.h"
#include "../include/constants.h"
#include <cmath>
using std::abs;

Player::Player() {
    playerHealth = 100;
    setRadius(30);
    playerShape.setFillColor(sf::Color::Blue);
    vel = {0, 0};
    playerShape.setPosition({(Constants::WINDOW_WIDTH)/2, (Constants::WINDOW_HEIGHT)/2});

    //RELOAD BAR
    //100 good width for max
    reloadBar.setSize(Constants::DEFAULT_RELOAD_SIZE);
    reloadBarOffset = {-1 * (reloadBar.getSize().x / 2.f), Constants::RELOAD_BAR_Y_MARGIN};
    
    reloadBar.setFillColor(sf::Color::White);
    reloadBar.setOrigin({0, reloadBar.getSize().y / 2});
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

    pos += vel * dt;

    playerShape.setPosition({(Constants::WINDOW_WIDTH)/2 + vel.x / 10, (Constants::WINDOW_HEIGHT)/2 + vel.y / 10});
    //updates mag and reloadBar
    weapon.updateMag(dt, reloadBar);
    //update reloadBar position after updated length
    reloadBar.setPosition(playerShape.getPosition() + reloadBarOffset);
}
void Player::handleInput(const sf::Vector2f &mousePos, float &dt) {
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
        //player.animate(reload)
        weapon.reload();
    }
    weapon.update(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left), *this, mousePos);
}
void Player::friction(float dt)
{
    if (vel.length() <= (dt * Constants::FRICTION))
    {
        vel = {0, 0};
    } else
    {
        vel -= (vel.normalized() * (dt * Constants::FRICTION));
    }
}

/**
 * @brief Accel takes a of a given frame and checks if adding that acceleration to current velocity would surpass MAX_SPEED; then it will sum it!
 * 
 * @param a Acceleration summed over a single game frame (in pixels)
 */
void Player::accel(sf::Vector2f a) {

    // Compute new velocity by adding the acceleration
    sf::Vector2f new_vel = vel + a;

    // Check if velocity is less than max speed
    if (new_vel.lengthSquared() <= Constants::MAX_SPEED_SQ)
    {
        // Velocity is acceptable, just be done with it
        vel = new_vel;
        return;
    }

    // In this case, the acceleration causes the player to accelerate past max speed
    // so we should force vel to keep the same speed it had before
    vel = new_vel.normalized() * vel.length();
}
sf::Vector2f Player::getVel() {
    return vel;
}

const sf::Vector2f& Player::getPos() const
{
    return pos;
}
float Player::getPlayerHealth() const{
    return playerHealth;
}
void Player::render(Renderer& window)
{
    window.draw(playerShape);
    weapon.render(window, reloadBar);
}

void Player::damage(float amount)
{
    playerHealth -= amount;
}