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
#include "../include/player.h"
#include "../include/constants.h"


int main () {
    sf::RenderWindow window(sf::VideoMode({static_cast<unsigned>(Constants::WINDOW_WIDTH), static_cast<unsigned>(Constants::WINDOW_HEIGHT)}), "Unfinished Zombie Game 2");

    //loads menu music
    sf::Music menu("assets/music/Night-Stalker-3.ogg");
    //loads gameloop music
    sf::Music game("assets/music/Night-Stalker-2.ogg");

    //WE DONT NEED ALL OF THESE BUT I THINK WE COULD PICK FROM THESE
    const sf::Font CaveatBrush("assets/fonts/CaveatBrush-Regular.ttf");
    const sf::Font Lacquer("assets/fonts/Lacquer-Regular.ttf");
    const sf::Font Mansalva("assets/fonts/Mansalva-Regular.ttf");
    const sf::Font RubikDirt("assets/fonts/RubikDirt-Regular.ttf");
    const sf::Font RubikWetPaint("assets/fonts/RubikWetPaint-Regular.ttf");

    //TODO THIS SHOULD BE MOVED TO MENU GAME STATE NOT IN MAIN LOOP
    menu.play();

    Player player;
    

    sf::Text test1(CaveatBrush, "Hey this is CaveatBrush", 50);
    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

        }
        window.clear(sf::Color::Black);
        window.draw(test1);
        window.draw(player.playerShape);
        window.display();
    }
}