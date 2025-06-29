#pragma once

#include <cstdint>

struct Size {
    int width  = 0;
    int height = 0;
    int depth  = 0;

    constexpr Size() = default;
    constexpr Size(int w, int h) : width(w), height(h) {}
    constexpr Size(int w, int h, int d) : width(w), height(h), depth(d) {}

    constexpr Size center() const noexcept {
        return Size(width / 2.0f, height / 2.0f, depth / 2.0f);
    }
};
