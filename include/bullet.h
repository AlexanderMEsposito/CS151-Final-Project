/**
 * @file bullet.h
 * @author 
 * @brief 
 * 
 * @date 2026-11-05
 * 
 */

#pragma once

#include <SFML/Graphics.hpp>

// Represents a bullet fired by the player.
// Stores the bullet sprite and its movement velocity.
class Bullet {
public:
    Bullet(const sf::Texture& texture, sf::Vector2f velocity,
           sf::Vector2f position, const sf::IntRect& textureRect);

    void update(float deltaTime);
    
    const sf::Sprite& getSprite() const;
    sf::Vector2f getPosition() const;
private:
    sf::Sprite sprite;
    sf::Vector2f velocity;
};

