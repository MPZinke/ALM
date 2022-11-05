

#pragma once


#include <iostream>


#include "Port.hpp"


class ALU;


class Adder
{
	public:
		Adder(ALU& alu);

		Port<1>& carry_in();
		Port<8> operator[](int index) const;  // Getter
		Port<8>& operator[](int index);  // Setter

		friend std::ostream& operator<<(std::ostream& stream, Adder& adder);
		friend void operator<<(Port<8>& port, Adder& adder);

	private:
		ALU& _alu;

		Port<1> _carry;
		Port<8> _operand1;
		Port<8> _operand2;
		Port<8> _result;

		void add();
};
