

#include "Not.hpp"


Not::Not()
{}


Port<16>& Not::operator>>(Port<16>& output)
{
	for(int x = 0; x < 16; x++)
	{
		_output[x] = !_input[x];
	}

	_output >> output;
	return output;
}


Not& operator>>(Port<16>& input, Not& right)
{
	input >> right._input;
	return right;
}


void operator<<(Port<16>& output, Not& right)
{
	for(int x = 0; x < 16; x++)
	{
		output[x] = !right._output[x];
	}

	output << right._output;
}
