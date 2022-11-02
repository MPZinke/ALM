

#pragma once


#include <array>
#include <iostream>
#include <tuple>
#include <type_traits> // enable_if, conjuction


#define BUS_WIDTH 8


enum Endian
{
	LITTLE,
	BIG
};


typedef bool bit;


class Adder;
class Register;


class Bus
{
	private:
		bool a = 0;
		bool b = 0;
		bool c = 0;
		bool d = 0;
		bool e = 0;
		bool f = 0;
		bool g = 0;
		bool h = 0;


	public:
		Bus();

		friend std::ostream& operator<<(std::ostream& stream, Bus& bus);

		void operator>>(Bus& bus);
		friend void operator>(Bus& bus, Adder& adder);
		friend void operator>>(Bus& bus, Adder& adder);
		friend void operator<<(Bus& bus, Adder& adder);
		friend Bus& operator>(Register& register_x, Bus& bus);
		friend Bus& operator>>(Register& register_x, Bus& bus);
		// friend void operator>>(Bus& bus1, Bus& bus2);
};
