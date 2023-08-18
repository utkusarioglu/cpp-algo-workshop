cmake_minimum_required(VERSION 3.22)
project(PackageTest CXX)

find_package(cpp-algo-workshop CONFIG REQUIRED)

add_executable(example src/example.cpp)
target_link_libraries(example cpp-algo-workshop::cpp-algo-workshop)
