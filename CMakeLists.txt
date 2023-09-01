cmake_minimum_required(VERSION 3.22)
project(cpp-algo-workshop)

find_package(spdlog REQUIRED)
find_package(fmt REQUIRED)

add_executable(${PROJECT_NAME} src/main.cc)

target_link_libraries(${PROJECT_NAME} 
  spdlog::spdlog
  fmt::fmt
)

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
