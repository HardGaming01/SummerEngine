#ifndef SPINE_H
#define SPINE_H

#include <spine/TextureLoader.h>
#include <spine/Skeleton.h>

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

void DrawSkeleton(Skeleton * skeleton, Shader shader);

}

#endif //SPINE_H
