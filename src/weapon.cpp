#include "weapon.h"

// ------------------------ ------------------------ ------------------------
// Constructors

Weapon::Weapon()
{
    name = "Weapon";
    damage = 10;
    range = 1;
}


Weapon::Weapon(std::string name, int dmg, int Range): name(name), damage(dmg), range(Range)
{

}


// ------------------------ ------------------------ ------------------------