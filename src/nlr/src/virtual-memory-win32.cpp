// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#include "virtual-memory.h"
#if NLR_PLATFORM_WINDOWS
#include <Windows.h>

namespace nlr {

void flush_instruction_cache(void *memory, UIntPtr size) noexcept {
	FlushInstructionCache(GetCurrentProcess(), memory, size);
}

DWORD get_win32_protect_flags(MemoryFlags flags) {
	DWORD value = 0;

	if (has_flag(flags, MemoryFlags::Execute)) {
		if (has_flag(flags, MemoryFlags::Write)) {
			value = PAGE_EXECUTE_READWRITE;
		} else if (has_flag(flags, MemoryFlags::Read)) {
			value = PAGE_EXECUTE_READ;
		} else {
			value = PAGE_EXECUTE;
		}
	} else if (has_flag(flags, MemoryFlags::ReadWrite)) {
		value = has_flag(flags, MemoryFlags::Write) ? PAGE_READWRITE : PAGE_READONLY;
	} else {
		value = PAGE_NOACCESS;
	}

	return value;
}

bool allocate(void **out_memory, UIntPtr size, MemoryFlags flags) noexcept {
	*out_memory = nullptr;
	constexpr DWORD allocation_mode = MEM_COMMIT | MEM_RESERVE;
	DWORD protect = get_win32_protect_flags(flags);
	*out_memory = VirtualAlloc(nullptr, size, allocation_mode, protect);

	return *out_memory;
}

bool protect(void *memory, UIntPtr size, MemoryFlags flags) noexcept {
	DWORD protect = get_win32_protect_flags(flags);
	DWORD previous_protect;

	if (!VirtualProtect(memory, size, protect, &previous_protect)) {
		return false;
	}

	return true;
}

bool release(void *memory, UIntPtr size) noexcept {
	unused(size);

	constexpr DWORD free_type = MEM_RELEASE;
	return VirtualFree(memory, 0, free_type);
}

UIntPtr get_page_size() noexcept {
	SYSTEM_INFO sys_info;
	GetSystemInfo(&sys_info);
	return sys_info.dwPageSize;
}

UIntPtr get_large_page_size() noexcept {
	return GetLargePageMinimum();
}

} // namespace nlr
#endif