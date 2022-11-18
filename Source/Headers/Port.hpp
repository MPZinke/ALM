

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

		// Getters/Setters
		bit operator[](int index) const;  // Getter
		bit& operator[](int index);  // Setter

		// Logical
		bool operator==(int right);
		friend bool operator==(int right, Port<N>& port);

		bit operator^(bit right);
		template<size_t M>
		friend bit operator^(bit left, Port<M>& port);

		// Convert
		explicit operator int();

		// Data Flow
		// Convert ports of different size
		template<size_t M, size_t P>
		friend Port<P>& operator>>(Port<M>& left, Port<P>& right);

		friend Port<16>& operator>>(Register &register_x, Port<16>& port);
		friend Port<4>& operator>>(Register &register_x, Port<4>& port);  // TEMP
		template<size_t M>
		friend Port<M>& operator>>(bit left, Port<M>& port);
		void operator<<(Port<N>& right);

		// Printing
		template<size_t M>
		friend std::ostream& operator<<(std::ostream& stream, Port<M>& port);
};


// ———————————————————————————————————————————————— GETTERS/SETTERS  ———————————————————————————————————————————————— //

template<size_t N>
bit& Port<N>::operator[](int index)
{
	if(N <= index)
	{
		std::string message("In `bit& Port<N>::operator[](int index)`\n"
		  "\tIndex " + std::to_string(index) + " is out of range");

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
		  "\tIndex " + std::to_string(index) + " is out of range");
		throw std::out_of_range(message);
	}

	return _bits[index];
}


// ———————————————————————————————————————————————————— LOGICAL  ———————————————————————————————————————————————————— //

template<size_t N>
bool Port<N>::operator==(int right)
{
	for(int n = N; n > 0; n--)
	{
		if(_bits[n-1] != ((right >> (N-n)) & 1))
		{
			return false;
		}
	}

	return true;
}

template<size_t N>
bool operator==(int right, Port<N>& port)
{

}


template<size_t N>
bit operator^(bit left, Port<N>& right)
{
	return left ^ right._bits[N-1];
}


template<size_t N>
bit Port<N>::operator^(bit right)
{
	return _bits[N-1] ^ right;
}


// ——————————————————————————————————————————————————— DATA  FLOW ——————————————————————————————————————————————————— //

template<size_t N>
Port<N>::operator int()
{
	int value = 0;
	for(int x = 0; x < N; x++)
	{
		value |= (((int)_bits[x]) << ((N-1) - x));
	}

	return value;
}


// ——————————————————————————————————————————————————— DATA  FLOW ——————————————————————————————————————————————————— //

template<size_t N, size_t M>
Port<M>& operator>>(Port<N>& left, Port<M>& right)
{
	static_assert(N > 0 && M > 0);
	for(int x = 0; x < (int)(N < M ? N : M); x++)
	{
		right._bits[(M - 1) - x] = left._bits[(N - 1) - x];
	}
	return right;
}


template<size_t N>
Port<N>& operator>>(bit left, Port<N>& right)
{
	for(int x = 0; x < N; x++)
	{
		right._bits[x] = 0;
	}

	right._bits[N-1] = left;
	return right;
}


template<size_t N>
void Port<N>::operator<<(Port<N>& right)
{
	for(int x = 0; x < N; x++)
	{
		this->_bits[x] = right._bits[x];
	}
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
