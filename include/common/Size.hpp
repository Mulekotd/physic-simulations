#pragma once

#include <cstdint>

struct Size {
    int width  = 0;
    int height = 0;
    int depth  = 0;

    constexpr Size() = default;
    constexpr Size(int w, int h) : width(w), height(h) {}
    constexpr Size(int w, int h, int d) : width(w), height(h), depth(d) {}
};
