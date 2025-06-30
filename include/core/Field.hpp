#pragma once

#include "common/Constants.hpp"
#include "common/Dimensions.hpp"
#include "common/Vector3.hpp"

class Particle;

class Field {
public:
    explicit Field(Dimensions size, float gravity = Constants::Physics::GRAVITY);
    ~Field() = default;

    [[nodiscard]] Dimensions getSize() const noexcept { return m_size; }
    [[nodiscard]] Vector3 getPosition() const noexcept { return m_position; }
    [[nodiscard]] float getGravity() const noexcept { return m_gravity; }

    void setSize(Dimensions s) noexcept { m_size = s; }
    void setPosition(Vector3 p) noexcept { m_position = p; }
    void setGravity(float g) noexcept { m_gravity = g; }

    bool contains(const Vector3& position) const noexcept;
    bool contains(const Particle& particle) const noexcept;
    Vector3 getRelativePosition(const Vector3& position) const noexcept;

private:
    Dimensions m_size;
    Vector3    m_position;
    float      m_gravity;
};
