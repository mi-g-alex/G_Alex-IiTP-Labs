cmake_minimum_required(VERSION 3.25)
project(T2)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(T2 main.cpp ui/MainWindow.cpp ui/MainWindow.h)
target_link_libraries(T2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

find_library(LIB_PATH
        NAMES str
        PATHS ${CMAKE_CURRENT_LIST_DIR}/files)

target_link_libraries(T2 ${LIB_PATH})

