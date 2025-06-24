#pragma once

#include "Vector3.hpp"

class Field;

class Camera2D {
public:
    int screenWidth, screenHeight;
    float zoom = 1.0f;

    explicit Camera2D(Field* field, int screenWidth, int screenHeight);
    ~Camera2D() = default;

    float getZoom() const { return zoom; }
    void setZoom(float value);
    Vector3 worldToNDC(const Vector3& position) const;

private:
    Field* field;
};
