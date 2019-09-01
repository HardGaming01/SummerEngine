#include "SummerEngine/System.h"

#include <iostream>

#include <SDL2/SDL.h>
#include <glad/glad.h>

using namespace SE;

System::System(unsigned height, unsigned width):
window(), glContext()
{
    SCR_HEIGHT = height;
    SCR_WIDTH = width;
}

void System::startUp()
{
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        error("Couldn't initialize SDL");
    atexit (SDL_Quit);

    // Context Setup
    SDL_GL_LoadLibrary(nullptr);

    // Request an OpenGL 3.3 context (should be core)
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    // Also request a depth buffer
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    // Create Window
    window = SDL_CreateWindow(
        "LearnOpenGL_SDL",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCR_WIDTH, SCR_HEIGHT, SDL_WINDOW_OPENGL
    );
    if (window == nullptr) error("Couldn't set video mode");

    // Create Context
    glContext = SDL_GL_CreateContext(window);
    if (glContext == nullptr) error("Failed to create OpenGL Context");

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader(SDL_GL_GetProcAddress))
    {
        error("Failed to initialize GLAD");
    }
    std::cout<<"Vendor:    "<<glGetString(GL_VENDOR)<<std::endl;
    std::cout<<"Renderer:  "<<glGetString(GL_RENDERER)<<std::endl;
    std::cout<<"Version:   "<<glGetString(GL_VERSION)<<std::endl;

    // Use v-sync
    SDL_GL_SetSwapInterval(-1);
    //SDL_SetRelativeMouseMode(SDL_TRUE);

    // Disable depth test and face culling.
    glDisable(GL_CULL_FACE);

    // Enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    int w,h;
    SDL_GetWindowSize(window, &w, &h);
    glViewport(0, 0, w, h);
    glClearColor(0.4f, 0.7f, 1.0f, 0.0f);
}

void System::shutDown()
{

}

void System::update()
{

}

void System::error(const char *message)
{
    std::cerr << message << ": " << SDL_GetError() << std::endl;
    exit(2);
}
