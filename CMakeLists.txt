cmake_minimum_required(VERSION 3.10)

project(code_log)

# 设置C++标准
set(CMAKE_CXX_STANDARD 14)

# 遍历所有子目录下的cpp文件
file(GLOB_RECURSE SOURCES "*.cpp")

# 遍历SOURCES列表，为每个.cpp文件创建一个可执行文件
foreach(SOURCE_FILE ${SOURCES})
    # 获取文件的父目录名称
    get_filename_component(PARENT_DIR ${SOURCE_FILE} DIRECTORY)
    # 去除父目录的路径，只保留目录名
    string(REPLACE "${CMAKE_SOURCE_DIR}/" "" PARENT_DIR ${PARENT_DIR})
    string(REPLACE "/" "" PARENT_DIR ${PARENT_DIR})
    message("DIR ${PARENT_DIR}")
    # 获取文件名，去掉.cpp后缀
    get_filename_component(EXECUTABLE_NAME ${SOURCE_FILE} NAME_WE)
    # 将父目录名称和文件名结合作为可执行文件的名称
    set(EXECUTABLE_NAME "${PARENT_DIR}_${EXECUTABLE_NAME}")
    # 编译每个.cpp文件为一个独立的可执行文件\
    message("make ${EXECUTABLE_NAME}")
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE})
endforeach()