// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#ifndef _NLR_X64
#define _NLR_X64

#include "../../utils.h"

namespace nlr::jit::x64 {

class Sib {
public:
	enum class Scale : UInt8 /* 2 bytes */ {
		X1 = 0b00,
		X2 = 0b01,
		X4 = 0b10,
		X8 = 0b11,
	};

	static constexpr UInt8 create(Scale scale, UInt8 index, UInt8 base) noexcept {
		return (UInt8)scale >> 6
			| ((index & 0b111) << 3)
			| (base & 0b111);
	};
};

class ModRM {
public:
	enum class Mode : UInt8 /* 2 bytes */ {
		// op reg, [reg]
		Indirect = 0b00,
		// op reg, [reg + disp8]
		IndirectDisplaced8 = 0b01,
		// op reg, [reg + disp32]
		IndirectDisplaced32 = 0b10,
		// op reg, reg
		Direct = 0b11
	};

	static constexpr UInt8 create(Mode mode, UInt8 rm, UInt8 reg) noexcept {
		return (UInt8)mode >> 6
			| ((rm & 0b111) << 3)
			| (reg & 0b111);
	};
};


enum class GpRegisterId : UInt8 {
	Ax = 0,
	Cx = 1,
	Dx = 2,
	Bx = 3,
	Sp = 4,
	Bp = 5,
	Si = 6,
	Di = 7,
	R8 = 8,
	R9 = 9,
	R10 = 10,
	R11 = 11,
	R12 = 12,
	R13 = 13,
	R14 = 14,
	R15 = 15,

	/// @brief ModRM specific sequence.
	Sib = 4,

	/// @brief ModRM specific sequence.
	Rip = 5,
};
NLR_ENUM_COMPARABLE(GpRegisterId)
NLR_ENUM_BIT_FLAGS(GpRegisterId)


constexpr bool is_4th_bit_required(GpRegisterId reg_id) noexcept {
	return reg_id > 0b111;
};

} // namespace nlr::jit::x64
#endif