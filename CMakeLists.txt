project(algorithms)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR})

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

message(STATUS "cmake module path: ${CMAKE_MODULE_PATH}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

add_subdirectory(algorithms_on_strings)
add_subdirectory(sorting_algorithms)
add_subdirectory(tests)



