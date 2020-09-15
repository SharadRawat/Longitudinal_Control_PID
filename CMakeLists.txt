cmake_minimum_required(VERSION 3.0.0)

# set the project name
project(longitudinal_control_pid CXX)

# Set some global variables
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()
add_subdirectory(googletest)

set(SOURCES longitudinal_control_pid.cpp) 

add_library(longitudinal_control_pid ${SOURCES})

add_subdirectory(high_level_controller)