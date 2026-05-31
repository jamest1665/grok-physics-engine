#pragma once
// Updated pipeline stub for v0.3
namespace physics {

class PhysicsWorld {
public:
    void tick(float dt) {
        // broadphase -> narrow -> generate constraints -> solver.solve() -> integrate
        // serialization hook
    }
    ConstraintSolver solver;
    // ... other SoA storages
};

} // namespace physics
