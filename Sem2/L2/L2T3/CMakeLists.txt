cmake_minimum_required(VERSION 3.24)
project(L2T3)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(L2T3 main.cpp ui/mainWindow.cpp ui/mainWindow.h stack/stack.h stack/stack.cpp stack/item.h rpe/rpe.cpp rpe/rpe.h)
target_link_libraries(L2T3
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

