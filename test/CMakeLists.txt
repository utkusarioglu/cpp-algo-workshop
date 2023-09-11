find_package(GTest REQUIRED)
include(GoogleTest)
enable_testing()

add_executable(${TEST_TARGET_NAME}
  ${TEST_DIR}/main.cc
)

target_sources(${TEST_TARGET_NAME}
  PRIVATE
  ${SRC_DIR}/sorting_algorithms/counting_sort.cc
)

target_link_libraries(${TEST_TARGET_NAME}
  ${BUILD_TARGET_LINK_LIBRARIES}
  ${TEST_TARGET_LINK_LIBRARIES}
)

gtest_discover_tests(${TEST_TARGET_NAME})
