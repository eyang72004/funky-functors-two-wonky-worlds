cmake_minimum_required(VERSION 3.20)

project(funky_functors_two_worlds CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include headers in "include/"
include_directories(${CMAKE_SOURCE_DIR}/include)

# ---- Demos (binaries you can run) ----

add_executable(cpp_functors_demo
    src/cpp_functors_demo.cpp
)

add_executable(covariant_functors_demo
    src/covariant_functors_demo.cpp
)

add_executable(contravariant_functors_demo
    src/contravariant_functors_demo.cpp
)

add_executable(subfunctors_demo
    src/subfunctors_demo.cpp
)

add_executable(category_diagrams_demo
    src/category_diagrams_demo.cpp
)

# ---- Tests ----

enable_testing()

add_executable(functor_laws_tests
    tests/test_functor_laws.cpp
)

add_test(
    NAME functor_laws_tests
    COMMAND functor_laws_tests
)
