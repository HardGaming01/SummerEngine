
set(SRC Engine.cpp System.cpp Rendering/Renderer.cpp ../include/SummerEngine/Manager.h)

add_library(SumEngine STATIC ${SRC})

target_link_libraries(SumEngine ${SDL2_LIBRARIES} ${SDL2_image_LIBRARIES})
