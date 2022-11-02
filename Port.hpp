

#include <array>
#include <iostream>
#include <tuple>
#include <type_traits> // enable_if, conjuction


#pragma once


enum Endian
{
	LITTLE,
	BIG
};


typedef bool bit;


class Register;


template<size_t N>
class Port
{
	private:
		bit _bits[N];

	public:
		Port()
		{
			std::fill(_bits, _bits + N, false);
		}

		friend void operator>>(Register &register_x, Port<8>& port);


		bit& operator[](int index)
		{
			return _bits[index];
		}


		const bit& operator[](int index) const
		{
			return _bits[index];
		}
};
