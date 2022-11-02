

#include "Bus.hpp"


Bus::Bus()
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


std::ostream& operator<<(std::ostream& stream, Bus& bus)
{
	stream << bus.a << " " << bus.b << " " << bus.c << " " << bus.d << " "
		   << bus.e << " " << bus.f << " " << bus.g << " " << bus.h << std::endl;

	return stream;
}


void Bus::operator>>(Bus& bus)
{
	bus.a = a;
	bus.b = b;
	bus.c = c;
	bus.d = d;
	bus.e = e;
	bus.f = f;
	bus.g = g;
	bus.h = h;
}
