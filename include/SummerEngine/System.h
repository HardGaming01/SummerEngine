#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL2/SDL.h>
#include "Module.h"

namespace SE
{
class System: public Module
{
public:
    System(unsigned height, unsigned width);

    void startUp() override;
    void shutDown() override;
    void update() override;

    void error(const char *message);

    SDL_Window *window;
    SDL_GLContext glContext;

private:
    unsigned int SCR_WIDTH = 800;
    unsigned int SCR_HEIGHT = 800;
};
}

#endif //SYSTEM_H
