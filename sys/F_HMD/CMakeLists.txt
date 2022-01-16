cmake_minimum_required(VERSION 3.16)
project(F_HMD C)

set(CMAKE_C_STANDARD 11)

add_library(F_HMD SHARED EXT_OPS.c EXT_OPS.h)