#include <iostream>

using std::cout;

int a;

namespace uno  
{			  // comienzo del espacio uno
	int a;
}			  // fin del espacio uno

void main () 
{
	::a = 0;       // a global
	uno::a = 1;    // a del espacio uno 

	using uno::a;  // la variable a global queda oculta
	cout << "a = " << a;  // a del espacio uno
}