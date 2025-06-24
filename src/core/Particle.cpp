#include "core/Camera2D.hpp"
#include "core/Field.hpp"

#include "core/Particle.hpp"
#include "core/Vector3.hpp"

// Constructor

Particle::Particle(const Vector3& position, const Vector3& velocity, float mass)
    : position(position), velocity(velocity), mass(mass) {}

// Methods    
