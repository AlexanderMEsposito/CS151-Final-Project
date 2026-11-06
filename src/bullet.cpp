/**
 * @file bullet.cpp
 * @author 
 * @brief 
 * 
 * @date 2026-11-05
 * 
 */

#include "bullet.h"

Bullet::Bullet(const sf::Texture& texture, sf::Vector2f velocity,
               sf::Vector2f position, const sf::IntRect& textureRect)
    : sprite(texture, textureRect), velocity(velocity)
{
    sprite.setPosition(position);
}

void Bullet::update(float deltaTime)
{
    sprite.setPosition(sprite.getPosition() + velocity * deltaTime);
}

const sf::Sprite& Bullet::getSprite() const
{
    return sprite;
}

sf::Vector2f Bullet::getPosition() const
{
    return sprite.getPosition();
}
