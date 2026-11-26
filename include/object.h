#pragma once

#include <SFML/Graphics.hpp>
#include "renderer.h"

#include "objectData.h"

#include "player.h"

class Object
{

public:

    Object(sf::Vector2f spawnpoint, const ObjectData& data, Renderer* renderer);

    void update(Player& player);
    void render(Renderer& window);

    void explode(Player& player);

    void remove();
    bool shouldRemove() {return removed;}

    ObjectData data;

private:

    bool removed = false;

    sf::Vector2f pos;
    sf::Vector2f vel;

    sf::RectangleShape shape;

    sf::Texture temp_texture {data.texture};

    Renderer* window = 0;

};

