#ifndef MODEL_H
#define MODEL_H

#include <SummerEngine/Render/Mesh.h>
#include <SummerEngine/Component.h>

#include <vector>

namespace SE
{

class Model : public Component
{
public:
    vector<Mesh> meshes;

    void addMesh(Mesh &mesh);
    void Draw();
};

}

#endif //MODEL_H
