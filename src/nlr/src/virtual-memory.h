// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#ifndef _NLR_VIRT_MEM_H
#define _NLR_VIRT_MEM_H

#include "utils.h"

namespace nlr {

enum class MemoryFlags : UInt8 {
	NoAccess			= 0x00,
	Read				= 0x01,
	Write				= 0x02,
	ReadWrite			= 0x03,
	Execute				= 0x04,
	ExecuteRead			= 0x05,
	ExecuteWrite		= 0x06,
	ExecuteReadWrite	= 0x07,
	//Jit				= 0x10, /* Uncomment when adding MacOS support */
};
NLR_ENUM_BIT_FLAGS(MemoryFlags)

/// @brief Flush instruction cache.
/// @param memory Pointer to instruction memory whose cache need to flush.
/// @param size Size of flushed instruction cache.
void flush_instruction_cache(void *memory, UIntPtr size) noexcept;

/// @brief Allocate memory with specific size.
/// @param out_memory Output parameter: store pointer to allocated memory.
/// @param size Size of allocated memory.
/// @param flags Memory flags.
bool allocate(void **out_memory, UIntPtr size, MemoryFlags flags) noexcept;

/// @brief Changes allocated memory protection.
/// @param memory Pointer to memory to change protection level.
/// @param size Size of memory to change protection level.
/// @param flags Memory flags.
/// @return Operation result.
bool protect(void *memory, UIntPtr size, MemoryFlags flags) noexcept;

/// @brief Releases allocated memory.
/// @param memory Pointer to allocated memory.
/// @param size Size of allocated memory. It must be the same with the @ref allocate argument.
/// @return
bool release(void *memory, UIntPtr size) noexcept;

/// @brief Gets system page size.
/// @return System page size.
UIntPtr get_page_size() noexcept;

/// @brief Gets system large page size.
/// @return Returns system page size on success, zero on fail.
UIntPtr get_large_page_size() noexcept;

} // namespace nlr
#endif