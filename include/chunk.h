#pragma once

#include <SFML/Graphics.hpp>
#include "../include/object.h"
#include "../include/enemy.h"
#include <list>

class Game; // Forward declaration


class Chunk
{

public:

    Chunk() {};
    Chunk(int u, int v, Game* owner);

    Chunk& initialize(int u, int v, Game* owner);

    // Render functions
    void render(Renderer& window);
    void renderObjects(Renderer& window);

    void updateObjects(Player& player);

    void cleanup();

    sf::Vector2i Twist2(int U, int V);

private:

    int u {0}, v {0};

    bool initialized {false};

    sf::Vector2f corner_upper_left {0.0f, 0.0f};
    sf::Vector2f corner_lower_right {0.0f, 0.0f};

    sf::RectangleShape display;
    const sf::Texture* material {};

    // Generation Data
    int biome {0};
    
    void generate();

    // Pointer to game
    Game* game {};

    // Container
    std::list<Object> objects;
    std::list<Enemy> enemies;
};



