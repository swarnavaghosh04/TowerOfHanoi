cmake_minimum_required(VERSION 3.0.0)
project(examples VERSION 0.1.0)

find_package(CMakeTemplate REQUIRED)

add_executable(example1 example1.cpp)
target_link_libraries(example1 CMakeTemplate::CMakeTemplate)
