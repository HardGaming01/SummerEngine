#include "SummerEngine/Render.h"

using namespace SE;
void Render::startUp()
{
    shader = new Shader("Shaders/shader.vs", "Shaders/shader.fs");
}
void Render::update()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shader->use();

    for (auto i = std::begin(meshes); i != std::end(meshes); ++i)
    {
        i->Draw(*shader);
    }

    SDL_GL_SwapWindow(system->window);
}
void Render::shutDown()
{
    delete shader;
}
void Render::addMesh(Mesh &mesh)
{
    meshes.push_back(mesh);
}

Render::Render(SE::System &_system)
{
    system = &_system;
}
