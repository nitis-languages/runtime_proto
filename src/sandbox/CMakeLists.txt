cmake_minimum_required(VERSION 3.20)

# Install output directory
set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_LIST_DIR}/../../bin/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
# Removes Debug and Release directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR})

include(../nlr/CMakeLists.txt)

project(sandbox)

add_executable(sandbox main.cpp)
target_link_libraries(sandbox PUBLIC nlr::nlr)