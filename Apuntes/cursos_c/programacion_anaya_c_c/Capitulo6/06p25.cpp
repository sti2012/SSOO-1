#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::string;
using std::stringstream;

void main ()
{
	string         cad;
	long           dis;
	stringstream   flujo;

	// Se escribe "Burgos 239" en el flujo
	flujo << "Burgos 239";

	// Se lee un string y un numero entero
	// del flujo de cadena
	flujo >> cad >> dis;

	// Se escribe la cadena y el numero leidos
	// en el flujo de salida estandar
	cout << cad << " : " << dis;
}
