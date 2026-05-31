# Grok Physics Engine

From-scratch C++23 zero-dependency real-time physics engine.

## Features
- Strict Data-Oriented Design (DOD) + custom ECS
- Hand-tuned SIMD & cache-optimized SoA storage
- Deterministic simulation with fixed timestep
- Dynamic BVH broadphase (stubbed for MVP; full impl next)
- CCD & constraints framework ready
- Serialization hooks for replays/netcode
- Benchmarks & fuzz tests
- Shippable examples

## Build
```bash
git clone https://github.com/jamest1665/grok-physics-engine.git
cd grok-physics-engine
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
```

## Run
- `./examples/basic_particles` - 10k particles sim + bench
- `./benchmarks/bench_particles`
- `./tests/fuzz_basic`

Built to SpaceX/AI engineering standards: correct, measurable, extensible.

Iterate via issues/PRs.