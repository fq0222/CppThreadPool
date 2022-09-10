cmake_minimum_required(VERSION 3.0.0)
project(CppThreadPool VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(LIBRARY_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/lib)

include_directories(includes)

file(GLOB SRC_LIST "src/*.cpp")

add_library(CppThreadPool SHARED ${SRC_LIST})
