add_executable(test1 test1.cpp)
target_link_libraries(test1 ${PROJECT_NAME})

add_test(NAME test1 COMMAND test1)
