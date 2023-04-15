add_executable(Test_4 ${CMAKE_CURRENT_LIST_DIR}/g_test/Test4.cpp ${CMAKE_CURRENT_LIST_DIR}/g_test/Test4Code.cpp)

target_link_libraries(Test_4 gmock pthread)