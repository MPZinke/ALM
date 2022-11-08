

#include <iostream>


#include "ALU.hpp"
#include "Register.hpp"


int main()
{
	Register register1(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
	Register register2(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0);
	Register instruction(ADD);
	Port<4> temp_instruction_port;
	instruction >> temp_instruction_port;
	ALU alu;

	std::cout << register1;
	std::cout << register2;

	temp_instruction_port >> alu;
	register1 >> alu[OPERAND1];
	register2 >> alu[OPERAND2];
	register1 << alu;
	std::cout << register1;

	// Sub
	std::cout << "————————————————————————\n";
	instruction = Register(SUB);
	instruction >> temp_instruction_port;
	temp_instruction_port >> alu;
	register1 >> alu[OPERAND1];

	std::cout << register1;
	std::cout << register2;

	register1 << alu;
	std::cout << register1;

	return 0;
}
