

#pragma once


#include "Port.hpp"
#include "Register.hpp"


class CPU;


class Controller
{
	public:
		Controller(CPU& cpu);

		void operator++();


	private:
		CPU& _cpu;
		Register& _instruction;
};
