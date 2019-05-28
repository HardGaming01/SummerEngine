cmake_minimum_required(VERSION 3.0)

project(SummerEngine)

# Find required packages
find_package(SDL2 REQUIRED)
find_package(GLM REQUIRED)

if (MSVC)
    find_path(SDL2_INCLUDE_DIR SDL2/SDL.h)
endif ()

include_directories(include)
include_directories(${SDL2_INCLUDE_DIR})
include_directories(${GLM_INCLUDE_DIR})

# Add the subdirectories

add_subdirectory(lib)
add_subdirectory(engine)
add_subdirectory(src)
