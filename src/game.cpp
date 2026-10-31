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

}

void Game::loadAssets() {}

bool Game::running() const 
{
    return window.isOpen();
}


void Game::handleInput() {
    // Process events
    while (const std::optional event = window.pollEvent())
    {
        // Close window: exit
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
    }

    // Handle input on player
    player.handleInput();
}

void Game::update() {
    // Get time between frames
    dt = clock.restart().asSeconds();

    // Update objects
    player.update(dt);
    testEnemy.update(dt, player);
    
    updateTestUI();
}

void Game::render() {
    window.clear(sf::Color::Black);

    // THEN DRAW
    window.draw(test_text);
    window.draw(text_vel);
    window.draw(player.playerShape);

    window.draw(testEnemy.getShape());

    // THEN DISPLAY
    window.display();
}

void Game::updateTestUI()
{
    std::string vel_str = "Vel: (" + std::to_string(player.getVel().x) + ", " + std::to_string(player.getVel().y) + ")";
    
    text_vel.setString(vel_str);
    
}