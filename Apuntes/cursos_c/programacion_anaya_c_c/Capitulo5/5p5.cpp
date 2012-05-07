#include <iostream>

using std::cout;
using std::endl;

double potencia (long base, long exponente = 2)
{
	if (exponente == 2)
		return (base * base);
	else 
	{
		double res = base;
		for (long i=1; i<exponente; i++)
			res *= base;
		return res;
	}
}

void main()
{
	cout << "potencia (3) = " << potencia (3) << endl;
	cout << "potencia (3, 4) = " << potencia (3, 4)
	     << endl;
}