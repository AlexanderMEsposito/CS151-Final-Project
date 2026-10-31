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
#include "../include/enemy.h"
#include "../include/constants.h"
#include "../include/game.h"


int main () {
    

    Game game;
    
    //loads menu music
    sf::Music menu("assets/music/Night-Stalker-3.ogg");
    //loads gameloop music
    sf::Music gameBg("assets/music/Night-Stalker-2.ogg");

    //TODO THIS SHOULD BE MOVED TO MENU GAME STATE NOT IN MAIN LOOP
    menu.play();


    while (game.running())
    {
        game.handleInput();
        game.update();
        game.render();
    }
}