#pragma once

#include <GLFW/glfw3.h>

#include "common/Constants.hpp"
#include "common/Size.hpp"

#include "core/Camera2D.hpp"
#include "core/Field.hpp"

#include "simulation/Motion.hpp"

namespace Application {
    inline GLFWwindow* window = nullptr;
    inline Size windowSize = Size(Constants::DEFAULT_SCREEN_WIDTH, Constants::DEFAULT_SCREEN_HEIGHT);
    
    inline Vector3 centerOffset = Vector3(-windowSize.width / 2.0f, -windowSize.height / 2.0f, 0.0f);

    inline Field field{centerOffset, windowSize};
    inline Camera2D camera(&field, field.getSize());

    inline simulation::Motion motion(200, simulation::Law::Third);

    bool initialize();
    void update(float dt);
    void render();
    void cleanup();
}
