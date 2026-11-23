#include "../include/renderer.h"
#include "../include/constants.h"
#include "../include/twister.h"


Renderer::Renderer(): 
window(
    sf::VideoMode({
        static_cast<unsigned>(Constants::WINDOW_WIDTH), 
        static_cast<unsigned>(Constants::WINDOW_HEIGHT)
    }), 
    "Unfinished Zombie Game 2"
    )
{

    m_screen_center = {Constants::WINDOW_WIDTH / 2, Constants::WINDOW_HEIGHT / 2};

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

    // Screen shake decay
    screen_shake *= Constants::SCREEN_SHAKE_DECAY;
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


// Effects
void Renderer::addScreenShake(float amount)
{

    if (amount > screen_shake)
    {
        screen_shake = amount;
    }

}

// Drawing

void Renderer::clear(const sf::Color& color)
{
    window.clear(color);
}

void Renderer::prepareDraw()
{

    // Reset render states
    states = sf::RenderStates::Default;

    draw_offset = {randrange(-screen_shake, screen_shake), randrange(-screen_shake, screen_shake)};

    states.transform.translate(draw_offset);
}

void Renderer::draw(const sf::Drawable& drawable)
{
    window.draw(drawable, states);
}

void Renderer::display()
{
    window.display();
}