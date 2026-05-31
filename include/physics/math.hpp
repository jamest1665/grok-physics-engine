#pragma once
#include <cmath>
#include <immintrin.h>
#include <cstdint>

struct alignas(32) Vec3 {
    float x, y, z, pad;
    Vec3() = default;
    Vec3(float x_, float y_, float z_) : x(x_), y(y_), z(z_), pad(0) {}
    Vec3 operator+(const Vec3& o) const { return {x+o.x, y+o.y, z+o.z}; }
    Vec3 operator*(float s) const { return {x*s, y*s, z*s}; }
    // SIMD batch add (8x)
    static void batch_add(const float* __restrict a, const float* __restrict b, float* __restrict out, size_t n) {
        for(size_t i=0; i<n; i+=8) {
            __m256 va = _mm256_load_ps(a+i);
            __m256 vb = _mm256_load_ps(b+i);
            _mm256_store_ps(out+i, _mm256_add_ps(va, vb));
        }
    }
};

// Similar for Quat, Mat3, AABB... (full in future iterations)
