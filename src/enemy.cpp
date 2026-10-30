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

void Enemy::accelerate(const sf::Vector2f& a, float dt)
{
    vel += a * dt;
}

void Enemy::update(float dt, Player& player)
{

    ai(dt, player);

    friction(dt);

    clampSpeed();

    pos += vel * dt;

    

    temp_shape.setPosition(pos);

}

void Enemy::friction(float dt)
{
    if (vel.length() <= dt * Constants::FRICTION)
    {
        vel = {0, 0};
    }
    else
    {

        sf::Vector2f fricAmt = vel.normalized() * -1.0f; // Get a length 1 vector pointing in opposite direction of vel

        vel -= fricAmt * Constants::FRICTION * dt;
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

void Enemy::ai(float dt, Player& player)
{
    // Calculate direction to move in
    if (pos != player.playerShape.getPosition())

        // Point towards the player
        moveDir = (player.playerShape.getPosition() - pos).normalized();
    
    else
        // Point nowhere
        moveDir = {0, 0};
        

    // Accelerate based on move direction
    accelerate(moveDir, dt * acceleration);
}