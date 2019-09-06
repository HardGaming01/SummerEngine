#include <SummerEngine/Render/Texture.h>
#include <SummerEngine/Render/Spine.h>
#include <SummerEngine/Render/Mesh.h>

#include <spine/spine.h>

using namespace spine;
using namespace SE;

SpineExtension * spine::getDefaultExtension()
{
    return new spine::DefaultSpineExtension();
}

SummerEngineTextureLoader::SummerEngineTextureLoader()
= default;
SummerEngineTextureLoader::~SummerEngineTextureLoader()
= default;

void SummerEngineTextureLoader::load(AtlasPage& page, const String &path)
{
    auto * texture = new Texture(path.buffer());

    page.setRendererObject(texture);

    page.width = texture->width;
    page.height = texture->height;
}
void SummerEngineTextureLoader::unload(void *texture)
{
    auto * trueTexture = (Texture *) texture;
    delete trueTexture;
}
void SE::DrawSkeleton(Skeleton *skeleton)
{
    size_t n = skeleton->getSlots().size();
    for (int i = 0; i < n ; ++i)
    {
        // Get Slot with draw order
        Slot * slot = skeleton->getDrawOrder()[i];

        //Get the attachment, skip if no attachment
        Attachment* attachment = slot->getAttachment();
        if (!attachment) continue;

        //Get and set Engine Blend Mode
        switch (slot->getData().getBlendMode())
        {
        case BlendMode_Normal:
            break;
        case BlendMode_Additive:
            break;
        case BlendMode_Multiply:
            break;
        case BlendMode_Screen:
            break;
        default:
            break;
        }

        // Calculate tinting Color
        Color skeletonColor = skeleton->getColor();
        Color slotColor = slot->getColor();
        Color tint(skeletonColor.r * slotColor.r, skeletonColor.g * slotColor.g, skeletonColor.b * slotColor.b, skeletonColor.a * slotColor.a);

        //Load in Data
        Texture * texture = nullptr;
        vector<unsigned > indices = {0, 1, 3, 1, 2, 3};
        vector<Vertex> vertices;

        //For Regional attachment
        if (attachment->getRTTI().isExactly(RegionAttachment::rtti))
        {
            // Cast to a region attachment
            auto * regionAttachment = (RegionAttachment*) attachment;
            texture = (Texture *) ((AtlasRegion *) regionAttachment->getRendererObject())->page->getRendererObject();

            for (int j = 0; j < 4; ++j)
            {
                vertices.emplace_back(Vertex());
            }

            // Compute world vertices positions
            regionAttachment->computeWorldVertices(slot->getBone(), (float *)&vertices[0], 0, 9);

            for (size_t j = 0, l = 0; j < 4 ; ++j, l += 2)
            {
                Vertex & vertex = vertices[j];
                vertex.position *= 0.01;

                vertex.color[0] = tint.r;
                vertex.color[1] = tint.g;
                vertex.color[2] = tint.b;
                vertex.color[3] = tint.a;

                vertex.texCoords[0] = regionAttachment->getUVs()[l];
                vertex.texCoords[1] = regionAttachment->getUVs()[l+1];
            }
        }
        Mesh mesh = Mesh(vertices, indices, texture->id);
        mesh.Draw();
    }
}
