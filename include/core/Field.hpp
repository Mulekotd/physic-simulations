#pragma once

#include "Vector3.hpp"

class Particle;

class Field {
public:
    Vector3 position;

    int width, height;
    float gravity;

    Field(Vector3 position, int width, int height, float gravity = 9.81f);
    ~Field() = default;

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    Vector3 getPosition() const { return position; }

    void setPosition(Vector3 newPos) { position = newPos; }
    void setWidth(int newWidth) { width = newWidth; }
    void setHeight(int newHeight) { height = newHeight; }

    bool contains(const Particle& particle) const;
    Vector3 getRelativePosition(const Particle& particle) const;
};
