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

void leer_codigo (short * codigo)
{
	cout << "Elija un codigo: ";
	cin >> *codigo;

	// El codigo debe estar en [0, 2]
	while (*codigo < 0 || *codigo > 2)
	{
		cout << "Codigo incorrecto. ";
		cout << "Elija otro: ";
		cin >> *codigo;
	}
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
    leer_codigo (&moneda);

	double cantidad;
	cout << "Introduzca una cantidad: ";
	cin >> cantidad;

	cantidad = convertir (moneda, cantidad);

	cout << "Cambio = " << cantidad 
			<< " euros" << endl;
	return 0;
}