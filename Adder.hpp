

#pragma once


#include <iostream>


#include "Port.hpp"


class Adder
{
	public:
		Adder(){}

		Port<8> operator[](int index) const;  // Getter
		Port<8>& operator[](int index);  // Setter

		void add();

		friend std::ostream& operator<<(std::ostream& stream, Adder& adder);

	private:
		Port<8> operand1;
		Port<8> operand2;
		Port<8> result;
};
