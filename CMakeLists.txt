cmake_minimum_required(VERSION 3.16.3)
project(algorithm LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置可执行文件输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)

add_library(algorithm_lib INTERFACE)

target_include_directories(algorithm_lib
        INTERFACE
        ${PROJECT_SOURCE_DIR}/src
)

enable_testing()
add_subdirectory(src/test)