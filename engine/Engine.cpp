#include "SummerEngine/Engine.h"


SE::Engine::Engine(unsigned height, unsigned width):
system(height, width)
{

}
void SE::Engine::run()
{
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

        system.update();
    }
    system.shutDown();
}
