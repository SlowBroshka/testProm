cmake_minimum_required(VERSION 3.15)
project(testProm)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../out")

set(CMAKE_CXX_STANDARD 14)


add_executable(server server/main.cpp common/CmdArgs.h common/CmdArgs.cpp common/ClientSocket.cpp common/ClientSocket.h common/Socket.cpp common/Socket.h common/ServerSocket.cpp common/ServerSocket.h)

add_executable(client client/main.cpp common/CmdArgs.h common/CmdArgs.cpp common/ClientSocket.cpp common/ClientSocket.h common/Socket.cpp common/Socket.h common/ServerSocket.cpp common/ServerSocket.h)

