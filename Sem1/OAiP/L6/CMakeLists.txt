cmake_minimum_required(VERSION 3.23)
project(Lab6)

set(CMAKE_CXX_STANDARD 23)

enable_testing()
add_subdirectory(googletest)

add_executable(Start start.cpp solves/forStart.h solves/1.cpp checkInput/checkInput.h checkInput/checkInput.cpp solves/2.cpp solves/3.cpp solves/4.cpp solves/5.cpp solves/6.cpp solves/7.cpp solves/8.cpp)

add_executable(Test_5 ${CMAKE_CURRENT_LIST_DIR}/test/Test5.cpp ${CMAKE_CURRENT_LIST_DIR}/test/5.cpp)
target_link_libraries(Test_5 gmock pthread)

add_executable(Test_6 ${CMAKE_CURRENT_LIST_DIR}/test/Test6.cpp ${CMAKE_CURRENT_LIST_DIR}/test/6.cpp)
target_link_libraries(Test_6 gmock pthread)

add_executable(Test_7 ${CMAKE_CURRENT_LIST_DIR}/test/Test7.cpp ${CMAKE_CURRENT_LIST_DIR}/test/7.cpp)
target_link_libraries(Test_7 gmock pthread)

add_executable(Test_8 ${CMAKE_CURRENT_LIST_DIR}/test/Test8.cpp ${CMAKE_CURRENT_LIST_DIR}/test/8.cpp)
target_link_libraries(Test_8 gmock pthread)
