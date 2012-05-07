/* 
 * Programa:    prog13_03
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 13:
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

  /* Asignación de valores a campos */    
  r.a = 3; r.b = 2; r.c = 1; r.d = 0;
  /* Impresión de valores a campos */    
  printf("Valores de campos de bits: %d %d %d %d\n", 
          r.a, r.b, r.c, r.c);

  /* Asignación de valores FUERA DE RANGO a campos */    
  r.a = 7; r.b = 24; r.c = 3; r.d = 5;
  /* Impresión de valores a campos */    
  printf("Valores de campos de bits fuera de rango?: %d %d %d %d\n", 
          r.a, r.b, r.c, r.c);

  printf("r requiere %d bytes\n", sizeof(r));
  return (0);
}

