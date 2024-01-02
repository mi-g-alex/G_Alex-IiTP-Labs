cmake_minimum_required(VERSION 3.24)
project(Lab0T2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Lab0T2 main.cpp mainWindow/mainWindow.cpp mainWindow/mainWindow.h figures/figureSquare.cpp figures/figureSquare.h figures/figures.cpp figures/figures.h figures/figureCircle.cpp figures/figureCircle.h figures/figureRhombus.cpp figures/figureRhombus.h figures/figureStar/star_5.cpp figures/figureStar/star_5.h figures/figureStar/star.cpp figures/figureStar/star.h figures/figureStar/star_6.cpp figures/figureStar/star_6.h figures/figureStar/star_7.cpp figures/figureStar/star_7.h figures/figureStar/star_8.cpp figures/figureStar/star_8.h figures/figureHexagon.cpp figures/figureHexagon.h figures/figurePolyline.cpp figures/figurePolyline.h figures/figureTriangle.cpp figures/figureTriangle.h)
target_link_libraries(Lab0T2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

