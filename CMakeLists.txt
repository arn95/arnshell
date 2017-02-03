cmake_minimum_required(VERSION 3.6)
project(arnshell)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES driver.h driver.c helpers.c helpers.h string.c string.h)

add_executable(arnshell ${SOURCE_FILES})