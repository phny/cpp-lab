include(ExternalProject)

FIND_PACKAGE(HDFS)

IF(NOT HDFS_FOUND)
    EXECUTE_PROCESS(COMMAND mkdir -p external/install/lib WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
	EXECUTE_PROCESS(COMMAND wget -O libhdfs.so http://file.intra.sensetime.com/f/b379ced37b/?raw=1 WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/external/install/lib
					COMMAND ln -s libhdfs.so libhdfs.so.0.0.0 WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/external/install/lib)
	# install directory
	set(HDFS_INSTALL ${CMAKE_BINARY_DIR}/external/install/)

	# 先设置好这些环境变量，后面再 FIND_PACKAGE 就能找到
	set(HDFS_FOUND TRUE)
	set(HDFS_LIBRARIES  ${HDFS_INSTALL}/lib/libhdfs.so)
	set(HDFS_LIBRARY_DIRS ${HDFS_INSTALL}/lib)

	set(HDFS_LIBRARY ${HDFS_LIBRARIES})

ENDIF()