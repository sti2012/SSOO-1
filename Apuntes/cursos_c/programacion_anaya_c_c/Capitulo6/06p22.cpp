#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;

int main ()
{
	string ciudades [3];
	long dis [3];

	ifstream p ("plano.txt");

	if (!p)
	{
		cout << "No se pudo abrir el archivo." << endl;
		return 1;
	}

	for (int i=0; i<3; i++)
		p >> ciudades [i] >> dis [i];

	p.close ();
	return 0;
}
