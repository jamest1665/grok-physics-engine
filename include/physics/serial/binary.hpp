#pragma once
#include <vector>
#include <cstdint>
#include <span>

namespace physics {

class BinarySerializer {
public:
    std::vector<uint8_t> serialize(const WorldState& state); // stub, full impl dumps SoA arrays bit-exact
    bool deserialize(std::span<const uint8_t> data, WorldState& state);

    // For replays: record inputs + state at fixed intervals
    void recordTick(const WorldState& state, uint64_t tick);
};

} // namespace physics
// Note: WorldState defined in world.hpp - bit exact for determinism
