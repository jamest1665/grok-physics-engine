# Architecture

## Core Principles
- Strict DOD: SoA everywhere, no pointer chasing
- Custom ECS: dense arrays + entity (id+gen)
- Pipeline: forces → broad → narrow → solve → integrate → refit
- Determinism: fixed dt, explicit FP control

## Layers
- math/: SIMD vec/quat/AABB
- ecs/: SoA ComponentStorage
- world/: PhysicsWorld orchestrator
- broadphase/: Dynamic BVH (refit + rebuild)
- constraints/: Iterative PGS solver

Extension points: template policies, custom allocators.

See code comments for trade-offs.