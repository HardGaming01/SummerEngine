#include <SDL2/SDL.h>
#include <SummerEngine/Engine.h>

using namespace SE;

Texture * textureFace;
Texture * textureWall;

float degree = 0;

void SE::Scene::startUp()
{
    textureFace = new Texture("./Textures/awesomeface.png");
    textureWall = new Texture("./Textures/wall.jpg");

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, textureFace->id);
    engine->render.shader->setInt("texture1", 1);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureWall->id);
    engine->render.shader->setInt("texture2", 0);

    Mesh mesh = quadMesh();
    mesh.textureID = textureFace->id;

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
        mesh->textureID = textureFace->id;
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
        mesh->textureID = textureWall->id;
        mesh->Update();
    }
    engine->render.shader->setFloat("degree", degree);
}

void SE::Scene::shutDown()
{
    delete textureFace;
    delete textureWall;
}

