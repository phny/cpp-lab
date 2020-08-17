cmake_minimum_required(VERSION 3.5)

project(pybind11-cases VERSION 0.1.0)

option(DEBUG "debug or not" OFF)

IF (DEBUG) 
    ADD_DEFINITIONS(-DDEBUG) 
    SET(CMAKE_CXX_FLAGS"${CMAKE_CXX_FLAGS} -g")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer") 
ENDIF()

set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++11 -fPIC -mavx")

find_package(PythonInterp 3 REQUIRED)

# 添加 pybind11 源码目录
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/pybind11)

include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/pybind11/)

# Find all main *.cpp files and store in list mains
file(GLOB mains RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
foreach (mainfile IN LISTS mains)
    # Get file name without directory
    get_filename_component(mainname ${mainfile} NAME_WE) 
    pybind11_add_module(${mainname} ${mainfile})
endforeach()
