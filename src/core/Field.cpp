#include "core/Field.hpp"
#include "core/Particle.hpp"
#include "core/Vector3.hpp"

// Constructor

Field::Field(Vector3 position, int width, int height, float gravity)
    : position(position), width(width), height(height), gravity(gravity) {}

// Methods

bool Field::contains(const Particle& particle) const {
    Vector3 relative = particle.position - position;
    
    return (0 <= relative.x && relative.x <= width) &&
       (0 <= relative.y && relative.y <= height);
}

Vector3 Field::getRelativePosition(const Particle& particle) const {
    return particle.position - position;
}
