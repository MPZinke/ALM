

#pragma once


#include <iostream>


#include "Port.hpp"
#include "ALU.hpp"


class Register
{
	public:
		Register();
		Register(int bits);
		Register(bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h);


		friend void operator>>(Register& register_x, Port<8>& port);
		friend void operator>>(Register& register_x, Port<4>& port);  //TEMP
		friend void operator<<(Register& register_x, ALU& alu);
		friend std::ostream& operator<<(std::ostream& stream, Register& register_x);


	private:
		Port<8> _port;
};
