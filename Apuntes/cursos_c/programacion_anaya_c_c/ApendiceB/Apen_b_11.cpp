#include <iostream>
#include <bitset>
using namespace std;

void main () 
{
	bitset<16> b = 0xABCD;
	cout << b << endl;
	b = b >> 1;
	cout << b << endl;
}