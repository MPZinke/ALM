

#pragma once


#include "Port.hpp"


class CPU;


class Controller
{
	public:
		Controller(CPU& cpu);


	private:
		CPU& _cpu;
		Port<16> _instruction;
};
