

#pragma once


#include "ALU/ALU.hpp"
#include "Controller.hpp"
#include "Port.hpp"
#include "Register.hpp"


typedef int Memory[256];


class CPU
{
	public:
		CPU();

		Register& operator[](int index);
		void operator++();

	private:
		Memory _memory = {ADD, SUB};
		Register _register0;
		Register _register1;
		Register _register2;
		Register _register3;
		Register _register4;
		Register _register5;
		Register _instruction;

		ALU _alu;
		Controller _controller;

		Port<16> _input_bus;
		Port<16> _output_bus;
};
