## Grok Physics Engine

C++23 zero-dep real-time physics engine: strict DOD + custom ECS, hand-tuned SIMD, cache-optimized.

### Current Version: v0.5 — Full GJK + EPA narrowphase

**Features implemented:**
- v0.1: SoA ECS + particle pipeline
- v0.3: PGS solver + serialization
- v0.4: CCD/TOI + joints
- v0.5: GJK + EPA for arbitrary convex shapes (SIMD optimized)

Build with C++23, -march=haswell -O3.

See include/physics/ for modules.
