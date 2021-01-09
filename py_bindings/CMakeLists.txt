cmake_minimum_required(VERSION 3.0.0)

set(ThisBinding py_controller_binding)

find_package(PythonLibs 3.6 REQUIRED)
find_package(Boost COMPONENTS python REQUIRED)

set(CMAKE_SHARED_MODULE_PREFIX "")

add_library(${ThisBinding} MODULE py_controller_binding.cpp)
target_link_libraries(${ThisBinding} ${Boost_LIBRARIES} ${PYTHON_LIBRARIES} longitudinal_control_pid)
target_include_directories(${ThisBinding} PRIVATE ${PYTHON_INCLUDE_DIRS})
