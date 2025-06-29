#pragma once

#include <GLFW/glfw3.h>

#include "common/Constants.hpp"
#include "common/Size.hpp"

#include "core/Camera2D.hpp"
#include "core/Field.hpp"

#include "simulation/Motion.hpp"

namespace Application {

    inline auto gravity = [](Particle& particle, float) {
        particle.addForce(Constants::GRAVITY * particle.getMass() * Vector3{0, -1, 0});
    };

    inline GLFWwindow* window = nullptr;
    inline Size screenSize = Size(Constants::DEFAULT_SCREEN_WIDTH, Constants::DEFAULT_SCREEN_HEIGHT);
    
    inline Vector3 centerOffset = Vector3(-screenSize.width / 2.0f, -screenSize.height / 2.0f, 0.0f);

    inline Field field{centerOffset, screenSize};
    inline Camera2D camera(&field, screenSize);

    inline simulation::Motion motion(
        200,     // particles
        field,   // world reference
        gravity, // choose any ForceFunc
        0.8f);   // restitution

    bool initialize();
    void update(float dt);
    void render();
    void cleanup();
}
