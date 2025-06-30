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

    inline Field field(screenSize);
    inline Camera2D camera(field);

    inline simulation::Motion motion(
        200,                             // particles (TODO: Make this configurable)
        field,                           // world reference
        simulation::forces::gravity());  // ForceFunc

    bool initialize();
    void update(float dt);
    void render();
    void tick(float dt);
    void cleanup();
}
