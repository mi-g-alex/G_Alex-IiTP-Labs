cmake_minimum_required(VERSION 3.23)
project(Lab5_libs)

set(CMAKE_CXX_STANDARD 23)

add_library(Task1 Task1.cpp)
add_library(Task2 SHARED Task2.cpp)