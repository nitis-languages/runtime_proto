// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#include <nlr/defines.h>

namespace nlr::vm {

enum class CallingConvention : UInt8 {
	/// @brief Use default host calling convention.
	Default = 0,

	/// @brief Default X64 ABI calling convention.
	X64Abi = 1,

	/// @brief Default Windows x64 calling convention.
	X64Window = 2,

	/// @brief Default Nite langauges calling convention.
	/// @details Supports multiple return parameters.
	NiteCall = 3,
};

constexpr bool is_multiple_return_parameters_supported(CallingConvention convention) {
	return convention == CallingConvention::NiteCall;
}

} // namespace nlr::vm