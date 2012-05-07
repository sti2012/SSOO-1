/* 
 * Programa:    prog13_03
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 13:
 *              Programa que hace operaciones con campos de bits
 */
#include <stdio.h>

struct registro
{
   unsigned a : 2;
   unsigned b : 4;
   unsigned c : 1;
   unsigned d : 1;
};
    
int main(void)
{
  struct registro r;

  /* Asignaci�n de valores a campos */    
  r.a = 3; r.b = 2; r.c = 1; r.d = 0;
  /* Impresi�n de valores a campos */    
  printf("Valores de campos de bits: %d %d %d %d\n", 
          r.a, r.b, r.c, r.c);

  /* Asignaci�n de valores FUERA DE RANGO a campos */    
  r.a = 7; r.b = 24; r.c = 3; r.d = 5;
  /* Impresi�n de valores a campos */    
  printf("Valores de campos de bits fuera de rango?: %d %d %d %d\n", 
          r.a, r.b, r.c, r.c);

  printf("r requiere %d bytes\n", sizeof(r));
  return (0);
}

