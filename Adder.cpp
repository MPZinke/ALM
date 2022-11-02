
/***********************************************************************************************************************
*                                                                                                                      *
*   created by: MPZinke                                                                                                *
*   on 2022.11.01                                                                                                      *
*                                                                                                                      *
*   DESCRIPTION: TEMPLATE                                                                                              *
*   BUGS:                                                                                                              *
*   FUTURE:                                                                                                            *
*                                                                                                                      *
***********************************************************************************************************************/


#include "Adder.hpp"


Adder::Adder()
{}


void Adder::add()
{
	h_result = h1 ^ h2;
	bool g_carry = h1 && h2;

	bool g_xor = g1 ^ g2;
	g_result = g_xor ^ g_carry;
	bool f_carry = (g_xor && g_carry) || (g1 && g2);

	bool f_xor = f1 ^ f2;
	f_result = f_xor ^ f_carry;
	bool e_carry = (f_xor && f_carry) || (f1 && f2);

	bool e_xor = e1 ^ e2;
	e_result = e_xor ^ e_carry;
	bool d_carry = (e_xor && e_carry) || (e1 && e2);

	bool d_xor = d1 ^ d2;
	d_result = d_xor ^ d_carry;
	bool c_carry = (d_xor && d_carry) || (d1 && d2);

	bool c_xor = c1 ^ c2;
	c_result = c_xor ^ c_carry;
	bool b_carry = (c_xor && c_carry) || (c1 && c2);

	bool b_xor = b1 ^ b2;
	b_result = b_xor ^ b_carry;
	bool a_carry = (b_xor && b_carry) || (b1 && b2);

	bool a_xor = a1 ^ a2;
	a_result = a_xor ^ a_carry;
	bool carry_out = (b_xor && b_carry) || (b1 && b2);
}


std::ostream& operator<<(std::ostream& stream, Adder& adder)
{
	stream << adder.a1 << " " << adder.b1 << " " << adder.c1 << " " << adder.d1 << " "
		   << adder.e1 << " " << adder.f1 << " " << adder.g1 << " " << adder.h1 << " | "
		   << adder.a2 << " " << adder.b2 << " " << adder.c2 << " " << adder.d2 << " "
		   << adder.e2 << " " << adder.f2 << " " << adder.g2 << " " << adder.h2 << std::endl
		   << adder.a_result << " " << adder.b_result << " " << adder.c_result << " " << adder.d_result << " "
		   << adder.e_result << " " << adder.f_result << " " << adder.g_result << " " << adder.h_result << std::endl;

	return stream;
}



void operator>(Bus& bus, Adder& adder)
{
	adder.a1 = bus.a;
	adder.b1 = bus.b;
	adder.c1 = bus.c;
	adder.d1 = bus.d;
	adder.e1 = bus.e;
	adder.f1 = bus.f;
	adder.g1 = bus.g;
	adder.h1 = bus.h;

	adder.add();
}


void operator>>(Bus& bus, Adder& adder)
{
	adder.a2 = bus.a;
	adder.b2 = bus.b;
	adder.c2 = bus.c;
	adder.d2 = bus.d;
	adder.e2 = bus.e;
	adder.f2 = bus.f;
	adder.g2 = bus.g;
	adder.h2 = bus.h;

	adder.add();
}


void operator<<(Bus& bus, Adder& adder)
{
	bus.a = adder.a_result;
	bus.b = adder.b_result;
	bus.c = adder.c_result;
	bus.d = adder.d_result;
	bus.e = adder.e_result;
	bus.f = adder.f_result;
	bus.g = adder.g_result;
	bus.h = adder.h_result;
}
