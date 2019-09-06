#include <SummerEngine/Render/Mesh.h>

using namespace SE;

Mesh::Mesh(vector<Vertex> vertices, vector<unsigned int> indices, unsigned int textureID):
vertices(std::move(vertices)), indices(std::move(indices)), textureID(textureID)
{
    setupMesh();
}

void Mesh::Draw()
{
    // Setup texture
    //glBindTexture(GL_TEXTURE_2D, textureID);

    // draw mesh
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
}

void Mesh::setupMesh()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()* sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoords));

    glBindVertexArray(0);
}
void Mesh::Update()
{
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    void * ptr = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
    memcpy(ptr, &vertices[0], vertices.size() * sizeof(Vertex));
    glUnmapBuffer(GL_ARRAY_BUFFER);
}

Vertex::Vertex()
= default;

Vertex::Vertex(float x, float y, float u, float v):
position(x, y, 0.0f), texCoords(u, v)
{
}
Vertex::Vertex(float x, float y, float z, float u, float v):
position(x, y, z), texCoords(u, v)
{
}
Vertex::Vertex(float x, float y, float z, float u, float v, float r, float g, float b, float a):
position(x, y, z), color(r, g, b, a), texCoords(u, v)
{
}
