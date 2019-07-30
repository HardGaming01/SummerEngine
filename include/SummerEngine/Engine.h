#ifndef ENGINE_H
#define ENGINE_H

#include "System.h"
#include "Render.h"

namespace SE
{
class Engine
{
public:
    Engine(unsigned height, unsigned width);
    void run();

    System system;
    Render render;

private:
    bool quit = false;
    SDL_Event event;
};

}

#endif //ENGINE_H
