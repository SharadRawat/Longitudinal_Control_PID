cmake_minimum_required(VERSION 3.0.0)

set(ThisTest high_level_controller_unit_tests)
set(Sources
    high_level_controller_unit_test.cpp
)

add_executable(${ThisTest} ${Sources}) 

target_link_libraries(${ThisTest} PUBLIC
                    gtest_main
                    high_level_controller
)

add_test(
    NAME ${ThisTest}
    COMMAND ${ThisTest}
)