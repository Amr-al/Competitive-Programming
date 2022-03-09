									Bits 
Why ? 
Time Efficiency 
Code shorten 
Memory Efficiency 

AND   => &
OR    => |
XOR   => ^
NOT   => ~
INVERTER => !
shift left =>  << 
shift right =>  >> 
A ^ B ^ C ^ D =  E For any bit in E with 1, must be ODD number of 1s
(A ^ B ^ C ^ D ^ E) ^ (A ^ B ^ C) = D ^ E 
(A ^ B ) = C => (A ^C) = B
	A 	B 	!A 	A&B 	A|B 	A^B
	0	0	1	0	0	0		
	0	1	1	0	1	1		
	1	0	0	0	1	1		
	1	1	0	1	1	0

X >> 1	 = 	1001000000 			Equals X/2
X >> 2	 = 	100100000 			Equals X/4
X << 1	 =      100100000000		Equals X*2
X << 2	 =      1001000000000		Equals X*4


X << 1	 =  010010000000	Equals X*2
X = 11010 = 26 = 2^1 + 2^3 + 2^4 = 2 + 8 + 16

X = 11010 = 26		// Last Bit shows Parity: Even / Odd
X = 11011 = 27

X % 2 = X & 1 = bit 0

Generally:	X%(2^n)  = X & (2^n -1)

Even test
	if(n%2 == 1)		-> Fails of n is negative

	if( (n&1) == 1)	-> Works always

*/
int countNumBits1(int mask) {	// O(bits Length)
	int ret = 0;	//1101001 -> 110100 -> 11010 -> 1101 -> 110 -> 11 -> 1 -> 0
	while (mask) {
		if(mask&1)
			ret++;
		mask >>= 1;
	}
	return ret;
}
// Get bit
int getBit(int num, int idx) {
  return ((num >> idx) & 1) == 1;		// 110100, idx = 4  -->  110 & 1 = 0
}

int setBit1(int num, int idx) {
	return num | (1<<idx);
}

int setBit0(int num, int idx) {
	return num & ~(1<<idx);				// 110100, idx = 3  -->  110100 & ~000100 = 110100 & 111011
}

int flipBit(int num, int idx) {
	return num ^ (1<<idx);
}

/*
X-1 is very important!

X = 840 	= 01101001000
X-1 = 839 	= 01101000111		What happened? First bit 16=(2^4) is removed, and 15=2^4-1 is added.

X & (X-1) 	= 01101000000		first bit from right removed

X & ~(X-1) 	= 01101001000 & 10010111000 = 0000000100 		value of 1<<SmaintestBitIdx
*/




i

int countNumBits2(int mask) {	//	O(bits Count)		__builtin_popcount
	int ret = 0;
	while (mask) 	{
		mask &= (mask-1);
		++ret;	// Simply remove the last bit and so on
	}
	return ret;
}


// Be careful with operators precedence problems. http://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B#Operator_precedence
// X & 7 == 1 		is interpreted as 			X & (7 == 1)	--> (X & 7) == 1
// 1<<10 -1 		is interpreted as			= 1<<9			--> (1<<10) - 1

// Watch out from overflow
// 1 << 60 Fails. 1 is 32 bitInteger		-->		1LL << 60


// 110101000 -1 = 110100111 & 110101000 = 110100000
The g++ compiler provides the following functions for counting bits:
• __builtin_clz(x): the number of zeros at the beginning of the number
• __builtin_ctz(x): the number of zeros at the end of the number
• __builtin_popcount(x): the number of ones in the number
• __builtin_parity(x): the parity (even or odd) of the number of ones
The functions can be used as follows:
int x = 5328; // 00000000000000000001010011010000
cout << __builtin_clz(x) << "\n"; // 19
cout << __builtin_ctz(x) << "\n"; // 4
cout << __builtin_popcount(x) << "\n"; // 5
cout << __builtin_parity(x) << "\n"; // 1

