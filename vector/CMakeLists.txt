cmake_minimum_required(VERSION 3.5)

if (CMAKE_BUILD_TYPE) 
    ADD_DEFINITIONS(-DDEBUG) 
    SET(CMAKE_CXX_FLAGS"${CMAKE_CXX_FLAGS} -g")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer") 
endif()

set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++11 -fPIC -mavx")

find_package(Threads REQUIRED) 
include_directories("${PROJECT_BINARY_DIR}")

# 查找线程库
FIND_PACKAGE(Threads REQUIRED)

#Find all main *.cpp files and store in list mains
file(GLOB_RECURSE mains RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
foreach (mainfile IN LISTS mains)
    #Get file name without directory
    get_filename_component(mainname ${mainfile} NAME_WE) 
    add_executable(${mainname} ${mainfile}) 
    # target_link_libraries(${mainname} ${CMAKE_THREAD_LIBS_INIT})
endforeach()
