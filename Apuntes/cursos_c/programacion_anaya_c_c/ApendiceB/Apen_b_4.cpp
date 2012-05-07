#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Elemento {
	string ciudad;
	long   distancia;
};

void main ()
{
	vector<Elemento> plano;
	Elemento         x;

	x.ciudad = "Gerona";
	x.distancia = 725;
	plano.push_back (x);

	x.ciudad = "Granada";
	x.distancia = 432;
	plano.push_back (x);

	x.ciudad = "Guadalajara";
	x.distancia = 56;
	plano.push_back (x);

	plano.erase (plano.begin ());

	x.ciudad = "Cuenca";
	x.distancia = 165;
	plano.insert (plano.begin (), x);
  
	typedef vector<Elemento>::const_iterator VI;
	for (VI p=plano.begin(); p!=plano.end(); p++)
		cout << p->ciudad << " : " 
		<< p->distancia << endl;
}