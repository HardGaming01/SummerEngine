#include "SummerEngine/Engine.h"

#include <vector>

using namespace SE;

Engine::Engine(unsigned height, unsigned width):
system(height, width), render(system)
{

}

void Engine::run()
{
    const Uint8 * keystate;

    //Module Startups
    system.startUp();
    render.startUp();

    //Test Code
    vector<Vertex> vertices;
    vertices.emplace_back(Vertex(0.5, 0.5, 1.0, 1.0));
    vertices.emplace_back(Vertex(0.5, -0.5, 1.0, 0.0));
    vertices.emplace_back(Vertex(-0.5, -0.5, 0.0, 0.0));
    vertices.emplace_back(Vertex(-0.5, 0.5, 0.0, 1.0));

    vector<unsigned > indicies;
    indicies.emplace_back(0);
    indicies.emplace_back(1);
    indicies.emplace_back(3);
    indicies.emplace_back(1);
    indicies.emplace_back(2);
    indicies.emplace_back(3);

    vector<Texture> textures;
    textures.emplace_back(Texture("Textures/wall.jpg", ".", true));

    Mesh mesh(vertices, indicies, textures);

    render.addMesh(mesh);

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
            SDL_Event quitEvent;
            quitEvent.type = SDL_QUIT;
            SDL_PushEvent(&quitEvent);
        }
        //quit input end

        //Module Updates
        system.update();
        render.update();
    }
    //Module
    system.shutDown();
    render.shutDown();
}
