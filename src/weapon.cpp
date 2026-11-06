#include "weapon.h"
#include "constants.h"

//testing
#include <iostream>

// ------------------------ ------------------------ ------------------------
// Constructors

Weapon::Weapon()
{
    name = "Weapon";
    damage = 10;
    range = 400.f;
    ammo = 10;
    magSize = 20;

    beam.setSize(sf::Vector2f(range, 2.f));
    beam.setOrigin({0.f, 1.f});
    beam.setFillColor(sf::Color::White);
    beam.setPosition({Constants::WINDOW_WIDTH / 2.f, Constants::WINDOW_HEIGHT / 2.f});

    gunFire2.setVolume(25);
}


Weapon::Weapon(std::string name, int dmg, float Range): name(name), damage(dmg), range(Range)
{
    beam.setSize(sf::Vector2f(range, 10.f));
    beam.setOrigin({0.f, 5.f});
    beam.setFillColor(sf::Color::White);
    beam.setPosition({Constants::WINDOW_WIDTH / 2.f, Constants::WINDOW_HEIGHT / 2.f});
}


// ------------------------ ------------------------ ------------------------

bool Weapon::fire(sf::Vector2f playerPos, sf::Vector2f mousePos)
{
    if (ammo > 0 && isReload == false) {
        beam.setPosition(playerPos);

        sf::Vector2f diff = mousePos - playerPos;
        beam.setRotation(diff.angle());
        ammo -= 1;
        return true;
    } else return false;

}
int Weapon::getAmmo() const{
    return ammo;
}
void Weapon::reload() {
    if (isReload == false && ammo < magSize && firing == false) {
        isReload = true;
        reloadTimer = reloadTime;
    }
}
void Weapon::updateMag(float dt, sf::RectangleShape& reloadBar) {
    if (isReload) {
        reloadTimer -= dt;
        //std::cout << "dt / reloadTimer: " << dt/reloadTimer << '\n';
        std::cout << "reloadTimer / reloadTime: " << reloadTimer/reloadTime << '\n';
        //set length based on fraction of being close to reloading
        reloadBar.setSize({Constants::DEFAULT_RELOAD_SIZE.x * (1 - reloadTimer/reloadTime), reloadBar.getSize().y});
        if (reloadTimer <= 0) {
            ammo += 1;
            std::cout << "Ammo added!" << std::endl;
            if (ammo == magSize) {
                isReload = false;
                std::cout << "Mag full." << std::endl;
            } else reloadTimer = reloadTime;
        }
    }
}

void Weapon::update(bool left_click, sf::Vector2f playerPos, sf::Vector2f mousePos)
{
    if (left_click) 
    {
        if (ready)
        {
            ready = false;
            if(fire(playerPos, mousePos)) 
            {
                firing = true;
                gunFire2.play();
                fire_timer.restart();
            }
        }
    }

    if (fire_timer.done())
    {
        firing = false;
    }

    if (!left_click)
    {
        ready = true;
    }
}

void Weapon::render(sf::RenderWindow& window)
{

    if (firing)
    {
        window.draw(beam);
    }
    

}