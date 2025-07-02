#include <algorithm>

#include "common/Constants.hpp"
#include "common/Dimensions.hpp"
#include "common/Vector3.hpp"

#include "core/Field.hpp"
#include "core/Camera2D.hpp"

void Camera2D::setZoom(float factor) noexcept {
    if (factor > 0.0f) {
        m_zoom = std::clamp(m_zoom * factor, Constants::ZOOM_MIN, Constants::ZOOM_MAX);
    }
}

void Camera2D::move(const Vector3& delta) noexcept {
    const Dimensions& size = m_field->getSize();

    float halfW = size.width  * 0.5f;
    float halfH = size.height * 0.5f;

    m_offset.x = std::clamp(m_offset.x + delta.x, -halfW, halfW);
    m_offset.y = std::clamp(m_offset.y + delta.y, -halfH, halfH);
}

Vector3 Camera2D::worldToNDC(const Vector3& position) const noexcept {
    Vector3 rel = m_field->getRelativePosition(position) - m_offset;
    Dimensions s = m_field->getSize();

    float x = (rel.x / (s.width  * 0.5f)) * m_zoom;
    float y = (rel.y / (s.height * 0.5f)) * m_zoom;

    return {x, y, 0.f};
}

