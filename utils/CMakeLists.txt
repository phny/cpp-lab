cmake_minimum_required(VERSION 3.5)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++11 -fPIC -mavx")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(srcs 
    ${CMAKE_CURRENT_SOURCE_DIR}/io_utils.hpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/date_utils.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/random_utils.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/string_utils.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/thread_safe_queue.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/timer.hpp)

# 获取当前文件夹的名字
# GET_FILENAME_COMPONENT(dir_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)

add_library(utils SHARED ${srcs})

set_target_properties(utils PROPERTIES LINKER_LANGUAGE CXX)