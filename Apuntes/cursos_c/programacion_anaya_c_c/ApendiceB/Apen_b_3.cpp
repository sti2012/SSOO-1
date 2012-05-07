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
	vector<Elemento> plano (3);

	typedef vector<Elemento>::iterator  VI;
	for (VI p=plano.begin (); p!=plano.end (); p++)
	{
		cout << "Introduzca ciudad y distancia: "; 
		cin >> p->ciudad;
		cin >> p->distancia;
	}
	
	typedef vector<Elemento>::reverse_iterator RI;
	for (RI r=plano.rbegin(); r!=plano.rend(); r++)
		cout << r->ciudad << " : " << r->distancia << endl;
}