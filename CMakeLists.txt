cmake_minimum_required (VERSION 2.9)
set (CMAKE_CXX_STANDARD 17)
project (cpp-idiom-bench)
file (GLOB_RECURSE sources src/*.cpp src/*.h)
add_executable (cpp-idiom-bench ${sources})
