#pragma once
#include <vector>
#include <cstdint>

template<typename T>
struct SoAStorage {
    std::vector<T> data;
    void reserve(size_t n) { data.reserve(n); }
    void resize(size_t n) { data.resize(n); }
    T& operator[](size_t i) { return data[i]; }
    const T& operator[](size_t i) const { return data[i]; }
};

struct Entity { uint32_t id; uint16_t gen; };

// Physics-specific SoA components (position, velocity etc. in separate storages for cache)
