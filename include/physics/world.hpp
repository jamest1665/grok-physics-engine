#pragma once
#include "math.hpp"
#include "ecs.hpp"
#include <vector>
#include <chrono>

struct ParticleComponents {
    SoAStorage<float> pos_x, pos_y, pos_z;
    SoAStorage<float> vel_x, vel_y, vel_z;
    size_t size = 0;
    void resize(size_t n) {
        pos_x.resize(n); pos_y.resize(n); pos_z.resize(n);
        vel_x.resize(n); vel_y.resize(n); vel_z.resize(n);
        size = n;
    }
};

class PhysicsWorld {
public:
    ParticleComponents particles;
    void init(size_t num_particles) {
        particles.resize(num_particles);
        // deterministic init
        for(size_t i=0; i<num_particles; ++i) {
            particles.pos_x[i] = (i % 100) * 0.1f;
            particles.vel_x[i] = 0.0f;
            // ... similar
        }
    }

    void tick(float dt) { // fixed dt for determinism
        const float gravity = -9.81f;
        for(size_t i=0; i<particles.size; ++i) {
            particles.vel_y[i] += gravity * dt;
            particles.pos_x[i] += particles.vel_x[i] * dt;
            particles.pos_y[i] += particles.vel_y[i] * dt;
            particles.pos_z[i] += particles.vel_z[i] * dt;
            // simple floor constraint
            if (particles.pos_y[i] < 0.0f) {
                particles.pos_y[i] = 0.0f;
                particles.vel_y[i] = -particles.vel_y[i] * 0.8f; // restitution
            }
        }
        // TODO: full BVH + CCD + solver
    }

    void run_benchmark(size_t ticks) {
        auto start = std::chrono::high_resolution_clock::now();
        for(size_t t=0; t<ticks; ++t) tick(1.0f/60.0f);
        auto end = std::chrono::high_resolution_clock::now();
        double fps = ticks / std::chrono::duration<double>(end-start).count();
        // output fps
    }
};
