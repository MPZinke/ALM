
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


Controller::Controller(CPU& cpu)
: _cpu{cpu}
{}


void Controller::operator++()
{
	// load instruction

	// decode instruction
	//  determine if ALU, loading or branching
	//  determine registers if ALU or loading

	// execute instruction
}
