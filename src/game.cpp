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

Game::Game() {

}
void Game::handleInput(sf::RenderWindow& mWindow) {
    // Process events
        while (const std::optional event = mWindow.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>()) {
                mWindow.close();
            }
        }
}
void Game::update(float dt, sf::RenderWindow& mWindow) {

}
void Game::render(sf::RenderWindow& mWindow) {

}