cmake_minimum_required(VERSION 3.3)
project(Lab1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(BUILD_1 1.cpp)
set(SOURCE_FILES_1 1.cpp)
add_executable(${BUILD_1} ${SOURCE_FILES_1})

set(BUILD_2 2_stepik.cpp)
set(SOURCE_FILES_2 2_stepik.cpp)
add_executable(${BUILD_2} ${SOURCE_FILES_2})

set(BUILD_3 3_stepik.cpp)
set(SOURCE_FILES_3 3_stepik.cpp)
add_executable(${BUILD_3} ${SOURCE_FILES_3})

set(BUILD_4 4_stepik.cpp)
set(SOURCE_FILES_4 4_stepik.cpp)
add_executable(${BUILD_4} ${SOURCE_FILES_4})

set(BUILD_5 5_stepik.cpp)
set(SOURCE_FILES_5 5_stepik.cpp)
add_executable(${BUILD_5} ${SOURCE_FILES_5})

set(BUILD_6 6.cpp)
set(SOURCE_FILES_6 6.cpp)
add_executable(${BUILD_6} ${SOURCE_FILES_6})

set(BUILD_7 7_stepik.cpp)
set(SOURCE_FILES_7 7_stepik.cpp)
add_executable(${BUILD_7} ${SOURCE_FILES_7})

set(BUILD_8 8.cpp)
set(SOURCE_FILES_8 8.cpp)
add_executable(${BUILD_8} ${SOURCE_FILES_8})

set(BUILD_9 9.cpp)
set(SOURCE_FILES_9 9.cpp)
add_executable(${BUILD_9} ${SOURCE_FILES_9})