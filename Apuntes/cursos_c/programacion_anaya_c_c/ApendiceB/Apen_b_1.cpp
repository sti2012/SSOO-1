#include <iostream>
#include <string>
#include <vector>

using namespace std;
	
typedef struct {
	string ciudad;
	long   distancia;
} Elemento;

void main ()
{
	vector<Elemento> plano (3);

	cout << plano.size () << endl;;
}
