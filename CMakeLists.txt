cmake_minimum_required(VERSION 3.10)

project(LR_5_Zhukov VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LR_5_Zhukov src/main.cpp src/cruise/Cruise.cpp src/cruise/Cruise.hpp)
