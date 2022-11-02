

#include "Register.hpp"
#include <iostream>


Register::Register()
{
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	e = 0;
	f = 0;
	g = 0;
	h = 0;
}


Register::Register(int bits)
{
	a = (bits >> 7) & 0b1;
	b = (bits >> 6) & 0b1;
	c = (bits >> 5) & 0b1;
	d = (bits >> 4) & 0b1;
	e = (bits >> 3) & 0b1;
	f = (bits >> 2) & 0b1;
	g = (bits >> 1) & 0b1;
	h = (bits >> 0) & 0b1;
}


Register::Register(bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->e = e;
	this->f = f;
	this->g = g;
	this->h = h;
}


Bus& operator>(Register& register_x, Bus& bus)
{
	bus.a = register_x.a;
	bus.b = register_x.b;
	bus.c = register_x.c;
	bus.d = register_x.d;
	bus.e = register_x.e;
	bus.f = register_x.f;
	bus.g = register_x.g;
	bus.h = register_x.h;

	return bus;
}


Bus& operator>>(Register& register_x, Bus& bus)
{
	return register_x > bus;
}
