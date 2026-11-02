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
}