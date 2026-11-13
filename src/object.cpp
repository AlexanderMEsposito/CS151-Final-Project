#include "../include/object.h"


Object::Object(sf::Vector2f spawnpoint): pos(spawnpoint)
{

    shape.setSize({40, 40});
    shape.setTexture(&temp_texture);

}


void Object::update()
{}


void Object::render(sf::RenderWindow& window)
{
    window.draw(shape);
}
