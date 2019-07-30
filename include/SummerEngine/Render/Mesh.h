#ifndef SUMMERENGINE_MESH_H
#define SUMMERENGINE_MESH_H

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <SummerEngine/Render/Shader.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

namespace SE
{

struct Vertex
{
    //Data
    glm::vec3 position;
    glm::vec2 texCoords;
    glm::vec3 color = glm::vec3(0, 1, 0);

    //Constructor
    Vertex(float x, float y, float u, float v);
    Vertex(float x, float y, float z, float u, float v);
};

struct Texture
{
    //Data
    unsigned int id;
    string type;
    string path;

    //Constructor
    Texture(const char *path, const string &directory, bool gamma);
};

class Mesh
{
public:
    //Data
    vector<Vertex> vertices;
    vector<unsigned int> indices;
    vector<Texture> textures;
    unsigned int VAO;

    //Functions
    Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);

    void Draw(Shader shader);

private:
    //Data
    unsigned int VBO, EBO;

    //Functions
    void setupMesh();
};

}

#endif //SUMMERENGINE_MESH_H
