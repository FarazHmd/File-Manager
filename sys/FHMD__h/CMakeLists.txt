cmake_minimum_required(VERSION 3.16)
project(FHMD__h C)

set(CMAKE_C_STANDARD 11)

add_library(FHMD__h SHARED DIR_OPS.c DIR_OPS.h)