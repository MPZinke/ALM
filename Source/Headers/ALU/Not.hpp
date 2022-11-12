

#pragma once


#include "Port.hpp"


class Not
{
	public:
		Not();

		Port<16>& operator>>(Port<16>& output);
		friend Not& operator>>(Port<16>& input, Not& right);
		friend void operator<<(Port<16>& output, Not& right);

	private:
		Port<16> _input;	
		Port<16> _output;
};
