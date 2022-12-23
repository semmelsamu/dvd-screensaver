
#include <SDL2/SDL.h>

class Timer
{
    private:

        float elapsed;
        float currentTime;
        float lastTime;

    public:

        Timer()
        {
            currentTime = 0.0f;
            lastTime = SDL_GetTicks() / 1000.0f;
            elapsed = 0.0f;
        }

        void Update()
        {
            currentTime = SDL_GetTicks() / 1000.0f;
            elapsed = currentTime - lastTime;
            lastTime = currentTime;
        }

        float GetElapsed()
        {
            return elapsed;
        }
};