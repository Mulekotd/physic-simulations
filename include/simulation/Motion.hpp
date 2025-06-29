#pragma once

#include <vector>
#include <cstddef>

#include "core/Particle.hpp"

namespace simulation {
    enum class Law : int {
        First  = 1,
        Second = 2,
        Third  = 3
    };

    class Motion {
    public:
        Motion(std::size_t particleCount, Law law = Law::First);

        void update(float dt);
        bool verifyIds() const;

        const std::vector<Particle>& particles() const noexcept { return m_particles; }

    private:
        std::vector<Particle> m_particles;
        Law                   m_law;

        void applyFirst (float dt);
        void applySecond(float dt);
        void applyThird (float dt);
    };
}
