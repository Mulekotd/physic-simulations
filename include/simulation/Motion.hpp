#pragma once

#include <vector>
#include <functional>

#include "core/Field.hpp"
#include "core/Particle.hpp"

namespace simulation {
    
    using ForceFunc = std::function<void(Particle&, float)>;

    class Motion {
    public:
        Motion(std::size_t particleCount,
               Field& world,
               ForceFunc forceGenerator   = nullptr,
               float    restitution       = 0.9f);

        void update(float dt);

        const std::vector<Particle>& particles() const noexcept { return m_particles; }

    private:
        std::vector<Particle> m_particles;
        Field&                m_field;
        ForceFunc             m_forceGen;
        float                 m_restitution;

        void resolveBounds(Particle&) const;
        void resolveParticleCollision(Particle& a, Particle& b) const;
    };
}
