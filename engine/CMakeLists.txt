
set(SRC Engine.cpp System.cpp Render.cpp Scene.cpp Render/Mesh.cpp Render/Shader.cpp  Render/Spine.cpp Render/Texture.cpp ../include/SummerEngine/Render/Model.h Render/Model.cpp)

add_library(SumEngine STATIC ${SRC})

target_link_libraries(SumEngine ${SDL2_LIBRARIES} GLAD spine)
