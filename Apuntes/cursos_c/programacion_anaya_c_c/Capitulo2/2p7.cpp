#include <iostream>

char c = 'A'; // c global, declarada fuera de main

void main ( ) 
{ 
	char  c = 'B';      // c local a main
	{
		char c = 'D';     // c local al bloque interno
		std::cout << c;   // c es la c local al b. i.
		std::cout << ::c; // ::c es la c global
	}
}