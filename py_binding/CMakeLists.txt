cmake_minimum_required(VERSION 3.0.0)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 

set(ThisBinding py_binding)

find_package(Boost 1.45.0 COMPONENTS *boost libraries here*) 

include_directories(${Boost_INCLUDE_DIRS}) 
add_executable(${ThisBinding} py_binding.cpp) 
target_link_libraries(${ThisBinding} PUBLIC ${Boost_LIBRARIES})



