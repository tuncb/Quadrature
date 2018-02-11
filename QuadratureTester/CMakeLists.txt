project(quadrature-tester CXX)
cmake_minimum_required(VERSION 2.8.12)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE SRC_TESTING
    "./src/*.cpp"
    "./src/*.h"
)
file(GLOB_RECURSE SRC_SQUANCH
    "../include/quadrature/*.cpp"
    "../include/quadrature/*.h"
)

add_executable(quadrature-tester ${SRC_TESTING} ${SRC_SQUANCH})

target_link_libraries(quadrature-tester ${CONAN_LIBS})
target_include_directories(quadrature-tester PRIVATE "../include/")

source_group("quadrature" FILES ${SRC_SQUANCH})

