#include <SummerEngine/Render.h>

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
        i->Draw();
    }
    for (auto i = std::begin(models); i != std::end(models); ++i)
    {
        i->Draw();
    }

    SDL_GL_SwapWindow(system->window);
}
void Render::shutDown()
{
    delete shader;
}
void Render::addMesh(Mesh &mesh)
{
    meshes.emplace_back(mesh);
}
void Render::addModel(Model &model)
{
    models.emplace_back(model);
}

Render::Render(SE::System &_system):
shader()
{
    system = &_system;
}
Mesh * Render::getMesh(int index)
{
    return &meshes[index];
}
