#include <iostream>

using std::cout;
using std::endl;

template <class T> void ordenar (T * x, long n)
{
	long i, j;
	T    tmp;

	for (i=1; i<n; i++)
	{
		tmp = x [i];
		j = i-1;
		while (j>-1 && (x [j]>tmp))
		{
			x [j+1] = x [j];
			j = j -1;
		}
		x [j+1] = tmp;
	}
}

template <class T> void escribir (T * x, long n)
{
	for (long i=0; i<n; i++)
		cout << x [i] << " ";
	cout << endl;
}

void main ()
{
	long tabla [] = {3, 2, 54, 23, 67, 5};
	double grupo [] = {2.1, 7.8, 1.3, 6.5};

	ordenar (tabla, 6);
	escribir (tabla, 6);
	ordenar (grupo, 4);
	escribir (grupo, 4);
}