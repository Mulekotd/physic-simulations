#include "common/Vector3.hpp"

#include "core/Field.hpp"
#include "core/Particle.hpp"

// Constructor

Field::Field(Dimensions size, float gravity)
    : m_size(size), m_position(size.centerAsVector()), m_gravity(gravity) {}

// Methods

bool Field::contains(const Vector3& position) const noexcept {
    Vector3 rel = getRelativePosition(position);

    float halfW = m_size.width  * 0.5f;
    float halfH = m_size.height * 0.5f;

    return (-halfW <= rel.x && rel.x <= halfW) &&
           (-halfH <= rel.y && rel.y <= halfH);
}


bool Field::contains(const Particle& particle) const noexcept {
    return contains(particle.getPosition());
}

Vector3 Field::getRelativePosition(const Vector3& position) const noexcept {
    return position - m_position;
}
