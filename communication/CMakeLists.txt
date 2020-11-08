cmake_minimum_required(VERSION 3.0.0)


add_subdirectory(py_binding)
add_test(Name communication
            COMMAND ${PYTHON_EXECUTABLE} -m arduino_connection_usb.py
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
