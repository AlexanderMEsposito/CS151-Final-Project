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
    enemies.emplace_back();
    enemies.push_back(
        Enemy({0.0f, Constants::WINDOW_HEIGHT})
    );

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

    updateEnemies();
    
    updateTestUI();
}

// ------------------------ ------------------------ ------------------------

// Update related functions
void Game::updateEnemies()
{
    for (Enemy& e : enemies)
    {
        e.update(dt, player);
    }
}

// ------------------------ ------------------------ ------------------------

// Update the ui that draws on the screen for testing purposes. This should be replaced with a real ui drawing function at some point.
void Game::updateTestUI()
{
    std::string vel_str = "Vel: (" + std::to_string(player.getVel().x) + ", " + std::to_string(player.getVel().y) + ")";
    
    text_vel.setString(vel_str);
    
}

// ------------------------ ------------------------ ------------------------ ------------------------
// ------------------------ ------------------------ ------------------------ ------------------------

void Game::render() {
    window.clear(sf::Color::Black);

    // THEN DRAW
    window.draw(test_text);
    window.draw(text_vel);
    window.draw(player.playerShape);
    window.draw(player.healthBar.getFill());
    window.draw(player.healthBar.getBorder());

    drawEnemies();

    // THEN DISPLAY
    window.display();
}

// ------------------------ ------------------------ ------------------------

void Game::drawEnemies()
{
    for (Enemy& e : enemies)
    {
        window.draw(e.getShape());
    }
}

