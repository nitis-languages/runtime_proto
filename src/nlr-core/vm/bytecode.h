#ifndef _BYTECODE_H
#define _BYTECODE_H

#include "../support.h"

NLR_BEGIN_NAMESPACE

enum class Bytecode : Uint8 {
	Nope						= 0x00,
	Break						= 0x01,
	PushArg						= 0x02,
	PushArgAddress				= 0x03,
	StoreArg					= 0x04,
	PushLocal					= 0x05,
	PushLocalAddress			= 0x06,
	StoreLocal					= 0x07,
	PushField					= 0x08,
	PushFieldAddress			= 0x09,
	StoreField					= 0x0A,
	Call						= 0x0B,
	CallPointer					= 0x0C,
	LongCall					= 0x0D,
	LongCallPointer				= 0x0E,
	Return						= 0x0F,

	PushS8						= 0x10,
	PushS16						= 0x11,
	PushS32						= 0x12,
	PushS64						= 0x13,
	PushU8						= 0x14,
	PushU16						= 0x15,
	PushU32						= 0x16,
	PushU64						= 0x17,
	PushF16						= 0x18,
	PushF32						= 0x19,
	PushF64						= 0x1A,
	PushNull					= 0x1B,
	Pop							= 0x1C,

	Goto						= 0x1D,
	GotoIfZero					= 0x1E,
	GotoIfZeroNot				= 0x1F,
	GotoIfEquals				= 0x20,
	GotoIfEqualsNot				= 0x21,
	GotoIfGreater				= 0x22,
	GotoIfGreaterOrEquals		= 0x23,
	GotoIfLess					= 0x24,
	GotoIfLessOrEquals			= 0x25,

	Add							= 0x26,
	Sub							= 0x27,
	Div							= 0x28,
	Mul							= 0x29,
	Rem							= 0x2A,
	And							= 0x2B,
	Or							= 0x2C,
	Xor							= 0x2D,
	Negate						= 0x2E,
	Not							= 0x2F,
	BitShiftLeft				= 0x30,
	BitShiftRight				= 0x31,
	ArithmeticShiftRight		= 0x32,

	TwoByteInstructionPrefix	= 0xFF,
};

NLR_END_NAMESPACE
#endif