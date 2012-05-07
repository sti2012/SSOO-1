#include <iostream>

using std::cout;
using std::endl;

long suma (int * datos, long dim) 
{
	long sum = 0;
	for (long i=0; i<dim; i++)
		sum += datos [i];

	return sum;
}

double suma (double * datos, long dim) 
{
	double sum = 0.0;
	for (long i=0; i<dim; i++)
		sum += datos [i];

	return sum;
}

void main ()
{
	int datos_1 [] = {1, 3, 5, 7, 9};
	double datos_2 [] = {1.2, 3.4, 5.9, 4.2};

	cout << "Suma = " << suma (datos_1, 5) << endl;
	cout << "Suma = " << suma (datos_2, 4) << endl;
}