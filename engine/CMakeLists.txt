
set(SRC Engine.cpp System.cpp Render/Mesh.cpp Render/Shader.cpp Render.cpp Animation/Spine.cpp Render/Texture.cpp Scene.cpp)

add_library(SumEngine STATIC ${SRC})

target_link_libraries(SumEngine ${SDL2_LIBRARIES} GLAD)
