cmake_minimum_required(VERSION 3.20)

project(nlr)

include(../../cmake/compiler.cmake)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC" OR "x${CMAKE_CXX_COMPILER_FRONTEND_VARIANT}" STREQUAL "xMSVC")
	list(APPEND NLR_PRIVATE_CFLAGS
		-MP
		-GF
		-Zc:strictStrings
		-W4
	)

	list(APPEND NLR_PRIVATE_CFLAGS_DBG
		-GS # Buffer security
		-DDEBUG
	)
	
	list(APPEND NLR_PRIVATE_CFLAGS_RLS
		-GS- # Disable buffer security
		-O2  # Maximum speed
		-DNDEBUG
		-DRELEASE
	)
endif()

if(MSVC)
	set(CMAKE_CXX_STANDARD_LIBRARIES "")
endif (MSVC)

if (NLR_EMBED)
	set(NLR_TARGET_TYPE "EMBED")
elseif (NLR_STATIC)
	set(NLR_TARGET_TYPE "STATIC")
else()
	set(NLR_TARGET_TYPE "SHARED")
	list(APPEND NLR_PRIVATE_CFLAGS
		-DNLR_EXPORTS
	)
endif()

set(NLR_SRC
	${CMAKE_CURRENT_LIST_DIR}/src/zone.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/virtual-memory-win32.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/test.cpp
)

message("== Nlr build info ==")
message(" | NLR_TARGET_TYPE = ${NLR_TARGET_TYPE}")
message(" | NLR_PRIVATE_CFLAGS = ${NLR_PRIVATE_CFLAGS}")
message(" | NLR_PRIVATE_CFLAGS_DBG = ${NLR_PRIVATE_CFLAGS_DBG}")
message(" | NLR_PRIVATE_CFLAGS_RLS = ${NLR_PRIVATE_CFLAGS_RLS}")
message(" | NLR_LIBRARIES = ${NLR_LIBRARIES}")

add_library(nlr ${NLR_TARGET_TYPE} ${NLR_SRC})
target_compile_options(nlr PRIVATE ${NLR_PRIVATE_CFLAGS} $<$<CONFIG:Debug>:${NLR_PRIVATE_CFLAGS_DBG}> $<$<NOT:$<CONFIG:Debug>>:${NLR_PRIVATE_CFLAGS_RLS}>)
target_include_directories(nlr PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)

add_library(nlr::nlr ALIAS nlr)