#include "physics/world.hpp"
#include <iostream>

int main() {
    PhysicsWorld world;
    world.init(50000);
    world.run_benchmark(5000);
    std::cout << "[BENCH] High-scale particle stress test complete.\n";
    return 0;
}
