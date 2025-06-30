#pragma once

#include <algorithm>

#include "common/Constants.hpp"
#include "common/Dimensions.hpp"
#include "common/Vector3.hpp"

class Field;

class Camera2D {
public:
    explicit Camera2D(const Field& field) : m_field(&field) {}
    ~Camera2D() = default;

    [[nodiscard]] float getZoom() const noexcept { return m_zoom; }

    void setZoom(float factor) noexcept {
        if (factor > 0.0f)
            m_zoom = std::clamp(m_zoom * factor,
                                Constants::ZOOM_MIN,
                                Constants::ZOOM_MAX);
    }

    Vector3 worldToNDC(const Vector3& position) const noexcept;

private:
    const Field* m_field;
    float        m_zoom = 1.0f;
};
