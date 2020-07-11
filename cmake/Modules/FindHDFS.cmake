# - Try to find HDFS

include(FindPackageHandleStandardArgs)

set(HDFS_ROOT_DIR "" CACHE PATH "Folder contains HDFS")

find_path(HDFS_INCLUDE_DIR hdfs.h PATHS ${HDFS_ROOT_DIR}/include)
find_library(HDFS_LIBRARY hdfs PATHS ${HDFS_ROOT_DIR}/lib/native)

find_package_handle_standard_args(HDFS DEFAULT_MSG HDFS_INCLUDE_DIR HDFS_LIBRARY)

if(HDFS_LIBRARY)
	set(HDFS_FOUND TRUE)
    set(HDFS_INCLUDE_DIRS ${HDFS_INCLUDE_DIR})
    set(HDFS_LIBRARIES ${HDFS_LIBRARY})
    message(STATUS "Found hdfs  (include: ${HDFS_INCLUDE_DIR}, library: ${HDFS_LIBRARY})")
    mark_as_advanced(HDFS_LIBRARY_DEBUG HDFS_LIBRARY_RELEASE
                    HDFS_LIBRARY HDFS_INCLUDE_DIR HDFS_ROOT_DIR)
else()
	set(HDFS_FOUND FALSE)
endif()
