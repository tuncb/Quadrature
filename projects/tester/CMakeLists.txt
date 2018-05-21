cmake_minimum_required(VERSION 3.10.0)
project(quadrature-tester CXX)

include(../../conan.cmake)
conan_cmake_run(BASIC_SETUP CMAKE_TARGETS CONAN_CMAKE_MULTI
  REQUIRES
  "catch2/2.2.2@bincrafters/stable"
)

set(SOURCE 
  ./source/main.cpp
)

set(QUADRATURE_LIBRARY 
  ../quadrature/include/quadrature/quadrature.h
  ../quadrature/include/quadrature/gaussian.h
)

add_executable(quadrature-tester ${SOURCE} ${QUADRATURE_LIBRARY})
target_include_directories(quadrature-tester PRIVATE "../quadrature/include/")
conan_target_link_libraries(quadrature-tester)

source_group("quadrature_lib" FILES ${QUADRATURE_LIBRARY})

set_target_properties(quadrature-tester PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

