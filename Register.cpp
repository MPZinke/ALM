

#include "Register.hpp"


Register::Register()
{}


Register::Register(int bits)
{
	_port[0] = (bits >> 7) & 0b1;
	_port[1] = (bits >> 6) & 0b1;
	_port[2] = (bits >> 5) & 0b1;
	_port[3] = (bits >> 4) & 0b1;
	_port[4] = (bits >> 3) & 0b1;
	_port[5] = (bits >> 2) & 0b1;
	_port[6] = (bits >> 1) & 0b1;
	_port[7] = (bits >> 0) & 0b1;
}


Register::Register(bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h)
{
	_port[0] = a;
	_port[1] = b;
	_port[2] = c;
	_port[3] = d;
	_port[4] = e;
	_port[5] = f;
	_port[6] = g;
	_port[7] = h;
}


// ————————————————————————————————————————————————————— FRIEND ————————————————————————————————————————————————————— //

void operator>>(Register& register_x, Port<8>& port)
{
	port._bits[0] = register_x._port._bits[0];
	port._bits[1] = register_x._port._bits[1];
	port._bits[2] = register_x._port._bits[2];
	port._bits[3] = register_x._port._bits[3];
	port._bits[4] = register_x._port._bits[4];
	port._bits[5] = register_x._port._bits[5];
	port._bits[6] = register_x._port._bits[6];
	port._bits[7] = register_x._port._bits[7];
}


void operator<<(Register& register_x, ALU& alu)
{
	register_x._port << alu;
}


std::ostream& operator<<(std::ostream& stream, Register& register_x)
{
	stream << register_x._port[0] << " " << register_x._port[1] << " " << register_x._port[2] << " "
		   << register_x._port[3] << " " << register_x._port[4] << " " << register_x._port[5] << " "
		   << register_x._port[6] << " " << register_x._port[7] << std::endl;

	return stream;
}
