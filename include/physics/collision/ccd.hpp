#pragma once

#include <physics/math.hpp>
#include <physics/components/rigid_body.hpp>

namespace physics {

// Continuous Collision Detection (CCD) with Time of Impact (TOI)
// Strict DOD: SoA friendly, SIMD-ready stubs
// Basic raycast-style TOI for spheres/boxes to prevent tunneling
struct CCDResult {
    float toi; // 0.0-1.0 fraction of timestep
    Vec3 normal;
    Vec3 point;
    bool collided;
};

// TODO: Full GJK-based swept volume + EPA for general convex
CCDResult compute_toi(const RigidBody& a, const RigidBody& b, float dt);

// Integrate into narrowphase after BVH
} // namespace physics
