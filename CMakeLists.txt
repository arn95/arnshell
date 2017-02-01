cmake_minimum_required(VERSION 3.6)
project(arnshell)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES driver.h driver.c helpers.c helpers.h tokenizer.c tokenizer.h string.c string.h)
add_executable(arnshell ${SOURCE_FILES})