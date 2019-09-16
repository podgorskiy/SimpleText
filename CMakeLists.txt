cmake_minimum_required (VERSION 3.1 FATAL_ERROR)
project (SimpleText)

option(SIMPLE_TEXT_EXAMPLES "Build SimpleText examples" OFF)
option(SIMPLE_TEXT_TESTS "Build SimpleText tests" OFF)

include_directories(include)

if (SIMPLE_TEXT_EXAMPLES OR SIMPLE_TEXT_TESTS)
    configure_file(examples/libs/CMakeLists.txt.in examples/libs/CMakeLists.txt)
    execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/examples/libs/")
    execute_process(COMMAND "${CMAKE_COMMAND}" --build .
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/examples/libs/" )
endif()

if (SIMPLE_TEXT_EXAMPLES)
    add_subdirectory(examples)
endif()
