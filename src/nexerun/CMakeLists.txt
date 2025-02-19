cmake_minimum_required(VERSION 3.20)

include(../nlr/CMakeLists.txt)

project(nexerun)

add_executable(nexerun main.cpp)
target_link_libraries(nexerun PUBLIC nlr::nlr)