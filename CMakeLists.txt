cmake_minimum_required(VERSION 3.16.3)
project(algorithm LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(algorithm_lib INTERFACE)

target_include_directories(algorithm_lib
        INTERFACE
        ${PROJECT_SOURCE_DIR}/src
)

enable_testing()
add_subdirectory(src/test)