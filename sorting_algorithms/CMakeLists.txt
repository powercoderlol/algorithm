project(sorting-algo-lib)
cmake_minimum_required(VERSION 3.10)

set(SORTING_ALGORITHMS_LIB_SRC
  quick_sort/parallel_and_sequential_quick_sort.cpp
  quick_sort/qsort_test.cpp
  quick_sort/template_qsort.h
)

add_library(sorting_algorithms STATIC ${SORTING_ALGORITHMS_LIB_SRC})
target_include_directories(sorting_algorithms
  PRIVATE
  sorting_algorithms/quick_sort)
set_property(TARGET sorting_algorithms PROPERTY LINKER_LANGUAGE CXX)

SET(SORTING_ALGO_LIBS sorting_algorithms)