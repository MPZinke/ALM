

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


		void operator>>(Port<N>& port)
		{
			for(int x = 0; x < N; x++)
			{
				port._bits[x] = this->_bits[x];
			}
		}


		friend void operator>>(Register &register_x, Port<8>& port);
		friend bit operator>>(bit left, Port<1>& port);
		friend bit operator^(bit left, Port<1>& port);


		const bit& operator[](int index) const;  // Getter
		bit& operator[](int index);  // Setter
};
