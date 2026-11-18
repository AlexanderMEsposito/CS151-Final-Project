#pragma once

struct WeaponData {

    // Main
    float damage {50};
    float range {500};

    // Firing
    float cooldown {.05f};
    float duration {.015f};
    bool automatic {false};

    // Ammo
    int magazine_size {10};
    int reload_amount {10};

    float reload_time {1.5f};

    //
    float screen_shake {.04};

    

};