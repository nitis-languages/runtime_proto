// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#ifndef _ARCH_H
#define _ARCH_H

#include "../nlr-core-api.h"

NLR_BEGIN_NAMESPACE

/// @brief 
enum class Architecture : Uint8 {
	Unknown = 0,
	/// @brief Also known as Amd64, x86_64, x64.
	X64 = 1,

	/// @brief The host architecture.
	Host = X64,
};

enum class BitEndianess : Uint8 {
	/// @brief Integral bits stored from right to left by 8-bit groups in reverse order.
	LittleEndian = 0,
	
	/// @brief Integral bits stored from right to left.
	BigEndian = 1,

	/// @brief The endianess of host compiler.
	Host = 
	#if NLR_BYTE_ORDER_BE
		BigEndian
	#else
		LittleEndian
	#endif
};

NLR_END_NAMESPACE
#endif