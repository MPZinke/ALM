

#include "Port.hpp"


class ALU
{
	private:
		Port<8> operand1;
		Port<8> operand2;
		Port<8> result;

		Port<2> flags;
		Port<4> instruction;

	public:
		ALU();
}

