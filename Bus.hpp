

#include <array>
#include <tuple>
#include <type_traits> // enable_if, conjuction


#pragma once


enum Endian
{
	LITTLE,
	BIG
};


typedef bool bit;

// template<class Head, class... Tail, class = std::enable_if_t<are_same<Head, Tail...>::value, void>>
// void print_same_type(Head head, Tail... tail)

// template<unsigned int N, Endian=LITTLE>

template<size_t N>
class Bus
{
	private:
		unsigned int _read_index = 0;
		unsigned int _write_index = 0;
		bit _bits[N];

	public:
		Bus()
		{
			std::fill(_bits, _bits + N, false);
		}


		// FROM: https://stackoverflow.com/a/36132879
		template<typename... Args, typename std::enable_if<sizeof...(Args) == N, bit>::type = 0>
		Bus(Args... args)
		: _bits{args...}
		{}


		bit operator[](unsigned int index)
		{
			if(index >= N)
			{
				throw std::out_of_range("Index out of range");
			}

			return _bits[index];
		}
};
