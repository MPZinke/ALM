

#pragma once


#include "Memory.hpp"
#include "Port.hpp"
#include "Register.hpp"


class CPU;


class Controller
{
	public:
		Controller(Register& _register0, Register& _register1, Register& _register2, Register& _register3,
		  Register& _register4, Register& _register5, Register& _instruction);

		void operator++();


	private:
		Register& _cpu_register0;
		Register& _cpu_register1;
		Register& _cpu_register2;
		Register& _cpu_register3;
		Register& _cpu_register4;
		Register& _cpu_register5;
		Register& _cpu_instruction;
};
