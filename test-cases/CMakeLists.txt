cmake_minimum_required(VERSION 3.5)

# project(cpp-test-cases VERSION 0.1.0) # 会影响 PROJECT_SOURCE_DIR

option(DEBUG "debug or not" OFF)

if (DEBUG) 
    ADD_DEFINITIONS(-DDEBUG) 
    SET(CMAKE_CXX_FLAGS"${CMAKE_CXX_FLAGS} -g")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer") 
endif()

set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++11 -fPIC -mavx")

find_package(Threads REQUIRED) 
include_directories(${PROJECT_SOURCE_DIR})

# faiss
LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules)
include(${PROJECT_SOURCE_DIR}/cmake/faiss.cmake)
INCLUDE_DIRECTORIES(${FAISS_INCLUDE_DIRS})

# 查找线程库
FIND_PACKAGE(Threads REQUIRED)
# 查找 cuda 依赖
FIND_PACKAGE(CUDA 8 REQUIRED)

# Find all main *.cpp files and store in list mains
file(GLOB_RECURSE mains RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
foreach (mainfile IN LISTS mains)
    # Get file name without directory
    get_filename_component(mainname ${mainfile} NAME_WE) 
    add_executable(${mainname} ${mainfile}) 
    if (${mainname} MATCHES  "yamlcpp_test")
        target_link_libraries(${mainname} libyaml-cpp.so) 
    endif()
    if (${mainname} MATCHES "cuda_test")
        target_link_libraries(${mainname} ${CUDA_LIBRARIES} ${CUDA_CUBLAS_LIBRARIES} ${FAISS_LIBRARIES})
    endif()
endforeach()
