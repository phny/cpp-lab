cmake_minimum_required(VERSION 3.5)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++11 -fPIC -mavx")

# 添加当前的 include 目录
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

# 获取当前文件夹名称
GET_FILENAME_COMPONENT(dir_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# 获取所有子目录下的源文件
FILE(GLOB_RECURSE src_files ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC)

add_executable(${dir_name} ${src_files})

