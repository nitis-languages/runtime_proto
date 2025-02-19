// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#ifndef _NLR_DEFINES_H
#define _NLR_DEFINES_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prettier numeric types
typedef uint8_t		UInt8;
typedef uint16_t	UInt16;
typedef uint32_t	UInt32;
typedef uint64_t	UInt64;
typedef uintptr_t	UIntPtr;
typedef int8_t		SInt8;
typedef int16_t		SInt16;
typedef int32_t		SInt32;
typedef int64_t		SInt64;
typedef intptr_t	SIntPtr;
typedef float		Float32;
typedef double		Float64;

static_assert(sizeof(Float32) == 32 / 8);
static_assert(sizeof(Float64) == 64 / 8);

// Exports
#if !defined(NLR_STATIC)
	#if defined(_WIN32) && (defined(_MSC_VER) || defined(__MINGW32__))
		#ifdef NLR_EXPORTS
			#define NLR_API __declspec(dllexport)
		#else
			#define NLR_API __declspec(dllimport)
		#endif
	#elif defined(_WIN32) && defined(__GNUC__)
		#ifdef NLR_EXPORTS
			#define NLR_API __attribute__((__dllexport__))
		#else
			#define NLR_API __attribute__((__dllimport__))
		#endif
	#elif defined(__GNUC__)
		#define NLR_API __attribute__((__visibility__("default")))
	#endif
#endif

// Platform dependent
#if (defined(__ARMEB__))  || \
	(defined(__MIPSEB__)) || \
	(defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__))
	#define NLR_BYTE_ORDER_LE 0
	#define NLR_BYTE_ORDER_BE 1
#else
	#define NLR_BYTE_ORDER_LE 1
	#define NLR_BYTE_ORDER_BE 0
#endif

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	#ifndef _WIN64
		#error "32-bit Windows is not supported."
	#endif
	#define NLR_PLATFORM "Windows"
	#define NLR_PLATFORM_WINDOWS 1
#elif __APPLE__
	#include <TargetConditionals.h>
	#error "Apple systems are not supported."
	#define NLR_PLATFORM "Some Apple device"
	#define NLR_PLATFORM_MACOS 1
#else
	#error "This system is not supported."
#endif

#ifdef __cplusplus
	#define NLR_BEGIN_EXTERN_C extern "C" {
	#define NLR_END_EXTERN_C }
	#define NLR_NOEXCEPT noexcept
#else
	#define NLR_EXTERN_C
	#define NLR_END_EXTERN_C
	#define NLR_NOEXCEPT
#endif

#endif