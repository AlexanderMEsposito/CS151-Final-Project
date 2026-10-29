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
    playerShape.setOrigin(playerShape.getGeometricCenter());
}
void Player::setVel(sf::Vector2f v) {
    vel = v;
}
void Player::update() {
    playerShape.setPosition(playerShape.getPosition() + vel);

    friction(); // Apply friction every update
}

void Player::friction()
{
    // Remove friction from velocity
    if (vel.x > Constants::FRICTION) // Should be slowed down
    {
        vel.x -= Constants::FRICTION;
    }
    else if (vel.x < -Constants::FRICTION) // Should be slowed down in negative direction
    {
        vel.x += Constants::FRICTION;
    }
    else // Smaller than friction, should be set to zero
    {
        vel.x = 0;
    }

    // Do the same for y
    if (vel.y > Constants::FRICTION) // Should be slowed down
    {
        vel.y -= Constants::FRICTION;
    }
    else if (vel.y < -Constants::FRICTION) // Should be slowed down in negative direction
    {
        vel.y += Constants::FRICTION;
    }
    else // Smaller than friction, should be set to zero
    {
        vel.y = 0;
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

//sets vel to magnitude 1 keeping direction
//setVel({, });
}
sf::Vector2f Player::getVel() {
    return vel;
}