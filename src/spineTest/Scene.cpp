#include <SDL2/SDL.h>
#include <SummerEngine/Render/Spine.h>
#include <SummerEngine/Engine.h>
#include <glm/glm.hpp>

using namespace SE;
using namespace spine;

TextureLoader * textureLoader;
Atlas * atlas;
SkeletonData * skeletonData;
AnimationStateData * animationStateData;

Skeleton * skeleton;

Mesh mesh;

void Scene::startUp()
{
    // Setup texture loader and atlas
    textureLoader = new SummerEngineTextureLoader;
    atlas = new Atlas("./Animation/spineboy/export/spineboy.atlas", textureLoader);

    //Setup Skeleton Data
    SkeletonBinary binary(atlas);
    binary.setScale(2);
    skeletonData = binary.readSkeletonDataFile("./Animation/spineboy/export/spineboy-ess.skel");
    if (!skeletonData)
    {
        printf("%s\n", binary.getError().buffer());
        exit(0);
    }

    //Setup Animation state data.
    animationStateData = new AnimationStateData(skeletonData);
    animationStateData->setDefaultMix(0.1f);
    animationStateData->setMix("jump", "walk", 0.2f);

    skeleton = new Skeleton(skeletonData);

    Model * model = SetupSkeleton(skeleton);
    engine->render.addModel(*model);
}

void Scene::update()
{
    //mesh.Draw();
}

void Scene::shutDown()
{
}
