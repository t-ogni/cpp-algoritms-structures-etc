cmake_minimum_required(VERSION 3.0)

set (CMAKE_CXX_STANDARD 17)

project(main)

set(dir "5. Cryptographic Functions")

include_directories(${dir})

file(GLOB dir_SRC
        "${dir}/*.h"
        "${dir}/*.cpp"
        )

add_executable(main main.cpp ${dir_SRC})
