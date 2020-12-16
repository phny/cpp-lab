cmake_minimum_required(VERSION 3.5)

if (CMAKE_BUILD_TYPE) 
    ADD_DEFINITIONS(-DDEBUG) 
    SET(CMAKE_CXX_FLAGS"${CMAKE_CXX_FLAGS} -g")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer") 
endif()

# 设置C++标记
set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++11 -fPIC -mavx")

# 所有的其他依赖链接库
SET(OTHER_DEPENDENCIES "")

# 查找线程库
find_package(Threads REQUIRED) 
include_directories(${PROJECT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR})
LIST(APPEND OTHER_DEPENDENCIES ${CMAKE_THREAD_LIBS_INIT})

# faiss 的依赖
LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules)
FIND_PACKAGE(Faiss REQUIRED)
INCLUDE_DIRECTORIES(${FAISS_INCLUDE_DIRS})
LIST(APPEND OTHER_DEPENDENCIES ${FAISS_LIBRARIES})

INCLUDE_DIRECTORIES(${CMAKE_PROJECT_SOURCE_DIR}/utils)


# Find all main *.cpp files and store in list mains
file(GLOB_RECURSE mains RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
foreach (mainfile IN LISTS mains)
    # Get file name without directory
    get_filename_component(mainname ${mainfile} NAME_WE) 
    add_executable(${mainname} ${mainfile}) 
    target_link_libraries(${mainname} ${OTHER_DEPENDENCIES})
endforeach()
