#ifndef SCENE_H
#define SCENE_H

#include <SummerEngine/Module.h>

namespace SE
{

class Engine;

class Scene : public Module
{
public:
    explicit Scene(Engine * engine);

    void startUp() override;
    void update() override;
    void shutDown() override;

    Engine * engine;
};

}

#endif //SCENE_H
