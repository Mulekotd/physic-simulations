#pragma once

#include <algorithm>

#include "common/Constants.hpp"
#include "common/Size.hpp"
#include "common/Vector3.hpp"

class Field;

class Camera2D {
public:
    explicit Camera2D(Field* field, Size screenSize);
    ~Camera2D() = default;

    Size getScreenSize() const noexcept { return m_screenSize; }
    float getZoom() const noexcept { return m_zoom; }

    void setScreenSize(Size s) noexcept { m_screenSize = s; }
    void setZoom(float factor) noexcept {
        if (factor <= 0.0f) return;

        m_zoom = std::clamp(m_zoom * factor, Constants::ZOOM_MIN, Constants::ZOOM_MAX);
    }

    Vector3 worldToNDC(const Vector3& position) const;

private:
    Field* m_field;
    Size   m_screenSize;
    float  m_zoom = 1.0f;
};
