/**
 * @file main.cpp
 * @author The Cool Guys
 * @brief 
 * @version 0.1
 * @date 2026-10-27
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
int main () {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML Window");

    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>()) {
                window.close();
                return 0;
            }
        }
    }
    
}