cmake_minimum_required(VERSION 3.23)
project(Lab7)

set(CMAKE_CXX_STANDARD 20)

enable_testing()
add_subdirectory(googletest)

add_executable(Task1 Task1/Task1.cpp)

add_executable(Task2 Task2/Task2.cpp)

add_executable(Task3 Task3/Task3.cpp checkInput/checkInput.cpp checkInput/checkInput.cpp)

add_executable(Task4 Task4/Task4.cpp)
add_executable(Test_4 Tests/Test4.cpp Tests/Task4.cpp)
target_link_libraries(Test_4 gmock pthread)

add_executable(Task5 Task5/Task5.cpp)
add_executable(Test_5 Tests/Test5.cpp Tests/Task5.cpp)
target_link_libraries(Test_5 gmock pthread)

add_executable(Task6 Task6/Task6.cpp checkInput/checkInput.cpp checkInput/checkInput.cpp)

add_executable(Task7 Task7/Task7.cpp)
add_executable(Test_7 Tests/Test7.cpp Tests/Task7.cpp)
target_link_libraries(Test_7 gmock pthread)

add_executable(Task8 Task8/Task8.cpp)
add_executable(Test_8 Tests/Test8.cpp Tests/Task8.cpp)
target_link_libraries(Test_8 gmock pthread)

add_executable(Task9 Task9/Task9.cpp)

add_executable(del del2.cpp)

