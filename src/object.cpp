#include "../include/object.h"


Object::Object(sf::Vector2f spawnpoint): pos(spawnpoint)
{

    shape.setSize({120, 120});
    shape.setTexture(&temp_texture);

}


void Object::update()
{}


void Object::render(Renderer& window)
{   
    shape.setPosition(pos - window.world_reference);
    window.draw(shape);
}
