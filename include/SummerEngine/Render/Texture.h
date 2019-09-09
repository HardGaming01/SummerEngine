#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <vector>
#include <SummerEngine/Component.h>

using namespace std;

namespace SE
{

class Texture
{
public:
    //Data
    unsigned int id{};
    int width{};
    int height{};
    string type;
    string path;

    //Constructor
    Texture(const char *path);
};

class TextureManager
{
public:
    vector<Texture> textures;
};

}

#endif //TEXTURE_H
