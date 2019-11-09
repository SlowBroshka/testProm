cmake_minimum_required(VERSION 3.15)
project(testProm)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../out")

set(CMAKE_CXX_STANDARD 14)

add_executable(testProm main.cpp)