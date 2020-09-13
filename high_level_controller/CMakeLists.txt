cmake_minimum_required(VERSION 3.0.0)

# set the project name
project(high_level_controller VERSION 0.1.0)


add_executable(high_level_controller src/high_level_controller.cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
