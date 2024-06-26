find_package(GTest REQUIRED)
include(GoogleTest)
enable_testing()

add_executable(${TEST_TARGET_NAME}
  ${TEST_DIR}/main.cc
)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
  add_compile_definitions(DEBUG)
endif()


target_sources(${TEST_TARGET_NAME}
  PRIVATE
  ${SRC_DIR}/sorting_algorithms/counting_sort.cc
  ${SRC_DIR}/sorting_algorithms/insertion_sort.cc
  ${SRC_DIR}/leetcode/product_of_array_except_self.cc
  ${SRC_DIR}/leetcode/maximum_subarray.cc
  ${SRC_DIR}/leetcode/maximum_product_subarray.cc
  ${SRC_DIR}/leetcode/clone_graph.cc
  ${SRC_DIR}/leetcode/minimum_window_substring.cc
  ${SRC_DIR}/leetcode/spiral_matrix.cc
  ${SRC_DIR}/data_structures/fenwick_tree.cc
  # ${SRC_DIR}/leetcode/valid_anagram.cc
)

include_directories("${SRC_DIR}")

target_link_libraries(${TEST_TARGET_NAME}
  ${BUILD_TARGET_LINK_LIBRARIES}
  ${TEST_TARGET_LINK_LIBRARIES}
)

gtest_discover_tests(${TEST_TARGET_NAME})
