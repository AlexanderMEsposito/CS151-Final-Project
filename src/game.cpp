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
#include <algorithm>

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

    // Spawn test enemies
    // enemies.emplace_back();
    // enemies.push_back(
    //     Enemy({0.0f, Constants::WINDOW_HEIGHT})
    // );
    // enemies.push_back(
    //     Enemy({0.0f, Constants::WINDOW_HEIGHT / 2})
    // );

    spawnEnemies();


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

void Game::spawnEnemies()
{
    // seed randomization
    std::srand(static_cast<unsigned>(time(NULL)));

    
    // randomizes enemy position through rand (Vector2f needs floats and rand needs ints))
    // first enemy
    enemies.push_back(Enemy({static_cast<float>(rand() % static_cast<int>(Constants::WINDOW_WIDTH)),
        static_cast<float>(rand() % static_cast<int>(Constants::WINDOW_HEIGHT))}));
    // second enemy
    enemies.push_back(Enemy({static_cast<float>(rand() % static_cast<int>(Constants::WINDOW_WIDTH)),
        static_cast<float>(rand() % static_cast<int>(Constants::WINDOW_HEIGHT))}));
    // third enemy
    enemies.push_back(Enemy({static_cast<float>(rand() % static_cast<int>(Constants::WINDOW_WIDTH)),
        static_cast<float>(rand() % static_cast<int>(Constants::WINDOW_HEIGHT))}));

    

}







// ------------------------ ------------------------ ------------------------

// Update related functions
void Game::updateEnemies()
{
    for (Enemy& e : enemies)
    {
        e.update(dt, player);
        beamCollision(e);
    }

    //Loops through list and removes enemy if isDead returns true
    enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [](const Enemy& e) { return e.isDead(); }), enemies.end());
}


// ------------------------ ------------------------ ------------------------

// Called in updateEnemies(), checks when the fire button is pressed
// if there is collision between the enemy and the player weapon beam
// if so, changes the color and subtracts from the enemies health
void Game::beamCollision(Enemy& e)
{

    if(player.weapon.firing == true)
    {
        // checks if beam and enemy are intersecting and if the gun is being fired 
        if(e.getShape().getGlobalBounds().findIntersection(player.weapon.beam.getGlobalBounds()))
        {
            e.getHealth() -= player.weapon.damage;
            juicyImpact.play();
            e.getShape().setFillColor(sf::Color::Red);
            
            
            
        }
    }


}


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

