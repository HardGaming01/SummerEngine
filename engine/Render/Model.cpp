#include <SummerEngine/Module.h>
#include <SummerEngine/Render/Model.h>


using namespace SE;


void Model::addMesh(Mesh &mesh)
{
    meshes.emplace_back(mesh);
}

void Model::Draw()
{
    for (auto i = std::begin(meshes); i != std::end(meshes); ++i)
    {
        i->Draw();
    }
}
