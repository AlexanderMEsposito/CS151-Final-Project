#pragma once
#include <SFML/Graphics.hpp>
#include "player.h"
#include "healthbar.h"

#include "enemyData.h"

class Enemy {
    public:

        // ------------------------
        // Constructors

        Enemy(const sf::Vector2f& spawnpoint);

        // ------------------------
        // Temporary (until draw with texture)
        void setRadius(float r);

        // ------------------------
        // Motion
        void setVel(const sf::Vector2f& v) {vel = v;}

        sf::Vector2f getVel() {return vel;}

        /**
         * @brief Adds the given acceleration to the velocity, scaled by delta time.
         * 
         * @param a Acceleration
         */
        void accelerate(const sf::Vector2f& a, float dt);

        // ------------------------
        // Tick
        
        void update(float dt, Player& player);

        // ------

        void friction(float dt);

        // Forces the enemy's speed to be at or below this->speed
        void clampSpeed();

        // Tracks the player and moves in that direction
        void ai(float dt, Player& player);

        // ------------------------
        // Rendering

        sf::CircleShape& getShape() {return temp_shape;}

        void render(sf::RenderWindow& window);

        void collide(Enemy& other);
        void collidePlayer(Player& player);

        float sqdist(const Enemy& other);

        bool isDead() const;

        void setData(const EnemyData& Data) {data = Data;}
        EnemyData& getData() {return data;}
        
    private:
        // Motion
        sf::Vector2f vel;
        sf::Vector2f pos; // Will default to (0, 0)

        sf::Vector2f moveDir; // Direction that enemy is moving in
        
        // Data
        EnemyData data;

        // Render
        sf::CircleShape temp_shape; // Replace with a texture at some point

        //Objects
        HealthBar healthBar;

        Timer attackTimer;
};