#pragma once

#include <cmath>

namespace Constants {
    // Gravitational acceleration (m/s²)
    inline constexpr float GRAVITY = 9.81f;

    // Circle drawing (OpenGL, UI, particles etc.)
    inline constexpr int   CIRCLE_SEGMENTS = 12;
    inline constexpr float THETA_STEP = 2.0f * static_cast<float>(M_PI) / CIRCLE_SEGMENTS;

    // Zoom limits
    inline constexpr float ZOOM_MIN = 0.1f;
    inline constexpr float ZOOM_MAX = 10.0f;
}
