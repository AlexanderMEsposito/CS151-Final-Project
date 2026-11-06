/**
 * @file menuscreen.h
 * @author The Cool Guys
 * @brief Menu Screen derived from Screen class
 * @version 0.1
 * @date 2026-10-29
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#pragma once
#include "../include/screen.h"
#include "../include/button.h"
#include <vector>

class MenuScreen: public Screen {
    public:
        MenuScreen();
        virtual void handleEvent(const sf::Event& event, sf::RenderWindow &window) override;
        virtual void update(float dt) override;
        virtual void draw(sf::RenderWindow& window) const override;
    private:
        //Every object that makes up the screen (sprites, images, text, fonts)
        //Sprites
            //Textures
            sf::Texture bgTexture{"assets/art/title/bg-1080.png"};
            //Background
            sf::Sprite bg{bgTexture};
        //Fonts
        sf::Font Oswald{"assets/fonts/Oswald/Oswald-Medium.ttf"};
        //Text
        sf::Text title{Oswald, "Unfinished Zombie Game 2", 100};
        sf::Text newGame{Oswald, "New Game", 50};
        sf::Text continueGame{Oswald, "Continue", 50};
        sf::Text options{Oswald, "Options", 50};
        sf::Text quit{Oswald, "Quit", 50};
        //Buttons
        std::vector<Button> menuButtons{};
        Button newGamebtn;
        Button continuebtn;
        Button optionsbtn;
        Button quitbtn;

};