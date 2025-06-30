#pragma once

#include <cmath>

namespace Constants {

    // Physics
    // Gravitational acceleration (m/s²)
    inline constexpr float GRAVITY = 9.81f;
    inline constexpr float COEFFICIENT_OF_RESTITUTION = 0.8f;

    // Math
    inline constexpr float PI = static_cast<float>(M_PI);
    inline constexpr float EPSILON = 1e-5f;

    inline constexpr float MIN_RANDOM_POS = -25.f;
    inline constexpr float MAX_RANDOM_POS =  25.f;

    inline constexpr float MIN_RANDOM_VEL =  0.f;
    inline constexpr float MAX_RANDOM_VEL =  10.f;

    inline constexpr float MIN_RANDOM_MASS = 250.f;
    inline constexpr float MAX_RANDOM_MASS = 2'000.f;

    // Zoom limits
    inline constexpr float ZOOM_MIN = 0.1f;
    inline constexpr float ZOOM_MAX = 10.0f;

    // Screen size
    inline constexpr int   DEFAULT_SCREEN_WIDTH = 800;
    inline constexpr int   DEFAULT_SCREEN_HEIGHT = 600; 
}
