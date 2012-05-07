#include <iostream>
#include <string>

using namespace std;

void main ()
{
	cout << "Introduzca su nombre ";
	cout << "seguido de un .: ";

	string nombre;
	getline (cin, nombre, '.');
	nombre = "AUTOR: " + nombre;

	string primera (nombre.size () + 2, '*');
	primera = "/*" + primera;

	string segunda = "  ";
	segunda += nombre;

	string tercera = "  FECHA: ";

	string cuarta (nombre.size () + 3, '*');
	cuarta += "/";

	cout << primera << endl;
	cout << segunda << endl;
	cout << tercera << __DATE__ << endl;
	cout << cuarta << endl;
}