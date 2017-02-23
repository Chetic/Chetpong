cmake_minimum_required(VERSION 3.6)
project(Pong)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp loadShaders.cpp)
add_executable(Pong ${SOURCE_FILES})

find_package(OpenGL REQUIRED)

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})
target_link_libraries(Pong ${GLEW_LIBRARIES} GLEW)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})
target_link_libraries(Pong ${GLFW_STATIC_LIBRARIES})
