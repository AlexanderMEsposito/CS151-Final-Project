#pragma once

#include <SFML/Graphics.hpp>

class Timer
{

public:

    Timer();
    Timer(float duration);

    void restart();
    
    bool done() const;

    float progress() const;

    float delta() const;

    void setDuration(float duration);

    float getDuration() const;

private:

    sf::Clock clock;
    float dur {1.0f};

};


