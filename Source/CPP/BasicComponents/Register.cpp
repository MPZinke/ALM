

#include "Register.hpp"


Register::Register()
{}


Register::Register(int bits)
{
	_port[0] = (bits >> 15) & 0b1;
	_port[1] = (bits >> 14) & 0b1;
	_port[2] = (bits >> 13) & 0b1;
	_port[3] = (bits >> 12) & 0b1;
	_port[4] = (bits >> 11) & 0b1;
	_port[5] = (bits >> 10) & 0b1;
	_port[6] = (bits >> 9) & 0b1;
	_port[7] = (bits >> 8) & 0b1;
	_port[8] = (bits >> 7) & 0b1;
	_port[9] = (bits >> 6) & 0b1;
	_port[10] = (bits >> 5) & 0b1;
	_port[11] = (bits >> 4) & 0b1;
	_port[12] = (bits >> 3) & 0b1;
	_port[13] = (bits >> 2) & 0b1;
	_port[14] = (bits >> 1) & 0b1;
	_port[15] = (bits >> 0) & 0b1;
}


Register::Register(	bool bit0,  bool bit1,  bool bit2,  bool bit3,  bool bit4,  bool bit5,  bool bit6,  bool bit7,
  					bool bit8,  bool bit9,  bool bit10, bool bit11, bool bit12, bool bit13, bool bit14, bool bit15)
{
	_port[0] = bit0;
	_port[1] = bit1;
	_port[2] = bit2;
	_port[3] = bit3;
	_port[4] = bit4;
	_port[5] = bit5;
	_port[6] = bit6;
	_port[7] = bit7;
	_port[8] = bit8;
	_port[9] = bit9;
	_port[10] = bit10;
	_port[11] = bit11;
	_port[12] = bit12;
	_port[13] = bit13;
	_port[14] = bit14;
	_port[15] = bit15;
}


// ————————————————————————————————————————————————————— FRIEND ————————————————————————————————————————————————————— //

void operator>>(Register& register_x, Port<16>& port)
{
	port._bits[0]  = register_x._port._bits[0];
	port._bits[1]  = register_x._port._bits[1];
	port._bits[2]  = register_x._port._bits[2];
	port._bits[3]  = register_x._port._bits[3];
	port._bits[4]  = register_x._port._bits[4];
	port._bits[5]  = register_x._port._bits[5];
	port._bits[6]  = register_x._port._bits[6];
	port._bits[7]  = register_x._port._bits[7];
	port._bits[8]  = register_x._port._bits[8];
	port._bits[9]  = register_x._port._bits[9];
	port._bits[10] = register_x._port._bits[10];
	port._bits[11] = register_x._port._bits[11];
	port._bits[12] = register_x._port._bits[12];
	port._bits[13] = register_x._port._bits[13];
	port._bits[14] = register_x._port._bits[14];
	port._bits[15] = register_x._port._bits[15];
}


void operator>>(Register& register_x, Port<4>& port)
{
	register_x._port >> port;
}


void operator<<(Register& register_x, ALU& alu)
{
	register_x._port << alu;
}


std::ostream& operator<<(std::ostream& stream, Register& register_x)
{
	stream << register_x._port[0]  << " " << register_x._port[1]  << " " << register_x._port[2]  << " "
		   << register_x._port[3]  << " " << register_x._port[4]  << " " << register_x._port[5]  << " "
		   << register_x._port[6]  << " " << register_x._port[7]  << " " << register_x._port[8]  << " "
		   << register_x._port[9]  << " " << register_x._port[10] << " " << register_x._port[11] << " "
		   << register_x._port[12] << " " << register_x._port[13] << " " << register_x._port[14] << " "
		   << register_x._port[15] << std::endl;

	return stream;
}
