#ifndef SUMMERENGINE_RENDER_H
#define SUMMERENGINE_RENDER_H

#include "Module.h"
#include "System.h"
#include "SummerEngine/Render/Mesh.h"
#include "SummerEngine/Render/Shader.h"

#include <vector>

namespace SE
{
class Render: public Module
{
public:
    Render(System& _system);
    void startUp() override;
    void update() override;
    void shutDown() override;

    void addMesh(Mesh &mesh);

private:
    vector<Mesh> meshes;
    Shader* shader;
    System* system;
};
}

#endif //SUMMERENGINE_RENDER_H
