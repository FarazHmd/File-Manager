cmake_minimum_required(VERSION 3.16)
project(Attrib_h C)

set(CMAKE_C_STANDARD 11)

add_library(Attrib_h library.c Attrib.h)