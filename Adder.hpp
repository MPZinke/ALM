

#include "Bus.hpp"


template<size_t N>
class Adder
{
	public:
		Adder(){}


		friend void operator>>(Bus<N>& bus, Adder& adder)
		{
			if(adder._bus1 == NULL || adder._bus2 != NULL)
			{
				adder._bus2 = NULL;
				adder._bus1 = &bus;
			}
			else
			{
				adder._bus2 = &bus;
			}
		}


		void operator>>(Bus<N>& bus)
		{
			bit carry = false;
			for(unsigned int x = 0; x < N; x++)
			{
				bit bus_1_2_xor = _bus1[x] ^ _bus2[x];
				bus._bits[x] = bus_1_2_xor ^ carry;
				carry = (bus_1_2_xor and carry) or (_bus1[x] and _bus2[x]);
			}
		}


	private:
		Bus<N>* _bus1 = NULL;
		Bus<N>* _bus2 = NULL;
};
