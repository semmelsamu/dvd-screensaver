
#ifndef SPRITE_CPP
#define SPRITE_CPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include "Framework.cpp"

class Sprite
{
    private:

        Framework* framework;
        SDL_Texture* image;
        SDL_Rect rect;

    public:

        Sprite(Framework* _framework)
        {
            framework = _framework;
        }

        void Load(const std::string filename)
        {
            SDL_Surface *tempSurface = IMG_Load(filename.c_str());

            if(tempSurface == NULL)
            {
                std::cout << "Fehler beim laden von: " << filename.c_str() << std::endl;
                std::cout << "Fehlermeldung: " << SDL_GetError() << std::endl;

                framework->Quit();
                exit(1);
            }

            image = SDL_CreateTextureFromSurface(framework->GetRenderer(), tempSurface);
        
            rect.x = 0;
            rect.y = 0;
            rect.w = tempSurface->w;
            rect.h = tempSurface->h;

            SDL_FreeSurface(tempSurface);
        }

        void Render()
        {
            SDL_RenderCopy(framework->GetRenderer(), image, NULL, &rect);
        }

        SDL_Rect GetRect()
        {
            return rect;
        }

        void SetPos(unsigned int x, unsigned int y)
        {
            rect.x = x;
            rect.y = y;
        }

        ~Sprite()
        {
            SDL_DestroyTexture(image);
        }
};

#endif