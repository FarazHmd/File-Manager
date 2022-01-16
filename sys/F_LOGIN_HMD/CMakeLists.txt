cmake_minimum_required(VERSION 3.16)
project(F_LOGIN_HMD C)

set(CMAKE_C_STANDARD 11)

add_library(F_LOGIN_HMD SHARED LOGIN.c LOGIN.h)