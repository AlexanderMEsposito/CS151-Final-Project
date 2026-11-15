/**
 * @file bullet.cpp
 * @author 
 * @brief 
 * 
 * @date 2026-11-05
 * 
 */

 
#include "bullet.h"

Bullet::Bullet(sf::Vector2f position, sf::Vector2f velocity)
    : shape(4.f), previousPosition(position), velocity(velocity)
{
    shape.setOrigin(shape.getGeometricCenter());
    shape.setPosition(position);
    shape.setFillColor(sf::Color::Yellow);
}

void Bullet::update(float deltaTime, sf::Vector2f cameraVelocity)
{
    previousPosition = shape.getPosition();
    shape.setPosition(previousPosition + (velocity - cameraVelocity) * deltaTime);
}

void Bullet::render(sf::RenderWindow& window) const
{
    window.draw(shape);
}

sf::Vector2f Bullet::getPosition() const
{
    return shape.getPosition();
}


float Bullet::getRadius() const
{
    return shape.getRadius();
}
