cmake_minimum_required(VERSION 3.24)
project(Lab0T1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(untitled main.cpp mainWindow/mainWindow.cpp mainWindow/mainWindow.h figureWindow/figureWindow.cpp figureWindow/figureWindow.h carWindow/carWindow.cpp carWindow/carWindow.h moveRect/moveRect.cpp moveRect/moveRect.h)
target_link_libraries(untitled
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

