// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#ifndef _NLR_VIRT_MEM_H
#define _NLR_VIRT_MEM_H

#include "../support.h"

NLR_BEGIN_NAMESPACE

enum class MemoryFlags : Uint8 {
	NoAccess	= 0x00,
	Read		= 0x01,
	Write		= 0x02,
	Execute		= 0x04,
	//Jit			= 0x10, /* Uncomment when adding MacOS support */
};
NLR_ENUM_BIT_FLAGS(MemoryFlags)

/// @brief Flush instruction cache.
/// @param memory Pointer to instruction memory whose cache need to flush.
/// @param size Size of flushed instruction cache.
NLR_API void flush_instruction_cache(void *memory, UintPtr size) noexcept;

/// @brief Allocate memory with specific size.
/// @param out_memory Output parameter: store pointer to allocated memory.
/// @param size Size of allocated memory.
/// @param flags Memory flags.
/// @return Operation result.
NLR_API Result allocate(void **out_memory, UintPtr size, MemoryFlags flags) noexcept;

/// @brief Changes allocated memory protection.
/// @param memory Pointer to memory to change protection level.
/// @param size Size of memory to change protection level.
/// @param flags Memory flags.
/// @return Operation result.
NLR_API Result protect(void *memory, UintPtr size, MemoryFlags flags) noexcept;

/// @brief Releases allocated memory.
/// @param memory Pointer to allocated memory.
/// @param size Size of allocated memory. It must be the same with the @ref allocate argument.
/// @return 
NLR_API Result release(void *memory, UintPtr size) noexcept;

/// @brief Gets system page size.
/// @return System page size.
NLR_API UintPtr get_page_size() noexcept;

/// @brief Gets system large page size.
/// @return Returns system page size on success, zero on fail.
NLR_API UintPtr get_large_page_size() noexcept;

NLR_END_NAMESPACE
#endif