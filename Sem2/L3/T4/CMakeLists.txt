cmake_minimum_required(VERSION 3.25)
project(L3T4)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(L3T4 main.cpp ui/mainWindow.cpp ui/mainWindow.h vector/vector.h vector/iterator.h)
target_link_libraries(L3T4
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        ${LIB_PATH}
        )

find_library(LIB_PATH
        NAMES MyVector
        PATHS ${CMAKE_CURRENT_LIST_DIR})

