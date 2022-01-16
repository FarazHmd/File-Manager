cmake_minimum_required(VERSION 3.16)
project(Rename_OPS C)

set(CMAKE_C_STANDARD 11)

add_library(Rename_OPS SHARED Rename_OPS.c  Rename_OPS.h)