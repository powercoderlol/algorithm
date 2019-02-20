project(strings-lib)
cmake_minimum_required(VERSION 3.10)

set(ALGORITHMS_ON_STRINGS_LIB_SRC
  longest_common_substring/LongestSubstring.h
  longest_common_substring/LongestSubstring.cpp
)

add_library(${PROJECT_NAME} STATIC ${ALGORITHMS_ON_STRINGS_LIB_SRC})
target_include_directories(${PROJECT_NAME}
  PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/longest_common_substring>)

set_property(TARGET ${PROJECT_NAME} PROPERTY LINKER_LANGUAGE CXX)
