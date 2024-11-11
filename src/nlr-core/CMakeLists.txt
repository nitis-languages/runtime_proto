cmake_minimum_required(VERSION 3.20)

project(nlr)

include(../../cmake/compiler.cmake)

if(MSVC)
	set(CMAKE_CXX_STANDARD_LIBRARIES "")
endif (MSVC)

if (NLR_EMBED)
	set(NLR_TARGET_TYPE "EMBED")
elseif (NLR_STATIC)
	set(NLR_TARGET_TYPE "STATIC")
else()
	set(NLR_TARGET_TYPE "SHARED")
	add_definitions(-DNLR_EXPORTS)
endif()

set(NLR_SRC
	${CMAKE_CURRENT_LIST_DIR}/vm/runtime.cpp
	${CMAKE_CURRENT_LIST_DIR}/vm/domain.cpp
)

message("== Nlr build info ==")
message(" | NLR_TARGET_TYPE=${NLR_TARGET_TYPE}")

add_library(nlr ${NLR_TARGET_TYPE} ${NLR_SRC})
target_include_directories(nlr PUBLIC ${CMAKE_CURRENT_LIST_DIR})
set_target_properties(nlr PROPERTIES OUTPUT_NAME "nlr")

add_library(nlr::nlr ALIAS nlr)