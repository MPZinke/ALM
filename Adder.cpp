

#include "Adder.hpp"


Port<8> Adder::operator[](int index) const
{
	if(index > 2)
	{
		throw std::out_of_range("Index out of range.");
	}

	if(index == 2)
	{
		return operand2;
	}

	return operand1;
}


Port<8>& Adder::operator[](int index)
{
	if(index > 2)
	{
		throw std::out_of_range("Index out of range.");
	}

	if(index == 2)
	{
		return operand2;
	}

	return operand1;
}


void Adder::add()
{
	result[7] = operand1[7] ^ operand2[7];
	bool g_carry = operand1[7] && operand2[7];

	bool g_xor = operand1[6] ^ operand2[6];
	result[6] = g_xor ^ g_carry;
	bool f_carry = (g_xor && g_carry) || (operand1[6] && operand2[6]);

	bool f_xor = operand1[5] ^ operand2[5];
	result[5] = f_xor ^ f_carry;
	bool e_carry = (f_xor && f_carry) || (operand1[5] && operand2[5]);

	bool e_xor = operand1[4] ^ operand2[4];
	result[4] = e_xor ^ e_carry;
	bool d_carry = (e_xor && e_carry) || (operand1[4] && operand2[4]);

	bool d_xor = operand1[3] ^ operand2[3];
	result[3] = d_xor ^ d_carry;
	bool c_carry = (d_xor && d_carry) || (operand1[3] && operand2[3]);

	bool c_xor = operand1[2] ^ operand2[2];
	result[2] = c_xor ^ c_carry;
	bool b_carry = (c_xor && c_carry) || (operand1[2] && operand2[2]);

	bool b_xor = operand1[1] ^ operand2[1];
	result[1] = b_xor ^ b_carry;
	bool a_carry = (b_xor && b_carry) || (operand1[1] && operand2[1]);

	bool a_xor = operand1[0] ^ operand2[0];
	result[0] = a_xor ^ a_carry;
	bool carry_out = (a_xor && a_carry) || (operand1[0] && operand2[0]);
}


// ————————————————————————————————————————————————————— FRIEND ————————————————————————————————————————————————————— //

std::ostream& operator<<(std::ostream& stream, Adder& adder)
{
	adder.add();

	stream << adder.operand1[0] << " " << adder.operand1[1] << " " << adder.operand1[2] << " "
		   << adder.operand1[3] << " " << adder.operand1[4] << " " << adder.operand1[5] << " "
		   << adder.operand1[6] << " " << adder.operand1[7] << " | "
		   << adder.operand2[0] << " " << adder.operand2[1] << " " << adder.operand2[2] << " "
		   << adder.operand2[3] << " " << adder.operand2[4] << " " << adder.operand2[5] << " "
		   << adder.operand2[6] << " " << adder.operand2[7] << std::endl
		   << adder.result[0] << " " << adder.result[1] << " " << adder.result[2] << " "
		   << adder.result[3] << " "
		   << adder.result[4] << " " << adder.result[5] << " " << adder.result[6] << " "
		   << adder.result[7] << std::endl;

	return stream;
}
