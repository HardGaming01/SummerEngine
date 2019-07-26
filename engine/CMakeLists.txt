
set(SRC Engine.cpp System.cpp Render/Mesh.cpp Render/Shader.cpp)

add_library(SumEngine STATIC ${SRC})

target_link_libraries(SumEngine ${SDL2_LIBRARIES} GLAD)
