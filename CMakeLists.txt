cmake_minimum_required (VERSION 2.8)
project (cpp-idiom-bench)
file (GLOB_RECURSE sources src/*.cpp src/*.h)
add_executable (cpp-idiom-bench ${sources})
