#include "common/Size.hpp"
#include "common/Vector3.hpp"

#include "core/Field.hpp"
#include "core/Viewport.hpp"

// Constructor

Viewport::Viewport(Field* field, Size screenSize)
    : m_field(field), m_screenSize(screenSize) {}

// Methods

Vector3 Viewport::worldToNDC(const Vector3& position) const {
    Vector3 relative = m_field->getRelativePosition(position);
    Size size = m_field->getSize();

    float x_ndc = ((relative.x / size.width) * 2.0f - 1.0f) * m_zoom;
    float y_ndc = ((relative.y / size.height) * 2.0f - 1.0f) * m_zoom;

    return Vector3(x_ndc, y_ndc, 0);
}
