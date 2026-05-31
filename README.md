# Grok Physics Engine

From-scratch C++23 zero-dep real-time physics engine: strict DOD + custom ECS, hand-tuned SIMD, cache-optimized.

## v0.3 — Full iterative PGS constraint solver + binary serialization / deterministic replay

**Implemented:**
- SoA constraint buffer with warm-started Projected Gauss-Seidel solver
- Contact constraints with friction, restitution, Baumgarte stabilization
- Binary state + input serialization for perfect replays and netcode delta hooks
- Updated pipeline in world.hpp
- Stable rigid body stacking demos

## Features
- Dynamic BVH broadphase
- RigidBody SoA components
- Deterministic fixed-timestep integration
- Benchmarks, fuzz tests, shippable examples

Build with CMake (Release, C++23, -march=haswell).

See docs/architecture.md for DOD details.
