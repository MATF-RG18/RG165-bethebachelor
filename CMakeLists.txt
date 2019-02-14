cmake_minimum_required(VERSION 3.8)
project(RG165_bethebachelor)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.c
        Makefile
        README.md)

link_libraries(GL)
link_libraries(GLU)
link_libraries(glut)

add_executable(RG165_bethebachelor ${SOURCE_FILES})