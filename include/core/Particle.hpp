#pragma once

#include <cstdint>

#include "common/Vector3.hpp"

class Camera2D;

class Particle {
public:
    using Id = std::uint32_t;

    explicit Particle(const Vector3& position = {}, const Vector3& velocity = {}, float mass = 1.0f, float radius = 0.05f);

    Id getId() const noexcept { return m_id; }
    const Vector3& getPosition() const noexcept { return m_position; }
    const Vector3& getVelocity() const noexcept { return m_velocity; }

    float getMass() const noexcept { return m_mass; }
    float getRadius() const noexcept { return m_radius; }

    void setPosition(const Vector3& p) noexcept { m_position = p; }
    void setVelocity(const Vector3& v) noexcept { m_velocity = v; }
    void setMass(float m) noexcept { m_mass = m; }
    void setRadius(float r) noexcept { m_radius = r; }

    void draw(const Camera2D& camera) const;

    void applyForce(const Vector3& force, float dt) noexcept;
    void integrate (float dt) noexcept;

private:
    Id       m_id;
    Vector3  m_position;
    Vector3  m_velocity;
    float    m_mass, m_radius;

    inline static Id m_nextId{0};
};
