
#ifndef APP_CPP
#define APP_CPP

#include <SDL2/SDL.h>
#include "Framework.cpp"
#include "Sprite.cpp"

class App
{

    private:
    
        Framework* framework;
        bool run;
        Sprite* dvd;
        
    public:

        void Init()
        {
            framework = new Framework;
            framework->Init(800, 600);

            dvd = new Sprite(framework);
            dvd->Load("dvd.png");
        }

        void Run()
        {
            run = true;

            const int screenWidth = framework->GetWidth(), screenHeight = framework->GetHeight();
            float spriteX = 0.0f, spriteY = 0.0f;
            const int spriteWidth = dvd->GetRect().w, spriteHeight = dvd->GetRect().h;
            int spriteMovementX = 1, spriteMovementY = 1;

            float speed = 200.0f;

            while(run)
            {
                // Inputs and Frame Clearing
                
                ProcessEvents();

                framework->Clear();
                framework->Update();

                float elapsed = framework->getTimer()->GetElapsed();


                // Sprite Logic

                dvd->SetPos((int)spriteX, (int)spriteY);

                if((int)spriteX <= 0)
                    spriteMovementX = 1;
                if(((int)spriteX + spriteWidth) >= screenWidth)
                    spriteMovementX = -1;

                if((int)spriteY <= 0)
                    spriteMovementY = 1;
                if(((int)spriteY + spriteHeight) >= screenHeight)
                    spriteMovementY = -1;

                spriteX += (float)spriteMovementX * speed * elapsed;
                spriteY += (float)spriteMovementY * speed * elapsed;


                // Render

                dvd->Render();

                framework->Render();
            }
        }

        void ProcessEvents()
        {
            SDL_Event event;

            if(SDL_PollEvent(&event))
            {
                if(event.type == SDL_QUIT)
                {
                    run = false;
                }
            }
        }

        void Quit()
        {
            framework->Quit();
        }
};

#endif