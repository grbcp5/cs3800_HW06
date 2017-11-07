cmake_minimum_required(VERSION 3.5)
project(hw06)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp simple.cpp simple.h Allocator.h FirstFit.cpp FirstFit.h MemoryBlock.h MemoryBlock.cpp)
add_executable(hw06 ${SOURCE_FILES})