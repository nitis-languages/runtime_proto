#ifndef _CALLCONV_H
#define _CALLCONV_H
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