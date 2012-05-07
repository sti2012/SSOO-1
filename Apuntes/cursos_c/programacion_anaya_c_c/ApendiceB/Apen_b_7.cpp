#include <iostream>
#include <stack>
using namespace std;

void main () 
{
	stack<long> pila;

	for (long i=0; i<10; i++)
		pila.push (i);

	while (!pila.empty()) 
	{
		// escribe el elemento del principio
		cout << pila.top() << " ";
		// elimina el elemento del principio
		pila.pop();  
	}
}
