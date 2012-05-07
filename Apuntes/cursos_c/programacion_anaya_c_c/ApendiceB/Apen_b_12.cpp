#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

typedef struct {
	string ciudad;
	long   distancia;
} Elemento;

bool distance (const Elemento & x)
{
	return x.distancia <= 600;
}

void main ()
{
	vector<Elemento> plano;
	ifstream         f ("plano.txt");
	Elemento         x;

	while (f >> x.ciudad)
	{
		f >> x.distancia;
		plano.push_back (x);
	}

	typedef vector<Elemento>::iterator VEI;
	VEI iter = partition (plano.begin (), plano.end (), distance);

	vector <Elemento> filtro (iter, plano.end ());
	for (VEI p = filtro.begin (); p != filtro.end (); p++)
		cout << p->ciudad << " : " << p->distancia << endl;
}