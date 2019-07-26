#ifndef ENGINE_H
#define ENGINE_H

#include "System.h"

namespace SE
{
class Engine
{
public:
    Engine(unsigned height, unsigned width);
    void run();

private:
    bool quit = false;
    SDL_Event event;

    System system;
};

}

#endif //ENGINE_H
