#include <iostream>

using std::cout;
using std::endl;

void main ()
{
	long longitud;
	char cad [] = "una cadena";

	longitud = 0;
	for (char * p = cad; *p != 0; p++)
		longitud++;

	cout << longitud << endl;
}