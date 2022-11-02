

#include "Adder.hpp"
#include "Bus.hpp"
#include "Register.hpp"


int main()
{
	Adder adder;
	Bus bus1, bus2, bus_out;

	Register register1(0, 0, 0, 0, 0, 1, 1, 1), register2(0, 0, 0, 0, 0, 0, 1, 0);
	register1 >> bus1 > adder;
	register2 >> bus2 >> adder;

	// bus1 > adder;
	bus2 >> adder;

	bus_out << adder;

	std::cout << bus_out;

	// Bus<8> result;
	// adder >> result;

	return 0;
}
