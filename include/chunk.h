#pragma once

#include <SFML/Graphics.hpp>

class Game; // Forward declaration


class Chunk
{

public:

    Chunk() {};
    Chunk(int u, int v, Game* owner);

    Chunk& initialize(int u, int v, Game* owner);

    void render(sf::RenderWindow& window, const sf::Vector2f& reference);

    sf::Vector2i Twist2(int U, int V);

private:

    int u {0}, v {0};

    bool initialized {false};

    sf::Vector2f corner_upper_left {0.0f, 0.0f};
    sf::Vector2f corner_lower_right {0.0f, 0.0f};

    sf::RectangleShape display;
    sf::Texture material {"assets/art/world/grass.png"};

    // Generation Data
    int biome {0};
    
    void generate();

    // Pointer to game
    Game* game {};
};



