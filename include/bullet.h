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
#include "../include/renderer.h"

class Bullet {
public:
    Bullet(sf::Vector2f position, sf::Vector2f velocity);

    void update(float deltaTime);
    
    void render(Renderer& window);
    sf::Vector2f getPosition() const;

    bool colliding(const sf::Vector2f& target_pos, float target_radius);
    
    float getRadius() const;

private:
    sf::CircleShape shape;
    sf::Vector2f pos;
    sf::Vector2f previousPosition;
    sf::Vector2f velocity;
};

