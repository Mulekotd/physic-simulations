#include <algorithm>

#include "core/Camera2D.hpp"
#include "core/Field.hpp"
#include "core/Vector3.hpp"

Camera2D::Camera2D(Field* field, int screenWidth, int screenHeight)
    : field(field), screenWidth(screenWidth), screenHeight(screenHeight) {}

void Camera2D::setZoom(float value) {
    zoom = std::max(0.1f, std::min(zoom * value, 10.0f));
}

Vector3 Camera2D::worldToNDC(const Vector3& position) const {
    Vector3 relative = position - field->getPosition();

    float x_ndc = ((relative.x / field->getWidth()) * 2.0f - 1.0f) * zoom;
    float y_ndc = ((relative.y / field->getHeight()) * 2.0f - 1.0f) * zoom;

    return Vector3(x_ndc, y_ndc, 0);
}