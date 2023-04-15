cmake_minimum_required(VERSION 3.25)
project(L3T3)

set(CMAKE_CXX_STANDARD 23)

add_executable(L3T3 main.cpp vector/vector.h vector/iterator.h)

find_library(LIB_PATH
        NAMES MyVector
        PATHS ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(L3T3 ${LIB_PATH})


