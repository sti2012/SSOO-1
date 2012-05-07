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

	for (long i=0; i<plano.size(); i++)
	{
		cout << "Introduzca ciudad y distancia: "; 
		// acceso sin comprobacion
		cin >> plano [i].ciudad;
		cin >> plano [i].distancia;
	}

	// la longitud de plano pasa a ser 2
	plano.resize (2);  

	try 
	{
		for (long i=0; i<3; i++)
		// acceso con comprobacion
		cout << plano.at (i).ciudad << endl; 
	}
	catch (out_of_range x) 
	{
		cout << x.what () << endl;
	}
}
