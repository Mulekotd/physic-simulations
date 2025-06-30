#pragma once

#include <vector>

#include "common/Constants.hpp"
#include "common/Types.hpp"

#include "core/Field.hpp"
#include "core/Particle.hpp"

#include "simulation/ForceFunctions.hpp"

namespace simulation {
    
    class Motion {
    public:
        Motion(std::size_t particleCount,
               Field&      world,
               ForceFunc   forceGenerator = nullptr,
               float       restitution    = Constants::Physics::RESTITUTION_COEFFICIENT);

        void render();
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
