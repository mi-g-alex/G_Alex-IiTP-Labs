cmake_minimum_required(VERSION 3.5)
project(untitled1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


add_executable(T2 main.cpp MyQueue/MyDeque.cpp MyQueue/MyDeque.h shared_ptr.h unique_ptr.h ui/MainWindow.cpp ui/MainWindow.h)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

target_link_libraries(T2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )
