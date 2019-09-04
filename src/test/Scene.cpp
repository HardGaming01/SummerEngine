#include <SDL2/SDL.h>
#include <SummerEngine/Engine.h>

using namespace SE;

Texture * textureFace;
Texture * textureWall;

float degree = 0;

void SE::Scene::startUp()
{
    //Test Code
    vector<Vertex> vertices;
    vertices.emplace_back(Vertex(0.5, 0.5, 1.0, 0.0));
    vertices.emplace_back(Vertex(0.5, -0.5, 1.0, 1.0));
    vertices.emplace_back(Vertex(-0.5, -0.5, 0.0, 1.0));
    vertices.emplace_back(Vertex(-0.5, 0.5, 0.0, 0.0));

    vector<unsigned > indicies;
    indicies.emplace_back(0);
    indicies.emplace_back(1);
    indicies.emplace_back(3);
    indicies.emplace_back(1);
    indicies.emplace_back(2);
    indicies.emplace_back(3);

    textureFace = new Texture("./Textures/awesomeface.png");
    textureWall = new Texture("./Textures/wall.jpg");

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, textureFace->id);
    engine->render.shader->setInt("texture1", 1);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureWall->id);
    engine->render.shader->setInt("texture2", 0);

    Mesh mesh = Mesh(vertices, indicies, textureWall->id);

    engine->render.addMesh(mesh);
    engine->render.shader->setFloat("degree", degree);
}

void SE::Scene::update()
{

    if(engine->keystate[SDL_SCANCODE_LEFT])
    {
        Mesh * mesh = engine->render.getMesh(0);
        if (mesh->vertices[0].position.x <= 0.75)
        {
            mesh->vertices[0].position.x += 0.005;
        }
        if (degree <= 1.0)
        {
            degree += 0.01;
        }
        //mesh->textureID = textureFace->id;
        mesh->Update();
    }
    if(engine->keystate[SDL_SCANCODE_RIGHT])
    {
        Mesh * mesh = engine->render.getMesh(0);
        if (mesh->vertices[0].position.x >= 0.5)
        {
            mesh->vertices[0].position.x -= 0.005;
        }
        if (degree >= 0.0)
        {
            degree -= 0.01;
        }
        //mesh->textureID = textureWall->id;
        mesh->Update();
    }
    engine->render.shader->setFloat("degree", degree);
    //quit input end
}

void SE::Scene::shutDown()
{
    delete textureFace;
    delete textureWall;
}

