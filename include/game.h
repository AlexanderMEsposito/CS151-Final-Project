/**
 * @file game.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-10-29
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include "../include/player.h"
#include "../include/menuscreen.h"

class Game {
    public:
        Game();
        ~Game(){};

        void handleInput(sf::RenderWindow& mWindow);
        void update(float dt, sf::RenderWindow& mWindow);
        void render(sf::RenderWindow& mWindow);
        void loadAssets() const;
        //bool isDone() const;
    private:
        //sf::RenderWindow mWindow;
        // bool mIsDone;
        MenuScreen menu;

};