#ifndef ENGINE_H
#define ENGINE_H

#include "System.h"
#include "Render.h"
#include "Scene.h"

namespace SE
{
class Engine
{
public:
    //Functions
    Engine(unsigned height, unsigned width);
    void run();

    //Module
    System system;
    Render render;

private:
    //Module
    Scene scene;

    //Variable
    bool quit = false;
    SDL_Event event;
};

}

#endif //ENGINE_H
