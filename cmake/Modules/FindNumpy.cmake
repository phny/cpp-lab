# - Try to find Numpy
#
# The following variables are optionally searched for defaults
#  Numpy_ROOT_DIR:            Base directory where all Numpy components are found
#
# The following are set after configuration is done:
#  Numpy_FOUND
#  Numpy_INCLUDE_DIRS
#  Numpy_LIBRARIES
#  Numpy_LIBRARY_DIRS

include(FindPackageHandleStandardArgs)

set(Numpy_ROOT_DIR "" CACHE PATH "Folder contains Numpy")

if (Numpy_ROOT_DIR STREQUAL "")
  find_package(PythonInterp 3 REQUIRED)
  find_package(PythonLibs 3 REQUIRED)
  message(STATUS "Found Python libs: ${PYTHON_LIBRARIES} (found version \"${PYTHON_VERSION_STRING}\")")
  get_filename_component(PARENT_DIR ${PYTHON_LIBRARIES} DIRECTORY)
  SET(Numpy_ROOT_DIR "${PARENT_DIR}/python${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR}/site-packages/numpy/core")
endif()

find_path(Numpy_INCLUDE_DIR numpy/arrayobject.h PATHS ${Numpy_ROOT_DIR}/include)
find_library(Numpy_LIBRARY npymath PATHS ${Numpy_ROOT_DIR}/lib)

find_package_handle_standard_args(Numpy DEFAULT_MSG Numpy_INCLUDE_DIR Numpy_LIBRARY)


if(Numpy_FOUND)
    set(Numpy_INCLUDE_DIRS ${Numpy_INCLUDE_DIR})
    set(Numpy_LIBRARIES ${Numpy_LIBRARY})
    message(STATUS "Found Numpy  (include: ${Numpy_INCLUDE_DIR}, library: ${Numpy_LIBRARY})")
    mark_as_advanced(Numpy_LIBRARY_DEBUG Numpy_LIBRARY_RELEASE
                     Numpy_LIBRARY Numpy_INCLUDE_DIR Numpy_ROOT_DIR)
endif()