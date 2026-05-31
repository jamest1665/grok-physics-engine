#pragma once
#include <vector>
#include <cstdint>
#include "../math.hpp" // assume vec3, etc. from core

namespace physics {

struct ContactConstraint {
    uint32_t bodyA, bodyB;
    float penetration;
    vec3 normal, point;
    float restitution, friction;
    // warm start impulses
    float normalImpulse = 0.0f;
    float frictionImpulse = 0.0f;
};

class ConstraintSolver {
public:
    void solve(std::vector<ContactConstraint>& constraints, float dt, int iterations = 30) {
        // PGS loop - cache hot SoA would be optimized in full SoA ECS
        for (int iter = 0; iter < iterations; ++iter) {
            for (auto& c : constraints) {
                // Simplified impulse calculation (full version uses velocities, inertia)
                float impulse = -c.penetration / dt; // Baumgarte + velocity solve stub
                c.normalImpulse += impulse;
                // Apply to bodies (stub - integrate with RigidBody SoA in world)
            }
        }
    }

    // Warm start, friction, etc. added in full impl
};

} // namespace physics
