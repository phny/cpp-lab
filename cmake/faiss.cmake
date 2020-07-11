include(ExternalProject)

FIND_PACKAGE(Faiss)

IF(NOT FAISS_FOUND)
    # build directory
    set(faiss_PREFIX ${CMAKE_BINARY_DIR}/external/prefix/faiss)
    set(faiss_SRC_PREFIX ${faiss_PREFIX}/src/faiss)
    # install directory
    set(faiss_INSTALL ${CMAKE_BINARY_DIR}/external/install)

    set(FAISS_FOUND TRUE)
    set(FAISS_INCLUDE_DIRS ${faiss_INSTALL}/include)
    set(FAISS_LIBRARIES ${faiss_INSTALL}/lib/libfaiss.so)
    set(FAISS_LIBRARY_DIRS ${faiss_INSTALL}/lib)
    set(FAISS_EXTERNAL TRUE)

    set(FAISS_INCLUDE_DIR ${faiss_INSTALL}/include)
    set(FAISS_LIBRARY ${faiss_INSTALL}/lib/libfaiss.so)
ELSE()
    RETURN()
ENDIF()

# build directory
set(faiss_PREFIX ${CMAKE_BINARY_DIR}/external/prefix/faiss)
set(faiss_SRC_PREFIX ${faiss_PREFIX}/src/faiss)
# install directory
set(faiss_INSTALL ${CMAKE_BINARY_DIR}/external/install)

set(FAISS_FOUND TRUE)
set(FAISS_INCLUDE_DIRS ${faiss_INSTALL}/include)
set(FAISS_LIBRARIES ${faiss_INSTALL}/lib/libfaiss.so)
set(FAISS_LIBRARY_DIRS ${faiss_INSTALL}/lib)
set(FAISS_EXTERNAL TRUE)

set(FAISS_INCLUDE_DIR ${faiss_INSTALL}/include)
set(FAISS_LIBRARY ${faiss_INSTALL}/lib/libfaiss.so)

# 如果已经有这个目标，则忽略，防止重复添加这个目标
IF(TARGET faiss)
    RETURN()
ENDIF()

set(FAISS_CXX_FLAGS ${CMAKE_CXX_FLAGS})
set(FAISS_C_FLAGS ${CMAKE_C_FLAGS})


FIND_PACKAGE(CUDA 10 REQUIRED)
INCLUDE_DIRECTORIES(${CUDA_INCLUDE_DIRS})

SET(CUDA_ARCH "")
IF(${CUDA_VERSION_MAJOR} VERSION_GREATER "7")
    SET(CUDA_ARCH "${CUDA_ARCH} -gencode arch=compute_61,code=sm_61")
ENDIF()
IF(${CUDA_VERSION_MAJOR} VERSION_GREATER "8")
    SET(CUDA_ARCH "${CUDA_ARCH} -gencode arch=compute_70,code=sm_70")
ENDIF()
IF(${CUDA_VERSION_MAJOR} VERSION_GREATER "9")
    SET(CUDA_ARCH "${CUDA_ARCH} -gencode arch=compute_72,code=sm_72 -gencode arch=compute_75,code=sm_75")
ENDIF()
SET(CUDA_PROPAGATE_HOST_FLAGS OFF)

ExternalProject_Add(faiss
    PREFIX ${faiss_PREFIX}
    GIT_REPOSITORY "git@gitlab.sz.sensetime.com:cstk/faiss.git"
    GIT_TAG v1.5.3
    UPDATE_COMMAND ""
    INSTALL_DIR ${faiss_INSTALL}
    CONFIGURE_COMMAND ${faiss_PREFIX}/src/faiss/configure --prefix=${faiss_INSTALL} --with-cuda=${CUDA_TOOLKIT_ROOT_DIR} "--with-cuda-arch=${CUDA_ARCH}"
    BUILD_IN_SOURCE 1
    BUILD_COMMAND make
    LOG_DOWNLOAD 1
    LOG_CONFIGURE 1
    LOG_BUILD 1
    LOG_INSTALL 1
    )
