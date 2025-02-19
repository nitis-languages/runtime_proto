// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#ifndef _NLR_X64_COMPILER
#define _NLR_X64_COMPILER

namespace nlr::jit::x64 {

class JitCompiler {
public:
	void generate_stub(void *method) noexcept;

	void generate_code(void *method) noexcept;
};

} // namespace nlr::jit::x64
#endif