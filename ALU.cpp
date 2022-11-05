
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


#include "ALU.hpp"
#include "Port.hpp"


ALU::ALU()
: _adder{*this}
{}


void ALU::_decode()
{
	if(!_instruction[0] && !_instruction[1] && !_instruction[2] && !_instruction[3])
	{
		_flags[CARRY] >> _adder.carry_in();
		_operand1 >> _adder[0];
		_operand2 >> _adder[1];
		_result << _adder;
	}
}


// ——————————————————————————————————————————————————— OPERATORS  ——————————————————————————————————————————————————— //

Port<8> ALU::operator[](int index) const
{
	if(index == OPERAND1)
	{
		return _operand1;
	}
	if(index == OPERAND2)
	{
		return _operand2;
	}

	std::string message("In `Port<8> ALU::operator[](int index) const`\n"
	  "\tIndex " + std::to_string(index) + " out of range");
	throw std::out_of_range(message);
}


Port<8>& ALU::operator[](int index)
{
	if(index == OPERAND1)
	{
		return _operand1;
	}
	if(index == OPERAND2)
	{
		return _operand2;
	}

	std::string message("In `Port<8>& ALU::operator[](int index)`\n"
	  "\tIndex " + std::to_string(index) + " out of range");
	throw std::out_of_range(message);
}


// ————————————————————————————————————————————————————— FRIEND ————————————————————————————————————————————————————— //

std::ostream& operator<<(std::ostream& stream, ALU& alu)
{
	stream << alu._operand1[0] << " " << alu._operand1[1] << " " << alu._operand1[2] << " "
		   << alu._operand1[3] << " " << alu._operand1[4] << " " << alu._operand1[5] << " "
		   << alu._operand1[6] << " " << alu._operand1[7] << " | "
		   << alu._operand2[0] << " " << alu._operand2[1] << " " << alu._operand2[2] << " "
		   << alu._operand2[3] << " " << alu._operand2[4] << " " << alu._operand2[5] << " "
		   << alu._operand2[6] << " " << alu._operand2[7] << std::endl
		   << alu._result[0] << " " << alu._result[1] << " " << alu._result[2] << " "
		   << alu._result[3] << " "
		   << alu._result[4] << " " << alu._result[5] << " " << alu._result[6] << " "
		   << alu._result[7] << std::endl;

	return stream;
}


void operator>>(Port<4>& port, ALU& alu)
{
	port >> alu._instruction;
}


void operator<<(Port<8>& port, ALU& alu)
{
	alu._decode();

	port << alu._result;
}
