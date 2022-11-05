

#include <iostream>
#include <tuple>


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

		void operator>>(Port<N>& port);
		void operator<<(Port<N>& port);
		bit operator[](int index) const;  // Getter
		bit& operator[](int index);  // Setter

		friend void operator>>(Register &register_x, Port<8>& port);
		friend void operator>>(bit left, Port<1>& port);
		friend bit operator^(bit left, Port<1>& port);
		template<size_t N1>
		friend std::ostream& operator<<(std::ostream& stream, Port<N1>& port);
};


template<size_t N>
void Port<N>::operator>>(Port<N>& port)
{
	for(int x = 0; x < N; x++)
	{
		port._bits[x] = this->_bits[x];
	}
}


template<size_t N>
void Port<N>::operator<<(Port<N>& port)
{
	for(int x = 0; x < N; x++)
	{
		this->_bits[x] = port._bits[x];
	}
}


template<size_t N>
bit& Port<N>::operator[](int index)
{
	if(N <= index)
	{
		std::string message("In `bit& Port<N>::operator[](int index)`\n"
		  "\tIndex " + std::to_string(index) + " out of range");

		throw std::out_of_range(message);
	}

	return _bits[index];
}


template<size_t N>
bit Port<N>::operator[](int index) const
{
	if(N <= index)
	{
		std::string message("In `bit Port<N>::operator[](int index) const`\n"
		  "\tIndex " + std::to_string(index) + " out of range");
		throw std::out_of_range(message);
	}

	return _bits[index];
}


template<size_t N>
std::ostream& operator<<(std::ostream& stream, Port<N>& port)
{
	for(int x = 0; x < N; x++)
	{
		stream << port._bits[x] << " ";
	}

	return stream;
}