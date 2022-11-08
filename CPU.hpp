
#include "Port.hpp"


class CPU
{
	public:
		CPU();

	private:
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
