cmake_minimum_required(VERSION 3.0.0)
project(cmaketest VERSION 0.1.0)

include_directories("${PROJECT_BINARY_DIR}")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++11 -fPIC -mavx")

# Find all main*.cpp files and store in list mains
file(GLOB_RECURSE mains RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
foreach(mainfile IN LISTS mains)
    # Get file name without directory
    get_filename_component(mainname ${mainfile} NAME_WE)
    add_executable(${mainname} ${mainfile})
endforeach()
