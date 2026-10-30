#include "enemy.h"
#include "constants.h"

// Spawn at world origin (0, 0)
Enemy::Enemy()
{
    setRadius(15);
    temp_shape.setFillColor(sf::Color::Green);
}

// Spawn at a specific location
Enemy::Enemy(const sf::Vector2f& spawnpoint): pos(spawnpoint)
{
    setRadius(15);
    temp_shape.setFillColor(sf::Color::Green);
}


void Enemy::setRadius(float r)
{
    temp_shape.setRadius(r);
    temp_shape.setOrigin(temp_shape.getGeometricCenter());
}

void Enemy::accelerate(const sf::Vector2f& a)
{
    vel += a; // Delta time component still needed
}

void Enemy::update(float dt)
{

    temp_shape.setPosition(pos);

}

void Enemy::friction(float dt)
{

    if (vel.x > Constants::FRICTION)
    {
        vel.x -= Constants::FRICTION;
    }
    else if (vel.x < -Constants::FRICTION)
    {
        vel.x += Constants::FRICTION;
    }
    else
    {
        vel.x = 0;
    }

    if (vel.y > Constants::FRICTION)
    {
        vel.y -= Constants::FRICTION;
    }
    else if (vel.y < -Constants::FRICTION)
    {
        vel.y += Constants::FRICTION;
    }
    else
    {
        vel.y = 0;
    }

}

void Enemy::clampSpeed()
{
    // Get ratio of current speed to desired speed
    float rate = vel.lengthSquared() / speed;

    if (rate > 1)
    {
        // Vel should become desired speed
        vel /= rate;

    }
}

void Enemy::draw(sf::RenderWindow& window)
{

    window.draw(temp_shape);

}