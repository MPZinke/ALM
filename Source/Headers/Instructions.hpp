

#pragma once


enum Flags  // The bit numbers of the flags
{
	CARRY,
	NEGATIVE,
	ZERO,
	OVERFLOW
};


enum Instructions
{
	ADD,
	ADDC,
	SUB,
	SUBC,
	MUL,
	AND,
	OR,
	XOR,
	NOT,
	LSHIFT,
	RSHIFT,
	COMPARE,
	TEST
};


enum Operands
{
	INSTRUCTION,
	OPERAND1,
	OPERAND2
};
