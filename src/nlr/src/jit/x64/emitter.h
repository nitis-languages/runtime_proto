// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#ifndef _NLR_EMITTER
#define _NLR_EMITTER

#include "x64.h"

namespace nlr::jit::x64 {

struct Emitter {
public:
	void NLR_INLINE emit_modrm(ModRM::Mode mode, UInt8 rm, UInt8 reg) noexcept;
	void NLR_INLINE emit_sib(Sib::Scale scale, UInt8 index, UInt8 base) noexcept;
};

} // namespace nlr::jit::x64
#endif