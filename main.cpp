#include <SDL/SDL.h>
#include <iostream>

SDL_Surface * init(unsigned width, unsigned height, unsigned color)
{
    SDL_Surface *screen;
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
        std::cout << "SDL ERROR: Video initialization: " << SDL_GetError() << std::endl;
    else
    {
        screen = SDL_SetVideoMode(width, height, color, SDL_SWSURFACE);
        if(screen == NULL)
            std::cout << "SDL ERROR: Window creation: " << SDL_GetError() << std::endl;
        else
        {
            return screen;
        }
    }
}
 

void mainLoop()
{
    bool active = true; // Window is not minimized

    for(;;)
    {
        SDL_Event event;

        //if(SDL_WaitEvent(&event) == 0) throw SDL_Exception();

        bool redraw = false; // Screen needs redraw
        
        do // Handle events
        {
            switch(event.type)
            {
                case SDL_ACTIVEEVENT : // Stop redraw when minimized
                    if(event.active.state == SDL_APPACTIVE)
                        active = event.active.gain;
                    break;
                case SDL_KEYDOWN :
                    std::cout << "KEY DOWN" << std::endl;
                    break;
                case SDL_KEYUP :
                    std::cout << "KEY UP" << std::endl;
                    break;
                case SDL_MOUSEMOTION :
                    std::cout << "MOUSE MOTION " << event.motion.x << " + " << event.motion.y << " + " << event.motion.xrel << " + " << event.motion.yrel << " + " << event.motion.state << std::endl;
                    break;
                case SDL_MOUSEBUTTONDOWN :
                    std::cout << "MOUSE BUTTON DOWN " << event.button.button << " + " << event.button.x << " + " << event.button.y << std::endl;
                    break;
                case SDL_MOUSEBUTTONUP :
                    std::cout << "MB UP" << std::endl;
                    break;
                case SDL_QUIT :
                    return; // End main loop
                case SDL_VIDEORESIZE :
                    // onWindowResized(event.resize.w, event.resize.h);
                    break;
                case SDL_VIDEOEXPOSE :
                    redraw = true;
                    break;
                default :
                    break;
            }
        } while(SDL_PollEvent(&event) == 1);

        // Optionally redraw window
        //if(active && redraw) onWindowRedraw();
    }
}    

int main(int argc, char *argv[])
{
    init(640, 480, 32);
    
    mainLoop();
    
    atexit(SDL_Quit);
    
    return 0;
    
}
