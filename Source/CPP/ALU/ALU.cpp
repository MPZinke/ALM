
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


ALU::ALU()
: _adder{*this}
{}


void ALU::_decode()
{
	switch((int)_instruction)
	{
		case(ADDC):
		{
			_flags[CARRY] >> _adder.carry_in();
		}
		case(ADD):
		{
			_operand1 >> _adder[OPERAND1];
			_operand2 >> _adder[OPERAND2];
			_result << _adder;
			break;
		}
		case(SUB):
		{
			// Two's compliment
			_operand2 >> _not >> _adder[OPERAND1];
			1 >> _adder[OPERAND2];
			_operand2 << _adder;

			_operand1 >> _adder[OPERAND1];
			_operand2 >> _adder[OPERAND2];
			_result << _adder;
			break;
		}
	}
}


// ——————————————————————————————————————————————————— OPERATORS  ——————————————————————————————————————————————————— //

Port<16> ALU::operator[](int index) const
{
	if(index == OPERAND1)
	{
		return _operand1;
	}
	if(index == OPERAND2)
	{
		return _operand2;
	}

	std::string message("In `Port<16> ALU::operator[](int index) const`\n"
	  "\tIndex " + std::to_string(index) + " is out of range");
	throw std::out_of_range(message);
}


Port<16>& ALU::operator[](int index)
{
	if(index == OPERAND1)
	{
		return _operand1;
	}
	if(index == OPERAND2)
	{
		return _operand2;
	}

	std::string message("In `Port<16>& ALU::operator[](int index)`\n"
	  "\tIndex " + std::to_string(index) + " is out of range");
	throw std::out_of_range(message);
}


// ————————————————————————————————————————————————————— FRIEND ————————————————————————————————————————————————————— //

void operator<<(Register& register_x, ALU& alu)
{
	register_x._port << alu;
}


std::ostream& operator<<(std::ostream& stream, ALU& alu)
{
	stream << alu._operand1[0]  << " " << alu._operand1[1]  << " " << alu._operand1[2]  << " "
		   << alu._operand1[3]  << " " << alu._operand1[4]  << " " << alu._operand1[5]  << " "
		   << alu._operand1[6]  << " " << alu._operand1[7]  << " " << alu._operand1[8]  << " "
		   << alu._operand1[9]  << " " << alu._operand1[10] << " " << alu._operand1[11] << " "
		   << alu._operand1[12] << " " << alu._operand1[13] << " " << alu._operand1[14] << " "
		   << alu._operand1[15] << " | "
		   << alu._operand2[0]  << " " << alu._operand2[1]  << " " << alu._operand2[2]  << " "
		   << alu._operand2[3]  << " " << alu._operand2[4]  << " " << alu._operand2[5]  << " "
		   << alu._operand2[6]  << " " << alu._operand2[7]  << " " << alu._operand2[8]  << " "
		   << alu._operand2[9]  << " " << alu._operand2[10] << " " << alu._operand2[11] << " "
		   << alu._operand2[12] << " " << alu._operand2[13] << " " << alu._operand2[14] << " "
		   << alu._operand2[15] << std::endl
		   << alu._result[0]  << " " << alu._result[1]  << " " << alu._result[2]  << " "
		   << alu._result[3]  << " " << alu._result[4]  << " " << alu._result[5]  << " "
		   << alu._result[6]  << " " << alu._result[7]  << " " << alu._result[8]  << " "
		   << alu._result[9]  << " " << alu._result[10] << " " << alu._result[11] << " "
		   << alu._result[12] << " " << alu._result[13] << " " << alu._result[14] << " "
		   << alu._result[15] << std::endl;

	return stream;
}


void operator>>(Port<4>& port, ALU& alu)
{
	port >> alu._instruction;
}


void operator<<(Port<16>& port, ALU& alu)
{
	alu._decode();

	port << alu._result;
}
