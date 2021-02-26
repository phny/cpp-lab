cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

list(APPEND CMAKE_PREFIX_PATH "/usr/local/libtorch")

find_package(Torch REQUIRED)

# Find all main *.cpp files and store in list mains
file(GLOB_RECURSE mains RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
foreach (mainfile IN LISTS mains)
    # Get file name without directory
    get_filename_component(mainname ${mainfile} NAME_WE) 
    add_executable(${mainname} ${mainfile}) 
    target_link_libraries(${mainname} "${TORCH_LIBRARIES}")
    set_property(TARGET ${mainname} PROPERTY CXX_STANDARD 14)
endforeach()
