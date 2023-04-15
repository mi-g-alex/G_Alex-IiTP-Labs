cmake_minimum_required(VERSION 3.23)
project(Lab5)

set(CMAKE_CXX_STANDARD 14)

enable_testing()
add_subdirectory(googletest)

include(${CMAKE_CURRENT_LIST_DIR}/Task1/Task1Cmake.cmake)

#tests
include(${CMAKE_CURRENT_LIST_DIR}/Task3/Test3Cmake.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/Task4/Test4Cmake.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/Task5/Test5Cmake.cmake)


add_executable(Task_2 Task2/2.cpp checkInput/checkInput.cpp checkInput/checkInput.h)
add_executable(Task_3 Task3/3.cpp checkInput/checkInput.cpp checkInput/checkInput.h)
add_executable(Task_4 Task4/4.cpp checkInput/checkInput.cpp checkInput/checkInput.h)
add_executable(Task_5 Task5/5.cpp checkInput/checkInput.cpp checkInput/checkInput.h)
add_executable(Task_6 Task6/6_stepik.cpp checkInput/checkInput.cpp checkInput/checkInput.h)
add_executable(Task_7 Task7/7_stepik.cpp checkInput/checkInput.cpp checkInput/checkInput.h)
add_executable(Task_8 Task8/8_stepik.cpp checkInput/checkInput.cpp checkInput/checkInput.h)


