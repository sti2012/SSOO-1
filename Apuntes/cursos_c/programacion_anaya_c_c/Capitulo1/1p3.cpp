#include <iostream>

void main ()
{
	std::cout << "Indice de masa corporal" 
	          << std::endl;

	double peso;
	std::cout << "Introduzca peso (kg): ";
	std::cin >> peso;

	int altura;
	std::cout << "Introduzca altura (cm): ";
	std::cin >> altura;

	// indice = peso partido por altura 
	// en metros al cuadrado
	double indice;
	indice = 10000 * peso / (altura * altura);

	std::cout << "Indice = " << indice << std::endl;
}
