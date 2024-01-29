cmake_minimum_required(VERSION 3.0.2)
project(T125)


IF(NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE Debug)
ENDIF()
MESSAGE("Build type: " ${CMAKE_BUILD_TYPE})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
message("c++ std: " ${CMAKE_CXX_FLAGS} )


###########
## Build ##
###########
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib) # 设置静态库文件目录
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib) # 设置动态库文件目录

add_executable(T125_1
    ./T125_1.cpp

)
add_executable(T125_2
        ./T125_2.cpp
)
