#ifndef SUMMERENGINE_RENDER_H
#define SUMMERENGINE_RENDER_H

#include <SummerEngine/Module.h>
#include <SummerEngine/System.h>
#include <SummerEngine/Render/Mesh.h>
#include <SummerEngine/Render/Shader.h>
#include <SummerEngine/Render/Texture.h>
#include <SummerEngine/Render/Model.h>

#include <vector>

namespace SE
{
class Render: public Module
{
public:
    explicit Render(System& _system);
    void startUp() override;
    void update() override;
    void shutDown() override;

    void addMesh(Mesh &mesh);
    void addModel(Model & model);
    Mesh * getMesh(int index);

    Shader* shader;

private:
    vector<Mesh> meshes;
    vector<Model> models;
    System* system;
};
}

#endif //SUMMERENGINE_RENDER_H
