add_executable(Test_3 ${CMAKE_CURRENT_LIST_DIR}/g_test/Test3.cpp ${CMAKE_CURRENT_LIST_DIR}/g_test/Test3Code.cpp)

target_link_libraries(Test_3 gmock pthread)