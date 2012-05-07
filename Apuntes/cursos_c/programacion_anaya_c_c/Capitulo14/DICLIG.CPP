#include "diclig.h"

// M‚todos de la clase DiccionarioLigado

int DiccionarioLigado::insertar (string clave, long valor) {
/* Devuelve 0 si la inserci¢n se realiz¢ correctamente */
  Capital * nueva = new Capital;
  // Crea una capital nueva
  nueva->ciudad = clave;
  // Rellena la capital
  nueva->distancia = valor;
  // A¤ade la capital a la lista
  lista.agregar(nueva);
  return 0;
}
