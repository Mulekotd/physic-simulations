#pragma once

#include <GLFW/glfw3.h>

#include "common/Constants.hpp"
#include "common/Dimensions.hpp"

#include "core/Field.hpp"
#include "core/Camera2D.hpp"

#include "simulation/ForceFunctions.hpp"
#include "simulation/Motion.hpp"

namespace Application {

    inline GLFWwindow* window = nullptr;
    inline Dimensions screenSize = Dimensions(Constants::Window::DEFAULT_WIDTH, Constants::Window::DEFAULT_HEIGHT);

    inline Field world(screenSize);
    inline Camera2D camera(world);

    inline simulation::Motion motion(
        200,                             // particle count (TODO: Make this configurable)
        world);                          // world reference

    bool initialize();
    void update(float dt);
    void render();
    void tick(float dt);
    void cleanup();
}
