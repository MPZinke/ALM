

#include "Adder.hpp"
#include "Bus.hpp"


int main()
{
	Bus<8> bus1(true, true, true, true, true, true, true, true);
	Bus<8> bus2(false, false, false, false, false, false, false, false);

	Adder<8> adder;
	bus1 >> adder;
	bus2 >> adder;

	Bus<8> result;
	adder >> result;

	return 0;
}
