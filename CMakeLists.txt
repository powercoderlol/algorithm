project(algorithms)
cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR})

message(STATUS "cmake module path: ${CMAKE_MODULE_PATH}")

# download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE    result
  WORKING_DIRECTORY  ${CMAKE_BINARY_DIR}/googletest-download)

if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src" "${CMAKE_BINARY_DIR}/googletest-build")

if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

enable_testing()

include(Sources)

add_library(algorithms_on_strings_lib STATIC ${ALGORITHMS_ON_STRINGS_LIB})
target_include_directories(algorithms_on_strings_lib
  PUBLIC
  algorithms_on_strings/longest_common_string)

SET(GTEST_LIBS gtest gtest_main)
SET(ALGO_LIBS algorithms_on_strings_lib)

#message(STATUS "ALGO_LIBS: ${ALGO_LIBS}")
message(STATUS "GTEST_LIBS: ${GTEST_LIBS}")

add_executable(smoke-test-longest-substring tests/smoke-test-longest-substring.cpp)
target_link_libraries(smoke-test-longest-substring ${GTEST_LIBS})
target_link_libraries(smoke-test-longest-substring ${ALGO_LIBS})

add_test(NAME longest-substring-test COMMAND smoke-test-longest-substring)


