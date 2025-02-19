// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#ifndef _NLR_SUPPORT_H
#define _NLR_SUPPORT_H

#include <nlr/defines.h>

namespace nlr {

// Force inline
#if !defined(DEBUG) && defined(__GNUC__)
  #define NLR_INLINE inline __attribute__((__always_inline__))
#elif !defined(DEBUG) && defined(_MSC_VER)
  #define NLR_INLINE __forceinline
#else
  #define NLR_INLINE inline
#endif

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
	static NLR_INLINE bool operator<(T a, std::underlying_type<T>::type b) noexcept {		\
		return (std::underlying_type<T>::type)(a) < (b);									\
	}																						\
	static NLR_INLINE bool operator<(std::underlying_type<T>::type a, T b) noexcept {		\
		return (a) < (std::underlying_type<T>::type)(b);									\
	}																						\
	static NLR_INLINE bool operator<=(T a, T b) noexcept {									\
		return (std::underlying_type<T>::type)(a) <= (std::underlying_type<T>::type)(b);	\
	}																						\
	static NLR_INLINE bool operator<=(T a, std::underlying_type<T>::type b) noexcept {		\
		return (std::underlying_type<T>::type)(a) <= (b);									\
	}																						\
	static NLR_INLINE bool operator<=(std::underlying_type<T>::type a, T b) noexcept {		\
		return (a) <= (std::underlying_type<T>::type)(b);									\
	}																						\
	static NLR_INLINE bool operator>(T a, T b) noexcept {									\
		return (std::underlying_type<T>::type)(a) > (std::underlying_type<T>::type)(b);		\
	}																						\
	static NLR_INLINE bool operator>(T a, std::underlying_type<T>::type b) noexcept {		\
		return (std::underlying_type<T>::type)(a) > (b);									\
	}																						\
	static NLR_INLINE bool operator>(std::underlying_type<T>::type a, T b) noexcept {		\
		return (a) > (std::underlying_type<T>::type)(b);									\
	}																						\
	static NLR_INLINE bool operator>=(T a, T b) noexcept {									\
		return (std::underlying_type<T>::type)(a) >= (std::underlying_type<T>::type)(b);	\
	}																						\
	static NLR_INLINE bool operator>=(T a, std::underlying_type<T>::type b) noexcept {		\
		return (std::underlying_type<T>::type)(a) >= (b);									\
	}																						\
	static NLR_INLINE bool operator>=(std::underlying_type<T>::type a, T b) noexcept {		\
		return (a) >= (std::underlying_type<T>::type)(b);									\
	}																						\
	static NLR_INLINE bool operator==(std::underlying_type<T>::type a, T b) noexcept {		\
		return (a) == (std::underlying_type<T>::type)(b);									\
	}																						\
	static NLR_INLINE bool operator==(T a, std::underlying_type<T>::type b) noexcept {		\
		return (std::underlying_type<T>::type)(a) == (b);									\
	}																						\
	static NLR_INLINE bool operator!=(std::underlying_type<T>::type a, T b) noexcept {		\
		return (a) != (std::underlying_type<T>::type)(b);									\
	}																						\
	static NLR_INLINE bool operator!=(T a, std::underlying_type<T>::type b) noexcept {		\
		return (std::underlying_type<T>::type)(a) != (b);									\
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
	}																\

#define NLR_ENUM_SHIFT(T)																									\
	static NLR_INLINE constexpr std::underlying_type<T>::type operator<<(T a, std::underlying_type<T>::type b) noexcept {	\
		return (std::underlying_type<T>::type)(a) << b;																		\
	}																														\
	static NLR_INLINE constexpr std::underlying_type<T>::type operator>>(T a, std::underlying_type<T>::type b) noexcept {	\
		return (std::underlying_type<T>::type)(a) >> b;																		\
	}

template<UIntPtr _Size>
struct Reserved {
private:
	std::array<uint8_t, _Size> reserved_array;
};

template<typename _Element>
struct ArrayView {
public:
	_Element *items;
	UIntPtr count;

	constexpr bool is_empty() noexcept {
		return count != 0;
	}
};

template<typename... Args>
NLR_INLINE void unused(Args&&...) noexcept {}

template<typename From, typename To>
NLR_INLINE constexpr To ptr_cast(From from) noexcept { return (To)from; }

template<typename Func>
NLR_INLINE constexpr Func ptr_to_func(void *ptr) noexcept { return ptr_cast<void *, Func>(ptr); }

template<typename Target>
NLR_INLINE constexpr Target *move_ptr(void *ptr, SIntPtr byte_offset) noexcept {
	return ptr_cast<UInt8 *, Target *>(
		ptr_cast<void *, UInt8 *>(ptr) + byte_offset
	);
}

template<typename Lhs, typename Rhs>
NLR_INLINE constexpr bool has_flag(Lhs value, Rhs flag) noexcept {
	return (value & flag) != (Rhs)0;
}
static_assert(nlr::has_flag(0b01, 0b01));
static_assert(nlr::has_flag(0b01, 0b11));

template<typename Lhs, typename Rhs>
NLR_INLINE constexpr bool has_flags(Lhs value, Rhs flags) noexcept {
	return (value & flags) == flags;
}
static_assert(nlr::has_flags(0b01, 0b01));
static_assert(nlr::has_flags(0b11, 0b11));
static_assert(!nlr::has_flags(0b0111, 0b1110));


NLR_INLINE constexpr UInt8 fill_trailing_bits(UInt8 value) noexcept {
	value |= value >> 1;
	value |= value >> 2;
	value |= value >> 4;
	return value;
}

NLR_INLINE constexpr UInt16 fill_trailing_bits(UInt16 value) noexcept {
	value |= value >> 1;
	value |= value >> 2;
	value |= value >> 4;
	value |= value >> 8;
	return value;
}

NLR_INLINE constexpr UInt32 fill_trailing_bits(UInt32 value) noexcept {
	value |= value >> 1;
	value |= value >> 2;
	value |= value >> 4;
	value |= value >> 8;
	value |= value >> 16;
	return value;
}

NLR_INLINE constexpr UInt64 fill_trailing_bits(UInt64 value) noexcept {
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
NLR_INLINE constexpr Integer fill_trailing_bits(Integer value) noexcept {
	return fill_trailing_bits((typename std::make_unsigned<Integer>::type)value);
}

/// @brief Align up value by granularity.
/// @tparam Integer Any integral type.
/// @param value Value to align up.
/// @param granularity Granularity.
/// @return If value is 0 returns 0; otherwise returns value aligned by granularity.
template<typename Integer>
NLR_INLINE constexpr Integer align_up(Integer value, Integer granularity) noexcept {
	return ((value + (granularity - 1)) & ~(granularity - 1));
}

/// @brief Align up the value to the nearest greater power of two.
/// @tparam Integer Any integral type.
/// @param value Value to align up.
/// @return If value is 0 returns 0; if value is power of 2, returns value; otherwise nearest greater power of 2.
template<typename Integer>
NLR_INLINE Integer align_up_power2(Integer value) noexcept {
	return fill_trailing_bits<Integer>(value - 1u) + 1u;
}

} // namespace nlr
#endif