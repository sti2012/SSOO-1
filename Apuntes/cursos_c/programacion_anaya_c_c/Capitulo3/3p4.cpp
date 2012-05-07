#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main (void) 
{
	cout << "Conversor a euros de:" << endl;
	cout << "  Pesetas (0)" << endl;
	cout << "  Marcos (1)" << endl;
	cout << "  Francos (2)" << endl;

	unsigned short moneda;
	cout << "Elija un codigo: ";
	cin >> moneda;

	double cantidad;
	cout << "Introduzca una cantidad: ";
	cin >> cantidad;

	switch (moneda) 
	{
		case 0 : 
			cantidad /= 166.386;
			break;
		case 1 :
			cantidad /= 1.95583;
			break;
		case 2 :
			cantidad /= 6.55957;
			break;
		default :
			cout << "No hay cambio para este codigo." 
				<< endl;
			return 1;
	}

	cout << "Cambio = " << cantidad 
	<< " euros" << endl;
	return 0;
}