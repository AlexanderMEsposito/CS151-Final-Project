#pragma once

namespace Constants {
    
    //eventually we could have different settings maybe for windows but it doesn't make sense to make it resizable so we should lock the window
    inline constexpr float WINDOW_WIDTH = 1920;
    inline constexpr float WINDOW_HEIGHT = 1080;

    // ---------------------------------------------
    // PLAYER
    inline constexpr float PLAYER_ACCEL = 3000;
    inline constexpr float MAX_SPEED = 500;
    inline constexpr float FRICTION = 1000;

    // ---------------------------------------------
        // WORLD
        inline constexpr float CHUNK_SIZE = 1000;

    // ---------------------------------------------
    // ENEMIES
        // Stats
            inline constexpr float acceleration = 1600.0f; // How fast the enemy speeds up when running
            inline constexpr float speed = 50000.0f; // This value is pre-squared: a speed of 16 is really a speed of 4 (it speeds up computation)

        // Game
        inline constexpr int MAX_ENEMIES = 5;

        //Physics
        inline constexpr float COLLISION_RADIUS = 40;
    
}