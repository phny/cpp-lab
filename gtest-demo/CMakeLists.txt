# 工程名
set (PROJECT_NAME my-gtest)
PROJECT(${PROJECT_NAME})
SET(CMAKE_C_COMPILER "g++")  #选择编译器，默认是gcc

message("工程名: " ${PROJECT_NAME})
message("工程目录: " ${PROJECT_SOURCE_DIR})

# 最低版本需求
cmake_minimum_required(VERSION 2.8)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
set (LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

message("编译后可执行程序目录: " ${EXECUTABLE_OUTPUT_PATH})
message("编译后库程序文件目录: " ${LIBRARY_OUTPUT_PATH})

ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(gtest)
