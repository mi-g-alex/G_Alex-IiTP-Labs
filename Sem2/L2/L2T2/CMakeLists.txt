cmake_minimum_required(VERSION 3.24)
project(L2T2)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(L2T2 main.cpp ui/MainWindow.cpp ui/MainWindow.h stack/stack.cpp stack/stack.h stack/bracketItem.h)
target_link_libraries(L2T2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

