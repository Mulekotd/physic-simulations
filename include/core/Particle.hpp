#pragma once

#include <string>

#include "Vector3.hpp"

class Camera2D;

class Particle {
public:
    Vector3 position, velocity;
    float mass;

    Particle(const Vector3& position, const Vector3& velocity, float mass);
    ~Particle() = default;

private:
    std::string uid; // TODO: Change type string to a more suitable type for unique IDs
};
