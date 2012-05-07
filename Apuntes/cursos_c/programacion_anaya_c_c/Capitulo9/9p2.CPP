#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::ifstream;

// Declaraci¢n de la clase DiccionarioConsecutivo

class DiccionarioConsecutivo {

  struct Elemento {
    string  ciudad;
    long    distancia;
  };

    Elemento    * elem;
    long        maximo;
    long        ultimo;

  public:

    DiccionarioConsecutivo (long n)
    {
      elem = new Elemento [n];
      maximo = n;
      ultimo = 0;
    }

    ~DiccionarioConsecutivo ()
    {
      delete [] elem;
    }

    int insertar (string clave, long valor);
    long buscar (string clave);
    void listar (long a, long b);
};

int DiccionarioConsecutivo::insertar
    (string clave, long valor) {
/* Devuelve 0 si la inserci¢n se realiz¢
  correctamente, 1 si la tabla est  llena
*/
  if (ultimo == maximo) return 1;
  elem[ultimo].ciudad = clave;
  elem [ultimo].distancia = valor;
  ultimo++;
  return 0;
}
long DiccionarioConsecutivo::buscar
     (string clave) {
/* Devuelve el valor asociado a la clave
  o -1 si la clave no est  en el diccionario
*/
  for (long i=0; i<ultimo; i++)
    if (clave == elem[i].ciudad)
      return elem[i].distancia;
  return -1;
}
void DiccionarioConsecutivo::listar (long a, long b) {
/* Escribe la ciudad en el flujo de salida
  si su distancia est  comprendida entre a y b
*/
  for (long i=0; i<ultimo; i++)
    if (elem[i].distancia <= b &&
        elem[i].distancia >= a)
          cout << elem[i].ciudad << endl;
}

void main ()
{
  DiccionarioConsecutivo  plano (46);
  ifstream                is ("plano.txt");
  string                  ciudad;
  long                    distancia;
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