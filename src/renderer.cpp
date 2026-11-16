#include "../include/renderer.h"
#include "../include/constants.h"



Renderer::Renderer(): 
window(
    sf::VideoMode({
        static_cast<unsigned>(Constants::WINDOW_WIDTH), 
        static_cast<unsigned>(Constants::WINDOW_HEIGHT)
    }), 
    "Unfinished Zombie Game 2"
    )
{

}


void Renderer::handleInput()
{
    // Process events
    while (const std::optional event = window.pollEvent())
    {
        // Close window: exit
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
    }

    // Get mouse position this frame
    m_mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
}

void Renderer::update(const sf::Vector2f& worldReference)
{
    m_world_reference = worldReference;
}

void Renderer::close()
{
    window.close();
}



// Transform
void Renderer::setPosition(const sf::Vector2i& pos)
{
    window.setPosition(pos);
}


void Renderer::setFramerateLimit(float fps)
{

    window.setFramerateLimit(fps);

}


// Drawing

void Renderer::clear(const sf::Color& color)
{
    window.clear(color);
}

void Renderer::draw(const sf::Drawable& drawable, const sf::RenderStates& states)
{
    window.draw(drawable, states);
}

void Renderer::display()
{
    window.display();
}