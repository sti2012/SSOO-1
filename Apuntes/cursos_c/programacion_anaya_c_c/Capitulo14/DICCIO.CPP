#include <iostream>
#include "diccio.h"
using std::cout;
using std::endl;

//      M‚todos de la clase Diccionario

long Diccionario::buscar (string clave) {
/* Devuelve el valor asociado a la clave
   o -1 si la clave no est  en el diccionario
*/
  for (empezar(); !fin(); sucesor())
    if (clave == pActual()->ciudad)
      return pActual()->distancia;
  return -1;
}

void Diccionario::listar (long a, long b) {
/* Escribe la ciudad en el flujo de salida
   si su distancia est  comprendida entre a y b
*/
  for (empezar(); !fin(); sucesor())
    if (pActual()->distancia <= b &&
        pActual()->distancia >= a)
          cout << pActual()->ciudad << endl;
}
