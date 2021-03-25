cmake_minimum_required(VERSION 3.7 FATAL_ERROR)

## Use -std=c++11 as default.
set(CMAKE_CXX_STANDARD 11)
## Disable C++ extensions
set(CMAKE_CXX_EXTENSIONS OFF)
## Require full C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(externals/pybind11)
add_subdirectory(externals/certfhe)

SET(LIBCERTFHE_PRJ externals/certfhe)
SET(LIBCERTFHE_INCLUDE_DIR ${LIBCERTFHE_PRJ}/src/)
SET(LIBCERTFHE_SOURCES 
    ${LIBCERTFHE_PRJ}/src/Context.cpp
    ${LIBCERTFHE_PRJ}/src/SecretKey.cpp
    ${LIBCERTFHE_PRJ}/src/Ciphertext.cpp
    ${LIBCERTFHE_PRJ}/src/Plaintext.cpp
    ${LIBCERTFHE_PRJ}/src/Permutation.cpp
    ${LIBCERTFHE_PRJ}/src/Helpers.cpp
    ${LIBCERTFHE_PRJ}/src/Timer.cpp
)

include_directories(${LIBCERTFHE_INCLUDE_DIR})

pybind11_add_module(certfhepy
        certfhe-py/certfhe11_wrapper.cpp 
        ${LIBCERTFHE_SOURCES}
    )
