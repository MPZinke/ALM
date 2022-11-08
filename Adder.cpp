

#include "Adder.hpp"
#include "ALU.hpp"


Adder::Adder(ALU& alu)
: _alu{alu}
{}


Port<16> Adder::operator[](int index) const
{
	if(index == OPERAND1)
	{
		return _operand1;
	}
	if(index == OPERAND2)
	{
		return _operand2;
	}

	std::string message("In `Port<16> Adder::operator[](int index) const`\n"
	  "\tIndex " + std::to_string(index) + " is out of range");
	throw std::out_of_range(message);
}


Port<16>& Adder::operator[](int index)
{
	if(index == OPERAND1)
	{
		return _operand1;
	}
	if(index == OPERAND2)
	{
		return _operand2;
	}

	std::string message("In `Port<16>& Adder::operator[](int index)`\n"
	  "\tIndex " + std::to_string(index) + " is out of range");
	throw std::out_of_range(message);
}


void Adder::_add()
{
	bool bit15_xor = _operand1[15] ^ _operand2[15];
	_result[15] = bit15_xor ^ _carry_in;
	bool bit14_carry = _operand1[15] && _operand2[15];

	bool bit14_xor = _operand1[14] ^ _operand2[14];
	_result[14] = bit14_xor ^ bit14_carry;
	bool bit13_carry = (bit14_xor && bit14_carry) || (_operand1[14] && _operand2[14]);

	bool bit13_xor = _operand1[13] ^ _operand2[13];
	_result[13] = bit13_xor ^ bit13_carry;
	bool bit12_carry = (bit13_xor && bit13_carry) || (_operand1[13] && _operand2[13]);

	bool bit12_xor = _operand1[12] ^ _operand2[12];
	_result[12] = bit12_xor ^ bit12_carry;
	bool bit11_carry = (bit12_xor && bit12_carry) || (_operand1[12] && _operand2[12]);

	bool bit11_xor = _operand1[11] ^ _operand2[11];
	_result[11] = bit11_xor ^ bit11_carry;
	bool bit10_carry = (bit11_xor && bit11_carry) || (_operand1[11] && _operand2[11]);

	bool bit10_xor = _operand1[10] ^ _operand2[10];
	_result[10] = bit10_xor ^ bit10_carry;
	bool bit9_carry = (bit10_xor && bit10_carry) || (_operand1[10] && _operand2[10]);

	bool bit9_xor = _operand1[9] ^ _operand2[9];
	_result[9] = bit9_xor ^ bit9_carry;
	bool bit8_carry = (bit9_xor && bit9_carry) || (_operand1[9] && _operand2[9]);

	bool bit8_xor = _operand1[8] ^ _operand2[8];
	_result[8] = bit8_xor ^ bit8_carry;
	bool bit7_carry = (bit8_xor && bit8_carry) || (_operand1[8] && _operand2[8]);

	bool bit7_xor = _operand1[7] ^ _operand2[7];
	_result[7] = bit7_xor ^ bit7_carry;
	bool bit6_carry = (bit7_xor && bit7_carry) || (_operand1[7] && _operand2[7]);

	bool bit6_xor = _operand1[6] ^ _operand2[6];
	_result[6] = bit6_xor ^ bit6_carry;
	bool bit5_carry = (bit6_xor && bit6_carry) || (_operand1[6] && _operand2[6]);

	bool bit5_xor = _operand1[5] ^ _operand2[5];
	_result[5] = bit5_xor ^ bit5_carry;
	bool bit4_carry = (bit5_xor && bit5_carry) || (_operand1[5] && _operand2[5]);

	bool bit4_xor = _operand1[4] ^ _operand2[4];
	_result[4] = bit4_xor ^ bit4_carry;
	bool bit3_carry = (bit4_xor && bit4_carry) || (_operand1[4] && _operand2[4]);

	bool bit3_xor = _operand1[3] ^ _operand2[3];
	_result[3] = bit3_xor ^ bit3_carry;
	bool bit2_carry = (bit3_xor && bit3_carry) || (_operand1[3] && _operand2[3]);

	bool bit2_xor = _operand1[2] ^ _operand2[2];
	_result[2] = bit2_xor ^ bit2_carry;
	bool bit1_carry = (bit2_xor && bit2_carry) || (_operand1[2] && _operand2[2]);

	bool bit1_xor = _operand1[1] ^ _operand2[1];
	_result[1] = bit1_xor ^ bit1_carry;
	bool bit0_carry = (bit1_xor && bit1_carry) || (_operand1[1] && _operand2[1]);

	bool bit0_xor = _operand1[0] ^ _operand2[0];
	_result[0] = bit0_xor ^ bit0_carry;
	bool carry_out = (bit0_xor && bit0_carry) || (_operand1[0] && _operand2[0]);
}


Port<1>& Adder::carry_in()
{
	return _carry_in;
}


// ————————————————————————————————————————————————————— FRIEND ————————————————————————————————————————————————————— //

std::ostream& operator<<(std::ostream& stream, Adder& adder)
{
	adder._add();

	stream << adder._operand1[0]  << " " << adder._operand1[1]  << " " << adder._operand1[2]  << " "
		   << adder._operand1[3]  << " " << adder._operand1[4]  << " " << adder._operand1[5]  << " "
		   << adder._operand1[6]  << " " << adder._operand1[7]  << " " << adder._operand1[8]  << " "
		   << adder._operand1[9]  << " " << adder._operand1[10] << " " << adder._operand1[11] << " "
		   << adder._operand1[12] << " " << adder._operand1[13] << " " << adder._operand1[14] << " "
		   << adder._operand1[15] << " | "
		   << adder._operand2[0]  << " " << adder._operand2[1]  << " " << adder._operand2[2]  << " "
		   << adder._operand2[3]  << " " << adder._operand2[4]  << " " << adder._operand2[5]  << " "
		   << adder._operand2[6]  << " " << adder._operand2[7]  << " " << adder._operand2[8]  << " "
		   << adder._operand2[9]  << " " << adder._operand2[10] << " " << adder._operand2[11] << " "
		   << adder._operand2[12] << " " << adder._operand2[13] << " " << adder._operand2[14] << " "
		   << adder._operand2[15] << std::endl
		   << adder._result[0]  << " " << adder._result[1]  << " " << adder._result[2]  << " "
		   << adder._result[3]  << " " << adder._result[4]  << " " << adder._result[5]  << " "
		   << adder._result[6]  << " " << adder._result[7]  << " " << adder._result[8]  << " "
		   << adder._result[9]  << " " << adder._result[10] << " " << adder._result[11] << " "
		   << adder._result[12] << " " << adder._result[13] << " " << adder._result[14] << " "
		   << adder._result[15] << std::endl;

	return stream;
}


void operator<<(Port<16>& port, Adder& adder)
{
	adder._add();

	port << adder._result;
}
