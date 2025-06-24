#include <cmath>

#include "core/Vector3.hpp"

// Constructors

Vector3::Vector3() : x(0), y(0), z(0) {}
Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

// Operators

Vector3 Vector3::operator+(const Vector3& other) const {
    return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator-(const Vector3& other) const {
    return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator*(float scalar) const {
    return Vector3(x * scalar, y * scalar, z * scalar);
}

// Methods

float Vector3::distance(const Vector3& other) const {
    return (*this - other).length();
}

float Vector3::dot(const Vector3& other) const {
    return x * other.x + y * other.y + z * other.z;
}

float Vector3::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

void Vector3::normalize() {
    float len = length();
    
    if (len > 0) {
        x /= len;
        y /= len;
        z /= len;
    }
}
