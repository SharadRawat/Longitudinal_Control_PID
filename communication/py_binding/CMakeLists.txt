cmake_minimum_required(VERSION 3.0.0)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 

set(ThisBinding py_binding)

find_package(Python REQUIRED COMPONENTS Development)
find_package(Boost 1.67.0 COMPONENTS python38 REQUIRED python) 

include_directories(${Boost_INCLUDE_DIRS}) 
add_library(${ThisBinding} SHARED MODULE py_binding.cpp)
target_link_libraries(${ThisBinding} PUBLIC Python::Python Boost::python Boost::dynamic_linking)
target_link_libraries(${ThisBinding} PUBLIC ${Boost_LIBRARIES} longitudinal_control_pid)
target_include_directories(${ThisBinding} PUBLIC ${PYTHON_INCLUDE_DIRS})