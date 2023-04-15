cmake_minimum_required(VERSION 3.25)
project(T3)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(T3 main.cpp ui/MainWindow.cpp ui/MainWindow.h parser.h)
target_link_libraries(T3
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

find_library(LIB_PATH
        NAMES str
        PATHS ${CMAKE_CURRENT_LIST_DIR}/files)

target_link_libraries(T3 ${LIB_PATH})

