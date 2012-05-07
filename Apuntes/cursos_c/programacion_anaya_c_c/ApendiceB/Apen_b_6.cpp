#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

void main ()
{
	map <string, long> numero;
	ifstream f ("nombres.txt");
	string palabra;

	while (f >> palabra)
		numero [palabra]++;

	typedef map <string, long>::const_iterator MI;
	for (MI p=numero.begin(); p != numero.end (); p++)
		cout << p->first << " : " << p->second << endl;
}
