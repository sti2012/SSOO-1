#include "diccionario.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;

void main ()
{
	try 
	{
		DiccionarioConsecutivo plano;
		ifstream               is ("plano.txt");
		Elemento               aux;

		if (!is) throw ("Error de apertura");

		iniciar (&plano, 46);

		while (is >> aux.ciudad)
		{
			is >> aux.distancia;
			insertar (&plano, aux.ciudad, aux.distancia);
		}

		is.close ();
		listar (&plano, 200, 300);
		terminar (&plano);
	}
	catch (char * mensaje)
	{
		cout << mensaje << endl;
	}
}