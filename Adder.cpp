

#include "Adder.hpp"
#include "ALU.hpp"


Adder::Adder(ALU& alu)
: _alu{alu}
{}


Port<8> Adder::operator[](int index) const
{
	if(index == OPERAND1)
	{
		return _operand1;
	}
	if(index == OPERAND2)
	{
		return _operand2;
	}

	std::string message("In `Port<8> Adder::operator[](int index) const`\n"
	  "\tIndex " + std::to_string(index) + " out of range");
	throw std::out_of_range(message);
}


Port<8>& Adder::operator[](int index)
{
	if(index == OPERAND1)
	{
		return _operand1;
	}
	if(index == OPERAND2)
	{
		return _operand2;
	}

	std::string message("In `Port<8>& Adder::operator[](int index)`\n"
	  "\tIndex " + std::to_string(index) + " out of range");
	throw std::out_of_range(message);
}


void Adder::_add()
{
	bool h_xor = _operand1[7] ^ _operand2[7];
	_result[7] = h_xor ^ _carry_in;
	bool g_carry = _operand1[7] && _operand2[7];

	bool g_xor = _operand1[6] ^ _operand2[6];
	_result[6] = g_xor ^ g_carry;
	bool f_carry = (g_xor && g_carry) || (_operand1[6] && _operand2[6]);

	bool f_xor = _operand1[5] ^ _operand2[5];
	_result[5] = f_xor ^ f_carry;
	bool e_carry = (f_xor && f_carry) || (_operand1[5] && _operand2[5]);

	bool e_xor = _operand1[4] ^ _operand2[4];
	_result[4] = e_xor ^ e_carry;
	bool d_carry = (e_xor && e_carry) || (_operand1[4] && _operand2[4]);

	bool d_xor = _operand1[3] ^ _operand2[3];
	_result[3] = d_xor ^ d_carry;
	bool c_carry = (d_xor && d_carry) || (_operand1[3] && _operand2[3]);

	bool c_xor = _operand1[2] ^ _operand2[2];
	_result[2] = c_xor ^ c_carry;
	bool b_carry = (c_xor && c_carry) || (_operand1[2] && _operand2[2]);

	bool b_xor = _operand1[1] ^ _operand2[1];
	_result[1] = b_xor ^ b_carry;
	bool a_carry = (b_xor && b_carry) || (_operand1[1] && _operand2[1]);

	bool a_xor = _operand1[0] ^ _operand2[0];
	_result[0] = a_xor ^ a_carry;
	bool carry_out = (a_xor && a_carry) || (_operand1[0] && _operand2[0]);
}


Port<1>& Adder::carry_in()
{
	return _carry_in;
}


// ————————————————————————————————————————————————————— FRIEND ————————————————————————————————————————————————————— //

std::ostream& operator<<(std::ostream& stream, Adder& adder)
{
	adder._add();

	stream << adder._operand1[0] << " " << adder._operand1[1] << " " << adder._operand1[2] << " "
		   << adder._operand1[3] << " " << adder._operand1[4] << " " << adder._operand1[5] << " "
		   << adder._operand1[6] << " " << adder._operand1[7] << " | "
		   << adder._operand2[0] << " " << adder._operand2[1] << " " << adder._operand2[2] << " "
		   << adder._operand2[3] << " " << adder._operand2[4] << " " << adder._operand2[5] << " "
		   << adder._operand2[6] << " " << adder._operand2[7] << std::endl
		   << adder._result[0] << " " << adder._result[1] << " " << adder._result[2] << " "
		   << adder._result[3] << " "
		   << adder._result[4] << " " << adder._result[5] << " " << adder._result[6] << " "
		   << adder._result[7] << std::endl;

	return stream;
}


void operator<<(Port<8>& port, Adder& adder)
{
	adder._add();

	port << adder._result;
}
