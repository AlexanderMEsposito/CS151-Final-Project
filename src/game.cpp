/**
 * @file game.cpp
 * @author The Cool Guys
 * @brief 
 * @version 0.1
 * @date 2026-10-29
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <SFML/Graphics.hpp>
#include "../include/game.h"
#include "../include/player.h"
#include "../include/enemyTemplates.h"
#include "../include/twister.h"
#include <algorithm>
#include <cstddef>


// ------------------------ ------------------------ ------------------------ ------------------------
// ------------------------ ------------------------ ------------------------ ------------------------

Game::Game(): 
window(
    sf::VideoMode({
        static_cast<unsigned>(Constants::WINDOW_WIDTH), 
        static_cast<unsigned>(Constants::WINDOW_HEIGHT)
    }), 
    "Unfinished Zombie Game 2"
    )
{

    window.setPosition({50, 50});
    window.setFramerateLimit(120);


    test_text.setPosition({0.f, 100.f});
    text_vel.setPosition({0, 200});


    // seed randomization
    //std::srand(static_cast<unsigned>(time(NULL)));
    seed_random();

    spawnEnemies(3, {0, 0}, {Constants::CHUNK_SIZE, Constants::CHUNK_SIZE});


}

// ------------------------ ------------------------ ------------------------ ------------------------
// ------------------------ ------------------------ ------------------------ ------------------------

void Game::loadAssets() {}


// ------------------------ ------------------------ ------------------------ ------------------------
// ------------------------ ------------------------ ------------------------ ------------------------

void Game::handleInput() {
    // Process events
    while (const std::optional event = window.pollEvent())
    {
        // Close window: exit
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
    }

    sf::Vector2f mouseWorld = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    // Handle input on player
    player.handleInput(mouseWorld, dt);
}

// ------------------------ ------------------------ ------------------------


//W helper function
bool Game::running() const 
{
    return window.isOpen();
}


// ------------------------ ------------------------ ------------------------ ------------------------
// ------------------------ ------------------------ ------------------------ ------------------------

void Game::update() {
    // Get time between frames
    dt = clock.restart().asSeconds();

    // Update objects
    player.update(dt);

    handleCollisions();

    world.setOrigin(player.getPos());

    updateEnemies();
    hud.update(player.getPlayerHealth(), 100.f, player.weapon.getAmmo(), 20);
    updateTestUI();
}

// ------------------------ ------------------------ ------------------------

/**
 * @brief Spawns a number of enemies equal to quantity. Each enemy will spawn at a random position between bound_a and bound_b.
 * 
 * @param quantity # of enemies to spawn
 * @param bound_a Top left corner of the area enemies can spawn in
 * @param bound_b Bottom left corner of the area enemies can spawn in
 */
void Game::spawnEnemies(int quantity, const sf::Vector2f& bound_a, const sf::Vector2f& bound_b)
{
    sf::Vector2f delta = bound_b - bound_a;

    for (int i {}; i < quantity; i++)
    {
        // randomizes enemy position through rand
        enemies.push_back(
            Enemy({
                bound_a.x + delta.x * randomf(),
                bound_a.y + delta.y * randomf()
            })
        );

        float enemyKey = randomf();

        if (enemyKey > .5)
        {
            if (enemyKey > .75)
            {
                enemies.back().setData(EnemyTypes::sprinter);
            }
            else 
            {
                enemies.back().setData(EnemyTypes::injured);
            }
        }
            
    }

}







// ------------------------ ------------------------ ------------------------

// Update related functions
void Game::updateEnemies()
{
    for (Enemy& e : enemies)
    {
        e.update(dt, player);
    }

    std::vector<Bullet>& bullets = player.weapon.getBullets();
    std::size_t bulletIndex = 0;



    while (bulletIndex < bullets.size())
    {
        Bullet& bullet = bullets[bulletIndex];
        bullet.update(dt, player.getVel());

        bool hit = false;

        for (Enemy& e : enemies)
        {
            float distance = (bullet.getPosition() - e.getShape().getPosition()).length();

            float radius = bullet.getRadius() + e.getShape().getRadius();

            if (distance <= radius)
            {
                e.getData().health -= player.weapon.damage;
                e.getShape().setFillColor(sf::Color::Red);
                juicyImpact.play();

                hit = true;
                break;
            }
        }

        const sf::Vector2f position = bullet.getPosition();
        const float margin = bullet.getRadius();

        const bool offscreen =
            position.x + margin < 0.f || position.x - margin > Constants::WINDOW_WIDTH ||
            position.y + margin < 0.f || position.y - margin > Constants::WINDOW_HEIGHT;

        if (hit || offscreen)
        {
            bullets.erase(bullets.begin() + bulletIndex);
        }
        else
        {
            ++bulletIndex;
        }
    }

    //Loops through list and removes enemy if isDead returns true
    enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [](const Enemy& e) { return e.isDead(); }), enemies.end());
}


// ------------------------ ------------------------ ------------------------

// Called in updateEnemies(), checks when the fire button is pressed
// if there is collision between the enemy and the player weapon beam
// if so, changes the color and subtracts from the enemies health
// void Game::beamCollision(Enemy& e)
// {

//     if(player.weapon.firing == true)
//     {
//         // checks if beam and enemy are intersecting and if the gun is being fired 
//         if(e.getShape().getGlobalBounds().findIntersection(player.weapon.beam.getGlobalBounds()))
//         {
//             e.getData().health -= player.weapon.damage;
//             juicyImpact.play();
//             e.getShape().setFillColor(sf::Color::Red);
            
            
            
//         }
//     }


// }


// ------------------------ ------------------------ ------------------------

// Update the ui that draws on the screen for testing purposes. This should be replaced with a real ui drawing function at some point.
void Game::updateTestUI()
{
    std::string vel_str = "Vel: (" + std::to_string(player.getVel().x) + ", " + std::to_string(player.getVel().y) + ")";
    
    text_vel.setString(vel_str);
    
}

void Game::handleCollisions()
{
    for (Enemy& e : enemies)
    {
        e.collidePlayer(player);

        for (Enemy& other : enemies)
        {
            if (&e != &other)
            {
                e.collide(other);
            }
        }
    }
}

// ------------------------ ------------------------ ------------------------ ------------------------
// ------------------------ ------------------------ ------------------------ ------------------------

void Game::render() {
    window.clear(sf::Color::Black);

    // First draw the world background
    world.renderChunks(window, player.getPos());

    // THEN DRAW
    window.draw(test_text);
    window.draw(text_vel);
    player.render(window);
    for (const Bullet& bullet : player.weapon.getBullets())
    {
        bullet.render(window);
    }
    drawEnemies(window);
    hud.render(window);

    // THEN DISPLAY
    window.display();
}

// ------------------------ ------------------------ ------------------------

void Game::drawEnemies(sf::RenderWindow &window)
{
    for (Enemy& e : enemies)
    {
        e.render(window);
    }
}

