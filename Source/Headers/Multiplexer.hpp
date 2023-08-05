

#include <type_traits> // enable_if, conjuction


#include "Port.hpp"


template<size_t N, typename PortType>
class Multiplexer
{
	private:
		PortType _ports[N];
		Port<16> _output;

	public:
		// FROM: https://stackoverflow.com/a/36132879
		template<typename... Args, typename std::enable_if<sizeof...(Args) == N>::type>
		Multiplexer(Args... args)
		: _ports{args...}
		{};
};
