#pragma once

namespace Constants {

    namespace Physics {
        inline constexpr float GRAVITY = 9.81f; // Gravitational acceleration (m/s²)
        inline constexpr float RESTITUTION_COEFFICIENT = 0.8f; // Coefficient of restitution (elasticity)
        inline constexpr float DYNAMIC_FRICTION_COEFFICIENT = 0.05f; // Coefficient of dynamic friction
    }

    namespace Math {
        inline constexpr float PI = 3.14159265358979323846f;
        inline constexpr float EPSILON = 1e-5f;
    }

    namespace Random {
        inline constexpr float MASS_MIN = 250.f;
        inline constexpr float MASS_MAX = 2000.f;
    }

    inline constexpr float ZOOM_MIN = 0.1f;
    inline constexpr float ZOOM_MAX = 10.0f;

    namespace Simulation {
        inline constexpr float CLUSTER_RADIUS = 50.0f; // Radius of the cluster of particles
        inline constexpr float CLUSTER_MARGIN = 20.0f; // Margin around the cluster
    }

    namespace Window {
        inline constexpr int DEFAULT_WIDTH = 800;
        inline constexpr int DEFAULT_HEIGHT = 600;
        inline constexpr const char* DEFAULT_TITLE = "Physics Simulation";
    }
}
