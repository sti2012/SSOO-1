#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Elemento {
	string   ciudad;
	long     distancia;
};

struct DiccionarioConsecutivo {
	Elemento * elem;
	long     maximo;
	long     ultimo;
};

int main (void)
{
	DiccionarioConsecutivo  plano;

	// Inicializacion de plano
	cout << "Introduzca numero de ciudades: ";
	cin >> plano.maximo;
	plano.ultimo = 0;

	// Reserva de memoria
	plano.elem = new Elemento [plano.maximo];
	if (!plano.elem)
	{
		cout << "Memoria agotada" << endl;
		return 1;
	}

	// Inserción de ciudades en la tabla
	for (long i=0; i<plano.maximo; i++)
	{
		cout << "Introduzca ciudad y distancia: ";
		cin >> plano.elem[i].ciudad;
		cin >> plano.elem[i].distancia;
		plano.ultimo++;
	}

	// Liberacion de memoria
	delete [] plano.elem;

	return 0;
}
