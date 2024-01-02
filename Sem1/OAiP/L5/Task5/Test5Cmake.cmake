add_executable(Test_5 ${CMAKE_CURRENT_LIST_DIR}/g_test/Test5.cpp ${CMAKE_CURRENT_LIST_DIR}/g_test/Test5Code.cpp)

target_link_libraries(Test_5 gmock pthread)