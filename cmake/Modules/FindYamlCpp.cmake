# - Try to find YamlCpp
#
# The following variables are optionally searched for defaults
#  YamlCpp_ROOT_DIR:            Base directory where all FAISS components are found
#
# The following are set after configuration is done:
#  YamlCpp_FOUND
#  YamlCpp_INCLUDE_DIRS
#  YamlCpp_LIBRARIES
#  YamlCpp_LIBRARYRARY_DIRS

include(FindPackageHandleStandardArgs)

set(YamlCpp_ROOT_DIR "" CACHE PATH "Folder contains YamlCpp")

find_path(YamlCpp_INCLUDE_DIR yaml-cpp/yaml.h PATHS ${YamlCpp_ROOT_DIR}/include)
find_library(YamlCpp_LIBRARY yaml-cpp PATHS ${YamlCpp_ROOT_DIR}/lib)

find_package_handle_standard_args(YamlCpp DEFAULT_MSG YamlCpp_INCLUDE_DIR YamlCpp_LIBRARY)

if(YamlCpp_LIBRARY)
	set(YamlCpp_FOUND TRUE)
    set(YamlCpp_INCLUDE_DIRS ${YamlCpp_INCLUDE_DIR})
    set(YamlCpp_LIBRARIES ${YamlCpp_LIBRARY})
    message(STATUS "Found yaml-cpp  (include: ${YamlCpp_INCLUDE_DIR}, library: ${YamlCpp_LIBRARY})")
    mark_as_advanced(YamlCpp_LIBRARY_DEBUG YamlCpp_LIBRARY_RELEASE
                     YamlCpp_LIBRARY YamlCpp_INCLUDE_DIR YamlCpp_ROOT_DIR)
else()
	set(YamlCpp_FOUND FALSE)
endif()
