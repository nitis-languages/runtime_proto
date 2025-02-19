// Licensed to the NiTiS-Dev under one or more agreements.
// The NiTiS-Dev licenses this file to you under the MIT license.

#ifndef _NLR_BYTECODE_H
#define _NLR_BYTECODE_H

#include "../utils.h"

namespace nlr::vm {

enum class Bytecode : UInt8 {
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

	PushGenericArgumentType		= 0x33,
	PushGenericArgumentConst	= 0x34,

	// StackAlloc				= 0x35,

	TwoByteInstructionPrefix	= 0xFF,
};

struct Instruction {
	Bytecode bytecode;
	union {
		UInt8 u8;
		UInt8 u16;
		UInt8 u32;
		UInt8 u64;
		SInt8 s8;
		SInt8 s16;
		SInt8 s32;
		SInt8 s64;
		UInt16 branch_target;
		UInt8 argument_index;
		UInt8 local_index;
		UInt32 token;
	};
};

enum class FlowControl : UInt8 {
	/// @brief Normal flow.
	Next = 0,
	/// @brief Break instruction.
	Break = 1,
	/// @brief Call instruction.
	Call = 2,
	/// @brief Conditional branch instruction.
	BranchConditional = 3,
	/// @brief Branch instruction.
	Branch = 4,
	/// @brief Return instruction.
	Return = 5,
	/// @brief Instruction is prefix.
	Meta = 0xFF
};

enum class BytecodeClass : UInt8 {
	/// @brief Bytecode is reserved for future use.
	Reserved = 0,
	/// @brief Bytecode is well-known instruction.
	Instruction = 1,
	/// @brief Bytecode is prefix pair of leading instruction.
	Prefix = 0xFF,
};

struct InstructionInfo {
public:
	FlowControl flow;
	BytecodeClass _class;
	UInt8 size;
	Reserved<1> reserved;

	InstructionInfo()
		: flow(FlowControl::Next)
		, _class(BytecodeClass::Reserved)
		, size(1)
	{}

	InstructionInfo(FlowControl flow, BytecodeClass _class, UInt8 size)
		: flow(flow)
		, _class(_class)
		, size(size)
	{}
};

static const InstructionInfo instructionsInfo[UINT8_MAX] {
	{FlowControl::Next, BytecodeClass::Instruction, 1}, // Nope
	{FlowControl::Break, BytecodeClass::Instruction, 1}, // Break
	{FlowControl::Next, BytecodeClass::Instruction, 1 + 4}, // PushArg
	{FlowControl::Next, BytecodeClass::Instruction, 1 + 4}, // PushArgAddress
	{FlowControl::Next, BytecodeClass::Instruction, 1 + 4}, // StoreArg
	{FlowControl::Next, BytecodeClass::Instruction, 1 + 2}, // PushLocal
	{FlowControl::Next, BytecodeClass::Instruction, 1 + 2}, // PushLocalAddress
	{FlowControl::Next, BytecodeClass::Instruction, 1 + 2}, // StoreLocal
	{FlowControl::Next, BytecodeClass::Instruction, 1 + 4}, // PushField
	{FlowControl::Next, BytecodeClass::Instruction, 1 + 4}, // PushFieldAddress
	{FlowControl::Next, BytecodeClass::Instruction, 1 + 4}, // StoreField
	{FlowControl::Call, BytecodeClass::Instruction, 1 + 4}, // Call
	{FlowControl::Call, BytecodeClass::Instruction, 1 + 4}, // CallPointer
	{FlowControl::Call, BytecodeClass::Instruction, 1 + 4}, // LongCall
	{FlowControl::Call, BytecodeClass::Instruction, 1 + 4}, // LongCallPointer
	{FlowControl::Return, BytecodeClass::Instruction, 1}, // Return

	{FlowControl::Next, BytecodeClass::Instruction, 1 + 1}, // PushS8
	{FlowControl::Next, BytecodeClass::Instruction, 1 + 2}, // PushS16
	{FlowControl::Next, BytecodeClass::Instruction, 1 + 4}, // PushS32
	{FlowControl::Next, BytecodeClass::Instruction, 1 + 8}, // PushS64
	{FlowControl::Next, BytecodeClass::Instruction, 1 + 1}, // PushU8
	{FlowControl::Next, BytecodeClass::Instruction, 1 + 2}, // PushU16
	{FlowControl::Next, BytecodeClass::Instruction, 1 + 4}, // PushU32
	{FlowControl::Next, BytecodeClass::Instruction, 1 + 8}, // PushU64
	{FlowControl::Next, BytecodeClass::Instruction, 1 + 2}, // PushF16
	{FlowControl::Next, BytecodeClass::Instruction, 1 + 4}, // PushF32
	{FlowControl::Next, BytecodeClass::Instruction, 1 + 8}, // PushF64
	{FlowControl::Next, BytecodeClass::Instruction, 1}, // PushNull
	{FlowControl::Next, BytecodeClass::Instruction, 1}, // Pop

	{FlowControl::Branch, BytecodeClass::Instruction, 1 + 2}, // Goto
	{FlowControl::BranchConditional, BytecodeClass::Instruction, 1 + 2}, // GotoIfZero
	{FlowControl::BranchConditional, BytecodeClass::Instruction, 1 + 2}, // GotoIfZeroNot
	{FlowControl::BranchConditional, BytecodeClass::Instruction, 1 + 2}, // GotoIfEquals
	{FlowControl::BranchConditional, BytecodeClass::Instruction, 1 + 2}, // GotoIfEqualsNot
	{FlowControl::BranchConditional, BytecodeClass::Instruction, 1 + 2}, // GotoIfGreater
	{FlowControl::BranchConditional, BytecodeClass::Instruction, 1 + 2}, // GotoIfGreaterOrEquals
	{FlowControl::BranchConditional, BytecodeClass::Instruction, 1 + 2}, // GotoIfLess
	{FlowControl::BranchConditional, BytecodeClass::Instruction, 1 + 2}, // GotoIfLessOrEquals

	{FlowControl::Next, BytecodeClass::Instruction, 1}, // Add
	{FlowControl::Next, BytecodeClass::Instruction, 1}, // Sub
	{FlowControl::Next, BytecodeClass::Instruction, 1}, // Div
	{FlowControl::Next, BytecodeClass::Instruction, 1}, // Mul
	{FlowControl::Next, BytecodeClass::Instruction, 1}, // Rem
	{FlowControl::Next, BytecodeClass::Instruction, 1}, // And
	{FlowControl::Next, BytecodeClass::Instruction, 1}, // Or
	{FlowControl::Next, BytecodeClass::Instruction, 1}, // Xor
	{FlowControl::Next, BytecodeClass::Instruction, 1}, // Negate
	{FlowControl::Next, BytecodeClass::Instruction, 1}, // Not
	{FlowControl::Next, BytecodeClass::Instruction, 1}, // BitShiftLeft
	{FlowControl::Next, BytecodeClass::Instruction, 1}, // BitShiftRight
	{FlowControl::Next, BytecodeClass::Instruction, 1}, // ArithmeticShiftRight

	{FlowControl::Next, BytecodeClass::Instruction, 1 + 4}, // PushGenericArgumentType
	{FlowControl::Next, BytecodeClass::Instruction, 1 + 4}, // PushGenericArgumentConst

	{FlowControl::Next, BytecodeClass::Reserved, 1 + 4}, // StackAlloc RESERVED

	{FlowControl::Meta, BytecodeClass::Prefix, 1}, // TwoByteInstructionPrefix
};

constexpr InstructionInfo get_instruction_info(UInt8 prefix, UInt8 bytecode) {
	if (prefix == 0x00) {
		return instructionsInfo[bytecode];
	}

	return InstructionInfo{};
}

} // namespace nlr::vm
#endif