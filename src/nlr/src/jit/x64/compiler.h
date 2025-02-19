// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#ifndef _NLR_X64_COMPILER
#define _NLR_X64_COMPILER

#include "../jit-compiler.h"

namespace nlr::jit::x64 {

class DumbX64Compiler : public JitCompiler {
public:
	DumbX64Compiler(Runtime *runtime) : JitCompiler(runtime)
	{}
};

} // namespace nlr::jit::x64
#endif