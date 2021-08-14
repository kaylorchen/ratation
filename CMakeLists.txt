cmake_minimum_required(VERSION 3.10)
project(rotation)
add_executable(rotation main.c rotation.c)
target_link_libraries(rotation m)