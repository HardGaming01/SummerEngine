#include "SummerEngine/Engine.h"

using namespace SE;

Engine::Engine(unsigned height, unsigned width):
system(height, width),event()
{

}

void Engine::run()
{
    const Uint8 * keystate;
    system.startUp();

    // Main loop
    while (!quit)
    {
        // Event handling
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        //quit input handling
        //Get Keyboard input
        keystate = SDL_GetKeyboardState(nullptr);
        if (keystate[SDL_SCANCODE_ESCAPE])
        {
            SDL_Event quit;
            quit.type = SDL_QUIT;
            SDL_PushEvent(&quit);
        }
        //quit input end

        system.update();
    }
    system.shutDown();
}
