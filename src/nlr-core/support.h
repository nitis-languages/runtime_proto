// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#ifndef _NLR_SUPPORT_H
#define _NLR_SUPPORT_H

#include "nlr-core-api.h"

NLR_BEGIN_NAMESPACE

enum class Result : Sint32 {
	/// @brief Operation was executed successfully.
	Success = 0,
	/// @brief Operation failed with unknown error.
	UnknownError = -1,
	/// @brief System can't provide more memory.
	NotEnoughMemory = -2,
	/// @brief Error during code execution.
	/// Usually invalid machine code.
	ExecutionError = -3,
	/// @brief Parameter value is invalid.
	InvalidArgument = -4,
};
NLR_ENUM_COMPARABLE(Result)

template<typename... Args>
static NLR_INLINE void unused(Args&&...) noexcept {}

template<typename From, typename To>
static NLR_INLINE constexpr To ptr_cast(From from) noexcept { return (To)from; }

template<typename Func>
static NLR_INLINE constexpr Func ptr_to_func(void *ptr) noexcept { return ptr_cast<void *, Func>(ptr); }

template<typename Target>
static NLR_INLINE constexpr Target *move_ptr(void *ptr, SintPtr byte_offset) noexcept {
	return ptr_cast<Uint8 *, Target *>(
		ptr_cast<void *, Uint8 *>(ptr) + byte_offset
	);
}

template<typename Lhs, typename Rhs>
static NLR_INLINE constexpr bool has_flag(Lhs value, Rhs flag) noexcept {
	return (value & flag) != (Rhs)0;
}

template<typename Lhs, typename Rhs>
static NLR_INLINE constexpr bool has_flags(Lhs value, Rhs flags) noexcept {
	return (value & flags) == flags;
}

static NLR_INLINE constexpr Uint8 fill_trailing_bits(Uint8 value) noexcept {
	value |= value >> 1;
	value |= value >> 2;
	value |= value >> 4;
	return value;
}

static NLR_INLINE constexpr Uint16 fill_trailing_bits(Uint16 value) noexcept {
	value |= value >> 1;
	value |= value >> 2;
	value |= value >> 4;
	value |= value >> 8;
	return value;
}

static NLR_INLINE constexpr Uint32 fill_trailing_bits(Uint32 value) noexcept {
	value |= value >> 1;
	value |= value >> 2;
	value |= value >> 4;
	value |= value >> 8;
	value |= value >> 16;
	return value;
}

static NLR_INLINE constexpr Uint64 fill_trailing_bits(Uint64 value) noexcept {
	value |= value >> 1;
	value |= value >> 2;
	value |= value >> 4;
	value |= value >> 8;
	value |= value >> 16;
	value |= value >> 32;
	return value;
}

/// @brief Fill trailing bits.
/// @tparam Integer Any integral type.
/// @param value Value to be fill trailing bits.
/// @return Value with set trailing bits.
template<typename Integer>
static NLR_INLINE constexpr Integer fill_trailing_bits(Integer value) noexcept {
	return fill_trailing_bits((typename std::make_unsigned<Integer>::type)value);
}

/// @brief Align up value by granularity.
/// @tparam Integer Any integral type.
/// @param value Value to align up.
/// @param granularity Granularity.
/// @return If value is 0 returns 0; otherwise returns value aligned by granularity.
template<typename Integer>
static NLR_INLINE constexpr Integer align_up(Integer value, Integer granularity) noexcept {
	return ((value + (granularity - 1)) & ~(granularity - 1));
}

/// @brief Align up the value to the nearest greater power of two.
/// @tparam Integer Any integral type.
/// @param value Value to align up.
/// @return If value is 0 returns 0; if value is power of 2, returns value; otherwise nearest greater power of 2.
template<typename Integer>
static NLR_INLINE Integer align_up_power2(Integer value) noexcept {
	return fill_trailing_bits<Integer>(value - 1u) + 1u;
}

NLR_END_NAMESPACE
#endif