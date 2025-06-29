#include <random>
#include <unordered_set>
#include <algorithm>

#include "simulation/Motion.hpp"

using namespace simulation;

// Construtor

Motion::Motion(std::size_t particleCount, Law law)
    : m_law(law)
{
    m_particles.reserve(particleCount);

    std::mt19937 rng{ std::random_device{}() };
    std::uniform_real_distribution<float> posDist(-25.f, 25.f);
    std::uniform_real_distribution<float> velDist(-5.f, 5.f);

    for (std::size_t i = 0; i < particleCount; ++i) {
        Vector3 pos{ posDist(rng), posDist(rng), posDist(rng) };
        Vector3 vel{ velDist(rng), velDist(rng), velDist(rng) };

        m_particles.emplace_back(pos, vel, 1.0f);
    }
}

// --------------------------------------------------------------
// Passo de simulação
// --------------------------------------------------------------
void Motion::update(float dt) {
    switch (m_law) {
        case Law::First:  applyFirst(dt);  break;
        case Law::Second: applySecond(dt); break;
        case Law::Third:  applyThird(dt);  break;
    }
}

// --------------------------------------------------------------
// Lei I – apenas integra posição (v constante)
// --------------------------------------------------------------
void Motion::applyFirst(float dt) {
    for (auto& particle : m_particles) {
        particle.integrate(dt);
    }
}

// --------------------------------------------------------------
// Lei II – força gravitacional simples F = m·g no eixo Y
// --------------------------------------------------------------
void Motion::applySecond(float dt) {
    const Vector3 g{ 0.f, -9.81f, 0.f };
    
    for (auto& particle : m_particles) {
        particle.applyForce(g * particle.getMass(), dt);
        particle.integrate(dt);
    }
}

// --------------------------------------------------------------
// Lei III – stub (ação=reação). Implementação real exigiria
// pares de partículas; aqui apenas demonstra estrutura.
// --------------------------------------------------------------
void Motion::applyThird(float dt) {
    applyFirst(dt);
}

// --------------------------------------------------------------
// Checagem de unicidade/sequência dos IDs
// --------------------------------------------------------------
bool Motion::verifyIds() const {
    if (m_particles.empty()) return true;

    // 1) IDs crescentes
    for (std::size_t i = 1; i < m_particles.size(); ++i)
        if (m_particles[i].getId() != m_particles[i-1].getId() + 1)
            return false;

    // 2) (Opcional) unicidade usando hash – garante mesmo se não forem sequenciais
    /*
    std::unordered_set<Particle::Id> seen;
    seen.reserve(m_particles.size());
    for (const auto& p : m_particles) {
        if (!seen.insert(p.id()).second) return false;
    }
    */
   
    return true;
}
