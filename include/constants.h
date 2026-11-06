#pragma once

namespace Constants {
    
    //eventually we could have different settings maybe for windows but it doesn't make sense to make it resizable so we should lock the window
    inline constexpr float WINDOW_WIDTH = 1920;
    inline constexpr float WINDOW_HEIGHT = 1080;

    // ---------------------------------------------
    // HUD
    inline constexpr sf::Vector2f HP_TEXT_POS = {130, 1030};
    inline constexpr sf::Vector2f AMMO_TEXT_POS = {1740, 1030};
    inline constexpr sf::Vector2f AMMO_ICON_POS = {1840, 1000};
    inline constexpr int HUD_MARGIN_X = 180;    
    inline constexpr int HUD_MARGIN_Y = 180;   
    inline constexpr int HP_TEXT_MARGIN_X = 130; 
    inline constexpr int HP_TEXT_MARGIN_Y = 50;

    // ---------------------------------------------
    // PLAYER
    inline constexpr float PLAYER_ACCEL = 3000;
    inline constexpr float MAX_SPEED = 500;
    inline constexpr float FRICTION = 1000;
    inline constexpr sf::Vector2f DEFAULT_RELOAD_SIZE = {100, 4};
    inline constexpr float RELOAD_BAR_Y_MARGIN = 50;

    // ---------------------------------------------
        // WORLD
        inline constexpr float CHUNK_SIZE = 1000;

    // ---------------------------------------------
    // ENEMIES
        // Stats

        // Game
        inline constexpr int MAX_ENEMIES = 5;

        //Physics
        inline constexpr float COLLISION_RADIUS = 40;
    
}