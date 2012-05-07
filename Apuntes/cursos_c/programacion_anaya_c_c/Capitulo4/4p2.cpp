#include <iostream>

using std::cout;
using std::endl;

void main ()
{
	long i, longitud;
	char cad [] = "una cadena";

	for (longitud=0, i=0; cad [i] != '\0'; i++)
		longitud++;

	cout << longitud << endl;
}
