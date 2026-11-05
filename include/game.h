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
#pragma once

#include "../include/player.h"
#include "../include/enemy.h"
#include "../include/menuscreen.h"
#include "../include/hud.h"
#include "../include/constants.h"

#include "../include/world.h"
#include <ctime>

#include <vector>



class Game {
    public:

        // ------------------------
        Game();
        ~Game(){};

        // ------------------------
        // Input

        void handleInput();


        void spawnEnemies();


        // ------------------------
        // Update

        void update();

        // ------

        void updateEnemies();
        void updateTestUI();
        void handleCollisions();
        void beamCollision(Enemy& e);
        void isDead(Enemy& e);

        // ------------------------

        void render();

        void drawEnemies(sf::RenderWindow &window);

        // ------------------------
        // Initialization / assets

        void loadAssets();

        // ------------------------

        bool running() const;

    private:
        
        // SETUP WINDOW AND FRAME LIMIT
        sf::RenderWindow window;
        
        sf::Clock clock;

        float dt;

        // bool mIsDone;
        MenuScreen menu;

        Player player;

        std::vector<Enemy> enemies; // List of all enemies in the world

        //HUD
        HUD hud;
        // World
        World world;

        // Assets, these are likely to move somewhere else
        const sf::Font CaveatBrush {"assets/fonts/CaveatBrush-Regular.ttf"};


        /*
        const sf::Font Lacquer("assets/fonts/Lacquer-Regular.ttf");
        const sf::Font Mansalva("assets/fonts/Mansalva-Regular.ttf");
        const sf::Font RubikDirt("assets/fonts/RubikDirt-Regular.ttf");
        const sf::Font RubikWetPaint("assets/fonts/RubikWetPaint-Regular.ttf");
        */

        // Temp test ui
        sf::Text test_text {CaveatBrush, "Hey this is CaveatBrush", 50};
        sf::Text text_vel {CaveatBrush, "---", 30};
};