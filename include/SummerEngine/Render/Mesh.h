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
    glm::vec3 position{};
    glm::vec4 color = glm::vec4(1.0f, 1.0f, 1.0f, 0.8f);
    glm::vec2 texCoords{};

    //Constructor
    Vertex();
    Vertex(float x, float y, float u, float v);
    Vertex(float x, float y, float z, float u, float v);
    Vertex(float x, float y, float z, float u, float v, float r, float g, float b, float a);
};

class Mesh
{
public:
    //Data
    vector<Vertex> vertices;
    vector<unsigned int> indices;
    unsigned int textureID{};
    unsigned int VAO{};

    //Functions
    Mesh() = default;
    Mesh(vector<Vertex> vertices, vector<unsigned int> indices, unsigned int textureID);

    void Draw();
    void Update();

private:
    //Data
    unsigned int VBO{}, EBO{};

    //Functions
    //Mesh(const Mesh & mesh);

    void setupMesh();
};

Mesh quadMesh();

}

#endif //SUMMERENGINE_MESH_H
