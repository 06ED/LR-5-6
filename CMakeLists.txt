cmake_minimum_required(VERSION 3.10)

project(LR_5_Zhukov VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES
    "src/*.cpp"
    "src/*.c"
    "src/*.h"
    "src/*.hpp"
)

add_executable(LR_5_Zhukov ${SOURCES})
