cmake_minimum_required(VERSION 3.0)

project(SummerEngine)

if (MSVC)
    find_path(SDL2_INCLUDE_DIR SDL2/SDL.h)
endif ()

if(MINGW)
    add_compile_options(-lmingw)
endif(MINGW)

include_directories(include)

# Add the subdirectories
add_subdirectory(lib)
add_subdirectory(engine)
add_subdirectory(src)
