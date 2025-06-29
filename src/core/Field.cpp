#include "common/Vector3.hpp"

#include "core/Field.hpp"
#include "core/Particle.hpp"

// Constructor

Field::Field(Vector3 position, Size size, float gravity)
    : m_position(position), m_size(size), m_gravity(gravity) {}

// Methods

bool Field::contains(const Vector3& position) const {
    Vector3 relative = getRelativePosition(position);
    
    return (0 <= relative.x && relative.x <= m_size.width) &&
       (0 <= relative.y && relative.y <= m_size.height);
}

bool Field::contains(const Particle& particle) const {
    return contains(particle.getPosition());
}

Vector3 Field::getRelativePosition(const Vector3& position) const noexcept {
    return position - m_position;
}
