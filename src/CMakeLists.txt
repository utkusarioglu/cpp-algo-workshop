add_executable(${BUILD_TARGET_NAME}
  ${SRC_DIR}/main.cc
)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
  add_compile_definitions(DEBUG)
endif()

target_sources(${BUILD_TARGET_NAME}
  PRIVATE
  ${SRC_DIR}/array_printer/array_printer.cc
  ${SRC_DIR}/sorting_algorithms/counting_sort.cc
)

target_link_libraries(${BUILD_TARGET_NAME}
  ${BUILD_TARGET_LINK_LIBRARIES}
)
