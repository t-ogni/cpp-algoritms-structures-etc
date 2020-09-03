cmake_minimum_required(VERSION 3.0)

set (CMAKE_CXX_STANDARD 17)

project(test)
include_directories(sort-algoritms)

file(GLOB helloworld_SRC
        "sort-algoritms/*.h"
        "sort-algoritms/*.cpp"
        )

add_executable(main main.cpp ${helloworld_SRC})
