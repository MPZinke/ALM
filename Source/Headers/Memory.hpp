

#pragma once


#include "Instructions.hpp"
#include "Port.hpp"


typedef int Word;


class Memory
{
	public:
		Memory();

		Port<16>& operator[](int index);

	private:
		Word _words[256] = {ADD, SUB};

		Port<16> _input_bus;
		Port<16> _output_bus;
};
