find_library(LIB_PATH
        NAMES Task1
        PATH_SUFFIXES lib
        PATHS ${CMAKE_CURRENT_LIST_DIR})

add_executable(Task_1 Task1/1.cpp ../checkInput/checkInput.cpp ../checkInput/checkInput.h)
target_link_libraries(Task_1 ${LIB_PATH})