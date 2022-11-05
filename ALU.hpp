
/***********************************************************************************************************************
*                                                                                                                      *
*   created by: MPZinke                                                                                                *
*   on 2022.11.04                                                                                                      *
*                                                                                                                      *
*   DESCRIPTION: TEMPLATE                                                                                              *
*   BUGS:                                                                                                              *
*   FUTURE:                                                                                                            *
*                                                                                                                      *
***********************************************************************************************************************/


#pragma once


#include "Port.hpp"
#include "Adder.hpp"


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


class ALU
{
	public:
		ALU();

		Port<8> operator[](int index) const;  // Getter
		Port<8>& operator[](int index);  // Setter

		friend void operator>>(Port<4>& port, ALU& alu);
		friend void operator<<(Port<8>& port, ALU& alu);
		friend void operator<<(Register& register_x, ALU& alu);

		// Printing
		friend std::ostream& operator<<(std::ostream& stream, ALU& alu);

	private:
		// IO
		Port<8> _operand1;
		Port<8> _operand2;
		Port<8> _result;

		Port<4> _flags;
		Port<4> _instruction;

		void _decode();

		// Arithmetic
		Adder _adder;

		// Logic

};
