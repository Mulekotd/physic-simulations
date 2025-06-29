#pragma once

#include "common/Size.hpp"
#include "common/Vector3.hpp"

class Particle;

class Field {
public:
    explicit Field(Vector3 position, Size size, float gravity = 9.81f);
    ~Field() = default;

    Size getSize() const noexcept { return m_size; }
    Vector3 getPosition() const noexcept { return m_position; }
    float getGravity() const noexcept { return m_gravity; }

    void setSize(Size s) noexcept { m_size = s; }
    void setPosition(Vector3 p) noexcept { m_position = p; }
    void setGravity(float g) noexcept { m_gravity = g; }

    bool contains(const Vector3& position) const;
    bool contains(const Particle& particle) const;
    Vector3 getRelativePosition(const Vector3& position) const noexcept;

private:
    Size    m_size;
    Vector3 m_position;
    float   m_gravity;
};
