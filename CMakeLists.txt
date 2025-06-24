cmake_minimum_required(VERSION 3.10)
project(physic-simulation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use modern OpenGL preference (GLVND)
cmake_policy(SET CMP0072 NEW)

# Recursively search for source files
file(GLOB_RECURSE SOURCES src/*.cpp main.cpp)

# Create the executable first
add_executable(physic-simulation ${SOURCES})

# Now add include directories
target_include_directories(physic-simulation PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Find required libraries
find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

# Link libraries
target_link_libraries(physic-simulation ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES} dl m)
