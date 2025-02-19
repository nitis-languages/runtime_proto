// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#ifndef _NLR_JIT_COMPILER_H
#define _NLR_JIT_COMPILER_H

#include "../runtime.h"

namespace nlr::jit {

class JitCompiler {
protected:
	Runtime *runtime;
public:
	void generate_stub(void *method) noexcept;

	void generate_code(void *method) noexcept;

	JitCompiler(Runtime *runtime)
		: runtime(runtime)
	{}
};

} // namespace nlr::jit

#endif