#pragma once

#include <SFML/Graphics.hpp>
#include "renderer.h"

#include "objectData.h"

#include "player.h"

#include "GameContext.h"

class Object
{

public:

    Object(sf::Vector2f spawnpoint, const ObjectData& data, GameContext& ctx);

    void update(Player& player);
    void render(Renderer& window);

    void explode(Player& player);

    void remove();
    bool shouldRemove() const {return removed;}

    ObjectData data;

private:

    bool removed = false;

    sf::Vector2f pos;
    sf::Vector2f vel;

    sf::RectangleShape shape;

    const sf::Texture* texture {0};

    GameContext& ctx;

};

