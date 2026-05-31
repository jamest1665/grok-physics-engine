#pragma once

#include <physics/constraints/solver.hpp>

namespace physics {

// Expanded joints: Hinge, Ball-and-Socket (6DOF ready stub)
// SoA storage in World, solved in PGS loop
struct HingeJoint {
    EntityID bodyA, bodyB;
    Vec3 anchorA, anchorB;
    Vec3 axis; // rotation axis
    float lowerLimit, upperLimit; // angular limits
};

struct BallJoint {
    EntityID bodyA, bodyB;
    Vec3 anchorA, anchorB;
};

// Register joints into constraint buffer for solver
void add_hinge_joint(World& world, const HingeJoint& j);
void add_ball_joint(World& world, const BallJoint& j);

} // namespace physics
