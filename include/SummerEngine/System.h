#include <SDL2/SDL.h>
#include "Module.h"

#ifndef SYSTEM_H
#define SYSTEM_H

namespace SE
{
class System : public Module
{
public:
    System(unsigned height, unsigned width);

    void startUp() override ;
    void shutDown() override ;
    void update() override ;
    void error(const char * message);

private:
    unsigned int SCR_WIDTH = 800;
    unsigned int SCR_HEIGHT = 600;

    static SDL_Window * window;
    static SDL_GLContext glContext;
};
}

#endif //SYSTEM_H
