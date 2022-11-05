
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


#include "Port.hpp"


void operator>>(bit left, Port<1>& port)
{
	port._bits[0] = left;
}


bit operator^(bit left, Port<1>& port)
{
	return left ^ port._bits[0];
}
