// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#ifndef _NLR_CORE_API
#define _NLR_CORE_API

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <array>
#if !defined(__cplusplus)
#include <stdbool.h>
#endif

// Prettier numeric types
typedef uint8_t		Uint8;
typedef uint16_t	Uint16;
typedef uint32_t	Uint32;
typedef uint64_t	Uint64;
typedef uintptr_t	UintPtr;
typedef int8_t		Sint8;
typedef int16_t		Sint16;
typedef int32_t		Sint32;
typedef int64_t		Sint64;
typedef intptr_t	SintPtr;
typedef float		Float32;
typedef double		Float64;

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
	#define NLR_PLATFORM "Unknown Apple"
	#define NLR_PLATFORM_MACOS 1
#else
	#error "This system is not supported."
#endif


// Force inline
#if !defined(DEBUG) && defined(__GNUC__)
  #define NLR_INLINE inline __attribute__((__always_inline__))
#elif !defined(DEBUG) && defined(_MSC_VER)
  #define NLR_INLINE __forceinline
#else
  #define NLR_INLINE inline
#endif

// Namespaces
#define NLR_BEGIN_NAMESPACE									\
	namespace nlr {
#define NLR_END_NAMESPACE									\
	}
#define NLR_BEGIN_SUBNAMESPACE(subnamespace)				\
	NLR_BEGIN_NAMESPACE namespace subnamespace {
#define NLR_END_SUBNAMESPACE								\
	} NLR_END_NAMESPACE

/// @brief Removes default constructors.
#define NLR_TYPE_REMOVE_CONSTRUCTORS(type)					\
	type() = delete;										\
	type(const type& other) = delete;						\
	type& operator=(const type& other) = delete;

/// @brief Removes default copy constructors.
#define NLR_TYPE_REMOVE_COPY(type)							\
	type(const type& other) = delete;						\
	type& operator=(const type& other) = delete;

/// @brief Defines comparable operators for enum.
#define NLR_ENUM_COMPARABLE(T)																\
	static NLR_INLINE bool operator<(T a, T b) noexcept {									\
		return (std::underlying_type<T>::type)(a) < (std::underlying_type<T>::type)(b);		\
	}																						\
	static NLR_INLINE bool operator<=(T a, T b) noexcept {									\
		return (std::underlying_type<T>::type)(a) <= (std::underlying_type<T>::type)(b);	\
	}																						\
	static NLR_INLINE bool operator>(T a, T b) noexcept {									\
		return (std::underlying_type<T>::type)(a) > (std::underlying_type<T>::type)(b);		\
	}																						\
	static NLR_INLINE bool operator>=(T a, T b) noexcept {									\
		return (std::underlying_type<T>::type)(a) >= (std::underlying_type<T>::type)(b);	\
	}

/// @brief Defines bitwise operators for enum.
#define NLR_ENUM_BIT_FLAGS(T)										\
	static NLR_INLINE constexpr T operator~(T a) noexcept {			\
		return T(~(std::underlying_type<T>::type)(a));				\
	}																\
	static NLR_INLINE constexpr T operator|(T a, T b) noexcept {	\
		return T((std::underlying_type<T>::type)(a) |				\
			(std::underlying_type<T>::type)(b));					\
	}																\
	static NLR_INLINE constexpr T operator&(T a, T b) noexcept {	\
		return T((std::underlying_type<T>::type)(a) &				\
			(std::underlying_type<T>::type)(b));					\
	}																\
	static NLR_INLINE constexpr T operator^(T a, T b) noexcept {	\
		return T((std::underlying_type<T>::type)(a) ^				\
			(std::underlying_type<T>::type)(b));					\
	}																\
	static NLR_INLINE T& operator|=(T& a, T b) noexcept {			\
		a = T((std::underlying_type<T>::type)(a) |					\
			(std::underlying_type<T>::type)(b));					\
		return a;													\
	}																\
	static NLR_INLINE T& operator&=(T& a, T b) noexcept {			\
		a = T((std::underlying_type<T>::type)(a) &					\
			(std::underlying_type<T>::type)(b));					\
		return a;													\
	}																\
	static NLR_INLINE T& operator^=(T& a, T b) noexcept {			\
		a = T((std::underlying_type<T>::type)(a) ^					\
			(std::underlying_type<T>::type)(b));					\
		return a;													\
	}

#endif