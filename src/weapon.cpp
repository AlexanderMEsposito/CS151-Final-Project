#include "weapon.h"
#include "constants.h"

// ------------------------ ------------------------ ------------------------
// Constructors

Weapon::Weapon()
{
    beam.setSize(sf::Vector2f(range, 2.f));
    beam.setOrigin({0.f, 1.f});
    beam.setFillColor(sf::Color::White);
    beam.setPosition({Constants::WINDOW_WIDTH / 2.f, Constants::WINDOW_HEIGHT / 2.f});
}


Weapon::Weapon(std::string name, int dmg, float Range): name(name), damage(dmg), range(Range)
{
    beam.setSize(sf::Vector2f(range, 10.f));
    beam.setOrigin({0.f, 5.f});
    beam.setFillColor(sf::Color::White);
    beam.setPosition({Constants::WINDOW_WIDTH / 2.f, Constants::WINDOW_HEIGHT / 2.f});
}


// ------------------------ ------------------------ ------------------------

void Weapon::fire(sf::Vector2f playerPos, sf::Vector2f mousePos)
{
    beam.setPosition(playerPos);

    sf::Vector2f diff = mousePos - playerPos;
    beam.setRotation(diff.angle());
}

void Weapon::update(bool left_click, sf::Vector2f playerPos, sf::Vector2f mousePos)
{
    if (left_click) 
    {

        if (ready)
        {
            firing = true;
            ready = false;
            fire_timer.restart();

            fire(playerPos, mousePos);

        }
    }

    if (fire_timer.getElapsedTime().asSeconds() > fire_duration)
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