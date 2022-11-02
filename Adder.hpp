

#pragma once


#include <iostream>


#include "Bus.hpp"


class Adder
{
	public:
		Adder();

		void add();

		friend std::ostream& operator<<(std::ostream& stream, Adder& adder);

		friend void operator>(Bus& bus, Adder& adder);
		friend void operator>>(Bus& bus, Adder& adder);
		friend void operator<<(Bus& bus, Adder& adder);


	protected:
		bool a1 = 0;
		bool b1 = 0;
		bool c1 = 0;
		bool d1 = 0;
		bool e1 = 0;
		bool f1 = 0;
		bool g1 = 0;
		bool h1 = 0;

		bool a2 = 0;
		bool b2 = 0;
		bool c2 = 0;
		bool d2 = 0;
		bool e2 = 0;
		bool f2 = 0;
		bool g2 = 0;
		bool h2 = 0;

		bool a_result = 0;
		bool b_result = 0;
		bool c_result = 0;
		bool d_result = 0;
		bool e_result = 0;
		bool f_result = 0;
		bool g_result = 0;
		bool h_result = 0;
};
