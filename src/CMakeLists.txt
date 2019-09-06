add_executable(test test/main.cpp test/Scene.cpp)
add_executable(spineTest test/main.cpp spineTest/Scene.cpp)
target_link_libraries(test SumEngine)
target_link_libraries(spineTest SumEngine)

file(COPY ../Assets/Shaders
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ../Assets/Textures
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ../Assets/Animation
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
