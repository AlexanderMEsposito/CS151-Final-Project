#pragma once

#include "weaponData.h"

namespace WeaponTemplates
{

    constexpr WeaponData pistol {
        50,
        500,
        .05f,
        .015f,
        false,
        10,
        10,
        1.5f,
        4.0f
    };

    constexpr WeaponData rifle {
        100,
        500,
        .05f,
        .015f,
        false,
        10,
        10,
        1.5f,
        4.0f
    };

    constexpr WeaponData machineGun {
        40,
        500,
        .05f,
        .015f,
        false,
        30,
        30,
        2.0f,
        4.0f,
        3
    };

    constexpr WeaponData cannon {
        200,
        1000,
        .05f,
        .2f,
        true,
        1,
        1,
        5.0f,
        500.0f
    };

    constexpr WeaponData all[] = {
        pistol,     // type 0
        rifle,    // type 1
        machineGun, // type 2
        cannon // type 3
    };
};


