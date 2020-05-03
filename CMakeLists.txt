cmake_minimum_required(VERSION 3.5)

project(cpp-learning)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++11 -fPIC -mavx")

IF (CMAKE_BUILD_TYPE)
    IF (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
        message("****build in debug mode****")
        SET(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)
        SET(CMAKE_C_OUTPUT_EXTENSION_REPLACE 1)
        SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -std=c++11 -g -ggdb -O0 --coverage -fprofile-arcs -ftest-coverage")
        SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -ggdb -O0 --coverage -fprofile-arcs -ftest-coverage")
    ENDIF()
ENDIF()

# 获取当前目录下的所有子目录夹宏
MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

# 获取所有子目录
SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})

# 移除不相关的文件夹
list(REMOVE_ITEM SUBDIRS ".git" ".vscode" "build")

# 添加所有的子目录
foreach(subdirectory  ${SUBDIRS})
    add_subdirectory(${subdirectory})
endforeach()

