#include "physics/world.hpp"
#include <iostream>

int main() {
    PhysicsWorld world;
    world.init(10000);
    world.run_benchmark(1000);
    std::cout << "[DEMO] 10000 particles simulated deterministically.\n";
    return 0;
}
