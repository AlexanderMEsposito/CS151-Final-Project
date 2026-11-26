#include "../include/object.h"
#include "../include/objectData.h"

#include "constants.h"

Object::Object(sf::Vector2f spawnpoint, const ObjectData& Template, Renderer* renderer): data(Template), pos(spawnpoint), window(renderer)
{
    shape.setSize(data.size);
    shape.setTexture(&temp_texture);
    shape.setOrigin(shape.getGeometricCenter());

}


void Object::update(Player& player)
{
    if (data.on_step > 0)
    {
        // Check if player stepping on this object
        if ((pos - player.getPos() - window->screen_center).lengthSquared() < data.size.x * data.size.y)
        {
            if (data.on_step == 1)
            {
                remove();
                explode(player);
            }
        }
    }
    

}


void Object::remove()
{
    removed = true;
}

void Object::render(Renderer& window)
{   
    shape.setPosition(pos - window.world_reference);
    window.draw(shape);
}


void Object::explode(Player& player)
{
    if ((pos - player.getPos() - window->screen_center).lengthSquared() < data.size.x * data.size.y)
    {
        player.damage(50);
        player.setVel(
            player.getVel() + (player.getPos() - pos + window->screen_center).normalized() * 1410.f
        );

        if (window)
        {
            window->addScreenShake(300);
        }
    }
}
