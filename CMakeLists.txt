cmake_minimum_required(VERSION 3.8)
project(RG165_bethebachelor)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/main.cpp
        src/light.hpp
        src/light.cpp
        src/draw.hpp
        src/draw.cpp
        Makefile
        README.md
        src/camera.cpp
        src/camera.hpp
        src/callbackfuncs.cpp
        src/callbackfuncs.h)

link_libraries(GL)
link_libraries(GLU)
link_libraries(glut)

add_executable(RG165_bethebachelor ${SOURCE_FILES})