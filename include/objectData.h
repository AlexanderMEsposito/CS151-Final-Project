#pragma once

#include <SFML/Graphics.hpp>
#include <string_view>

struct ObjectData
{

    sf::Vector2f size;
    std::string_view texture;

    int on_step {}; // 0: nothing, 1: explode
    

};



