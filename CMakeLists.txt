cmake_minimum_required(VERSION 3.17)
project(taskbard C)

set(CMAKE_C_STANDARD 99)

add_executable(taskbard main.c main.h logger.h logger.c stub.h stub.c)