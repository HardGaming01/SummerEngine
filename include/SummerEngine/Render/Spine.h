#ifndef SPINE_H
#define SPINE_H

#include <spine/spine.h>

#include <SummerEngine/Render/Shader.h>
#include <SummerEngine/Render/Model.h>

using namespace spine;

namespace SE
{

class SummerEngineTextureLoader: public TextureLoader
{
public:
    SummerEngineTextureLoader();
    ~SummerEngineTextureLoader() override;

    void load(AtlasPage & page, const String& path) override;
    void unload(void * texture) override;
};

Model * SetupSkeleton(Skeleton *skeleton);

}

#endif //SPINE_H
