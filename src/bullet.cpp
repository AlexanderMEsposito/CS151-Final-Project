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
    pos = position;
    shape.setOrigin(shape.getGeometricCenter());
    shape.setFillColor(sf::Color::Yellow);
}

void Bullet::update(float deltaTime)
{
    // Add velocity
    previousPosition = pos;
    pos += velocity * deltaTime;
}

void Bullet::render(Renderer& window)
{

    // Update shape position
    shape.setPosition(pos + window.screen_center - window.world_reference);

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

bool Bullet::colliding(const sf::Vector2f& target_pos, float target_radius)
{
    // Get two deltas
    sf::Vector2f to_target = target_pos - pos;
    sf::Vector2f direction = (previousPosition - pos).normalized();

    // Use dot product (cosine) to determine the dist the enemy is along the bullet's path
    float dist_colinear = to_target.dot(direction);

    // Check if the colinear distance is actually in the bullet's path
    if (dist_colinear < 0 || dist_colinear * dist_colinear > (previousPosition - pos).lengthSquared()) return false;

    // Compute the closest point along the bullet's path to the enemy
    sf::Vector2f closest_point = pos + direction * dist_colinear;
    
    // Use the closest point and target pos to find the distance the enemy is from the bullet
    float sqdist = (target_pos - closest_point).lengthSquared();

    // Standard circle collision
    return (sqdist < target_radius * target_radius);

}
