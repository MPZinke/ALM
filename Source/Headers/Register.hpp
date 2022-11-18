

#pragma once


#include <iostream>


#include "Port.hpp"


class ALU;


class Register
{
	public:
		Register();
		Register(int bits);
		Register(	bool bit0,  bool bit1,  bool bit2,  bool bit3,  bool bit4,  bool bit5,  bool bit6,  bool bit7,
  					bool bit8,  bool bit9,  bool bit10, bool bit11, bool bit12, bool bit13, bool bit14, bool bit15);


		friend Port<16>& operator>>(Register& register_x, Port<16>& port);
		friend Port<4>& operator>>(Register& register_x, Port<4>& port);  //TEMP
		friend void operator<<(Register& register_x, ALU& alu);
		friend std::ostream& operator<<(std::ostream& stream, Register& register_x);


	private:
		Port<16> _port;
};
