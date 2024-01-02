cmake_minimum_required(VERSION 3.24)
project(L2T1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(L2T1 main.cpp list_of_books/BooksList.cpp list_of_books/BooksList.h list_of_books/BookItem.h ui/mainWindow.cpp ui/mainWindow.h ui/addDialog.cpp ui/addDialog.h ui/searchByIdDialog.cpp ui/searchByIdDialog.h ui/searchByNameAndYear.cpp ui/searchByNameAndYear.h list_of_books/sortBy.cpp)

target_link_libraries(L2T1
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

