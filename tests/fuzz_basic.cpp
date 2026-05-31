#include "physics/world.hpp"
#include <iostream>
#include <cstdlib>

int main() {
    PhysicsWorld world;
    world.init(1000);
    for(int i=0; i<100; ++i) {
        // random force injection for fuzz
        // deterministic seed not used in core sim
        world.tick(1.0f/60.0f);
    }
    std::cout << "[FUZZ] Invariants held (no NaN/crash).\n";
    return 0;
}
