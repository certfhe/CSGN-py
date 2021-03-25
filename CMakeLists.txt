cmake_minimum_required(VERSION 3.7 FATAL_ERROR)

## Use -std=c++11 as default.
set(CMAKE_CXX_STANDARD 11)
## Disable C++ extensions
set(CMAKE_CXX_EXTENSIONS OFF)
## Require full C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(externals/pybind11)
add_subdirectory(externals/certfhe.git)

include_directories(externals/certfhe.git/src/)
pybind11_add_module(certfhepy certfhe-py/certfhe11_wrapper.cpp externals/certfhe.git/src/Context.cpp)
