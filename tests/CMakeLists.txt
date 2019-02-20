project(strings-test)
cmake_minimum_required(VERSION 3.10)

add_executable(${PROJECT_NAME}
  smoke-test-longest-substring.cpp
)

add_dependencies(${PROJECT_NAME} strings-lib)

message(STATUS "cmake current source dir: ${CMAKE_CURRENT_SOURCE_DIR}")

target_include_directories(${PROJECT_NAME}
  PRIVATE
    ${CONAN_INCLUDE_DIRS_GTEST}
    ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} 
  PRIVATE
    strings-lib
    CONAN_PKG::gtest)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

