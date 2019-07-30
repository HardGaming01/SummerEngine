set(SRC main.cpp)

add_executable(test ${SRC})
target_link_libraries(test SumEngine)

file(COPY Shaders
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
