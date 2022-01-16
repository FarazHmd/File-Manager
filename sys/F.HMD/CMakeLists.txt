cmake_minimum_required(VERSION 3.16)
project(F_HMD C)

set(CMAKE_C_STANDARD 11)

add_library(F_HMD SHARED FILE_OPS_DEL.c FILE_OPS_DEL.h)