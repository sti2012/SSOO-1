#include <fstream>
#include <cstring>
#define MAX 20

using std::ofstream;
using std::ios_base;

struct Elemento {
	char	ciudad [MAX];
	long	distancia;
};

void main()
{
	Elemento   x;
	ofstream   f ("datos.bin", ios_base::binary);

	strcpy (x.ciudad, "Albacete");
	x.distancia = 412;

	f.write((char *) &x, sizeof x);
}