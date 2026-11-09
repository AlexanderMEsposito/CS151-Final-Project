#include "enemy.h"
#include "constants.h"

// Spawn at world origin (0, 0)
Enemy::Enemy()
{
    setRadius(20);
    temp_shape.setFillColor(sf::Color::Green);
    healthBar.setSize(70, 8);
}

// Spawn at a specific location
Enemy::Enemy(const sf::Vector2f& spawnpoint): pos(spawnpoint)
{
    setRadius(20);
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

    // This should later be calculated once, this line is just temporary
    sf::Vector2f screen_center = {Constants::WINDOW_WIDTH / 2, Constants::WINDOW_HEIGHT / 2};

    temp_shape.setPosition(pos - player.getPos() + screen_center);

    healthBar.update(data.health, temp_shape.getPosition());

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
    float rate = vel.lengthSquared() / data.speed;

    if (rate > 1)
    {
        // Vel should become desired speed
        vel /= rate;

    }
}

void Enemy::render(sf::RenderWindow& window)
{

    window.draw(temp_shape);
    healthBar.render(window);

}

void Enemy::ai(float dt, Player& player)
{
    // Calculate direction to move in
    if (pos != player.getPos())

        // Point towards the player
        moveDir = (player.getPos() - pos).normalized();
    
    else
        // Point nowhere
        moveDir = {0, 0};
        

    // Accelerate based on move direction
    accelerate(moveDir, dt * data.acceleration);
}

/**
 * @brief Returns the square distance between this enemy and the other
 * 
 * @param other 
 * @return float 
 */
float Enemy::sqdist(const Enemy& other)
{
    return (other.pos - pos).lengthSquared();
}

void Enemy::collide(Enemy& other)
{   
    if (sqdist(other) < Constants::COLLISION_RADIUS * Constants::COLLISION_RADIUS)
    {
        // Vector pointing from this enemy to the other enemy
        sf::Vector2f delta = (other.pos - pos).normalized() * (Constants::COLLISION_RADIUS / 2.0f);

        // Push the two enemies apart
        vel -= delta;
        other.vel += delta;
    }
}
bool Enemy::isDead() const{
    if (data.health <= 0) {
        return true;
    } else return false;
}