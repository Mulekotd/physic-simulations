#include "common/Dimensions.hpp"
#include "common/Vector3.hpp"

#include "core/Field.hpp"
#include "core/Camera2D.hpp"

// Methods

Vector3 Camera2D::worldToNDC(const Vector3& position) const noexcept {
    Vector3 rel = m_field->getRelativePosition(position);
    Dimensions s = m_field->getSize();

    float x = (rel.x / (s.width  * 0.5f)) * m_zoom;
    float y = (rel.y / (s.height * 0.5f)) * m_zoom;

    return {x, y, 0.f};
}
