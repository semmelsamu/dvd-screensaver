#ifndef TIMER_HPP
#define TIMER_HPP

#include <SDL.h>
#include "singleton.cpp"

#define Timer Timer::Get()

class Timer : public Singleton<Timer>
{
    public:

        Timer();
        void update();
        float getElapsed();

    public:

        float elapsed;
        float currentTime;
        float lastTime;
};

#endif