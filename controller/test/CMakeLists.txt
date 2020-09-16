cmake_minimum_required(VERSION 3.0.0)

set(ThisTest controller_unit_tests)
set(Sources
    controller_unit_test.cpp
)

add_executable(${ThisTest} ${Sources}) 

target_link_libraries(${ThisTest} PUBLIC
                    gtest_main
                    controller
)

add_test(
    NAME ${ThisTest}
    COMMAND ${ThisTest}
)