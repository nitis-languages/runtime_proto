#ifndef _NLR_SUPPORT_H
#define _NLR_SUPPORT_H

#include "nlr-core-api.h"

NLR_BEGIN_NAMESPACE

enum class NlrResult : Sint32 {
	/// @brief Operation was executed successfully.
	Success = 0,
	/// @brief Operation failed with unknown error.
	UnknownError = -1,
	/// @brief System can't provide more memory.
	NotEnoughMemory = -2,
	/// @brief Error during code execution.
	/// Usually invalid machine code.
	ExecutionError = -3,
};

template<typename From, typename To>
static NLR_INLINE To ptr_cast(From from) noexcept { return (To)from; }

template<typename Func>
static NLR_INLINE Func ptr_to_func(void *ptr) noexcept { return ptr_cast<void *, Func>(ptr); }

template<typename... Args>
static NLR_INLINE void unused(Args&&...) noexcept {}

template<typename Target>
static NLR_INLINE Target *move_ptr(void *ptr, SintPtr byte_offset) noexcept {
	return ptr_cast<Uint8 *, Target *>(
		ptr_cast<void *, Uint8 *>(ptr) + byte_offset
	);
};

NLR_END_NAMESPACE
#endif