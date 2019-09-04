#ifndef SPINE_H
#define SPINE_H

#include <spine/spine.h>

#include <SummerEngine/Render/Shader.h>

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

void DrawSkeleton(Skeleton * skeleton);

}

#endif //SPINE_H
