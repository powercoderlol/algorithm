project(algorithms)
cmake_minimum_required(VERSION 2.8.11)


# download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
	RESULT_VARIABLE 	result
	WORKING_DIRECTORY	${CMAKE_BINARY_DIR}/googletest-download )
if(result)
	message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
	message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# prevent overriding the parent project's compiler/linker
# setting on windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# add googletest directly to build
# this defines the gtest and gtest_main targets

add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
				 "${CMAKE_BINARY_DIR}/googletest-build")	
				 

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
	include_directories("${gtest_SOURCE_DIR}/include")
endif()                                    

enable_testing()

add_executable(smoke-test-longest-substring tests/smoke-test-longest-substring.cpp)
target_link_libraries(smoke-test-longest-substring gtest gtest_main)
add_test(NAME longest-substring-test COMMAND smoke-test-longest-substring)



set(SOURCES LongestSubstring.h LongestSubstring.cpp)

add_executable(algorithms ${SOURCES})

