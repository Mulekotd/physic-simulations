#pragma once

#include "common/Constants.hpp"
#include "common/Vector3.hpp"

#include "core/Particle.hpp"

namespace simulation::forces {
    // Gravity (weight force)
    inline auto gravity(float g = Constants::Physics::GRAVITY) {
        return [g](Particle& p, float) {
            p.addForce(Vector3{0, -1, 0} * g * p.getMass());
        };
    }

    // Dynamic friction
    inline auto friction(float mu = Constants::Physics::DYNAMIC_FRICTION_COEFFICIENT, float g = Constants::Physics::GRAVITY) {
        return [mu, g](Particle& p, float) {
            const Vector3& v = p.getVelocity();
            float speed = v.length();

            if (speed > 0.0001f) {
                Vector3 dir = -v.normalized();
                Vector3 force = dir * mu * p.getMass() * g;
                
                p.addForce(force);
            }
        };
    }
}
