#include "diccionario.h"
#include <fstream>

using std::ifstream;

void main ()
{
  DiccionarioConsecutivo  plano;
  ifstream                is ("plano.txt");
  string                  ciudad;
  long                    distancia;

  iniciar (&plano, 46);
  while (is >> ciudad) 
  {
    is >> distancia;
    insertar (&plano, ciudad, distancia);
  }

  is.close ();
  listar (&plano, 200, 300);
  terminar (&plano);
}
