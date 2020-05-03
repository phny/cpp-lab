cmake_minimum_required(VERSION 3.5)

project(myloger)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++11 -fPIC -mavx")

set(src
    ./mytemplate.cpp
    )

add_executable(my_stack ${src})

