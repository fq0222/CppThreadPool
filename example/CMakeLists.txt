cmake_minimum_required(VERSION 3.0.0)
project(threadPoolTest VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/)

link_directories( ${PROJECT_SOURCE_DIR}/../lib/)

include_directories(${PROJECT_SOURCE_DIR}/../includes)

add_executable(threadPoolTest main.cpp)
target_link_libraries(threadPoolTest CppThreadPool)
