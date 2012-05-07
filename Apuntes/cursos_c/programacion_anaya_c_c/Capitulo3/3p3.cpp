#include <iostream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main ()
{
    cout << "Indice de masa corporal"
		<< endl;

	double peso;
	cout << "Introduzca peso (kg): ";
	cin >> peso;

	int altura;
	cout << "Introduzca altura (cm): ";
	cin >> altura;

	if (altura == 0)
	{
		cerr << "Error: altura nula" << endl;
		return 1;
	}

	double indice;
	indice = 10000 * peso / (altura * altura);

	// varones, indice normal en [21, 25)

	cout << "Diagnostico: ";
	if (indice < 21)
		cout << "Peso bajo" << endl;
	else if (indice >=  25)
		cout << "Sobrepeso" << endl;
	else
		cout << "Indice normal" << endl;

	return 0;
}
