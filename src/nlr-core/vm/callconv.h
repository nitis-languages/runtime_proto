// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#ifndef _NLR_CALLCONV_H
#define _NLR_CALLCONV_H

#include "../nlr-core-api.h"

NLR_BEGIN_NAMESPACE

enum class CallConvention {
	/// @brief The compiler choose best available option.
	Default = 0,
	/// @brief Default AMD64 calling convention.
	X64 = 1,
	/// @brief Default Windows AMD64 calling convention.
	X64Windows = 2,
};

NLR_END_NAMESPACE
#endif