cmake_minimum_required(VERSION 3.10)
project(darray_bigint)

set(CMAKE_CXX_STANDARD 11)

add_executable(darray_bigint main.cpp source/darray/darray.hpp tests/darray/darray_tests.cpp tests/darray/darray_tests.h source/bigint/bigint.cpp source/bigint/bigint.h tests/bigint/bigint_tests.cpp tests/bigint/bigint_tests.h)