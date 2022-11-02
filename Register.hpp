

#pragma once


#include "Bus.hpp"


class Register
{
	private:
		bool a = 0;
		bool b = 0;
		bool c = 0;
		bool d = 0;
		bool e = 0;
		bool f = 0;
		bool g = 0;
		bool h = 0;


	public:
		Register();
		Register(int bits);
		Register(bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h);

		friend Bus& operator>(Register& register_x, Bus& bus);
		friend Bus& operator>>(Register& register_x, Bus& bus);
		// friend void operator>>(Register& register_x, Bus& bus);

};
