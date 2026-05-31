cmake_minimum_required(VERSION 3.22)
project(GrokPhysics LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-march=haswell -O3 -ffast-math)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(basic_particles examples/basic_particles.cpp)
add_executable(bench_particles benchmarks/bench_particles.cpp)
add_executable(fuzz_basic tests/fuzz_basic.cpp)

target_link_libraries(basic_particles PRIVATE)
target_link_libraries(bench_particles PRIVATE)
target_link_libraries(fuzz_basic PRIVATE)
