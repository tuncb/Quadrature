cmake_minimum_required(VERSION 3.1.2)
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
  ../quadrature/include/quadrature/Gaussian.h
)

add_executable(quadrature-tester ${SOURCE} ${QUADRATURE_LIBRARY})
target_include_directories(quadrature-tester PRIVATE "../quadrature/include/")
conan_target_link_libraries(quadrature-tester)

source_group("quadrature_lib" FILES ${QUADRATURE_LIBRARY})

