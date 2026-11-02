#include "timer.h"


Timer::Timer()
{}

Timer::Timer(float duration): dur(duration)
{}

void Timer::restart()
{
    clock.restart();
}
    
bool Timer::done() const
{

    return clock.getElapsedTime().asSeconds() > dur;

}

float Timer::progress() const
{
    float s = clock.getElapsedTime().asSeconds();

    if (s > dur)
    {
        return 1;
    }

    return s / dur;
}

float Timer::delta() const
{
    return clock.getElapsedTime().asSeconds();
}

void Timer::setDuration(float duration)
{
    dur = duration;
}

float Timer::getDuration() const
{
    return dur;
}