# Sets the minimum version
cmake_minimum_required(VERSION 2.8.1)
project(HELLO)
include_directories(include)
add_subdirectory(leecode)
add_subdirectory(julyex)
#build a variable to save the filename that need build 
set(SRC_LIST main.cpp )
add_executable (hello_bin ${SRC_LIST})
add_compile_options(-std=c++11 g++)
target_link_libraries(hello_bin leecode julyex)
