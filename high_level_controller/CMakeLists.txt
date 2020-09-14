cmake_minimum_required(VERSION 3.0.0)

# set the project name
project(high_level_controller VERSION 0.1.0)


add_library(high_level_controller_impl src/high_level_controller.cpp)

add_executable(high_level_controller main.cpp)

target_link_libraries(high_level_controller PUBLIC high_level_controller_impl)
target_include_directories(high_level_controller PUBLIC include)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Testing
# Use gtest
include(ExternalProject)
ExternalProject_Add(googletest
  GIT_REPOSITORY    https://github.com/google/googletest.git
  GIT_TAG           master
  SOURCE_DIR        "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
  BINARY_DIR        "${CMAKE_CURRENT_BINARY_DIR}/googletest-build"
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)

# Add test executable target
add_executable(MainTest ${PROJECT_SOURCE_DIR}/main.cpp)

# Create dependency of MainTest on googletest
add_dependencies(MainTest googletest)
