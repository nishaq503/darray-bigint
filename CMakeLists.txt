cmake_minimum_required(VERSION 3.10)
project(darray_bigint)

set(CMAKE_CXX_STANDARD 11)

add_executable(darray_bigint main.cpp source/darray.hpp tests/darray_tests.cpp tests/darray_tests.h source/bigint.cpp source/bigint.h tests/bigint_tests.cpp tests/bigint_tests.h)