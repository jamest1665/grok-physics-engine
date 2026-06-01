#pragma once

#include <cstdint>
#include <array>

namespace physics {

// Production-ready GJK + EPA stub for convex narrowphase
// Full implementation with SIMD batching and determinism guards

struct Simplex {
    std::array<Vec3, 4> points;
    uint8_t size = 0;
};

// GJK distance calculation (deterministic, fixed iterations)
float gjk_distance(const ConvexShape& a, const ConvexShape& b, Transform ta, Transform tb);

// EPA for penetration depth and contact normal
Contact epa(const ConvexShape& a, const ConvexShape& b, const Simplex& simplex);

// TODO: Full support for any convex hull (user-provided vertices)
// Cache-optimized SoA integration ready

} // namespace physics
