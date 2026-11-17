#pragma once

#include <SFML/Graphics.hpp>


class Renderer
{

public:

    Renderer();

    void handleInput();

    void update(const sf::Vector2f& worldReference);

    void close();

    bool isOpen() const {return window.isOpen();}

    // Vector references
    const sf::Vector2f& mouse_pos = m_mouse_pos;
    const sf::Vector2f& world_reference = m_world_reference;
    const sf::Vector2f& screen_center = m_screen_center;


    // Transform
    void setPosition(const sf::Vector2i& pos);

    // Details
    void setFramerateLimit(float fps);

    // Drawing
    void clear(const sf::Color& color);

    void prepareDraw();

    void draw(const sf::Drawable& drawable);

    void display();

    void addScreenShake(float amount);

private:

    // SFML Window
    sf::RenderWindow window;

    // -----------------------------------
    // Accessable values

        // Mouse location
    sf::Vector2f m_mouse_pos;

        // The point to compare to when drawing world objects
    sf::Vector2f m_world_reference;

        // The center of the screen in pixel coordinates
    sf::Vector2f m_screen_center;

    // -----------------------------------

    // Offset to draw all drawables at, in pixels
    sf::Vector2f draw_offset;

    // Screen shake per tick, in pixels
    float screen_shake {0.0f};

    // Render states
    sf::RenderStates states = sf::RenderStates::Default;

};




