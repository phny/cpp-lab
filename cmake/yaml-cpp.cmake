include(ExternalProject)

FIND_PACKAGE(YamlCpp)


IF(YamlCpp_FOUND)
    RETURN()
ENDIF()


set(YamlCpp_FOUND TRUE)
# build directory
set(YamlCpp_PREFIX ${CMAKE_BINARY_DIR}/external/prefix/YamlCpp)
# install directory
set(YamlCpp_INSTALL ${CMAKE_BINARY_DIR}/external/install)

set(YamlCpp_INCLUDE_DIRS ${YamlCpp_INSTALL}/include)
set(YamlCpp_LIBRARIES  ${YamlCpp_INSTALL}/lib/libyaml-cpp.so)
set(YamlCpp_LIBRARY_DIRS ${YamlCpp_INSTALL}/lib)
set(YamlCpp_EXTERNAL TRUE)

set(YamlCpp_INCLUDE_DIR ${YamlCpp_INCLUDE_DIRS})
set(YamlCpp_LIBRARY ${YamlCpp_LIBRARIES})

# 如果已经有这个目标，则忽略，防止重复添加这个目标
IF(TARGET YamlCpp)
	RETURN()
ENDIF()

ExternalProject_Add(YamlCpp
		PREFIX ${YamlCpp_PREFIX}
		GIT_REPOSITORY "https://github.com/jbeder/yaml-cpp.git"
		GIT_TAG "yaml-cpp-0.6.2"
		TIMEOUT 100
		UPDATE_COMMAND ""
		INSTALL_DIR ${YamlCpp_INSTALL}
		CMAKE_ARGS -DBUILD_SHARED_LIBS=ON -DCMAKE_INSTALL_PREFIX=${YamlCpp_INSTALL}
		BUILD_IN_SOURCE 1
		BUILD_COMMAND make
		LOG_DOWNLOAD 1
		LOG_CONFIGURE 1
		LOG_BUILD 1
		LOG_INSTALL 1
		)

