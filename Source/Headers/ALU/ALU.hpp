
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


#include "Instructions.hpp"
#include "Port.hpp"
#include "Register.hpp"

#include "Adder.hpp"
#include "Not.hpp"


class ALU
{
	public:
		ALU();

		Port<16> operator[](int index) const;  // Getter
		Port<16>& operator[](int index);  // Setter

		friend void operator>>(Port<4>& port, ALU& alu);
		friend void operator<<(Port<16>& port, ALU& alu);
		friend void operator<<(Register& register_x, ALU& alu);

		// Printing
		friend std::ostream& operator<<(std::ostream& stream, ALU& alu);

	private:
		// IO
		Port<16> _operand1;
		Port<16> _operand2;
		Port<16> _result;

		Port<4> _flags;
		Port<4> _instruction;

		void _decode();

		// Arithmetic
		Adder _adder;

		// Logic
		Not _not;

};
