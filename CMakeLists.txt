cmake_minimum_required(VERSION 3.16)
project(File_Manager C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Build")
add_executable(File_Manager main.c)
