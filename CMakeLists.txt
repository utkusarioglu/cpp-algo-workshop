cmake_minimum_required(VERSION 3.22)
project(cpp-algo-workshop)

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(TEST_DIR "${CMAKE_SOURCE_DIR}/test")

set(BUILD_TARGET_NAME "${PROJECT_NAME}-src")
set(TEST_TARGET_NAME "${PROJECT_NAME}-test")

set(BUILD_TARGET_LINK_LIBRARIES 
  spdlog::spdlog
  fmt::fmt
)
set(TEST_TARGET_LINK_LIBRARIES 
  GTest::Main
)

find_package(spdlog REQUIRED)
find_package(fmt REQUIRED)

add_subdirectory(${SRC_DIR})
add_subdirectory(${TEST_DIR})

if (${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
  set_target_properties(${PROJECT_NAME} 
    PROPERTIES 
    LINK_FLAGS
      "-O3 \
      -o ${PROJECT_NAME}.js \
      -s WASM=1 \
      -s ENVIRONMENT=web \
      -s SINGLE_FILE=1 \
      -s EXPORT_ES6=1 \
      -s EXPORTED_RUNTIME_METHODS=['UTF8ToString'] \
      -s ASSERTIONS=1 \
      --bind"
  )
endif()
