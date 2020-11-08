cmake_minimum_required(VERSION 3.0.0)

# set the project name
project(longitudinal_control_pid CXX)

# Set some global variables
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()
add_subdirectory(googletest)

file(GLOB SOURCES 
    src/*.cpp
)

file(GLOB HEADERS 
    include/*.h
)

add_library(longitudinal_control_pid ${SOURCES})

target_include_directories(longitudinal_control_pid PUBLIC ./)

add_subdirectory(test)
add_subdirectory(communication)