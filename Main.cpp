

#include <iostream>


#include "Adder.hpp"
#include "Port.hpp"
#include "Register.hpp"


int main()
{
	Register register1(0, 0, 0, 0, 0, 0, 1, 0), register2(0, 0, 0, 0, 0, 1, 1, 0);
	Adder adder;

	std::cout <<register1;
	std::cout <<register2;

	register1 >> adder[1];
	register2 >> adder[2];

	std::cout << adder;


	return 0;
}
