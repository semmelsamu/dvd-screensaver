
#ifndef FRAMEWORK_CPP
#define FRAMEWORK_CPP

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Timer.cpp"

class Framework
{
    private:

        SDL_Window* window;
        SDL_Renderer* renderer;
        unsigned int width, height;
        Timer* timer;

    public:

        Framework()
        {
            window = NULL;
            renderer = NULL;
            timer = NULL;
        }

        SDL_Renderer* GetRenderer()
        {
            return renderer;
        }

        Timer* getTimer()
        {
            return timer;
        }

        int Init(unsigned int _width, unsigned int _height)
        {
            width = _width;
            height = _height;

            SDL_Init(SDL_INIT_EVERYTHING);
            IMG_Init(IMG_INIT_PNG);

            timer = new Timer();

            window = SDL_CreateWindow("Hello SDL!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_ALLOW_HIGHDPI);

            if(window == NULL)
            {
                std::cout << "Could not create Window: " << SDL_GetError() << std::endl;
                return false;
            }

            renderer = SDL_CreateRenderer(window, -1, 0);

            if(renderer == NULL)
            {
                std::cout << "Could not create Renderer: " << SDL_GetError() << std::endl;
                return false;
            }

            return 0;
        }

        void Quit()
        {
            if(renderer != NULL) SDL_DestroyRenderer(renderer);
            if(window != NULL) SDL_DestroyWindow(window);

            SDL_Quit();
        }

        ~Framework()
        {
            renderer = NULL;
            window = NULL;
        }

        unsigned int GetWidth()
        {
            return width;
        }

        unsigned int GetHeight()
        {
            return height;
        }

        void Clear()
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderClear(renderer);
        }

        void Render()
        {
            SDL_RenderPresent(renderer);
        }

        void Update()
        {
            timer->Update();
        }
};

#endif