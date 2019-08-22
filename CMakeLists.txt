cmake_minimum_required(VERSION 3.8)
project(RG165_bethebachelor)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/main.cpp
        src/light.hpp
        src/light.cpp
        src/figure.hpp
        src/figure.cpp
	src/image.cpp
	src/image.hpp
        src/camera.cpp
        src/camera.hpp
        src/callbackfuncs.cpp
        src/callbackfuncs.hpp
        src/boban.hpp
        src/boban.cpp
		src/functions.hpp
		src/functions.cpp)

link_libraries(GL)
link_libraries(GLU)
link_libraries(glut)

add_executable(RG165_bethebachelor ${SOURCE_FILES})
