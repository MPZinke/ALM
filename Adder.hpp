

#pragma once


#include <iostream>


#include "Port.hpp"


class ALU;


class Adder
{
	public:
		Adder(ALU& alu);

		Port<1>& carry_in();
		Port<16> operator[](int index) const;  // Getter
		Port<16>& operator[](int index);  // Setter

		friend std::ostream& operator<<(std::ostream& stream, Adder& adder);
		friend void operator<<(Port<16>& port, Adder& adder);

	private:
		ALU& _alu;

		Port<1> _carry_in;
		Port<16> _operand1;
		Port<16> _operand2;
		Port<16> _result;

		void _add();
};
