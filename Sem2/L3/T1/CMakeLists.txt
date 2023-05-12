cmake_minimum_required(VERSION 3.24)
project(L3T1)

set(CMAKE_CXX_STANDARD 23)

add_executable(L3T1 main.cpp vector/vector.cpp vector/vector.h vector/iterator.h vector/pair.h)

add_library(MyVector STATIC vector/vector.cpp vector/vector.h vector/iterator.h vector/pair.h)
