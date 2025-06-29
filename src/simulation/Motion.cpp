#include <random>

#include "common/Constants.hpp"
#include "simulation/Motion.hpp"

simulation::Motion::Motion(std::size_t n, Field& world, ForceFunc fn, float rest) 
    : m_field(world), m_forceGen(fn), m_restitution(rest) 
{
    m_particles.reserve(n);

    std::mt19937 rng{ std::random_device{}() };
    std::uniform_real_distribution<float> pos(Constants::MIN_RANDOM_POS, Constants::MAX_RANDOM_POS), 
                                          vel(Constants::MIN_RANDOM_VEL, Constants::MAX_RANDOM_VEL),
                                          m(Constants::MIN_RANDOM_MASS, Constants::MAX_RANDOM_MASS);

    for (std::size_t i = 0; i < n; ++i) {
        Vector3 position = Vector3{pos(rng), pos(rng), 0};
        Vector3 velocity = Vector3{vel(rng), vel(rng), 0};

        float mass = m(rng);
        float radius = std::cbrt(mass) * 0.3f;

        m_particles.emplace_back(position,
                                 velocity,
                                 mass,
                                 radius);
    }
}

void simulation::Motion::update(float dt) {
    // apply external forces + integrate
    for (auto& particle : m_particles) {
        if (m_forceGen) m_forceGen(particle, dt);

        particle.integrate(dt);  // semi‑implicit
        resolveBounds(particle); // bounce off walls
    }

    // O(n²) pair‑wise collision
    const std::size_t count = m_particles.size();

    for (std::size_t i = 0; i < count; ++i)
        for (std::size_t j = i + 1; j < count; ++j)
            resolveParticleCollision(m_particles[i], m_particles[j]);
}

// ------------------------------------------------------------------
// Collision with world bounds
// ------------------------------------------------------------------
void simulation::Motion::resolveBounds(Particle& a) const {
    Vector3 rel = m_field.getRelativePosition(a.getPosition());
    Vector3 vel = a.getVelocity();

    bool hit = false;

    if (rel.x < 0) {
        rel.x = 0;
        vel.x = -vel.x * m_restitution;
        hit = true;
    } else if (rel.x > m_field.getSize().width) {
        rel.x = m_field.getSize().width;
        vel.x = -vel.x * m_restitution;
        hit = true;
    }

    if (rel.y < 0) {
        rel.y = 0;
        vel.y = -vel.y * m_restitution;
        hit = true;
    } else if (rel.y > m_field.getSize().height) {
        rel.y = m_field.getSize().height;
        vel.y = -vel.y * m_restitution;
        hit = true;
    }

    if (hit) {
        a.setPosition(rel + m_field.getPosition());
        a.setVelocity(vel);
    }
}

// ------------------------------------------------------------------
// Elastic collision between two discs
// ------------------------------------------------------------------
void simulation::Motion::resolveParticleCollision(Particle& a, Particle& b) const {
    Vector3 delta = b.getPosition() - a.getPosition();
    float distanceSq = delta.dot(delta);
    float radiusSum = a.getRadius() + b.getRadius();

    // no contact
    if (distanceSq >= radiusSum * radiusSum) return;

    float dist = std::sqrt(distanceSq);

    // same position
    if (dist == 0.0f) return;                              

    // --- 2.1 push the discs apart (positional correction)
    Vector3 n = delta * (1.0f / dist); // collision normal
    float penetration = radiusSum - dist;

    float invMa = 1.0f / a.getMass();
    float invMb = 1.0f / b.getMass();
    float invMassSum = invMa + invMb;

    a.setPosition(a.getPosition() - n * (penetration * invMa / invMassSum));
    b.setPosition(b.getPosition() + n * (penetration * invMb / invMassSum));

    // --- 2.2 impulse to change velocities
    Vector3 relVel = b.getVelocity() - a.getVelocity();
    float   vRelN  = relVel.dot(n);

    // already separating
    if (vRelN >= 0.0f) return;

    float e = m_restitution; // 0 = inelastic, 1 = elastic
    float j = -(1 + e) * vRelN / invMassSum;

    Vector3 impulse = n * j;
    a.setVelocity(a.getVelocity() - impulse * invMa);
    b.setVelocity(b.getVelocity() + impulse * invMb);
}
