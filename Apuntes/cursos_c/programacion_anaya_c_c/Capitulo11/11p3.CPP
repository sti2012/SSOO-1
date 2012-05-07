#include <iostream>
#include <string>
#include "lista.h"
using std::cin;
using std::cout;
using std::endl;

void main () {
  Lista<int> p;
  int n;
  cout << "Para terminar, escriba 999" << endl;
  for (;;) {
    cout << "Escriba un n£mero para meterlo en la lista: ";
    cin >> n;
    if (n==999) break;
    else p.agregar(&n);
  }
  cout << "Ahora vamos a sacar los valores de la lista" << endl;
  for (p.empezar(); !p.fin(); p.sucesor())
    cout << *p.extraer() << endl;
  cout << "Escriba 0 para terminar" << endl;
  cin >> n;
}
