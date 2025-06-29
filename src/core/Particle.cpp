#include <cmath>
#include <GLFW/glfw3.h>

#include "common/Application.hpp"
#include "common/Constants.hpp"

#include "core/Camera2D.hpp"
#include "core/Particle.hpp"

// Constructor

Particle::Particle(const Vector3& position, const Vector3& velocity, float mass, float radius)
    : m_id{ m_nextId++ }, m_position{ position }, m_velocity{ velocity }, m_mass{ mass }, m_radius{ radius }
{}

void Particle::draw() const {
    Vector3 ndc = Application::camera.worldToNDC(m_position);
    Vector3 ndcEdge = Application::camera.worldToNDC(m_position + Vector3{m_radius, 0, 0});

    float ndcRadius = std::abs(ndcEdge.x - ndc.x);

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);

    // Circle center
    glVertex2f(ndc.x, ndc.y);

    // Circumference
    int segments = std::clamp(static_cast<int>(m_radius * 10), 16, 128);
    float step = 2.0f * Constants::PI / segments;

    for (int i = 0; i <= segments; ++i) {
        float angle = i * step;

        float dx = std::cos(angle) * ndcRadius;
        float dy = std::sin(angle) * ndcRadius;

        glVertex2f(ndc.x + dx, ndc.y + dy);
    }

    glEnd();
}
