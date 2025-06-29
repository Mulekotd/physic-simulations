#pragma once

#include <cmath>

namespace Constants {
    // Gravitational acceleration (m/s²)
    inline constexpr float GRAVITY = 9.81f;

    // Circle drawing (OpenGL, UI, particles etc.)
    inline constexpr int   CIRCLE_SEGMENTS = 12;
    inline constexpr float THETA_STEP = 2.0f * static_cast<float>(M_PI) / CIRCLE_SEGMENTS;

    // Math
    inline constexpr float EPSILON = 1e-5f;

    // Zoom limits
    inline constexpr float ZOOM_MIN = 0.1f;
    inline constexpr float ZOOM_MAX = 10.0f;

    // Screen size
    inline constexpr int   DEFAULT_SCREEN_WIDTH = 800.f;
    inline constexpr int   DEFAULT_SCREEN_HEIGHT = 600.f; 
}
