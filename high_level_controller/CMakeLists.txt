cmake_minimum_required(VERSION 3.0.0)

file(GLOB SOURCES 
    src/*.cpp
)

add_library(high_level_controller ${SOURCES})
target_include_directories(high_level_controller PUBLIC ./)

add_subdirectory(test)