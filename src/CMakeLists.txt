set(SRC main.cpp Scene.cpp)

add_executable(test ${SRC})
target_link_libraries(test SumEngine)

file(COPY Shaders
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY Textures
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
