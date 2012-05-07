#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

class VectorEntero {
    int *datos;
    long cuantos;
  public:
    VectorEntero (int *valores, long numero) {
      datos = new int[numero];
      memcpy (datos, valores, numero*sizeof(int));
      cuantos = numero;
    }
    ~VectorEntero () { delete[] datos; }
    int operator [ ] (long indice) {
      if (indice<0 || indice >=cuantos) throw 1;
      return datos[indice];
    }
};

void main () {
  int tabla [ ] = {2,4,6,8,10};
  VectorEntero ve (tabla, 5);
  int indice;
  for (;;) {
    try {
      cout << "Escriba el ¡ndice que desea extraer
        (999 para terminar): ";
      cin >> indice;
      if (indice==999) break;
      cout << "El valor correspondiente es "
           << ve[indice] << endl;
    } catch (int) {
      cout << "Ese ¡ndice no es correcto." << endl;
    }
  }
}
