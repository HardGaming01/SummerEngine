//
// Created by Buster on 2019/7/9.
//
#include "System.h"

#ifndef ENGINE_H
#define ENGINE_H

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
