# 打印当前目录
message("源程序工程当前目录: "  ${CMAKE_CURRENT_SOURCE_DIR})

# 头文件目录
INCLUDE_DIRECTORIES(
    /usr/local/include/
    /usr/include
)

AUX_SOURCE_DIRECTORY(. DIR_SRCS)
add_library(src ${DIR_SRCS})

add_executable(src_sult ${DIR_SRCS})
