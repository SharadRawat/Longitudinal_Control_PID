cmake_minimum_required(VERSION 3.0.0)

file(GLOB SOURCES 
    src/*.cpp
)

add_library(controller ${SOURCES})
target_include_directories(controller PUBLIC ./)

add_subdirectory(test)