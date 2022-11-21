

#include "Memory.hpp"


Memory::Memory()
{}


Port<16>& Memory::operator[](int index)
{
	_output_bus << _words[index];
	return _output_bus;
}
