#pragma once

#include <string>


struct EnemyData
{

    // Type of enemy 0 = default, 1 = next enemy type in enemyTemplates.h, so on
    int type {0};

    // Health points of the enemy
    float health {100.0f};

    // Maximum square speed the enemy can move
    float speed {50000.0f};

    // How quickly the enemy adds velocity to itself
    float acceleration {1600.0f};
    
};

