#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void menu () 
{
	cout << "Conversor a euros de:" << endl;
	cout << "  Pesetas (0)" << endl;
	cout << "  Marcos (1)" << endl;
	cout << "  Francos (2)" << endl;
}

double convertir (short codigo, double x)
{
	switch (codigo) 
	{
		case 0 :
			x /= 166.386;
			break;
		case 1 :
			x /= 1.95583;
			break;
		case 2 :
			x /= 6.55957;
			break;
	}
	return x;
}

int main (void) 
{
	menu ();

	short moneda;
	cout << "Elija un codigo: ";
	cin >> moneda;

	// El codigo debe estar en [0, 2]
	while (moneda < 0 || moneda > 2)
	{
		cout << "Codigo incorrecto. ";
		cout << "Elija otro: ";
		cin >> moneda;
	}

	double cantidad;
	cout << "Introduzca una cantidad: ";
	cin >> cantidad;

	cantidad = convertir (moneda, cantidad);

	cout << "Cambio = " << cantidad 
			<< " euros" << endl;
	return 0;
}