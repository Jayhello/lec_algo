project(lec_algo)

cmake_minimum_required(VERSION 3.5)

add_compile_options(-std=c++11)
add_compile_options(-pthread)

include_directories(./)

add_subdirectory(src)

add_subdirectory(test)
