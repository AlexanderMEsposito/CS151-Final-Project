#include "weapon.h"
#include "constants.h"

#include "../include/player.h"

#include "weaponTemplates.h"

//testing
#include <iostream>

// ------------------------ ------------------------ ------------------------
// Constructors

Weapon::Weapon(): ammo(data.magazine_size)
{
    name = "Weapon";

    // beam.setSize(sf::Vector2f(range, 2.f));
    // beam.setOrigin({0.f, 1.f});
    // beam.setFillColor(sf::Color::White);
    // beam.setPosition({Constants::WINDOW_WIDTH / 2.f, Constants::WINDOW_HEIGHT / 2.f});

    gunFire2.setVolume(25);
}

Weapon::Weapon(int type)
{
    data = WeaponTemplates::all[type];
    ammo = data.magazine_size;
    fire_timer.setDuration(data.duration);
    cooldownTimer.setDuration(data.cooldown);
    reloadTimer.setDuration(data.reload_time);
    burstTimer.setDuration(data.cooldown);

    gunFire2.setVolume(25);
}


// ------------------------ ------------------------ ------------------------

bool Weapon::fire(Player& player, sf::Vector2f mousePos)
{
    if (ammo > 0) {
        if (isReload)
        {
            isReload = false;
        }

        //beam.setPosition(playerPos);
        //beam.setRotation(diff.angle());
        sf::Vector2f diff = (mousePos - player.playerShape.getPosition());
        if (diff.lengthSquared() > 0.f)
        {
            diff = diff.normalized();

            constexpr float bulletSpeed = 900.f;
            bullets.emplace_back(player.getPos() + player.getVel() * .1f + diff * 30.0f, diff * bulletSpeed);
        }
        ammo -= 1;
        return true;
    } else return false;

}
int Weapon::getAmmo() const{
    return ammo;
}
void Weapon::reload() {
    if (isReload == false && ammo < data.magazine_size && firing == false && burstShotsRemaining == 0) {
        isReload = true;
        reloadTimer.restart();
    }
}
void Weapon::updateMag(float dt, sf::RectangleShape& reloadBar) {
    if (isReload) {
        //std::cout << "dt / reloadTimer: " << dt/reloadTimer << '\n';
        //set length based on fraction of being close to reloading
        reloadBar.setSize({Constants::DEFAULT_RELOAD_SIZE.x * reloadTimer.progress(), reloadBar.getSize().y});
        if (reloadTimer.done()) {
            ammo += data.reload_amount;
            if (ammo >= data.magazine_size) {
                isReload = false;
                ammo = data.magazine_size;
            } else reloadTimer.restart();
        }
    }
}

void Weapon::update(bool left_click, Player& player, sf::Vector2f mousePos)
{
    if (data.burst_size > 1)
    {
        const auto recordShot = [this]()
        {
            firing = true;
            gunFire2.play();
            fire_timer.restart();
            cooldownTimer.restart();
        };

        if (left_click && ready)
        {
            ready = false;
            if (burstShotsRemaining == 0 && fire(player, mousePos))
            {
                burstShotsRemaining = data.burst_size - 1;
                burstTimer.setDuration(data.cooldown);
                burstTimer.restart();
                recordShot();
            }
        }

        if (burstShotsRemaining > 0 && burstTimer.done())
        {
            if (fire(player, mousePos))
            {
                --burstShotsRemaining;
                burstTimer.restart();
                recordShot();
            }
            else
            {
                burstShotsRemaining = 0;
            }
        }

        if (!left_click && cooldownTimer.done())
        {
            ready = true;
        }

        if (fire_timer.done())
        {
            firing = false;
        }

        return;
    }

    if (left_click) 
    {
        if (ready)
        {
            ready = false;
            if(fire(player, mousePos)) 
            {
                firing = true;
                gunFire2.play();
                fire_timer.restart();
                cooldownTimer.restart();
            }
        }
    }

    if (fire_timer.done())
    {
        firing = false;
    }

    if (cooldownTimer.done() && (data.automatic || !left_click))
    {
        ready = true;
    }
}

void Weapon::render(Renderer& window, sf::RectangleShape& reloadBar)
{

    if (firing)
    {
        window.addScreenShake(data.screen_shake);
    }
    if (isReload) {
        window.draw(reloadBar);
    }
}

std::vector<Bullet>& Weapon::getBullets()
{
    return bullets;
}

const std::vector<Bullet>& Weapon::getBullets() const
{
    return bullets;
}