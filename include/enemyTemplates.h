#pragma once

#include "enemyData.h"

namespace EnemyTypes
{
    constexpr EnemyData normal {
        0,
        100.0f,
        50000.0f,
        1600.0f,
        0.0f
    };

    constexpr EnemyData injured {
        1,
        75.0f,
        4000.0f,
        1000.0f,
        0.0f
    };

    constexpr EnemyData sprinter {
        2,
        125.0f,
        120000.0f,
        3500.0f,
        0.0f
    };

    constexpr EnemyData all[] = {
        normal,     // type 0
        injured,    // type 1
        sprinter    // type 2
    };
};


