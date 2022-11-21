
/***********************************************************************************************************************
*                                                                                                                      *
*   created by: MPZinke                                                                                                *
*   on 2022.11.11                                                                                                      *
*                                                                                                                      *
*   DESCRIPTION: TEMPLATE                                                                                              *
*   BUGS:                                                                                                              *
*   FUTURE:                                                                                                            *
*                                                                                                                      *
***********************************************************************************************************************/


#include "CPU.hpp"


CPU::CPU()
: _controller{_register0, _register1, _register2, _register3, _register4, _register5, _instruction}
{}


void CPU::operator++()
{
	_instruction << _memory[_program_counter];
}
