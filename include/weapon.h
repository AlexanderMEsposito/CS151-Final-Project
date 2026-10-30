#pragma once

#include <string>

class Weapon
{

public:

    // ------------------------

    std::string name;

    int damage;
    int range;

    // ------------------------

    Weapon();

    Weapon(std::string name, int dmg, int Range);

    // ------------------------

private:


};



