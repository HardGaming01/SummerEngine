#include "SummerEngine/Engine.h"

#include <vector>

using namespace SE;

Engine::Engine(unsigned height, unsigned width):
system(height, width), render(system),scene(this), event()
{

}

void Engine::run()
{
    //Module Startups
    system.startUp();
    render.startUp();
    scene.startUp();

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

        //Module Updates
        system.update();
        render.update();
        scene.update();
    }
    //Module
    scene.shutDown();
    render.shutDown();
    system.shutDown();
}
