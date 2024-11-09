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

NLR_END_NAMESPACE
#endif