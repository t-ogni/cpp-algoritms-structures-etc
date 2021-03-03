cmake_minimum_required(VERSION 3.0)

set (CMAKE_CXX_STANDARD 17)

project(cpp-files)

include_directories(.)

add_executable(${PROJECT_NAME}  main.cpp)
