#include "diccon.h"

// M‚todos de la clase DiccionarioConsecutivo

int DiccionarioConsecutivo::insertar (string clave, long valor) {
/* Devuelve 0 si la inserci¢n se realiz¢ correctamente,
   1 si la tabla est  llena
*/
  if (ultimo == maximo) return 1;
  elem[ultimo].ciudad = clave;
  elem [ultimo].distancia = valor;
  ultimo++;
  return 0;
}
