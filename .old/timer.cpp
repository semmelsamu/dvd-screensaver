#include "timer.hpp"

Timer::Timer()
{
    currentTime = 0.0f;
    lastTime = SDL_GetTicks() / 1000.0f;
    elapsed = 0.0f;
}

Timer::update()
{
    currentTime = SDL_GetTicks() / 1000.0f;
    elapsed = currentTime - lastTime;
    lastTime = currentTime;
}