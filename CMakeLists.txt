cmake_minimum_required(VERSION 3.14)          # 3.14+ for FetchContent
project(physics-simulation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Prefer modern GLVND on Linux
cmake_policy(SET CMP0072 NEW)

# --------------------------------------------------------------------------- #
# 1.  Source files
# --------------------------------------------------------------------------- #
file(GLOB_RECURSE SRC CONFIGURE_DEPENDS
     ${CMAKE_SOURCE_DIR}/src/*.cpp
     ${CMAKE_SOURCE_DIR}/main.cpp)

add_executable(${PROJECT_NAME} ${SRC})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

# --------------------------------------------------------------------------- #
# 2.  OpenGL
# --------------------------------------------------------------------------- #
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL)

# --------------------------------------------------------------------------- #
# 3.  GLFW  ── system on Linux, FetchContent elsewhere
# --------------------------------------------------------------------------- #
set(GLFW_TARGET glfw)

if (UNIX AND NOT APPLE)                  # Linux
    find_package(PkgConfig REQUIRED)
    pkg_search_module(GLFW3 glfw3)
endif()

if (GLFW3_FOUND)
    target_include_directories(${PROJECT_NAME} PRIVATE ${GLFW3_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME}  PRIVATE ${GLFW3_LIBRARIES})
else()                                   # Windows / macOS / fallback
    include(FetchContent)
    FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG        3.3.8
    )
    FetchContent_MakeAvailable(glfw)
    target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
endif()

# --------------------------------------------------------------------------- #
# 4.  GLAD 2.x (modern OpenGL loader)
# --------------------------------------------------------------------------- #
# include(FetchContent)
# FetchContent_Declare(
#     glad
#     GIT_REPOSITORY  https://github.com/Dav1dde/glad.git
#     GIT_TAG         v2.0.5            # stable tag
# )
# FetchContent_MakeAvailable(glad)

# target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad)

# --------------------------------------------------------------------------- #
# 5.  Dear ImGui (static library) – assumes git submodule in external/imgui
# --------------------------------------------------------------------------- #
# set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/external/imgui)

# file(GLOB IMGUI_SRC
#      ${IMGUI_DIR}/*.cpp
#      ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
#      ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp)

# add_library(imgui STATIC ${IMGUI_SRC})
# target_include_directories(imgui PUBLIC
#     ${IMGUI_DIR}
#     ${IMGUI_DIR}/backends)

# target_link_libraries(imgui PUBLIC glfw OpenGL::GL)
# target_link_libraries(${PROJECT_NAME} PRIVATE imgui)

# --------------------------------------------------------------------------- #
# 6.  Extra platform‑specific libraries
# --------------------------------------------------------------------------- #
if (UNIX AND NOT APPLE)                  # Linux extra libs
    target_link_libraries(${PROJECT_NAME} PRIVATE dl m)
endif()

if (APPLE)                               # macOS frameworks
    find_library(COCOA_LIBRARY     Cocoa     REQUIRED)
    find_library(IOKIT_LIBRARY     IOKit     REQUIRED)
    find_library(COREVIDEO_LIBRARY CoreVideo REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        ${COCOA_LIBRARY} ${IOKIT_LIBRARY} ${COREVIDEO_LIBRARY})
endif()
