cmake_minimum_required(VERSION 3.12)
project(Introduction_to_algorithms)

set(CMAKE_CXX_STANDARD 14)
add_executable(array array/main.cpp "../leetcode/217.Contains Duplicate/main.cpp" "../leetcode/217.Contains Duplicate/main.h")
#add_executable(Introduction_to_algorithms billian-sort.cpp)
#add_executable(insert_sort insert_sort.cpp)