
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


#include "Controller.hpp"
#include "CPU.hpp"


Controller::Controller(Register& _register0, Register& _register1, Register& _register2,
  Register& _register3, Register& _register4, Register& _register5, Register& _instruction)
: _cpu_register0{_register0}, _cpu_register1{_register1}, _cpu_register2{_register2}, _cpu_register3{_register3},
  _cpu_register4{_register4}, _cpu_register5{_register5}, _cpu_instruction{_instruction}
{}


void Controller::operator++()
{
	// load instruction

	// decode instruction
	//  determine if ALU, loading or branching
	//  determine registers if ALU or loading

	// execute instruction
}
