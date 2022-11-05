
/***********************************************************************************************************************
*                                                                                                                      *
*   created by: MPZinke                                                                                                *
*   on 2022.11.04                                                                                                      *
*                                                                                                                      *
*   DESCRIPTION: TEMPLATE                                                                                              *
*   BUGS:                                                                                                              *
*   FUTURE:                                                                                                            *
*                                                                                                                      *
***********************************************************************************************************************/


#include "ALU.hpp"


ALU::ALU()
: _adder{*this}
{
	// _instructions = {this->_add};
}


void ALU::_add()
{
	_flags[CARRY] >> _adder.carry_in();
	_operand1 >> _adder[0];
	_operand2 >> _adder[1];
	_result << _adder;
}
