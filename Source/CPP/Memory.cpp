

#include "Memory.hpp"


Memory::Memory()
{}


Word Memory::operator[](int index)
{
	return _words[index];
}
