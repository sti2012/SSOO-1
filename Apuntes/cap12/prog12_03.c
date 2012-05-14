/* 
 * Programa:    prog12_03
 * Autores:     Jesús Carretero Pérez, 
 *              Félix García Carballeira, 
 *              Javier Fernandez Muñoz, 
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 12:
 *              Ejemplo de borrado de un archivo.
 */

#include <stdio.h>

int main(void)
{
   int res;

   res = remove("./ejemplo_1.txt");
   if (res != 0)
   {
      printf("Error, no se puede borrar el archivo\n");
   }
   return(0);
}

