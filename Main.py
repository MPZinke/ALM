

bit = bool
int8 = tuple[bit, bit, bit, bit, bit, bit, bit, bit]


def add(a1: bit, b1: bit, c1: bit, d1: bit, e1: bit, f1: bit, g1: bit, h1: bit,
		a2: bit, b2: bit, c2: bit, d2: bit, e2: bit, f2: bit, g2: bit, h2: bit
) -> int8:
	a_out = a1 ^ a2
	b_carry = a1 and a2

	b_xor = b1 ^ b2
	b_out = b_xor ^ b_carry
	c_carry = (b_xor and b_carry) or (b1 and b2)

	c_xor = c1 ^ c2
	c_out = c_xor ^ c_carry
	d_carry = (c_xor and c_carry) or (c1 and c2)

	d_xor = d1 ^ d2
	d_out = d_xor ^ d_carry
	e_carry = (d_xor and d_carry) or (d1 and d2)

	e_xor = e1 ^ e2
	e_out = e_xor ^ e_carry
	f_carry = (e_xor and e_carry) or (e1 and e2)

	f_xor = f1 ^ f2
	f_out = f_xor ^ f_carry
	g_carry = (f_xor and f_carry) or (f1 and f2)

	g_xor = g1 ^ g2
	g_out = g_xor ^ g_carry
	h_carry = (g_xor and g_carry) or (g1 and g2)

	h_xor = h1 ^ h2
	h_out = h_xor ^ h_carry
	carry_out = (h_xor and h_carry) or (h1 and h2)

	return a_out, b_out, c_out, d_out, e_out, f_out, g_out, h_out


def binary_to_bit(binary: int) -> int8:
	bits: int8 = ()
	for x in range(7, -1, -1):
		bits += ((binary >> x) & 1,)

	return bits


print(binary_to_bit(0b11111111))
print(add(*binary_to_bit(0b11111111), *binary_to_bit(0b10000000)))
