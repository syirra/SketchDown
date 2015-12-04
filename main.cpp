#include <SDL/SDL.h>
#include <iostream>

int main(int argc, char *argv[])
{
    SDL_Surface *screen;
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
        std::cout << "SDL ERROR: Video initialization: " << SDL_GetError() << std::endl;
    else
    {
        screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
        if(screen == NULL)
            std::cout << "SDL ERROR: Window creation: " << SDL_GetError() << std::endl;
        else
        {
            SDL_Delay(2000);
        }
    }
    
    SDL_Quit();
    
    return 0;
    
}
