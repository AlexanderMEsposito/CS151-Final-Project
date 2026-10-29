#pragma once

#include <string>

class Weapon
{

public:

    std::string name {"Weapon"};

    int damage {1};
    int range {10};

    Weapon(int dmg, int Range, std::string name);

private:


};



