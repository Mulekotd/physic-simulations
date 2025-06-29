#include <cmath>
#include <GLFW/glfw3.h>

#include "common/Constants.hpp"

#include "core/Camera2D.hpp"
#include "core/Particle.hpp"

// Constructor

Particle::Particle(const Vector3& position, const Vector3& velocity, float mass, float radius)
    : m_id{ m_nextId++ }, m_position{ position }, m_velocity{ velocity }, m_mass{ mass }, m_radius{ radius }
{}

void Particle::draw(const Camera2D& camera) const {
    Vector3 ndc = camera.worldToNDC(m_position);

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);

    // Circle center
    glVertex2f(ndc.x, ndc.y);

    // Circumference
    for (int i = 0; i <= Constants::CIRCLE_SEGMENTS; ++i) {
        float angle = i * Constants::THETA_STEP;

        float dx = std::cos(angle) * m_radius;
        float dy = std::sin(angle) * m_radius;

        glVertex2f(ndc.x + dx, ndc.y + dy);
    }

    glEnd();
}

void Particle::applyForce(const Vector3& force, float dt) noexcept {
    // a = F / m
    Vector3 acceleration = force * (1.0f / m_mass);
    m_velocity += acceleration * dt;
}

void Particle::integrate(float dt) noexcept {
    // x += v * dt
    m_position += m_velocity * dt;
}
