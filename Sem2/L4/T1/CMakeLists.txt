cmake_minimum_required(VERSION 3.5)
project(untitled1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main main.cpp iterator.h MyString.h MyString.cpp unique_char.h)
add_library(str SHARED MyString.cpp MyString.h unique_char.h iterator.h)