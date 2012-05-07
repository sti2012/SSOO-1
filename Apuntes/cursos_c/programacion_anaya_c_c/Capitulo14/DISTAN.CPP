#include <iostream>
#include <fstream>
#include <string>
#include "diclig.h"
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

// Programa principal

void main ()
{
  DiccionarioLigado plano;
  ifstream          is ("plano.txt");
  string            ciudad;
  long              distancia;

  if (!is)
  {
    cout << "Error de apertura" << endl;
    return;
  }

  while (is >> ciudad)
  {
    is >> distancia;
    plano.insertar (ciudad, distancia);
  }
  is.close ();
  plano.listar (200, 300);
}
