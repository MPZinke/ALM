

#pragma once


#include "ALU/ALU.hpp"
#include "Controller.hpp"
#include "Instructions.hpp"
#include "Memory.hpp"
#include "Port.hpp"
#include "Register.hpp"


class CPU
{
	public:
		CPU();

		Register& operator[](int index);
		void operator++();

	private:
		Memory _memory;
		Register _register0;
		Register _register1;
		Register _register2;
		Register _register3;
		Register _register4;
		Register _register5;
		Register _instruction;

		ALU _alu;
		Controller _controller;
		int _program_counter = 0;

		Port<16> _input_bus;
		Port<16> _output_bus;
};
