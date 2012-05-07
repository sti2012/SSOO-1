#include <iostream>
#include <string>
#include <list>
#include <fstream>

using namespace std;

struct Elemento {
	string ciudad;
	long   distancia;
};

typedef list<Elemento> LISTELEM;
typedef list<Elemento>::iterator LI;

void filtrar (list<Elemento> & plano, long dis)
{
	LI p = plano.begin ();

	while (p != plano.end ())
	{
		if (p->distancia < dis)
			p = plano.erase (p);
		else
			++p;
	}
}

void main () 
{
	ifstream  f ("plano.txt");
	LISTELEM  uno;
	Elemento  x;

	// Lectura y rellenado de la lista
	while (f >> x.ciudad)
	{
		f >> x.distancia;
		uno.push_back (x);
	}

	// Se eliminan las ciudades
	// cuya distancia es > 100
	filtrar (uno, 600);

	for (LI p=uno.begin(); p!=uno.end(); p++)
		cout << p->ciudad << " : " 
			 << p->distancia << endl;
}
